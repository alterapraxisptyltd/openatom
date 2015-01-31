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

struct lb_framebuffer {
	uint32_t tag;
	uint32_t size;

	uint64_t physical_address;
	uint32_t x_resolution;
	uint32_t y_resolution;
	uint32_t bytes_per_line;
	uint8_t bits_per_pixel;
	uint8_t red_mask_pos;
	uint8_t red_mask_size;
	uint8_t green_mask_pos;
	uint8_t green_mask_size;
	uint8_t blue_mask_pos;
	uint8_t blue_mask_size;
	uint8_t reserved_mask_pos;
	uint8_t reserved_mask_size;
};

void udelay(unsigned usecs);
void mdelay(unsigned msecs);
void delay(unsigned secs);

#endif /* _COREBOOT_GLUE_H */
