#include "aruba.h"
#include "radeon_util.h"

#define GENERAL_PWRMGT				0x670
# define GLOBAL_PWRMGT_EN			(1 << 0)

// LVDS_Info[39] == ucPowerSequenceVARY_BLtoBLON_in4Ms
// LVDS_Info[40] == ucPowerSequenceBLONtoVARY_BL_in4Ms
#define BLON_DELAYS	0x0303
void aruba_backlight_init(struct radeon_device *rdev, bool controls_edp)
{
	radeon_mask(rdev, 0x191b << 2, 0xffff, 0x0f9f);

	if (!controls_edp)
		return;

	radeon_write(rdev, 0x191c << 2, 0x78000001);
	radeon_mask(rdev, 0x191d << 2, 0xff, 0x74);
	/* FIXME: BLON_DELAYS is a hardcoded value */
	radeon_mask(rdev, 0x191d << 2, 0xffff << 8, BLON_DELAYS << 8);
	radeon_mask(rdev, 0x1919 << 2, 0, 1 << 25);
}

/*
 * bl_pwm_freq_hz is LVDS_Info[0032] [..XX] (usBacklightPWM)
 */
#define PWM_MAGIC_CONST 	25000000	// 0x017d7840
#define PWM_RESOLUTION		4095		// 0xfff

void aruba_backlight_control(struct radeon_device *rdev,
			      uint16_t bl_pwm_freq_hz, uint8_t bl_level)
{
	uint32_t ticks_per_cycle, cycle_div, adjusted_ticks, high_ctr;

	if (bl_pwm_freq_hz == 0)
		return;

	if (!(radeon_read(rdev, GENERAL_PWRMGT) & BIT(16)))
		radeon_mask(rdev, 0x1921 << 2, 0, 0x01);

	ticks_per_cycle = bl_pwm_freq_hz * PWM_RESOLUTION;
	cycle_div = DIV_ROUND_UP(PWM_MAGIC_CONST, ticks_per_cycle);

	radeon_mask(rdev, 0x191b << 2, 0xffff << 16, cycle_div << 16);

	/*
	 * Mathematically, this comes out to be exactly PWM_RESOLUTION, but
	 * after rounding, we may end up with a slightly different resolution.
	 * Doing things this way gets us closer to the desired PWM frequency.
	 */
	adjusted_ticks = PWM_MAGIC_CONST / (cycle_div * bl_pwm_freq_hz);

	radeon_mask(rdev, 0x1920 << 2, 0xff << 16, 0x0c << 16);
	radeon_mask(rdev, 0x1920 << 2, 0xffff, adjusted_ticks & 0xffff);

	high_ctr = adjusted_ticks * (bl_level + 1);
	high_ctr >>= 4;
	radeon_mask(rdev, 0x191e << 2, 0xffff, high_ctr & 0xffff);
	radeon_mask(rdev, 0x191e << 2, 0, 0xc0 << 24);

	radeon_mask(rdev, 0x1921 << 2, (1 << 0), 0);
	while (radeon_read(rdev, 0x1921 << 2) & BIT(8))
		udelay(10);

	// 	fprintf(stderr, "0x%x\t0x%x\t0x%x\n%u\t%u\t%u\n", cycle_div, cycle_ctr, high_ctr, cycle_div, cycle_ctr, high_ctr);
	// 	fprintf(stderr, "ticks_per_cycle vs cycle_ctr %u\t%u\n", ticks_per_cycle, cycle_ctr);
}

void aruba_backlight_blon(struct radeon_device *rdev)
{
	if (radeon_read(rdev, 0x1919 << 2) & BIT(24))
		return;

	udelay(50000);

	if (((radeon_read(rdev, 0x191d << 2) >> 8) & 0xff) == 0) {
		radeon_mask(rdev, 0x191d << 2, 0, 0x03 << 24);
	} else {
		radeon_mask(rdev, 0x1940 << 2, 0, (1 << 16));
		radeon_mask(rdev, 0x1919 << 2, 0, 0x03 << 24);
		udelay(4000);
		radeon_mask(rdev, 0x1940 << 2, (1 << 16), 0);
	}
}

// LVDS_Info[0x40] "usMaxPclkFreqInSingleLink"
void aruba_backlight_bloff(struct radeon_device *rdev)
{
	if (!(radeon_read(rdev, 0x1919 << 2) & BIT(24)))
		return;

	if (((radeon_read(rdev, 0x191d << 2) >> 8) & 0xff) != 0) {
		radeon_mask(rdev, 0x1940 << 2, 0, 0x01 << 16);
		udelay(40000);
		radeon_mask(rdev, 0x1919 << 2, (1 << 24), (1 << 25));
		radeon_mask(rdev, 0x1940 << 2, (1 << 16), 0);
	} else {
		radeon_mask(rdev, 0x1919 << 2, (1 << 24), (1 << 25));
	}
	udelay(1000);
}
