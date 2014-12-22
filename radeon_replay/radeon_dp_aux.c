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

#define DP_AUX_NATIVE_REPLY_ACK		(0x0 << 0)
#define DP_AUX_NATIVE_REPLY_NACK	(0x1 << 0)
#define DP_AUX_NATIVE_REPLY_DEFER	(0x2 << 0)
#define DP_AUX_NATIVE_REPLY_MASK	(0x3 << 0)

#define DP_AUX_I2C_REPLY_ACK		(0x0 << 2)
#define DP_AUX_I2C_REPLY_NACK		(0x1 << 2)
#define DP_AUX_I2C_REPLY_DEFER		(0x2 << 2)
#define DP_AUX_I2C_REPLY_MASK		(0x3 << 2)

static const uint16_t padoff[] = {0, 0x14, 0x28, 0x40, 0x54, 0x68};

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

/*
 * [PATCH 12/48] drm/radeon/kms: DP aux updates for DCE6
 * From: Alex Deucher <alexander.deucher at amd.com>
 *
 * DCE6 requires a non-0 value for lpAuxRequest for the
 * ProcessAuxChannelTransaction command table. Setting lpAuxRequest to 0 is a
 * special case used by AsicInit for setting up the aux pads.
 */
uint8_t radeon_init_aux_pads(void)
{
	int i;
	//   01a7: SET_DATA_BLOCK  ff  (this table)
	//   01a9: ADD    WS_DATAPTR [..XX]  <-  020f
	////dataptr = data;
	for (i = 0; i < 6; i++) {
		//   01ae: MOVE   WS_REGPTR [..XX]  <-  data[0000] [..XX]
		//   01b3: MOVE   reg[1888]  [XXXX]  <-  00320000
		radeon_reg_write(0x1888 + padoff[i], 0x00320000);
		//   01bb: MOVE   reg[1889]  [XXXX]  <-  00001c00
		radeon_reg_write(0x1889 + padoff[i], 0x00001c00);
		//   01c3: MOVE   reg[188a]  [XXXX]  <-  123d1210
		radeon_reg_write(0x188a + padoff[i], 0x123d1210);
		//   01cb: ADD    WS_DATAPTR [..XX]  <-  0004
		//   01d0: ADD    lpAuxRequest_low  <-  01
		//   01d4: COMP   lpAuxRequest_low  <-  06
		//   01d8: JUMP_NotEqual  01ae
	}
	//   01db: CLEAR  WS_REGPTR [..XX]
	//   01de: MOVE   WS_REMIND/HI32 [...X]  <-  10
	for (i = 0x10; i--; i != 0) {
		//   01e2: OR     reg[197f]  [..X.]  <-  40
		radeon_reg_mask(0x197f, 0, 0x40 << 8);
		//   01e7: AND    reg[197f]  [..X.]  <-  bf
		radeon_reg_mask(0x197f, ~0xffffbfff, 0);
		//   01ec: SUB    WS_REMIND/HI32 [...X]  <-  01
		//   01f0: COMP   WS_REMIND/HI32 [...X]  <-  00
		//   01f4: JUMP_NotEqual  01e2
	}
	//   01f7: OR     reg[190b]  [...X]  <-  01
	radeon_reg_mask(0x190b, 0, 0x01);
	//   01fc: CLEAR  reg[190b]  [.X..]
	radeon_reg_mask(0x190b, 0xff << 16, 0);
	//   0200: OR     reg[190c]  [...X]  <-  01
	radeon_reg_mask(0x190c, 0, 0x01);
	//   0205: CLEAR  reg[190c]  [.X..]
	radeon_reg_mask(0x190b, 0xff << 16, 0);
	//   0209: DELAY_MicroSec  32
	radeon_udelay(0x32);
	//   020b: EOT
	return 0;
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
	fprintf(stderr, "Gotz beck leik %u baitz %x\n", num_bytes_received, reply);

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
					 uint8_t delay, uint8_t *reply)
{
	int ret, retry;
	uint8_t recv_bytes = 0, hpd_id = 2;

	/* Default the reply field to something absurd */
	*reply = 0xff;

	/* Retry six times. That keeps us busy for 3ms or less */
	for (retry = 0; retry < 6; retry++) {
		ret = do_aux_tran(chan, delay / 10, hpd_id, send, send_bytes,
				  recv, recv_size, &recv_bytes);
		*reply = (ret & 0xff) >> 4;

		if (ret == -EBUSY)
			continue;
		else if (ret < 0)
			break;

		switch (*reply & DP_AUX_NATIVE_REPLY_MASK) {
		case DP_AUX_NATIVE_REPLY_ACK:
			return recv_bytes;
		case DP_AUX_NATIVE_REPLY_DEFER:
			fprintf(stderr, "defer\n");
			usleep(400);
			continue;
		default:
			return -EIO;
		}
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
	uint8_t msg[4], reply;
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
					    recv, recv_bytes, delay, &reply);

	return ret;
}


static int radeon_dp_aux_i2c_write(uint8_t bus, uint8_t address, uint8_t reg, uint8_t delay)
{
	int ret;
	uint8_t msg[5], reply;

	msg[0] = (DP_AUX_I2C_WRITE | DP_AUX_I2C_MOT) << 4;
	msg[1] = 0;
	msg[2] = address;
	msg[3] = 0;
	msg[4] = reg;

	ret = radeon_process_aux_ch_wrapper(bus, msg, sizeof(msg),
					    NULL, 0, delay, &reply);

	return ret;
}

static int radeon_dp_aux_i2c_stop(uint8_t bus, uint8_t address, uint8_t delay)
{
	int ret;
	uint8_t msg[3], reply;

	msg[0] = (DP_AUX_I2C_READ) << 4;
	msg[1] = 0;
	msg[2] = address;

	ret = radeon_process_aux_ch_wrapper(bus, msg, sizeof(msg),
					    NULL, 0, delay, &reply);

	return ret;
}

static int radeon_dp_aux_i2c_read(uint8_t bus, uint16_t address, uint8_t reg,
				  uint8_t *recv, int recv_bytes, uint8_t delay)
{
	int ret;
	uint8_t msg[4], reply;

	if (recv_bytes == 0)
		return -EINVAL;

	/* FIXME: We could break up the big transaction into smaller chunks */
	if (recv_bytes > 16)
		return -EINVAL;

	msg[0] = (DP_AUX_I2C_READ | DP_AUX_I2C_MOT) << 4;
	msg[1] = 0;
	msg[2] = address;
	msg[3] = recv_bytes - 1;

	ret = radeon_process_aux_ch_wrapper(bus, msg, sizeof(msg),
					    recv, recv_bytes, delay, &reply);

	return ret;
}

uint8_t radeon_read_dpcd_reg(uint8_t bus, uint16_t reg)
{
	uint8_t val;

	radeon_dp_aux_native_read(bus, reg, &val, 1, 0);

	return val;
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

int radeon_read_dp_aux_i2c(uint8_t bus, uint8_t addr,
		    uint8_t *dest, uint8_t start, uint16_t len)
{
	int ret;

	for (; len != 0; len -= MIN(16, len), dest += 16, start += 16) {
		ret = radeon_dp_aux_i2c_write(bus, addr, start, 0);
		if (ret < 0) {
			fprintf(stderr, "I²C: address write failed\n");
			goto force_i2c_stop;
		}

		ret = radeon_dp_aux_i2c_read(bus, addr, start, dest, MIN(16, len), 0);
		if ((ret < 0) || (ret != MIN(16, len))) {
			fprintf(stderr, "I²C: Got less data than expected\n");
			ret = -EAGAIN;
			goto force_i2c_stop;
		}

		ret = radeon_dp_aux_i2c_stop(bus, addr, 0);
		if (ret < 0) {
			fprintf(stderr, "I²C: Could not stop transaction\n");
			goto force_i2c_stop;
		}
	}
	return 0;

force_i2c_stop:
	ret = radeon_dp_aux_i2c_stop(bus, addr, 0);
	return ret;
}
