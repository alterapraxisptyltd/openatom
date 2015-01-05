/*
 * linux_glue.h: Provide a glue layer that allows our code to look more like
 * it were part of a linu driver *
 */
#ifndef _LINUX_GLUE_H
#define _LINUX_GLUE_H

#include <errno.h>
#include <stdint.h>
#include <stdio.h>

#include "radeon_util.h"

#define BIT(x)					(1 << (x))

#define DRM_DEBUG_KMS(fmt, args...)				\
	do {							\
		fprintf(stderr, fmt"\n", ##args);		\
	} while (0)

#define DRM_ERROR(fmt, args...)					\
	do {							\
		fprintf(stderr, fmt"\n", ##args);		\
	} while (0)

struct drm_device {
	void *dev_private;
};

struct radeon_i2c_bus_rec {
	uint8_t i2c_id;
	uint8_t hpd;
};
struct radeon_i2c_chan {
	struct drm_device *dev;
	struct radeon_i2c_bus_rec rec;
};

struct radeon_device {
	int dummy;
};

extern struct radeon_i2c_chan my_i2c;

static inline
void aruba_write(struct radeon_device *rdev, uint32_t reg, uint32_t value)
{
	radeon_reg_write(reg >> 2, value);
}

static inline
uint32_t aruba_read(struct radeon_device *rdev, uint32_t reg)
{
	return radeon_reg_read(reg >> 2);
}

static inline
void aruba_mask(struct radeon_device *rdev, uint32_t reg, uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32 = radeon_read(reg);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	radeon_write(reg, reg32);
}

static inline
void aruba_write_io(struct radeon_device *rdev, uint32_t reg, uint32_t value)
{
	radeon_write_io(reg, value);
}

static inline
uint32_t aruba_read_io(struct radeon_device *rdev, uint32_t reg)
{
	return radeon_read_io(reg);
}


inline static
void aruba_mask_io(struct radeon_device *rdev, uint32_t reg, uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32 = radeon_read_io(reg);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	radeon_write_io(reg, reg32);
}

#endif /* _LINUX_GLUE_H */
