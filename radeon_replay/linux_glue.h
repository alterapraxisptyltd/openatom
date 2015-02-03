/*
 * linux_glue.h: Provide a glue layer that allows our code to look more like
 * it were part of a linu driver *
 */
#ifndef _LINUX_GLUE_H
#define _LINUX_GLUE_H

#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

/* It may seem stupid to include a coreboot glue layer in the linux glue layer,
 * but the coreboot layer provides some delay functions which are also used by
 * linux. We've also modified the linux i2c structures to match the coreboot
 * definition.
 */
#include "coreboot_glue.h"
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

enum radeon_rmx_type {
	RMX_OFF,
	RMX_FULL,
	RMX_CENTER,
	RMX_ASPECT
};

extern struct radeon_i2c_chan my_i2c;
extern struct drm_dp_aux my_aux;

#endif /* _LINUX_GLUE_H */
