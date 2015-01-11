#include "linux_glue.h"

#include <stdbool.h>
#include <stdint.h>

// command_table  0000e578  #49  (EnableYUV):
//
// Size         00bd
// Format Rev.  02
// Param Rev.   00
// Content Rev. 01
// Attributes:  Work space size        00 longs
// Parameter space size   01 longs
// Table update indicator 0
//

uint16_t master_yuv(uint16_t par)
{
	uint16_t somepointer, rem;
	// 0006: MOVE   WS_QUOT/LOW32 [..XX]  <-  param[00]  [..XX]
	// 000a: MOVE   param[00]  [..XX]  <-  ff00
	// 000f: SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	// 0011: MOVE   WS_REMIND/HI32 [..XX]  <-  WS_QUOT/LOW32 [..XX]
	// 0015: SHIFT_RIGHT  WS_REMIND/HI32 [..XX]  by  0c
	rem = par >> 12;
	// 0019: COMP   WS_REMIND/HI32 [...X]  <-  02
	// 001d: JUMP_Equal  002f
	if (rem == 2) {
		// 0020: COMP   WS_REMIND/HI32 [...X]  <-  03
		// 0024: JUMP_NotEqual  00b9
		if (rem == 3)
			return 0;
		// 0027: ADD    WS_DATAPTR [..XX]  <-  data[0006] [..XX]
		// 002c: JUMP   0034
	} else {
		// 002f: ADD    WS_DATAPTR [..XX]  <-  data[000a] [..XX]
		// 0034: MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	}
	do {
		// 0039: COMP   WS_REMIND/HI32 [...X]  <-  00
		// 003d: JUMP_Equal  00b9
		if (rem == 0)
			return 0;
		// 0040: COMP   WS_QUOT/LOW32 [..XX]  <-  data[0004] [..XX]
		// 0045: JUMP_Equal  0054
		if (co)
			break;
		// 0048: ADD    WS_DATAPTR [..XX]  <-  0008
		// 004d: SUB    WS_REMIND/HI32 [...X]  <-  01
		// 0051: JUMP   0039
	} while (1);
	// 0054: MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0006] [..XX]
	// 0059: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0008] [..XX]
	// 005e: SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	// 0060: ADD    WS_QUOT/LOW32 [..XX]  <-  WS_DATAPTR [..XX]
	// 0064: COMP   WS_REMIND/HI32 [..XX]  <-  0000
	// 0069: JUMP_Equal  00a7
	// 006c: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	// 0070: CLEAR  WS_REMIND/HI32 [XXXX]
	do {
		// 0073: MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
		// 0078: MOVE   WS_REMIND/HI32 [.X..]  <-  data[0001] [...X]
		// 007d: COMP   WS_REMIND/HI32 [...X]  <-  ff
		// 0081: JUMP_Equal  00a7
		if (co)
			break;
		// 0084: COMP   WS_REMIND/HI32 [...X]  <-  01
		// 0088: JUMP_NotEqual  0090
		if (co)
			// 008b: MOVE   param[00]  [...X]  <-  data[0002] [...X]
		// 0090: COMP   WS_REMIND/HI32 [...X]  <-  02
		// 0094: JUMP_NotEqual  00a0
		if (co) {
			// 0097: MOVE   param[00]  [..X.]  <-  data[0002] [...X]
			// 009c: SUB    param[00]  [..X.]  <-  01
		}
		// 00a0: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [XX..]
		// 00a4: JUMP   0073
	} while(1);
	// 00a7: MOVE   WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	// 00ab: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0001] [..XX]
	// 00b0: COMP   WS_REMIND/HI32 [..XX]  <-  0000
	// 00b5: JUMP_Equal  00b9
	if (co)
		return 0;
	// 00b8: EOT
	return somepointer;
	// 00b9: CLEAR  WS_DATAPTR [..XX]
	// 00bc: EOT

}

// command_table  0000ccf0  #32  (ExternalEncoderControl):
//
// Size         13c9
// Format Rev.  02
// Param Rev.   00
// Content Rev. 03
// Attributes:  Work space size        02 longs
// Parameter space size   00 longs
// Table update indicator 0
//

#define EXTENC_DPCD_IDX		0x5f0
#define EXTENC_DPCD_DAT		0x5f2

#define ID_TRAVIS_LOW		0x20
#define ID_TRAVIS_HIGH		0x31

typedef struct _EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3
{
	union{
		uint16_t usPixelClock;      // pixel clock in 10Khz, valid when ucAction=SETUP/ENABLE_OUTPUT
		uint16_t usConnectorId;     // connector id, valid when ucAction = INIT
	};
	uint8_t  ucConfig;          // indicate which encoder, and DP link rate when ucAction = SETUP/ENABLE_OUTPUT
	uint8_t  ucAction;          //

	uint8_t  ucEncoderMode;     // encoder mode, only used when ucAction = SETUP/ENABLE_OUTPUT
	uint8_t  ucLaneNum;         // lane number, only used when ucAction = SETUP/ENABLE_OUTPUT
	uint8_t  ucBitPerColor;     // output bit per color, only valid when ucAction = SETUP/ENABLE_OUTPUT and ucEncodeMode= DP
	uint8_t  ucReserved;
} EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3;

// :0e 00 10 07 00 00 02 00 00 00 00 00 00 00 00 00

static const EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3 how_linux_inits_us = {
	.usConnectorId = 0x000e,
	.ucConfig = EXTERNAL_ENCODER_CONFIG_V3_ENCODER2,
	.ucAction = EXTERNAL_ENCODER_ACTION_V3_ENCODER_INIT,
	.ucEncoderMode = 0,
	.ucLaneNum = 8,
	.ucBitPerColor = 2, // means 6 BPC
};
// ucAction
#define EXTERNAL_ENCODER_ACTION_V3_DISABLE_OUTPUT         0x00
#define EXTERNAL_ENCODER_ACTION_V3_ENABLE_OUTPUT          0x01
#define EXTERNAL_ENCODER_ACTION_V3_ENCODER_INIT           0x07
#define EXTERNAL_ENCODER_ACTION_V3_ENCODER_SETUP          0x0f
#define EXTERNAL_ENCODER_ACTION_V3_ENCODER_BLANKING_OFF   0x10
#define EXTERNAL_ENCODER_ACTION_V3_ENCODER_BLANKING       0x11
#define EXTERNAL_ENCODER_ACTION_V3_DACLOAD_DETECTION      0x12
#define EXTERNAL_ENCODER_ACTION_V3_DDC_SETUP              0x14

// ucConfig
#define EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_MASK                              0x03
#define EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_1_62GHZ             0x00
#define EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_2_70GHZ             0x01
#define EXTERNAL_ENCODER_CONFIG_V3_DPLINKRATE_5_40GHZ             0x02
#define EXTERNAL_ENCODER_CONFIG_V3_ENCODER_SEL_MASK                 0x70
#define EXTERNAL_ENCODER_CONFIG_V3_ENCODER1                         0x00
#define EXTERNAL_ENCODER_CONFIG_V3_ENCODER2                         0x10
#define EXTERNAL_ENCODER_CONFIG_V3_ENCODER3                         0x20


//static uint8_t extenc_read(struct radeon_device *rdev, uint16_t addr)
//{
//	return 0;
//}

static uint8_t extenc_read_modify_write_reg(uint16_t bridge_reg,
					    uint8_t and_mask, uint8_t or_mask)
{
	/*
	 * work[00] == [or_mask][and_mask][addr_lo][addr_hi]
	 */

	/*
	 * Simplified pseudo_c_code of what this does:
	 * extenc_rw(bridge_reg, and_mask, or_mask)
	 * {
	 * 	uint8_t reg8;
	 * 	dpcd_write16(rdev, EXTENC_DPCD_IDX, bridge_reg);
	 * 	reg8 = dpcd_readb(rdev, EXTENC_DPCD_DAT);
	 *
	 * 	if (and_mask == 0xff)
	 * 		return;
	 *
	 * 	reg8 &= and_mask;
	 * 	reg8 |= or_mask;
	 * 	dpcd_write8(rdev, EXTENC_DPCD_DAT, reg8);
	 *
	 * 	return reg8;
	 * }
	 * ---
	 * after that, WS_REMIND is left with:
	 * [00][(reg8 & and_mask) | or_mask][addr_lo][addr_hi]
	 *
	 * The reason this handler is so long in ATOM bytecode is that it
	 * implements retries, which in our pseudocode are handled by the
	 * dpcd_(read/write)* wrappers, as they fucking should.
	 */
// ext_encoder_read_me_some_shit:	//// This looks like the heart of DPCD indexing
	//   0131: CLEAR  work[01]   [..X.]
	//   0134: MOVE   work[01]   [XX..]  <-  param[00]  [XX..]
	//   0138: SET_FB_BASE  00004c00
	//   013e: MOVE   fb[00]     [XXXX]  <-  618005f0
	//   0145: CLEAR  fb[01]     [XXXX]
	//   0148: MOVE   fb[01]     [..XX]  <-  work[00]   [..XX] : bridge_reg
	//// dpcd_write(0x5f0, bridge_reg);
	//   014c: MOVE   param[01]  [...X]  <-  param[00]  [...X]
	//   0150: MOVE   param[01]  [X...]  <-  param[00]  [..X.]
	//   0154: MOVE   param[00]  [XXXX]  <-  00004c00
	//   015b: CLEAR  param[01]  [.XX.]
	//   015e: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	//   0160: COMP   param[01]  [..X.]  <-  00
	//   0164: JUMP_Equal  0177
	//   0167: DELAY_MicroSec  c8
	//   0169: DELAY_MicroSec  c8
	//   016b: ADD    work[01]   [..X.]  <-  01
	//   016f: COMP   work[01]   [..X.]  <-  0c
	//   0173: JUMP_Below  0154
	//   0176: EOT
	return -1;
	//   0177: CLEAR  work[01]   [..X.]
	//   017a: SET_FB_BASE  00004c00
	//   0180: MOVE   fb[00]     [XXXX]  <-  409005f2
	//// dpcd_read(0x5f2);
	//   0187: MOVE   param[00]  [XXXX]  <-  4c044c00
	//   018e: CLEAR  param[01]  [.XX.]
	//   0191: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	//   0193: COMP   param[01]  [..X.]  <-  00
	//   0197: JUMP_Equal  01a6
	//   019a: ADD    work[01]   [..X.]  <-  01
	//   019e: COMP   work[01]   [..X.]  <-  06
	//   01a2: JUMP_Below  017a
	//   01a5: EOT
	return -1;
// extman_write:
	//   01a6: CLEAR  WS_REMIND/HI32 [XXXX]
	//   01a9: SET_FB_BASE  00004c04
	//   01af: MOVE   WS_REMIND/HI32 [.X..]  <-  fb[00]     [...X]
	//   01b3: COMP   work[00]   [.X..] : and_mask  <-  ff
	//   01b7: JUMP_Equal  01f9
	//   01ba: AND    WS_REMIND/HI32 [.X..]  <-  work[00]   [.X..] : and_mask
	//   01be: OR     WS_REMIND/HI32 [.X..]  <-  work[00]   [X...] : or_mask
	//   01c2: MOVE   WS_REMIND/HI32 [..XX]  <-  work[00]   [..XX] : bridge_reg
	//   01c6: SET_FB_BASE  00004c00
	//   01cc: MOVE   fb[00]     [XXXX]  <-  728005f0
	//// dpcd_write(0x5f2, yadayada, yada);
	//   01d3: MOVE   fb[01]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   01d7: CLEAR  work[01]   [..X.]
	//   01da: MOVE   param[00]  [XXXX]  <-  00004c00
	//   01e1: CLEAR  param[01]  [.XX.]
	//   01e4: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	//   01e6: COMP   param[01]  [..X.]  <-  00
	//   01ea: JUMP_Equal  01f9
	//   01ed: ADD    work[01]   [..X.]  <-  01
	//   01f1: COMP   work[01]   [..X.]  <-  06
	//   01f5: JUMP_Below  01da
	//   01f8: EOT
	return -1;
	//   01f9: MOVE   param[00]  [XX..]  <-  work[01]   [XX..]
	//   01fd: MOVE   param[00]  [...X]  <-  param[01]  [...X]
	//   0201: MOVE   param[00]  [..X.]  <-  param[01]  [X...]
	//   0205:
	//                           SWITCH  work[01]   [...X]
	//         00->0108 01->0130 02->02ab 03->00e3 04->02c0
	/*
	 * "caller" normally puts an enum here as to where to return once we're
	 * done. The "return" always points right below the JUMP to this
	 * "function", so we can just return safely without any need to parse
	 * any bullshit return_to enum. PHEW!
	 */
	//   021e: EOT
	return -1;
}

// command_table  0000ccf0  #32  (ExternalEncoderControl):
//
//   Size         13c9
//   Format Rev.  02
//   Param Rev.   00
//   Content Rev. 03
//   Attributes:  Work space size        02 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//

static const uint16_t reg_off[] = {0x00, 0x14, 0x28, 0x40, 0x54, 0x68};

static const uint32_t travis_data[];

static void add_to_proccess(uint32_t encoder_wo_inst)
{
	(void)encoder_wo_inst;
}

static void change_process_data(uint16_t idx, uint8_t new_data)
{
	(void)idx;
	(void)new_data;
}

static void run_process()
{
}

static bool find_spread_spectrum_data(uint8_t ucClockIndication,
				      uint16_t *ss_percent,
				      uint16_t *ss_rate_khz)
{
	(void) ucClockIndication;
	*ss_percent = 0x0064;
	*ss_rate_khz = 3300;
	return true;
}

static uint16_t get_lvds_info_pixel_clock()
{
	return 7630;
}

void fucking_headache(struct radeon_device *rdev,
		      EXTERNAL_ENCODER_CONTROL_PARAMETERS_V3 *cfg)
{
	bool is_travis, found;
	uint8_t extenc_reg8;
	uint16_t regptr, ss_percent, ss_rate_khz, pixel_clock;
	uint32_t quot, rem, win, work[2];
	const uint32_t *enc_data;

	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CLEAR  work[00]   [XXXX]
	//   000c: MOVE   work[00]   [..XX]  <-  param[00]  [..XX]
	//   0010: MOVE   param[00]  [..XX]  <-  2123
	//   0015: TEST   param[00]  [.X..]  <-  10
	//   0019: JUMP_Equal  0021
	//   001c: MOVE   param[00]  [..XX]  <-  2223
	//   0021: CALL_TABLE  49  (EnableYUV)
	//   0023: COMP   WS_DATAPTR [..XX]  <-  0000
	//   0028: JUMP_Equal  05b6
	if (dataptr == 0)
		goto _something_totally_different;
	//   002b: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0004] [..XX]
	//   0030: COMP   WS_REMIND/HI32 [...X]  <-  00
	//   0034: JUMP_Equal  05b6
	if (rem == 0)
		goto _something_totally_different;
	//   0037: COMP   WS_REMIND/HI32 [...X]  <-  15
	//   003b: JUMP_Equal  05b6
	if (rem == 0x15)
		goto _something_totally_different;
	//   003e:
	//                           SWITCH  param[00]  [X...] : cfg->ucAction
	//         07->0276 05->00ef 06->00ef 12->021f 01->005c 00->0069
	switch (cfg->ucAction) {
	case EXTERNAL_ENCODER_ACTION_V3_DISABLE_OUTPUT:		//0x00
		goto l_DISABLE_OUTPUT;
	case EXTERNAL_ENCODER_ACTION_V3_ENABLE_OUTPUT:		//0x01
		goto l_ENABLE_OUTPUT;
	case EXTERNAL_ENCODER_ACTION_V3_ENCODER_INIT:	 	//0x07
		goto l_ENCODER_INIT;
	case EXTERNAL_ENCODER_ACTION_V3_DACLOAD_DETECTION:	//0x12
		goto l_DACLOAD_DETECTION;
	case 0x05:
	case 0x06:	/* Fall through */
		goto l_UNKNOWN_05_06;
	default:
		//   005b: EOT
		return;
	}

 l_ENABLE_OUTPUT:
	//   005c: TEST   param[00]  [.X..]  <-  10
	//   0060: JUMP_Equal  0a65
	// return equal
	//   0063: OR     reg[1919]  [X...]  <-  03
	//   0068: EOT
	return;
 l_DISABLE_OUTPUT:
	//   0069: TEST   param[00]  [.X..]  <-  10
	//   006d: JUMP_Equal  0a65
	// return equal
	//   0070: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0001] [..XX]
	//   0075: SET_DATA_BLOCK  ff  (this table)
	//   0077: ADD    WS_DATAPTR [..XX]  <-  13b1
	//   007c: COMP   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
	//   0081: JUMP_Equal  008c
	//   0084: ADD    WS_DATAPTR [..XX]  <-  0004
	//   0089: JUMP   007c
	//   008c: MOVE   WS_REGPTR [..XX]  <-  data[0002] [..XX]
	//   0091: TEST   reg[1c51]  [...X]  <-  01
	//   0096: JUMP_Equal  0a65
	//   0099: MOVE   WS_REMIND/HI32 [..XX]  <-  0001
	//   009e: SET_DATA_BLOCK  ff  (this table)
	//   00a0: ADD    WS_DATAPTR [..XX]  <-  13b1
	//   00a5: TEST   reg[1c50]  [..X.]  <-  WS_REMIND/HI32 [...X]
	//   00aa: JUMP_NotEqual  00c0
	//   00ad: SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  01
	//   00b1: ADD    WS_DATAPTR [..XX]  <-  0004
	//   00b6: COMP   WS_REMIND/HI32 [...X]  <-  40
	//   00ba: JUMP_NotEqual  00a5
	//   00bd: JUMP   00d5
	//   00c0: MOVE   WS_REGPTR [..XX]  <-  data[0002] [..XX]
	//   00c5: CLEAR  reg[1cc3]  [..XX]
	//   00c9: DELAY_MicroSec  c8
	//   00cb: OR     reg[1cc4]  [...X]  <-  01
	//   00d0: DELAY_MicroSec  32
	//   00d2: CLEAR  WS_REGPTR [..XX]
	//   00d5: MOVE   work[01]   [...X]  <-  03	// return_point_00e3
	//   00d9: MOVE   work[00]   [XXXX]  <-  00ffbc01
	//   00e0: JUMP   0131
	extenc_read_modify_write_reg(0x01bc, 0, 0xff);
	//   00e3: TEST   WS_REMIND/HI32 [.X..]  <-  02
	//   00e7: JUMP_Equal  0a65
	//   00ea: DELAY_MilliSec  01
	//   00ec: JUMP   00d5
 l_UNKNOWN_05_06:
	//   00ef: CLEAR  work[01]   [...X] : return_point_0108
	//   00f2: MOVE   work[00]   [XXXX]  <-  01fef300
	//   00f9: COMP   param[00]  [X...]  <-  05
	//   00fd: JUMP_Equal  0131
	//// extenc_read_modify_write_reg(0x03f, 0xfe, 0x01);
	//   0100: MOVE   work[00]   [XX..]  <-  00fe
	//   0105: JUMP   0131
	extenc_read_modify_write_reg(0x03f, 0xfe, 0x00);
	//   0108: SET_DATA_BLOCK  06  (LVDS_Info)
	//   010a: MOVE   WS_REMIND/HI32 [...X]  <-  data[0028] [...X]
	//   010f: TEST   WS_REMIND/HI32 [...X]  <-  01
	//   0113: JUMP_Equal  0a65
	//   0116: MOVE   work[01]   [...X]  <-  01	// do then return
	//   011a: MOVE   work[00]   [XXXX]  <-  04fbf400
	//   0121: COMP   param[00]  [X...]  <-  05
	//   0125: JUMP_Equal  0131
	//   0128: MOVE   work[00]   [XX..]  <-  00fb
	//   012d: JUMP   0131
	extenc_read_modify_write_reg(0xf4, 0xfb, 0x04);
	//   0130: EOT
	return;

 l_DACLOAD_DETECTION:
	//   021f: AND    reg[05c9]  [...X]  <-  fc
	//   0224: CLEAR  work[00]   [.X..]
	//   0227: SET_FB_BASE  00004c00
	//   022d: MOVE   fb[00]     [XXXX]  <-  40900200
	//// Read 1 byte from 0x200: SINK_COUNT
	//   0234: MOVE   param[01]  [...X]  <-  param[00]  [...X]
	//   0238: MOVE   param[01]  [X...]  <-  param[00]  [..X.]
	//   023c: MOVE   param[00]  [XXXX]  <-  4c044c00
	//   0243: CLEAR  param[01]  [.XX.]
	//   0246: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	//   0248: COMP   param[01]  [..X.]  <-  00
	//   024c: JUMP_Equal  025f
	//   024f: DELAY_MicroSec  c8
	//   0251: DELAY_MicroSec  c8
	//   0253: ADD    work[00]   [.X..]  <-  01
	//   0257: COMP   work[00]   [.X..]  <-  06
	//   025b: JUMP_Below  0227
	//   025e: EOT
	//   025f: SET_FB_BASE  00004c04
	//   0265: AND    fb[00]     [...X]  <-  3f
	//   0269: COMP   fb[00]     [...X]  <-  00
	//   026d: JUMP_Equal  0275
	//   0270: OR     reg[05c9]  [...X]  <-  02
	//   0275: EOT
	return;
 l_ENCODER_INIT:
	//   0276: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0279: MOVE   WS_REMIND/HI32 [...X]  <-  param[00]  [...X]
	//   027d: AND    WS_REMIND/HI32 [...X]  <-  0f
	//   0281: SHIFT_LEFT  WS_REMIND/HI32 [..XX]  by  01
	//   0285: SET_DATA_BLOCK  ff  (this table)
	//   0287: ADD    WS_DATAPTR [..XX]  <-  0a69
	//   028c: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   0290: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	regptr = reg_off[cfg->usConnectorId & 0xf];
	//   0295: AND    reg[1880]  [.X..]  <-  fb
	aruba_mask(rdev, (0x1880 + regptr) << 2, BIT(18), 0);
	//   029a: CLEAR  WS_REGPTR [..XX]
	regptr = 0;
	//   029d: MOVE   work[01]   [...X]  <-  02 : return_point_02ab
	//   02a1: MOVE   work[00]   [XXXX]  <-  00ff0200
	//   02a8: JUMP   0131
	is_travis = false;
	extenc_reg8 = extenc_read_modify_write_reg(0x02, 0xff, 0);
	//   02ab: COMP   WS_REMIND/HI32 [.X..]  <-  20
	//   02af: JUMP_NotEqual  02d1
	if (extenc_reg8 == ID_TRAVIS_LOW) {
		//   02b2: MOVE   work[01]   [...X]  <-  04 : return_point_02c0
		//   02b6: MOVE   work[00]   [XXXX]  <-  00ff0300
		//   02bd: JUMP   0131
		extenc_reg8 = extenc_read_modify_write_reg(0x03, 0xff, 0);
		if (extenc_reg8 == ID_TRAVIS_HIGH)
			//   02c0: COMP   WS_REMIND/HI32 [.X..]  <-  31
			//   02c4: JUMP_NotEqual  02d1
			is_travis = true;
	}
	if (is_travis) {
		//   02c7: SET_DATA_BLOCK  ff  (this table)
		//   02c9: ADD    WS_DATAPTR [..XX]  <-  12ed
		enc_data = travis_data;
		//   02ce: JUMP   02e4
	} else {
		//   02d1: SET_DATA_BLOCK  ff  (this table)
		//   02d3: ADD    WS_DATAPTR [..XX]  <-  11f1
		//   02d8: TEST   param[00]  [.X..]  <-  10 : cfg->ucConfig
		//   02dc: JUMP_Equal  02e4
		if (cfg->ucConfig & EXTERNAL_ENCODER_CONFIG_V3_ENCODER2) {
			//   02df: ADD    WS_DATAPTR [..XX]  <-  0040
		}
	}
	//   02e4: MOVE   WS_REMIND/HI32 [XXXX]  <-  00004c80
	do {
		//   02eb: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
		//   02ee: MOVE   fb[00]     [XXXX]  <-  data[0000] [XXXX]
		add_to_proccess(*enc_data);
		//   02f3: ADD    WS_DATAPTR [..XX]  <-  0004
		enc_data++;
		//   02f8: ADD    WS_REMIND/HI32 [XXXX]  <-  00000004
		//   02ff: COMP   fb[00]     [XXXX]  <-  ffffffff
		//   0306: JUMP_NotEqual  02eb
	} while (*enc_data != 0xffffffff);
	//   0309: TEST   param[00]  [.X..]  <-  10
	//   030d: JUMP_Equal  054f
	if (!(cfg->ucConfig & EXTERNAL_ENCODER_CONFIG_V3_ENCODER2))
		goto l_skip_some_shit_to_54f;

#if 1
	{
		//   0310: MOVE   param[01]  [XXXX]  <-  00000006
		//   0317: CLEAR  WS_REMIND/HI32 [XXXX]
		//   031a: SET_DATA_BLOCK  1a  (ASIC_InternalSS_Info/ASIC_MVDDC_Info)
		//   031c: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
		//   0321: ADD    WS_REMIND/HI32 [..XX]  <-  WS_DATAPTR [..XX]
		//   0325: ADD    WS_DATAPTR [..XX]  <-  0004
		{
			//   032a: COMP   param[01]  [...X]  <-  data[0008] [...X]
			//   032f: JUMP_Equal  0346
			//   0332: ADD    WS_DATAPTR [..XX]  <-  000c
			//   0337: COMP   WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
			//   033b: JUMP_NotEqual  032a
		}
		//   033e: MOVE   WS_REMIND/HI32 [..XX]  <-  0000
		//   0343: JUMP   041f
	}
	found = find_spread_spectrum_data(6, &ss_percent, &ss_rate_khz);
	//   0346: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0004] [..XX]
	rem = ss_percent;
	//   034b: COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   0350: JUMP_Equal  041f
	if (!found || ss_percent == 0)
		goto not_found;
	/* ^^^ More if(found) checking ^^^ */
	/* definitely_found: */
	//   0353: MOVE   param[01]  [..XX]  <-  data[0006] [..XX]
	//   0358: MOVE   WS_FB_WIN [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	win = ss_percent;
	//   035c: DIV    param[01]  [XXXX]  <-  00000064
	quot = ss_rate_khz / 100;
	//   0363: MOVE   work[01]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	work[1] = quot;
	//   0367: MUL    WS_FB_WIN [XXXX]  <-  work[01]   [XXXX]
	quot = ss_percent * work[1];
	//   036b: MOVE   param[01]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   036f: MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_FB_WIN [XXXX]
	quot *= ss_percent;
	//   0373: MUL    WS_QUOT/LOW32 [XXXX]  <-  00000400
	quot *= 0x400;
	//   037a: DIV    WS_QUOT/LOW32 [XXXX]  <-  0000017d
	quot /= 0x0000017d;
	//   0381: MOVE   WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	win = quot;
	//   0385: MUL    param[01]  [XXXX]  <-  00080000
	quot = (ss_percent * work[1]) * 0x00080000;
	//   038c: DIV    WS_QUOT/LOW32 [XXXX]  <-  00000271
	quot /= 0x271;
	//   0393: MUL    WS_QUOT/LOW32 [XXXX]  <-  00000010
	quot *= 0x010;
	//   039a: ADD    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	win += quot;
	//   039e: MOVE   WS_REMIND/HI32 [XXXX]  <-  WS_FB_WIN [XXXX]
	rem = win;
	//   03a2: SET_DATA_BLOCK  06  (LVDS_Info)
	//   03a4: CLEAR  param[01]  [XXXX]
	//   03a7: MOVE   param[01]  [..XX]  <-  data[0004] [..XX]
	pixel_clock = get_lvds_info_pixel_clock();
	//   03ac: MUL    param[01]  [XXXX]  <-  00000230
	quot = pixel_clock * 0x230;
	//   03b3: COMP   param[01]  [..XX]  <-  0697
	//   03b8: JUMP_BelowOrEq  03e3
	if (pixel_clock <= 0x697)
		goto skip_this_nonsense;
	//   03bb: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  01
	quot >>= 1;
	//   03bf: COMP   param[01]  [..XX]  <-  0d2f
	//   03c4: JUMP_BelowOrEq  03e3
	if (pixel_clock <= 0xd2f)
		goto skip_this_nonsense;
	//   03c7: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  01
	quot >>= 1;
	//   03cb: COMP   param[01]  [..XX]  <-  1a5e
	//   03d0: JUMP_BelowOrEq  03e3
	if (pixel_clock <= 0x1a5e)
		goto skip_this_nonsense;
	//   03d3: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  01
	quot >>= 1;
	//   03d7: COMP   param[01]  [..XX]  <-  34bc
	//   03dc: JUMP_BelowOrEq  03e3
	if (pixel_clock <= 0x34bc)
		goto skip_this_nonsense;
	//   03df: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  01
	quot >>= 1;
 skip_this_nonsense:
	//   03e3: MOVE   work[00]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	work[0] = quot;
	//   03e7: SET_FB_BASE  00004ce8
	//   03ed: DIV    WS_REMIND/HI32 [XXXX]  <-  work[00]   [XXXX]
	quot = rem / work[0];
	//   03f1: MOVE   fb[00]     [.X..]  <-  WS_QUOT/LOW32 [...X]
	change_process_data(0x1a, quot & 0xff);	// reg 0x1b3
	//   03f5: SET_FB_BASE  00004cec
	//   03fb: SHIFT_LEFT  work[01]   [XXXX]  by  09
	work[1] <<= 9;
	//   03ff: DIV    work[00]   [XXXX]  <-  work[01]   [XXXX]
	quot = work[0] / work[1];
	//   0403: OR     WS_QUOT/LOW32 [...X]  <-  80
	quot |= 0x80;
	//   0407: MOVE   fb[00]     [.X..]  <-  WS_QUOT/LOW32 [...X]
	change_process_data(0x1b, quot & 0xff);	// reg 0x1b2
	//   040b: SET_FB_BASE  00004d18
	//   0411: MOVE   fb[00]     [.X..]  <-  00
	change_process_data(0x26, 0);	// reg 0xf3
	//   0415: SET_FB_BASE  00004d20
	//   041b: MOVE   fb[00]     [.X..]  <-  02
	change_process_data(0x28, BIT(1));	// reg 0x1b4
 not_found:
	//   041f: SET_FB_BASE  00004cf0
	//   0425: SET_DATA_BLOCK  06  (LVDS_Info)
	//   0427: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
	//   042c: TEST   WS_REMIND/HI32 [X...]  <-  01
	//   0430: JUMP_NotEqual  0437
	if (!(ucLCD_Misc & ATOM_PANEL_MISC_V13_DUAL));
		//   0433: MOVE   fb[00]     [.X..]  <-  00
		change_process_data(0x1c, 0);	// reg 0x9f
	//   0437: SET_FB_BASE  00004d1c
	//   043d: SET_DATA_BLOCK  06  (LVDS_Info)
	//   043f: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
	//   0444: TEST   WS_REMIND/HI32 [X...]  <-  01
	//   0448: JUMP_NotEqual  044f
	if (!(ucLCD_Misc & ATOM_PANEL_MISC_V13_DUAL));
		//   044b: MOVE   fb[00]     [.X..]  <-  3c
		change_process_data(0x27, 0x3c);
	//   044f: SET_FB_BASE  00004ca4
	//   0455: SET_DATA_BLOCK  06  (LVDS_Info)
	//   0457: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
	//   045c: TEST   WS_REMIND/HI32 [X...]  <-  02
	//   0460: JUMP_Equal  0472
	if (ucLCD_Misc & ATOM_PANEL_MISC_V13_FPDI);
		//   0463: MOVE   fb[00]     [.X..]  <-  46
		change_process_data(0x09 0x46);
	//   0467: TEST   WS_REMIND/HI32 [X...]  <-  10
	//   046b: JUMP_NotEqual  0472
	if (!(ucLCD_Misc & ATOM_PANEL_MISC_V13_6BIT_PER_COLOR));
		//   046e: MOVE   fb[00]     [.X..]  <-  4a
		change_process_data(0x09, 0x4a);
	//   0472: SET_FB_BASE  00004d20
	//   0478: SET_DATA_BLOCK  06  (LVDS_Info)
	//   047a: MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
	//   047f: TEST   WS_REMIND/HI32 [X...]  <-  20
	//   0483: JUMP_NotEqual  048a
	if (!(ucLCD_Misc & ATOM_PANEL_MISC_V13_8BIT_PER_COLOR));
		//   0486: OR     fb[00]     [.X..]  <-  04
		change_process_data(0x28, OR(BIT(2)));

	//   048a: SET_DATA_BLOCK  06  (LVDS_Info)
	//   048c: MOVE   WS_REMIND/HI32 [...X]  <-  data[0034] [...X]
	rem = ucPowerSequenceDIGONtoDE_in4Ms;
	//   0491: SET_FB_BASE  00004cc4
	//   0497: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x11, rem);

	//   049b: MOVE   WS_REMIND/HI32 [...X]  <-  data[0035] [...X]
	rem = ucPowerSequenceDEtoVARY_BL_in4Ms;
	//   04a0: SET_FB_BASE  00004cc8
	//   04a6: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x12, rem);

	//   04aa: MOVE   WS_REMIND/HI32 [...X]  <-  data[0039] [...X]
	rem = ucPowerSequenceVARY_BLtoBLON_in4Ms;
	//   04af: SET_FB_BASE  00004ccc
	//   04b5: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x13, rem);


	//   04b9: MOVE   WS_REMIND/HI32 [...X]  <-  data[0037] [...X]
	rem = ucPowerSequenceDEtoDIGON_in4Ms;
	//   04be: SET_FB_BASE  00004cd0
	//   04c4: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x14, rem);

	//   04c8: MOVE   WS_REMIND/HI32 [...X]  <-  data[0036] [...X]
	rem = ucPowerSequenceVARY_BLtoDE_in4Ms;
	//   04cd: SET_FB_BASE  00004cd4
	//   04d3: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x15, rem);

	//   04d7: MOVE   WS_REMIND/HI32 [...X]  <-  data[003a] [...X]
	rem = ucPowerSequenceBLONtoVARY_BL_in4Ms;
	//   04dc: SET_FB_BASE  00004cd8
	//   04e2: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x16, rem);

	//   04e6: MOVE   WS_REMIND/HI32 [...X]  <-  data[0038] [...X]
	rem = ucOffDelay_in4Ms;
	//   04eb: SET_FB_BASE  00004cdc
	//   04f1: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [...X]
	change_process_data(0x17, rem);

	//   04f5: SET_FB_BASE  00004ca8
	//   04fb: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   04fd: MOVE   WS_REMIND/HI32 [X...]  <-  data[0136] [...X]
	//   0502: TEST   WS_REMIND/HI32 [X...]  <-  02
	//   0506: JUMP_Equal  0521
	if (isys_info->ucLvdsMisc & SYS_INFO_LVDSMISC__DL_CH_SWAP) {
		//   0509: MOVE   fb[00]     [.X..]  <-  67
		change_process_data(0x0a, 0x67);	// reg 0xf9
		//   050d: MOVE   fb[01]     [.X..]  <-  89
		change_process_data(0x0b, 0x89);	// reg 0xfa
		//   0511: MOVE   fb[02]     [.X..]  <-  ab
		change_process_data(0x0c, 0xab);	// reg 0xfb
		//   0515: MOVE   fb[03]     [.X..]  <-  01
		change_process_data(0x0d, 0x01);	// reg 0xfc
		//   0519: MOVE   fb[04]     [.X..]  <-  23
		change_process_data(0x0e, 0x23);	// reg 0xfd
		//   051	d: MOVE   fb[05]     [.X..]  <-  45
		change_process_data(0x0f, 0x45);	// reg 0xfe
	}
	//   0521: SET_FB_BASE  00004cc0
	//   0527: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   0529: MOVE   WS_REMIND/HI32 [X...]  <-  data[0136] [...X]
	//   052e: TEST   WS_REMIND/HI32 [X...]  <-  20
	//   0532: JUMP_Equal  053e
	if (isys_info->ucLvdsMisc & SYS_INFO_LVDSMISC__TRAVIS_LVDS_VOL_OVERRIDE_EN) {
		//   0535: MOVE   WS_REMIND/HI32 [X...]  <-  data[0137] [...X]
		//   053a: MOVE   fb[00]     [.X..]  <-  WS_REMIND/HI32 [X...]
		change_process_data(0x10, rem);
	}
	//   053e: SET_FB_BASE  00004d08
	//   0544: TEST   WS_REMIND/HI32 [X...]  <-  10
	//   0548: JUMP_Equal  054f
	//   054b: MOVE   fb[00]     [.X..]  <-  80
#endif
 l_skip_some_shit_to_54f:
	//   054f: MOVE   work[00]   [XXXX]  <-  00004c80
	//   0556: MOVE   param[01]  [...X]  <-  param[00]  [...X]
	//   055a: MOVE   param[01]  [X...]  <-  param[00]  [..X.]
	{
		//   055e: CLEAR  WS_REMIND/HI32 [XXXX]
		//   0561: MOVE   WS_REMIND/HI32 [..XX]  <-  work[00]   [..XX]
		//   0565: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
		//   0568: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
		//   056c: COMP   WS_REMIND/HI32 [XXXX]  <-  ffffffff
		//   0573: JUMP_Equal  05b5
		//   0576: SET_FB_BASE  00004c00
		//   057c: MOVE   fb[01]     [XXXX]  <-  728005f0
		//   0583: MOVE   fb[02]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   0587: MOVE   param[00]  [XXXX]  <-  00004c04
		//   058e: CLEAR  param[01]  [.XX.]
		//   0591: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
		//   0593: COMP   param[01]  [..X.]  <-  00
		//   0597: JUMP_Equal  05aa
		//   059a: DELAY_MicroSec  c8
		//   059c: DELAY_MicroSec  c8
		//   059e: ADD    work[00]   [.X..]  <-  01
		//   05a2: COMP   work[00]   [.X..]  <-  07
		//   05a6: JUMP_Below  055e
		//   05a9: EOT
		//   05aa: ADD    work[00]   [..XX]  <-  0004
		//   05af: CLEAR  work[00]   [XX..]
		//   05b2: JUMP   055e
	}
	run_process();
	//   05b5: EOT

 _something_totally_different:
	//   05b6: MOVE   param[00]  [..XX]  <-  2122
	//   05bb: CALL_TABLE  49  (EnableYUV)
	dataptr = enable_yuv_shit();
	//   05bd: COMP   WS_DATAPTR [..XX]  <-  0000
	//   05c2: JUMP_Equal  0a65
	if (dataptr == 0)
		return;
	//   05c5:
	//                           SWITCH  param[00]  [X...]
	//         07->05e3 00->06c1 01->06d0 0f->06fd 12->06df 14->06ee
	switch (cfg->ucAction) {
	case EXTERNAL_ENCODER_ACTION_V3_ENCODER_INIT:	 	//0x07
		goto l_ENCODER_INIT_OTHER;
	case EXTERNAL_ENCODER_ACTION_V3_DISABLE_OUTPUT:		//0x00
		goto l_DISABLE_OUTPUT_OTHER;
	case EXTERNAL_ENCODER_ACTION_V3_ENABLE_OUTPUT:		//0x01
		goto l_ENABLE_OUTPUT_OTHER;
	case EXTERNAL_ENCODER_ACTION_V3_ENCODER_SETUP:          //0x0f
		goto l_ENCODER_SETUP_OTHER;
	case EXTERNAL_ENCODER_ACTION_V3_DACLOAD_DETECTION:	//0x12
		goto l_DACLOAD_DETECTION_OTHER;
	case EXTERNAL_ENCODER_ACTION_V3_DDC_SETUP:	//0x14
		goto l_DDC_SETUP_OTHER;
	default:
		//   05e2: EOT
		return;
	}
 l_ENCODER_INIT_OTHER:
	//   05e3: CLEAR  WS_REMIND/HI32 [XXXX]
	//   05e6: MOVE   WS_REMIND/HI32 [...X]  <-  param[00]  [...X]
	//   05ea: AND    WS_REMIND/HI32 [...X]  <-  0f
	//   05ee: SHIFT_LEFT  WS_REMIND/HI32 [..XX]  by  01
	//   05f2: SET_DATA_BLOCK  ff  (this table)
	//   05f4: ADD    WS_DATAPTR [..XX]  <-  0a69
	//   05f9: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   05fd: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	//   0602: AND    reg[1880]  [.X..]  <-  fb
	//   0607: CLEAR  WS_REGPTR [..XX]
	//   060a: MOVE   work[01]   [XXXX]  <-  param[00]  [XXXX]
	do {
		//   060e: MOVE   param[01]  [...X]  <-  param[00]  [...X]
		//   0612: MOVE   param[01]  [X...]  <-  param[00]  [..X.]
		//   0616: SET_FB_BASE  00004c00
		//   061c: MOVE   fb[00]     [XXXX]  <-  439850a8
		// dpcd_read_4_bytes(0x850a8); // EFUS_DAC_ADJUSTMENT_CONTROL
		//   0623: CLEAR  param[01]  [.XX.]
		//   0626: MOVE   param[00]  [XXXX]  <-  4c044c00
		//   062d: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
		//   062f: SET_FB_BASE  00004c00
		//   0635: MOVE   WS_QUOT/LOW32 [XXXX]  <-  fb[01]     [XXXX]
		//   0639: COMP   param[01]  [..X.]  <-  00
		//   063d: JUMP_Equal  0656
		//   0640: DELAY_MicroSec  c8
		//   0642: DELAY_MicroSec  c8
		//   0644: ADD    work[00]   [.X..]  <-  01
		//   0648: MOVE   param[00]  [XXXX]  <-  work[01]   [XXXX]
		//   064c: COMP   work[00]   [.X..]  <-  07
		//   0650: JUMP_Below  060e
	} while (--retry);
		//   0653: CLEAR  WS_QUOT/LOW32 [XXXX]
	//   0656: MOVE   param[00]  [XXXX]  <-  work[01]   [XXXX]
	//   065a: CLEAR  work[00]   [XX..]
	//   065d: SET_DATA_BLOCK  ff  (this table)
	//   065f: ADD    WS_DATAPTR [..XX]  <-  0a75
	//   0664: MOVE   work[01]   [..XX]  <-  01c0
	//   0669: MOVE   WS_REMIND/HI32 [XXXX]  <-  00004c80
	do {
		//   0670: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
		//   0673: MOVE   fb[00]     [XXXX]  <-  data[0000] [XXXX]
		//   0678: ADD    WS_DATAPTR [..XX]  <-  0004
		//   067d: ADD    WS_REMIND/HI32 [XXXX]  <-  00000004
		//   0684: SUB    work[01]   [..XX]  <-  0004
		//   0689: COMP   work[01]   [..XX]  <-  0000
		//   068e: JUMP_NotEqual  0670
	} while (work[1]);
	//   0691: COMP   WS_QUOT/LOW32 [...X]  <-  00
	//   0695: JUMP_Equal  06ad
	if (quot != 0) {
		//   0698: COMP   WS_QUOT/LOW32 [...X]  <-  32
		//   069c: JUMP_NotEqual  06a3
		if (quot == 0x32)
			//   069f: MOVE   WS_QUOT/LOW32 [...X]  <-  1f
			quot = 15;
		//   06a3: SET_FB_BASE  00004e30
		//   06a9: MOVE   fb[00]     [...X]  <-  WS_QUOT/LOW32 [...X]
	}
	//   06ad: COMP   WS_QUOT/LOW32 [..X.]  <-  00
	//   06b1: JUMP_Equal  0901
	//   06b4: SET_FB_BASE  00004e38
	//   06ba: MOVE   fb[00]     [..X.]  <-  WS_QUOT/LOW32 [..X.]
	//   06be: JUMP   0901
	goto only_few_jump_here_at_901;
 l_DISABLE_OUTPUT_OTHER:
	//   06c1: SET_DATA_BLOCK  ff  (this table)
	//   06c3: ADD    WS_DATAPTR [..XX]  <-  0f75
	//   06c8: MOVE   WS_QUOT/LOW32 [..XX]  <-  0164
	//   06cd: JUMP   0709
	goto everybody_likes_to_jump_here;
 l_ENABLE_OUTPUT_OTHER:
	//   06d0: SET_DATA_BLOCK  ff  (this table)
	//   06d2: ADD    WS_DATAPTR [..XX]  <-  0f1d
	//   06d7: MOVE   WS_QUOT/LOW32 [..XX]  <-  0058
	//   06dc: JUMP   0709
 l_DACLOAD_DETECTION_OTHER:
	//   06df: SET_DATA_BLOCK  ff  (this table)
	//   06e1: ADD    WS_DATAPTR [..XX]  <-  10d9
	//   06e6: MOVE   WS_QUOT/LOW32 [..XX]  <-  0104
	//   06eb: JUMP   0709
	goto everybody_likes_to_jump_here;
 l_DDC_SETUP_OTHER:
	//   06ee: SET_DATA_BLOCK  ff  (this table)
	//   06f0: ADD    WS_DATAPTR [..XX]  <-  11dd
	//   06f5: MOVE   WS_QUOT/LOW32 [..XX]  <-  0014
	//   06fa: JUMP   0709
	goto everybody_likes_to_jump_here;
 l_ENCODER_SETUP_OTHER:
	//   06fd: SET_DATA_BLOCK  ff  (this table)
	//   06ff: ADD    WS_DATAPTR [..XX]  <-  0c35
	//   0704: MOVE   WS_QUOT/LOW32 [..XX]  <-  02e8
 everybody_likes_to_jump_here:
	//   0709: MOVE   WS_REMIND/HI32 [XXXX]  <-  00004c80
	do {
		//   0710: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
		//   0713: MOVE   fb[00]     [XXXX]  <-  data[0000] [XXXX]
		//   0718: ADD    WS_DATAPTR [..XX]  <-  0004
		//   071d: ADD    WS_REMIND/HI32 [XXXX]  <-  00000004
		//   0724: SUB    WS_QUOT/LOW32 [..XX]  <-  0004
		//   0729: COMP   WS_QUOT/LOW32 [..XX]  <-  0000
		//   072e: JUMP_NotEqual  0710
	} while (quot != 0);
	//   0731: COMP   param[00]  [X...]  <-  0f
	//   0735: JUMP_NotEqual  0901
	//   0738: MOVE   WS_REMIND/HI32 [XXXX]  <-  00640000
	//   073f: MOVE   WS_QUOT/LOW32 [XXXX]  <-  00220000
	//   0746: TEST   param[00]  [.X..]  <-  01
	//   074a: JUMP_Equal  075b
	if (condition) {
		//   074d: MOVE   WS_REMIND/HI32 [XXXX]  <-  00230000
		//   0754: MOVE   WS_QUOT/LOW32 [XXXX]  <-  001b0000
	}
	//   075b: SET_FB_BASE  00004dbc
	//   0761: MOVE   fb[00]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   0765: SET_FB_BASE  00004dc4
	//   076b: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   076f: MOVE   WS_REMIND/HI32 [XXXX]  <-  00000080
	//   0776: TEST   param[00]  [.X..]  <-  01
	//   077a: JUMP_Equal  0784
		//   077d: MOVE   WS_REMIND/HI32 [XXXX]  <-  00000000
	//   0784: SET_FB_BASE  00004e18
	//   078a: OR     WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
	//   078e: OR     WS_REMIND/HI32 [..XX]  <-  0201
	//   0793: MOVE   WS_REMIND/HI32 [XX..]  <-  WS_REMIND/HI32 [..XX]
	//   0797: OR     WS_REMIND/HI32 [..XX]  <-  0800
	//   079c: MOVE   WS_QUOT/LOW32 [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   07a0: OR     WS_QUOT/LOW32 [..XX]  <-  0020
	//   07a5: MOVE   fb[00]     [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   07a9: MOVE   fb[09]     [..XX]  <-  WS_REMIND/HI32 [XX..]
	//   07ad: MOVE   fb[0b]     [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   07b1: COMP   param[01]  [..X.]  <-  01
	//   07b5: JUMP_Equal  07e3
	{
		//   07b8: MOVE   fb[02]     [..XX]  <-  WS_REMIND/HI32 [..XX]
		//   07bc: MOVE   fb[0d]     [..XX]  <-  WS_REMIND/HI32 [XX..]
		//   07c0: MOVE   fb[0f]     [..XX]  <-  WS_QUOT/LOW32 [..XX]
		//   07c4: COMP   param[01]  [..X.]  <-  02
		//   07c8: JUMP_Equal  07e3
		{
			//   07cb: MOVE   fb[04]     [..XX]  <-  WS_REMIND/HI32 [..XX]
			//   07cf: MOVE   fb[06]     [..XX]  <-  WS_REMIND/HI32 [..XX]
			//   07d3: MOVE   fb[11]     [..XX]  <-  WS_REMIND/HI32 [XX..]
			//   07d7: MOVE   fb[13]     [..XX]  <-  WS_QUOT/LOW32 [..XX]
			//   07db: MOVE   fb[15]     [..XX]  <-  WS_REMIND/HI32 [XX..]
			//   07df: MOVE   fb[17]     [..XX]  <-  WS_QUOT/LOW32 [..XX]
		}
	}
	//   07e3: MOVE   WS_QUOT/LOW32 [XXXX]  <-  00b71b00
	//   07ea: DIV    WS_QUOT/LOW32 [XXXX]  <-  work[00]   [XXXX]
	//   07ee: DIV    WS_QUOT/LOW32 [XXXX]  <-  00000064
	//   07f5: MOVE   work[01]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   07f9: MUL    work[01]   [XXXX]  <-  work[00]   [XXXX]
	//   07fd: MUL    WS_QUOT/LOW32 [XXXX]  <-  00000001
	//   0804: MOVE   work[00]   [XX..]  <-  work[01]   [..XX]
	//   0808: MOVE   work[01]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   080c: MUL    WS_QUOT/LOW32 [XXXX]  <-  000028f5
	//   0813: MOVE   WS_REMIND/HI32 [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   0817: MOVE   WS_QUOT/LOW32 [XXXX]  <-  work[01]   [XXXX]
	//   081b: MOVE   work[01]   [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   081f: MUL    WS_QUOT/LOW32 [XXXX]  <-  0000004c
	//   0826: DIV    WS_QUOT/LOW32 [XXXX]  <-  00000064
	//   082d: ADD    WS_QUOT/LOW32 [XXXX]  <-  work[01]   [XXXX]
	//   0831: ADD    WS_QUOT/LOW32 [XXXX]  <-  0000000c
	//   0838: DIV    WS_QUOT/LOW32 [XXXX]  <-  00000019
	//   083f: MOVE   work[01]   [XXXX]  <-  00004001
	//   0846: SET_FB_BASE  00004e9c
	//   084c: MOVE   fb[00]     [XXXX]  <-  work[01]   [XXXX]
	//   0850: SET_FB_BASE  00004ea4
	//   0856: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   085a: SET_FB_BASE  00004e7c
	//   0860: SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  14
	//   0864: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  10
	//   0868: ADD    WS_QUOT/LOW32 [XXXX]  <-  00000000
	//   086f: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   0873: CLEAR  work[01]   [XXXX]
	//   0876: MOVE   work[01]   [..XX]  <-  work[00]   [XX..]
	//   087a: SET_FB_BASE  00004eb4
	//   0880: MOVE   fb[00]     [XXXX]  <-  work[01]   [XXXX]
	//   0884: MUL    work[00]   [XX..]  <-  work[00]   [..XX]
	//   0888: DIV    WS_QUOT/LOW32 [XXXX]  <-  000009c4
	//   088f: MOVE   work[01]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   0893: ADD    work[01]   [XXXX]  <-  00000001
	//   089a: COMP   WS_REMIND/HI32 [XXXX]  <-  00000000
	//   08a1: JUMP_NotEqual  08b2
	if (condition) {
		//   08a4: SUB    work[01]   [XXXX]  <-  00000001
		//   08ab: SHIFT_LEFT  work[01]   [XXXX]  by  10
		//   08af: JUMP   08e6
	} else {
		//   08b2: SHIFT_LEFT  work[01]   [XXXX]  by  10
		//   08b6: MOVE   WS_QUOT/LOW32 [XXXX]  <-  000009c4
		//   08bd: SUB    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   08c1: MUL    WS_QUOT/LOW32 [XXXX]  <-  0000000a
		//   08c8: DIV    WS_QUOT/LOW32 [XXXX]  <-  000009c4
		//   08cf: SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  1c
		//   08d3: ADD    work[01]   [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		//   08d7: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  10
		//   08db: DIV    WS_REMIND/HI32 [XXXX]  <-  000009c4
		//   08e2: MOVE   work[01]   [..XX]  <-  WS_QUOT/LOW32 [..XX]
	}
	//   08e6: SET_FB_BASE  00004f18
	//   08ec: MOVE   fb[00]     [XXXX]  <-  work[01]   [XXXX]
	//   08f0: CLEAR  work[01]   [XXXX]
	//   08f3: MOVE   work[01]   [...X]  <-  param[01]  [..X.]
	//   08f7: SET_FB_BASE  00004f60
	//   08fd: ADD    fb[00]     [XXXX]  <-  work[01]   [XXXX]
 only_few_jump_here_at_901:
	//   0901: MOVE   work[01]   [XX..]  <-  param[00]  [XX..]
	//   0905: MOVE   work[00]   [XXXX]  <-  00004c80
	//   090c: MOVE   param[01]  [...X]  <-  param[00]  [...X]
	//   0910: MOVE   param[01]  [X...]  <-  param[00]  [..X.]
	do {
		do {
			do {
				//   0914: SET_FB_BASE  work[00]   [XXXX]
				//   0917: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
				rem = d[0];
				//   091b: MOVE   WS_QUOT/LOW32 [XXXX]  <-  fb[01]     [XXXX]
				quot = d[1];
				//   091f: COMP   WS_REMIND/HI32 [XXXX]  <-  ffffffff
				//   0926: JUMP_Equal  0a43
				if (rem == 0xffffffff)
					break;
				//   0929: COMP   WS_REMIND/HI32 [X...]  <-  00
				//   092d: JUMP_Equal  093a
				//   0930: COMP   WS_REMIND/HI32 [X...]  <-  01
				//   0934: JUMP_Equal  093a
				//   0937: JUMP   09c2
				if (((rem >> 24) == 0) || ((rem >> 24) == 1))
					goto break_hard;
				do {
					//   093a: SET_FB_BASE  work[00]   [XXXX]
					//   093d: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
					//   0941: MASK   WS_REMIND/HI32 [XXXX]  &  000fffff  |  43900000
					//   094c: SET_FB_BASE  00004c00
					//dpcd_read32()
					//   0952: MOVE   fb[00]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
					//   0956: CLEAR  param[01]  [.XX.]
					//   0959: MOVE   param[00]  [XXXX]  <-  4c044c00
					//   0960: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
					//   0962: SET_FB_BASE  00004c00
					//   0968: MOVE   WS_QUOT/LOW32 [XXXX]  <-  fb[01]     [XXXX]
					//   096c: COMP   param[01]  [..X.]  <-  00
					//   0970: JUMP_Equal  0983
					if (all_is_good)
						break;
					//   0973: DELAY_MicroSec  c8
					//   0975: DELAY_MicroSec  c8
					//   0977: ADD    work[01]   [...X]  <-  01
					//   097b: COMP   work[01]   [...X]  <-  07
					//   097f: JUMP_Below  093a
				} while (++retry < 7);
				//   0982: EOT
				//   0983: SET_FB_BASE  work[00]   [XXXX]
				//   0986: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
				//   098a: COMP   WS_REMIND/HI32 [X...]  <-  00
				//   098e: JUMP_Equal  09ab
				if ((rem >> 24) == 0)
					break;
				//   0991: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[01]     [XXXX]
				//   0995: ADD    WS_REMIND/HI32 [XXXX]  <-  00004c80
				//   099c: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
				//   099f: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
				//   09a3: ADD    work[00]   [..XX]  <-  0008
				work[0] += 8;
				//   09a8: JUMP   0914
			} while (1);
			//   09ab: OR     WS_REMIND/HI32 [XXXX]  <-  83800000
			//   09b2: AND    WS_QUOT/LOW32 [XXXX]  <-  fb[01]     [XXXX]
			//   09b6: OR     WS_QUOT/LOW32 [XXXX]  <-  fb[02]     [XXXX]
			//   09ba: ADD    work[00]   [..XX]  <-  0004
			work[0] += 4;
			//   09bf: JUMP   0a09
				break;
		 break_hard:
			//   09c2: COMP   WS_REMIND/HI32 [XX..]  <-  fffe
			//   09c7: JUMP_NotEqual  0a09
			if (rem >> 16 != 0xfffe)
				break;
			//   09ca: COMP   WS_REMIND/HI32 [..XX]  <-  0064
			//   09cf: JUMP_Below  09f2
			if (rem & 0xffff >= 0x64) {
				//   09d2: DIV    WS_REMIND/HI32 [..XX]  <-  0064
				//   09d7: MOVE   WS_REMIND/HI32 [..XX]  <-  WS_QUOT/LOW32 [..XX]
				do {
					//   09db: DELAY_MilliSec  01
					//   09dd: SUB    WS_REMIND/HI32 [..XX]  <-  0001
					//   09e2: COMP   WS_REMIND/HI32 [..XX]  <-  0000
					//   09e7: JUMP_NotEqual  09db
				} while (--rem)
				//   09ea: ADD    work[00]   [..XX]  <-  0004
				work[0] += 4;
				//   09ef: JUMP   0914
				continue;
			}
			do {
				//   09f2: DELAY_MicroSec  0a
				//   09f4: SUB    WS_REMIND/HI32 [..XX]  <-  0001
				//   09f9: COMP   WS_REMIND/HI32 [..XX]  <-  0000
				//   09fe: JUMP_NotEqual  09f2
			} while (--rem)
			//   0a01: ADD    work[00]   [..XX]  <-  0004
			work[0] += 4;
			//   0a06: JUMP   0914
		} while (1);
		//   0a09: SET_FB_BASE  00004c00
		//   0a0f: MOVE   fb[00]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
		//   0a13: MOVE   fb[01]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		do {
			//   0a17: MOVE   param[00]  [XXXX]  <-  00004c00
			//   0a1e: CLEAR  param[01]  [.XX.]
			//   0a21: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
			//   0a23: COMP   param[01]  [..X.]  <-  00
			//   0a27: JUMP_Equal  0a38
			if (all_is_good)
				break;
			//   0a2a: DELAY_MicroSec  c8
			//   0a2c: ADD    work[00]   [.X..]  <-  01
			retry++;
			//   0a30: COMP   work[00]   [.X..]  <-  07
			//   0a34: JUMP_Below  0a17
		} while(retry < 7);
		//   0a37: EOT
		//   0a38: ADD    work[00]   [..XX]  <-  0008
		work[0] += 8;
		//   0a3d: CLEAR  work[00]   [XX..]
		//   0a40: JUMP   0914
	} while (1);
	//   0a43: COMP   work[01]   [X...]  <-  12
	//   0a47: JUMP_NotEqual  0a65
	//// retrun; if not_equal
	//   0a4a: SET_FB_BASE  00004d3c
	//   0a50: MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
	//   0a54: AND    reg[05c9]  [...X]  <-  fc
	//   0a59: COMP   WS_REMIND/HI32 [...X]  <-  00
	//   0a5d: JUMP_Equal  0a65
	//   0a60: OR     reg[05c9]  [...X]  <-  02
	//   0a65: EOT
}
//   0a66: 7a6009
/*          0 1 2 3 4 5 6 7 8 9 a b c d e f 0 1 2 3 4 5 6 7 8 9 a b c d e f */
/* 0a69: aux_channel_reg_offset:
 *         000014002800400054006800
 * 0a75: size=0x1c0              { 088088837f0f0000008088831000000010058050
 */
/*  20*//* e400000011058050000000008205808301000000a1058083f000000018808883
//  40	 * 1001000080808883010000007080888301000000308088830300000020808883
//  60	 * 01000000081088830000001004108883100023000810888300001b1004118883
//  80	 * 000000000004888301000000040088830006000008000800f4ffffff08200000
//  a0	 * 040188830006000008010800f4ffffff08200000040288830006000008020800
//  c0	 * f4ffffff08200000040388830006000008030800f4ffffff0820000024308883
//  e0	 * 0304060020308883856f0729383088830000002040300800feffefff01000000
// 100	 * 003088830100000000508883000000005050888301010101a4500800feffffff
// 120	 * 0100000014050000feffffff0000000020058083ee0200001c058083d0070000
// 140	 * 1805808300000000130580500000000014050000f9ffffff0600000038708883
// 160	 * 0001000030700800fff0ffff0004000030700800fffffffd0000000208700800
// 180	 * bfffffff4000000014050000feffffff0100000030700800feffffff00000000
// 1a0	 * f401feff1470888302001100a8500800fffffeff00000000885088831f000000
// 1c0	 * 74508883021b0000ffffffff }
 [0x0c35]: size = 0x02e8         { 088088837f0f0000008088831000000018800800
// 1e0	 * cfffffff10000000243088830304060038308883000000200030888300000000
// 200	 * 000680500200000004000800dfffffff0000000004000800fff7ffff00000000
// 220	 * 04010800dfffffff0000000004010800fff7ffff0000000004020800dfffffff
// 240	 * 0000000004020800fff7ffff0000000004030800dfffffff0000000004030800
// 260	 * fff7ffff0000000004000800feffffff0000000004010800feffffff00000000
// 280	 * 04020800feffffff0000000004030800feffffff0000000008000800ffffffff
// 2a0	 * 0020000008010800ffffffff0020000008020800ffffffff0020000008030800
// 2c0	 * ffffffff0020000018800800fffcffff00010000041188830000000004100800
// 2e0	 * ffff00fc000000000480888300000000f401feff18800800fff7ffff00080000
// 300	 * 0100feff04108883000000000810888300000000041188830b0000000a00feff
// 320	 * 18800800fffcffff040200000a00feff08000800ffdfffff0000000008010800
// 340	 * ffdfffff0000000008020800ffdfffff0000000008030800ffdfffff00000000
// 360	 * 0400888300060000040188830006000004028883000600000403888300060000
// 380	 * 0300feff04008883000600000400888300060000040188830006000004018883
// 3a0	 * 0006000004028883000600000402888300060000040388830006000004038883
// 3c0	 * 0006000058308883000000003430888300000800543088830000000054308883
// 3e0	 * 010000000430888300400000183088830000000014308883100000001c308883
// 400	 * 000000001400feff38300800ffffffef000000100100feff38300800ffffffef
// 420	 * 000000000100feff38300800ffffffdf000000002c01feff0030888301000000
// 440	 * 24300800fdffffff000000000500feff24300800feffffff000000004000feff
// 460	 * 583088830000000034300800fffffcff0000010054300800fdffffff02000000
// 480	 * 0500feff24300800fffff9fc0000000154300800feffffff0000000018800800
// 4a0	 * cfffffff300000000101808380000000ffffffff }
 [0xf1d] : size = 0x58                           {
           08808883,7f0f0000,00808883,10000000,50500800,feffffff,00000000
           0a00feff,a4500800,feffffff,00000000,6400feff,50508883,00000000
           6400feff,00508883,01000000,08808883,530f0000,00808883,00000000
           ffffffff }
 [0xf75] : size = 0x164          { 088088837f0f000000808883130000001880000
// 520	 * ffffffff0001000000508883000000005050888301010101a4500800feffffff
// 540	 * 0100000018800800dfffffff0000000024300800fffffffc0304060038308883
// 560	 * 00000020000680830200000004000800dfffffff0000000004000800fff7ffff
// 580	 * 0000000004010800dfffffff0000000004010800fff7ffff0000000004020800
// 5a0	 * dfffffff0000000004020800fff7ffff0000000004030800dfffffff00000000
// 5c0	 * 04030800fff7ffff0000000004000800feffffff0000000004010800feffffff
// 5e0	 * 0000000004020800feffffff0000000004030800feffffff0000000008000800
// 600	 * ffffffff0020000008010800ffffffff0020000008020800ffffffff00200000
// 620	 * 08030800ffffffff0020000018800800fffdffff000000000411888300000000
// 640	 * 041088830000000008808883530f0000008088830000000018800800fff7ffff
// 660	 * 000000000480888301000000ffffffff }
 [0x10d9]: size = 0x0104                 { 00500801c400000028500801cc000000
// 680	 * 40500801d400000058500801dc0000005c500801e400000050500801ec000000
// 6a0	 * 04800801f4000000a4500801fc00000004808883000000000100feff00508883
// 6c0	 * 0100000028500800fcffffff0000000040508883000000005850888301000000
// 6e0	 * 5c5088830000070050500800feffffff000000000a00feffa4500800feffffff
// 700	 * 00000000f401feff505088830000000040508883e60100001400feff5c508883
// 720	 * 000107000a00feff60500801bc00000000508883000000002850888300000000
// 740	 * 405088830000000058508883000000005c508883000000005050888300000000
// 760	 * 0480888300000000a450888300000000ffffffff }
 [0x11dd]: size = 0x0014                         { 30700800feffffff00000000
// 780	 * f401feffffffffff }
	 */
	/*
	 * [0x11f1]: travis_other_encoder_parameters[]
 0	 * 00053d00
 1	 * 001f0100
 2	 * 00ba0000
 3	 * 00bb0800
 4	 * 00b14b00
 5	 * 01736900
 6	 * 019f2600
 7	 * 00193300
 8	 * 00893900
 9	 * 019e0500
 a	 * 01cb8000
 b	 * 00164400
 c	 * 00f12000
 d	 * 00dc0000
 e	 * 00dd0000
 f	 * ffffffff
	 */
	/*
	 * [0x11f1 + 0x40] travis_other_encoder_parameters_v2[]
	 *                 00053d00
	 * 001f0300
	 * 00ba0000
	 * 00bb0800
	 * 00b14b00
	 * 01736900
	 * 019f2400
	 * 00193300
	 * 00893900
	 * 00f84200
	 * 00f90100
	 * 00fa2300
	 * 00fb4500
	 * 00fc6700
	 * 00fd8900
	 * 00feab00
	 * 001d2500
	 * 01c30700
	 * 01c25a00
	 * 01c40000
	 * 01c00700
	 * 01c15a00
	 * 01b10000
	 * 01bf7d00
	 * 01b56300
	 * 01cb8000
	 * 01b30000
	 * 01b20000
	 * 009f1000
	 * 01831400
	 * 00a7c200
	 * 01711200
	 * 01825d00
	 * 01892400
	 * 01be0100
	 * 008a5300
	 * 000a0100
	 * 01d41000
	 * 00f34000
	 * 00f40000
	 * 01b40000
	 * 00dc0000
	 * 00dd0000
	 * 01912000
	 * 00d10600
	 * 00d60100
	 * ffffffff
	 */

static const uint32_t travis_data[] = {0, 1, 2, 3, 4, 0xffffffff};
	/*
	 * [0x12ed]: travis_encoder_parameters[]
 0	 * 00053d00
 1	 * 001f0300
 2	 * 00ba0000
 3	 * 00bb0800
 4	 * 00b14b00
 5	 * 01736900
 6	 * 019f2400
 7	 * 00193300
 8	 * 00893900
 9	 * 00f84200
 a	 * 00f90100
 b	 * 00fa2300
 c	 * 00fb4500
 d	 * 00fc6700
 e	 * 00fd8900
 f	 * 00feab00
10	 * 001d2500
11	 * 01c30700
12	 * 01c25a00
13	 * 01c40000
14	 * 01c00700
15	 * 01c15a00
16	 * 01b10000
17	 * 01bf7d00
18	 * 01b56300
19	 * 01cb8000
1a	 * 01b30000
1b	 * 01b20000
1c	 * 009f1000
1d	 * 01831400
1e	 * 00a7c200
1f	 * 01711200
20	 * 01825d00
21	 * 01892800
22	 * 01be0100
23	 * 008a5300
24	 * 000a0100
25	 * 01d41000
26	 * 00f34000
27	 * 00f40000
28	 * 01b40000
29	 * 00dc0000
2a	 * 00dd0000
2b	 * 01912000
2c	 * 00d10600
2d	 * 00d60100
2e	 * 01d20800
2f	 * 01d38000
	 * ffffffff
	 */
	/*
	 * [0x13b1] : used for ACTION_DISABLE_OUTPUT:
	 *                 1e2100001e22000320210026202200292121002c2122002f
	 *                   CTB_DS  2400 bytes
*/
