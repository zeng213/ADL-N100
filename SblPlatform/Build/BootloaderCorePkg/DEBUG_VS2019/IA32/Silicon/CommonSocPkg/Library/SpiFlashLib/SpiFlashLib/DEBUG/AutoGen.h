/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_6F96AFCB_DE89_4ca1_A63F_8703EE8FDE50
#define _AUTOGENH_6F96AFCB_DE89_4ca1_A63F_8703EE8FDE50

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdSpiFlashLibId  0U
extern const UINT8 _gPcd_FixedAtBuild_PcdSpiFlashLibId;
#define _PCD_GET_MODE_8_PcdSpiFlashLibId  _gPcd_FixedAtBuild_PcdSpiFlashLibId
//#define _PCD_SET_MODE_8_PcdSpiFlashLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSpiFlashLibId 2
#define _PCD_SIZE_PcdSpiFlashLibId 1
#define _PCD_GET_MODE_SIZE_PcdSpiFlashLibId _PCD_SIZE_PcdSpiFlashLibId

RETURN_STATUS
EFIAPI
SpiConstructor (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
