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
#define DIV_ROUND_UP(n,d)			(((n) + (d) - 1) / (d))

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

/* Video mode flags */
/* bit compatible with the xorg definitions. */
#define DRM_MODE_FLAG_PHSYNC			(1<<0)
#define DRM_MODE_FLAG_NHSYNC			(1<<1)
#define DRM_MODE_FLAG_PVSYNC			(1<<2)
#define DRM_MODE_FLAG_NVSYNC			(1<<3)
#define DRM_MODE_FLAG_INTERLACE			(1<<4)
#define DRM_MODE_FLAG_DBLSCAN			(1<<5)
#define DRM_MODE_FLAG_CSYNC			(1<<6)
#define DRM_MODE_FLAG_PCSYNC			(1<<7)
#define DRM_MODE_FLAG_NCSYNC			(1<<8)
#define DRM_MODE_FLAG_HSKEW			(1<<9) /* hskew provided */
#define DRM_MODE_FLAG_BCAST			(1<<10)
#define DRM_MODE_FLAG_PIXMUX			(1<<11)
#define DRM_MODE_FLAG_DBLCLK			(1<<12)
#define DRM_MODE_FLAG_CLKDIV2			(1<<13)

struct drm_display_mode {
	unsigned int type;

	/* Proposed mode values */
	int clock;		/* in kHz */
	int hdisplay;
	int hsync_start;
	int hsync_end;
	int htotal;
	int hskew;
	int vdisplay;
	int vsync_start;
	int vsync_end;
	int vtotal;
	int vscan;
	unsigned int flags;

	/* Addressable image size (may be 0 for projectors, etc.) */
	int width_mm;
	int height_mm;

	/* Actual mode we give to hw */
	int crtc_clock;		/* in KHz */
	int crtc_hdisplay;
	int crtc_hblank_start;
	int crtc_hblank_end;
	int crtc_hsync_start;
	int crtc_hsync_end;
	int crtc_htotal;
	int crtc_hskew;
	int crtc_vdisplay;
	int crtc_vblank_start;
	int crtc_vblank_end;
	int crtc_vsync_start;
	int crtc_vsync_end;
	int crtc_vtotal;

	int vrefresh;		/* in Hz */
	int hsync;		/* in kHz */
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
