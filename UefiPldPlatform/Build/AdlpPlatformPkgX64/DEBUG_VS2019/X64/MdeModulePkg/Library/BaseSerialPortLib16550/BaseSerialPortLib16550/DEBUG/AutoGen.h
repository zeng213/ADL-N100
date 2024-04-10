/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_9E7C00CF_355A_4d4e_BF60_0428CFF95540
#define _AUTOGENH_9E7C00CF_355A_4d4e_BF60_0428CFF95540

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gEfiMdeModulePkgTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdSerialRegisterAccessWidth  124U
extern const UINT8 _gPcd_FixedAtBuild_PcdSerialRegisterAccessWidth;
#define _PCD_GET_MODE_8_PcdSerialRegisterAccessWidth  _gPcd_FixedAtBuild_PcdSerialRegisterAccessWidth
//#define _PCD_SET_MODE_8_PcdSerialRegisterAccessWidth  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSerialRegisterAccessWidth 8
#define _PCD_SIZE_PcdSerialRegisterAccessWidth 1
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterAccessWidth _PCD_SIZE_PcdSerialRegisterAccessWidth
#define _PCD_TOKEN_PcdSerialUseMmio  128U
extern volatile  BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseMmio;
#define _PCD_GET_MODE_BOOL_PcdSerialUseMmio  _gPcd_BinaryPatch_PcdSerialUseMmio
#define _PCD_SET_MODE_BOOL_PcdSerialUseMmio(Value)  (_gPcd_BinaryPatch_PcdSerialUseMmio = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseMmio(Value)  ((_gPcd_BinaryPatch_PcdSerialUseMmio = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialUseMmio_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseMmio _gPcd_BinaryPatch_Size_PcdSerialUseMmio
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio; 
#define _PCD_TOKEN_PcdSerialUseHardwareFlowControl  127U
extern volatile  BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl;
#define _PCD_GET_MODE_BOOL_PcdSerialUseHardwareFlowControl  _gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl
#define _PCD_SET_MODE_BOOL_PcdSerialUseHardwareFlowControl(Value)  (_gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseHardwareFlowControl(Value)  ((_gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialUseHardwareFlowControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseHardwareFlowControl _gPcd_BinaryPatch_Size_PcdSerialUseHardwareFlowControl
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseHardwareFlowControl; 
#define _PCD_TOKEN_PcdSerialDetectCable  119U
extern volatile  BOOLEAN  _gPcd_BinaryPatch_PcdSerialDetectCable;
#define _PCD_GET_MODE_BOOL_PcdSerialDetectCable  _gPcd_BinaryPatch_PcdSerialDetectCable
#define _PCD_SET_MODE_BOOL_PcdSerialDetectCable(Value)  (_gPcd_BinaryPatch_PcdSerialDetectCable = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialDetectCable(Value)  ((_gPcd_BinaryPatch_PcdSerialDetectCable = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialDetectCable_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialDetectCable _gPcd_BinaryPatch_Size_PcdSerialDetectCable
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialDetectCable; 
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
#define _PCD_TOKEN_PcdSerialLineControl  122U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdSerialLineControl;
#define _PCD_GET_MODE_8_PcdSerialLineControl  _gPcd_BinaryPatch_PcdSerialLineControl
#define _PCD_SET_MODE_8_PcdSerialLineControl(Value)  (_gPcd_BinaryPatch_PcdSerialLineControl = (Value))
#define _PCD_SET_MODE_8_S_PcdSerialLineControl(Value)  ((_gPcd_BinaryPatch_PcdSerialLineControl = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialLineControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialLineControl _gPcd_BinaryPatch_Size_PcdSerialLineControl
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialLineControl; 
#define _PCD_TOKEN_PcdSerialFifoControl  121U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdSerialFifoControl;
#define _PCD_GET_MODE_8_PcdSerialFifoControl  _gPcd_BinaryPatch_PcdSerialFifoControl
#define _PCD_SET_MODE_8_PcdSerialFifoControl(Value)  (_gPcd_BinaryPatch_PcdSerialFifoControl = (Value))
#define _PCD_SET_MODE_8_S_PcdSerialFifoControl(Value)  ((_gPcd_BinaryPatch_PcdSerialFifoControl = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialFifoControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialFifoControl _gPcd_BinaryPatch_Size_PcdSerialFifoControl
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialFifoControl; 
#define _PCD_TOKEN_PcdSerialClockRate  118U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialClockRate;
#define _PCD_GET_MODE_32_PcdSerialClockRate  _gPcd_BinaryPatch_PcdSerialClockRate
#define _PCD_SET_MODE_32_PcdSerialClockRate(Value)  (_gPcd_BinaryPatch_PcdSerialClockRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialClockRate(Value)  ((_gPcd_BinaryPatch_PcdSerialClockRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialClockRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialClockRate _gPcd_BinaryPatch_Size_PcdSerialClockRate
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialClockRate; 
#define _PCD_TOKEN_PcdSerialPciDeviceInfo  123U
extern const UINT8 _gPcd_FixedAtBuild_PcdSerialPciDeviceInfo[];
#define _PCD_GET_MODE_PTR_PcdSerialPciDeviceInfo  (VOID *)_gPcd_FixedAtBuild_PcdSerialPciDeviceInfo
//#define _PCD_SET_MODE_PTR_PcdSerialPciDeviceInfo  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdSerialPciDeviceInfo (VOID *)_gPcd_FixedAtBuild_PcdSerialPciDeviceInfo
#define _PCD_SIZE_PcdSerialPciDeviceInfo 1
#define _PCD_GET_MODE_SIZE_PcdSerialPciDeviceInfo _PCD_SIZE_PcdSerialPciDeviceInfo
#define _PCD_TOKEN_PcdSerialExtendedTxFifoSize  120U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize;
#define _PCD_GET_MODE_32_PcdSerialExtendedTxFifoSize  _gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize
#define _PCD_SET_MODE_32_PcdSerialExtendedTxFifoSize(Value)  (_gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialExtendedTxFifoSize(Value)  ((_gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialExtendedTxFifoSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialExtendedTxFifoSize _gPcd_BinaryPatch_Size_PcdSerialExtendedTxFifoSize
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialExtendedTxFifoSize; 
#define _PCD_TOKEN_PcdSerialRegisterStride  126U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialRegisterStride;
#define _PCD_GET_MODE_32_PcdSerialRegisterStride  _gPcd_BinaryPatch_PcdSerialRegisterStride
#define _PCD_SET_MODE_32_PcdSerialRegisterStride(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialRegisterStride(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialRegisterStride_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterStride _gPcd_BinaryPatch_Size_PcdSerialRegisterStride
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterStride; 


#ifdef __cplusplus
}
#endif

#endif
