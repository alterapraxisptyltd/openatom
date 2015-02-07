//#include "evergreend.h"
#include "aruba/trinityd.h"
#include "radeon_util.h"
#include "radeon_init_native.h"
#include "linux_glue.h"	// For aruba_ IO accessor ONLY!!!!!!!!!
#include "ObjectID.h"
#include "drm_dp_helper.h"
#include "edid.h"

/* GRPH blocks at 0x6800, 0x7400, 0x10000, 0x10c00, 0x11800, 0x12400 */
#define GRPH_ENABLE                           0x6800
#define GRPH_CONTROL                          0x6804
#       define GRPH_DEPTH(x)                  (((x) & 0x3) << 0)
#       define GRPH_DEPTH_8BPP                0
#       define GRPH_DEPTH_16BPP               1
#       define GRPH_DEPTH_32BPP               2
#       define GRPH_NUM_BANKS(x)              (((x) & 0x3) << 2)
#       define ADDR_SURF_2_BANK               0
#       define ADDR_SURF_4_BANK               1
#       define ADDR_SURF_8_BANK               2
#       define ADDR_SURF_16_BANK              3
#       define GRPH_Z(x)                      (((x) & 0x3) << 4)
#       define GRPH_BANK_WIDTH(x)             (((x) & 0x3) << 6)
#       define ADDR_SURF_BANK_WIDTH_1         0
#       define ADDR_SURF_BANK_WIDTH_2         1
#       define ADDR_SURF_BANK_WIDTH_4         2
#       define ADDR_SURF_BANK_WIDTH_8         3
#       define GRPH_FORMAT(x)                 (((x) & 0x7) << 8)
/* 8 BPP */
#       define GRPH_FORMAT_INDEXED            0
/* 16 BPP */
#       define GRPH_FORMAT_ARGB1555           0
#       define GRPH_FORMAT_ARGB565            1
#       define GRPH_FORMAT_ARGB4444           2
#       define GRPH_FORMAT_AI88               3
#       define GRPH_FORMAT_MONO16             4
#       define GRPH_FORMAT_BGRA5551           5
/* 32 BPP */
#       define GRPH_FORMAT_ARGB8888           0
#       define GRPH_FORMAT_ARGB2101010        1
#       define GRPH_FORMAT_32BPP_DIG          2
#       define GRPH_FORMAT_8B_ARGB2101010     3
#       define GRPH_FORMAT_BGRA1010102        4
#       define GRPH_FORMAT_8B_BGRA1010102     5
#       define GRPH_FORMAT_RGB111110          6
#       define GRPH_FORMAT_BGR101111          7
#       define GRPH_BANK_HEIGHT(x)            (((x) & 0x3) << 11)
#       define ADDR_SURF_BANK_HEIGHT_1        0
#       define ADDR_SURF_BANK_HEIGHT_2        1
#       define ADDR_SURF_BANK_HEIGHT_4        2
#       define ADDR_SURF_BANK_HEIGHT_8        3
#       define GRPH_TILE_SPLIT(x)             (((x) & 0x7) << 13)
#       define ADDR_SURF_TILE_SPLIT_64B       0
#       define ADDR_SURF_TILE_SPLIT_128B      1
#       define ADDR_SURF_TILE_SPLIT_256B      2
#       define ADDR_SURF_TILE_SPLIT_512B      3
#       define ADDR_SURF_TILE_SPLIT_1KB       4
#       define ADDR_SURF_TILE_SPLIT_2KB       5
#       define ADDR_SURF_TILE_SPLIT_4KB       6
#       define GRPH_MACRO_TILE_ASPECT(x)      (((x) & 0x3) << 18)
#       define ADDR_SURF_MACRO_TILE_ASPECT_1  0
#       define ADDR_SURF_MACRO_TILE_ASPECT_2  1
#       define ADDR_SURF_MACRO_TILE_ASPECT_4  2
#       define ADDR_SURF_MACRO_TILE_ASPECT_8  3
#       define GRPH_ARRAY_MODE(x)             (((x) & 0x7) << 20)
#       define GRPH_ARRAY_LINEAR_GENERAL      0
#       define GRPH_ARRAY_LINEAR_ALIGNED      1
#       define GRPH_ARRAY_1D_TILED_THIN1      2
#       define GRPH_ARRAY_2D_TILED_THIN1      4
#define GRPH_LUT_10BIT_BYPASS_CONTROL         0x6808
#       define LUT_10BIT_BYPASS_EN            (1 << 8)
#define GRPH_SWAP_CONTROL                     0x680c
#       define GRPH_ENDIAN_SWAP(x)            (((x) & 0x3) << 0)
#       define GRPH_ENDIAN_NONE               0
#       define GRPH_ENDIAN_8IN16              1
#       define GRPH_ENDIAN_8IN32              2
#       define GRPH_ENDIAN_8IN64              3
#       define GRPH_RED_CROSSBAR(x)           (((x) & 0x3) << 4)
#       define GRPH_RED_SEL_R                 0
#       define GRPH_RED_SEL_G                 1
#       define GRPH_RED_SEL_B                 2
#       define GRPH_RED_SEL_A                 3
#       define GRPH_GREEN_CROSSBAR(x)         (((x) & 0x3) << 6)
#       define GRPH_GREEN_SEL_G               0
#       define GRPH_GREEN_SEL_B               1
#       define GRPH_GREEN_SEL_A               2
#       define GRPH_GREEN_SEL_R               3
#       define GRPH_BLUE_CROSSBAR(x)          (((x) & 0x3) << 8)
#       define GRPH_BLUE_SEL_B                0
#       define GRPH_BLUE_SEL_A                1
#       define GRPH_BLUE_SEL_R                2
#       define GRPH_BLUE_SEL_G                3
#       define GRPH_ALPHA_CROSSBAR(x)         (((x) & 0x3) << 10)
#       define GRPH_ALPHA_SEL_A               0
#       define GRPH_ALPHA_SEL_R               1
#       define GRPH_ALPHA_SEL_G               2
#       define GRPH_ALPHA_SEL_B               3
#define GRPH_PRIMARY_SURFACE_ADDRESS          0x6810
#define GRPH_SECONDARY_SURFACE_ADDRESS        0x6814
#       define GRPH_DFQ_ENABLE                (1 << 0)
#       define GRPH_SURFACE_ADDRESS_MASK      0xffffff00
#define GRPH_PITCH                            0x6818
#define GRPH_PRIMARY_SURFACE_ADDRESS_HIGH     0x681c
#define GRPH_SECONDARY_SURFACE_ADDRESS_HIGH   0x6820
#define GRPH_SURFACE_OFFSET_X                 0x6824
#define GRPH_SURFACE_OFFSET_Y                 0x6828
#define GRPH_X_START                          0x682c
#define GRPH_Y_START                          0x6830
#define GRPH_X_END                            0x6834
#define GRPH_Y_END                            0x6838
#define GRPH_UPDATE                           0x6844
#       define GRPH_SURFACE_UPDATE_PENDING    (1 << 2)
#       define GRPH_UPDATE_LOCK               (1 << 16)
#define GRPH_FLIP_CONTROL                     0x6848
#       define GRPH_SURFACE_UPDATE_H_RETRACE_EN (1 << 0)


// command_table  0000c840  #2b  (EnableGraphSurfaces):
//
//   Size         01e6
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 04
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0
//
typedef struct _ENABLE_GRAPH_SURFACE_PARAMETERS_V1_4
{
	uint16_t usHight;                     // Image Hight
	uint16_t usWidth;                     // Image Width

	uint16_t usGraphPitch;
	uint8_t  ucColorDepth;
	uint8_t  ucPixelFormat;

	uint8_t  ucSurface;                   // Surface 1 or 2
	uint8_t  ucEnable;                    // ATOM_ENABLE or ATOM_DISABLE
	uint8_t  ucModeType;
	uint8_t  ucReserved;
}ENABLE_GRAPH_SURFACE_PARAMETERS_V1_4;

static void suck_a_dick(void) {};

static uint16_t get_uniphy_reg_offset(uint8_t huge, uint8_t tits)
{
	/*
	 * big = par[0] >> 6
	 * small = par[0] & 0x7
	 */
	static const uint16_t really[3][6] = {
		{ 0x0000, 0x0300, 0x2600, 0x2900, 0x2c00, 0x2f00 },  /* 0x00 */
		{ 0x0000, 0x0002, 0x002c, 0x002d, 0x002e, 0x002f },  /* 0x40 */
		{ 0x0000, 0x0001, 0x0007, 0x0008, 0x000b, 0x000c }}; /* 0x80 */

		return really[huge][tits];
}


void aruba_disable_grph_srfc(struct radeon_device *rdev, uint8_t surf)
{
	uint32_t regptr = aruba_get_block_offest(surf) >> 2;
	radeon_mask(rdev, (0x1a00 + regptr) << 2, 0xff, 0);
	if ((radeon_read(rdev, 0x00fc << 2) & 0xff) != surf)
		return;
	radeon_mask(rdev, 0x00c1 << 2, 0xffff, 0);
}

#define VIEWPORT_START                        0x6d70
#define VIEWPORT_SIZE                         0x6d74

void aruba_enable_grph_srfc(struct radeon_device *rdev, uint8_t surf, uint8_t enable,
			    uint16_t h, uint16_t w, uint16_t fbpitch)
{
	uint32_t regptr, off;
	uint8_t big_qfuck;
	bool condition = true, condition_d0 = false, condition_169 = true;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: COMP   param[02]  [..X.]  <-  01
	//   000d: JUMP_NotEqual  017b
	if (enable != 1)
		goto do_enable_shit;
	//   0010: MOVE   reg[013f]  [...X]  <-  10
	radeon_mask(rdev, 0x13f << 2, 0xff, 0x10);
	//   0015: TEST   param[02]  [.X..]  <-  03
	//   0019: JUMP_NotEqual  00a0
	if (!condition)
	{
		//   001c: MOVE   param[00]  [XXXX]  <-  05000300
		//   0023: MOVE   param[01]  [XXXX]  <-  00020500
		//   002a: COMP   reg[00fc]  [...X]  <-  param[02]  [...X]
		//   002f: JUMP_NotEqual  00c7
		//   0032: MOVE   reg[00c0]  [XX..]  <-  0200
		//   0038: DELAY_MicroSec  02
		//   003a: MOVE   reg[00c6]  [XXXX]  <-  00100000
		//   0042: MOVE   reg[00c8]  [XXXX]  <-  00500000
		//   004a: MOVE   reg[00c3]  [..XX]  <-  0002
		//   0050: CLEAR  reg[00ca]  [...X]
		//   0054: MOVE   reg[00c2]  [XXXX]  <-  00000100
		//   005c: OR     param[02]  [...X]  <-  80
		//   0060: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		//   0062: AND    param[02]  [...X]  <-  07
		//   0066: MOVE   WS_QUOT/LOW32 [...X]  <-  01
		//   006a: TEST   reg[00cc]  [..X.]  <-  01
		//   006f: JUMP_Equal  009a
		//   0072: CLEAR  WS_REGPTR [..XX]
		//   0075: MOVE   WS_REMIND/HI32 [..XX]  <-  reg[05d0]  [XX..]
		//   007a: AND    WS_REMIND/HI32 [..XX]  <-  ff7f
		//   007f: COMP   WS_REMIND/HI32 [..XX]  <-  0006
		//   0084: JUMP_Equal  0097
		//   0087: COMP   WS_REMIND/HI32 [..XX]  <-  000c
		//   008c: JUMP_Equal  0097
		//   008f: COMP   WS_REMIND/HI32 [..XX]  <-  000e
		//   0094: JUMP_NotEqual  009a
		//   0097: CLEAR  WS_QUOT/LOW32 [...X]
		//   009a: CLEAR  WS_REGPTR [..XX]
		//   009d: JUMP   00c7
	} else {
		//   00a0: OR     param[02]  [...X]  <-  80
		//   00a4: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		regptr = get_uniphy_reg_offset(1, surf);
		off = regptr << 2;
		//   00a6: CLEAR  reg[00cc]  [XXXX]
		radeon_write(rdev, (0xcc + regptr) << 2, 0);
		//   00aa: CLEAR  WS_REGPTR [..XX]
		//   00ad: AND    param[02]  [...X]  <-  07
		//   00b1: OR     reg[00ca]  [...X]  <-  01
		radeon_mask(rdev, 0xca << 2, 0, BIT(0));
		//   00b6: MOVE   reg[00c2]  [...X]  <-  11
		radeon_mask(rdev, 0xc2 << 2, 0, 0x11);
		//   00bb: CLEAR  reg[00c6]  [XXXX]
		radeon_write(rdev, 0xc6 << 2, 0);
		//   00bf: CLEAR  reg[00c8]  [XXXX]
		radeon_write(rdev, 0xc8 << 2, 0);
		//   00c3: MOVE   WS_QUOT/LOW32 [...X]  <-  01
		big_qfuck = 1;
	}
	//   00c7: AND    reg[05d0]  [..X.]  <-  fe
	radeon_mask(rdev, 0x5d0 << 2, BIT(8), 0);
	//   00cc: COMP   param[01]  [.X..]  <-  01
	//   00d0: JUMP_BelowOrEq  00d8
	if (condition_d0)
		//   00d3: OR     reg[05d0]  [..X.]  <-  01
		suck_a_dick();
	//   00d8: MOVE   WS_QUOT/LOW32 [.X..]  <-  reg[00c9]  [...X]
	uint8_t qfuck = radeon_read(rdev, 0xc9 << 2) & 0xff;
	//   00dd: MOVE   WS_FB_WIN [XXXX]  <-  reg[00c4]  [XXXX]
	uint32_t wfuck = radeon_read(rdev, 0xc4 << 2);
	//   00e2: MOVE   WS_REMIND/HI32 [XXXX]  <-  WS_FB_WIN [XXXX]
	uint32_t rfuck = wfuck;
	//   00e6: ADD    WS_FB_WIN [XXXX]  <-  reg[00c6]  [XXXX]
	wfuck += radeon_read(rdev, 0xc6 << 2);
	//   00eb: ADD    WS_REMIND/HI32 [XXXX]  <-  reg[00c8]  [XXXX]
	//   00f0: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = regptr << 2;
	regptr = aruba_get_block_offest(surf) >> 2;
	//   00f2: MOVE   reg[1a07]  [...X]  <-  WS_QUOT/LOW32 [.X..]
	radeon_mask(rdev, (0x1a07 + regptr) << 2, 0xff, qfuck);
	//   00f7: MOVE   reg[1a08]  [...X]  <-  WS_QUOT/LOW32 [.X..]
	radeon_mask(rdev, (0x1a08 + regptr) << 2, 0xff, qfuck);
	//   00fc: MOVE   reg[1a04]  [XXXX]  <-  WS_FB_WIN [XXXX]
	radeon_write(rdev, (0x1a04 + regptr) << 2, wfuck);
	//   0101: MOVE   reg[1a05]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_write(rdev, (0x1a05 + regptr) << 2, rfuck);
	//   0106: CLEAR  reg[1ac3]  [.X..]
	radeon_mask(rdev, (0x1ac3 + regptr) << 2, 0xff << 16, 0);
	//   010a: CLEAR  reg[1b5c]  [XXXX]
	radeon_write(rdev, VIEWPORT_START + off, 0);
	//   010e: MOVE   reg[1b5d]  [XXXX]  <-  param[00]  [XXXX]
	radeon_write(rdev, VIEWPORT_SIZE + off, (w << 16) | h);
	//   0113: CLEAR  reg[1a09]  [..XX]
	radeon_write(rdev, GRPH_SURFACE_OFFSET_X + off, 0);
	//   0117: CLEAR  reg[1a0a]  [..XX]
	radeon_write(rdev, GRPH_SURFACE_OFFSET_Y + off, 0);
	//   011b: CLEAR  reg[1a0b]  [..XX]
	radeon_write(rdev, GRPH_X_START + off, 0);
	//   011f: CLEAR  reg[1a0c]  [..XX]
	radeon_write(rdev, GRPH_Y_START + off, 0);
	//   0123: MOVE   reg[1a0e]  [..XX]  <-  param[00]  [..XX]
	radeon_write(rdev, GRPH_Y_END + off, h);
	//   0128: MOVE   reg[1a0d]  [..XX]  <-  param[00]  [XX..]
	radeon_write(rdev, GRPH_X_END + off, w);
	//   012d: MASK   reg[1a01]  [..XX]  &  f8fc  |  param[01]
	uint32_t pfmt = 2;
	//radeon_mask(rdev, GRPH_CONTROL + off, 0x0703, pfmt);
	radeon_mask(rdev, GRPH_CONTROL + off, 0xffff, pfmt);
	//   0134: AND    reg[1a01]  [.X..]  <-  0f
	radeon_mask(rdev, GRPH_CONTROL + off, 0xf0 << 16, 0);
	//   0139: MOVE   reg[1a06]  [..XX]  <-  param[01]  [..XX]
	fbpitch = (fbpitch + 0x7f) & ~0x7f;
	radeon_mask(rdev, GRPH_PITCH + off, 0xffff, fbpitch);
	//   013e: MOVE   reg[1a00]  [...X]  <-  01
	radeon_mask(rdev, GRPH_ENABLE  + off, 0xff, 1);
	/* vvv extra shit vvv */
	uint32_t swapper;
	swapper = GRPH_RED_CROSSBAR(GRPH_RED_SEL_B);
	swapper |= GRPH_BLUE_CROSSBAR(GRPH_BLUE_SEL_R);
	radeon_write(rdev, GRPH_SWAP_CONTROL + off, swapper);
	/* ^^^ extra shit ^^^ */
	//   0143: OR     reg[1b9c]  [X...]  <-  10
	radeon_mask(rdev, (0x1b9c + regptr) << 2, 0, BIT(28));
	//   0148: CLEAR  reg[1a0f]  [...X]
	radeon_mask(rdev, (0x1a0f + regptr) << 2, 0xff, 0);
	//   014c: CLEAR  reg[1a35]  [...X]
	radeon_mask(rdev, (0x1a35 + regptr) << 2, 0xff, 0);
	//   0150: CLEAR  reg[1a3c]  [...X]
	radeon_mask(rdev, (0x1a3c + regptr) << 2, 0xff, 0);
	//   0154: CLEAR  reg[1ba1]  [XXXX]
	radeon_write(rdev, (0x1ba1 + regptr) << 2, 0);
	//   0158: CLEAR  reg[1ba0]  [XXXX]
	radeon_write(rdev, (0x1ba0 + regptr) << 2, 0);
	//   015c: CLEAR  reg[1ba2]  [XXXX]
	radeon_write(rdev, (0x1ba2 + regptr) << 2, 0);
	//   0160: MOVE   reg[1af6]  [...X]  <-  WS_QUOT/LOW32 [...X]
	radeon_mask(rdev, (0x1af6 + regptr) << 2, 0xff, big_qfuck);
	//   0165: TEST   param[02]  [.X..]  <-  03
	//   0169: JUMP_NotEqual  0177
	if (condition_169)
		return;
	//   016c: OR     param[02]  [...X]  <-  80
	//   0170: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = get_uniphy_reg_offset(2, surf);
	//   0172: OR     reg[00cc]  [...X]  <-  01
	radeon_mask(rdev, (0xcc + regptr) << 2, 0, BIT(0));
	//   0177: SET_REG_BLOCK  0000
	//   017a: EOT
	return;
 do_enable_shit:
	//   017b: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = aruba_get_block_offest(surf) >> 2;
	//   017d: COMP   param[02]  [..X.]  <-  00
	//   0181: JUMP_NotEqual  0198
	if (enable == 0) {
		aruba_disable_grph_srfc(rdev, surf);
		return;
	}
	//   0198: COMP   param[02]  [..X.]  <-  10
	//   019c: JUMP_Equal  01a5
	//   019f: MOVE   reg[1a06]  [..XX]  <-  param[01]  [..XX]
	//   01a4: EOT
	//   01a5: MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[1a04]  [XXXX]
	//   01aa: AND    WS_QUOT/LOW32 [XXXX]  <-  ff000000
	//   01b1: ADD    WS_QUOT/LOW32 [XXXX]  <-  param[00]  [XXXX]
	//   01b5: AND    WS_QUOT/LOW32 [..XX]  <-  f000
	//   01ba: MOVE   reg[1a04]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   01bf: AND    param[00]  [..XX]  <-  0fff
	//   01c4: CLEAR  WS_REMIND/HI32 [XXXX]
	//   01c7: MOVE   WS_REMIND/HI32 [...X]  <-  param[01]  [.X..]
	//   01cb: SHR    param[00]  [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   01cf: ADD    param[01]  [..XX]  <-  param[00]  [..XX]
	//   01d3: AND    param[00]  [...X]  <-  fc
	//   01d7: SHIFT_LEFT  param[00]  [XXXX]  by  10
	//   01db: MOVE   reg[1b5c]  [XXXX]  <-  param[00]  [XXXX]
	//   01e0: MOVE   reg[1a0d]  [..XX]  <-  param[01]  [..XX]
	//   01e5: EOT
}

// command_table  0000c600  #24  (GetPixelClock):
//
//   Size         0132
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 03
//   Attributes:  Work space size        00 longs
//                Parameter space size   03 longs
//                Table update indicator 0
//
void cock_pixel_pipeline(struct radeon_device *rdev)
{
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CLEAR  WS_QUOT/LOW32 [XXXX]
	//   000c: MOVE   WS_QUOT/LOW32 [..XX]  <-  param[01]  [..XX]
	//   0010: MUL    WS_QUOT/LOW32 [XXXX]  <-  000f4240
	//   0017: ADD    WS_QUOT/LOW32 [XXXX]  <-  param[03]  [XXXX]
	//   001b: DIV    WS_QUOT/LOW32 [XXXX]  <-  0000000a
	//   0022: MUL    WS_QUOT/LOW32 [XXXX]  <-  00000064
	//   0029: CLEAR  WS_REMIND/HI32 [XXXX]
	//   002c: MOVE   WS_REMIND/HI32 [...X]  <-  param[01]  [X...]
	//   0030: DIV    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   0034: DIV    WS_QUOT/LOW32 [XXXX]  <-  000003e8
	//   003b: MOVE   WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   003f: COMP   WS_FB_WIN [XXXX]  <-  0001e366
	//   0046: JUMP_Below  005b
	//   0049: OR     param[02]  [X...]  <-  20
	//   004d: COMP   WS_FB_WIN [XXXX]  <-  00028488
	//   0054: JUMP_BelowOrEq  005b
	//   0057: OR     param[02]  [X...]  <-  PIXEL_CLOCK_V6_MISC_GEN_DPREFCLK
	//   005b: COMP   param[03]  [XXXX]  <-  00000000
	//   0062: JUMP_Equal  008f
	//   0065: ADD    param[01]  [..XX]  <-  0001
	//   006a: MOVE   WS_QUOT/LOW32 [XXXX]  <-  000f4240
	//   0071: SUB    WS_QUOT/LOW32 [XXXX]  <-  param[03]  [XXXX]
	//   0075: DIV    WS_QUOT/LOW32 [XXXX]  <-  000186a0
	//   007c: MOVE   param[03]  [.X..]  <-  WS_QUOT/LOW32 [...X]
	//   0080: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  0e
	//   0084: DIV    WS_REMIND/HI32 [XXXX]  <-  000061a8
	//   008b: MOVE   param[03]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   008f: MOVE   param[03]  [X...]  <-  param[01]  [.X..]
	//   0093: COMP   param[02]  [.X..]  <-  00
	//   0097: JUMP_Equal  00b0
	//   009a: ADD    WS_FB_WIN [XXXX]  <-  000003e8
	//   00a1: MOVE   WS_REMIND/HI32 [XXXX]  <-  param[00]  [XXXX]
	//   00a5: CLEAR  WS_REMIND/HI32 [X...]
	//   00a8: DIV    WS_FB_WIN [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   00ac: MOVE   param[03]  [X...]  <-  WS_QUOT/LOW32 [...X]
	//   00b0: OR     param[03]  [.X..]  <-  10
	//   00b4: TEST   param[02]  [X...]  <-  PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL
	//   00b8: JUMP_NotEqual  012a
	//   00bb: COMP   param[02]  [...X]  <-  02
	//   00bf: JUMP_Equal  00cf
	//   00c2: SET_REG_BLOCK  0010
	//   00c5: COMP   param[02]  [...X]  <-  00
	//   00c9: JUMP_Equal  00cf
	//   00cc: SET_REG_BLOCK  0020
	//   00cf: MOVE   WS_REMIND/HI32 [XXXX]  <-  reg[1707]  [XXXX]
	//   00d4: MASK   WS_REMIND/HI32 [XXXX]  &  fff8fffc  |  00010008
	//   00df: TEST   param[02]  [X...]  <-  PIXEL_CLOCK_V6_MISC_REF_DIV_SRC
	//   00e3: JUMP_Equal  00ea
	//   00e6: AND    WS_REMIND/HI32 [.X..]  <-  f8
	//   00ea: COMP   reg[1707]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   00ef: JUMP_NotEqual  012a
	//   00f2: COMP   reg[1700]  [...X]  <-  param[01]  [X...]
	//   00f7: JUMP_NotEqual  012a
	//   00fa: COMP   reg[1701]  [XX..]  <-  param[01]  [..XX]
	//   00ff: JUMP_NotEqual  012a
	//   0102: COMP   reg[1701]  [...X]  <-  param[03]  [.X..]
	//   0107: JUMP_NotEqual  012a
	//   010a: COMP   reg[1705]  [..XX]  <-  param[03]  [..XX]
	//   010f: JUMP_NotEqual  012a
	//   0112: COMP   reg[1702]  [.X..]  <-  param[01]  [.X..]
	//   0117: JUMP_NotEqual  012a
	//   011a: COMP   param[02]  [..XX]  <-  0002
	//   011f: JUMP_Equal  012e
	//   0122: COMP   reg[1702]  [...X]  <-  param[03]  [X...]
	//   0127: JUMP_Equal  012e
	//   012a: OR     param[02]  [X...]  <-  PIXEL_CLOCK_V6_MISC_FORCE_PROG_PPLL
	//   012e: SET_REG_BLOCK  0000
	//   0131: EOT
}

// command_table  0000ca70  #2d  (LUT_AutoFill):
//
//   Size         00d9
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 03
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
void aruba_fuck_my_lute(struct radeon_device *rdev, uint8_t lute_id)
{
	bool orgasm = false, orgasm2 = false;
	uint32_t regptr;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = aruba_get_block_offest(lute_id) >> 2;
	//   000b: CLEAR  reg[1a78]  [...X]
	radeon_mask(rdev, (0x1a78 + regptr) << 2, 0xff, 0);
	//   000f: CLEAR  reg[1a80]  [XXXX]
	radeon_write(rdev, (0x1a80 + regptr) << 2, 0);
	//   0013: COMP   param[00]  [..X.]  <-  01
	//   0017: JUMP_NotEqual  009a
	if (orgasm)
		goto l_9a;
	//   001a: TEST   reg[1a01]  [...X]  <-  03
	//   001f: JUMP_Equal  0059
	if (orgasm2)
		goto l_59;
	//   0022: OR     reg[1a7e]  [...X]  <-  07
	radeon_mask(rdev, (0x1a7e + regptr) << 2, 0, 7);
	//   0027: MOVE   reg[1a7f]  [...X]  <-  01
	radeon_mask(rdev, (0x1a7f + regptr) << 2, 0xff, 1);
	do {
		//   002c: DELAY_MicroSec  01
		udelay(1);
		//   002e: TEST   reg[1a7f]  [...X]  <-  02
		//   0033: JUMP_Equal  002c
	} while (!(radeon_read(rdev, (0x1a7f + regptr) << 2) & BIT(1)));
	//   0036: CLEAR  reg[1a7f]  [...X]
	radeon_mask(rdev, (0x1a7f + regptr) << 2, 0xff, 0);
	//   003a: CLEAR  reg[1a81]  [..XX]
	radeon_mask(rdev, (0x1a81 + regptr) << 2, 0xffff, 0);
	//   003e: CLEAR  reg[1a82]  [..XX]
	radeon_mask(rdev, (0x1a82 + regptr) << 2, 0xffff, 0);
	//   0042: CLEAR  reg[1a83]  [..XX]
	radeon_mask(rdev, (0x1a83 + regptr) << 2, 0xffff, 0);
	//   0046: MOVE   reg[1a84]  [..XX]  <-  ffff
	radeon_mask(rdev, (0x1a84 + regptr) << 2, 0, 0xffff);
	//   004c: MOVE   reg[1a85]  [..XX]  <-  ffff
	radeon_mask(rdev, (0x1a85 + regptr) << 2, 0, 0xffff);
	//   0052: MOVE   reg[1a86]  [..XX]  <-  ffff
	radeon_mask(rdev, (0x1a86 + regptr) << 2, 0, 0xffff);
	//   0058: EOT
	return;
 l_59:
	//   0059: CLEAR  reg[1a79]  [XXXX]
	//   005d: SET_DATA_BLOCK  05  (DAC_Info)
	//   005f: ADD    WS_DATAPTR [..XX]  <-  0004
	//   0064: CLEAR  WS_REMIND/HI32 [XXXX]
	{
		//   0067: MOVE   WS_QUOT/LOW32 [...X]  <-  data[0000] [...X]
		//   006c: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  0a
		//   0070: MOVE   WS_QUOT/LOW32 [...X]  <-  data[0001] [...X]
		//   0075: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  0a
		//   0079: MOVE   WS_QUOT/LOW32 [...X]  <-  data[0002] [...X]
		//   007e: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  04
		//   0082: MOVE   reg[1a7c]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   0087: ADD    WS_DATAPTR [..XX]  <-  0003
		//   008c: ADD    WS_REMIND/HI32 [..XX]  <-  0001
		//   0091: COMP   WS_REMIND/HI32 [..XX]  <-  0100
		//   0096: JUMP_Below  0067
	}
	//   0099: EOT
	return;
 l_9a:
	//   009a: MOVE   reg[1a79]  [...X]  <-  param[00]  [.X..]
	//   009f: CLEAR  WS_REMIND/HI32 [XXXX]
	//   00a2: MOVE   WS_REMIND/HI32 [..XX]  <-  param[01]  [XX..]
	//   00a6: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
	{
		//   00a9: COMP   param[00]  [..X.]  <-  02
		//   00ad: JUMP_NotEqual  00bc
		//   00b0: MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[1a7c]  [XXXX]
		//   00b5: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   00b9: JUMP   00c5
		//   00bc: MOVE   WS_QUOT/LOW32 [XXXX]  <-  fb[00]     [XXXX]
		//   00c0: MOVE   reg[1a7c]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   00c5: ADD    WS_FB_WIN [XXXX]  <-  00000004
		//   00cc: ADD    WS_REMIND/HI32 [XX..]  <-  0001
		//   00d1: COMP   WS_REMIND/HI32 [XX..]  <-  param[01]  [..XX]
		//   00d5: JUMP_Below  00a9
	}
	//   00d8: EOT
}

// command_table  0000e0ba  #35  (MemoryCleanUp):
//
//   Size         00dc
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        01 longs
//                Parameter space size   01 longs
//                Table update indicator 0
//
struct _MEMORY_CLEAN_UP_PARAMETERS
{
	uint16_t  usMemoryStart;                //in 8Kb boundary, offset from memory base address
	uint16_t  usMemorySize;                 //8Kb blocks aligned
};
#include "linux_glue.h"
void aruba_mcleanup(struct radeon_device *rdev, uint16_t start_8k, uint16_t size_8k)
{
	uint8_t saviour;
	uint32_t memend_256b, memend_64k, wok;
	uint32_t membase_256b, membase_b, size_b, size_now;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: MOVE   WS_REMIND/HI32 [XXXX]  <-  reg[00c4]  [XXXX]
	//   000e: SHIFT_RIGHT  WS_REMIND/HI32 [XXXX]  by  08
	membase_256b = radeon_read(rdev, 0x310) >> 8;
	//   0012: MOVE   WS_REMIND/HI32 [X...]  <-  reg[00c9]  [...X]
	membase_256b |= radeon_read(rdev, 0x324) << 24;
	//   0017: CLEAR  WS_QUOT/LOW32 [XXXX]
	//   001a: MOVE   WS_QUOT/LOW32 [..XX]  <-  start
	//   001e: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  05
	memend_256b = start_8k << 5;
	//   0022: ADD    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	memend_256b += membase_256b;
	//   0026: MOVE   param[00]  [...X]  <-  WS_QUOT/LOW32 [X...]
	saviour = memend_256b >> 24;
	//   002a: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  08
	memend_64k = memend_256b << 8;
	//   002e: SET_FB_BASE  00001700
	//   0034: CLEAR  fb[00]     [XXXX]
	//   0037: SET_DATA_BLOCK  0b  (VRAM_UsageByFirmware)
	//   0039: MOVE   work[00]   [XXXX]  <-  00001700
	//   0040: SHIFT_RIGHT  work[00]   [XXXX]  by  08
	wok = 0x00001700 >> 8;
	//   0044: ADD    WS_REMIND/HI32 [XXXX]  <-  work[00]   [XXXX]
	membase_256b += wok;
	//   0048: MOVE   work[00]   [XXXX]  <-  data[0004] [XXXX]
	wok = 0x0007ffe0; //ulStartAddrUsedByFirmware
	//   004d: SHIFT_LEFT  work[00]   [XXXX]  by  02
	wok <<= 2;
	//   0051: ADD    WS_REMIND/HI32 [XXXX]  <-  work[00]   [XXXX]
	membase_256b += wok;
	//   0055: MOVE   reg[2181]  [...X]  <-  WS_REMIND/HI32 [X...]
	radeon_mask(rdev, 0x8604, 0xff, membase_256b >> 24);
	//   005a: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
	membase_b = membase_256b << 8;
	//   005e: MOVE   reg[2180]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_write(rdev, 0x8600, membase_b);
	//   0063: CLEAR  work[00]   [XXXX]
	//   0066: MOVE   work[00]   [..XX]  <-  size
	//   006a: SHIFT_LEFT  work[00]   [XXXX]  by  0d
	size_b = size_8k << 13; // size 8k * 8*KiB
	do {
		//fprintf(stderr, "size_beer\t\t0x%x\n", size_b);
		/*do {
			//   006e: DELAY_MicroSec  c8
			udelay(200);
			//   0070: TEST   reg[21a0]  [X...]  <-  80
			//   0075: JUMP_NotEqual  006e
		} while(radeon_read(rdev, CP_STAT) & BIT(31));*/
		if (radeon_wait_clear(rdev, CP_STAT, BIT(31), 20000) < 0)
			DRM_ERROR("mothafuckin' timeout\n");
		//   0078: COMP   work[00]   [XXXX]  <-  00000000
		//   007f: JUMP_Equal  00cb
		if (size_b == 0)
			break;
		//   0082: MOVE   WS_REMIND/HI32 [XXXX]  <-  00100000
		size_now = 0x00100000;
		//   0089: COMP   work[00]   [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   008d: JUMP_Above  0094
		if (size_b <= size_now)
			//   0090: MOVE   WS_REMIND/HI32 [XXXX]  <-  work[00]   [XXXX]
			size_now = size_b;
		//   0094: SUB    work[00]   [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		size_b -= size_now;
		//   0098: MOVE   reg[2183]  [...X]  <-  param[00]  [...X]
		radeon_mask(rdev, 0x860c, 0xff, saviour);
		//   009d: MOVE   reg[2182]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		radeon_write(rdev, 0x8608, memend_64k);
		//   00a2: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  08
		memend_256b = memend_64k >> 8;
		//   00a6: MOVE   WS_QUOT/LOW32 [X...]  <-  param[00]  [...X]
		memend_256b |= saviour << 24;
		//   00aa: SHIFT_RIGHT  WS_REMIND/HI32 [XXXX]  by  08
		size_now >>= 8;
		//   00ae: ADD    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		memend_256b += size_now;
		//   00b2: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
		size_now <<= 8;
		//   00b6: MOVE   param[00]  [...X]  <-  WS_QUOT/LOW32 [X...]
		saviour = memend_256b >> 24;
		//   00ba: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  08
		memend_64k = memend_256b << 8;
		//   00be: OR     WS_REMIND/HI32 [XX..]  <-  d020
		size_now |= 0xd020 << 16;
		//   00c3: MOVE   reg[2184]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		radeon_write(rdev, 0x8610, size_now);
		//   00c8: JUMP   006e
	} while (1);
	//   00cb: MOVE   reg[0012]  [XXXX]  <-  00010000
	radeon_write(rdev, 0x48, 0x00010000);
	//   00d3: MOVE   reg[0013]  [XXXX]  <-  00010000
	radeon_write(rdev, 0x4c, 0x00010000);
	//   00db: EOT
}
