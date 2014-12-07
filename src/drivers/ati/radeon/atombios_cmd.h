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

#ifndef __ATOMBIOS_CMD_H__
#define __ATOMBIOS_CMD_H__

unsigned short ASIC_Init();                              //Function Table, used by various SW components,latest version 1.1
unsigned short GetDisplaySurfaceSize();                  //Atomic Table,  Used by Bios when enabling HW ICON
unsigned short ASIC_RegistersInit();                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
unsigned short VRAM_BlockVenderDetection();              //Atomic Table,  used only by Bios
unsigned short DIGxEncoderControl();										 //Only used by Bios
unsigned short MemoryControllerInit();                   //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
unsigned short EnableCRTCMemReq();                       //Function Table,directly used by various SW components,latest version 2.1
unsigned short MemoryParamAdjust(); 										 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock if needed
unsigned short DVOEncoderControl();                      //Function Table,directly used by various SW components,latest version 1.2
unsigned short GPIOPinControl();												 //Atomic Table,  only used by Bios
unsigned short SetEngineClock();                         //Function Table,directly used by various SW components,latest version 1.1
unsigned short SetMemoryClock();                         //Function Table,directly used by various SW components,latest version 1.1
unsigned short SetPixelClock();                          //Function Table,directly used by various SW components,latest version 1.2
unsigned short DynamicClockGating();                     //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
unsigned short ResetMemoryDLL();                         //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short ResetMemoryDevice();                      //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short MemoryPLLInit();
unsigned short AdjustDisplayPll();												//only used by Bios
unsigned short AdjustMemoryController();                 //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short EnableASIC_StaticPwrMgt();                //Atomic Table,  only used by Bios
unsigned short ASIC_StaticPwrMgtStatusChange();          //Obsolete ,     only used by Bios
unsigned short DAC_LoadDetection();                      //Atomic Table,  directly used by various SW components,latest version 1.2
unsigned short LVTMAEncoderControl();                    //Atomic Table,directly used by various SW components,latest version 1.3
unsigned short LCD1OutputControl();                      //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short DAC1EncoderControl();                     //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short DAC2EncoderControl();                     //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short DVOOutputControl();                       //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short CV1OutputControl();                       //Atomic Table,  Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
unsigned short GetConditionalGoldenSetting();            //only used by Bios
unsigned short TVEncoderControl();                       //Function Table,directly used by various SW components,latest version 1.1
unsigned short TMDSAEncoderControl();                    //Atomic Table,  directly used by various SW components,latest version 1.3
unsigned short LVDSEncoderControl();                     //Atomic Table,  directly used by various SW components,latest version 1.3
unsigned short TV1OutputControl();                       //Atomic Table,  Obsolete from Ry6xx, use DAC2 Output instead
unsigned short EnableScaler();                           //Atomic Table,  used only by Bios
unsigned short BlankCRTC();                              //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short EnableCRTC();                             //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short GetPixelClock();                          //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short EnableVGA_Render();                       //Function Table,directly used by various SW components,latest version 1.1
unsigned short GetSCLKOverMCLKRatio();                   //Atomic Table,  only used by Bios
unsigned short SetCRTC_Timing();                         //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short SetCRTC_OverScan();                       //Atomic Table,  used by various SW components,latest version 1.1
unsigned short SetCRTC_Replication();                    //Atomic Table,  used only by Bios
unsigned short SelectCRTC_Source();                      //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short EnableGraphSurfaces();                    //Atomic Table,  used only by Bios
unsigned short UpdateCRTC_DoubleBufferRegisters();
unsigned short LUT_AutoFill();                           //Atomic Table,  only used by Bios
unsigned short EnableHW_IconCursor();                    //Atomic Table,  only used by Bios
unsigned short GetMemoryClock();                         //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short GetEngineClock();                         //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short SetCRTC_UsingDTDTiming();                 //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short ExternalEncoderControl();                 //Atomic Table,  directly used by various SW components,latest version 2.1
unsigned short LVTMAOutputControl();                     //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short VRAM_BlockDetectionByStrap();             //Atomic Table,  used only by Bios
unsigned short MemoryCleanUp();                          //Atomic Table,  only used by Bios
unsigned short ProcessI2cChannelTransaction();           //Function Table,only used by Bios
unsigned short WriteOneByteToHWAssistedI2C();            //Function Table,indirectly used by various SW components
unsigned short ReadHWAssistedI2CStatus();                //Atomic Table,  indirectly used by various SW components
unsigned short SpeedFanControl();                        //Function Table,indirectly used by various SW components,called from ASIC_Init
unsigned short PowerConnectorDetection();                //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short MC_Synchronization();                     //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short ComputeMemoryEnginePLL();                 //Atomic Table,  indirectly used by various SW components,called from SetMemory/EngineClock
unsigned short MemoryRefreshConversion();                //Atomic Table,  indirectly used by various SW components,called from SetMemory or SetEngineClock
unsigned short VRAM_GetCurrentInfoBlock();               //Atomic Table,  used only by Bios
unsigned short DynamicMemorySettings();                  //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short MemoryTraining();                         //Atomic Table,  used only by Bios
unsigned short EnableSpreadSpectrumOnPPLL();             //Atomic Table,  directly used by various SW components,latest version 1.2
unsigned short TMDSAOutputControl();                     //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short SetVoltage();                             //Function Table,directly and/or indirectly used by various SW components,latest version 1.1
unsigned short DAC1OutputControl();                      //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short DAC2OutputControl();                      //Atomic Table,  directly used by various SW components,latest version 1.1
unsigned short SetupHWAssistedI2CStatus();               //Function Table,only used by Bios, obsolete soon.Switch to use "ReadEDIDFromHWAssistedI2C"
unsigned short ClockSource();                            //Atomic Table,  indirectly used by various SW components,called from ASIC_Init
unsigned short MemoryDeviceInit();                       //Atomic Table,  indirectly used by various SW components,called from SetMemoryClock
unsigned short EnableYUV();                              //Atomic Table,  indirectly used by various SW components,called from EnableVGARender
unsigned short DIG1EncoderControl();                     //Atomic Table,directly used by various SW components,latest version 1.1
unsigned short DIG2EncoderControl();                     //Atomic Table,directly used by various SW components,latest version 1.1
unsigned short DIG1TransmitterControl();                 //Atomic Table,directly used by various SW components,latest version 1.1
unsigned short DIG2TransmitterControl();	               //Atomic Table,directly used by various SW components,latest version 1.1
unsigned short ProcessAuxChannelTransaction();					 //Function Table,only used by Bios
unsigned short DPEncoderService();											 //Function Table,only used by Bios

#endif /* __ATOMBIOS_CMD_H__ */
