#include "radeon_init_native.h"

// command_table  00000000  #4a  (DIG1EncoderControl):
//
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
// command_table  0000e90a  #4b  (DIG2EncoderControl):
//
//   Size         035a
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        01 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//

static const uint8_t object_header[] = {
 0x00, 0x00, 0x00, 0x00, 0x0b, 0x00, 0x5e, 0x00, 0x00, 0x00, 0x64, 0x01, 0x00, 0x00, 0x12, 0x00,
 0x25, 0x02, 0x06, 0x01, 0x00, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x0e, 0x31, 0x00, 0x11, 0x21, 0x21,
 0x23, 0x22, 0x01, 0x00, 0x0c, 0x00, 0x05, 0x31, 0x00, 0x11, 0x21, 0x22, 0x22, 0x21, 0x08, 0x00,
 0x0c, 0x00, 0x0c, 0x31, 0x00, 0x11, 0x1e, 0x21, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00,
 0x00, 0x11, 0x1e, 0x22, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x11, 0x20, 0x21,
 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x11, 0x20, 0x22, 0x00, 0x00, 0x06, 0x00,
 0x00, 0x00, 0x0e, 0x31, 0x92, 0x00, 0x98, 0x00, 0x00, 0x00, 0x05, 0x31, 0xb5, 0x00, 0xbb, 0x00,
 0x00, 0x00, 0x0c, 0x31, 0xd8, 0x00, 0xde, 0x00, 0x00, 0x00, 0x00, 0x00, 0xfb, 0x00, 0x01, 0x01,
 0x00, 0x00, 0x00, 0x00, 0x1e, 0x01, 0x24, 0x01, 0x00, 0x00, 0x00, 0x00, 0x41, 0x01, 0x47, 0x01,
 0x00, 0x00, 0x01, 0x23, 0x22, 0x00, 0x00, 0x00, 0x04, 0x14, 0x01, 0x00, 0x10, 0x01, 0x00, 0x00,
 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x90, 0x00,
 0x02, 0x04, 0x01, 0x00, 0xff, 0x01, 0x22, 0x21, 0x00, 0x00, 0x00, 0x04, 0x14, 0x01, 0x00, 0x00,
 0x01, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
 0x04, 0x91, 0x00, 0x02, 0x04, 0x02, 0x00, 0xff, 0x01, 0x1e, 0x21, 0x00, 0x00, 0x00, 0x04, 0x14,
 0x01, 0x00, 0x10, 0x02, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x01, 0x04, 0x92, 0x00, 0x02, 0x04, 0x03, 0x00, 0xff, 0x01, 0x23, 0x22, 0x00, 0x00,
 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0xff, 0x01, 0x23,
 0x22, 0x00, 0x00, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00,
 0xff, 0x01, 0x23, 0x22, 0x00, 0x00, 0x00, 0x04, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x04, 0x00, 0x00, 0x02,
 0x04, 0x00, 0x00, 0xff, 0x09, 0x00, 0x00, 0x00, 0x21, 0x21, 0xb0, 0x01, 0xb6, 0x01, 0x00, 0x00,
 0x23, 0x21, 0xbb, 0x01, 0xc1, 0x01, 0x00, 0x00, 0x21, 0x22, 0xca, 0x01, 0xd0, 0x01, 0x00, 0x00,
 0x23, 0x22, 0xd5, 0x01, 0xe1, 0x01, 0x00, 0x00, 0x1e, 0x21, 0xea, 0x01, 0xf0, 0x01, 0x00, 0x00,
 0x22, 0x21, 0xf5, 0x01, 0xfb, 0x01, 0x00, 0x00, 0x1e, 0x22, 0x04, 0x02, 0x0a, 0x02, 0x00, 0x00,
 0x20, 0x21, 0x0f, 0x02, 0x15, 0x02, 0x00, 0x00, 0x20, 0x22, 0x1a, 0x02, 0x20, 0x02, 0x00, 0x00,
 0x01, 0x00, 0x11, 0x01, 0x23, 0x22, 0x14, 0x04, 0x03, 0x00, 0xff, 0x01, 0x21, 0x21, 0x01, 0x15,
 0x31, 0x01, 0x04, 0x00, 0x00, 0x02, 0x04, 0x00, 0x00, 0xff, 0x01, 0x00, 0x11, 0x01, 0x22, 0x21,
 0x14, 0x04, 0x03, 0x00, 0xff, 0x01, 0x21, 0x21, 0x01, 0x0e, 0x31, 0x15, 0x34, 0x15, 0x35, 0x15,
 0x36, 0x01, 0x04, 0x90, 0x00, 0x02, 0x04, 0x01, 0x00, 0xff, 0x01, 0x00, 0x11, 0x01, 0x0c, 0x31,
 0x14, 0x04, 0x03, 0x00, 0xff, 0x01, 0x21, 0x22, 0x01, 0x05, 0x31, 0x01, 0x04, 0x91, 0x00, 0x02,
 0x04, 0x02, 0x00, 0xff, 0x01, 0x00, 0x11, 0x01, 0x23, 0x22, 0x14, 0x04, 0x03, 0x00, 0xff, 0x01,
 0x00, 0x11, 0x01, 0x23, 0x22, 0x14, 0x04, 0x03, 0x00, 0xff, 0x01, 0x00, 0x11, 0x01, 0x23, 0x22,
 0x14, 0x04, 0x03, 0x00, 0xff, 0x02, 0x00, 0x00, 0x00, 0x03, 0x71, 0x00, 0x00, 0x39, 0x02, 0x00,
 0x00, 0x04, 0x71, 0x4e, 0x02, 0x54, 0x02, 0x00, 0x00, 0x10, 0x0a, 0x01, 0x02, 0x03, 0x04, 0x05,
 0x06, 0x00, 0x00, 0x11, 0x0a, 0x90, 0x91, 0x92, 0x93, 0x94, 0x95, 0x00, 0x00, 0xff, 0x00, 0x00,
 0x00, 0x00, 0x00, 0x00, 0x09, 0x06, 0x00, 0x01, 0x00, 0x00, 0xff
};

uint16_t read16(const uint8_t *raw)
{
	return (raw[1] << 8) | raw[0];
}

void radeon_dp_encoder_control(void)
{
	uint32_t work, rem;
	uint16_t quot;

	static const uint8_t dat[] = {0x01, 0x1e, 0x00, 0x00, 0x02, 0x5a, 0x00, 0x00,
		0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x5a,
		0x00, 0x00, 0x06, 0x1e, 0x00, 0x00, 0x07, 0x7d, 0x00, 0x00,
		0x08, 0x20, 0x00, 0x00, 0x09, 0x01, 0x00, 0x00, 0x0a, 0x0c,
		0x00, 0x00, 0x0b, 0x00, 0x00, 0x00, 0x0c, 0x06, 0x00, 0x00,
		0x0e, 0x38, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x0d, 0x01,
		0x00, 0x00, 0xff, 0xff, 0xff, 0xff};

	const uint8_t *dptr;
	//   0006: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   000b: 0324004200        MOVE   work[00]   [...X]  <-  data[0042] [...X]
	work = 0; /* it is 0 on 1035dx */
	//   0010: 3e250002          COMP   work[00]   [...X]  <-  02
	//   0014: 451603            JUMP_Below  0316
	if (work < 2)
		return;
	//   0017: 020d0000ff        MOVE   param[00]  [..XX]  <-  ff00
	/* TODO */
	//   001c: 030d401431        MOVE   WS_QUOT/LOW32 [..XX]  <-  3114
	quot = 0x3114;
	//   0021: 6616              SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	//   0023: 2d0c420600        ADD    WS_DATAPTR [..XX]  <-  data[0006] [..XX]
	dptr = object_header + 6;
	//   0028: 0324410000        MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	for (rem = dptr[0]; ;rem --)
	{
		//   002d: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
		//   0031: 44ac00            JUMP_Equal  00ac
		if (rem == 0)
			return;
		//   0034: 3e0c400400        COMP   WS_QUOT/LOW32 [..XX]  <-  data[0004] [..XX]
		//   0039: 444800            JUMP_Equal  0048
		if (quot == read16(dptr + 4))
			break;
		//   003c: 2d0d420800        ADD    WS_DATAPTR [..XX]  <-  0008
		dptr += 8;
		//   0041: 33254101          SUB    WS_REMIND/HI32 [...X]  <-  01
		//   0045: 432d00            JUMP   002d
	}
	//   0048: 030c400600        MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0006] [..XX]
	quot = read16(dptr + 6);
	//   004d: 030c410800        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0008] [..XX]
	rem = read16(dptr + 8);
	//   0052: 6616              SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	//   0054: 2d0a4042          ADD    WS_QUOT/LOW32 [..XX]  <-  WS_DATAPTR [..XX]
	//   0058: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   005d: 449b00            JUMP_Equal  009b
	//   0060: 2d0a4241          ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   0064: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0067: 0324410000        MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	//   006c: 03a4410100        MOVE   WS_REMIND/HI32 [.X..]  <-  data[0001] [...X]
	//   0071: 3e2541ff          COMP   WS_REMIND/HI32 [...X]  <-  ff
	//   0075: 449b00            JUMP_Equal  009b
	//   0078: 3e254101          COMP   WS_REMIND/HI32 [...X]  <-  01
	//   007c: 498400            JUMP_NotEqual  0084
	//   007f: 0224000200        MOVE   param[00]  [...X]  <-  data[0002] [...X]
	//   0084: 3e254102          COMP   WS_REMIND/HI32 [...X]  <-  02
	//   0088: 499400            JUMP_NotEqual  0094
	//   008b: 0264000200        MOVE   param[00]  [..X.]  <-  data[0002] [...X]
	//   0090: 32650001          SUB    param[00]  [..X.]  <-  01
	//   0094: 2d1a4241          ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [XX..]
	//   0098: 436700            JUMP   0067
	//   009b: 030a4240          MOVE   WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   009f: 030c410100        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0001] [..XX]
	//   00a4: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   00a9: 49b000            JUMP_NotEqual  00b0
	//   00ac: 560842            CLEAR  WS_DATAPTR [..XX]
	//   00af: 5b                EOT
	//   00b0: 4222006302ba005a5a
	//                           SWITCH  work[00]   [...X]
	//         02->00ba
	//   00b9: 5b                EOT
	//   00ba: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   00bc: 2d0d421a03        ADD    WS_DATAPTR [..XX]  <-  031a
	//   00c1: 030541804c0000    MOVE   WS_REMIND/HI32 [XXXX]  <-  00004c80
	//   00c8: 3b0241            SET_FB_BASE  WS_REMIND/HI32 [XXXX]
	//   00cb: 0404000000        MOVE   fb[00]     [XXXX]  <-  data[0000] [XXXX]
	//   00d0: 2d0d420400        ADD    WS_DATAPTR [..XX]  <-  0004
	//   00d5: 2d054104000000    ADD    WS_REMIND/HI32 [XXXX]  <-  00000004
	//   00dc: 3f0500ffffffff    COMP   fb[00]     [XXXX]  <-  ffffffff
	//   00e3: 49c800            JUMP_NotEqual  00c8
	//   00e6: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   00e8: 0324413400        MOVE   WS_REMIND/HI32 [...X]  <-  data[0034] [...X]
	//   00ed: 15254102          SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  02
	//   00f1: 3b05804c0000      SET_FB_BASE  00004c80
	//   00f7: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   00fb: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   00fe: 0324413500        MOVE   WS_REMIND/HI32 [...X]  <-  data[0035] [...X]
	//   0103: 3b05844c0000      SET_FB_BASE  00004c84
	//   0109: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   010d: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0110: 0324413900        MOVE   WS_REMIND/HI32 [...X]  <-  data[0039] [...X]
	//   0115: 150d4102          SHIFT_LEFT  WS_REMIND/HI32 [..XX]  by  02
	//   0119: 3b05884c0000      SET_FB_BASE  00004c88
	//   011f: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0123: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0126: 0324413a00        MOVE   WS_REMIND/HI32 [...X]  <-  data[003a] [...X]
	//   012b: 150d4102          SHIFT_LEFT  WS_REMIND/HI32 [..XX]  by  02
	//   012f: 3b058c4c0000      SET_FB_BASE  00004c8c
	//   0135: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0139: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   013c: 0324413600        MOVE   WS_REMIND/HI32 [...X]  <-  data[0036] [...X]
	//   0141: 3b05904c0000      SET_FB_BASE  00004c90
	//   0147: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   014b: 0324413700        MOVE   WS_REMIND/HI32 [...X]  <-  data[0037] [...X]
	//   0150: 15254102          SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  02
	//   0154: 3b05944c0000      SET_FB_BASE  00004c94
	//   015a: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   015e: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0161: 0324413800        MOVE   WS_REMIND/HI32 [...X]  <-  data[0038] [...X]
	//   0166: 3b05984c0000      SET_FB_BASE  00004c98
	//   016c: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0170: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0173: 0f254108          OR     WS_REMIND/HI32 [...X]  <-  08
	//   0177: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   0179: 03e4412800        MOVE   WS_REMIND/HI32 [X...]  <-  data[0028] [...X]
	//   017e: 4ce54101          TEST   WS_REMIND/HI32 [X...]  <-  01
	//   0182: 448901            JUMP_Equal  0189
	//   0185: 0f254180          OR     WS_REMIND/HI32 [...X]  <-  80
	//   0189: 4ce54102          TEST   WS_REMIND/HI32 [X...]  <-  02
	//   018d: 499401            JUMP_NotEqual  0194
	//   0190: 0f254104          OR     WS_REMIND/HI32 [...X]  <-  04
	//   0194: 4ce54120          TEST   WS_REMIND/HI32 [X...]  <-  20
	//   0198: 449f01            JUMP_Equal  019f
	//   019b: 0f254101          OR     WS_REMIND/HI32 [...X]  <-  01
	//   019f: 3b05a44c0000      SET_FB_BASE  00004ca4
	//   01a5: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   01a9: 02050106000000    MOVE   param[01]  [XXXX]  <-  00000006
	//   01b0: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   01b3: 661a              SET_DATA_BLOCK  1a  (ASIC_InternalSS_Info/ASIC_MVDDC_Info)
	//   01b5: 030c410000        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
	//   01ba: 2d0a4142          ADD    WS_REMIND/HI32 [..XX]  <-  WS_DATAPTR [..XX]
	//   01be: 2d0d420400        ADD    WS_DATAPTR [..XX]  <-  0004
	//   01c3: 3d24010800        COMP   param[01]  [...X]  <-  data[0008] [...X]
	//   01c8: 44de01            JUMP_Equal  01de
	//   01cb: 2d0d420c00        ADD    WS_DATAPTR [..XX]  <-  000c
	//   01d0: 3e0a4241          COMP   WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   01d4: 49c301            JUMP_NotEqual  01c3
	//   01d7: 03254100          MOVE   WS_REMIND/HI32 [...X]  <-  00
	//   01db: 43a602            JUMP   02a6
	//   01de: 038c410400        MOVE   WS_REMIND/HI32 [XX..]  <-  data[0004] [..XX]
	//   01e3: 3e8d410000        COMP   WS_REMIND/HI32 [XX..]  <-  0000
	//   01e8: 44d701            JUMP_Equal  01d7
	//   01eb: 03254100          MOVE   WS_REMIND/HI32 [...X]  <-  00
	//   01ef: 3e8d411700        COMP   WS_REMIND/HI32 [XX..]  <-  0017
	//   01f4: 455b02            JUMP_Below  025b
	//   01f7: 03254101          MOVE   WS_REMIND/HI32 [...X]  <-  01
	//   01fb: 3e8d414700        COMP   WS_REMIND/HI32 [XX..]  <-  0047
	//   0200: 455b02            JUMP_Below  025b
	//   0203: 03254102          MOVE   WS_REMIND/HI32 [...X]  <-  02
	//   0207: 3e8d417c00        COMP   WS_REMIND/HI32 [XX..]  <-  007c
	//   020c: 455b02            JUMP_Below  025b
	//   020f: 03254103          MOVE   WS_REMIND/HI32 [...X]  <-  03
	//   0213: 3e8d41ac00        COMP   WS_REMIND/HI32 [XX..]  <-  00ac
	//   0218: 455b02            JUMP_Below  025b
	//   021b: 03254104          MOVE   WS_REMIND/HI32 [...X]  <-  04
	//   021f: 3e8d41d300        COMP   WS_REMIND/HI32 [XX..]  <-  00d3
	//   0224: 455b02            JUMP_Below  025b
	//   0227: 03254105          MOVE   WS_REMIND/HI32 [...X]  <-  05
	//   022b: 3e8d411001        COMP   WS_REMIND/HI32 [XX..]  <-  0110
	//   0230: 455b02            JUMP_Below  025b
	//   0233: 03254106          MOVE   WS_REMIND/HI32 [...X]  <-  06
	//   0237: 3e8d414b01        COMP   WS_REMIND/HI32 [XX..]  <-  014b
	//   023c: 455b02            JUMP_Below  025b
	//   023f: 03254107          MOVE   WS_REMIND/HI32 [...X]  <-  07
	//   0243: 3e8d417101        COMP   WS_REMIND/HI32 [XX..]  <-  0171
	//   0248: 455b02            JUMP_Below  025b
	//   024b: 03254108          MOVE   WS_REMIND/HI32 [...X]  <-  08
	//   024f: 3e8d41ac01        COMP   WS_REMIND/HI32 [XX..]  <-  01ac
	//   0254: 455b02            JUMP_Below  025b
	//   0257: 03254109          MOVE   WS_REMIND/HI32 [...X]  <-  09
	//   025b: 3b05a04c0000      SET_FB_BASE  00004ca0
	//   0261: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0265: 038c410600        MOVE   WS_REMIND/HI32 [XX..]  <-  data[0006] [..XX]
	//   026a: 03254100          MOVE   WS_REMIND/HI32 [...X]  <-  00
	//   026e: 3e8d41ab09        COMP   WS_REMIND/HI32 [XX..]  <-  09ab
	//   0273: 459202            JUMP_Below  0292
	//   0276: 03254120          MOVE   WS_REMIND/HI32 [...X]  <-  20
	//   027a: 3e8d413610        COMP   WS_REMIND/HI32 [XX..]  <-  1036
	//   027f: 459202            JUMP_Below  0292
	//   0282: 03254140          MOVE   WS_REMIND/HI32 [...X]  <-  40
	//   0286: 3e8d41a816        COMP   WS_REMIND/HI32 [XX..]  <-  16a8
	//   028b: 459202            JUMP_Below  0292
	//   028e: 03254160          MOVE   WS_REMIND/HI32 [...X]  <-  60
	//   0292: 0f254180          OR     WS_REMIND/HI32 [...X]  <-  80
	//   0296: 03a4410900        MOVE   WS_REMIND/HI32 [.X..]  <-  data[0009] [...X]
	//   029b: 4ca54101          TEST   WS_REMIND/HI32 [.X..]  <-  01
	//   029f: 49a602            JUMP_NotEqual  02a6
	//   02a2: 0f254110          OR     WS_REMIND/HI32 [...X]  <-  10
	//   02a6: 3b059c4c0000      SET_FB_BASE  00004c9c
	//   02ac: 04620041          MOVE   fb[00]     [..X.]  <-  WS_REMIND/HI32 [...X]
	//   02b0: 030500804c0000    MOVE   work[00]   [XXXX]  <-  00004c80
	//   02b7: 02210100          MOVE   param[01]  [...X]  <-  param[00]  [...X]
	//   02bb: 02e90100          MOVE   param[01]  [X...]  <-  param[00]  [..X.]
	//   02bf: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   02c2: 030a4100          MOVE   WS_REMIND/HI32 [..XX]  <-  work[00]   [..XX]
	//   02c6: 3b0241            SET_FB_BASE  WS_REMIND/HI32 [XXXX]
	//   02c9: 03034100          MOVE   WS_REMIND/HI32 [XXXX]  <-  fb[00]     [XXXX]
	//   02cd: 3e0541ffffffff    COMP   WS_REMIND/HI32 [XXXX]  <-  ffffffff
	//   02d4: 441603            JUMP_Equal  0316
	//   02d7: 3b05004c0000      SET_FB_BASE  00004c00
	//   02dd: 040501f0038061    MOVE   fb[01]     [XXXX]  <-  618003f0
	//   02e4: 04020241          MOVE   fb[02]     [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   02e8: 020500044c0000    MOVE   param[00]  [XXXX]  <-  00004c04
	//   02ef: 551001            CLEAR  param[01]  [.XX.]
	//   02f2: 524e              CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	//   02f4: 3d650100          COMP   param[01]  [..X.]  <-  00
	//   02f8: 440b03            JUMP_Equal  030b
	//   02fb: 51c8              DELAY_MicroSec  c8
	//   02fd: 51c8              DELAY_MicroSec  c8
	//   02ff: 2da50001          ADD    work[00]   [.X..]  <-  01
	//   0303: 3ea50007          COMP   work[00]   [.X..]  <-  07
	//   0307: 45bf02            JUMP_Below  02bf
	//   030a: 5b                EOT
	//   030b: 2d0d000400        ADD    work[00]   [..XX]  <-  0004
	//   0310: 561800            CLEAR  work[00]   [XX..]
	//   0313: 43bf02            JUMP   02bf
	//   0316: 5b                EOT
	//   0317: 7a4000011e0000025a00000300000004000000055a0000061e0000077d000008
	//         200000090100000a0c00000b0000000c0600000e380000100000000d010000ff
	//         ffffff
	//                           CTB_DS  64 bytes

}
