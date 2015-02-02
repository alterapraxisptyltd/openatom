#ifndef __ARUBA_H
#define __ARUBA_H

#include <stdint.h>

/* dp_aux.c */
int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len);
int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
			   uint8_t *dest, uint8_t start, uint16_t len);

#endif	/* __ARUBA_H */
