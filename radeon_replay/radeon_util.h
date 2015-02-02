#ifndef __RADEON_UTIL_H
#define __RADEON_UTIL_H

#include <stdint.h>

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

void radeon_enable_iotracing(void);
void radeon_disable_iotracing(void);

void sync_read(void);
uint32_t radeon_read_old(uint32_t reg_addr);
void radeon_write_old(uint32_t reg_addr, uint32_t value);
uint32_t radeon_read_io_old(uint32_t reg_addr);
void radeon_write_io_old(uint32_t reg_addr, uint32_t value);
uint32_t radeon_read_sync(uint32_t reg_addr);
void radeon_write_sync(uint32_t reg_addr, uint32_t value);
void radeon_delay(uint32_t internal_timer);
void radeon_udelay(uint32_t usec);

uint32_t radeon_reg_read(uint32_t reg_addr);
void radeon_reg_write(uint32_t reg_addr, uint32_t value);
void radeon_reg_mask(uint32_t reg, uint32_t clrbits, uint32_t setbits);

void run_radeon_tests(void);
void radeon_init_mmio(void);

#endif /* RADEON_UTIL */
