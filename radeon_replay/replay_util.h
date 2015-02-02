/*
 * Accessors used by replay traces. These should never be used anywhere else.
 */

#ifndef __REPLAY_UTIL_H
#define __REPLAY_UTIL_H

#include "radeon_util.h"

void sync_read(void);
uint32_t radeon_read_old(uint32_t reg_addr);
void radeon_write_old(uint32_t reg_addr, uint32_t value);
uint32_t radeon_read_sync(uint32_t reg_addr);
void radeon_write_sync(uint32_t reg_addr, uint32_t value);
void radeon_delay(uint32_t internal_timer);
void radeon_udelay(uint32_t usec);

uint32_t radeon_reg_read(uint32_t reg_addr);
void radeon_reg_write(uint32_t reg_addr, uint32_t value);
void radeon_reg_mask(uint32_t reg, uint32_t clrbits, uint32_t setbits);

#endif /* __REPLAY_UTIL_H */
