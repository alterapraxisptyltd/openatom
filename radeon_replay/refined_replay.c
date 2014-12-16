#include "radeon_init_native.h"
#include "radeon_util.h"

#include <stdio.h>

static void clock_source(void)
{
	uint32_t reg32;
	reg32 = radeon_reg_read(0x019c);
	reg32 &= 0xfffcffff;
	reg32 |= 0x0000800;
	radeon_reg_write(0x19c, reg32);
	radeon_reg_write(0x01c5, 0x1d20d320);
}
static void dcg7(void)
{
	uint32_t reg32;
	radeon_write_sync(0x0c68, 0x66666666);
	radeon_write_sync(0x0c74, 0x002bc666);

	reg32 = radeon_read_sync(0x0bd8);
	reg32 &= 0x9fff08ff;
	reg32 |= 0x2000f404;
	radeon_write_sync(0x0bd8, reg32);

	radeon_write_sync(0x0be4, 0x00022710);
	radeon_write_sync(0x0be0, 0x00040000);

	reg32 = radeon_read_sync(0x5c1c);
	reg32 &= 0xffffe7ff;
	reg32 |= 0x00000800;
	radeon_write_sync(0x5c1c, reg32);

	radeon_write_sync(0x04ec, 0x01120464);
	radeon_write_sync(0x04c0, 0x001186a0);
	radeon_write_sync(0x5ee8, 0x00640018);
	radeon_write_sync(0x04c4, 0x0801003c);

	reg32 = radeon_read_sync(0x0350);
	reg32 &= ~(0xff << 8);
	reg32 |= 0x02 << 8;
	radeon_write_sync(0x0350, reg32);

	reg32 = radeon_read_sync(0x03f0);
	reg32 &= ~0xffff;
	reg32 |= 0x0100;
	radeon_write_sync(0x03f0, reg32);

	radeon_write_sync(0x6428, 0x0000000f);
	radeon_write_sync(0x60e0, 0x30000000);

	// 	0104: 4a257e1701        TEST   reg[177e]  [...X]  <-  01
	// 	0109: 490401            JUMP_NotEqual  0104
	while (!!!!!!!!!!!!!!!!!!!!!((radeon_reg_read(0x177e) & 0xff) != 0x01));

	radeon_write_sync(0x5df4, 0x00002000);
	radeon_write_sync(0x5df0, 0x100010ff);
}

static void asic_static_power_bullshit(void)
{
	/* What THE FUCK is this!!???!!??!!!?? */
	//   0006: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   0008: 560847            CLEAR  WS_ATTR [..XX]
	//   000b: 2d0d425000        ADD    WS_DATAPTR [..XX]  <-  0050
	//   0010: 03214700          MOVE   WS_ATTR [...X]  <-  param[00]  [...X]
	//   0014: 092547f0          AND    WS_ATTR [...X]  <-  f0
	//   0018: 4222476300370063402a00638032005a5a
	//                           SWITCH  WS_ATTR [...X]
	//         00->0037 40->002a 80->0032
	//   0029: 5b                EOT
	//   002a: 2d0d421800        ADD    WS_DATAPTR [..XX]  <-  0018
	//   002f: 433700            JUMP   0037
	//   0032: 2d0d420c00        ADD    WS_DATAPTR [..XX]  <-  000c
	//   0037: 03214700          MOVE   WS_ATTR [...X]  <-  param[00]  [...X]
	//   003b: 09254707          AND    WS_ATTR [...X]  <-  07
	//   003f: 2d0a4247          ADD    WS_DATAPTR [..XX]  <-  WS_ATTR [..XX]
	//   0043: 2d0a4247          ADD    WS_DATAPTR [..XX]  <-  WS_ATTR [..XX]
	//   0047: 030c480000        MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	//   004c: 5b                EOT
	//   004d: 7a24000000000300260029002c002f000002002c002d002e002f000000010007
	//         0008000b000c00
	//                           CTB_DS  36 bytes

}

static void dcg_else(uint8_t parbig, uint8_t par)
{
	uint32_t mista_mista, mista_reg, reg32;

	// 	0010: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	// 	0013: 03214100          MOVE   WS_REMIND/HI32 [...X]  <-  param[00]  [...X]
	// 	0017: 15254102          SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  02
	mista_mista = par << 2;
	// 	001b: 030a4841          MOVE   WS_REGPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	mista_reg = mista_mista;
	// 	001f: 3d650001          COMP   param[00]  [..X.]  <-  01
	// 	0023: 448300            JUMP_Equal  0083
	if (parbig == 1)
		goto label_83;

	// 	0026: 3d250002          COMP   param[00]  [...X]  <-  02
	// 	002a: 453900            JUMP_Below  0039
	if (!(par < 2)) {
		// 	002d: 54206117          CLEAR  reg[1761]  [...X]
		reg32 = radeon_reg_read(0x1761);
		reg32 != ~0xff;
		radeon_reg_write(0x1761, reg32);

		// 	0031: 3ce5621730        COMP   reg[1762]  [X...]  <-  30
		// 	0036: 493100            JUMP_NotEqual  0031
		while (radeon_reg_read(0x1762) >> 24 != 0x30);
	}
	// 	0039: 03214800          MOVE   WS_REGPTR [...X]  <-  param[00]  [...X]
	mista_reg = par;
	// 	003d: 010dfa020200      MOVE   reg[02fa]  [..XX]  <-  0002
	reg32 = radeon_reg_read(0x02fa);
	reg32 &= ~0xffff;
	reg32 |= 0x0002;
	radeon_reg_write(0x02fa, reg32);
	// 	0043: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	asic_static_power_bullshit();
	// 	0045: 0125be1b02        MOVE   reg[1bbe]  [...X]  <-  02
	radeon_reg_mask(0x1bbe, 0xff, 0x02);
	// 	004a: 5ce5c01afc02      MASK   reg[1ac0]  [X...]  &  fc  |  02
	radeon_reg_mask(0x1ac0, 0xfc << 24, 0x02 << 24);
	// 	0050: 0125911a11        MOVE   reg[1a91]  [...X]  <-  11
	radeon_reg_mask(0x1a91, 0xff, 0x11);
	// 	0055: 0d257d1a01        OR     reg[1a7d]  [...X]  <-  01
	radeon_reg_mask(0x1a7d, 0, 0x01);
	// 	005a: 0d25341b01        OR     reg[1b34]  [...X]  <-  01
	radeon_reg_mask(0x1b34, 0, 0x01);
	// 	005f: 0105f61a01000000  MOVE   reg[1af6]  [XXXX]  <-  00000001
	radeon_reg_write(0x1af6, 0x00000001);
	// 	0067: 0da5b61b01        OR     reg[1bb6]  [.X..]  <-  01
	radeon_reg_mask(0x1bb6, 0, 0x01 << 16);
	// 	006c: 0105311b00080004  MOVE   reg[1b31]  [XXXX]  <-  04000800
	radeon_reg_write(0x1b31, 0x04000800);
	// 	0074: 0125c51b06        MOVE   reg[1bc5]  [...X]  <-  06
	radeon_reg_mask(0x1bc5, 0xff, 0x06);
	// 	0079: 010d861b0400      MOVE   reg[1b86]  [..XX]  <-  0004
	radeon_reg_mask(0x1b86, 0xffff, 0x0004);
	// 	007f: 3a0000            SET_REG_BLOCK  0000
	// 	0082: 5b                EOT
	return;
label_83:
	// 	0083: 3d250002          COMP   param[00]  [...X]  <-  02
	// 	0087: 457f00            JUMP_Below  007f
	if (par < 2)
		return;
	// 	008a: 54086017          CLEAR  reg[1760]  [..XX]
	radeon_reg_mask(0x1762, 0xffff, 0);
	// 	008e: 0d25611701        OR     reg[1761]  [...X]  <-  01
	radeon_reg_mask(0x1761, 0xff, 0x01);
	// 	0093: 3a0000            SET_REG_BLOCK  0000
	// 	0096: 5b                EOT

}
static void dynamic_clock_gating(uint8_t parbig, uint8_t par)
{
	if (parbig == 7)
		dcg7();
	else
		dcg_else(parbig, par);
}

static void asic_registers_init(void)
{
	uint32_t reg32;

	clock_source();
	radeon_write_sync(0x2c00, 0x0f200021);
	radeon_write_sync(0x2f30, 0x00000001);
	radeon_write_sync(0x2f4c, 0x00121be0);
	radeon_write_sync(0x5008, 0x0000d80d);
	radeon_write_sync(0x500c, 0x0000d80c);
	radeon_write_sync(0x5010, 0x00020169);
	radeon_write_sync(0x5014, 0x00020168);
	radeon_write_sync(0x5018, 0x0002017d);
	radeon_write_sync(0x501c, 0x0002017c);
	radeon_write_sync(0x5020, 0x00020191);
	radeon_write_sync(0x5024, 0x00020190);
	radeon_reg_write(0x0038, 0x01338040);

	radeon_reg_write(0x0039, radeon_reg_read(0x0039) | 1);
	radeon_reg_write(0x0038, 0x01338041);
	radeon_reg_write(0x0039, radeon_reg_read(0x0039) | 1);

// 	007d: 02650007          MOVE   param[00]  [..X.]  <-  07
// 	0081: 520d              CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating(7, 0);
// 	0083: 550000            CLEAR  param[00]  [XXXX]
// 	0086: 520d              CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating(0, 0);
// 	0088: 5223              CALL_TABLE  23  (EnableCRTC)
// 	008a: 2c250001          ADD    param[00]  [...X]  <-  01
// 	008e: 3d250004          COMP   param[00]  [...X]  <-  04
// 	0092: 458600            JUMP_Below  0086
	radeon_udelay(2);// 	0095: 5102              DELAY_MicroSec  02
// 	0097: 550000            CLEAR  param[00]  [XXXX]
// 	009a: 524e              CALL_TABLE  4e  (ProcessAuxChannelTransaction)
// 	009c: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
// 	009e: 012447183800      MOVE   reg[1847]  [...X]  <-  data[0038] [...X]
// 	00a4: 0105331bff7f0000  MOVE   reg[1b33]  [XXXX]  <-  00007fff
// 	00ac: 0105331eff7f0000  MOVE   reg[1e33]  [XXXX]  <-  00007fff
// 	00b4: 01053341ff7f0000  MOVE   reg[4133]  [XXXX]  <-  00007fff
// 	00bc: 01053344ff7f0000  MOVE   reg[4433]  [XXXX]  <-  00007fff
// 	00c4: 5b                EOT

}

void asic_init(void)
{
	//   0006: 5202              CALL_TABLE  02  (ASIC_RegistersInit)
	asic_registers_init();
	//   0008: 5205              CALL_TABLE  05  (MemoryControllerInit)
	//   000a: 02010200          MOVE   param[02]  [XXXX]  <-  param[00]  [XXXX]
	//   000e: 0ee50208          OR     param[02]  [X...]  <-  08
	//   0012: 520a              CALL_TABLE  0a  (SetEngineClock)
	//   0014: 6616              SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	//   0016: 030c410400        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0004] [..XX]
	//   001b: 4c0d410200        TEST   WS_REMIND/HI32 [..XX]  <-  0002
	//   0020: 442a00            JUMP_Equal  002a
	//   0023: 0da5c90504        OR     reg[05c9]  [.X..]  <-  04
	//   0028: 524b              CALL_TABLE  4b  (DIG2EncoderControl)
	//   002a: 5b                EOT

	fprintf(stderr, "====== End of refined replay ======\n");
}
