/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_40A2CBC6_CFB8_447b_A90E_198E88FD345E
#define _AUTOGENH_40A2CBC6_CFB8_447b_A90E_198E88FD345E

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdeModulePkgTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSerialUseMmio  128U
extern volatile  BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseMmio;
#define _PCD_GET_MODE_BOOL_PcdSerialUseMmio  _gPcd_BinaryPatch_PcdSerialUseMmio
#define _PCD_SET_MODE_BOOL_PcdSerialUseMmio(Value)  (_gPcd_BinaryPatch_PcdSerialUseMmio = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseMmio(Value)  ((_gPcd_BinaryPatch_PcdSerialUseMmio = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialUseMmio_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseMmio _gPcd_BinaryPatch_Size_PcdSerialUseMmio
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio; 
#define _PCD_TOKEN_PcdSerialRegisterBase  125U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdSerialRegisterBase;
#define _PCD_GET_MODE_64_PcdSerialRegisterBase  _gPcd_BinaryPatch_PcdSerialRegisterBase
#define _PCD_SET_MODE_64_PcdSerialRegisterBase(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value))
#define _PCD_SET_MODE_64_S_PcdSerialRegisterBase(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialRegisterBase_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterBase _gPcd_BinaryPatch_Size_PcdSerialRegisterBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterBase; 
#define _PCD_TOKEN_PcdSerialBaudRate  117U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialBaudRate;
#define _PCD_GET_MODE_32_PcdSerialBaudRate  _gPcd_BinaryPatch_PcdSerialBaudRate
#define _PCD_SET_MODE_32_PcdSerialBaudRate(Value)  (_gPcd_BinaryPatch_PcdSerialBaudRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialBaudRate(Value)  ((_gPcd_BinaryPatch_PcdSerialBaudRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialBaudRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialBaudRate _gPcd_BinaryPatch_Size_PcdSerialBaudRate
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialBaudRate; 
#define _PCD_TOKEN_PcdSerialRegisterStride  126U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialRegisterStride;
#define _PCD_GET_MODE_32_PcdSerialRegisterStride  _gPcd_BinaryPatch_PcdSerialRegisterStride
#define _PCD_SET_MODE_32_PcdSerialRegisterStride(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialRegisterStride(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialRegisterStride_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterStride _gPcd_BinaryPatch_Size_PcdSerialRegisterStride
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterStride; 
#define _PCD_TOKEN_PcdSerialClockRate  118U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialClockRate;
#define _PCD_GET_MODE_32_PcdSerialClockRate  _gPcd_BinaryPatch_PcdSerialClockRate
#define _PCD_SET_MODE_32_PcdSerialClockRate(Value)  (_gPcd_BinaryPatch_PcdSerialClockRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialClockRate(Value)  ((_gPcd_BinaryPatch_PcdSerialClockRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialClockRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialClockRate _gPcd_BinaryPatch_Size_PcdSerialClockRate
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialClockRate; 
#define _PCD_TOKEN_PcdUartDefaultBaudRate  175U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdUartDefaultBaudRate;
#define _PCD_GET_MODE_64_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_PcdUartDefaultBaudRate
#define _PCD_SET_MODE_64_PcdUartDefaultBaudRate(Value)  (_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value))
#define _PCD_SET_MODE_64_S_PcdUartDefaultBaudRate(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdUartDefaultBaudRate_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdUartDefaultBaudRate _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate; 
#define _PCD_TOKEN_PcdPciSerialParameters  110U
extern UINT8 _gPcd_BinaryPatch_PcdPciSerialParameters[];
#define _PCD_GET_MODE_PTR_PcdPciSerialParameters  (VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters
#define _PCD_SET_MODE_PTR_PcdPciSerialParameters(SizeOfBuffer, Buffer)  LibPatchPcdSetPtrAndSize((VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters, &_gPcd_BinaryPatch_Size_PcdPciSerialParameters, _gPcd_BinaryPatch_MaxSize_PcdPciSerialParameters, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdPciSerialParameters(SizeOfBuffer, Buffer)  LibPatchPcdSetPtrAndSizeS((VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters, &_gPcd_BinaryPatch_Size_PcdPciSerialParameters, _gPcd_BinaryPatch_MaxSize_PcdPciSerialParameters, (SizeOfBuffer), (Buffer))
#define _PCD_PATCHABLE_PcdPciSerialParameters_SIZE _gPcd_BinaryPatch_MaxSize_PcdPciSerialParameters
extern const UINTN _gPcd_BinaryPatch_MaxSize_PcdPciSerialParameters; 
#define _PCD_GET_MODE_SIZE_PcdPciSerialParameters _gPcd_BinaryPatch_Size_PcdPciSerialParameters
extern UINTN _gPcd_BinaryPatch_Size_PcdPciSerialParameters; 

RETURN_STATUS
EFIAPI
PlatformHookSerialPortInitialize (
  VOID
  );


#ifdef __cplusplus
}
#endif

#endif
