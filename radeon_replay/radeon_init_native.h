#ifndef __RADEON_INIT_NATIVE_H
#define __RADEON_INIT_NATIVE_H

#include <aruba/aruba.h>

struct logoman {
	size_t width;
	size_t height;
	size_t p;
	uint8_t *pixel_data;
};

void asic_init(void);

void radeon_init_aux_pads(struct radeon_device* rdev);
int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len);
int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
		    uint8_t *dest, uint8_t start, uint16_t len);

void radeon_dp_encoder_control(void);

void asic_init(void);

/* aruba_misc.c */
void dynamic_clock_gating_init(struct radeon_device *rdev);

#endif	/* __RADEON_INIT_NATIVE_H */
