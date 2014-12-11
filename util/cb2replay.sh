iport=0x2000
dport=0x2004
stsport=0x204c

header="
#include <arch/io.h>

static void sync_read(void)
{
	inb(0x03c3);
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

void run_replay(void)
{"

echo "$header"

egrep "c000:[0-9,a-f]{4}" $1 |
grep -v "Running option rom at c000:0003" |
sed "s/c000\:[0-9,a-f]\{4\}\ /\t/g" |

tr '\n' '\r' |

sed "/\r/s/\[[0-9,a-f]\{8\}\]//g" |
sed "s/)/);/g" |
sed "s/=\ 0x\([0-9,a-f]*\)/\/\*\ \1\ \*\//g" |

sed "s/outl(0x0\{0,4\}\([0-9,a-f]*\), $iport);[^\r]*\r\toutl(0x\([0-9,a-f]*\), $dport);/radeon_write(0x\1, 0x\2);/g" |
sed "s/outl(0x0\{0,4\}\([0-9,a-f]*\), $iport);[^\r]*\r\tinl($dport);/radeon_read(0x\1);/g" |

sed "s/inb(0x03c3);[^\r]*\r\tinl($stsport);[^\r]*/sync_read();/g" |

sed "s/sync_read();[^\r]*\r\tradeon_write(/radeon_write_sync(/g" |
sed "s/sync_read();[^\r]*\r\tradeon_read(/radeon_read_sync(/g" |

tr '\r' '\n'

echo "}"
