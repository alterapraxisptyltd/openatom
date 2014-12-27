#ifndef __ATOMFAKE_H
#define __ATOMFAKE_H

#include <stdint.h>

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
/* Common header for all ROM Data tables.
  Every table pointed  _ATOM_MASTER_DATA_TABLE has this common header.
  And the pointer actually points to this header. */

typedef struct _ATOM_COMMON_TABLE_HEADER
{
  uint16_t usStructureSize;
  uint8_t  ucTableFormatRevision;   /*Change it when the Parser is not backward compatible */
  uint8_t  ucTableContentRevision;  /*Change it only when the table needs to change but the firmware */
                                  /*Image can't be updated, while Driver needs to carry the new table! */
}ATOM_COMMON_TABLE_HEADER;

/****************************************************************************/
// Structure stores the ROM header.
/****************************************************************************/
typedef struct _ATOM_ROM_HEADER
{
  ATOM_COMMON_TABLE_HEADER		sHeader;
  uint8_t	 uaFirmWareSignature[4];    /*Signature to distinguish between Atombios and non-atombios,
                                      atombios should init it as "ATOM", don't change the position */
  uint16_t usBiosRuntimeSegmentAddress;
  uint16_t usProtectedModeInfoOffset;
  uint16_t usConfigFilenameOffset;
  uint16_t usCRC_BlockOffset;
  uint16_t usBIOS_BootupMessageOffset;
  uint16_t usInt10Offset;
  uint16_t usPciBusDevInitCode;
  uint16_t usIoBaseAddress;
  uint16_t usSubsystemVendorID;
  uint16_t usSubsystemID;
  uint16_t usPCI_InfoOffset;
  uint16_t usMasterCommandTableOffset; /*Offset for SW to get all command table offsets, Don't change the position */
  uint16_t usMasterDataTableOffset;   /*Offset for SW to get all data table offsets, Don't change the position */
  uint8_t  ucExtendedFunctionCode;
  uint8_t  ucReserved;
}ATOM_ROM_HEADER;

/****************************************************************************/
// Structures used in Command.mtb
/****************************************************************************/
typedef struct _ATOM_MASTER_LIST_OF_COMMAND_TABLES {
  uint16_t ASIC_Init;                              //Function Table, used by various SW components,latest version 1.1
  uint16_t GetDisplaySurfaceSize;                  //Atomic Table,  Used by Bios when enabling HW ICON
  uint16_t ASIC_RegistersInit;                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  uint16_t VRAM_BlockVenderDetection;              //Atomic Table,  used only by Bios
  uint16_t DIGxEncoderControl;										 //Only used by Bios
  uint16_t MemoryControllerInit;                   //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  uint16_t EnableCRTCMemReq;                       //Function Table,directly used by various SW components,latest version 2.1
  uint16_t MemoryParamAdjust; 										 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock if needed
  uint16_t DVOEncoderControl;                      //Function Table,directly used by various SW components,latest version 1.2
  uint16_t GPIOPinControl;												 //Atomic Table,  only used by Bios
  uint16_t SetEngineClock;                         //Function Table,directly used by various SW components,latest version 1.1
  uint16_t SetMemoryClock;                         //Function Table,directly used by various SW components,latest version 1.1
  uint16_t SetPixelClock;                          //Function Table,directly used by various SW components,latest version 1.2
  uint16_t DynamicClockGating;                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  uint16_t ResetMemoryDLL;                         //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t ResetMemoryDevice;                      //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t MemoryPLLInit;
  uint16_t AdjustDisplayPll;												//only used by Bios
  uint16_t AdjustMemoryController;                 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t EnableASIC_StaticPwrMgt;                //Atomic Table,  only used by Bios
  uint16_t ASIC_StaticPwrMgtStatusChange;          //Obsolete ,     only used by Bios
  uint16_t DAC_LoadDetection;                      //Atomic Table,  directly used by various SW components,latest version 1.2
  uint16_t LVTMAEncoderControl;                    //Atomic Table,directly used by various SW components,latest version 1.3
  uint16_t LCD1OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t DAC1EncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t DAC2EncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t DVOOutputControl;                       //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t CV1OutputControl;                       //Atomic Table,  Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
  uint16_t GetConditionalGoldenSetting;            //only used by Bios
  uint16_t TVEncoderControl;                       //Function Table,directly used by various SW components,latest version 1.1
  uint16_t TMDSAEncoderControl;                    //Atomic Table,  directly used by various SW components,latest version 1.3
  uint16_t LVDSEncoderControl;                     //Atomic Table,  directly used by various SW components,latest version 1.3
  uint16_t TV1OutputControl;                       //Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
  uint16_t EnableScaler;                           //Atomic Table,  used only by Bios
  uint16_t BlankCRTC;                              //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t EnableCRTC;                             //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t GetPixelClock;                          //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t EnableVGA_Render;                       //Function Table,directly used by various SW components,latest version 1.1
  uint16_t GetSCLKOverMCLKRatio;                   //Atomic Table,  only used by Bios
  uint16_t SetCRTC_Timing;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t SetCRTC_OverScan;                       //Atomic Table,  used by various SW components,latest version 1.1
  uint16_t SetCRTC_Replication;                    //Atomic Table,  used only by Bios
  uint16_t SelectCRTC_Source;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t EnableGraphSurfaces;                    //Atomic Table,  used only by Bios
  uint16_t UpdateCRTC_DoubleBufferRegisters;
  uint16_t LUT_AutoFill;                           //Atomic Table,  only used by Bios
  uint16_t EnableHW_IconCursor;                    //Atomic Table,  only used by Bios
  uint16_t GetMemoryClock;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t GetEngineClock;                         //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t SetCRTC_UsingDTDTiming;                 //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t ExternalEncoderControl;                 //Atomic Table,  directly used by various SW components,latest version 2.1
  uint16_t LVTMAOutputControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t VRAM_BlockDetectionByStrap;             //Atomic Table,  used only by Bios
  uint16_t MemoryCleanUp;                          //Atomic Table,  only used by Bios
  uint16_t ProcessI2cChannelTransaction;           //Function Table,only used by Bios
  uint16_t WriteOneByteToHWAssistedI2C;            //Function Table,indirectly used by various SW components
  uint16_t ReadHWAssistedI2CStatus;                //Atomic Table,  indirectly used by various SW components
  uint16_t SpeedFanControl;                        //Function Table,indirectly used by various SW components,called from ASIC_Init
  uint16_t PowerConnectorDetection;                //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t MC_Synchronization;                     //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t ComputeMemoryEnginePLL;                 //Atomic Table,  indirectly used by various SW components,called from SetMemory/EngineClock
  uint16_t MemoryRefreshConversion;                //Atomic Table,  indirectly used by various SW components,called from SetMemory or SetEngineClock
  uint16_t VRAM_GetCurrentInfoBlock;               //Atomic Table,  used only by Bios
  uint16_t DynamicMemorySettings;                  //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t MemoryTraining;                         //Atomic Table,  used only by Bios
  uint16_t EnableSpreadSpectrumOnPPLL;             //Atomic Table,  directly used by various SW components,latest version 1.2
  uint16_t TMDSAOutputControl;                     //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t SetVoltage;                             //Function Table,directly and/or indirectly used by various SW components,latest version 1.1
  uint16_t DAC1OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t DAC2OutputControl;                      //Atomic Table,  directly used by various SW components,latest version 1.1
  uint16_t SetupHWAssistedI2CStatus;               //Function Table,only used by Bios, obsolete soon.Switch to use "ReadEDIDFromHWAssistedI2C"
  uint16_t ClockSource;                            //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
  uint16_t MemoryDeviceInit;                       //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
  uint16_t EnableYUV;                              //Atomic Table,  indirectly used by various SW components,called from EnableVGARender
  uint16_t DIG1EncoderControl;                     //Atomic Table,directly used by various SW components,latest version 1.1
  uint16_t DIG2EncoderControl;                     //Atomic Table,directly used by various SW components,latest version 1.1
  uint16_t DIG1TransmitterControl;                 //Atomic Table,directly used by various SW components,latest version 1.1
  uint16_t DIG2TransmitterControl;	               //Atomic Table,directly used by various SW components,latest version 1.1
  uint16_t ProcessAuxChannelTransaction;					 //Function Table,only used by Bios
  uint16_t DPEncoderService;											 //Function Table,only used by Bios
} ATOM_MASTER_LIST_OF_COMMAND_TABLES;

void atomfake_insert_table(void);

#endif /* __ATOMFAKE_H */
