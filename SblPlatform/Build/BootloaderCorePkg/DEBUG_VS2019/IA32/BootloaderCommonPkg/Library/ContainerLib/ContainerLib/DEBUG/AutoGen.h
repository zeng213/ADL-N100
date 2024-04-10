/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_F7EAF992_7473_4232_B1D2_4A798E92722A
#define _AUTOGENH_F7EAF992_7473_4232_B1D2_4A798E92722A

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdContainerMaxNumber  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdContainerMaxNumber;
#define _PCD_GET_MODE_32_PcdContainerMaxNumber  _gPcd_FixedAtBuild_PcdContainerMaxNumber
//#define _PCD_SET_MODE_32_PcdContainerMaxNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdContainerMaxNumber 8
#define _PCD_SIZE_PcdContainerMaxNumber 4
#define _PCD_GET_MODE_SIZE_PcdContainerMaxNumber _PCD_SIZE_PcdContainerMaxNumber
#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdCompSignHashAlg  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdCompSignHashAlg;
#define _PCD_GET_MODE_8_PcdCompSignHashAlg  _gPcd_FixedAtBuild_PcdCompSignHashAlg
//#define _PCD_SET_MODE_8_PcdCompSignHashAlg  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCompSignHashAlg 0x00000002
#define _PCD_SIZE_PcdCompSignHashAlg 1
#define _PCD_GET_MODE_SIZE_PcdCompSignHashAlg _PCD_SIZE_PcdCompSignHashAlg


#ifdef __cplusplus
}
#endif

#endif
