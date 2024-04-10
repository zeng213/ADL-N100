/** @file
  This module update ACPI Firmware Performance Data Table (FPDT).

  This module register report status code listener to collect performance data
  for Firmware Basic Boot Performance Record and update ACPI FPDT.

  Copyright (c) 2011 - 2023, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <PiDxe.h>

#include <Protocol/ReportStatusCodeHandler.h>
#include <Protocol/AcpiTable.h>

#include <Guid/FirmwarePerformance.h>
#include <Guid/EventGroup.h>
#include <Guid/SystemTableInfoGuid.h>
#include <Guid/PerformanceInfoGuid.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PcdLib.h>
#include <Library/HobLib.h>
#include <Library/UefiLib.h>

EFI_RSC_HANDLER_PROTOCOL    *mRscHandlerProtocol           = NULL;
BOOT_PERFORMANCE_TABLE      *mBootPerfTable                = NULL;
BOOLEAN                     mDxeCoreReportStatusCodeEnable = FALSE;
EFI_EVENT                   mExitBootServicesEvent;
UINT32                      mTscFreqKhz;


/**
  Get current time

  Based on current TSC timer value and its frequency, get current time in nano seconds.

  @return    The current time in nano seconds.

**/
UINT64
GetCurrentTime (
  VOID
  )
{
  UINT64     TscValue;
  UINT64     TimeInMs;

  TscValue = AsmReadTsc();
  TimeInMs = DivU64x32 (TscValue, mTscFreqKhz);

  return MultU64x32 (TimeInMs, 1000000);
}

/**
  Find FPDT boot performance table from ACPI table

  @retval RETURN_SUCCESS     Successfully find out all the required information.
  @retval RETURN_NOT_FOUND   Failed to find the required info.

**/
RETURN_STATUS
GetFpdtBootPerfTable (
  VOID
  )
{
  EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER  *Rsdp;
  EFI_ACPI_DESCRIPTION_HEADER                   *Rsdt;
  UINT32                                        *Entry32;
  UINTN                                         Entry32Num;
  FIRMWARE_PERFORMANCE_TABLE                    *Fpdt;
  EFI_ACPI_DESCRIPTION_HEADER                   *Xsdt;
  UINT64                                        *Entry64;
  UINTN                                         Entry64Num;
  UINTN                                         Idx;
  EFI_HOB_GUID_TYPE                             *GuidHob;
  SYSTEM_TABLE_INFO                             *SystemTableInfo;

  GuidHob = GetFirstGuidHob (&gUefiSystemTableInfoGuid);
  if (GuidHob == NULL) {
    DEBUG ((EFI_D_INFO, "NOT found SystemTableInfo HOB.\n"));
    return EFI_NOT_FOUND;
  }

  SystemTableInfo  = (SYSTEM_TABLE_INFO *)GET_GUID_HOB_DATA (GuidHob);
  Rsdp = (EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER *)(UINTN)SystemTableInfo->AcpiTableBase;

  //
  // Search Rsdt First
  //
  Fpdt     = NULL;
  Rsdt     = (EFI_ACPI_DESCRIPTION_HEADER *)(UINTN)(Rsdp->RsdtAddress);
  if (Rsdt != NULL) {
    Entry32  = (UINT32 *)(Rsdt + 1);
    Entry32Num = (Rsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) >> 2;
    for (Idx = 0; Idx < Entry32Num; Idx++) {
      if (*(UINT32 *)(UINTN)(Entry32[Idx]) == EFI_ACPI_5_0_FIRMWARE_PERFORMANCE_DATA_TABLE_SIGNATURE) {
        Fpdt = (FIRMWARE_PERFORMANCE_TABLE *)(UINTN)(Entry32[Idx]);
        DEBUG ((EFI_D_INFO, "Found Fpdt in Rsdt\n"));
        goto Done;
      }
    }
  }

  //
  // Search Xsdt Second
  //
  Xsdt     = (EFI_ACPI_DESCRIPTION_HEADER *)(UINTN)(Rsdp->XsdtAddress);
  if (Xsdt != NULL) {
    Entry64  = (UINT64 *)(Xsdt + 1);
    Entry64Num = (Xsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER)) >> 3;
    for (Idx = 0; Idx < Entry64Num; Idx++) {
      if (*(UINT32 *)(UINTN)(Entry64[Idx]) == EFI_ACPI_5_0_FIRMWARE_PERFORMANCE_DATA_TABLE_SIGNATURE) {
        Fpdt = (FIRMWARE_PERFORMANCE_TABLE *)(UINTN)(Entry64[Idx]);
        DEBUG ((EFI_D_INFO, "Found Fpdt in Xsdt\n"));
        goto Done;
      }
    }
  }

  if (Fpdt == NULL) {
    return RETURN_NOT_FOUND;
  }

Done:
  mBootPerfTable = (BOOT_PERFORMANCE_TABLE *)(UINTN)Fpdt->BootPointerRecord.BootPerformanceTablePointer;
  ASSERT (mBootPerfTable->Header.Signature == EFI_ACPI_5_0_FPDT_BOOT_PERFORMANCE_TABLE_SIGNATURE);

  return RETURN_SUCCESS;
}


/**
  Report status code listener of FPDT. This is used to collect performance data
  for OsLoaderLoadImageStart and OsLoaderStartImageStart in FPDT.

  @param[in]  CodeType            Indicates the type of status code being reported.
  @param[in]  Value               Describes the current status of a hardware or software entity.
                                  This included information about the class and subclass that is used to
                                  classify the entity as well as an operation.
  @param[in]  Instance            The enumeration of a hardware or software entity within
                                  the system. Valid instance numbers start with 1.
  @param[in]  CallerId            This optional parameter may be used to identify the caller.
                                  This parameter allows the status code driver to apply different rules to
                                  different callers.
  @param[in]  Data                This optional parameter may be used to pass additional data.

  @retval EFI_SUCCESS             Status code is what we expected.
  @retval EFI_UNSUPPORTED         Status code not supported.

**/
EFI_STATUS
EFIAPI
FpdtStatusCodeListenerDxe (
  IN EFI_STATUS_CODE_TYPE     CodeType,
  IN EFI_STATUS_CODE_VALUE    Value,
  IN UINT32                   Instance,
  IN EFI_GUID                 *CallerId,
  IN EFI_STATUS_CODE_DATA     *Data
  )
{
  EFI_STATUS                   Status;

  //
  // Check whether status code is what we are interested in.
  //
  if ((CodeType & EFI_STATUS_CODE_TYPE_MASK) != EFI_PROGRESS_CODE) {
    return EFI_UNSUPPORTED;
  }
  
  if (Value == (EFI_SOFTWARE_DXE_CORE | EFI_SW_DXE_CORE_PC_HANDOFF_TO_NEXT)) {
    //
    // DxeCore ReportStatusCode Enable so that the capability can be supported.
    //
    mDxeCoreReportStatusCodeEnable = TRUE;
  }

  Status = EFI_SUCCESS;
  if (Value == PcdGet32 (PcdProgressCodeOsLoaderLoad)) {
    //
    // Update OS Loader LoadImage Start for UEFI boot.
    //
    mBootPerfTable->BasicBoot.OsLoaderLoadImageStart = GetCurrentTime ();
  } else if (Value == PcdGet32 (PcdProgressCodeOsLoaderStart)) {
    //
    // Update OS Loader StartImage Start for UEFI boot.
    //
    mBootPerfTable->BasicBoot.OsLoaderStartImageStart = GetCurrentTime ();
  } else if (Value == (EFI_SOFTWARE_EFI_BOOT_SERVICE | EFI_SW_BS_PC_EXIT_BOOT_SERVICES)) {
    //
    // Unregister boot time report status code listener.
    //
    mRscHandlerProtocol->Unregister (FpdtStatusCodeListenerDxe);

    //
    // Update ExitBootServicesExit for UEFI boot.
    //
    mBootPerfTable->BasicBoot.ExitBootServicesExit = GetCurrentTime ();
  } else {
    //
    // Ignore else progress code.
    //
    Status = EFI_UNSUPPORTED;
  }

  return Status;
}



/**
  Notify function for event EVT_SIGNAL_EXIT_BOOT_SERVICES. This is used to record
  performance data for ExitBootServicesEntry in FPDT.

  @param[in]  Event   The Event that is being processed.
  @param[in]  Context The Event Context.

**/
VOID
EFIAPI
FpdtExitBootServicesEventNotify (
  IN EFI_EVENT        Event,
  IN VOID             *Context
  )
{
  if (!mDxeCoreReportStatusCodeEnable) {
    //
    // When DxeCore Report Status Code is disabled, 
    // Unregister boot time report status code listener at ExitBootService Event.
    //
    mRscHandlerProtocol->Unregister (FpdtStatusCodeListenerDxe);
  }

  //
  // Update Firmware Basic Boot Performance Record for UEFI boot.
  //
  mBootPerfTable->BasicBoot.ExitBootServicesEntry = GetCurrentTime ();

  //
  // Dump FPDT Boot Performance record.
  //
  DEBUG ((EFI_D_INFO, "FPDT: -ResetEnd                = %ld\n", mBootPerfTable->BasicBoot.ResetEnd));
  DEBUG ((EFI_D_INFO, "FPDT: -OsLoaderLoadImageStart  = %ld\n", mBootPerfTable->BasicBoot.OsLoaderLoadImageStart));
  DEBUG ((EFI_D_INFO, "FPDT: -OsLoaderStartImageStart = %ld\n", mBootPerfTable->BasicBoot.OsLoaderStartImageStart));
  DEBUG ((EFI_D_INFO, "FPDT: -ExitBootServicesEntry   = %ld\n", mBootPerfTable->BasicBoot.ExitBootServicesEntry));
}


/**
  The module Entry Point of the Firmware Performance Data Table DXE driver.

  @param[in]  ImageHandle    The firmware allocated handle for the EFI image.
  @param[in]  SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS    The entry point is executed successfully.
  @retval Other          Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
FirmwarePerformanceDxeEntryPoint (
  IN EFI_HANDLE            ImageHandle,
  IN EFI_SYSTEM_TABLE      *SystemTable
  )
{
  EFI_STATUS               Status;
  EFI_HOB_GUID_TYPE        *GuidHob;
  PERFORMANCE_INFO         *PerfInfo;

  //
  // Get ACPI FPDT boot performance table
  //
  Status = GetFpdtBootPerfTable ();
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "NOT found Fpdt in ACPI table, abort to update it.\n"));
    return EFI_SUCCESS;
  }

  //
  // Get TSC frequency from performance data HOB
  //
  GuidHob = GetFirstGuidHob (&gLoaderPerformanceInfoGuid);
  if (GuidHob != NULL) {
    PerfInfo = (PERFORMANCE_INFO *)GET_GUID_HOB_DATA (GuidHob);
    mTscFreqKhz = PerfInfo->Frequency;
  }
  ASSERT (mTscFreqKhz != 0);

  //
  // Get Report Status Code Handler Protocol.
  //
  Status = gBS->LocateProtocol (&gEfiRscHandlerProtocolGuid, NULL, (VOID **) &mRscHandlerProtocol);
  ASSERT_EFI_ERROR (Status);

  //
  // Register report status code listener for OS Loader load and start.
  //
  Status = mRscHandlerProtocol->Register (FpdtStatusCodeListenerDxe, TPL_HIGH_LEVEL);
  ASSERT_EFI_ERROR (Status);

  //
  // Register the notify function to update FPDT on ExitBootServices Event.
  //
  Status = gBS->CreateEventEx (
                  EVT_NOTIFY_SIGNAL,
                  TPL_NOTIFY,
                  FpdtExitBootServicesEventNotify,
                  NULL,
                  &gEfiEventExitBootServicesGuid,
                  &mExitBootServicesEvent
                  );
  ASSERT_EFI_ERROR (Status);

  return EFI_SUCCESS;
}

