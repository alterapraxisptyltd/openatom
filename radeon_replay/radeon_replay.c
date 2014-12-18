#include <stdint.h>
#include <stdio.h>
#include <sys/io.h>

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
	printf("radeon_replay AtomBIOS replayer\n");

	if (ioperm(0x2000, 0x2000, 1) || ioperm(0x300, 0x100, 1)) {
		printf("No IO permissions. Are we root?\n");
		return;
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
