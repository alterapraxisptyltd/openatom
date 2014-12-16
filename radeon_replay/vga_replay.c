#include <sys/io.h>

#include "replay_util.h"
#include "vga_io.h"

void run_replay(uint8_t goto_skippie)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	sync_read();
	radeon_write_sync(0x1728, 0x0008c000);
	radeon_read_sync(0x3f54); /* 00000000 */
	radeon_write_sync(0x174c, 0x00000000);
	if (goto_skippie)
		goto skippie;
	radeon_read_sync(0x0670); /* 00037e04 */
	radeon_write_sync(0x0670, 0x00007e04);
	radeon_read_sync(0x0670); /* 00007e04 */
	radeon_write_sync(0x0670, 0x0000fe04);
	radeon_write_sync(0x0714, 0x1d20d320);
	radeon_write_sync(0x2c00, 0x0f200021);
	radeon_write_sync(0x2f30, 0x00000001);
	radeon_write_sync(0x2f4c, 0x00121be0);
	radeon_write_sync(0x5008, 0x0000d80d);
	radeon_write_sync(0x500c, 0x0000d80c);
	radeon_write_sync(0x5010, 0x00020169);
	radeon_write_sync(0x5014, 0x00020168);
	radeon_write_sync(0x5018, 0x0002017d);
	radeon_write_sync(0x501c, 0x0002017c);
	radeon_write_sync(0x5020, 0x00020191);
	radeon_write_sync(0x5024, 0x00020190);
	radeon_write_sync(0x00e0, 0x01338040);
	radeon_read_sync(0x00e4); /* 00000001 */
	radeon_write_sync(0x00e4, 0x00000001);
	radeon_write_sync(0x00e0, 0x01338041);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_write_sync(0x00e4, 0x00000001);
	radeon_write_sync(0x0c68, 0x66666666);
	radeon_write_sync(0x0c74, 0x002bc666);
	radeon_read_sync(0x0bd8); /* 00000404 */
	radeon_write_sync(0x0bd8, 0x2000f404);
	radeon_write_sync(0x0be4, 0x00022710);
	radeon_write_sync(0x0be0, 0x00040000);
	radeon_read_sync(0x5c1c); /* 00000003 */
	radeon_write_sync(0x5c1c, 0x00000803);
	radeon_write_sync(0x04ec, 0x01120464);
	radeon_write_sync(0x04c0, 0x001186a0);
	radeon_write_sync(0x5ee8, 0x00640018);
	radeon_write_sync(0x04c4, 0x0801003c);
	radeon_read_sync(0x0350); /* 00000018 */
	radeon_write_sync(0x0350, 0x00000218);
	radeon_read_sync(0x03f0); /* 00000100 */
	radeon_write_sync(0x03f0, 0x00000100);
	radeon_write_sync(0x6428, 0x0000000f);
	radeon_write_sync(0x60e0, 0x30000000);
	radeon_read_sync(0x5df8); /* 00000000 */
	radeon_write_sync(0x5df4, 0x00002000);
	radeon_write_sync(0x5df0, 0x100010ff);
	radeon_read_sync(0x0be8); /* 00000000 */
	radeon_write_sync(0x0be8, 0x00000002);
	radeon_read_sync(0x6ef8); /* 00000000 */
	radeon_write_sync(0x6ef8, 0x00000002);
	radeon_read_sync(0x6b00); /* 00010000 */
	radeon_write_sync(0x6b00, 0x02010000);
	radeon_read_sync(0x6a44); /* 00000015 */
	radeon_write_sync(0x6a44, 0x00000011);
	radeon_read_sync(0x69f4); /* 00000000 */
	radeon_write_sync(0x69f4, 0x00000001);
	radeon_read_sync(0x6cd0); /* 00003000 */
	radeon_write_sync(0x6cd0, 0x00003001);
	radeon_write_sync(0x6bd8, 0x00000001);
	radeon_read_sync(0x6ed8); /* 00000000 */
	radeon_write_sync(0x6ed8, 0x00010000);
	radeon_write_sync(0x6cc4, 0x04000800);
	radeon_read_sync(0x6f14); /* 00000000 */
	radeon_write_sync(0x6f14, 0x00000006);
	radeon_read_sync(0x6e18); /* 00000003 */
	radeon_write_sync(0x6e18, 0x00000004);
skippie:
	radeon_read_sync(0x6e70); /* 00400110 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_read_sync(0x6df0); /* 00006260 */
	radeon_write_sync(0x6df0, 0x00006260);
	radeon_read_sync(0x6ea4); /* 00000000 */
	radeon_write_sync(0x6ea4, 0x00000000);
	radeon_read_sync(0x0bec); /* 00000000 */
	radeon_write_sync(0x0bec, 0x00000002);
	radeon_read_sync(0x7af8); /* 00000000 */
	radeon_write_sync(0x7af8, 0x00000002);
	radeon_read_sync(0x7700); /* 00010000 */
	radeon_write_sync(0x7700, 0x02010000);
	radeon_read_sync(0x7644); /* 00000015 */
	radeon_write_sync(0x7644, 0x00000011);
	radeon_read_sync(0x75f4); /* 00000000 */
	radeon_write_sync(0x75f4, 0x00000001);
	radeon_read_sync(0x78d0); /* 00003000 */
	radeon_write_sync(0x78d0, 0x00003001);
	radeon_write_sync(0x77d8, 0x00000001);
	radeon_read_sync(0x7ad8); /* 00000000 */
	radeon_write_sync(0x7ad8, 0x00010000);
	radeon_write_sync(0x78c4, 0x04000800);
	radeon_read_sync(0x7b14); /* 00000000 */
	radeon_write_sync(0x7b14, 0x00000006);
	radeon_read_sync(0x7a18); /* 00000003 */
	radeon_write_sync(0x7a18, 0x00000004);
	radeon_read_sync(0x7a70); /* 00400110 */
	radeon_write_sync(0x7a70, 0x00400310);
	radeon_read_sync(0x7a70); /* 00400310 */
	radeon_write_sync(0x7a70, 0x00400310);
	radeon_read_sync(0x7a70); /* 00400310 */
	radeon_read_sync(0x79f0); /* 00006260 */
	radeon_write_sync(0x79f0, 0x00006260);
	radeon_read_sync(0x7aa4); /* 00000000 */
	radeon_write_sync(0x7aa4, 0x00000000);
	radeon_read_sync(0x5da4); /* 00000000 */
	radeon_write_sync(0x5da4, 0x00000000);
	radeon_read_sync(0x5da8); /* 30000010 */
	radeon_read_sync(0x0bf0); /* 00000000 */
	radeon_write_sync(0x0bf0, 0x00000002);
	radeon_read_sync(0x106f8); /* 00000000 */
	radeon_write_sync(0x106f8, 0x00000002);
	radeon_read_sync(0x10300); /* 00010000 */
	radeon_write_sync(0x10300, 0x02010000);
	radeon_read_sync(0x10244); /* 00000015 */
	radeon_write_sync(0x10244, 0x00000011);
	radeon_read_sync(0x101f4); /* 00000000 */
	radeon_write_sync(0x101f4, 0x00000001);
	radeon_read_sync(0x104d0); /* 00003000 */
	radeon_write_sync(0x104d0, 0x00003001);
	radeon_write_sync(0x103d8, 0x00000001);
	radeon_read_sync(0x106d8); /* 00000000 */
	radeon_write_sync(0x106d8, 0x00010000);
	radeon_write_sync(0x104c4, 0x04000800);
	radeon_read_sync(0x10714); /* 00000000 */
	radeon_write_sync(0x10714, 0x00000006);
	radeon_read_sync(0x10618); /* 00000003 */
	radeon_write_sync(0x10618, 0x00000004);
	radeon_read_sync(0x10670); /* 00400110 */
	radeon_write_sync(0x10670, 0x00400310);
	radeon_read_sync(0x10670); /* 00400310 */
	radeon_write_sync(0x10670, 0x00400310);
	radeon_read_sync(0x10670); /* 00400310 */
	radeon_read_sync(0x105f0); /* 00006260 */
	radeon_write_sync(0x105f0, 0x00006260);
	radeon_read_sync(0x106a4); /* 00000000 */
	radeon_write_sync(0x106a4, 0x00000000);
	radeon_read_sync(0x5db4); /* 00000000 */
	radeon_write_sync(0x5db4, 0x00000000);
	radeon_read_sync(0x5db8); /* 30000010 */
	radeon_read_sync(0x0bf4); /* 00000000 */
	radeon_write_sync(0x0bf4, 0x00000002);
	radeon_read_sync(0x112f8); /* 00000000 */
	radeon_write_sync(0x112f8, 0x00000002);
	radeon_read_sync(0x10f00); /* 00010000 */
	radeon_write_sync(0x10f00, 0x02010000);
	radeon_read_sync(0x10e44); /* 00000015 */
	radeon_write_sync(0x10e44, 0x00000011);
	radeon_read_sync(0x10df4); /* 00000000 */
	radeon_write_sync(0x10df4, 0x00000001);
	radeon_read_sync(0x110d0); /* 00003000 */
	radeon_write_sync(0x110d0, 0x00003001);
	radeon_write_sync(0x10fd8, 0x00000001);
	radeon_read_sync(0x112d8); /* 00000000 */
	radeon_write_sync(0x112d8, 0x00010000);
	radeon_write_sync(0x110c4, 0x04000800);
	radeon_read_sync(0x11314); /* 00000000 */
	radeon_write_sync(0x11314, 0x00000006);
	radeon_read_sync(0x11218); /* 00000003 */
	radeon_write_sync(0x11218, 0x00000004);
	radeon_read_sync(0x11270); /* 00400110 */
	radeon_write_sync(0x11270, 0x00400310);
	radeon_read_sync(0x11270); /* 00400310 */
	radeon_write_sync(0x11270, 0x00400310);
	radeon_read_sync(0x11270); /* 00400310 */
	radeon_read_sync(0x111f0); /* 00006260 */
	radeon_write_sync(0x111f0, 0x00006260);
	radeon_read_sync(0x112a4); /* 00000000 */
	radeon_write_sync(0x112a4, 0x00000000);
	radeon_delay(0x00097558 - 0x000974e0);
	radeon_write_sync(0x6220, 0x00320000);
	radeon_write_sync(0x6224, 0x00001c00);
	radeon_write_sync(0x6228, 0x123d1210);
	radeon_write_sync(0x6270, 0x00320000);
	radeon_write_sync(0x6274, 0x00001c00);
	radeon_write_sync(0x6278, 0x123d1210);
	radeon_write_sync(0x62c0, 0x00320000);
	radeon_write_sync(0x62c4, 0x00001c00);
	radeon_write_sync(0x62c8, 0x123d1210);
	radeon_write_sync(0x6320, 0x00320000);
	radeon_write_sync(0x6324, 0x00001c00);
	radeon_write_sync(0x6328, 0x123d1210);
	radeon_write_sync(0x6370, 0x00320000);
	radeon_write_sync(0x6374, 0x00001c00);
	radeon_write_sync(0x6378, 0x123d1210);
	radeon_write_sync(0x63c0, 0x00320000);
	radeon_write_sync(0x63c4, 0x00001c00);
	radeon_write_sync(0x63c8, 0x123d1210);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x65fc); /* 00001000 */
	radeon_write_sync(0x65fc, 0x00005000);
	radeon_read_sync(0x65fc); /* 00005000 */
	radeon_write_sync(0x65fc, 0x00001000);
	radeon_read_sync(0x642c); /* 0b0b0100 */
	radeon_write_sync(0x642c, 0x0b0b0101);
	radeon_read_sync(0x642c); /* 0b0b0101 */
	radeon_write_sync(0x642c, 0x0b000101);
	radeon_read_sync(0x6430); /* 04040100 */
	radeon_write_sync(0x6430, 0x04040101);
	radeon_read_sync(0x6430); /* 04040101 */
	radeon_write_sync(0x6430, 0x04000101);
	radeon_delay(0x000de41a - 0x000dda12);
	radeon_read_sync(0x611c); /* 00000000 */
	radeon_write_sync(0x611c, 0x00000002);
	radeon_write_sync(0x6ccc, 0x00007fff);
	radeon_write_sync(0x78cc, 0x00007fff);
	radeon_write_sync(0x104cc, 0x00007fff);
	radeon_write_sync(0x110cc, 0x00007fff);
	radeon_read_sync(0x5490); /* 00000003 */
	radeon_write_sync(0x5490, 0x00000000);
	radeon_read_sync(0x2024); /* 0f1f0f00 */
	radeon_write_sync(0x2c04, 0x0f000000);
	radeon_read_sync(0x0324); /* 00000000 */
	radeon_write_sync(0x0324, 0x0000000f);
	radeon_write_sync(0x0310, 0x00000000);
	radeon_read_sync(0x20ac); /* 00000000 */
	radeon_write_sync(0x20ac, 0x00000000);
	radeon_read_sync(0x5490); /* 00000000 */
	radeon_write_sync(0x5490, 0x00000003);
	radeon_read_sync(0x0604); /* 00000001 */
	radeon_read_sync(0x0600); /* 0000002b */
	radeon_write_sync(0x0600, 0x00000044);
	radeon_read_sync(0x0604); /* 00000009 */
	radeon_read_sync(0x1724); /* 00000000 */
	radeon_write_sync(0x1724, 0x00040000);
	radeon_read_sync(0x5428); /* 00000200 */
	radeon_read_sync(0x1734); /* 00000000 */
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_write_sync(0x1738, 0x00000000);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_write_sync(0x1724, 0x00000000);
	radeon_read_sync(0x646c); /* 00010000 */
	radeon_write_sync(0x646c, 0x00010f9f);
	radeon_read_sync(0x6020); /* 00000000 */
	radeon_write_sync(0x6020, 0x00010000);
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010001);
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010000);
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010001);
	radeon_read_sync(0x6530); /* 0f400000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040000 */
	radeon_write_sync(0x6200, 0x21040000);
	radeon_read_sync(0x6200); /* 21040000 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6204); /* 00000000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000700);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c0000000 */
	radeon_delay(0x001bb0ce - 0x001baea2);
	radeon_read_sync(0x6210); /* 09000001 */
	radeon_read_sync(0x6210); /* 09000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 09000001 */
	radeon_read_sync(0x6218); /* 00011101 */
	radeon_read_sync(0x6218); /* 00020a01 */
	radeon_read_sync(0x6218); /* 00038101 */
	radeon_read_sync(0x6218); /* 00044101 */
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00070101 */
	radeon_read_sync(0x6218); /* 00088001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000c00);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c9000000 */
	radeon_delay(0x001ea47c - 0x001ea24e);
	radeon_read_sync(0x6210); /* 05000001 */
	radeon_read_sync(0x6210); /* 05000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 05000001 */
	radeon_read_sync(0x6218); /* 00010801 */
	radeon_read_sync(0x6218); /* 00020101 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00002000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c5000000 */
	radeon_delay(0x00214252 - 0x00214026);
	radeon_read_sync(0x6210); /* 03000001 */
	radeon_read_sync(0x6210); /* 03000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 03000001 */
	radeon_read_sync(0x6218); /* 00010001 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_read_sync(0x1724); /* 00000000 */
	radeon_write_sync(0x1724, 0x00040000);
	radeon_read_sync(0x172c); /* 00000000 */
	radeon_write_sync(0x172c, 0x0000ff00);
	radeon_read_sync(0x172c); /* 0000ff00 */
	radeon_read_sync(0x0670); /* 0000fe04 */
	radeon_read_sync(0x6484); /* 00000000 */
	radeon_write_sync(0x6484, 0x00000001);
	radeon_read_sync(0x646c); /* 00010f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x6480); /* 00000001 */
	radeon_write_sync(0x6480, 0x000c0001);
	radeon_read_sync(0x6480); /* 000c0001 */
	radeon_write_sync(0x6480, 0x000c0fc0);
	radeon_read_sync(0x172c); /* 0000ff00 */
	radeon_read_sync(0x6478); /* 00000000 */
	radeon_write_sync(0x6478, 0x0000fc00);
	radeon_read_sync(0x6478); /* 0000fc00 */
	radeon_write_sync(0x6478, 0xc000fc00);
	radeon_read_sync(0x6484); /* 00000101 */
	radeon_write_sync(0x6484, 0x00000100);
	radeon_read_sync(0x6484); /* 00000000 */
	radeon_read_sync(0x1734); /* 00000000 */
	radeon_write_sync(0x1734, 0x00003c00);
	radeon_read_sync(0x12144); /* 00000000 */
	radeon_read_sync(0x12144); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x008adb78 - 0x008ad94e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x008d3764 - 0x008d353e);
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6218); /* 00012001 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 0004f901 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060001);
	radeon_read_sync(0x6210); /* c2000000 */
	radeon_delay(0x00910180 - 0x0090ff56);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00935cce - 0x00935aac);
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6218); /* 00013101 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 0004f901 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x00003d00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c2000000 */
	radeon_delay(0x00a2c09a - 0x00a2be7a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00001f00);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00a5c54c - 0x00a5c32a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000ba00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00a8ca68 - 0x00a8c846);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000bb00);
	radeon_write_sync(0x6218, 0x00000800);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00abcf44 - 0x00abcd24);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000b100);
	radeon_write_sync(0x6218, 0x00004b00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00aed466 - 0x00aed24c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00007300);
	radeon_write_sync(0x6218, 0x00006900);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00b1d95e - 0x00b1d73e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00009f00);
	radeon_write_sync(0x6218, 0x00002400);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00b4de3c - 0x00b4dc1a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00001900);
	radeon_write_sync(0x6218, 0x00003300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00b7e354 - 0x00b7e132);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00008900);
	radeon_write_sync(0x6218, 0x00003900);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00bae852 - 0x00bae630);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000f800);
	radeon_write_sync(0x6218, 0x00004200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00bded34 - 0x00bdeb12);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000f900);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00c0f200 - 0x00c0efe2);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000fa00);
	radeon_write_sync(0x6218, 0x00002300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00c3f72a - 0x00c3f508);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000fb00);
	radeon_write_sync(0x6218, 0x00004500);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00c6fc2c - 0x00c6fa0a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000fc00);
	radeon_write_sync(0x6218, 0x00006700);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00ca0162 - 0x00c9ff3c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000fd00);
	radeon_write_sync(0x6218, 0x00008900);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00cd062a - 0x00cd040a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000fe00);
	radeon_write_sync(0x6218, 0x0000ab00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00d00b26 - 0x00d0090e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00001d00);
	radeon_write_sync(0x6218, 0x00002500);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00d30fe6 - 0x00d30dcc);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000c300);
	radeon_write_sync(0x6218, 0x00000700);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00d614a4 - 0x00d6128a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000c200);
	radeon_write_sync(0x6218, 0x00005a00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00d91994 - 0x00d9177a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000c400);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00dc1e9c - 0x00dc1c84);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000c000);
	radeon_write_sync(0x6218, 0x00000700);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00df2344 - 0x00df212a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000c100);
	radeon_write_sync(0x6218, 0x00005a00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00e22872 - 0x00e2264e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000b100);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00e52d58 - 0x00e52b3e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000bf00);
	radeon_write_sync(0x6218, 0x00007d00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00e83230 - 0x00e8300c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000b500);
	radeon_write_sync(0x6218, 0x00006300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00eb3744 - 0x00eb3520);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000cb00);
	radeon_write_sync(0x6218, 0x00008000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00ee3bf4 - 0x00ee39d0);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000b300);
	radeon_write_sync(0x6218, 0x00006600);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00f140dc - 0x00f13ec0);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000b200);
	radeon_write_sync(0x6218, 0x00009a00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00f44578 - 0x00f44356);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00009f00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00f749e2 - 0x00f747c6);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00008300);
	radeon_write_sync(0x6218, 0x00001400);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00fa4e6e - 0x00fa4c4a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000a700);
	radeon_write_sync(0x6218, 0x0000c200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00fd5322 - 0x00fd5108);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00007100);
	radeon_write_sync(0x6218, 0x00001200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x010057cc - 0x0100559c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00008200);
	radeon_write_sync(0x6218, 0x00005d00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x01035cb8 - 0x01035a84);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00008900);
	radeon_write_sync(0x6218, 0x00002800);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0106617a - 0x01065f4a);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000be00);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0109660a - 0x010963dc);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00008a00);
	radeon_write_sync(0x6218, 0x00005300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x010c6aea - 0x010c68ba);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x010f6fa0 - 0x010f6d6e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000d400);
	radeon_write_sync(0x6218, 0x00001000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x01127466 - 0x0112723c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000f300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x011578da - 0x011576b2);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000f400);
	radeon_write_sync(0x6218, 0x00003c00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x01187d8e - 0x01187b5e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000b400);
	radeon_write_sync(0x6218, 0x00000600);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x011b823c - 0x011b800e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000dc00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x011e86e2 - 0x011e84b6);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000dd00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x01218bb4 - 0x01218988);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00009100);
	radeon_write_sync(0x6218, 0x00002000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x01249062 - 0x01248e2e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000d100);
	radeon_write_sync(0x6218, 0x00000600);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0127952c - 0x012792fc);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x0000d600);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x012a99b6 - 0x012a9788);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000d200);
	radeon_write_sync(0x6218, 0x00000800);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x012d9ea8 - 0x012d9c78);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x0000d300);
	radeon_write_sync(0x6218, 0x00008000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0130a37e - 0x0130a154);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x7144); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x6540); /* 0f400000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21040000 */
	radeon_write_sync(0x6250, 0x21140000);
	radeon_read_sync(0x6250); /* 21140000 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00000000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00007f00);
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c0000000 */
	radeon_delay(0x014a5784 - 0x014a5552);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x014d7fd0 - 0x014d7da2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01502a7e - 0x01502850);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0153ae74 - 0x0153ac46);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0156d64c - 0x0156d41e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0159fede - 0x0159fcb2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x015ca984 - 0x015ca754);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00018001 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00008100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01602d20 - 0x01602af2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0162d770 - 0x0162d53c);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020101 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01665b2c - 0x016658fe);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00002400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01690586 - 0x01690354);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040101 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00002400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x016c8994 - 0x016c8766);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00003800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00002000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x016fb1c4 - 0x016faf96);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0172d98a - 0x0172d75e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x017583cc - 0x017581a0);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00012101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0179075c - 0x01790532);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x017bb194 - 0x017baf66);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x017f3508 - 0x017f32dc);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0181df30 - 0x0181dd04);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00012101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x018562e6 - 0x018560be);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01880d6e - 0x01880b40);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x018b9104 - 0x018b8ed8);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x018e3b44 - 0x018e3918);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00012101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0191bf1c - 0x0191bcee);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x019469cc - 0x019467a0);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0197ed54 - 0x0197eb26);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x019a97ae - 0x019a9584);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00012101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x019e1b78 - 0x019e1950);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01a0c5f8 - 0x01a0c3ca);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020a01 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01a449aa - 0x01a4477e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01a6f404 - 0x01a6f1d6);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020201 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01aa77a4 - 0x01aa7576);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01ad21e8 - 0x01ad1fba);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020201 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01b0a55e - 0x01b0a330);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01b34fb8 - 0x01b34d90);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020201 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01b6d32c - 0x01b6d100);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01b97d6c - 0x01b97b42);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010101 */
	radeon_read_sync(0x6268); /* 00020201 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01bd00ea - 0x01bcfeb4);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01bfab58 - 0x01bfa928);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00020801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01c32f0c - 0x01c32cde);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01c5d980 - 0x01c5d74e);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00020801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01c95d5e - 0x01c95b2e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01cc07ee - 0x01cc05c0);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00020801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01cf8baa - 0x01cf897c);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01d2365c - 0x01d2342a);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00020801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01d5ba4c - 0x01d5b81e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01d864ee - 0x01d862bc);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020101 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01dbe8ce - 0x01dbe6a2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01df10d2 - 0x01df0ea8);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01e23880 - 0x01e23652);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00005300);
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01e560a8 - 0x01e55e7c);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01e8889e - 0x01e88670);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01eb3344 - 0x01eb3118);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020101 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x01eeb71c - 0x01eeb4ee);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01f1df56 - 0x01f1dd24);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x12d44); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x01fa3e18 - 0x01fa3be6);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00011901 */
	radeon_read_sync(0x6268); /* 00021b01 */
	radeon_read_sync(0x6268); /* 00030101 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00007f00);
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02134716 - 0x021344ea);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02166eb0 - 0x02166c80);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x0000e400);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x021996c6 - 0x02199494);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x021cbeea - 0x021cbcba);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00008200);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x021fe6a0 - 0x021fe476);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x0000a100);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x0000f000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02230e7a - 0x02230c50);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02263674 - 0x02263448);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02295e42 - 0x02295c16);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x022c8626 - 0x022c83fa);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x022fadfe - 0x022fabd2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00008000);
	radeon_write_sync(0x6268, 0x00002000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0232d5d4 - 0x0232d3a4);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0235fe0e - 0x0235fbdc);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00002300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02392650 - 0x02392424);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x023c4ecc - 0x023c4c96);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00001100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x023f769e - 0x023f7470);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02429e5e - 0x02429c32);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0245c66a - 0x0245c436);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0248710e - 0x02486ede);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00022801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x024bf51c - 0x024bf2f2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x024f1d02 - 0x024f1ad6);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0251c78a - 0x0251c55c);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00022801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02554b52 - 0x02554924);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02587342 - 0x02587116);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x025b1dca - 0x025b1ba0);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00022801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x025ea19a - 0x025e9f6a);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0261c99a - 0x0261c76e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02647422 - 0x026471f8);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010501 */
	radeon_read_sync(0x6268); /* 00022801 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_write_sync(0x6268, 0x00002800);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0267f80c - 0x0267f5dc);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00002400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x026b2082 - 0x026b1e56);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00002000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00008500);
	radeon_write_sync(0x6268, 0x00006f00);
	radeon_write_sync(0x6268, 0x00000700);
	radeon_write_sync(0x6268, 0x00002900);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x026e4936 - 0x026e470a);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00003800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00002000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x027171bc - 0x02716f8e);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00004000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02741c28 - 0x027419fa);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00031001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00004000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0277a062 - 0x02779e30);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x027ac876 - 0x027ac646);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x027df062 - 0x027dee36);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x028118e4 - 0x028116b8);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0283c396 - 0x0283c168);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00018101 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00008100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x0287478a - 0x02874554);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0289f216 - 0x0289efe6);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010701 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030101 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x028d7622 - 0x028d73f4);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00002000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x0000ee00);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02909e1a - 0x02909bea);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001c00);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x0000d000);
	radeon_write_sync(0x6268, 0x00000700);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0293c60e - 0x0293c3e2);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x0296edec - 0x0296ebc0);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x029a166e - 0x029a1440);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x029cc0ec - 0x029cbebc);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010601 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030101 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000600);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02a044c8 - 0x02a0429a);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02a36ce0 - 0x02a36aae);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02a617aa - 0x02a6157c);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020401 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02a99b28 - 0x02a998f6);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02ac4564 - 0x02ac4336);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020401 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02afc94e - 0x02afc724);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02b27376 - 0x02b27148);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00000800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00004000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02b5f72e - 0x02b5f500);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02b8a1ae - 0x02b89f7e);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010601 */
	radeon_read_sync(0x6268); /* 00020001 */
	radeon_read_sync(0x6268); /* 00030101 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008000);
	radeon_write_sync(0x6268, 0x00000500);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000700);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02bc255e - 0x02bc232c);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02becfa6 - 0x02becd74);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00010001 */
	radeon_read_sync(0x6268); /* 00020401 */
	radeon_read_sync(0x6268); /* 00030001 */
	radeon_read_sync(0x6268); /* 00040201 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00003000);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000400);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02c253b0 - 0x02c25186);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_delay(0x02c41bd6 - 0x02c3586e);
	radeon_delay(0x02c4f8f4 - 0x02c4353e);
	radeon_delay(0x02c5d5ae - 0x02c51244);
	radeon_delay(0x02c6b2c4 - 0x02c5eefc);
	radeon_delay(0x02c78f72 - 0x02c6cc18);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00007000);
	radeon_write_sync(0x6268, 0x00001400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00001100);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02ca390e - 0x02ca36dc);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_write_sync(0x6268, 0x80009800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02cce3c0 - 0x02cce18c);
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 05000001 */
	radeon_read_sync(0x6268); /* 00011901 */
	radeon_read_sync(0x6268); /* 00021b01 */
	radeon_read_sync(0x6268); /* 00030101 */
	radeon_read_sync(0x6268); /* 00040001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001900);
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c5000000 */
	radeon_delay(0x02d067ee - 0x02d065c4);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00008800);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00001900);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02d3904c - 0x02d38e1a);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_write_sync(0x6268, 0x80008800);
	radeon_write_sync(0x6268, 0x00005000);
	radeon_write_sync(0x6268, 0x00007400);
	radeon_write_sync(0x6268, 0x00000300);
	radeon_write_sync(0x6268, 0x00000200);
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x625c); /* 00000000 */
	radeon_write_sync(0x625c, 0x00000002);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080001);
	radeon_read_sync(0x6260); /* c1000000 */
	radeon_delay(0x02d6b8b6 - 0x02d6b684);
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_write_sync(0x6268, 0x80000001);
	radeon_read_sync(0x6268); /* 00000001 */
	radeon_read_sync(0x6260); /* 01000001 */
	radeon_read_sync(0x173c); /* 00000000 */
	radeon_write_sync(0x173c, 0x00001000);
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x173c, 0x00001000);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1724); /* 00040000 */
	vga_misc_read(); /* 00 */
	vga_misc_write(0x01);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x173c); /* 00001000 */
	outb(0x0e, 0x03b4);
	inb(0x03b5); /* ff */
	outb(0x0f, 0x03b4);
	inb(0x03b5); /* ff */
	outw(0xaa0e, 0x03b4);
	outw(0x550f, 0x03b4);
	outb(0x0e, 0x03b4);
	inb(0x03b5); /* ff */
	outb(0x0f, 0x03b4);
	inb(0x03b5); /* ff */
	radeon_read_sync(0x0670); /* 0000fe04 */
	radeon_read_sync(0x4000); /* 99001002 */
	radeon_read_sync(0x402c); /* 99001002 */
	radeon_read_sync(0x4020); /* 00000000 */
	radeon_read_sync(0x174c); /* 00000000 */
	radeon_read_sync(0x3f54); /* 02dfe202 */
	radeon_write_sync(0x174c, 0x000eb7b8);
	radeon_write_sync(0x0000, 0x9ffffffc);
}

void replay_int10_c1(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	radeon_read_sync(0x4054); /* 00000000 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

void replay_int10_c2(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	radeon_read_sync(0x4054); /* 00000000 */
	radeon_read_sync(0x4010); /* e0000008 */
	radeon_read_sync(0x4010); /* e0000008 */
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_write_sync(0x1738, 0x0000000b);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

void replay_int10_c3(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	radeon_read_sync(0x4054); /* 00000000 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x1738); /* 0000000b */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_write_sync(0x1730, 0x00000000);
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x172c); /* 0000ff00 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_write_sync(0x1730, 0x00000002);
	radeon_write_sync(0x1740, 0x41170001);
	outw(0x0100, 0x03c4);/* vga_sr_write(0x00, 0x01); */
	outw(0x0101, 0x03c4);/* vga_sr_write(0x01, 0x01); */
	outw(0x0f02, 0x03c4);/* vga_sr_write(0x02, 0x0f); */
	outw(0x0003, 0x03c4);/* vga_sr_write(0x03, 0x00); */
	outw(0x0a04, 0x03c4);/* vga_sr_write(0x04, 0x0a); */
	outw(0x0300, 0x03c4);/* vga_sr_write(0x00, 0x03); */
	vga_gr_write(0x00, 0x00);
	vga_gr_write(0x01, 0x00);
	vga_gr_write(0x02, 0x00);
	vga_gr_write(0x03, 0x00);
	vga_gr_write(0x04, 0x00);
	vga_gr_write(0x05, 0x40);
	vga_gr_write(0x06, 0x05);
	vga_gr_write(0x07, 0x0f);
	vga_gr_write(0x08, 0xff);
	inb(0x03da); /* 08 */
	outb(0x00, 0x03c0);
	outb(0x00, 0x03c0);
	outb(0x01, 0x03c0);
	outb(0x01, 0x03c0);
	outb(0x02, 0x03c0);
	outb(0x02, 0x03c0);
	outb(0x03, 0x03c0);
	outb(0x03, 0x03c0);
	outb(0x04, 0x03c0);
	outb(0x04, 0x03c0);
	outb(0x05, 0x03c0);
	outb(0x05, 0x03c0);
	outb(0x06, 0x03c0);
	outb(0x06, 0x03c0);
	outb(0x07, 0x03c0);
	outb(0x07, 0x03c0);
	outb(0x08, 0x03c0);
	outb(0x08, 0x03c0);
	outb(0x09, 0x03c0);
	outb(0x09, 0x03c0);
	outb(0x0a, 0x03c0);
	outb(0x0a, 0x03c0);
	outb(0x0b, 0x03c0);
	outb(0x0b, 0x03c0);
	outb(0x0c, 0x03c0);
	outb(0x0c, 0x03c0);
	outb(0x0d, 0x03c0);
	outb(0x0d, 0x03c0);
	outb(0x0e, 0x03c0);
	outb(0x0e, 0x03c0);
	outb(0x0f, 0x03c0);
	outb(0x0f, 0x03c0);
	outb(0x10, 0x03c0);
	outb(0x01, 0x03c0);
	outb(0x11, 0x03c0);
	outb(0x00, 0x03c0);
	outb(0x12, 0x03c0);
	outb(0x0f, 0x03c0);
	outb(0x13, 0x03c0);
	outb(0x00, 0x03c0);
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	vga_sr_read(0x01); /* 01 */
	outb(0x21, 0x03c5);
	radeon_read_sync(0x6e74); /* 00000001 */
	radeon_write_sync(0x6e74, 0x00000001);
	radeon_read_sync(0x6e74); /* 00000001 */
	radeon_write_sync(0x6e74, 0x00000101);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x6104); /* 00000100 */
	radeon_write_sync(0x6104, 0x00000100);
	radeon_read_sync(0x0c7c); /* 07f90004 */
	radeon_write_sync(0x0c7c, 0x07f90000);
	radeon_read_sync(0x0490); /* 00190000 */
	radeon_read_sync(0x0490); /* 00190000 */
	radeon_read_sync(0x0490); /* 00190000 */
	radeon_write_sync(0x0490, 0x18190000);
	radeon_read_sync(0x0490); /* 18790000 */
	radeon_write_sync(0x0508, 0xd630c380);
	radeon_write_sync(0x0518, 0xd630c380);
	radeon_write_sync(0x0528, 0xd630c380);
	radeon_write_sync(0x0538, 0xd630c380);
	radeon_read_sync(0x0490); /* 18790000 */
	radeon_read_sync(0x0490); /* 18790000 */
	radeon_read_sync(0x0490); /* 18790000 */
	radeon_write_sync(0x0490, 0x18790012);
	radeon_read_sync(0x0490); /* 181f1212 */
	radeon_read_sync(0x6ed8); /* 00010000 */
	radeon_write_sync(0x6ed8, 0x00010000);
	radeon_read_sync(0x6ef4); /* 00000000 */
	radeon_write_sync(0x6ef4, 0x00000001);
	radeon_read_sync(0x6e78); /* 00000000 */
	radeon_write_sync(0x6e78, 0x00000000);
	radeon_read_sync(0x04c8); /* 00000101 */
	radeon_write_sync(0x04c8, 0x00000101);
	radeon_read_sync(0x6800); /* 00000001 */
	radeon_write_sync(0x6800, 0x00000000);
	radeon_read_sync(0x03f0); /* 00000100 */
	radeon_read_sync(0x0304); /* 00003f3f */
	radeon_write_sync(0x0304, 0x00000000);
	radeon_read_sync(0x611c); /* 00000002 */
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_read_sync(0x6df0); /* 00006260 */
	radeon_write_sync(0x6df0, 0x00006260);
	radeon_read_sync(0x6ea4); /* 00000000 */
	radeon_write_sync(0x6ea4, 0x00000000);
	radeon_read_sync(0x5c18); /* 00000000 */
	radeon_write_sync(0x5c18, 0x00000000);
	radeon_read_sync(0x5c10); /* 00000000 */
	radeon_write_sync(0x5c10, 0x00000000);
	radeon_read_sync(0x5c14); /* 00000000 */
	radeon_write_sync(0x5c14, 0x00000000);
	radeon_read_sync(0x5c0c); /* 00000000 */
	radeon_write_sync(0x5c0c, 0x00000000);
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_write_sync(0x5c1c, 0x00000803);
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_write_sync(0x5c1c, 0x00000803);
	radeon_delay(0x02eb5f2a - 0x02eb5510);
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_write_sync(0x5c1c, 0x00000803);
	radeon_delay(0x02eb98fe - 0x02eb71d0);
	radeon_read_sync(0x5c1c); /* 00000803 */
	radeon_write_sync(0x5c1c, 0x00002803);
	radeon_read_sync(0x0330); /* 00000000 */
	radeon_write_sync(0x0330, 0x00000000);
	radeon_write_sync(0x5c20, 0xd5077604);
	radeon_read_sync(0x5c1c); /* 00002803 */
	radeon_write_sync(0x5c1c, 0x00002803);
	radeon_read_sync(0x5c00); /* 00002007 */
	radeon_write_sync(0x5c00, 0x00006007);
	radeon_read_sync(0x5c28); /* 00000013 */
	radeon_write_sync(0x5c28, 0x00000012);
	radeon_read_sync(0x5c24); /* 00000000 */
	radeon_write_sync(0x5c24, 0x00000000);
	radeon_read_sync(0x5c1c); /* 00002803 */
	radeon_write_sync(0x5c1c, 0x00002803);
	radeon_read_sync(0x5c30); /* 00000000 */
	radeon_write_sync(0x5c30, 0x00000001);
	radeon_read_sync(0x5c00); /* 00006007 */
	radeon_write_sync(0x5c00, 0x00006002);
	radeon_read_sync(0x5c04); /* 01280010 */
	radeon_write_sync(0x5c04, 0x001b0010);
	radeon_read_sync(0x5c04); /* 001b0010 */
	radeon_write_sync(0x5c04, 0x001b0010);
	radeon_read_sync(0x5c08); /* 002e2e2e */
	radeon_write_sync(0x5c08, 0x00012e2e);
	radeon_read_sync(0x5c08); /* 00012e2e */
	radeon_write_sync(0x5c08, 0x00012e01);
	radeon_read_sync(0x5c08); /* 00012e01 */
	radeon_write_sync(0x5c08, 0x00010101);
	radeon_read_sync(0x5c18); /* 00000000 */
	radeon_write_sync(0x5c18, 0x00010000);
	radeon_read_sync(0x5c18); /* 00010000 */
	radeon_write_sync(0x5c18, 0x00011000);
	radeon_delay(0x02ed990c - 0x02ed8528);
	radeon_read_sync(0x5c30); /* 00000001 */
	radeon_write_sync(0x5c30, 0x00000000);
	radeon_read_sync(0x5c1c); /* 00002803 */
	radeon_write_sync(0x5c1c, 0x00002801);
	radeon_delay(0x02ee7960 - 0x02edb5da);
	radeon_read_sync(0x5c1c); /* 00002801 */
	radeon_write_sync(0x5c1c, 0x00002800);
	radeon_read_sync(0x5c1c); /* 00102800 */
	radeon_write_sync(0x5c1c, 0x00100800);
	radeon_delay(0x02ee9a80 - 0x02ee985c);
	radeon_read_sync(0x5c1c); /* 00300800 */
	radeon_read_sync(0x5c1c); /* 00300800 */
	radeon_read_sync(0x5c04); /* 001b0010 */
	radeon_write_sync(0x5c04, 0x001b0010);
	radeon_read_sync(0x5c1c); /* 00300800 */
	radeon_write_sync(0x5c1c, 0x00300808);
	radeon_read_sync(0x6cc0); /* 00000000 */
	radeon_write_sync(0x6cc0, 0x00003332);
	radeon_read_sync(0x0504); /* 00000000 */
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x00400310);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_read_sync(0x6df0); /* 00006260 */
	radeon_write_sync(0x6df0, 0x00006260);
	radeon_read_sync(0x6ea4); /* 00000000 */
	radeon_write_sync(0x6ea4, 0x00000000);
	radeon_read_sync(0x0500); /* 0000c001 */
	radeon_write_sync(0x0500, 0x0000c001);
	radeon_write_sync(0x0504, 0x1b497940);
	radeon_read_sync(0x0500); /* 0000c001 */
	radeon_write_sync(0x0500, 0x0000c011);
	radeon_read_sync(0x5c10); /* 00000000 */
	radeon_write_sync(0x5c10, 0x00000000);
	radeon_read_sync(0x5c14); /* 00000000 */
	radeon_read_sync(0x5c14); /* 00000000 */
	radeon_write_sync(0x5c14, 0x00000000);
	radeon_read_sync(0x6e00); /* 00000000 */
	radeon_write_sync(0x6e00, 0x00000615);
	radeon_read_sync(0x6e08); /* 00000000 */
	radeon_write_sync(0x6e08, 0x00000000);
	radeon_read_sync(0x6e08); /* 00000000 */
	radeon_write_sync(0x6e08, 0x000a0000);
	radeon_read_sync(0x6e04); /* 00000000 */
	radeon_write_sync(0x6e04, 0x00b80000);
	radeon_read_sync(0x6e04); /* 00b80000 */
	radeon_write_sync(0x6e04, 0x00b8060e);
	radeon_read_sync(0x6e0c); /* 00000000 */
	radeon_write_sync(0x6e0c, 0x00000001);
	radeon_read_sync(0x6d78); /* 00000000 */
	radeon_write_sync(0x6d78, 0x00000000);
	radeon_read_sync(0x6d78); /* 00000000 */
	radeon_write_sync(0x6d78, 0x00000000);
	radeon_read_sync(0x6d78); /* 00000000 */
	radeon_write_sync(0x6d78, 0x00000000);
	radeon_read_sync(0x6e1c); /* 00000000 */
	radeon_write_sync(0x6e1c, 0x0000032f);
	radeon_read_sync(0x6e38); /* 00000000 */
	radeon_write_sync(0x6e38, 0x00000000);
	radeon_read_sync(0x6e38); /* 00000000 */
	radeon_write_sync(0x6e38, 0x00010000);
	radeon_read_sync(0x6e34); /* 00000000 */
	radeon_write_sync(0x6e34, 0x002d0000);
	radeon_read_sync(0x6e34); /* 002d0000 */
	radeon_write_sync(0x6e34, 0x002d032d);
	radeon_read_sync(0x6e3c); /* 00000000 */
	radeon_write_sync(0x6e3c, 0x00000001);
	radeon_read_sync(0x6d7c); /* 00000000 */
	radeon_write_sync(0x6d7c, 0x00000000);
	radeon_read_sync(0x6d7c); /* 00000000 */
	radeon_write_sync(0x6d7c, 0x00000000);
	radeon_read_sync(0x6d7c); /* 00000000 */
	radeon_write_sync(0x6d7c, 0x00000000);
	radeon_read_sync(0x6e78); /* 00000000 */
	radeon_write_sync(0x6e78, 0x00000000);
	radeon_read_sync(0x6b00); /* 02010000 */
	radeon_write_sync(0x6b00, 0x02010000);
	radeon_read_sync(0x6d44); /* 00000100 */
	radeon_write_sync(0x6d44, 0x00010100);
	radeon_read_sync(0x6d50); /* 00000000 */
	radeon_write_sync(0x6d50, 0x00000000);
	radeon_read_sync(0x6d14); /* 00000000 */
	radeon_write_sync(0x6d14, 0x00000000);
	radeon_read_sync(0x6d0c); /* 00000000 */
	radeon_write_sync(0x6d0c, 0x00000101);
	radeon_write_sync(0x6d1c, 0x00010001);
	radeon_read_sync(0x6d28); /* 00000000 */
	radeon_write_sync(0x6d28, 0x00030100);
	radeon_read_sync(0x6d38); /* 00000000 */
	radeon_write_sync(0x6d38, 0x00030100);
	radeon_read_sync(0x6d4c); /* 00000000 */
	radeon_write_sync(0x6d4c, 0x00001010);
	radeon_read_sync(0x6d08); /* 00000000 */
	radeon_write_sync(0x6d08, 0x00000001);
	radeon_read_sync(0x6d44); /* 00010101 */
	radeon_write_sync(0x6d44, 0x00000101);
	radeon_read_sync(0x04fc); /* 00000000 */
	radeon_write_sync(0x04fc, 0x00000010);
	radeon_read_sync(0x0330); /* 00000000 */
	radeon_write_sync(0x0330, 0x00000000);
	radeon_read_sync(0x0328); /* 00000000 */
	radeon_write_sync(0x0328, 0x00000001);
	radeon_read_sync(0x0308); /* 00000000 */
	radeon_write_sync(0x0308, 0x00000011);
	radeon_read_sync(0x0318); /* 00000000 */
	radeon_write_sync(0x0318, 0x00000000);
	radeon_read_sync(0x0320); /* 00000000 */
	radeon_write_sync(0x0320, 0x00000000);
	radeon_read_sync(0x1740); /* 41170001 */
	radeon_write_sync(0x1740, 0x41170001);
	radeon_read_sync(0x0324); /* 0000000f */
	radeon_read_sync(0x0310); /* 00000000 */
	radeon_read_sync(0x0318); /* 00000000 */
	radeon_read_sync(0x0320); /* 00000000 */
	radeon_read_sync(0x681c); /* 00000000 */
	radeon_write_sync(0x681c, 0x0000000f);
	radeon_read_sync(0x6820); /* 00000000 */
	radeon_write_sync(0x6820, 0x0000000f);
	radeon_write_sync(0x6810, 0x00000000);
	radeon_write_sync(0x6814, 0x00000000);
	radeon_read_sync(0x6b0c); /* 00000000 */
	radeon_write_sync(0x6b0c, 0x00000000);
	radeon_read_sync(0x6d70); /* 00000000 */
	radeon_write_sync(0x6d70, 0x00000000);
	radeon_write_sync(0x6d74, 0x04000300);
	radeon_read_sync(0x6824); /* 00000000 */
	radeon_write_sync(0x6824, 0x00000000);
	radeon_read_sync(0x6828); /* 00000000 */
	radeon_write_sync(0x6828, 0x00000000);
	radeon_read_sync(0x682c); /* 00000000 */
	radeon_write_sync(0x682c, 0x00000000);
	radeon_read_sync(0x6830); /* 00000000 */
	radeon_write_sync(0x6830, 0x00000000);
	radeon_read_sync(0x6838); /* 00000000 */
	radeon_write_sync(0x6838, 0x00000300);
	radeon_read_sync(0x6834); /* 00000000 */
	radeon_write_sync(0x6834, 0x00000400);
	radeon_read_sync(0x6804); /* 0a008008 */
	radeon_write_sync(0x6804, 0x0a008109);
	radeon_read_sync(0x6804); /* 0a008109 */
	radeon_write_sync(0x6804, 0x0a008109);
	radeon_read_sync(0x6818); /* 00000000 */
	radeon_write_sync(0x6818, 0x00000400);
	radeon_read_sync(0x6800); /* 00000000 */
	radeon_write_sync(0x6800, 0x00000001);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_write_sync(0x6e70, 0x10400310);
	radeon_read_sync(0x683c); /* 00000000 */
	radeon_write_sync(0x683c, 0x00000000);
	radeon_read_sync(0x68d4); /* 00000000 */
	radeon_write_sync(0x68d4, 0x00000000);
	radeon_read_sync(0x68f0); /* 00000000 */
	radeon_write_sync(0x68f0, 0x00000000);
	radeon_read_sync(0x6e84); /* 00000000 */
	radeon_write_sync(0x6e84, 0x00000000);
	radeon_read_sync(0x6e80); /* 00000000 */
	radeon_write_sync(0x6e80, 0x00000000);
	radeon_read_sync(0x6e88); /* 00000000 */
	radeon_write_sync(0x6e88, 0x00000000);
	radeon_read_sync(0x6bd8); /* 00000001 */
	radeon_write_sync(0x6bd8, 0x00000001);
	radeon_read_sync(0x69e0); /* 00000000 */
	radeon_write_sync(0x69e0, 0x00000000);
	radeon_read_sync(0x6a00); /* 00000000 */
	radeon_write_sync(0x6a00, 0x00000000);
	radeon_read_sync(0x6804); /* 0a008109 */
	radeon_read_sync(0x69f8); /* 00000007 */
	radeon_write_sync(0x69f8, 0x00000007);
	radeon_read_sync(0x69fc); /* 00000000 */
	radeon_write_sync(0x69fc, 0x00000001);
	radeon_delay(0x02f80e4e - 0x02f80dca);
	radeon_read_sync(0x69fc); /* 00000002 */
	radeon_read_sync(0x69fc); /* 00000002 */
	radeon_write_sync(0x69fc, 0x00000000);
	radeon_read_sync(0x6a04); /* 00000000 */
	radeon_write_sync(0x6a04, 0x00000000);
	radeon_read_sync(0x6a08); /* 00000000 */
	radeon_write_sync(0x6a08, 0x00000000);
	radeon_read_sync(0x6a0c); /* 00000000 */
	radeon_write_sync(0x6a0c, 0x00000000);
	radeon_read_sync(0x6a10); /* 0000ffff */
	radeon_write_sync(0x6a10, 0x0000ffff);
	radeon_read_sync(0x6a14); /* 0000ffff */
	radeon_write_sync(0x6a14, 0x0000ffff);
	radeon_read_sync(0x6a18); /* 0000ffff */
	radeon_write_sync(0x6a18, 0x0000ffff);
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x04fc); /* 00000010 */
	radeon_write_sync(0x04fc, 0x00000010);
	radeon_read_sync(0x0338); /* 00000000 */
	radeon_write_sync(0x0338, 0x00000000);
	radeon_read_sync(0x0328); /* 00000001 */
	radeon_write_sync(0x0328, 0x00000001);
	radeon_read_sync(0x0308); /* 00000011 */
	radeon_write_sync(0x0308, 0x00000011);
	radeon_read_sync(0x0318); /* 00000000 */
	radeon_write_sync(0x0318, 0x00000000);
	radeon_read_sync(0x0320); /* 00000000 */
	radeon_write_sync(0x0320, 0x00000000);
	radeon_read_sync(0x1740); /* 41170001 */
	radeon_write_sync(0x1740, 0x41170001);
	radeon_read_sync(0x0324); /* 0000000f */
	radeon_read_sync(0x0310); /* 00000000 */
	radeon_read_sync(0x0318); /* 00000000 */
	radeon_read_sync(0x0320); /* 00000000 */
	radeon_read_sync(0x741c); /* 00000000 */
	radeon_write_sync(0x741c, 0x0000000f);
	radeon_read_sync(0x7420); /* 00000000 */
	radeon_write_sync(0x7420, 0x0000000f);
	radeon_write_sync(0x7410, 0x00000000);
	radeon_write_sync(0x7414, 0x00000000);
	radeon_read_sync(0x770c); /* 00000000 */
	radeon_write_sync(0x770c, 0x00000000);
	radeon_read_sync(0x7970); /* 00000000 */
	radeon_write_sync(0x7970, 0x00000000);
	radeon_write_sync(0x7974, 0x04000300);
	radeon_read_sync(0x7424); /* 00000000 */
	radeon_write_sync(0x7424, 0x00000000);
	radeon_read_sync(0x7428); /* 00000000 */
	radeon_write_sync(0x7428, 0x00000000);
	radeon_read_sync(0x742c); /* 00000000 */
	radeon_write_sync(0x742c, 0x00000000);
	radeon_read_sync(0x7430); /* 00000000 */
	radeon_write_sync(0x7430, 0x00000000);
	radeon_read_sync(0x7438); /* 00000000 */
	radeon_write_sync(0x7438, 0x00000300);
	radeon_read_sync(0x7434); /* 00000000 */
	radeon_write_sync(0x7434, 0x00000400);
	radeon_read_sync(0x7404); /* 0a008008 */
	radeon_write_sync(0x7404, 0x0a008109);
	radeon_read_sync(0x7404); /* 0a008109 */
	radeon_write_sync(0x7404, 0x0a008109);
	radeon_read_sync(0x7418); /* 00000000 */
	radeon_write_sync(0x7418, 0x00000400);
	radeon_read_sync(0x7400); /* 00000001 */
	radeon_write_sync(0x7400, 0x00000001);
	radeon_read_sync(0x7a70); /* 00400310 */
	radeon_write_sync(0x7a70, 0x10400310);
	radeon_read_sync(0x743c); /* 00000000 */
	radeon_write_sync(0x743c, 0x00000000);
	radeon_read_sync(0x74d4); /* 00000000 */
	radeon_write_sync(0x74d4, 0x00000000);
	radeon_read_sync(0x74f0); /* 00000000 */
	radeon_write_sync(0x74f0, 0x00000000);
	radeon_read_sync(0x7a84); /* 00000000 */
	radeon_write_sync(0x7a84, 0x00000000);
	radeon_read_sync(0x7a80); /* 00000000 */
	radeon_write_sync(0x7a80, 0x00000000);
	radeon_read_sync(0x7a88); /* 00000000 */
	radeon_write_sync(0x7a88, 0x00000000);
	radeon_read_sync(0x77d8); /* 00000001 */
	radeon_write_sync(0x77d8, 0x00000001);
	radeon_read_sync(0x75e0); /* 00000000 */
	radeon_write_sync(0x75e0, 0x00000000);
	radeon_read_sync(0x7600); /* 00000000 */
	radeon_write_sync(0x7600, 0x00000000);
	radeon_read_sync(0x7404); /* 0a008109 */
	radeon_read_sync(0x75f8); /* 00000007 */
	radeon_write_sync(0x75f8, 0x00000007);
	radeon_read_sync(0x75fc); /* 00000000 */
	radeon_write_sync(0x75fc, 0x00000001);
	radeon_delay(0x02fbd9ac - 0x02fbd928);
	radeon_read_sync(0x75fc); /* 00000002 */
	radeon_read_sync(0x75fc); /* 00000002 */
	radeon_write_sync(0x75fc, 0x00000000);
	radeon_read_sync(0x7604); /* 00000000 */
	radeon_write_sync(0x7604, 0x00000000);
	radeon_read_sync(0x7608); /* 00000000 */
	radeon_write_sync(0x7608, 0x00000000);
	radeon_read_sync(0x760c); /* 00000000 */
	radeon_write_sync(0x760c, 0x00000000);
	radeon_read_sync(0x7610); /* 0000ffff */
	radeon_write_sync(0x7610, 0x0000ffff);
	radeon_read_sync(0x7614); /* 0000ffff */
	radeon_write_sync(0x7614, 0x0000ffff);
	radeon_read_sync(0x7618); /* 0000ffff */
	radeon_write_sync(0x7618, 0x0000ffff);
	radeon_read_sync(0x0310); /* 00000000 */
	radeon_read_sync(0x0324); /* 0000000f */
	radeon_read_sync(0x8604); /* 00000000 */
	radeon_write_sync(0x8604, 0x0000000f);
	radeon_write_sync(0x8600, 0x1fff9700);
	radeon_delay(0x02fd2fd0 - 0x02fd084e);
	radeon_read_sync(0x8680); /* 00000000 */
	radeon_read_sync(0x860c); /* 00000000 */
	radeon_write_sync(0x860c, 0x0000000f);
	radeon_write_sync(0x8608, 0x00000000);
	radeon_write_sync(0x8610, 0xd0300000);
	radeon_delay(0x02fdf2d0 - 0x02fdcba8);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02fe2fe4 - 0x02fe0880);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02fe6cfe - 0x02fe458a);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02fea9d8 - 0x02fe82a2);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x02fee696 - 0x02febf78);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02ff2360 - 0x02fefc3a);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02ff601a - 0x02ff38fc);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02ff9cd6 - 0x02ff75ae);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x02ffd9a4 - 0x02ffb26c);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x0300166e - 0x02ffef3c);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x03005342 - 0x03002c08);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x03009002 - 0x030068de);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0300ccea - 0x0300a5a8);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x030109c0 - 0x0300e294);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0301468e - 0x03011f5e);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x0301834e - 0x03015c32);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0301c018 - 0x030198ea);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0301fce4 - 0x0301d5b6);
	radeon_read_sync(0x8680); /* 00000000 */
	radeon_read_sync(0x860c); /* 0000000f */
	radeon_write_sync(0x860c, 0x0000000f);
	radeon_write_sync(0x8608, 0x00100000);
	radeon_write_sync(0x8610, 0xd0290000);
	radeon_delay(0x0302c580 - 0x03029e68);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x03030244 - 0x0302db30);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x03033f40 - 0x030317de);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x03037c42 - 0x030354d8);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x0303b944 - 0x030391d2);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x0303f63e - 0x0303cee0);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x03043348 - 0x03040bd6);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x03047038 - 0x030448e0);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0304ad26 - 0x030485cc);
	radeon_read_sync(0x8680); /* 804001c2 */
	radeon_delay(0x0304ea26 - 0x0304c2c2);
	radeon_read_sync(0x8680); /* 80400142 */
	radeon_delay(0x0305271e - 0x0304ffbc);
	radeon_read_sync(0x8680); /* 00000000 */
	radeon_write_sync(0x0048, 0x00010000);
	radeon_write_sync(0x004c, 0x00010000);
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x6df0); /* 00006260 */
	radeon_write_sync(0x6df0, 0x80006260);
	radeon_read_sync(0x6e70); /* 10400310 */
	radeon_write_sync(0x6e70, 0x10400311);
	radeon_read_sync(0x6ed8); /* 00010000 */
	radeon_write_sync(0x6ed8, 0x00010000);
	radeon_read_sync(0x69b8); /* 00000000 */
	radeon_write_sync(0x69b8, 0x00000000);
	radeon_read_sync(0x689c); /* 00000000 */
	radeon_write_sync(0x689c, 0x00000000);
	radeon_read_sync(0x6844); /* 00000000 */
	radeon_write_sync(0x6844, 0x00000000);
	radeon_read_sync(0x6ed4); /* 00000000 */
	radeon_write_sync(0x6ed4, 0x00000000);
	radeon_read_sync(0x6ef4); /* 00000001 */
	radeon_write_sync(0x6ef4, 0x00000000);
	radeon_read_sync(0x6ed8); /* 00010000 */
	radeon_read_sync(0x12000); /* 00000000 */
	radeon_write_sync(0x12000, 0x00000000);
	radeon_read_sync(0x6fc8); /* 00600000 */
	radeon_write_sync(0x6fc8, 0x00000000);
	radeon_write_sync(0x6fc8, 0x05010000);
	radeon_read_sync(0x6fb8); /* 00000000 */
	radeon_write_sync(0x6fb8, 0x00000000);
	radeon_read_sync(0x6fe4); /* 00000000 */
	radeon_write_sync(0x6fe4, 0x00000000);
	radeon_read_sync(0x6fb4); /* 00000000 */
	radeon_write_sync(0x6fb4, 0x00000000);
	radeon_read_sync(0x1220c); /* 00000000 */
	radeon_write_sync(0x1220c, 0x00000000);
	radeon_read_sync(0x1200c); /* 00000063 */
	radeon_write_sync(0x1200c, 0x0000001f);
	radeon_read_sync(0x12000); /* 00000000 */
	radeon_write_sync(0x12000, 0x00000000);
	radeon_read_sync(0x12304); /* 00000000 */
	radeon_write_sync(0x12304, 0x00000000);
	radeon_read_sync(0x12304); /* 00000000 */
	radeon_write_sync(0x12304, 0x00000000);
	radeon_read_sync(0x1230c); /* 00100200 */
	radeon_read_sync(0x12324); /* 00000000 */
	radeon_write_sync(0x12324, 0x00000000);
	radeon_write_sync(0x12328, 0x00008000);
	radeon_write_sync(0x1232c, 0x00008000);
	radeon_read_sync(0x12330); /* 10002000 */
	radeon_write_sync(0x12330, 0x10002000);
	radeon_read_sync(0x12000); /* 00000000 */
	radeon_write_sync(0x12000, 0x00000400);
	radeon_read_sync(0x12000); /* 00000000 */
	radeon_read_sync(0x6e70); /* 10410311 */
	radeon_write_sync(0x6e70, 0x10100311);
	radeon_read_sync(0x12354); /* 0101ff10 */
	radeon_write_sync(0x12354, 0x0101ff10);
	radeon_read_sync(0x12378); /* 00000000 */
	radeon_write_sync(0x12378, 0x00000001);
	radeon_read_sync(0x6718); /* 00000000 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 00000000 */
	radeon_write_sync(0x0204, 0x04000000);
	radeon_write_sync(0x022c, 0x00000123);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 04000000 */
	radeon_write_sync(0x0204, 0x040f0000);
	radeon_read_sync(0x0204); /* 040f0000 */
	radeon_write_sync(0x0204, 0x040f0000);
	radeon_read_sync(0x0204); /* 040f0000 */
	radeon_write_sync(0x0204, 0x040f0006);
	radeon_write_sync(0x022c, 0x00000118);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_read_sync(0x12140); /* 00010000 */
	radeon_write_sync(0x12140, 0x00011000);
	radeon_read_sync(0x12140); /* 00011000 */
	radeon_write_sync(0x12140, 0x00001000);
	radeon_read_sync(0x12140); /* 00001000 */
	radeon_write_sync(0x12140, 0x00001000);
	radeon_read_sync(0x12308); /* 00000000 */
	radeon_write_sync(0x12308, 0x00000000);
	radeon_read_sync(0x12234); /* 00000000 */
	radeon_write_sync(0x12234, 0x00000001);
	radeon_read_sync(0x12144); /* 00000000 */
	radeon_read_sync(0x6728); /* 00000000 */
	radeon_write_sync(0x6728, 0x00000001);
	radeon_write_sync(0x6738, 0x03020100);
	radeon_read_sync(0x6734); /* 00110100 */
	radeon_write_sync(0x6734, 0x00110100);
	radeon_read_sync(0x6734); /* 00110100 */
	radeon_write_sync(0x6734, 0x00000100);
	radeon_read_sync(0x671c); /* 00010506 */
	radeon_write_sync(0x671c, 0x00010506);
	radeon_write_sync(0x00e0, 0x01222002);
	radeon_read_sync(0x00e0); /* 01222002 */
	radeon_write_sync(0x00e0, 0x01226006);
	radeon_read_sync(0x00e4); /* 402a2a00 */
	radeon_read_sync(0x00e0); /* 01226006 */
	radeon_write_sync(0x00e0, 0x01226006);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226006 */
	radeon_write_sync(0x00e0, 0x01226086);
	radeon_read_sync(0x00e4); /* 402a2a00 */
	radeon_read_sync(0x00e0); /* 01226086 */
	radeon_write_sync(0x00e0, 0x01226086);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226086 */
	radeon_write_sync(0x00e0, 0x01226106);
	radeon_read_sync(0x00e4); /* 402a2a00 */
	radeon_read_sync(0x00e0); /* 01226106 */
	radeon_write_sync(0x00e0, 0x01226106);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226106 */
	radeon_write_sync(0x00e0, 0x01226186);
	radeon_read_sync(0x00e4); /* 402a2a00 */
	radeon_read_sync(0x00e0); /* 01226186 */
	radeon_write_sync(0x00e0, 0x01226186);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226186 */
	radeon_write_sync(0x00e0, 0x01226005);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226005 */
	radeon_write_sync(0x00e0, 0x01226005);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226005 */
	radeon_write_sync(0x00e0, 0x01226085);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226085 */
	radeon_write_sync(0x00e0, 0x01226085);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226085 */
	radeon_write_sync(0x00e0, 0x01226105);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226105 */
	radeon_write_sync(0x00e0, 0x01226105);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226105 */
	radeon_write_sync(0x00e0, 0x01226185);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226185 */
	radeon_write_sync(0x00e0, 0x01226185);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226185 */
	radeon_write_sync(0x00e0, 0x01226205);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226205 */
	radeon_write_sync(0x00e0, 0x01226205);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226205 */
	radeon_write_sync(0x00e0, 0x01226285);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226285 */
	radeon_write_sync(0x00e0, 0x01226285);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226285 */
	radeon_write_sync(0x00e0, 0x01226305);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226305 */
	radeon_write_sync(0x00e0, 0x01226305);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x00e0); /* 01226305 */
	radeon_write_sync(0x00e0, 0x01226385);
	radeon_read_sync(0x00e4); /* 00000000 */
	radeon_read_sync(0x00e0); /* 01226385 */
	radeon_write_sync(0x00e0, 0x01226385);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_write_sync(0x00e0, 0x01120011);
	radeon_read_sync(0x00e4); /* 00000300 */
	radeon_write_sync(0x00e4, 0x00000300);
	radeon_read_sync(0x611c); /* 00000002 */
	radeon_read_sync(0x5c18); /* 00011000 */
	radeon_write_sync(0x5c18, 0x00011010);
	radeon_write_sync(0x00e0, 0x0132804c);
	radeon_read_sync(0x00e4); /* 00000701 */
	radeon_write_sync(0x00e4, 0x00000701);
	radeon_write_sync(0x00e0, 0x01222002);
	radeon_read_sync(0x00e0); /* 01222002 */
	radeon_write_sync(0x00e0, 0x01220009);
	radeon_write_sync(0x00e4, 0x00000000);
	radeon_read_sync(0x671c); /* 00010506 */
	radeon_write_sync(0x671c, 0x00010506);
	radeon_read_sync(0x6718); /* 00000000 */
	radeon_write_sync(0x6718, 0x00000001);
	radeon_write_sync(0x00e0, 0x0132804c);
	radeon_read_sync(0x00e4); /* 00000701 */
	radeon_read_sync(0x00e4); /* 00000701 */
	radeon_read_sync(0x00e4); /* 00000701 */
	radeon_read_sync(0x00e4); /* 00000701 */
	radeon_read_sync(0x00e4); /* 00000704 */
	radeon_read_sync(0x0590); /* 00000400 */
	radeon_write_sync(0x0590, 0x00000401);
	radeon_read_sync(0x12144); /* 00000100 */
	radeon_write_sync(0x12144, 0x00000101);
	radeon_delay(0x03160f06 - 0x03160cd6);
	radeon_read_sync(0x6734); /* 00000100 */
	radeon_write_sync(0x6734, 0x00000101);
	radeon_delay(0x03163414 - 0x031631ec);
	radeon_read_sync(0x6728); /* 00000001 */
	radeon_write_sync(0x6728, 0x00001001);
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 040f0006 */
	radeon_write_sync(0x0204, 0x040f0006);
	radeon_read_sync(0x0204); /* 040f0006 */
	radeon_write_sync(0x0204, 0x040f0006);
	radeon_read_sync(0x0204); /* 040f0006 */
	radeon_write_sync(0x0204, 0x040f0001);
	radeon_write_sync(0x022c, 0x00000117);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 040f0001 */
	radeon_write_sync(0x0204, 0x040f0001);
	radeon_write_sync(0x022c, 0x00000122);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000600);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x031a29c4 - 0x031a2796);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x12300); /* 00000000 */
	radeon_write_sync(0x12300, 0x00000000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_write_sync(0x6218, 0x00008100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x031d8ba4 - 0x031d8974);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000700);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00001000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00004e00);
	radeon_write_sync(0x6218, 0x00000c00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x03204470 - 0x03204244);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0322fa48 - 0x0322f81c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x12344); /* 00000000 */
	radeon_write_sync(0x12344, 0x00000000);
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 040f0001 */
	radeon_write_sync(0x0204, 0x040f0001);
	radeon_write_sync(0x022c, 0x00000123);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_write_sync(0x00e0, 0x01222002);
	radeon_read_sync(0x00e0); /* 01222002 */
	radeon_write_sync(0x00e0, 0x01226006);
	radeon_read_sync(0x00e4); /* 402a0055 */
	radeon_read_sync(0x00e0); /* 01226006 */
	radeon_write_sync(0x00e0, 0x01226006);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226006 */
	radeon_write_sync(0x00e0, 0x01226086);
	radeon_read_sync(0x00e4); /* 402a0055 */
	radeon_read_sync(0x00e0); /* 01226086 */
	radeon_write_sync(0x00e0, 0x01226086);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226086 */
	radeon_write_sync(0x00e0, 0x01226106);
	radeon_read_sync(0x00e4); /* 402a0055 */
	radeon_read_sync(0x00e0); /* 01226106 */
	radeon_write_sync(0x00e0, 0x01226106);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x00e0); /* 01226106 */
	radeon_write_sync(0x00e0, 0x01226186);
	radeon_read_sync(0x00e4); /* 402a0055 */
	radeon_read_sync(0x00e0); /* 01226186 */
	radeon_write_sync(0x00e0, 0x01226186);
	radeon_write_sync(0x00e4, 0x402a0055);
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x0200, 0x0001f478);
	radeon_read_sync(0x0204); /* 040f0001 */
	radeon_write_sync(0x0204, 0x040f0001);
	radeon_write_sync(0x022c, 0x00000122);
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000000 */
	radeon_read_sync(0x0230); /* 00000001 */
	radeon_delay(0x03277108 - 0x032722e8);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x03299e9e - 0x03299c70);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x032c569e - 0x032c5472);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x032cf836 - 0x032ce4a8);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x032eb522 - 0x032eb2f6);
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6218); /* 00010101 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00038001 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_read_sync(0x12344); /* 00000000 */
	radeon_write_sync(0x12344, 0x00000001);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c7000000 */
	radeon_delay(0x0332eac4 - 0x0332e892);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000300);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0335a262 - 0x0335a038);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x03367dde - 0x03362f60);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x03383ad2 - 0x033838a8);
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6218); /* 00010701 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00038101 */
	radeon_read_sync(0x6218); /* 00040101 */
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_write_sync(0x6218, 0x80008000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c7000000 */
	radeon_delay(0x033bc0ee - 0x033bbec0);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x12300); /* 00000000 */
	radeon_write_sync(0x12300, 0x00000010);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000100);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x033eb084 - 0x033eae54);
	radeon_read_sync(0x6210); /* 04000001 */
	radeon_read_sync(0x6210); /* 04000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 04000001 */
	radeon_read_sync(0x6218); /* 00010a01 */
	radeon_read_sync(0x6218); /* 00028101 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 00040101 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000200);
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c4000000 */
	radeon_delay(0x03415ac6 - 0x0341589e);
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 07000001 */
	radeon_read_sync(0x6218); /* 00010701 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030101 */
	radeon_read_sync(0x6218); /* 00040101 */
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_write_sync(0x6218, 0x80009000);
	radeon_write_sync(0x6218, 0x00000600);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c7000000 */
	radeon_delay(0x03445986 - 0x0344575e);
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 02000001 */
	radeon_read_sync(0x6218); /* 00010101 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030101 */
	radeon_read_sync(0x6218); /* 00040101 */
	radeon_read_sync(0x12324); /* 00000000 */
	radeon_write_sync(0x12324, 0x00000100);
	radeon_delay(0x03461076 - 0x03460e48);
	radeon_read_sync(0x12310); /* 00000000 */
	radeon_write_sync(0x12310, 0x00000000);
	radeon_delay(0x03462540 - 0x0346231c);
	radeon_read_sync(0x1230c); /* 00100200 */
	radeon_write_sync(0x1230c, 0x00100201);
	radeon_delay(0x03465fa0 - 0x0346387a);
	radeon_read_sync(0x6464); /* 00000000 */
	radeon_write_sync(0x6464, 0x03000000);
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	vga_sr_read(0x01); /* 21 */
	outb(0x01, 0x03c5);
	radeon_read_sync(0x6e74); /* 00000101 */
	radeon_write_sync(0x6e74, 0x00000101);
	radeon_read_sync(0x6e74); /* 00000101 */
	radeon_write_sync(0x6e74, 0x00000001);
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

