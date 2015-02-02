#ifndef __RADEON_UTIL_H
#define __RADEON_UTIL_H

#include <stdint.h>

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

#endif /* RADEON_UTIL */
