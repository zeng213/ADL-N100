/** @file
  UFS platform driver header file for Intel platforms.

@copyright
  INTEL CONFIDENTIAL
  Copyright 2021 Intel Corporation.

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
#include <Uefi.h>
#include <Protocol/PciIo.h>
#include <Protocol/UfsHostControllerPlatform.h>

#ifndef _UFS_PLATFORM_HCI_H_
#define _UFS_PLATFORM_HCI_H_

#define UFS_HC_IS_OFFSET           0x0020  // Interrupt Status
#define UFS_HC_IS_UPMS             BIT4
#define UFS_TIMEOUT                EFI_TIMER_PERIOD_SECONDS(3)

#define UFS_UIC_ARG_MIB_SEL(x,y)   ((((x) & 0xFFFF) << 16) | ((y) & 0xFFFF))
#define UFS_PA_HS_MODE_A           0x1
#define UFS_PA_HS_MODE_B           0x2
#pragma pack(1)
//
// UIC command opcodes
//
typedef enum {
  UfsUicDmeGet            = 0x01,
  UfsUicDmeSet            = 0x02,
  UfsUicDmePeerGet        = 0x03,
  UfsUicDmePeerSet        = 0x04,
  UfsUicDmePwrOn          = 0x10,
  UfsUicDmePwrOff         = 0x11,
  UfsUicDmeEnable         = 0x12,
  UfsUicDmeReset          = 0x14,
  UfsUicDmeEndpointReset  = 0x15,
  UfsUicDmeLinkStartup    = 0x16,
  UfsUicDmeHibernateEnter = 0x17,
  UfsUicDmeHibernateExit  = 0x18,
  UfsUicDmeTestMode       = 0x1A
} UFS_UIC_OPCODE;

typedef enum {
  UfsRxLane                = 0,
  UfsTxLane                = 1,
  UfsReservedLane
} UFS_LANE_TYPE;

typedef enum {
  Fast_Mode     = 1,
  Slow_Mode     = 2,
  FastAuto_Mode = 4,
  SlowAuto_Mode = 5,
  UNCHANGED     = 7,
  UfsReservedPowerMode
} UFS_POWER_MODE;

typedef enum {
  PWM_G1 = 1,
  PWM_G2 = 2,
  PWM_G3 = 3,
  PWM_G4 = 4,
  PWM_G5 = 5,
  PWM_G6 = 6,
  PWM_G7 = 7,
  UfsReservedPwmGear
} UFS_PWM_GEARS;

typedef enum {
  NO_HS  = 0,
  HS_G1  = 1,
  HS_G2  = 2,
  HS_G3  = 3,
  HS_G4  = 4,
  UfsReservedHsGear
} UFS_HS_GEARS;

typedef enum {
  PA_ActiveRxDataLanes                = 0x1580,
  PA_ConnectedRxDataLanes             = 0x1581,
  PA_AvailRxDataLanes                 = 0x1540,
  PA_RXGear                           = 0x1583,
  PA_MaxRxPWMGear                     = 0x1586,
  PA_MaxRxHSGear                      = 0x1587,
  PA_RxPWRStatus                      = 0x1582,
  PA_RxTermination                    = 0x1584,
  PA_ActiveTxDataLanes                = 0x1560,
  PA_ConnectedTxDataLanes             = 0x1561,
  PA_AvailTxDataLanes                 = 0x1520,
  PA_TXGear                           = 0x1568,
  PA_TxPWRStatus                      = 0x1567,
  PA_TxTermination                    = 0x1569,
  PA_HSSeries                         = 0x156A,
  PA_PWRMode                          = 0x1571,
  PA_Scrambling                       = 0x1585,
  PA_TxHsAdaptType                    = 0x15D4,
  PA_AdaptTypeInPA_INIT               = 0x15D5,
  PA_Local_TX_LCC_Enable              = 0x155E,
  PA_Peer_TX_LCC_Enable               = 0x155F,
  PA_Reserved                         = 0xFFFF
} PA_ATTRIBUTES;

typedef enum {
  DL_FC0ProtectionTimeOutVal         = 0x15B0,
  DL_TC0ReplayTimeOutVal             = 0x15B1,
  DL_AFC0ReqTimeOutVal               = 0x15B2,
  DL_Reserved                        = 0xFFFF
} DL_ATTRIBUTES;

/**
  Switches the link Power Mode and Gear.

  @param[in] Private The pointer to the UFS_PASS_THRU_PRIVATE_DATA data structure

  @retval EFI_SUCCESS  Successfully switched the Power Mode and Gear
  @retval others       Failed to switch the Power Mode and Gear
**/
VOID
UfsHcPlatformPostHceSwithGear (
  IN EFI_HANDLE                     ControllerHandle,
  IN EFI_PCI_IO_PROTOCOL            *PciIo,
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  );

#pragma pack()

#endif


