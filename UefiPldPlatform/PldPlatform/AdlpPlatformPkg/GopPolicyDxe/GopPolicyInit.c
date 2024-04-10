/** @file
  Gop policy implementation.

  Copyright (c) 2011 - 2021, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include <PiDxe.h>
#include <Library/UefiDriverEntryPoint.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DxeServicesTableLib.h>
#include <Library/BaseLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PciLib.h>
#include <Library/DebugLib.h>
#include <IndustryStandard/IgdOpRegion.h>
#include <Protocol/GopPolicy.h>

GLOBAL_REMOVE_IF_UNREFERENCED GOP_POLICY_PROTOCOL        mGOPPolicy;
/**

  @param[out] CurrentLidStatus

  @retval     EFI_SUCCESS
  @retval     EFI_UNSUPPORTED
**/
EFI_STATUS
EFIAPI
GetPlatformLidStatus (
  OUT LID_STATUS *CurrentLidStatus
  )
{
  return EFI_UNSUPPORTED;
}

/**

  @param[out] CurrentDockStatus

  @retval     EFI_SUCCESS
  @retval     EFI_UNSUPPORTED
**/
EFI_STATUS
EFIAPI
GetPlatformDockStatus (
  OUT DOCK_STATUS  CurrentDockStatus
  )
{
  return EFI_UNSUPPORTED;
}


/**

  @param[out] VbtAddress
  @param[out] VbtSize

  @retval     EFI_SUCCESS
  @retval     EFI_NOT_FOUND
**/
EFI_STATUS
EFIAPI
GetVbtData (
  OUT EFI_PHYSICAL_ADDRESS *VbtAddress,
  OUT UINT32               *VbtSize
  )
{
  IGD_OPREGION_STRUCTURE   *OpRegion;

  OpRegion    = (IGD_OPREGION_STRUCTURE *)(UINTN)PciRead32 (PCI_LIB_ADDRESS (0, 2, 0, 0xFC));
  if ((OpRegion != NULL) && \
      (CompareMem (OpRegion->Header.SIGN, IGD_OPREGION_HEADER_SIGN, sizeof(OpRegion->Header.SIGN)) == 0)) {

    *VbtAddress = (EFI_PHYSICAL_ADDRESS)((UINTN)OpRegion + OpRegion->MBox3.RVDA);
    *VbtSize    = OpRegion->MBox3.RVDS;
    return EFI_SUCCESS;
  } else {
    return EFI_NOT_FOUND;
  }
}

/**
Initialize GOP DXE Policy

@param[in] ImageHandle          Image handle of this driver.

@retval EFI_SUCCESS             Initialization complete.
@retval EFI_UNSUPPORTED         The chipset is unsupported by this driver.
@retval EFI_OUT_OF_RESOURCES    Do not have enough resources to initialize the driver.
@retval EFI_DEVICE_ERROR        Device error, driver exits abnormally.
**/

EFI_STATUS
EFIAPI
GopPolicyInitDxe (
  IN EFI_HANDLE       ImageHandle
  )
{
  EFI_STATUS  Status;

  //
  // Initialize the EFI Driver Library
  //
  SetMem (&mGOPPolicy, sizeof (GOP_POLICY_PROTOCOL), 0);

  mGOPPolicy.Revision                = GOP_POLICY_PROTOCOL_REVISION_03;
  mGOPPolicy.GetPlatformLidStatus    = GetPlatformLidStatus;
  mGOPPolicy.GetVbtData              = GetVbtData;
  mGOPPolicy.GetPlatformDockStatus   = GetPlatformDockStatus;

  //
  // Install protocol to allow access to this Policy.
  //
  Status = gBS->InstallMultipleProtocolInterfaces (
                  &ImageHandle,
                  &gGopPolicyProtocolGuid,
                  &mGOPPolicy,
                  NULL
                  );

  return Status;
}


/**
  Initialize  DXE Platform Policy

  @param[in] ImageHandle       Image handle of this driver.
  @param[in] SystemTable       Global system service table.

  @retval EFI_SUCCESS           Initialization complete.
  @exception EFI_UNSUPPORTED    The chipset is unsupported by this driver.
  @retval EFI_OUT_OF_RESOURCES  Do not have enough resources to initialize the driver.
  @retval EFI_DEVICE_ERROR      Device error, driver exits abnormally.
**/
EFI_STATUS
EFIAPI
PolicyInitDxeEntryPoint (
  IN EFI_HANDLE       ImageHandle,
  IN EFI_SYSTEM_TABLE *SystemTable
  )
{
  return GopPolicyInitDxe (ImageHandle);
}

