/*++
  This file contains an 'Intel Peripheral Driver' and is        
  licensed for Intel CPUs and chipsets under the terms of your  
  license agreement with Intel or your vendor.  This file may   
  be modified by the user, subject to additional terms of the   
  license agreement                                             
--*/
/*++

Copyright (c) 2010, Intel Corporation. All rights reserved. <BR> 
This software and associated documentation (if any) is furnished
under a license and may only be used or copied in accordance
with the terms of the license. Except as permitted by such
license, no part of this software or documentation may be
reproduced, stored in a retrieval system, or transmitted in any
form or by any means without the express written consent of
Intel Corporation.


Module Name:

  FvbInfo.c

Abstract:

  Defines data structure that is the volume header found.
  These data is intent to decouple FVB driver with FV header.

--*/

#include <PiDxe.h>
#include <Protocol/FirmwareVolumeBlock.h>
#include <Library/PcdLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseLib.h>
#include <Guid/FirmwareFileSystem2.h>
#include <Guid/SystemNvDataGuid.h>
#include <Guid/SpiFlashInfoGuid.h>
#include <Library/HobLib.h>

#define FVB_MEDIA_BLOCK_SIZE        0x1000

typedef struct {
  EFI_FIRMWARE_VOLUME_HEADER  FvbInfo;
  EFI_FV_BLOCK_MAP_ENTRY      End[1];
} EFI_FVB2_MEDIA_INFO;

//
// This data structure contains a template of all correct FV headers, which is used to restore
// Fv header if it's corrupted.
//
EFI_FVB2_MEDIA_INFO mPlatformFvbMediaInfo = {
  {
    {0,},           // ZeroVector[16]
    EFI_SYSTEM_NV_DATA_FV_GUID,
    0,
    EFI_FVH_SIGNATURE,
    0x0004feff,     // check MdePkg/Include/Pi/PiFirmwareVolume.h for details on EFI_FVB_ATTRIBUTES_2
    sizeof (EFI_FIRMWARE_VOLUME_HEADER) + sizeof (EFI_FV_BLOCK_MAP_ENTRY),
    0,              // CheckSum which will be calucated dynamically.
    0,              // ExtHeaderOffset
    {0,},
    EFI_FVH_REVISION,
    {
      {
        0,
        FVB_MEDIA_BLOCK_SIZE,
      }
    }
  },
  {
    {
      0,
      0
    }
  }
};


EFI_STATUS
InitVariableStore (
  VOID
  )
{
  UINT32              NvStorageBase;
  UINT32              NvStorageSize;
  UINT32              NvVariableSize;
  UINT32              FtwWorkingSize;
  UINT32              FtwSpareSize;
  EFI_HOB_GUID_TYPE   *GuidHob;
  SPI_FLASH_INFO      *SpiFlashInfo;

  //
  // Find SPI flash hob
  //
  GuidHob = GetFirstGuidHob (&gSpiFlashVariableInfoGuid);
  if (GuidHob == NULL) {
    ASSERT (FALSE);
    return EFI_NOT_FOUND;
  }
  SpiFlashInfo = (SPI_FLASH_INFO *) GET_GUID_HOB_DATA (GuidHob);

  // Get variable region base and size.
  // Here, just hard code here.
  NvStorageSize = SpiFlashInfo->VariableStoreSize; //0x40000;
  NvStorageBase = SpiFlashInfo->VariableStoreBase; //0xFFDC7000 + 0x170000 - NvStorageSize;

  // NvStorageBase needs to be 4KB aligned
  // NvStorageSize needs to be 8KB * n
  if (((NvStorageBase & (SIZE_4KB - 1)) != 0) || ((NvStorageSize & (SIZE_8KB - 1)) != 0)) {
    return EFI_INVALID_PARAMETER;
  }

  FtwSpareSize   = NvStorageSize / 2;
  FtwWorkingSize = 0x2000;
  NvVariableSize = NvStorageSize / 2 - 0x2000;

  PcdSet32(PcdFlashNvStorageVariableSize,   NvVariableSize);
  PcdSet32(PcdFlashNvStorageVariableBase,   NvStorageBase);
  PcdSet64(PcdFlashNvStorageVariableBase64, NvStorageBase);

  PcdSet32(PcdFlashNvStorageFtwWorkingSize, FtwWorkingSize);
  PcdSet32(PcdFlashNvStorageFtwWorkingBase, NvStorageBase + NvVariableSize);

  PcdSet32(PcdFlashNvStorageFtwSpareSize,   FtwSpareSize);
  PcdSet32(PcdFlashNvStorageFtwSpareBase,   NvStorageBase + FtwSpareSize);

  return EFI_SUCCESS;
}


EFI_STATUS
GetFvbInfo (
  OUT EFI_FIRMWARE_VOLUME_HEADER    **FvbInfo
  )
{
  EFI_FIRMWARE_VOLUME_HEADER        *FvHeader;
  UINTN                             FvSize;

  FvSize = PcdGet32(PcdFlashNvStorageFtwSpareSize) * 2;

  //
  // Update the checksum value of FV header.
  //
  FvHeader                        = &mPlatformFvbMediaInfo.FvbInfo;
  FvHeader->FvLength              = FvSize;
  FvHeader->BlockMap[0].NumBlocks = (UINT32) (FvSize / FvHeader->BlockMap[0].Length);
  FvHeader->Checksum = 0;
  FvHeader->Checksum = CalculateCheckSum16 ((UINT16 *) FvHeader, FvHeader->HeaderLength);
  if (FvbInfo != NULL) {
    *FvbInfo = FvHeader;

    DEBUG ((DEBUG_INFO, "FvLength: 0x%lx \n", (*FvbInfo)->FvLength));
    DEBUG ((DEBUG_INFO, "HeaderLength: 0x%x \n", (*FvbInfo)->HeaderLength));
    DEBUG ((DEBUG_INFO, "Header Checksum: 0x%X\n", (*FvbInfo)->Checksum));
    DEBUG ((DEBUG_INFO, "FvBlockMap[0].NumBlocks: 0x%x \n", (*FvbInfo)->BlockMap[0].NumBlocks));
    DEBUG ((DEBUG_INFO, "FvBlockMap[0].BlockLength: 0x%x \n", (*FvbInfo)->BlockMap[0].Length));
  } else {
    return EFI_NOT_FOUND;
  }

  return EFI_SUCCESS;
}

