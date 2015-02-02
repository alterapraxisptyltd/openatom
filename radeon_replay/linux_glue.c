#include "linux_glue.h"

static struct radeon_device my_rdev = {
	.dummy = 0,
};

static struct drm_device my_drm = {
	.dev_private = &my_rdev,
};

struct radeon_i2c_chan my_i2c = {
	.dev = &my_drm,
	.rec = {
		.i2c_id = 0,
		.hpd = 0,
	},
};
