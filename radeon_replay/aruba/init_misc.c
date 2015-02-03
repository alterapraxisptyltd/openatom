/*
 * Miscellaneous init helpers that are used by asic_init only.
 */
#include "aruba.h"
#include "linux_glue.h"

void dynamic_clock_gating_init_hp_1035dx(struct radeon_device *rdev)
{
	radeon_write(rdev, 0x0c68, 0x66666666);
	radeon_write(rdev, 0x0c74, 0x002bc666);
	radeon_mask(rdev, 0x0bd8, 0x9fff08f, 0x2000f404);
	radeon_write(rdev, 0x0be4, 0x00022710);
	radeon_write(rdev, 0x0be0, 0x00040000);
	radeon_mask(rdev, 0x5c1c, BIT(12), BIT(11));	/* PLL WARNING!!! */
	radeon_write(rdev, 0x04ec, 0x01120464);
	radeon_write(rdev, 0x04c0, 0x001186a0);
	radeon_write(rdev, 0x5ee8, 0x00640018);
	radeon_write(rdev, 0x04c4, 0x0801003c);
	radeon_mask(rdev, 0x0350, 0xff << 8, 2 << 8);
	radeon_mask(rdev, 0x03f0, 0xffff, 0x0100);
	radeon_write(rdev, 0x6428, 0x0000000f);
	radeon_write(rdev, 0x60e0, 0x30000000);
	/* Just continue if this step times out. Nothing we can do about it. */
	radeon_wait_clear(rdev, 0x5df8, BIT(0), 10);
	radeon_write(rdev, 0x5df4, 0x00002000);
	radeon_write(rdev, 0x5df0, 0x100010ff);
}
