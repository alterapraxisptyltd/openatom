//#include "evergreend.h"
#include "trinityd.h"
#include "radeon_util.h"
#include "radeon_init_native.h"
#include "linux_glue.h"	// For aruba_ IO accessor ONLY!!!!!!!!!
// And we also fucking cheat and use the drm_display_mode as well */
#include "ObjectID.h"
#include "drm_dp_helper.h"
#include "edid.h"

/*
 * Use this fucking regexp to clean tables
 *
 * ([0-9a-f]{4}: )[0-9a-f ]*
 * \1
 */

#define VGA_MEMORY_BASE_ADDRESS               0x310
#define VGA_MEMORY_BASE_ADDRESS_HIGH          0x324

#define TIMED_OUT(str) \
	do {						\
		DRM_ERROR("Timed out on %s", str);	\
		return;					\
	} while(0)

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
	aruba_mask(rdev, GENERAL_PWRMGT, 3 << 16, 0);
	//   000e: OR     reg[019c]  [..X.]  <-  80
	aruba_mask(rdev, GENERAL_PWRMGT, 0, BIT(15));
	//   0013: MOVE   reg[01c5]  [XXXX]  <-  1d20d320
	aruba_write(rdev, 0x1c5 << 2, 0x1d20d320);
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
	aruba_write(rdev, HDP_HOST_PATH_CNTL, 0x0f200021);
	//   0013: MOVE   reg[0bcc]  [XXXX]  <-  00000001
	aruba_write(rdev, 0x2f30, 0x00000001);
	//   001b: MOVE   reg[0bd3]  [XXXX]  <-  00121be0
	aruba_write(rdev, HDP_MISC_CNTL, 0x00121be0);
	//   0023: MOVE   reg[1402]  [XXXX]  <-  0000d80d
	aruba_write(rdev, 0x5008, 0x0000d80d);
	//   002b: MOVE   reg[1403]  [XXXX]  <-  0000d80c
	aruba_write(rdev, 0x500c, 0x0000d80c);
	//   0033: MOVE   reg[1404]  [XXXX]  <-  00020169
	aruba_write(rdev, 0x5010, 0x00020169);
	//   003b: MOVE   reg[1405]  [XXXX]  <-  00020168
	aruba_write(rdev, 0x5014, 0x00020168);
	//   0043: MOVE   reg[1406]  [XXXX]  <-  0002017d
	aruba_write(rdev, 0x5018, 0x0002017d);
	//   004b: MOVE   reg[1407]  [XXXX]  <-  0002017c
	aruba_write(rdev, 0x501c, 0x0002017c);
	//   0053: MOVE   reg[1408]  [XXXX]  <-  00020191
	aruba_write(rdev, 0x5020, 0x00020191);
	//   005b: MOVE   reg[1409]  [XXXX]  <-  00020190
	aruba_write(rdev, 0x5024, 0x00020190);
	//   0063: MOVE   reg[0038]  [XXXX]  <-  01338040
	aruba_write(rdev, 0x0038 << 2, 0x01338040);
	//   006b: OR     reg[0039]  [...X]  <-  01
	aruba_mask(rdev, 0x0039 << 2, 0, BIT(0));
	//   0070: MOVE   reg[0038]  [XXXX]  <-  01338041
	aruba_write(rdev, 0x0038 << 2, 0x01338041);
	//   0078: OR     reg[0039]  [...X]  <-  01
	aruba_mask(rdev, 0x0039 << 2, 0, BIT(0));
	//   007d: MOVE   param[00]  [..X.]  <-  07
	//   0081: CALL_TABLE  0d  (DynamicClockGating)
	dynamic_clock_gating_init(rdev);
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
	aruba_write(rdev, BIG_ASS_ACRATCH_REG, BIT(1));
	/* WARNING: vvv This does UNIPHY 0 -> 3, in order vvv */
	//   00a4: MOVE   reg[1b33]  [XXXX]  <-  00007fff
	aruba_write(rdev, 0x1b33 << 2, 0x00007fff);
	//   00ac: MOVE   reg[1e33]  [XXXX]  <-  00007fff
	aruba_write(rdev, 0x1e33 << 2, 0x00007fff);
	//   00b4: MOVE   reg[4133]  [XXXX]  <-  00007fff
	aruba_write(rdev, 0x4133 << 2, 0x00007fff);
	//   00bc: MOVE   reg[4433]  [XXXX]  <-  00007fff
	aruba_write(rdev, 0x4433 << 2, 0x00007fff);
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
	aruba_mask(rdev, BIF_FB_EN, 0xff, 0);
	//   000d: CLEAR  WS_REMIND/HI32 [XXXX]
	//   0010: MOVE   WS_REMIND/HI32 [XX..]  <-  reg[0809]  [..XX]
	reg16 = aruba_read(rdev, MC_VM_FB_LOCATION);
	//   0015: MOVE   reg[0b01]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	aruba_write(rdev, HDP_NONSURFACE_BASE, reg16 << 16);
	//   001a: MOVE   reg[00c9]  [...X]  <-  WS_REMIND/HI32 [X...]
	aruba_write(rdev, VGA_MEMORY_BASE_ADDRESS_HIGH, reg16 >> 8);
	//   001f: SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
	//   0023: MOVE   reg[00c4]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	aruba_write(rdev, VGA_MEMORY_BASE_ADDRESS, reg16 << 24);
	//   0028: CLEAR  reg[082b]  [...X]
	aruba_mask(rdev, MC_SHARED_BLACKOUT_CNTL, 0xff, 0);
	//   002c: OR     reg[1524]  [...X]  <-  03
	aruba_mask(rdev, BIF_FB_EN, 0, FB_READ_EN | FB_WRITE_EN);
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
	pll = aruba_compute_engine_pll(&clock_khz);
	//   0010: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0013: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0018: 441300            JUMP_Equal  0013
	while (!(aruba_read(rdev, CG_SPLL_FUNC_CNTL_2) & 1));
	//   001b: 0139800101        MOVE   reg[0180]  [...X]  <-  param[01]  [X...]
	aruba_mask(rdev, CG_SPLL_FUNC_CNTL, 0xff, pll);
	//   0020: 4a25810101        TEST   reg[0181]  [...X]  <-  01
	//   0025: 442000            JUMP_Equal  0020
	while (!(aruba_read(rdev, CG_SPLL_FUNC_CNTL_2) & 1));
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
		aruba_mask(rdev, 0x1724, 0, BIT(18));
		//   0028: CALL_TABLE  4b  (DIG2EncoderControl)
	}
	fprintf(stderr, "\t/* asic_init done */\n");
	//   002a: EOT
}

// command_table  0000e3d0  #38  (ReadHWAssistedI2CStatus/HPDInterruptService):
//
//   Size         005f
//   Format Rev.  02
//   Param Rev.   00
//   Content Rev. 02
//   Attributes:  Work space size        00 longs
//                Parameter space size   01 longs
//                Table update indicator 0
//
uint8_t aruba_hpd_interrupt_status(struct radeon_device *rdev, uint8_t hpd_id)
{
	uint8_t status;
	uint32_t off;
	//   0006: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: 3d650001          COMP   param[00]  [..X.]  <-  01
	//   000d: 445400            JUMP_Equal  0054
		/* Should have called aruba_sw_interrupt() */
	//   0010: 553000            CLEAR  param[00]  [.X..]
	//   0013: 3d250006          COMP   param[00]  [...X]  <-  06
	//   0017: 465000            JUMP_Above  0050
	if (hpd_id > 5)
		return 0;
	//   001a: 32250001          SUB    param[00]  [...X]  <-  01
	//   001e: 20250003          MUL    param[00]  [...X]  <-  03
	//   0022: 560848            CLEAR  WS_REGPTR [..XX]
	//   0025: 03224840          MOVE   WS_REGPTR [...X]  <-  WS_QUOT/LOW32 [...X]
	off = hpd_id * 0xc;
	//   0029: 0da5081801        OR     reg[1808]  [.X..]  <-  01
	aruba_mask(rdev, DC_HPD1_INT_CONTROL + off, 0, DC_HPDx_INT_EN);
	//   002e: 02a0000718        MOVE   param[00]  [.X..]  <-  reg[1807]  [...X]
	//   0033: 08a50003          AND    param[00]  [.X..]  <-  03
	status = aruba_read(rdev, DC_HPD1_INT_STATUS + off) & 0x3;
	//   0037: 4a25071802        TEST   reg[1807]  [...X]  <-  02
	//   003c: 444a00            JUMP_Equal  004a
	if (status & DC_HPDx_SENSE)
		//   003f: 5c0d0818fffe0100  MASK   reg[1808]  [..XX]  &  feff  |  0001
		aruba_mask(rdev, DC_HPD1_INT_CONTROL + off, DC_HPDx_INT_POLARITY, DC_HPDx_INT_ACK);
		//   0047: 435000            JUMP   0050
	else
		//   004a: 0d0d08180101      OR     reg[1808]  [..XX]  <-  0101
		aruba_mask(rdev, DC_HPD1_INT_CONTROL + off, 0, DC_HPDx_INT_POLARITY | DC_HPDx_INT_ACK);
	//   0050: 3a0000            SET_REG_BLOCK  0000
	//   0053: 5b                EOT
	return status;
}
void aruba_sw_interrupt(struct radeon_device *rdev)
{
	//   0054: 0d65cf0508        OR     reg[05cf]  [..X.]  <-  08
	/* ^^^ That's a scratch register. Fuck it. ^^^ */
	//   0059: 0d65131401        OR     reg[1413]  [..X.]  <-  01
	aruba_mask(rdev, 0x504c, 0, BIT(0));
	//   005e: 5b                EOT
}

void set_video_mode_motherfucker(struct radeon_device *rdev, struct edid *edid);
/*
 * Yes. This is it. The master plan. The master function. This is where we run
 * through all the hoops and loops and actually initialize the display, not just
 * GPU. This is the culminating event of all that bullshit work
 */
void execute_master_plan(struct radeon_device * rdev)
{
	int ret;
	uint8_t edid_raw[256];
	struct edid edid;
	if (rdev == NULL)
		rdev = my_aux.parent;

	//aruba_asic_init(rdev);

	aruba_read(rdev, CONFIG_MEMSIZE);

	/* > Some scratch reg shit we're skipping <*/

	/* This bit is part of UNIPHY transmitter init. What does it do? */
	fprintf(stderr, "\t/* transmitter_init */\n");
	aruba_transmitter_init(rdev, CONNECTOR_OBJECT_ID_LVDS);

	fprintf(stderr, "\t/* hpd_interrupt_status */\n");
	aruba_hpd_interrupt_status(rdev, 0);

	fprintf(stderr, "\t/* EDID read */\n");
	ret = radeon_read_dp_aux_i2c(0, 0x50, edid_raw, 0, 128);
	if (ret < 0) {
		printf("Sorry. Could not get an EDID. Aborting this shit\n");
		return;
	}

	ret = decode_edid(edid_raw, sizeof(edid_raw), &edid);
	if (ret < 0) {
		printf("Something's wrong with the EDID. farting...\n");
		return;
	}

	//aruba_lcd_bloff(rdev);
	fprintf(stderr, "\t/* brightness_control */\n");
	aruba_brightness_control(rdev, 200, 255);
	fprintf(stderr, "\t/* brightness_control done */\n");
	fprintf(stderr, "\t/* travis_init */\n");
	travis_init(rdev);
	fprintf(stderr, "\t/* travis should now work */\n");

	vga_pre_c1();

	set_video_mode_motherfucker(rdev, &edid);
}

static void edid_to_mode(struct drm_display_mode *mode, struct edid *edid)
{
	printf( "pclk %d\n"
		"x_mm %d\n"
		"y_mm %d\n"
		"ha!  %d\n"
		"hbl  %d\n"
		"hso  %d\n"
		"hspw %d\n"
		"hbo  %d\n"
		"va!  %d\n"
		"vbl  %d\n"
		"vso  %d\n"
		"vspw %d\n"
		"vbo  %d\n",
		edid->pixel_clock,
		edid->x_mm,
		edid->y_mm,
		edid->ha,
		edid->hbl,
		edid->hso,
		edid->hspw,
		edid->hborder,
		edid->va,
		edid->vbl,
		edid->vso,
		edid->vspw,
		edid->vborder);

	mode->crtc_clock = edid->pixel_clock;
	mode->crtc_hdisplay = edid->ha;
	mode->crtc_hblank_start = edid->ha;
	mode->crtc_hblank_end = edid->ha + edid->hbl;

	mode->crtc_hsync_start = edid->ha + edid->hso;
	mode->crtc_hsync_end = edid->ha + edid->hso + edid->hspw;
	mode->crtc_htotal = edid->ha + edid->hbl;
	mode->crtc_hskew = 0;

	mode->crtc_vdisplay = edid->va;
	mode->crtc_vblank_start = edid->va;
	mode->crtc_vblank_end = edid->va + edid->vbl;
	mode->crtc_vsync_start = edid->va + edid->vso;

	mode->crtc_vsync_end = edid->va + edid->vso + edid->vspw;
	mode->crtc_vtotal = edid->va + edid->vbl;

	mode->flags = 0;
	mode->flags |= (edid->pvsync == '-') ? DRM_MODE_FLAG_NVSYNC : 0;
	mode->flags |= (edid->phsync == '-') ? DRM_MODE_FLAG_NHSYNC : 0;

	printf( "Detailed mode (IN FUCKING DECIMAL): Clock %d KHz,\n"
		"               %4d %4d %4d %4d hborder %x\n"
		"               %4d %4d %4d %4d vborder %x\n"
		"               %chsync %cvsync%s\n",
		edid->pixel_clock,
		mode->crtc_hdisplay,
		mode->crtc_hsync_start,
		mode->crtc_hsync_end,
		mode->crtc_htotal,
		edid->hborder,
		mode->crtc_vdisplay,
		mode->crtc_vsync_start,
		mode->crtc_vsync_end,
		mode->crtc_vtotal,
		edid->vborder,
		edid->phsync, edid->pvsync,
		edid->syncmethod
	);

}

uint32_t global_fucksize;

extern void aruba_fuck_my_lute(struct radeon_device *rdev, uint8_t lut_id);
void aruba_enable_grph_srfc(struct radeon_device *rdev, uint8_t surf, uint8_t enable,
			    uint16_t h, uint16_t w, uint16_t pizditch);

static void quick_link_training(struct radeon_device *rdev);

#define my_bpc 1
static const uint8_t my_crtc = 0, my_pll = 2, my_hpd = 0 + 1, my_phy = 4;
void set_video_mode_motherfucker(struct radeon_device *rdev, struct edid *edid)
{
	struct drm_display_mode mode;
	const uint32_t dp_rate_khz = 27000;

	memset(&mode, 0, sizeof(mode));

	fprintf(stderr, "void replay_int10_c3(void)\t// vbe_set_mode()\n{\n");
	c3_mambojumbo();
	fprintf(stderr, "\t/* blank_crtc */\n");
	if (aruba_blank_crtc(rdev, my_crtc, true) < 0)
		TIMED_OUT("crtc blanking 1");
	fprintf(stderr, "\t/* set_disp_eng_pll */\n");
	if (aruba_set_disp_eng_pll(rdev, 80000))
		TIMED_OUT("engine PLL");
	fprintf(stderr, "\t/* update_crtc_x2_buf */\n");
	if (aruba_update_crtc_x2_buf(rdev, my_crtc, true))
		TIMED_OUT("x2 buf");
	fprintf(stderr, "\t/* disable_grph_srfc */\n");
	aruba_disable_grph_srfc(rdev, 0);

	fprintf(stderr, "\t/* init_pixel_pll */\n");
	aruba_init_pixel_pll(rdev, my_pll);
	//fprintf(stderr, "\t/* fuck_with_pll stage 2 */\n");
	//aruba_more_init_pixel_pll(rdev, my_pll);
	fprintf(stderr, "\t/* disable_pll__ss */\n");
	aruba_disable_pll_ss(rdev, my_pll);
	fprintf(stderr, "\t/* set_crtc_dtd_timing */\n");
	edid_to_mode(&mode, edid);
	aruba_set_crtc_dtd_timing(rdev, my_crtc, &mode, 0, 0);
	fprintf(stderr, "\t/* enable_scaler */\n");
	aruba_scaler_setup(rdev, my_crtc, RMX_ASPECT);
	fprintf(stderr, "\t/* enable_grph_srfc */\n");
	global_fucksize = mode.crtc_hdisplay << 16 | mode.crtc_vdisplay;
	global_fucksize = (0x400 << 16) | (0x300);
	aruba_enable_grph_srfc(rdev, 0, true, 0x300, 0x400, 0x400);
	fprintf(stderr, "\t/* lut_setup */\n");
	aruba_fuck_my_lute(rdev, 0);
	fprintf(stderr, "\t/* enable_grph_srfc_more */\n");
	aruba_enable_grph_srfc(rdev, 1, true, 0x300, 0x400, 0x400);
	fprintf(stderr, "\t/* lut_setup_more */\n");
	aruba_fuck_my_lute(rdev, 1);
	aruba_mcleanup(rdev, 0, 200);
	fprintf(stderr, "\t/* enable_crtc */\n");
	if (aruba_enable_crtc(rdev, my_crtc, true))
		TIMED_OUT("crtc diable");
	fprintf(stderr, "\t/* update_crtc_x2_buf */\n");
	if (aruba_update_crtc_x2_buf(rdev, my_crtc, false))
		TIMED_OUT("c2 buf again");
	fprintf(stderr, "\t/* set_encoder_crtc_source */\n");
	aruba_set_encoder_crtc_source(rdev, my_crtc, 0xc, 1);
	aruba_encoder_video_off(rdev, 4);	// <- VBIOS doesn't do this
	fprintf(stderr, "\t/* encoder_setup_dp */\n");
	aruba_encoder_setup_dp(rdev, 4, edid->pixel_clock, 1, my_bpc, dp_rate_khz/10);
	fprintf(stderr, "\t/* encoder_setup_panel_mode */\n");
	aruba_encoder_setup_panel_mode(rdev, 4, 0x1);

	struct DIG_TRANSMITTER_PARAMETERS xmit_ctl = {
		.usSymClock = dp_rate_khz,
		.ucPhyId = my_phy,
		//.ucAction = 0, // Not used

		.ucLaneNum = 1,
		//.ucConnObjId = 0,	// Not used
		.ucDigMode = 0, // ATOM_TRANSMITTER_DIGMODE_V5_DP
		.asConfig = {
			.ucCoherentMode = 0,
			.ucPhyClkSrcId = my_pll,
			.ucHPDSel = 1 + 0,
		},

		.ucDigEncoderSel = 0x10,	// ATOM_TRANSMITTER_DIGMODE_V5_DP
		//.ucDPLaneSet = 0,	// Not used
	};

	fprintf(stderr, "\t/* transmitter_enable */\n");
	aruba_transmitter_enable(rdev, &xmit_ctl);
	fprintf(stderr, "\t/* quick_link_training */\n");
	quick_link_training(rdev);
	/* OK, this is it. We should  have something by now */
}

static void satanic_pattern(struct radeon_device *rdev, int pat)
{
	aruba_encoder_link_training_pattern(rdev, 4, pat);
	drm_dp_dpcd_writeb(&my_aux, DP_TRAINING_PATTERN_SET, pat);
}

static void quick_link_training(struct radeon_device *rdev)
{
	uint8_t sts[DP_LINK_STATUS_SIZE];
	uint8_t dpcd[DP_RECEIVER_CAP_SIZE];
	struct drm_dp_link link;
	struct drm_dp_aux *aux = &my_aux;
	uint8_t world_of_zero[] = {0, 0, 0};

	drm_dp_dpcd_read(aux, DP_DPCD_REV, dpcd, sizeof(dpcd));
	drm_dp_link_probe(aux,  &link);
	drm_dp_link_power_up(aux, &link);
	fprintf(stderr, "\t/* link_training_start */\n");
	aruba_encoder_link_training_start(rdev, 4);
	drm_dp_link_configure(aux, &link);
	drm_dp_dpcd_writeb(aux, DP_DOWNSPREAD_CTRL, DP_SPREAD_AMP_0_5);
	drm_dp_dpcd_writeb(aux, DP_EDP_CONFIGURATION_SET, 1);
	fprintf(stderr, "\t/* training_pattern 1 */\n");
	aruba_encoder_link_training_pattern(rdev, 4, DP_TRAINING_PATTERN_1);

	fprintf(stderr, "\t/* VSEMPH */\n");
	aruba_transmitter_vsemph(rdev, 4, 0);
	fprintf(stderr, "\t/* VSEMPH done */\n");
	drm_dp_dpcd_writeb(aux, DP_TRAINING_PATTERN_SET, DP_TRAINING_PATTERN_1);
	drm_dp_dpcd_write(aux, DP_TRAINING_LANE0_SET, world_of_zero, 3);
	udelay(400);
	while (1) {
		drm_dp_link_train_clock_recovery_delay(dpcd);
		drm_dp_dpcd_read_link_status(aux, sts);
		if (drm_dp_clock_recovery_ok(sts, 1))
			break;
		break;
	}

	satanic_pattern(rdev, DP_TRAINING_PATTERN_2);
	drm_dp_dpcd_write(aux, DP_TRAINING_LANE0_SET, world_of_zero, 3);
	while (1) {
		drm_dp_link_train_channel_eq_delay(dpcd);
		drm_dp_dpcd_read_link_status(aux, sts);
		break;
	}
	aruba_encoder_link_training_finish(rdev, 4);
	drm_dp_dpcd_writeb(&my_aux, DP_TRAINING_PATTERN_SET, DP_TRAINING_PATTERN_DISABLE);

	drm_dp_dpcd_read_link_status(aux, sts);

	aruba_encoder_video_on(rdev, 4);

	//aruba_lcd_blon(rdev);
	/* extrenal encoder video enable */
	aruba_mask(rdev, 0x6464, 0, 3 << 24);

	if (aruba_blank_crtc(rdev, 0, false))
		TIMED_OUT("when we were about to enable CRTC");

	//vga_sr_read(0x01);
	//vga_sr_write(0x01, 0x01);
}
