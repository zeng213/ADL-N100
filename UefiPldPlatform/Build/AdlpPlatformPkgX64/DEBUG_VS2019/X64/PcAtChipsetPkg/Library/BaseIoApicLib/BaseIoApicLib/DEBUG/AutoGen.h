/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_58ED6E5A_E36A_462a_9ED6_6E62C9A26DF8
#define _AUTOGENH_58ED6E5A_E36A_462a_9ED6_6E62C9A26DF8

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPcAtChipsetPkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdIoApicBaseAddress  242U
extern const UINT32 _gPcd_FixedAtBuild_PcdIoApicBaseAddress;
#define _PCD_GET_MODE_32_PcdIoApicBaseAddress  _gPcd_FixedAtBuild_PcdIoApicBaseAddress
//#define _PCD_SET_MODE_32_PcdIoApicBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdIoApicBaseAddress 0xFEC00000
#define _PCD_SIZE_PcdIoApicBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdIoApicBaseAddress _PCD_SIZE_PcdIoApicBaseAddress


#ifdef __cplusplus
}
#endif

#endif
