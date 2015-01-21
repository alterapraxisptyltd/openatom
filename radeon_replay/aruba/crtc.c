#include "radeon_util.h"
#include "linux_glue.h"
#include "ObjectID.h"
#include "radeon_init_native.h"

#include <stdbool.h>

extern  uint16_t get_uniphy_reg_offset(uint8_t huge, uint8_t tits);


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

#define CRTC_1b9e				0x6e78

#define CRTC_STATUS				0x6e8c	// 1ba3
# define CRTC_V_BLANK				BIT(0)

#define CRTC_1ba9				0x6ea4

#define CRTC_UPDATE_LOCK			0x6ed4	// 1bb5
#define CRTC_1bb6				0x6ed8
#define CRTC_MASTER_UPDATE_LOCK			0x6ef4	// 1bbd

#define CRTC_H_OVERSCAN				0x6d78 // 1b5e
#define CRTC_V_OVERSCAN				0x6d7c // 1b5f

// command_table  0000c5c2  #23  (EnableCRTC):
//
//   Size         003e
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//

void aruba_enable_crtc(struct radeon_device * rdev,
		       uint8_t crtc_id, bool enable)
{
	uint32_t off;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = get_uniphy_reg_offset(crtc_id / 0x40, crtc_id & 0x7) << 2;
	//   000b: COMP   param[00]  [..X.]  <-  01
	//   000f: JUMP_Equal  0030
	if (enable) {
		//   0030: OR     reg[1b7c]  [X...]  <-  80
		aruba_mask(rdev, CRTC_1b7c + off, 0, BIT(31));
		//   0035: OR     reg[1b9c]  [...X]  <-  01
		aruba_mask(rdev, CRTC_CONTROL + off, 0, CRTC_MASTER_EN);
	} else {
		//   0012: OR     reg[1b9c]  [..X.]  <-  03
		aruba_mask(rdev, CRTC_CONTROL + off, 0, 0x300);
		//   0017: AND    reg[1b9c]  [...X]  <-  fe
		aruba_mask(rdev, CRTC_CONTROL + off, CRTC_MASTER_EN, 0);
		//   001c: TEST   reg[1b9c]  [.X..]  <-  01
		//   0021: JUMP_NotEqual  001c
		while(aruba_read(rdev, CRTC_CONTROL + off) & BIT(16));
		//   0024: AND    reg[1b7c]  [X...]  <-  7f
		aruba_mask(rdev, CRTC_1b7c + off, BIT(31),  0);
		//   0029: CLEAR  reg[1ba9]  [...X]
		aruba_mask(rdev, CRTC_1ba9 + off, 0xff,  0);
		//   002d: JUMP   003a
	}
	//   003a: SET_REG_BLOCK  0000
	//   003d: EOT
}


// command_table  0000ca26  #2c  (UpdateCRTC_DoubleBufferRegisters):
//
//   Size         0049
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
void aruba_update_crtc_x2_buf(struct radeon_device * rdev,
			     uint8_t crtc_id, bool enable)
{
	uint32_t off;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = get_uniphy_reg_offset(0, crtc_id & 0x7) << 2;
	//   000b: AND    reg[1bb6]  [..X.]  <-  fe
	aruba_mask(rdev, CRTC_1bb6 + off, BIT(8), 0);
	//   0010: COMP   param[00]  [..X.]  <-  01
	//   0014: JUMP_Equal  0037
	if (enable) {
		//   0037: OR     reg[1bbd]  [...X]  <-  01
		aruba_mask(rdev, CRTC_MASTER_UPDATE_LOCK + off, 0, BIT(0));
		//   003c: CLEAR  reg[1b9e]  [XXXX]
		aruba_write(rdev, CRTC_1b9e, 0);
		//   0040: SET_REG_BLOCK  0000
		//   0043: OR     reg[0132]  [...X]  <-  01
		aruba_mask(rdev, 0x0132 << 2, 0, BIT(0));
		//   0048: EOT
	} else {
		//   0017: CLEAR  reg[1a6e]  [.X..]
		aruba_mask(rdev, CURSOR_UPDATE + off, 0xff << 16, 0);
		//   001b: CLEAR  reg[1a27]  [.X..]
		aruba_mask(rdev, CRTC_1a27 + off, 0xff << 16, 0);
		//   001f: CLEAR  reg[1a11]  [.X..]
		aruba_mask(rdev, GRPH_UPDATE + off, 0xff << 16, 0);
		//   0023: CLEAR  reg[1bb5]  [...X]
		aruba_mask(rdev, CRTC_UPDATE_LOCK + off, 0xff, 0);
		//   0027: CLEAR  reg[1bbd]  [...X]
		aruba_mask(rdev, CRTC_MASTER_UPDATE_LOCK + off, 0xff, 0);
		//   002b: TEST   reg[1bb6]  [...X]  <-  01
		//   0030: JUMP_NotEqual  002b
		while (aruba_read(rdev, CRTC_1bb6 + off) & BIT(0));
		//   0033: SET_REG_BLOCK  0000
		//   0036: EOT
	}

}

// command_table  0000c582  #22  (BlankCRTC):
//
//   Size         003f
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
void aruba_blank_crtc(struct radeon_device * rdev, uint8_t crtc_id, bool enable)
{
	uint32_t off, setmask;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = get_uniphy_reg_offset(0, crtc_id & 0x7) << 2;
	//   000b: CLEAR  reg[1b9d]  [.X..]
	aruba_mask(rdev, CRTC_BLANK_CONTROL + off, 0xff << 16, 0);
	//   000f: MOVE   reg[1b9d]  [..X.]  <-  param[00]  [..X.]
	setmask = enable ? CRTC_BLANK_DATA_EN : 0;
	aruba_mask(rdev, CRTC_BLANK_CONTROL + off, 0xff << 8, setmask);
	//   0014: COMP   param[00]  [..X.]  <-  00
	//   0018: JUMP_Equal  003b
	if (!enable)
		return;
	//   001b: TEST   reg[1b9c]  [.X..]  <-  01
	//   0020: JUMP_Equal  003b
	if (!(aruba_read(rdev, CRTC_CONTROL + off) & BIT(16)))
		return;
	//   0023: TEST   reg[1ba3]  [...X]  <-  01
	//   0028: JUMP_NotEqual  0023
	while (aruba_read(rdev, CRTC_STATUS + off) & CRTC_V_BLANK);
	//   002b: TEST   reg[1ba3]  [...X]  <-  01
	//   0030: JUMP_Equal  002b
	while (!(aruba_read(rdev, CRTC_STATUS + off) & CRTC_V_BLANK));
	//   0033: TEST   reg[1ba3]  [...X]  <-  01
	//   0038: JUMP_NotEqual  0033
	while (aruba_read(rdev, CRTC_STATUS + off) & CRTC_V_BLANK);
	//   003b: SET_REG_BLOCK  0000
	//   003e: EOT

}

static void aruba_program_ext_pll_refclk(struct radeon_device * rdev, uint8_t pll)
{
	//   0025: COMP   reg[0124]  [X...]  <-  param[00]  [X...]
	//   002a: JUMP_Equal  0042
	if ((aruba_read(rdev, 0x124 << 2) >> 24) == pll)
		return;

	//   002d: TEST   reg[0124]  [.X..]  <-  10
	//   0032: JUMP_Equal  002d
	while (!(aruba_read(rdev, 0x124 << 2) & BIT(16)));
	//   0035: MOVE   reg[0124]  [X...]  <-  param[00]  [X...]
	aruba_mask(rdev, 0x124 << 2, 0xff << 24, pll << 24);
	//   003a: TEST   reg[0124]  [.X..]  <-  10
	//   003f: JUMP_Equal  003a
	while (!(aruba_read(rdev, 0x124 << 2) & BIT(16)));
}

static void aruba_program_ext_pll_engine(struct radeon_device * rdev, uint8_t pll)
{
	if ((aruba_read(rdev, 0x124 << 2) & 0xff) == pll)
		return;
	//   0087: TEST   reg[0124]  [.X..]  <-  08
	//   008c: JUMP_Equal  0087
	while (!(aruba_read(rdev, 0x124 << 2) & BIT(19)));
	//   008f: MOVE   reg[0124]  [...X]  <-  param[00]  [X...]
	aruba_mask(rdev, 0x124 << 2, 0xff, pll);
	//   0094: TEST   reg[0124]  [.X..]  <-  08
	//   0099: JUMP_Equal  0094
	while (!(aruba_read(rdev, 0x124 << 2) & BIT(19)));
}


void aruba_set_disp_eng_pll(struct radeon_device *rdev, uint32_t clock_10khz)
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
	DRM_DEBUG_KMS("We think pll should be %x (%d -> %d)\n", pll, rclock, ohman);
	aruba_program_ext_pll_refclk(rdev, pll);
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
	aruba_program_ext_pll_engine(rdev, pll);
	//   009c: COMP   param[01]  [XXXX]  <-  00000000
	//   00a3: JUMP_NotEqual  00b3
	if (clock_10khz != 0)
		return;
	//   00a6: OR     reg[1841]  [...X]  <-  01
	aruba_mask(rdev, 0x1841 << 2, 0, 1);
	//   00ab: TEST   reg[1841]  [..X.]  <-  01
	//   00b0: JUMP_Equal  00ab
	while (!(aruba_read(rdev, 0x1841 << 2) & BIT(0)));
	//   00b3: EOT
	return;
}



typedef struct _SET_CRTC_USING_DTD_TIMING_PARAMETERS
{
	// param[00]
	uint16_t  usH_Size;
	uint16_t  usH_Blanking_Time;
	// param[01]
	uint16_t  usV_Size;
	uint16_t  usV_Blanking_Time;
	// param[02]
	uint16_t  usH_SyncOffset;
	//uint16_t  usH_SyncWidth;
	// param[03]
	uint16_t  usV_SyncOffset;
	//uint16_t  usV_SyncWidth;
	// param[04]
	uint16_t  usAccess;
	uint8_t   ucH_Border;         // From DFP EDID
	uint8_t   ucV_Border;
	// param[05]
	uint8_t   ucCRTC;             // ATOM_CRTC1 or ATOM_CRTC2
	uint8_t   ucPadding[3];
}SET_CRTC_USING_DTD_TIMING_PARAMETERS;

#define ATOM_H_CUTOFF           0x01
#define ATOM_HSYNC_POLARITY     0x02             //0=Active High, 1=Active Low
#define ATOM_VSYNC_POLARITY     0x04             //0=Active High, 1=Active Low
#define ATOM_V_CUTOFF           0x08
#define ATOM_H_REPLICATIONBY2   0x10
#define ATOM_V_REPLICATIONBY2   0x20
#define ATOM_COMPOSITESYNC      0x40
#define ATOM_INTERLACE          0x80
#define ATOM_DOUBLE_CLOCK_MODE  0x100
#define ATOM_RGB888_MODE        0x200

// command_table  0000cbc8  #31  (SetCRTC_UsingDTDTiming):
//
//   Size         0128
//   Format Rev.  02
//   Param Rev.   00
//   Content Rev. 03
//   Attributes:  Work space size        00 longs
//                Parameter space size   06 longs
//                Table update indicator 0
//

#include <stddef.h>
void aruba_set_crtc_dtd_timing(struct radeon_device *rdev, uint8_t crtc_id,
			       struct drm_display_mode *mode,
			       uint8_t h_border, uint8_t v_border)
{
	uint32_t regptr, reg32, off;
	uint16_t val16;
	uint8_t r8;

	/* 0000 0003 0026 0029 002c 002f < same data as get_uniphy_reg_offset */
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: SET_DATA_BLOCK  ff  (this table)
	//   000b: ADD    WS_DATAPTR [..XX]  <-  011c
	//   0010: CLEAR  param[05]  [..X.]
	//   0013: ADD    WS_DATAPTR [..XX]  <-  param[05]  [..XX]
	//   0017: ADD    WS_DATAPTR [..XX]  <-  param[05]  [..XX]
	//   001b: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	regptr = get_uniphy_reg_offset(0, crtc_id);
	off = regptr << 2;
	//   0020: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usH_Size
	//   0024: ADD    WS_REMIND/HI32 [..XX]  <-  cfg->usH_Blanking_Time
	//   0028: SUB    WS_REMIND/HI32 [..XX]  <-  0001
	val16 = mode->crtc_hblank_end - 1;
	//   002d: MOVE   reg[1b80]  [..XX]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b80 + regptr) << 2, 0xffff, val16);
	//   0032: CLEAR  reg[1b82]  [..XX]
	aruba_mask(rdev, (0x1b82 + regptr) << 2, 0xffff, 0);
	//   0036: MOVE   reg[1b82]  [XX..]  <-  cfg->usH_SyncWidth
	val16 = mode->crtc_hsync_end - mode->crtc_hsync_start;
	aruba_mask(rdev, (0x1b82 + regptr) << 2, 0xffff << 16, val16 << 16);
	//   003b: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usH_Blanking_Time
	//   003f: SUB    WS_REMIND/HI32 [..XX]  <-  usH_SyncOffset
	//   0043: CLEAR  WS_REMIND/HI32 [XX..]
	//   0046: MOVE   WS_REMIND/HI32 [.X..]  <-  cfg->ucH_Border
	//   004a: SUB    WS_REMIND/HI32 [..XX]  <-  WS_REMIND/HI32 [XX..]
	////rem = h_blank - h_sync_off - h_border;
	val16 = mode->crtc_hblank_end - mode->crtc_hsync_start ;
	//   004e: MOVE   reg[1b81]  [XX..]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b81 + regptr) << 2, 0xffff << 16, val16 << 16);
	//   0053: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usH_Blanking_Time
	//   0057: SUB    WS_REMIND/HI32 [..XX]  <-  usH_SyncOffset
	//   005b: ADD    WS_REMIND/HI32 [..XX]  <-  WS_REMIND/HI32 [XX..]
	//   005f: ADD    WS_REMIND/HI32 [..XX]  <-  cfg->usH_Size
	////rem = h_blank - h_sync_off + h_border + h_size;
	val16 = mode->crtc_hblank_end - mode->crtc_hsync_start + mode->crtc_hdisplay;
	/* Not used *///   0063: TEST   cfg->usAccess  <-  10//   0067: JUMP_Equal  006e
	//   006e: MOVE   reg[1b81]  [..XX]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b81 + regptr) << 2, 0xffff, val16);
	//   0073: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->usAccess
	//   0077: AND    WS_REMIND/HI32 [...X]  <-  02
	//   007b: SHIFT_RIGHT  WS_REMIND/HI32 [...X]  by  01
	r8 = (mode->flags & DRM_MODE_FLAG_NHSYNC) ? BIT(0) : 0;
	//   007f: MOVE   reg[1b83]  [...X]  <-  WS_REMIND/HI32 [...X]
	aruba_mask(rdev, (0x1b83 + regptr) << 2, 0xff, r8);
	//   0084: CLEAR  reg[1b5e]  [XXXX]
	//   0088: MOVE   reg[1b5e]  [...X]  <-  cfg->ucH_Border
	//   008d: MOVE   reg[1b5e]  [.X..]  <-  cfg->ucH_Border
	reg32 = h_border | (h_border << 16);
	aruba_write(rdev, CRTC_H_OVERSCAN + off, reg32);
	//   0092: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usV_Size
	//   0096: ADD    WS_REMIND/HI32 [..XX]  <-  cfg->usV_Blanking_Time
	//   009a: SUB    WS_REMIND/HI32 [..XX]  <-  0001
	val16 = mode->crtc_vblank_end - 1;
	//   009f: MOVE   reg[1b87]  [..XX]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b87 + regptr) << 2, 0xffff, val16);
	//   00a4: CLEAR  reg[1b8e]  [..XX]
	aruba_mask(rdev, (0x1b8e + regptr) << 2, 0xffff, 0);
	//   00a8: MOVE   reg[1b8e]  [XX..]  <-  cfg->usV_SyncWidth
	val16 = mode->crtc_vsync_end - mode->crtc_vsync_start;
	aruba_mask(rdev, (0x1b8e + regptr) << 2, 0xffff << 16, val16 << 16);
	//   00ad: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usV_Blanking_Time
	//   00b1: SUB    WS_REMIND/HI32 [..XX]  <-  cfg->usV_SyncOffset
	//   00b5: CLEAR  WS_REMIND/HI32 [XX..]
	//   00b8: MOVE   WS_REMIND/HI32 [.X..]  <-  cfg->ucV_Border
	//   00bc: SUB    WS_REMIND/HI32 [..XX]  <-  WS_REMIND/HI32 [XX..]
	////rem = v_blank - v_sync_off - v_border;
	val16 = mode->crtc_vblank_end - mode->crtc_vsync_start ;
	//   00c0: MOVE   reg[1b8d]  [XX..]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b8d + regptr) << 2, 0xffff << 16, val16 << 16);
	//   00c5: MOVE   WS_REMIND/HI32 [..XX]  <-  cfg->usV_Blanking_Time
	//   00c9: SUB    WS_REMIND/HI32 [..XX]  <-  cfg->usV_SyncOffset
	//   00cd: ADD    WS_REMIND/HI32 [..XX]  <-  WS_REMIND/HI32 [XX..]
	//   00d1: ADD    WS_REMIND/HI32 [..XX]  <-  cfg->usV_Size
	////rem = v_blank - v_sync_off + v_border + v_size;
	val16 = mode->crtc_vblank_end - mode->crtc_vsync_start + mode->crtc_vdisplay;
	/* Not used */ //   00d5: TEST   cfg->usAccess  <-  20 //   00d9: JUMP_Equal  00e0
	//   00e0: MOVE   reg[1b8d]  [..XX]  <-  WS_REMIND/HI32 [..XX]
	aruba_mask(rdev, (0x1b8d + regptr) << 2, 0xffff, val16);
	//   00e5: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->usAccess
	//   00e9: AND    WS_REMIND/HI32 [...X]  <-  04
	//   00ed: SHIFT_RIGHT  WS_REMIND/HI32 [...X]  by  02
	r8 = (mode->flags & DRM_MODE_FLAG_NVSYNC) ? BIT(0): 0;
	//   00f1: MOVE   reg[1b8f]  [...X]  <-  WS_REMIND/HI32 [...X]
	aruba_mask(rdev, (0x1b8f + regptr) << 2, 0xff, r8);
	//   00f6: CLEAR  reg[1b5f]  [XXXX]
	//   00fa: MOVE   reg[1b5f]  [...X]  <-  cfg->ucV_Border
	//   00ff: MOVE   reg[1b5f]  [.X..]  <-  cfg->ucV_Border
	reg32 = v_border | (v_border << 16);
	aruba_write(rdev, CRTC_V_OVERSCAN + off, reg32);
	//   0104: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->usAccess
	//   0108: AND    WS_REMIND/HI32 [...X]  <-  80
	//   010c: SHIFT_RIGHT  WS_REMIND/HI32 [...X]  by  07
	r8 = (mode->flags & DRM_MODE_FLAG_INTERLACE) ? BIT(0): 0;
	//   0110: MOVE   reg[1b9e]  [...X]  <-  WS_REMIND/HI32 [...X]
	aruba_mask(rdev, (0x1b9e + regptr) << 2, 0xff, r8);
	//   0115: SET_REG_BLOCK  0000
	//   0118: EOT
	//   0119:
	//         0000000300260029002c002f
	//                           CTB_DS  12 bytes
}

// command_table  0000c75e  #28  (SetCRTC_OverScan):
//
//   Size         0019
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0
//

void aruba_overscan_setup(struct radeon_device * rdev, uint8_t crtc_id,
			  uint8_t h_border, uint8_t v_border)
{
	uint32_t off, reg32;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = get_uniphy_reg_offset(0, crtc_id) << 2;
	//   000b: MOVE   reg[1b5e]  [XXXX]  <-  param[00]  [XXXX]
	reg32 =  (h_border << 16) | h_border;
	aruba_write(rdev, CRTC_H_OVERSCAN + off, reg32);
	//   0010: MOVE   reg[1b5f]  [XXXX]  <-  param[01]  [XXXX]
	reg32 = (v_border << 16) | v_border;
	aruba_write(rdev, CRTC_V_OVERSCAN + off, reg32);
	//   0015: SET_REG_BLOCK  0000
	//   0018: EOT
}
