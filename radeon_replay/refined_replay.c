#include "radeon_init_native.h"
#include "radeon_util.h"

#include <stdio.h>

uint16_t get_uniphy_reg_offset(uint8_t huge, uint8_t tits)
{
	/*
	 * big = par[0] >> 6
	 * small = par[0] & 0x7
	 */
	static const uint16_t really[3][6] = {
		{ 0x0000, 0x0300, 0x2600, 0x2900, 0x2c00, 0x2f00 },  /* 0x00 */
		{ 0x0000, 0x0002, 0x002c, 0x002d, 0x002e, 0x002f },  /* 0x40 */
		{ 0x0000, 0x0001, 0x0007, 0x0008, 0x000b, 0x000c }}; /* 0x80 */

	return really[huge][tits];
}



