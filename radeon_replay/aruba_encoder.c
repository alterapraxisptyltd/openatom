#include "radeon_util.h"
#include "ObjectID.h"

// command_table  0000ec64  #4c  (DIG1TransmitterControl/UNIPHYTransmitterControl):
//
//   Size         0a52
//   Format Rev.  01
//   Param Rev.   00
//   Content Rev. 05
//   Attributes:  Work space size        00 longs
//                Parameter space size   02 longs
//                Table update indicator 0

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

typedef struct ATOM_DIG_TRANSMITTER_CONFIG_V5
{
	UCHAR ucReserved:1;
	UCHAR ucCoherentMode:1;
	UCHAR ucPhyClkSrcId:2;
	UCHAR ucHPDSel:3;
	UCHAR ucReservd1:1;
};

struct DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5
{
	USHORT usSymClock;                    // Encoder Clock in 10kHz,(DP mode)= linkclock/10, (TMDS/LVDS/HDMI)= pixel clock,  (HDMI deep color), =pixel clock * deep_color_ratio
	UCHAR  ucPhyId;                   // 0=UNIPHYA, 1=UNIPHYB, 2=UNIPHYC, 3=UNIPHYD, 4= UNIPHYE 5=UNIPHYF
	UCHAR  ucAction;                                  // define as ATOM_TRANSMITER_ACTION_xxx

	UCHAR  ucLaneNum;                 // indicate lane number 1-8
	UCHAR  ucConnObjId;               // Connector Object Id defined in ObjectId.h
	UCHAR  ucDigMode;                 // indicate DIG mode
	union{
		ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
		UCHAR ucConfig;
	};

	UCHAR  ucDigEncoderSel;           // indicate DIG front end encoder
	UCHAR  ucDPLaneSet;
	UCHAR  ucReserved;
	UCHAR  ucReserved1;
};

//ucPhyId
#define ATOM_PHY_ID_UNIPHYA                                 0
#define ATOM_PHY_ID_UNIPHYB                                 1
#define ATOM_PHY_ID_UNIPHYC                                 2
#define ATOM_PHY_ID_UNIPHYD                                 3
#define ATOM_PHY_ID_UNIPHYE                                 4
#define ATOM_PHY_ID_UNIPHYF                                 5
#define ATOM_PHY_ID_UNIPHYG                                 6

// ucDigEncoderSel
#define ATOM_TRANMSITTER_V5__DIGA_SEL                       0x01
#define ATOM_TRANMSITTER_V5__DIGB_SEL                       0x02
#define ATOM_TRANMSITTER_V5__DIGC_SEL                       0x04
#define ATOM_TRANMSITTER_V5__DIGD_SEL                       0x08
#define ATOM_TRANMSITTER_V5__DIGE_SEL                       0x10
#define ATOM_TRANMSITTER_V5__DIGF_SEL                       0x20
#define ATOM_TRANMSITTER_V5__DIGG_SEL                       0x40

// ucDigMode
#define ATOM_TRANSMITTER_DIGMODE_V5_DP                      0
#define ATOM_TRANSMITTER_DIGMODE_V5_LVDS                    1
#define ATOM_TRANSMITTER_DIGMODE_V5_DVI                     2
#define ATOM_TRANSMITTER_DIGMODE_V5_HDMI                    3
#define ATOM_TRANSMITTER_DIGMODE_V5_SDVO                    4
#define ATOM_TRANSMITTER_DIGMODE_V5_DP_MST                  5

// ucDPLaneSet
#define DP_LANE_SET__0DB_0_4V                               0x00
#define DP_LANE_SET__0DB_0_6V                               0x01
#define DP_LANE_SET__0DB_0_8V                               0x02
#define DP_LANE_SET__0DB_1_2V                               0x03
#define DP_LANE_SET__3_5DB_0_4V                             0x08
#define DP_LANE_SET__3_5DB_0_6V                             0x09
#define DP_LANE_SET__3_5DB_0_8V                             0x0a
#define DP_LANE_SET__6DB_0_4V                               0x10
#define DP_LANE_SET__6DB_0_6V                               0x11
#define DP_LANE_SET__9_5DB_0_4V                             0x18

// ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
// Bit1
#define ATOM_TRANSMITTER_CONFIG_V5_COHERENT                                       0x02

// Bit3:2
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_MASK              0x0c
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SEL_SHIFT                 0x02

#define ATOM_TRANSMITTER_CONFIG_V5_P1PLL                                0x00
#define ATOM_TRANSMITTER_CONFIG_V5_P2PLL                                0x04
#define ATOM_TRANSMITTER_CONFIG_V5_P0PLL                                0x08
#define ATOM_TRANSMITTER_CONFIG_V5_REFCLK_SRC_EXT           0x0c
// Bit6:4
#define ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_MASK                   0x70
#define ATOM_TRANSMITTER_CONFIG_V5_HPD_SEL_SHIFT                      0x04

#define ATOM_TRANSMITTER_CONFIG_V5_NO_HPD_SEL                                   0x00
#define ATOM_TRANSMITTER_CONFIG_V5_HPD1_SEL                                       0x10
#define ATOM_TRANSMITTER_CONFIG_V5_HPD2_SEL                                       0x20
#define ATOM_TRANSMITTER_CONFIG_V5_HPD3_SEL                                       0x30
#define ATOM_TRANSMITTER_CONFIG_V5_HPD4_SEL                                       0x40
#define ATOM_TRANSMITTER_CONFIG_V5_HPD5_SEL                                       0x50
#define ATOM_TRANSMITTER_CONFIG_V5_HPD6_SEL                                       0x60

#define DIG_TRANSMITTER_CONTROL_PS_ALLOCATION_V1_5            DIG_TRANSMITTER_CONTROL_PARAMETERS_V1_5

static void aruba_encoder_init(uint8_t ucConnObjId)
{
	//   0668: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   066b: 010d1b199f0f      MOVE   reg[191b]  [..XX]  <-  0f9f
	radeon_reg_mask(0x191b, 0xffff, 0x0f9f);
	//   0671: 3d650114          COMP   param[01]  [..X.]  <-  14
	//   0675: 496406            JUMP_NotEqual  0664
	if (ucConnObjId != CONNECTOR_OBJECT_ID_eDP)
		return;
	//   0678: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   067a: 01051c1901000078  MOVE   reg[191c]  [XXXX]  <-  78000001
	radeon_reg_write(0x191c, 0x78000001);
	//   0682: 01251d197d        MOVE   reg[191d]  [...X]  <-  7d
	radeon_reg_mask(0x191d, 0xff, 0x74);
	//   0687: 014c1d193900      MOVE   reg[191d]  [.XX.]  <-  data[0039] [..XX] // UNKNOW == 0x0303
	//// FIXME FUXME FEXME TODO
	radeon_reg_mask(0x191d, 0xffff << 8; 0x0303 << 8);
	//   068d: 0de5191902        OR     reg[1919]  [X...]  <-  02
	radeon_reg_mask(0x1919, 0, 0x02 << 24);
	//   0692: 5b                EOT
}

void aruba_brightness_control(void)
{
	uint16_t rem;
	uint32_t quot, win;
	//   07d9: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   07db: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   07de: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	/// FIXME
	rem = 0x00c8;
	//   07e3: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   07e8: 446808            JUMP_Equal  0868
	if (rem == 0)
		return;
	//   07eb: 4aa59c0101        TEST   reg[019c]  [.X..]  <-  01
	//   07f0: 49f807            JUMP_NotEqual  07f8
	if (((radeon_reg_read(0x019c) >> 16) & 0xff) != 0x01)
		//   07f3: 0d25211901        OR     reg[1921]  [...X]  <-  01
		radeon_reg_mask(0x1921, 0, 0x01);

	//   07f8: 03054640787d01    MOVE   WS_FB_WIN [XXXX]  <-  017d7840
	win = 0x017d7840;
	//   07ff: 210541ff0f0000    MUL    WS_REMIND/HI32 [XXXX]  <-  00000fff
	quot = rem * 0xfff;
	//   0806: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	quot = win / quot;
	rem = win & quot;
	//   080a: 3e054100000000    COMP   WS_REMIND/HI32 [XXXX]  <-  00000000
	//   0811: 441908            JUMP_Equal  0819
	if (rem != 0)
		//   0814: 2d0d400100        ADD    WS_QUOT/LOW32 [..XX]  <-  0001
		quot++;
	//   0819: 018a1b1940        MOVE   reg[191b]  [XX..]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x191b, 0xffff << 16, quot << 16);
	//   081e: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0821: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	/* FIXME */
	rem = 0x00c8;
	//   0826: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	quot *= rem;
	//   082a: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	quot = win / quot;
	rem = win % quot;
	//   082e: 01a520190c        MOVE   reg[1920]  [.X..]  <-  0c
	radeon_reg_mask(0x1920, 0xff << 16, 0x0c << 16);
	//   0833: 010a201940        MOVE   reg[1920]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x1920, 0xffff, quot & 0xffff);
	//   0838: 15054004          SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  04
	quot <<= 4l
	//   083c: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   083f: 032841cb05        MOVE   WS_REMIND/HI32 [...X]  <-  reg[05cb]  [..X.]
	rem = (radeon_reg_read(0x05cb) >> 8) & 0xff;
	//   0844: 2d0d410100        ADD    WS_REMIND/HI32 [..XX]  <-  0001
	rem++;
	//   0849: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	quot = quot * rem;
	//   084d: 1b054008          SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  08
	quot >>= 8;
	//   0851: 010a1e1940        MOVE   reg[191e]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	radeon_reg_mask(0x191e, 0xffff, quot & 0xffff);
	//   0856: 0de51e19c0        OR     reg[191e]  [X...]  <-  c0
	radeon_reg_mask(0x191e, 0, 0xc0 << 24);
	//   085b: 07252119fe        AND    reg[1921]  [...X]  <-  fe
	radeon_reg_mask(0x1921, ~0xfffffffe, 0);
	//   0860: 4a65211901        TEST   reg[1921]  [..X.]  <-  01
	//   0865: 496008            JUMP_NotEqual  0860
	while (((radeon_reg_read(0x1921) >> 8) & 0xff) != 0x01);
	//   0868: 5b                EOT
}

static void aruba_lcd_blon(void)
{
	//   0773: 4ae5191901        TEST   reg[1919]  [X...]  <-  01
	//   0778: 496406            JUMP_NotEqual  0664
	if ((radeon_reg_read(0x1919) >> 24) != 0x01)
		return;
	//   077b: 5032              DELAY_MilliSec  32
	radeon_udelay(0x32 * 1000);
	//   077d: 3c651d1900        COMP   reg[191d]  [..X.]  <-  00
	//   0782: 449707            JUMP_Equal  0797
	if (((radeon_reg_read(0x191d) >> 8) & 0xff) == 0) {
		//   0797: 0de5191903        OR     reg[1919]  [X...]  <-  03
		radeon_reg_mask(0x191d, 0, 0x03 << 24);
		//   079c: 5b                EOT
		return;
	}
	//   0785: 0da5401901        OR     reg[1940]  [.X..]  <-  01
	radeon_reg_mask(0x1940, 0, 0x01 << 16);
	//   078a: 0de5191903        OR     reg[1919]  [X...]  <-  03
	radeon_reg_mask(0x1919, 0, 0x03 << 24);
	//   078f: 5004              DELAY_MilliSec  04
	radeon_udelay(0x04 * 1000);
	//   0791: 07a54019fe        AND    reg[1940]  [.X..]  <-  fe
	radeon_reg_mask(0x1940, ~0xfffeffff, 0);
	//   0796: 5b                EOT

}

static void aruba_lcd_bloff(void)
{
	//   079d: 4ae5191901        TEST   reg[1919]  [X...]  <-  01
	//   07a2: 446406            JUMP_Equal  0664
	if ((radeon_reg_read(0x1919) >> 24) == 0x01)
		return;
	//   07a5: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   07a7: 0324414200        MOVE   WS_REMIND/HI32 [...X]  <-  data[0042] [...X]
	//// FIXME
	rem = 0;
	//   07ac: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   07b0: 496406            JUMP_NotEqual  0664
	if (rem != 0)
		return;
	//   07b3: 3c651d1900        COMP   reg[191d]  [..X.]  <-  00
	//   07b8: 44d007            JUMP_Equal  07d0
	if (((radeon_reg_read(0x191d) >> 8) & 0xff) != 0) {
		//   07bb: 0da5401901        OR     reg[1940]  [.X..]  <-  01
		radeon_reg_mask(0x1940, 0, 0x01 << 16);
		//   07c0: 5004              DELAY_MilliSec  04
		radeon_udelay(0x04 * 1000);
		//   07c2: 5ce51919fe02      MASK   reg[1919]  [X...]  &  fe  |  02
		radeon_reg_mask(0x1919, ~0xfeffffff, 0x02 << 24);
		//   07c8: 07a54019fe        AND    reg[1940]  [.X..]  <-  fe
		radeon_reg_mask(0x1940, ~0xfffeffff, 0;);
		//   07cd: 43d607            JUMP   07d6
	} else {
		//   07d0: 5ce51919fe02      MASK   reg[1919]  [X...]  &  fe  |  02
		radeon_reg_mask(0x1919, ~0xfeffffff << 24, 0x02 << 24);
	}
	//   07d6: 5001              DELAY_MilliSec  01
	radeon_udelay(1000);
	//   07d8: 5b                EOT
}

void shitmapants(void)
{
	uint8_t ldat[] = {
		/* PHY 0 */
		0x02, 0x20, 0x23, 0x01, 0x11, 0x00, 0x13, 0x01,
		0x48, 0x80, 0x33, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x02, 0x06,
		/* PHY 1 */
		0x02, 0x20, 0x21, 0x01, 0x11, 0x00, 0x11, 0x01,
		0x49, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x10, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x01,
		/* PHY 2 */
		0x02, 0x20, 0x21, 0x02, 0x11, 0x00, 0x11, 0x02,
		0x4a, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x20, 0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x02,
		/* PHY 3 */
		0x02, 0x20, 0x21, 0x02, 0x11, 0x00, 0x11, 0x02,
		0x4b, 0x80, 0x31, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x30, 0x00, 0x00, 0x00, 0x00, 0x08, 0x05, 0x03,
		/* PHY 4 */
		0x02, 0x20, 0x22, 0x01, 0x11, 0x00, 0x12, 0x01,
		0x4c, 0x80, 0x32, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x40, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x04,
		/* PHY 5 */
		0x02, 0x20, 0x22, 0x01, 0x11, 0x00, 0x12, 0x01,
		0x4d, 0x80, 0x32, 0x01, 0x00, 0x01, 0x02, 0x03,
		0x50, 0x00, 0x00, 0x00, 0x00, 0x10, 0x01, 0x05,
		/* Something else */
		0x05, 0x20, 0x21, 0x01, 0x10, 0x00, 0x02, 0x60,
		0x05, 0x20, 0x23, 0x01, 0x20, 0x00, 0x08, 0x40,
		0x05, 0x20, 0x22, 0x01, 0x00, 0x00, 0x10, 0x40,
		0x0c, 0x00, 0xff, 0xff, 0x02, 0x0e, 0x00, 0x0b,
		0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b, 0xff, 0xff,
		0x02, 0x31, 0x00, 0x0b, 0x00, 0x0b, 0x00, 0x0b,
		0x00, 0x0b, 0xff, 0xff, 0x03,
		0x0e, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x00,
		0x2a, 0xff, 0xff, 0x03, 0x31, 0x00, 0x0b, 0x00,
		0x0b, 0x00, 0x0b, 0x00, 0x0b, 0x35, 0x0c, 0x00,
		0x06, 0x1d, 0x10, 0x01, 0x06, 0x88, 0x13, 0x02,
		0x06, 0x6a, 0x18, 0x03, 0x06, 0xbd, 0x1f, 0x04,
		0x06, 0x10, 0x27, 0x05, 0x06, 0xd4, 0x30, 0x06,
		0x06, 0x74, 0x40, 0x07, 0x06, 0xff, 0xff, 0x08,
		0x06, 0x68, 0x42, 0x00, 0x04, 0x78, 0x69, 0x02,
		0x04, 0xff, 0xff, 0x01, 0x04, 0x0e, 0x00, 0x09,
		0x00, 0x61, 0x00, 0x00, 0x55, 0x00, 0x55, 0x00,
		0x55, 0x00, 0x55, 0x00, 0x01, 0x40, 0x00, 0x40,
		0x00, 0x40, 0x00, 0x40, 0x00, 0x02, 0x2a, 0x00,
		0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x03, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08,
		0x40, 0x15, 0x40, 0x15, 0x40, 0x15, 0x40, 0x15,
		0x09, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x0a, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a,
		0x00, 0x2a, 0x10, 0x2a, 0x2a, 0x2a, 0x2a, 0x2a,
		0x2a, 0x2a, 0x2a, 0x11, 0x00, 0x40, 0x00, 0x40,
		0x00, 0x40, 0x00, 0x40, 0x18, 0x00, 0x55, 0x00,
		0x55, 0x00, 0x55, 0x00, 0x55, 0xff, 0x31, 0x00,
		0x09, 0x00, 0x61, 0x00, 0x00, 0x55, 0x00, 0x55,
		0x00, 0x55, 0x00, 0x55, 0x00, 0x01, 0x40, 0x00,
		0x40, 0x00, 0x40, 0x00, 0x40, 0x00, 0x02, 0x2a,
		0x00, 0x2a, 0x00, 0x2a, 0x00, 0x2a, 0x00, 0x03,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x08, 0x40, 0x15, 0x40, 0x15, 0x40, 0x15, 0x40,
		0x15, 0x09, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
		0x20, 0x20, 0x0a, 0x00, 0x2a, 0x00, 0x2a, 0x00,
		0x2a, 0x00, 0x2a, 0x10, 0x2a, 0x2a, 0x2a, 0x2a,
		0x2a, 0x2a, 0x2a, 0x2a, 0x11, 0x00, 0x40, 0x00,
		0x40, 0x00, 0x40, 0x00, 0x40, 0x18, 0x00, 0x55,
		0x00, 0x55, 0x00, 0x55, 0x00, 0x55, 0xff};
	uint16_t *tada;
	uint8_t *dptr;
	//   0006: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   0009: 03014602          MOVE   WS_FB_WIN [XXXX]  <-  param[02]  [XXXX]
	//   000d: 561846            CLEAR  WS_FB_WIN [XX..]
	// FIXME
	//   0010: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   0012: 2d0d428608        ADD    WS_DATAPTR [..XX]  <-  0886
	dptr = ldat;
	//   0017: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
	//   001a: 20a50018          MUL    ucPhyId  <-  18
	//   001e: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	dptr += ucPhyId * 0x18;
	//   0022: 038a4642          MOVE   WS_FB_WIN [XX..]  <-  WS_DATAPTR [..XX]
	//   0026: 423900630768066301520063006305630b93066303730763029d076304d90763
	//         0c6908630d7c085a5a
	//                           SWITCH  param[00]  [X...]
	//         07->0668 01->0052 00->0563 0b->0693 03->0773 02->079d 04->07d9 0c->0869
	//         0d->087c
	switch (action) {
	case ATOM_TRANSMITTER_ACTION_INIT:			// 7
		aruba_encoder_init(ucConnObjId);
		return;
	case ATOM_TRANSMITTER_ACTION_ENABLE:			// 1
		goto l_0052;
	case ATOM_TRANSMITTER_ACTION_DISABLE:			// 0
		goto l_0563;
	case ATOM_TRANSMITTER_ACTION_SETUP_VSEMPH:		// b
		goto l_0693;
	case ATOM_TRANSMITTER_ACTION_LCD_BLON:			// 3
		aruba_lcd_blon();
		return;
	case ATOM_TRANSMITTER_ACTION_LCD_BLOFF:			// 2
		aruba_lcd_bloff();
		return;
	case ATOM_TRANSMITTER_ACTION_BL_BRIGHTNESS_CONTROL:	// 4
		aruba_brightness_control();
		return;
	case ATOM_TRANSMITTER_ACTION_POWER_ON:			// c
		goto l_0869;
	case ATOM_TRANSMITTER_ACTION_POWER_OFF:			// d
		goto l_087c;
	default:
		//   004f: 436406            JUMP   0664
		/////goto l_664:
		return;
	}
 l_0052:
	//   0052: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0056: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   005b: 4a25861901        TEST   reg[1986]  [...X]  <-  01
	//   0060: 496406            JUMP_NotEqual  0664
	//   0063: 560848            CLEAR  WS_REGPTR [..XX]
	//   0066: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
	//   006d: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0072: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0074: 03394101          MOVE   WS_REMIND/HI32 [...X]  <-  param[01]  [X...]
	//   0078: 0925410c          AND    WS_REMIND/HI32 [...X]  <-  0c
	//   007c: 02a50204          MOVE   param[02]  [.X..]  <-  04
	//   0080: 3e254108          COMP   WS_REMIND/HI32 [...X]  <-  08
	//   0084: 449600            JUMP_Equal  0096
	//   0087: 02a50201          MOVE   param[02]  [.X..]  <-  01
	//   008b: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   008f: 449600            JUMP_Equal  0096
	//   0092: 02a50206          MOVE   param[02]  [.X..]  <-  06
	//   0096: 0324411700        MOVE   WS_REMIND/HI32 [...X]  <-  data[0017] [...X]
	//   009b: 092541fe          AND    WS_REMIND/HI32 [...X]  <-  fe
	//   009f: 3da20241          COMP   param[02]  [.X..]  <-  WS_REMIND/HI32 [...X]
	//   00a3: 44a800            JUMP_Equal  00a8
	//   00a6: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   00a8: 0205021806000f    MOVE   param[02]  [XXXX]  <-  0f000618
	//   00af: 3d0d00f0d2        COMP   param[00]  [..XX]  <-  d2f0
	//   00b4: 45bb00            JUMP_Below  00bb
	//   00b7: 0ee50280          OR     param[02]  [X...]  <-  80
	//   00bb: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   00c0: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   00c2: 3d250104          COMP   param[01]  [...X]  <-  04
	//   00c6: 47cf00            JUMP_BelowOrEq  00cf
	//   00c9: 68a50201          XOR    param[02]  [.X..]  <-  01
	//   00cd: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   00cf: 02310200          MOVE   param[02]  [...X]  <-  ucPhyId
	//   00d3: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	//   00d5: 0162501c46        MOVE   reg[1c50]  [..X.]  <-  WS_FB_WIN [...X]
	//   00da: 01b1501c01        MOVE   reg[1c50]  [.X..]  <-  param[01]  [.X..]
	//   00df: 03394101          MOVE   WS_REMIND/HI32 [...X]  <-  param[01]  [X...]
	//   00e3: 09254170          AND    WS_REMIND/HI32 [...X]  <-  70
	//   00e7: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   00eb: 44f700            JUMP_Equal  00f7
	//   00ee: 33254110          SUB    WS_REMIND/HI32 [...X]  <-  10
	//   00f2: 01e2501c41        MOVE   reg[1c50]  [X...]  <-  WS_REMIND/HI32 [...X]
	//   00f7: 3da50105          COMP   param[01]  [.X..]  <-  05
	//   00fb: 441a01            JUMP_Equal  011a
	//   00fe: 3da50100          COMP   param[01]  [.X..]  <-  00
	//   0102: 441a01            JUMP_Equal  011a
	//   0105: 3d250104          COMP   param[01]  [...X]  <-  04
	//   0109: 471101            JUMP_BelowOrEq  0111
	//   010c: 0da5001c01        OR     reg[1c00]  [.X..]  <-  01
	//   0111: 010d8d1c0f01      MOVE   reg[1c8d]  [..XX]  <-  010f
	//   0117: 433c01            JUMP   013c
	//   011a: 02a50100          MOVE   param[01]  [.X..]  <-  00
	//   011e: 0ee50102          OR     param[01]  [X...]  <-  02
	//   0122: 03214301          MOVE   WS_SHIFT [...X]  <-  param[01]  [...X]
	//   0126: 03024044          MOVE   WS_QUOT/LOW32 [XXXX]  <-  WS_OR_MASK [XXXX]
	//   012a: 33254001          SUB    WS_QUOT/LOW32 [...X]  <-  01
	//   012e: 32250101          SUB    param[01]  [...X]  <-  01
	//   0132: 0121c21c01        MOVE   reg[1cc2]  [...X]  <-  param[01]  [...X]
	//   0137: 010a8d1c40        MOVE   reg[1c8d]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   013c: 4a25511c01        TEST   reg[1c51]  [...X]  <-  01
	//   0141: 445001            JUMP_Equal  0150
	//   0144: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0148: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   014d: 43f004            JUMP   04f0
	//   0150: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0154: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   0159: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
	//   015c: 0324401600        MOVE   WS_QUOT/LOW32 [...X]  <-  data[0016] [...X]
	//   0161: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   0163: 2d0d428801        ADD    WS_DATAPTR [..XX]  <-  0188
	//   0168: 210d401000        MUL    WS_QUOT/LOW32 [..XX]  <-  0010
	//   016d: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   0171: 0324410a00        MOVE   WS_REMIND/HI32 [...X]  <-  data[000a] [...X]
	//   0176: 0324400b00        MOVE   WS_QUOT/LOW32 [...X]  <-  data[000b] [...X]
	//   017b: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   017f: 44a001            JUMP_Equal  01a0
	//   0182: 03624141          MOVE   WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0186: 038a4141          MOVE   WS_REMIND/HI32 [XX..]  <-  WS_REMIND/HI32 [..XX]
	//   018a: 1b3d4106          SHIFT_RIGHT  WS_REMIND/HI32 [X...]  by  06
	//   018e: 1b354104          SHIFT_RIGHT  WS_REMIND/HI32 [.X..]  by  04
	//   0192: 1b2d4102          SHIFT_RIGHT  WS_REMIND/HI32 [..X.]  by  02
	//   0196: 09054103030303    AND    WS_REMIND/HI32 [XXXX]  <-  03030303
	//   019d: 43ae01            JUMP   01ae
	//   01a0: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   01a4: 0304410c00        MOVE   WS_REMIND/HI32 [XXXX]  <-  data[000c] [XXXX]
	//   01a9: 0324401400        MOVE   WS_QUOT/LOW32 [...X]  <-  data[0014] [...X]
	//   01ae: 0d258a1901        OR     reg[198a]  [...X]  <-  01
	//   01b3: 01028e1941        MOVE   reg[198e]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   01b8: 15254004          SHIFT_LEFT  WS_QUOT/LOW32 [...X]  by  04
	//   01bc: 5c628d190f40      MASK   reg[198d]  [..X.]  &  0f  |  WS_QUOT/LOW32 [...X]
	//   01c2: 07a58d198c        AND    reg[198d]  [.X..]  <-  8c
	//   01c7: 3e254000          COMP   WS_QUOT/LOW32 [...X]  <-  00
	//   01cb: 44d601            JUMP_Equal  01d6
	//   01ce: 0d65871920        OR     reg[1987]  [..X.]  <-  20
	//   01d3: 43db01            JUMP   01db
	//   01d6: 07658719df        AND    reg[1987]  [..X.]  <-  df
	//   01db: 3a0000            SET_REG_BLOCK  0000
	//   01de: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   01e2: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	//   01e8: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   01eb: 3da50100          COMP   param[01]  [.X..]  <-  00
	//   01ef: 493e02            JUMP_NotEqual  023e
	//   01f2: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   01f4: 2d0d429009        ADD    WS_DATAPTR [..XX]  <-  0990
	//   01f9: 2d0d420600        ADD    WS_DATAPTR [..XX]  <-  0006
	//   01fe: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   0201: 4ba50001          TEST   ucPhyId  <-  01
	//   0205: 492302            JUMP_NotEqual  0223
	//   0208: 010c06600100      MOVE   reg[6006]  [..XX]  <-  data[0001] [..XX]
	//   020e: 010c86600300      MOVE   reg[6086]  [..XX]  <-  data[0003] [..XX]
	//   0214: 010c06610500      MOVE   reg[6106]  [..XX]  <-  data[0005] [..XX]
	//   021a: 010c86610700      MOVE   reg[6186]  [..XX]  <-  data[0007] [..XX]
	//   0220: 43b602            JUMP   02b6
	//   0223: 010c06620100      MOVE   reg[6206]  [..XX]  <-  data[0001] [..XX]
	//   0229: 010c86620300      MOVE   reg[6286]  [..XX]  <-  data[0003] [..XX]
	//   022f: 010c06630500      MOVE   reg[6306]  [..XX]  <-  data[0005] [..XX]
	//   0235: 010c86630700      MOVE   reg[6386]  [..XX]  <-  data[0007] [..XX]
	//   023b: 43b602            JUMP   02b6
	//   023e: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   0240: 2d0d422e09        ADD    WS_DATAPTR [..XX]  <-  092e
	//   0245: 030c410000        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0000] [..XX]
	//   024a: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
	//   024e: 03e24144          MOVE   WS_REMIND/HI32 [X...]  <-  WS_OR_MASK [...X]
	//   0252: 4ce4410500        TEST   WS_REMIND/HI32 [X...]  <-  data[0005] [...X]
	//   0257: 446a02            JUMP_Equal  026a
	//   025a: 3da4010400        COMP   param[01]  [.X..]  <-  data[0004] [...X]
	//   025f: 496a02            JUMP_NotEqual  026a
	//   0262: 3d0c000200        COMP   param[00]  [..XX]  <-  data[0002] [..XX]
	//   0267: 477102            JUMP_BelowOrEq  0271
	//   026a: 2d0a4241          ADD    WS_DATAPTR [..XX]  <-  WS_REMIND/HI32 [..XX]
	//   026e: 434a02            JUMP   024a
	//   0271: 4ba50001          TEST   ucPhyId  <-  01
	//   0275: 447f02            JUMP_Equal  027f
	//   0278: 3d250104          COMP   param[01]  [...X]  <-  04
	//   027c: 479e02            JUMP_BelowOrEq  029e
	//   027f: 010c06600600      MOVE   reg[6006]  [..XX]  <-  data[0006] [..XX]
	//   0285: 010c86600800      MOVE   reg[6086]  [..XX]  <-  data[0008] [..XX]
	//   028b: 010c06610a00      MOVE   reg[6106]  [..XX]  <-  data[000a] [..XX]
	//   0291: 010c86610c00      MOVE   reg[6186]  [..XX]  <-  data[000c] [..XX]
	//   0297: 3d250104          COMP   param[01]  [...X]  <-  04
	//   029b: 47b602            JUMP_BelowOrEq  02b6
	//   029e: 010c06620600      MOVE   reg[6206]  [..XX]  <-  data[0006] [..XX]
	//   02a4: 010c86620800      MOVE   reg[6286]  [..XX]  <-  data[0008] [..XX]
	//   02aa: 010c06630a00      MOVE   reg[6306]  [..XX]  <-  data[000a] [..XX]
	//   02b0: 010c86630c00      MOVE   reg[6386]  [..XX]  <-  data[000c] [..XX]
	//   02b6: 560841            CLEAR  WS_REMIND/HI32 [..XX]
	//   02b9: 3d250104          COMP   param[01]  [...X]  <-  04
	//   02bd: 47c502            JUMP_BelowOrEq  02c5
	//   02c0: 030d418001        MOVE   WS_REMIND/HI32 [..XX]  <-  0180
	//   02c5: 5ce205607f41      MASK   reg[6005]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02cb: 5ce285607f41      MASK   reg[6085]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02d1: 5ce205617f41      MASK   reg[6105]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02d7: 5ce285617f41      MASK   reg[6185]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02dd: 5ce205627f41      MASK   reg[6205]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02e3: 5ce285627f41      MASK   reg[6285]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02e9: 5ce205637f41      MASK   reg[6305]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02ef: 5ce285637f41      MASK   reg[6385]  [X...]  &  7f  |  WS_REMIND/HI32 [...X]
	//   02f5: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   02f8: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   02fc: 010438000400      MOVE   reg[0038]  [XXXX]  <-  data[0004] [XXXX]
	//   0302: 5caa3900fe41      MASK   reg[0039]  [.X..]  &  fe  |  WS_REMIND/HI32 [..X.]
	//   0308: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   030c: 560848            CLEAR  WS_REGPTR [..XX]
	//   030f: 08e501fe          AND    param[01]  [X...]  <-  fe
	//   0313: 4be50102          TEST   param[01]  [X...]  <-  02
	//   0317: 443503            JUMP_Equal  0335
	//   031a: 03254102          MOVE   WS_REMIND/HI32 [...X]  <-  02
	//   031e: 3da50100          COMP   param[01]  [.X..]  <-  00
	//   0322: 442903            JUMP_Equal  0329
	//   0325: 03254101          MOVE   WS_REMIND/HI32 [...X]  <-  01
	//   0329: 4a22471841        TEST   reg[1847]  [...X]  <-  WS_REMIND/HI32 [...X]
	//   032e: 443503            JUMP_Equal  0335
	//   0331: 0ee50101          OR     param[01]  [X...]  <-  01
	//   0335: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0339: 0364411500        MOVE   WS_REMIND/HI32 [..X.]  <-  data[0015] [...X]
	//   033e: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   0340: 2d0d421609        ADD    WS_DATAPTR [..XX]  <-  0916
	//   0345: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
	//   0348: 03394001          MOVE   WS_QUOT/LOW32 [...X]  <-  param[01]  [X...]
	//   034c: 0925400c          AND    WS_QUOT/LOW32 [...X]  <-  0c
	//   0350: 15254001          SHIFT_LEFT  WS_QUOT/LOW32 [...X]  by  01
	//   0354: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   0358: 030c480400        MOVE   WS_REGPTR [..XX]  <-  data[0004] [..XX]
	//   035d: 0324410600        MOVE   WS_REMIND/HI32 [...X]  <-  data[0006] [...X]
	//   0362: 03394001          MOVE   WS_QUOT/LOW32 [...X]  <-  param[01]  [X...]
	//   0366: 09254003          AND    WS_QUOT/LOW32 [...X]  <-  03
	//   036a: 3e254003          COMP   WS_QUOT/LOW32 [...X]  <-  03
	//   036e: 448003            JUMP_Equal  0380
	//   0371: 0f624141          OR     WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0375: 4c254002          TEST   WS_QUOT/LOW32 [...X]  <-  02
	//   0379: 448003            JUMP_Equal  0380
	//   037c: 03624141          MOVE   WS_REMIND/HI32 [..X.]  <-  WS_REMIND/HI32 [...X]
	//   0380: 012a061741        MOVE   reg[1706]  [...X]  <-  WS_REMIND/HI32 [..X.]
	//   0385: 3a0000            SET_REG_BLOCK  0000
	//   0388: 4be50101          TEST   param[01]  [X...]  <-  01
	//   038c: 49e003            JUMP_NotEqual  03e0
	//   038f: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	//   0395: 0324410700        MOVE   WS_REMIND/HI32 [...X]  <-  data[0007] [...X]
	//   039a: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   039c: 2d0d426009        ADD    WS_DATAPTR [..XX]  <-  0960
	//   03a1: 3da50100          COMP   param[01]  [.X..]  <-  00
	//   03a5: 49ad03            JUMP_NotEqual  03ad
	//   03a8: 2d0d422400        ADD    WS_DATAPTR [..XX]  <-  0024
	//   03ad: 030c400200        MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0002] [..XX]
	//   03b2: 3d0c000000        COMP   param[00]  [..XX]  <-  data[0000] [..XX]
	//   03b7: 47c203            JUMP_BelowOrEq  03c2
	//   03ba: 2d0d420400        ADD    WS_DATAPTR [..XX]  <-  0004
	//   03bf: 43ad03            JUMP   03ad
	//   03c2: 0f624041          OR     WS_QUOT/LOW32 [..X.]  <-  WS_REMIND/HI32 [...X]
	//   03c6: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   03c9: 010a052040        MOVE   reg[2005]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   03ce: 0d25082001        OR     reg[2008]  [...X]  <-  01
	//   03d3: 07250820fe        AND    reg[2008]  [...X]  <-  fe
	//   03d8: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   03db: 0300403800        MOVE   WS_QUOT/LOW32 [XXXX]  <-  reg[0038]  [XXXX]
	//   03e0: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   03e3: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   03e7: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	//   03ed: 3da50100          COMP   param[01]  [.X..]  <-  00
	//   03f1: 490404            JUMP_NotEqual  0404
	//   03f4: 3d0d00f0d2        COMP   param[00]  [..XX]  <-  d2f0
	//   03f9: 450404            JUMP_Below  0404
	//   03fc: 0d25390050        OR     reg[0039]  [...X]  <-  50
	//   0401: 430904            JUMP   0409
	//   0404: 07253900af        AND    reg[0039]  [...X]  <-  af
	//   0409: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   040c: 4be50101          TEST   param[01]  [X...]  <-  01
	//   0410: 491704            JUMP_NotEqual  0417
	//   0413: 0fe54110          OR     WS_REMIND/HI32 [X...]  <-  10
	//   0417: 4be50104          TEST   param[01]  [X...]  <-  04
	//   041b: 492904            JUMP_NotEqual  0429
	//   041e: 4be50108          TEST   param[01]  [X...]  <-  08
	//   0422: 492904            JUMP_NotEqual  0429
	//   0425: 0fe54102          OR     WS_REMIND/HI32 [X...]  <-  02
	//   0429: 3d250104          COMP   param[01]  [...X]  <-  04
	//   042d: 473404            JUMP_BelowOrEq  0434
	//   0430: 0fa54110          OR     WS_REMIND/HI32 [.X..]  <-  10
	//   0434: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	//   043a: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   043d: 3d250104          COMP   param[01]  [...X]  <-  04
	//   0441: 464b04            JUMP_Above  044b
	//   0444: 4ba50001          TEST   ucPhyId  <-  01
	//   0448: 495704            JUMP_NotEqual  0457
	//   044b: 0102090041        MOVE   reg[0009]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   0450: 3d250104          COMP   param[01]  [...X]  <-  04
	//   0454: 475c04            JUMP_BelowOrEq  045c
	//   0457: 01020a0041        MOVE   reg[000a]  [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   045c: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   045f: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0463: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   0468: 4be50102          TEST   param[01]  [X...]  <-  02
	//   046c: 497704            JUMP_NotEqual  0477
	//   046f: 07258719fc        AND    reg[1987]  [...X]  <-  fc
	//   0474: 437d04            JUMP   047d
	//   0477: 5c258719fc02      MASK   reg[1987]  [...X]  &  fc  |  02
	//   047d: 0d25861901        OR     reg[1986]  [...X]  <-  01
	//   0482: 3a0000            SET_REG_BLOCK  0000
	//   0485: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	//   048b: 4a25390004        TEST   reg[0039]  [...X]  <-  04
	//   0490: 448b04            JUMP_Equal  048b
	//   0493: 4be50101          TEST   param[01]  [X...]  <-  01
	//   0497: 49c704            JUMP_NotEqual  04c7
	//   049a: 0102380040        MOVE   reg[0038]  [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   049f: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   04a2: 07e50220f7        AND    reg[2002]  [X...]  <-  f7
	//   04a7: 0d25082001        OR     reg[2008]  [...X]  <-  01
	//   04ac: 07250820fe        AND    reg[2008]  [...X]  <-  fe
	//   04b1: 0de5022008        OR     reg[2002]  [X...]  <-  08
	//   04b6: 0d25082001        OR     reg[2008]  [...X]  <-  01
	//   04bb: 07250820fe        AND    reg[2008]  [...X]  <-  fe
	//   04c0: 51fa              DELAY_MicroSec  fa
	//   04c2: 51fa              DELAY_MicroSec  fa
	//   04c4: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   04c7: 560848            CLEAR  WS_REGPTR [..XX]
	//   04ca: 03314800          MOVE   WS_REGPTR [...X]  <-  ucPhyId
	//   04ce: 0d25600101        OR     reg[0160]  [...X]  <-  01
	//   04d3: 02310200          MOVE   param[02]  [...X]  <-  ucPhyId
	//   04d7: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	//   04d9: 0d25511c01        OR     reg[1c51]  [...X]  <-  01
	//   04de: 510a              DELAY_MicroSec  0a
	//   04e0: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   04e4: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   04e9: 0d258d1901        OR     reg[198d]  [...X]  <-  01
	//   04ee: 510a              DELAY_MicroSec  0a
	//   04f0: 0d658a1910        OR     reg[198a]  [..X.]  <-  10
	//   04f5: 3a0000            SET_REG_BLOCK  0000
	//   04f8: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   04fc: 0205021701000f    MOVE   param[02]  [XXXX]  <-  0f000117
	//   0503: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0508: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   050a: 3d250104          COMP   param[01]  [...X]  <-  04
	//   050e: 471705            JUMP_BelowOrEq  0517
	//   0511: 68a50201          XOR    param[02]  [.X..]  <-  01
	//   0515: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0517: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
	//   051e: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0523: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0525: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
	//   052c: 03394101          MOVE   WS_REMIND/HI32 [...X]  <-  param[01]  [X...]
	//   0530: 0925410c          AND    WS_REMIND/HI32 [...X]  <-  0c
	//   0534: 02a50204          MOVE   param[02]  [.X..]  <-  04
	//   0538: 3e254108          COMP   WS_REMIND/HI32 [...X]  <-  08
	//   053c: 444e05            JUMP_Equal  054e
	//   053f: 02a50201          MOVE   param[02]  [.X..]  <-  01
	//   0543: 3e254100          COMP   WS_REMIND/HI32 [...X]  <-  00
	//   0547: 444e05            JUMP_Equal  054e
	//   054a: 02a50206          MOVE   param[02]  [.X..]  <-  06
	//   054e: 0324411700        MOVE   WS_REMIND/HI32 [...X]  <-  data[0017] [...X]
	//   0553: 092541fe          AND    WS_REMIND/HI32 [...X]  <-  fe
	//   0557: 3da20241          COMP   param[02]  [.X..]  <-  WS_REMIND/HI32 [...X]
	//   055b: 446406            JUMP_Equal  0664
	//   055e: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0560: 436406            JUMP   0664
	return;
	//   0563: 02310200          MOVE   param[02]  [...X]  <-  ucPhyId
	//   0567: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	//   0569: 4a25511c01        TEST   reg[1c51]  [...X]  <-  01
	//   056e: 446406            JUMP_Equal  0664
	//   0571: 3ca5501c02        COMP   reg[1c50]  [.X..]  <-  02
	//   0576: 448105            JUMP_Equal  0581
	//   0579: 3ca5501c03        COMP   reg[1c50]  [.X..]  <-  03
	//   057e: 498a05            JUMP_NotEqual  058a
	//   0581: 5400511c          CLEAR  reg[1c51]  [XXXX]
	//   0585: 5002              DELAY_MilliSec  02
	//   0587: 43ab05            JUMP   05ab
	//   058a: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
	//   058e: 4a62501c44        TEST   reg[1c50]  [..X.]  <-  WS_OR_MASK [...X]
	//   0593: 44ab05            JUMP_Equal  05ab
	//   0596: 5408c31c          CLEAR  reg[1cc3]  [..XX]
	//   059a: 51c8              DELAY_MicroSec  c8
	//   059c: 0d25c41c01        OR     reg[1cc4]  [...X]  <-  01
	//   05a1: 5132              DELAY_MicroSec  32
	//   05a3: 5420c01c          CLEAR  reg[1cc0]  [...X]
	//   05a7: 5420d11c          CLEAR  reg[1cd1]  [...X]
	//   05ab: 560848            CLEAR  WS_REGPTR [..XX]
	//   05ae: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   05b2: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	//   05b8: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   05bb: 03e0401480        MOVE   WS_QUOT/LOW32 [X...]  <-  reg[8014]  [...X]
	//   05c0: 07251480c3        AND    reg[8014]  [...X]  <-  c3
	//   05c5: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   05c8: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   05cd: 07658a19ef        AND    reg[198a]  [..X.]  <-  ef
	//   05d2: 02310200          MOVE   param[02]  [...X]  <-  ucPhyId
	//   05d6: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	//   05d8: 0725511cfe        AND    reg[1c51]  [...X]  <-  fe
	//   05dd: 5428501c          CLEAR  reg[1c50]  [..X.]
	//   05e1: 54008d1c          CLEAR  reg[1c8d]  [XXXX]
	//   05e5: 560848            CLEAR  WS_REGPTR [..XX]
	//   05e8: 03314800          MOVE   WS_REGPTR [...X]  <-  ucPhyId
	//   05ec: 07256001fe        AND    reg[0160]  [...X]  <-  fe
	//   05f1: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   05f5: 030c481000        MOVE   WS_REGPTR [..XX]  <-  data[0010] [..XX]
	//   05fa: 07258619fe        AND    reg[1986]  [...X]  <-  fe
	//   05ff: 3a0000            SET_REG_BLOCK  0000
	//   0602: 010438000800      MOVE   reg[0038]  [XXXX]  <-  data[0008] [XXXX]
	//   0608: 4a25390001        TEST   reg[0039]  [...X]  <-  01
	//   060d: 440806            JUMP_Equal  0608
	//   0610: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   0613: 013a148040        MOVE   reg[8014]  [...X]  <-  WS_QUOT/LOW32 [X...]
	//   0618: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   061b: 02310200          MOVE   param[02]  [...X]  <-  ucPhyId
	//   061f: 5214              CALL_TABLE  14  (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
	//   0621: 07a5001cfe        AND    reg[1c00]  [.X..]  <-  fe
	//   0626: 3a0000            SET_REG_BLOCK  0000
	//   0629: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   062d: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
	//   0634: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0639: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   063b: 0205021707000f    MOVE   param[02]  [XXXX]  <-  0f000717
	//   0642: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0647: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0649: 3d650104          COMP   param[01]  [..X.]  <-  04
	//   064d: 495606            JUMP_NotEqual  0656
	//   0650: 68a50201          XOR    param[02]  [.X..]  <-  01
	//   0654: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0656: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
	//   065d: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   0662: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
 l_664:
	//   0664: 3a0000            SET_REG_BLOCK  0000
	//   0667: 5b                EOT
	return;

	//   0693: 02050223000000    MOVE   param[02]  [XXXX]  <-  00000023
	//   069a: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   069f: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   06a1: 560040            CLEAR  WS_QUOT/LOW32 [XXXX]
	//   06a4: 0324401600        MOVE   WS_QUOT/LOW32 [...X]  <-  data[0016] [...X]
	//   06a9: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   06ab: 2d0d428801        ADD    WS_DATAPTR [..XX]  <-  0188
	//   06b0: 210d401000        MUL    WS_QUOT/LOW32 [..XX]  <-  0010
	//   06b5: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   06b9: 0324400c00        MOVE   WS_QUOT/LOW32 [...X]  <-  data[000c] [...X]
	//   06be: 3e254002          COMP   WS_QUOT/LOW32 [...X]  <-  02
	//   06c2: 49cc06            JUMP_NotEqual  06cc
	//   06c5: 661e              SET_DATA_BLOCK  1e  (IntegratedSystemInfo)
	//   06c7: 036446fc01        MOVE   WS_FB_WIN [..X.]  <-  data[01fc] [...X]
	//   06cc: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   06d0: 010438000000      MOVE   reg[0038]  [XXXX]  <-  data[0000] [XXXX]
	//   06d6: 66ff              SET_DATA_BLOCK  ff  (this table)
	//   06d8: 0965461b          AND    WS_FB_WIN [..X.]  <-  1b
	//   06dc: 2d0d429009        ADD    WS_DATAPTR [..XX]  <-  0990
	//   06e1: 03314300          MOVE   WS_SHIFT [...X]  <-  ucPhyId
	//   06e5: 03a24044          MOVE   WS_QUOT/LOW32 [.X..]  <-  WS_OR_MASK [...X]
	//   06e9: 030c400200        MOVE   WS_QUOT/LOW32 [..XX]  <-  data[0002] [..XX]
	//   06ee: 4ca4400000        TEST   WS_QUOT/LOW32 [.X..]  <-  data[0000] [...X]
	//   06f3: 49fe06            JUMP_NotEqual  06fe
	//   06f6: 2d0c420400        ADD    WS_DATAPTR [..XX]  <-  data[0004] [..XX]
	//   06fb: 43e906            JUMP   06e9
	//   06fe: 2d0d420600        ADD    WS_DATAPTR [..XX]  <-  0006
	//   0703: 3e64460000        COMP   WS_FB_WIN [..X.]  <-  data[0000] [...X]
	//   0708: 441e07            JUMP_Equal  071e
	//   070b: 0324410000        MOVE   WS_REMIND/HI32 [...X]  <-  data[0000] [...X]
	//   0710: 3e2541ff          COMP   WS_REMIND/HI32 [...X]  <-  ff
	//   0714: 441e07            JUMP_Equal  071e
	//   0717: 2d0a4240          ADD    WS_DATAPTR [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   071b: 430307            JUMP   0703
	//   071e: 370300            SET_ATI_PORT  0003  (INDIRECT_IO_PCIE)
	//   0721: 4ba50001          TEST   ucPhyId  <-  01
	//   0725: 494307            JUMP_NotEqual  0743
	//   0728: 010c06600100      MOVE   reg[6006]  [..XX]  <-  data[0001] [..XX]
	//   072e: 010c86600300      MOVE   reg[6086]  [..XX]  <-  data[0003] [..XX]
	//   0734: 010c06610500      MOVE   reg[6106]  [..XX]  <-  data[0005] [..XX]
	//   073a: 010c86610700      MOVE   reg[6186]  [..XX]  <-  data[0007] [..XX]
	//   0740: 435b07            JUMP   075b
	//   0743: 010c06620100      MOVE   reg[6206]  [..XX]  <-  data[0001] [..XX]
	//   0749: 010c86620300      MOVE   reg[6286]  [..XX]  <-  data[0003] [..XX]
	//   074f: 010c06630500      MOVE   reg[6306]  [..XX]  <-  data[0005] [..XX]
	//   0755: 010c86630700      MOVE   reg[6386]  [..XX]  <-  data[0007] [..XX]
	//   075b: 370000            SET_ATI_PORT  0000  (INDIRECT_IO_MM)
	//   075e: 031a4246          MOVE   WS_DATAPTR [..XX]  <-  WS_FB_WIN [XX..]
	//   0762: 02050222000000    MOVE   param[02]  [XXXX]  <-  00000022
	//   0769: 02a4021700        MOVE   param[02]  [.X..]  <-  data[0017] [...X]
	//   076e: 5213              CALL_TABLE  13  (EnableASIC_StaticPwrMgt)
	//   0770: 436406            JUMP   0664

	return;

	return;
	//   07d9: 6606              SET_DATA_BLOCK  06  (LVDS_Info)
	//   07db: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   07de: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	//   07e3: 3e0d410000        COMP   WS_REMIND/HI32 [..XX]  <-  0000
	//   07e8: 446808            JUMP_Equal  0868
	//   07eb: 4aa59c0101        TEST   reg[019c]  [.X..]  <-  01
	//   07f0: 49f807            JUMP_NotEqual  07f8
	//   07f3: 0d25211901        OR     reg[1921]  [...X]  <-  01
	//   07f8: 03054640787d01    MOVE   WS_FB_WIN [XXXX]  <-  017d7840
	//   07ff: 210541ff0f0000    MUL    WS_REMIND/HI32 [XXXX]  <-  00000fff
	//   0806: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   080a: 3e054100000000    COMP   WS_REMIND/HI32 [XXXX]  <-  00000000
	//   0811: 441908            JUMP_Equal  0819
	//   0814: 2d0d400100        ADD    WS_QUOT/LOW32 [..XX]  <-  0001
	//   0819: 018a1b1940        MOVE   reg[191b]  [XX..]  <-  WS_QUOT/LOW32 [..XX]
	//   081e: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   0821: 030c413200        MOVE   WS_REMIND/HI32 [..XX]  <-  data[0032] [..XX]
	//   0826: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   082a: 27024640          DIV    WS_FB_WIN [XXXX]  <-  WS_QUOT/LOW32 [XXXX]
	//   082e: 01a520190c        MOVE   reg[1920]  [.X..]  <-  0c
	//   0833: 010a201940        MOVE   reg[1920]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   0838: 15054004          SHIFT_LEFT  WS_QUOT/LOW32 [XXXX]  by  04
	//   083c: 560041            CLEAR  WS_REMIND/HI32 [XXXX]
	//   083f: 032841cb05        MOVE   WS_REMIND/HI32 [...X]  <-  reg[05cb]  [..X.]
	//   0844: 2d0d410100        ADD    WS_REMIND/HI32 [..XX]  <-  0001
	//   0849: 21024041          MUL    WS_QUOT/LOW32 [XXXX]  <-  WS_REMIND/HI32 [XXXX]
	//   084d: 1b054008          SHIFT_RIGHT  WS_QUOT/LOW32 [XXXX]  by  08
	//   0851: 010a1e1940        MOVE   reg[191e]  [..XX]  <-  WS_QUOT/LOW32 [..XX]
	//   0856: 0de51e19c0        OR     reg[191e]  [X...]  <-  c0
	//   085b: 07252119fe        AND    reg[1921]  [...X]  <-  fe
	//   0860: 4a65211901        TEST   reg[1921]  [..X.]  <-  01
	//   0865: 496008            JUMP_NotEqual  0860
	//   0868: 5b                EOT
	return;
	//   0869: 07a51919fd        AND    reg[1919]  [.X..]  <-  fd
	//   086e: 0d25191911        OR     reg[1919]  [...X]  <-  11
	//   0873: 3c651a1904        COMP   reg[191a]  [..X.]  <-  04
	//   0878: 497308            JUMP_NotEqual  0873
	//   087b: 5b                EOT
	return;
	//   087c: 5c251919ef01      MASK   reg[1919]  [...X]  &  ef  |  01
	//   0882: 5b                EOT
	return;
	//   0883: 7acc010220230111001301488033010001020300000000000802060220210111
	//         0011014980310100010203100000000002030102202102110011024a80310100
	//         010203200000000008040202202102110011024b803101000102033000000000
	//         08050302202201110012014c8032010001020340000000001000040220220111
	//         0012014d80320100010203500000000010010505202101100002600520230120
	//         00084005202201000010400c00ffff020e000b000b000b000bffff0231000b00
	//         0b000b000bffff030e002a002a002a002affff0331000b000b000b000b350c00
	//         061d100106881302066a180306bd1f040610270506d430060674400706ffff08
	//         066842000478690204ffff01040e000900610000550055005500550001400040
	//         0040004000022a002a002a002a00030000000000000000084015401540154015
	//         0920202020202020200a002a002a002a002a102a2a2a2a2a2a2a2a1100400040
	//         00400040180055005500550055ff310009006100005500550055005500014000
	//         400040004000022a002a002a002a000300000000000000000840154015401540
	//         150920202020202020200a002a002a002a002a102a2a2a2a2a2a2a2a11004000
	//         4000400040180055005500550055ff
	//                           CTB_DS  460 bytes

}
