/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_BB83F95F_EDBC_4884_A520_CD42AF388FAE
#define _AUTOGENH_BB83F95F_EDBC_4884_A520_CD42AF388FAE

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdDebugClearMemoryValue  65U
extern const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdDebugClearMemoryValue 0xAF
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue _PCD_SIZE_PcdDebugClearMemoryValue
#define _PCD_TOKEN_PcdDebugPropertyMask  67U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_BinaryPatch_PcdDebugPropertyMask
#define _PCD_SET_MODE_8_PcdDebugPropertyMask(Value)  (_gPcd_BinaryPatch_PcdDebugPropertyMask = (Value))
#define _PCD_SET_MODE_8_S_PcdDebugPropertyMask(Value)  ((_gPcd_BinaryPatch_PcdDebugPropertyMask = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdDebugPropertyMask_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask _gPcd_BinaryPatch_Size_PcdDebugPropertyMask
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPropertyMask; 
#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  68U
extern const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel 0xFFFFFFFF
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel _PCD_SIZE_PcdFixedDebugPrintErrorLevel

RETURN_STATUS
EFIAPI
BaseDebugLibSerialPortConstructor (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
