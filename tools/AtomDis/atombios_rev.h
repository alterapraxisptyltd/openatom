/*
 * Reverse engineered AtomBIOS entries.
 * Plus addon information for dynamic data tables.
 */

#include <endian.h>

#if __BYTE_ORDER == __LITTLE_ENDIAN
#define ATOM_BIG_ENDIAN 0
#define ATOM_LITTLE_ENDIAN 1
#elif __BYTE_ORDER == __BIG_ENDIAN
#define ATOM_BIG_ENDIAN 1
#define ATOM_LITTLE_ENDIAN 0
#endif

/*
 * Dynamic data tables:
 * Modify table sizes and offset positions by replacing access code
 * (e.g. &d->asPowerUnknownInfo[i]) by custom code.
 * d is the current data structure, data as a char *,
 * start the main data structure as char *, i is counter.
 *
 * #pragma count  ATOM_POWERPLAY_INFO_V4 asPowerIndexInfo   (d->NumPowerIndexEntries)
 * #pragma offset ATOM_POWERPLAY_INFO_V4 asPowerIndexInfo   (data + d->OffsetPowerIndexEntries + i*d->SizeOfPowerIndexEntry)
 * #pragma return ATOM_POWERPLAY_INFO_V4 -                  (d->OffsetPowerUnknownEntries + ATOM_MAX_NUMBEROF_POWERUNKNOWN_BLOCK_V4*d->SizeOfPowerUnknownEntry)
 *
 * Has to be issued *before* the offset is encountered. And outside structures.
 */

typedef struct
{
    unsigned char u[2];
} U16;
#define _U16(x) (((x).u[1]<<8)|(x).u[0])

typedef struct
{
    unsigned char u[3];
} U24;
#define _U24(x) (((x).u[2]<<16)|((x).u[1]<<8)|(x).u[0])

#include <stddef.h> /* offsetof() */
#define COUNT_REMAINDER(s,m,e) ((((ATOM_COMMON_TABLE_HEADER*)d)->usStructureSize-offsetof(s,m)) / sizeof(e))
#define RETURN_REMAINDER(s,m,e) (d ? (offsetof(s,m) + COUNT_REMAINDER(s,m,e) * sizeof(e)) : 0)
#define COUNT_ALL(s,e) ((((ATOM_COMMON_TABLE_HEADER*)d)->usStructureSize-sizeof(ATOM_COMMON_TABLE_HEADER)) / sizeof(e))
#define RETURN_ALL(s,e) (d ? (sizeof(ATOM_COMMON_TABLE_HEADER) + COUNT_ALL(s,e) * sizeof(e)) : 0)


/*
 * Dynamic additions to generic atombios.h
 */
#pragma count  ATOM_GPIO_I2C_INFO            asGPIO_Info               COUNT_ALL  (ATOM_GPIO_I2C_INFO, ATOM_GPIO_I2C_ASSIGMENT)
#pragma return ATOM_GPIO_I2C_INFO            asGPIO_Info               RETURN_ALL (ATOM_GPIO_I2C_INFO, ATOM_GPIO_I2C_ASSIGMENT)

#pragma count  ATOM_GPIO_PIN_LUT             asGPIO_Pin                COUNT_ALL  (ATOM_GPIO_PIN_LUT,  ATOM_GPIO_PIN_ASSIGNMENT)
#pragma return ATOM_GPIO_PIN_LUT             asGPIO_Pin                RETURN_ALL (ATOM_GPIO_PIN_LUT,  ATOM_GPIO_PIN_ASSIGNMENT)

#pragma count  ATOM_VESA_TO_INTENAL_MODE_LUT asVESA_ToExtendedModeInfo COUNT_ALL  (ATOM_VESA_TO_INTENAL_MODE_LUT, ATOM_VESA_TO_EXTENDED_MODE)
#pragma return ATOM_VESA_TO_INTENAL_MODE_LUT asVESA_ToExtendedModeInfo RETURN_ALL (ATOM_VESA_TO_INTENAL_MODE_LUT, ATOM_VESA_TO_EXTENDED_MODE)

#pragma count  ATOM_COMPONENT_VIDEO_INFO     aWbGpioStateBlock         (d->ucNumOfWbGpioBlocks)
#pragma count  ATOM_COMPONENT_VIDEO_INFO     aModeTimings              COUNT_REMAINDER  (ATOM_COMPONENT_VIDEO_INFO,     aModeTimings[0], ATOM_DTD_FORMAT)
#pragma return ATOM_COMPONENT_VIDEO_INFO     -                         RETURN_REMAINDER (ATOM_COMPONENT_VIDEO_INFO,     aModeTimings[0], ATOM_DTD_FORMAT)
#pragma count  ATOM_COMPONENT_VIDEO_INFO_V21 aWbGpioStateBlock         (d->ucNumOfWbGpioBlocks)
#pragma count  ATOM_COMPONENT_VIDEO_INFO_V21 aModeTimings              COUNT_REMAINDER  (ATOM_COMPONENT_VIDEO_INFO_V21, aModeTimings[0], ATOM_DTD_FORMAT)
#pragma return ATOM_COMPONENT_VIDEO_INFO_V21 -                         RETURN_REMAINDER (ATOM_COMPONENT_VIDEO_INFO_V21, aModeTimings[0], ATOM_DTD_FORMAT)

#pragma count  INDIRECT_IO_ACCESS            IOAccessSequence          -1 /* No useful information */
#pragma return INDIRECT_IO_ACCESS            IOAccessSequence          RETURN_ALL (ATOM_INDIRECT_IO_ACCESS, UCHAR)

#pragma offset ATOM_VRAM_INFO_V3             aVramInfo                *(offset_ATOM_VRAM_INFO_V3_aVramInfo(d,i))
#pragma count  ATOM_VRAM_INFO_V3             aVramInfo                (count_ATOM_VRAM_INFO_V3_aVramInfo(d))
#pragma offset ATOM_VRAM_INFO_V3             asMemPatch               *(data + d->usMemClkPatchTblOffset)
// Needs more love
#pragma return ATOM_VRAM_INFO_V3             -                        0

// Doesn't look completely reasonable, but seems ok...
#pragma count  ATOM_ASIC_PROFILE_VOLTAGE     asLeakVol                ((d->usSize - offsetof(ATOM_ASIC_PROFILE_VOLTAGE,asLeakVol)) / sizeof(ATOM_LEAKID_VOLTAGE))

#pragma count  ATOM_VOLTAGE_FORMULA          ucVIDAdjustEntries       (d->ucNumOfVoltageEntries)
#pragma offset ATOM_VOLTAGE_OBJECT_INFO      asVoltageObj             *(offset_ATOM_VOLTAGE_OBJECT_INFO_asVoltageObj(d,i))
#pragma count  ATOM_VOLTAGE_OBJECT_INFO      asVoltageObj             (count_ATOM_VOLTAGE_OBJECT_INFO_asVoltageObj(d))
#pragma return ATOM_VOLTAGE_OBJECT_INFO      -                        0

#pragma count  ATOM_POWER_SOURCE_INFO        asPwrObj                 COUNT_REMAINDER  (ATOM_POWER_SOURCE_INFO, asPwrObj[0], ATOM_POWER_SOURCE_OBJECT)
#pragma return ATOM_POWER_SOURCE_INFO        -                        RETURN_REMAINDER (ATOM_POWER_SOURCE_INFO, asPwrObj[0], ATOM_POWER_SOURCE_OBJECT)

/*
 * Generic atombios.h
 */
#include "atombios.h"

static inline char *offset_ATOM_VRAM_INFO_V3_aVramInfo(ATOM_VRAM_INFO_V3 *d, int i) {
    char *r = (char *)&d->aVramInfo[0];
    while (i-- > 0)
	r += ((ATOM_VRAM_MODULE_V3 *)r)->usSize;
    return r;
}
static inline int count_ATOM_VRAM_INFO_V3_aVramInfo(ATOM_VRAM_INFO_V3 *d) {
    int i=0;
    char *last = 0, *next;
    while ( (next = offset_ATOM_VRAM_INFO_V3_aVramInfo(d,i)) - (char*)d < d->usMemAdjustTblOffset && next != last) {
	last = next;
	i++;
    }
    return i;
}
static inline char *offset_ATOM_VOLTAGE_OBJECT_INFO_asVoltageObj(ATOM_VOLTAGE_OBJECT_INFO *d, int i) {
    char *r = (char *)&d->asVoltageObj[0];
    while (i-- > 0)
	r += ((ATOM_VOLTAGE_OBJECT *)r)->ucSize;
    return r;
}
static inline int count_ATOM_VOLTAGE_OBJECT_INFO_asVoltageObj(ATOM_VOLTAGE_OBJECT_INFO *d) {
    int i=0;
    char *last=0, *next;
    while ( (next = offset_ATOM_VOLTAGE_OBJECT_INFO_asVoltageObj(d,i)) - (char*)d < d->sHeader.usStructureSize && next != last) {
	last = next;
	i++;
    }
    return i;
}


/*
 * Reverse engineered tables
 */

