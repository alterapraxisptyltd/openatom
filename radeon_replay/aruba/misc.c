#include "aruba.h"
#include "radeon_util.h"
#include "linux_glue.h"

#include <stdbool.h>

/*
 * There are a number of register blocks. Each block contains one crtc, one
 * encoder, one transmitter, etc. One of everything. If the display path uses
 * CRTC 2, with encoder 0, and transmitter 4, then each will be found in blocks
 * 2, 0, and 4, respectively. This function returns the offset from block 0.
 *
 * There is no bounds check. It is the caller's job to pass a valid block_id.
 */
uint32_t aruba_get_block_offest(uint8_t block_id)
{
	static const uint32_t blocks[] = {
		0, 0xc00, 0x9800, 0xa400, 0xb000, 0xbc00 };
	return blocks[block_id];
}

static void crtc_pwrgate_en(struct radeon_device *rdev, uint8_t crtc_id)
{
	uint32_t block = crtc_id << 4;
	if (crtc_id < 2)
		return;
	radeon_mask(rdev, 0x5d80 + block, 0xffff, 0);
	radeon_mask(rdev, 0x5d84 + block, 0, BIT(0));
}

void aruba_powergate_crtc(struct radeon_device *rdev, uint8_t crtc_id,
			  bool enable)
{
	unsigned int timeout_us;
	uint32_t block = crtc_id << 4;

	if (enable) {
		crtc_pwrgate_en(rdev, crtc_id);
		return;
	}

	if (crtc_id >= 2) {
		radeon_mask(rdev, 0x5d84 + block, 0xff, 0);

		timeout_us = 10;
		while ((radeon_read(rdev, 0x5d88 + block) >> 24) != 0x30) {
			if (!timeout_us--) {
				DRM_ERROR("Timeout waiting for CRTC powergate");
				break;
			}
			udelay(1);
		}
	}

	radeon_mask(rdev, 0xbe8 + (crtc_id << 2), 0xffff, BIT(1));

	block = aruba_get_block_offest(crtc_id);
	radeon_mask(rdev, 0x6ef8 + block, 0xff, BIT(1));
	radeon_mask(rdev, 0x6b00 + block, BIT(24), BIT(25));
	radeon_mask(rdev, 0x6a44 + block, 0xff, 0x11);
	radeon_mask(rdev, 0x69f4 + block, 0xff, BIT(0));
	radeon_mask(rdev, 0x6cd0 + block, 0, BIT(0));
	radeon_write(rdev, 0x6bd8 + block, 1);
	radeon_mask(rdev, 0x6ed8 + block, 0, BIT(16));
	radeon_write(rdev, 0x6cc4 + block, 0x04000800);
	radeon_mask(rdev, 0x6f14 + block, 0xff, 0x06);
	radeon_mask(rdev, 0x6e18 + block, 0xffff, BIT(2));
}

void aruba_scaler_setup(struct radeon_device *rdev, uint8_t crtc_id,
			enum radeon_rmx_type rmx_type)
{
	uint8_t reg_val = 0;
	const uint32_t block = aruba_get_block_offest(crtc_id);

	radeon_mask(rdev, 0x6b00 + block, BIT(0), 0);
	radeon_mask(rdev, 0x6d44 + block, 0, BIT(16));
	radeon_mask(rdev, 0x6d50 + block, 0xff, 0);
	radeon_mask(rdev, 0x6d14 + block, 0xff, 0);

	switch (rmx_type) {
	default:		/* Fall through */
	case RMX_OFF:
		reg_val = 1;
	case RMX_CENTER:	/* Fall through */
		radeon_mask(rdev, 0x6d14 + block, 0xff, reg_val + 1);
		radeon_mask(rdev, 0x6d08 + block, 0xff, 0);
		radeon_write(rdev, 0x6d0c + block, 0);
		radeon_write(rdev, 0x6d1c + block, 0);
		break;
	case RMX_FULL:		/* Fall through */
	case RMX_ASPECT:
		radeon_mask(rdev, 0x6d0c + block, 0xffff, 0x0101);
		radeon_write(rdev, 0x6d1c + block, 0x00010001);
		radeon_mask(rdev, 0x6d28 + block, 0xffff << 8, 0x0301 << 8);
		radeon_mask(rdev, 0x6d38 + block, 0xffff << 8, 0x0301 << 8);
		radeon_mask(rdev, 0x6d4c + block, 0xffff, 0x1010);
		radeon_mask(rdev, 0x6d08 + block, 0xff, BIT(0));
		break;
	}

	radeon_mask(rdev, 0x6d44 + block, 0xff << 16, 0);
}

