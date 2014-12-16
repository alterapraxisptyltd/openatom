#ifndef __RADEON_INIT_NATIVE_H
#define __RADEON_INIT_NATIVE_H

#include <stdint.h>

int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len);
int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
		    uint8_t *dest, uint8_t start, uint16_t len);
void asic_init(void);

#endif	/* __RADEON_INIT_NATIVE_H */
