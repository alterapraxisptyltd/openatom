#ifndef __RADEON_UTIL_H
#define __RADEON_UTIL_H

#include <stdint.h>
#include <errno.h>

#include "coreboot_glue.h"

#define min(a,b) ((a) < (b) ? (a) : (b))
#define max(a,b) ((a) > (b) ? (a) : (b))

/*
 * This is an intentionally opaque type. Most code should not need to access
 * its members. This allows us to ensure compatibility of radeon_replay with
 * both coreboot and linux at all but the lowest levels.
 */
struct radeon_device;

void radeon_enable_iotracing(void);
void radeon_disable_iotracing(void);

void run_radeon_tests(void);
void radeon_init_mmio(void);

uint32_t radeon_read(struct radeon_device *rdev, uint32_t reg);
void radeon_write(struct radeon_device *rdev, uint32_t reg, uint32_t value);
uint32_t radeon_read_io(struct radeon_device *rdev, uint32_t reg);
void radeon_write_io(struct radeon_device *rdev, uint32_t reg, uint32_t value);

static inline
void radeon_mask(struct radeon_device *rdev, uint32_t reg, uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32 = radeon_read(rdev, reg);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	radeon_write(rdev, reg, reg32);
}


inline static
void radeon_mask_io(struct radeon_device *rdev, uint32_t reg, uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32 = radeon_read_io(rdev, reg);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	radeon_write_io(rdev, reg, reg32);
}

/**
 * \brief Wait until a bit is set by the hardware
 *
 * Wait until the bit specified in 'bitmask' is set by the hardware within a
 * given timeout. This function is meant to be used in places where very small
 * delays are expected, on the order of a few microseconds. If more than a bit
 * is specified in 'bitmask' this function only waits until one bit is set.
 *
 * @return -ETIMEDOUT on a timeout, or zero otherwise
 */
static inline
int radeon_wait_set(struct radeon_device *rdev, uint32_t reg, uint32_t bitmask,
		    unsigned int timeout_us)
{
	while (!(radeon_read(rdev, reg) & bitmask)) {
		if (!(timeout_us--))
			return -ETIMEDOUT;
		udelay(1);
	}
	return 0;
}

/**
 * \brief Wait until a bit is cleared by the hardware
 *
 * Wait until the bit specified in 'bitmask' is set by the hardware within a
 * given timeout. This function is meant to be used in places where very small
 * delays are expected, on the order of a few microseconds. If more than a bit
 * is specified in 'bitmask' this function waits until all the bits are cleared.
 *
 * @return -ETIMEDOUT on a timeout, or zero otherwise
 */
static inline
int radeon_wait_clear(struct radeon_device *rdev, uint32_t reg,
		      uint32_t bitmask, unsigned int timeout_us)
{
	while (radeon_read(rdev, reg) & bitmask) {
		if (!(timeout_us--))
			return -ETIMEDOUT;
		udelay(1);
	}
	return 0;
}

#endif /* RADEON_UTIL */
