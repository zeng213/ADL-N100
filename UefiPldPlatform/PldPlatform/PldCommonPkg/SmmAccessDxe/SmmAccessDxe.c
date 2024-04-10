/** @file
  This is the driver that publishes the SMM Access Protocol.

  Copyright (c) 2014 - 2022, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiDxe.h>

#include <Protocol/SmmAccess2.h>
#include <Protocol/SmmControl2.h>
#include <Library/HobLib.h>
#include <Library/BaseLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/BaseMemoryLib.h>
#include "SmmAccessDxe.h"
#include <Guid/LoaderSmmInfoGuid.h>
//
// Module variable hold the instance of SMM_ACCESS_PRIVATE_DATA
// 
SMM_ACCESS_PRIVATE_DATA  mSmmAccess;

/**
  This is the constructor for the SMM Access protocol.

  This function installs EFI_SMM_ACCESS_PROTOCOL.

  @param  ImageHandle Handle for the image of this driver
  @param  SystemTable Pointer to the EFI System Table

  @retval EFI_UNSUPPORTED There's no Intel ICH on this platform
  @return The status returned from InstallProtocolInterface().

--*/

EFI_STATUS
EFIAPI
SmmAccessDriverEntryPoint (
  IN EFI_HANDLE                 ImageHandle,
  IN EFI_SYSTEM_TABLE           *SystemTable
  )
{
  EFI_STATUS                    Status;
  LOADER_SMM_INFO               *LdrSmmInfo;
  EFI_HOB_GUID_TYPE             *GuidHob;
  UINT32                        SmmCommSize;

  //
  // Initialize Global variables
  //
  ZeroMem (&mSmmAccess, sizeof (mSmmAccess));
  mSmmAccess.Handle = NULL;
  
  //
  // Get SMRAM info HOB
  //
  LdrSmmInfo = NULL;
  GuidHob = GetFirstGuidHob (&gSmmInformationGuid);
  if (GuidHob == NULL) {
    ASSERT (FALSE);
    return EFI_NOT_FOUND;
  }
  LdrSmmInfo = (VOID *) (GET_GUID_HOB_DATA(GuidHob));

  SmmCommSize = 0;
  if ((LdrSmmInfo->Flags & SMM_FLAGS_4KB_COMMUNICATION) != 0) {
    // Reserve 4KB for communication interface between bootloader and payload
    SmmCommSize = SIZE_4KB;
  }

  DEBUG ((EFI_D_INFO, "SmmAccess: SmmBase = 0x%x, SmmSize = 0x%x\n", LdrSmmInfo->SmmBase, LdrSmmInfo->SmmSize));
  DEBUG ((EFI_D_INFO, "SmmAccess: Flags = 0x%x, SmmCommSize=0x%x\n", LdrSmmInfo->Flags, SmmCommSize));

  //
  // Allocate buffer for all the SMRAM descriptorst
  // Here, only one smm descriptor, as bootloader only reports one SMM region(T seg)
  //
  mSmmAccess.SmramDesc = AllocateZeroPool (sizeof (EFI_SMRAM_DESCRIPTOR) * 2);
  if (mSmmAccess.SmramDesc == NULL) {
    ASSERT (FALSE);
    return EFI_OUT_OF_RESOURCES;
  }

  //
  // Fill the SMRAM descriptor
  //
  mSmmAccess.SmramDesc[0].PhysicalStart = LdrSmmInfo->SmmBase + SmmCommSize;
  mSmmAccess.SmramDesc[0].CpuStart      = LdrSmmInfo->SmmBase + SmmCommSize;
  mSmmAccess.SmramDesc[0].PhysicalSize  = LdrSmmInfo->SmmSize - SmmCommSize;
  mSmmAccess.SmramDesc[0].RegionState   = EFI_SMRAM_CLOSED | EFI_CACHEABLE;

  //
  // Fill the communication 4KB SMRAM descriptor
  //
  mSmmAccess.SmramDesc[1].PhysicalStart = LdrSmmInfo->SmmBase;
  mSmmAccess.SmramDesc[1].CpuStart      = LdrSmmInfo->SmmBase;
  mSmmAccess.SmramDesc[1].PhysicalSize  = SmmCommSize;
  mSmmAccess.SmramDesc[1].RegionState   = EFI_SMRAM_CLOSED | EFI_CACHEABLE | EFI_ALLOCATED;

  mSmmAccess.NumberRegions               = 2;
  mSmmAccess.SmmAccess.Open              = Open;
  mSmmAccess.SmmAccess.Close             = Close;
  mSmmAccess.SmmAccess.Lock              = Lock;
  mSmmAccess.SmmAccess.GetCapabilities   = GetCapabilities;
  mSmmAccess.SmmAccess.LockState         = FALSE;
  mSmmAccess.SmmAccess.OpenState         = FALSE;
  mSmmAccess.SMMRegionState              = EFI_SMRAM_CLOSED;

  //
  // Install our protocol interfaces on the device's handle
  //
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &mSmmAccess.Handle,
                  &gEfiSmmAccess2ProtocolGuid, &mSmmAccess.SmmAccess,
                  NULL
                  );
                  
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_ERROR, "SmmAccess:Failed to install SmmAccess2 protocol(%r)\n", Status));
    return EFI_UNSUPPORTED;
  }

  return EFI_SUCCESS;
}

/**
   This routine accepts a request to "open" a region of SMRAM.  The
   region could be legacy ABSEG, HSEG, or TSEG near top of physical memory.
   The use of "open" means that the memory is visible from all boot-service
   and SMM agents.

   @param This                    Pointer to the SMM Access Interface.
   
   @retval EFI_SUCCESS            The region was successfully opened.
   @retval EFI_DEVICE_ERROR       The region could not be opened because locked by chipset.
   @retval EFI_INVALID_PARAMETER  The descriptor index was out of bounds.

**/
EFI_STATUS
EFIAPI
Open (
  IN EFI_SMM_ACCESS2_PROTOCOL  *This
  )
{
  DEBUG ((EFI_D_INFO, "SmmAccess: Open SMRAM Region\n"));
  if (((UINT32) mSmmAccess.SMMRegionState) & EFI_SMRAM_LOCKED) {
    //
    // Cannot open a "locked" region
    //
    DEBUG ((EFI_D_INFO, "SmmAccess: Cannot open the locked SMRAM Region\n"));
    return EFI_DEVICE_ERROR;
  }
    
  mSmmAccess.SMMRegionState &= ~(EFI_SMRAM_CLOSED | EFI_ALLOCATED);
  SyncRegionState2SmramDesc(FALSE, (UINT64)(UINTN)(~(EFI_SMRAM_CLOSED | EFI_ALLOCATED)));

  mSmmAccess.SMMRegionState |= EFI_SMRAM_OPEN;
  SyncRegionState2SmramDesc(TRUE, EFI_SMRAM_OPEN);
  mSmmAccess.SmmAccess.OpenState = TRUE;

  return EFI_SUCCESS;

}

/**
   This routine accepts a request to "close" a region of SMRAM.  The
   region could be legacy AB or TSEG near top of physical memory.
   The use of "close" means that the memory is only visible from SMM agents,
   not from BS or RT code.

   @param This                      Pointer to the SMM Access Interface.
   
   @retval EFI_SUCCESS              The region was successfully closed.
   @retval EFI_DEVICE_ERROR         The region could not be closed because locked by
                                    chipset.
   @retval EFI_INVALID_PARAMETER    The descriptor index was out of bounds.

**/
EFI_STATUS
EFIAPI
Close (
  IN EFI_SMM_ACCESS2_PROTOCOL    *This
  )
{

  DEBUG ((EFI_D_INFO, "SmmAccess: Prepare to close the SMRAM\n"));

  if (mSmmAccess.SMMRegionState & EFI_SMRAM_LOCKED) {
    //
    // Cannot close a "locked" region
    //
    DEBUG ((EFI_D_INFO, "SmmAccess:Cannot close the locked SMRAM Region\n"));
    return EFI_DEVICE_ERROR;
  }

  if (((UINT32) mSmmAccess.SMMRegionState) & EFI_SMRAM_CLOSED) {
    return EFI_DEVICE_ERROR;
  }

  mSmmAccess.SMMRegionState &= ~EFI_SMRAM_OPEN;
  SyncRegionState2SmramDesc(FALSE, (UINT64)(UINTN)(~EFI_SMRAM_OPEN)); 
  mSmmAccess.SMMRegionState |= (EFI_SMRAM_CLOSED | EFI_ALLOCATED);
  SyncRegionState2SmramDesc(TRUE, EFI_SMRAM_CLOSED | EFI_ALLOCATED); 
  mSmmAccess.SmmAccess.OpenState = FALSE;
  DEBUG ((EFI_D_INFO, "SmmAccess:Close SMRAM Region, success!\n"));

  return EFI_SUCCESS;

}

/**
   This routine accepts a request to "lock" SMRAM.  The
   region could be legacy AB or TSEG near top of physical memory.
   The use of "lock" means that the memory can no longer be opened
   to BS state.

   @param This                     Pointer to the SMM Access Interface.
   
   @retval EFI_SUCCESS             The region was successfully locked.
   @retval EFI_DEVICE_ERROR        The region could not be locked because at least
                                   one range is still open.
   @retval EFI_INVALID_PARAMETER   The descriptor index was out of bounds.

**/
EFI_STATUS
EFIAPI
Lock (
  IN EFI_SMM_ACCESS2_PROTOCOL    *This
  )
{
#if 0 // used for coreboot before
  EFI_SMM_CONTROL2_PROTOCOL  *SmmControl2;
  UINT8                       CmdPort;
  EFI_STATUS                  Status;
#endif

  DEBUG ((EFI_D_INFO, "SmmAccess: Prepare to lock SMRAM Region\n"));

  if (mSmmAccess.SmmAccess.OpenState) {
    DEBUG ((EFI_D_INFO, "SmmAccess: Cannot lock SMRAM when SMRAM regions are still open\n"));
    return EFI_DEVICE_ERROR;
  }

#if 0 // used for coreboot before
  //
  // Send SMI to coreboot and let it lock the smm ram
  //
  //
  // Get SMM Control2 Protocol
  //
  Status = gBS->LocateProtocol (&gEfiSmmControl2ProtocolGuid, NULL, (VOID **)&SmmControl2);
  ASSERT_EFI_ERROR (Status);

  //
  // Generate Software SMI
  //
  CmdPort = 0xCF;
  Status = SmmControl2->Trigger (SmmControl2, &CmdPort, NULL, FALSE, 0);
  if (EFI_ERROR (Status)) {
    DEBUG ((EFI_D_INFO, "Cannot lock SMRAM when trigger smi, Status = %r\n", Status));
    return EFI_DEVICE_ERROR;
  }
#endif

  mSmmAccess.SMMRegionState |= EFI_SMRAM_LOCKED;
  SyncRegionState2SmramDesc(TRUE, EFI_SMRAM_LOCKED); 
  mSmmAccess.SmmAccess.LockState = TRUE;
  DEBUG ((EFI_D_INFO, "SmmAccess: Locked SMM success!\n"));
  return EFI_SUCCESS;
}

/**
   This routine services a user request to discover the SMRAM
   capabilities of this platform.  This will report the possible
   ranges that are possible for SMRAM access, based upon the
   memory controller capabilities.

   @param This            Pointer to the SMRAM Access Interface.
   @param SmramMapSize    Pointer to the variable containing size of the
                          buffer to contain the description information.
   @param SmramMap        Buffer containing the data describing the Smram
                          region descriptors.
   
   @retval EFI_BUFFER_TOO_SMALL  The user did not provide a sufficient buffer.
   @retval EFI_SUCCESS           The user provided a sufficiently-sized buffer.

**/
EFI_STATUS
EFIAPI
GetCapabilities (
  IN CONST EFI_SMM_ACCESS2_PROTOCOL     *This,
  IN OUT   UINTN                        *SmramMapSize,
  IN OUT   EFI_SMRAM_DESCRIPTOR         *SmramMap
  )
{
  EFI_STATUS                Status;
  UINTN                     NecessaryBufferSize;

  NecessaryBufferSize = mSmmAccess.NumberRegions * sizeof(EFI_SMRAM_DESCRIPTOR);

#if 0
  DEBUG ((EFI_D_INFO, "SmmAccess: NecessaryBufferSize = 0x%x\n", NecessaryBufferSize));
  DEBUG ((EFI_D_INFO, "SmramMapSize = 0x%x\n", *SmramMapSize));
  DEBUG ((EFI_D_INFO, "mSmmAccess.NumberRegio = 0x%x\n", mSmmAccess.NumberRegions));
  DEBUG ((EFI_D_INFO, "sizeof(EFI_SMRAM_DESCRIPTOR) = 0x%x\n", sizeof(EFI_SMRAM_DESCRIPTOR)));
#endif

  if (*SmramMapSize < NecessaryBufferSize) {
    DEBUG ((EFI_D_INFO, "SmmAccess: SMRAM Map Buffer too small\n"));
    Status = EFI_BUFFER_TOO_SMALL;
  } else {
    CopyMem(SmramMap, mSmmAccess.SmramDesc, NecessaryBufferSize);
    Status = EFI_SUCCESS;
  }

  *SmramMapSize = NecessaryBufferSize;

  return Status;
}


VOID
SyncRegionState2SmramDesc(
  IN BOOLEAN  OrAnd,
  IN UINT64   Value
  )
{
  UINT64 Index;

  for (Index = 0; Index < mSmmAccess.NumberRegions; Index++) {
    if (OrAnd) {
      mSmmAccess.SmramDesc[Index].RegionState |= Value;
    } else {
      mSmmAccess.SmramDesc[Index].RegionState &= Value;
    }
  }
}

