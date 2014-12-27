#include "atomfake.h"

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

static void* get_atom_base()
{
	int fd;
	void *atom_base;

	fd = open("/dev/mem", O_RDWR | O_SYNC);

	if (fd == -1) {
		fprintf(stderr, "No /dev/mem ? %s\n", strerror(errno));
		return NULL;
	}

	atom_base = mmap(0, 0x20000, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0xa0000);
	if (atom_base == MAP_FAILED) {
		fprintf(stderr, "mmap() failed %s\n", strerror(errno));
		return NULL;
	}

	return atom_base;
}
#if 0

static void *generate_header(void *base)
{
	u_int8_t *ptr;
	struct vbt_header *head = vbt;
	struct bdb_header *bdb_head;
	struct bdb_general_features *genfeat;
	u8 *ptr;

	*ptr++ = 0x55;
	*ptr++ = 0xaa;

	memset (head, 0, sizeof (*head));

	memcpy (head->signature, idstr, 20);
	head->version = 100;
	head->header_size = sizeof (*head);
	head->bdb_offset = sizeof (*head);

	bdb_head = (struct bdb_header *) (head + 1);
	memset (bdb_head, 0, sizeof (*bdb_head));
	memcpy (bdb_head->signature, "BIOS_DATA_BLOCK ", 16);
	bdb_head->version = 0xa8;
	bdb_head->header_size = sizeof (*bdb_head);

	ptr = (u8 *) (bdb_head + 1);

	ptr[0] = BDB_GENERAL_FEATURES;
	ptr[1] = sizeof (*genfeat);
	ptr[2] = sizeof (*genfeat) >> 8;
	ptr += 3;

	genfeat = (struct bdb_general_features *) ptr;
	memset (genfeat, 0, sizeof (*genfeat));
	genfeat->panel_fitting = 3;
	genfeat->flexaim = 1;
	genfeat->download_ext_vbt = 1;
	genfeat->enable_ssc = conf->use_spread_spectrum_clock;
	genfeat->ssc_freq = !conf->link_frequency_270_mhz;
	genfeat->rsvd10 = 0x4;
	genfeat->legacy_monitor_detect = 1;
	genfeat->int_crt_support = 1;
	genfeat->dp_ssc_enb = 1;

	ptr += sizeof (*genfeat);

	bdb_head->bdb_size = ptr - (u8 *)bdb_head;
	head->vbt_size = ptr - (u8 *)head;
	head->vbt_checksum = 0;
	return ptr - (u8 *)head;
}

void
generate_fake_intel_oprom(const struct i915_gpu_controller_info *conf,
			  struct device *dev, const char *idstr)
{
	optionrom_header_t *oh = (void *)PCI_VGA_RAM_IMAGE_START;
	optionrom_pcir_t *pcir;
	size_t vbt_size;
	size_t fake_oprom_size;

	memset(oh, 0, 8192);

	oh->signature = PCI_ROM_HDR;
	oh->pcir_offset = 0x40;
	oh->vbt_offset = 0x80;

	pcir = (void *)(PCI_VGA_RAM_IMAGE_START + 0x40);
	pcir->signature = 0x52494350;	// PCIR
	pcir->vendor = dev->vendor;
	pcir->device = dev->device;
	pcir->length = sizeof(*pcir);
	pcir->revision = dev->class;
	pcir->classcode[0] = dev->class >> 8;
	pcir->classcode[1] = dev->class >> 16;
	pcir->classcode[2] = dev->class >> 24;
	pcir->indicator = 0x80;

	vbt_size = generate_vbt (conf, (void *)(PCI_VGA_RAM_IMAGE_START + 0x80), idstr);
	fake_oprom_size = (0x80 + vbt_size + 511) / 512;
	oh->size = fake_oprom_size;
	pcir->imagelength = fake_oprom_size;

}
#endif

void atomfake_insert_table(void)
{
	void *base;
	int subsystem_vendor, subsystem_device; // XXX set these to your card..

	base = get_atom_base();

	ATOM_ROM_HEADER *rom_header = base + OFFSET_TO_POINTER_TO_ATOM_ROM_HEADER;
	memset (rom_header, 0, sizeof (*rom_header)); // zero out structure

	ATOM_COMMON_TABLE_HEADER *sheader = rom_header; // sHeader is the first member of rom_header struct which is aligned
	memset (sheader, 0, sizeof (*sheader)); // zero out structure
	/* Fill in ATOM_COMMON_TABLE_HEADER */
	sheader->usStructureSize = sizeof(ATOM_ROM_HEADER);

	/* Fill in ATOM_ROM_HEADER structure */
	memcpy (rom_header->sHeader, sheader, sizeof(ATOM_COMMON_TABLE_HEADER));
	memcpy (rom_header->uaFirmWareSignature, "ATOM", 4);
	rom_header->usIoBaseAddress = (unsigned short) base;
	rom_header->usSubsystemVendorID = subsystem_vendor;
	rom_header->usSubsystemID = subsystem_device;
}
