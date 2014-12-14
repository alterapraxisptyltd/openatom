#ifndef __RADEON_UTIL_H
#define __RADEON_UTIL_H

#include <stdint.h>

void udelay(uint32_t usecs);
void sync_read(void);
uint32_t radeon_read(uint32_t reg_addr);
void radeon_write(uint32_t reg_addr, uint32_t value);
uint32_t radeon_read_sync(uint32_t reg_addr);
void radeon_write_sync(uint32_t reg_addr, uint32_t value);
uint32_t radeon_delay(uint32_t internal_timer);

void run_radeon_tests(void);

#endif /* RADEON_UTIL */
