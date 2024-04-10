/** @file
  This library provides routines that help establish communication
  between bootloader and uefi payload.

  Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#include <PiSmm.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/IoLib.h>
#include <Library/BlSmmCommunicationLib.h>
#include <Protocol/SmmAccess2.h>

/**
  Get base and size of communication area

  @param[out] BlSmmCommInfo Pointer to Bootloader smm communication info structure

  @retval   EFI_NOT_FOUND     Struct with signature not found
  @retval   EFI_SUCCESS       Struct with signature found
**/
EFI_STATUS
EFIAPI
GetBlCommArea (
  OUT  BL_SMM_COMMUNICATION_INFO    *BlSmmCommInfo
  )
{
  EFI_STATUS                Status;
  EFI_SMRAM_DESCRIPTOR      *SmramRanges;
  EFI_SMM_ACCESS2_PROTOCOL  *SmmAccess;
  UINTN                     Size;
  UINTN                     SmramRangeCount;
  UINTN                     Index;

  if (BlSmmCommInfo == NULL){
    return EFI_INVALID_PARAMETER;
  }

  //
  // Get SMRAM range information
  //
  Status = gBS->LocateProtocol (&gEfiSmmAccess2ProtocolGuid, NULL, (VOID **)&SmmAccess);
  if (EFI_ERROR(Status)) {
    return Status;
  }

  //
  // Get SMRAM range information
  //
  Size = 0;
  SmramRanges = NULL;
  Status = SmmAccess->GetCapabilities (SmmAccess, &Size, NULL);
  if (Status == EFI_BUFFER_TOO_SMALL) {
    //
    // Allocate enough memory for smramranges
    //
    SmramRanges = (EFI_SMRAM_DESCRIPTOR *) AllocatePool (Size);
    if (SmramRanges == NULL) {
      return EFI_OUT_OF_RESOURCES;
    }
    Status = SmmAccess->GetCapabilities (SmmAccess, &Size, SmramRanges);
  }
  if (EFI_ERROR (Status) || (SmramRanges == NULL)) {
    goto GetBlCommAreaEnd;
  }

  //
  // Find the SMRAM address for  communication
  //
  SmramRangeCount = Size / sizeof (EFI_SMRAM_DESCRIPTOR);
  for (Index = 0; Index < SmramRangeCount; Index++) {
    if (SmramRanges[Index].PhysicalSize == SIZE_4KB) {
      break;
    }
  }

  if (Index == SmramRangeCount) {
    DEBUG ((DEBUG_ERROR, "Could not find SMRAM Region for communication\n"));
    Status = EFI_NOT_FOUND;
    goto GetBlCommAreaEnd;
  }

  BlSmmCommInfo->SmmCommBase = (UINTN) SmramRanges[Index].PhysicalStart;
  BlSmmCommInfo->SmmCommSize = (UINTN) SmramRanges[Index].PhysicalSize;

GetBlCommAreaEnd:
  if (SmramRanges != NULL) {
    FreePool(SmramRanges);
  }

  return Status;
}

/**
  Get pointer to a specific struct area in TSEG

  @param[in] BlSmmCommInfo Pointer to Bootloader smm communication info structure
  @param[in] Id            Id of the struct to be retreived

  @retval   NULL           Struct with signature not found
  @retval   Ptr            Pointer to struct with signature
**/
VOID *
EFIAPI
GetBlCommData (
  IN  BL_SMM_COMMUNICATION_INFO *BlSmmCommInfo,
  IN  UINT8   Id
  )
{
  BOOLEAN           FoundInfo = FALSE;
  BL_PLD_COMM_HDR   *CommHdr;

  if (BlSmmCommInfo == NULL) {
    return NULL;
  }

  CommHdr = (BL_PLD_COMM_HDR *) (BlSmmCommInfo->SmmCommBase);
  while ( ((UINT8 *)CommHdr < (UINT8 *)BlSmmCommInfo->SmmCommBase + BlSmmCommInfo->SmmCommSize) &&
          CommHdr->Signature == BL_PLD_COMM_SIG) {
    if (CommHdr->Id == Id) {
      FoundInfo = TRUE;
      break;
    }
    CommHdr = (BL_PLD_COMM_HDR *) ((UINT8 *)CommHdr + CommHdr->TotalSize);
  }

  if (!FoundInfo) {
    DEBUG ((DEBUG_ERROR, "Could not find any structure with ID# %d in BL communication area\n", Id));
    return NULL;
  }

  return (VOID *) CommHdr;
}

/**
  This function set data in TSEG area
  designated for bootloader and payload communication purpose.

  @param[in] BlSmmCommInfo Pointer to Bootloader smm communication info structure
  @param[in] DataPtr       Address of the structure to be copied to TSEG

  @retval   EFI_OUT_OF_RESOURCES  If SmmSize is exceeding the range
  @retval   EFI_OUT_OF_RESOURCES  If appeding new struct exceeds SmmCommSize
  @retval   EFI_SUCCESS           Append is successful

**/
EFI_STATUS
EFIAPI
SetBlCommData (
  IN  BL_SMM_COMMUNICATION_INFO *BlSmmCommInfo,
  IN  VOID                      *DataPtr
  )
{
  BL_PLD_COMM_HDR   *CommHdr;

  if (BlSmmCommInfo == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  if (DataPtr == NULL) {
    return EFI_INVALID_PARAMETER;
  }

  if (((BL_PLD_COMM_HDR*)DataPtr)->Signature != BL_PLD_COMM_SIG) {
    return EFI_INVALID_PARAMETER;
  }

  CommHdr = (BL_PLD_COMM_HDR *) BlSmmCommInfo->SmmCommBase;

  if (CommHdr->Signature != BL_PLD_COMM_SIG) {
    return EFI_INVALID_PARAMETER;
  }

  while ( ((UINT8 *)CommHdr < (UINT8 *)BlSmmCommInfo->SmmCommBase + BlSmmCommInfo->SmmCommSize) &&
          CommHdr->Signature == BL_PLD_COMM_SIG) {
    CommHdr = (BL_PLD_COMM_HDR *) ((UINT8 *)CommHdr + CommHdr->TotalSize);
  }

  if ( (UINT8 *)CommHdr + ((BL_PLD_COMM_HDR*)DataPtr)->TotalSize > (UINT8 *)BlSmmCommInfo->SmmCommBase + BlSmmCommInfo->SmmCommSize ) {
    return EFI_OUT_OF_RESOURCES;
  }
  CopyMem ((VOID *)CommHdr, DataPtr, ((BL_PLD_COMM_HDR*)DataPtr)->TotalSize);

  return EFI_SUCCESS;
}
