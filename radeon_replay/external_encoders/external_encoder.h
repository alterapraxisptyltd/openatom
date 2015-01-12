#ifndef __EXTERNAL_ENCODER_H
#define __EXTERNAL_ENCODER_H

#include "linux_glue.h"

#include <stdint.h>

/*
 * These do not match any atombios definitions because AMD keeps changing the
 * flags for no good reason.
 */
enum panel_props {
	PANEL_IS_FPDI = (1 << 0),
	PANEL_IS_DUAL_LINK = (1 << 1),
	PANEL_8_BPC = (1 << 2),
	PANEL_6_BPC = (1 << 3),
	PANEL_SWAP_CHANNELS = (1 << 4),
};

struct radeon_panel_timings {
	uint16_t digon_to_de_ms;
	uint16_t de_to_vary_bl_ms;
	uint16_t vary_bl_to_blon_ms;
	uint16_t de_to_digon_ms;
	uint16_t vary_bl_to_de_ms;
	uint16_t blon_to_vary_bl_ms;
	uint16_t off_delay_ms;
	uint32_t flags;
};

void travis_init(struct radeon_device *rdev, struct radeon_panel_timings *t);

#endif /* __EXTERNAL_ENCODER_H */
