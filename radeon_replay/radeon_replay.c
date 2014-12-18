#include <stdint.h>
#include <stdio.h>
#include <sys/io.h>

#include "radeon_init_native.h"
#include "replay.h"

static void dump_array(const uint8_t *what, size_t len)
{
	size_t i;
	for (i = 0; i < len; i++) {
		if ((i & 0xf) == 0)
			printf("\n %02x:", i);
		printf(" %02x", what[i]);
	}
	printf("\n");
}

int main(void)
{
	int dpcd_ret, edid_ret;
	uint8_t dpcd[256], edid[256];
	printf("radeon_replay AtomBIOS replayer\n");

	if (ioperm(0x2000, 0x2000, 1) || ioperm(0x300, 0x100, 1)) {
		printf("No IO permissions. Are we root?\n");
		return;
	}

	printf("Let's try to read from the aux channel\n");
	dpcd_ret = radeon_read_dpcd(0, dpcd, 0, sizeof(dpcd));

	printf("Now let's try to get an EDID\n");
	edid_ret = radeon_read_dp_aux_i2c(0, 0x50, edid, 0, sizeof(edid));

	if (dpcd_ret >= 0) {
		printf("Here's the DPCD data:\n");
		dump_array(dpcd, sizeof(dpcd));
	}
	if (edid_ret >= 0) {
		printf("And here's the EDID:\n");
		dump_array(edid, sizeof(edid));
	}

	printf("Replaying initial init\n");
	run_replay();

	printf("Replaying first int10 call\n");
	replay_int10_c1();

	printf("Replaying second int10 call\n");
	replay_int10_c2();

	printf("Replaying third int10 call\n");
	replay_int10_c3();

	printf("Did it work ?\n");
}
