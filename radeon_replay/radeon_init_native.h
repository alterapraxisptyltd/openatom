#ifndef __RADEON_INIT_NATIVE_H
#define __RADEON_INIT_NATIVE_H

#include "linux_glue.h"
#include <aruba/aruba.h>

#include <stdint.h>
#include <stdbool.h>

#define BIG_ASS_ACRATCH_REG		0x611c	// 1847

/* vvv FIXME: KILLME PLEASE vvv*/
struct ATOM_DIG_TRANSMITTER_CONFIG_V5
{
	uint8_t ucReserved:1;
	uint8_t ucCoherentMode:1;
	uint8_t ucPhyClkSrcId:2;
	uint8_t ucHPDSel:3;
	uint8_t ucReservd1:1;
};

struct DIG_TRANSMITTER_PARAMETERS
{
	uint16_t usSymClock;		// Encoder Clock in 10kHz,(DP mode)= linkclock/10, (TMDS/LVDS/HDMI)= pixel clock,  (HDMI deep color), =pixel clock * deep_color_ratio
	uint8_t  ucPhyId;		// 0=UNIPHYA, 1=UNIPHYB, 2=UNIPHYC, 3=UNIPHYD, 4= UNIPHYE 5=UNIPHYF
	uint8_t  ucAction;		// define as ATOM_TRANSMITER_ACTION_xxx

	uint8_t  ucLaneNum;		// indicate lane number 1-8
	uint8_t  ucConnObjId;               // Connector Object Id defined in ObjectId.h
	uint8_t  ucDigMode;		// indicate DIG mode
	union{
		struct ATOM_DIG_TRANSMITTER_CONFIG_V5 asConfig;
		uint8_t ucConfig;
	};

	uint8_t  ucDigEncoderSel;           // indicate DIG front end encoder
	uint8_t  ucDPLaneSet;
	uint8_t  ucReserved;
	uint8_t  ucReserved1;
};

/* ^^^ FIXME: KILLME PLEASE ^^^ */

void aruba_asic_init(struct radeon_device *rdev);

void radeon_init_aux_pads(struct radeon_device* rdev);
int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len);
int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
		    uint8_t *dest, uint8_t start, uint16_t len);

void radeon_dp_encoder_control(void);

void asic_init(void);

struct radeon_pll_config {
	uint32_t feedbback_div_frac;	// 20 bit feedback divider decimal fraction part, range from 1~999999 ( 0.000001 to 0.999999 )
	uint16_t feedback_div_int;	// feedback divider integer part.
	uint8_t  post_div;		// post divider.
	uint8_t  ref_div;		// Reference divider
};

/* aruba_crtc.c */
void aruba_enable_crtc(struct radeon_device * rdev,
		       uint8_t crtc_id, bool enable);
void aruba_update_crtc_x2_buf(struct radeon_device * rdev,
			      uint8_t crtc_id, bool enable);
void aruba_blank_crtc(struct radeon_device * rdev, uint8_t crtc_id, bool enable);
void aruba_set_crtc_dtd_timing(struct radeon_device *rdev, uint8_t crtc_id,
			       struct drm_display_mode *mode,
			       uint8_t h_border, uint8_t v_border);
void aruba_set_disp_eng_pll(struct radeon_device *rdev, uint32_t clock_10khz);
void aruba_set_encoder_crtc_source(struct radeon_device * rdev,
				   uint8_t crtc_id, uint8_t encoder_id,
				   uint8_t encoder_mode);

/* aruba_misc.c */
void dynamic_clock_gating_init(struct radeon_device *rdev);
void aruba_powergate_crtc(struct radeon_device *rdev, uint8_t enable, uint8_t crtc_id);

/* aruba_pll.c */
uint8_t aruba_compute_engine_pll(uint32_t *clock_khz);

void aruba_disable_pll_ss(struct radeon_device *rdev, uint8_t pll_id);
void aruba_enable_pll_ss(struct radeon_device *rdev, uint8_t pll_id,
			 uint16_t step, uint16_t ds_frac, uint8_t fbdiv,
			 uint8_t nfrac, bool downspread);

void aruba_scaler_setup(struct radeon_device *rdev, uint8_t crtc_id,
			int rmx_type);

void aruba_init_pixel_pll(struct radeon_device * rdev, uint8_t pll_id);

/* aruba_encoder.c */
void aruba_encoder_setup_dp(struct radeon_device *rdev, uint8_t id,
			    uint16_t pixel_clock_khz, uint8_t lane_num,
			    uint8_t bpc_mask, uint32_t dp_link_rate);
void aruba_encoder_setup_other(struct radeon_device *rdev, uint8_t id,
			       uint8_t mode, uint8_t lane_num);
void aruba_encoder_setup_panel_mode(struct radeon_device *rdev,
				    uint8_t encoder_id, uint8_t panel_mode);
void aruba_encoder_video_on(struct radeon_device *rdev, uint8_t encoder_id);
void aruba_encoder_video_off(struct radeon_device *rdev, uint8_t encoder_id);
void aruba_encoder_link_training_start(struct radeon_device *rdev,
				       uint8_t encoder_id);
void aruba_encoder_link_training_pattern(struct radeon_device *rdev,
					 uint8_t encoder_id, uint8_t pattern);
void aruba_encoder_link_training_finish(struct radeon_device *rdev,
					uint8_t encoder_id);

/* aruba_transmitter.c */
void aruba_transmitter_init(struct radeon_device *rdev, uint8_t connector_id);
void aruba_transmitter_vsemph(struct radeon_device *rdev, uint8_t phy_id,
			      uint8_t lane_sel_mask);
void aruba_brightness_control(struct radeon_device *rdev,
			      uint16_t bl_pwm_freq_hz, uint8_t bl_level);
void aruba_lcd_blon(struct radeon_device *rdev);
void aruba_lcd_bloff(struct radeon_device *rdev);


void aruba_transmitter_enable(struct radeon_device *rdev,
			      struct DIG_TRANSMITTER_PARAMETERS *cfg);
/* external_encoder_travis.c */
void travis_init(struct radeon_device *rdev);

/* extras */
uint16_t get_uniphy_reg_offset(uint8_t level, uint8_t phy);
void aruba_disable_grph_srfc(struct radeon_device *rdev, uint8_t surf);

#endif	/* __RADEON_INIT_NATIVE_H */
