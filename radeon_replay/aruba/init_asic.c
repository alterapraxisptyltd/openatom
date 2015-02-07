#include "aruba/aruba.h"
#include "aruba/trinityd.h"

#define VGA_MEMORY_BASE_ADDRESS               0x310
#define VGA_MEMORY_BASE_ADDRESS_HIGH          0x324

extern const uint32_t aruba_on_hp_1035dx_vco_freq;

// command_table  0000c394  #47  (ClockSource):
//
//   Size         001c
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
static void clock_source(struct radeon_device *rdev)
{
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: AND    reg[019c]  [.X..]  <-  fc
	radeon_mask(rdev, GENERAL_PWRMGT, 3 << 16, 0);
	//   000e: OR     reg[019c]  [..X.]  <-  80
	radeon_mask(rdev, GENERAL_PWRMGT, 0, BIT(15));
	//   0013: MOVE   reg[01c5]  [XXXX]  <-  1d20d320
	radeon_write(rdev, 0x1c5 << 2, 0x1d20d320);
	//   001b: EOT
}

// command_table  0000bc92  #02  (ASIC_RegistersInit):
//
//   Size         00c5
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
static void asic_registrers_init(struct radeon_device *rdev)
{
	uint8_t crtc_id;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CALL_TABLE  47  (ClockSource)
	clock_source(rdev);
	//   000b: MOVE   reg[0b00]  [XXXX]  <-  0f200021
	radeon_write(rdev, HDP_HOST_PATH_CNTL, 0x0f200021);
	//   0013: MOVE   reg[0bcc]  [XXXX]  <-  00000001
	radeon_write(rdev, 0x2f30, 0x00000001);
	//   001b: MOVE   reg[0bd3]  [XXXX]  <-  00121be0
	radeon_write(rdev, HDP_MISC_CNTL, 0x00121be0);
	//   0023: MOVE   reg[1402]  [XXXX]  <-  0000d80d
	radeon_write(rdev, 0x5008, 0x0000d80d);
	//   002b: MOVE   reg[1403]  [XXXX]  <-  0000d80c
	radeon_write(rdev, 0x500c, 0x0000d80c);
	//   0033: MOVE   reg[1404]  [XXXX]  <-  00020169
	radeon_write(rdev, 0x5010, 0x00020169);
	//   003b: MOVE   reg[1405]  [XXXX]  <-  00020168
	radeon_write(rdev, 0x5014, 0x00020168);
	//   0043: MOVE   reg[1406]  [XXXX]  <-  0002017d
	radeon_write(rdev, 0x5018, 0x0002017d);
	//   004b: MOVE   reg[1407]  [XXXX]  <-  0002017c
	radeon_write(rdev, 0x501c, 0x0002017c);
	//   0053: MOVE   reg[1408]  [XXXX]  <-  00020191
	radeon_write(rdev, 0x5020, 0x00020191);
	//   005b: MOVE   reg[1409]  [XXXX]  <-  00020190
	radeon_write(rdev, 0x5024, 0x00020190);
	//   0063: MOVE   reg[0038]  [XXXX]  <-  01338040
	radeon_write(rdev, 0x0038 << 2, 0x01338040);
	//   006b: OR     reg[0039]  [...X]  <-  01
	radeon_mask(rdev, 0x0039 << 2, 0, BIT(0));
	//   0070: MOVE   reg[0038]  [XXXX]  <-  01338041
	radeon_write(rdev, 0x0038 << 2, 0x01338041);
	//   0078: OR     reg[0039]  [...X]  <-  01
	radeon_mask(rdev, 0x0039 << 2, 0, BIT(0));
	//   007d: MOVE   param[00]  [..X.]  <-  07
	//   0081: CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating_init_hp_1035dx(rdev);
	//   0083: CLEAR  param[00]  [XXXX]
	for (crtc_id = 0; crtc_id < 4; crtc_id++) {
		//   0086: CALL_TABLE  0d  (DynamicClockGating)
		aruba_powergate_crtc(rdev, 0, crtc_id);
		//   0088: CALL_TABLE  23  (EnableCRTC)
		aruba_enable_crtc(rdev, crtc_id, 0);
		//   008a: ADD    param[00]  [...X]  <-  01
		//   008e: COMP   param[00]  [...X]  <-  04
		//   0092: JUMP_Below  0086
	}
	//   0095: DELAY_MicroSec  02
	udelay(2);
	//   0097: CLEAR  param[00]  [XXXX]
	//   009a: CALL_TABLE  4e  (ProcessAuxChannelTransaction)
	radeon_init_aux_pads(rdev);
	//   009c: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   009e: MOVE   reg[1847]  [...X]  <-  data[0038] [...X]
	/* FIXME: This is GPU caps info */
	const uint32_t BIG_ASS_ACRATCH_REG = 0x7388;
	radeon_write(rdev, BIG_ASS_ACRATCH_REG, BIT(1));
	/* WARNING: vvv This does UNIPHY 0 -> 3, in order vvv */
	//   00a4: MOVE   reg[1b33]  [XXXX]  <-  00007fff
	radeon_write(rdev, 0x1b33 << 2, 0x00007fff);
	//   00ac: MOVE   reg[1e33]  [XXXX]  <-  00007fff
	radeon_write(rdev, 0x1e33 << 2, 0x00007fff);
	//   00b4: MOVE   reg[4133]  [XXXX]  <-  00007fff
	radeon_write(rdev, 0x4133 << 2, 0x00007fff);
	//   00bc: MOVE   reg[4433]  [XXXX]  <-  00007fff
	radeon_write(rdev, 0x4433 << 2, 0x00007fff);
	//   00c4: EOT
}


// command_table  0000bd58  #05  (MemoryControllerInit):
//
//   Size         0032
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   00 longs
//                Table update indicator 0
//
static void memory_init(struct radeon_device *rdev)
{
	uint16_t reg16;
	//   0006: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: CLEAR  reg[1524]  [...X]
	radeon_mask(rdev, BIF_FB_EN, 0xff, 0);
	//   000d: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0010: MOVE   WS_REMIND/HI32 [XX..]  <-  reg[0809]  [..XX]
	reg16 = radeon_read(rdev, MC_VM_FB_LOCATION);
	//   0015: MOVE   reg[0b01]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_write(rdev, HDP_NONSURFACE_BASE, reg16 << 16);
	//   001a: MOVE   reg[00c9]  [...X]  <-  WS_REMIND/HI32 [X...]
	radeon_write(rdev, VGA_MEMORY_BASE_ADDRESS_HIGH, reg16 >> 8);
	//   001f: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
	//   0023: MOVE   reg[00c4]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	radeon_write(rdev, VGA_MEMORY_BASE_ADDRESS, reg16 << 24);
	//   0028: CLEAR  reg[082b]  [...X]
	radeon_mask(rdev, MC_SHARED_BLACKOUT_CNTL, 0xff, 0);
	//   002c: OR     reg[1524]  [...X]  <-  03
	radeon_mask(rdev, BIF_FB_EN, 0, FB_READ_EN | FB_WRITE_EN);
	//   0031: EOT
}

// command_table  0000be8a  #0a  (SetEngineClock):
//
//   Size         0029
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   01 longs
//                Table update indicator 0
//
static void set_engine_clock(struct radeon_device *rdev, uint32_t clock_khz)
{
	uint8_t pll;
	//   0006: 02010100          MOVE   param[01]  [XXXX]  <-  param[00]  [XXXX]
	//   000a: 02e50102          MOVE   param[01]  [X...]  <-  02
	//   000e: 523c              CALL_TABLE  3c  (ComputeMemoryEnginePLL)
	pll = aruba_compute_engine_pll(aruba_on_hp_1035dx_vco_freq, &clock_khz);
	//   0010: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0013: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0018: 441300            JUMP_Equal  0013
	while (!(radeon_read(rdev, CG_SPLL_FUNC_CNTL_2) & 1));
	//   001b: 0139800101        MOVE   reg[0180]  [...X]  <-  param[01]  [X...]
	radeon_mask(rdev, CG_SPLL_FUNC_CNTL, 0xff, pll);
	//   0020: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0025: 442000            JUMP_Equal  0020
	while (!(radeon_read(rdev, CG_SPLL_FUNC_CNTL_2) & 1));
	//   0028: 5b                EOT
}

// command_table  0000bc0e  #00  (ASIC_Init):
//
//   Size         002b
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 01
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0
//
void aruba_asic_init(struct radeon_device *rdev)
{
	const uint16_t usDeviceSupport = 0xb;
	//   0006: CALL_TABLE  02  (ASIC_RegistersInit)
	fprintf(stderr, "\t/* asic_registers_init */\n");
	asic_registrers_init(rdev);
	//   0008: CALL_TABLE  05  (MemoryControllerInit)
	fprintf(stderr, "\t/* memory_init */\n");
	memory_init(rdev);
	//   000a: MOVE   param[02]  [XXXX]  <-  param[00]  [XXXX]
	//   000e: OR     param[02]  [X...]  <-  08
	//   0012: CALL_TABLE  0a  (SetEngineClock)
	fprintf(stderr, "\t/* set_engine_clock */\n");
	set_engine_clock(rdev, 200000);
	//   0014: SET_DATA_BLOCK  16  (Object_Info/Object_Header)
	//   0016: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0004] [..XX]
	//   001b: TEST   WS_REMIND/HI32 [..XX]  <-  0002
	//   0020: JUMP_Equal  002a
	if (usDeviceSupport & BIT(1)) {
		//   0023: OR     reg[05c9]  [.X..]  <-  04
		radeon_mask(rdev, 0x1724, 0, BIT(18));
		//   0028: CALL_TABLE  4b  (DIG2EncoderControl)
	}
	fprintf(stderr, "\t/* asic_init done */\n");
	//   002a: EOT
}
