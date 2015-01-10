#include "aruba.h"
#include "linux_glue.h"
#include "radeon_util.h"
//#include "ObjectID.h"

#include <stdbool.h>
#include <stdio.h>

#define CTL_VIDEO					0x730c
#define  VIDEO_ON					BIT(0)
#define CTL_VIDEO_2					0x7310
#define DP_LINK_TRAINING_CTL				(0x1cc0 << 2)
#define  DP_LINK_TRAINING_EN				BIT(4)

#define BIT(x)				(1 << (x))

#define ATOM_ENCODER_CMD_DP_LINK_TRAINING_START			0x08
#define ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN1		0x09
#define ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN2		0x0a
#define ATOM_ENCODER_CMD_DP_LINK_TRAINING_PATTERN3		0x13
#define ATOM_ENCODER_CMD_DP_LINK_TRAINING_COMPLETE		0x0b
#define ATOM_ENCODER_CMD_DP_VIDEO_OFF				0x0c
#define ATOM_ENCODER_CMD_DP_VIDEO_ON				0x0d
#define ATOM_ENCODER_CMD_QUERY_DP_LINK_TRAINING_STATUS		0x0e
#define ATOM_ENCODER_CMD_SETUP					0x0f
#define ATOM_ENCODER_CMD_SETUP_PANEL_MODE			0x10

//ucEncoderMode
#define ATOM_ENCODER_MODE_DP					0
#define ATOM_ENCODER_MODE_LVDS					1
#define ATOM_ENCODER_MODE_DVI					2
#define ATOM_ENCODER_MODE_HDMI					3
#define ATOM_ENCODER_MODE_SDVO					4
#define ATOM_ENCODER_MODE_DP_AUDIO				5
#define ATOM_ENCODER_MODE_TV					13
#define ATOM_ENCODER_MODE_CV					14
#define ATOM_ENCODER_MODE_CRT					15
#define ATOM_ENCODER_MODE_DVO					16
#define ATOM_ENCODER_MODE_DP_SST				ATOM_ENCODER_MODE_DP    // For DP1.2
#define ATOM_ENCODER_MODE_DP_MST				5                       // For DP1.2

// define ucBitPerColor:
#define PANEL_6BIT_PER_COLOR					0x00
#define PANEL_8BIT_PER_COLOR					0x01
#define PANEL_10BIT_PER_COLOR					0x02
#define PANEL_12BIT_PER_COLOR					0x03
#define PANEL_16BIT_PER_COLOR					0x04

/* Yes, this table means we default to 6 bpc whenever we get an invalid value
 * for bpc. That's of no concern, however, as this is a bug in the caller. */
static const uint8_t bpc_to_register_table[] = {
	[6] = PANEL_6BIT_PER_COLOR,
	[8] = PANEL_8BIT_PER_COLOR,
	[10] = PANEL_10BIT_PER_COLOR,
	[12] = PANEL_12BIT_PER_COLOR,
	[16] = PANEL_16BIT_PER_COLOR,
};

/* FIXME: KILLME */
extern void usleep(unsigned int usecs);

static const uint8_t ucLVDS_Misc = 0x1c;
#define PANEL_MISC_DUAL                   0x01
#define PANEL_MISC_FPDI                   0x02
#define PANEL_MISC_8BIT_PER_COLOR         0x20

static uint8_t bpc_to_register(uint8_t bpc)
{
	if (bpc > 16)
		return PANEL_16BIT_PER_COLOR;
	return bpc_to_register_table[bpc];
}

void aruba_encoder_setup_dp(struct radeon_device *rdev, uint8_t id,
			 uint16_t pixel_clock_khz, uint8_t lane_num,
			 uint8_t bpc, uint32_t dp_link_rate)
{
	uint8_t source_crtc_id, bpc_reg;
	uint32_t quot, off;
	uint32_t pixel_clock = pixel_clock_khz / 10;
	dp_link_rate /= 10;

	off = aruba_get_block_offest(id);
	//   004b: CLEAR  reg[1c83]  [XXXX]
	radeon_write(rdev, 0x720c + off, 0);
	//   0056: MOVE   reg[1c03]  [..XX]  <-  001f
	radeon_mask(rdev, 0x700c + off, 0xffff, 0x001f);

	//   0071: AND    reg[1c00]  [.X..]  <-  fe
	radeon_mask(rdev, 0x7000 + off, BIT(16), 0);
	//   0076: CLEAR  reg[1cc1]  [..XX]
	radeon_mask(rdev, 0x7304 + off, 0xffff, 0);
	//   007a: COMP   cfg->ucBitPerColor  <-  00
	//   007e: JUMP_NotEqual  0085
		//   0081: MOVE   cfg->ucBitPerColor  <-  02
	//   0085: SUB    cfg->ucBitPerColor  <-  01
	bpc_reg = bpc_to_register(bpc);
	//   0089: MOVE   reg[1cc1]  [X...]  <-  cfg->ucBitPerColor
	radeon_mask(rdev, 0x7304 + off, 0xff << 24, bpc_reg << 24);
	/*
	 * OK, we're not changing the link rate if video is on, but then how
	 * do we change it? Someone forgetting to turn video off before calling
	 * here is no fun
	 */
	//   008e: TEST   reg[1cc3]  [...X]  <-  01
	//   0093: JUMP_NotEqual  00e3
	if (!(radeon_read(rdev, CTL_VIDEO + off) & VIDEO_ON)) {
		//   0096: SET_DATA_BLOCK  ff  (this table)
		//   0098: ADD    WS_DATAPTR [..XX]  <-  01c2
		//   009d: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->ucConfig
		//   00a1: AND    WS_REMIND/HI32 [XXXX]  <-  00000003
		//// cfg->ucDPLinkRate;
		//   00a8: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
		//   00ac: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
		//   00b0: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
		////dp_link_rate = dp_link_rates[cfg->acConfig.ucDPLinkRate];
		//   00b5: AND    reg[1cc9]  [..X.]  <-  fe
		radeon_mask(rdev, 0x7324 + off, BIT(8), 0);
		//   00ba: MOVE   reg[1cca]  [XXXX]  <-  00008000
		radeon_write(rdev, 0x7328 + off, 0x00008000);
		//   00c2: CLEAR  WS_QUOT/LOW32 [XXXX]
		//   00c5: MOVE   WS_QUOT/LOW32 [..XX]  <-  cfg->usPixelClock
		//   00c9: MUL    WS_QUOT/LOW32 [XXXX]  <-  00008000
		//   00d0: DIV    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		quot = pixel_clock * 0x00008000 / dp_link_rate;
		//   00d4: MOVE   reg[1ccb]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		radeon_write(rdev, 0x732c + off, quot);
		//   00d9: OR     reg[1ccc]  [X...]  <-  10
		radeon_mask(rdev, 0x7330 + off, 0, BIT(28));
		//   00de: OR     reg[1c00]  [..X.]  <-  04
		radeon_mask(rdev, 0x7000 + off, 0, BIT(10));
	}
	//   00e3: MOVE   param[01]  [...X]  <-  reg[1c00]  [...X]
	source_crtc_id = radeon_read(rdev, 0x7000 + off) & 0xff;
	//   00e8: AND    param[01]  [...X]  <-  07
	source_crtc_id &= 7;
	//   00ec: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = aruba_get_block_offest(source_crtc_id);
	//   00ee: SHIFT_LEFT  cfg->ucLaneNum  by  04
	//   00f2: MOVE   reg[1b9c]  [.X..]  <-  cfg->ucLaneNum
	radeon_mask(rdev, 0x6e70 + off, 0xff << 16, lane_num << 20); // FIXME: bitmap last
	//   00f7: SET_REG_BLOCK  0000
	//   00fa: EOT
	return;
}

void aruba_encoder_setup_other(struct radeon_device *rdev, uint8_t id,
			       uint8_t mode, uint8_t lane_num)
{
	uint32_t off = aruba_get_block_offest(id);

	//   004b: CLEAR  reg[1c83]  [XXXX]
	radeon_write(rdev, 0x720c + off, 0);
	//   004f: COMP   param[01]  [...X]  <-  01
	//   0053: JUMP_Equal  010c
	//if (mode != ATOM_ENCODER_MODE_LVDS) {
	//   0056: MOVE   reg[1c03]  [..XX]  <-  001f
	radeon_mask(rdev, 0x700c + off, 0xffff, 0x001f);

	//   005c: COMP   param[01]  [...X]  <-  ATOM_ENCODER_MODE_DP
	//   0060: JUMP_Equal  0071
	//   0063: COMP   param[01]  [...X]  <-  ATOM_ENCODER_MODE_DVI
	//   0067: JUMP_Equal  00fb
	//   006a: COMP   param[01]  [...X]  <-  ATOM_ENCODER_MODE_DP_AUDIO
	//   006e: JUMP_NotEqual  0103

	switch (mode) {
	case ATOM_ENCODER_MODE_DVI:
		//   00fb: MOVE   reg[1c83]  [XXXX]  <-  00000000
		radeon_write(rdev, 0x7204 + off, 0);
	default:		/* Fall through */
		//   0103: AND    reg[1c7c]  [..XX]  <-  fcef
		radeon_mask(rdev, 0x71f0 + off, 0x0310, 0);
		//   0109: JUMP   0145
		break;
	///} else {
	case ATOM_ENCODER_MODE_LVDS:
		//   010c: MOVE   reg[1c03]  [..XX]  <-  0063
		radeon_mask(rdev, 0x700c + off, 0xffff, 0x0063);
		//   0112: SET_DATA_BLOCK  06  (LVDS_Info)
		//   0114: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
		//   0119: TEST   WS_REMIND/HI32 [X...]  <-  20
		//   011d: JUMP_Equal  0136
		if (ucLVDS_Misc & PANEL_MISC_8BIT_PER_COLOR) {
			//   0120: OR     reg[1c8c]  [...X]  <-  01
			radeon_mask(rdev, 0x7230 + off, 0, BIT(0));
			//   0125: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
			//   012a: TEST   WS_REMIND/HI32 [X...]  <-  02
			//   012e: JUMP_Equal  0136
			if (ucLVDS_Misc & PANEL_MISC_FPDI)
				//   0131: OR     reg[1c8c]  [...X]  <-  10
				radeon_mask(rdev, 0x7230 + off, 0, BIT(4));
		}
		//   0136: TEST   WS_REMIND/HI32 [X...]  <-  01
		//   013a: JUMP_Equal  0154
		if (ucLVDS_Misc & PANEL_MISC_DUAL) {
			if (lane_num > 4) {
				DRM_DEBUG_KMS("Changing lane num for LVDS from %d to 4.\n", lane_num);
				lane_num = 4;
			}
		} else {
			//   013d: OR     reg[1c8c]  [..X.]  <-  01
			radeon_mask(rdev, 0x7230 + off, 0, BIT(8));
			//   0142: JUMP   014c
			if (lane_num <= 4) {
				DRM_DEBUG_KMS("Changing lane num for LVDS from %d to 8.\n", lane_num);
				lane_num = 8;
			}
		}
	}
	//   0145: COMP   param[01]  [..X.]  <-  04
	//   0149: JUMP_BelowOrEq  0154
	if (lane_num > 4)
		//   014c: OR     reg[1c00]  [.X..]  <-  01
		radeon_mask(rdev, 0x7000 + off, 0, BIT(16));
		//   0151: JUMP   0159
	else
		//   0154: AND    reg[1c00]  [.X..]  <-  fe
		radeon_mask(rdev, 0x7000 + off, BIT(16), 0);
	//   0159: OR     reg[1c00]  [..X.]  <-  04
	radeon_mask(rdev, 0x7000 + off, 0, BIT(11));
	//   015e: SET_REG_BLOCK  0000
	//   0161: EOT
	return;
}

// command_table  0000e742  #04  (SetClocksRatio/DIGxEncoderControl):
//
//   Size         01c8
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 04
//   Attributes:  Work space size        00 longs
//                Parameter space size   01 longs
//                Table update indicator 0

void aruba_encoder_setup_panel_mode(struct radeon_device *rdev,
				    uint8_t encoder_id, uint8_t panel_mode)
{
	uint32_t off = aruba_get_block_offest(encoder_id);
	//   01b2: OR     reg[1cd5]  [...X]  <-  10
	radeon_mask(rdev, 0x7354 + off, 0, 0x10);
	//   01b7: MOVE   reg[1cde]  [...X]  <-  param[01]  [...X]
	radeon_mask(rdev, 0x7378 + off, 0xff, panel_mode);
}

void aruba_encoder_video_on(struct radeon_device *rdev, uint8_t encoder_id)
{
	const uint32_t off = aruba_get_block_offest(encoder_id);
	//   0199: OR     reg[1cc9]  [..X.]  <-  01
	radeon_mask(rdev, 0x7324 + off, 0, 1 << 8);
	//   019e: DELAY_MicroSec  0a
	usleep(10);
	//   01a0: AND    reg[1cc4]  [...X]  <-  fe
	radeon_mask(rdev, CTL_VIDEO_2 + off, 1, 0);
	//   01a5: DELAY_MicroSec  0a
	usleep(10);
	//   01a7: MOVE   reg[1cc3]  [..XX]  <-  0201
	radeon_mask(rdev, CTL_VIDEO + off, 0xffff, BIT(9) | VIDEO_ON);
	//   01ad: DELAY_MicroSec  c8
	usleep(200);
}

void aruba_encoder_video_off(struct radeon_device *rdev, uint8_t encoder_id)
{
	uint32_t off;
	off = aruba_get_block_offest(encoder_id);
	//   0189: CLEAR  reg[1cc3]  [..XX]
	radeon_mask(rdev, CTL_VIDEO + off, 0xffff, 0);
	//   018d: DELAY_MicroSec  c8
	usleep(200);
	//   018f: OR     reg[1cc4]  [...X]  <-  01
	radeon_mask(rdev, CTL_VIDEO_2 + off, 0, BIT(0));
	//   0194: DELAY_MicroSec  32
	usleep(50);
}

void aruba_encoder_link_training_start(struct radeon_device *rdev,
				       uint8_t encoder_id)
{
	uint32_t off;
	off = aruba_get_block_offest(encoder_id);
	//   0179: AND    reg[1cc0]  [...X]  <-  ef
	radeon_mask(rdev, 0x7300 + off, BIT(4), 0);
}

void aruba_encoder_link_training_pattern(struct radeon_device *rdev,
				       uint8_t encoder_id, uint8_t pattern)
{
	uint32_t off;
	off = aruba_get_block_offest(encoder_id);
	//   0162: CLEAR  reg[1cd1]  [...X]
	radeon_mask(rdev, 0x7344 + off, 0xff, pattern - 1);
}

void aruba_encoder_link_training_finish(struct radeon_device *rdev,
				       uint8_t encoder_id)
{
	uint32_t off;
	off = aruba_get_block_offest(encoder_id);
	//   0181: OR     reg[1cc0]  [...X]  <-  10
	radeon_mask(rdev, 0x7300 + off, 0, BIT(4));
}

// command_table  0000c778  #2a  (SelectCRTC_Source):
//
//   Size         00c8
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 02
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//

#define ASIC_INT_DAC1_ENCODER_ID				0x00
#define ASIC_INT_DIG1_ENCODER_ID				0x03
#define ASIC_INT_DVO_ENCODER_ID					0x07
#define ASIC_INT_DIG2_ENCODER_ID				0x09
#define ASIC_INT_DIG3_ENCODER_ID				0x0a
#define ASIC_INT_DIG4_ENCODER_ID				0x0b
#define ASIC_INT_DIG5_ENCODER_ID				0x0c
#define ASIC_INT_DIG6_ENCODER_ID				0x0d
#define ASIC_INT_DIG7_ENCODER_ID				0x0e

#define ATOM_ENCODER_MODE_LVDS				1

#define BIT_DEPTH_CTL					0x6fc8

static uint8_t dig_encoder_id_to_index(uint8_t dig_encoder_id)
{
	if (dig_encoder_id == ASIC_INT_DIG1_ENCODER_ID)
		return 0;
	else
		return dig_encoder_id - 8;
}

void aruba_set_encoder_crtc_source(struct radeon_device *rdev,
				   uint8_t crtc_id, uint8_t encoder_id,
				   uint8_t encoder_mode)
{
	uint32_t off;
	const uint8_t ucLVDS_Misc = 0x1c;
	const uint32_t ulLCDBitDepthControlVal = 0x5010000;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009:
	//         0d3f005a5a
	//                           SWITCH  encoder_id
	//         00->002f 07->0037 03->003f 09->003f 0a->003f 0b->003f 0c->003f 0d->003f
	switch (encoder_id) {
	case ASIC_INT_DAC1_ENCODER_ID:	//0x0:
		//   002f: MOVE   reg[19e5]  [...X]  <-  crtc_id
		radeon_mask(rdev, 0x19e5 << 2, 0xff, crtc_id);
		//   0034: JUMP   00b2
		break;
	case ASIC_INT_DVO_ENCODER_ID:	//0x7:
		//   0037: MOVE   reg[1859]  [...X]  <-  crtc_id
		radeon_mask(rdev, 0x1859 << 2, 0xff, crtc_id);
		//   003c: JUMP   00b2
		break;
	default:
		//   002e: EOT
		return;
	case ASIC_INT_DIG1_ENCODER_ID:	//0x3: // fall
	case ASIC_INT_DIG2_ENCODER_ID:	//0x9: // fall
	case ASIC_INT_DIG3_ENCODER_ID:	//0xa: // fall
	case ASIC_INT_DIG4_ENCODER_ID:	//0xb: // fall
	case ASIC_INT_DIG5_ENCODER_ID:	//0xc: // fall
	case ASIC_INT_DIG6_ENCODER_ID:	//0xd: // fall

		//   003f: MOVE   save  <-  crtc_id

		//   0055: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		off = aruba_get_block_offest(dig_encoder_id_to_index(encoder_id));
		//   0057: MASK   reg[1c00]  [...X]  &  f8  |  save
		radeon_mask(rdev, 0x7000 + off, 0x7, crtc_id);

		//   0061: COMP   encoder_mode  <-  01
		//   0065: JUMP_NotEqual  00b2
		if (encoder_mode != ATOM_ENCODER_MODE_LVDS)
			break;
		//   0068: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
		off = aruba_get_block_offest(crtc_id);
		//   006a: CLEAR  reg[1bf2]  [XXXX]
		radeon_write(rdev, BIT_DEPTH_CTL + off, 0);
		//   006e: SET_DATA_BLOCK  06  (LVDS_Info)
		//   0070: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
		//   0075: AND    WS_REMIND/HI32 [X...]  <-  70
		//   0079: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
		//   007b: MOVE   WS_QUOT/LOW32 [XXXX]  <-  data[0140] [XXXX]
		//   0080: COMP   WS_QUOT/LOW32 [XXXX]  <-  00000000
		//   0087: JUMP_Equal  0092
		if (ulLCDBitDepthControlVal != 0) ; {
			//   008a: MOVE   reg[1bf2]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
			radeon_write(rdev, BIT_DEPTH_CTL + off, ulLCDBitDepthControlVal);
			//   008f: JUMP   00b8
			goto l_less_common;
		}
		//   0092: COMP   WS_REMIND/HI32 [X...]  <-  20
		//   0096: JUMP_Above  00b8
		if ((ucLVDS_Misc & 0x70) > 0x20)
			goto l_less_common;
		//   0099: JUMP_NotEqual  00a7
		if ((ucLVDS_Misc & 0x70) == 0x20)
			//   009c: OR     reg[1bf2]  [XXXX]  <-  0000f100
			radeon_mask(rdev, BIT_DEPTH_CTL + off, 0, 0xf100);
		//   00a4: JUMP   00b8
		else
			//   00a7: OR     reg[1bf2]  [XXXX]  <-  0000a100
			radeon_mask(rdev, BIT_DEPTH_CTL + off, 0, 0xa100);
		//   00af: JUMP   00b8
		goto l_less_common;
	}
	//   00b2: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	off = aruba_get_block_offest(crtc_id & 0x7) << 2;
	//   00b4: CLEAR  reg[1bf2]  [XXXX]
	radeon_write(rdev, BIT_DEPTH_CTL + off, 0);
 l_less_common:
	//   00b8: CLEAR  reg[1bee]  [.X..]
	radeon_mask(rdev, 0x6fb8 + off, 0xff << 16, 0);
	//   00bc: CLEAR  reg[1bf9]  [XXXX]
	radeon_write(rdev, 0x6fe4 + off, 0);
	//   00c0: CLEAR  reg[1bed]  [XXXX]
	radeon_write(rdev, 0x6fb4 + off, 0);
	//   00c4: SET_REG_BLOCK  0000
	//   00c7: EOT
}
