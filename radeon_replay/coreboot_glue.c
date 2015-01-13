#include <unistd.h>

#include "coreboot_glue.h"

void udelay(unsigned usecs)
{
	usleep(usecs);
}

void mdelay(unsigned msecs)
{
	while(msecs--)
		udelay(1000);
}

void delay(unsigned secs)
{
	/* sleep() returns the number of seconds not slept, so keep sleeping
	 * until we've slept all the way.
	 */
	while(secs)
		secs = sleep(secs);
}
