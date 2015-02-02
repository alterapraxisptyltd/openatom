/*
 * coreboot_glue.h: Provide a glue layer that allows our code to look more like
 * it were part of a linu driver *
 */
#ifndef _COREBOOT_GLUE_H
#define _COREBOOT_GLUE_H

#include <stdint.h>

struct i2c_seg
{
	int read;
	uint8_t chip;
	uint8_t *buf;
	int len;
};

void udelay(unsigned usecs);
void mdelay(unsigned msecs);
void delay(unsigned secs);

#endif /* _COREBOOT_GLUE_H */
