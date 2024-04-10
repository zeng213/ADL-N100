/** @file
  function definitions for internal to shell functions.

  (C) Copyright 2014 Hewlett-Packard Development Company, L.P.<BR>
  Copyright (c) 2019 - 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent

**/

#ifndef _SHELL_GPIO_APP_H_
#define _SHELL_GPIO_APP_H_

#include <Uefi.h>

#include <Library/MemoryAllocationLib.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/ShellCEntryLib.h>
#include <Library/SortLib.h>
#include <Library/ShellLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/ShellCommandLib.h>
#include <Library/IoLib.h>
#include <Library/BaseMemoryLib.h>

#include <Protocol/SimpleFileSystem.h>
#include <Protocol/ShellParameters.h>
#include <Protocol/Shell.h>

#include <Guid/FileInfo.h>

typedef struct {
  UINT8   Magic[4]; // "SBL\0"
  UINT8   Version;  // 1
  UINT8   Cmd;      // 1: gpiodump
  UINT8   BoardId;
  UINT8   RevGpioTmpFormat; // revision of gpio template format
  UINT8   DswGrpIdx; // DSW gpio group index. "0xff" if not exist
  UINT8   reserved[7];
} BIN_HEADER;

BIN_HEADER *mHeader;

typedef struct {
    UINT8   Name[8];
    UINT16  GrpId;
    UINT16  PinNum;
    UINT32  PadCfg0Addr;
    UINT32  PadCfg1Addr; 
} PAD_INFO_STRUCT;

PAD_INFO_STRUCT *mPadInfo;

typedef union {
  struct {
    UINT32  GPIOTXSTATE     : 1;
    UINT32  GPIORXSTATE     : 1;
    UINT32  Rsvd1           : 6;
    UINT32  GPIOTXDIS       : 1;
    UINT32  GPIORXDIS       : 1;
    UINT32  PMODE           : 2;
    UINT32  Rsvd2           : 5;
    UINT32  GPIROUTNMI      : 1;
    UINT32  GPIROUTSMI      : 1;
    UINT32  GPIROUTSCI      : 1;
    UINT32  GPIROUTIOXAPIC  : 1;
    UINT32  RXTXENCFG       : 2;
    UINT32  RXINV           : 1;
    UINT32  PREGFRXSEL      : 1;
    UINT32  RXEVCFG         : 2;
    UINT32  Rsvd3           : 1;
    UINT32  RXRAW1          : 1;
    UINT32  RXPADSTSEL      : 1;
    UINT32  PADRSTCFG       : 2;
  } PAD_CFG;
    UINT32  PadCfgVal;
} BIOS_PAD_CFG_0;

typedef union {
  struct {
    UINT32  INTSEL          : 8;
    UINT32  Rsvd1           : 2;
    UINT32  TERM            : 4;
    UINT32  Rsvd2           : 18;
  } PAD_CFG;
    UINT32  PadCfgVal;
} BIOS_PAD_CFG_1;

typedef union {
  struct {
    UINT32  PadMode         : 5;
    UINT32  HostSoftPadOwn  : 2;
    UINT32  Direction       : 6;
    UINT32  OutputState     : 2;
    UINT32  InterruptConfig : 9;
    UINT32  PowerConfig     : 8;
  } DW;
    UINT32  DwVal;
} SBL_DW0;

typedef union {
  struct {
    UINT32  ElectricalCfg   : 9;
    UINT32  LockConfig      : 4;
    UINT32  Rsvd1           : 3;
    UINT32  PadNum          : 8;
    UINT32  GrpIdx          : 5;
    UINT32  Rsvd2           : 1;
    UINT32  Hide            : 1;
    UINT32  Skip            : 1;
  } DW;
    UINT32  DwVal;
} SBL_DW1;

/**
  GPIO interrupt configuration
  This setting is applicable only if pad is in GPIO mode and has input enabled.
  GPIO_INT_CONFIG allows to choose which interrupt is generated (IOxAPIC/SCI/SMI/NMI)
  and how it is triggered (edge or level). Refer to PADCFG_DW0 register description in
  EDS for details on this settings.
  Field from GpioIntNmi to GpioIntApic can be OR'ed with GpioIntLevel to GpioIntBothEdge
  to describe an interrupt e.g. GpioIntApic | GpioIntLevel
  If GPIO is set to cause an SCI then also GPI_GPE_EN is enabled for this pad.
  If GPIO is set to cause an NMI then also GPI_NMI_EN is enabled for this pad.
  Not all GPIO are capable of generating an SMI or NMI interrupt.
  When routing GPIO to cause an IOxAPIC interrupt care must be taken, as this
  interrupt cannot be shared and its IRQn number is not configurable.
  Refer to EDS for GPIO pads IRQ numbers (PADCFG_DW1.IntSel)
  If GPIO is under GPIO OS driver control and appropriate ACPI GpioInt descriptor
  exist then use only trigger type setting (from GpioIntLevel to GpioIntBothEdge).
  This type of GPIO Driver interrupt doesn't have any additional routing setting
  required to be set by BIOS. Interrupt is handled by GPIO OS Driver.
**/

typedef enum {
  GpioIntDefault           = 0x0,  ///< Leave value of interrupt routing unmodified
  GpioIntDis               = 0x1,  ///< Disable IOxAPIC/SCI/SMI/NMI interrupt generation
  GpioIntNmi               = 0x3,  ///< Enable NMI interrupt only
  GpioIntSmi               = 0x5,  ///< Enable SMI interrupt only
  GpioIntSci               = 0x9,  ///< Enable SCI interrupt only
  GpioIntApic              = 0x11, ///< Enable IOxAPIC interrupt only
  GpioIntLevel       = (0x1 << 5), ///< Set interrupt as level triggered
  GpioIntEdge        = (0x3 << 5), ///< Set interrupt as edge triggered (type of edge depends on input inversion)
  GpioIntLvlEdgDis   = (0x5 << 5), ///< Disable interrupt trigger
  GpioIntBothEdge    = (0x7 << 5)  ///< Set interrupt as both edge triggered
} GPIO_INT_CONFIG;

/**
  GPIO LockConfiguration
  Set GPIO configuration lock and output state lock.
  GpioPadConfigUnlock/Lock and GpioOutputStateUnlock can be OR'ed.
  By default GPIO pads will be locked unless GPIO lib is explicitly
  informed that certain pad is to be left unlocked.
  Lock settings reset is in Powergood domain. Care must be taken when using this setting
  as fields it locks may be reset by a different signal and can be controlled
  by what is in GPIO_RESET_CONFIG (PADCFG_DW0.PadRstCfg). GPIO library provides
  functions which allow to unlock a GPIO pad. If possible each GPIO lib function will try to unlock
  an already locked pad upon request for reconfiguration
**/
typedef enum {
  /**
  Perform default action
   - if pad is an GPO, lock configuration but leave output unlocked
   - if pad is an GPI, lock everything
   - if pad is in native, lock everything
**/
  GpioLockDefault       = 0x0,
  GpioPadConfigUnlock   = 0x3,  ///< Leave Pad configuration unlocked
  GpioPadConfigLock     = 0x1,  ///< Lock Pad configuration
  GpioOutputStateUnlock = 0xC,  ///< Leave Pad output control unlocked
  GpioPadUnlock         = 0xF,  ///< Leave both Pad configuration and output control unlocked
  GpioPadLock           = 0x5   ///< Lock both Pad configuration and output control
} GPIO_LOCK_CONFIG;

#define B_GPIO_LOCK_CONFIG_PAD_CONF_LOCK_MASK  0x3  ///< Mask for GPIO_LOCK_CONFIG for Pad Configuration Lock
#define B_GPIO_LOCK_CONFIG_OUTPUT_LOCK_MASK    0xC  ///< Mask for GPIO_LOCK_CONFIG for Pad Output Lock

/**
  GPIO Power Configuration
  GPIO_RESET_CONFIG allows to set GPIO Reset type (PADCFG_DW0.PadRstCfg) which will
  be used to reset certain GPIO settings.
  Refer to EDS for settings that are controllable by PadRstCfg.
**/
typedef enum {
  GpioResetDefault   = 0x00,        ///< Leave value of pad reset unmodified
  /**
  Resume Reset (RSMRST)
    GPP: PadRstCfg = 00b = "Powergood"
    GPD: PadRstCfg = 11b = "Resume Reset"
  Pad setting will reset on:
  - DeepSx transition
  - G3
  Pad settings will not reset on:
  - S3/S4/S5 transition
  - Warm/Cold/Global reset
  **/
  GpioResumeReset      = 0x01,
  /**
  Host Deep Reset
    PadRstCfg = 01b = "Deep GPIO Reset"
  Pad settings will reset on:
  - Warm/Cold/Global reset
  - DeepSx transition
  - G3
  Pad settings will not reset on:
  - S3/S4/S5 transition
  **/
  GpioHostDeepReset    = 0x03,
  /**
  Platform Reset (PLTRST)
    PadRstCfg = 10b = "GPIO Reset"
  Pad settings will reset on:
  - S3/S4/S5 transition
  - Warm/Cold/Global reset
  - DeepSx transition
  - G3
  **/
  GpioPlatformReset    = 0x05,
  /**
  Deep Sleep Well Reset (DSW_PWROK)
    GPP: not applicable
    GPD: PadRstCfg = 00b = "Powergood"
  Pad settings will reset on:
  - G3
  Pad settings will not reset on:
  - S3/S4/S5 transition
  - Warm/Cold/Global reset
  - DeepSx transition
  **/
  GpioDswReset         = 0x07,
  /**
    Global reset. Server chipsets only.
      PadRstCfg = 11b = "Global reset"
    Pad settings will reset on:
    - Global reset
    - G3
    Pad settings will not reset on:
    - S3/S4/S5 transition
    - Warm/Cold reset
    - DeepSx transition
  **/
  GpioGlobalReset      = 0x09
} GPIO_RESET_CONFIG;

GPIO_RESET_CONFIG  GppPadRstCfgToGpioResetConfigMap[] = {
                            GpioResumeReset,
                            GpioHostDeepReset,
                            GpioPlatformReset,
                            GpioGlobalReset};
GPIO_RESET_CONFIG  GpdPadRstCfgToGpioResetConfigMap[] = {
                            GpioDswReset,
                            GpioHostDeepReset,
                            GpioPlatformReset,
                            GpioResumeReset};


#endif //_SHELL_GPIO_APP_H_

