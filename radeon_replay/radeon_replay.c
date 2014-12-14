#include <stdio.h>
#include <sys/io.h>

#include "replay.h"

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
