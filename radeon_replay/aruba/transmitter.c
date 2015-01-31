#include "linux_glue.h"
#include "radeon_util.h"
#include "ObjectID.h"
#include "drm_dp_helper.h"
#include "radeon_init_native.h"

#include "trinityd.h"
#include <stdio.h>

// command_table  0000ec64  #4c  (DIG1TransmitterControl/UNIPHYTransmitterControl):
//
//   Size         0a52
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 05
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0

#define REG_ENC_CH_MAPPING		(0x198e << 2)
#define  CH_LANE_MAP(src, dest)		(((src) & 3) << ((dest) * 8))
#define  CH_MAP(src3, src2, src1, src0)		\
		CH_LANE_MAP(src3, 3) |		\
		CH_LANE_MAP(src2, 2) |		\
		CH_LANE_MAP(src1, 1) |		\
		CH_LANE_MAP(src0, 0)

/* Some magic registers that give us access to a magic space */
#define PCIEP_IDX				0xe0
#define PCIEP_DAT				0xe4

#define TN_SMC_IND_INDEX_0			0x200
#define TN_SMC_IND_DATA_0			0x204

#define SMU_17		0x17
#define SMU_18		0x18
#define SMU_22		0x22
#define SMU_23		0x23

#define BIT(x)				(1 << (x))

//ucAction
#define ATOM_TRANSMITTER_ACTION_DISABLE			0
#define ATOM_TRANSMITTER_ACTION_ENABLE			1
#define ATOM_TRANSMITTER_ACTION_LCD_BLOFF		2
#define ATOM_TRANSMITTER_ACTION_LCD_BLON		3
#define ATOM_TRANSMITTER_ACTION_BL_BRIGHTNESS_CONTROL	4
#define ATOM_TRANSMITTER_ACTION_LCD_SELFTEST_START	5
#define ATOM_TRANSMITTER_ACTION_LCD_SELFTEST_STOP	6
#define ATOM_TRANSMITTER_ACTION_INIT			7
#define ATOM_TRANSMITTER_ACTION_DISABLE_OUTPUT		8
#define ATOM_TRANSMITTER_ACTION_ENABLE_OUTPUT		9
#define ATOM_TRANSMITTER_ACTION_SETUP			10
#define ATOM_TRANSMITTER_ACTION_SETUP_VSEMPH		11
#define ATOM_TRANSMITTER_ACTION_POWER_ON		12
#define ATOM_TRANSMITTER_ACTION_POWER_OFF		13

//ucPhyId
#define ATOM_PHY_ID_UNIPHYA				0
#define ATOM_PHY_ID_UNIPHYB				1
#define ATOM_PHY_ID_UNIPHYC				2
#define ATOM_PHY_ID_UNIPHYD				3
#define ATOM_PHY_ID_UNIPHYE				4
#define ATOM_PHY_ID_UNIPHYF				5
#define ATOM_PHY_ID_UNIPHYG				6

// ucDigEncoderSel
#define ATOM_TRANMSITTER_V5__DIGA_SEL			0x01
#define ATOM_TRANMSITTER_V5__DIGB_SEL			0x02
#define ATOM_TRANMSITTER_V5__DIGC_SEL			0x04
#define ATOM_TRANMSITTER_V5__DIGD_SEL			0x08
#define ATOM_TRANMSITTER_V5__DIGE_SEL			0x10
#define ATOM_TRANMSITTER_V5__DIGF_SEL			0x20
#define ATOM_TRANMSITTER_V5__DIGG_SEL			0x40

// ucDigMode
#define ATOM_TRANSMITTER_DIGMODE_V5_DP			0
#define ATOM_TRANSMITTER_DIGMODE_V5_LVDS		1
#define ATOM_TRANSMITTER_DIGMODE_V5_DVI			2
#define ATOM_TRANSMITTER_DIGMODE_V5_HDMI		3
#define ATOM_TRANSMITTER_DIGMODE_V5_SDVO		4
#define ATOM_TRANSMITTER_DIGMODE_V5_DP_MST		5

// ucDPLaneSet
#define DP_LANE_SET__0DB_0_4V				0x00
#define DP_LANE_SET__0DB_0_6V				0x01
#define DP_LANE_SET__0DB_0_8V				0x02
#define DP_LANE_SET__0DB_1_2V				0x03
#define DP_LANE_SET__3_5DB_0_4V				0x08
#define DP_LANE_SET__3_5DB_0_6V				0x09
#define DP_LANE_SET__3_5DB_0_8V				0x0a
#define DP_LANE_SET__6DB_0_4V				0x10
#define DP_LANE_SET__6DB_0_6V				0x11
#define DP_LANE_SET__9_5DB_0_4V				0x18

// ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
// Bit1
#define ATOM_TRANSMITTER_CONFIG_V5_COHERENT		0x02

// Bit3:2
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_MASK		0x0c
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_SHIFT		0x02

#define ATOM_TRANSMITTER_CONFIG_V5_P1PLL		0x00
#define ATOM_TRANSMITTER_CONFIG_V5_P2PLL		0x04
#define ATOM_TRANSMITTER_CONFIG_V5_P0PLL		0x08
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SRC_EXT           0x0c

enum refclk {
	REFCLK_P1PLL = 0,
	REFCLK_P2PLL = 1,
	REFCLK_P0PLL = 2,
	REFCLK_EXT = 3,
};
// Bit6:4
#define ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_MASK		0x70
#define ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_SHIFT	0x04

#define ATOM_TRANSMITTER_CONFIG_V5_NO_HPD_SEL		0x00
#define ATOM_TRANSMITTER_CONFIG_V5_HPD1_SEL		0x10
#define ATOM_TRANSMITTER_CONFIG_V5_HPD2_SEL		0x20
#define ATOM_TRANSMITTER_CONFIG_V5_HPD3_SEL		0x30
#define ATOM_TRANSMITTER_CONFIG_V5_HPD4_SEL		0x40
#define ATOM_TRANSMITTER_CONFIG_V5_HPD5_SEL		0x50
#define ATOM_TRANSMITTER_CONFIG_V5_HPD6_SEL		0x60

#define DIG_TRANSMITTER_CONTROL_PS_ALLOCATION_V1_5            DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5

// Scratch register bowel movement
#define ATOM_S6_ACC_MODE				0x00000010L

// LVDS_Info[39] == ucPowerSequenceVARY_BLtoBLON_in4Ms
// LVDS_Info[40] == ucPowerSequenceBLONtoVARY_BL_in4Ms
#define BLON_DELAYS	0x0303
void aruba_transmitter_init(struct radeon_device *rdev, uint8_t connector_id)
{
	aruba_mask(rdev, 0x191b << 2, 0xffff, 0x0f9f);

	if (connector_id != CONNECTOR_OBJECT_ID_eDP)
		return;

	aruba_write(rdev, 0x191c << 2, 0x78000001);
	aruba_mask(rdev, 0x191d << 2, 0xff, 0x74);
	/* FIXME: BLON_DELAYS is a hardcoded value */
	aruba_mask(rdev, 0x191d << 2, 0xffff << 8, BLON_DELAYS << 8);
	aruba_mask(rdev, 0x1919 << 2, 0, 1 << 25);
}

#define DIV_UP(x, y)     (((x) + (y) - 1) / (y))

/*
 * bl_pwm_freq_hz is LVDS_Info[0032] [..XX] (usBacklightPWM)
 */
#define PWM_MAGIC_CONST 	25000000	// 0x017d7840
#define PWM_RESOLUTION		4095		// 0xfff

void aruba_brightness_control(struct radeon_device *rdev,
			      uint16_t bl_pwm_freq_hz, uint8_t bl_level)
{
	uint32_t ticks_per_cycle, cycle_div, adjusted_ticks, high_ctr;

	if (bl_pwm_freq_hz == 0)
		return;

	if (!(aruba_read(rdev, GENERAL_PWRMGT) & BIT(16)))
		aruba_mask(rdev, 0x1921 << 2, 0, 0x01);

	ticks_per_cycle = bl_pwm_freq_hz * PWM_RESOLUTION;
	cycle_div = DIV_UP(PWM_MAGIC_CONST, ticks_per_cycle);

	aruba_mask(rdev, 0x191b << 2, 0xffff << 16, cycle_div << 16);

	/*
	 * Mathematically, this comes out to be exactly PWM_RESOLUTION, but
	 * after rounding, we may end up with a slightly different resolution.
	 * Doing things this way gets us closer to the desired PWM frequency.
	 */
	adjusted_ticks = PWM_MAGIC_CONST / (cycle_div * bl_pwm_freq_hz);

	aruba_mask(rdev, 0x1920 << 2, 0xff << 16, 0x0c << 16);
	aruba_mask(rdev, 0x1920 << 2, 0xffff, adjusted_ticks & 0xffff);

	high_ctr = adjusted_ticks * (bl_level + 1);
	high_ctr >>= 4;
	aruba_mask(rdev, 0x191e << 2, 0xffff, high_ctr & 0xffff);
	aruba_mask(rdev, 0x191e << 2, 0, 0xc0 << 24);

	aruba_mask(rdev, 0x1921 << 2, (1 << 0), 0);
	while (aruba_read(rdev, 0x1921 << 2) & BIT(8))
		udelay(10);

	fprintf(stderr, "0x%x\t0x%x\t0x%x\n%u\t%u\t%u\n", cycle_div, cycle_ctr, high_ctr, cycle_div, cycle_ctr, high_ctr);
	fprintf(stderr, "ticks_per_cycle vs cycle_ctr %u\t%u\n", ticks_per_cycle, cycle_ctr);
}

void aruba_lcd_blon(struct radeon_device *rdev)
{
	if (aruba_read(rdev, 0x1919 << 2) & BIT(24))
		return;

	udelay(50000);

	if (((aruba_read(rdev, 0x191d << 2) >> 8) & 0xff) == 0) {
		aruba_mask(rdev, 0x191d << 2, 0, 0x03 << 24);
	} else {
		aruba_mask(rdev, 0x1940 << 2, 0, (1 << 16));
		aruba_mask(rdev, 0x1919 << 2, 0, 0x03 << 24);
		udelay(4000);
		aruba_mask(rdev, 0x1940 << 2, (1 << 16), 0);
	}
}

// LVDS_Info[0x40] "usMaxPclkFreqInSingleLink"
void aruba_lcd_bloff(struct radeon_device *rdev)
{
	if (!(aruba_read(rdev, 0x1919 << 2) & BIT(24)))
		return;

	if (((aruba_read(rdev, 0x191d << 2) >> 8) & 0xff) != 0) {
		aruba_mask(rdev, 0x1940 << 2, 0, 0x01 << 16);
		udelay(40000);
		aruba_mask(rdev, 0x1919 << 2, (1 << 24), (1 << 25));
		aruba_mask(rdev, 0x1940 << 2, (1 << 16), 0);
	} else {
		aruba_mask(rdev, 0x1919 << 2, (1 << 24), (1 << 25));
	}
	udelay(1000);
}

static const struct phy_par {
	uint32_t pciep_phy_ctl_idx;
	uint32_t pciep_idx_4;
	uint32_t pciep_idx_8;
	uint32_t default_ch_map;
	uint16_t reg_offset;
	uint8_t default_ch_pn_invert;
	uint8_t magic_15;
	uint8_t ext_disp_path_idx;
	uint8_t city_17;
} phy_info[6] = {
	/* PHY 0 */
	{
		.pciep_phy_ctl_idx = 0x01232002,	//0x02, 0x20, 0x23, 0x01,
		.pciep_idx_4 = 0x01130011,		//0x11, 0x00, 0x13, 0x01,
		.pciep_idx_8 = 0x01338048,		//0x48, 0x80, 0x33, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0000,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x08,
		.ext_disp_path_idx = 0x02,
		.city_17 = 0x06
	},
	/* PHY 1 */
	{
		.pciep_phy_ctl_idx = 0x01212002,	//0x02, 0x20, 0x21, 0x01,
		.pciep_idx_4 = 0x01110011,		//0x11, 0x00, 0x11, 0x01,
		.pciep_idx_8 = 0x01318049,		//0x49, 0x80, 0x31, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0010,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x02,
		.ext_disp_path_idx = 0x03,
		.city_17 = 0x01
	},
	/* PHY 2 */
	{
		.pciep_phy_ctl_idx = 0x02212002,	//0x02, 0x20, 0x21, 0x02,
		.pciep_idx_4 = 0x02110011,		//0x11, 0x00, 0x11, 0x02,
		.pciep_idx_8 = 0x0131804a,		//0x4a, 0x80, 0x31, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0020,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x08,
		.ext_disp_path_idx = 0x04,
		.city_17 = 0x02
	},
	/* PHY 3 */
	{
		.pciep_phy_ctl_idx = 0x02212002,	//0x02, 0x20, 0x21, 0x02,
		.pciep_idx_4 = 0x01110011,		//0x11, 0x00, 0x11, 0x02,
		.pciep_idx_8 = 0x0131804b,		//0x4b, 0x80, 0x31, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0030,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x08,
		.ext_disp_path_idx = 0x05,
		.city_17 = 0x03
	},
	/* PHY 4 */
	{	.pciep_phy_ctl_idx = 0x01222002,	//0x02, 0x20, 0x22, 0x01,
		.pciep_idx_4 = 0x01120011,		//0x11, 0x00, 0x12, 0x01,
		.pciep_idx_8 = 0x0132804c,		//0x4c, 0x80, 0x32, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0040,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x10,
		.ext_disp_path_idx = 0x00,
		.city_17 = 0x04
	},
	/* PHY 5 */
	{	.pciep_phy_ctl_idx = 0x01222002,	//0x02, 0x20, 0x22, 0x01,
		.pciep_idx_4 = 0x01120011,		//0x11, 0x00, 0x12, 0x01,
		.pciep_idx_8 = 0x0131804d,		//0x4d, 0x80, 0x32, 0x01,
		.default_ch_map = 0x03020100,
		.reg_offset = 0x0050,
		.default_ch_pn_invert = 0x00,
		.magic_15 = 0x10,
		.ext_disp_path_idx = 0x01,
		.city_17 = 0x05
	},
};

static const struct non_dp_drive_param {
//	uint16_t offset_next;
	uint16_t sym_clk_max;
	uint8_t dig_mode;
	uint8_t phy_mask;
	uint16_t lane0;
	uint16_t lane1;
	uint16_t lane2;
	uint16_t lane3;
} non_dp_drive_param_table[] = {{
		.sym_clk_max = 0xffff,
		.dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_DVI,
		.phy_mask = 0x3f,
		.lane0 = 0x0b00,
		.lane1 = 0x0b00,
		.lane2 = 0x0b00,
		.lane3 = 0x0b00
	}, {
		.sym_clk_max = 0xffff,
		.dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_HDMI,
		.phy_mask = 0x0e,
		.lane0 = 0x2a00,
		.lane1 = 0x2a00,
		.lane2 = 0x2a00,
		.lane3 = 0x2a00
	}, {
		.sym_clk_max = 0xffff,
		.dig_mode = ATOM_TRANSMITTER_DIGMODE_V5_HDMI,
		.phy_mask = 0x31,
		.lane0 = 0x0b00,
		.lane1 = 0x0b00,
		.lane2 = 0x0b00,
		.lane3 = 0x0b00
	}, {
		/* We somehow have to terminate this list */
		.dig_mode = 0xff
	}
};

static const struct clk_src_params {
	uint32_t pciep_reg_idx;
	uint16_t reg_offset;
	uint8_t smells_like_a_bitmask;	// <- That's a fucking bitmask
	uint8_t d7;
} clk_src_param_table[] = {
	{
		/* Pixel PLL 1 */
		.pciep_reg_idx = 0x01212005,	// 0x05, 0x20, 0x21, 0x01,
		.reg_offset = 0x0001,
		.smells_like_a_bitmask = 0x02,
		.d7 = 0x60,
	},
	{
		/* Pixel PLL 2 */
		.pciep_reg_idx = 0x01232005,	// 0x05, 0x20, 0x23, 0x01,
		.reg_offset = 0x0002,
		.smells_like_a_bitmask = 0x08,
		.d7 = 0x40,
	},
	{
		/* Pixel PLL 0 */
		.pciep_reg_idx = 0x01222005,	// 0x05, 0x20, 0x22, 0x01,
		.reg_offset = 0x0000,
		.smells_like_a_bitmask = 0x10,
		.d7 = 0x40,
	},
};

struct x960_data {
	uint16_t max_sym_clk;
	uint16_t d2;
};

static const struct x960_data x960_non_dp_table[] = { {
		.max_sym_clk = 0x0c35, // 0x35, 0x0c,
		.d2 = 0x0600, // 0x00, 0x06,
	}, {
		.max_sym_clk = 0x101d, // 0x1d, 0x10,
		.d2 = 0x0601, // 0x01, 0x06,
	}, {
		.max_sym_clk = 0x1388, // 0x88, 0x13,
		.d2 = 0x0602, // 0x02, 0x06,
	}, {
		.max_sym_clk = 0x186a, // 0x6a, 0x18,
		.d2 = 0x0603, // 0x03, 0x06,
	}, {
		.max_sym_clk = 0x1fbd, // 0xbd, 0x1f,
		.d2 = 0x0604, // 0x04, 0x06,
	}, {
		.max_sym_clk = 0x2710, // 0x10, 0x27,
		.d2 = 0x0605, // 0x05, 0x06,
	}, {
		.max_sym_clk = 0x30d4, // 0xd4, 0x30,
		.d2 = 0x0606, // 0x06, 0x06,
	}, {
		.max_sym_clk = 0x4074, // 0x74, 0x40,
		.d2 = 0x0607, // 0x07, 0x06,
	}, {
		.max_sym_clk = 0xffff, // 0xff, 0xff,
		.d2 = 0x0608, // 0x08, 0x06,
	}
};

static const struct x960_data x960_dp_table[] = { {
		.max_sym_clk = 17000, // 0x68, 0x42,
		.d2 = 0x0400, // 0x00, 0x04,
	}, {
		.max_sym_clk = 27000, // 0x78, 0x69,
		.d2 = 0x0402, // 0x02, 0x04,
	}, {
		.max_sym_clk = 0xffff, // 0xff, 0xff,
		.d2 = 0x0401, // 0x01, 0x04,
	}
};

extern uint16_t get_uniphy_reg_offset(uint8_t huge, uint8_t tits);

// command_table  0000c3b0  #13  (EnableASIC_StaticPwrMgt):
//
//   Size         00e4
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 02
//   Attributes:  Work space size        00 longs
//                Parameter space size   01 longs
//                Table update indicator 0
//
static void fucking_smu_message(struct radeon_device *rdev, uint32_t msg)
{
	//   00d6: 01028b0041        MOVE   reg[008b]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	aruba_write(rdev, SMC_MESSAGE_0, msg);
	//   00db: 3c258c0000        COMP   reg[008c]  [...X]  <-  00
	//   00e0: 44db00            JUMP_Equal  00db
	int timeout = 1000;
	while ((aruba_read(rdev, SMC_RESP_0) & 0xff) == 0) {
		udelay(1);
		if (!--timeout) {
			DRM_ERROR("SMU event timed out. farting...");
			break;
		}
	}
}

static void smu_18_special_access(struct radeon_device *rdev,
				  uint8_t par3, uint8_t clk_id)
{
	uint32_t quot, rem;
	//   0046: 3da50003          COMP   param[00]  [.X..]  <-  03
	//   004a: 46b000            JUMP_Above  00b0
	if (clk_id > 03)
		return;

	//   004d: 03054100000f00    MOVE   WS_REMIND/HI32 [XXXX]  <-  000f0000
	rem = 0x000f0000;
	//   0054: 4be50080          TEST   param[00]  [X...]  <-  80
	//   0058: 446000            JUMP_Equal  0060
	if (par3 & 0x80) {
		//   005b: 030d410f00        MOVE   WS_REMIND/HI32 [..XX]  <-  000f
		rem |= 0xf;
	}
	//   0060: 3da50000          COMP   param[00]  [.X..]  <-  00
	//   0064: 448100            JUMP_Equal  0081

	rem <<= (clk_id & 3) * 4;
	//   0081: 03024041          MOVE   WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	quot = rem;
	//   0085: 15054108          SHIFT_LEFT  WS_REMIND/HI32 [XXXX]  by  08
	rem <<= 8;
	//   0089: 032a4140          MOVE   WS_REMIND/HI32 [...X]  <-  WS_QUOT/LOW32 [..X.]
	rem = (rem & ~0xff) | ((quot >> 8) & 0xff);
	//   008d: 03ba4140          MOVE   WS_REMIND/HI32 [.X..]  <-  WS_QUOT/LOW32 [X...]
	rem = (rem & ~(0xff << 16)) | ((quot >> 8) & (0xff << 16));
	//   0091: 0105800010f60100  MOVE   reg[0080]  [XXXX]  <-  0001f610
	aruba_write(rdev, TN_SMC_IND_INDEX_0, 0x0001f610);
	//   0099: 0300408100        MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[0081]  [XXXX]
	quot = aruba_read(rdev, TN_SMC_IND_DATA_0);
	//   009e: 698d41ffff        XOR    WS_REMIND/HI32 [XX..]  <-  ffff
	rem ^= 0xffff << 16;
	//   00a3: 095a4041          AND    WS_QUOT/LOW32 [.XX.]  <-  WS_REMIND/HI32 [XX..]
	quot = quot & ((rem >> 8) | 0xff0000ff);
	//   00a7: 0f4a4041          OR     WS_QUOT/LOW32 [.XX.]  <-  WS_REMIND/HI32 [..XX]
	quot = quot | ((rem << 8) & 0x00ffff00);
	//   00ab: 0102810040        MOVE   reg[0081]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	aruba_write(rdev, TN_SMC_IND_DATA_0, quot);

	//   003f: 3d250017          COMP   param[00]  [...X]  <-  17
	//   0043: 44b000            JUMP_Equal  00b0
}

static void smu_fuck_with_phy_clocks(struct radeon_device *rdev,
				     uint8_t par3, uint8_t clk_id,
				     uint8_t par1, uint8_t smu_msg)
{
	uint32_t smu_reg_idx, smu_data, smu_mask;

	/// FIXME: vvv scratch_register_shit vvv
	//   0009: 4a25cf0510        TEST   reg[05cf]  [...X]  <-  10
	//   000e: 441900            JUMP_Equal  0019
	if (aruba_read(rdev, 0x05cf << 2) & ATOM_S6_ACC_MODE) {
		//   0011: 4a25471804        TEST   reg[1847]  [...X]  <-  04
		//   0016: 492e00            JUMP_NotEqual  002e
		if (aruba_read(rdev, 0x1847 << 2) & 0x04)
			return;
	}

	switch (smu_msg) {
	case SMU_18:
		smu_18_special_access(rdev, par3, clk_id);
	case SMU_17:		/* Fall through */
		smu_reg_idx = 0x0001f478;
		smu_data = (par3 & 0xf) << 16;
		smu_data |= clk_id << 24;
		smu_data |= par1 << 0;
		smu_mask = 0xffff00ff;
		break;
	case SMU_22:
	case SMU_23:		/* Fall through */
		smu_reg_idx = 0x0001f478;
		smu_data = clk_id << 24;
		smu_mask = 0xff << 24;
		break;
	default:
		//   002e: 5b                EOT
		return;
	}
	aruba_write(rdev, TN_SMC_IND_INDEX_0, smu_reg_idx);
	if (smu_mask == 0xffffffff)
		aruba_write(rdev, TN_SMC_IND_DATA_0, smu_data);
	else
		aruba_mask(rdev, TN_SMC_IND_DATA_0, smu_mask, smu_data);

	fucking_smu_message(rdev, (1 << 8) | smu_msg);
}

#define INVALID 0xffff

static const uint16_t phy_dp_drive_params[] = {
		/* 0.4 */	/* 0.6 V */	/* 0.8 V */	/* 1.2 V */
/* 0.0 dB */	0x0055,		0x0040,		0x002a,		0x0000,
/* 3.5 dB */	0x1540,		0x2020,		0x2a00,		INVALID,
/* 6.0 dB */	0x2a2a,		0x4000,		INVALID,	INVALID,
/* 9.5 dB */	0x5500,		INVALID,	INVALID,	INVALID
};

static const uint16_t get_dp_drive_strength(uint8_t level)
{
	uint16_t strength;

	level &= 0xf;
	strength = phy_dp_drive_params[level];

	if (strength == INVALID) {
		DRM_ERROR("Invalid voltage level specified [%d][%d]",
			  level & 3, level >> 2);
		/*
		 * Caller doesn't check for return. Avoid giving invalid values,
		 * and default to weakest drive strength.
		 */
		strength = phy_dp_drive_params[0];
	}
	return strength;
}

/*
 * Some numnum decided that it was a good idea to not store pre-emphasis level
 * in bits[3:2], and voltage level in bits [1:0]. That would have made a perfect
 * index, and it's how we get the data back from the sink... but nooo, we have
 * to instead use long shifts with very long constant names. Well fuck that.
 * Convert the "set" to a proper index.
 */
static inline uint8_t set_to_idx(uint8_t set)
{
	uint8_t idx;

	/* Pre-emphasis level in bits [3:2] */
	idx = ((set & DP_TRAIN_PRE_EMPHASIS_MASK)
	       >> DP_TRAIN_PRE_EMPHASIS_SHIFT) << 2;
	/* Voltage swing level in bits [1:0] */
	idx |= (set & DP_TRAIN_VOLTAGE_SWING_MASK)
		>> DP_TRAIN_VOLTAGE_SWING_SHIFT;
	return idx;

}

static void aruba_pciep_mask(struct radeon_device *rdev, uint32_t pceipreg,
			      uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32;

	aruba_write_io(rdev, PCIEP_IDX, pceipreg);
	reg32 = aruba_read_io(rdev, PCIEP_DAT);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	aruba_write_io(rdev, PCIEP_DAT, reg32);
}

static void aruba_pciep_write(struct radeon_device *rdev, uint32_t pciepreg,
			      uint32_t val)
{
	aruba_write_io(rdev, PCIEP_IDX, pciepreg);
	aruba_write_io(rdev, PCIEP_DAT, val);
}

static void program_phy_drive_strength(struct radeon_device *rdev,
				       uint8_t id, const uint16_t strenght[4])
{
	/* FIXME: What determines how this base is computed. It seems random */
	//uint32_t base = (id & 1) ? 0x18818 : 0x18018;
	uint32_t base = (id & 1) ? 0x01226206 : 0x01226006;

	aruba_pciep_mask(rdev, base + 0 * 0x80, 0xffff, strenght[0]);
	aruba_pciep_mask(rdev, base + 1 * 0x80, 0xffff, strenght[1]);
	aruba_pciep_mask(rdev, base + 2 * 0x80, 0xffff, strenght[2]);
	aruba_pciep_mask(rdev, base + 3 * 0x80, 0xffff, strenght[3]);
}

/*
 * This 4-byte table replaces an ugly nested if block for an O(1) operation.
 * Pretty sleek, eh?
 */
static const uint8_t clk_src_id_to_par2_table[] = {
	[REFCLK_P0PLL] = 4,
	[REFCLK_P1PLL] = 1,
	[REFCLK_P2PLL] = 6,
	[REFCLK_EXT] = 6
};

void aruba_transmitter_enable(struct radeon_device *rdev,
			      struct DIG_TRANSMITTER_PARAMETERS *cfg)
{
	uint32_t regptr, rem, quot;
	const struct phy_par *phy = &phy_info[cfg->ucPhyId];
	uint8_t par3, par2, par1;
	uint32_t setbit = 0, sb2 = 0;
	uint16_t ppar[4];

	cfg->usSymClock /= 10;

	//   0052: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0056: MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	regptr = phy->reg_offset;
	//   005b: TEST   reg[1986]  [...X]  <-  01
	//   0060: JUMP_NotEqual  0664
	if (aruba_read(rdev, (0x1986 + regptr) << 2) & BIT(0)) {
		DRM_ERROR("Should have exited out, but here we are again");
		//return;
	}
	//   0063: CLEAR  WS_REGPTR [..XX]
	regptr = 0;
	//   0066: MOVE   param[02]  [XXXX]  <-  00000023
	par3 = par2 = par1 = 0;
	//   006d: MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   0072: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, 0, phy->city_17, 0, SMU_23);
	//   0074: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->ucConfig
	//   0078: AND    WS_REMIND/HI32 [...X]  <-  0c
	///rem = cfg->ucConfig & 0x0c;
	//   007c: MOVE   cfg->ucReserved  <-  04

	//par2 = 4;
	//   0080: COMP   WS_REMIND/HI32 [...X]  <-  08
	//   0084: JUMP_Equal  0096
	//if(cfg->asConfig.ucPhyClkSrcId != REFCLK_P0PLL) {
		//   0087: MOVE   cfg->ucReserved  <-  01
	//	par2 = 1;
		//   008b: COMP   WS_REMIND/HI32 [...X]  <-  00
		//   008f: JUMP_Equal  0096
	//	if (cfg->asConfig.ucPhyClkSrcId != REFCLK_P1PLL)
	//		//   0092: MOVE   cfg->ucReserved  <-  06
	//		par2 = 6;
	//}

	par2 = clk_src_id_to_par2_table[cfg->asConfig.ucPhyClkSrcId];
	//   0096: MOVE   WS_REMIND/HI32 [...X]  <-  data[0017] [...X]
	//   009b: AND    WS_REMIND/HI32 [...X]  <-  fe
	rem = phy->city_17 & 0xfe;
	//   009f: COMP   cfg->ucReserved  <-  WS_REMIND/HI32 [...X]
	//   00a3: JUMP_Equal  00a8
	if (par2 != (rem & 0xff))
		//   00a6: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_23);
	//   00a8: MOVE   param[02]  [XXXX]  <-  0f000618
	par3 = 0x0f; par2 = 0; par1 = 6;
	//   00af: COMP   cfg->usSymCloc  <-  d2f0
	//   00b4: JUMP_Below  00bb
	if (cfg->usSymClock >= 54000)
		//   00b7: OR     cfg->ucReserved1  <-  80
		par3 |= 0x80;
	//   00bb: MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   00c0: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_18);
	//   00c2: COMP   cfg->ucLaneNum  <-  04
	//   00c6: JUMP_BelowOrEq  00cf
	if (cfg->ucLaneNum > 4) {
		//   00c9: XOR    cfg->ucReserved  <-  01
		par1 ^= 1;
		//   00cd: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_18);
	}
	DRM_ERROR("\t/* may_the_enable_magic_begin */\n");
	//   00cf: MOVE   cfg->ucDigEncoderSel  <-  ucPhyId
	//   00d3: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = get_uniphy_reg_offset(0, cfg->ucPhyId);
	//   00d5: MOVE   reg[1c50]  [..X.]  <-  WS_FB_WIN [...X]
	aruba_mask(rdev, (0x1c50 + regptr) << 2, 0xff << 8, cfg->ucDigEncoderSel << 8);
	//   00da: MOVE   reg[1c50]  [.X..]  <-  cfg->ucDigMode
	aruba_mask(rdev, (0x1c50 + regptr) << 2, 0xff << 16, cfg->ucDigMode << 16);
	//   00df: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->ucConfig
	//   00e3: AND    WS_REMIND/HI32 [...X]  <-  70
	//   00e7: COMP   WS_REMIND/HI32 [...X]  <-  00
	//   00eb: JUMP_Equal  00f7
	//if (cfg->ucConfig & 0x70 == 0);
	if (cfg->asConfig.ucHPDSel != 0) {
		//   00ee: SUB    WS_REMIND/HI32 [...X]  <-  10
		//   00f2: MOVE   reg[1c50]  [X...]  <-  WS_REMIND/HI32 [...X]
		aruba_mask(rdev, (0x1c50 + regptr) << 2, 0xff << 24, (cfg->asConfig.ucHPDSel - 1) << (24 + 4));
	}
	//   00f7: COMP   cfg->ucDigMode  <-  05
	//   00fb: JUMP_Equal  011a
	//   00fe: COMP   cfg->ucDigMode  <-  00
	//   0102: JUMP_Equal  011a
	if ((cfg->ucDigMode != ATOM_TRANSMITTER_DIGMODE_V5_DP_MST)
		&& (cfg->ucDigMode != ATOM_TRANSMITTER_DIGMODE_V5_DP)) {
		//   0105: COMP   cfg->ucLaneNum  <-  04
		//   0109: JUMP_BelowOrEq  0111
		if (cfg->ucLaneNum > 4)
			//   010c: OR     reg[1c00]  [.X..]  <-  01
			aruba_mask(rdev, (0x1c00 + regptr) << 2, 0, 1 << 16);
		//   0111: MOVE   reg[1c8d]  [..XX]  <-  010f
		aruba_mask(rdev, (0x1c8d + regptr) << 2, 0xffff, 0x010f);
		//   0117: JUMP   013c
	} else {
		//   011a: MOVE   cfg->ucDigMode  <-  00
		cfg->ucDigMode = ATOM_TRANSMITTER_DIGMODE_V5_DP;
		//   011e: OR     cfg->ucConfig  <-  02
		cfg->asConfig.ucCoherentMode = 1;
		//   0122: MOVE   WS_SHIFT [...X]  <-  cfg->ucLaneNum
		//   0126: MOVE   WS_QUOT/LOW32 [XXXX]  <-  WS_OR_MASK [XXXX]
		quot = 1 << cfg->ucLaneNum;
		//   012a: SUB    WS_QUOT/LOW32 [...X]  <-  01
		quot--;
		//   012e: SUB    cfg->ucLaneNum  <-  01
		cfg->ucLaneNum--;
		//   0132: MOVE   reg[1cc2]  [...X]  <-  cfg->ucLaneNum
		aruba_mask(rdev, (0x1cc2 + regptr) << 2, 0xff, cfg->ucLaneNum);
		//   0137: MOVE   reg[1c8d]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
		aruba_mask(rdev, (0x1c8d + regptr) << 2, 0xffff, quot & 0xffff);
	}
	//   013c: TEST   reg[1c51]  [...X]  <-  01
	//   0141: JUMP_Equal  0150
	if (aruba_read(rdev, (0x1c51 + regptr) << 2) & BIT(0)) {
		//   0144: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		/* FIXME: just assuming WS_FB_WIN [XX..] has the pointer tp phy[i]; */
		phy = &phy_info[cfg->ucPhyId];
		//   0148: MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
		regptr = phy->reg_offset;
		//   014d: JUMP   04f0
		DRM_ERROR(" I should jump here, but fuck it for now\n");
		if (0)
			goto l_04f0;
	}
	//   0150: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	/* FIXME: just assuming WS_FB_WIN [XX..] has the pointer tp phy[i]; */
	phy = &phy_info[cfg->ucPhyId];
	//   0154: MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	regptr = phy->reg_offset;
	//   0159: CLEAR  WS_QUOT/LOW32 [XXXX]
	//   015c: MOVE   WS_QUOT/LOW32 [...X]  <-  data[0016] [...X]
	quot = phy->ext_disp_path_idx;
	//   0161: SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   0163: ADD    WS_DATAPTR [..XX]  <-  0188
	// dataptr = &IntegratedSystemInfo.EXT_DISPLAY_PATH[0]
	//   0168: MUL    WS_QUOT/LOW32 [..XX]  <-  0010
	//   016d: ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	// dataptr = &IntegratedSystemInfo.EXT_DISPLAY_PATH[phy->ext_disp_path_idx]
	//   0171: MOVE   WS_REMIND/HI32 [...X]  <-  data[000a] [...X]
	//   0176: MOVE   WS_QUOT/LOW32 [...X]  <-  data[000b] [...X]
	/* FIXME */ uint8_t ucChannelMapping = 0xe4;
	/* FIXME */ uint8_t ucChPNInvert = 0;
	uint32_t ch_map_reg;
	uint8_t ch_pn_invert;
	rem = ucChannelMapping;
	ch_pn_invert = quot = ucChPNInvert;
	//   017b: COMP   WS_REMIND/HI32 [...X]  <-  00
	//   017f: JUMP_Equal  01a0
	if (ucChannelMapping != 0) {
		//   0182: MOVE   WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
		//   0186: MOVE   WS_REMIND/HI32 [XX..]  <-  WS_REMIND/HI32 [..XX]
		//   018a: SHIFT_RIGHT  WS_REMIND/HI32 [X...]  by  06
		//   018e: SHIFT_RIGHT  WS_REMIND/HI32 [.X..]  by  04
		//   0192: SHIFT_RIGHT  WS_REMIND/HI32 [..X.]  by  02
		//   0196: AND    WS_REMIND/HI32 [XXXX]  <-  03030303
		////rem |= ((ucChannelMapping >> 0) & 3) << 0;
		////rem |= ((ucChannelMapping >> 2) & 3) << 8;
		////rem |= ((ucChannelMapping >> 4) & 3) << 16;
		////rem |= ((ucChannelMapping >> 6) & 3) << 24;
		ch_map_reg = rem = CH_MAP(ucChannelMapping >> 6, ucChannelMapping >> 4,
			     ucChannelMapping >> 2, ucChannelMapping >> 0);
		//   019d: JUMP   01ae
	} else {
		//   01a0: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
		//   01a4: MOVE   WS_REMIND/HI32 [XXXX]  <-  data[000c] [XXXX]
		ch_map_reg = rem = phy->default_ch_map;
		//   01a9: MOVE   WS_QUOT/LOW32 [...X]  <-  data[0014] [...X]
		ch_pn_invert = quot = phy->default_ch_pn_invert;
	}
	//   01ae: OR     reg[198a]  [...X]  <-  01
	aruba_mask(rdev, (0x198a + regptr) << 2, 0, BIT(0));
	//   01b3: MOVE   reg[198e]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	aruba_write(rdev, REG_ENC_CH_MAPPING + (regptr << 2), ch_map_reg);
	//   01b8: SHIFT_LEFT  WS_QUOT/LOW32 [...X]  by  04
	ch_pn_invert = quot <<= 4;
	//   01bc: MASK   reg[198d]  [..X.]  &  0f  |  WS_QUOT/LOW32 [...X]
	aruba_mask(rdev, (0x198d + regptr) << 2, 0xf0 << 8, ch_pn_invert << 8);
	//   01c2: AND    reg[198d]  [.X..]  <-  8c
	aruba_mask(rdev, (0x198d + regptr) << 2, 0x73 << 16, 0);
	//   01c7: COMP   WS_QUOT/LOW32 [...X]  <-  00
	//   01cb: JUMP_Equal  01d6
	if (ch_pn_invert != 0) {
		//   01ce: OR     reg[1987]  [..X.]  <-  20
		aruba_mask(rdev, (0x1987 + regptr) << 2, 0, BIT(13));
		//   01d3: JUMP   01db
	} else {
		//   01d6: AND    reg[1987]  [..X.]  <-  df
		aruba_mask(rdev, (0x1987 + regptr) << 2, BIT(13), 0);
	}
	//   01db: SET_REG_BLOCK  0000
	regptr = 0;		/* FIXME: are we sure? */
	//   01de: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   01e2: MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_phy_ctl_idx);
	//   01e8: SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   01eb: COMP   cfg->ucDigMode  <-  00
	//   01ef: JUMP_NotEqual  023e
	if (cfg->ucDigMode == ATOM_TRANSMITTER_DIGMODE_V5_DP) {
		/* Start with the weakest drive strength */
		ppar[0] = ppar[1] = ppar[2] = ppar[3] = get_dp_drive_strength(0);
	} else {
		//   023e: SET_DATA_BLOCK  ff  (this table)
		//   0240: ADD    WS_DATAPTR [..XX]  <-  092e
		//   0245: MOVE   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
		const struct non_dp_drive_param *x92ed = non_dp_drive_param_table;

		while (1) {
			if (x92ed->dig_mode == 0xff) {
				DRM_ERROR("Could not find drive parameters. farting...");
				return;
			}
			if (((1 << cfg->ucPhyId) & x92ed->phy_mask) &&
			    (cfg->ucDigMode == x92ed->dig_mode) &&
			    (cfg->usSymClock <= x92ed->sym_clk_max))
				break;
			x92ed++;
		}
		//   0271: TEST   ucPhyId  <-  01
		//   0275: JUMP_Equal  027f
		//   0278: COMP   cfg->ucLaneNum  <-  04
		//   027c: JUMP_BelowOrEq  029e
// 		if (!(cfg->ucPhyId & 1) || (cfg->ucLaneNum > 4)) {
// 		program_low();
// 		} else {
// 		program_high();
// 		}

		ppar[0] = x92ed->lane0;
		ppar[1] = x92ed->lane1;
		ppar[2] = x92ed->lane2;
		ppar[3] = x92ed->lane3;
	}

	program_phy_drive_strength(rdev, cfg->ucPhyId, ppar);

	//   02b6: CLEAR  WS_REMIND/HI32 [..XX]
	//   02b9: COMP   cfg->ucLaneNum  <-  04
	//   02bd: JUMP_BelowOrEq  02c5
	if (cfg->ucLaneNum > 4) {
		//   02c0: MOVE   WS_REMIND/HI32 [..XX]  <-  0180
		setbit = BIT(31);
		sb2 = BIT(24);
	}
	//   02c5: MASK   reg[6005]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226005, BIT(31), setbit);
	//   02cb: MASK   reg[6085]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226085, BIT(31), setbit);
	//   02d1: MASK   reg[6105]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226105, BIT(31), setbit);
	//   02d7: MASK   reg[6185]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226185, BIT(31), setbit);
	//   02dd: MASK   reg[6205]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226205, BIT(31), setbit);
	//   02e3: MASK   reg[6285]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226285, BIT(31), setbit);
	//   02e9: MASK   reg[6305]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226305, BIT(31), setbit);
	//   02ef: MASK   reg[6385]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	aruba_pciep_mask(rdev, 0x1226385, BIT(31), setbit);

	//   02f5: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   02f8: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   02fc: MOVE   reg[0038]  [XXXX]  <-  data[0004] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_idx_4);
	//   0302: MASK   reg[0039]  [.X..]  &  fe  |  WS_REMIND/HI32 [..X.]
	aruba_mask(rdev, PCIEP_DAT, BIT(24), sb2);
	//   0308: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   030c: CLEAR  WS_REGPTR [..XX]
	regptr = 0;
	//   030f: AND    cfg->ucConfig  <-  fe
	cfg->ucConfig &= ~BIT(0);
	//   0313: TEST   cfg->ucConfig  <-  02
	//   0317: JUMP_Equal  0335
	if (cfg->asConfig.ucCoherentMode) {
		//   031a: MOVE   WS_REMIND/HI32 [...X]  <-  02
		rem = 2;
		//   031e: COMP   cfg->ucDigMode  <-  00
		//   0322: JUMP_Equal  0329
		if (cfg->ucDigMode != ATOM_TRANSMITTER_DIGMODE_V5_DP)
			//   0325: MOVE   WS_REMIND/HI32 [...X]  <-  01
			rem = 0;
		//   0329: TEST   reg[1847]  [...X]  <-  WS_REMIND/HI32 [...X]
		//   032e: JUMP_Equal  0335
		if (aruba_read(rdev, 0x1847 << 2) & rem)
			//   0331: OR     cfg->ucConfig  <-  01
			cfg->ucConfig |= BIT(0);
	}
	//   0335: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0339: MOVE   WS_REMIND/HI32 [..X.]  <-  data[0015] [...X]
	rem = phy->magic_15 << 8;
	//   033e: SET_DATA_BLOCK  ff  (this table)
	//   0340: ADD    WS_DATAPTR [..XX]  <-  0916
	//   0345: CLEAR  WS_QUOT/LOW32 [XXXX]
	//   0348: MOVE   WS_QUOT/LOW32 [...X]  <-  cfg->ucConfig
	//   034c: AND    WS_QUOT/LOW32 [...X]  <-  0c
	//   0350: SHIFT_LEFT  WS_QUOT/LOW32 [...X]  by  01
	////quot = (cfg->ucConfig & 0x0c) << 1; //ucPhyClkSrcId << (1 + 2);
	//   0354: ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	const struct clk_src_params* x916d = &clk_src_param_table[cfg->asConfig.ucPhyClkSrcId];
	//   0358: MOVE   WS_REGPTR [..XX]  <-  data[0004] [..XX]
	regptr = x916d->reg_offset;
	//   035d: MOVE   WS_REMIND/HI32 [...X]  <-  data[0006] [...X]
	rem = (rem & ~0xff) | x916d->smells_like_a_bitmask;
	//   0362: MOVE   WS_QUOT/LOW32 [...X]  <-  cfg->ucConfig
	//   0366: AND    WS_QUOT/LOW32 [...X]  <-  03
	quot = cfg->ucConfig & 0x03;
	//   036a: COMP   WS_QUOT/LOW32 [...X]  <-  03
	//   036e: JUMP_Equal  0380
	if (quot != 3) {
		//   0371: OR     WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
		rem |= (rem & 0xff) << 8;

		//   0375: TEST   WS_QUOT/LOW32 [...X]  <-  02
		//   0379: JUMP_Equal  0380
		if (quot & ATOM_TRANSMITTER_CONFIG_V5_COHERENT)
			//   037c: MOVE   WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
			rem =
			    x916d->smells_like_a_bitmask | (x916d->
							    smells_like_a_bitmask
							    << 8);
	}
	//   0380: MOVE   reg[1706]  [...X]  <-  WS_REMIND/HI32 [..X.]
	aruba_mask(rdev, (0x1706 + regptr) << 2, 0xff, (rem >> 8) & 0xff);
	//   0385: SET_REG_BLOCK  0000
	regptr = 0;		/* FIXME: Of cpurse we're not sure it's what it means */
	//   0388: TEST   cfg->ucConfig  <-  01
	//   038c: JUMP_NotEqual  03e0
	if (!(cfg->ucConfig & BIT(0))) {
		//   038f: MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
		aruba_write(rdev, PCIEP_IDX, x916d->pciep_reg_idx);
		//   0395: MOVE   WS_REMIND/HI32 [...X]  <-  data[0007] [...X]
		rem = (rem & ~0xff) | x916d->d7;
		//   039a: SET_DATA_BLOCK  ff  (this table)
		//   039c: ADD    WS_DATAPTR [..XX]  <-  0960
		const struct x960_data *x960d = x960_non_dp_table;
		//   03a1: COMP   cfg->ucDigMode  <-  00
		//   03a5: JUMP_NotEqual  03ad
		if (cfg->ucDigMode == ATOM_TRANSMITTER_DIGMODE_V5_DP)
			//   03a8: ADD    WS_DATAPTR [..XX]  <-  0024
			x960d = x960_dp_table;

		do {
			//   03ad: MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0002] [..XX]
			quot = x960d->d2;
			//   03b2: COMP   cfg->usSymCloc  <-  data[0000] [..XX]
			//   03b7: JUMP_BelowOrEq  03c2
			if (cfg->usSymClock <= x960d->max_sym_clk)
				break;
			//   03ba: ADD    WS_DATAPTR [..XX]  <-  0004
			x960d++;
			//   03bf: JUMP   03ad
		} while (1);

		//   03c2: OR     WS_QUOT/LOW32 [..X.]  <-  WS_REMIND/HI32 [...X]
		quot |= rem & 0xff;
		//   03c6: SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
		//   03c9: MOVE   reg[2005]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
		aruba_pciep_mask(rdev, 0x1222005, 0xffff, quot);
		//   03ce: OR     reg[2008]  [...X]  <-  01
		aruba_pciep_mask(rdev, 0x1222000, 0, BIT(0));
		//   03d3: AND    reg[2008]  [...X]  <-  fe
		aruba_pciep_mask(rdev, 0x1222000, BIT(0), 0);
		//   03d8: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
		//   03db: MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[0038]  [XXXX]
		quot = aruba_read(rdev, PCIEP_IDX);
	}
	//   03e0: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   03e3: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   03e7: MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_idx_8);

	//   03ed: COMP   cfg->ucDigMode  <-  00
	//   03f1: JUMP_NotEqual  0404
	//   03f4: COMP   cfg->usSymCloc  <-  d2f0
	//   03f9: JUMP_Below  0404
	if (!cfg->ucDigMode == ATOM_TRANSMITTER_DIGMODE_V5_DP && cfg->usSymClock >= 54000)
		//   03fc: OR     reg[0039]  [...X]  <-  50
		aruba_mask(rdev, PCIEP_DAT, 0, 0x50);
		//   0401: JUMP   0409
	else
		//   0404: AND    reg[0039]  [...X]  <-  af
		aruba_mask(rdev, PCIEP_DAT, 0x50, 0);

	//   0409: CLEAR  WS_REMIND/HI32 [XXXX]
	rem = 0;
	//   040c: TEST   cfg->ucConfig  <-  01
	//   0410: JUMP_NotEqual  0417
	if (!(cfg->ucConfig & BIT(0)))
		//   0413: OR     WS_REMIND/HI32 [X...]  <-  10
		rem |= 0x18;
	//   0417: TEST   cfg->ucConfig  <-  04
	//   041b: JUMP_NotEqual  0429
	//   041e: TEST   cfg->ucConfig  <-  08
	//   0422: JUMP_NotEqual  0429
	if (!(cfg->ucConfig & ATOM_TRANSMITTER_CONFIG_V5_P2PLL)
	    && !(cfg->ucConfig & ATOM_TRANSMITTER_CONFIG_V5_P0PLL))
		//   0425: OR     WS_REMIND/HI32 [X...]  <-  02
		rem |= 0x02;
	//   0429: COMP   cfg->ucLaneNum  <-  04
	//   042d: JUMP_BelowOrEq  0434
	if (cfg->ucLaneNum > 4)
		//   0430: OR     WS_REMIND/HI32 [.X..]  <-  10
		rem |= 0x10;

	//   0434: MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_phy_ctl_idx);
	//   043a: SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   043d: COMP   cfg->ucLaneNum  <-  04
	//   0441: JUMP_Above  044b
	if (cfg->ucLaneNum <= 4) {
		//   0444: TEST   ucPhyId  <-  01
		//   0448: JUMP_NotEqual  0457
		if (cfg->ucPhyId & 1)
			goto l_clusterfuck;
	}
	//   044b: MOVE   reg[0009]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	aruba_pciep_write(rdev, 0x1220009, rem);
	//   0450: COMP   cfg->ucLaneNum  <-  04
	//   0454: JUMP_BelowOrEq  045c
	if (cfg->ucLaneNum > 4)
		//   0457: MOVE   reg[000a]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
 l_clusterfuck:
		aruba_pciep_write(rdev, 0x122000a, rem);

	//   045c: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   045f: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0463: MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	regptr = phy->reg_offset;
	//   0468: TEST   cfg->ucConfig  <-  02
	//   046c: JUMP_NotEqual  0477
	if (!(cfg->ucConfig & BIT(1)))
		//   046f: AND    reg[1987]  [...X]  <-  fc
		aruba_mask(rdev, (0x1987 + regptr) << 2, 0x03, 0);
		//   0474: JUMP   047d
	else
		//   0477: MASK   reg[1987]  [...X]  &  fc  |  02
		aruba_mask(rdev, (0x1987 + regptr) << 2, 0x03, 0x02);
	//   047d: OR     reg[1986]  [...X]  <-  01
	aruba_mask(rdev, (0x1986 + regptr) << 2, 0, 0x01);

	//   0482: SET_REG_BLOCK  0000
	regptr = 0;
	//   0485: MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_idx_8);
	//   048b: TEST   reg[0039]  [...X]  <-  04
	//   0490: JUMP_Equal  048b
	int timeout = 1000;
	while (!(aruba_read(rdev, PCIEP_DAT) & BIT(2))) {
		if (--timeout == 0) {
			DRM_DEBUG_KMS("Timed out waiting for magic event\n");
			break;
		}
		usleep(100);
	}
	//   0493: TEST   cfg->ucConfig  <-  01
	//   0497: JUMP_NotEqual  04c7
	if (!(cfg->ucConfig & BIT(0))) {
		//   049a: MOVE   reg[0038]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
		aruba_write(rdev, PCIEP_DAT, quot);
		//   049f: SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
		//   04a2: AND    reg[2002]  [X...]  <-  f7
		aruba_pciep_mask(rdev, 0x1222002, 0x80 << 24, 0);
		//   04a7: OR     reg[2008]  [...X]  <-  01
		aruba_pciep_mask(rdev, 0x1222008, 0, 1);
		//   04ac: AND    reg[2008]  [...X]  <-  fe
		aruba_pciep_mask(rdev, 0x1222008, 1, 0);
		//   04b1: OR     reg[2002]  [X...]  <-  08
		aruba_pciep_mask(rdev, 0x1222002, 0, 0x80 << 24);
		//   04b6: OR     reg[2008]  [...X]  <-  01
		aruba_pciep_mask(rdev, 0x1222008, 0, 1);
		//   04bb: AND    reg[2008]  [...X]  <-  fe
		aruba_pciep_mask(rdev, 0x1222008, 1, 0);
		//   04c0: DELAY_MicroSec  fa
		//   04c2: DELAY_MicroSec  fa
		radeon_udelay(500 * 1000);
		//   04c4: SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	}
	//   04c7: CLEAR  WS_REGPTR [..XX]
	//   04ca: MOVE   WS_REGPTR [...X]  <-  ucPhyId
	regptr = cfg->ucPhyId;
	//   04ce: OR     reg[0160]  [...X]  <-  01
	aruba_mask(rdev, (0x0160 + regptr) << 2, 0, 1);
	//   04d3: MOVE   cfg->ucDigEncoderSel  <-  ucPhyId
	//   04d7: CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	regptr = get_uniphy_reg_offset(0, cfg->ucPhyId);
	//   04d9: OR     reg[1c51]  [...X]  <-  01
	aruba_mask(rdev, (0x1c51 + regptr) << 2, 0, 1);
	//   04de: DELAY_MicroSec  0a
	usleep(10000);
	//   04e0: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   04e4: MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	regptr = phy->reg_offset;
	//   04e9: OR     reg[198d]  [...X]  <-  01
	aruba_mask(rdev, (0x198d + regptr) << 2, 0, 1);
	//   04ee: DELAY_MicroSec  0a
	usleep(10000);
 l_04f0:
	//   04f0: OR     reg[198a]  [..X.]  <-  10
	aruba_mask(rdev, (0x198a + regptr) << 2, 0, 0x10 << 8);
	//   04f5: SET_REG_BLOCK  0000
	regptr = 0;
	//   04f8: MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   04fc: MOVE   param[02]  [XXXX]  <-  0f000117
	par3 = 0x0f; par2 = 0; par1 = 1;
	//   0503: MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   0508: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_17);
	//   050a: COMP   cfg->ucLaneNum  <-  04
	//   050e: JUMP_BelowOrEq  0517
	if (cfg->ucLaneNum > 4) {
		//   0511: XOR    cfg->ucReserved  <-  01
		par2 ^= 1;
		//   0515: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
		fprintf(stderr, "MOTHERFUCKER!!!!\n");
		smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_17);
	}
	//   0517: MOVE   param[02]  [XXXX]  <-  00000022
	par3 = 0; par2 = 0; par1 = 0;
	//   051e: MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   0523: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_22);
	//   0525: MOVE   param[02]  [XXXX]  <-  00000022
	par3 = 0; par2 = 0; par1 = 0;
	//   052c: MOVE   WS_REMIND/HI32 [...X]  <-  cfg->ucConfig
	//   0530: AND    WS_REMIND/HI32 [...X]  <-  0c
	////rem = cfg->ucConfig & 0x0c;
	//   0534: MOVE   cfg->ucReserved  <-  04
	par2 = clk_src_id_to_par2_table[cfg->asConfig.ucPhyClkSrcId];
	//   054e: MOVE   WS_REMIND/HI32 [...X]  <-  data[0017] [...X]
	//   0553: AND    WS_REMIND/HI32 [...X]  <-  fe
	//   0557: COMP   cfg->ucReserved  <-  WS_REMIND/HI32 [...X]
	//   055b: JUMP_Equal  0664
	if (par2 == (phy->city_17 & 0xfe))
		return;
	//   055e: CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_22);
	//   0560: JUMP   0664
	return;
}

void aruba_transmitter_vsemph(struct radeon_device *rdev, uint8_t phy_id,
			      uint8_t lane_sel)
{
	const struct phy_par *phy = &phy_info[phy_id];

	uint8_t par3, par2, par1;
	uint16_t strength[4];
	uint32_t quot;

	lane_sel = set_to_idx(lane_sel);
	//   0693: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
	par3 = par2 = par1 = 0;
	//   069a: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   069f: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_23);
	//   06a1: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
	//   06a4: 0324401600        MOVE   WS_QUOT/LOW32 [...X]  <-  data[0016] [...X]
	quot = phy->ext_disp_path_idx;
	//   06a9: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   06ab: 2d0d428801        ADD    WS_DATAPTR [..XX]  <-  0188
	//   06b0: 210d401000        MUL    WS_QUOT/LOW32 [..XX]  <-  0010
	//// EXT_DISPLAY_PATH sPath[phy->ext_disp_path_idx]
	//   06b5: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   06b9: 0324400c00        MOVE   WS_QUOT/LOW32 [...X]  <-  data[000c] [...X]
	quot = 0xe4;		// What do you know? This is the channel mapping!!!
	//   06be: 3e254002          COMP   WS_QUOT/LOW32 [...X]  <-  02
	//   06c2: 49cc06            JUMP_NotEqual  06cc
	if (quot == 0x02) {
		//   06c5: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
		//   06c7: 036446fc01        MOVE   WS_FB_WIN [..X.]  <-  data[01fc] [...X]
		lane_sel = 0;
	}
	//   06cc: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   06d0: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	aruba_write(rdev, PCIEP_IDX, phy->pciep_phy_ctl_idx);
	//   06d6: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   06d8: 0965461b          AND    WS_FB_WIN [..X.]  <-  1b
	//lane_sel &= 0x1b;
	//   06dc: 2d0d429009        ADD    WS_DATAPTR [..XX]  <-  0990
	////link = &link_data[0];
	//   06e1: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
	//   06e5: 03a24044          MOVE   WS_QUOT/LOW32 [.X..]  <-  WS_OR_MASK [...X]

	//   071e: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   0721: 4ba50001          TEST   ucPhyId  <-  01
	//   0725: 494307            JUMP_NotEqual  0743
	strength[0] = strength[1] = strength[2] = strength[3] = get_dp_drive_strength(lane_sel);
	program_phy_drive_strength(rdev, phy_id, strength);

	//   075b: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   075e: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0762: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
	par3 = par2 = par1 = 0;
	//   0769: 02a4021700        MOVE   cfg->ucReserved  <-  data[0017] [...X]
	par2 = phy->city_17;
	//   076e: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	smu_fuck_with_phy_clocks(rdev, par3, par2, par1, SMU_22);
	//   0770: 436406            JUMP   0664
	return;
}
