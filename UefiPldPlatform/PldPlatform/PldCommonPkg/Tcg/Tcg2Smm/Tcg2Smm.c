/** @file
  It updates TPM2 items in ACPI table and registers SMI2 callback
  functions for Tcg2 physical presence, ClearMemory, and sample
  for dTPM StartMethod.

  Caution: This module requires additional review when modified.
  This driver will have external input - variable and ACPINvs data in SMM mode.
  This external input must be validated carefully to avoid security issue.

  PhysicalPresenceCallback() and MemoryClearCallback() will receive untrusted input and do some check.

Copyright (c) 2015 - 2017, Intel Corporation. All rights reserved.<BR>
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "Tcg2Smm.h"

#include <Library/HobLib.h>
#include <Guid/LoaderFspInfoGuid.h>
#include <Guid/TpmEventLogInfoGuid.h>

EFI_SMM_VARIABLE_PROTOCOL  *mSmmVariable;
TCG_NVS                    *mTcgNvs;

/**
  Software SMI callback for TPM physical presence which is called from ACPI method.

  Caution: This function may receive untrusted input.
  Variable and ACPINvs are external input, so this function will validate
  its data structure to be valid value.

  @param[in]      DispatchHandle  The unique handle assigned to this handler by SmiHandlerRegister().
  @param[in]      Context         Points to an optional handler context which was specified when the
                                  handler was registered.
  @param[in, out] CommBuffer      A pointer to a collection of data in memory that will
                                  be conveyed from a non-SMM environment into an SMM environment.
  @param[in, out] CommBufferSize  The size of the CommBuffer.

  @retval EFI_SUCCESS             The interrupt was handled successfully.

**/
EFI_STATUS
EFIAPI
PhysicalPresenceCallback (
  IN EFI_HANDLE                  DispatchHandle,
  IN CONST VOID                  *Context,
  IN OUT VOID                    *CommBuffer,
  IN OUT UINTN                   *CommBufferSize
  )
{
  UINT32                MostRecentRequest;
  UINT32                Response;
  UINT32                OperationRequest;
  UINT32                RequestParameter;

  DEBUG ((EFI_D_INFO, "[TCG2SMM] Entering PhysicalPresenceCallback \n"));

  if (mTcgNvs->PhysicalPresence.Parameter == TCG_ACPI_FUNCTION_RETURN_REQUEST_RESPONSE_TO_OS) {
      DEBUG ((EFI_D_INFO, "[TCG2SMM]  TCG_ACPI_FUNCTION_RETURN_REQUEST_RESPONSE_TO_OS\n"));


    mTcgNvs->PhysicalPresence.ReturnCode = Tcg2PhysicalPresenceLibReturnOperationResponseToOsFunction (
                                             &MostRecentRequest,
                                             &Response
                                             );
    mTcgNvs->PhysicalPresence.LastRequest = MostRecentRequest;
    mTcgNvs->PhysicalPresence.Response = Response;
    return EFI_SUCCESS;
  } else if ((mTcgNvs->PhysicalPresence.Parameter == TCG_ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS)
          || (mTcgNvs->PhysicalPresence.Parameter == TCG_ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS_2)) {
    DEBUG ((EFI_D_INFO, "[TCG2SMM]  TCG_ACPI_FUNCTION_SUBMIT_REQUEST_TO_BIOS\n"));

    OperationRequest = mTcgNvs->PhysicalPresence.Request;
    RequestParameter = mTcgNvs->PhysicalPresence.RequestParameter;
    mTcgNvs->PhysicalPresence.ReturnCode = Tcg2PhysicalPresenceLibSubmitRequestToPreOSFunctionEx (
                                             &OperationRequest,
                                             &RequestParameter
                                             );
    mTcgNvs->PhysicalPresence.Request = OperationRequest;
    mTcgNvs->PhysicalPresence.RequestParameter = RequestParameter;
  } else if (mTcgNvs->PhysicalPresence.Parameter == TCG_ACPI_FUNCTION_GET_USER_CONFIRMATION_STATUS_FOR_REQUEST) {
    DEBUG ((EFI_D_INFO, "[TCG2SMM]  TCG_ACPI_FUNCTION_GET_USER_CONFIRMATION_STATUS_FOR_REQUEST\n"));
    mTcgNvs->PhysicalPresence.ReturnCode = Tcg2PhysicalPresenceLibGetUserConfirmationStatusFunction (mTcgNvs->PPRequestUserConfirm);
  }

    DEBUG ((EFI_D_INFO, "[TCG2SMM] Exiting PhysicalPresenceCallback\n"));

  return EFI_SUCCESS;
}


/**
  Software SMI callback for MemoryClear which is called from ACPI method.

  Caution: This function may receive untrusted input.
  Variable and ACPINvs are external input, so this function will validate
  its data structure to be valid value.

  @param[in]      DispatchHandle  The unique handle assigned to this handler by SmiHandlerRegister().
  @param[in]      Context         Points to an optional handler context which was specified when the
                                  handler was registered.
  @param[in, out] CommBuffer      A pointer to a collection of data in memory that will
                                  be conveyed from a non-SMM environment into an SMM environment.
  @param[in, out] CommBufferSize  The size of the CommBuffer.

  @retval EFI_SUCCESS             The interrupt was handled successfully.

**/
EFI_STATUS
EFIAPI
MemoryClearCallback (
  IN EFI_HANDLE                  DispatchHandle,
  IN CONST VOID                  *Context,
  IN OUT VOID                    *CommBuffer,
  IN OUT UINTN                   *CommBufferSize
  )
{
  EFI_STATUS                     Status;
  UINTN                          DataSize;
  UINT8                          MorControl;

  DEBUG ((EFI_D_INFO, "[TCG2SMM] Entering MemoryClearCallback\n"));

  mTcgNvs->MemoryClear.ReturnCode = MOR_REQUEST_SUCCESS;
  if (mTcgNvs->MemoryClear.Parameter == ACPI_FUNCTION_DSM_MEMORY_CLEAR_INTERFACE) {
    MorControl = (UINT8) mTcgNvs->MemoryClear.Request;

  } else if (mTcgNvs->MemoryClear.Parameter == ACPI_FUNCTION_PTS_CLEAR_MOR_BIT) {
    DataSize = sizeof (UINT8);
    Status = mSmmVariable->SmmGetVariable (
                             MEMORY_OVERWRITE_REQUEST_VARIABLE_NAME,
                             &gEfiMemoryOverwriteControlDataGuid,
                             NULL,
                             &DataSize,
                             &MorControl
                             );
    if (EFI_ERROR (Status)) {
      mTcgNvs->MemoryClear.ReturnCode = MOR_REQUEST_GENERAL_FAILURE;
      DEBUG ((EFI_D_ERROR, "[TPM] Get MOR variable failure! Status = %r\n", Status));
      return EFI_SUCCESS;
    }

    if (MOR_CLEAR_MEMORY_VALUE (MorControl) == 0x0) {
      return EFI_SUCCESS;
    }
    MorControl &= ~MOR_CLEAR_MEMORY_BIT_MASK;
  } else {
    mTcgNvs->MemoryClear.ReturnCode = MOR_REQUEST_GENERAL_FAILURE;
    DEBUG ((EFI_D_ERROR, "[TPM] MOR Parameter error! Parameter = %x\n", mTcgNvs->MemoryClear.Parameter));
    return EFI_SUCCESS;
  }

  DataSize = sizeof (UINT8);
  Status = mSmmVariable->SmmSetVariable (
                           MEMORY_OVERWRITE_REQUEST_VARIABLE_NAME,
                           &gEfiMemoryOverwriteControlDataGuid,
                           EFI_VARIABLE_NON_VOLATILE | EFI_VARIABLE_BOOTSERVICE_ACCESS | EFI_VARIABLE_RUNTIME_ACCESS,
                           DataSize,
                           &MorControl
                           );
  if (EFI_ERROR (Status)) {
    mTcgNvs->MemoryClear.ReturnCode = MOR_REQUEST_GENERAL_FAILURE;
    DEBUG ((EFI_D_ERROR, "[TPM] Set MOR variable failure! Status = %r\n", Status));
  }

  DEBUG ((EFI_D_INFO, "[TCG2SMM] Exiting MemoryClearCallback\n"));

  return EFI_SUCCESS;
}

/**
  Find the operation region in TCG ACPI table by given Name and Size,
  and initialize it if the region is found.

  @param[in, out] Table          The TPM item in ACPI table.
  @param[in]      Name           The name string to find in TPM table.
  @param[in]      Size           The size of the region to find.

  @return                        The allocated address for the found region.

**/
VOID *
AssignOpRegion (
  EFI_ACPI_DESCRIPTION_HEADER    *Table,
  UINT32                         Name,
  UINT16                         Size
  )
{
  EFI_STATUS                     Status;
  AML_OP_REGION_32_8             *OpRegion;
  EFI_PHYSICAL_ADDRESS           MemoryAddress;

  MemoryAddress = SIZE_4GB - 1;

  //
  // Patch some pointers for the ASL code before loading the SSDT.
  //
  for (OpRegion  = (AML_OP_REGION_32_8 *) (Table + 1);
       OpRegion <= (AML_OP_REGION_32_8 *) ((UINT8 *) Table + Table->Length);
       OpRegion  = (AML_OP_REGION_32_8 *) ((UINT8 *) OpRegion + 1)) {
    if ((OpRegion->OpRegionOp  == AML_EXT_REGION_OP) &&
        (OpRegion->NameString  == Name) &&
        (OpRegion->DWordPrefix == AML_DWORD_PREFIX) &&
        (OpRegion->BytePrefix  == AML_BYTE_PREFIX)) {

      Status = gBS->AllocatePages(AllocateMaxAddress, EfiACPIMemoryNVS, EFI_SIZE_TO_PAGES (Size), &MemoryAddress);
      ASSERT_EFI_ERROR (Status);
      ZeroMem ((VOID *)(UINTN)MemoryAddress, Size);
      OpRegion->RegionOffset = (UINT32) (UINTN) MemoryAddress;
      OpRegion->RegionLen    = (UINT8) Size;
      break;
    }
  }

  DEBUG ((EFI_D_INFO, "[TCG ACPI] Operation Region MemoryAddress  = 0x%lx\n", MemoryAddress));

  return (VOID *) (UINTN) MemoryAddress;
}


/**
  Calculates the checksum over ACPI table.

  @retval ACPI table checksum.
**/
UINT8 acpi_checksum(UINT8 *table, UINT32 length)
{
  UINT8 ret = 0;
  while (length--) {
    ret += *table;
    table++;
  }
  return -ret;
}


/**
  Find and update TPM items in ACPI table.

  @retval   EFI_SUCCESS     The TCG ACPI table is updated successfully.
  @retval   Others          The TCG ACPI table is not updated.

**/
EFI_STATUS
UpdateTpm2Table(
  )
{

  EFI_STATUS                                                 Status;
  EFI_ACPI_TABLE_PROTOCOL                                   *AcpiTableProtocol;
  EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER              *Rsdp;
  EFI_ACPI_DESCRIPTION_HEADER                               *Rsdt;
  EFI_ACPI_DESCRIPTION_HEADER                               *Table = NULL;
  UINT32                                                    Index;
  UINT32                                                    NumEntries;
  UINT32                                                    *TableAddr;

  Status = gBS->LocateProtocol (&gEfiAcpiTableGuid, NULL, (VOID **)&AcpiTableProtocol);
  ASSERT (EFI_ERROR(Status));

  //
  // Find ACPI table from system table
  //
  Rsdp = NULL;
  for (Index = 0, Rsdp = NULL; Index < gST->NumberOfTableEntries; Index++) {
    if ( CompareGuid (&(gST->ConfigurationTable[Index].VendorGuid), &gEfiAcpiTableGuid) ) {
      //
      // A match was found.
      //
      Rsdp = (EFI_ACPI_3_0_ROOT_SYSTEM_DESCRIPTION_POINTER *) gST->ConfigurationTable[Index].VendorTable;
      break;
    }
  }

  ASSERT (Rsdp != NULL);
  if (Rsdp == NULL) {
    return EFI_NOT_FOUND;
  }
  Rsdt = (EFI_ACPI_DESCRIPTION_HEADER *) (UINTN) Rsdp->RsdtAddress;
  NumEntries = (Rsdt->Length - sizeof(EFI_ACPI_DESCRIPTION_HEADER))/sizeof(UINT32);
  DEBUG ((EFI_D_INFO, "Rsdp = 0x%x, Rsdt- 0x%p, NumEntries - %u, Signature = 0x%x\n", Rsdp, Rsdt,
            NumEntries, Rsdt->Signature));

  for (Index = 0; Index < NumEntries; Index++)
  {
    TableAddr = (UINT32*)((UINT8*)Rsdt + sizeof(EFI_ACPI_DESCRIPTION_HEADER) + (sizeof(UINT32)*Index));
    Table =  (EFI_ACPI_DESCRIPTION_HEADER*)(UINTN)(*(TableAddr));
    if ((Table->Signature == SIGNATURE_32('S', 'S', 'D', 'T')) &&
        (Table->OemTableId == SIGNATURE_64 ('T', 'p', 'm', '2', 'T', 'a', 'b', 'l'))) {
      DEBUG ((EFI_D_INFO, "Found Tpm2Table\n"));
      break;
    }
  }

  if (Index == NumEntries) {
    return EFI_NOT_FOUND;
  }

  mTcgNvs = AssignOpRegion (Table, SIGNATURE_32 ('T', 'N', 'V', 'S'), (UINT16) sizeof (TCG_NVS));
  ASSERT (mTcgNvs != NULL);

  // Update Table Checksum
  Table->Checksum = 0;
  Table->Checksum = acpi_checksum((UINT8*)Table, Table->Length);

  return EFI_SUCCESS;
}



/**
  Checks if Measured Boot feature was disabled in bootloader or not.

  @retval TRUE    Measured Boot was disabled.
  @retval FALSE   Measured Boot was enabled.
**/
BOOLEAN
TpmDisabledInBootloader (
  VOID
  )
{
  EFI_HOB_GUID_TYPE                *GuidHob;
  LOADER_FSP_INFO                  *FspInfo;

  DEBUG ((EFI_D_INFO, "Check the tpm information from the bootloader.\n"));

  GuidHob = GetFirstGuidHob (&gLoaderFspInfoGuid);
  if (GuidHob == NULL) {
     DEBUG((EFI_D_ERROR, "ERROR when try to find FSP information HOB.\n"));
     ASSERT (FALSE);
  }

  FspInfo  = GET_GUID_HOB_DATA (GuidHob);
  if ( (FspInfo == NULL) || (FspInfo->MeasuredBoot == 0)) {
    DEBUG((EFI_D_INFO, "Measure boot is not enabled in bootloader. \n"));
    return TRUE;
  }

  return FALSE;
}


/**
  The driver's entry point.

  It install callbacks for TPM physical presence and MemoryClear, and locate
  SMM variable to be used in the callback function.

  @param[in] ImageHandle  The firmware allocated handle for the EFI image.
  @param[in] SystemTable  A pointer to the EFI System Table.

  @retval EFI_SUCCESS     The entry point is executed successfully.
  @retval Others          Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
InitializeTcgSmm (
  IN EFI_HANDLE                  ImageHandle,
  IN EFI_SYSTEM_TABLE            *SystemTable
  )
{
  EFI_STATUS                     Status;
  EFI_SMM_SW_DISPATCH2_PROTOCOL  *SwDispatch;
  EFI_SMM_SW_REGISTER_CONTEXT    SwContext;
  EFI_HANDLE                     SwHandle;

  if (!CompareGuid (PcdGetPtr(PcdTpmInstanceGuid), &gEfiTpmDeviceInstanceTpm20DtpmGuid) &&
      !CompareGuid (PcdGetPtr(PcdTpmInstanceGuid), &gTpmDeviceInstanceTpm20PttPtpGuid)) {
    DEBUG ((EFI_D_INFO, "No TPM2 DTPM or PTT instance required!\n"));
  }

  if (TpmDisabledInBootloader()) {
    DEBUG ((EFI_D_ERROR, "TPM is disabled in bootloader.\n"));
    return EFI_UNSUPPORTED;
  }

  //
  // Update TPM2 ACPI table
  //
  Status = UpdateTpm2Table();
  ASSERT_EFI_ERROR (Status);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "UpdateTpm2Table returned error\n"));
    return Status;
  }

  //
  // Get the Sw dispatch protocol and register SMI callback functions.
  //
  Status = gSmst->SmmLocateProtocol (&gEfiSmmSwDispatch2ProtocolGuid, NULL, (VOID**)&SwDispatch);
  ASSERT_EFI_ERROR (Status);
  SwContext.SwSmiInputValue = (UINTN) -1;
  Status = SwDispatch->Register (SwDispatch, PhysicalPresenceCallback, &SwContext, &SwHandle);
  ASSERT_EFI_ERROR (Status);
  if (EFI_ERROR (Status)) {
    return Status;
  }
  mTcgNvs->PhysicalPresence.SoftwareSmi = (UINT8) SwContext.SwSmiInputValue;

  SwContext.SwSmiInputValue = (UINTN) -1;
  Status = SwDispatch->Register (SwDispatch, MemoryClearCallback, &SwContext, &SwHandle);
  ASSERT_EFI_ERROR (Status);
  if (EFI_ERROR (Status)) {
    return Status;
  }
  mTcgNvs->MemoryClear.SoftwareSmi = (UINT8) SwContext.SwSmiInputValue;

  //
  // Locate SmmVariableProtocol.
  //
  Status = gSmst->SmmLocateProtocol (&gEfiSmmVariableProtocolGuid, NULL, (VOID**)&mSmmVariable);
  ASSERT_EFI_ERROR (Status);

  //
  // Todo: check if need update ACPI checksum since gnvs data is changed.
  //

  return EFI_SUCCESS;
}

