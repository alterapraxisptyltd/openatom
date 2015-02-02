#include <stdbool.h>
#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>


#include "radeon_util.h"
#include "vga_io.h"

typedef uint32_t radeon_read_op_t(uint32_t reg_addr);
typedef void radeon_write_op_t(uint32_t reg_addr, uint32_t value);
typedef void sync_read_op_t(void);

static bool radeon_iotrace = false;

void radeon_enable_iotracing(void)
{
	radeon_iotrace = true;
}

void radeon_disable_iotracing(void)
{
	radeon_iotrace = false;
}

uint32_t radeon_reg_read(uint32_t reg_addr)
{
	return radeon_read_sync(reg_addr << 2);
}

void radeon_reg_write(uint32_t reg_addr, uint32_t value)
{
	radeon_write_sync(reg_addr << 2, value);
}

void radeon_reg_mask(uint32_t reg, uint32_t clrbits, uint32_t setbits)
{
	uint32_t reg32 = radeon_reg_read(reg);
	reg32 &= ~clrbits;
	reg32 |= setbits;
	radeon_reg_write(reg, reg32);
}

static void udelay(uint32_t usecs)
{
	usleep(usecs);
}

static void sync_read_op(void)
{
	vga_enable_read();
	inl(0x204c);
}

static uint32_t radeon_read_op_pio(uint32_t reg_addr)
{
	outl(reg_addr, 0x2000);
	return inl(0x2004);
}

static void radeon_write_op_pio(uint32_t reg_addr, uint32_t value)
{
	outl(reg_addr, 0x2000);
	outl(value, 0x2004);
}

static void *mmio_base = NULL;
static void sync_read_nop(void)
{
}

static uint32_t radeon_read_op_mmio(uint32_t reg_addr)
{
	volatile uint32_t *base = (void *)((uintptr_t)mmio_base + reg_addr);
	return *base;
}

static void radeon_write_op_mmio(uint32_t reg_addr, uint32_t value)
{
	volatile uint32_t *base = (void *)((uintptr_t)mmio_base + reg_addr);
	*base = value;
}

radeon_read_op_t *master_read_op = radeon_read_op_pio;
radeon_write_op_t *master_write_op = radeon_write_op_pio;
sync_read_op_t *master_sync_op = sync_read_op;

void radeon_init_mmio(void)
{
	int fd;

	fd = open("/dev/mem", O_RDWR | O_SYNC);

	if (fd == -1) {
		fprintf(stderr, "No /dev/mem ? %s\n", strerror(errno));
		return;
	}

	mmio_base = mmap(0, 0x40000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0xf0380000);
	if (mmio_base == MAP_FAILED) {
		mmio_base = NULL;
		fprintf(stderr, "mmap() failed %s\n", strerror(errno));
		return;
	}

	fprintf(stderr, "pointing to %p\n", mmio_base);

	master_read_op = radeon_read_op_mmio;
	master_write_op = radeon_write_op_mmio;
	master_sync_op = sync_read_nop;
}

void sync_read(void)
{
	if (radeon_iotrace)
		fprintf(stderr, "\t%s();\n", __func__);
	master_sync_op();
}

uint32_t radeon_read(struct radeon_device *rdev, uint32_t reg)
{
	uint32_t reg32;

	(void) rdev;

	reg32 = master_read_op(reg);
	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x); /* %08x */\n", __func__, reg, reg32);
	return reg32;
}

void radeon_write(struct radeon_device *rdev, uint32_t reg, uint32_t value)
{
	(void) rdev;

	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x, 0x%08x);\n", __func__, reg, value);
	master_write_op(reg, value);
}

uint32_t radeon_read_io(struct radeon_device *rdev, uint32_t reg)
{
	uint32_t reg32;

	(void) rdev;

	reg32 = radeon_read_op_pio(reg);
	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x); /* %08x */\n", __func__, reg, reg32);
	return reg32;
}

void radeon_write_io(struct radeon_device *rdev, uint32_t reg, uint32_t value)
{
	(void) rdev;

	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x, 0x%08x);\n", __func__, reg, value);
	radeon_write_op_pio(reg, value);
}

uint32_t radeon_read_old(uint32_t reg_addr)
{
	return radeon_read(NULL, reg_addr);
}

void radeon_write_old(uint32_t reg_addr, uint32_t value)
{
	radeon_write(NULL, reg_addr, value);
}

uint32_t radeon_read_io_old(uint32_t reg_addr)
{
	return radeon_read_io(NULL, reg_addr);
}

void radeon_write_io_old(uint32_t reg_addr, uint32_t value)
{
	radeon_write_io(NULL, reg_addr, value);
}

uint32_t radeon_read_sync(uint32_t reg_addr)
{
	uint32_t reg32;
	master_sync_op();
	reg32 = master_read_op(reg_addr);
	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x); /* %08x */\n", __func__, reg_addr, reg32);
	return reg32;
}

void radeon_write_sync(uint32_t reg_addr, uint32_t value)
{
	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%04x, 0x%08x);\n", __func__, reg_addr, value);
	master_sync_op();
	master_write_op(reg_addr, value);
}

void radeon_delay(uint32_t internal_timer)
{
	if (radeon_iotrace)
		fprintf(stderr, "\t%s(0x%08x);\n", __func__, internal_timer);
	master_sync_op();
	master_write_op(0x3f50, 0x0);
	/* Based on a 50MHz internal_timer. YMMV */
	udelay(internal_timer / 50);
}

void radeon_udelay(uint32_t usec)
{
	radeon_delay(usec * 50);
}
