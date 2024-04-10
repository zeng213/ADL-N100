/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_588E4F33_F177_4f60_A446_9AD38884B382
#define _AUTOGENH_588E4F33_F177_4f60_A446_9AD38884B382

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gPayloadKeyHashGuid;
extern GUID gFlashMapInfoGuid;
extern GUID gDeviceTableHobGuid;
extern GUID gPayloadTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdPayloadHobList  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadHobList;
#define _PCD_GET_MODE_32_PcdPayloadHobList  _gPcd_BinaryPatch_PcdPayloadHobList
#define _PCD_SET_MODE_32_PcdPayloadHobList(Value)  (_gPcd_BinaryPatch_PcdPayloadHobList = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadHobList(Value)  ((_gPcd_BinaryPatch_PcdPayloadHobList = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadHobList_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadHobList _gPcd_BinaryPatch_Size_PcdPayloadHobList
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadHobList; 
#define _PCD_TOKEN_PcdGlobalDataAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdGlobalDataAddress;
#define _PCD_GET_MODE_32_PcdGlobalDataAddress  _gPcd_BinaryPatch_PcdGlobalDataAddress
#define _PCD_SET_MODE_32_PcdGlobalDataAddress(Value)  (_gPcd_BinaryPatch_PcdGlobalDataAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGlobalDataAddress(Value)  ((_gPcd_BinaryPatch_PcdGlobalDataAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdGlobalDataAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGlobalDataAddress _gPcd_BinaryPatch_Size_PcdGlobalDataAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdGlobalDataAddress; 
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 


#ifdef __cplusplus
}
#endif

#endif
