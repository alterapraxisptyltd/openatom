/*
 * This file is part of the coreboot project.
 *
 * Copyright (C) 2014 Edward O'Callaghan <eocallaghan@alterapraxis.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston,
 * MA 02110-1301 USA
 */

#include <stdint.h>
#include <delay.h>
#include <edid.h>
#include <stdlib.h>
#include <string.h>
#include <arch/io.h>

#include <boot/coreboot_tables.h>
#include <console/console.h>
#include <device/device.h>
#include <device/pci.h>
#include <device/pci_ids.h>
#include <device/pci_ops.h>
#include <pc80/vga.h>
#include <pc80/vga_io.h>

#include "atombios.h"
#include "atombios_cmd.h"

static void radeon_init(struct device *dev)
{
	int bar;
	u32 addr;

	/* find lfb pci bar */
	addr = pci_read_config32(dev, PCI_BASE_ADDRESS_0);

	printk(BIOS_DEBUG, "ATOMBIOS: framebuffer @ %x (pci bar %d)\n",
	       addr, bar);

  ATOM_ROM_HEADER rom_header;

  //rom_header.sHeader.usStructureSize = sizeof(ATOM_ROM_HEADER);
  rom_header.iaFirmWareSignature = "ATOM";
  rom_header.usIoBaseAddress = addr;
  rom_header.usSubsystemVendorID = dev->subsystem_vendor;
  rom_header.usSubsystemID = dev->subsystem_device;
}

static struct device_operations ati_radeon_ops = {
	.read_resources	  = pci_dev_read_resources,
	.set_resources	  = pci_dev_set_resources,
	.enable_resources = pci_dev_enable_resources,
	.init		  = radeon_init,
	.scan_bus	  = 0,
};

static const struct pci_driver ati_richland_driver __pci_driver = {
	.ops	  = &ati_radeon_ops,
	.vendor = 0x1002, /* ATi */
	.device = 0x990b, /* Richland */
};
