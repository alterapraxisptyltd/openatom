#include "radeon_util.h"

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
	radeon_write_sync(0x0c68, 0x66666666);// 	0097: 01051a0366666666  MOVE   reg[031a]  [XXXX]  <-  66666666
	radeon_write_sync(0x0c74, 0x002bc666);// 	009f: 01051d0366c62b00  MOVE   reg[031d]  [XXXX]  <-  002bc666
	// 	00a7: 5c05f602ff08ff9f04f40020  MASK   reg[02f6]  [XXXX]  &  9fff08ff  |  2000f404
	reg32 = radeon_read_sync(0x0bd8);
	reg32 &= 0x9fff08ff;
	reg32 |= 0x2000f404;
	radeon_write_sync(0x0bd8, reg32);

	radeon_write_sync(0x0be4, 0x00022710);// 	00b3: 0105f90210270200  MOVE   reg[02f9]  [XXXX]  <-  00022710
	radeon_write_sync(0x0be0, 0x00040000);// 	00bb: 0105f80200000400  MOVE   reg[02f8]  [XXXX]  <-  00040000
	// 	00c3: 5c650717e708      MASK   reg[1707]  [..X.]  &  e7  |  08
	reg32 = radeon_read_sync(0x5c1c);
	reg32 &= 0xffffe7ff;
	reg32 |= 0x00000800;
	radeon_write_sync(0x5c1c, reg32);

	radeon_write_sync(0x04ec, 0x01120464);// 	00c9: 01053b0164041201  MOVE   reg[013b]  [XXXX]  <-  01120464
	radeon_write_sync(0x04c0, 0x001186a0);// 	00d1: 01053001a0861100  MOVE   reg[0130]  [XXXX]  <-  001186a0
	radeon_write_sync(0x5ee8, 0x00640018);// 	00d9: 0105ba1718006400  MOVE   reg[17ba]  [XXXX]  <-  00640018
	radeon_write_sync(0x04c4, 0x0801003c);// 	00e1: 010531013c000108  MOVE   reg[0131]  [XXXX]  <-  0801003c
	// 	00e9: 0165d40002        MOVE   reg[00d4]  [..X.]  <-  02
	reg32 = radeon_read_sync(0x0350);
	reg32 &= ~(0xff << 8);
	reg32 |= 0x02 << 8;
	radeon_write_sync(0x0350, reg32);

	// 	00ee: 010dfc000001      MOVE   reg[00fc]  [..XX]  <-  0100
	reg32 = radeon_read_sync(0x03f0);
	reg32 &= ~0xffff;
	reg32 |= 0x0100;
	radeon_write_sync(0x03f0, reg32);

	radeon_write_sync(0x6428, 0x0000000f);// 	00f4: 01050a190f000000  MOVE   reg[190a]  [XXXX]  <-  0000000f
	radeon_write_sync(0x60e0, 0x30000000);// 	00fc: 0105381800000030  MOVE   reg[1838]  [XXXX]  <-  30000000

	// 	0104: 4a257e1701        TEST   reg[177e]  [...X]  <-  01
	// 	0109: 490401            JUMP_NotEqual  0104
	while ((radeon_reg_read(0x177e) & 0xff) != 0x01);
	
	radeon_write_sync(0x5df4, 0x00002000);// 	010c: 01057d1700200000  MOVE   reg[177d]  [XXXX]  <-  00002000
	radeon_write_sync(0x5df0, 0x100010ff);// 	0114: 01057c17ff100010  MOVE   reg[177c]  [XXXX]  <-  100010ff
}
static void dcg_else(uint8_t par)
{
	// 	0010: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	// 	0013: 03214100          MOVE   WS_REMIND/HI32 [...X]  <-  param[00]  [...X]
	// 	0017: 15254102          SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  02
	// 	001b: 030a4841          MOVE   WS_REGPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	// 	001f: 3d650001          COMP   param[00]  [..X.]  <-  01
	// 	0023: 448300            JUMP_Equal  0083
	// 	0026: 3d250002          COMP   param[00]  [...X]  <-  02
	// 	002a: 453900            JUMP_Below  0039
	// 	002d: 54206117          CLEAR  reg[1761]  [...X]
	// 	0031: 3ce5621730        COMP   reg[1762]  [X...]  <-  30
	// 	0036: 493100            JUMP_NotEqual  0031
	// 	0039: 03214800          MOVE   WS_REGPTR [...X]  <-  param[00]  [...X]
	// 	003d: 010dfa020200      MOVE   reg[02fa]  [..XX]  <-  0002
	// 	0043: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	// 	0045: 0125be1b02        MOVE   reg[1bbe]  [...X]  <-  02
	// 	004a: 5ce5c01afc02      MASK   reg[1ac0]  [X...]  &  fc  |  02
	// 	0050: 0125911a11        MOVE   reg[1a91]  [...X]  <-  11
	// 	0055: 0d257d1a01        OR     reg[1a7d]  [...X]  <-  01
	// 	005a: 0d25341b01        OR     reg[1b34]  [...X]  <-  01
	// 	005f: 0105f61a01000000  MOVE   reg[1af6]  [XXXX]  <-  00000001
	// 	0067: 0da5b61b01        OR     reg[1bb6]  [.X..]  <-  01
	// 	006c: 0105311b00080004  MOVE   reg[1b31]  [XXXX]  <-  04000800
	// 	0074: 0125c51b06        MOVE   reg[1bc5]  [...X]  <-  06
	// 	0079: 010d861b0400      MOVE   reg[1b86]  [..XX]  <-  0004
	// 	007f: 3a0000            SET_REG_BLOCK  0000
	// 	0082: 5b                EOT
	// 	0083: 3d250002          COMP   param[00]  [...X]  <-  02
	// 	0087: 457f00            JUMP_Below  007f
	// 	008a: 54086017          CLEAR  reg[1760]  [..XX]
	// 	008e: 0d25611701        OR     reg[1761]  [...X]  <-  01
	// 	0093: 3a0000            SET_REG_BLOCK  0000
	// 	0096: 5b                EOT

}
static void dynamic_clock_gating(uint8_t par)
{
	if (par != 7)
		dcg7();
	else
		dcg_else(par);
}

static void asic_registers_init(void)
{
	uint32_t reg32;

	clock_source();
	radeon_write_sync(0x2c00, 0x0f200021);// 	000b: 0105000b2100200f  MOVE   reg[0b00]  [XXXX]  <-  0f200021
	radeon_write_sync(0x2f30, 0x00000001);// 	0013: 0105cc0b01000000  MOVE   reg[0bcc]  [XXXX]  <-  00000001
	radeon_write_sync(0x2f4c, 0x00121be0);// 	001b: 0105d30be01b1200  MOVE   reg[0bd3]  [XXXX]  <-  00121be0
	radeon_write_sync(0x5008, 0x0000d80d);// 	0023: 010502140dd80000  MOVE   reg[1402]  [XXXX]  <-  0000d80d
	radeon_write_sync(0x500c, 0x0000d80c);// 	002b: 010503140cd80000  MOVE   reg[1403]  [XXXX]  <-  0000d80c
	radeon_write_sync(0x5010, 0x00020169);// 	0033: 0105041469010200  MOVE   reg[1404]  [XXXX]  <-  00020169
	radeon_write_sync(0x5014, 0x00020168);// 	003b: 0105051468010200  MOVE   reg[1405]  [XXXX]  <-  00020168
	radeon_write_sync(0x5018, 0x0002017d);// 	0043: 010506147d010200  MOVE   reg[1406]  [XXXX]  <-  0002017d
	radeon_write_sync(0x501c, 0x0002017c);// 	004b: 010507147c010200  MOVE   reg[1407]  [XXXX]  <-  0002017c
	radeon_write_sync(0x5020, 0x00020191);// 	0053: 0105081491010200  MOVE   reg[1408]  [XXXX]  <-  00020191
	radeon_write_sync(0x5024, 0x00020190);// 	005b: 0105091490010200  MOVE   reg[1409]  [XXXX]  <-  00020190
	radeon_reg_write(0x0038, 0x01338040);// 	0063: 0105380040803301  MOVE   reg[0038]  [XXXX]  <-  01338040

	radeon_reg_write(0x0039, radeon_reg_read(0x0039) | 1); // 	006b: 0d25390001        OR     reg[0039]  [...X]  <-  01
	radeon_reg_write(0x0038, 0x01338041);// 	0070: 0105380041803301  MOVE   reg[0038]  [XXXX]  <-  01338041
	radeon_reg_write(0x0039, radeon_reg_read(0x0039) | 1);// 	0078: 0d25390001        OR     reg[0039]  [...X]  <-  01

// 	007d: 02650007          MOVE   param[00]  [..X.]  <-  07
// 	0081: 520d              CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating(7);
// 	0083: 550000            CLEAR  param[00]  [XXXX]
// 	0086: 520d              CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating(0);
// 	0088: 5223              CALL_TABLE  23  (EnableCRTC)
// 	008a: 2c250001          ADD    param[00]  [...X]  <-  01
// 	008e: 3d250004          COMP   param[00]  [...X]  <-  04
// 	0092: 458600            JUMP_Below  0086
	udelay(2);// 	0095: 5102              DELAY_MicroSec  02
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

void asic_init(voifd)
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
}
