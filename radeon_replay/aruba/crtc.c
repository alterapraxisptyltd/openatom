#include "aruba.h"
#include "radeon_util.h"
#include "linux_glue.h"

#include <errno.h>
#include <stdbool.h>

#define CRTC_CONTROL				0x6e70	// 0x1b9c
# define CRTC_MASTER_EN				BIT(0)

#define CRTC_BLANK_CONTROL			0x6e74	// 0x1b9d
# define CRTC_BLANK_DATA_EN			BIT(8)

#define GRPH_UPDATE				0x6844	// 1a11
# define GRPH_SURFACE_UPDATE_PENDING		BIT(2)
# define GRPH_UPDATE_LOCK			BIT(16)

#define CRTC_1a27				0x689c

#define CURSOR_UPDATE				0x69b8	// 1a6e
# define CURSOR_UPDATE_PENDING			BIT(0)
# define CURSOR_UPDATE_TAKEN			BIT(1)
# define CURSOR_UPDATE_LOCK			BIT(16)
# define CURSOR_DISABLE_MULTIPLE_UPDATE		BIT(24)

#define CRTC_1b7c				0x6df0

#define CRTC_H_BLANK_END			0x6e00
#define CRTC_H_BLANK_LEN			0x6e04
#define CRTC_H_SYNC_LEN				0x6e08
#define CRTC_H_SYNC_FLAGS			0x6e0c
# define H_SYNC_NHSYNC				BIT(0)
#define CRTC_V_BLANK_END			0x6e1c
#define CRTC_V_BLANK_LEN			0x6e34
#define CRTC_V_SYNC_LEN				0x6e38
#define CRTC_V_SYNC_FLAGS			0x6e3C
# define V_SYNC_NVSYNC				BIT(0)
#define CRTC_INTERLACE_FLAGS			0x6e78
# define INTERLACE_EN				BIT(0)

#define CRTC_STATUS				0x6e8c	// 1ba3
# define CRTC_V_BLANK				BIT(0)

#define CRTC_1ba9				0x6ea4

#define CRTC_UPDATE_LOCK			0x6ed4	// 1bb5
#define CRTC_1bb6				0x6ed8
#define CRTC_MASTER_UPDATE_LOCK			0x6ef4	// 1bbd

#define CRTC_H_OVERSCAN				0x6d78 // 1b5e
#define CRTC_V_OVERSCAN				0x6d7c // 1b5f


static int disable_crtc(struct radeon_device *rdev, uint8_t crtc_id)
{
	const uint32_t block = aruba_get_block_offest(crtc_id);
	radeon_mask(rdev, CRTC_CONTROL + block, 0, 0x300);
	radeon_mask(rdev, CRTC_CONTROL + block, CRTC_MASTER_EN, 0);
	if (radeon_wait_clear(rdev, CRTC_CONTROL + block, BIT(16), 1000) < 0) {
		DRM_ERROR("Timed out when disabling CRTC.");
		return -ETIMEDOUT;
	}
	radeon_mask(rdev, CRTC_1b7c + block, BIT(31), 0);
	radeon_mask(rdev, CRTC_1ba9 + block, 0xff, 0);
	return 0;
}

static void enable_crtc(struct radeon_device *rdev, uint8_t crtc_id)
{
	const uint32_t off = aruba_get_block_offest(crtc_id);
	radeon_mask(rdev, CRTC_1b7c + off, 0, BIT(31));
	radeon_mask(rdev, CRTC_CONTROL + off, 0, CRTC_MASTER_EN);
}

int aruba_enable_crtc(struct radeon_device *rdev, uint8_t crtc_id, bool enable)
{
	if (enable)
		enable_crtc(rdev, crtc_id);
	else
		return disable_crtc(rdev, crtc_id);

	return 0;
}

int aruba_update_crtc_x2_buf(struct radeon_device *rdev,
			     uint8_t crtc_id, bool enable)
{
	int ret;
	const uint32_t block = aruba_get_block_offest(crtc_id);

	radeon_mask(rdev, CRTC_1bb6 + block, BIT(8), 0);

	if (enable) {
		radeon_mask(rdev, CRTC_MASTER_UPDATE_LOCK + block, 0, BIT(0));
		radeon_write(rdev, CRTC_INTERLACE_FLAGS + block, 0);
		radeon_mask(rdev, 0x4c8, 0, BIT(0));
	} else {
		radeon_mask(rdev, CURSOR_UPDATE + block, 0xff << 16, 0);
		radeon_mask(rdev, CRTC_1a27 + block, 0xff << 16, 0);
		radeon_mask(rdev, GRPH_UPDATE + block, 0xff << 16, 0);
		radeon_mask(rdev, CRTC_UPDATE_LOCK + block, 0xff, 0);
		radeon_mask(rdev, CRTC_MASTER_UPDATE_LOCK + block, 0xff, 0);
		ret = radeon_wait_clear(rdev, CRTC_1bb6 + block, BIT(0), 10000);
		if (ret < 0) {
			DRM_ERROR("Timed out waiting for CRTC");
			return -ETIMEDOUT;
		}
	}
	return 0;

}

int aruba_blank_crtc(struct radeon_device *rdev, uint8_t crtc_id, bool enable)
{
	int ret;
	uint32_t setmask;
	uint32_t block = aruba_get_block_offest(crtc_id);

	radeon_mask(rdev, CRTC_BLANK_CONTROL + block, 0xff << 16, 0);

	setmask = enable ? CRTC_BLANK_DATA_EN : 0;
	radeon_mask(rdev, CRTC_BLANK_CONTROL + block, 0xff << 8, setmask);

	if (!enable)
		return 0;

	if (!(radeon_read(rdev, CRTC_CONTROL + block) & BIT(16)))
		return 0;

	/* FIXME: Use some better wait function that's not based on udelay(1) */
	ret = radeon_wait_clear(rdev, CRTC_STATUS + block, CRTC_V_BLANK, 50000);
	if (ret < 0) {
		DRM_ERROR("CRTC timed out waiting for first VACTIVE");
		return -ETIMEDOUT;
	}

	ret = radeon_wait_set(rdev, CRTC_STATUS + block, CRTC_V_BLANK, 50000);
	if (ret < 0) {
		DRM_ERROR("CRTC timed out waiting for VBLANK");
		return -ETIMEDOUT;
	}

	ret = radeon_wait_clear(rdev, CRTC_STATUS + block, CRTC_V_BLANK, 50000);
	if (ret < 0) {
		DRM_ERROR("CRTC timed out waiting for second VACTIVE");
		return -ETIMEDOUT;
	}

	return 0;

}

void aruba_set_crtc_dtd_timing(struct radeon_device *rdev, uint8_t crtc_id,
			       struct drm_display_mode *mode)
{
	uint8_t r8;
	uint16_t val16;
	uint32_t reg32;
	const uint32_t block = aruba_get_block_offest(crtc_id);

	val16 = mode->crtc_hblank_end - 1;
	radeon_mask(rdev, CRTC_H_BLANK_END + block, 0xffff, val16);

	val16 = mode->crtc_hsync_end - mode->crtc_hsync_start;
	radeon_write(rdev, CRTC_H_SYNC_LEN + block, val16 << 16);

	val16 = mode->crtc_hblank_end - mode->crtc_hsync_start;
	reg32 = ((val16 + mode->crtc_hdisplay) & 0xffff) | (val16 << 16);
	radeon_write(rdev, CRTC_H_BLANK_LEN  + block, reg32);

	r8 = (mode->flags & DRM_MODE_FLAG_NHSYNC) ? H_SYNC_NHSYNC : 0;
	radeon_mask(rdev, CRTC_H_SYNC_FLAGS + block, 0xff, r8);

	val16 = mode->crtc_vblank_end - 1;
	radeon_mask(rdev, CRTC_V_BLANK_END + block, 0xffff, val16);

	val16 = mode->crtc_vsync_end - mode->crtc_vsync_start;
	radeon_write(rdev, CRTC_V_SYNC_LEN + block, val16 << 16);

	val16 = mode->crtc_vblank_end - mode->crtc_vsync_start;
	reg32 = ((val16 + mode->crtc_vdisplay) & 0xffff) | (val16 << 16);
	radeon_write(rdev, CRTC_V_BLANK_LEN + block, reg32);

	r8 = (mode->flags & DRM_MODE_FLAG_NVSYNC) ? V_SYNC_NVSYNC : 0;
	radeon_mask(rdev, CRTC_V_SYNC_FLAGS + block, 0xff, r8);

	r8 = (mode->flags & DRM_MODE_FLAG_INTERLACE) ? INTERLACE_EN : 0;
	radeon_mask(rdev, CRTC_INTERLACE_FLAGS + block, 0xff, r8);
}

void aruba_overscan_setup(struct radeon_device *rdev, uint8_t crtc_id,
			  uint8_t h_border, uint8_t v_border)
{
	uint32_t reg32;
	uint32_t block = aruba_get_block_offest(crtc_id);

	reg32 = (h_border << 16) | h_border;
	radeon_write(rdev, CRTC_H_OVERSCAN + block, reg32);

	reg32 = (v_border << 16) | v_border;
	radeon_write(rdev, CRTC_V_OVERSCAN + block, reg32);
}
