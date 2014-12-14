#include <sys/io.h>
#include <unistd.h>

#include "radeon_util.h"

void udelay(uint32_t usecs)
{
	usleep(usecs);
}

void sync_read(void)
{
	vga_enable_read();
	inl(0x204c);
}

uint32_t radeon_read(uint32_t reg_addr)
{
	outl(reg_addr, 0x2000);
	return inl(0x2004);
}

void radeon_write(uint32_t reg_addr, uint32_t value)
{
	outl(reg_addr, 0x2000);
	outl(value, 0x2004);
}

uint32_t radeon_read_sync(uint32_t reg_addr)
{
	sync_read();
	return radeon_read(reg_addr);
}

void radeon_write_sync(uint32_t reg_addr, uint32_t value)
{
	sync_read();
	radeon_write(reg_addr, value);
}

uint32_t radeon_delay(uint32_t internal_timer)
{
	radeon_write_sync(0x3f50, 0x0);
	/* Based on a 50MHz internal_timer. YMMV */
	udelay(internal_timer / 50);
}
