/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_f56d7f0d_68ec_4560_a848_01456335cd53
#define _AUTOGENH_f56d7f0d_68ec_4560_a848_01456335cd53

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPlatformModuleTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdAcpiGnvsAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiGnvsAddress;
#define _PCD_GET_MODE_32_PcdAcpiGnvsAddress  _gPcd_BinaryPatch_PcdAcpiGnvsAddress
#define _PCD_SET_MODE_32_PcdAcpiGnvsAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiGnvsAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiGnvsAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiGnvsAddress _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress; 
#define _PCD_TOKEN_PcdVtdEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


#ifdef __cplusplus
}
#endif

#endif
