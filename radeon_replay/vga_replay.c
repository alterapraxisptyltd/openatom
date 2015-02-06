#include <sys/io.h>

#include "replay_util.h"
#include "vga_io.h"

void run_replay(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	sync_read();
	radeon_write_sync(0x1728, 0x0008c000);
	radeon_read_sync(0x3f54); /* 00000000 */
	radeon_write_sync(0x174c, 0x00000000);
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
	radeon_write_sync(0x9fffb000, 0x0101008c);
	radeon_write_sync(0x9fffb004, 0x00000000);
	radeon_write_sync(0x9fffb008, 0x00000000);
	radeon_write_sync(0x9fffb00c, 0x00000000);
	radeon_write_sync(0x9fffb010, 0x00000000);
	radeon_write_sync(0x9fffb014, 0x01100002);
	radeon_write_sync(0x9fffb018, 0x0000310e);
	radeon_write_sync(0x9fffb01c, 0x00e42223);
	radeon_write_sync(0x9fffb020, 0x00000000);
	radeon_write_sync(0x9fffb024, 0x01000001);
	radeon_write_sync(0x9fffb028, 0x01013105);
	radeon_write_sync(0x9fffb02c, 0x00e42122);
	radeon_write_sync(0x9fffb030, 0x00000000);
	radeon_write_sync(0x9fffb034, 0x02100008);
	radeon_write_sync(0x9fffb038, 0x0202310c);
	radeon_write_sync(0x9fffb03c, 0x00e40000);
	radeon_write_sync(0x9fffb040, 0x00000000);
	radeon_write_sync(0x9fffb044, 0x00000000);
	radeon_write_sync(0x9fffb048, 0x00000000);
	radeon_write_sync(0x9fffb04c, 0x00000000);
	radeon_write_sync(0x9fffb050, 0x00000000);
	radeon_write_sync(0x9fffb054, 0x00000000);
	radeon_write_sync(0x9fffb058, 0x00000000);
	radeon_write_sync(0x9fffb05c, 0x00000000);
	radeon_write_sync(0x9fffb060, 0x00000000);
	radeon_write_sync(0x9fffb064, 0x00000000);
	radeon_write_sync(0x9fffb068, 0x00000000);
	radeon_write_sync(0x9fffb06c, 0x00000000);
	radeon_write_sync(0x9fffb070, 0x00000000);
	radeon_write_sync(0x9fffb074, 0x00000000);
	radeon_write_sync(0x9fffb078, 0x00000000);
	radeon_write_sync(0x9fffb07c, 0x00000000);
	radeon_write_sync(0x9fffb080, 0x00000000);
	radeon_write_sync(0x9fffb084, 0x00000000);
	radeon_write_sync(0x9fffb088, 0x00000000);
	radeon_write_sync(0x9fffa400, 0x00000000);
	radeon_write_sync(0x9fffa404, 0x00000000);
	radeon_write_sync(0x9fffa408, 0x00000000);
	radeon_write_sync(0x9fffa40c, 0x00000000);
	radeon_write_sync(0x9fffa410, 0x00000000);
	radeon_write_sync(0x9fffa414, 0x00000000);
	radeon_write_sync(0x9fffa418, 0x00000000);
	radeon_write_sync(0x9fffa41c, 0x00000000);
	radeon_write_sync(0x9fffa420, 0x00000000);
	radeon_write_sync(0x9fffa424, 0x00000000);
	radeon_write_sync(0x9fffa428, 0x00000000);
	radeon_write_sync(0x9fffa42c, 0x00000000);
	radeon_write_sync(0x9fffa430, 0x00000000);
	radeon_write_sync(0x9fffa434, 0x00000000);
	radeon_write_sync(0x9fffa438, 0x00000000);
	radeon_write_sync(0x9fffa43c, 0x00000000);
	radeon_write_sync(0x9fffa440, 0x00000000);
	radeon_write_sync(0x9fffa444, 0x00000000);
	radeon_write_sync(0x9fffa448, 0x00000000);
	radeon_write_sync(0x9fffa44c, 0x00000000);
	radeon_write_sync(0x9fffa450, 0x00000000);
	radeon_write_sync(0x9fffa454, 0x00000000);
	radeon_write_sync(0x9fffa458, 0x00000000);
	radeon_write_sync(0x9fffa45c, 0x00000000);
	radeon_write_sync(0x9fffa460, 0x00000000);
	radeon_write_sync(0x9fffa464, 0x00000000);
	radeon_write_sync(0x9fffa468, 0x00000000);
	radeon_write_sync(0x9fffa46c, 0x00000000);
	radeon_write_sync(0x9fffa470, 0x00000000);
	radeon_write_sync(0x9fffa474, 0x00000000);
	radeon_write_sync(0x9fffa478, 0x00000000);
	radeon_write_sync(0x9fffa47c, 0x00000000);
	radeon_write_sync(0x9fffa480, 0x00000000);
	radeon_write_sync(0x9fffa484, 0x00000000);
	radeon_write_sync(0x9fffa488, 0x00000000);
	radeon_write_sync(0x9fffa48c, 0x00000000);
	radeon_write_sync(0x9fffa490, 0x00000000);
	radeon_write_sync(0x9fffa494, 0x00000000);
	radeon_write_sync(0x9fffa498, 0x00000000);
	radeon_write_sync(0x9fffa49c, 0x00000000);
	radeon_write_sync(0x9fffa4a0, 0x00000000);
	radeon_write_sync(0x9fffa4a4, 0x00000000);
	radeon_write_sync(0x9fffa4a8, 0x00000000);
	radeon_write_sync(0x9fffa4ac, 0x00000000);
	radeon_write_sync(0x9fffa4b0, 0x00000000);
	radeon_write_sync(0x9fffa4b4, 0x00000000);
	radeon_write_sync(0x9fffa4b8, 0x00000000);
	radeon_write_sync(0x9fffa4bc, 0x00000000);
	radeon_write_sync(0x9fffa4c0, 0x00000000);
	radeon_write_sync(0x9fffa4c4, 0x00000000);
	radeon_write_sync(0x9fffa4c8, 0x00000000);
	radeon_write_sync(0x9fffa4cc, 0x00000000);
	radeon_write_sync(0x9fffa4d0, 0x00000000);
	radeon_write_sync(0x9fffa4d4, 0x00000000);
	radeon_write_sync(0x9fffa4d8, 0x00000000);
	radeon_write_sync(0x9fffa4dc, 0x00000000);
	radeon_write_sync(0x9fffa4e0, 0x00000000);
	radeon_write_sync(0x9fffa4e4, 0x00000000);
	radeon_write_sync(0x9fffa4e8, 0x00000000);
	radeon_write_sync(0x9fffa4ec, 0x00000000);
	radeon_write_sync(0x9fffa4f0, 0x00000000);
	radeon_write_sync(0x9fffa4f4, 0x00000000);
	radeon_write_sync(0x9fffa4f8, 0x00000000);
	radeon_write_sync(0x9fffa4fc, 0x00000000);
	radeon_write_sync(0x9fffa500, 0x00000000);
	radeon_write_sync(0x9fffa504, 0x00000000);
	radeon_write_sync(0x9fffa508, 0x00000000);
	radeon_write_sync(0x9fffa50c, 0x00000000);
	radeon_write_sync(0x9fffa510, 0x00000000);
	radeon_write_sync(0x9fffa514, 0x00000000);
	radeon_write_sync(0x9fffa518, 0x00000000);
	radeon_write_sync(0x9fffa51c, 0x00000000);
	radeon_write_sync(0x9fffa520, 0x00000000);
	radeon_write_sync(0x9fffa524, 0x00000000);
	radeon_write_sync(0x9fffa528, 0x00000000);
	radeon_write_sync(0x9fffa52c, 0x00000000);
	radeon_write_sync(0x9fffa530, 0x00000000);
	radeon_write_sync(0x9fffa534, 0x00000000);
	radeon_write_sync(0x9fffa538, 0x00000000);
	radeon_write_sync(0x9fffa53c, 0x00000000);
	radeon_write_sync(0x9fffa540, 0x00000000);
	radeon_write_sync(0x9fffa544, 0x00000000);
	radeon_write_sync(0x9fffa548, 0x00000000);
	radeon_write_sync(0x9fffa54c, 0x00000000);
	radeon_write_sync(0x9fffa550, 0x00000000);
	radeon_write_sync(0x9fffa554, 0x00000000);
	radeon_write_sync(0x9fffa558, 0x00000000);
	radeon_write_sync(0x9fffa55c, 0x00000000);
	radeon_write_sync(0x9fffa560, 0x00000000);
	radeon_write_sync(0x9fffa564, 0x00000000);
	radeon_write_sync(0x9fffa568, 0x00000000);
	radeon_write_sync(0x9fffa56c, 0x00000000);
	radeon_write_sync(0x9fffa570, 0x00000000);
	radeon_write_sync(0x9fffa574, 0x00000000);
	radeon_write_sync(0x9fffa578, 0x00000000);
	radeon_write_sync(0x9fffa57c, 0x00000000);
	radeon_write_sync(0x9fffa580, 0x00000000);
	radeon_write_sync(0x9fffa584, 0x00000000);
	radeon_write_sync(0x9fffa588, 0x00000000);
	radeon_write_sync(0x9fffa58c, 0x00000000);
	radeon_write_sync(0x9fffa590, 0x00000000);
	radeon_write_sync(0x9fffa594, 0x00000000);
	radeon_write_sync(0x9fffa598, 0x00000000);
	radeon_write_sync(0x9fffa59c, 0x00000000);
	radeon_write_sync(0x9fffa5a0, 0x00000000);
	radeon_write_sync(0x9fffa5a4, 0x00000000);
	radeon_write_sync(0x9fffa5a8, 0x00000000);
	radeon_write_sync(0x9fffa5ac, 0x00000000);
	radeon_write_sync(0x9fffa5b0, 0x00000000);
	radeon_write_sync(0x9fffa5b4, 0x00000000);
	radeon_write_sync(0x9fffa5b8, 0x00000000);
	radeon_write_sync(0x9fffa5bc, 0x00000000);
	radeon_write_sync(0x9fffa5c0, 0x00000000);
	radeon_write_sync(0x9fffa5c4, 0x00000000);
	radeon_write_sync(0x9fffa5c8, 0x00000000);
	radeon_write_sync(0x9fffa5cc, 0x00000000);
	radeon_write_sync(0x9fffa5d0, 0x00000000);
	radeon_write_sync(0x9fffa5d4, 0x00000000);
	radeon_write_sync(0x9fffa5d8, 0x00000000);
	radeon_write_sync(0x9fffa5dc, 0x00000000);
	radeon_write_sync(0x9fffa5e0, 0x00000000);
	radeon_write_sync(0x9fffa5e4, 0x00000000);
	radeon_write_sync(0x9fffa5e8, 0x00000000);
	radeon_write_sync(0x9fffa5ec, 0x00000000);
	radeon_write_sync(0x9fffa5f0, 0x00000000);
	radeon_write_sync(0x9fffa5f4, 0x00000000);
	radeon_write_sync(0x9fffa5f8, 0x00000000);
	radeon_write_sync(0x9fffa5fc, 0x00000000);
	radeon_write_sync(0x9fffa600, 0x00000000);
	radeon_write_sync(0x9fffa604, 0x00000000);
	radeon_write_sync(0x9fffa608, 0x00000000);
	radeon_write_sync(0x9fffa60c, 0x00000000);
	radeon_write_sync(0x9fffa610, 0x00000000);
	radeon_write_sync(0x9fffa614, 0x00000000);
	radeon_write_sync(0x9fffa618, 0x00000000);
	radeon_write_sync(0x9fffa61c, 0x00000000);
	radeon_write_sync(0x9fffa620, 0x00000000);
	radeon_write_sync(0x9fffa624, 0x00000000);
	radeon_write_sync(0x9fffa628, 0x00000000);
	radeon_write_sync(0x9fffa62c, 0x00000000);
	radeon_write_sync(0x9fffa630, 0x00000000);
	radeon_write_sync(0x9fffa634, 0x00000000);
	radeon_write_sync(0x9fffa638, 0x00000000);
	radeon_write_sync(0x9fffa63c, 0x00000000);
	radeon_write_sync(0x9fffa640, 0x00000000);
	radeon_write_sync(0x9fffa644, 0x00000000);
	radeon_write_sync(0x9fffa648, 0x00000000);
	radeon_write_sync(0x9fffa64c, 0x00000000);
	radeon_write_sync(0x9fffa650, 0x00000000);
	radeon_write_sync(0x9fffa654, 0x00000000);
	radeon_write_sync(0x9fffa658, 0x00000000);
	radeon_write_sync(0x9fffa65c, 0x00000000);
	radeon_write_sync(0x9fffa660, 0x00000000);
	radeon_write_sync(0x9fffa664, 0x00000000);
	radeon_write_sync(0x9fffa668, 0x00000000);
	radeon_write_sync(0x9fffa66c, 0x00000000);
	radeon_write_sync(0x9fffa670, 0x00000000);
	radeon_write_sync(0x9fffa674, 0x00000000);
	radeon_write_sync(0x9fffa678, 0x00000000);
	radeon_write_sync(0x9fffa67c, 0x00000000);
	radeon_write_sync(0x9fffa680, 0x00000000);
	radeon_write_sync(0x9fffa684, 0x00000000);
	radeon_write_sync(0x9fffa688, 0x00000000);
	radeon_write_sync(0x9fffa68c, 0x00000000);
	radeon_write_sync(0x9fffa690, 0x00000000);
	radeon_write_sync(0x9fffa694, 0x00000000);
	radeon_write_sync(0x9fffa698, 0x00000000);
	radeon_write_sync(0x9fffa69c, 0x00000000);
	radeon_write_sync(0x9fffa6a0, 0x00000000);
	radeon_write_sync(0x9fffa6a4, 0x00000000);
	radeon_write_sync(0x9fffa6a8, 0x00000000);
	radeon_write_sync(0x9fffa6ac, 0x00000000);
	radeon_write_sync(0x9fffa6b0, 0x00000000);
	radeon_write_sync(0x9fffa6b4, 0x00000000);
	radeon_write_sync(0x9fffa6b8, 0x00000000);
	radeon_write_sync(0x9fffa6bc, 0x00000000);
	radeon_write_sync(0x9fffa6c0, 0x00000000);
	radeon_write_sync(0x9fffa6c4, 0x00000000);
	radeon_write_sync(0x9fffa6c8, 0x00000000);
	radeon_write_sync(0x9fffa6cc, 0x00000000);
	radeon_write_sync(0x9fffa6d0, 0x00000000);
	radeon_write_sync(0x9fffa6d4, 0x00000000);
	radeon_write_sync(0x9fffa6d8, 0x00000000);
	radeon_write_sync(0x9fffa6dc, 0x00000000);
	radeon_write_sync(0x9fffa6e0, 0x00000000);
	radeon_write_sync(0x9fffa6e4, 0x00000000);
	radeon_write_sync(0x9fffa6e8, 0x00000000);
	radeon_write_sync(0x9fffa6ec, 0x00000000);
	radeon_write_sync(0x9fffa6f0, 0x00000000);
	radeon_write_sync(0x9fffa6f4, 0x00000000);
	radeon_write_sync(0x9fffa6f8, 0x00000000);
	radeon_write_sync(0x9fffa6fc, 0x00000000);
	radeon_write_sync(0x9fffa700, 0x00000000);
	radeon_write_sync(0x9fffa704, 0x00000000);
	radeon_write_sync(0x9fffa708, 0x00000000);
	radeon_write_sync(0x9fffa70c, 0x00000000);
	radeon_write_sync(0x9fffa710, 0x00000000);
	radeon_write_sync(0x9fffa714, 0x00000000);
	radeon_write_sync(0x9fffa718, 0x00000000);
	radeon_write_sync(0x9fffa71c, 0x00000000);
	radeon_write_sync(0x9fffa720, 0x00000000);
	radeon_write_sync(0x9fffa724, 0x00000000);
	radeon_write_sync(0x9fffa728, 0x00000000);
	radeon_write_sync(0x9fffa72c, 0x00000000);
	radeon_write_sync(0x9fffa730, 0x00000000);
	radeon_write_sync(0x9fffa734, 0x00000000);
	radeon_write_sync(0x9fffa738, 0x00000000);
	radeon_write_sync(0x9fffa73c, 0x00000000);
	radeon_write_sync(0x9fffa740, 0x00000000);
	radeon_write_sync(0x9fffa744, 0x00000000);
	radeon_write_sync(0x9fffa748, 0x00000000);
	radeon_write_sync(0x9fffa74c, 0x00000000);
	radeon_write_sync(0x9fffa750, 0x00000000);
	radeon_write_sync(0x9fffa754, 0x00000000);
	radeon_write_sync(0x9fffa758, 0x00000000);
	radeon_write_sync(0x9fffa75c, 0x00000000);
	radeon_write_sync(0x9fffa760, 0x00000000);
	radeon_write_sync(0x9fffa764, 0x00000000);
	radeon_write_sync(0x9fffa768, 0x00000000);
	radeon_write_sync(0x9fffa76c, 0x00000000);
	radeon_write_sync(0x9fffa770, 0x00000000);
	radeon_write_sync(0x9fffa774, 0x00000000);
	radeon_write_sync(0x9fffa778, 0x00000000);
	radeon_write_sync(0x9fffa77c, 0x00000000);
	radeon_write_sync(0x9fffa780, 0x00000000);
	radeon_write_sync(0x9fffa784, 0x00000000);
	radeon_write_sync(0x9fffa788, 0x00000000);
	radeon_write_sync(0x9fffa78c, 0x00000000);
	radeon_write_sync(0x9fffa790, 0x00000000);
	radeon_write_sync(0x9fffa794, 0x00000000);
	radeon_write_sync(0x9fffa798, 0x00000000);
	radeon_write_sync(0x9fffa79c, 0x00000000);
	radeon_write_sync(0x9fffa7a0, 0x00000000);
	radeon_write_sync(0x9fffa7a4, 0x00000000);
	radeon_write_sync(0x9fffa7a8, 0x00000000);
	radeon_write_sync(0x9fffa7ac, 0x00000000);
	radeon_write_sync(0x9fffa7b0, 0x00000000);
	radeon_write_sync(0x9fffa7b4, 0x00000000);
	radeon_write_sync(0x9fffa7b8, 0x00000000);
	radeon_write_sync(0x9fffa7bc, 0x00000000);
	radeon_write_sync(0x9fffa7c0, 0x00000000);
	radeon_write_sync(0x9fffa7c4, 0x00000000);
	radeon_write_sync(0x9fffa7c8, 0x00000000);
	radeon_write_sync(0x9fffa7cc, 0x00000000);
	radeon_write_sync(0x9fffa7d0, 0x00000000);
	radeon_write_sync(0x9fffa7d4, 0x00000000);
	radeon_write_sync(0x9fffa7d8, 0x00000000);
	radeon_write_sync(0x9fffa7dc, 0x00000000);
	radeon_write_sync(0x9fffa7e0, 0x00000000);
	radeon_write_sync(0x9fffa7e4, 0x00000000);
	radeon_write_sync(0x9fffa7e8, 0x00000000);
	radeon_write_sync(0x9fffa408, 0x00000002);
	radeon_write_sync(0x9fffa414, 0x22232121);
	radeon_write_sync(0x9fffa40c, 0x0000310e);
	radeon_write_sync(0x9fffa410, 0x00000190);
	radeon_write_sync(0x9fffa800, 0x00000000);
	radeon_write_sync(0x9fffa804, 0x00000000);
	radeon_write_sync(0x9fffa808, 0x00000000);
	radeon_write_sync(0x9fffa80c, 0x00000000);
	radeon_write_sync(0x9fffa810, 0x00000000);
	radeon_write_sync(0x9fffa814, 0x00000000);
	radeon_write_sync(0x9fffa818, 0x00000000);
	radeon_write_sync(0x9fffa81c, 0x00000000);
	radeon_write_sync(0x9fffa820, 0x00000000);
	radeon_write_sync(0x9fffa824, 0x00000000);
	radeon_write_sync(0x9fffa828, 0x00000000);
	radeon_write_sync(0x9fffa82c, 0x00000000);
	radeon_write_sync(0x9fffa830, 0x00000000);
	radeon_write_sync(0x9fffa834, 0x00000000);
	radeon_write_sync(0x9fffa838, 0x00000000);
	radeon_write_sync(0x9fffa83c, 0x00000000);
	radeon_write_sync(0x9fffa840, 0x00000000);
	radeon_write_sync(0x9fffa844, 0x00000000);
	radeon_write_sync(0x9fffa848, 0x00000000);
	radeon_write_sync(0x9fffa84c, 0x00000000);
	radeon_write_sync(0x9fffa850, 0x00000000);
	radeon_write_sync(0x9fffa854, 0x00000000);
	radeon_write_sync(0x9fffa858, 0x00000000);
	radeon_write_sync(0x9fffa85c, 0x00000000);
	radeon_write_sync(0x9fffa860, 0x00000000);
	radeon_write_sync(0x9fffa864, 0x00000000);
	radeon_write_sync(0x9fffa868, 0x00000000);
	radeon_write_sync(0x9fffa86c, 0x00000000);
	radeon_write_sync(0x9fffa870, 0x00000000);
	radeon_write_sync(0x9fffa874, 0x00000000);
	radeon_write_sync(0x9fffa878, 0x00000000);
	radeon_write_sync(0x9fffa87c, 0x00000000);
	radeon_write_sync(0x9fffa880, 0x00000000);
	radeon_write_sync(0x9fffa884, 0x00000000);
	radeon_write_sync(0x9fffa888, 0x00000000);
	radeon_write_sync(0x9fffa88c, 0x00000000);
	radeon_write_sync(0x9fffa890, 0x00000000);
	radeon_write_sync(0x9fffa894, 0x00000000);
	radeon_write_sync(0x9fffa898, 0x00000000);
	radeon_write_sync(0x9fffa89c, 0x00000000);
	radeon_write_sync(0x9fffa8a0, 0x00000000);
	radeon_write_sync(0x9fffa8a4, 0x00000000);
	radeon_write_sync(0x9fffa8a8, 0x00000000);
	radeon_write_sync(0x9fffa8ac, 0x00000000);
	radeon_write_sync(0x9fffa8b0, 0x00000000);
	radeon_write_sync(0x9fffa8b4, 0x00000000);
	radeon_write_sync(0x9fffa8b8, 0x00000000);
	radeon_write_sync(0x9fffa8bc, 0x00000000);
	radeon_write_sync(0x9fffa8c0, 0x00000000);
	radeon_write_sync(0x9fffa8c4, 0x00000000);
	radeon_write_sync(0x9fffa8c8, 0x00000000);
	radeon_write_sync(0x9fffa8cc, 0x00000000);
	radeon_write_sync(0x9fffa8d0, 0x00000000);
	radeon_write_sync(0x9fffa8d4, 0x00000000);
	radeon_write_sync(0x9fffa8d8, 0x00000000);
	radeon_write_sync(0x9fffa8dc, 0x00000000);
	radeon_write_sync(0x9fffa8e0, 0x00000000);
	radeon_write_sync(0x9fffa8e4, 0x00000000);
	radeon_write_sync(0x9fffa8e8, 0x00000000);
	radeon_write_sync(0x9fffa8ec, 0x00000000);
	radeon_write_sync(0x9fffa8f0, 0x00000000);
	radeon_write_sync(0x9fffa8f4, 0x00000000);
	radeon_write_sync(0x9fffa8f8, 0x00000000);
	radeon_write_sync(0x9fffa8fc, 0x00000000);
	radeon_write_sync(0x9fffa900, 0x00000000);
	radeon_write_sync(0x9fffa904, 0x00000000);
	radeon_write_sync(0x9fffa908, 0x00000000);
	radeon_write_sync(0x9fffa90c, 0x00000000);
	radeon_write_sync(0x9fffa910, 0x00000000);
	radeon_write_sync(0x9fffa914, 0x00000000);
	radeon_write_sync(0x9fffa918, 0x00000000);
	radeon_write_sync(0x9fffa91c, 0x00000000);
	radeon_write_sync(0x9fffa920, 0x00000000);
	radeon_write_sync(0x9fffa924, 0x00000000);
	radeon_write_sync(0x9fffa928, 0x00000000);
	radeon_write_sync(0x9fffa92c, 0x00000000);
	radeon_write_sync(0x9fffa930, 0x00000000);
	radeon_write_sync(0x9fffa934, 0x00000000);
	radeon_write_sync(0x9fffa938, 0x00000000);
	radeon_write_sync(0x9fffa93c, 0x00000000);
	radeon_write_sync(0x9fffa940, 0x00000000);
	radeon_write_sync(0x9fffa944, 0x00000000);
	radeon_write_sync(0x9fffa948, 0x00000000);
	radeon_write_sync(0x9fffa94c, 0x00000000);
	radeon_write_sync(0x9fffa950, 0x00000000);
	radeon_write_sync(0x9fffa954, 0x00000000);
	radeon_write_sync(0x9fffa958, 0x00000000);
	radeon_write_sync(0x9fffa95c, 0x00000000);
	radeon_write_sync(0x9fffa960, 0x00000000);
	radeon_write_sync(0x9fffa964, 0x00000000);
	radeon_write_sync(0x9fffa968, 0x00000000);
	radeon_write_sync(0x9fffa96c, 0x00000000);
	radeon_write_sync(0x9fffa970, 0x00000000);
	radeon_write_sync(0x9fffa974, 0x00000000);
	radeon_write_sync(0x9fffa978, 0x00000000);
	radeon_write_sync(0x9fffa97c, 0x00000000);
	radeon_write_sync(0x9fffa980, 0x00000000);
	radeon_write_sync(0x9fffa984, 0x00000000);
	radeon_write_sync(0x9fffa988, 0x00000000);
	radeon_write_sync(0x9fffa98c, 0x00000000);
	radeon_write_sync(0x9fffa990, 0x00000000);
	radeon_write_sync(0x9fffa994, 0x00000000);
	radeon_write_sync(0x9fffa998, 0x00000000);
	radeon_write_sync(0x9fffa99c, 0x00000000);
	radeon_write_sync(0x9fffa9a0, 0x00000000);
	radeon_write_sync(0x9fffa9a4, 0x00000000);
	radeon_write_sync(0x9fffa9a8, 0x00000000);
	radeon_write_sync(0x9fffa9ac, 0x00000000);
	radeon_write_sync(0x9fffa9b0, 0x00000000);
	radeon_write_sync(0x9fffa9b4, 0x00000000);
	radeon_write_sync(0x9fffa9b8, 0x00000000);
	radeon_write_sync(0x9fffa9bc, 0x00000000);
	radeon_write_sync(0x9fffa9c0, 0x00000000);
	radeon_write_sync(0x9fffa9c4, 0x00000000);
	radeon_write_sync(0x9fffa9c8, 0x00000000);
	radeon_write_sync(0x9fffa9cc, 0x00000000);
	radeon_write_sync(0x9fffa9d0, 0x00000000);
	radeon_write_sync(0x9fffa9d4, 0x00000000);
	radeon_write_sync(0x9fffa9d8, 0x00000000);
	radeon_write_sync(0x9fffa9dc, 0x00000000);
	radeon_write_sync(0x9fffa9e0, 0x00000000);
	radeon_write_sync(0x9fffa9e4, 0x00000000);
	radeon_write_sync(0x9fffa9e8, 0x00000000);
	radeon_write_sync(0x9fffa9ec, 0x00000000);
	radeon_write_sync(0x9fffa9f0, 0x00000000);
	radeon_write_sync(0x9fffa9f4, 0x00000000);
	radeon_write_sync(0x9fffa9f8, 0x00000000);
	radeon_write_sync(0x9fffa9fc, 0x00000000);
	radeon_write_sync(0x9fffaa00, 0x00000000);
	radeon_write_sync(0x9fffaa04, 0x00000000);
	radeon_write_sync(0x9fffaa08, 0x00000000);
	radeon_write_sync(0x9fffaa0c, 0x00000000);
	radeon_write_sync(0x9fffaa10, 0x00000000);
	radeon_write_sync(0x9fffaa14, 0x00000000);
	radeon_write_sync(0x9fffaa18, 0x00000000);
	radeon_write_sync(0x9fffaa1c, 0x00000000);
	radeon_write_sync(0x9fffaa20, 0x00000000);
	radeon_write_sync(0x9fffaa24, 0x00000000);
	radeon_write_sync(0x9fffaa28, 0x00000000);
	radeon_write_sync(0x9fffaa2c, 0x00000000);
	radeon_write_sync(0x9fffaa30, 0x00000000);
	radeon_write_sync(0x9fffaa34, 0x00000000);
	radeon_write_sync(0x9fffaa38, 0x00000000);
	radeon_write_sync(0x9fffaa3c, 0x00000000);
	radeon_write_sync(0x9fffaa40, 0x00000000);
	radeon_write_sync(0x9fffaa44, 0x00000000);
	radeon_write_sync(0x9fffaa48, 0x00000000);
	radeon_write_sync(0x9fffaa4c, 0x00000000);
	radeon_write_sync(0x9fffaa50, 0x00000000);
	radeon_write_sync(0x9fffaa54, 0x00000000);
	radeon_write_sync(0x9fffaa58, 0x00000000);
	radeon_write_sync(0x9fffaa5c, 0x00000000);
	radeon_write_sync(0x9fffaa60, 0x00000000);
	radeon_write_sync(0x9fffaa64, 0x00000000);
	radeon_write_sync(0x9fffaa68, 0x00000000);
	radeon_write_sync(0x9fffaa6c, 0x00000000);
	radeon_write_sync(0x9fffaa70, 0x00000000);
	radeon_write_sync(0x9fffaa74, 0x00000000);
	radeon_write_sync(0x9fffaa78, 0x00000000);
	radeon_write_sync(0x9fffaa7c, 0x00000000);
	radeon_write_sync(0x9fffaa80, 0x00000000);
	radeon_write_sync(0x9fffaa84, 0x00000000);
	radeon_write_sync(0x9fffaa88, 0x00000000);
	radeon_write_sync(0x9fffaa8c, 0x00000000);
	radeon_write_sync(0x9fffaa90, 0x00000000);
	radeon_write_sync(0x9fffaa94, 0x00000000);
	radeon_write_sync(0x9fffaa98, 0x00000000);
	radeon_write_sync(0x9fffaa9c, 0x00000000);
	radeon_write_sync(0x9fffaaa0, 0x00000000);
	radeon_write_sync(0x9fffaaa4, 0x00000000);
	radeon_write_sync(0x9fffaaa8, 0x00000000);
	radeon_write_sync(0x9fffaaac, 0x00000000);
	radeon_write_sync(0x9fffaab0, 0x00000000);
	radeon_write_sync(0x9fffaab4, 0x00000000);
	radeon_write_sync(0x9fffaab8, 0x00000000);
	radeon_write_sync(0x9fffaabc, 0x00000000);
	radeon_write_sync(0x9fffaac0, 0x00000000);
	radeon_write_sync(0x9fffaac4, 0x00000000);
	radeon_write_sync(0x9fffaac8, 0x00000000);
	radeon_write_sync(0x9fffaacc, 0x00000000);
	radeon_write_sync(0x9fffaad0, 0x00000000);
	radeon_write_sync(0x9fffaad4, 0x00000000);
	radeon_write_sync(0x9fffaad8, 0x00000000);
	radeon_write_sync(0x9fffaadc, 0x00000000);
	radeon_write_sync(0x9fffaae0, 0x00000000);
	radeon_write_sync(0x9fffaae4, 0x00000000);
	radeon_write_sync(0x9fffaae8, 0x00000000);
	radeon_write_sync(0x9fffaaec, 0x00000000);
	radeon_write_sync(0x9fffaaf0, 0x00000000);
	radeon_write_sync(0x9fffaaf4, 0x00000000);
	radeon_write_sync(0x9fffaaf8, 0x00000000);
	radeon_write_sync(0x9fffaafc, 0x00000000);
	radeon_write_sync(0x9fffab00, 0x00000000);
	radeon_write_sync(0x9fffab04, 0x00000000);
	radeon_write_sync(0x9fffab08, 0x00000000);
	radeon_write_sync(0x9fffab0c, 0x00000000);
	radeon_write_sync(0x9fffab10, 0x00000000);
	radeon_write_sync(0x9fffab14, 0x00000000);
	radeon_write_sync(0x9fffab18, 0x00000000);
	radeon_write_sync(0x9fffab1c, 0x00000000);
	radeon_write_sync(0x9fffab20, 0x00000000);
	radeon_write_sync(0x9fffab24, 0x00000000);
	radeon_write_sync(0x9fffab28, 0x00000000);
	radeon_write_sync(0x9fffab2c, 0x00000000);
	radeon_write_sync(0x9fffab30, 0x00000000);
	radeon_write_sync(0x9fffab34, 0x00000000);
	radeon_write_sync(0x9fffab38, 0x00000000);
	radeon_write_sync(0x9fffab3c, 0x00000000);
	radeon_write_sync(0x9fffab40, 0x00000000);
	radeon_write_sync(0x9fffab44, 0x00000000);
	radeon_write_sync(0x9fffab48, 0x00000000);
	radeon_write_sync(0x9fffab4c, 0x00000000);
	radeon_write_sync(0x9fffab50, 0x00000000);
	radeon_write_sync(0x9fffab54, 0x00000000);
	radeon_write_sync(0x9fffab58, 0x00000000);
	radeon_write_sync(0x9fffab5c, 0x00000000);
	radeon_write_sync(0x9fffab60, 0x00000000);
	radeon_write_sync(0x9fffab64, 0x00000000);
	radeon_write_sync(0x9fffab68, 0x00000000);
	radeon_write_sync(0x9fffab6c, 0x00000000);
	radeon_write_sync(0x9fffab70, 0x00000000);
	radeon_write_sync(0x9fffab74, 0x00000000);
	radeon_write_sync(0x9fffab78, 0x00000000);
	radeon_write_sync(0x9fffab7c, 0x00000000);
	radeon_write_sync(0x9fffab80, 0x00000000);
	radeon_write_sync(0x9fffab84, 0x00000000);
	radeon_write_sync(0x9fffab88, 0x00000000);
	radeon_write_sync(0x9fffab8c, 0x00000000);
	radeon_write_sync(0x9fffab90, 0x00000000);
	radeon_write_sync(0x9fffab94, 0x00000000);
	radeon_write_sync(0x9fffab98, 0x00000000);
	radeon_write_sync(0x9fffab9c, 0x00000000);
	radeon_write_sync(0x9fffaba0, 0x00000000);
	radeon_write_sync(0x9fffaba4, 0x00000000);
	radeon_write_sync(0x9fffaba8, 0x00000000);
	radeon_write_sync(0x9fffabac, 0x00000000);
	radeon_write_sync(0x9fffabb0, 0x00000000);
	radeon_write_sync(0x9fffabb4, 0x00000000);
	radeon_write_sync(0x9fffabb8, 0x00000000);
	radeon_write_sync(0x9fffabbc, 0x00000000);
	radeon_write_sync(0x9fffabc0, 0x00000000);
	radeon_write_sync(0x9fffabc4, 0x00000000);
	radeon_write_sync(0x9fffabc8, 0x00000000);
	radeon_write_sync(0x9fffabcc, 0x00000000);
	radeon_write_sync(0x9fffabd0, 0x00000000);
	radeon_write_sync(0x9fffabd4, 0x00000000);
	radeon_write_sync(0x9fffabd8, 0x00000000);
	radeon_write_sync(0x9fffabdc, 0x00000000);
	radeon_write_sync(0x9fffabe0, 0x00000000);
	radeon_write_sync(0x9fffabe4, 0x00000000);
	radeon_write_sync(0x9fffabe8, 0x00000000);
	radeon_write_sync(0x9fffa808, 0x00000008);
	radeon_write_sync(0x9fffa814, 0x0000211e);
	radeon_write_sync(0x9fffa80c, 0x0000310c);
	radeon_write_sync(0x9fffa810, 0x00000392);
	radeon_write_sync(0x9fffa000, 0x00000000);
	radeon_write_sync(0x9fffa004, 0x00000000);
	radeon_write_sync(0x9fffa008, 0x00000000);
	radeon_write_sync(0x9fffa00c, 0x00000000);
	radeon_write_sync(0x9fffa010, 0x00000000);
	radeon_write_sync(0x9fffa014, 0x00000000);
	radeon_write_sync(0x9fffa018, 0x00000000);
	radeon_write_sync(0x9fffa01c, 0x00000000);
	radeon_write_sync(0x9fffa020, 0x00000000);
	radeon_write_sync(0x9fffa024, 0x00000000);
	radeon_write_sync(0x9fffa028, 0x00000000);
	radeon_write_sync(0x9fffa02c, 0x00000000);
	radeon_write_sync(0x9fffa030, 0x00000000);
	radeon_write_sync(0x9fffa034, 0x00000000);
	radeon_write_sync(0x9fffa038, 0x00000000);
	radeon_write_sync(0x9fffa03c, 0x00000000);
	radeon_write_sync(0x9fffa040, 0x00000000);
	radeon_write_sync(0x9fffa044, 0x00000000);
	radeon_write_sync(0x9fffa048, 0x00000000);
	radeon_write_sync(0x9fffa04c, 0x00000000);
	radeon_write_sync(0x9fffa050, 0x00000000);
	radeon_write_sync(0x9fffa054, 0x00000000);
	radeon_write_sync(0x9fffa058, 0x00000000);
	radeon_write_sync(0x9fffa05c, 0x00000000);
	radeon_write_sync(0x9fffa060, 0x00000000);
	radeon_write_sync(0x9fffa064, 0x00000000);
	radeon_write_sync(0x9fffa068, 0x00000000);
	radeon_write_sync(0x9fffa06c, 0x00000000);
	radeon_write_sync(0x9fffa070, 0x00000000);
	radeon_write_sync(0x9fffa074, 0x00000000);
	radeon_write_sync(0x9fffa078, 0x00000000);
	radeon_write_sync(0x9fffa07c, 0x00000000);
	radeon_write_sync(0x9fffa080, 0x00000000);
	radeon_write_sync(0x9fffa084, 0x00000000);
	radeon_write_sync(0x9fffa088, 0x00000000);
	radeon_write_sync(0x9fffa08c, 0x00000000);
	radeon_write_sync(0x9fffa090, 0x00000000);
	radeon_write_sync(0x9fffa094, 0x00000000);
	radeon_write_sync(0x9fffa098, 0x00000000);
	radeon_write_sync(0x9fffa09c, 0x00000000);
	radeon_write_sync(0x9fffa0a0, 0x00000000);
	radeon_write_sync(0x9fffa0a4, 0x00000000);
	radeon_write_sync(0x9fffa0a8, 0x00000000);
	radeon_write_sync(0x9fffa0ac, 0x00000000);
	radeon_write_sync(0x9fffa0b0, 0x00000000);
	radeon_write_sync(0x9fffa0b4, 0x00000000);
	radeon_write_sync(0x9fffa0b8, 0x00000000);
	radeon_write_sync(0x9fffa0bc, 0x00000000);
	radeon_write_sync(0x9fffa0c0, 0x00000000);
	radeon_write_sync(0x9fffa0c4, 0x00000000);
	radeon_write_sync(0x9fffa0c8, 0x00000000);
	radeon_write_sync(0x9fffa0cc, 0x00000000);
	radeon_write_sync(0x9fffa0d0, 0x00000000);
	radeon_write_sync(0x9fffa0d4, 0x00000000);
	radeon_write_sync(0x9fffa0d8, 0x00000000);
	radeon_write_sync(0x9fffa0dc, 0x00000000);
	radeon_write_sync(0x9fffa0e0, 0x00000000);
	radeon_write_sync(0x9fffa0e4, 0x00000000);
	radeon_write_sync(0x9fffa0e8, 0x00000000);
	radeon_write_sync(0x9fffa0ec, 0x00000000);
	radeon_write_sync(0x9fffa0f0, 0x00000000);
	radeon_write_sync(0x9fffa0f4, 0x00000000);
	radeon_write_sync(0x9fffa0f8, 0x00000000);
	radeon_write_sync(0x9fffa0fc, 0x00000000);
	radeon_write_sync(0x9fffa100, 0x00000000);
	radeon_write_sync(0x9fffa104, 0x00000000);
	radeon_write_sync(0x9fffa108, 0x00000000);
	radeon_write_sync(0x9fffa10c, 0x00000000);
	radeon_write_sync(0x9fffa110, 0x00000000);
	radeon_write_sync(0x9fffa114, 0x00000000);
	radeon_write_sync(0x9fffa118, 0x00000000);
	radeon_write_sync(0x9fffa11c, 0x00000000);
	radeon_write_sync(0x9fffa120, 0x00000000);
	radeon_write_sync(0x9fffa124, 0x00000000);
	radeon_write_sync(0x9fffa128, 0x00000000);
	radeon_write_sync(0x9fffa12c, 0x00000000);
	radeon_write_sync(0x9fffa130, 0x00000000);
	radeon_write_sync(0x9fffa134, 0x00000000);
	radeon_write_sync(0x9fffa138, 0x00000000);
	radeon_write_sync(0x9fffa13c, 0x00000000);
	radeon_write_sync(0x9fffa140, 0x00000000);
	radeon_write_sync(0x9fffa144, 0x00000000);
	radeon_write_sync(0x9fffa148, 0x00000000);
	radeon_write_sync(0x9fffa14c, 0x00000000);
	radeon_write_sync(0x9fffa150, 0x00000000);
	radeon_write_sync(0x9fffa154, 0x00000000);
	radeon_write_sync(0x9fffa158, 0x00000000);
	radeon_write_sync(0x9fffa15c, 0x00000000);
	radeon_write_sync(0x9fffa160, 0x00000000);
	radeon_write_sync(0x9fffa164, 0x00000000);
	radeon_write_sync(0x9fffa168, 0x00000000);
	radeon_write_sync(0x9fffa16c, 0x00000000);
	radeon_write_sync(0x9fffa170, 0x00000000);
	radeon_write_sync(0x9fffa174, 0x00000000);
	radeon_write_sync(0x9fffa178, 0x00000000);
	radeon_write_sync(0x9fffa17c, 0x00000000);
	radeon_write_sync(0x9fffa180, 0x00000000);
	radeon_write_sync(0x9fffa184, 0x00000000);
	radeon_write_sync(0x9fffa188, 0x00000000);
	radeon_write_sync(0x9fffa18c, 0x00000000);
	radeon_write_sync(0x9fffa190, 0x00000000);
	radeon_write_sync(0x9fffa194, 0x00000000);
	radeon_write_sync(0x9fffa198, 0x00000000);
	radeon_write_sync(0x9fffa19c, 0x00000000);
	radeon_write_sync(0x9fffa1a0, 0x00000000);
	radeon_write_sync(0x9fffa1a4, 0x00000000);
	radeon_write_sync(0x9fffa1a8, 0x00000000);
	radeon_write_sync(0x9fffa1ac, 0x00000000);
	radeon_write_sync(0x9fffa1b0, 0x00000000);
	radeon_write_sync(0x9fffa1b4, 0x00000000);
	radeon_write_sync(0x9fffa1b8, 0x00000000);
	radeon_write_sync(0x9fffa1bc, 0x00000000);
	radeon_write_sync(0x9fffa1c0, 0x00000000);
	radeon_write_sync(0x9fffa1c4, 0x00000000);
	radeon_write_sync(0x9fffa1c8, 0x00000000);
	radeon_write_sync(0x9fffa1cc, 0x00000000);
	radeon_write_sync(0x9fffa1d0, 0x00000000);
	radeon_write_sync(0x9fffa1d4, 0x00000000);
	radeon_write_sync(0x9fffa1d8, 0x00000000);
	radeon_write_sync(0x9fffa1dc, 0x00000000);
	radeon_write_sync(0x9fffa1e0, 0x00000000);
	radeon_write_sync(0x9fffa1e4, 0x00000000);
	radeon_write_sync(0x9fffa1e8, 0x00000000);
	radeon_write_sync(0x9fffa1ec, 0x00000000);
	radeon_write_sync(0x9fffa1f0, 0x00000000);
	radeon_write_sync(0x9fffa1f4, 0x00000000);
	radeon_write_sync(0x9fffa1f8, 0x00000000);
	radeon_write_sync(0x9fffa1fc, 0x00000000);
	radeon_write_sync(0x9fffa200, 0x00000000);
	radeon_write_sync(0x9fffa204, 0x00000000);
	radeon_write_sync(0x9fffa208, 0x00000000);
	radeon_write_sync(0x9fffa20c, 0x00000000);
	radeon_write_sync(0x9fffa210, 0x00000000);
	radeon_write_sync(0x9fffa214, 0x00000000);
	radeon_write_sync(0x9fffa218, 0x00000000);
	radeon_write_sync(0x9fffa21c, 0x00000000);
	radeon_write_sync(0x9fffa220, 0x00000000);
	radeon_write_sync(0x9fffa224, 0x00000000);
	radeon_write_sync(0x9fffa228, 0x00000000);
	radeon_write_sync(0x9fffa22c, 0x00000000);
	radeon_write_sync(0x9fffa230, 0x00000000);
	radeon_write_sync(0x9fffa234, 0x00000000);
	radeon_write_sync(0x9fffa238, 0x00000000);
	radeon_write_sync(0x9fffa23c, 0x00000000);
	radeon_write_sync(0x9fffa240, 0x00000000);
	radeon_write_sync(0x9fffa244, 0x00000000);
	radeon_write_sync(0x9fffa248, 0x00000000);
	radeon_write_sync(0x9fffa24c, 0x00000000);
	radeon_write_sync(0x9fffa250, 0x00000000);
	radeon_write_sync(0x9fffa254, 0x00000000);
	radeon_write_sync(0x9fffa258, 0x00000000);
	radeon_write_sync(0x9fffa25c, 0x00000000);
	radeon_write_sync(0x9fffa260, 0x00000000);
	radeon_write_sync(0x9fffa264, 0x00000000);
	radeon_write_sync(0x9fffa268, 0x00000000);
	radeon_write_sync(0x9fffa26c, 0x00000000);
	radeon_write_sync(0x9fffa270, 0x00000000);
	radeon_write_sync(0x9fffa274, 0x00000000);
	radeon_write_sync(0x9fffa278, 0x00000000);
	radeon_write_sync(0x9fffa27c, 0x00000000);
	radeon_write_sync(0x9fffa280, 0x00000000);
	radeon_write_sync(0x9fffa284, 0x00000000);
	radeon_write_sync(0x9fffa288, 0x00000000);
	radeon_write_sync(0x9fffa28c, 0x00000000);
	radeon_write_sync(0x9fffa290, 0x00000000);
	radeon_write_sync(0x9fffa294, 0x00000000);
	radeon_write_sync(0x9fffa298, 0x00000000);
	radeon_write_sync(0x9fffa29c, 0x00000000);
	radeon_write_sync(0x9fffa2a0, 0x00000000);
	radeon_write_sync(0x9fffa2a4, 0x00000000);
	radeon_write_sync(0x9fffa2a8, 0x00000000);
	radeon_write_sync(0x9fffa2ac, 0x00000000);
	radeon_write_sync(0x9fffa2b0, 0x00000000);
	radeon_write_sync(0x9fffa2b4, 0x00000000);
	radeon_write_sync(0x9fffa2b8, 0x00000000);
	radeon_write_sync(0x9fffa2bc, 0x00000000);
	radeon_write_sync(0x9fffa2c0, 0x00000000);
	radeon_write_sync(0x9fffa2c4, 0x00000000);
	radeon_write_sync(0x9fffa2c8, 0x00000000);
	radeon_write_sync(0x9fffa2cc, 0x00000000);
	radeon_write_sync(0x9fffa2d0, 0x00000000);
	radeon_write_sync(0x9fffa2d4, 0x00000000);
	radeon_write_sync(0x9fffa2d8, 0x00000000);
	radeon_write_sync(0x9fffa2dc, 0x00000000);
	radeon_write_sync(0x9fffa2e0, 0x00000000);
	radeon_write_sync(0x9fffa2e4, 0x00000000);
	radeon_write_sync(0x9fffa2e8, 0x00000000);
	radeon_write_sync(0x9fffa2ec, 0x00000000);
	radeon_write_sync(0x9fffa2f0, 0x00000000);
	radeon_write_sync(0x9fffa2f4, 0x00000000);
	radeon_write_sync(0x9fffa2f8, 0x00000000);
	radeon_write_sync(0x9fffa2fc, 0x00000000);
	radeon_write_sync(0x9fffa300, 0x00000000);
	radeon_write_sync(0x9fffa304, 0x00000000);
	radeon_write_sync(0x9fffa308, 0x00000000);
	radeon_write_sync(0x9fffa30c, 0x00000000);
	radeon_write_sync(0x9fffa310, 0x00000000);
	radeon_write_sync(0x9fffa314, 0x00000000);
	radeon_write_sync(0x9fffa318, 0x00000000);
	radeon_write_sync(0x9fffa31c, 0x00000000);
	radeon_write_sync(0x9fffa320, 0x00000000);
	radeon_write_sync(0x9fffa324, 0x00000000);
	radeon_write_sync(0x9fffa328, 0x00000000);
	radeon_write_sync(0x9fffa32c, 0x00000000);
	radeon_write_sync(0x9fffa330, 0x00000000);
	radeon_write_sync(0x9fffa334, 0x00000000);
	radeon_write_sync(0x9fffa338, 0x00000000);
	radeon_write_sync(0x9fffa33c, 0x00000000);
	radeon_write_sync(0x9fffa340, 0x00000000);
	radeon_write_sync(0x9fffa344, 0x00000000);
	radeon_write_sync(0x9fffa348, 0x00000000);
	radeon_write_sync(0x9fffa34c, 0x00000000);
	radeon_write_sync(0x9fffa350, 0x00000000);
	radeon_write_sync(0x9fffa354, 0x00000000);
	radeon_write_sync(0x9fffa358, 0x00000000);
	radeon_write_sync(0x9fffa35c, 0x00000000);
	radeon_write_sync(0x9fffa360, 0x00000000);
	radeon_write_sync(0x9fffa364, 0x00000000);
	radeon_write_sync(0x9fffa368, 0x00000000);
	radeon_write_sync(0x9fffa36c, 0x00000000);
	radeon_write_sync(0x9fffa370, 0x00000000);
	radeon_write_sync(0x9fffa374, 0x00000000);
	radeon_write_sync(0x9fffa378, 0x00000000);
	radeon_write_sync(0x9fffa37c, 0x00000000);
	radeon_write_sync(0x9fffa380, 0x00000000);
	radeon_write_sync(0x9fffa384, 0x00000000);
	radeon_write_sync(0x9fffa388, 0x00000000);
	radeon_write_sync(0x9fffa38c, 0x00000000);
	radeon_write_sync(0x9fffa390, 0x00000000);
	radeon_write_sync(0x9fffa394, 0x00000000);
	radeon_write_sync(0x9fffa398, 0x00000000);
	radeon_write_sync(0x9fffa39c, 0x00000000);
	radeon_write_sync(0x9fffa3a0, 0x00000000);
	radeon_write_sync(0x9fffa3a4, 0x00000000);
	radeon_write_sync(0x9fffa3a8, 0x00000000);
	radeon_write_sync(0x9fffa3ac, 0x00000000);
	radeon_write_sync(0x9fffa3b0, 0x00000000);
	radeon_write_sync(0x9fffa3b4, 0x00000000);
	radeon_write_sync(0x9fffa3b8, 0x00000000);
	radeon_write_sync(0x9fffa3bc, 0x00000000);
	radeon_write_sync(0x9fffa3c0, 0x00000000);
	radeon_write_sync(0x9fffa3c4, 0x00000000);
	radeon_write_sync(0x9fffa3c8, 0x00000000);
	radeon_write_sync(0x9fffa3cc, 0x00000000);
	radeon_write_sync(0x9fffa3d0, 0x00000000);
	radeon_write_sync(0x9fffa3d4, 0x00000000);
	radeon_write_sync(0x9fffa3d8, 0x00000000);
	radeon_write_sync(0x9fffa3dc, 0x00000000);
	radeon_write_sync(0x9fffa3e0, 0x00000000);
	radeon_write_sync(0x9fffa3e4, 0x00000000);
	radeon_write_sync(0x9fffa3e8, 0x00000000);
	radeon_write_sync(0x9fffa008, 0x00000001);
	radeon_write_sync(0x9fffa014, 0x21222221);
	radeon_write_sync(0x9fffa00c, 0x00003105);
	radeon_write_sync(0x9fffa010, 0x00000291);
	radeon_write_sync(0x9fff9e00, 0x00000000);
	radeon_write_sync(0x9fff9e04, 0x00000000);
	radeon_write_sync(0x9fff9e08, 0x00000000);
	radeon_write_sync(0x9fff9e0c, 0x00000000);
	radeon_write_sync(0x9fff9e10, 0x00000000);
	radeon_write_sync(0x9fff9e14, 0x00000000);
	radeon_write_sync(0x9fff9e18, 0x00000000);
	radeon_write_sync(0x9fff9e1c, 0x00000000);
	radeon_write_sync(0x9fff9e20, 0x00000000);
	radeon_write_sync(0x9fff9e24, 0x00000000);
	radeon_write_sync(0x9fff9e28, 0x00000000);
	radeon_write_sync(0x9fff9e2c, 0x00000000);
	radeon_write_sync(0x9fff9e30, 0x00000000);
	radeon_write_sync(0x9fff9e34, 0x00000000);
	radeon_write_sync(0x9fff9e38, 0x00000000);
	radeon_write_sync(0x9fff9e3c, 0x00000000);
	radeon_write_sync(0x9fff9e40, 0x00000000);
	radeon_write_sync(0x9fff9e44, 0x00000000);
	radeon_write_sync(0x9fff9e48, 0x00000000);
	radeon_write_sync(0x9fff9e4c, 0x00000000);
	radeon_write_sync(0x9fff9e50, 0x00000000);
	radeon_write_sync(0x9fff9e54, 0x00000000);
	radeon_write_sync(0x9fff9e58, 0x00000000);
	radeon_write_sync(0x9fff9e5c, 0x00000000);
	radeon_write_sync(0x9fff9e60, 0x00000000);
	radeon_write_sync(0x9fff9e64, 0x00000000);
	radeon_write_sync(0x9fff9e68, 0x00000000);
	radeon_write_sync(0x9fff9e6c, 0x00000000);
	radeon_write_sync(0x9fff9e70, 0x00000000);
	radeon_write_sync(0x9fff9e74, 0x00000000);
	radeon_write_sync(0x9fff9e78, 0x00000000);
	radeon_write_sync(0x9fff9e7c, 0x00000000);
	radeon_write_sync(0x9fff9e80, 0x00000000);
	radeon_write_sync(0x9fff9e84, 0x00000000);
	radeon_write_sync(0x9fff9e88, 0x00000000);
	radeon_write_sync(0x9fff9e8c, 0x00000000);
	radeon_write_sync(0x9fff9e90, 0x00000000);
	radeon_write_sync(0x9fff9e94, 0x00000000);
	radeon_write_sync(0x9fff9e98, 0x00000000);
	radeon_write_sync(0x9fff9e9c, 0x00000000);
	radeon_write_sync(0x9fff9ea0, 0x00000000);
	radeon_write_sync(0x9fff9ea4, 0x00000000);
	radeon_write_sync(0x9fff9ea8, 0x00000000);
	radeon_write_sync(0x9fff9eac, 0x00000000);
	radeon_write_sync(0x9fff9eb0, 0x00000000);
	radeon_write_sync(0x9fff9eb4, 0x00000000);
	radeon_write_sync(0x9fff9eb8, 0x00000000);
	radeon_write_sync(0x9fff9ebc, 0x00000000);
	radeon_write_sync(0x9fff9ec0, 0x00000000);
	radeon_write_sync(0x9fff9ec4, 0x00000000);
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_write_sync(0x1738, 0x00000000);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_write_sync(0x1724, 0x00000000);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x9fffa74c); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa73c); /* 00000000 */
	radeon_read_sync(0x646c); /* 00010000 */
	radeon_write_sync(0x646c, 0x00010f9f);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x6020); /* 00000000 */
	radeon_write_sync(0x6020, 0x00010000);
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010001);
	radeon_read_sync(0x9fffa548); /* 00000000 */
	radeon_write_sync(0x9fffa428, 0x00000000);
	radeon_write_sync(0x9fffa42c, 0x00000000);
	radeon_write_sync(0x9fffa430, 0x00000000);
	radeon_write_sync(0x9fffa434, 0x00000000);
	radeon_write_sync(0x9fffa438, 0x00000000);
	radeon_write_sync(0x9fffa43c, 0x00000000);
	radeon_write_sync(0x9fffa440, 0x00000000);
	radeon_write_sync(0x9fffa444, 0x00000000);
	radeon_write_sync(0x9fffa448, 0x00000000);
	radeon_write_sync(0x9fffa44c, 0x00000000);
	radeon_write_sync(0x9fffa450, 0x00000000);
	radeon_write_sync(0x9fffa454, 0x00000000);
	radeon_write_sync(0x9fffa458, 0x00000000);
	radeon_write_sync(0x9fffa45c, 0x00000000);
	radeon_write_sync(0x9fffa460, 0x00000000);
	radeon_write_sync(0x9fffa464, 0x00000000);
	radeon_write_sync(0x9fffa468, 0x00000000);
	radeon_write_sync(0x9fffa46c, 0x00000000);
	radeon_write_sync(0x9fffa470, 0x00000000);
	radeon_write_sync(0x9fffa474, 0x00000000);
	radeon_write_sync(0x9fffa478, 0x00000000);
	radeon_write_sync(0x9fffa47c, 0x00000000);
	radeon_write_sync(0x9fffa480, 0x00000000);
	radeon_write_sync(0x9fffa484, 0x00000000);
	radeon_write_sync(0x9fffa488, 0x00000000);
	radeon_write_sync(0x9fffa48c, 0x00000000);
	radeon_write_sync(0x9fffa490, 0x00000000);
	radeon_write_sync(0x9fffa494, 0x00000000);
	radeon_write_sync(0x9fffa498, 0x00000000);
	radeon_write_sync(0x9fffa49c, 0x00000000);
	radeon_write_sync(0x9fffa4a0, 0x00000000);
	radeon_write_sync(0x9fffa4a4, 0x00000000);
	radeon_write_sync(0x9fffa4a8, 0x00000000);
	radeon_write_sync(0x9fffa4ac, 0x00000000);
	radeon_write_sync(0x9fffa4b0, 0x00000000);
	radeon_write_sync(0x9fffa4b4, 0x00000000);
	radeon_write_sync(0x9fffa4b8, 0x00000000);
	radeon_write_sync(0x9fffa4bc, 0x00000000);
	radeon_write_sync(0x9fffa4c0, 0x00000000);
	radeon_write_sync(0x9fffa4c4, 0x00000000);
	radeon_write_sync(0x9fffa4c8, 0x00000000);
	radeon_write_sync(0x9fffa4cc, 0x00000000);
	radeon_write_sync(0x9fffa4d0, 0x00000000);
	radeon_write_sync(0x9fffa4d4, 0x00000000);
	radeon_write_sync(0x9fffa4d8, 0x00000000);
	radeon_write_sync(0x9fffa4dc, 0x00000000);
	radeon_write_sync(0x9fffa4e0, 0x00000000);
	radeon_write_sync(0x9fffa4e4, 0x00000000);
	radeon_write_sync(0x9fffa4e8, 0x00000000);
	radeon_write_sync(0x9fffa4ec, 0x00000000);
	radeon_write_sync(0x9fffa4f0, 0x00000000);
	radeon_write_sync(0x9fffa4f4, 0x00000000);
	radeon_write_sync(0x9fffa4f8, 0x00000000);
	radeon_write_sync(0x9fffa4fc, 0x00000000);
	radeon_write_sync(0x9fffa500, 0x00000000);
	radeon_write_sync(0x9fffa504, 0x00000000);
	radeon_write_sync(0x9fffa508, 0x00000000);
	radeon_write_sync(0x9fffa50c, 0x00000000);
	radeon_write_sync(0x9fffa510, 0x00000000);
	radeon_write_sync(0x9fffa514, 0x00000000);
	radeon_write_sync(0x9fffa518, 0x00000000);
	radeon_write_sync(0x9fffa51c, 0x00000000);
	radeon_write_sync(0x9fffa520, 0x00000000);
	radeon_write_sync(0x9fffa524, 0x00000000);
	radeon_write_sync(0x9fffa528, 0x00000000);
	radeon_write_sync(0x9fffa52c, 0x00000000);
	radeon_write_sync(0x9fffa530, 0x00000000);
	radeon_write_sync(0x9fffa534, 0x00000000);
	radeon_write_sync(0x9fffa538, 0x00000000);
	radeon_write_sync(0x9fffa53c, 0x00000000);
	radeon_write_sync(0x9fffa540, 0x00000000);
	radeon_write_sync(0x9fffa544, 0x00000000);
	radeon_write_sync(0x9fffa548, 0x00000000);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010000);
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x601c); /* 00000012 */
	radeon_read_sync(0x6020); /* 00010000 */
	radeon_write_sync(0x6020, 0x00010001);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00010001);
	radeon_write_sync(0x9fffbe00, 0x47900000);
	radeon_read_sync(0x6530); /* 0f400000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040000 */
	radeon_write_sync(0x6200, 0x21040000);
	radeon_read_sync(0x6200); /* 21040000 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 47900000 */
	radeon_read_sync(0x6204); /* 00000000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 47900000 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 47900000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 47900000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 47900000 */
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
	radeon_write_sync(0x9fffa528, 0x41810a11);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00070101 */
	radeon_read_sync(0x6218); /* 00088001 */
	radeon_write_sync(0x9fffa52c, 0x80010000);
	radeon_write_sync(0x9fffbe04, 0x80010000);
	radeon_write_sync(0x9fffbe00, 0x4390000c);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4390000c */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4390000c */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 4390000c */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4390000c */
	radeon_write_sync(0x6218, 0x00000c00);
	radeon_read_sync(0x9fffbe00); /* 4390000c */
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
	radeon_write_sync(0x9fffa530, 0x00000108);
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x41900020);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 41900020 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 41900020 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 41900020 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 41900020 */
	radeon_write_sync(0x6218, 0x00002000);
	radeon_read_sync(0x9fffbe00); /* 41900020 */
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
	radeon_write_sync(0x9fffa534, 0x00000000);
	radeon_read_sync(0x9fffa534); /* 00000000 */
	radeon_read_sync(0x9fffa538); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa754); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c3000000 */
	radeon_delay(0x0026996c - 0x00269740);
	radeon_read_sync(0x6210); /* c3000000 */
	radeon_delay(0x0026c168 - 0x0026bf48);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00290028 - 0x0028fe00);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x0029dd6a - 0x00298ef8);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x002b8be2 - 0x002b89c0);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010001 */
	radeon_read_sync(0x6218); /* 0002ff01 */
	radeon_read_sync(0x6218); /* 0003ff01 */
	radeon_read_sync(0x6218); /* 0004ff01 */
	radeon_write_sync(0x9fffa428, 0xffffff00);
	radeon_read_sync(0x6218); /* 0005ff01 */
	radeon_read_sync(0x6218); /* 0006ff01 */
	radeon_read_sync(0x6218); /* 0007ff01 */
	radeon_read_sync(0x6218); /* 00080001 */
	radeon_write_sync(0x9fffa42c, 0x00ffffff);
	radeon_read_sync(0x6218); /* 00090601 */
	radeon_read_sync(0x6218); /* 000aaf01 */
	radeon_read_sync(0x6218); /* 000bec01 */
	radeon_read_sync(0x6218); /* 000c3201 */
	radeon_write_sync(0x9fffa430, 0x32ecaf06);
	radeon_read_sync(0x6218); /* 000d0001 */
	radeon_read_sync(0x6218); /* 000e0001 */
	radeon_read_sync(0x6218); /* 000f0001 */
	radeon_read_sync(0x6218); /* 00100001 */
	radeon_write_sync(0x9fffa434, 0x00000000);
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa428); /* ffffff00 */
	radeon_write_sync(0x9fffbe04, 0xffffff10);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* ffffff10 */
	radeon_write_sync(0x6218, 0x00001000);
	radeon_read_sync(0x9fffbe04); /* ffffff10 */
	radeon_write_sync(0x6218, 0x0000ff00);
	radeon_read_sync(0x9fffbe04); /* ffffff10 */
	radeon_write_sync(0x6218, 0x0000ff00);
	radeon_read_sync(0x9fffbe04); /* ffffff10 */
	radeon_write_sync(0x6218, 0x0000ff00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0031a786 - 0x0031a566);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0031cf8c - 0x0031cd6c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00340e7e - 0x00340c5c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x0034ebda - 0x00349d82);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00369ad4 - 0x003698b4);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010001 */
	radeon_read_sync(0x6218); /* 00021501 */
	radeon_read_sync(0x6218); /* 00030101 */
	radeon_read_sync(0x6218); /* 00040401 */
	radeon_write_sync(0x9fffa438, 0x04011500);
	radeon_read_sync(0x6218); /* 00059001 */
	radeon_read_sync(0x6218); /* 00062201 */
	radeon_read_sync(0x6218); /* 00071301 */
	radeon_read_sync(0x6218); /* 00087801 */
	radeon_write_sync(0x9fffa43c, 0x78132290);
	radeon_read_sync(0x6218); /* 00090201 */
	radeon_read_sync(0x6218); /* 000abb01 */
	radeon_read_sync(0x6218); /* 000bf501 */
	radeon_read_sync(0x6218); /* 000c9401 */
	radeon_write_sync(0x9fffa440, 0x94f5bb02);
	radeon_read_sync(0x6218); /* 000d5501 */
	radeon_read_sync(0x6218); /* 000e5401 */
	radeon_read_sync(0x6218); /* 000f9001 */
	radeon_read_sync(0x6218); /* 00102701 */
	radeon_write_sync(0x9fffa444, 0x27905455);
	radeon_write_sync(0x9fffbe04, 0x27900000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000020);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000020 */
	radeon_write_sync(0x6218, 0x00002000);
	radeon_read_sync(0x9fffbe04); /* 00000020 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000020 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000020 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x003cb3c6 - 0x003cb1a0);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x003cdbc4 - 0x003cd9aa);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x003f1aca - 0x003f18a4);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x003ff81c - 0x003fa9c2);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0041a702 - 0x0041a4e2);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00012301 */
	radeon_read_sync(0x6218); /* 00025001 */
	radeon_read_sync(0x6218); /* 00035401 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_write_sync(0x9fffa448, 0x00545023);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00070101 */
	radeon_read_sync(0x6218); /* 00080101 */
	radeon_write_sync(0x9fffa44c, 0x01010000);
	radeon_read_sync(0x6218); /* 00090101 */
	radeon_read_sync(0x6218); /* 000a0101 */
	radeon_read_sync(0x6218); /* 000b0101 */
	radeon_read_sync(0x6218); /* 000c0101 */
	radeon_write_sync(0x9fffa450, 0x01010101);
	radeon_read_sync(0x6218); /* 000d0101 */
	radeon_read_sync(0x6218); /* 000e0101 */
	radeon_read_sync(0x6218); /* 000f0101 */
	radeon_read_sync(0x6218); /* 00100101 */
	radeon_write_sync(0x9fffa454, 0x01010101);
	radeon_write_sync(0x9fffbe04, 0x01010000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000030);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000030 */
	radeon_write_sync(0x6218, 0x00003000);
	radeon_read_sync(0x9fffbe04); /* 00000030 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000030 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000030 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0047c0ac - 0x0047be8a);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0047e8b0 - 0x0047e694);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x004a27ce - 0x004a25b2);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x004b054e - 0x004ab6b6);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x004cb44a - 0x004cb226);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010101 */
	radeon_read_sync(0x6218); /* 00020101 */
	radeon_read_sync(0x6218); /* 00030101 */
	radeon_read_sync(0x6218); /* 00040101 */
	radeon_write_sync(0x9fffa458, 0x01010101);
	radeon_read_sync(0x6218); /* 00050101 */
	radeon_read_sync(0x6218); /* 00060101 */
	radeon_read_sync(0x6218); /* 0007ce01 */
	radeon_read_sync(0x6218); /* 00081d01 */
	radeon_write_sync(0x9fffa45c, 0x1dce0101);
	radeon_read_sync(0x6218); /* 00095601 */
	radeon_read_sync(0x6218); /* 000ac001 */
	radeon_read_sync(0x6218); /* 000b5001 */
	radeon_read_sync(0x6218); /* 000c0001 */
	radeon_write_sync(0x9fffa460, 0x0050c056);
	radeon_read_sync(0x6218); /* 000d3001 */
	radeon_read_sync(0x6218); /* 000e3001 */
	radeon_read_sync(0x6218); /* 000f0801 */
	radeon_read_sync(0x6218); /* 00100a01 */
	radeon_write_sync(0x9fffa464, 0x0a083030);
	radeon_write_sync(0x9fffbe04, 0x0a080000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000040);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000040 */
	radeon_write_sync(0x6218, 0x00004000);
	radeon_read_sync(0x9fffbe04); /* 00000040 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000040 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000040 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0052cd46 - 0x0052cb1e);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0052f546 - 0x0052f32c);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0055346a - 0x00553246);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x0056119e - 0x0055c332);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0057c088 - 0x0057be66);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00013101 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00035801 */
	radeon_read_sync(0x6218); /* 0004c101 */
	radeon_write_sync(0x9fffa468, 0xc1580031);
	radeon_read_sync(0x6218); /* 00051001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00070001 */
	radeon_read_sync(0x6218); /* 00081801 */
	radeon_write_sync(0x9fffa46c, 0x18000010);
	radeon_read_sync(0x6218); /* 0009df01 */
	radeon_read_sync(0x6218); /* 000a1301 */
	radeon_read_sync(0x6218); /* 000b5601 */
	radeon_read_sync(0x6218); /* 000cc001 */
	radeon_write_sync(0x9fffa470, 0xc05613df);
	radeon_read_sync(0x6218); /* 000d5001 */
	radeon_read_sync(0x6218); /* 000e0001 */
	radeon_read_sync(0x6218); /* 000f3001 */
	radeon_read_sync(0x6218); /* 00103001 */
	radeon_write_sync(0x9fffa474, 0x30300050);
	radeon_write_sync(0x9fffbe04, 0x30300000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000050);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe04); /* 00000050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x005dda22 - 0x005dd7fc);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x005e0218 - 0x005dfffc);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x006040d0 - 0x00603ea6);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x00611dc2 - 0x0060cf96);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0062ccac - 0x0062ca8a);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010801 */
	radeon_read_sync(0x6218); /* 00020a01 */
	radeon_read_sync(0x6218); /* 00033101 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_write_sync(0x9fffa478, 0x00310a08);
	radeon_read_sync(0x6218); /* 00055801 */
	radeon_read_sync(0x6218); /* 0006c101 */
	radeon_read_sync(0x6218); /* 00071001 */
	radeon_read_sync(0x6218); /* 00080001 */
	radeon_write_sync(0x9fffa47c, 0x0010c158);
	radeon_read_sync(0x6218); /* 00090001 */
	radeon_read_sync(0x6218); /* 000a1801 */
	radeon_read_sync(0x6218); /* 000b0001 */
	radeon_read_sync(0x6218); /* 000c0001 */
	radeon_write_sync(0x9fffa480, 0x00001800);
	radeon_read_sync(0x6218); /* 000d0001 */
	radeon_read_sync(0x6218); /* 000e0001 */
	radeon_read_sync(0x6218); /* 000f0001 */
	radeon_read_sync(0x6218); /* 00100001 */
	radeon_write_sync(0x9fffa484, 0x00000000);
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000060);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000060 */
	radeon_write_sync(0x6218, 0x00006000);
	radeon_read_sync(0x9fffbe04); /* 00000060 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000060 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000060 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0068e5de - 0x0068e3be);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x00690de2 - 0x00690bbe);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x006b4cc4 - 0x006b4aa4);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x006c2a3e - 0x006bdbc0);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x006dd932 - 0x006dd712);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010001 */
	radeon_read_sync(0x6218); /* 00020001 */
	radeon_read_sync(0x6218); /* 00030001 */
	radeon_read_sync(0x6218); /* 00040001 */
	radeon_write_sync(0x9fffa488, 0x00000000);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00070001 */
	radeon_read_sync(0x6218); /* 00080001 */
	radeon_write_sync(0x9fffa48c, 0x00000000);
	radeon_read_sync(0x6218); /* 00090001 */
	radeon_read_sync(0x6218); /* 000a0001 */
	radeon_read_sync(0x6218); /* 000b0001 */
	radeon_read_sync(0x6218); /* 000c0001 */
	radeon_write_sync(0x9fffa490, 0x00000000);
	radeon_read_sync(0x6218); /* 000d0001 */
	radeon_read_sync(0x6218); /* 000e0001 */
	radeon_read_sync(0x6218); /* 000f0001 */
	radeon_read_sync(0x6218); /* 00100201 */
	radeon_write_sync(0x9fffa494, 0x02000000);
	radeon_write_sync(0x9fffbe04, 0x02000000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x9fffbe04, 0x00000070);
	radeon_write_sync(0x9fffbe00, 0x50400050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x80004000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 50400050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000070 */
	radeon_write_sync(0x6218, 0x00007000);
	radeon_read_sync(0x9fffbe04); /* 00000070 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000070 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000070 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0073f1ee - 0x0073efd0);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x007419ee - 0x007417cc);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffbe04, 0x08800100);
	radeon_write_sync(0x9fffbe00, 0x4f500050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x007658ae - 0x0076568e);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00002001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_delay(0x00773602 - 0x0076e782);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x80005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 4f500050 */
	radeon_write_sync(0x6218, 0x00000f00);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040001);
	radeon_read_sync(0x6210); /* c1000000 */
	radeon_delay(0x0078e4e6 - 0x0078e2c2);
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 11000001 */
	radeon_read_sync(0x6218); /* 00010001 */
	radeon_read_sync(0x6218); /* 00020c01 */
	radeon_read_sync(0x6218); /* 00033301 */
	radeon_read_sync(0x6218); /* 0004f901 */
	radeon_write_sync(0x9fffa498, 0xf9330c00);
	radeon_read_sync(0x6218); /* 00050a01 */
	radeon_read_sync(0x6218); /* 00063c01 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_write_sync(0x9fffa49c, 0x1f643c0a);
	radeon_read_sync(0x6218); /* 00091401 */
	radeon_read_sync(0x6218); /* 000a2201 */
	radeon_read_sync(0x6218); /* 000b6e01 */
	radeon_read_sync(0x6218); /* 000c2001 */
	radeon_write_sync(0x9fffa4a0, 0x206e2214);
	radeon_read_sync(0x6218); /* 000d2001 */
	radeon_read_sync(0x6218); /* 000e2001 */
	radeon_read_sync(0x6218); /* 000f0001 */
	radeon_read_sync(0x6218); /* 0010e701 */
	radeon_write_sync(0x9fffa4a4, 0xe7002020);
	radeon_write_sync(0x9fffbe04, 0xe7000000);
	radeon_write_sync(0x9fffbe00, 0x30100050);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21040101);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x80001000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00005000);
	radeon_read_sync(0x9fffbe00); /* 30100050 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x620c); /* 00000000 */
	radeon_write_sync(0x620c, 0x00000002);
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00030001);
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_write_sync(0x6218, 0x80000001);
	radeon_read_sync(0x6218); /* 00000001 */
	radeon_read_sync(0x6210); /* 01000001 */
	radeon_read_sync(0x9fffa528); /* 41810a11 */
	radeon_read_sync(0x9fffa428); /* ffffff00 */
	radeon_read_sync(0x9fffa42c); /* 00ffffff */
	radeon_read_sync(0x9fffa428); /* ffffff00 */
	radeon_read_sync(0x9fffa42c); /* 00ffffff */
	radeon_read_sync(0x9fffa438); /* 04011500 */
	radeon_read_sync(0x9fffa43c); /* 78132290 */
	radeon_read_sync(0x9fffa428); /* ffffff00 */
	radeon_read_sync(0x9fffa42c); /* 00ffffff */
	radeon_read_sync(0x9fffa430); /* 32ecaf06 */
	radeon_read_sync(0x9fffa434); /* 00000000 */
	radeon_read_sync(0x9fffa438); /* 04011500 */
	radeon_read_sync(0x9fffa43c); /* 78132290 */
	radeon_read_sync(0x9fffa440); /* 94f5bb02 */
	radeon_read_sync(0x9fffa444); /* 27905455 */
	radeon_read_sync(0x9fffa448); /* 00545023 */
	radeon_read_sync(0x9fffa44c); /* 01010000 */
	radeon_read_sync(0x9fffa450); /* 01010101 */
	radeon_read_sync(0x9fffa454); /* 01010101 */
	radeon_read_sync(0x9fffa458); /* 01010101 */
	radeon_read_sync(0x9fffa45c); /* 1dce0101 */
	radeon_read_sync(0x9fffa460); /* 0050c056 */
	radeon_read_sync(0x9fffa464); /* 0a083030 */
	radeon_read_sync(0x9fffa468); /* c1580031 */
	radeon_read_sync(0x9fffa46c); /* 18000010 */
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa474); /* 30300050 */
	radeon_read_sync(0x9fffa478); /* 00310a08 */
	radeon_read_sync(0x9fffa47c); /* 0010c158 */
	radeon_read_sync(0x9fffa480); /* 00001800 */
	radeon_read_sync(0x9fffa484); /* 00000000 */
	radeon_read_sync(0x9fffa488); /* 00000000 */
	radeon_read_sync(0x9fffa48c); /* 00000000 */
	radeon_read_sync(0x9fffa490); /* 00000000 */
	radeon_read_sync(0x9fffa494); /* 02000000 */
	radeon_read_sync(0x9fffa498); /* f9330c00 */
	radeon_read_sync(0x9fffa49c); /* 1f643c0a */
	radeon_read_sync(0x9fffa4a0); /* 206e2214 */
	radeon_read_sync(0x9fffa4a4); /* e7002020 */
	radeon_read_sync(0x9fffa548); /* 00000000 */
	radeon_write_sync(0x9fffa548, 0x0000000e);
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa548); /* 0000000e */
	radeon_read_sync(0x1724); /* 00000000 */
	radeon_write_sync(0x1724, 0x00040000);
	radeon_write_sync(0x9fffa54c, 0x00000000);
	radeon_write_sync(0x9fffa550, 0x00000000);
	radeon_write_sync(0x9fffa554, 0x00000000);
	radeon_write_sync(0x9fffa558, 0x00000000);
	radeon_write_sync(0x9fffa55c, 0x00000000);
	radeon_write_sync(0x9fffa560, 0x00000000);
	radeon_write_sync(0x9fffa564, 0x00000000);
	radeon_write_sync(0x9fffa568, 0x00000000);
	radeon_write_sync(0x9fffa56c, 0x00000000);
	radeon_write_sync(0x9fffa570, 0x00000000);
	radeon_write_sync(0x9fffa574, 0x00000000);
	radeon_write_sync(0x9fffa578, 0x00000000);
	radeon_write_sync(0x9fffa57c, 0x00000000);
	radeon_write_sync(0x9fffa580, 0x00000000);
	radeon_write_sync(0x9fffa584, 0x00000000);
	radeon_write_sync(0x9fffa588, 0x00000000);
	radeon_write_sync(0x9fffa58c, 0x00000000);
	radeon_write_sync(0x9fffa590, 0x00000000);
	radeon_write_sync(0x9fffa594, 0x00000000);
	radeon_write_sync(0x9fffa598, 0x00000000);
	radeon_write_sync(0x9fffa59c, 0x00000000);
	radeon_write_sync(0x9fffa5a0, 0x00000000);
	radeon_write_sync(0x9fffa5a4, 0x00000000);
	radeon_write_sync(0x9fffa5a8, 0x00000000);
	radeon_write_sync(0x9fffa5ac, 0x00000000);
	radeon_write_sync(0x9fffa5b0, 0x00000000);
	radeon_write_sync(0x9fffa5b4, 0x00000000);
	radeon_write_sync(0x9fffa5b8, 0x00000000);
	radeon_write_sync(0x9fffa5bc, 0x00000000);
	radeon_write_sync(0x9fffa5c0, 0x00000000);
	radeon_write_sync(0x9fffa5c4, 0x00000000);
	radeon_write_sync(0x9fffa5c8, 0x00000000);
	radeon_write_sync(0x9fffa5cc, 0x00000000);
	radeon_write_sync(0x9fffa5d0, 0x00000000);
	radeon_write_sync(0x9fffa5d4, 0x00000000);
	radeon_write_sync(0x9fffa5d8, 0x00000000);
	radeon_write_sync(0x9fffa5dc, 0x00000000);
	radeon_write_sync(0x9fffa5e0, 0x00000000);
	radeon_write_sync(0x9fffa5e4, 0x00000000);
	radeon_write_sync(0x9fffa5e8, 0x00000000);
	radeon_write_sync(0x9fffa5ec, 0x00000000);
	radeon_write_sync(0x9fffa5f0, 0x00000000);
	radeon_write_sync(0x9fffa5f4, 0x00000000);
	radeon_write_sync(0x9fffa5f8, 0x00000000);
	radeon_write_sync(0x9fffa5fc, 0x00000000);
	radeon_write_sync(0x9fffa600, 0x00000000);
	radeon_write_sync(0x9fffa604, 0x00000000);
	radeon_write_sync(0x9fffa608, 0x00000000);
	radeon_write_sync(0x9fffa60c, 0x00000000);
	radeon_write_sync(0x9fffa610, 0x00000000);
	radeon_write_sync(0x9fffa614, 0x00000000);
	radeon_write_sync(0x9fffa618, 0x00000000);
	radeon_write_sync(0x9fffa61c, 0x00000000);
	radeon_write_sync(0x9fffa620, 0x00000000);
	radeon_write_sync(0x9fffa624, 0x00000000);
	radeon_write_sync(0x9fffa628, 0x00000000);
	radeon_write_sync(0x9fffa62c, 0x00000000);
	radeon_write_sync(0x9fffa630, 0x00000000);
	radeon_write_sync(0x9fffa634, 0x00000000);
	radeon_write_sync(0x9fffa638, 0x00000000);
	radeon_write_sync(0x9fffa63c, 0x00000000);
	radeon_write_sync(0x9fffa640, 0x00000000);
	radeon_write_sync(0x9fffa644, 0x00000000);
	radeon_write_sync(0x9fffa648, 0x00000000);
	radeon_write_sync(0x9fffa64c, 0x00000000);
	radeon_write_sync(0x9fffa650, 0x00000000);
	radeon_write_sync(0x9fffa654, 0x00000000);
	radeon_write_sync(0x9fffa658, 0x00000000);
	radeon_write_sync(0x9fffa65c, 0x00000000);
	radeon_write_sync(0x9fffa660, 0x00000000);
	radeon_write_sync(0x9fffa664, 0x00000000);
	radeon_write_sync(0x9fffa668, 0x00000000);
	radeon_write_sync(0x9fffa66c, 0x00000000);
	radeon_write_sync(0x9fffa670, 0x00000000);
	radeon_write_sync(0x9fffa674, 0x00000000);
	radeon_write_sync(0x9fffa678, 0x00000000);
	radeon_write_sync(0x9fffa67c, 0x00000000);
	radeon_write_sync(0x9fffa680, 0x00000000);
	radeon_write_sync(0x9fffa684, 0x00000000);
	radeon_write_sync(0x9fffa688, 0x00000000);
	radeon_write_sync(0x9fffa68c, 0x00000000);
	radeon_write_sync(0x9fffa690, 0x00000000);
	radeon_write_sync(0x9fffa694, 0x00000000);
	radeon_write_sync(0x9fffa698, 0x00000000);
	radeon_write_sync(0x9fffa69c, 0x00000000);
	radeon_write_sync(0x9fffa6a0, 0x00000000);
	radeon_write_sync(0x9fffa6a4, 0x00000000);
	radeon_write_sync(0x9fffa6a8, 0x00000000);
	radeon_write_sync(0x9fffa6ac, 0x00000000);
	radeon_write_sync(0x9fffa6b0, 0x00000000);
	radeon_write_sync(0x9fffa6b4, 0x00000000);
	radeon_write_sync(0x9fffa6b8, 0x00000000);
	radeon_write_sync(0x9fffa6bc, 0x00000000);
	radeon_write_sync(0x9fffa6c0, 0x00000000);
	radeon_write_sync(0x9fffa6c4, 0x00000000);
	radeon_write_sync(0x9fffa6c8, 0x00000000);
	radeon_write_sync(0x9fffa6cc, 0x00000000);
	radeon_read_sync(0x9fffa548); /* 0000000e */
	radeon_read_sync(0x9fffa44c); /* 01010000 */
	radeon_read_sync(0x9fffa450); /* 01010101 */
	radeon_read_sync(0x9fffa450); /* 01010101 */
	radeon_read_sync(0x9fffa450); /* 01010101 */
	radeon_read_sync(0x9fffa454); /* 01010101 */
	radeon_read_sync(0x9fffa454); /* 01010101 */
	radeon_read_sync(0x9fffa454); /* 01010101 */
	radeon_read_sync(0x9fffa458); /* 01010101 */
	radeon_read_sync(0x9fffa458); /* 01010101 */
	radeon_read_sync(0x9fffa458); /* 01010101 */
	radeon_read_sync(0x9fffa45c); /* 1dce0101 */
	radeon_read_sync(0x9fffa45c); /* 1dce0101 */
	radeon_read_sync(0x9fffa448); /* 00545023 */
	radeon_read_sync(0x9fffa44c); /* 01010000 */
	radeon_read_sync(0x9fffa45c); /* 1dce0101 */
	radeon_read_sync(0x9fffa460); /* 0050c056 */
	radeon_read_sync(0x9fffa46c); /* 18000010 */
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa580); /* 00000000 */
	radeon_write_old(0x9fffa580, 0x00000206);
	radeon_read_sync(0x9fffa45c); /* 1dce0101 */
	radeon_read_sync(0x9fffa460); /* 0050c056 */
	radeon_read_sync(0x9fffa568); /* 00000000 */
	radeon_write_old(0x9fffa568, 0x00001dce);
	radeon_read_sync(0x9fffa460); /* 0050c056 */
	radeon_read_sync(0x9fffa568); /* 00001dce */
	radeon_write_old(0x9fffa568, 0x05561dce);
	radeon_read_sync(0x9fffa56c); /* 00000000 */
	radeon_write_old(0x9fffa56c, 0x000000c0);
	radeon_read_sync(0x9fffa460); /* 0050c056 */
	radeon_read_sync(0x9fffa464); /* 0a083030 */
	radeon_read_sync(0x9fffa56c); /* 000000c0 */
	radeon_write_old(0x9fffa56c, 0x030000c0);
	radeon_read_sync(0x9fffa570); /* 00000000 */
	radeon_write_old(0x9fffa570, 0x00000030);
	radeon_read_sync(0x9fffa464); /* 0a083030 */
	radeon_read_sync(0x9fffa468); /* c1580031 */
	radeon_read_sync(0x9fffa574); /* 00000000 */
	radeon_write_old(0x9fffa574, 0x0000000a);
	radeon_read_sync(0x9fffa570); /* 00000030 */
	radeon_write_old(0x9fffa570, 0x00080030);
	radeon_read_sync(0x9fffa574); /* 0000000a */
	radeon_write_old(0x9fffa574, 0x0003000a);
	radeon_read_sync(0x9fffa578); /* 00000000 */
	radeon_write_old(0x9fffa578, 0x00000001);
	radeon_read_sync(0x9fffa468); /* c1580031 */
	radeon_read_sync(0x9fffa46c); /* 18000010 */
	radeon_read_sync(0x9fffa578); /* 00000001 */
	radeon_write_old(0x9fffa578, 0x01580001);
	radeon_read_sync(0x9fffa57c); /* 00000000 */
	radeon_write_old(0x9fffa57c, 0x000000c1);
	radeon_read_sync(0x9fffa46c); /* 18000010 */
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa57c); /* 000000c1 */
	radeon_write_old(0x9fffa57c, 0x000000c1);
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa480); /* 00001800 */
	radeon_read_sync(0x9fffa484); /* 00000000 */
	radeon_read_sync(0x9fffa59c); /* 00000000 */
	radeon_write_old(0x9fffa59c, 0x00000206);
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa584); /* 00000000 */
	radeon_write_old(0x9fffa584, 0x000013df);
	radeon_read_sync(0x9fffa470); /* c05613df */
	radeon_read_sync(0x9fffa474); /* 30300050 */
	radeon_read_sync(0x9fffa584); /* 000013df */
	radeon_write_old(0x9fffa584, 0x055613df);
	radeon_read_sync(0x9fffa588); /* 00000000 */
	radeon_write_old(0x9fffa588, 0x000000c0);
	radeon_read_sync(0x9fffa474); /* 30300050 */
	radeon_read_sync(0x9fffa478); /* 00310a08 */
	radeon_read_sync(0x9fffa588); /* 000000c0 */
	radeon_write_old(0x9fffa588, 0x030000c0);
	radeon_read_sync(0x9fffa58c); /* 00000000 */
	radeon_write_old(0x9fffa58c, 0x00000030);
	radeon_read_sync(0x9fffa478); /* 00310a08 */
	radeon_read_sync(0x9fffa590); /* 00000000 */
	radeon_write_old(0x9fffa590, 0x0000000a);
	radeon_read_sync(0x9fffa58c); /* 00000030 */
	radeon_write_old(0x9fffa58c, 0x00080030);
	radeon_read_sync(0x9fffa590); /* 0000000a */
	radeon_write_old(0x9fffa590, 0x0003000a);
	radeon_read_sync(0x9fffa594); /* 00000000 */
	radeon_write_old(0x9fffa594, 0x00000001);
	radeon_read_sync(0x9fffa47c); /* 0010c158 */
	radeon_read_sync(0x9fffa594); /* 00000001 */
	radeon_write_old(0x9fffa594, 0x01580001);
	radeon_read_sync(0x9fffa598); /* 00000000 */
	radeon_write_old(0x9fffa598, 0x000000c1);
	radeon_read_sync(0x9fffa47c); /* 0010c158 */
	radeon_read_sync(0x9fffa480); /* 00001800 */
	radeon_read_sync(0x9fffa598); /* 000000c1 */
	radeon_write_old(0x9fffa598, 0x000000c1);
	radeon_read_sync(0x9fffa480); /* 00001800 */
	radeon_read_sync(0x9fffa484); /* 00000000 */
	radeon_read_sync(0x9fffa494); /* 02000000 */
	radeon_read_sync(0x9fffa6b4); /* 00000000 */
	radeon_write_sync(0x9fffa6b4, 0x00000000);
	radeon_read_sync(0x9fffa438); /* 04011500 */
	radeon_read_sync(0x9fffa43c); /* 78132290 */
	radeon_read_sync(0x9fffa43c); /* 78132290 */
	radeon_read_sync(0x9fffa6b4); /* 00000000 */
	radeon_write_sync(0x9fffa6b4, 0x00000100);
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa574); /* 0003000a */
	radeon_read_sync(0x9fffa578); /* 01580001 */
	radeon_read_sync(0x9fffa57c); /* 000000c1 */
	radeon_read_sync(0x9fffa580); /* 00000206 */
	radeon_read_sync(0x9fffa6b4); /* 00000100 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_read_sync(0x9fffa534); /* 00000000 */
	radeon_read_sync(0x9fffa528); /* 41810a11 */
	radeon_write_sync(0x9fffa54c, 0x00000000);
	radeon_write_sync(0x9fffa550, 0x00000000);
	radeon_write_sync(0x9fffa554, 0x00000000);
	radeon_write_sync(0x9fffa558, 0x00000000);
	radeon_write_sync(0x9fffa55c, 0x00000000);
	radeon_write_sync(0x9fffa560, 0x00000000);
	radeon_write_sync(0x9fffa564, 0x00000000);
	radeon_write_sync(0x9fffa568, 0x00000000);
	radeon_write_sync(0x9fffa56c, 0x00000000);
	radeon_write_sync(0x9fffa570, 0x00000000);
	radeon_write_sync(0x9fffa574, 0x00000000);
	radeon_write_sync(0x9fffa578, 0x00000000);
	radeon_write_sync(0x9fffa57c, 0x00000000);
	radeon_write_sync(0x9fffa580, 0x00000000);
	radeon_write_sync(0x9fffa584, 0x00000000);
	radeon_write_sync(0x9fffa588, 0x00000000);
	radeon_write_sync(0x9fffa58c, 0x00000000);
	radeon_write_sync(0x9fffa590, 0x00000000);
	radeon_write_sync(0x9fffa594, 0x00000000);
	radeon_write_sync(0x9fffa598, 0x00000000);
	radeon_write_sync(0x9fffa59c, 0x00000000);
	radeon_write_sync(0x9fffa5a0, 0x00000000);
	radeon_write_sync(0x9fffa5a4, 0x00000000);
	radeon_write_sync(0x9fffa5a8, 0x00000000);
	radeon_write_sync(0x9fffa5ac, 0x00000000);
	radeon_write_sync(0x9fffa5b0, 0x00000000);
	radeon_write_sync(0x9fffa5b4, 0x00000000);
	radeon_write_sync(0x9fffa5b8, 0x00000000);
	radeon_write_sync(0x9fffa5bc, 0x00000000);
	radeon_write_sync(0x9fffa5c0, 0x00000000);
	radeon_write_sync(0x9fffa5c4, 0x00000000);
	radeon_write_sync(0x9fffa5c8, 0x00000000);
	radeon_write_sync(0x9fffa5cc, 0x00000000);
	radeon_write_sync(0x9fffa5d0, 0x00000000);
	radeon_write_sync(0x9fffa5d4, 0x00000000);
	radeon_write_sync(0x9fffa5d8, 0x00000000);
	radeon_write_sync(0x9fffa5dc, 0x00000000);
	radeon_write_sync(0x9fffa5e0, 0x00000000);
	radeon_write_sync(0x9fffa5e4, 0x00000000);
	radeon_write_sync(0x9fffa5e8, 0x00000000);
	radeon_write_sync(0x9fffa5ec, 0x00000000);
	radeon_write_sync(0x9fffa5f0, 0x00000000);
	radeon_write_sync(0x9fffa5f4, 0x00000000);
	radeon_write_sync(0x9fffa5f8, 0x00000000);
	radeon_write_sync(0x9fffa5fc, 0x00000000);
	radeon_write_sync(0x9fffa600, 0x00000000);
	radeon_write_sync(0x9fffa604, 0x00000000);
	radeon_write_sync(0x9fffa608, 0x00000000);
	radeon_write_sync(0x9fffa60c, 0x00000000);
	radeon_write_sync(0x9fffa610, 0x00000000);
	radeon_write_sync(0x9fffa614, 0x00000000);
	radeon_write_sync(0x9fffa618, 0x00000000);
	radeon_write_sync(0x9fffa61c, 0x00000000);
	radeon_write_sync(0x9fffa620, 0x00000000);
	radeon_write_sync(0x9fffa624, 0x00000000);
	radeon_write_sync(0x9fffa628, 0x00000000);
	radeon_write_sync(0x9fffa62c, 0x00000000);
	radeon_write_sync(0x9fffa630, 0x00000000);
	radeon_write_sync(0x9fffa634, 0x00000000);
	radeon_write_sync(0x9fffa638, 0x00000000);
	radeon_write_sync(0x9fffa63c, 0x00000000);
	radeon_write_sync(0x9fffa640, 0x00000000);
	radeon_write_sync(0x9fffa644, 0x00000000);
	radeon_write_sync(0x9fffa648, 0x00000000);
	radeon_write_sync(0x9fffa64c, 0x00000000);
	radeon_write_sync(0x9fffa650, 0x00000000);
	radeon_write_sync(0x9fffa654, 0x00000000);
	radeon_write_sync(0x9fffa658, 0x00000000);
	radeon_write_sync(0x9fffa65c, 0x00000000);
	radeon_write_sync(0x9fffa660, 0x00000000);
	radeon_write_sync(0x9fffa664, 0x00000000);
	radeon_write_sync(0x9fffa668, 0x00000000);
	radeon_write_sync(0x9fffa66c, 0x00000000);
	radeon_write_sync(0x9fffa670, 0x00000000);
	radeon_write_sync(0x9fffa674, 0x00000000);
	radeon_write_sync(0x9fffa678, 0x00000000);
	radeon_write_sync(0x9fffa67c, 0x00000000);
	radeon_write_sync(0x9fffa680, 0x00000000);
	radeon_write_sync(0x9fffa684, 0x00000000);
	radeon_write_sync(0x9fffa688, 0x00000000);
	radeon_write_sync(0x9fffa68c, 0x00000000);
	radeon_write_sync(0x9fffa690, 0x00000000);
	radeon_write_sync(0x9fffa694, 0x00000000);
	radeon_write_sync(0x9fffa698, 0x00000000);
	radeon_write_sync(0x9fffa69c, 0x00000000);
	radeon_write_sync(0x9fffa6a0, 0x00000000);
	radeon_write_sync(0x9fffa6a4, 0x00000000);
	radeon_write_sync(0x9fffa6a8, 0x00000000);
	radeon_write_sync(0x9fffa6ac, 0x00000000);
	radeon_write_sync(0x9fffa6b0, 0x00000000);
	radeon_write_sync(0x9fffa6b4, 0x00000000);
	radeon_write_sync(0x9fffa6b8, 0x00000000);
	radeon_write_sync(0x9fffa6bc, 0x00000000);
	radeon_write_sync(0x9fffa6c0, 0x00000000);
	radeon_write_sync(0x9fffa6c4, 0x00000000);
	radeon_write_sync(0x9fffa6c8, 0x00000000);
	radeon_write_sync(0x9fffa6cc, 0x00000000);
	radeon_read_sync(0x9fffa548); /* 0000000e */
	radeon_write_sync(0x9fffa6b8, 0x00000013);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa6b4); /* 00000000 */
	radeon_write_sync(0x9fffa6b4, 0x00000004);
	radeon_write_sync(0x9fffa568, 0x05561dce);
	radeon_write_sync(0x9fffa56c, 0x030000c0);
	radeon_write_sync(0x9fffa570, 0x00080030);
	radeon_write_sync(0x9fffa574, 0x0003000a);
	radeon_write_sync(0x9fffa578, 0x01580001);
	radeon_write_sync(0x9fffa57c, 0x000000c1);
	radeon_write_sync(0x9fffa580, 0x00000206);
	radeon_read_sync(0x9fffa6b4); /* 00000004 */
	radeon_write_sync(0x9fffa6b4, 0x00000104);
	radeon_write_sync(0x9fffa528, 0x41810a01);
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_write_sync(0x9fffa530, 0x00000108);
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fff9e00); /* 00000000 */
	radeon_read_sync(0x9fff9e00); /* 00000000 */
	radeon_write_sync(0x9fff9e00, 0x00000001);
	radeon_write_sync(0x9fff9e08, 0x03000556);
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
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa754); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 00000000 */
	radeon_read_sync(0x12144); /* 00000000 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa404); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x9fffa74c); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa73c); /* 00000000 */
	radeon_read_sync(0x12144); /* 00000000 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x9fffa74c); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa73c); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa754); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 00000000 */
	radeon_read_sync(0x6200); /* 21040101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_write_sync(0x9fffcc00, 0x618005f0);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x9fffcc04, 0x00000200);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_read_sync(0x6204); /* 00030000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
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
	radeon_write_sync(0x9fffcc00, 0x409005f2);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x0000f200);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
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
	radeon_write_sync(0x9fffcc04, 0xf9000020);
	radeon_read_sync(0x9fffcc04); /* f9000020 */
	radeon_write_sync(0x9fffcc00, 0x618005f0);
	radeon_read_sync(0x9fffcc04); /* f9000020 */
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x9fffcc04, 0x00000300);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc00); /* 618005f0 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000300 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000300 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000300 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000300 */
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
	radeon_write_sync(0x9fffcc00, 0x409005f2);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
	radeon_write_sync(0x6218, 0x0000f200);
	radeon_read_sync(0x9fffcc00); /* 409005f2 */
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
	radeon_write_sync(0x9fffcc04, 0xf9000031);
	radeon_read_sync(0x9fffcc04); /* f9000031 */
	radeon_write_sync(0x9fffcc80, 0x003d0500);
	radeon_read_sync(0x9fffcc80); /* 003d0500 */
	radeon_write_sync(0x9fffcc84, 0x00031f00);
	radeon_read_sync(0x9fffcc84); /* 00031f00 */
	radeon_write_sync(0x9fffcc88, 0x0000ba00);
	radeon_read_sync(0x9fffcc88); /* 0000ba00 */
	radeon_write_sync(0x9fffcc8c, 0x0008bb00);
	radeon_read_sync(0x9fffcc8c); /* 0008bb00 */
	radeon_write_sync(0x9fffcc90, 0x004bb100);
	radeon_read_sync(0x9fffcc90); /* 004bb100 */
	radeon_write_sync(0x9fffcc94, 0x00697301);
	radeon_read_sync(0x9fffcc94); /* 00697301 */
	radeon_write_sync(0x9fffcc98, 0x00249f01);
	radeon_read_sync(0x9fffcc98); /* 00249f01 */
	radeon_write_sync(0x9fffcc9c, 0x00331900);
	radeon_read_sync(0x9fffcc9c); /* 00331900 */
	radeon_write_sync(0x9fffcca0, 0x00398900);
	radeon_read_sync(0x9fffcca0); /* 00398900 */
	radeon_write_sync(0x9fffcca4, 0x0042f800);
	radeon_read_sync(0x9fffcca4); /* 0042f800 */
	radeon_write_sync(0x9fffcca8, 0x0001f900);
	radeon_read_sync(0x9fffcca8); /* 0001f900 */
	radeon_write_sync(0x9fffccac, 0x0023fa00);
	radeon_read_sync(0x9fffccac); /* 0023fa00 */
	radeon_write_sync(0x9fffccb0, 0x0045fb00);
	radeon_read_sync(0x9fffccb0); /* 0045fb00 */
	radeon_write_sync(0x9fffccb4, 0x0067fc00);
	radeon_read_sync(0x9fffccb4); /* 0067fc00 */
	radeon_write_sync(0x9fffccb8, 0x0089fd00);
	radeon_read_sync(0x9fffccb8); /* 0089fd00 */
	radeon_write_sync(0x9fffccbc, 0x00abfe00);
	radeon_read_sync(0x9fffccbc); /* 00abfe00 */
	radeon_write_sync(0x9fffccc0, 0x00251d00);
	radeon_read_sync(0x9fffccc0); /* 00251d00 */
	radeon_write_sync(0x9fffccc4, 0x0007c301);
	radeon_read_sync(0x9fffccc4); /* 0007c301 */
	radeon_write_sync(0x9fffccc8, 0x005ac201);
	radeon_read_sync(0x9fffccc8); /* 005ac201 */
	radeon_write_sync(0x9fffcccc, 0x0000c401);
	radeon_read_sync(0x9fffcccc); /* 0000c401 */
	radeon_write_sync(0x9fffccd0, 0x0007c001);
	radeon_read_sync(0x9fffccd0); /* 0007c001 */
	radeon_write_sync(0x9fffccd4, 0x005ac101);
	radeon_read_sync(0x9fffccd4); /* 005ac101 */
	radeon_write_sync(0x9fffccd8, 0x0000b101);
	radeon_read_sync(0x9fffccd8); /* 0000b101 */
	radeon_write_sync(0x9fffccdc, 0x007dbf01);
	radeon_read_sync(0x9fffccdc); /* 007dbf01 */
	radeon_write_sync(0x9fffcce0, 0x0063b501);
	radeon_read_sync(0x9fffcce0); /* 0063b501 */
	radeon_write_sync(0x9fffcce4, 0x0080cb01);
	radeon_read_sync(0x9fffcce4); /* 0080cb01 */
	radeon_write_sync(0x9fffcce8, 0x0000b301);
	radeon_read_sync(0x9fffcce8); /* 0000b301 */
	radeon_write_sync(0x9fffccec, 0x0000b201);
	radeon_read_sync(0x9fffccec); /* 0000b201 */
	radeon_write_sync(0x9fffccf0, 0x00109f00);
	radeon_read_sync(0x9fffccf0); /* 00109f00 */
	radeon_write_sync(0x9fffccf4, 0x00148301);
	radeon_read_sync(0x9fffccf4); /* 00148301 */
	radeon_write_sync(0x9fffccf8, 0x00c2a700);
	radeon_read_sync(0x9fffccf8); /* 00c2a700 */
	radeon_write_sync(0x9fffccfc, 0x00127101);
	radeon_read_sync(0x9fffccfc); /* 00127101 */
	radeon_write_sync(0x9fffcd00, 0x005d8201);
	radeon_read_sync(0x9fffcd00); /* 005d8201 */
	radeon_write_sync(0x9fffcd04, 0x00288901);
	radeon_read_sync(0x9fffcd04); /* 00288901 */
	radeon_write_sync(0x9fffcd08, 0x0001be01);
	radeon_read_sync(0x9fffcd08); /* 0001be01 */
	radeon_write_sync(0x9fffcd0c, 0x00538a00);
	radeon_read_sync(0x9fffcd0c); /* 00538a00 */
	radeon_write_sync(0x9fffcd10, 0x00010a00);
	radeon_read_sync(0x9fffcd10); /* 00010a00 */
	radeon_write_sync(0x9fffcd14, 0x0010d401);
	radeon_read_sync(0x9fffcd14); /* 0010d401 */
	radeon_write_sync(0x9fffcd18, 0x0040f300);
	radeon_read_sync(0x9fffcd18); /* 0040f300 */
	radeon_write_sync(0x9fffcd1c, 0x0000f400);
	radeon_read_sync(0x9fffcd1c); /* 0000f400 */
	radeon_write_sync(0x9fffcd20, 0x0000b401);
	radeon_read_sync(0x9fffcd20); /* 0000b401 */
	radeon_write_sync(0x9fffcd24, 0x0000dc00);
	radeon_read_sync(0x9fffcd24); /* 0000dc00 */
	radeon_write_sync(0x9fffcd28, 0x0000dd00);
	radeon_read_sync(0x9fffcd28); /* 0000dd00 */
	radeon_write_sync(0x9fffcd2c, 0x00209101);
	radeon_read_sync(0x9fffcd2c); /* 00209101 */
	radeon_write_sync(0x9fffcd30, 0x0006d100);
	radeon_read_sync(0x9fffcd30); /* 0006d100 */
	radeon_write_sync(0x9fffcd34, 0x0001d600);
	radeon_read_sync(0x9fffcd34); /* 0001d600 */
	radeon_write_sync(0x9fffcd38, 0x0008d201);
	radeon_read_sync(0x9fffcd38); /* 0008d201 */
	radeon_write_sync(0x9fffcd3c, 0x0080d301);
	radeon_read_sync(0x9fffcd3c); /* 0080d301 */
	radeon_write_sync(0x9fffcd40, 0xffffffff);
	radeon_read_sync(0x9fffcd40); /* ffffffff */
	radeon_read_sync(0x9fffcce8); /* 0000b301 */
	radeon_write_sync(0x9fffcce8, 0x0066b301);
	radeon_read_sync(0x9fffccec); /* 0000b201 */
	radeon_write_sync(0x9fffccec, 0x009ab201);
	radeon_read_sync(0x9fffcd18); /* 0040f300 */
	radeon_write_sync(0x9fffcd18, 0x0000f300);
	radeon_read_sync(0x9fffcd20); /* 0000b401 */
	radeon_write_sync(0x9fffcd20, 0x0002b401);
	radeon_read_sync(0x9fffccf0); /* 00109f00 */
	radeon_write_sync(0x9fffccf0, 0x00009f00);
	radeon_read_sync(0x9fffcd1c); /* 0000f400 */
	radeon_write_sync(0x9fffcd1c, 0x003cf400);
	radeon_read_sync(0x9fffcd20); /* 0002b401 */
	radeon_write_sync(0x9fffcd20, 0x0006b401);
	radeon_read_sync(0x9fffccc4); /* 0007c301 */
	radeon_write_sync(0x9fffccc4, 0x0007c301);
	radeon_read_sync(0x9fffccc8); /* 005ac201 */
	radeon_write_sync(0x9fffccc8, 0x005ac201);
	radeon_read_sync(0x9fffcccc); /* 0000c401 */
	radeon_write_sync(0x9fffcccc, 0x0003c401);
	radeon_read_sync(0x9fffccd0); /* 0007c001 */
	radeon_write_sync(0x9fffccd0, 0x0007c001);
	radeon_read_sync(0x9fffccd4); /* 005ac101 */
	radeon_write_sync(0x9fffccd4, 0x005ac101);
	radeon_read_sync(0x9fffccd8); /* 0000b101 */
	radeon_write_sync(0x9fffccd8, 0x0003b101);
	radeon_read_sync(0x9fffccdc); /* 007dbf01 */
	radeon_write_sync(0x9fffccdc, 0x007dbf01);
	radeon_read_sync(0x9fffcc80); /* 003d0500 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x003d0500);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 003d0500 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 003d0500 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc08); /* 003d0500 */
	radeon_write_sync(0x6218, 0x00003d00);
	radeon_read_sync(0x9fffcc08); /* 003d0500 */
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
	radeon_read_sync(0x9fffcc84); /* 00031f00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00031f00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00031f00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00031f00 */
	radeon_write_sync(0x6218, 0x00001f00);
	radeon_read_sync(0x9fffcc08); /* 00031f00 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffcc08); /* 00031f00 */
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
	radeon_read_sync(0x9fffcc88); /* 0000ba00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0000ba00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0000ba00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000ba00 */
	radeon_write_sync(0x6218, 0x0000ba00);
	radeon_read_sync(0x9fffcc08); /* 0000ba00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000ba00 */
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
	radeon_read_sync(0x9fffcc8c); /* 0008bb00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0008bb00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0008bb00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0008bb00 */
	radeon_write_sync(0x6218, 0x0000bb00);
	radeon_read_sync(0x9fffcc08); /* 0008bb00 */
	radeon_write_sync(0x6218, 0x00000800);
	radeon_read_sync(0x9fffcc08); /* 0008bb00 */
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
	radeon_read_sync(0x9fffcc90); /* 004bb100 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x004bb100);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 004bb100 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 004bb100 */
	radeon_write_sync(0x6218, 0x0000b100);
	radeon_read_sync(0x9fffcc08); /* 004bb100 */
	radeon_write_sync(0x6218, 0x00004b00);
	radeon_read_sync(0x9fffcc08); /* 004bb100 */
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
	radeon_read_sync(0x9fffcc94); /* 00697301 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00697301);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00697301 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00697301 */
	radeon_write_sync(0x6218, 0x00007300);
	radeon_read_sync(0x9fffcc08); /* 00697301 */
	radeon_write_sync(0x6218, 0x00006900);
	radeon_read_sync(0x9fffcc08); /* 00697301 */
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
	radeon_read_sync(0x9fffcc98); /* 00249f01 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00249f01);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00249f01 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00249f01 */
	radeon_write_sync(0x6218, 0x00009f00);
	radeon_read_sync(0x9fffcc08); /* 00249f01 */
	radeon_write_sync(0x6218, 0x00002400);
	radeon_read_sync(0x9fffcc08); /* 00249f01 */
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
	radeon_read_sync(0x9fffcc9c); /* 00331900 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00331900);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00331900 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00331900 */
	radeon_write_sync(0x6218, 0x00001900);
	radeon_read_sync(0x9fffcc08); /* 00331900 */
	radeon_write_sync(0x6218, 0x00003300);
	radeon_read_sync(0x9fffcc08); /* 00331900 */
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
	radeon_read_sync(0x9fffcca0); /* 00398900 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00398900);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00398900 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00398900 */
	radeon_write_sync(0x6218, 0x00008900);
	radeon_read_sync(0x9fffcc08); /* 00398900 */
	radeon_write_sync(0x6218, 0x00003900);
	radeon_read_sync(0x9fffcc08); /* 00398900 */
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
	radeon_read_sync(0x9fffcca4); /* 0042f800 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0042f800);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0042f800 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0042f800 */
	radeon_write_sync(0x6218, 0x0000f800);
	radeon_read_sync(0x9fffcc08); /* 0042f800 */
	radeon_write_sync(0x6218, 0x00004200);
	radeon_read_sync(0x9fffcc08); /* 0042f800 */
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
	radeon_read_sync(0x9fffcca8); /* 0001f900 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0001f900);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0001f900 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0001f900 */
	radeon_write_sync(0x6218, 0x0000f900);
	radeon_read_sync(0x9fffcc08); /* 0001f900 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0001f900 */
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
	radeon_read_sync(0x9fffccac); /* 0023fa00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0023fa00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0023fa00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0023fa00 */
	radeon_write_sync(0x6218, 0x0000fa00);
	radeon_read_sync(0x9fffcc08); /* 0023fa00 */
	radeon_write_sync(0x6218, 0x00002300);
	radeon_read_sync(0x9fffcc08); /* 0023fa00 */
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
	radeon_read_sync(0x9fffccb0); /* 0045fb00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0045fb00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0045fb00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0045fb00 */
	radeon_write_sync(0x6218, 0x0000fb00);
	radeon_read_sync(0x9fffcc08); /* 0045fb00 */
	radeon_write_sync(0x6218, 0x00004500);
	radeon_read_sync(0x9fffcc08); /* 0045fb00 */
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
	radeon_read_sync(0x9fffccb4); /* 0067fc00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0067fc00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0067fc00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0067fc00 */
	radeon_write_sync(0x6218, 0x0000fc00);
	radeon_read_sync(0x9fffcc08); /* 0067fc00 */
	radeon_write_sync(0x6218, 0x00006700);
	radeon_read_sync(0x9fffcc08); /* 0067fc00 */
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
	radeon_read_sync(0x9fffccb8); /* 0089fd00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0089fd00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0089fd00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0089fd00 */
	radeon_write_sync(0x6218, 0x0000fd00);
	radeon_read_sync(0x9fffcc08); /* 0089fd00 */
	radeon_write_sync(0x6218, 0x00008900);
	radeon_read_sync(0x9fffcc08); /* 0089fd00 */
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
	radeon_read_sync(0x9fffccbc); /* 00abfe00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00abfe00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00abfe00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00abfe00 */
	radeon_write_sync(0x6218, 0x0000fe00);
	radeon_read_sync(0x9fffcc08); /* 00abfe00 */
	radeon_write_sync(0x6218, 0x0000ab00);
	radeon_read_sync(0x9fffcc08); /* 00abfe00 */
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
	radeon_read_sync(0x9fffccc0); /* 00251d00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00251d00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00251d00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00251d00 */
	radeon_write_sync(0x6218, 0x00001d00);
	radeon_read_sync(0x9fffcc08); /* 00251d00 */
	radeon_write_sync(0x6218, 0x00002500);
	radeon_read_sync(0x9fffcc08); /* 00251d00 */
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
	radeon_read_sync(0x9fffccc4); /* 0007c301 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0007c301);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0007c301 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0007c301 */
	radeon_write_sync(0x6218, 0x0000c300);
	radeon_read_sync(0x9fffcc08); /* 0007c301 */
	radeon_write_sync(0x6218, 0x00000700);
	radeon_read_sync(0x9fffcc08); /* 0007c301 */
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
	radeon_read_sync(0x9fffccc8); /* 005ac201 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x005ac201);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 005ac201 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 005ac201 */
	radeon_write_sync(0x6218, 0x0000c200);
	radeon_read_sync(0x9fffcc08); /* 005ac201 */
	radeon_write_sync(0x6218, 0x00005a00);
	radeon_read_sync(0x9fffcc08); /* 005ac201 */
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
	radeon_read_sync(0x9fffcccc); /* 0003c401 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0003c401);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0003c401 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0003c401 */
	radeon_write_sync(0x6218, 0x0000c400);
	radeon_read_sync(0x9fffcc08); /* 0003c401 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffcc08); /* 0003c401 */
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
	radeon_read_sync(0x9fffccd0); /* 0007c001 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0007c001);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0007c001 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0007c001 */
	radeon_write_sync(0x6218, 0x0000c000);
	radeon_read_sync(0x9fffcc08); /* 0007c001 */
	radeon_write_sync(0x6218, 0x00000700);
	radeon_read_sync(0x9fffcc08); /* 0007c001 */
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
	radeon_read_sync(0x9fffccd4); /* 005ac101 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x005ac101);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 005ac101 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 005ac101 */
	radeon_write_sync(0x6218, 0x0000c100);
	radeon_read_sync(0x9fffcc08); /* 005ac101 */
	radeon_write_sync(0x6218, 0x00005a00);
	radeon_read_sync(0x9fffcc08); /* 005ac101 */
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
	radeon_read_sync(0x9fffccd8); /* 0003b101 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0003b101);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0003b101 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0003b101 */
	radeon_write_sync(0x6218, 0x0000b100);
	radeon_read_sync(0x9fffcc08); /* 0003b101 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffcc08); /* 0003b101 */
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
	radeon_read_sync(0x9fffccdc); /* 007dbf01 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x007dbf01);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 007dbf01 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 007dbf01 */
	radeon_write_sync(0x6218, 0x0000bf00);
	radeon_read_sync(0x9fffcc08); /* 007dbf01 */
	radeon_write_sync(0x6218, 0x00007d00);
	radeon_read_sync(0x9fffcc08); /* 007dbf01 */
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
	radeon_read_sync(0x9fffcce0); /* 0063b501 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0063b501);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0063b501 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0063b501 */
	radeon_write_sync(0x6218, 0x0000b500);
	radeon_read_sync(0x9fffcc08); /* 0063b501 */
	radeon_write_sync(0x6218, 0x00006300);
	radeon_read_sync(0x9fffcc08); /* 0063b501 */
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
	radeon_read_sync(0x9fffcce4); /* 0080cb01 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0080cb01);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0080cb01 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0080cb01 */
	radeon_write_sync(0x6218, 0x0000cb00);
	radeon_read_sync(0x9fffcc08); /* 0080cb01 */
	radeon_write_sync(0x6218, 0x00008000);
	radeon_read_sync(0x9fffcc08); /* 0080cb01 */
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
	radeon_read_sync(0x9fffcce8); /* 0066b301 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0066b301);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0066b301 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0066b301 */
	radeon_write_sync(0x6218, 0x0000b300);
	radeon_read_sync(0x9fffcc08); /* 0066b301 */
	radeon_write_sync(0x6218, 0x00006600);
	radeon_read_sync(0x9fffcc08); /* 0066b301 */
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
	radeon_read_sync(0x9fffccec); /* 009ab201 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x009ab201);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 009ab201 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 009ab201 */
	radeon_write_sync(0x6218, 0x0000b200);
	radeon_read_sync(0x9fffcc08); /* 009ab201 */
	radeon_write_sync(0x6218, 0x00009a00);
	radeon_read_sync(0x9fffcc08); /* 009ab201 */
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
	radeon_read_sync(0x9fffccf0); /* 00009f00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00009f00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00009f00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00009f00 */
	radeon_write_sync(0x6218, 0x00009f00);
	radeon_read_sync(0x9fffcc08); /* 00009f00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00009f00 */
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
	radeon_read_sync(0x9fffccf4); /* 00148301 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00148301);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00148301 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00148301 */
	radeon_write_sync(0x6218, 0x00008300);
	radeon_read_sync(0x9fffcc08); /* 00148301 */
	radeon_write_sync(0x6218, 0x00001400);
	radeon_read_sync(0x9fffcc08); /* 00148301 */
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
	radeon_read_sync(0x9fffccf8); /* 00c2a700 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00c2a700);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00c2a700 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00c2a700 */
	radeon_write_sync(0x6218, 0x0000a700);
	radeon_read_sync(0x9fffcc08); /* 00c2a700 */
	radeon_write_sync(0x6218, 0x0000c200);
	radeon_read_sync(0x9fffcc08); /* 00c2a700 */
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
	radeon_read_sync(0x9fffccfc); /* 00127101 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00127101);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00127101 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00127101 */
	radeon_write_sync(0x6218, 0x00007100);
	radeon_read_sync(0x9fffcc08); /* 00127101 */
	radeon_write_sync(0x6218, 0x00001200);
	radeon_read_sync(0x9fffcc08); /* 00127101 */
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
	radeon_read_sync(0x9fffcd00); /* 005d8201 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x005d8201);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 005d8201 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 005d8201 */
	radeon_write_sync(0x6218, 0x00008200);
	radeon_read_sync(0x9fffcc08); /* 005d8201 */
	radeon_write_sync(0x6218, 0x00005d00);
	radeon_read_sync(0x9fffcc08); /* 005d8201 */
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
	radeon_read_sync(0x9fffcd04); /* 00288901 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00288901);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00288901 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00288901 */
	radeon_write_sync(0x6218, 0x00008900);
	radeon_read_sync(0x9fffcc08); /* 00288901 */
	radeon_write_sync(0x6218, 0x00002800);
	radeon_read_sync(0x9fffcc08); /* 00288901 */
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
	radeon_read_sync(0x9fffcd08); /* 0001be01 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0001be01);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0001be01 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0001be01 */
	radeon_write_sync(0x6218, 0x0000be00);
	radeon_read_sync(0x9fffcc08); /* 0001be01 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0001be01 */
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
	radeon_read_sync(0x9fffcd0c); /* 00538a00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00538a00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00538a00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00538a00 */
	radeon_write_sync(0x6218, 0x00008a00);
	radeon_read_sync(0x9fffcc08); /* 00538a00 */
	radeon_write_sync(0x6218, 0x00005300);
	radeon_read_sync(0x9fffcc08); /* 00538a00 */
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
	radeon_read_sync(0x9fffcd10); /* 00010a00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00010a00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00010a00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 00010a00 */
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_read_sync(0x9fffcc08); /* 00010a00 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00010a00 */
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
	radeon_read_sync(0x9fffcd14); /* 0010d401 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0010d401);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0010d401 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0010d401 */
	radeon_write_sync(0x6218, 0x0000d400);
	radeon_read_sync(0x9fffcc08); /* 0010d401 */
	radeon_write_sync(0x6218, 0x00001000);
	radeon_read_sync(0x9fffcc08); /* 0010d401 */
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
	radeon_read_sync(0x9fffcd18); /* 0000f300 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0000f300);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0000f300 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000f300 */
	radeon_write_sync(0x6218, 0x0000f300);
	radeon_read_sync(0x9fffcc08); /* 0000f300 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000f300 */
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
	radeon_read_sync(0x9fffcd1c); /* 003cf400 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x003cf400);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 003cf400 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 003cf400 */
	radeon_write_sync(0x6218, 0x0000f400);
	radeon_read_sync(0x9fffcc08); /* 003cf400 */
	radeon_write_sync(0x6218, 0x00003c00);
	radeon_read_sync(0x9fffcc08); /* 003cf400 */
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
	radeon_read_sync(0x9fffcd20); /* 0006b401 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0006b401);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0006b401 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0006b401 */
	radeon_write_sync(0x6218, 0x0000b400);
	radeon_read_sync(0x9fffcc08); /* 0006b401 */
	radeon_write_sync(0x6218, 0x00000600);
	radeon_read_sync(0x9fffcc08); /* 0006b401 */
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
	radeon_read_sync(0x9fffcd24); /* 0000dc00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0000dc00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0000dc00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000dc00 */
	radeon_write_sync(0x6218, 0x0000dc00);
	radeon_read_sync(0x9fffcc08); /* 0000dc00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000dc00 */
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
	radeon_read_sync(0x9fffcd28); /* 0000dd00 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0000dd00);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0000dd00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000dd00 */
	radeon_write_sync(0x6218, 0x0000dd00);
	radeon_read_sync(0x9fffcc08); /* 0000dd00 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0000dd00 */
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
	radeon_read_sync(0x9fffcd2c); /* 00209101 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x00209101);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 00209101 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 00209101 */
	radeon_write_sync(0x6218, 0x00009100);
	radeon_read_sync(0x9fffcc08); /* 00209101 */
	radeon_write_sync(0x6218, 0x00002000);
	radeon_read_sync(0x9fffcc08); /* 00209101 */
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
	radeon_read_sync(0x9fffcd30); /* 0006d100 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0006d100);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0006d100 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0006d100 */
	radeon_write_sync(0x6218, 0x0000d100);
	radeon_read_sync(0x9fffcc08); /* 0006d100 */
	radeon_write_sync(0x6218, 0x00000600);
	radeon_read_sync(0x9fffcc08); /* 0006d100 */
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
	radeon_read_sync(0x9fffcd34); /* 0001d600 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0001d600);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0001d600 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffcc08); /* 0001d600 */
	radeon_write_sync(0x6218, 0x0000d600);
	radeon_read_sync(0x9fffcc08); /* 0001d600 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0001d600 */
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
	radeon_read_sync(0x9fffcd38); /* 0008d201 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0008d201);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0008d201 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0008d201 */
	radeon_write_sync(0x6218, 0x0000d200);
	radeon_read_sync(0x9fffcc08); /* 0008d201 */
	radeon_write_sync(0x6218, 0x00000800);
	radeon_read_sync(0x9fffcc08); /* 0008d201 */
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
	radeon_read_sync(0x9fffcd3c); /* 0080d301 */
	radeon_write_sync(0x9fffcc04, 0x728005f0);
	radeon_write_sync(0x9fffcc08, 0x0080d301);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00070000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 728005f0 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffcc08); /* 0080d301 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffcc08); /* 0080d301 */
	radeon_write_sync(0x6218, 0x0000d300);
	radeon_read_sync(0x9fffcc08); /* 0080d301 */
	radeon_write_sync(0x6218, 0x00008000);
	radeon_read_sync(0x9fffcc08); /* 0080d301 */
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
	radeon_read_sync(0x9fffcd40); /* ffffffff */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffa814); /* 0000211e */
	radeon_read_sync(0x9fffa818); /* 00000000 */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffa804); /* 00000000 */
	radeon_read_sync(0x9fffa814); /* 0000211e */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffab5c); /* 00000000 */
	radeon_read_sync(0x9fffa810); /* 00000392 */
	radeon_read_sync(0x9fffab58); /* 00000000 */
	radeon_read_sync(0x9fffab4c); /* 00000000 */
	radeon_read_sync(0x9fffab50); /* 00000000 */
	radeon_read_sync(0x9fffab40); /* 00000000 */
	radeon_read_sync(0x9fffab44); /* 00000000 */
	radeon_read_sync(0x9fffab40); /* 00000000 */
	radeon_read_sync(0x9fffab3c); /* 00000000 */
	radeon_read_sync(0x7144); /* 00000000 */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffa814); /* 0000211e */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffab5c); /* 00000000 */
	radeon_read_sync(0x9fffa810); /* 00000392 */
	radeon_read_sync(0x9fffab58); /* 00000000 */
	radeon_read_sync(0x9fffab4c); /* 00000000 */
	radeon_read_sync(0x9fffab50); /* 00000000 */
	radeon_read_sync(0x9fffab40); /* 00000000 */
	radeon_read_sync(0x9fffab44); /* 00000000 */
	radeon_read_sync(0x9fffab40); /* 00000000 */
	radeon_read_sync(0x9fffab3c); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x9fffa814); /* 0000211e */
	radeon_read_sync(0x9fffa818); /* 00000000 */
	radeon_read_sync(0x9fffa80c); /* 0000310c */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa00c); /* 00003105 */
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa018); /* 00000000 */
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa018); /* 00000000 */
	radeon_read_sync(0x9fffa354); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa350); /* 00000000 */
	radeon_read_sync(0x9fffa300); /* 00000000 */
	radeon_write_sync(0x9fffcc80, 0x83888008);
	radeon_write_sync(0x9fffcc84, 0x00000f7f);
	radeon_write_sync(0x9fffcc88, 0x83888000);
	radeon_write_sync(0x9fffcc8c, 0x00000013);
	radeon_write_sync(0x9fffcc90, 0x00088018);
	radeon_write_sync(0x9fffcc94, 0xffffffff);
	radeon_write_sync(0x9fffcc98, 0x00000100);
	radeon_write_sync(0x9fffcc9c, 0x83885000);
	radeon_write_sync(0x9fffcca0, 0x00000000);
	radeon_write_sync(0x9fffcca4, 0x83885050);
	radeon_write_sync(0x9fffcca8, 0x01010101);
	radeon_write_sync(0x9fffccac, 0x000850a4);
	radeon_write_sync(0x9fffccb0, 0xfffffffe);
	radeon_write_sync(0x9fffccb4, 0x00000001);
	radeon_write_sync(0x9fffccb8, 0x00088018);
	radeon_write_sync(0x9fffccbc, 0xffffffdf);
	radeon_write_sync(0x9fffccc0, 0x00000000);
	radeon_write_sync(0x9fffccc4, 0x00083024);
	radeon_write_sync(0x9fffccc8, 0xfcffffff);
	radeon_write_sync(0x9fffcccc, 0x00060403);
	radeon_write_sync(0x9fffccd0, 0x83883038);
	radeon_write_sync(0x9fffccd4, 0x20000000);
	radeon_write_sync(0x9fffccd8, 0x83800600);
	radeon_write_sync(0x9fffccdc, 0x00000002);
	radeon_write_sync(0x9fffcce0, 0x00080004);
	radeon_write_sync(0x9fffcce4, 0xffffffdf);
	radeon_write_sync(0x9fffcce8, 0x00000000);
	radeon_write_sync(0x9fffccec, 0x00080004);
	radeon_write_sync(0x9fffccf0, 0xfffff7ff);
	radeon_write_sync(0x9fffccf4, 0x00000000);
	radeon_write_sync(0x9fffccf8, 0x00080104);
	radeon_write_sync(0x9fffccfc, 0xffffffdf);
	radeon_write_sync(0x9fffcd00, 0x00000000);
	radeon_write_sync(0x9fffcd04, 0x00080104);
	radeon_write_sync(0x9fffcd08, 0xfffff7ff);
	radeon_write_sync(0x9fffcd0c, 0x00000000);
	radeon_write_sync(0x9fffcd10, 0x00080204);
	radeon_write_sync(0x9fffcd14, 0xffffffdf);
	radeon_write_sync(0x9fffcd18, 0x00000000);
	radeon_write_sync(0x9fffcd1c, 0x00080204);
	radeon_write_sync(0x9fffcd20, 0xfffff7ff);
	radeon_write_sync(0x9fffcd24, 0x00000000);
	radeon_write_sync(0x9fffcd28, 0x00080304);
	radeon_write_sync(0x9fffcd2c, 0xffffffdf);
	radeon_write_sync(0x9fffcd30, 0x00000000);
	radeon_write_sync(0x9fffcd34, 0x00080304);
	radeon_write_sync(0x9fffcd38, 0xfffff7ff);
	radeon_write_sync(0x9fffcd3c, 0x00000000);
	radeon_write_sync(0x9fffcd40, 0x00080004);
	radeon_write_sync(0x9fffcd44, 0xfffffffe);
	radeon_write_sync(0x9fffcd48, 0x00000000);
	radeon_write_sync(0x9fffcd4c, 0x00080104);
	radeon_write_sync(0x9fffcd50, 0xfffffffe);
	radeon_write_sync(0x9fffcd54, 0x00000000);
	radeon_write_sync(0x9fffcd58, 0x00080204);
	radeon_write_sync(0x9fffcd5c, 0xfffffffe);
	radeon_write_sync(0x9fffcd60, 0x00000000);
	radeon_write_sync(0x9fffcd64, 0x00080304);
	radeon_write_sync(0x9fffcd68, 0xfffffffe);
	radeon_write_sync(0x9fffcd6c, 0x00000000);
	radeon_write_sync(0x9fffcd70, 0x00080008);
	radeon_write_sync(0x9fffcd74, 0xffffffff);
	radeon_write_sync(0x9fffcd78, 0x00002000);
	radeon_write_sync(0x9fffcd7c, 0x00080108);
	radeon_write_sync(0x9fffcd80, 0xffffffff);
	radeon_write_sync(0x9fffcd84, 0x00002000);
	radeon_write_sync(0x9fffcd88, 0x00080208);
	radeon_write_sync(0x9fffcd8c, 0xffffffff);
	radeon_write_sync(0x9fffcd90, 0x00002000);
	radeon_write_sync(0x9fffcd94, 0x00080308);
	radeon_write_sync(0x9fffcd98, 0xffffffff);
	radeon_write_sync(0x9fffcd9c, 0x00002000);
	radeon_write_sync(0x9fffcda0, 0x00088018);
	radeon_write_sync(0x9fffcda4, 0xfffffdff);
	radeon_write_sync(0x9fffcda8, 0x00000000);
	radeon_write_sync(0x9fffcdac, 0x83881104);
	radeon_write_sync(0x9fffcdb0, 0x00000000);
	radeon_write_sync(0x9fffcdb4, 0x83881004);
	radeon_write_sync(0x9fffcdb8, 0x00000000);
	radeon_write_sync(0x9fffcdbc, 0x83888008);
	radeon_write_sync(0x9fffcdc0, 0x00000f53);
	radeon_write_sync(0x9fffcdc4, 0x83888000);
	radeon_write_sync(0x9fffcdc8, 0x00000000);
	radeon_write_sync(0x9fffcdcc, 0x00088018);
	radeon_write_sync(0x9fffcdd0, 0xfffff7ff);
	radeon_write_sync(0x9fffcdd4, 0x00000000);
	radeon_write_sync(0x9fffcdd8, 0x83888004);
	radeon_write_sync(0x9fffcddc, 0x00000001);
	radeon_write_sync(0x9fffcde0, 0xffffffff);
	radeon_read_sync(0x9fffcc80); /* 83888008 */
	radeon_read_sync(0x9fffcc84); /* 00000f7f */
	radeon_write_sync(0x9fffcc00, 0x83888008);
	radeon_write_sync(0x9fffcc04, 0x00000f7f);
	radeon_read_sync(0x6540); /* 0f400000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21040000 */
	radeon_write_sync(0x6250, 0x21140000);
	radeon_read_sync(0x6250); /* 21140000 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_read_sync(0x6254); /* 00000000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00007f00);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
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
	radeon_read_sync(0x9fffcc88); /* 83888000 */
	radeon_read_sync(0x9fffcc8c); /* 00000013 */
	radeon_write_sync(0x9fffcc00, 0x83888000);
	radeon_write_sync(0x9fffcc04, 0x00000013);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000013 */
	radeon_write_sync(0x6268, 0x00001300);
	radeon_read_sync(0x9fffcc04); /* 00000013 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000013 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000013 */
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
	radeon_read_sync(0x9fffcc90); /* 00088018 */
	radeon_read_sync(0x9fffcc94); /* ffffffff */
	radeon_read_sync(0x9fffcc90); /* 00088018 */
	radeon_write_sync(0x9fffcc00, 0x43988018);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
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
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_read_sync(0x9fffcc90); /* 00088018 */
	radeon_read_sync(0x9fffcc94); /* ffffffff */
	radeon_read_sync(0x9fffcc98); /* 00000100 */
	radeon_write_sync(0x9fffcc00, 0x83888018);
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
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
	radeon_read_sync(0x9fffcc9c); /* 83885000 */
	radeon_read_sync(0x9fffcca0); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83885000);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcca4); /* 83885050 */
	radeon_read_sync(0x9fffcca8); /* 01010101 */
	radeon_write_sync(0x9fffcc00, 0x83885050);
	radeon_write_sync(0x9fffcc04, 0x01010101);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
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
	radeon_read_sync(0x9fffccac); /* 000850a4 */
	radeon_read_sync(0x9fffccb0); /* fffffffe */
	radeon_read_sync(0x9fffccac); /* 000850a4 */
	radeon_write_sync(0x9fffcc00, 0x439850a4);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
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
	radeon_write_sync(0x9fffcc04, 0x00000080);
	radeon_read_sync(0x9fffcc04); /* 00000080 */
	radeon_read_sync(0x9fffccac); /* 000850a4 */
	radeon_read_sync(0x9fffccb0); /* fffffffe */
	radeon_read_sync(0x9fffccb4); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x838850a4);
	radeon_write_sync(0x9fffcc04, 0x00000081);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00008100);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
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
	radeon_read_sync(0x9fffccb8); /* 00088018 */
	radeon_read_sync(0x9fffccbc); /* ffffffdf */
	radeon_read_sync(0x9fffccb8); /* 00088018 */
	radeon_write_sync(0x9fffcc00, 0x43988018);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
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
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_read_sync(0x9fffccb8); /* 00088018 */
	radeon_read_sync(0x9fffccbc); /* ffffffdf */
	radeon_read_sync(0x9fffccc0); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83888018);
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
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
	radeon_read_sync(0x9fffccc4); /* 00083024 */
	radeon_read_sync(0x9fffccc8); /* fcffffff */
	radeon_read_sync(0x9fffccc4); /* 00083024 */
	radeon_write_sync(0x9fffcc00, 0x43983024);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43983024 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43983024 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43983024 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 43983024 */
	radeon_write_sync(0x6268, 0x00002400);
	radeon_read_sync(0x9fffcc00); /* 43983024 */
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
	radeon_write_sync(0x9fffcc04, 0x01000000);
	radeon_read_sync(0x9fffcc04); /* 01000000 */
	radeon_read_sync(0x9fffccc4); /* 00083024 */
	radeon_read_sync(0x9fffccc8); /* fcffffff */
	radeon_read_sync(0x9fffcccc); /* 00060403 */
	radeon_write_sync(0x9fffcc00, 0x83883024);
	radeon_write_sync(0x9fffcc04, 0x00060403);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00002400);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
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
	radeon_read_sync(0x9fffccd0); /* 83883038 */
	radeon_read_sync(0x9fffccd4); /* 20000000 */
	radeon_write_sync(0x9fffcc00, 0x83883038);
	radeon_write_sync(0x9fffcc04, 0x20000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00003800);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
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
	radeon_read_sync(0x9fffccd8); /* 83800600 */
	radeon_read_sync(0x9fffccdc); /* 00000002 */
	radeon_write_sync(0x9fffcc00, 0x83800600);
	radeon_write_sync(0x9fffcc04, 0x00000002);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83800600 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800600 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800600 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc00); /* 83800600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83800600 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000002 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000002 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000002 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000002 */
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
	radeon_read_sync(0x9fffcce0); /* 00080004 */
	radeon_read_sync(0x9fffcce4); /* ffffffdf */
	radeon_read_sync(0x9fffcce0); /* 00080004 */
	radeon_write_sync(0x9fffcc00, 0x43980004);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a21);
	radeon_read_sync(0x9fffcc04); /* 00000a21 */
	radeon_read_sync(0x9fffcce0); /* 00080004 */
	radeon_read_sync(0x9fffcce4); /* ffffffdf */
	radeon_read_sync(0x9fffcce8); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880004);
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
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
	radeon_read_sync(0x9fffccec); /* 00080004 */
	radeon_read_sync(0x9fffccf0); /* fffff7ff */
	radeon_read_sync(0x9fffccec); /* 00080004 */
	radeon_write_sync(0x9fffcc00, 0x43980004);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_read_sync(0x9fffccec); /* 00080004 */
	radeon_read_sync(0x9fffccf0); /* fffff7ff */
	radeon_read_sync(0x9fffccf4); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880004);
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
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
	radeon_read_sync(0x9fffccf8); /* 00080104 */
	radeon_read_sync(0x9fffccfc); /* ffffffdf */
	radeon_read_sync(0x9fffccf8); /* 00080104 */
	radeon_write_sync(0x9fffcc00, 0x43980104);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a21);
	radeon_read_sync(0x9fffcc04); /* 00000a21 */
	radeon_read_sync(0x9fffccf8); /* 00080104 */
	radeon_read_sync(0x9fffccfc); /* ffffffdf */
	radeon_read_sync(0x9fffcd00); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880104);
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
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
	radeon_read_sync(0x9fffcd04); /* 00080104 */
	radeon_read_sync(0x9fffcd08); /* fffff7ff */
	radeon_read_sync(0x9fffcd04); /* 00080104 */
	radeon_write_sync(0x9fffcc00, 0x43980104);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_read_sync(0x9fffcd04); /* 00080104 */
	radeon_read_sync(0x9fffcd08); /* fffff7ff */
	radeon_read_sync(0x9fffcd0c); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880104);
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
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
	radeon_read_sync(0x9fffcd10); /* 00080204 */
	radeon_read_sync(0x9fffcd14); /* ffffffdf */
	radeon_read_sync(0x9fffcd10); /* 00080204 */
	radeon_write_sync(0x9fffcc00, 0x43980204);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a21);
	radeon_read_sync(0x9fffcc04); /* 00000a21 */
	radeon_read_sync(0x9fffcd10); /* 00080204 */
	radeon_read_sync(0x9fffcd14); /* ffffffdf */
	radeon_read_sync(0x9fffcd18); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880204);
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
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
	radeon_read_sync(0x9fffcd1c); /* 00080204 */
	radeon_read_sync(0x9fffcd20); /* fffff7ff */
	radeon_read_sync(0x9fffcd1c); /* 00080204 */
	radeon_write_sync(0x9fffcc00, 0x43980204);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_read_sync(0x9fffcd1c); /* 00080204 */
	radeon_read_sync(0x9fffcd20); /* fffff7ff */
	radeon_read_sync(0x9fffcd24); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880204);
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
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
	radeon_read_sync(0x9fffcd28); /* 00080304 */
	radeon_read_sync(0x9fffcd2c); /* ffffffdf */
	radeon_read_sync(0x9fffcd28); /* 00080304 */
	radeon_write_sync(0x9fffcc00, 0x43980304);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a21);
	radeon_read_sync(0x9fffcc04); /* 00000a21 */
	radeon_read_sync(0x9fffcd28); /* 00080304 */
	radeon_read_sync(0x9fffcd2c); /* ffffffdf */
	radeon_read_sync(0x9fffcd30); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880304);
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000a00);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
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
	radeon_read_sync(0x9fffcd34); /* 00080304 */
	radeon_read_sync(0x9fffcd38); /* fffff7ff */
	radeon_read_sync(0x9fffcd34); /* 00080304 */
	radeon_write_sync(0x9fffcc00, 0x43980304);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
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
	radeon_write_sync(0x9fffcc04, 0x00000a01);
	radeon_read_sync(0x9fffcc04); /* 00000a01 */
	radeon_read_sync(0x9fffcd34); /* 00080304 */
	radeon_read_sync(0x9fffcd38); /* fffff7ff */
	radeon_read_sync(0x9fffcd3c); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880304);
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
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
	radeon_read_sync(0x9fffcd40); /* 00080004 */
	radeon_read_sync(0x9fffcd44); /* fffffffe */
	radeon_read_sync(0x9fffcd40); /* 00080004 */
	radeon_write_sync(0x9fffcc00, 0x43980004);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980004 */
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
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_read_sync(0x9fffcd40); /* 00080004 */
	radeon_read_sync(0x9fffcd44); /* fffffffe */
	radeon_read_sync(0x9fffcd48); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880004);
	radeon_write_sync(0x9fffcc04, 0x00000200);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
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
	radeon_read_sync(0x9fffcd4c); /* 00080104 */
	radeon_read_sync(0x9fffcd50); /* fffffffe */
	radeon_read_sync(0x9fffcd4c); /* 00080104 */
	radeon_write_sync(0x9fffcc00, 0x43980104);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980104 */
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
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_read_sync(0x9fffcd4c); /* 00080104 */
	radeon_read_sync(0x9fffcd50); /* fffffffe */
	radeon_read_sync(0x9fffcd54); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880104);
	radeon_write_sync(0x9fffcc04, 0x00000200);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
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
	radeon_read_sync(0x9fffcd58); /* 00080204 */
	radeon_read_sync(0x9fffcd5c); /* fffffffe */
	radeon_read_sync(0x9fffcd58); /* 00080204 */
	radeon_write_sync(0x9fffcc00, 0x43980204);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980204 */
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
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_read_sync(0x9fffcd58); /* 00080204 */
	radeon_read_sync(0x9fffcd5c); /* fffffffe */
	radeon_read_sync(0x9fffcd60); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880204);
	radeon_write_sync(0x9fffcc04, 0x00000200);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
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
	radeon_read_sync(0x9fffcd64); /* 00080304 */
	radeon_read_sync(0x9fffcd68); /* fffffffe */
	radeon_read_sync(0x9fffcd64); /* 00080304 */
	radeon_write_sync(0x9fffcc00, 0x43980304);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 43980304 */
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
	radeon_write_sync(0x9fffcc04, 0x00000201);
	radeon_read_sync(0x9fffcc04); /* 00000201 */
	radeon_read_sync(0x9fffcd64); /* 00080304 */
	radeon_read_sync(0x9fffcd68); /* fffffffe */
	radeon_read_sync(0x9fffcd6c); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83880304);
	radeon_write_sync(0x9fffcc04, 0x00000200);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000200 */
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
	radeon_read_sync(0x9fffcd70); /* 00080008 */
	radeon_read_sync(0x9fffcd74); /* ffffffff */
	radeon_read_sync(0x9fffcd70); /* 00080008 */
	radeon_write_sync(0x9fffcc00, 0x43980008);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
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
	radeon_write_sync(0x9fffcc04, 0x00000805);
	radeon_read_sync(0x9fffcc04); /* 00000805 */
	radeon_read_sync(0x9fffcd70); /* 00080008 */
	radeon_read_sync(0x9fffcd74); /* ffffffff */
	radeon_read_sync(0x9fffcd78); /* 00002000 */
	radeon_write_sync(0x9fffcc00, 0x83880008);
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
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
	radeon_read_sync(0x9fffcd7c); /* 00080108 */
	radeon_read_sync(0x9fffcd80); /* ffffffff */
	radeon_read_sync(0x9fffcd7c); /* 00080108 */
	radeon_write_sync(0x9fffcc00, 0x43980108);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
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
	radeon_write_sync(0x9fffcc04, 0x00000805);
	radeon_read_sync(0x9fffcc04); /* 00000805 */
	radeon_read_sync(0x9fffcd7c); /* 00080108 */
	radeon_read_sync(0x9fffcd80); /* ffffffff */
	radeon_read_sync(0x9fffcd84); /* 00002000 */
	radeon_write_sync(0x9fffcc00, 0x83880108);
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
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
	radeon_read_sync(0x9fffcd88); /* 00080208 */
	radeon_read_sync(0x9fffcd8c); /* ffffffff */
	radeon_read_sync(0x9fffcd88); /* 00080208 */
	radeon_write_sync(0x9fffcc00, 0x43980208);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
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
	radeon_write_sync(0x9fffcc04, 0x00000805);
	radeon_read_sync(0x9fffcc04); /* 00000805 */
	radeon_read_sync(0x9fffcd88); /* 00080208 */
	radeon_read_sync(0x9fffcd8c); /* ffffffff */
	radeon_read_sync(0x9fffcd90); /* 00002000 */
	radeon_write_sync(0x9fffcc00, 0x83880208);
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
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
	radeon_read_sync(0x9fffcd94); /* 00080308 */
	radeon_read_sync(0x9fffcd98); /* ffffffff */
	radeon_read_sync(0x9fffcd94); /* 00080308 */
	radeon_write_sync(0x9fffcc00, 0x43980308);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
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
	radeon_write_sync(0x9fffcc04, 0x00000805);
	radeon_read_sync(0x9fffcc04); /* 00000805 */
	radeon_read_sync(0x9fffcd94); /* 00080308 */
	radeon_read_sync(0x9fffcd98); /* ffffffff */
	radeon_read_sync(0x9fffcd9c); /* 00002000 */
	radeon_write_sync(0x9fffcc00, 0x83880308);
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
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
	radeon_read_sync(0x9fffcda0); /* 00088018 */
	radeon_read_sync(0x9fffcda4); /* fffffdff */
	radeon_read_sync(0x9fffcda0); /* 00088018 */
	radeon_write_sync(0x9fffcc00, 0x43988018);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
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
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_read_sync(0x9fffcda0); /* 00088018 */
	radeon_read_sync(0x9fffcda4); /* fffffdff */
	radeon_read_sync(0x9fffcda8); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83888018);
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
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
	radeon_read_sync(0x9fffcdac); /* 83881104 */
	radeon_read_sync(0x9fffcdb0); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83881104);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00001100);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcdb4); /* 83881004 */
	radeon_read_sync(0x9fffcdb8); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83881004);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcdbc); /* 83888008 */
	radeon_read_sync(0x9fffcdc0); /* 00000f53 */
	radeon_write_sync(0x9fffcc00, 0x83888008);
	radeon_write_sync(0x9fffcc04, 0x00000f53);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000f53 */
	radeon_write_sync(0x6268, 0x00005300);
	radeon_read_sync(0x9fffcc04); /* 00000f53 */
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_read_sync(0x9fffcc04); /* 00000f53 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000f53 */
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
	radeon_read_sync(0x9fffcdc4); /* 83888000 */
	radeon_read_sync(0x9fffcdc8); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83888000);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcdcc); /* 00088018 */
	radeon_read_sync(0x9fffcdd0); /* fffff7ff */
	radeon_read_sync(0x9fffcdcc); /* 00088018 */
	radeon_write_sync(0x9fffcc00, 0x43988018);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 43988018 */
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
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_read_sync(0x9fffcdcc); /* 00088018 */
	radeon_read_sync(0x9fffcdd0); /* fffff7ff */
	radeon_read_sync(0x9fffcdd4); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83888018);
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
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
	radeon_read_sync(0x9fffcdd8); /* 83888004 */
	radeon_read_sync(0x9fffcddc); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83888004);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21140101);
	radeon_read_sync(0x9fffcc00); /* 83888004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888004 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83888004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffcde0); /* ffffffff */
	radeon_read_sync(0x9fffcde4); /* 00000000 */
	radeon_read_sync(0x9fffa00c); /* 00003105 */
	radeon_read_sync(0x9fffa004); /* 00000000 */
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa00c); /* 00003105 */
	radeon_read_sync(0x9fffa35c); /* 00000000 */
	radeon_read_sync(0x9fffa010); /* 00000291 */
	radeon_read_sync(0x9fffa358); /* 00000000 */
	radeon_read_sync(0x9fffa34c); /* 00000000 */
	radeon_read_sync(0x9fffa350); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa344); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa33c); /* 00000000 */
	radeon_read_sync(0x12d44); /* 00000000 */
	radeon_read_sync(0x9fffa00c); /* 00003105 */
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa00c); /* 00003105 */
	radeon_read_sync(0x9fffa35c); /* 00000000 */
	radeon_read_sync(0x9fffa010); /* 00000291 */
	radeon_read_sync(0x9fffa358); /* 00000000 */
	radeon_read_sync(0x9fffa34c); /* 00000000 */
	radeon_read_sync(0x9fffa350); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa344); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa33c); /* 00000000 */
	radeon_read_sync(0x646c); /* 001f0f9f */
	radeon_write_sync(0x646c, 0x001f0f9f);
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa018); /* 00000000 */
	radeon_read_sync(0x9fffa014); /* 21222221 */
	radeon_read_sync(0x9fffa018); /* 00000000 */
	radeon_read_sync(0x9fffa354); /* 00000000 */
	radeon_read_sync(0x9fffa340); /* 00000000 */
	radeon_read_sync(0x9fffa350); /* 00000000 */
	radeon_read_sync(0x9fffa300); /* 00000000 */
	radeon_read_sync(0x6250); /* 21140101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_write_sync(0x9fffcc00, 0x439850a8);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
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
	radeon_write_sync(0x9fffcc04, 0x00011b19);
	radeon_read_sync(0x9fffcc04); /* 00011b19 */
	radeon_write_sync(0x9fffcc80, 0x83888008);
	radeon_write_sync(0x9fffcc84, 0x00000f7f);
	radeon_write_sync(0x9fffcc88, 0x83888000);
	radeon_write_sync(0x9fffcc8c, 0x00000010);
	radeon_write_sync(0x9fffcc90, 0x50800510);
	radeon_write_sync(0x9fffcc94, 0x000000e4);
	radeon_write_sync(0x9fffcc98, 0x50800511);
	radeon_write_sync(0x9fffcc9c, 0x00000000);
	radeon_write_sync(0x9fffcca0, 0x83800582);
	radeon_write_sync(0x9fffcca4, 0x00000001);
	radeon_write_sync(0x9fffcca8, 0x838005a1);
	radeon_write_sync(0x9fffccac, 0x000000f0);
	radeon_write_sync(0x9fffccb0, 0x83888018);
	radeon_write_sync(0x9fffccb4, 0x00000110);
	radeon_write_sync(0x9fffccb8, 0x83888080);
	radeon_write_sync(0x9fffccbc, 0x00000001);
	radeon_write_sync(0x9fffccc0, 0x83888070);
	radeon_write_sync(0x9fffccc4, 0x00000001);
	radeon_write_sync(0x9fffccc8, 0x83888030);
	radeon_write_sync(0x9fffcccc, 0x00000003);
	radeon_write_sync(0x9fffccd0, 0x83888020);
	radeon_write_sync(0x9fffccd4, 0x00000001);
	radeon_write_sync(0x9fffccd8, 0x83881008);
	radeon_write_sync(0x9fffccdc, 0x10000000);
	radeon_write_sync(0x9fffcce0, 0x83881004);
	radeon_write_sync(0x9fffcce4, 0x00230010);
	radeon_write_sync(0x9fffcce8, 0x83881008);
	radeon_write_sync(0x9fffccec, 0x101b0000);
	radeon_write_sync(0x9fffccf0, 0x83881104);
	radeon_write_sync(0x9fffccf4, 0x00000000);
	radeon_write_sync(0x9fffccf8, 0x83880400);
	radeon_write_sync(0x9fffccfc, 0x00000001);
	radeon_write_sync(0x9fffcd00, 0x83880004);
	radeon_write_sync(0x9fffcd04, 0x00000600);
	radeon_write_sync(0x9fffcd08, 0x00080008);
	radeon_write_sync(0x9fffcd0c, 0xfffffff4);
	radeon_write_sync(0x9fffcd10, 0x00002008);
	radeon_write_sync(0x9fffcd14, 0x83880104);
	radeon_write_sync(0x9fffcd18, 0x00000600);
	radeon_write_sync(0x9fffcd1c, 0x00080108);
	radeon_write_sync(0x9fffcd20, 0xfffffff4);
	radeon_write_sync(0x9fffcd24, 0x00002008);
	radeon_write_sync(0x9fffcd28, 0x83880204);
	radeon_write_sync(0x9fffcd2c, 0x00000600);
	radeon_write_sync(0x9fffcd30, 0x00080208);
	radeon_write_sync(0x9fffcd34, 0xfffffff4);
	radeon_write_sync(0x9fffcd38, 0x00002008);
	radeon_write_sync(0x9fffcd3c, 0x83880304);
	radeon_write_sync(0x9fffcd40, 0x00000600);
	radeon_write_sync(0x9fffcd44, 0x00080308);
	radeon_write_sync(0x9fffcd48, 0xfffffff4);
	radeon_write_sync(0x9fffcd4c, 0x00002008);
	radeon_write_sync(0x9fffcd50, 0x83883024);
	radeon_write_sync(0x9fffcd54, 0x00060403);
	radeon_write_sync(0x9fffcd58, 0x83883020);
	radeon_write_sync(0x9fffcd5c, 0x29076f85);
	radeon_write_sync(0x9fffcd60, 0x83883038);
	radeon_write_sync(0x9fffcd64, 0x20000000);
	radeon_write_sync(0x9fffcd68, 0x00083040);
	radeon_write_sync(0x9fffcd6c, 0xffeffffe);
	radeon_write_sync(0x9fffcd70, 0x00000001);
	radeon_write_sync(0x9fffcd74, 0x83883000);
	radeon_write_sync(0x9fffcd78, 0x00000001);
	radeon_write_sync(0x9fffcd7c, 0x83885000);
	radeon_write_sync(0x9fffcd80, 0x00000000);
	radeon_write_sync(0x9fffcd84, 0x83885050);
	radeon_write_sync(0x9fffcd88, 0x01010101);
	radeon_write_sync(0x9fffcd8c, 0x000850a4);
	radeon_write_sync(0x9fffcd90, 0xfffffffe);
	radeon_write_sync(0x9fffcd94, 0x00000001);
	radeon_write_sync(0x9fffcd98, 0x00000514);
	radeon_write_sync(0x9fffcd9c, 0xfffffffe);
	radeon_write_sync(0x9fffcda0, 0x00000000);
	radeon_write_sync(0x9fffcda4, 0x83800520);
	radeon_write_sync(0x9fffcda8, 0x000002ee);
	radeon_write_sync(0x9fffcdac, 0x8380051c);
	radeon_write_sync(0x9fffcdb0, 0x000007d0);
	radeon_write_sync(0x9fffcdb4, 0x83800518);
	radeon_write_sync(0x9fffcdb8, 0x00000000);
	radeon_write_sync(0x9fffcdbc, 0x50800513);
	radeon_write_sync(0x9fffcdc0, 0x00000000);
	radeon_write_sync(0x9fffcdc4, 0x00000514);
	radeon_write_sync(0x9fffcdc8, 0xfffffff9);
	radeon_write_sync(0x9fffcdcc, 0x00000006);
	radeon_write_sync(0x9fffcdd0, 0x83887038);
	radeon_write_sync(0x9fffcdd4, 0x00000100);
	radeon_write_sync(0x9fffcdd8, 0x00087030);
	radeon_write_sync(0x9fffcddc, 0xfffff0ff);
	radeon_write_sync(0x9fffcde0, 0x00000400);
	radeon_write_sync(0x9fffcde4, 0x00087030);
	radeon_write_sync(0x9fffcde8, 0xfdffffff);
	radeon_write_sync(0x9fffcdec, 0x02000000);
	radeon_write_sync(0x9fffcdf0, 0x00087008);
	radeon_write_sync(0x9fffcdf4, 0xffffffbf);
	radeon_write_sync(0x9fffcdf8, 0x00000040);
	radeon_write_sync(0x9fffcdfc, 0x00000514);
	radeon_write_sync(0x9fffce00, 0xfffffffe);
	radeon_write_sync(0x9fffce04, 0x00000001);
	radeon_write_sync(0x9fffce08, 0x00087030);
	radeon_write_sync(0x9fffce0c, 0xfffffffe);
	radeon_write_sync(0x9fffce10, 0x00000000);
	radeon_write_sync(0x9fffce14, 0xfffe01f4);
	radeon_write_sync(0x9fffce18, 0x83887014);
	radeon_write_sync(0x9fffce1c, 0x00110002);
	radeon_write_sync(0x9fffce20, 0x000850a8);
	radeon_write_sync(0x9fffce24, 0xfffeffff);
	radeon_write_sync(0x9fffce28, 0x00000000);
	radeon_write_sync(0x9fffce2c, 0x83885088);
	radeon_write_sync(0x9fffce30, 0x0000001f);
	radeon_write_sync(0x9fffce34, 0x83885074);
	radeon_write_sync(0x9fffce38, 0x00001b02);
	radeon_write_sync(0x9fffce3c, 0xffffffff);
	radeon_read_sync(0x9fffce30); /* 0000001f */
	radeon_write_sync(0x9fffce30, 0x00000019);
	radeon_read_sync(0x9fffce38); /* 00001b02 */
	radeon_write_sync(0x9fffce38, 0x00001b02);
	radeon_read_sync(0x9fffcc80); /* 83888008 */
	radeon_read_sync(0x9fffcc84); /* 00000f7f */
	radeon_write_sync(0x9fffcc00, 0x83888008);
	radeon_write_sync(0x9fffcc04, 0x00000f7f);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83888008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00007f00);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00000f00);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000f7f */
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
	radeon_read_sync(0x9fffcc88); /* 83888000 */
	radeon_read_sync(0x9fffcc8c); /* 00000010 */
	radeon_write_sync(0x9fffcc00, 0x83888000);
	radeon_write_sync(0x9fffcc04, 0x00000010);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83888000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000010 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc04); /* 00000010 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000010 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000010 */
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
	radeon_read_sync(0x9fffcc90); /* 50800510 */
	radeon_read_sync(0x9fffcc94); /* 000000e4 */
	radeon_write_sync(0x9fffcc00, 0x50800510);
	radeon_write_sync(0x9fffcc04, 0x000000e4);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 50800510 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x9fffcc00); /* 50800510 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 50800510 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 50800510 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc00); /* 50800510 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000000e4 */
	radeon_write_sync(0x6268, 0x0000e400);
	radeon_read_sync(0x9fffcc04); /* 000000e4 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000000e4 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000000e4 */
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
	radeon_read_sync(0x9fffcc98); /* 50800511 */
	radeon_read_sync(0x9fffcc9c); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x50800511);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 50800511 */
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x9fffcc00); /* 50800511 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 50800511 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 50800511 */
	radeon_write_sync(0x6268, 0x00001100);
	radeon_read_sync(0x9fffcc00); /* 50800511 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcca0); /* 83800582 */
	radeon_read_sync(0x9fffcca4); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83800582);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800582 */
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800582 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800582 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800582 */
	radeon_write_sync(0x6268, 0x00008200);
	radeon_read_sync(0x9fffcc00); /* 83800582 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffcca8); /* 838005a1 */
	radeon_read_sync(0x9fffccac); /* 000000f0 */
	radeon_write_sync(0x9fffcc00, 0x838005a1);
	radeon_write_sync(0x9fffcc04, 0x000000f0);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 838005a1 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 838005a1 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 838005a1 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 838005a1 */
	radeon_write_sync(0x6268, 0x0000a100);
	radeon_read_sync(0x9fffcc00); /* 838005a1 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 000000f0 */
	radeon_write_sync(0x6268, 0x0000f000);
	radeon_read_sync(0x9fffcc04); /* 000000f0 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000000f0 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000000f0 */
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
	radeon_read_sync(0x9fffccb0); /* 83888018 */
	radeon_read_sync(0x9fffccb4); /* 00000110 */
	radeon_write_sync(0x9fffcc00, 0x83888018);
	radeon_write_sync(0x9fffcc04, 0x00000110);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83888018 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000110 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc04); /* 00000110 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000110 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000110 */
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
	radeon_read_sync(0x9fffccb8); /* 83888080 */
	radeon_read_sync(0x9fffccbc); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83888080);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888080 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888080 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888080 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888080 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888080 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffccc0); /* 83888070 */
	radeon_read_sync(0x9fffccc4); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83888070);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888070 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888070 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888070 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888070 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83888070 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffccc8); /* 83888030 */
	radeon_read_sync(0x9fffcccc); /* 00000003 */
	radeon_write_sync(0x9fffcc00, 0x83888030);
	radeon_write_sync(0x9fffcc04, 0x00000003);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888030 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888030 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888030 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83888030 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000003 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000003 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000003 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000003 */
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
	radeon_read_sync(0x9fffccd0); /* 83888020 */
	radeon_read_sync(0x9fffccd4); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83888020);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83888020 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83888020 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83888020 */
	radeon_write_sync(0x6268, 0x00008000);
	radeon_read_sync(0x9fffcc00); /* 83888020 */
	radeon_write_sync(0x6268, 0x00002000);
	radeon_read_sync(0x9fffcc00); /* 83888020 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffccd8); /* 83881008 */
	radeon_read_sync(0x9fffccdc); /* 10000000 */
	radeon_write_sync(0x9fffcc00, 0x83881008);
	radeon_write_sync(0x9fffcc04, 0x10000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 10000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 10000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 10000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 10000000 */
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
	radeon_read_sync(0x9fffcce0); /* 83881004 */
	radeon_read_sync(0x9fffcce4); /* 00230010 */
	radeon_write_sync(0x9fffcc00, 0x83881004);
	radeon_write_sync(0x9fffcc04, 0x00230010);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83881004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00230010 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc04); /* 00230010 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00230010 */
	radeon_write_sync(0x6268, 0x00002300);
	radeon_read_sync(0x9fffcc04); /* 00230010 */
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
	radeon_read_sync(0x9fffcce8); /* 83881008 */
	radeon_read_sync(0x9fffccec); /* 101b0000 */
	radeon_write_sync(0x9fffcc00, 0x83881008);
	radeon_write_sync(0x9fffcc04, 0x101b0000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00001000);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83881008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 101b0000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 101b0000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 101b0000 */
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_read_sync(0x9fffcc04); /* 101b0000 */
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
	radeon_read_sync(0x9fffccf0); /* 83881104 */
	radeon_read_sync(0x9fffccf4); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83881104);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00001100);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83881104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffccf8); /* 83880400 */
	radeon_read_sync(0x9fffccfc); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83880400);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880400 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880400 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880400 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880400 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffcd00); /* 83880004 */
	radeon_read_sync(0x9fffcd04); /* 00000600 */
	radeon_write_sync(0x9fffcc00, 0x83880004);
	radeon_write_sync(0x9fffcc04, 0x00000600);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880004 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
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
	radeon_read_sync(0x9fffcd08); /* 00080008 */
	radeon_read_sync(0x9fffcd0c); /* fffffff4 */
	radeon_read_sync(0x9fffcd08); /* 00080008 */
	radeon_write_sync(0x9fffcc00, 0x43980008);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980008 */
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
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_read_sync(0x9fffcd08); /* 00080008 */
	radeon_read_sync(0x9fffcd0c); /* fffffff4 */
	radeon_read_sync(0x9fffcd10); /* 00002008 */
	radeon_write_sync(0x9fffcc00, 0x83880008);
	radeon_write_sync(0x9fffcc04, 0x0000280c);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
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
	radeon_read_sync(0x9fffcd14); /* 83880104 */
	radeon_read_sync(0x9fffcd18); /* 00000600 */
	radeon_write_sync(0x9fffcc00, 0x83880104);
	radeon_write_sync(0x9fffcc04, 0x00000600);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880104 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
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
	radeon_read_sync(0x9fffcd1c); /* 00080108 */
	radeon_read_sync(0x9fffcd20); /* fffffff4 */
	radeon_read_sync(0x9fffcd1c); /* 00080108 */
	radeon_write_sync(0x9fffcc00, 0x43980108);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980108 */
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
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_read_sync(0x9fffcd1c); /* 00080108 */
	radeon_read_sync(0x9fffcd20); /* fffffff4 */
	radeon_read_sync(0x9fffcd24); /* 00002008 */
	radeon_write_sync(0x9fffcc00, 0x83880108);
	radeon_write_sync(0x9fffcc04, 0x0000280c);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880108 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
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
	radeon_read_sync(0x9fffcd28); /* 83880204 */
	radeon_read_sync(0x9fffcd2c); /* 00000600 */
	radeon_write_sync(0x9fffcc00, 0x83880204);
	radeon_write_sync(0x9fffcc04, 0x00000600);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880204 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
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
	radeon_read_sync(0x9fffcd30); /* 00080208 */
	radeon_read_sync(0x9fffcd34); /* fffffff4 */
	radeon_read_sync(0x9fffcd30); /* 00080208 */
	radeon_write_sync(0x9fffcc00, 0x43980208);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980208 */
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
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_read_sync(0x9fffcd30); /* 00080208 */
	radeon_read_sync(0x9fffcd34); /* fffffff4 */
	radeon_read_sync(0x9fffcd38); /* 00002008 */
	radeon_write_sync(0x9fffcc00, 0x83880208);
	radeon_write_sync(0x9fffcc04, 0x0000280c);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880208 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
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
	radeon_read_sync(0x9fffcd3c); /* 83880304 */
	radeon_read_sync(0x9fffcd40); /* 00000600 */
	radeon_write_sync(0x9fffcc00, 0x83880304);
	radeon_write_sync(0x9fffcc04, 0x00000600);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc00); /* 83880304 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000600 */
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
	radeon_read_sync(0x9fffcd44); /* 00080308 */
	radeon_read_sync(0x9fffcd48); /* fffffff4 */
	radeon_read_sync(0x9fffcd44); /* 00080308 */
	radeon_write_sync(0x9fffcc00, 0x43980308);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43980308 */
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
	radeon_write_sync(0x9fffcc04, 0x00002805);
	radeon_read_sync(0x9fffcc04); /* 00002805 */
	radeon_read_sync(0x9fffcd44); /* 00080308 */
	radeon_read_sync(0x9fffcd48); /* fffffff4 */
	radeon_read_sync(0x9fffcd4c); /* 00002008 */
	radeon_write_sync(0x9fffcc00, 0x83880308);
	radeon_write_sync(0x9fffcc04, 0x0000280c);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83880308 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000c00);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00002800);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 0000280c */
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
	radeon_read_sync(0x9fffcd50); /* 83883024 */
	radeon_read_sync(0x9fffcd54); /* 00060403 */
	radeon_write_sync(0x9fffcc00, 0x83883024);
	radeon_write_sync(0x9fffcc04, 0x00060403);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00002400);
	radeon_read_sync(0x9fffcc00); /* 83883024 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00060403 */
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
	radeon_read_sync(0x9fffcd58); /* 83883020 */
	radeon_read_sync(0x9fffcd5c); /* 29076f85 */
	radeon_write_sync(0x9fffcc00, 0x83883020);
	radeon_write_sync(0x9fffcc04, 0x29076f85);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83883020 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883020 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883020 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883020 */
	radeon_write_sync(0x6268, 0x00002000);
	radeon_read_sync(0x9fffcc00); /* 83883020 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 29076f85 */
	radeon_write_sync(0x6268, 0x00008500);
	radeon_read_sync(0x9fffcc04); /* 29076f85 */
	radeon_write_sync(0x6268, 0x00006f00);
	radeon_read_sync(0x9fffcc04); /* 29076f85 */
	radeon_write_sync(0x6268, 0x00000700);
	radeon_read_sync(0x9fffcc04); /* 29076f85 */
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
	radeon_read_sync(0x9fffcd60); /* 83883038 */
	radeon_read_sync(0x9fffcd64); /* 20000000 */
	radeon_write_sync(0x9fffcc00, 0x83883038);
	radeon_write_sync(0x9fffcc04, 0x20000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00003800);
	radeon_read_sync(0x9fffcc00); /* 83883038 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 20000000 */
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
	radeon_read_sync(0x9fffcd68); /* 00083040 */
	radeon_read_sync(0x9fffcd6c); /* ffeffffe */
	radeon_read_sync(0x9fffcd68); /* 00083040 */
	radeon_write_sync(0x9fffcc00, 0x43983040);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43983040 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43983040 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43983040 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 43983040 */
	radeon_write_sync(0x6268, 0x00004000);
	radeon_read_sync(0x9fffcc00); /* 43983040 */
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
	radeon_write_sync(0x9fffcc04, 0x00100000);
	radeon_read_sync(0x9fffcc04); /* 00100000 */
	radeon_read_sync(0x9fffcd68); /* 00083040 */
	radeon_read_sync(0x9fffcd6c); /* ffeffffe */
	radeon_read_sync(0x9fffcd70); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83883040);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83883040 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883040 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883040 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883040 */
	radeon_write_sync(0x6268, 0x00004000);
	radeon_read_sync(0x9fffcc00); /* 83883040 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffcd74); /* 83883000 */
	radeon_read_sync(0x9fffcd78); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83883000);
	radeon_write_sync(0x9fffcc04, 0x00000001);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83883000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83883000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83883000 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83883000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83883000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000001 */
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
	radeon_read_sync(0x9fffcd7c); /* 83885000 */
	radeon_read_sync(0x9fffcd80); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83885000);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc00); /* 83885000 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcd84); /* 83885050 */
	radeon_read_sync(0x9fffcd88); /* 01010101 */
	radeon_write_sync(0x9fffcc00, 0x83885050);
	radeon_write_sync(0x9fffcc04, 0x01010101);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885050 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 01010101 */
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
	radeon_read_sync(0x9fffcd8c); /* 000850a4 */
	radeon_read_sync(0x9fffcd90); /* fffffffe */
	radeon_read_sync(0x9fffcd8c); /* 000850a4 */
	radeon_write_sync(0x9fffcc00, 0x439850a4);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_read_sync(0x9fffcc00); /* 439850a4 */
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
	radeon_write_sync(0x9fffcc04, 0x00000081);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_read_sync(0x9fffcd8c); /* 000850a4 */
	radeon_read_sync(0x9fffcd90); /* fffffffe */
	radeon_read_sync(0x9fffcd94); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x838850a4);
	radeon_write_sync(0x9fffcc04, 0x00000081);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x0000a400);
	radeon_read_sync(0x9fffcc00); /* 838850a4 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00008100);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000081 */
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
	radeon_read_sync(0x9fffcd98); /* 00000514 */
	radeon_read_sync(0x9fffcd9c); /* fffffffe */
	radeon_read_sync(0x9fffcd98); /* 00000514 */
	radeon_write_sync(0x9fffcc00, 0x43900514);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x80009000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
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
	radeon_write_sync(0x9fffcc04, 0x00010007);
	radeon_read_sync(0x9fffcc04); /* 00010007 */
	radeon_read_sync(0x9fffcd98); /* 00000514 */
	radeon_read_sync(0x9fffcd9c); /* fffffffe */
	radeon_read_sync(0x9fffcda0); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83800514);
	radeon_write_sync(0x9fffcc04, 0x00010006);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
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
	radeon_read_sync(0x9fffcda4); /* 83800520 */
	radeon_read_sync(0x9fffcda8); /* 000002ee */
	radeon_write_sync(0x9fffcc00, 0x83800520);
	radeon_write_sync(0x9fffcc04, 0x000002ee);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800520 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800520 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800520 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800520 */
	radeon_write_sync(0x6268, 0x00002000);
	radeon_read_sync(0x9fffcc00); /* 83800520 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 000002ee */
	radeon_write_sync(0x6268, 0x0000ee00);
	radeon_read_sync(0x9fffcc04); /* 000002ee */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 000002ee */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000002ee */
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
	radeon_read_sync(0x9fffcdac); /* 8380051c */
	radeon_read_sync(0x9fffcdb0); /* 000007d0 */
	radeon_write_sync(0x9fffcc00, 0x8380051c);
	radeon_write_sync(0x9fffcc04, 0x000007d0);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 8380051c */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 8380051c */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 8380051c */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 8380051c */
	radeon_write_sync(0x6268, 0x00001c00);
	radeon_read_sync(0x9fffcc00); /* 8380051c */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 000007d0 */
	radeon_write_sync(0x6268, 0x0000d000);
	radeon_read_sync(0x9fffcc04); /* 000007d0 */
	radeon_write_sync(0x6268, 0x00000700);
	radeon_read_sync(0x9fffcc04); /* 000007d0 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 000007d0 */
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
	radeon_read_sync(0x9fffcdb4); /* 83800518 */
	radeon_read_sync(0x9fffcdb8); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83800518);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800518 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800518 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800518 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800518 */
	radeon_write_sync(0x6268, 0x00001800);
	radeon_read_sync(0x9fffcc00); /* 83800518 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcdbc); /* 50800513 */
	radeon_read_sync(0x9fffcdc0); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x50800513);
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 50800513 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00050000);
	radeon_read_sync(0x9fffcc00); /* 50800513 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 50800513 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 50800513 */
	radeon_write_sync(0x6268, 0x00001300);
	radeon_read_sync(0x9fffcc00); /* 50800513 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
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
	radeon_read_sync(0x9fffcdc4); /* 00000514 */
	radeon_read_sync(0x9fffcdc8); /* fffffff9 */
	radeon_read_sync(0x9fffcdc4); /* 00000514 */
	radeon_write_sync(0x9fffcc00, 0x43900514);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_read_sync(0x6254); /* 00050000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x80009000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
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
	radeon_write_sync(0x9fffcc04, 0x00010006);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_read_sync(0x9fffcdc4); /* 00000514 */
	radeon_read_sync(0x9fffcdc8); /* fffffff9 */
	radeon_read_sync(0x9fffcdcc); /* 00000006 */
	radeon_write_sync(0x9fffcc00, 0x83800514);
	radeon_write_sync(0x9fffcc04, 0x00010006);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000600);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
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
	radeon_read_sync(0x9fffcdd0); /* 83887038 */
	radeon_read_sync(0x9fffcdd4); /* 00000100 */
	radeon_write_sync(0x9fffcc00, 0x83887038);
	radeon_write_sync(0x9fffcc04, 0x00000100);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887038 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887038 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887038 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887038 */
	radeon_write_sync(0x6268, 0x00003800);
	radeon_read_sync(0x9fffcc00); /* 83887038 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000100 */
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
	radeon_read_sync(0x9fffcdd8); /* 00087030 */
	radeon_read_sync(0x9fffcddc); /* fffff0ff */
	radeon_read_sync(0x9fffcdd8); /* 00087030 */
	radeon_write_sync(0x9fffcc00, 0x43987030);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
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
	radeon_write_sync(0x9fffcc04, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
	radeon_read_sync(0x9fffcdd8); /* 00087030 */
	radeon_read_sync(0x9fffcddc); /* fffff0ff */
	radeon_read_sync(0x9fffcde0); /* 00000400 */
	radeon_write_sync(0x9fffcc00, 0x83887030);
	radeon_write_sync(0x9fffcc04, 0x00000400);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
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
	radeon_read_sync(0x9fffcde4); /* 00087030 */
	radeon_read_sync(0x9fffcde8); /* fdffffff */
	radeon_read_sync(0x9fffcde4); /* 00087030 */
	radeon_write_sync(0x9fffcc00, 0x43987030);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
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
	radeon_write_sync(0x9fffcc04, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 00000400 */
	radeon_read_sync(0x9fffcde4); /* 00087030 */
	radeon_read_sync(0x9fffcde8); /* fdffffff */
	radeon_read_sync(0x9fffcdec); /* 02000000 */
	radeon_write_sync(0x9fffcc00, 0x83887030);
	radeon_write_sync(0x9fffcc04, 0x02000400);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
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
	radeon_read_sync(0x9fffcdf0); /* 00087008 */
	radeon_read_sync(0x9fffcdf4); /* ffffffbf */
	radeon_read_sync(0x9fffcdf0); /* 00087008 */
	radeon_write_sync(0x9fffcc00, 0x43987008);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43987008 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43987008 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43987008 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 43987008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 43987008 */
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
	radeon_write_sync(0x9fffcc04, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000000 */
	radeon_read_sync(0x9fffcdf0); /* 00087008 */
	radeon_read_sync(0x9fffcdf4); /* ffffffbf */
	radeon_read_sync(0x9fffcdf8); /* 00000040 */
	radeon_write_sync(0x9fffcc00, 0x83887008);
	radeon_write_sync(0x9fffcc04, 0x00000040);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887008 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887008 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887008 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887008 */
	radeon_write_sync(0x6268, 0x00000800);
	radeon_read_sync(0x9fffcc00); /* 83887008 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000040 */
	radeon_write_sync(0x6268, 0x00004000);
	radeon_read_sync(0x9fffcc04); /* 00000040 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000040 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000040 */
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
	radeon_read_sync(0x9fffcdfc); /* 00000514 */
	radeon_read_sync(0x9fffce00); /* fffffffe */
	radeon_read_sync(0x9fffcdfc); /* 00000514 */
	radeon_write_sync(0x9fffcc00, 0x43900514);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x80009000);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 43900514 */
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
	radeon_write_sync(0x9fffcc04, 0x00010006);
	radeon_read_sync(0x9fffcc04); /* 00010006 */
	radeon_read_sync(0x9fffcdfc); /* 00000514 */
	radeon_read_sync(0x9fffce00); /* fffffffe */
	radeon_read_sync(0x9fffce04); /* 00000001 */
	radeon_write_sync(0x9fffcc00, 0x83800514);
	radeon_write_sync(0x9fffcc04, 0x00010007);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x80008000);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000500);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 83800514 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00010007 */
	radeon_write_sync(0x6268, 0x00000700);
	radeon_read_sync(0x9fffcc04); /* 00010007 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00010007 */
	radeon_write_sync(0x6268, 0x00000100);
	radeon_read_sync(0x9fffcc04); /* 00010007 */
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
	radeon_read_sync(0x9fffce08); /* 00087030 */
	radeon_read_sync(0x9fffce0c); /* fffffffe */
	radeon_read_sync(0x9fffce08); /* 00087030 */
	radeon_write_sync(0x9fffcc00, 0x43987030);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 43987030 */
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
	radeon_write_sync(0x9fffcc04, 0x02000400);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_read_sync(0x9fffce08); /* 00087030 */
	radeon_read_sync(0x9fffce0c); /* fffffffe */
	radeon_read_sync(0x9fffce10); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x83887030);
	radeon_write_sync(0x9fffcc04, 0x02000400);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00003000);
	radeon_read_sync(0x9fffcc00); /* 83887030 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000400);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 02000400 */
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
	radeon_read_sync(0x9fffce14); /* fffe01f4 */
	radeon_read_sync(0x9fffce18); /* 83887014 */
	radeon_delay(0x02c41bd6 - 0x02c3586e);
	radeon_delay(0x02c4f8f4 - 0x02c4353e);
	radeon_delay(0x02c5d5ae - 0x02c51244);
	radeon_delay(0x02c6b2c4 - 0x02c5eefc);
	radeon_delay(0x02c78f72 - 0x02c6cc18);
	radeon_read_sync(0x9fffce18); /* 83887014 */
	radeon_read_sync(0x9fffce1c); /* 00110002 */
	radeon_write_sync(0x9fffcc00, 0x83887014);
	radeon_write_sync(0x9fffcc04, 0x00110002);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83887014 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83887014 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83887014 */
	radeon_write_sync(0x6268, 0x00007000);
	radeon_read_sync(0x9fffcc00); /* 83887014 */
	radeon_write_sync(0x6268, 0x00001400);
	radeon_read_sync(0x9fffcc00); /* 83887014 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00110002 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00110002 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00110002 */
	radeon_write_sync(0x6268, 0x00001100);
	radeon_read_sync(0x9fffcc04); /* 00110002 */
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
	radeon_read_sync(0x9fffce20); /* 000850a8 */
	radeon_read_sync(0x9fffce24); /* fffeffff */
	radeon_read_sync(0x9fffce20); /* 000850a8 */
	radeon_write_sync(0x9fffcc00, 0x439850a8);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00040000);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x80009800);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_read_sync(0x9fffcc00); /* 439850a8 */
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
	radeon_write_sync(0x9fffcc04, 0x00011b19);
	radeon_read_sync(0x9fffcc04); /* 00011b19 */
	radeon_read_sync(0x9fffce20); /* 000850a8 */
	radeon_read_sync(0x9fffce24); /* fffeffff */
	radeon_read_sync(0x9fffce28); /* 00000000 */
	radeon_write_sync(0x9fffcc00, 0x838850a8);
	radeon_write_sync(0x9fffcc04, 0x00001b19);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 838850a8 */
	radeon_read_sync(0x6254); /* 00040000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 838850a8 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 838850a8 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 838850a8 */
	radeon_write_sync(0x6268, 0x0000a800);
	radeon_read_sync(0x9fffcc00); /* 838850a8 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00001b19 */
	radeon_write_sync(0x6268, 0x00001900);
	radeon_read_sync(0x9fffcc04); /* 00001b19 */
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_read_sync(0x9fffcc04); /* 00001b19 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00001b19 */
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
	radeon_read_sync(0x9fffce2c); /* 83885088 */
	radeon_read_sync(0x9fffce30); /* 00000019 */
	radeon_write_sync(0x9fffcc00, 0x83885088);
	radeon_write_sync(0x9fffcc04, 0x00000019);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83885088 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885088 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885088 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885088 */
	radeon_write_sync(0x6268, 0x00008800);
	radeon_read_sync(0x9fffcc00); /* 83885088 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00000019 */
	radeon_write_sync(0x6268, 0x00001900);
	radeon_read_sync(0x9fffcc04); /* 00000019 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000019 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00000019 */
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
	radeon_read_sync(0x9fffce34); /* 83885074 */
	radeon_read_sync(0x9fffce38); /* 00001b02 */
	radeon_write_sync(0x9fffcc00, 0x83885074);
	radeon_write_sync(0x9fffcc04, 0x00001b02);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6540); /* 0f410000 */
	radeon_write_sync(0x6540, 0x0f410000);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x6250); /* 21100101 */
	radeon_write_sync(0x6250, 0x21100101);
	radeon_read_sync(0x9fffcc00); /* 83885074 */
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x6254); /* 00080000 */
	radeon_write_sync(0x6254, 0x00080000);
	radeon_read_sync(0x9fffcc00); /* 83885074 */
	radeon_write_sync(0x6268, 0x80008800);
	radeon_read_sync(0x9fffcc00); /* 83885074 */
	radeon_write_sync(0x6268, 0x00005000);
	radeon_read_sync(0x9fffcc00); /* 83885074 */
	radeon_write_sync(0x6268, 0x00007400);
	radeon_read_sync(0x9fffcc00); /* 83885074 */
	radeon_write_sync(0x6268, 0x00000300);
	radeon_read_sync(0x9fffcc04); /* 00001b02 */
	radeon_write_sync(0x6268, 0x00000200);
	radeon_read_sync(0x9fffcc04); /* 00001b02 */
	radeon_write_sync(0x6268, 0x00001b00);
	radeon_read_sync(0x9fffcc04); /* 00001b02 */
	radeon_write_sync(0x6268, 0x00000000);
	radeon_read_sync(0x9fffcc04); /* 00001b02 */
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
	radeon_read_sync(0x9fffce3c); /* ffffffff */
	radeon_read_sync(0x9fffce40); /* 00000000 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x173c); /* 00000000 */
	radeon_write_sync(0x173c, 0x00001000);
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_write_sync(0x173c, 0x00001000);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa6b8); /* 00000013 */
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
	radeon_read_sync(0x9fff9e00); /* 00000001 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

void replay_int10_c2(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	radeon_read_sync(0x4054); /* 00000000 */
	radeon_read_sync(0x4010); /* e0000008 */
	radeon_read_sync(0x4010); /* e0000008 */
	radeon_write_sync(0x9fff9c80, 0x00000000);
	radeon_write_sync(0x9fff9c84, 0x00000000);
	radeon_write_sync(0x9fff9c88, 0x00000000);
	radeon_write_sync(0x9fff9c8c, 0x00000000);
	radeon_write_sync(0x9fff9c90, 0x00000000);
	radeon_write_sync(0x9fff9c94, 0x00000000);
	radeon_write_sync(0x9fff9c98, 0x00000000);
	radeon_write_sync(0x9fff9c9c, 0x00000000);
	radeon_write_sync(0x9fff9c88, 0x01170001);
	radeon_read_sync(0x9fff9c94); /* 00000000 */
	radeon_write_old(0x9fff9c94, 0x19640000);
	radeon_write_sync(0x9fff9c80, 0x03000400);
	radeon_write_sync(0x9fff9c84, 0x01010400);
	radeon_read_sync(0x9fff9c84); /* 01010400 */
	radeon_read_sync(0x9fff9c88); /* 01170001 */
	radeon_read_sync(0x9fff9c94); /* 19640000 */
	radeon_write_old(0x9fff9c94, 0x19640019);
	radeon_write_sync(0x9fff9c8c, 0x05060b05);
	radeon_write_sync(0x9fff9c90, 0x00000005);
	radeon_read_sync(0x9fff9c80); /* 03000400 */
	radeon_read_sync(0x9fff9c8c); /* 05060b05 */
	radeon_read_sync(0x9fff9c90); /* 00000005 */
	radeon_read_sync(0x9fff9c88); /* 01170001 */
	radeon_read_sync(0x9fff9c80); /* 03000400 */
	radeon_read_sync(0x9fff9c84); /* 01010400 */
	radeon_read_sync(0x9fff9c88); /* 01170001 */
	radeon_read_sync(0x9fff9c84); /* 01010400 */
	radeon_read_sync(0x9fff9c94); /* 19640019 */
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x1738); /* 00000000 */
	radeon_write_sync(0x1738, 0x0000000b);
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fff9c80); /* 03000400 */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa6b8); /* 00000013 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa580); /* 00000206 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_write_sync(0x9fffa54c, 0x05561dce);
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_write_sync(0x9fffa550, 0x030000c0);
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_write_sync(0x9fffa554, 0x00080030);
	radeon_read_sync(0x9fffa574); /* 0003000a */
	radeon_write_sync(0x9fffa558, 0x0003000a);
	radeon_read_sync(0x9fffa578); /* 01580001 */
	radeon_write_sync(0x9fffa55c, 0x01580001);
	radeon_read_sync(0x9fffa57c); /* 000000c1 */
	radeon_write_sync(0x9fffa560, 0x000000c1);
	radeon_read_sync(0x9fffa580); /* 00000206 */
	radeon_write_sync(0x9fffa564, 0x00000206);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

void replay_int10_c3(void)
{
	radeon_read_sync(0x0000); /* 9ffffffc */
	radeon_read_sync(0x4054); /* 00000000 */
	radeon_write_sync(0x9fff9c20, 0x00000000);
	radeon_write_sync(0x9fff9c24, 0x00000000);
	radeon_write_sync(0x9fff9c28, 0x00000000);
	radeon_write_sync(0x9fff9c2c, 0x00000000);
	radeon_write_sync(0x9fff9c30, 0x00000000);
	radeon_write_sync(0x9fff9c34, 0x00000000);
	radeon_write_sync(0x9fff9c38, 0x00000000);
	radeon_write_sync(0x9fff9c3c, 0x00000000);
	radeon_write_sync(0x9fff9c28, 0x41170001);
	radeon_read_sync(0x9fff9c34); /* 00000000 */
	radeon_write_old(0x9fff9c34, 0x19640000);
	radeon_write_sync(0x9fff9c20, 0x03000400);
	radeon_write_sync(0x9fff9c24, 0x01010400);
	radeon_read_sync(0x9fff9c24); /* 01010400 */
	radeon_read_sync(0x9fff9c28); /* 41170001 */
	radeon_read_sync(0x9fff9c34); /* 19640000 */
	radeon_write_old(0x9fff9c34, 0x19640019);
	radeon_write_sync(0x9fff9c2c, 0x05060b05);
	radeon_write_sync(0x9fff9c30, 0x00000005);
	radeon_read_sync(0x9fff9c28); /* 41170001 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x1738); /* 0000000b */
	radeon_read_sync(0x1724); /* 00040000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fff9c20); /* 03000400 */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa6b8); /* 00000013 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_read_sync(0x9fffa580); /* 00000206 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_read_sync(0x9fffa568); /* 05561dce */
	radeon_write_sync(0x9fffa54c, 0x05561dce);
	radeon_read_sync(0x9fffa56c); /* 030000c0 */
	radeon_write_sync(0x9fffa550, 0x030000c0);
	radeon_read_sync(0x9fffa570); /* 00080030 */
	radeon_write_sync(0x9fffa554, 0x00080030);
	radeon_read_sync(0x9fffa574); /* 0003000a */
	radeon_write_sync(0x9fffa558, 0x0003000a);
	radeon_read_sync(0x9fffa578); /* 01580001 */
	radeon_write_sync(0x9fffa55c, 0x01580001);
	radeon_read_sync(0x9fffa57c); /* 000000c1 */
	radeon_write_sync(0x9fffa560, 0x000000c1);
	radeon_read_sync(0x9fffa580); /* 00000206 */
	radeon_write_sync(0x9fffa564, 0x00000206);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_write_sync(0x1730, 0x00000000);
	radeon_read_sync(0x9fffa404); /* 00000000 */
	radeon_read_sync(0x9fffa404); /* 00000000 */
	radeon_write_sync(0x9fffa404, 0x00000000);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa6b8); /* 00000013 */
	radeon_read_sync(0x9fffa74c); /* 00000000 */
	radeon_write_sync(0x9fffa74c, 0x00000000);
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_write_sync(0x9fffa6d4, 0x00000000);
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa74c); /* 00000000 */
	radeon_write_sync(0x9fffa74c, 0x00000002);
	radeon_read_sync(0x9fffa404); /* 00000000 */
	radeon_read_sync(0x9fffa404); /* 00000000 */
	radeon_write_sync(0x9fffa404, 0x00000002);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_read_sync(0x9fffa73c); /* 00000000 */
	radeon_write_sync(0x9fffa73c, 0x0000000c);
	radeon_read_sync(0x9fffa54c); /* 05561dce */
	radeon_read_sync(0x9fffa700); /* 00000000 */
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_write_sync(0x9fffa404, 0x00000002);
	radeon_read_sync(0x9fffa54c); /* 05561dce */
	radeon_read_sync(0x9fffa54c); /* 05561dce */
	radeon_write_sync(0x9fffa700, 0x05561dce);
	radeon_read_sync(0x9fffa550); /* 030000c0 */
	radeon_write_sync(0x9fffa704, 0x030000c0);
	radeon_read_sync(0x9fffa554); /* 00080030 */
	radeon_write_sync(0x9fffa708, 0x00080030);
	radeon_read_sync(0x9fffa558); /* 0003000a */
	radeon_write_sync(0x9fffa70c, 0x0003000a);
	radeon_read_sync(0x9fffa55c); /* 01580001 */
	radeon_write_sync(0x9fffa710, 0x01580001);
	radeon_read_sync(0x9fffa560); /* 000000c1 */
	radeon_write_sync(0x9fffa714, 0x000000c1);
	radeon_read_sync(0x9fffa564); /* 00000206 */
	radeon_write_sync(0x9fffa718, 0x00000206);
	radeon_write_sync(0x9fffa6d8, 0x00013880);
	radeon_read_sync(0x9fff9c20); /* 03000400 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa704); /* 030000c0 */
	radeon_read_sync(0x9fffa704); /* 030000c0 */
	radeon_read_sync(0x9fffa708); /* 00080030 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x9fffa6d0); /* 00000000 */
	radeon_write_sync(0x9fffa6d0, 0x00000002);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa740); /* 00000000 */
	radeon_write_sync(0x9fffa740, 0x01000000);
	radeon_read_sync(0x9fffa6b4); /* 00000104 */
	radeon_read_sync(0x9fffa740); /* 01000000 */
	radeon_write_sync(0x9fffa740, 0x01010000);
	radeon_read_sync(0x9fffa740); /* 01010000 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa740); /* 01010000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 01010000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa740); /* 01010000 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa750); /* 00000000 */
	radeon_write_sync(0x9fffa750, 0x00006978);
	radeon_write_sync(0x9fffa754, 0x00006978);
	radeon_read_sync(0x9fffa740); /* 01010000 */
	radeon_write_sync(0x9fffa740, 0x01010100);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_read_sync(0x9fffa534); /* 00000000 */
	radeon_read_sync(0x9fffa748); /* 00000000 */
	radeon_write_sync(0x9fffa748, 0x00000001);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x172c); /* 0000ff00 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_write_sync(0x9fffa758, 0x00000000);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_write_sync(0x9fffa764, 0x00000000);
	radeon_write_sync(0x9fffa764, 0x0c4e0024);
	radeon_write_sync(0x9fffa768, 0x00000207);
	radeon_read_sync(0x9fffa74c); /* 00000002 */
	radeon_read_sync(0x9fffa6dc); /* 00000000 */
	radeon_write_sync(0x9fffa6dc, 0x00000002);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x1730); /* 00000000 */
	radeon_write_sync(0x1730, 0x00000002);
	radeon_read_sync(0x9fff9c28); /* 41170001 */
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
	radeon_read_sync(0x9fff9c20); /* 03000400 */
	radeon_read_sync(0x9fff9c20); /* 03000400 */
	radeon_write_sync(0x9fff9c00, 0x03000400);
	radeon_read_sync(0x9fff9c24); /* 01010400 */
	radeon_write_sync(0x9fff9c04, 0x01010400);
	radeon_read_sync(0x9fff9c28); /* 41170001 */
	radeon_write_sync(0x9fff9c08, 0x41170001);
	radeon_read_sync(0x9fff9c2c); /* 05060b05 */
	radeon_write_sync(0x9fff9c0c, 0x05060b05);
	radeon_read_sync(0x9fff9c30); /* 00000005 */
	radeon_write_sync(0x9fff9c10, 0x00000005);
	radeon_read_sync(0x9fff9c34); /* 19640019 */
	radeon_write_sync(0x9fff9c14, 0x19640019);
	radeon_read_sync(0x9fff9c38); /* 00000000 */
	radeon_write_sync(0x9fff9c18, 0x00000000);
	radeon_read_sync(0x9fff9c3c); /* 00000000 */
	radeon_write_sync(0x9fff9c1c, 0x00000000);
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_write_sync(0x9fff9c08, 0x41170001);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa804); /* 00000000 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa004); /* 00000000 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	vga_sr_read(0x01); /* 01 */
	outb(0x21, 0x03c5);
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x6e74); /* 00000001 */
	radeon_write_sync(0x6e74, 0x00000001);
	radeon_read_sync(0x6e74); /* 00000001 */
	radeon_write_sync(0x6e74, 0x00000101);
	radeon_read_sync(0x6e70); /* 00400310 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x9fffa6d8); /* 00013880 */
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
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
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
	radeon_read_sync(0x9fffa74c); /* 00000002 */
	radeon_read_sync(0x9fffa6d8); /* 00013880 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa764); /* 0c4e0024 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x611c); /* 00000002 */
	radeon_write_sync(0x9fffa6e4, 0x00020f58);
	radeon_write_sync(0x9fffa6e8, 0x0201001b);
	radeon_write_sync(0x9fffa6ec, 0x00000000);
	radeon_read_sync(0x9fffa768); /* 00000207 */
	radeon_read_sync(0x9fffa76c); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa704); /* 030000c0 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
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
	radeon_read_sync(0x9fffa74c); /* 00000002 */
	radeon_read_sync(0x9fffa768); /* 00000207 */
	radeon_read_sync(0x9fffa76c); /* 00000000 */
	radeon_read_sync(0x9fffa768); /* 00000207 */
	radeon_read_sync(0x9fffa76c); /* 00000000 */
	radeon_read_sync(0x5c10); /* 00000000 */
	radeon_write_sync(0x5c10, 0x00000000);
	radeon_read_sync(0x5c14); /* 00000000 */
	radeon_read_sync(0x5c14); /* 00000000 */
	radeon_write_sync(0x5c14, 0x00000000);
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa704); /* 030000c0 */
	radeon_read_sync(0x9fffa704); /* 030000c0 */
	radeon_read_sync(0x9fffa708); /* 00080030 */
	radeon_read_sync(0x9fffa708); /* 00080030 */
	radeon_read_sync(0x9fffa70c); /* 0003000a */
	radeon_read_sync(0x9fffa70c); /* 0003000a */
	radeon_read_sync(0x9fffa710); /* 01580001 */
	radeon_read_sync(0x9fffa714); /* 000000c1 */
	radeon_read_sync(0x9fffa718); /* 00000206 */
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
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x9fffa6d0); /* 00000002 */
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
	radeon_read_sync(0x9fff9c00); /* 03000400 */
	radeon_read_sync(0x9fff9c04); /* 01010400 */
	radeon_read_sync(0x9fff9c08); /* 41170001 */
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
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_read_sync(0x9fff9c0c); /* 05060b05 */
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
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fff9c00); /* 03000400 */
	radeon_read_sync(0x9fff9c04); /* 01010400 */
	radeon_read_sync(0x9fff9c08); /* 41170001 */
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
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_read_sync(0x9fff9c0c); /* 05060b05 */
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
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_read_sync(0x9fff9c0c); /* 05060b05 */
	radeon_read_sync(0x9fff9c14); /* 19640019 */
	radeon_read_sync(0x0310); /* 00000000 */
	radeon_read_sync(0x0324); /* 0000000f */
	radeon_read_sync(0x9fff9700); /* 00000000 */
	radeon_write_sync(0x9fff9700, 0x00000000);
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
	radeon_read_sync(0x9fff9c08); /* 41170001 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x173c); /* 00001000 */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa748); /* 00000001 */
	radeon_read_sync(0x12354); /* 0101ff10 */
	radeon_write_sync(0x12354, 0x0101ff10);
	radeon_read_sync(0x12378); /* 00000000 */
	radeon_write_sync(0x12378, 0x00000001);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x9fffa74c); /* 00000002 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa73c); /* 0000000c */
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
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_write_sync(0x9fffa7ac, 0x00000000);
	radeon_write_sync(0x9fffa7b0, 0x00000000);
	radeon_write_sync(0x9fffa7b4, 0x00000000);
	radeon_write_sync(0x9fffa7b8, 0x00000000);
	radeon_write_sync(0x9fffa7bc, 0x00000000);
	radeon_write_sync(0x9fffa7c0, 0x00000000);
	radeon_write_sync(0x9fffa7c4, 0x00000000);
	radeon_write_sync(0x9fffa7c8, 0x00000000);
	radeon_write_sync(0x9fffa7cc, 0x00000000);
	radeon_write_sync(0x9fffa7d0, 0x00000000);
	radeon_write_sync(0x9fffa7d4, 0x00000000);
	radeon_write_sync(0x9fffa7d8, 0x00000000);
	radeon_write_sync(0x9fffa7dc, 0x00000000);
	radeon_write_sync(0x9fffa7e0, 0x00000000);
	radeon_write_sync(0x9fffa7e4, 0x00000000);
	radeon_write_sync(0x9fffa7e8, 0x00000000);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000001);
	radeon_write_sync(0x9fffbe00, 0x50800600);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 50800600 */
	radeon_read_sync(0x6204); /* 00070000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50800600 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 50800600 */
	radeon_write_sync(0x6218, 0x00000600);
	radeon_read_sync(0x9fffbe00); /* 50800600 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 50800600 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x12300); /* 00000000 */
	radeon_write_sync(0x12300, 0x00000000);
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x0000810a);
	radeon_write_sync(0x9fffbe00, 0x61800100);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 61800100 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00060000);
	radeon_read_sync(0x9fffbe00); /* 61800100 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 61800100 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 61800100 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 61800100 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe04); /* 0000810a */
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_read_sync(0x9fffbe04); /* 0000810a */
	radeon_write_sync(0x6218, 0x00008100);
	radeon_read_sync(0x9fffbe04); /* 0000810a */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 0000810a */
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
	radeon_read_sync(0x9fffa764); /* 0c4e0024 */
	radeon_read_sync(0x9fffa7bc); /* 00000000 */
	radeon_write_sync(0x9fffa7bc, 0x00000010);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x0c4e0010);
	radeon_write_sync(0x9fffbe00, 0x50800107);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 50800107 */
	radeon_read_sync(0x6204); /* 00060000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50800107 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 50800107 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 50800107 */
	radeon_write_sync(0x6218, 0x00000700);
	radeon_read_sync(0x9fffbe00); /* 50800107 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 0c4e0010 */
	radeon_write_sync(0x6218, 0x00001000);
	radeon_read_sync(0x9fffbe04); /* 0c4e0010 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 0c4e0010 */
	radeon_write_sync(0x6218, 0x00004e00);
	radeon_read_sync(0x9fffbe04); /* 0c4e0010 */
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
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa748); /* 00000001 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000001);
	radeon_write_sync(0x9fffbe00, 0x5080010a);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 5080010a */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 5080010a */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 5080010a */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 5080010a */
	radeon_write_sync(0x6218, 0x00000a00);
	radeon_read_sync(0x9fffbe00); /* 5080010a */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x12344); /* 00000000 */
	radeon_write_sync(0x12344, 0x00000000);
	radeon_write_sync(0x9fffa7b0, 0x00000000);
	radeon_write_sync(0x9fffa7b8, 0x00000000);
	radeon_read_sync(0x9fffa7b8); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_write_sync(0x9fffa75c, 0x00000000);
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa75c); /* 00000000 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa758); /* 00000000 */
	radeon_read_sync(0x9fffa74c); /* 00000002 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa73c); /* 0000000c */
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
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000001);
	radeon_write_sync(0x9fffbe00, 0x50800102);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000001 */
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
	radeon_read_sync(0x9fffa7ac); /* 00000000 */
	radeon_write_sync(0x9fffa7ac, 0x00000002);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa7b8); /* 00000000 */
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x83800103);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
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
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_read_sync(0x9fffa534); /* 00000000 */
	radeon_read_sync(0x9fffa7ac); /* 00000002 */
	radeon_delay(0x032cf836 - 0x032ce4a8);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000002);
	radeon_write_sync(0x9fffbe00, 0x45900202);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
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
	radeon_write_sync(0x9fffa7c0, 0x00800001);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_write_sync(0x9fffa7c4, 0x1f640000);
	radeon_read_sync(0x9fffa7ac); /* 00000002 */
	radeon_write_sync(0x9fffa7ac, 0x00000003);
	radeon_read_sync(0x9fffa7c0); /* 00800001 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa7ac); /* 00000003 */
	radeon_write_sync(0x9fffa7b0, 0x00000000);
	radeon_read_sync(0x9fffa528); /* 41810a01 */
	radeon_read_sync(0x9fffa52c); /* 80010000 */
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x12344); /* 00000000 */
	radeon_write_sync(0x12344, 0x00000001);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000002);
	radeon_write_sync(0x9fffbe00, 0x50800102);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000002 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe04); /* 00000002 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000002 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000002 */
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
	radeon_read_sync(0x9fffa7ac); /* 00000003 */
	radeon_write_sync(0x9fffa7ac, 0x00000004);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_read_sync(0x9fffa7b8); /* 00000000 */
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x83800103);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00080000);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffbe00); /* 83800103 */
	radeon_write_sync(0x6218, 0x00000300);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
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
	radeon_read_sync(0x9fffa530); /* 00000108 */
	radeon_read_sync(0x9fffa534); /* 00000000 */
	radeon_read_sync(0x9fffa7ac); /* 00000004 */
	radeon_delay(0x03367dde - 0x03362f60);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000004);
	radeon_write_sync(0x9fffbe00, 0x45900202);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_read_sync(0x6204); /* 00080000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
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
	radeon_write_sync(0x9fffa7c0, 0x01810007);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_write_sync(0x9fffa7c4, 0x1f640000);
	radeon_read_sync(0x9fffa7ac); /* 00000004 */
	radeon_write_sync(0x9fffa7ac, 0x00000005);
	radeon_read_sync(0x9fffa7c0); /* 01810007 */
	radeon_read_sync(0x9fffa7c0); /* 01810007 */
	radeon_read_sync(0x9fffa7c4); /* 1f640000 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa7ac); /* 00000005 */
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x50800102);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00050000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x80008000);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 50800102 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe04); /* 00000000 */
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
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x12300); /* 00000000 */
	radeon_write_sync(0x12300, 0x00000010);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x00000000);
	radeon_write_sync(0x9fffbe00, 0x42900100);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 42900100 */
	radeon_read_sync(0x6204); /* 00050000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 42900100 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 42900100 */
	radeon_write_sync(0x6218, 0x00000100);
	radeon_read_sync(0x9fffbe00); /* 42900100 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 42900100 */
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
	radeon_write_sync(0x9fffa7b4, 0x0100810a);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x01000000);
	radeon_write_sync(0x9fffbe00, 0x45900202);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
	radeon_write_sync(0x6218, 0x00000200);
	radeon_read_sync(0x9fffbe00); /* 45900202 */
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
	radeon_write_sync(0x9fffa7c0, 0x01010007);
	radeon_read_sync(0x6218); /* 00050001 */
	radeon_read_sync(0x6218); /* 00060001 */
	radeon_read_sync(0x6218); /* 00076401 */
	radeon_read_sync(0x6218); /* 00081f01 */
	radeon_write_sync(0x9fffa7c4, 0x1f640000);
	radeon_read_sync(0x9fffa410); /* 00000190 */
	radeon_write_sync(0x9fffbe04, 0x1f640000);
	radeon_write_sync(0x9fffbe00, 0x40900600);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6530); /* 0f410000 */
	radeon_write_sync(0x6530, 0x0f410000);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x6200); /* 21000101 */
	radeon_write_sync(0x6200, 0x21000101);
	radeon_read_sync(0x9fffbe00); /* 40900600 */
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x6204); /* 00040000 */
	radeon_write_sync(0x6204, 0x00040000);
	radeon_read_sync(0x9fffbe00); /* 40900600 */
	radeon_write_sync(0x6218, 0x80009000);
	radeon_read_sync(0x9fffbe00); /* 40900600 */
	radeon_write_sync(0x6218, 0x00000600);
	radeon_read_sync(0x9fffbe00); /* 40900600 */
	radeon_write_sync(0x6218, 0x00000000);
	radeon_read_sync(0x9fffbe00); /* 40900600 */
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
	radeon_write_sync(0x9fffa7c8, 0x01010001);
	radeon_read_sync(0x9fffa7c8); /* 01010001 */
	radeon_read_sync(0x9fffa7c0); /* 01010007 */
	radeon_read_sync(0x9fffa7c4); /* 1f640000 */
	radeon_read_sync(0x9fffa7c0); /* 01010007 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa744); /* 00000000 */
	radeon_read_sync(0x9fffa7ac); /* 00000005 */
	radeon_read_sync(0x9fffa7b0); /* 00000000 */
	radeon_write_sync(0x9fffa7ae, 0x00010000);
	radeon_read_sync(0x9fffa73c); /* 0000000c */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x12324); /* 00000000 */
	radeon_write_sync(0x12324, 0x00000100);
	radeon_delay(0x03461076 - 0x03460e48);
	radeon_read_sync(0x12310); /* 00000000 */
	radeon_write_sync(0x12310, 0x00000000);
	radeon_delay(0x03462540 - 0x0346231c);
	radeon_read_sync(0x1230c); /* 00100200 */
	radeon_write_sync(0x1230c, 0x00100201);
	radeon_delay(0x03465fa0 - 0x0346387a);
	radeon_read_sync(0x9fffa40c); /* 0000310e */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa414); /* 22232121 */
	radeon_read_sync(0x9fffa418); /* 00000000 */
	radeon_read_sync(0x9fffa754); /* 00006978 */
	radeon_read_sync(0x9fffa740); /* 01010100 */
	radeon_read_sync(0x9fffa750); /* 00006978 */
	radeon_read_sync(0x9fffa700); /* 05561dce */
	radeon_read_sync(0x6464); /* 00000000 */
	radeon_write_sync(0x6464, 0x03000000);
	radeon_read_sync(0x9fffa404); /* 00000002 */
	radeon_write_sync(0x9fffa404, 0x00000001);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x1730); /* 00000002 */
	vga_sr_read(0x01); /* 21 */
	outb(0x01, 0x03c5);
	radeon_read_sync(0x9fffa6d4); /* 00000000 */
	radeon_read_sync(0x6e74); /* 00000101 */
	radeon_write_sync(0x6e74, 0x00000101);
	radeon_read_sync(0x6e74); /* 00000101 */
	radeon_write_sync(0x6e74, 0x00000001);
	radeon_read_sync(0x9fffa408); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa808); /* 00000008 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_read_sync(0x1730); /* 00000002 */
	radeon_read_sync(0x9fffa008); /* 00000001 */
	radeon_write_sync(0x0000, 0x9ffffffc);
}

