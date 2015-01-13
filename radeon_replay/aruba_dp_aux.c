#include "drm_dp_helper.h"
#include "linux_glue.h"
#include "radeon_init_native.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

/* NOTE: These names are based on what _we_think_ these registers do */
#define REG_DP_AUX_CTL			(0x1880 << 2)
#define REG_DP_AUX_FIFO_CTL		(0x1881 << 2)
#define REG_DP_AUX_CTL2			(0x1883 << 2)
#define REG_DP_AUX_STATUS		(0x1884 << 2)
#define  XFER_DONE			BIT(0)
#define  AUX_ERROR_FLAGS		0x00ff8ff0
#define REG_DP_AUX_FIFO			(0x1886 << 2)
#define REG_AUX_PAD_EN_CTL		(0x194c << 2)

/*
 * This tells us the offset of each AUX control block from the first block.
 * It is given in number of 32-bit registers, so it needs to be multiplied by
 * 4 before converting it to an address offset.
 */
static const uint16_t aux_ch_reg[] = {0, 0x14, 0x28, 0x40, 0x54, 0x68};

static void aux_channel_fifo_write_start(struct radeon_device *rdev, uint8_t channel, uint8_t data)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (aux_ch_reg[channel] << 2);
	aruba_write(rdev, reg, (data << 8) | (1 << 31));
}

static void aux_channel_fifo_write(struct radeon_device *rdev, uint8_t channel, uint8_t data)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (aux_ch_reg[channel] << 2);
	aruba_write(rdev, reg, data << 8);
}

static uint8_t aux_channel_fifo_read(struct radeon_device *rdev, uint8_t channel)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (aux_ch_reg[channel] << 2);
	return (aruba_read(rdev, reg) >> 8) & 0xff;
}


static int do_aux_tran(struct radeon_device *rdev,
		       uint8_t channel_id, uint8_t hpd_id,
		       const uint8_t *msg, uint8_t send_bytes,
		       uint8_t *recv, uint8_t recv_size, uint8_t *reply)
{
	int i, wait;
	uint32_t regptr;
	uint8_t num_bytes_received;

	regptr = channel_id * 0x04 << 2;
	aruba_mask(rdev, REG_AUX_PAD_EN_CTL + regptr, 0xffff, 0x01 << 16);

	regptr = aux_ch_reg[channel_id] << 2;

	aruba_mask(rdev, REG_DP_AUX_CTL + regptr, 0x7 << 20,
				       ((hpd_id & 0x7) << 20) | 0x0101);

	/* Tell controller how many bytes we want to send */
	aruba_mask(rdev, REG_DP_AUX_FIFO_CTL + regptr, 0xff00ff, send_bytes << 16);

	/* Caller should make sure message is 16 bytes or less */
	aux_channel_fifo_write_start(rdev, channel_id, *msg++);
	while (--send_bytes)
		aux_channel_fifo_write(rdev, channel_id, *msg++);

	aruba_mask(rdev, REG_DP_AUX_CTL2 + regptr, 0, 0x02);
	aruba_mask(rdev, REG_DP_AUX_FIFO_CTL + regptr, 0, 0x01);

	wait = 50;
	while (!(aruba_read(rdev, REG_DP_AUX_STATUS + regptr) & XFER_DONE)) {
		radeon_udelay(10);
		if (--wait != 0)
			continue;
		/* Timed out */
		return -ETIMEDOUT;
	}

	if (aruba_read(rdev, REG_DP_AUX_STATUS + regptr) & AUX_ERROR_FLAGS)
		return -EBUSY;

	aruba_write(rdev, REG_DP_AUX_FIFO + regptr, 0x80000001);

	*reply = aux_channel_fifo_read(rdev, channel_id);
	num_bytes_received = (aruba_read(rdev, REG_DP_AUX_STATUS + regptr) >> 24) & 0x1f;

	if (num_bytes_received == 0)
		return -EIO;

	/* First byte is the reply field. The others are the data bytes */
	if (--num_bytes_received == 0)
		return num_bytes_received;

	for (i = 0; i < min(num_bytes_received, recv_size); i++)
		recv[i] = aux_channel_fifo_read(rdev, channel_id);

	/* This extra data is lost forever. TODO: Signal an error? */
	for (; i < num_bytes_received; i++)
		aux_channel_fifo_read(rdev, channel_id);

	return num_bytes_received;
}

static int radeon_process_aux_ch_wrapper(struct radeon_i2c_chan *chan,
					 uint8_t *send, int send_bytes,
					 uint8_t *recv, int recv_size,
					 uint8_t *reply)
{
	struct drm_device *dev = chan->dev;
	struct radeon_device *rdev = dev->dev_private;

	int ret;
	uint8_t hpd_id, ch_id;

	/* TODO: Actually, there are only five HPD pins and five AUX channels */
	hpd_id = chan->rec.hpd & 0x7;
	ch_id = chan->rec.i2c_id & 0x7;

	ret = do_aux_tran(rdev, ch_id, hpd_id, send, send_bytes,
			  recv, recv_size, reply);
	/* The hardware gives us a full byte, but we need bits [4:7] */
	*reply >>= 4;

	if (ret == -EIO) {
		DRM_DEBUG_KMS("AUX channel error\n");
		return -EIO;
	}

	if (ret == -ETIMEDOUT) {
		DRM_DEBUG_KMS("AUX channel timeout\n");
		return -ETIMEDOUT;
	}

	if (ret == -EBUSY) {
		DRM_DEBUG_KMS("AUX channel busy\n");
		return -EBUSY;
	}

	return ret;
}

uint8_t radeon_read_dpcd_reg(uint8_t bus, uint16_t reg)
{
	uint8_t val;

	drm_dp_dpcd_readb(&my_aux, reg, &val);

	return val;
}

int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len)
{
	int ret;

	for (; len != 0; len -= min(16, len), dest += 16, start += 16) {
		ret = drm_dp_dpcd_read(&my_aux, start, dest, min(16, len));
		if (ret < 0)
			return ret;
		if (ret != min(16, len))
			return -EAGAIN;
	}
	return 0;
}

int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
				   uint8_t *dest, uint8_t start, uint16_t len)
{
	int ret;

	struct i2c_seg msgs[2];

	for (; len != 0; len -= min(16, len), dest += 16, start += 16) {
		msgs[0].chip = addr;
		msgs[0].len = 1;
		msgs[0].buf = &start;
		msgs[0].read = 0;

		msgs[1].chip = addr;
		msgs[1].len = min(16, len);
		msgs[1].buf = dest;
		msgs[1].read = 1;

		ret = drm_dp_i2c_xfer(&my_aux, msgs, 2);

		if (ret < 0) {
			DRM_DEBUG_KMS("I²C: failed to complete transaction\n");
			return ret;
		}
	}
	return 0;
}


#define BARE_ADDRESS_SIZE 3
#define HEADER_SIZE (BARE_ADDRESS_SIZE + 1)

ssize_t aruba_dp_aux_transfer(struct drm_dp_aux *aux, struct drm_dp_aux_msg *msg)
{
	struct radeon_i2c_chan *chan = &my_i2c;

	int ret;
	uint8_t tx_buf[20];
	size_t tx_size;
	uint8_t ack;

	if (msg->size > 16)
		return -E2BIG;

	tx_buf[0] = (msg->request << 4) | ((msg->address >> 16) & 0xf);
	tx_buf[1] = msg->address >> 8;
	tx_buf[2] = msg->address & 0xff;
	tx_buf[3] = msg->size ? (msg->size - 1) : 0;

	switch (msg->request & ~DP_AUX_I2C_MOT) {
	case DP_AUX_NATIVE_WRITE:
	case DP_AUX_I2C_WRITE:
		tx_size = (msg->size) ? (HEADER_SIZE + msg->size) : BARE_ADDRESS_SIZE;

		memcpy(tx_buf + HEADER_SIZE, msg->buffer, msg->size);
		ret = radeon_process_aux_ch_wrapper(chan,
					    tx_buf, tx_size, NULL, 0, &ack);
		if (ret >= 0)
			/* Return payload size. */
			ret = msg->size;
		break;
	case DP_AUX_NATIVE_READ:
	case DP_AUX_I2C_READ:
		tx_size = (msg->size) ? HEADER_SIZE : BARE_ADDRESS_SIZE;
		ret = radeon_process_aux_ch_wrapper(chan,
					    tx_buf, tx_size, msg->buffer, msg->size, &ack);
		break;
	default:
		ret = -EINVAL;
		break;
	}

	if (ret >= 0)
		msg->reply = ack;

	return ret;
}

struct drm_dp_aux my_aux = {
	.transfer = aruba_dp_aux_transfer,
	.i2c_nack_count = 0,
	.i2c_defer_count = 0,
};
