#include "radeon_util.h"
#include "linux_glue.h"
#include "ObjectID.h"
#include "radeon_init_native.h"
#include <stdbool.h>


#define PLL_BLOCK_BASE			0x5c00

#define PLL_r0				0x00
#define PLL_r1				0x04
#define PLL_r2				0x08
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

enum pll_ids {
	PPLL_1 = 0,
	PPLL_2 = 1,
	PPLL_0 = 2,
};

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
#define DIV_UP(x, y)	(((x) + (y) - 1) / (y))
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

	reg = DIV_UP(*div_4x - data->div_min, data->reg_gran) + data->reg_start;
	*div_4x = (reg - data->reg_start) * data->reg_gran + data->div_min;
	return reg;
}

/**
 * Compute the PLL divider register value for wanted divisor
 *
 * @param[in,out] clock	Desired clock. Returns the actual clock
 * @return	PLL register value for given divisor
 */
#define dentist_freq 3600
uint8_t aruba_compute_engine_pll(uint32_t *clock_khz)
{
	uint8_t pll_div;
	uint32_t div_4x = 0xff;

	if (*clock_khz != 0)
		div_4x = DIV_UP(dentist_freq * 4000, *clock_khz);

	pll_div = divider_to_pll_map(&div_4x);

	*clock_khz = (dentist_freq * 4000) / div_4x;
	return pll_div;
}

// command_table  0000e504  #41  (EnableSpreadSpectrumOnPPLL):
//
//   Size         0074
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 03
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0
//
void aruba_disable_pll_ss(struct radeon_device *rdev, uint8_t pll_id)
{
	uint32_t block = get_pll_base(pll_id);
	//   0027: AND    reg[1704]  [..X.]  <-  ef
	aruba_mask(rdev, block + PLL_SS_CTL, SS_CTL_ENABLE, 0);
	//   002c: COMP   reg[1705]  [..XX]  <-  0000
	//   0032: JUMP_NotEqual  0070
	if ((aruba_read(rdev, block + PLL_r5) & 0xffff) == 0)
		//   0035: AND    reg[1705]  [.X..]  <-  fc
		aruba_mask(rdev, block + PLL_r5, (3 << 16), 0);
	//   003a: JUMP   0070
}

void aruba_enable_pll_ss(struct radeon_device *rdev, uint8_t pll_id,
			 uint16_t step, uint16_t ds_frac, uint8_t fbdiv,
			 uint8_t nfrac, bool downspread)
{
	uint32_t reg32;

	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: SET_REG_BLOCK  0010
	//   000c: TEST   param[00]  [.X..]  <-  0c
	//   0010: JUMP_Equal  0020
	//if (ucSpreadSpectrumType & ATOM_PPLL_SS_TYPE_V3_PPLL_SEL_MASK) {
	//if (pll_id != 0) DC_PPLL ATOM_PPLL0
		//   0013: SET_REG_BLOCK  0020
		//   0016: TEST   param[00]  [.X..]  <-  04
		//   001a: JUMP_NotEqual  0020
	//	if (!(ucSpreadSpectrumType & ATOM_PPLL_SS_TYPE_V3_P2PLL))
		//if (pll_id == 1) PPLL_1
			//   001d: SET_REG_BLOCK  0000
	//}
	uint32_t block = get_pll_base(pll_id);
	//   0020: COMP   param[00]  [X...]  <-  01
	//   0024: JUMP_Equal  003d

	//   003d: TEST   reg[1704]  [..X.]  <-  10
	//   0042: JUMP_NotEqual  0070
	if (aruba_read(rdev, block + PLL_SS_CTL) & SS_CTL_ENABLE)
		return;
	//   0045: AND    reg[1707]  [...X]  <-  f7
	aruba_mask(rdev, block + PLL_r7, BIT(3), 0);
	//   004a: MASK   reg[1705]  [.X..]  &  fc  |  01
	aruba_mask(rdev, block + PLL_r5, 3 << 16, 1 << 16);

	reg32 = SS_CTL_STEP(step) | SS_CTL_NFRAC(nfrac) | SS_CTL_FBDIV(fbdiv);
	// reg 32 |= SS_CTL_NFRAC(nfrac) | SS_CTL_FBDIV(fbdiv)
	//   0050: TEST   param[00]  [.X..]  <-  01
	//   0054: JUMP_NotEqual  005b
	if (downspread)
		//   0057: OR     param[01]  [..X.]  <-  20
		reg32 |= SS_CTL_DOWNSPREAD;
	//   005b: OR     param[01]  [..X.]  <-  10
	reg32 |= SS_CTL_ENABLE;
	//   005f: MOVE   reg[1703]  [..XX]  <-  param[00]  [..XX]
	aruba_mask(rdev, block + PLL_SS_FRAC, SS_FRAC_MASK, ds_frac);
	//   0064: MOVE   reg[1704]  [XXXX]  <-  param[01]  [XXXX]
	aruba_write(rdev, block + PLL_SS_CTL, reg32);
	//   0069: DELAY_MilliSec  01
	udelay(1000);
	//   006b: OR     reg[1707]  [...X]  <-  08
	aruba_mask(rdev, block + PLL_r7, 0, BIT(3));

	//   0070: SET_REG_BLOCK  0000
	//   0073: EOT
}

void shutdown_pll(struct radeon_device * rdev, uint8_t pll_id)
{
	uint32_t block = get_pll_base(pll_id);
	//   010c: CLEAR  reg[1706]  [XXXX]
	aruba_write(rdev, block + PLL_r6, 0);
	//   0110: AND    reg[1704]  [..X.]  <-  ef
	aruba_mask(rdev, block + PLL_SS_CTL, SS_CTL_ENABLE, 0);
	//   0115: CLEAR  reg[1705]  [XXXX]
	aruba_write(rdev, block + PLL_r5, 0);
	//   0119: CLEAR  reg[1703]  [XXXX]
	aruba_write(rdev, block + PLL_SS_FRAC, 0);
	//   011d: AND    reg[1707]  [...X]  <-  f7
	aruba_mask(rdev, block + PLL_r7, BIT(3) |  BIT(13), 0); // FIXME don't clear 13 here
	//   0122: OR     reg[1707]  [...X]  <-  01
	aruba_mask(rdev, block + PLL_r7, 0, BIT(0));
	//   0127: DELAY_MicroSec  32
	udelay(50);
	//   0129: OR     reg[1707]  [...X]  <-  02
	aruba_mask(rdev, block + PLL_r7, 0, BIT(1));
	//   012e: DELAY_MicroSec  c8
	udelay(200);
	//   0130: OR     reg[1707]  [..X.]  <-  20
	aruba_mask(rdev, block + PLL_r7, 0, BIT(13));
}

void fuck_again_with_pll(struct radeon_device * rdev, uint8_t pll_id,
			 uint8_t d2div)
{
}

void fuck_with_pll_config(struct radeon_device * rdev, uint8_t pll_id,
			  uint32_t frac_div, uint16_t int_div,
			  uint8_t ref_div, uint8_t post_div)
{
	uint32_t block = get_pll_base(pll_id);
	int timeout;

	// FIXME
	frac_div |= BIT(24) | BIT(20);
	//   01e8: OR     reg[170c]  [...X]  <-  01
	aruba_mask(rdev, block + PLL_rc, 0, BIT(0));
	//   01ed: MOVE   reg[1700]  [...X]  <-  param[01]  [X...]
	aruba_mask(rdev, block + PLL_r0, 0xff, ref_div);
	//   01f2: MOVE   reg[1701]  [XX..]  <-  param[01]  [..XX]
	aruba_mask(rdev, block + PLL_r1, 0xffff << 16, int_div << 16);
	//   01f7: AND    reg[1701]  [...X]  <-  f0
	aruba_mask(rdev, block + PLL_r1, 0x0f, 0);
	//   01fc: MOVE   reg[1702]  [.X..]  <-  param[01]  [.X..]
	aruba_mask(rdev, block + PLL_r2, 0xff << 16, post_div << 16);
	//   0201: MOVE   reg[1702]  [...X]  <-  param[03]  [X...]
	aruba_mask(rdev, block + PLL_r2, 0xff, frac_div >> 24);
	//   0206: MOVE   reg[1702]  [..X.]  <-  param[01]  [.X..]
	aruba_mask(rdev, block + PLL_r2, 0xff << 8, post_div << 8);

	//   020b: COMP   param[01]  [.X..]  <-  08
	//   020f: JUMP_Above  021c
	if (post_div <= 8) {
		//   0212: MOVE   reg[1706]  [.X..]  <-  param[01]  [.X..]
		aruba_mask(rdev, block + PLL_r6, 0xff << 16, post_div << 16);
		//   0217: OR     reg[1706]  [..X.]  <-  10
		aruba_mask(rdev, block + PLL_r6, 0, BIT(12));
	}
	//   021c: DELAY_MicroSec  64
	udelay(100);
	//   021e: CLEAR  reg[170c]  [...X]
	aruba_mask(rdev, block + PLL_rc, 0xff, 0);
	//   0222: AND    reg[1707]  [...X]  <-  fd
	aruba_mask(rdev, block + PLL_r7, BIT(1), 0);
	//   0227: DELAY_MilliSec  01
	udelay(1000);
	//   0229: AND    reg[1707]  [...X]  <-  fe
	aruba_mask(rdev, block + PLL_r7, BIT(0), 0);
	//   022e: AND    reg[1707]  [..X.]  <-  df
	aruba_mask(rdev, block + PLL_r7, BIT(13), 0);
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
	} while (!(aruba_read(rdev, block + PLL_r7) & BIT(20)));
	//   023d: TEST   reg[1707]  [.X..]  <-  20
	//   0242: JUMP_Equal  023d
	timeout = 10000;
	while (!(aruba_read(rdev, block + PLL_r7) & BIT(21))) {
		udelay(10);
		if (!--timeout) {
			DRM_ERROR("PLL failed to lock. We are probably really fucked");
			break;
		}
	}
	//   0245: MOVE   reg[1701]  [...X]  <-  param[03]  [.X..]
	aruba_mask(rdev, block + PLL_r1, 0xff, (frac_div >> 16) & 0xff);
	//   024a: COMP   param[03]  [..XX]  <-  0000
	//   024f: JUMP_Equal  025d
	if (frac_div & 0xffff) {
		//   0252: MOVE   reg[1705]  [..XX]  <-  param[03]  [..XX]
		aruba_mask(rdev, block + PLL_r5, 0xffff, frac_div & 0xffff);
		//   0257: MASK   reg[1705]  [.X..]  &  fc  |  02
		aruba_mask(rdev, block + PLL_r5, 3 << 16, 1 << 16);
	}
	//   025d: OR     reg[1707]  [...X]  <-  08
	aruba_mask(rdev, block + PLL_r7, 0, BIT(3));
}
// command_table  0000beb4  #0c  (SetPixelClock):
//
//   Size         03c2
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 06
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
typedef struct _CRTC_PIXEL_CLOCK_FREQ
{
	uint32_t  ulPixelClock:24;     // target the pixel clock to drive the CRTC timing.
	// 0 means disable PPLL/DCPLL. Expanded to 24 bits comparing to previous version.
	uint32_t  ucCRTC:8;            // ATOM_CRTC1~6, indicate the CRTC controller to
	// drive the pixel clock. not used for DCPLL case.
} CRTC_PIXEL_CLOCK_FREQ;
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
typedef struct _PIXEL_CLOCK_PARAMETERS_V6
{
	union{

		struct {
			uint32_t  ulPixelClock:24;     // target the pixel clock to drive the CRTC timing.
			// 0 means disable PPLL/DCPLL. Expanded to 24 bits comparing to previous version.
			uint32_t  ucCRTC:8;            // ATOM_CRTC1~6, indicate the CRTC controller to
			// drive the pixel clock. not used for DCPLL case.
		};
		uint32_t ulDispEngClkFreq;                  // dispclk frequency
	};

	/* param[01] */
	uint16_t usFbDiv;            // feedback divider integer part.
	uint8_t  ucPostDiv;          // post divider.
	uint8_t  ucRefDiv;           // Reference divider

	/* param[02] */
	uint8_t  ucPpll;             // ATOM_PPLL1/ATOM_PPLL2/ATOM_DCPLL
	uint8_t  ucTransmitterID;    // ASIC encoder id defined in objectId.h,
	// indicate which graphic encoder will be used.
	uint8_t  ucEncoderMode;      // Encoder mode:
	uint8_t  ucMiscInfo;         // bit[0]= Force program PPLL
	// bit[1]= when VGA timing is used.
	// bit[3:2]= HDMI panel bit depth: =0: 24bpp =1:30bpp, =2:32bpp
	// bit[4]= RefClock source for PPLL.
	// =0: XTLAIN( default mode )
	// =1: other external clock source, which is pre-defined
	//     by VBIOS depend on the feature required.
	// bit[7:5]: reserved.

	/* param[03] */
	union{

		struct {
			uint32_t  ulFbDivDecFrac:24;     // 20 bit feedback divider decimal fraction part, range from 1~999999 ( 0.000001 to 0.999999 )
			uint32_t  ucMagic:8;
		};
		uint32_t ulFracWithMagic;
	};

}PIXEL_CLOCK_PARAMETERS_V6;
void aruba_set_pixel_clock(struct radeon_device * rdev,
			   PIXEL_CLOCK_PARAMETERS_V6 *cfg);
void aruba_init_pixel_pll(struct radeon_device * rdev, uint8_t pll_id)
{
	PIXEL_CLOCK_PARAMETERS_V6 i_m_fucked = {
	.ulPixelClock = 7630,
	.ucCRTC = 0,
	.usFbDiv = 0x1b,
	.ucPostDiv = 1,
	.ucRefDiv = 2,
	.ucPpll = pll_id,
	.ucTransmitterID = 0,
	.ucEncoderMode = 0,
	.ucMiscInfo = 1,
	};

	/* This happens when pixel_clock is zero */
	aruba_set_pixel_clock(rdev, &i_m_fucked);
}

void aruba_set_pixel_clock(struct radeon_device * rdev,
			   PIXEL_CLOCK_PARAMETERS_V6 *cfg)
{
	uint32_t hdmi_clk_div, rem, win, block, regptr;

	static const struct bigbaradata {
		uint16_t fb_div;
		uint32_t d2;
	} data[] = {
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

	static const struct bpc_d {
		uint8_t bpp_mul;
		uint8_t bpp_div;
	} bpc_tbl[] = {{0x01, 0x01}, {0x05, 0x04}, {0x03, 0x02}, {0x02, 0x01}};
	const struct bpc_d *bpc_s;
	//   0006: COMP   cfg->ucPpll  <-  08
	//   000a: JUMP_NotEqual  00b4
	if (cfg->ucPpll == ATOM_EXT_PLL1)
		/* Should have called aruba_set_disp_eng_pll you son of a bitch! */
		return;

	//   00b4: TEST   param[00]  [XXXX]  <-  00ffffff
	//   00bb: JUMP_Equal  00d9
	if (cfg->ulPixelClock) {
		//   00be: COMP   param[02]  [..X.]  <-  24
		//   00c2: JUMP_NotEqual  00c9
		if (cfg->ucTransmitterID != ENCODER_OBJECT_ID_INTERNAL_VCE)
			//   00c5: MOVE   param[02]  [.X..]  <-  00
			cfg->ucTransmitterID = ENCODER_OBJECT_ID_NONE;
		//   00c9: COMP   cfg->ucPpll  <-  02
		//   00cd: JUMP_Above  0262
		if (cfg->ucPpll > ATOM_DCPLL)
			goto l_0262;
		//   00d0: CALL_TABLE  24  (GetPixelClock)
		//DRM_ERROR("GetPixelClock unimplemented.\n");
		//   00d2: TEST   param[02]  [X...]  <-  01
		//   00d6: JUMP_Equal  0143
		if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL))
			goto l_0143;
	}
	//   00d9: COMP   param[00]  [X...]  <-  03
	//   00dd: JUMP_Above  00f1
	if (cfg->ucCRTC <= 3) {
		//   00e0: MOVE   WS_FB_WIN [XXXX]  <-  param[00]  [XXXX]
		//   00e4: MOVE   param[00]  [...X]  <-  param[00]  [X...]
		//   00e8: CLEAR  param[00]  [..X.]
		//   00eb: CALL_TABLE  23  (EnableCRTC)
		//   00ed: MOVE   param[00]  [XXXX]  <-  WS_FB_WIN [XXXX]
		aruba_enable_crtc(rdev, cfg->ucCRTC, 0);
	}

	/* Lots of atom checks, but basically only continue with pll 0,1,2 */
	if (cfg->ucPpll > ATOM_PPLL0) // same as ATOM_DCPLL
		return;

	shutdown_pll(rdev, cfg->ucPpll);
	//   0135: TEST   param[00]  [XXXX]  <-  00ffffff
	//   013c: JUMP_Equal  0377
	if (cfg->ulPixelClock == 0)
		return;
	//   013f: MOVE   WS_REMIND/HI32 [..XX]  <-  WS_REGPTR [..XX]
 l_0143:
	//   0143: COMP   param[00]  [X...]  <-  03
	//   0147: JUMP_Above  0174
	if (cfg->ucCRTC <= 3) {
		//   014a: MOVE   WS_FB_WIN [XXXX]  <-  param[00]  [XXXX]
		//   014e: MOVE   param[00]  [...X]  <-  param[00]  [X...]
		//   0152: OR     param[00]  [...X]  <-  80
		//   0156: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		regptr = get_uniphy_reg_offset(2, cfg->ucCRTC);
		//   0158: MOVE   param[00]  [XXXX]  <-  WS_FB_WIN [XXXX]
		//   015c: TEST   param[02]  [X...]  <-  02
		//   0160: JUMP_Equal  016e
		if (cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_VGA_MODE)
			//   0163: MOVE   reg[00cc]  [XXXX]  <-  00010301
			aruba_write(rdev, (0xcc + regptr) << 2, 0x10300 | BIT(0));
		//   016b: JUMP   0174
		else
			//   016e: AND    reg[00cc]  [.XX.]  <-  fefc
			aruba_mask(rdev, (0xcc + regptr) << 2, 0x10300, 0);
	}
	//   0174: TEST   param[02]  [X...]  <-  01
	//   0178: JUMP_Equal  0262
	if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL))
		goto l_0262;
	//   017b: MOVE   WS_REGPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   017f: SET_DATA_BLOCK  ff  (this table)
	//   0181: ADD    WS_DATAPTR [..XX]  <-  037e
	pd = data;
	while (cfg->usFbDiv > pd->fb_div)
		//   0186: COMP   param[01]  [..XX]  <-  data[0000] [..XX]
		//   018b: JUMP_BelowOrEq  0196;
		//   018e: ADD    WS_DATAPTR [..XX]  <-  0006
		pd++;
	//   0193: JUMP   0186
	block = get_pll_base(cfg->ucPpll);

	//   0196: MOVE   reg[1708]  [XXXX]  <-  data[0002] [XXXX]
	aruba_write(rdev, block + PLL_r8, pd->d2);
	//   019c: TEST   param[02]  [X...]  <-  20
	//   01a0: JUMP_Equal  01b0
	if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_WTF)){
		//   01a3: AND    reg[1707]  [.X..]  <-  f7
		aruba_mask(rdev, block + PLL_r7, BIT(19), 0);
		//   01a8: MOVE   reg[1700]  [..X.]  <-  60
		aruba_mask(rdev, block + PLL_r0, 0xff << 8, 0x60 << 8);
		//   01ad: JUMP   01ba
	} else {
		//   01b0: OR     reg[1707]  [.X..]  <-  08
		aruba_mask(rdev, block + PLL_r7, 0, BIT(19));
		//   01b5: MOVE   reg[1700]  [..X.]  <-  90
		aruba_mask(rdev, block + PLL_r0, 0xff << 8, 0x90);
	}
	//   01ba: AND    reg[170a]  [...X]  <-  fe
	aruba_mask(rdev, block + PLL_ra, BIT(0), 0);
	//   01bf: TEST   param[02]  [X...]  <-  40
	//   01c3: JUMP_NotEqual  01ce
	if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_GEN_DPREFCLK))
		//   01c6: AND    reg[1709]  [..X.]  <-  f7
		aruba_mask(rdev, block + PLL_r9, BIT(11), 0);
	//   01cb: JUMP   01d3
	else
		//   01ce: OR     reg[1709]  [..X.]  <-  08
		aruba_mask(rdev, block + PLL_r9, 0, BIT(11));

	//   01d3: TEST   param[02]  [X...]  <-  10
	//   01d7: JUMP_Equal  01e2
	if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_REF_DIV_SRC))
		//   01da: AND    reg[1707]  [.X..]  <-  f8
		aruba_mask(rdev, block + PLL_r7, 0x7 << 16, 0);
	//   01df: JUMP   01e8
	else
		//   01e2: MASK   reg[1707]  [.X..]  &  f8  |  01
		aruba_mask(rdev, block + PLL_r7, 0x7 << 16, BIT(0));

	fuck_with_pll_config(rdev, cfg->ucPpll, cfg->ulFbDivDecFrac,
			     cfg->usFbDiv, cfg->ucRefDiv, cfg->ucPostDiv);
 l_0262:
	//   0262: SET_REG_BLOCK  0000
	//   0265: COMP   param[00]  [X...]  <-  03
	//   0269: JUMP_Above  0377
	if (cfg->ucCRTC > 3)
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
	bpc_s = &bpc_tbl[(cfg->ucMiscInfo & 0xc) >> 2]; // bit_depth << 1
	//   028d: MOVE   WS_REMIND/HI32 [...X]  <-  data[0001] [...X]
	//   0292: MUL    WS_FB_WIN [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	hdmi_clk_div = (cfg->ulPixelClock * bpc_s->bpp_div) / bpc_s->bpp_mul;
	//   0296: MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	//   029b: DIV    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
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
	regptr = get_uniphy_reg_offset(0, cfg->ucCRTC);
	//   02bf: MOVE   reg[1b30]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	aruba_mask(rdev, (0x1b30 + regptr) << 2, 0xffff, hdmi_clk_div & 0xffff);
	//   02c4: SET_REG_BLOCK  0000
	//   02c7: CLEAR  param[03]  [XXXX]
	//   02ca: MOVE   param[03]  [...X]  <-  param[00]  [X...]
	//   02ce: SHIFT_LEFT  param[03]  [..XX]  by  02
	//   02d2: COMP   param[02]  [.X..]  <-  00
	//   02d6: JUMP_NotEqual  0316
	if (cfg->ucEncoderMode == 0) {
		//   02d9: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
		regptr = cfg->ucCRTC << 2;
		//   02dd: MUL    WS_FB_WIN [XXXX]  <-  0000ea60
		//   02e4: MOVE   WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		win = cfg->ulPixelClock * 60000 + 1;
		//   02e8: COMP   reg[0141]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   02ed: JUMP_NotEqual  02f8
		if (aruba_read(rdev, (0x141 + regptr) << 2) == win) {
			//   02f0: TEST   reg[0140]  [...X]  <-  10
			//   02f5: JUMP_NotEqual  0377
			if (aruba_read(rdev, (0x140 + regptr) << 2) & BIT(4))
				return;
		}win --;
		//   02f8: SET_REG_BLOCK  0000
		//   02fb: CLEAR  param[00]  [..X.]
		//   02fe: CALL_TABLE  23  (EnableCRTC)
		aruba_enable_crtc(rdev, cfg->ucCRTC, 0);;
		//   0300: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
		//   0304: AND    reg[0140]  [...X]  <-  ef
		aruba_mask(rdev, (0x140 + regptr) << 2, BIT(4), 0);
		//   0309: MOVE   reg[0141]  [XXXX]  <-  WS_FB_WIN [XXXX]
		aruba_write(rdev, (0x141 + regptr) << 2, win);
		//   030e: OR     reg[0140]  [...X]  <-  10
		aruba_mask(rdev, (0x140 + regptr) << 2, 0, BIT(4));
		//   0313: JUMP   0377
		return;
	}

	//   0316: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
	regptr = cfg->ucCRTC << 2;
	//   031a: MOVE   WS_FB_WIN [...X]  <-  param[02]  [X...]
	//   031e: AND    WS_FB_WIN [...X]  <-  0c
	//   0322: SHIFT_LEFT  WS_FB_WIN [...X]  by  02
	//   0326: OR     WS_FB_WIN [...X]  <-  01
	win = (cfg->ucMiscInfo & 0x0c) << 2 | 1;
	//   032a: MOVE   param[02]  [.X..]  <-  cfg->ucPpll
	//   032e: ADD    param[02]  [.X..]  <-  01
	//   0332: COMP   cfg->ucPpll  <-  02
	//   0336: JUMP_NotEqual  033c
	if (cfg->ucPpll == ATOM_PPLL0)
		//   0339: CLEAR  param[02]  [.X..]
		cfg->ucEncoderMode = 0;
	//   033c: TEST   param[02]  [X...]  <-  01
	//   0340: JUMP_NotEqual  035c
	if (!(cfg->ucMiscInfo & PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL)) {
		//   0343: COMP   reg[0140]  [...X]  <-  param[02]  [.X..]
		//   0348: JUMP_NotEqual  0357
		if ((aruba_read(rdev, (0x140 + regptr) << 2) & 0xff) == (cfg->ucPpll + 1)) {
			//   034b: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
			regptr = cfg->ucPpll;
			//   034f: COMP   reg[0138]  [...X]  <-  WS_FB_WIN [...X]
			//   0354: JUMP_Equal  0377
			if ((aruba_read(rdev, (0x138 + regptr) << 2) & 0xff) == win)
				return;
		}
		DRM_ERROR("Unimplemented code path\n");
		//   0357: CLEAR  param[00]  [..X.]
		//   035a: CALL_TABLE  23  (EnableCRTC)
		aruba_enable_crtc(rdev, cfg->ucCRTC, 0); // FIXME: Are you sure, fucker?
	}
	//   035c: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
	regptr = cfg->ucPpll;
	//   0360: AND    reg[0138]  [...X]  <-  fe
	aruba_mask(rdev, (0x138 + regptr) << 2, BIT(0), 0);
	//   0365: MOVE   WS_REGPTR [..XX]  <-  param[03]  [..XX]
	regptr = cfg->ucCRTC << 2;
	//   0369: MOVE   reg[0140]  [...X]  <-  param[02]  [.X..]
	aruba_mask(rdev, (0x140 + regptr), 0xff, cfg->ucEncoderMode);
	//   036e: MOVE   WS_REGPTR [...X]  <-  cfg->ucPpll
	regptr = cfg->ucPpll;
	//   0372: MOVE   reg[0138]  [...X]  <-  WS_FB_WIN [...X]
	aruba_mask(rdev, (0x138 + regptr) << 2, 0xff, win);
	//   0377: SET_REG_BLOCK  0000
	//   037a: EOT
	return;
	//   037b:
	//   037e: 2400047607d5 2a00047707d5 320004d705d5 390004d705d5 3f0004d806d5 4600
	//         04d806d5 4c00043806d5 5100045804d5 5a00045904d5 ffff045a04d5
	//   03ba: 0101050403020201
	//                           CTB_DS  68 bytes
}


/* Arbitrarily chosen */
#define EXTPLL_LOCK_TIMEOUT		10000

enum divisor_type {
	DIV_REFCLOCK,
	DIV_ENGINE,
};

static int aruba_program_ext_pll(struct radeon_device * rdev, uint8_t pll,
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

	//   0025: COMP   reg[0124]  [X...]  <-  param[00]  [X...]
	//   002a: JUMP_Equal  0042
	if (((aruba_read(rdev, 0x124 << 2) >> shift) & 0xff) == pll)
		return 0;

	//   002d: TEST   reg[0124]  [.X..]  <-  10
	//   0032: JUMP_Equal  002d
	if (wait_set(rdev, 0x124 << 2, lockbit, EXTPLL_LOCK_TIMEOUT) < 0)
		return -ETIMEDOUT;
	//   0035: MOVE   reg[0124]  [X...]  <-  param[00]  [X...]
	aruba_mask(rdev, 0x124 << 2, 0xff << shift, pll << shift);
	//   003a: TEST   reg[0124]  [.X..]  <-  10
	//   003f: JUMP_Equal  003a
	if (wait_set(rdev, 0x124 << 2, lockbit, EXTPLL_LOCK_TIMEOUT) < 0)
		return -ETIMEDOUT;
	return 0;
}

int aruba_set_disp_eng_pll(struct radeon_device *rdev, uint32_t clock_10khz)
{
	const uint32_t rclock = 60000, ulDefaultEngineClock = 20000;
	const uint16_t usPCIEClkSSPercentage = 36;

	uint8_t pll;
	uint32_t ohman, clock_fuck;

	//   000d: CLEAR  reg[1841]  [...X]
	aruba_mask(rdev, 0x1841 << 2, 0xff, 0);
	//   0011: CLEAR  reg[031f]  [...X]
	aruba_mask(rdev, 0x31f << 2, 0xff, 0);
	//   0015: MOVE   param[01]  [XXXX]  <-  param[00]  [XXXX]
	//   0019: CLEAR  param[01]  [X...]
	//   001c: MOVE   param[00]  [XXXX]  <-  0000ea60
	//   0023: CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	ohman = rclock * 10;
	pll = aruba_compute_engine_pll(&ohman);
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
	ohman -= ohman * usPCIEClkSSPercentage / ulDefaultEngineClock;
	//   005e: MUL    param[00]  [XXXX]  <-  0000ea60
	clock_fuck = ohman * rclock;
	//   0065: MOVE   reg[0142]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	aruba_write(rdev, 0x142 << 2, clock_fuck);
	//   006a: MOVE   reg[0146]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	aruba_write(rdev, 0x146 << 2, clock_fuck);
	//   006f: MOVE   reg[014a]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	aruba_write(rdev, 0x14a << 2, clock_fuck);
	//   0074: MOVE   reg[014e]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	aruba_write(rdev, 0x14e << 2, clock_fuck);
	//   0079: MOVE   param[00]  [XXXX]  <-  param[01]  [XXXX]
	//   007d: CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	ohman = clock_10khz * 10;
	pll = aruba_compute_engine_pll(&ohman);
	ohman /= 10;
	if (aruba_program_ext_pll(rdev, pll, DIV_ENGINE) < 0) {
		DRM_ERROR("Engine EXTPLL failed to lock!!!");
		return -ETIMEDOUT;
	}
	//   009c: COMP   param[01]  [XXXX]  <-  00000000
	//   00a3: JUMP_NotEqual  00b3
	if (clock_10khz != 0)
		return 0;
	//   00a6: OR     reg[1841]  [...X]  <-  01
	aruba_mask(rdev, 0x1841 << 2, 0, 1);
	//   00ab: TEST   reg[1841]  [..X.]  <-  01
	//   00b0: JUMP_Equal  00ab
	if (wait_set(rdev, 0x1841 << 2, BIT(0), 10000) < 0)
		return -ETIMEDOUT;
	//   00b3: EOT
	return 0;
}
