/** @file
  Register Definitions for HECI

@copyright
  INTEL CONFIDENTIAL
  Copyright 2010 - 2019 Intel Corporation.

  The source code contained or described herein and all documents related to the
  source code ("Material") are owned by Intel Corporation or its suppliers or
  licensors. Title to the Material remains with Intel Corporation or its suppliers
  and licensors. The Material may contain trade secrets and proprietary and
  confidential information of Intel Corporation and its suppliers and licensors,
  and is protected by worldwide copyright and trade secret laws and treaty
  provisions. No part of the Material may be used, copied, reproduced, modified,
  published, uploaded, posted, transmitted, distributed, or disclosed in any way
  without Intel's prior express written permission.

  No license under any patent, copyright, trade secret or other intellectual
  property right is granted to or conferred upon you by disclosure or delivery
  of the Materials, either expressly, by implication, inducement, estoppel or
  otherwise. Any license under such intellectual property rights must be
  express and approved by Intel in writing.

  Unless otherwise agreed by Intel in writing, you may not remove or alter
  this notice or any other notice embedded in Materials by Intel or
  Intel's suppliers or licensors in any way.

  This file contains an 'Intel Peripheral Driver' and is uniquely identified as
  "Intel Reference Module" and is licensed for Intel CPUs and chipsets under
  the terms of your license agreement with Intel or your vendor. This file may
  be modified by the user, subject to additional terms of the license agreement.

@par Specification Reference:
**/
#ifndef _HECI_REGS_H_
#define _HECI_REGS_H_

#define HECI_BUS                        ME_BUS
#define HECI_DEV                        ME_DEVICE_NUMBER
#define HECI_FUN                        HECI_FUNCTION_NUMBER

///
/// HECIMBAR register definition
///
#define H_CB_WW   0x00
#define H_CSR     0x04
#define ME_CB_RW  0x08
#define ME_CSR_HA 0x0C
#define D0I3C     0x800

///
/// Host side access of CSME Extended Registers
///
#define R_HERS           0xCBC    ///< Host side access CSME Extended Register Status
#define R_HER_BASE       0xC00    ///< Host side access CSME Extended Register Base Address to get SHA384 Data (48 bytes) from DWord registers HECI1_HER1 (0xCC0) to HECI1_HER12 (0xCEC)

#pragma pack(1)
///
/// Register definitions
///

///
/// H_CSR     - Host Control Status Register, offset 04h
/// ME_CSR_HA - ME Control Status Register (Host Access), offset 0Ch
///
typedef union {
  UINT32 Data;
  struct {
    UINT32  IntEnable      : 1;  ///< 0 - Host/ME Interrupt Enable
    UINT32  IntStatus      : 1;  ///< 1 - Host/ME Interrupt Status
    UINT32  IntGenerate    : 1;  ///< 2 - Host/ME Interrupt Generate
    UINT32  Ready          : 1;  ///< 3 - Host/ME Ready
    UINT32  Reset          : 1;  ///< 4 - Host/ME Reset
    UINT32  Reserved       : 3;  ///< 7:5 - Reserved
    UINT32  CBReadPointer  : 8;  ///< 15:8 - Host/ME Circular Buffer Read Pointer
    UINT32  CBWritePointer : 8;  ///< 23:16 - Host/ME Circular Buffer Write Pointer
    UINT32  CBDepth        : 8;  ///< 31:24 - Host/ME Circular Buffer Depth
  } Fields;
} HECI_CONTROL_STATUS_REGISTER;

///
/// HFSTS1, offset 40h
///
typedef union {
  UINT32  ul;
  struct {
    UINT32  CurrentState         : 4;  ///< 0:3 - Current State
    UINT32  ManufacturingMode    : 1;  ///< 4 - Manufacturing Mode
    UINT32  FptBad               : 1;  ///< 5 - FPT(Flash Partition Table ) Bad
    UINT32  MeOperationState     : 3;  ///< 6:8 - ME Operation State
    UINT32  FwInitComplete       : 1;  ///< 9 - This bit is set when firmware has fully entered a stable state
    UINT32  FtBupLdFlr           : 1;  ///< 10 - This bit is set when firmware is not able to load BRINGUP from the fault tolerant (FT) code
    UINT32  FwUpdateInprogress   : 1;  ///< 11 - This bit is set when data migration is required during ME FW update process
    UINT32  ErrorCode            : 4;  ///< 12:15 - Error Code
    UINT32  MeOperationMode      : 4;  ///< 16:19 - Management Engine Current Operation Mode
    UINT32  MeRstCnt             : 4;  ///< 20:23 - Number of ME Resets
    UINT32  MeBootOptionsPresent : 1;  ///< 24 - If this bit is set, an Boot Options is present
    UINT32  Reserved             : 1;  ///< 25 - Reserved
    UINT32  BistTestState        : 1;  ///< 26 - This bit informs if BIST is starting or BIST is finished
    UINT32  BistResetRequest     : 1;  ///< 27 - This bit informs if BIST Reset Request
    UINT32  CurrentPowerSource   : 2;  ///< 28:29 - Current power source selection mode
    UINT32  D3SupportValid       : 1;  ///< 30 - D3 support
    UINT32  D0i3SupportValid     : 1;  ///< 31 - D0i3 support
  } r;
} HECI_FWS_REGISTER;

///
/// HFSTS2, offset 48h
///
typedef union {
  UINT32  ul;
  struct {
    UINT32  NftpLoadFailure  : 1;  ///< 0 - NFTP Load Failure Detection Field
    UINT32  IccProgSts       : 2;  ///< 1:2 - ICC Prog STS
    UINT32  InvokeMEBx       : 1;  ///< 3 - Invoke MEBX
    UINT32  CpuReplacedSts   : 1;  ///< 4 - CPU Replaced STS
    UINT32  Reserved         : 1;  ///< 5 - Reserved
    UINT32  MfsFailure       : 1;  ///< 6 - MFS Failure
    UINT32  WarmRstReqForDF  : 1;  ///< 7 - Warm Reset Required for Dynamic Fusing
    UINT32  CpuReplacedValid : 1;  ///< 8 - CPU Replaced Valid
    UINT32  LowPowerState    : 1;  ///< 9 - Low Power State
    UINT32  MePowerGating    : 1;  ///< 10 - ME Power Gating Indicator
    UINT32  FwUpdIpu         : 1;  ///< 11 - FW Update IPU Needed
    UINT32  FwUpdForcedSB    : 1;  ///< 12 - FW Update Forced Safe Boot
    UINT32  Reserved2        : 1;  ///< 13 - Reserved
    UINT32  IfuFaultTol      : 1;  ///< 14 - IFU Fault Tolerance Test State
    UINT32  HeciListCh       : 1;  ///< 15 - HECI Listner Change
    UINT32  ExtStatCode1     : 8;  ///< 16:23 - EXT Status Code 1
    UINT32  ExtStatCode2     : 4;  ///< 24:27 - EXT Status Code 2
    UINT32  InfPhaseCode     : 4;  ///< 31:28 - Infra. Phase code
  } r;
} HECI_GS_SHDW_REGISTER;

///
/// HFSTS4, offset 64h
///
typedef union {
  UINT32  ul;
  struct {
    UINT32 Reserved            : 9;  ///< 8:0 - Reserved
    UINT32 FwInEnfFlow         : 1;  ///< 9 - FW is in ENF flow
    UINT32 SxResumeType        : 1;  ///< 10 - Sx Resume Type, 0- S4, S5 or G3; 1 S3, deep S3 for Intel Rapid Start Tech.
    UINT32 Reserved2           : 1;  ///< 11 - Reserved
    UINT32 AllTpmDisconnected  : 1;  ///< 12 - All TPMs Disconnected
    UINT32 Reserved3           : 1;  ///< 13 - Reserved
    UINT32 BootGuardFwStsValid : 1;  ///< 14 - Boot Guard FWSTS Valid
    UINT32 BootGuardSelfTest   : 1;  ///< 15 - Boot Guard Self Test
    UINT32 Reserved4           : 16; ///< 31:16 - Reserved
  } r;
} HECI_FW_STS4_REGISTER;

///
/// HFSTS5, offset 68h
///
typedef union {
  UINT32  ul;
  struct {
    UINT32 AcmActived       : 1;  ///< 0 - Boot Guard ACM Active STS, 0 - Unknown Boot Guard ACM status; 1 - Boot Guard ACM is active
    UINT32 VLD              : 1;  ///< 1 - Valid Bit, 0 - HFSTS#5 Bits [7:2] are invalid, 1 - Valid.
    UINT32 RCS              : 1;  ///< 2 - Result Code Source, 0 - Boot Guard ACM; 1 - CPU Microcode
    UINT32 ESC              : 5;  ///< 7:3 - Error Status Code
    UINT32 AcmDone          : 1;  ///< 8 - Boot Guard ACM DONE STS, 0 - Boot Guard ACM is not done; 1 - Boot Guard ACM is done
    UINT32 Smtc             : 7;  ///< 15:9 - Startup Module Timeout Count
    UINT32 ScrtmIndicator   : 1;  ///< 16 - S-CRTM Indicator
    UINT32 IncAcmSvn        : 4;  ///< 20:17 - Increment Boot Guard ACM Security Version Number
    UINT32 IncKmSvn         : 4;  ///< 24:21 - Increment Key Manifest Security Version Number
    UINT32 IncBpmSvn        : 4;  ///< 28:25 - Increment Boot Policy Manifest Security Version Number
    UINT32 Reserved         : 2;  ///< 30:29 - Reserved
    UINT32 StartEnforcement : 1;  ///< 31 - Start Enforcement, 0 - no action; 1 - PCH starts the error enforcement logic
  } r;
} HECI_FW_STS5_REGISTER;

///
/// HFSTS6, offset 6Ch
///
typedef union {
  UINT32  ul;
  struct {
    UINT32 ForceBootPolicy    : 1;  ///< 0 - Force Boot Guard ACM Boot Policy
    UINT32 CpuDebugDisabled   : 1;  ///< 1 - CPU Debug Disabled
    UINT32 BspInitDisabled    : 1;  ///< 2 - BSP Initialization Disabled
    UINT32 PBE                : 1;  ///< 3 - Protect BIOS Environment Policy
    UINT32 Reserved           : 2;  ///< 5:4 - Reserved
    UINT32 ENF                : 2;  ///< 7:6 - Error Enforcement Policy
    UINT32 MeasuredBootPolicy : 1;  ///< 8 - Measured Boot Policy, 0 - Disabled; 1 - Enabled
    UINT32 VerifiedBootPolicy : 1;  ///< 9 - Verified Boot Policy
    UINT32 AcmSvn             : 4;  ///< 13:10 - Boot Guard ACM Security Version Number
    UINT32 KvmSvn             : 4;  ///< 17:14 - Key Manifest Security Version Number
    UINT32 BpmSvn             : 4;  ///< 21:18 - Boot Policy Manifest Security Version Number
    UINT32 KmId               : 4;  ///< 25:22 - Key Manifest ID
    UINT32 ExeStatus          : 1;  ///< 26 - BSP Boot Policy Manifest Execution Status
    UINT32 Error              : 1;  ///< 27 - CPU encountered an unexpected error and is asking FW to start the enforcement logic.
    UINT32 BootGuardDisable   : 1;  ///< 28 - Boot Guard Disable
    UINT32 FpfDisable         : 1;  ///< 29 - Field Programmable Fuses (FPF) Disable
    UINT32 FpfSocConfigLock   : 1;  ///< 30 - Field Programmable Fuses (FPF) SOC Configuration Lock
    UINT32 TxtSupport         : 1;  ///< 31 - TXT Support
  } r;
} HECI_FW_STS6_REGISTER;

//
// ME Current State Values
//
#define ME_STATE_RESET        0x00
#define ME_STATE_INIT         0x01
#define ME_STATE_RECOVERY     0x02
#define ME_STATE_DISABLED     0x04
#define ME_STATE_NORMAL       0x05
#define ME_STATE_DISABLE_WAIT 0x06
#define ME_STATE_TRANSITION   0x07
#define ME_STATE_INVALID_CPU  0x08
#define ME_STATE_DFX_FW       0x0F

//
// ME Firmware FwInitComplete
//
#define ME_FIRMWARE_COMPLETED   0x01
#define ME_FIRMWARE_INCOMPLETED 0x00

//
// ME Boot Options Present
//
#define ME_BOOT_OPTIONS_PRESENT     0x01
#define ME_BOOT_OPTIONS_NOT_PRESENT 0x00

//
// ME Operation State Values
//
#define ME_OPERATION_STATE_PREBOOT  0x00
#define ME_OPERATION_STATE_M0_UMA   0x01
#define ME_OPERATION_STATE_M3       0x04
#define ME_OPERATION_STATE_M0       0x05
#define ME_OPERATION_STATE_BRINGUP  0x06
#define ME_OPERATION_STATE_M0_ERROR 0x07

//
// ME Error Code Values
//
#define ME_ERROR_CODE_NO_ERROR      0x00
#define ME_ERROR_CODE_UNKNOWN       0x01
#define ME_ERROR_CODE_DISABLED      0x02
#define ME_ERROR_CODE_IMAGE_FAILURE 0x03
#define ME_ERROR_CODE_DEBUG_FAILURE 0x04

//
// Management Engine Current Operation Mode
//
#define ME_OPERATION_MODE_NORMAL            0x00
#define ME_OPERATION_MODE_DEBUG             0x02
#define ME_OPERATION_MODE_SOFT_TEMP_DISABLE 0x03
#define ME_OPERATION_MODE_SECOVR_JMPR       0x04
#define ME_OPERATION_MODE_SECOVR_HECI_MSG   0x05
#define ME_OPERATION_MODE_SPS_IGNITION      0x07 // Ignition SPS firmware is running in ME
#define ME_OPERATION_MODE_SPS               0x0F // SPS firmware is running in ME

#pragma pack()

#endif // _HECI_REGS_H_
