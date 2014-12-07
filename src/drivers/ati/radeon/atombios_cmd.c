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

#include "atombios_cmd.h"

unsigned short ASIC_Init()
{
/*
 * command_table 0000b45e #00 (ASIC_Init):
 *
 * Size 002b
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 02 longs
 * Table update indicator 0
 *
 * 0006: 5202 CALL_TABLE 02 (ASIC_RegistersInit)
 * 0008: 5205 CALL_TABLE 05 (MemoryControllerInit)
 * 000a: 02010200 MOVE param[02] [XXXX] <- param[00] [XXXX]
 * 000e: 0ee50208 OR param[02] [X...] <- 08
 * 0012: 520a CALL_TABLE 0a (SetEngineClock)
 * 0014: 6616 SET_DATA_BLOCK 16 (Object_Info/Object_Header)
 * 0016: 030c410400 MOVE WS_REMIND/HI32 [..XX] <- data[0004] [..XX]
 * 001b: 4c0d410200 TEST WS_REMIND/HI32 [..XX] <- 0002
 * 0020: 442a00 JUMP_Equal 002a
 * 0023: 0da5c90504 OR reg[05c9] [.X..] <- 04
 * 0028: 524b CALL_TABLE 4b (DIG2EncoderControl)
 * 002a: 5b EOT
 */
  return 0;
}

unsigned short GetDisplaySurfaceSize()
{
  return 0;
}

unsigned short ASIC_RegistersInit()
{
/*
 * command_table 0000b4e2 #02 (ASIC_RegistersInit):
 *
 * Size 00c5
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 5247 CALL_TABLE 47 (ClockSource)
 * 000b: 0105000b2100200f MOVE reg[0b00] [XXXX] <- 0f200021
 * 0013: 0105cc0b01000000 MOVE reg[0bcc] [XXXX] <- 00000001
 * 001b: 0105d30be01b1200 MOVE reg[0bd3] [XXXX] <- 00121be0
 * 0023: 010502140dd80000 MOVE reg[1402] [XXXX] <- 0000d80d
 * 002b: 010503140cd80000 MOVE reg[1403] [XXXX] <- 0000d80c
 * 0033: 0105041469010200 MOVE reg[1404] [XXXX] <- 00020169
 * 003b: 0105051468010200 MOVE reg[1405] [XXXX] <- 00020168
 * 0043: 010506147d010200 MOVE reg[1406] [XXXX] <- 0002017d
 * 004b: 010507147c010200 MOVE reg[1407] [XXXX] <- 0002017c
 * 0053: 0105081491010200 MOVE reg[1408] [XXXX] <- 00020191
 * 005b: 0105091490010200 MOVE reg[1409] [XXXX] <- 00020190
 * 0063: 0105380040803301 MOVE reg[0038] [XXXX] <- 01338040
 * 006b: 0d25390001 OR reg[0039] [...X] <- 01
 * 0070: 0105380041803301 MOVE reg[0038] [XXXX] <- 01338041
 * 0078: 0d25390001 OR reg[0039] [...X] <- 01
 * 007d: 02650007 MOVE param[00] [..X.] <- 07
 * 0081: 520d CALL_TABLE 0d (DynamicClockGating)
 * 0083: 550000 CLEAR param[00] [XXXX]
 * 0086: 520d CALL_TABLE 0d (DynamicClockGating)
 * 0088: 5223 CALL_TABLE 23 (EnableCRTC)
 * 008a: 2c250001 ADD param[00] [...X] <- 01
 * 008e: 3d250004 COMP param[00] [...X] <- 04
 * 0092: 458600 JUMP_Below 0086
 * 0095: 5102 DELAY_MicroSec 02
 * 0097: 550000 CLEAR param[00] [XXXX]
 * 009a: 524e CALL_TABLE 4e (ProcessAuxChannelTransaction)
 * 009c: 661e SET_DATA_BLOCK 1e (IntegratedSystemInfo)
 * 009e: 012447183800 MOVE reg[1847] [...X] <- data[0038] [...X]
 * 00a4: 0105331bff7f0000 MOVE reg[1b33] [XXXX] <- 00007fff
 * 00ac: 0105331eff7f0000 MOVE reg[1e33] [XXXX] <- 00007fff
 * 00b4: 01053341ff7f0000 MOVE reg[4133] [XXXX] <- 00007fff
 * 00bc: 01053344ff7f0000 MOVE reg[4433] [XXXX] <- 00007fff
 * 00c4: 5b EOT
 */
  return 0;
}

unsigned short VRAM_BlockVenderDetection()
{
  return 0; // Do nothing
}

unsigned short DIGxEncoderControl()
{
  return 0;
}

unsigned short MemoryControllerInit()
{
/*
 * command_table 0000b5a8 #05 (MemoryControllerInit):
 *
 * Size 0032
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 54202415 CLEAR reg[1524] [...X]
 * 000d: 560041 CLEAR WS_REMIND/HI32 [XXXX]
 * 0010: 0388410908 MOVE WS_REMIND/HI32 [XX..] <- reg[0809] [..XX]
 * 0015: 0102010b41 MOVE reg[0b01] [XXXX] <- WS_REMIND/HI32 [XXXX]
 * 001a: 013ac90041 MOVE reg[00c9] [...X] <- WS_REMIND/HI32 [X...]
 * 001f: 15054108 SHIFT_LEFT WS_REMIND/HI32 [XXXX] by 08
 * 0023: 0102c40041 MOVE reg[00c4] [XXXX] <- WS_REMIND/HI32 [XXXX]
 * 0028: 54202b08 CLEAR reg[082b] [...X]
 * 002c: 0d25241503 OR reg[1524] [...X] <- 03
 * 0031: 5b EOT
 */
  return 0;
}

unsigned short EnableCRTCMemReq()
{
  return 0; // Do nothing
}

unsigned short MemoryParamAdjust()
{
  return 0; // Do nothing
}

unsigned short DVOEncoderControl()
{
  return 0; // Do nothing
}

unsigned short GPIOPinControl()
{
/*
 * command_table 0000b5da #09 (GPIOPinControl):
 *
 * Size 00ff
 * Format Rev. 02
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 01 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 660c SET_DATA_BLOCK 0c (GPIO_Pin_LUT)
 * 000b: 030c410000 MOVE WS_REMIND/HI32 [..XX] <- data[0000] [..XX]
 * 0010: 2d0a4142 ADD WS_REMIND/HI32 [..XX] <- WS_DATAPTR [..XX]
 * 0014: 2d0d420400 ADD WS_DATAPTR [..XX] <- 0004
 * 0019: 3d24000300 COMP param[00] [...X] <- data[0003] [...X]
 * 001e: 443000 JUMP_Equal 0030
 * 0021: 2d0d420400 ADD WS_DATAPTR [..XX] <- 0004
 * 0026: 3e0a4241 COMP WS_DATAPTR [..XX] <- WS_REMIND/HI32 [..XX]
 * 002a: 44fb00 JUMP_Equal 00fb
 * 002d: 431900 JUMP 0019
 * 0030: 560043 CLEAR WS_SHIFT [XXXX]
 * 0033: 03a4410200 MOVE WS_REMIND/HI32 [.X..] <- data[0002] [...X]
 * 0038: 03f24141 MOVE WS_REMIND/HI32 [X...] <- WS_REMIND/HI32 [.X..]
 * 003c: 030c410000 MOVE WS_REMIND/HI32 [..XX] <- data[0000] [..XX]
 * 0041: 3e0d410000 COMP WS_REMIND/HI32 [..XX] <- 0000
 * 0046: 44fb00 JUMP_Equal 00fb
 * 0049: 3e0d414519 COMP WS_REMIND/HI32 [..XX] <- 1945
 * 004e: 496b00 JUMP_NotEqual 006b
 * 0051: 3ee54110 COMP WS_REMIND/HI32 [X...] <- 10
 * 0055: 465f00 JUMP_Above 005f
 * 0058: 1b3d4101 SHIFT_RIGHT WS_REMIND/HI32 [X...] by 01
 * 005c: 436b00 JUMP 006b
 * 005f: 09e54103 AND WS_REMIND/HI32 [X...] <- 03
 * 0063: 153d4102 SHIFT_LEFT WS_REMIND/HI32 [X...] by 02
 * 0067: 2de5410c ADD WS_REMIND/HI32 [X...] <- 0c
 * 006b: 033a4341 MOVE WS_SHIFT [...X] <- WS_REMIND/HI32 [X...]
 * 006f: 54000000 CLEAR reg[0000] [XXXX]
 * 0073: 330d410100 SUB WS_REMIND/HI32 [..XX] <- 0001
 * 0078: 010a000041 MOVE reg[0000] [..XX] <- WS_REMIND/HI32 [..XX]
 * 007d: 0d02010044 OR reg[0001] [XXXX] <- WS_OR_MASK [XXXX]
 * 0082: 2d0d410200 ADD WS_REMIND/HI32 [..XX] <- 0002
 * 0087: 010a000041 MOVE reg[0000] [..XX] <- WS_REMIND/HI32 [..XX]
 * 008c: 03324341 MOVE WS_SHIFT [...X] <- WS_REMIND/HI32 [.X..]
 * 0090: 4be50001 TEST param[00] [X...] <- 01
 * 0094: 49d700 JUMP_NotEqual 00d7
 * 0097: 0702010045 AND reg[0001] [XXXX] <- WS_AND_MASK [XXXX]
 * 009c: 2d0d410100 ADD WS_REMIND/HI32 [..XX] <- 0001
 * 00a1: 010a000041 MOVE reg[0000] [..XX] <- WS_REMIND/HI32 [..XX]
 * 00a6: 4a02010044 TEST reg[0001] [XXXX] <- WS_OR_MASK [XXXX]
 * 00ab: 44b900 JUMP_Equal 00b9
 * 00ae: 03294300 MOVE WS_SHIFT [...X] <- param[00] [..X.]
 * 00b2: 0ea20044 OR param[00] [.X..] <- WS_OR_MASK [...X]
 * 00b6: 43c100 JUMP 00c1
 * 00b9: 03294300 MOVE WS_SHIFT [...X] <- param[00] [..X.]
 * 00bd: 08a20045 AND param[00] [.X..] <- WS_AND_MASK [...X]
 * 00c1: 330d410300 SUB WS_REMIND/HI32 [..XX] <- 0003
 * 00c6: 010a000041 MOVE reg[0000] [..XX] <- WS_REMIND/HI32 [..XX]
 * 00cb: 033a4341 MOVE WS_SHIFT [...X] <- WS_REMIND/HI32 [X...]
 * 00cf: 0702010045 AND reg[0001] [XXXX] <- WS_AND_MASK [XXXX]
 * 00d4: 43fa00 JUMP 00fa
 * 00d7: 0d02010044 OR reg[0001] [XXXX] <- WS_OR_MASK [XXXX]
 * 00dc: 330d410100 SUB WS_REMIND/HI32 [..XX] <- 0001
 * 00e1: 010a000041 MOVE reg[0000] [..XX] <- WS_REMIND/HI32 [..XX]
 * 00e6: 3da50001 COMP param[00] [.X..] <- 01
 * 00ea: 44f500 JUMP_Equal 00f5
 * 00ed: 0702010045 AND reg[0001] [XXXX] <- WS_AND_MASK [XXXX]
 * 00f2: 43fa00 JUMP 00fa
 * 00f5: 0d02010044 OR reg[0001] [XXXX] <- WS_OR_MASK [XXXX]
 * 00fa: 5b EOT
 * 00fb: 552000 CLEAR param[00] [...X]
 * 00fe: 5b EOT
 */
  return 0;
}

unsigned short SetEngineClock()
{
/*
 * command_table 0000b6da #0a (SetEngineClock):
 *
 * Size 0029
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 01 longs
 * Table update indicator 0
 *
 * 0006: 02010100 MOVE param[01] [XXXX] <- param[00] [XXXX]
 * 000a: 02e50102 MOVE param[01] [X...] <- 02
 * 000e: 523c CALL_TABLE 3c (ComputeMemoryEnginePLL)
 * 0010: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0013: 4a25810101 TEST reg[0181] [...X] <- 01
 * 0018: 441300 JUMP_Equal 0013
 * 001b: 0139800101 MOVE reg[0180] [...X] <- param[01] [X...]
 * 0020: 4a25810101 TEST reg[0181] [...X] <- 01
 * 0025: 442000 JUMP_Equal 0020
 * 0028: 5b EOT
 */
  return 0;
}

unsigned short SetMemoryClock()
{
  return 0; // Do nothing
}

unsigned short SetPixelClock()
{
  return 0;
}

unsigned short DynamicClockGating()
{
  return 0;
}

unsigned short ResetMemoryDLL()
{
  return 0; // Do nothing
}

unsigned short ResetMemoryDevice()
{
  return 0; // Do nothing
}

unsigned short MemoryPLLInit()
{
  return 0; // Do nothing
}

unsigned short AdjustDisplayPll()
{
  return 0;
}

unsigned short AdjustMemoryController()
{
  return 0; // Do nothing
}

unsigned short EnableASIC_StaticPwrMgt()
{
  return 0;
}

unsigned short ASIC_StaticPwrMgtStatusChange()
{
  return 0;
}

unsigned short DAC_LoadDetection()
{
  return 0; // Do nothing
}

unsigned short LVTMAEncoderControl()
{
  return 0; // Do nothing
}

unsigned short LCD1OutputControl()
{
  return 0; // Do nothing
}

unsigned short DAC1EncoderControl()
{
  return 0; // Do nothing
}

unsigned short DAC2EncoderControl()
{
  return 0; // Do nothing
}

unsigned short DVOOutputControl()
{
  return 0; // Do nothing
}

unsigned short CV1OutputControl()
{
  return 0; // Do nothing
}

unsigned short GetConditionalGoldenSetting()
{
  return 0; // Do nothing
}

unsigned short TVEncoderControl()
{
  return 0; // Do nothing
}

unsigned short TMDSAEncoderControl()
{
  return 0; // Do nothing
}

unsigned short LVDSEncoderControl()
{
  return 0; // Do nothing
}

unsigned short TV1OutputControl()
{
  return 0; // Do nothing
}

unsigned short EnableScaler()
{
  return 0;
}

unsigned short BlankCRTC()
{
/*
 * command_table 0000bdd2 #22 (BlankCRTC):
 *
 * Size 004b
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 4aa5cb0501 TEST reg[05cb] [.X..] <- 01
 * 000e: 441500 JUMP_Equal 0015
 * 0011: 02650001 MOVE param[00] [..X.] <- 01
 * 0015: 5214 CALL_TABLE 14 (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
 * 0017: 54309d1b CLEAR reg[1b9d] [.X..]
 * 001b: 01699d1b00 MOVE reg[1b9d] [..X.] <- param[00] [..X.]
 * 0020: 3d650000 COMP param[00] [..X.] <- 00
 * 0024: 444700 JUMP_Equal 0047
 * 0027: 4aa59c1b01 TEST reg[1b9c] [.X..] <- 01
 * 002c: 444700 JUMP_Equal 0047
 * 002f: 4a25a31b01 TEST reg[1ba3] [...X] <- 01
 * 0034: 492f00 JUMP_NotEqual 002f
 * 0037: 4a25a31b01 TEST reg[1ba3] [...X] <- 01
 * 003c: 443700 JUMP_Equal 0037
 * 003f: 4a25a31b01 TEST reg[1ba3] [...X] <- 01
 * 0044: 493f00 JUMP_NotEqual 003f
 * 0047: 3a0000 SET_REG_BLOCK 0000
 * 004a: 5b EOT
 */
  return 0;
}

unsigned short EnableCRTC()
{
/*
 * command_table 0000be1e #23 (EnableCRTC):
 *
 * Size 003e
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 5214 CALL_TABLE 14 (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
 * 000b: 3d650001 COMP param[00] [..X.] <- 01
 * 000f: 443000 JUMP_Equal 0030
 * 0012: 0d659c1b03 OR reg[1b9c] [..X.] <- 03
 * 0017: 07259c1bfe AND reg[1b9c] [...X] <- fe
 * 001c: 4aa59c1b01 TEST reg[1b9c] [.X..] <- 01
 * 0021: 491c00 JUMP_NotEqual 001c
 * 0024: 07e57c1b7f AND reg[1b7c] [X...] <- 7f
 * 0029: 5420a91b CLEAR reg[1ba9] [...X]
 * 002d: 433a00 JUMP 003a
 * 0030: 0de57c1b80 OR reg[1b7c] [X...] <- 80
 * 0035: 0d259c1b01 OR reg[1b9c] [...X] <- 01
 * 003a: 3a0000 SET_REG_BLOCK 0000
 * 003d: 5b EOT
 */
  return 0;
}

unsigned short GetPixelClock()
{
  return 0;
}

unsigned short EnableVGA_Render()
{
/*
 * command_table 0000bf8e #25 (EnableVGA_Render):
 *
 * Size 002c
 * Format Rev. 02
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 3c21fc0000 COMP reg[00fc] [...X] <- param[00] [...X]
 * 000e: 491900 JUMP_NotEqual 0019
 * 0011: 0da5c00001 OR reg[00c0] [.X..] <- 01
 * 0016: 432600 JUMP 0026
 * 0019: 3c61fc0000 COMP reg[00fc] [..X.] <- param[00] [...X]
 * 001e: 492600 JUMP_NotEqual 0026
 * 0021: 0da5c00002 OR reg[00c0] [.X..] <- 02
 * 0026: 0da5c10001 OR reg[00c1] [.X..] <- 01
 * 002b: 5b EOT
 */
  return 0;
}

unsigned short GetSCLKOverMCLKRatio()
{
  return 0; // Do nothing
}

unsigned short SetCRTC_Timing()
{
  return 0; // Do nothing
}

unsigned short SetCRTC_OverScan()
{
/*
 * command_table 0000bfba #28 (SetCRTC_OverScan):
 *
 * Size 0019
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 02 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 5214 CALL_TABLE 14 (ASIC_StaticPwrMgtStatusChange/SetUniphyInstance)
 * 000b: 01015e1b00 MOVE reg[1b5e] [XXXX] <- param[00] [XXXX]
 * 0010: 01015f1b01 MOVE reg[1b5f] [XXXX] <- param[01] [XXXX]
 * 0015: 3a0000 SET_REG_BLOCK 0000
 * 0018: 5b EOT
 */
  return 0;
}

unsigned short SetCRTC_Replication()
{
  return 0; // Do nothing
}

unsigned short SelectCRTC_Source()
{
  return 0;
}

unsigned short GraphSurfaces()
{
  return 0;
}

unsigned short UpdateCRTC_DoubleBufferRegisters()
{
  return 0;
}

unsigned short LUT_AutoFill()
{
  return 0;
}

unsigned short EnableHW_IconCursor()
{
  return 0; // Do nothing
}

unsigned short GetMemoryClock()
{
  return 0; // Do nothing
}

unsigned short GetEngineClock()
{
  return 0;
}

unsigned short SetCRTC_UsingDTDTiming()
{
  return 0;
}

unsigned short ExternalEncoderControl()
{
  return 0;
}

unsigned short LVTMAOutputControl()
{
  return 0; // Do nothing
}

unsigned short VRAM_BlockDetectionByStrap()
{
  return 0; // Do nothing
}

unsigned short MemoryCleanUp()
{
  return 0;
}

unsigned short ProcessI2cChannelTransaction()
{
  return 0;
}

unsigned short WriteOneByteToHWAssistedI2C()
{
  return 0; // Do nothing
}

unsigned short ReadHWAssistedI2CStatus()
{
  return 0;
}

unsigned short SpeedFanControl()
{
  return 0; // Do nothing
}

unsigned short PowerConnectorDetection()
{
  return 0; // Do nothing
}

unsigned short MC_Synchronization()
{
  return 0; // Do nothing
}

unsigned short ComputeMemoryEnginePLL()
{
  return 0;
}

unsigned short MemoryRefreshConversion()
{
  return 0; // Do nothing
}

unsigned short VRAM_GetCurrentInfoBlock()
{
  return 0; // Do nothing
}

unsigned short DynamicMemorySettings()
{
  return 0; // Do nothing
}

unsigned short MemoryTraining()
{
  return 0; // Do nothing
}

unsigned short EnableSpreadSpectrumOnPPLL()
{
  return 0;
}

unsigned short TMDSAOutputControl()
{
  return 0; // Do nothing
}

unsigned short SetVoltage()
{
  return 0; // Do nothing
}

unsigned short DAC1OutputControl()
{
  return 0; // Do nothing
}

unsigned short DAC2OutputControl()
{
  return 0; // Do nothing
}

unsigned short SetupHWAssistedI2CStatus()
{
  return 0; // Do nothing
}

unsigned short ClockSource()
{
/*
 * command_table 0000bbe4 #47 (ClockSource):
 *
 * Size 001c
 * Format Rev. 01
 * Param Rev. 00
 * Content Rev. 01
 * Attributes: Work space size 00 longs
 * Parameter space size 00 longs
 * Table update indicator 0
 *
 * 0006: 370000 SET_ATI_PORT 0000 (INDIRECT_IO_MM)
 * 0009: 07a59c01fc AND reg[019c] [.X..] <- fc
 * 000e: 0d659c0180 OR reg[019c] [..X.] <- 80
 * 0013: 0105c50120d3201d MOVE reg[01c5] [XXXX] <- 1d20d320
 * 001b: 5b EOT
 */
  return 0;
}

unsigned short MemoryDeviceInit()
{
  return 0; // Do nothing
}

unsigned short EnableYUV()
{
  return 0;
}

unsigned short DIG1EncoderControl()
{
  return 0; // Do nothing
}

unsigned short DIG2EncoderControl()
{
  return 0;
}

unsigned short DIG1TransmitterControl()
{
  return 0;
}

unsigned short DIG2TransmitterControl()
{
  return 0; // Do nothing
}

unsigned short ProcessAuxChannelTransaction()
{
  return 0;
}

unsigned short DPEncoderService()
{
  return 0;
}
