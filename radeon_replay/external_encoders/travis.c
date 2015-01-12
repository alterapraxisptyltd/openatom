#include "external_encoder.h"
#include "linux_glue.h"
#include "drm_dp_helper.h"

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

#define TRAVIS_DPCD_IDX		0x5f0
#define TRAVIS_DPCD_DAT		0x5f2

#define REG_TRAVIS_ID_LOW	2
#define REG_TRAVIS_ID_HIGH	3

#define ID_RTD2132_LOW		0x20
#define ID_RTD2132_HIGH		0x31

struct initial_reg {
	uint16_t reg_addr;
	uint8_t reg_val;
};
#define TERMINATE 0xffff
#define DONT_CARE 0

/*
 * We don't worry about defaulting the timings in these registers, as we
 * overwrite those anyway. The other defaults are:
 *	- 8 bits per color
 *	- single-link (per color channel)
 *	- LVDS, not FPDI
 * 	- Links not swapped
 */
static const struct initial_reg rtd2132_registers[] = {
	{0x0005, 0x3d},	 //  0
	{0x001f, 0x03},	 //  1
	{0x00ba, 0x00},	 //  2
	{0x00bb, 0x08},	 //  3
	{0x00b1, 0x4b},	 //  4
	{0x0173, 0x69},	 //  5
	{0x019f, 0x24},	 //  6
	{0x0019, 0x33},	 //  7
	{0x0089, 0x39},	 //  8
	{0x00f8, 0x42},	 //  9 - bit 2: 0 = LVDS, 1 = FPDI; bit 3: 0 = 6pbc,1 = 8bpc
	{0x00f9, 0x01},	 //  a lane 0 PN map (?)
	{0x00fa, 0x23},	 //  b lane 1 PN map (?)
	{0x00fb, 0x45},	 //  c lane 2 PN map (?)
	{0x00fc, 0x67},	 //  d lane 3 PN map (?)
	{0x00fd, 0x89},	 //  e lane 4 PN map (?)
	{0x00fe, 0xab},	 //  f lane 5 PN map (?)
	{0x001d, 0x25},	 // 10
	{0x01c3, DONT_CARE},	 // 11
	{0x01c2, DONT_CARE},	 // 12
	{0x01c4, DONT_CARE},	 // 13
	{0x01c0, DONT_CARE},	 // 14
	{0x01c1, DONT_CARE},	 // 15
	{0x01b1, DONT_CARE},	 // 16
	{0x01bf, DONT_CARE},	 // 17
	{0x01b5, 0x63},	 // 18
	{0x01cb, 0x80},	 // 19
	{0x01b3, 0x00},	 // 1a - Spread-spectrum
	{0x01b2, 0x00},	 // 1b - Spread-spectrum
	{0x009f, 0x00},	 // 1c - dual = 0x10, single = 0
	{0x0183, 0x14},	 // 1d
	{0x00a7, 0xc2},	 // 1e
	{0x0171, 0x12},	 // 1f
	{0x0182, 0x5d},	 // 20
	{0x0189, 0x28},	 // 21
	{0x01be, 0x01},	 // 22
	{0x008a, 0x53},	 // 23
	{0x000a, 0x01},	 // 24
	{0x01d4, 0x10},	 // 25
	{0x00f3, 0x40},	 // 26
	{0x00f4, 0x3c},	 // 27 - dual = 0, single 0x3c
	{0x01b4, 0x04},	 // 28 - bit2 0 = 8bpc, 1 = 6bpc
	{0x00dc, 0x00},	 // 29
	{0x00dd, 0x00},	 // 2a
	{0x0191, 0x20},	 // 2b
	{0x00d1, 0x06},	 // 2c
	{0x00d6, 0x01},	 // 2d
	{0x01d2, 0x08},	 // 2e
	{0x01d3, 0x80},	 // 2f
	{TERMINATE, 0}
};

static const struct initial_reg travis_other_encoder_parameters[];
static const size_t other_travis_size;
static const struct initial_reg travis_other_encoder_parameters_v2[];
//static const struct initial_reg rtd2132_registers[];
static const struct initial_reg actual_rtd2132_registers[];

static uint8_t travis_read(struct radeon_device *rdev,
			   uint16_t reg)
{
	struct drm_dp_aux *aux = &my_aux;
	uint8_t val, buf[2] = { reg >> 8, reg & 0xff };

	/* TODO: error handling */
	drm_dp_dpcd_write(aux, TRAVIS_DPCD_IDX, buf, 2);
	drm_dp_dpcd_readb(aux, TRAVIS_DPCD_DAT, &val);
	return val;
}

static void travis_write(struct radeon_device *rdev,
			   uint16_t reg, uint8_t dat)
{
	struct drm_dp_aux *aux = &my_aux;
	uint8_t buf[3] = {reg >> 8, reg & 0xff, dat};

	/* TODO: error handling */
	drm_dp_dpcd_write(aux, TRAVIS_DPCD_IDX, buf, 3);
}

static void travis_get_some(uint8_t data[2])
{
	uint32_t win, adjusted_clk, rate_100khz;
	const uint32_t ss_percent = 100;
	const uint32_t ss_rate_khz = 4000;
	const uint32_t pixel_clock_khz = 76300;

	rate_100khz = ss_rate_khz / 100;

	win = ss_percent * ss_percent * rate_100khz * 1024 / 381;
	win += (ss_percent * rate_100khz) * 524288 / 625 * 16;

	adjusted_clk = pixel_clock_khz * 56;

	if (pixel_clock_khz > 16870)
		adjusted_clk >>= 1;
	if (pixel_clock_khz > 33750)
		adjusted_clk >>= 1;
	if (pixel_clock_khz > 67500)
		adjusted_clk >>= 1;
	if (pixel_clock_khz > 135000)
		adjusted_clk >>= 1;

	data[0] = (win / adjusted_clk) & 0xff;

	rate_100khz <<= 9;
	data[1] = (adjusted_clk / rate_100khz) & 0xff;
	data[1] |=  0x80;
}

static void process_travis_table(struct radeon_device *rdev,
				 const struct initial_reg *regs)
{
	while (regs->reg_addr != TERMINATE) {
		travis_write(rdev, regs->reg_addr, regs->reg_val);
		regs++;
	}
}

void travis_init(struct radeon_device *rdev, struct radeon_panel_timings *t)
{
	uint8_t id;
	size_t table_sz;
	const struct initial_reg *init_regs;
	/* Don't use malloc. 0x30 registers should be enough */
	struct initial_reg actual_regs[0x30];

	init_regs = travis_other_encoder_parameters;


	id = travis_read(rdev, REG_TRAVIS_ID_LOW);
	if (id == ID_RTD2132_LOW) {
		id = travis_read(rdev, REG_TRAVIS_ID_HIGH);
		if (id == ID_RTD2132_HIGH) {
			init_regs = rtd2132_registers;
			table_sz = sizeof(rtd2132_registers);
			DRM_DEBUG_KMS("Goog. We're where we think we're supposed to be\n");
		}
	}

	memcpy(actual_regs, init_regs, table_sz);

	actual_regs[0x11].reg_val = t->digon_to_de_ms / 4;
	actual_regs[0x12].reg_val = t->de_to_vary_bl_ms / 4;
	actual_regs[0x13].reg_val = t->vary_bl_to_blon_ms / 4;
	actual_regs[0x14].reg_val = t->de_to_digon_ms / 4;
	actual_regs[0x15].reg_val = t->vary_bl_to_de_ms / 4;
	actual_regs[0x16].reg_val = t->blon_to_vary_bl_ms / 4;
	actual_regs[0x17].reg_val = t->off_delay_ms / 4;

	if (t->flags & PANEL_IS_DUAL_LINK) {
		actual_regs[0x1c].reg_val |= 1 << 4;
		actual_regs[0x27].reg_val = 0;
	}
	if (t->flags & PANEL_IS_FPDI)
		actual_regs[0X09].reg_val |= BIT(2);

	if (t->flags & PANEL_8_BPC) {
		actual_regs[0x09].reg_val |= BIT(3);
		actual_regs[0x28].reg_val &= ~BIT(2);
	}

	if (t->flags & PANEL_SWAP_CHANNELS) {
		actual_regs[0x0a].reg_val = 0x67;
		actual_regs[0x0b].reg_val = 0x89;
		actual_regs[0x0c].reg_val = 0xab;
		actual_regs[0x0d].reg_val = 0x01;
		actual_regs[0x0e].reg_val = 0x23;
		actual_regs[0x0f].reg_val = 0x45;
	}

	process_travis_table(rdev, actual_regs);
}

static const struct initial_reg travis_other_encoder_parameters[] = {
	{0x0005, 0x3d},	 //  0
	{0x001f, 0x01},	 //  1
	{0x00ba, 0x00},	 //  2
	{0x00bb, 0x08},	 //  3
	{0x00b1, 0x4b},	 //  4
	{0x0173, 0x69},	 //  5
	{0x019f, 0x26},	 //  6
	{0x0019, 0x33},	 //  7
	{0x0089, 0x39},	 //  8
	{0x019e, 0x05},	 //  9
	{0x01cb, 0x80},	 //  a
	{0x0016, 0x44},	 //  b
	{0x00f1, 0x20},	 //  c
	{0x00dc, 0x00},	 //  d
	{0x00dd, 0x00},	 //  e
	{TERMINATE, 0}
};

static const struct initial_reg  travis_other_encoder_parameters_v2[] = {
	{0x0005, 0x3d},
	{0x001f, 0x03},	 //  0
	{0x00ba, 0x00},	 //  1
	{0x00bb, 0x08},	 //  2
	{0x00b1, 0x4b},	 //  3
	{0x0173, 0x69},	 //  4
	{0x019f, 0x24},	 //  5
	{0x0019, 0x33},	 //  6
	{0x0089, 0x39},	 //  7
	{0x00f8, 0x42},	 //  8
	{0x00f9, 0x01},	 //  9
	{0x00fa, 0x23},	 //  a
	{0x00fb, 0x45},	 //  b
	{0x00fc, 0x67},	 //  c
	{0x00fd, 0x89},	 //  d
	{0x00fe, 0xab},	 //  e
	{0x001d, 0x25},	 //  f
	{0x01c3, 0x07},	 // 10
	{0x01c2, 0x5a},	 // 11
	{0x01c4, 0x00},	 // 12
	{0x01c0, 0x07},	 // 13
	{0x01c1, 0x5a},	 // 14
	{0x01b1, 0x00},	 // 15
	{0x01bf, 0x7d},	 // 16
	{0x01b5, 0x63},	 // 17
	{0x01cb, 0x80},	 // 18
	{0x01b3, 0x00},	 // 19
	{0x01b2, 0x00},	 // 1a
	{0x009f, 0x10},	 // 1b
	{0x0183, 0x14},	 // 1c
	{0x00a7, 0xc2},	 // 1d
	{0x0171, 0x12},	 // 1e
	{0x0182, 0x5d},	 // 1f
	{0x0189, 0x24},	 // 20
	{0x01be, 0x01},	 // 21
	{0x008a, 0x53},	 // 22
	{0x000a, 0x01},	 // 23
	{0x01d4, 0x10},	 // 24
	{0x00f3, 0x40},	 // 25
	{0x00f4, 0x00},	 // 26
	{0x01b4, 0x00},	 // 27
	{0x00dc, 0x00},	 // 28
	{0x00dd, 0x00},	 // 29
	{0x0191, 0x20},	 // 2a
	{0x00d1, 0x06},	 // 2b
	{0x00d6, 0x01},	 // 2c
	{TERMINATE, 0}
};
