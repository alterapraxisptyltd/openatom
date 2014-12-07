/*
 * Copyright 2007 Matthias Hopf <mhopf@suse.de>
 *
 * AtomBIOS disassembler + data structure dumper
 *
 * indices.c:
 * Symbol indices creation + access functions.
 *
 * License: GPL Version 2.0
 */

#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>

#include "indices.h"
#include "atombios_consts.h"


const char *index_command_table[] = {
    "ASIC_Init", "GetDisplaySurfaceSize", "ASIC_RegistersInit",
    "VRAM_BlockVenderDetection", "SetClocksRatio/DIGxEncoderControl", "MemoryControllerInit",
    "EnableCRTCMemReq", "MemoryParamAdjust", "DVOEncoderControl",
    "GPIOPinControl", "SetEngineClock", "SetMemoryClock",
    "SetPixelClock", "DynamicClockGating", "ResetMemoryDLL",
    "ResetMemoryDevice", "MemoryPLLInit", "AdjustDisplayPll",
    "AdjustMemoryController", "EnableASIC_StaticPwrMgt", "ASIC_StaticPwrMgtStatusChange/SetUniphyInstance",
    "DAC_LoadDetection", "LVTMAEncoderControl", "LCD1OutputControl",
    "DAC1EncoderControl", "DAC2EncoderControl", "DVOOutputControl",
    "CV1OutputControl", "GetConditionalGoldenSetting/SetCRTC_DPM_State", "TVEncoderControl",
    "TMDSAEncoderControl", "LVDSEncoderControl", "TV1OutputControl",
    "EnableScaler", "BlankCRTC", "EnableCRTC",
    "GetPixelClock", "EnableVGA_Render", "EnableVGA_Access/GetSCLKOverMCLKRatio",
    "SetCRTC_Timing", "SetCRTC_OverScan", "SetCRTC_Replication",
    "SelectCRTC_Source", "EnableGraphSurfaces", "UpdateCRTC_DoubleBufferRegisters",
    "LUT_AutoFill", "EnableHW_IconCursor", "GetMemoryClock",
    "GetEngineClock", "SetCRTC_UsingDTDTiming", "ExternalEncoderControl",
    "LVTMAOutputControl", "VRAM_BlockDetectionByStrap", "MemoryCleanUp",
    "ReadEDIDFromHWAssistedI2C/ProcessI2cChannelTransaction",
    "WriteOneByteToHWAssistedI2C", "ReadHWAssistedI2CStatus/HPDInterruptService",
    "SpeedFanControl", "PowerConnectorDetection", "MC_Synchronization",
    "ComputeMemoryEnginePLL", "MemoryRefreshConversion", "VRAM_GetCurrentInfoBlock",
    "DynamicMemorySettings", "MemoryTraining", "EnableSpreadSpectrumOnPPLL",
    "TMDSAOutputControl", "SetVoltage", "DAC1OutputControl",
    "DAC2OutputControl", "SetupHWAssistedI2CStatus", "ClockSource",
    "MemoryDeviceInit", "EnableYUV", "DIG1EncoderControl",
    "DIG2EncoderControl", "DIG1TransmitterControl/UNIPHYTransmitterControl",
    "DIG2TransmitterControl/LVTMATransmitterControl",
    "ProcessAuxChannelTransaction", "DPEncoderService"
} ;

const char *index_data_table[] = {
    "UtilityPipeLine", "MultimediaCapabilityInfo", "MultimediaConfigInfo",
    "StandardVESA_Timing", "FirmwareInfo", "DAC_Info",
    "LVDS_Info", "TMDS_Info", "AnalogTV_Info",
    "SupportedDevicesInfo", "GPIO_I2C_Info", "VRAM_UsageByFirmware",
    "GPIO_Pin_LUT", "VESA_ToInternalModeLUT", "ComponentVideoInfo",
    "PowerPlayInfo", "CompassionateData", "SaveRestoreInfo/DispDevicePriorityInfo",
    "PPLL_SS_Info/SS_Info", "OemInfo", "XTMDS_Info",
    "MclkSS_Info", "Object_Info/Object_Header", "IndirectIOAccess",
    "MC_InitParameter/AdjustARB_SEQ", "ASIC_VDDC_Info", "ASIC_InternalSS_Info/ASIC_MVDDC_Info",
    "TV_VideoMode/DispOutInfo", "VRAM_Info", "MemoryTrainingInfo/ASIC_MVDDQ_Info",
    "IntegratedSystemInfo", "ASIC_ProfilingInfo/ASIC_VDDCI_Info",
    "VoltageObjectInfo/VRAM_GPIO_DetectionInfo",
    "PowerSourceInfo"
} ;


const char *index_ati_port[] = {
    "INDIRECT_IO_MM", "INDIRECT_IO_PLL", "INDIRECT_IO_MC", "INDIRECT_IO_PCIE"
} ;

const char *index_work_reg[] = {
    [WS_QUOTIENT]   = "WS_QUOT/LOW32", [WS_REMINDER]   = "WS_REMIND/HI32",
    [WS_DATAPTR]    = "WS_DATAPTR",    [WS_SHIFT]      = "WS_SHIFT",
    [WS_OR_MASK]    = "WS_OR_MASK",    [WS_AND_MASK]   = "WS_AND_MASK",
    [WS_FB_WINDOW]  = "WS_FB_WIN",     [WS_ATTRIBUTES] = "WS_ATTR",
    [WS_REGPTR]     = "WS_REGPTR"
} ;


#define TABENTRY(x) { #x, (index_ ## x), sizeof (index_ ## x) / sizeof (const char **) }

index_table_t index_tables[INDEXTABLE_SIZEOF] = {
    { NULL, NULL, 0 }, TABENTRY (command_table), TABENTRY (data_table),
    TABENTRY (ati_port), TABENTRY (work_reg),
    { "REG_MM",   NULL, 0 }, { "REG_PLL",  NULL, 0 }, { "REG_MC",   NULL, 0 },
    { "REG_PCIE", NULL, 0 }, { "REG_PCICONFIG", NULL, 0 },
    { "REG_SYSTEMIO", NULL, 0 }
} ;


const char *get_index (int type, int val)
{
    if (type < 0 || val < 0 ||
	type >= sizeof (index_tables) / sizeof (const struct index_table_s))
	return NULL;
    if (! index_tables[type].tab || val >= index_tables[type].len)
	return NULL;
    return index_tables[type].tab[val];
}


void index_load_registers (const char *file)
{
    FILE *f;
    char  buf[512], kind[32], offset[32];
    char *c, *d, *e, *name = NULL, *namefree = NULL;
    int   len, id, nr, size = 0;

    if (! (f = fopen (file, "r")) ) {
	perror (file);
	exit (1);
    }
    while (fgets (buf, 512, f)) {
	if ( (c = strstr (buf, "<register ")) ) {
	    if ( (d = strstr (c, " name=\"")) )
		if ( (e = strchr (d+7, '"')) ) {
		    free (namefree);
		    name = namefree = strndup (d+7, e-d-7);
		}
	    size = 0;
	    if ( (d = strstr (c, " size=\"")) )
		size = strtol (d+7, NULL, 0);
	}
	if ( (c = strstr (buf, "<addr ")) ) {
	    kind[0] = offset[0] = 0;
	    if ( (d = strstr (c, " kind=\"")) )
		if ( (e = strchr (d+7, '"')) ) {
		    strncpy (kind, d+7, e-d-7 > 31 ? 31 : e-d-7);
		    kind[ e-d-7 > 31 ? 31 : e-d-7] = 0;
		}
	    if ( (d = strstr (c, " offset=\"")) )
		if ( (e = strchr (d+9, '"')) ) {
		    strncpy (offset, d+9, e-d-9 > 31 ? 31 : e-d-9);
		    offset[ e-d-9 > 31 ? 31 : e-d-9] = 0;
		}
	    if (! kind[0] || ! offset[0])
		continue;
	    if (strcasestr (kind, "MMReg"))
		id = INDEX_REG_MM;
	    else if (strcasestr (kind, "MCIND"))
		id = INDEX_REG_MC;
	    else if (strcasestr (kind, "PCIEIND"))
		id = INDEX_REG_PCIE;
	    else if (strcasestr (kind, "pciConfig"))
		id = INDEX_REG_PCICONFIG;
	    else
		continue;
	    nr = strtol (offset, NULL, 0);
	    if (size != 32)
		continue;		/* TODO: 8-bit MM */
	    if (id == INDEX_REG_MM) {
		if (! (nr & 3))
		    nr >>= 2;
		else
		    continue;
	    }
	    if (index_tables[id].len <= nr || ! index_tables[id].tab) {
		len = (nr + 0x1f) & -0x20;
		if (len <= 0)
		    len = 0x20;
		index_tables[id].tab = realloc (index_tables[id].tab,
						len * sizeof (const char *));
		memset (index_tables[id].tab + index_tables[id].len,
			0,
			(len - index_tables[id].len) * sizeof (const char *));
		index_tables[id].len = len;
	    }
	    if (index_tables[id].tab[nr]) {
		fprintf (stderr, "Register clash: %04x = %s = %s in table %s\n",
			 nr, name, index_tables[id].tab[nr], index_tables[id].name);
	    } else {
#if 0
		fprintf (stderr, "   %s = %04x  [%02x]\n", name, nr, size);
#endif
		index_tables[id].tab[nr] = name;
		namefree = NULL;
	    }
	}
    }
    free (namefree);
    fclose (f);
}
