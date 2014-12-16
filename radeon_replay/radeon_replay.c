#include <getopt.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/io.h>

#include "edid.h"
#include "radeon_init_native.h"
#include "radeon_util.h"
#include "replay.h"

struct global_cfg {
	bool need_io_perm;
	bool run_replay;
	bool run_tests;
	bool read_dcpd;
	bool read_edid;
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
		{0, 0, 0, 0}
	};

	memset(config, 0, sizeof(*config));

	/*
	 * Parse arguments
	 */
	while (1) {
		opt = getopt_long(argc, argv, "hrTdet",
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


	if (config.run_replay) {
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
	return EXIT_SUCCESS;
}
