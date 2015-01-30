#include "radeon_util.h"
#include "linux_glue.h"
#include "ObjectID.h"

#include <stdbool.h>

extern uint16_t get_uniphy_reg_offset(uint8_t huge, uint8_t tits);

// command_table  0000c276  #0d  (DynamicClockGating):
//
//   Size         011d
//   Format Rev.  02
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
void dynamic_clock_gating_init(struct radeon_device *rdev)
{
	//   0097: MOVE   reg[031a]  [XXXX]  <-  66666666
	aruba_write(rdev, 0x0c68, 0x66666666);
	//   009f: MOVE   reg[031d]  [XXXX]  <-  002bc666
	aruba_write(rdev, 0x0c74, 0x002bc666);
	//   00a7: MASK   reg[02f6]  [XXXX]  &  9fff08ff  |  2000f404
	aruba_mask(rdev, 0x0bd8, 0x9fff08f, 0x2000f404);
	//   00b3: MOVE   reg[02f9]  [XXXX]  <-  00022710
	aruba_write(rdev, 0x0be4, 0x00022710);
	//   00bb: MOVE   reg[02f8]  [XXXX]  <-  00040000
	aruba_write(rdev, 0x0be0, 0x00040000);
	//   00c3: MASK   reg[1707]  [..X.]  &  e7  |  08
	aruba_mask(rdev, 0x5c1c, BIT(12), BIT(11));	// PLL WARNING!!!
	//   00c9: MOVE   reg[013b]  [XXXX]  <-  01120464
	aruba_write(rdev, 0x04ec, 0x01120464);
	//   00d1: MOVE   reg[0130]  [XXXX]  <-  001186a0
	aruba_write(rdev, 0x04c0, 0x001186a0);
	//   00d9: MOVE   reg[17ba]  [XXXX]  <-  00640018
	aruba_write(rdev, 0x5ee8, 0x00640018);
	//   00e1: MOVE   reg[0131]  [XXXX]  <-  0801003c
	aruba_write(rdev, 0x04c4, 0x0801003c);
	//   00e9: MOVE   reg[00d4]  [..X.]  <-  02
	aruba_mask(rdev, 0x0350, 0xff << 8, 2 << 8);
	//   00ee: MOVE   reg[00fc]  [..XX]  <-  0100
	aruba_mask(rdev, 0x03f0, 0xffff, 0x0100);
	//   00f4: MOVE   reg[190a]  [XXXX]  <-  0000000f
	aruba_write(rdev, 0x6428, 0x0000000f);
	//   00fc: MOVE   reg[1838]  [XXXX]  <-  30000000
	aruba_write(rdev, 0x60e0, 0x30000000);
	//   0104: TEST   reg[177e]  [...X]  <-  01
	//   0109: JUMP_NotEqual  0104
	while (aruba_read(rdev, 0x5df8) & BIT(0));
	//   010c: MOVE   reg[177d]  [XXXX]  <-  00002000
	aruba_write(rdev, 0x5df4, 0x00002000);
	//   0114: MOVE   reg[177c]  [XXXX]  <-  100010ff
	aruba_write(rdev, 0x5df0, 0x100010ff);
	//   011c: EOT
}

static void crtc_pwrgate_en(struct radeon_device *rdev, uint8_t crtc_id)
{
	uint32_t regptr = crtc_id << 2;
	//   0083: COMP   param[00]  [...X]  <-  02
	//   0087: JUMP_Below  007f
	if (crtc_id < 2)
		return;
	//   008a: CLEAR  reg[1760]  [..XX]
	aruba_mask(rdev, (0x1760 + regptr) << 2, 0xffff, 0);
	//   008e: OR     reg[1761]  [...X]  <-  01
	aruba_mask(rdev, (0x1761 + regptr) << 2, 0, BIT(0));
	//   0093: SET_REG_BLOCK  0000
	//   0096: EOT
}

void aruba_powergate_crtc(struct radeon_device *rdev, uint8_t enable, uint8_t crtc_id)
{
	uint32_t regptr;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: COMP   param[00]  [..X.]  <-  07
	//   000d: JUMP_Equal  0097
	if (enable == 7)
		/* You should have called dynamic_clock_gating_init() instead */
		return;
	//   0010: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0013: MOVE   WS_REMIND/HI32 [...X]  <-  param[00]  [...X]
	//   0017: SHIFT_LEFT  WS_REMIND/HI32 [...X]  by  02
	//   001b: MOVE   WS_REGPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	regptr = crtc_id << 2;
	//   001f: COMP   param[00]  [..X.]  <-  01
	//   0023: JUMP_Equal  0083
	if (enable == 1) {
		crtc_pwrgate_en(rdev, crtc_id);
		return;
	}
	//   0026: COMP   param[00]  [...X]  <-  02
	//   002a: JUMP_Below  0039
	if (crtc_id >= 2) {
		//   002d: CLEAR  reg[1761]  [...X]
		aruba_mask(rdev, (0x1761 + regptr) << 2, 0xff, 0);
		//   0031: COMP   reg[1762]  [X...]  <-  30
		//   0036: JUMP_NotEqual  0031
		while ((aruba_read(rdev, (0x1762 + regptr) << 2) >> 24) != 0x30);
	}
	//   0039: MOVE   WS_REGPTR [...X]  <-  param[00]  [...X]
	regptr = crtc_id;
	//   003d: MOVE   reg[02fa]  [..XX]  <-  0002
	aruba_mask(rdev, (0x2fa + regptr) << 2, 0xffff, BIT(1));
	//   0043: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = get_uniphy_reg_offset(0, crtc_id);
	//   0045: MOVE   reg[1bbe]  [...X]  <-  02
	aruba_mask(rdev, (0x1bbe + regptr) << 2, 0xff, BIT(1));
	//   004a: MASK   reg[1ac0]  [X...]  &  fc  |  02
	aruba_mask(rdev, (0x1ac0 + regptr) << 2, BIT(24), BIT(25));
	//   0050: MOVE   reg[1a91]  [...X]  <-  11
	aruba_mask(rdev, (0x1a91 + regptr) << 2, 0xff, 0x11);
	//   0055: OR     reg[1a7d]  [...X]  <-  01
	aruba_mask(rdev, (0x1a7d + regptr) << 2, 0xff, BIT(0));
	//   005a: OR     reg[1b34]  [...X]  <-  01
	aruba_mask(rdev, (0x1b34 + regptr) << 2, 0, BIT(0));
	//   005f: MOVE   reg[1af6]  [XXXX]  <-  00000001
	aruba_write(rdev, (0x1af6 + regptr) << 2, 1);
	//   0067: OR     reg[1bb6]  [.X..]  <-  01
	aruba_mask(rdev, (0x1bb6 + regptr) << 2, 0, BIT(16));
	//   006c: MOVE   reg[1b31]  [XXXX]  <-  04000800
	aruba_write(rdev, (0x1b31 + regptr) << 2, 0x04000800);
	//   0074: MOVE   reg[1bc5]  [...X]  <-  06
	aruba_mask(rdev, (0x1bc5 + regptr) << 2, 0xff, 0x06);
	//   0079: MOVE   reg[1b86]  [..XX]  <-  0004
	aruba_mask(rdev, (0x1b86 + regptr) << 2, 0xffff, BIT(2));
	//   007f: SET_REG_BLOCK  0000
	//   0082: EOT
}

// command_table  0000c508  #21  (EnableScaler):
//
//   Size         007a
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//

void aruba_scaler_setup(struct radeon_device *rdev, uint8_t crtc_id,
			int rmx_type)
{
	uint32_t regptr;
	uint8_t madman = 0;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = get_uniphy_reg_offset(0, crtc_id);
	//   000b: AND    reg[1ac0]  [...X]  <-  fe
	aruba_mask(rdev, (0x1ac0 + regptr) << 2, BIT(0), 0);
	//   0010: OR     reg[1b51]  [.X..]  <-  01
	aruba_mask(rdev, (0x1b51 + regptr) << 2, 0, BIT(16));
	//   0015: CLEAR  reg[1b54]  [...X]
	aruba_mask(rdev, (0x1b54 + regptr) << 2, 0xff, 0);
	//   0019: CLEAR  reg[1b45]  [...X]
	aruba_mask(rdev, (0x1b45 + regptr) << 2, 0xff, 0);
	//   001d:
	//                           SWITCH  param[00]  [..X.]
	//         00->0031 01->0039 02->004d
	switch (rmx_type) {
	default:		/* Fall through */
	case RMX_OFF:		// ATOM_SCALER_DISABLE
		//   0031: MOVE   reg[1b45]  [...X]  <-  02
		madman = 1;
		//   0036: JUMP   003e
	case RMX_CENTER:	/* Fall through */// ATOM_SCALER_CENTER
		//   0039: MOVE   reg[1b45]  [...X]  <-  01
		aruba_mask(rdev, (0x1b45 + regptr) << 2, 0xff, madman + 1);
		//   003e: CLEAR  reg[1b42]  [...X]
		aruba_mask(rdev, (0x1b42 + regptr) << 2, 0xff, 0);
		//   0042: CLEAR  reg[1b43]  [XXXX]
		aruba_write(rdev, (0x1b43 + regptr) << 2, 0);
		//   0046: CLEAR  reg[1b47]  [XXXX]
		aruba_write(rdev, (0x1b47 + regptr) << 2, 0);
		//   004a: JUMP   0072
		break;
	case RMX_FULL:		/* Fall through */
	case RMX_ASPECT:	// ATOM_SCALER_EXPANSION
		//   004d: MOVE   reg[1b43]  [..XX]  <-  0101
		aruba_mask(rdev, (0x1b43 + regptr) << 2, 0xffff, 0x0101);
		//   0053: MOVE   reg[1b47]  [XXXX]  <-  00010001
		aruba_write(rdev, (0x1b47 + regptr) << 2, 0x00010001);
		//   005b: MOVE   reg[1b4a]  [.XX.]  <-  0301
		aruba_mask(rdev, (0x1b4a + regptr) << 2, 0xffff << 8, 0x0301 << 8);
		//   0061: MOVE   reg[1b4e]  [.XX.]  <-  0301
		aruba_mask(rdev, (0x1b4e + regptr) << 2, 0xffff << 8, 0x0301 << 8);
		//   0067: MOVE   reg[1b53]  [..XX]  <-  1010
		aruba_mask(rdev, (0x1b53 + regptr) << 2, 0xffff, 0x1010);
		//   006d: MOVE   reg[1b42]  [...X]  <-  01
		aruba_mask(rdev, (0x1b42 + regptr) << 2, 0xff, BIT(0));
		break;
	}
	//   0072: CLEAR  reg[1b51]  [.X..]
	aruba_mask(rdev, (0x1b51 + regptr) << 2, 0xff << 16, 0);
	//   0076: SET_REG_BLOCK  0000
	//   0079: EOT
}
