#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/io.h>

#include "atomfake.h"
#include "edid.h"
#include "replay.h"
#include "radeon_init_native.h"
#include "radeon_util.h"

struct global_cfg {
	bool need_io_perm;
	bool run_replay;
	bool run_tests;
	bool read_dcpd;
	bool read_edid;
	bool do_haxorz_stuff;
};

static void dump_array(const uint8_t *what, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if ((i & 0xf) == 0)
			printf("\n %02zx:", i);
		printf(" %02x", what[i]);
	}
	printf("\n");
}

struct DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5
{
	uint16_t usSymClock;                    // Encoder Clock in 10kHz,(DP mode)= linkclock/10, (TMDS/LVDS/HDMI)= pixel clock,  (HDMI deep color), =pixel clock * deep_color_ratio
	uint8_t  ucPhyId;                   // 0=UNIPHYA, 1=UNIPHYB, 2=UNIPHYC, 3=UNIPHYD, 4= UNIPHYE 5=UNIPHYF
	uint8_t  ucAction;                                  // define as ATOM_TRANSMITER_ACTION_xxx

	uint8_t  ucLaneNum;                 // indicate lane number 1-8
	uint8_t  ucConnObjId;               // Connector Object Id defined in ObjectId.h
	uint8_t  ucDigMode;                 // indicate DIG mode
	union{
		//struct ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
		uint8_t ucConfig;
	};

	uint8_t  ucDigEncoderSel;           // indicate DIG front end encoder
	uint8_t  ucDPLaneSet;
	uint8_t  ucReserved;
	uint8_t  ucReserved1;
};

void aruba_transmitter_enable(struct radeon_device *rdev,
			      struct DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5 *cfg);

const int32_t trymafreq[] = {20000, 10000, 53300, 40000, 0, 0, 53300, 40000, 0, 0,
			33489, 16744, 49656, 24828, 68572, 34286, 25000, -1};
const int32_t trymafreq2[] = {5806, 5950, 6000, 6100, 6200, 6300, -1};

extern uint8_t more_compute_mem_eng_pll(uint32_t *clock);
void aruba_brightness_control(struct radeon_device *rdev,
			      uint16_t bl_pwm_freq_hz, uint8_t bl_level);
extern void aruba_lcd_blon(struct radeon_device *rdev);
extern void aruba_lcd_bloff(struct radeon_device *rdev, uint8_t max_pclk);

static void localtest(void)
{
	uint8_t div;
	uint32_t i, freq;

	struct DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5 cfg = {
		.usSymClock = 0x6978,
		.ucPhyId = 0x04,
		.ucAction = 0x01,
		.ucLaneNum = 0x01,
		.ucConnObjId = 0x0e, // CONNECTOR_OBJECT_ID_LVDS
		.ucDigMode = 0,
		.ucConfig = 0x1a,
		.ucDigEncoderSel = 0x10,
		.ucDPLaneSet = 0,
	};

	aruba_transmitter_enable(NULL, &cfg);
	return;
	//aruba_lcd_bloff(NULL, 0);
	//return;
	aruba_lcd_blon(NULL);
	for (i = 0; i < 256; i++) {
		aruba_brightness_control(NULL, 200, i);
		radeon_udelay(100000/(i + 1));
	}
	return;

	i = 0;
	do {
		freq = trymafreq[i];
		div = more_compute_mem_eng_pll(&freq);
		printf("Want %u, got %u, div %u\n", trymafreq[i], freq, div);
	} while (trymafreq[++i] != -1);
	return;
	for (i = 0; i < 200000; i += 1000) {
		freq = i;
		div = more_compute_mem_eng_pll(&freq);
		printf("Want %u, got %u, div %u\n", i, freq, div);
	}
}

static void print_help(void)
{
	printf("radeon_replay [ACTIONS]\n\n");
	printf("  -h, --help   Print this message and exit\n");
	printf("  -r, --replay Replay a VGA init (source: hp_1035dx)\n");
	printf("  -T, --tests  Run a random assortment of tests\n");
	printf("  -d, --dpcd   Read DisplayPort configuration data\n");
	printf("  -e, --edid   Read EDID over AUX channel (DANGEROUS)\n");
	printf("  -t, --trace  Print IO traces on stderr\n");
}

static void parse_options(int argc, char *argv[], struct global_cfg *config)
{
	int opt, option_index = 0;
	struct option long_options[] = {
		{"help",	no_argument, 		0, 'h'},
		{"replay",	no_argument,		0, 'r'},
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
		opt = getopt_long(argc, argv, "hrtdetX",
				  long_options, &option_index);

		if (opt == EOF)
			break;

		switch (opt) {
		case 'r':
			config->need_io_perm = true;
			config->run_replay = true;
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

	if (config.run_tests)
		run_radeon_tests();

	if (config.run_replay) {
		asic_init();
		printf("Replaying initial init\n");
		run_replay(1);

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

	return EXIT_SUCCESS;
}
