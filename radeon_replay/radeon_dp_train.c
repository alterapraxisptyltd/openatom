#include "aruba/aruba.h"

#include "drm_dp_helper.h"

#include <stdbool.h>
#include <stdlib.h>

#define TIMED_OUT(str) \
	do {						\
	DRM_ERROR("Timed out on %s", str);	\
	return;					\
	} while(0)

struct dp_link_ctx {
	uint8_t sts[DP_LINK_STATUS_SIZE];
	uint8_t dpcd[DP_RECEIVER_CAP_SIZE];
	uint8_t drive[4];
	struct drm_dp_link link;
	struct drm_dp_aux *aux;
	unsigned int max_link_rate;
	bool pattern3_supported;
	bool use_pattern3;
	uint8_t lane_count;
	struct radeon_encoder *encoder;
	struct radeon_transmitter *transmitter;
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
	ctx->link.num_lanes = drm_dp_max_lane_count(ctx->dpcd);

	if (drm_dp_enhanced_frame_cap(ctx->dpcd))
		ctx->link.capabilities |= DP_LINK_CAP_ENHANCED_FRAMING;

	return 0;
}

void decide_link_params(struct dp_link_ctx *ctx)
{
	if (ctx->pattern3_supported
	   && (ctx->dpcd[DP_MAX_LANE_COUNT] & DP_TPS3_SUPPORTED)) {
		DRM_DEBUG_KMS("Will use DP training pattern 3");
		ctx->use_pattern3 = true;
	} else {
		ctx->use_pattern3 = false;
	}

	/* Limit the link rate on what we are able to do */
	ctx->link.rate = min(ctx->max_link_rate, ctx->link.rate);
	ctx->lane_count = min(ctx->lane_count, ctx->link.num_lanes);
}

void prepare_sink(struct dp_link_ctx *ctx)
{
	uint8_t reg8;

	/* power up the sink */
	drm_dp_link_power_up(ctx->aux, &ctx->link);

	/* Skipped SS control */
	/* possibly enable downspread on the sink */
	reg8 = (ctx->dpcd[DP_MAX_DOWNSPREAD] & 0x1) ? DP_SPREAD_AMP_0_5 : 0;
	drm_dp_dpcd_writeb(ctx->aux, DP_DOWNSPREAD_CTRL, reg8);

	/* Skipped eDP control */
	if (1) {
		DRM_ERROR("About to do something that's nasty");
		drm_dp_dpcd_writeb(ctx->aux, DP_EDP_CONFIGURATION_SET, 1);
	}


	/* set the lane count on the sink */
	reg8 = ctx->lane_count;
	if (ctx->link.capabilities & DP_LINK_CAP_ENHANCED_FRAMING)
		reg8 |= DP_LANE_COUNT_ENHANCED_FRAME_EN;
	drm_dp_dpcd_writeb(ctx->aux, DP_LANE_COUNT_SET, reg8);

	/* set the link rate on the sink */
	reg8 = drm_dp_link_rate_to_bw_code(ctx->link.rate);
	drm_dp_dpcd_writeb(ctx->aux, DP_LINK_BW_SET, reg8);

	/* Skipped start link training on encoder */
	/* Skipped disable training pattern on sink */
}

static void set_training_pattern(struct dp_link_ctx *ctx, uint8_t pattern)
{
	ctx->encoder->set_dp_training_pattern(ctx->encoder, pattern);
	drm_dp_dpcd_writeb(ctx->aux, DP_TRAINING_PATTERN_SET, pattern);
}

static void set_drive_strength(struct dp_link_ctx *ctx)
{
	ctx->transmitter->update_drive_strength(ctx->transmitter,
						ctx->drive, ctx->lane_count);
	drm_dp_dpcd_write(ctx->aux, DP_TRAINING_LANE0_SET, ctx->drive,
			  ctx->lane_count);
}

static int reached_max_voltage(uint8_t *drive, uint8_t lane_count)
{
	int i;
	int num_failed = 0;

	for (i = 0; i < lane_count; i++) {
		if (drive[i] & DP_TRAIN_MAX_SWING_REACHED) {
			DRM_ERROR("Max swing voltage reached on lane %d", i);
			num_failed++;
		}
	}

	return num_failed;
}

/*
 **** general DP utility functions ****
 * Ripped straight from radeon.ko
 */

static void dp_get_adjust_train(uint8_t *drive, uint8_t lane_count,
				uint8_t status[DP_LINK_STATUS_SIZE])
{
	uint8_t v = 0;
	uint8_t p = 0;
	int lane;

	static const uint8_t max_pre_emphasis[] = {
		DP_TRAIN_PRE_EMPH_LEVEL_3, DP_TRAIN_PRE_EMPH_LEVEL_2,
		DP_TRAIN_PRE_EMPH_LEVEL_1, DP_TRAIN_PRE_EMPH_LEVEL_0,
	};

	for (lane = 0; lane < lane_count; lane++) {
		v = drm_dp_get_adjust_request_voltage(status, lane);
		p = drm_dp_get_adjust_request_pre_emphasis(status, lane);

		if (p >= max_pre_emphasis[v >> DP_TRAIN_VOLTAGE_SWING_SHIFT])
			p |= DP_TRAIN_MAX_PRE_EMPHASIS_REACHED;

		if (v >= DP_TRAIN_VOLTAGE_SWING_LEVEL_3)
			v |= DP_TRAIN_MAX_SWING_REACHED;

		drive[lane] = v | p;
	}
}

static void print_per_lane_drive_set(uint8_t drive[4], uint8_t lane_count)
{
	int i;

	for (i = 0; i < lane_count; i++)
		DRM_DEBUG_KMS("\t lane %d, voltage level %d, pre-emphasis %d",
			      i, drive[i] & DP_TRAIN_VOLTAGE_SWING_MASK,
			      (drive[i] & DP_TRAIN_PRE_EMPHASIS_MASK) >>
					DP_TRAIN_PRE_EMPHASIS_SHIFT);
}

#define MAX_RETRIES	5

static int train_clock_recovery(struct dp_link_ctx *ctx)
{
	int ret, num_retries;
	uint8_t old_drive[sizeof(ctx->drive)];
	bool succeeded = false;

	set_training_pattern(ctx, DP_TRAINING_PATTERN_1);
	memset(ctx->drive, 0, sizeof(ctx->drive));
	set_drive_strength(ctx);

	for (num_retries = 0; num_retries < MAX_RETRIES; /* empty */) {
		drm_dp_link_train_clock_recovery_delay(ctx->dpcd);

		ret = drm_dp_dpcd_read_link_status(ctx->aux, ctx->sts);
		if (ret < 0) {
			DRM_ERROR("Reading DisplayPort link status failed");
			break;
		}

		if (drm_dp_clock_recovery_ok(ctx->sts, ctx->lane_count)) {
			succeeded = true;
			break;
		}

		if (reached_max_voltage(ctx->drive, ctx->lane_count))
			break;

		memcpy(old_drive, ctx->drive, sizeof(old_drive));
		/* Compute new train_set as requested by sink */
		dp_get_adjust_train(ctx->drive, ctx->lane_count, ctx->sts);

		/* Using the same drive parameters consumes a brownie point */
		if (!memcmp(old_drive, ctx->drive, sizeof(old_drive)))
			num_retries++;

		set_drive_strength(ctx);
	}

	if (!succeeded) {
		DRM_ERROR("DP clock recovery failed\n");
		if (num_retries == MAX_RETRIES)
			DRM_ERROR("Too many retries\n");
		return -1;
	}

	DRM_DEBUG_KMS("DP clock recovery succesfully trained");
	print_per_lane_drive_set(ctx->drive, ctx->lane_count);

	return 0;
}

static int train_channel_eq(struct dp_link_ctx *ctx)
{
	int ret, num_retries;
	uint8_t pattern;
	bool succeeded = false;

	if (ctx->use_pattern3)
		pattern = DP_TRAINING_PATTERN_3;
	else
		pattern = DP_TRAINING_PATTERN_2;

	set_training_pattern(ctx, pattern);

	for (num_retries = 0; num_retries < MAX_RETRIES; num_retries++) {
		drm_dp_link_train_channel_eq_delay(ctx->dpcd);

		ret = drm_dp_dpcd_read_link_status(ctx->aux, ctx->sts);
		if (ret < 0) {
			DRM_ERROR("Reading DisplayPort link status failed");
			break;
		}

		if (drm_dp_channel_eq_ok(ctx->sts, ctx->lane_count)) {
			succeeded = true;
			break;
		}

		/* Compute new train_set as requested by sink */
		dp_get_adjust_train(ctx->drive, ctx->lane_count, ctx->sts);
		set_drive_strength(ctx);
	}

	if (!succeeded) {
		DRM_ERROR("DP channel EQ failed\n");
		if (num_retries == MAX_RETRIES)
			DRM_ERROR("Too many retries\n");
		return -1;
	}

	DRM_DEBUG_KMS("DP channel EQ succesfully trained");
	print_per_lane_drive_set(ctx->drive, ctx->lane_count);

	return 0;
}

int radeon_dp_link_train(struct radeon_device *rdev,
			 struct radeon_encoder *encoder,
			 struct radeon_transmitter *transmitter)
{
	int ret;
	struct dp_link_ctx context;
	struct dp_link_ctx *ctx = &context;

	/* FIXME: What are we doing here? */
	ctx->aux = &my_aux;
	ctx->max_link_rate = 540000;
	ctx->pattern3_supported = true;
	ctx->lane_count = 4;
	ctx->encoder = encoder;
	ctx->transmitter = transmitter;
	/* ^^^ FIXME: Refactor that to something smarter/separate func ^^^ */

	probe_link(ctx);
	decide_link_params(ctx);
	prepare_sink(ctx);

	ret = train_clock_recovery(ctx);
	if (ret < 0)
		goto finalize;
	ret = train_channel_eq(ctx);
	if (ret < 0)
		goto finalize;
 finalize:
	set_training_pattern(ctx, DP_TRAINING_PATTERN_DISABLE);
	return ret;
}
