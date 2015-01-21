#include "aruba.h"
#include "radeon_util.h"
#include "linux_glue.h"
//#include "ObjectID.h"
#include <stdbool.h>

#define EXTPLL_CTL			0x490

#define PLL_BLOCK_BASE			0x5c00

#define PLL_r0				0x00
#define PLL_r1				0x04
#define PLL_POST_DIV			0x08
#define PLL_SS_FRAC			0x0c
#define  SS_FRAC_MASK			0xffff
#define PLL_SS_CTL			0x10
#define  SS_SS_CTL_FBDIV_MASK		0xff
#define  SS_CTL_FBDIV(div)		((div) & SS_SS_CTL_FBDIV_MASK)
#define  SS_SS_CTL_NFRAC_MASK		(0xf << 8)
#define  SS_CTL_NFRAC(frac)		(((frac) << 8 ) & SS_SS_CTL_NFRAC_MASK)
#define  SS_CTL_ENABLE			BIT(12)
#define  SS_CTL_DOWNSPREAD		BIT(13)
#define  SS_SS_CTL_STEP_MASK		(0xffff << 16)
#define  SS_CTL_STEP(step)		(((step) << 16) & SS_SS_CTL_STEP_MASK)
#define PLL_r5				0x14
#define PLL_r6				0x18
#define PLL_r7				0x1c
#define PLL_r8				0x20
#define PLL_r9				0x24
#define PLL_ra				0x28
#define PLL_rb				0x2c
#define PLL_rc				0x30
#define PLL_rd				0x34
#define PLL_re				0x38
#define PLL_rf				0x3c

#define PLL_INVALID			(PLL_BLOCK_BASE + 0xff)



static uint32_t get_pll_base(uint8_t pll_id)
{
	static const uint8_t pll_offsets[] = {
		[PPLL_1] = 0x40,
		[PPLL_2] = 0x80,
		[PPLL_0] = 0
	};

	if (pll_id >= sizeof(pll_offsets)) {
		DRM_ERROR("Invalid PLL ID: %x\n", pll_id);
		return PLL_INVALID;
	}

	return PLL_BLOCK_BASE + pll_offsets[pll_id];
}

/**
 * Compute the PLL divider register value for wanted divisor
 *
 * @param[in,out]	div Desired divisor. Returns the actual divisor
 * 			This is given as four times the desired value of the
 * 			divisor as the divisor is granular to 0.25
 * @return	PLL register value for given divisor
 */
static uint8_t divider_to_pll_map(uint32_t *div_4x)
{
	uint8_t reg;
	static const struct pll_region {
		uint32_t div_min;	/* Min divider for this block */
		uint32_t div_max;	/* Max divider for this block */
		uint8_t reg_start;	/* Register value when div == div_min */
		uint8_t reg_gran;	/* Granularity in 0.25 units */
	} pll_regions[3] = { {   8,  64,  8, 1 },
			     {  64, 128, 64, 2 },
			     { 128, 248, 96, 4 } };
	const struct pll_region *data = pll_regions;

	*div_4x = min(*div_4x, pll_regions[2].div_max);
	*div_4x = max(*div_4x, pll_regions[0].div_min);

	while (*div_4x > data->div_max) {
		data++;
	}

	reg = DIV_ROUND_UP(*div_4x - data->div_min, data->reg_gran)
		+ data->reg_start;
	*div_4x = (reg - data->reg_start) * data->reg_gran + data->div_min;
	return reg;
}

/**
 * Compute the PLL divider register value for wanted divisor
 *
 * @param[in] vco_freq_mhz Frequency of the clock source VCO
 * @param[in,out] clock	Desired clock. Returns the actual clock
 * @return	PLL register value for given divisor
 */
uint8_t aruba_compute_engine_pll(uint32_t vco_freq_mhz, uint32_t *clock_khz)
{
	uint8_t pll_div;
	uint32_t div_4x = 0xff;

	if (*clock_khz != 0)
		div_4x = DIV_ROUND_UP(vco_freq_mhz * 4000, *clock_khz);

	pll_div = divider_to_pll_map(&div_4x);

	*clock_khz = (vco_freq_mhz * 4000) / div_4x;
	return pll_div;
}

void aruba_disable_pll_ss(struct radeon_device *rdev, uint8_t pll_id)
{
	uint32_t block = get_pll_base(pll_id);
	radeon_mask(rdev, block + PLL_SS_CTL, SS_CTL_ENABLE, 0);
	if ((radeon_read(rdev, block + PLL_r5) & 0xffff) == 0)
		radeon_mask(rdev, block + PLL_r5, (3 << 16), 0);
}

void aruba_enable_pll_ss(struct radeon_device *rdev, uint8_t pll_id,
			 uint16_t step, uint16_t ds_frac, uint8_t fbdiv,
			 uint8_t nfrac, bool downspread)
{
	uint32_t reg32;

	uint32_t block = get_pll_base(pll_id);

	/* Already enabled? */
	if (radeon_read(rdev, block + PLL_SS_CTL) & SS_CTL_ENABLE)
		return;

	radeon_mask(rdev, block + PLL_r7, BIT(3), 0);
	radeon_mask(rdev, block + PLL_r5, 3 << 16, 1 << 16);
	radeon_mask(rdev, block + PLL_SS_FRAC, SS_FRAC_MASK, ds_frac);

	reg32 = SS_CTL_STEP(step) | SS_CTL_NFRAC(nfrac) | SS_CTL_FBDIV(fbdiv);
	if (downspread)
		reg32 |= SS_CTL_DOWNSPREAD;
	reg32 |= SS_CTL_ENABLE;
	radeon_write(rdev, block + PLL_SS_CTL, reg32);

	udelay(1000);
	radeon_mask(rdev, block + PLL_r7, 0, BIT(3));
}

void shutdown_pll(struct radeon_device *rdev, uint8_t pll_id)
{
	uint32_t block = get_pll_base(pll_id);
	//   010c: CLEAR  reg[1706]  [XXXX]
	radeon_write(rdev, block + PLL_r6, 0);
	//   0110: AND    reg[1704]  [..X.]  <-  ef
	radeon_mask(rdev, block + PLL_SS_CTL, SS_CTL_ENABLE, 0);
	//   0115: CLEAR  reg[1705]  [XXXX]
	radeon_write(rdev, block + PLL_r5, 0);
	//   0119: CLEAR  reg[1703]  [XXXX]
	radeon_write(rdev, block + PLL_SS_FRAC, 0);
	//   011d: AND    reg[1707]  [...X]  <-  f7
	radeon_mask(rdev, block + PLL_r7, BIT(3), 0);
	//   0122: OR     reg[1707]  [...X]  <-  01
	radeon_mask(rdev, block + PLL_r7, 0, BIT(0));
	//   0127: DELAY_MicroSec  32
	udelay(50);
	//   0129: OR     reg[1707]  [...X]  <-  02
	radeon_mask(rdev, block + PLL_r7, 0, BIT(1));
	//   012e: DELAY_MicroSec  c8
	udelay(200);
	//   0130: OR     reg[1707]  [..X.]  <-  20
	radeon_mask(rdev, block + PLL_r7, 0, BIT(13));
}

static void program_pll_divisors(struct radeon_device *rdev, uint8_t pll_id,
				struct pll_settings *cfg)
{
	uint32_t block = get_pll_base(pll_id);
	uint8_t fixme;
	int timeout;

	// FIXME
	cfg->fb_div_frac |= BIT(24) | BIT(20);
	fixme = BIT(24) >> 24;
	//   01e8: OR     reg[170c]  [...X]  <-  01
	radeon_mask(rdev, block + PLL_rc, 0, BIT(0));
	//   01ed: MOVE   reg[1700]  [...X]  <-  param[01]  [X...]
	radeon_mask(rdev, block + PLL_r0, 0xff, cfg->ref_div);
	//   01f2: MOVE   reg[1701]  [XX..]  <-  param[01]  [..XX]
	radeon_mask(rdev, block + PLL_r1, 0xffff << 16, cfg->fb_div_int << 16);
	//   01f7: AND    reg[1701]  [...X]  <-  f0
	radeon_mask(rdev, block + PLL_r1, 0x0f, 0);
	//   01fc: MOVE   reg[1702]  [.X..]  <-  param[01]  [.X..]
	radeon_mask(rdev, block + PLL_POST_DIV, 0xff << 16, cfg->post_div << 16);
	//   0201: MOVE   reg[1702]  [...X]  <-  param[03]  [X...]
	radeon_mask(rdev, block + PLL_POST_DIV, 0xff, fixme);
	//   0206: MOVE   reg[1702]  [..X.]  <-  param[01]  [.X..]
	radeon_mask(rdev, block + PLL_POST_DIV, 0xff << 8, cfg->post_div << 8);

	//   020b: COMP   param[01]  [.X..]  <-  08
	//   020f: JUMP_Above  021c
	if (cfg->post_div <= 8) {
		//   0212: MOVE   reg[1706]  [.X..]  <-  param[01]  [.X..]
		radeon_mask(rdev, block + PLL_r6, 0xff << 16, cfg->post_div << 16);
		//   0217: OR     reg[1706]  [..X.]  <-  10
		radeon_mask(rdev, block + PLL_r6, 0, BIT(12));
	}
	//   021c: DELAY_MicroSec  64
	udelay(100);
	//   021e: CLEAR  reg[170c]  [...X]
	radeon_mask(rdev, block + PLL_rc, 0xff, 0);
	//   0222: AND    reg[1707]  [...X]  <-  fd
	radeon_mask(rdev, block + PLL_r7, BIT(1), 0);
	//   0227: DELAY_MilliSec  01
	udelay(1000);
	//   0229: AND    reg[1707]  [...X]  <-  fe
	radeon_mask(rdev, block + PLL_r7, BIT(0), 0);
	//   022e: AND    reg[1707]  [..X.]  <-  df
	radeon_mask(rdev, block + PLL_r7, BIT(13), 0);
	timeout = 10000;
	do {
		//   0233: DELAY_MicroSec  0a
		udelay(10);
		if (--timeout == 0) {
			DRM_ERROR("PLL lock timed out. This is bad and you know it");
			return;
		}
		//   0235: TEST   reg[1707]  [.X..]  <-  10
		//   023a: JUMP_Equal  0233
	} while (!(radeon_read(rdev, block + PLL_r7) & BIT(20)));
	//   023d: TEST   reg[1707]  [.X..]  <-  20
	//   0242: JUMP_Equal  023d
	timeout = 10000;
	while (!(radeon_read(rdev, block + PLL_r7) & BIT(21))) {
		udelay(10);
		if (!--timeout) {
			DRM_ERROR("PLL failed to lock. We are probably really fucked");
			break;
		}
	}
	//   0245: MOVE   reg[1701]  [...X]  <-  param[03]  [.X..]
	radeon_mask(rdev, block + PLL_r1, 0xff, (cfg->fb_div_frac >> 16) & 0xff);
	//   024a: COMP   param[03]  [..XX]  <-  0000
	//   024f: JUMP_Equal  025d
	if (cfg->fb_div_frac & 0xffff) {
		//   0252: MOVE   reg[1705]  [..XX]  <-  param[03]  [..XX]
		radeon_mask(rdev, block + PLL_r5, 0xffff, cfg->fb_div_frac & 0xffff);
		//   0257: MASK   reg[1705]  [.X..]  &  fc  |  02
		radeon_mask(rdev, block + PLL_r5, 3 << 16, 1 << 16);
	}
	//   025d: OR     reg[1707]  [...X]  <-  08
	radeon_mask(rdev, block + PLL_r7, 0, BIT(3));
}


#define ATOM_PPLL1            0
#define ATOM_PPLL2            1
#define ATOM_DCPLL            2
#define ATOM_PPLL0            2
#define ATOM_PPLL3            3

#define ATOM_EXT_PLL1         8
#define ATOM_EXT_PLL2         9
#define ATOM_EXT_CLOCK        10
#define ATOM_PPLL_INVALID     0xFF
//...//
#define PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL			0x01
#define PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL			0x01
#define PIXEL_CLOCK_V6_MISC_VGA_MODE				0x02
#define PIXEL_CLOCK_V6_MISC_REF_DIV_SRC				0x10
#define PIXEL_CLOCK_V6_MISC_WTF					0x20
#define PIXEL_CLOCK_V6_MISC_GEN_DPREFCLK			0x40

void aruba_init_pixel_pll(struct radeon_device * rdev, uint8_t pll_id)
{
	struct pll_settings pll_set = {
		.fb_div_int = 0x1b,
		.fb_div_frac = 0,
		.ref_div = 2,
		.post_div = 1,
	};

	uint8_t crtc_id = 0;
	uint32_t flags = 1;
	uint32_t px_clk = 76300;
	uint8_t encoder_mode = 0;

	aruba_set_pixel_clock(rdev, pll_id, &pll_set, crtc_id, px_clk, flags,
			      encoder_mode);
}

static uint32_t aruba_get_vga_ctl_offset(uint8_t block_id)
{
	static const uint32_t majika[] = {
		0, 0x4, 0x1c, 0x20, 0x2c, 0x30
	};
	return majika[block_id];
}

static void program_pll(struct radeon_device *rdev, uint8_t pll_id,
			struct pll_settings *pll_divs, uint32_t flags)
{
	uint32_t block;

	static const struct bigbaradata {
		uint16_t fb_div;
		uint32_t d2;
	} div_to_magic_tbl[] = {
		{ 0x24,		0xd5077604 },
		{ 0x2a,		0xd5077704 },
		{ 0x32,		0xd505d704 },
		{ 0x39,		0xd505d704 },
		{ 0x3f,		0xd506d804 },
		{ 0x46,		0xd506d804 },
		{ 0x4c,		0xd5063804 },
		{ 0x51,		0xd5045804 },
		{ 0x5a,		0xd5045904 },
		{ 0xffff,	0xd5045a04 },
	};
	const struct bigbaradata *pd;

	//   017b: MOVE   WS_REGPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   017f: SET_DATA_BLOCK  ff  (this table)
	//   0181: ADD    WS_DATAPTR [..XX]  <-  037e
	pd = div_to_magic_tbl;
	while (pll_divs->fb_div_int > pd->fb_div)
		//   0186: COMP   param[01]  [..XX]  <-  data[0000] [..XX]
		//   018b: JUMP_BelowOrEq  0196;
		//   018e: ADD    WS_DATAPTR [..XX]  <-  0006
		pd++;
	//   0193: JUMP   0186
	block = get_pll_base(pll_id);

	//   0196: MOVE   reg[1708]  [XXXX]  <-  data[0002] [XXXX]
	radeon_write(rdev, block + PLL_r8, pd->d2);
	//   019c: TEST   param[02]  [X...]  <-  20
	//   01a0: JUMP_Equal  01b0
	if (!(flags & PIXEL_CLOCK_V6_MISC_WTF)) {
		//   01a3: AND    reg[1707]  [.X..]  <-  f7
		radeon_mask(rdev, block + PLL_r7, BIT(19), 0);
		//   01a8: MOVE   reg[1700]  [..X.]  <-  60
		radeon_mask(rdev, block + PLL_r0, 0xff << 8, 0x60 << 8);
		//   01ad: JUMP   01ba
	} else {
		//   01b0: OR     reg[1707]  [.X..]  <-  08
		radeon_mask(rdev, block + PLL_r7, 0, BIT(19));
		//   01b5: MOVE   reg[1700]  [..X.]  <-  90
		radeon_mask(rdev, block + PLL_r0, 0xff << 8, 0x90 << 8);
	}
	//   01ba: AND    reg[170a]  [...X]  <-  fe
	radeon_mask(rdev, block + PLL_ra, BIT(0), 0);
	//   01bf: TEST   param[02]  [X...]  <-  40
	//   01c3: JUMP_NotEqual  01ce
	if (!(flags & PIXEL_CLOCK_V6_MISC_GEN_DPREFCLK))
		//   01c6: AND    reg[1709]  [..X.]  <-  f7
		radeon_mask(rdev, block + PLL_r9, BIT(11), 0);
		//   01cb: JUMP   01d3
	else
		//   01ce: OR     reg[1709]  [..X.]  <-  08
		radeon_mask(rdev, block + PLL_r9, 0, BIT(11));

	//   01d3: TEST   param[02]  [X...]  <-  10
	//   01d7: JUMP_Equal  01e2
	if (!(flags & PIXEL_CLOCK_V6_MISC_REF_DIV_SRC))
		//   01da: AND    reg[1707]  [.X..]  <-  f8
		radeon_mask(rdev, block + PLL_r7, 0x7 << 16, 0);
		//   01df: JUMP   01e8
	else
		//   01e2: MASK   reg[1707]  [.X..]  &  f8  |  01
		radeon_mask(rdev, block + PLL_r7, 0x7 << 16, BIT(16));

	program_pll_divisors(rdev, pll_id, pll_divs);
}

void aruba_set_pixel_clock(struct radeon_device *rdev, enum pll_ids pll_id,
			   struct pll_settings *pll_divs, uint8_t crtc_id,
			   uint32_t px_clk, uint32_t fags, uint8_t encoder_mode)
{
	uint32_t hdmi_clk_div, rem, win, off;

	static const struct bpc_d {
		uint8_t bpp_mul;
		uint8_t bpp_div;
	} bpc_tbl[] = {{0x01, 0x01}, {0x05, 0x04}, {0x03, 0x02}, {0x02, 0x01}};
	const struct bpc_d *bpc_s;

	px_clk /= 10;

	//   0006: COMP   cfg->ucPpll  <-  08
	//   000a: JUMP_NotEqual  00b4
	if (pll_id == ATOM_EXT_PLL1)
		/* Should have called aruba_set_disp_eng_pll you son of a bitch! */
		return;

	//   00b4: TEST   param[00]  [XXXX]  <-  00ffffff
	//   00bb: JUMP_Equal  00d9
	if (px_clk) {
		/* vvv TODO: KILLME NOT USED vvv
		 * //   00be: COMP   param[02]  [..X.]  <-  24
		 * //   00c2: JUMP_NotEqual  00c9
		 * if (cfg->ucTransmitterID == ENCODER_OBJECT_ID_INTERNAL_VCE)
		 *	//   00c5: MOVE   param[02]  [.X..]  <-  00
		 *	cfg->ucTransmitterID = ENCODER_OBJECT_ID_NONE;
		 */
		//   00c9: COMP   cfg->ucPpll  <-  02
		//   00cd: JUMP_Above  0262
		if (pll_id > ATOM_DCPLL)
			goto l_0262;
		//   00d0: CALL_TABLE  24  (GetPixelClock)
		//DRM_ERROR("GetPixelClock unimplemented.\n");
		//   00d2: TEST   param[02]  [X...]  <-  01
		//   00d6: JUMP_Equal  0143
		if (!(fags & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL))
			goto l_0143;
	}
	//   00d9: COMP   param[00]  [X...]  <-  03
	//   00dd: JUMP_Above  00f1
	if (crtc_id <= 3) {
		//   00e0: MOVE   WS_FB_WIN [XXXX]  <-  param[00]  [XXXX]
		//   00e4: MOVE   param[00]  [...X]  <-  param[00]  [X...]
		//   00e8: CLEAR  param[00]  [..X.]
		//   00eb: CALL_TABLE  23  (EnableCRTC)
		//   00ed: MOVE   param[00]  [XXXX]  <-  WS_FB_WIN [XXXX]
		aruba_enable_crtc(rdev, crtc_id, 0);
	}

	/* Lots of atom checks, but basically only continue with pll 0,1,2 */
	if (pll_id > ATOM_PPLL0)	// same as ATOM_DCPLL
		return;

	shutdown_pll(rdev, pll_id);
	//   0135: TEST   param[00]  [XXXX]  <-  00ffffff
	//   013c: JUMP_Equal  0377
	if (px_clk == 0)
		return;
	//   013f: MOVE   WS_REMIND/HI32 [..XX]  <-  WS_REGPTR [..XX]
 l_0143:
	//   0143: COMP   param[00]  [X...]  <-  03
	//   0147: JUMP_Above  0174
	if (crtc_id <= 3) {
		//   014a: MOVE   WS_FB_WIN [XXXX]  <-  param[00]  [XXXX]
		//   014e: MOVE   param[00]  [...X]  <-  param[00]  [X...]
		//   0152: OR     param[00]  [...X]  <-  80
		//   0156: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		off = aruba_get_vga_ctl_offset(crtc_id);
		//   0158: MOVE   param[00]  [XXXX]  <-  WS_FB_WIN [XXXX]
		//   015c: TEST   param[02]  [X...]  <-  02
		//   0160: JUMP_Equal  016e
		/* FIXME: PIXEL_CLOCK_V6_MISC_VGA_MODE is unused */
		if (fags & PIXEL_CLOCK_V6_MISC_VGA_MODE)
			//   0163: MOVE   reg[00cc]  [XXXX]  <-  00010301
			radeon_write(rdev, 0x330 + off, 0x10300 | BIT(0));
		//   016b: JUMP   0174
		else
			//   016e: AND    reg[00cc]  [.XX.]  <-  fefc
			radeon_mask(rdev, 0x330 + off, 0x10300, 0);
	}
	//   0174: TEST   param[02]  [X...]  <-  01
	//   0178: JUMP_Equal  0262
	if (fags & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL)
		program_pll(rdev, pll_id, pll_divs, fags);
 l_0262:
	//   0262: SET_REG_BLOCK  0000
	//   0265: COMP   param[00]  [X...]  <-  03
	//   0269: JUMP_Above  0377
	if (crtc_id > 3)
		return;
	//   026c: MOVE   WS_FB_WIN [XXXX]  <-  param[00]  [XXXX]
	//   0270: CLEAR  WS_FB_WIN [X...]
	//   0273: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0276: MOVE   WS_REMIND/HI32 [...X]  <-  param[02]  [X...]
	//   027a: AND    WS_REMIND/HI32 [...X]  <-  0c
	//   027e: SHIFT_RIGHT  WS_REMIND/HI32 [...X]  by  01
	//   0282: SET_DATA_BLOCK  ff  (this table)
	//   0284: ADD    WS_DATAPTR [..XX]  <-  03ba
	//   0289: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	bpc_s = &bpc_tbl[(fags & 0xc) >> 2]; // bit_depth << 1
	//   028d: MOVE   WS_REMIND/HI32 [...X]  <-  data[0001] [...X]
	//   0292: MUL    WS_FB_WIN [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   0296: MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	//   029b: DIV    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	/* FIXME: Isn't this just ((px_clk * bpp * 8) / 24); ? */
	hdmi_clk_div = (px_clk * bpc_s->bpp_div) / bpc_s->bpp_mul;
	//   029f: MOVE   WS_REMIND/HI32 [XXXX]  <-  05f5e100
	rem = 100000000;
	//   02a6: DIV    WS_REMIND/HI32 [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	hdmi_clk_div = rem / hdmi_clk_div;
	//   02aa: COMP   WS_QUOT/LOW32 [XXXX]  <-  00010000
	//   02b1: JUMP_Below  02b9
	if (hdmi_clk_div >= 0x00010000)
		//   02b4: MOVE   WS_QUOT/LOW32 [..XX]  <-  ffff
		hdmi_clk_div |= 0xffff;
	//   02b9: MOVE   param[00]  [...X]  <-  param[00]  [X...]
	//   02bd: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = aruba_get_block_offest(crtc_id);
	//   02bf: MOVE   reg[1b30]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	radeon_mask(rdev, 0x6cc0 + off, 0xffff, hdmi_clk_div & 0xffff);
	//   02c4: SET_REG_BLOCK  0000
	//   02c7: CLEAR  param[03]  [XXXX]
	//   02ca: MOVE   param[03]  [...X]  <-  param[00]  [X...]
	//   02ce: SHIFT_LEFT  param[03]  [..XX]  by  02
	//   02d2: COMP   param[02]  [.X..]  <-  00
	//   02d6: JUMP_NotEqual  0316
	if (encoder_mode == 0) {
		//   02d9: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
		off = crtc_id << 4;
		//   02dd: MUL    WS_FB_WIN [XXXX]  <-  0000ea60
		//   02e4: MOVE   WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		win = px_clk * 60000;
		//   02e8: COMP   reg[0141]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   02ed: JUMP_NotEqual  02f8
		if (radeon_read(rdev, 0x504 + off) == win) {
			//   02f0: TEST   reg[0140]  [...X]  <-  10
			//   02f5: JUMP_NotEqual  0377
			if (radeon_read(rdev, 0x500 + off) & BIT(4))
				return;
		};
		//   02f8: SET_REG_BLOCK  0000
		//   02fb: CLEAR  param[00]  [..X.]
		//   02fe: CALL_TABLE  23  (EnableCRTC)
		aruba_enable_crtc(rdev, crtc_id, 0);
		//   0300: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
		//   0304: AND    reg[0140]  [...X]  <-  ef
		radeon_mask(rdev, 0x500 + off, BIT(4), 0);
		//   0309: MOVE   reg[0141]  [XXXX]  <-  WS_FB_WIN [XXXX]
		radeon_write(rdev, 0x504 + off, win);
		//   030e: OR     reg[0140]  [...X]  <-  10
		radeon_mask(rdev, 0x500 + off, 0, BIT(4));
		//   0313: JUMP   0377
		return;
	}
	//   0316: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
	off = crtc_id << 4;
	//   031a: MOVE   WS_FB_WIN [...X]  <-  param[02]  [X...]
	//   031e: AND    WS_FB_WIN [...X]  <-  0c
	//   0322: SHIFT_LEFT  WS_FB_WIN [...X]  by  02
	//   0326: OR     WS_FB_WIN [...X]  <-  01
	win = (fags & 0x0c) << 2 | 1;
	//   032a: MOVE   param[02]  [.X..]  <-  cfg->ucPpll
	//   032e: ADD    param[02]  [.X..]  <-  01
	//   0332: COMP   cfg->ucPpll  <-  02
	//   0336: JUMP_NotEqual  033c
	if (pll_id == ATOM_PPLL0)
		//   0339: CLEAR  param[02]  [.X..]
		encoder_mode = 0;
	//   033c: TEST   param[02]  [X...]  <-  01
	//   0340: JUMP_NotEqual  035c
	if (!(fags & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL)) {
		//   0343: COMP   reg[0140]  [...X]  <-  param[02]  [.X..]
		//   0348: JUMP_NotEqual  0357
		if ((radeon_read(rdev, 0x500 + off) & 0xff) == (pll_id + 1)) {
			//   034b: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
			off = pll_id << 2;
			//   034f: COMP   reg[0138]  [...X]  <-  WS_FB_WIN [...X]
			//   0354: JUMP_Equal  0377
			if ((radeon_read(rdev, 0x4e0 + off) & 0xff) == win)
				return;
		}
		//   0357: CLEAR  param[00]  [..X.]
		//   035a: CALL_TABLE  23  (EnableCRTC)
		aruba_enable_crtc(rdev, crtc_id, 0);
	}
	//   035c: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
	off = pll_id << 2;
	//   0360: AND    reg[0138]  [...X]  <-  fe
	radeon_mask(rdev, 0x4e0 + off, BIT(0), 0);
	//   0365: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
	off = crtc_id << 4;
	//   0369: MOVE   reg[0140]  [...X]  <-  param[02]  [.X..]
	radeon_mask(rdev, 0x500 + off, 0xff, encoder_mode);
	//   036e: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
	off = pll_id << 2;
	//   0372: MOVE   reg[0138]  [...X]  <-  WS_FB_WIN [...X]
	radeon_mask(rdev, 0x4e0 + off, 0xff, win);
	//   0377: SET_REG_BLOCK  0000
	//   037a: EOT
	return;
	//   037b:
	//   037e: 2400047607d5 2a00047707d5 320004d705d5 390004d705d5 3f0004d806d5 4600
	//         04d806d5 4c00043806d5 5100045804d5 5a00045904d5 ffff045a04d5
	//   03ba: 0101050403020201
	//                           CTB_DS  68 bytes
}

enum divisor_type {
	DIV_REFCLOCK,
	DIV_ENGINE,
};

static int aruba_program_ext_pll(struct radeon_device *rdev, uint8_t pll,
				 enum divisor_type type)
{
	uint8_t shift;
	uint32_t lockbit;
	if (type == DIV_REFCLOCK) {
		shift = 24;
		lockbit = BIT(20);
	} else {
		shift = 0;
		lockbit = BIT(19);
	}

	/* Don't mess with PLL if it's already where we want it */
	if (((radeon_read(rdev, EXTPLL_CTL) >> shift) & 0xff) == pll)
		return 0;

	if (radeon_wait_set(rdev, EXTPLL_CTL, lockbit, 10000) < 0)
		return -ETIMEDOUT;

	radeon_mask(rdev, EXTPLL_CTL, 0xff << shift, pll << shift);

	if (radeon_wait_set(rdev, EXTPLL_CTL, lockbit, 10000) < 0)
		return -ETIMEDOUT;
	return 0;
}

int aruba_set_disp_eng_pll(struct radeon_device *rdev, uint32_t vco_freq_mhz,
			   uint32_t clock_khz, uint32_t default_clock_khz,
			   uint16_t pcie_ss_percent)
{
	const uint32_t rclock = 60000;

	uint8_t pll;
	uint32_t ohman, clock_fuck;

	//   000d: CLEAR  reg[1841]  [...X]
	radeon_mask(rdev, 0x1841 << 2, 0xff, 0);
	//   0011: CLEAR  reg[031f]  [...X]
	radeon_mask(rdev, 0x31f << 2, 0xff, 0);
	//   0015: MOVE   param[01]  [XXXX]  <-  param[00]  [XXXX]
	//   0019: CLEAR  param[01]  [X...]
	//   001c: MOVE   param[00]  [XXXX]  <-  0000ea60
	//   0023: CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	ohman = rclock * 10;
	pll = aruba_compute_engine_pll(vco_freq_mhz, &ohman);
	ohman /= 10;
	if (aruba_program_ext_pll(rdev, pll, DIV_REFCLOCK) < 0) {
		DRM_ERROR("Refclock EXTPLL failed to lock!!!");
		return -ETIMEDOUT;
	}
	//   0042: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0045: CLEAR  param[00]  [X...]
	//   0048: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   004a: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0110] [..XX]
	//   004f: MUL    param[00]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//quot = ohman * usPCIEClkSSPercentage;
	//   0053: DIV    WS_QUOT/LOW32 [XXXX]  <-  00004e20
	//quot /= ulDefaultEngineClock;
	//   005a: SUB    param[00]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	ohman -= ohman * pcie_ss_percent / default_clock_khz;
	//   005e: MUL    param[00]  [XXXX]  <-  0000ea60
	clock_fuck = ohman * rclock;
	//   0065: MOVE   reg[0142]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	radeon_write(rdev, 0x142 << 2, clock_fuck);
	//   006a: MOVE   reg[0146]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	radeon_write(rdev, 0x146 << 2, clock_fuck);
	//   006f: MOVE   reg[014a]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	radeon_write(rdev, 0x14a << 2, clock_fuck);
	//   0074: MOVE   reg[014e]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	radeon_write(rdev, 0x14e << 2, clock_fuck);
	//   0079: MOVE   param[00]  [XXXX]  <-  param[01]  [XXXX]
	//   007d: CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	ohman = clock_khz;
	pll = aruba_compute_engine_pll(vco_freq_mhz, &ohman);
	ohman /= 10;
	if (aruba_program_ext_pll(rdev, pll, DIV_ENGINE) < 0) {
		DRM_ERROR("Engine EXTPLL failed to lock!!!");
		return -ETIMEDOUT;
	}
	//   009c: COMP   param[01]  [XXXX]  <-  00000000
	//   00a3: JUMP_NotEqual  00b3
	if (clock_khz != 0)
		return 0;
	//   00a6: OR     reg[1841]  [...X]  <-  01
	radeon_mask(rdev, 0x1841 << 2, 0, 1);
	//   00ab: TEST   reg[1841]  [..X.]  <-  01
	//   00b0: JUMP_Equal  00ab
	if (radeon_wait_set(rdev, 0x1841 << 2, BIT(0), 10000) < 0)
		return -ETIMEDOUT;
	//   00b3: EOT
	return 0;
}
