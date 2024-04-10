/** @file
  UFS platform driver for Intel platforms.

@copyright
  INTEL CONFIDENTIAL
  Copyright 2020 - 2021 Intel Corporation.

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
#include "UfsPlatformHci.h"
#include <Uefi.h>
#include <Uefi/UefiMultiPhase.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/UefiLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/TimerLib.h>
#include <IndustryStandard/Pci.h>
#include <Protocol/PciIo.h>
#include <Protocol/UfsHostControllerPlatform.h>

#define UFS_PLATFORM_INTEL_VENDOR_ID  0x8086

/**
  Fill UIC Command associated fields.

  @param[in] UicOpcode        The opcode of the UIC command.
  @param[in] Arg1Mib          The value for MIB Attribute of UIC command 1st argument.
  @param[in] Arg1GenSel       The value for Gen Selector Index of UIC command 1st argument.
  @param[in] Arg2             The value for UIC command 2nd argument.
  @param[in] Arg3             The value for UIC command 3rd argument.
**/
VOID
UfsFillUicCommand (
  IN     UINT8             UicOpcode,
  IN     UINT16            Arg1Mib,
  IN     UINT16            Arg1GenSel,
  IN     UINT32            Arg2,
  IN     UINT32            Arg3,
  IN OUT EDKII_UIC_COMMAND *Cmd
  )
{
  Cmd->Opcode = UicOpcode;
  Cmd->Arg1   = UFS_UIC_ARG_MIB_SEL (Arg1Mib, Arg1GenSel);
  Cmd->Arg2   = Arg2;
  Cmd->Arg3   = Arg3;
}

/**
  Read 32bits data from specified UFS MMIO register.

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver
  @param[in]  Offset        The offset within the UFS Host Controller MMIO space to start
                            the memory operation.
  @param[out] Value         The data buffer to store.

  @retval EFI_TIMEOUT       The operation is time out.
  @retval EFI_SUCCESS       The operation succeeds.
  @retval Others            The operation fails.

**/
EFI_STATUS
UfsMmioRead32 (
  IN EDKII_UFS_HC_DRIVER_INTERFACE      *UfsHcDriverInterface,
  IN UINTN                               Offset,
    OUT UINT32                           *Value
  )
{
  EFI_STATUS                          Status;
  EDKII_UFS_HOST_CONTROLLER_PROTOCOL  *UfsHc;

  UfsHc = UfsHcDriverInterface->UfsHcProtocol;

  Status = UfsHc->Read (UfsHc, EfiUfsHcWidthUint32, Offset, 1, Value);

  return Status;
}

/**
  Write 32bits data to specified UFS MMIO register.

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver
  @param[in] Offset         The offset within the UFS Host Controller MMIO space to start
                            the memory operation.
  @param[in] Value          The data to write.

  @retval EFI_TIMEOUT       The operation is time out.
  @retval EFI_SUCCESS       The operation succeeds.
  @retval Others            The operation fails.

**/
EFI_STATUS
UfsMmioWrite32 (
  IN  EDKII_UFS_HC_DRIVER_INTERFACE      *UfsHcDriverInterface,
  IN  UINTN                              Offset,
  IN  UINT32                             Value
  )
{
  EFI_STATUS                          Status;
  EDKII_UFS_HOST_CONTROLLER_PROTOCOL  *UfsHc;

  UfsHc = UfsHcDriverInterface->UfsHcProtocol;

  Status = UfsHc->Write (UfsHc, EfiUfsHcWidthUint32, Offset, 1, &Value);

  return Status;
}

/**
  Wait for the value of the specified system memory set to the test value.

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver
  @param[in]  Offset        The offset within the UFS Host Controller MMIO space to start
                            the memory operation.
  @param[in]  MaskValue     The mask value of memory.
  @param[in]  TestValue     The test value of memory.
  @param[in]  Timeout       The time out value for wait memory set, uses 100ns as a unit.

  @retval EFI_TIMEOUT       The system memory setting is time out.
  @retval EFI_SUCCESS       The system memory is correct set.
  @retval Others            The operation fails.

**/
EFI_STATUS
UfsWaitMemSet (
  IN  EDKII_UFS_HC_DRIVER_INTERFACE      *UfsHcDriverInterface,
  IN  UINTN                              Offset,
  IN  UINT32                             MaskValue,
  IN  UINT32                             TestValue,
  IN  UINT64                             Timeout
  )
{
  UINT32     Value;
  UINT64     Delay;
  BOOLEAN    InfiniteWait;
  EFI_STATUS Status;

  if (Timeout == 0) {
    InfiniteWait = TRUE;
  } else {
    InfiniteWait = FALSE;
  }

  Delay = DivU64x32 (Timeout, 10) + 1;

  do {
    //
    // Access PCI MMIO space to see if the value is the tested one.
    //
    Status = UfsMmioRead32 (UfsHcDriverInterface, Offset, &Value);
    if (EFI_ERROR (Status)) {
      return Status;
    }

    Value &= MaskValue;

    if (Value == TestValue) {
      return EFI_SUCCESS;
    }

    //
    // Stall for 1 microseconds.
    //
    MicroSecondDelay (1);

    Delay--;

  } while (InfiniteWait || (Delay > 0));

  return EFI_TIMEOUT;
}

/**
  Detects the connected Ufs Lanes and Programs the Active Lanes Attribute.

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver

  @retval EFI_SUCCESS  Successfully Programmed the lanes
  @retval others       Failed to program the lanes
**/
EFI_STATUS
UfsActivateAllLanes (
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS         Status;
  UINT32             ConnectedLanes = 0;
  UINT32             ActiveLanes = 0;
  EDKII_UIC_COMMAND  UicCommand;

  //Step 1: Query connected and Active Rx lanes and make all conntected Rx lanes Active.
  UfsFillUicCommand (UfsUicDmeGet, PA_ConnectedRxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ConnectedRxDataLanes(%x) \n", PA_ConnectedRxDataLanes));
    return Status;
  }
  ConnectedLanes = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmeGet, PA_ActiveRxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ActiveRxDataLanes(%x) \n", PA_ActiveRxDataLanes));
    return Status;
  }
  ActiveLanes = UicCommand.Arg3;

  if (ActiveLanes < ConnectedLanes) {
    DEBUG ((DEBUG_INFO, "UfsActivateAllLanes : PA_ActiveRxDataLanes = %x  PA_ConnectedRxDataLanes = %x\n", ActiveLanes, ConnectedLanes));
    UfsFillUicCommand (UfsUicDmeSet, PA_ActiveRxDataLanes, 0, 0, ConnectedLanes, &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to set active Rx data lanes\n"));
      return Status;
    }
  }

  //Step 2: Query connected and Active Tx lanes and make all conntected Tx lanes Active.
  UfsFillUicCommand (UfsUicDmeGet, PA_ConnectedTxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ConnectedTxDataLanes(%x)\n", PA_ConnectedTxDataLanes));
    return Status;
  }
  ConnectedLanes = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmeGet, PA_ActiveTxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ActiveTxDataLanes(%x) \n", PA_ActiveTxDataLanes));
    return Status;
  }
  ActiveLanes = UicCommand.Arg3;

  if (ActiveLanes < ConnectedLanes) {
    DEBUG ((DEBUG_INFO, "UfsActivateAllLanes : PA_ActiveTxDataLanes = %x  PA_ConnectedTxDataLanes = %x\n", ActiveLanes, ConnectedLanes));
    UfsFillUicCommand (UfsUicDmeSet, PA_ActiveTxDataLanes, 0, 0, ConnectedLanes, &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to set active Tx data lanes\n"));
      return Status;
    }
  }

  return Status;
}

/**
  Dumps the link Configuration.
  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver

  @retval EFI_SUCCESS  Successfully switched to fast mode
  @retval others       Failed to switch to fast mode
**/
EFI_STATUS
UfsDumpLinkConfig (
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS         Status;
  EDKII_UIC_COMMAND  UicCommand;

  DEBUG ((DEBUG_INFO, "UfsDumpLinkConfig Entry \n"));

  UfsFillUicCommand (UfsUicDmeGet, PA_Local_TX_LCC_Enable, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_Local_TX_LCC_Enable(%x)\n", PA_Local_TX_LCC_Enable));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_Local_TX_LCC_Enable(%x) = %x \n", PA_Local_TX_LCC_Enable, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_MaxRxHSGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_MaxRxHSGear(%x)\n", PA_MaxRxHSGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_MaxRxHSGear(%x) = %x \n", PA_MaxRxHSGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmePeerGet, PA_MaxRxHSGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmePeerGet PA_MaxRxHSGear(%x)\n", PA_MaxRxHSGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmePeerGet PA_MaxRxHSGear(%x) = %x \n", PA_MaxRxHSGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_MaxRxPWMGear(%x)\n", PA_MaxRxPWMGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_MaxRxPWMGear(%x) = %x \n", PA_MaxRxPWMGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmePeerGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmePeerGet PA_MaxRxPWMGear(%x)\n", PA_MaxRxPWMGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmePeerGet PA_MaxRxPWMGear(%x) = %x \n", PA_MaxRxPWMGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_AvailTxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_AvailTxDataLanes(%x)\n", PA_AvailTxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_AvailTxDataLanes(%x) = %x \n", PA_AvailTxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_AvailRxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_AvailRxDataLanes(%x)\n", PA_AvailRxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_AvailRxDataLanes(%x) = %x \n", PA_AvailRxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_ConnectedTxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ConnectedTxDataLanes(%x)\n", PA_ConnectedTxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_ConnectedTxDataLanes(%x) = %x \n", PA_ConnectedTxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_ConnectedRxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ConnectedRxDataLanes(%x)\n", PA_ConnectedRxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_ConnectedRxDataLanes(%x) = %x \n", PA_ConnectedRxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_ActiveTxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ActiveTxDataLanes(%x)\n", PA_ActiveTxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_ActiveTxDataLanes(%x) = %x \n", PA_ActiveTxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_ActiveRxDataLanes, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_ActiveRxDataLanes(%x)\n", PA_ActiveRxDataLanes));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_ActiveRxDataLanes(%x) = %x \n", PA_ActiveRxDataLanes, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_TxPWRStatus, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_TxPWRStatus(%x)\n", PA_TxPWRStatus));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_TxPWRStatus(%x) = %x \n", PA_TxPWRStatus, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_RxPWRStatus, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_RxPWRStatus(%x)\n", PA_RxPWRStatus));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_RxPWRStatus(%x) = %x \n", PA_RxPWRStatus, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, DL_FC0ProtectionTimeOutVal, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet DL_FC0ProtectionTimeOutVal(%x)\n", DL_FC0ProtectionTimeOutVal));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet DL_FC0ProtectionTimeOutVal(%x) = %x \n", DL_FC0ProtectionTimeOutVal, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, DL_TC0ReplayTimeOutVal, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet DL_TC0ReplayTimeOutVal(%x)\n", DL_TC0ReplayTimeOutVal));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet DL_TC0ReplayTimeOutVal(%x) = %x \n", DL_TC0ReplayTimeOutVal, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, DL_AFC0ReqTimeOutVal, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet DL_AFC0ReqTimeOutVal(%x)\n", DL_AFC0ReqTimeOutVal));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet DL_AFC0ReqTimeOutVal(%x) = %x \n", DL_AFC0ReqTimeOutVal, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_TXGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_TXGear(%x)\n", PA_TXGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_TXGear(%x) = %x \n", PA_TXGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_TxTermination, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_TxTermination(%x)\n", PA_TxTermination));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_TxTermination(%x) = %x \n", PA_TxTermination, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_HSSeries, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_HSSeries(%x)\n", PA_HSSeries));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_HSSeries(%x) = %x \n", PA_HSSeries, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_RXGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_RXGear(%x)\n", PA_RXGear));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_RXGear(%x) = %x \n", PA_RXGear, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_RxTermination, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_RxTermination(%x)\n", PA_RxTermination));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_RxTermination(%x) = %x \n", PA_RxTermination, UicCommand.Arg3));

  UfsFillUicCommand (UfsUicDmeGet, PA_HSSeries, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_HSSeries(%x)\n", PA_HSSeries));
  }
  DEBUG ((DEBUG_INFO, "UfsUicDmeGet PA_HSSeries(%x) = %x \n", PA_HSSeries, UicCommand.Arg3));

  DEBUG ((DEBUG_INFO, "UfsDumpLinkConfig Exit \n"));
  return EFI_SUCCESS;
}

/**
  Checks if given UFS controller is an Intel design.

  @param[in] PciIo  PciIo protocol handle for the controller

  @retval TRUE   Device is Intel design
  @retval FALSE  Device is not Intel design
**/
BOOLEAN
IsIntelUfsDevice (
  IN EFI_PCI_IO_PROTOCOL  *PciIo
  )
{
  EFI_STATUS  Status;
  UINT16      VendorId;

  Status = PciIo->Pci.Read (
    PciIo,
    EfiPciIoWidthUint16,
    PCI_VENDOR_ID_OFFSET,
    1,
    &VendorId
    );
  if (EFI_ERROR (Status)) {
    return FALSE;
  }

  if (VendorId == UFS_PLATFORM_INTEL_VENDOR_ID) {
    return TRUE;
  } else {
    return FALSE;
  }
}

/**
  Allows platform protocol to override host controller information

  @param[in]      ControllerHandle  Handle of the UFS controller.
  @param[in, out] HcInfo            Pointer EDKII_UFS_HC_INFO associated with host controller.

  @retval EFI_SUCCESS            Function completed successfully.
  @retval EFI_INVALID_PARAMETER  HcInfo is NULL.
  @retval Others                 Function failed to complete.
**/
EFI_STATUS
EFIAPI
UfsHcPlatformOverrideHcInfo (
  IN     EFI_HANDLE         ControllerHandle,
  IN OUT EDKII_UFS_HC_INFO  *HcInfo
  )
{
  return EFI_SUCCESS;
}

/**
  Applies platform specific programming after the driver
  has enabled the host controller.

  @param[in] ControllerHandle      Handle of the UFS controller
  @param[in] PciIo                 Associated PciIo protocol
  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver
**/
VOID
UfsHcPlatformPostHce (
  IN EFI_HANDLE                     ControllerHandle,
  IN EFI_PCI_IO_PROTOCOL            *PciIo,
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EDKII_UIC_COMMAND  LccDisableCommand;

  if (UfsHcDriverInterface == NULL) {
    return;
  }

  //
  // For all supported integrated controllers we have to disable the
  // line configuration check(LCC).
  //
  UfsFillUicCommand (UfsUicDmeSet, PA_Local_TX_LCC_Enable, 0, 0, 0, &LccDisableCommand );
  UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &LccDisableCommand);
}

/**
  Switches the link to highest supported PWM Gear.

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver

  @retval EFI_SUCCESS  Successfully switched to PWM Gear
  @retval others       Failed to switch to PWM Gear
**/
EFI_STATUS
UfsPwmGearSwitch (
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS         Status;
  UINT32             MaxPwmGear[] = {PWM_G1, PWM_G1};
  EDKII_UIC_COMMAND  UicCommand;

  Status = UfsActivateAllLanes (UfsHcDriverInterface);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to activate connected UFS Lanes \n"));
    return Status;
  }

  UfsFillUicCommand (UfsUicDmeGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to Get UfsUicDmeGet PA_MaxRxPWMGear(%x) \n", PA_MaxRxPWMGear));
    return Status;
  }
  MaxPwmGear[UfsRxLane] = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmePeerGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to Get UfsUicDmePeerGet PA_MaxRxPWMGear(%x) \n", PA_MaxRxPWMGear));
    return Status;
  }
  MaxPwmGear[UfsTxLane] = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmeSet, PA_RXGear, 0, 0, MaxPwmGear[UfsRxLane], &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to set UfsUicDmeSet PA_RXGear \n"));
    return Status;
  }

  UfsFillUicCommand (UfsUicDmeSet, PA_TXGear, 0, 0, MaxPwmGear[UfsTxLane], &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to set UfsUicDmeSet PA_TXGear \n"));
    return Status;
  }

  //
  // Change Power Mode of both directions
  //
  UfsFillUicCommand (UfsUicDmeSet, PA_PWRMode, 0, 0, (((SlowAuto_Mode & 0xF) << 4) | (SlowAuto_Mode & 0xF)), &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to set PA_PWRMode(%x) \n", PA_PWRMode));
    return Status;
  }
  Status = UfsWaitMemSet (UfsHcDriverInterface, UFS_HC_IS_OFFSET, UFS_HC_IS_UPMS, UFS_HC_IS_UPMS, UFS_TIMEOUT);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "UfsPwmGearSwitch: Failed to switch power mode\n"));
    return EFI_DEVICE_ERROR;
  }

  return EFI_SUCCESS;
}

/**
  Programs the recipe required for High speed link Power Mode and Gear switch

  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver

  @retval EFI_SUCCESS  Successfully programmed the recipe
  @retval others       Failed to program the recipe
**/
EFI_STATUS
UfsHsRecipieProgramming (
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS         Status;
  EDKII_UIC_COMMAND  UicCommand;

  UfsFillUicCommand (UfsUicDmeSet, DL_FC0ProtectionTimeOutVal, 0, 0, 0x1FFF, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to set active FC0 protection time out value\n"));
    return Status;
  }
  UfsFillUicCommand (UfsUicDmeSet, DL_TC0ReplayTimeOutVal, 0, 0, 0xFFFF, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to set active TC0 replay time out value\n"));
    return Status;
  }
  UfsFillUicCommand (UfsUicDmeSet, DL_AFC0ReqTimeOutVal, 0, 0, 0x7FFF, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
   DEBUG ((DEBUG_ERROR, "Failed to set active AFC0 req time out value\n"));
    return Status;
  }
  UfsFillUicCommand (UfsUicDmeSet, PA_HSSeries, 0, 0, UFS_PA_HS_MODE_B, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
  DEBUG ((DEBUG_ERROR, "Failed to enable rate B\n"));
  return Status;
  }
  UfsFillUicCommand (UfsUicDmeSet, PA_RxTermination, 0, 0, 0x1, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to enable Rx termination\n"));
    return Status;
  }
  UfsFillUicCommand (UfsUicDmeSet, PA_TxTermination, 0, 0, 0x1, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to enable Tx termination\n"));
    return Status;
  }
  return Status;
}

/**
  Switches the link Power Mode and Gear.

  @param[in] ControllerHandle      Handle of the UFS controller
  @param[in] PciIo                 Associated PciIo protocol
  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver

  @retval EFI_SUCCESS  Successfully switched the Power Mode and Gear
  @retval others       Failed to switch the Power Mode and Gear
**/
EFI_STATUS
UfsPowerModeAndGearSwitch (
  IN EFI_HANDLE                     ControllerHandle,
  IN EFI_PCI_IO_PROTOCOL            *PciIo,
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS         Status;
  UINT32             PowerMode[] = {Fast_Mode, Fast_Mode};
  UINT32             MaxHsGear[] = {HS_G1, HS_G1};
  UINT32             CurrentHsGear[] = {NO_HS, NO_HS};
  UINT32             MaxPwmGear[] = {PWM_G1, PWM_G1};
  EDKII_UIC_COMMAND  UicCommand;

  DEBUG ((DEBUG_INFO, "UfsPowerModeAndGearSwitch Entry: \n" ));
  //
  //Step 1: Program Lanes
  //
  Status = UfsActivateAllLanes (UfsHcDriverInterface);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Program UFS Lanes \n"));
    return Status;
  }
  //
  //Step 2: Query Max HS Gear and Max PWM Gears and if no HS gear, set PowerMode to SlowAuto
  //
  UfsFillUicCommand (UfsUicDmeGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_MaxRxPWMGear(%x)\n", PA_MaxRxPWMGear));
    return Status;
  }
  MaxPwmGear[UfsRxLane] = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmeGet, PA_MaxRxHSGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeGet PA_MaxRxHSGear(%x) \n", PA_MaxRxHSGear));
    return Status;
  }
  MaxHsGear[UfsRxLane] = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmePeerGet, PA_MaxRxPWMGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmePeerGet PA_MaxRxPWMGear(%x) \n",PA_MaxRxPWMGear));
    return Status;
  }
  MaxPwmGear[UfsTxLane] = UicCommand.Arg3;

  UfsFillUicCommand (UfsUicDmePeerGet, PA_MaxRxHSGear, 0, 0, 0, &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmePeerGet PA_MaxRxHSGear(%x) \n", PA_MaxRxHSGear));
    return Status;
  }
  MaxHsGear[UfsTxLane] = UicCommand.Arg3;

  //
  //Step 3: Mark the Power Mode as SlowAuto_Mode
  //
  if ((NO_HS == MaxHsGear[UfsRxLane]) || (NO_HS == MaxHsGear[UfsTxLane])) {
    PowerMode[UfsRxLane] = SlowAuto_Mode;
    PowerMode[UfsTxLane] = SlowAuto_Mode;
  }

  DEBUG ((DEBUG_INFO, "PowerMode[UfsRxLane] = %x \n", PowerMode[UfsRxLane]));
  DEBUG ((DEBUG_INFO, "PowerMode[UfsTxLane] = %x \n", PowerMode[UfsTxLane]));
  DEBUG ((DEBUG_INFO, "MaxHsGear[UfsRxLane] = %x \n", MaxHsGear[UfsRxLane]));
  DEBUG ((DEBUG_INFO, "MaxHsGear[UfsTxLane] = %x \n", MaxHsGear[UfsTxLane]));
  DEBUG ((DEBUG_INFO, "MaxPwmGear[UfsRxLane] = %x \n", MaxPwmGear[UfsRxLane]));
  DEBUG ((DEBUG_INFO, "MaxPwmGear[UfsTxLane] = %x \n", MaxPwmGear[UfsTxLane]));

  //
  //Step 4: Set Rx gear
  //
  if (PowerMode[UfsRxLane] == SlowAuto_Mode) {
    UfsFillUicCommand (UfsUicDmeSet, PA_RXGear, 0, 0, MaxPwmGear[UfsRxLane], &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to set UfsUicDmeSet PA_RXGear \n"));
      return Status;
    }
  } else {
    if (MaxHsGear[UfsRxLane] > HS_G3) {
      MaxHsGear[UfsRxLane] = HS_G3;
      DEBUG ((DEBUG_INFO, "Limited MaxHsGear to %x \n", MaxHsGear[UfsRxLane]));
    }

    UfsFillUicCommand (UfsUicDmeGet, PA_RXGear, 0, 0, 0, &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to set UfsUicDmeSet PA_RXGear \n"));
      return Status;
    }
    CurrentHsGear[UfsRxLane] = UicCommand.Arg3;

    if (CurrentHsGear[UfsRxLane] < MaxHsGear[UfsRxLane]) {
      DEBUG ((DEBUG_INFO, "CurrentHsGear[UfsRxLane] = %x switching to MaxHsGear[UfsRxLane]=%x \n", CurrentHsGear[UfsRxLane], MaxHsGear[UfsRxLane]));
      UfsFillUicCommand (UfsUicDmeSet, PA_RXGear, 0, 0, MaxHsGear[UfsRxLane], &UicCommand );
      Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "Failed to set UfsUicDmeSet PA_RXGear \n"));
        return Status;
      }
    }
  }
  //
  //Step 5: Set Tx gear
  //
  if (PowerMode[UfsTxLane] == SlowAuto_Mode) {
    UfsFillUicCommand (UfsUicDmeSet, PA_TXGear, 0, 0, MaxPwmGear[UfsTxLane], &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to set UfsUicDmeSet PA_TXGear \n"));
      return Status;
    }
  } else {
    if (MaxHsGear[UfsTxLane] > HS_G3) {
      MaxHsGear[UfsTxLane] = HS_G3;
      DEBUG ((DEBUG_INFO, "Limited MaxHsGear to %x \n", MaxHsGear[UfsTxLane]));
    }
    UfsFillUicCommand (UfsUicDmeGet, PA_TXGear, 0, 0, 0, &UicCommand );
    Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
    if (EFI_ERROR (Status)) {
      DEBUG ((DEBUG_ERROR, "Failed to Get UfsUicDmeSet PA_TXGear \n"));
      return Status;
    }
    CurrentHsGear[UfsTxLane] = UicCommand.Arg3;
    if (CurrentHsGear[UfsTxLane] < MaxHsGear[UfsRxLane]) {
      DEBUG ((DEBUG_INFO, "CurrentHsGear[UfsTxLane] = %x switching to MaxHsGear[UfsTxLane]=%x \n", CurrentHsGear[UfsTxLane], MaxHsGear[UfsTxLane]));
      UfsFillUicCommand (UfsUicDmeSet, PA_TXGear, 0, 0, MaxHsGear[UfsTxLane], &UicCommand );
      Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
      if (EFI_ERROR (Status)) {
        DEBUG ((DEBUG_ERROR, "Failed to set UfsUicDmeSet PA_TXGear \n"));
        return Status;
      }
    }
  }
  //
  //Step 6: Program the Intel platform specific recipe required for High speed link Power Mode and Gear switch
  //
  Status = UfsHsRecipieProgramming (UfsHcDriverInterface);
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "UfsHsRecipieProgramming Fails, Status = %r\n", Status));
  }
  //
  // Step 7 Change Power Mode of both directions
  //
  UfsFillUicCommand (UfsUicDmeSet, PA_PWRMode, 0, 0, (((PowerMode[UfsRxLane] & 0xF) << 4) | (PowerMode[UfsTxLane] & 0xF)), &UicCommand );
  Status = UfsHcDriverInterface->UfsExecUicCommand (UfsHcDriverInterface, &UicCommand);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to set PA_PWRMode(%x) \n", PA_PWRMode));
    return Status;
  }

  Status = UfsWaitMemSet (UfsHcDriverInterface, UFS_HC_IS_OFFSET, UFS_HC_IS_UPMS, UFS_HC_IS_UPMS, UFS_TIMEOUT);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to switch power mode\n"));
    return EFI_DEVICE_ERROR;
  }

  DEBUG ((DEBUG_INFO, "Dump LinkConfig After UfsPowerModeAndGearSwitch\n"));
  Status = UfsDumpLinkConfig (UfsHcDriverInterface);
  if (EFI_ERROR (Status)) {
    DEBUG ((DEBUG_ERROR, "Failed to Dump LinkConfig\n"));
  }

  DEBUG ((DEBUG_INFO, "UfsPowerModeAndGearSwitch Exit\n" ));
  return EFI_SUCCESS;
}

/**
  Switches the link Power Mode and Gear.

  @param[in] ControllerHandle      Handle of the UFS controller
  @param[in] PciIo                 Associated PciIo protocol
  @param[in] UfsHcDriverInterface  Interface to the functionalities provided by core driver
**/
VOID
UfsHcPlatformPostHceSwithGear (
  IN EFI_HANDLE                     ControllerHandle,
  IN EFI_PCI_IO_PROTOCOL            *PciIo,
  IN EDKII_UFS_HC_DRIVER_INTERFACE  *UfsHcDriverInterface
  )
{
  EFI_STATUS                         Status;

  DEBUG ((DEBUG_INFO, "UfsHcPlatformPostHceSwithGear Entry\n" ));
  if (UfsHcDriverInterface == NULL) {
    DEBUG((DEBUG_ERROR, "UfsHcPlatformPostHceSwithGear UfsHcDriverInterface is NULL\n"));
    return;
  }
  Status = UfsPwmGearSwitch (UfsHcDriverInterface);
  if (EFI_ERROR (Status)) {
    DEBUG((DEBUG_ERROR, "UfsPwmGearSwitch Fails, Status = %r\n", Status));
  }
  Status = UfsPowerModeAndGearSwitch(ControllerHandle, PciIo, UfsHcDriverInterface);
  if (EFI_ERROR(Status)) {
    DEBUG((DEBUG_ERROR, "UfsPowerModeAndGearSwitch Fails, Status = %r\n", Status));
  }
  DEBUG ((DEBUG_INFO, "UfsHcPlatformPostHceSwithGear Exit\n" ));
}

/**
  Callback function for platform driver.

  @param[in]      ControllerHandle  Handle of the UFS controller.
  @param[in]      CallbackPhase     Specifies when the platform protocol is called
  @param[in, out] CallbackData      Data specific to the callback phase.
                                    For PreHce and PostHce - EDKII_UFS_HC_DRIVER_INTERFACE.
                                    For PreLinkStartup and PostLinkStartup - EDKII_UFS_HC_DRIVER_INTERFACE.

  @retval EFI_SUCCESS            Override function completed successfully.
  @retval EFI_INVALID_PARAMETER  CallbackPhase is invalid or CallbackData is NULL when phase expects valid data.
  @retval Others                 Function failed to complete.
**/
EFI_STATUS
EFIAPI
UfsHcPlatformCallback (
  IN     EFI_HANDLE                            ControllerHandle,
  IN     EDKII_UFS_HC_PLATFORM_CALLBACK_PHASE  CallbackPhase,
  IN OUT VOID                                  *CallbackData
  )
{
  EFI_STATUS           Status;
  EFI_PCI_IO_PROTOCOL  *PciIo;

  Status = gBS->HandleProtocol (
                  ControllerHandle,
                  &gEfiPciIoProtocolGuid,
                  (VOID *) &PciIo
                  );
  if (EFI_ERROR (Status)) {
    return Status;
  }

  if (!IsIntelUfsDevice (PciIo)) {
    return EFI_SUCCESS;
  }

  if (CallbackPhase == EdkiiUfsHcPostHce) {
    UfsHcPlatformPostHce (
      ControllerHandle,
      PciIo,
      (EDKII_UFS_HC_DRIVER_INTERFACE*) CallbackData
      );
  }

  if (CallbackPhase == EdkiiUfsHcPostLinkStartup) {
    UfsHcPlatformPostHceSwithGear (
      ControllerHandle,
      PciIo,
      (EDKII_UFS_HC_DRIVER_INTERFACE*) CallbackData
      );
  }

  return EFI_SUCCESS;
}

GLOBAL_REMOVE_IF_UNREFERENCED EDKII_UFS_HC_PLATFORM_PROTOCOL  gEdkiiUfsHcPlatformProtocol = {
  EDKII_UFS_HC_PLATFORM_PROTOCOL_VERSION,
  UfsHcPlatformOverrideHcInfo,
  UfsHcPlatformCallback
};

/**
  Entry point for UFS platform driver for Intel platforms

  @param[in] ImageHandle  This image handle
  @param[in] SystemTable  System table pointer
**/
EFI_STATUS
EFIAPI
UfsPlatformDriverEntryPoint (
  IN EFI_HANDLE         ImageHandle,
  IN EFI_SYSTEM_TABLE   *SystemTable
  )
{
  EFI_HANDLE  ProtocolHandle;

  ProtocolHandle = NULL;
  return gBS->InstallProtocolInterface (
                &ProtocolHandle,
                &gEdkiiUfsHcPlatformProtocolGuid,
                EFI_NATIVE_INTERFACE,
                (VOID*)&gEdkiiUfsHcPlatformProtocol
                );
}

