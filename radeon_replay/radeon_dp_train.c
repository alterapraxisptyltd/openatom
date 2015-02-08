#include "aruba/aruba.h"

#include "drm_dp_helper.h"

#include <stdbool.h>

struct dp_link_ctx {
	uint8_t sts[DP_LINK_STATUS_SIZE];
	uint8_t dpcd[DP_RECEIVER_CAP_SIZE];
	struct drm_dp_link link;
	struct drm_dp_aux *aux;
	unsigned int max_link_rate;
	bool pattern3_supported;
	bool use_pattern3;
	uint8_t lane_count;
};

int probe_link(struct dp_link_ctx *ctx)
{
	int err;

	err = drm_dp_dpcd_read(ctx->aux, DP_DPCD_REV,
			       ctx->dpcd, sizeof(ctx->dpcd));
	if (err < 0)
		return err;

	ctx->link.revision = ctx->dpcd[0];
	ctx->link.rate = drm_dp_bw_code_to_link_rate(ctx->dpcd[1]);
	ctx->link.num_lanes = ctx->dpcd[2] & DP_MAX_LANE_COUNT_MASK;

	if (drm_dp_enhanced_frame_cap(ctx->dpcd))
		ctx->link.capabilities |= DP_LINK_CAP_ENHANCED_FRAMING;

	return 0;
}

int radeon_dp_link_train(struct radeon *rdev)
{
	struct dp_link_ctx context;
	struct dp_link_ctx *ctx = &context;

	/* FIXME: What are we doing here? */
	ctx->aux = &my_aux;
	ctx->max_link_rate = 540000;
	ctx->pattern3_supported = true;
	ctx->lane_count = 4;
	/* ^^^ FIXME: Refactor that to something smarter/separate func ^^^ */

	probe_link(ctx);

	/* Decide on some link params */
	if (ctx->pattern3_supported
	   && (ctx->dpcd[DP_MAX_LANE_COUNT] & DP_TPS3_SUPPORTED)) {
		DRM_DEBUG_KMS("Will use DP training pattern 3");
		ctx->use_pattern3 = true;
	} else {
		ctx->use_pattern3 = false;
	}

	/* Limit the link rate on what we are able to do */
	ctx->link.rate = min(ctx->max_link_rate, ctx->link.rate);
	ctx->lane_count = min(ctx->lane_count, drm_dp_max_lane_count(ctx->dpcd));

	drm_dp_link_power_up(ctx->aux, &ctx->link);
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
	radeon_mask(rdev, 0x6464, 0, 3 << 24);

	if (aruba_blank_crtc(rdev, 0, false))
		TIMED_OUT("when we were about to enable CRTC");

	//vga_sr_read(0x01);
	//vga_sr_write(0x01, 0x01);
}
