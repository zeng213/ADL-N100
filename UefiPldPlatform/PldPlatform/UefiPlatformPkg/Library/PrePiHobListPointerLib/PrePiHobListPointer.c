/** @file
*
Copyright (c) 2020, Intel Corporation. All rights reserved.<BR>
*  SPDX-License-Identifier: BSD-2-Clause-Patent
*
**/

#include <PiPei.h>
#include <Library/DebugLib.h>

VOID      *mHobList;

/**
  Returns the pointer to the HOB list.

  This function returns the pointer to first HOB in the list.

  @return The pointer to the HOB list.

**/
VOID *
EFIAPI
PrePeiGetHobList (
  VOID
  )
{
  ASSERT (mHobList != NULL);
  return mHobList;
}


/**
  Updates the pointer to the HOB list.

  @param  HobList       Hob list pointer to store

**/
EFI_STATUS
EFIAPI
PrePeiSetHobList (
  IN  VOID      *HobList
  )
{
  mHobList = HobList;
  return EFI_SUCCESS;
}
