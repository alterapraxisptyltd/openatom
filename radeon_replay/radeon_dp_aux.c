#include "radeon_init_native.h"
#include "radeon_util.h"

#include <errno.h>
#include <stdio.h>
#include <unistd.h>

/* NOTE: These names are based on what _we_think_ these registers do */
#define REG_DP_AUX_CTL			0x1880
#define REG_DP_AUX_FIFO_CTL		0x1881
#define REG_DP_AUX_STATUS		0x1884
#define REG_DP_AUX_FIFO			0x1886

#define DP_AUX_I2C_WRITE		0x0
#define DP_AUX_I2C_READ			0x1
#define DP_AUX_I2C_STATUS		0x2
#define DP_AUX_I2C_MOT			0x4
#define DP_AUX_NATIVE_WRITE		0x8
#define DP_AUX_NATIVE_READ		0x9

#define DP_AUX_NATIVE_REPLY_MASK		(3 << 4)
#define DP_AUX_NATIVE_REPLY_ACK			(0 << 4)
#define DP_AUX_NATIVE_REPLY_NAK			(1 << 4)
#define DP_AUX_NATIVE_REPLY_DEFER		(2 << 4)
#define DP_AUX_I2C_REPLY_MASK			(3 << 4)
#define DP_AUX_I2C_REPLY_ACK			(0 << 6)
#define DP_AUX_I2C_REPLY_NAK			(1 << 6)
#define DP_AUX_I2C_REPLY_DEFER			(2 << 6)


static void aux_channel_fifo_write_start(uint8_t channel, uint8_t data)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (channel * 4);
	radeon_reg_write(reg, data << 8 | (1 << 31));
}

static void aux_channel_fifo_write(uint8_t channel, uint8_t data)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (channel * 4);
	radeon_reg_write(reg, data << 8);
}

static uint8_t aux_channel_fifo_read(uint8_t channel)
{
	uint32_t reg;
	reg = REG_DP_AUX_FIFO + (channel * 4);
	return (radeon_reg_read(reg) >> 8) & 0xff;
}

static int do_aux_tran(uint8_t channel_id, uint8_t delay, uint8_t hpd_id,
		       const uint8_t *msg, uint8_t send_bytes,
		       uint8_t *recv, uint8_t recv_size, uint8_t *num_received)
{
	int i, wait;
	uint32_t regptr;
	uint8_t reply, num_bytes_received;

	*num_received = 0;

	regptr = channel_id * 0x04;
	radeon_reg_mask(0x194c + regptr, 0, 0x01 << 16);
	radeon_reg_mask(0x194c + regptr, 0xffff, 0);

	regptr = channel_id * 0x14;

	radeon_reg_mask(REG_DP_AUX_CTL + regptr, 0x7 << 28, (hpd_id & 0x7) << 28);
	radeon_reg_mask(REG_DP_AUX_CTL + regptr, 0, 0x0101);

	/* Tell controller how many bytes we want to send */
	radeon_reg_mask(REG_DP_AUX_FIFO_CTL + regptr, 0xff << 16, send_bytes << 16);
	radeon_reg_mask(REG_DP_AUX_FIFO_CTL + regptr, 0xff, (delay << 4) & 0xff);

	/* Caller should make sure message is 16 bytes or less */
	aux_channel_fifo_write_start(channel_id, *msg++);
	while (--send_bytes)
		aux_channel_fifo_write(channel_id, *msg++);

	radeon_reg_mask(0x1883 + regptr, 0, 0x02);
	radeon_reg_mask(REG_DP_AUX_FIFO_CTL + regptr, 0, 0x01);

	wait = (delay * 10 + 0x32);
	while ((radeon_reg_read(REG_DP_AUX_STATUS + regptr) & 0xff) != 0x01) {
		radeon_udelay(10);
		if (--wait != 0)
			continue;
		/* Timed out */
		return -ETIMEDOUT;
	}

	if (radeon_reg_read(REG_DP_AUX_STATUS + regptr) == 0x00ff8ff0)
		return -EBUSY;

	radeon_reg_write(REG_DP_AUX_FIFO + regptr, 0x80000001);

	reply = aux_channel_fifo_read(channel_id);
	num_bytes_received = (radeon_reg_read(REG_DP_AUX_STATUS + regptr) >> 24) & 0x1f;

	if (num_bytes_received == 0)
		return -EIO;

	/* First byte is the reply field. The others are the data bytes */
	if (--num_bytes_received == 0)
		return reply;

	for (i = 0; i < MIN(num_bytes_received, recv_size); i++)
		recv[i] = aux_channel_fifo_read(channel_id);

	/* This extra data is lost forever. TODO: Signal an error? */
	for (; i < num_bytes_received; i++)
		aux_channel_fifo_read(channel_id);

	*num_received = num_bytes_received;
	return reply;
}

static int radeon_process_aux_ch_wrapper(uint8_t chan,
					 uint8_t *send, int send_bytes,
					 uint8_t *recv, int recv_size,
					 uint8_t delay, uint8_t *ack)
{
	int ret, retry;
	uint8_t recv_bytes = 0, hpd_id = 2, reply;

	/* Retry six times. That keeps us busy for 3ms or less */
	for (retry = 0; retry < 6; retry++) {
		ret = do_aux_tran(chan, delay / 10, hpd_id, send, send_bytes,
				  recv, recv_size, &recv_bytes);
		*ack = ret & 0xff;

		reply = *ack & DP_AUX_NATIVE_REPLY_MASK;

		if (ret == -EBUSY)
			continue;
		else if (ret < 0)
			break;

		if (reply == DP_AUX_NATIVE_REPLY_ACK)
			return recv_bytes;
		else if (reply == DP_AUX_NATIVE_REPLY_DEFER) {
			fprintf(stderr, "defer\n");
			usleep(400);
			continue;
		}
		else
			return -EIO;
	}

	if (ret == -EIO) {
		fprintf(stderr, "AUX channel error\n");
		return -EIO;
	}

	if (ret == -ETIMEDOUT) {
		fprintf(stderr, "AUX channel timeout\n");
		return -ETIMEDOUT;
	}

	if (ret == -EBUSY) {
		fprintf(stderr, "AUX channel busy\n");
		return -EBUSY;
	}

	return ret;
}

static int radeon_dp_aux_native_read(uint8_t bus,
				     uint16_t address, uint8_t *recv, int recv_bytes, uint8_t delay)
{
	uint8_t msg[4], ack;
	int ret;

	if (recv_bytes == 0)
		return -EINVAL;

	/* FIXME: We could break up the big transaction into smaller chunks */
	if (recv_bytes > 16)
		return -EINVAL;

	/* NOTE: address can be up to 20 bits */
	msg[0] = DP_AUX_NATIVE_READ << 4;
	msg[1] = address >> 8;
	msg[2] = address;
	msg[3] = recv_bytes - 1;

	ret = radeon_process_aux_ch_wrapper(bus, msg, sizeof(msg),
					    recv, recv_bytes, delay, &ack);

	return ret;
}

int radeon_read_dpcd(uint8_t bus, uint8_t *dest, uint16_t start, uint16_t len)
{
	int ret;

	for (; len != 0; len -= MIN(16, len), dest += 16, start += 16) {
		ret = radeon_dp_aux_native_read(bus, start, dest, MIN(16, len), 0);
		if (ret < 0)
			return ret;
		if (ret != MIN(16, len))
			return -EAGAIN;
	}
	return 0;
}
