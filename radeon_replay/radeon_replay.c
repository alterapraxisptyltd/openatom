#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/io.h>

#include "edid.h"
#include "replay.h"
#include "radeon_init_native.h"
#include "radeon_util.h"
#include "replay.h"

struct global_cfg {
	bool need_io_perm;
	bool run_replay;
	bool run_asic_init;
	bool run_init;
	bool run_tests;
	bool read_dcpd;
	bool read_edid;
	bool do_haxorz_stuff;
};

void dump_array(const uint8_t * what, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if ((i & 0xf) == 0)
			printf("\n %02zx:", i);
		printf(" %02x", what[i]);
	}
	printf("\n");
}

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>

static struct lb_framebuffer fb_magic = {
	.size = 0,
	.physical_address = 0x5f000000,
	.x_resolution = 1366,
	.y_resolution = 768,
	.bytes_per_line = 0,
	.bits_per_pixel = 32,
	.red_mask_pos = 0,
	.red_mask_size = 8,
	.green_mask_pos = 8,
	.green_mask_size = 8,
	.blue_mask_pos = 16,
	.blue_mask_size = 8,
	.reserved_mask_pos = 24,
	.reserved_mask_size = 8,
};

void *map_fb(void)
{
	int fd;
	void *rfbmmio;

	fd = open("/dev/mem", O_RDWR | O_SYNC);

	if (fd == -1) {
		fprintf(stderr, "No /dev/mem ? %s\n", strerror(errno));
		 NULL;
	}

	rfbmmio = mmap(0, 256*1024*1024, PROT_READ | PROT_WRITE, MAP_SHARED,
		       fd, fb_magic.physical_address);

	if (rfbmmio == MAP_FAILED) {
		fprintf(stderr, "mmap() failed %s\n", strerror(errno));
		return NULL;
	}

	return rfbmmio;
}

static void my_mask32(void *addr, uint32_t clr, uint32_t set)
{
	uint32_t mmio32;
	volatile uint32_t *base = addr;
	mmio32 = *base;
	mmio32 &= ~clr;
	mmio32 |= set;
	*base = mmio32;
}

static uint16_t pitch(uint16_t x)
{
	return (x + 0x7f) & ~0x7f;
}

static size_t byte_pitch(uint16_t x)
{
	return (pitch(x) * fb_magic.bits_per_pixel) / 8;
}

static
void get_pixel_offset32(uint16_t x, uint16_t y, uintptr_t *off)
{
	uint64_t bits = x * fb_magic.bits_per_pixel;

	*off = y * byte_pitch(x);
	*off += bits / 8;
}

static void put_pixel(void *fb, uint16_t x, uint16_t y, uint32_t color)
{
	uint8_t red = (color >> 16) & 0xff;
	uint8_t grn = (color >>  8) & 0xff;
	uint8_t blu = (color >>  0) & 0xff;
	uint16_t rmask = (1 << fb_magic.red_mask_size) - 1;
	uint16_t bmask = (1 << fb_magic.blue_mask_size) - 1;
	uint16_t gmask = (1 << fb_magic.green_mask_size) - 1;
	uintptr_t off;
	uint32_t mask, set;

	get_pixel_offset32(x, y, &off);

	printf("pixel %d x %d, at off 0x%zx\n", x, y, off);
	off += (uintptr_t)fb;

	mask = (rmask << fb_magic.red_mask_pos)
	     | (gmask << fb_magic.green_mask_pos)
	     | (bmask << fb_magic.blue_mask_pos);
	set = (red << fb_magic.red_mask_pos)
	    | (blu << fb_magic.blue_mask_pos)
	    | (grn << fb_magic.green_mask_pos);

	my_mask32((void*)off, mask, set);

}

extern struct logoman libreradeon_logo;

static void localtest(void)
{
	size_t y;
	void *fb = map_fb();

	fb_magic.bytes_per_line = byte_pitch(fb_magic.x_resolution);
	fb_magic.size = fb_magic.bytes_per_line * fb_magic.y_resolution;

	if (0) {
		aruba_backlight_control(NULL, 200, 254);
		if (1)
			aruba_backlight_blon(NULL);
		else
			aruba_backlight_bloff(NULL);
	}

	/*
	 * FUS_MC_VM_FB_OFFSET -- location of RAM framebuffer in 4 MiB units
	 * aruba_read(NULL, 0x2068);
	 */
	//aruba_read(NULL, 0x2068);

	memset(fb, 0, fb_magic.size);

	put_pixel(fb, 683, 383, 0x0000ff);
	put_pixel(fb, 683, 384, 0x00ff00);
	put_pixel(fb, 683, 500, 0xff0000);

	for (y = 0; y < libreradeon_logo.height; y++) {
		uintptr_t line = (uintptr_t)fb;
		line += y * fb_magic.bytes_per_line;
		size_t cp_size = libreradeon_logo.width * 4;
		size_t src_idx = cp_size * y;
		const void *src = &libreradeon_logo.pixel_data[src_idx];
		memcpy((void *)line, src, cp_size);
	}
}

static void print_help(void)
{
	printf("radeon_replay [ACTIONS]\n\n");
	printf("  -h, --help   Print this message and exit\n");
	printf("  -r, --replay Replay a VGA init (source: hp_1035dx)\n");
	printf("  -a, --asic_init   Also run asic_init table or native code\n");
	printf("  -i, --init   Try to initialize display and draw something\n");
	printf("  -T, --tests  Run a random assortment of tests\n");
	printf("  -d, --dpcd   Read DisplayPort configuration data\n");
	printf("  -e, --edid   Read EDID over AUX channel (DANGEROUS)\n");
	printf("  -t, --trace  Print IO traces on stderr\n");
}

static void parse_options(int argc, char *argv[], struct global_cfg *config)
{
	int opt, option_index = 0;
	struct option long_options[] = {
		{"help",	no_argument,		0, 'h'},
		{"replay",	no_argument,		0, 'r'},
		{"asic-init",	no_argument,		0, 'a'},
		{"init",	no_argument,		0, 'i'},
		{"tests",	no_argument,		0, 'T'},
		{"dpcd",	no_argument,		0, 'd'},
		{"edid",	no_argument,		0, 'e'},
		{"trace",	no_argument,		0, 't'},
		{"haxorz",	no_argument,		0, 'X'},
		{0, 0, 0, 0}
	};

	memset(config, 0, sizeof(*config));

	/*
	 * Parse argumentsx
	 */
	while (1) {
		opt = getopt_long(argc, argv, "hraiTdetX",
				  long_options, &option_index);

		if (opt == EOF)
			break;

		switch (opt) {
		case 'r':
			config->need_io_perm = true;
			config->run_replay = true;
			break;
		case 'i':
			config->need_io_perm = true;
			config->run_init = true;
			break;
		case 'T':
			config->need_io_perm = true;
			config->run_tests = true;
			break;
		case 'd':
			config->need_io_perm = true;
			config->read_dcpd = true;
			break;
		case 'e':
			config->need_io_perm = true;
			config->read_edid = true;
			break;
		case 't':
			radeon_enable_iotracing();
			break;
		case 'X':
			config->need_io_perm = true;
			config->do_haxorz_stuff = true;
			break;
		case 'h':
			print_help();
			exit(EXIT_SUCCESS);
		default:
			/* Invalid option. getopt will have printed something */
			exit(EXIT_FAILURE);
			break;
		}
	}
}

int main(int argc, char *argv[])
{

	int dpcd_ret, edid_ret;
	uint8_t dpcd[256], edid_raw[256];
	struct edid edid;
	struct global_cfg config;
	printf("radeon_replay AtomBIOS replayer\n");

	parse_options(argc, argv, &config);
	radeon_init_mmio();

	if (config.need_io_perm) {
		if (ioperm(0x2000, 0x2000, 1) || ioperm(0x300, 0x100, 1)) {
			printf("No IO permissions. Are we root?\n");
			return EXIT_FAILURE;
		}
	}

	if (config.read_dcpd) {
		printf("Let's try to read from the aux channel\n");
		dpcd_ret = radeon_read_dpcd(0, dpcd, 0, sizeof(dpcd));
	}

	if (config.read_edid) {
		printf("Now let's try to get an EDID\n");
		edid_ret = radeon_read_dp_aux_i2c(0, 0x50, edid_raw, 0, sizeof(edid_raw));
	}

	if (config.read_dcpd && (dpcd_ret >= 0)) {
		printf("Here's the DPCD data:\n");
		dump_array(dpcd, sizeof(dpcd));
	}
	if (config.read_edid && (edid_ret >= 0)) {
		printf("And here's the EDID:\n");
		dump_array(edid_raw, sizeof(edid_raw));
		decode_edid(edid_raw, sizeof(edid_raw), &edid);
	}


	if (config.run_replay) {
		printf("Replaying initial init\n");
		run_replay(config.run_asic_init);

		printf("Replaying first int10 call\n");
		replay_int10_c1();

		printf("Replaying second int10 call\n");
		replay_int10_c2();

		printf("Replaying third int10 call\n");
		replay_int10_c3();

		printf("Did it work ?\n");
	}

	if (config.do_haxorz_stuff) {
		localtest();
	}

	if (config.run_init) {
		if (config.run_asic_init)
			aruba_asic_init(NULL);
		execute_master_plan(NULL);
	}

	return EXIT_SUCCESS;
}
