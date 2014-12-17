#ifndef __RADEON_INIT_NATIVE_H
#define __RADEON_INIT_NATIVE_H

#include <stdint.h>

int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len);

#endif	/* __RADEON_INIT_NATIVE_H */
