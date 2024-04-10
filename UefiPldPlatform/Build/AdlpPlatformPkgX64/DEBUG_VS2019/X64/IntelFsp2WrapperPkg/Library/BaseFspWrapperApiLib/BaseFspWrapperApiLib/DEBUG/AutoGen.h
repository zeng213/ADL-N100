/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F42C789F_4D66_49AF_8C73_1AADC00437AC
#define _AUTOGENH_F42C789F_4D66_49AF_8C73_1AADC00437AC

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gFspHeaderFileGuid;
extern GUID gIntelFsp2WrapperTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdFspmBaseAddress  233U
extern const UINT32 _gPcd_FixedAtBuild_PcdFspmBaseAddress;
#define _PCD_GET_MODE_32_PcdFspmBaseAddress  _gPcd_FixedAtBuild_PcdFspmBaseAddress
//#define _PCD_SET_MODE_32_PcdFspmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFspmBaseAddress 0x00000000
#define _PCD_SIZE_PcdFspmBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFspmBaseAddress _PCD_SIZE_PcdFspmBaseAddress
#define _PCD_TOKEN_PcdFspsBaseAddress  26U
#define _PCD_GET_MODE_32_PcdFspsBaseAddress  LibPcdGet32(_PCD_TOKEN_PcdFspsBaseAddress)
#define _PCD_GET_MODE_SIZE_PcdFspsBaseAddress  LibPcdGetSize(_PCD_TOKEN_PcdFspsBaseAddress)
#define _PCD_SET_MODE_32_PcdFspsBaseAddress(Value)  LibPcdSet32(_PCD_TOKEN_PcdFspsBaseAddress, (Value))
#define _PCD_SET_MODE_32_S_PcdFspsBaseAddress(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFspsBaseAddress, (Value))


#ifdef __cplusplus
}
#endif

#endif
