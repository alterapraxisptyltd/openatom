#include <stdio.h>
#include <sys/io.h>
#include <unistd.h>

#include "radeon_util.h"
#include "vga_io.h"

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

static uint32_t radeon_read_op(uint32_t reg_addr)
{
	outl(reg_addr, 0x2000);
	return inl(0x2004);
}

static void radeon_write_op(uint32_t reg_addr, uint32_t value)
{
	outl(reg_addr, 0x2000);
	outl(value, 0x2004);
}

void sync_read(void)
{
	fprintf(stderr, "\t%s();\n", __func__);
	sync_read_op();
}

uint32_t radeon_read(uint32_t reg_addr)
{
	uint32_t reg32;
	reg32 = radeon_read_op(reg_addr);
	fprintf(stderr, "\t%s(0x%04x); /* %08x */\n", __func__, reg_addr, reg32);
	return reg32;
}

void radeon_write(uint32_t reg_addr, uint32_t value)
{
	fprintf(stderr, "\t%s(0x%04x, 0x%08x);\n", __func__, reg_addr, value);
	outl(reg_addr, 0x2000);
	outl(value, 0x2004);
}

uint32_t radeon_read_sync(uint32_t reg_addr)
{
	uint32_t reg32;
	sync_read_op();
	reg32 = radeon_read_op(reg_addr);
	fprintf(stderr, "\t%s(0x%04x); /* %08x */\n", __func__, reg_addr, reg32);
	return reg32;
}

void radeon_write_sync(uint32_t reg_addr, uint32_t value)
{
	fprintf(stderr, "\t%s(0x%04x, 0x%08x);\n", __func__, reg_addr, value);
	sync_read_op();
	radeon_write_op(reg_addr, value);
}

void radeon_delay(uint32_t internal_timer)
{
	fprintf(stderr, "\t%s(0x%08x);\n", __func__, internal_timer);
	sync_read_op();
	radeon_write_op(0x3f50, 0x0);
	/* Based on a 50MHz internal_timer. YMMV */
	udelay(internal_timer / 50);
}

void radeon_udelay(uint32_t usec)
{
	radeon_delay(usec * 50);
}
