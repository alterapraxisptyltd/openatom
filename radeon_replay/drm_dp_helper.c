#include "drm_dp_helper.h"
#include "linux_glue.h"


/**
 * DOC: dp helpers
 *
 * These functions contain some common logic and helpers at various abstraction
 * levels to deal with Display Port sink devices and related things like DP aux
 * channel transfers, EDID reading over DP aux channels, decoding certain DPCD
 * blocks, ...
 */

/* Helpers for DP link training */
static uint8_t dp_link_status(const uint8_t link_status[DP_LINK_STATUS_SIZE],
			      int r)
{
	return link_status[r - DP_LANE0_1_STATUS];
}

static uint8_t dp_get_lane_status(const uint8_t link_status[DP_LINK_STATUS_SIZE],
			     int lane)
{
	int i = DP_LANE0_1_STATUS + (lane >> 1);
	int s = (lane & 1) * 4;
	uint8_t l = dp_link_status(link_status, i);
	return (l >> s) & 0xf;
}

bool drm_dp_channel_eq_ok(const uint8_t link_status[DP_LINK_STATUS_SIZE],
			  int lane_count)
{
	uint8_t lane_align;
	uint8_t lane_status;
	int lane;

	lane_align = dp_link_status(link_status,
				    DP_LANE_ALIGN_STATUS_UPDATED);
	if ((lane_align & DP_INTERLANE_ALIGN_DONE) == 0)
		return false;
	for (lane = 0; lane < lane_count; lane++) {
		lane_status = dp_get_lane_status(link_status, lane);
		if ((lane_status & DP_CHANNEL_EQ_BITS) != DP_CHANNEL_EQ_BITS)
			return false;
	}
	return true;
}

bool drm_dp_clock_recovery_ok(const uint8_t link_status[DP_LINK_STATUS_SIZE],
			      int lane_count)
{
	int lane;
	uint8_t lane_status;

	for (lane = 0; lane < lane_count; lane++) {
		lane_status = dp_get_lane_status(link_status, lane);
		if ((lane_status & DP_LANE_CR_DONE) == 0)
			return false;
	}
	return true;
}

uint8_t drm_dp_get_adjust_request_voltage(const uint8_t link_status[DP_LINK_STATUS_SIZE],
				     int lane)
{
	int i = DP_ADJUST_REQUEST_LANE0_1 + (lane >> 1);
	int s = ((lane & 1) ?
		 DP_ADJUST_VOLTAGE_SWING_LANE1_SHIFT :
		 DP_ADJUST_VOLTAGE_SWING_LANE0_SHIFT);
	uint8_t l = dp_link_status(link_status, i);

	return ((l >> s) & 0x3) << DP_TRAIN_VOLTAGE_SWING_SHIFT;
}

uint8_t drm_dp_get_adjust_request_pre_emphasis(const uint8_t link_status[DP_LINK_STATUS_SIZE],
					  int lane)
{
	int i = DP_ADJUST_REQUEST_LANE0_1 + (lane >> 1);
	int s = ((lane & 1) ?
		 DP_ADJUST_PRE_EMPHASIS_LANE1_SHIFT :
		 DP_ADJUST_PRE_EMPHASIS_LANE0_SHIFT);
	uint8_t l = dp_link_status(link_status, i);

	return ((l >> s) & 0x3) << DP_TRAIN_PRE_EMPHASIS_SHIFT;
}

void drm_dp_link_train_clock_recovery_delay(const uint8_t dpcd[DP_RECEIVER_CAP_SIZE]) {
	if (dpcd[DP_TRAINING_AUX_RD_INTERVAL] == 0)
		udelay(100);
	else
		mdelay(dpcd[DP_TRAINING_AUX_RD_INTERVAL] * 4);
}

void drm_dp_link_train_channel_eq_delay(const uint8_t dpcd[DP_RECEIVER_CAP_SIZE]) {
	if (dpcd[DP_TRAINING_AUX_RD_INTERVAL] == 0)
		udelay(400);
	else
		mdelay(dpcd[DP_TRAINING_AUX_RD_INTERVAL] * 4);
}

uint8_t drm_dp_link_rate_to_bw_code(int link_rate)
{
	switch (link_rate) {
	case 162000:
	default:
		return DP_LINK_BW_1_62;
	case 270000:
		return DP_LINK_BW_2_7;
	case 540000:
		return DP_LINK_BW_5_4;
	}
}

int drm_dp_bw_code_to_link_rate(uint8_t link_bw)
{
	switch (link_bw) {
	case DP_LINK_BW_1_62:
	default:
		return 162000;
	case DP_LINK_BW_2_7:
		return 270000;
	case DP_LINK_BW_5_4:
		return 540000;
	}
}

/**
 * DOC: dp helpers
 *
 * The DisplayPort AUX channel is an abstraction to allow generic, driver-
 * independent access to AUX functionality. Drivers can take advantage of
 * this by filling in the fields of the drm_dp_aux structure.
 *
 * Transactions are described using a hardware-independent drm_dp_aux_msg
 * structure, which is passed into a driver's .transfer() implementation.
 * Both native and I2C-over-AUX transactions are supported.
 */

static int drm_dp_dpcd_access(struct drm_dp_aux *aux, uint8_t request,
			      unsigned int offset, void *buffer, size_t size)
{
	struct drm_dp_aux_msg msg;
	unsigned int retry;
	int err;

	memset(&msg, 0, sizeof(msg));
	msg.address = offset;
	msg.request = request;
	msg.buffer = buffer;
	msg.size = size;

	/*
	 * The specification doesn't give any recommendation on how often to
	 * retry native transactions. We used to retry 7 times like for
	 * aux i2c transactions but real world devices this wasn't
	 * sufficient, bump to 32 which makes Dell 4k monitors happier.
	 */
	for (retry = 0; retry < 32; retry++) {

		err = aux->transfer(aux, &msg);
		if (err < 0) {
			if (err == -EBUSY)
				continue;

			return err;
		}


		switch (msg.reply & DP_AUX_NATIVE_REPLY_MASK) {
		case DP_AUX_NATIVE_REPLY_ACK:
			if (err < size)
				return -EPROTO;
			return err;

		case DP_AUX_NATIVE_REPLY_NACK:
			return -EIO;

		case DP_AUX_NATIVE_REPLY_DEFER:
			udelay(400);
			break;
		}
	}

	DRM_DEBUG_KMS("too many retries, giving up\n");
	return -EIO;
}

/**
 * drm_dp_dpcd_read() - read a series of bytes from the DPCD
 * @aux: DisplayPort AUX channel
 * @offset: address of the (first) register to read
 * @buffer: buffer to store the register values
 * @size: number of bytes in @buffer
 *
 * Returns the number of bytes transferred on success, or a negative error
 * code on failure. -EIO is returned if the request was NAKed by the sink or
 * if the retry count was exceeded. If not all bytes were transferred, this
 * function returns -EPROTO. Errors from the underlying AUX channel transfer
 * function, with the exception of -EBUSY (which causes the transaction to
 * be retried), are propagated to the caller.
 */
ssize_t drm_dp_dpcd_read(struct drm_dp_aux *aux, unsigned int offset,
			 void *buffer, size_t size)
{
	return drm_dp_dpcd_access(aux, DP_AUX_NATIVE_READ, offset, buffer,
				  size);
}

/**
 * drm_dp_dpcd_write() - write a series of bytes to the DPCD
 * @aux: DisplayPort AUX channel
 * @offset: address of the (first) register to write
 * @buffer: buffer containing the values to write
 * @size: number of bytes in @buffer
 *
 * Returns the number of bytes transferred on success, or a negative error
 * code on failure. -EIO is returned if the request was NAKed by the sink or
 * if the retry count was exceeded. If not all bytes were transferred, this
 * function returns -EPROTO. Errors from the underlying AUX channel transfer
 * function, with the exception of -EBUSY (which causes the transaction to
 * be retried), are propagated to the caller.
 */
ssize_t drm_dp_dpcd_write(struct drm_dp_aux *aux, unsigned int offset,
			  void *buffer, size_t size)
{
	return drm_dp_dpcd_access(aux, DP_AUX_NATIVE_WRITE, offset, buffer,
				  size);
}

/**
 * drm_dp_dpcd_read_link_status() - read DPCD link status (bytes 0x202-0x207)
 * @aux: DisplayPort AUX channel
 * @status: buffer to store the link status in (must be at least 6 bytes)
 *
 * Returns the number of bytes transferred on success or a negative error
 * code on failure.
 */
int drm_dp_dpcd_read_link_status(struct drm_dp_aux *aux,
				 uint8_t status[DP_LINK_STATUS_SIZE])
{
	return drm_dp_dpcd_read(aux, DP_LANE0_1_STATUS, status,
				DP_LINK_STATUS_SIZE);
}

/**
 * drm_dp_link_probe() - probe a DisplayPort link for capabilities
 * @aux: DisplayPort AUX channel
 * @link: pointer to structure in which to return link capabilities
 *
 * The structure filled in by this function can usually be passed directly
 * into drm_dp_link_power_up() and drm_dp_link_configure() to power up and
 * configure the link based on the link's capabilities.
 *
 * Returns 0 on success or a negative error code on failure.
 */
int drm_dp_link_probe(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
	uint8_t values[3];
	int err;

	memset(link, 0, sizeof(*link));

	err = drm_dp_dpcd_read(aux, DP_DPCD_REV, values, sizeof(values));
	if (err < 0)
		return err;

	link->revision = values[0];
	link->rate = drm_dp_bw_code_to_link_rate(values[1]);
	link->num_lanes = values[2] & DP_MAX_LANE_COUNT_MASK;

	if (values[2] & DP_ENHANCED_FRAME_CAP)
		link->capabilities |= DP_LINK_CAP_ENHANCED_FRAMING;

	return 0;
}

/**
 * drm_dp_link_power_up() - power up a DisplayPort link
 * @aux: DisplayPort AUX channel
 * @link: pointer to a structure containing the link configuration
 *
 * Returns 0 on success or a negative error code on failure.
 */
int drm_dp_link_power_up(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
	uint8_t value;
	int err;

	/* DP_SET_POWER register is only available on DPCD v1.1 and later */
	if (link->revision < 0x11)
		return 0;

	err = drm_dp_dpcd_readb(aux, DP_SET_POWER, &value);
	if (err < 0)
		return err;

	value &= ~DP_SET_POWER_MASK;
	value |= DP_SET_POWER_D0;

	err = drm_dp_dpcd_writeb(aux, DP_SET_POWER, value);
	if (err < 0)
		return err;

	/*
	 * According to the DP 1.1 specification, a "Sink Device must exit the
	 * power saving state within 1 ms" (Section 2.5.3.1, Table 5-52, "Sink
	 * Control Field" (register 0x600).
	 */
	udelay(1000);

	return 0;
}

/**
 * drm_dp_link_configure() - configure a DisplayPort link
 * @aux: DisplayPort AUX channel
 * @link: pointer to a structure containing the link configuration
 *
 * Returns 0 on success or a negative error code on failure.
 */
int drm_dp_link_configure(struct drm_dp_aux *aux, struct drm_dp_link *link)
{
	uint8_t values[2];
	int err;

	values[0] = drm_dp_link_rate_to_bw_code(link->rate);
	values[1] = link->num_lanes;

	if (link->capabilities & DP_LINK_CAP_ENHANCED_FRAMING)
		values[1] |= DP_LANE_COUNT_ENHANCED_FRAME_EN;

	err = drm_dp_dpcd_write(aux, DP_LINK_BW_SET, values, sizeof(values));
	if (err < 0)
		return err;

	return 0;
}

/*
 * Transfer a single I2C-over-AUX message and handle various error conditions,
 * retrying the transaction as appropriate.  It is assumed that the
 * aux->transfer function does not modify anything in the msg other than the
 * reply field.
 */
static int drm_dp_i2c_do_msg(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
	unsigned int retry;
	int err;

	/*
	 * DP1.2 sections 2.7.7.1.5.6.1 and 2.7.7.1.6.6.1: A DP Source device
	 * is required to retry at least seven times upon receiving AUX_DEFER
	 * before giving up the AUX transaction.
	 */
	for (retry = 0; retry < 7; retry++) {
		err = aux->transfer(aux, msg);
		if (err < 0) {
			if (err == -EBUSY)
				continue;

			DRM_DEBUG_KMS("transaction failed: %d\n", err);
			return err;
		}


		switch (msg->reply & DP_AUX_NATIVE_REPLY_MASK) {
		case DP_AUX_NATIVE_REPLY_ACK:
			/*
			 * For I2C-over-AUX transactions this isn't enough, we
			 * need to check for the I2C ACK reply.
			 */
			break;

		case DP_AUX_NATIVE_REPLY_NACK:
			DRM_DEBUG_KMS("native nack\n");
			return -EREMOTEIO;

		case DP_AUX_NATIVE_REPLY_DEFER:
			DRM_DEBUG_KMS("native defer");
			/*
			 * We could check for I2C bit rate capabilities and if
			 * available adjust this interval. We could also be
			 * more careful with DP-to-legacy adapters where a
			 * long legacy cable may force very low I2C bit rates.
			 *
			 * For now just defer for long enough to hopefully be
			 * safe for all use-cases.
			 */
			udelay(500);
			continue;

		default:
			DRM_ERROR("invalid native reply %#04x\n", msg->reply);
			return -EREMOTEIO;
		}

		switch (msg->reply & DP_AUX_I2C_REPLY_MASK) {
		case DP_AUX_I2C_REPLY_ACK:
			/*
			 * Both native ACK and I2C ACK replies received. We
			 * can assume the transfer was successful.
			 */
			if (err < msg->size)
				return -EPROTO;
			return 0;

		case DP_AUX_I2C_REPLY_NACK:
			DRM_DEBUG_KMS("I2C nack\n");
			aux->i2c_nack_count++;
			return -EREMOTEIO;

		case DP_AUX_I2C_REPLY_DEFER:
			DRM_DEBUG_KMS("I2C defer\n");
			aux->i2c_defer_count++;
			udelay(400);
			continue;

		default:
			DRM_ERROR("invalid I2C reply %#04x\n", msg->reply);
			return -EREMOTEIO;
		}
	}

	DRM_DEBUG_KMS("too many retries, giving up\n");
	return -EREMOTEIO;
}

int drm_dp_i2c_xfer(struct drm_dp_aux *aux, struct i2c_seg *msgs,
			   int num)
{
	unsigned int i, j;
	struct drm_dp_aux_msg msg;
	int err = 0;

	memset(&msg, 0, sizeof(msg));

	for (i = 0; i < num; i++) {
		msg.address = msgs[i].chip;
		msg.request = (msgs[i].read) ?
			DP_AUX_I2C_READ :
			DP_AUX_I2C_WRITE;
		msg.request |= DP_AUX_I2C_MOT;
		/* Send a bare address packet to start the transaction.
		 * Zero sized messages specify an address only (bare
		 * address) transaction.
		 */
		msg.buffer = NULL;
		msg.size = 0;
		err = drm_dp_i2c_do_msg(aux, &msg);
		if (err < 0)
			break;
		/*
		 * Many hardware implementations support FIFOs larger than a
		 * single byte, but it has been empirically determined that
		 * transferring data in larger chunks can actually lead to
		 * decreased performance. Therefore each message is simply
		 * transferred byte-by-byte.
		 */
		for (j = 0; j < msgs[i].len; j++) {
			msg.buffer = msgs[i].buf + j;
			msg.size = 1;

			err = drm_dp_i2c_do_msg(aux, &msg);
			if (err < 0)
				break;
		}
		if (err < 0)
			break;
	}
	if (err >= 0)
		err = num;
	/* Send a bare address packet to close out the transaction.
	 * Zero sized messages specify an address only (bare
	 * address) transaction.
	 */
	msg.request &= ~DP_AUX_I2C_MOT;
	msg.buffer = NULL;
	msg.size = 0;
	(void)drm_dp_i2c_do_msg(aux, &msg);

	return err;
}
