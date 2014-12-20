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

static uint16_t asic_static_power_bullshit(uint8_t par)
{
	const uint16_t data[] = {0x0000, 0x0300, 0x2600, 0x2900,
				 0x2c00, 0x2f00, 0x0000, 0x0002,
				 0x002c, 0x002d, 0x002e, 0x002f,
				 0x0000, 0x0001, 0x0007, 0x0008,
				 0x000b, 0x000c};
	const uint8_t *pointy;
	uint16_t attr;
	/* What THE FUCK is this!!???!!??!!!?? */
	//   0006: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   0008: 560847            CLEAR  WS_ATTR [..XX]
	//   000b: 2d0d425000        ADD    WS_DATAPTR [..XX]  <-  0050
	pointy = (void *)data;
	//   0010: 03214700          MOVE   WS_ATTR [...X]  <-  param[00]  [...X]
	//   0014: 092547f0          AND    WS_ATTR [...X]  <-  f0
	//   0018: 4222476300370063402a00638032005a5a
	//                           SWITCH  WS_ATTR [...X]
	//         00->0037 40->002a 80->0032
	switch (par & 0xf0) {
		case 0:
			break;
		case 0x40:
			//   002a: 2d0d421800        ADD    WS_DATAPTR [..XX]  <-  0018
			//   002f: 433700            JUMP   0037
			pointy += 0x18;
			break;
		case 0x80:
			//   0032: 2d0d420c00        ADD    WS_DATAPTR [..XX]  <-  000c
			pointy += 0x0c;
			break;
		default:
			//   0029: 5b                EOT
			fprintf(stderr, "Unexfuckingpected EOT\n");
			return 0;
	}

	//   0037: 03214700          MOVE   WS_ATTR [...X]  <-  param[00]  [...X]
	//   003b: 09254707          AND    WS_ATTR [...X]  <-  07
	attr = par & 0x07;
	//   003f: 2d0a4247          ADD    WS_DATAPTR [..XX]  <-  WS_ATTR [..XX]
	//   0043: 2d0a4247          ADD    WS_DATAPTR [..XX]  <-  WS_ATTR [..XX]
	pointy += attr * 2;
	//   0047: 030c480000        MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
	return pointy[0] | (pointy[1] << 8);
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
		reg32 = radeon_reg_read(0x1761 + mista_reg);
		reg32 &= ~0xff;
		radeon_reg_write(0x1761 + mista_reg, reg32);

		// 	0031: 3ce5621730        COMP   reg[1762]  [X...]  <-  30
		// 	0036: 493100            JUMP_NotEqual  0031
		while (((radeon_reg_read(0x1762 + mista_reg) >> 24) != 0x30));
	}
	// 	0039: 03214800          MOVE   WS_REGPTR [...X]  <-  param[00]  [...X]
	mista_reg = par;
	// 	003d: 010dfa020200      MOVE   reg[02fa]  [..XX]  <-  0002
	radeon_reg_mask(0x02fa + mista_reg, 0xffff, 0x0002);
	// 	0043: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	mista_reg = asic_static_power_bullshit(par);
	// 	0045: 0125be1b02        MOVE   reg[1bbe]  [...X]  <-  02
	radeon_reg_mask(0x1bbe + mista_reg, 0xff, 0x02);
	// 	004a: 5ce5c01afc02      MASK   reg[1ac0]  [X...]  &  fc  |  02
	radeon_reg_mask(0x1ac0 + mista_reg, 0xfc << 24, 0x02 << 24);
	// 	0050: 0125911a11        MOVE   reg[1a91]  [...X]  <-  11
	radeon_reg_mask(0x1a91 + mista_reg, 0xff, 0x11);
	// 	0055: 0d257d1a01        OR     reg[1a7d]  [...X]  <-  01
	radeon_reg_mask(0x1a7d + mista_reg, 0, 0x01);
	// 	005a: 0d25341b01        OR     reg[1b34]  [...X]  <-  01
	radeon_reg_mask(0x1b34 + mista_reg, 0, 0x01);
	// 	005f: 0105f61a01000000  MOVE   reg[1af6]  [XXXX]  <-  00000001
	radeon_reg_write(0x1af6 + mista_reg, 0x00000001);
	// 	0067: 0da5b61b01        OR     reg[1bb6]  [.X..]  <-  01
	radeon_reg_mask(0x1bb6 + mista_reg, 0, 0x01 << 16);
	// 	006c: 0105311b00080004  MOVE   reg[1b31]  [XXXX]  <-  04000800
	radeon_reg_write(0x1b31 + mista_reg, 0x04000800);
	// 	0074: 0125c51b06        MOVE   reg[1bc5]  [...X]  <-  06
	radeon_reg_mask(0x1bc5 + mista_reg, 0xff, 0x06);
	// 	0079: 010d861b0400      MOVE   reg[1b86]  [..XX]  <-  0004
	radeon_reg_mask(0x1b86 + mista_reg, 0xffff, 0x0004);
	// 	007f: 3a0000            SET_REG_BLOCK  0000
	// 	0082: 5b                EOT
	return;
label_83:
	// 	0083: 3d250002          COMP   param[00]  [...X]  <-  02
	// 	0087: 457f00            JUMP_Below  007f
	if (par < 2)
		return;
	// 	008a: 54086017          CLEAR  reg[1760]  [..XX]
	radeon_reg_mask(0x1762 + mista_reg, 0xffff, 0);
	// 	008e: 0d25611701        OR     reg[1761]  [...X]  <-  01
	radeon_reg_mask(0x1761 + mista_reg, 0xff, 0x01);
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

static void enable_crtc(uint8_t eye)
{
	uint16_t prego;
	//   0009: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	prego = asic_static_power_bullshit(eye);
	//   000b: 3d650001          COMP   param[00]  [..X.]  <-  01
	//   000f: 443000            JUMP_Equal  0030
	if (0) {
		//   0030: 0de57c1b80        OR     reg[1b7c]  [X...]  <-  80
		radeon_reg_mask(0x1b7c + prego, 0, 0x80 << 24);
		//   0035: 0d259c1b01        OR     reg[1b9c]  [...X]  <-  01
		radeon_reg_mask(0x1b9c + prego, 0, 0x01);
		return;
	}
	//   0012: 0d659c1b03        OR     reg[1b9c]  [..X.]  <-  03
	radeon_reg_mask(0x1b9c + prego, 0, 0x03 << 8);
	//   0017: 07259c1bfe        AND    reg[1b9c]  [...X]  <-  fe
	radeon_reg_mask(0x1b9c + prego, ~0xfffffffe, 0);
	//   001c: 4aa59c1b01        TEST   reg[1b9c]  [.X..]  <-  01
	//   0021: 491c00            JUMP_NotEqual  001c
	while (!!!!!!!!!!!!!(((radeon_reg_read(0x1b9c + prego) >> 16) & 0xff) != 0x01));
	//   0024: 07e57c1b7f        AND    reg[1b7c]  [X...]  <-  7f
	radeon_reg_mask(0x1b7c + prego, ~0x7fffffff, 0);
	//   0029: 5420a91b          CLEAR  reg[1ba9]  [...X]
	radeon_reg_mask(0x1ba9 + prego, 0xff, 0);
}
static void asic_registers_init(void)
{
	uint32_t i;

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
	for (i = 0; i < 4; i++) {
		// 	0086: 520d              CALL_TABLE  0d  (DynamicClockGating)
		dynamic_clock_gating(0, i);
		// 	0088: 5223              CALL_TABLE  23  (EnableCRTC)
		enable_crtc(i);
		// 	008a: 2c250001          ADD    param[00]  [...X]  <-  01
		// 	008e: 3d250004          COMP   param[00]  [...X]  <-  04
		// 	0092: 458600            JUMP_Below  0086
	}
	radeon_udelay(2);// 	0095: 5102              DELAY_MicroSec  02
// 	0097: 550000            CLEAR  param[00]  [XXXX]
// 	009a: 524e              CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	radeon_init_aux_pads();
// 	009c: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
// 	009e: 012447183800      MOVE   reg[1847]  [...X]  <-  data[0038] [...X]
	/* FIXME: DOn't use hardcoded 0x02, but iplement actual table */
	radeon_reg_mask(0x1847, 0xff, 0x02);
// 	00a4: 0105331bff7f0000  MOVE   reg[1b33]  [XXXX]  <-  00007fff
	radeon_reg_write(0x1b33, 0x00007fff);
// 	00ac: 0105331eff7f0000  MOVE   reg[1e33]  [XXXX]  <-  00007fff
	radeon_reg_write(0x1e33, 0x00007fff);
// 	00b4: 01053341ff7f0000  MOVE   reg[4133]  [XXXX]  <-  00007fff
	radeon_reg_write(0x4133, 0x00007fff);
// 	00bc: 01053344ff7f0000  MOVE   reg[4433]  [XXXX]  <-  00007fff
	radeon_reg_write(0x4433, 0x00007fff);
// 	00c4: 5b                EOT

}

void memory_controller_init(void)
{
	uint32_t reg32;
	//   0006: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: 54202415          CLEAR  reg[1524]  [...X]
	radeon_reg_mask(0x1524, 0xff, 0);
	//   000d: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0010: 0388410908        MOVE   WS_REMIND/HI32 [XX..]  <-  reg[0809]  [..XX]
	reg32 = radeon_reg_read(0x0809) << 16;
	//   0015: 0102010b41        MOVE   reg[0b01]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_reg_write(0x0b01, reg32);
	//   001a: 013ac90041        MOVE   reg[00c9]  [...X]  <-  WS_REMIND/HI32 [X...]
	radeon_reg_mask(0x00c9, 0xff, reg32 >> 24);
	//   001f: 15054108          SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
	//   0023: 0102c40041        MOVE   reg[00c4]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_reg_write(0x0c4, reg32 >> 8);
	//   0028: 54202b08          CLEAR  reg[082b]  [...X]
	radeon_reg_mask(0x082b, 0xff, 0);
	//   002c: 0d25241503        OR     reg[1524]  [...X]  <-  03
	radeon_reg_mask(0x1524, 0, 3);
	//   0031: 5b                EOT
}

void compute_memory_engine_pll(uint32_t *parb0)
{
	uint32_t quot, rem, win;
	const uint16_t dataman[] = {0x00c8, 0x0640, 0x0008, 0x0019,
				    0x0640, 0x0c80, 0x0040, 0x0032,
				    0x0c80, 0x1838, 0x0060, 0x0064};
	const uint16_t *data;
	//   0006: 080500ffffff00    AND    param[00]  [XXXX]  <-  00ffffff
	*parb0 &= 0x00ffffff;
	//   000d: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   000f: 0304460800        MOVE   WS_FB_WIN [XXXX]  <-  data[0008] [XXXX]
	win = 0x00057e40;	/* data[0008] is 0x00057e40 on 1035dx */
	//   0014: 03054038180000    MOVE   WS_QUOT/LOW32 [XXXX]  <-  00001838
	quot = 0x00001838;
	//   001b: 3d050000000000    COMP   param[00]  [XXXX]  <-  00000000
	//   0022: 445d00            JUMP_Equal  005d
	if (*parb0 == 0)
		goto l_005d;
	//   0025: 21054664000000    MUL    WS_FB_WIN [XXXX]  <-  00000064
	win *= 0x64;
	//   002c: 2d014000          ADD    WS_QUOT/LOW32 [XXXX]  <-  param[00]  [XXXX]
	//   0030: 33054001000000    SUB    WS_QUOT/LOW32 [XXXX]  <-  00000001
	//   0037: 27014000          DIV    WS_QUOT/LOW32 [XXXX]  <-  param[00]  [XXXX]
	quot = (quot * *parb0) - 1;
	//   003b: 3e054038180000    COMP   WS_QUOT/LOW32 [XXXX]  <-  00001838
	//   0042: 454c00            JUMP_Below  004c
	if (quot > 0x00001838)
		//   0045: 03054038180000    MOVE   WS_QUOT/LOW32 [XXXX]  <-  00001838
		quot = 0x00001838;
	//   004c: 3e0540c8000000    COMP   WS_QUOT/LOW32 [XXXX]  <-  000000c8
	//   0053: 465d00            JUMP_Above  005d
	if (quot < 0xc8)
		quot = 0xc8;
	//   0056: 030540c8000000    MOVE   WS_QUOT/LOW32 [XXXX]  <-  000000c8
 l_005d:
	//   005d: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   005f: 2d0d42bb00        ADD    WS_DATAPTR [..XX]  <-  00bb
	data = dataman;

	//   0064: 3e0c400200        COMP   WS_QUOT/LOW32 [..XX]  <-  data[0002] [..XX]
	//   0069: 477400            JUMP_BelowOrEq  0074
	while (quot > data[1])
		//   006c: 2d0d420800        ADD    WS_DATAPTR [..XX]  <-  0008
		data += 4;
		//   0071: 436400            JUMP   0064

	//   0074: 330c400000        SUB    WS_QUOT/LOW32 [..XX]  <-  data[0000] [..XX]
	//   0079: 2d0c400600        ADD    WS_QUOT/LOW32 [..XX]  <-  data[0006] [..XX]
	//   007e: 330d400100        SUB    WS_QUOT/LOW32 [..XX]  <-  0001
	//   0083: 270c400600        DIV    WS_QUOT/LOW32 [..XX]  <-  data[0006] [..XX]
	//   0088: 2d0c400400        ADD    WS_QUOT/LOW32 [..XX]  <-  data[0004] [..XX]
	quot = (quot + data[0] - data[3] - 1) / data[3] + data[2];
	//   008d: 02e20040          MOVE   param[00]  [X...]  <-  WS_QUOT/LOW32 [...X]
	*parb0 |= quot << 24;
	//   0091: 330c400400        SUB    WS_QUOT/LOW32 [..XX]  <-  data[0004] [..XX]
	//   0096: 210c400600        MUL    WS_QUOT/LOW32 [..XX]  <-  data[0006] [..XX]
	//   009b: 2d0c400000        ADD    WS_QUOT/LOW32 [..XX]  <-  data[0000] [..XX]
	quot = ((quot - data[2]) * data[3]) + data[0];
	//   00a0: 03024140          MOVE   WS_REMIND/HI32 [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	rem = quot;
	//   00a4: 21054664000000    MUL    WS_FB_WIN [XXXX]  <-  00000064
	win *= 64;
	//   00ab: 27024041          DIV    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	quot /= rem;
	//   00af: 020a0040          MOVE   param[00]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   00b3: 02b20040          MOVE   param[00]  [.X..]  <-  WS_QUOT/LOW32 [.X..]
	*parb0 = (*parb0 & ~0x00ffffff) | (quot & 0x00ffffff);
	//   00b7: 5b                EOT
	//   00b8: 7a1800c8004006080019004006800c40003200800c381860006400
	//                           CTB_DS  24 bytes
}

void set_engine_cock(uint32_t parb1, uint32_t parb0)
{
	//   0006: 02010100          MOVE   param[01]  [XXXX]  <-  param[00]  [XXXX]
	parb1 = parb0;
	//   000a: 02e50102          MOVE   param[01]  [X...]  <-  02
	parb1 |= (2 << 24);
	//   000e: 523c              CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	compute_memory_engine_pll(&parb0);
	fprintf(stderr, "Engine cock cum back as 0x%x, 0x%x\n", parb1, parb0);
	//   0010: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0013: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0018: 441300            JUMP_Equal  0013
	while(!!!!!!!!!!!!!!!!!!!!!((radeon_reg_read(0x0181) & 0xff) == 0x01));
	//   001b: 0139800101        MOVE   reg[0180]  [...X]  <-  param[01]  [X...]
	radeon_reg_mask(0x0180, 0xff, parb1 >> 24);
	//   0020: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0025: 442000            JUMP_Equal  0020
	while((radeon_reg_read(0x0181) & 0xff) == 0x01);
	//   0028: 5b                EOT
}

void asic_init(void)
{
	//   0006: 5202              CALL_TABLE  02  (ASIC_RegistersInit)
	asic_registers_init();
	//   0008: 5205              CALL_TABLE  05  (MemoryControllerInit)
	memory_controller_init();
	//   000a: 02010200          MOVE   param[02]  [XXXX]  <-  param[00]  [XXXX]
	//   000e: 0ee50208          OR     param[02]  [X...]  <-  08
	//   0012: 520a              CALL_TABLE  0a  (SetEngineClock)
	set_engine_cock(0, 0);
	//   0014: 6616              SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	//   0016: 030c410400        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0004] [..XX]
	//   001b: 4c0d410200        TEST   WS_REMIND/HI32 [..XX]  <-  0002
	//   0020: 442a00            JUMP_Equal  002a
	if (/*usDeviceSupport*/ 0x000b != 0002) {
		//   0023: 0da5c90504        OR     reg[05c9]  [.X..]  <-  04
		radeon_reg_mask(0x05c9, 0, 4 << 16);
		//   0028: 524b              CALL_TABLE  4b  (DIG2EncoderControl)
// 		radeon_dp_encoder_control();
	}
	//   002a: 5b                EOT

	fprintf(stderr, "====== End of refined replay ======\n");
}