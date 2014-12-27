#ifndef __ATOMFAKE_H
#define __ATOMFAKE_H

// Hack !!! silly AMD.. struct's should use pragma aligned on each..
#pragma pack(1)                                       /* BIOS data must use byte aligment */

/*  Define offset to location of ROM header. */

#define OFFSET_TO_POINTER_TO_ATOM_ROM_HEADER		0x00000048L // #define ATOM_ROM_TABLE_PTR      0x48 in Linux (drivers/gpu/drm/radeon/atom.h#L34)
#define OFFSET_TO_ATOM_ROM_IMAGE_SIZE				    0x00000002L

#define OFFSET_TO_ATOMBIOS_ASIC_BUS_MEM_TYPE    0x94
#define MAXSIZE_OF_ATOMBIOS_ASIC_BUS_MEM_TYPE   20    /* including the terminator 0x0! */
#define	OFFSET_TO_GET_ATOMBIOS_STRINGS_NUMBER		0x002f
#define	OFFSET_TO_GET_ATOMBIOS_STRINGS_START		0x006e

// hack this in..
typedef unsigned short USHORT;
typedef unsigned char UCHAR;

/* Common header for all ROM Data tables.
  Every table pointed  _ATOM_MASTER_DATA_TABLE has this common header.
  And the pointer actually points to this header. */

typedef struct _ATOM_COMMON_TABLE_HEADER
{
  USHORT usStructureSize;
  UCHAR  ucTableFormatRevision;   /*Change it when the Parser is not backward compatible */
  UCHAR  ucTableContentRevision;  /*Change it only when the table needs to change but the firmware */
                                  /*Image can't be updated, while Driver needs to carry the new table! */
}ATOM_COMMON_TABLE_HEADER;

/****************************************************************************/
// Structure stores the ROM header.
/****************************************************************************/
typedef struct _ATOM_ROM_HEADER
{
  ATOM_COMMON_TABLE_HEADER		sHeader;
  UCHAR	 uaFirmWareSignature[4];    /*Signature to distinguish between Atombios and non-atombios,
                                      atombios should init it as "ATOM", don't change the position */
  USHORT usBiosRuntimeSegmentAddress;
  USHORT usProtectedModeInfoOffset;
  USHORT usConfigFilenameOffset;
  USHORT usCRC_BlockOffset;
  USHORT usBIOS_BootupMessageOffset;
  USHORT usInt10Offset;
  USHORT usPciBusDevInitCode;
  USHORT usIoBaseAddress;
  USHORT usSubsystemVendorID;
  USHORT usSubsystemID;
  USHORT usPCI_InfoOffset;
  USHORT usMasterCommandTableOffset; /*Offset for SW to get all command table offsets, Don't change the position */
  USHORT usMasterDataTableOffset;   /*Offset for SW to get all data table offsets, Don't change the position */
  UCHAR  ucExtendedFunctionCode;
  UCHAR  ucReserved;
}ATOM_ROM_HEADER;

/****************************************************************************/
// Structures used in Command.mtb
/****************************************************************************/
typedef struct _ATOM_MASTER_LIST_OF_COMMAND_TABLES {
  USHORT ASIC_Init;                              //Function Table, used by various SW components,latest version 1.1
  USHORT GetDisplaySurfaceSize;                  //Atomic Table,  Used by Bios when enabling HW ICON
  USHORT ASIC_RegistersInit;                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  USHORT VRAM_BlockVenderDetection;              //Atomic Table,  used only by Bios
  USHORT DIGxEncoderControl;										 //Only used by Bios
  USHORT MemoryControllerInit;                   //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  USHORT EnableCRTCMemReq;                       //Function Table,directly used by various SW components,latest version 2.1
  USHORT MemoryParamAdjust; 										 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock if needed
  USHORT DVOEncoderControl;                      //Function Table,directly used by various SW components,latest version 1.2
  USHORT GPIOPinControl;												 //Atomic Table,  only used by Bios
  USHORT SetEngineClock;                         //Function Table,directly used by various SW components,latest version 1.1
  USHORT SetMemoryClock;                         //Function Table,directly used by various SW components,latest version 1.1
  USHORT SetPixelClock;                          //Function Table,directly used by various SW components,latest version 1.2
  USHORT DynamicClockGating;                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  USHORT ResetMemoryDLL;                         //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT ResetMemoryDevice;                      //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT MemoryPLLInit;
  USHORT AdjustDisplayPll;												//only used by Bios
  USHORT AdjustMemoryController;                 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT EnableASIC_StaticPwrMgt;                //Atomic Table,  only used by Bios
  USHORT ASIC_StaticPwrMgtStatusChange;          //Obsolete ,     only used by Bios
  USHORT DAC_LoadDetection;                      //Atomic Table,  directly used by various SW components,latest version 1.2
  USHORT LVTMAEncoderControl;                    //Atomic Table,directly used by various SW components,latest version 1.3
  USHORT LCD1OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT DAC1EncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT DAC2EncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT DVOOutputControl;                       //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT CV1OutputControl;                       //Atomic Table,  Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
  USHORT GetConditionalGoldenSetting;            //only used by Bios
  USHORT TVEncoderControl;                       //Function Table,directly used by various SW components,latest version 1.1
  USHORT TMDSAEncoderControl;                    //Atomic Table,  directly used by various SW components,latest version 1.3
  USHORT LVDSEncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.3
  USHORT TV1OutputControl;                       //Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
  USHORT EnableScaler;                           //Atomic Table,  used only by Bios
  USHORT BlankCRTC;                              //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT EnableCRTC;                             //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT GetPixelClock;                          //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT EnableVGA_Render;                       //Function Table,directly used by various SW components,latest version 1.1
  USHORT GetSCLKOverMCLKRatio;                   //Atomic Table,  only used by Bios
  USHORT SetCRTC_Timing;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT SetCRTC_OverScan;                       //Atomic Table,  used by various SW components,latest version 1.1
  USHORT SetCRTC_Replication;                    //Atomic Table,  used only by Bios
  USHORT SelectCRTC_Source;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT EnableGraphSurfaces;                    //Atomic Table,  used only by Bios
  USHORT UpdateCRTC_DoubleBufferRegisters;
  USHORT LUT_AutoFill;                           //Atomic Table,  only used by Bios
  USHORT EnableHW_IconCursor;                    //Atomic Table,  only used by Bios
  USHORT GetMemoryClock;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT GetEngineClock;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT SetCRTC_UsingDTDTiming;                 //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT ExternalEncoderControl;                 //Atomic Table,  directly used by various SW components,latest version 2.1
  USHORT LVTMAOutputControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT VRAM_BlockDetectionByStrap;             //Atomic Table,  used only by Bios
  USHORT MemoryCleanUp;                          //Atomic Table,  only used by Bios
  USHORT ProcessI2cChannelTransaction;           //Function Table,only used by Bios
  USHORT WriteOneByteToHWAssistedI2C;            //Function Table,indirectly used by various SW components
  USHORT ReadHWAssistedI2CStatus;                //Atomic Table,  indirectly used by various SW components
  USHORT SpeedFanControl;                        //Function Table,indirectly used by various SW components,called from ASIC_Init
  USHORT PowerConnectorDetection;                //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT MC_Synchronization;                     //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT ComputeMemoryEnginePLL;                 //Atomic Table,  indirectly used by various SW components,called from SetMemory/EngineClock
  USHORT MemoryRefreshConversion;                //Atomic Table,  indirectly used by various SW components,called from SetMemory or SetEngineClock
  USHORT VRAM_GetCurrentInfoBlock;               //Atomic Table,  used only by Bios
  USHORT DynamicMemorySettings;                  //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT MemoryTraining;                         //Atomic Table,  used only by Bios
  USHORT EnableSpreadSpectrumOnPPLL;             //Atomic Table,  directly used by various SW components,latest version 1.2
  USHORT TMDSAOutputControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT SetVoltage;                             //Function Table,directly and/or indirectly used by various SW components,latest version 1.1
  USHORT DAC1OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT DAC2OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  USHORT SetupHWAssistedI2CStatus;               //Function Table,only used by Bios, obsolete soon.Switch to use "ReadEDIDFromHWAssistedI2C"
  USHORT ClockSource;                            //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  USHORT MemoryDeviceInit;                       //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  USHORT EnableYUV;                              //Atomic Table,  indirectly used by various SW components,called from EnableVGARender
  USHORT DIG1EncoderControl;                     //Atomic Table,directly used by various SW components,latest version 1.1
  USHORT DIG2EncoderControl;                     //Atomic Table,directly used by various SW components,latest version 1.1
  USHORT DIG1TransmitterControl;                 //Atomic Table,directly used by various SW components,latest version 1.1
  USHORT DIG2TransmitterControl;	               //Atomic Table,directly used by various SW components,latest version 1.1
  USHORT ProcessAuxChannelTransaction;					 //Function Table,only used by Bios
  USHORT DPEncoderService;											 //Function Table,only used by Bios
} ATOM_MASTER_LIST_OF_COMMAND_TABLES;

void atomfake_insert_table(void);

#endif /* __ATOMFAKE_H */
