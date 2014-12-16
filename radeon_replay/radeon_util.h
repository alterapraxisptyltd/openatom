#ifndef __RADEON_UTIL_H
#define __RADEON_UTIL_H

#include <stdint.h>

void sync_read(void);
uint32_t radeon_read(uint32_t reg_addr);
void radeon_write(uint32_t reg_addr, uint32_t value);
uint32_t radeon_read_sync(uint32_t reg_addr);
void radeon_write_sync(uint32_t reg_addr, uint32_t value);
void radeon_delay(uint32_t internal_timer);
void radeon_udelay(uint32_t usec);

static uint32_t radeon_reg_read(uint32_t reg_addr)
{
	return radeon_read_sync(reg_addr << 2);
}

static void radeon_reg_write(uint32_t reg_addr, uint32_t value)
{
	radeon_write_sync(reg_addr << 2, value);
}

void run_radeon_tests(void);

#endif /* RADEON_UTIL */
