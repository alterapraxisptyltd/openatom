iport=0x2000
dport=0x2004
stsport=0x204c
timer=0x3f54

hex=0-9,a-f

header="
#include <arch/io.h>
#include <pc80/vga_io.h>
#include <delay.h>

static void sync_read(void)
{
	vga_enable_read();
	inl($stsport);
}

static uint32_t radeon_read(uint32_t reg_addr)
{
	outl(reg_addr, $iport);
	return inl($dport);
}

static void radeon_write(uint32_t reg_addr, uint32_t value)
{
	outl(reg_addr, $iport);
	outl(value, $dport);
}

static uint32_t radeon_read_sync(uint32_t reg_addr)
{
	sync_read();
	return radeon_read(reg_addr);
}

static void radeon_write_sync(uint32_t reg_addr, uint32_t value)
{
	sync_read();
	radeon_write(reg_addr, value);
}

static void radeon_delay(uint32_t internal_timer)
{
	/* Based on a 50MHz internal_timer. YMMV */
	udelay(internal_timer / 50);
}

void run_replay(void)
{"

echo "$header"

egrep "c000:[$hex]{4}|x86emuOp_halt|runInt[$hex]{2}.*starting" $1 |
grep -v "Running option rom at c000:0003" |
sed "s/c000\:[$hex]\{4\}\ /\t/g" |

tr '\n' '\r' |

sed "/\r/s/\[[$hex]\{8\}\]//g" |
sed "s/)/);/g" |
sed "s/=\ 0x\([$hex]*\)/\/\*\ \1\ \*\//g" |

sed "s/outl(0x0\{0,4\}\([$hex]*\), $iport);[^\r]*\r\toutl(0x\([$hex]*\), $dport);/radeon_write(0x\1, 0x\2);/g" |
sed "s/outl(0x0\{0,4\}\([$hex]*\), $iport);[^\r]*\r\tinl($dport);/radeon_read(0x\1);/g" |

sed "s/inb(0x03c3);[^\r]*\r\tinl($stsport);[^\r]*/sync_read();/g" |

sed "s/sync_read();[^\r]*\r\tradeon_write(/radeon_write_sync(/g" |
sed "s/sync_read();[^\r]*\r\tradeon_read(/radeon_read_sync(/g" |

sed "s/outb(0x\([$hex]*\), 0x03c2);/vga_misc_write(0x\1);/g" |
sed "s/inb(0x03cc);/vga_misc_read();/g" |
sed "s/inb(0x03c3));/vga_enable_read();/g" |
sed "s/outw(0x\([$hex]\{2\}\)\([$hex]\{2\}\), 0x03c4);/outw(0x\1\2, 0x03c4);\/\*\ vga_sr_write(0x\2, 0x\1); \*\//g" |
sed "s/outb(0x\([$hex]*\), 0x03c4);[^\r]*\r\tinb(0x03c5);/vga_sr_read(0x\1);/g" |
sed "s/outb(0x\([$hex]*\), 0x03ce);[^\r]*\r\toutb(0x\([$hex]*\), 0x03cf);/vga_gr_write(0x\1, 0x\2);/g" |

sed "s/radeon_read($timer);[^$hex\r]*\([$hex]*\)[^\r]*\(\r\tinl($dport);[^$hex\r]*\([$hex]*\)[^\r]*\)*/radeon_delay(0x\3 - 0x\1);/g" |

sed "/\r/s/halt_sys: in x86emuOp_halt/}\r/g" |
sed "/\r/s/[^\r]*runInt[$hex]*();: starting execution of INT\([$hex]*\)[^\r]*/void replay_int\1(void)\r{/g" |

tr '\r' '\n'
