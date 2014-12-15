#include <stdio.h>

#include "radeon_util.h"
#include "trinity.h"

static void test_revision(void)
{
	uint32_t rev;

	rev = radeon_read(HW_REV);
	rev = (rev & ATI_REV_ID_MASK) >> ATI_REV_ID_SHIFT;

	printf("Hardware says it is revision %x\n", rev);
}

static uint8_t attempt_aux_read(uint16_t aux_req, uint16_t data_out,
				uint8_t channel_id, uint8_t sts_dly,
				uint8_t data_out_len, uint8_t hpd_id)
{
	uint32_t remind, quot;
	const uint8_t *dataptr = 0;
	uint32_t reg = 0;
	uint32_t regptr = 0;
	uint32_t unidentified;
	const uint8_t data[] = {0x7a, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x14,
		0x00, 0x04, 0x00, 0x28, 0x00, 0x08, 0x00, 0x40, 0x00, 0x0c,
		0x00, 0x54, 0x00, 0x10, 0x00, 0x68, 0x00, 0x14, 0x00};
	// 0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)

	// 0009: COMP   lpAuxRequest  <-  0000
	// 000e: JUMP_Equal  01a7
	if (aux_req == 0)
		goto label_01a7;

	// 0011: CLEAR  WS_REMIND/HI32 [XXXX]
	// 0014: MOVE   WS_REMIND/HI32 [...X]  <-  channelID
	// 0018: AND    WS_REMIND/HI32 [...X]  <-  0f
	// 001c: SHIFT_LEFT  WS_REMIND/HI32 [..XX]  by  02
	remind = (channel_id * 0x0f) << 2;

	// 0020: MOVE   WS_QUOT/LOW32 [..XX]  <-  WS_DATAPTR [..XX]
	quot = (uintptr_t)dataptr & 0xffff;
	// 0024: SET_DATA_BLOCK  ff  (this table)
	// 0026: ADD    WS_DATAPTR [..XX]  <-  020f
	dataptr = data + (0x020f - 0x020c);
	// 002b: ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	dataptr += remind;
	// 002f: MOVE   WS_REGPTR [..XX]  <-  data[0002] [..XX]
	regptr = (data[0x02] + (data[0x03] << 8));
	// 0034: OR     reg[194c]  [.X..]  <-  01
	reg = radeon_read_sync((0x194c + regptr) << 2);
	reg |= 0x00010000;
	radeon_write_sync((0x194c + regptr) << 2, reg);
	// 0039: CLEAR  reg[194c]  [..XX]
	reg &= ~0x0000ffff;
	radeon_write_sync((0x194c + regptr) << 2, reg);
	// 003d: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	regptr = (data[0x00] + (data[0x01] << 8));
	// 0042: MOVE   WS_REMIND/HI32 [X...]  <-  hpdID
	// 0046: SHIFT_LEFT  WS_REMIND/HI32 [X...]  by  04
	remind |= hpd_id << (24 + 4);
	// 004a: MASK   reg[1880]  [.X..]  &  8f  |  WS_REMIND/HI32 [X...]
	reg = radeon_read_sync((0x1880 + regptr) << 2);
	reg &= 0xff8fffff;
	reg |= remind & 0xff000000;
	radeon_write_sync((0x1880 + regptr) << 2, reg);
	// 0050: MOVE   WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	// 0054: OR     reg[1880]  [..XX]  <-  0101
	reg = radeon_read_sync((0x1880 + regptr) << 2);
	reg |= 0x0101;
	radeon_write_sync((0x1880 + regptr) << 2, reg);
	// 005a: CLEAR  WS_REMIND/HI32 [XXXX]
	// 005d: MOVE   WS_REMIND/HI32 [..XX]  <-  lpAuxRequest
	remind = aux_req;

	// 0061: SET_FB_BASE  WS_REMIND/HI32 [XXXX]
	// 0064: MOVE   WS_REMIND/HI32 [...X]  <-  fb[00]     [X...]
	// 0068: SHIFT_RIGHT  WS_REMIND/HI32 [...X]  by  04
	// 006c: MOVE   reg[1881]  [.X..]  <-  WS_REMIND/HI32 [...X]
	// 0071: MOVE   WS_REMIND/HI32 [..X.]  <-  Delay
	// 0075: SHIFT_LEFT  WS_REMIND/HI32 [..X.]  by  04
	// 0079: MOVE   reg[1881]  [...X]  <-  WS_REMIND/HI32 [..X.]
	// 007e: CLEAR  WS_QUOT/LOW32 [XXXX]
	// 0081: OR     WS_QUOT/LOW32 [X...]  <-  80
	// 0085: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [.X..]

	// 0089: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	radeon_write_sync((0x1886 + regptr) << 2, quot);

	// 008e: CLEAR  WS_QUOT/LOW32 [XXXX]
	// 0091: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [..X.]
	// 0095: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 009a: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [...X]
	// 009e: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00a3: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [X...]
	// 00a7: AND    WS_QUOT/LOW32 [..X.]  <-  0f
	// 00ab: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00b0: COMP   WS_REMIND/HI32 [...X]  <-  04
	// 00b4: JUMP_BelowOrEq  00e9
	// 00b7: SUB    WS_REMIND/HI32 [...X]  <-  04
	// 00bb: ADD    WS_FB_WIN [XXXX]  <-  00000004
	// 00c2: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [...X]
	// 00c6: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00cb: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [..X.]
	// 00cf: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00d4: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [.X..]
	// 00d8: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00dd: MOVE   WS_QUOT/LOW32 [..X.]  <-  fb[00]     [X...]
	// 00e1: MOVE   reg[1886]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 00e6: JUMP   00b0
	// 00e9: OR     reg[1883]  [...X]  <-  02
	// 00ee: OR     reg[1881]  [...X]  <-  01
	// 00f3: MOVE   WS_QUOT/LOW32 [...X]  <-  Delay
	// 00f7: MUL    WS_QUOT/LOW32 [...X]  <-  0a
	// 00fb: ADD    WS_QUOT/LOW32 [...X]  <-  32
	// 00ff: TEST   reg[1884]  [...X]  <-  01
	// 0104: JUMP_NotEqual  011b
	// 0107: DELAY_MicroSec  0a
	// 0109: SUB    WS_QUOT/LOW32 [...X]  <-  01
	// 010d: COMP   WS_QUOT/LOW32 [...X]  <-  00
	// 0111: JUMP_NotEqual  00ff
	// 0114: MOVE   Delay  <-  01
	// 0118: JUMP   01a3
	// 011b: TEST   reg[1884]  [XXXX]  <-  00ff8ff0
	// 0123: JUMP_Equal  012d
	// 0126: MOVE   Delay  <-  02
	// 012a: JUMP   01a3
	// 012d: MOVE   reg[1886]  [XXXX]  <-  80000001
	// 0135: MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[1886]  [XXXX]
	// 013a: MOVE   Delay  <-  WS_QUOT/LOW32 [..X.]
	// 013e: MOVE   DataOutLen  <-  reg[1884]  [X...]
	// 0143: AND    DataOutLen  <-  1f
	// 0147: COMP   DataOutLen  <-  00
	// 014b: JUMP_Above  0155
	// 014e: MOVE   Delay  <-  03
	// 0152: JUMP   01a3
	// 0155: SUB    DataOutLen  <-  01
	// 0159: COMP   DataOut  <-  0000
	// 015e: JUMP_Equal  01a3
	// 0161: COMP   DataOutLen  <-  00
	// 0165: JUMP_Equal  01a3
	// 0168: MOVE   WS_REMIND/HI32 [...X]  <-  DataOutLen
	// 016c: MOVE   WS_QUOT/LOW32 [..XX]  <-  DataOut
	// 0170: CLEAR  WS_QUOT/LOW32 [XX..]
	// 0173: SET_FB_BASE  WS_QUOT/LOW32 [XXXX]
	// 0176: MOVE   WS_QUOT/LOW32 [...X]  <-  reg[1886]  [..X.]
	// 017b: MOVE   WS_QUOT/LOW32 [..X.]  <-  reg[1886]  [..X.]
	// 0180: MOVE   WS_QUOT/LOW32 [.X..]  <-  reg[1886]  [..X.]
	// 0185: MOVE   WS_QUOT/LOW32 [X...]  <-  reg[1886]  [..X.]
	// 018a: MOVE   fb[00]     [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	// 018e: COMP   WS_REMIND/HI32 [...X]  <-  04
	// 0192: JUMP_BelowOrEq  01a3
	// 0195: SUB    WS_REMIND/HI32 [...X]  <-  04
	// 0199: ADD    WS_FB_WIN [XXXX]  <-  00000004
	// 01a0: JUMP   0176
	// 01a3: SET_REG_BLOCK  0000
	return sts_dly; // 01a6: EOT

label_01a7:
	// 01a7: SET_DATA_BLOCK  ff  (this table)

	// 01a9: ADD    WS_DATAPTR [..XX]  <-  020f

label_01ae:
	// 01ae: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	// 01b3: MOVE   reg[1888]  [XXXX]  <-  00320000
	// 01bb: MOVE   reg[1889]  [XXXX]  <-  00001c00
	// 01c3: MOVE   reg[188a]  [XXXX]  <-  123d1210
	// 01cb: ADD    WS_DATAPTR [..XX]  <-  0004

	// 01d0: ADD    param[00]  [...X]  <-  01
	unidentified += 1;

	// 01d4: COMP   param[00]  [...X]  <-  06
	// 01d8: JUMP_NotEqual  01ae
	if (unidentified != 0x06)
		goto label_01ae;

	// 01db: CLEAR  WS_REGPTR [..XX]
	regptr &= ~0xffff;
	// 01de: MOVE   WS_REMIND/HI32 [...X]  <-  10
	remind = 0x10;

label_01e2:
	// 01e2: OR     reg[197f]  [..X.]  <-  40
	// 01e7: AND    reg[197f]  [..X.]  <-  bf
	// 01ec: SUB    WS_REMIND/HI32 [...X]  <-  01
	// 01f0: COMP   WS_REMIND/HI32 [...X]  <-  00
	// 01f4: JUMP_NotEqual  01e2
	// 01f7: OR     reg[190b]  [...X]  <-  01
	// 01fc: CLEAR  reg[190b]  [.X..]
	// 0200: OR     reg[190c]  [...X]  <-  01
	// 0205: CLEAR  reg[190c]  [.X..]
	udelay(0x32);// 0209: DELAY_MicroSec  32
	return sts_dly; // 020b: EOT
	// 020c: 7a180000000000140004002800080040000c005400100068001400
	// CTB_DS  24 bytes
}

void run_radeon_tests(void)
{
	printf("Starting a set of radeon tests to see if VGA responds\n");
	test_revision();
	attempt_aux_read(0,0,0,0,0,0);
}
