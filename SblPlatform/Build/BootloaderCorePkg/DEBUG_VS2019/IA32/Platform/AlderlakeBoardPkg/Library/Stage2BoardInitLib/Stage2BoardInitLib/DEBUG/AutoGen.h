/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_382FF3D3_6872_4737_9CD3_7232AF2C6748
#define _AUTOGENH_382FF3D3_6872_4737_9CD3_7232AF2C6748

#ifdef __cplusplus
extern "C" {
#endif

#include <Base.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;


// Guids
extern GUID gOsConfigDataGuid;
extern GUID gFspVariableNvDataHobGuid;
extern GUID gCpuInitDataHobGuid;
extern GUID gCsmePerformanceInfoGuid;
extern GUID gPlatformAlderLakeTokenSpaceGuid;
extern GUID gEfiMdePkgTokenSpaceGuid;
extern GUID gPlatformModuleTokenSpaceGuid;
extern GUID gPlatformCommonLibTokenSpaceGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// PCD definitions
#define _PCD_TOKEN_PcdAdlLpSupport  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdAdlLpSupport 1
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport _PCD_SIZE_PcdAdlLpSupport
#define _PCD_TOKEN_PcdPciExpressBaseAddress  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdPciExpressBaseAddress;
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  _gPcd_BinaryPatch_PcdPciExpressBaseAddress
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  (_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  ((_gPcd_BinaryPatch_PcdPciExpressBaseAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciExpressBaseAddress_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress; 
#define _PCD_TOKEN_PcdPciResourceIoBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciResourceIoBase;
#define _PCD_GET_MODE_32_PcdPciResourceIoBase  _gPcd_BinaryPatch_PcdPciResourceIoBase
#define _PCD_SET_MODE_32_PcdPciResourceIoBase(Value)  (_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceIoBase(Value)  ((_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResourceIoBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceIoBase _gPcd_BinaryPatch_Size_PcdPciResourceIoBase
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceIoBase; 
#define _PCD_TOKEN_PcdPciResourceMem32Base  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciResourceMem32Base;
#define _PCD_GET_MODE_32_PcdPciResourceMem32Base  _gPcd_BinaryPatch_PcdPciResourceMem32Base
#define _PCD_SET_MODE_32_PcdPciResourceMem32Base(Value)  (_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceMem32Base(Value)  ((_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciResourceMem32Base_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceMem32Base _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base; 
#define _PCD_TOKEN_PcdVariableRegionSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdVariableRegionSize;
#define _PCD_GET_MODE_32_PcdVariableRegionSize  _gPcd_FixedAtBuild_PcdVariableRegionSize
//#define _PCD_SET_MODE_32_PcdVariableRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdVariableRegionSize 0x00002000
#define _PCD_SIZE_PcdVariableRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdVariableRegionSize _PCD_SIZE_PcdVariableRegionSize
#define _PCD_TOKEN_PcdOsBootOptionNumber  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdOsBootOptionNumber;
#define _PCD_GET_MODE_32_PcdOsBootOptionNumber  _gPcd_FixedAtBuild_PcdOsBootOptionNumber
//#define _PCD_SET_MODE_32_PcdOsBootOptionNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdOsBootOptionNumber 0x00000008
#define _PCD_SIZE_PcdOsBootOptionNumber 4
#define _PCD_GET_MODE_SIZE_PcdOsBootOptionNumber _PCD_SIZE_PcdOsBootOptionNumber
#define _PCD_TOKEN_PcdIntelGfxEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdIntelGfxEnabled;
#define _PCD_GET_MODE_BOOL_PcdIntelGfxEnabled  _gPcd_FixedAtBuild_PcdIntelGfxEnabled
//#define _PCD_SET_MODE_BOOL_PcdIntelGfxEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdAcpiGnvsAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdAcpiGnvsAddress;
#define _PCD_GET_MODE_32_PcdAcpiGnvsAddress  _gPcd_BinaryPatch_PcdAcpiGnvsAddress
#define _PCD_SET_MODE_32_PcdAcpiGnvsAddress(Value)  (_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiGnvsAddress(Value)  ((_gPcd_BinaryPatch_PcdAcpiGnvsAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdAcpiGnvsAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiGnvsAddress _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress; 
#define _PCD_TOKEN_PcdServiceNumber  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdServiceNumber;
#define _PCD_GET_MODE_32_PcdServiceNumber  _gPcd_FixedAtBuild_PcdServiceNumber
//#define _PCD_SET_MODE_32_PcdServiceNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdServiceNumber 0x00000004
#define _PCD_SIZE_PcdServiceNumber 4
#define _PCD_GET_MODE_SIZE_PcdServiceNumber _PCD_SIZE_PcdServiceNumber
#define _PCD_TOKEN_PcdCfgDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdCfgDataSize 0x00004000
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize _PCD_SIZE_PcdCfgDataSize
#define _PCD_TOKEN_PcdMrcDataSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdMrcDataSize;
#define _PCD_GET_MODE_32_PcdMrcDataSize  _gPcd_FixedAtBuild_PcdMrcDataSize
//#define _PCD_SET_MODE_32_PcdMrcDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdMrcDataSize 0x00010000
#define _PCD_SIZE_PcdMrcDataSize 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataSize _PCD_SIZE_PcdMrcDataSize
#define _PCD_TOKEN_PcdPayloadReservedMemSize  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPayloadReservedMemSize;
#define _PCD_GET_MODE_32_PcdPayloadReservedMemSize  _gPcd_BinaryPatch_PcdPayloadReservedMemSize
#define _PCD_SET_MODE_32_PcdPayloadReservedMemSize(Value)  (_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadReservedMemSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPayloadReservedMemSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadReservedMemSize _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize; 
#define _PCD_TOKEN_PcdSmbiosEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdSmbiosEnabled;
#define _PCD_GET_MODE_BOOL_PcdSmbiosEnabled  _gPcd_FixedAtBuild_PcdSmbiosEnabled
//#define _PCD_SET_MODE_BOOL_PcdSmbiosEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdSmbiosStringsPtr  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmbiosStringsPtr;
#define _PCD_GET_MODE_32_PcdSmbiosStringsPtr  _gPcd_BinaryPatch_PcdSmbiosStringsPtr
#define _PCD_SET_MODE_32_PcdSmbiosStringsPtr(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosStringsPtr(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosStringsPtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsPtr _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr; 
#define _PCD_TOKEN_PcdSmbiosStringsCnt  0U
extern volatile  UINT16  _gPcd_BinaryPatch_PcdSmbiosStringsCnt;
#define _PCD_GET_MODE_16_PcdSmbiosStringsCnt  _gPcd_BinaryPatch_PcdSmbiosStringsCnt
#define _PCD_SET_MODE_16_PcdSmbiosStringsCnt(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value))
#define _PCD_SET_MODE_16_S_PcdSmbiosStringsCnt(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosStringsCnt_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsCnt _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt; 
#define _PCD_TOKEN_PcdSmbiosTablesBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmbiosTablesBase;
#define _PCD_GET_MODE_32_PcdSmbiosTablesBase  _gPcd_BinaryPatch_PcdSmbiosTablesBase
#define _PCD_SET_MODE_32_PcdSmbiosTablesBase(Value)  (_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosTablesBase(Value)  ((_gPcd_BinaryPatch_PcdSmbiosTablesBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmbiosTablesBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosTablesBase _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase; 
#define _PCD_TOKEN_PcdFuncCpuInitHook  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdFuncCpuInitHook;
#define _PCD_GET_MODE_32_PcdFuncCpuInitHook  _gPcd_BinaryPatch_PcdFuncCpuInitHook
#define _PCD_SET_MODE_32_PcdFuncCpuInitHook(Value)  (_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value))
#define _PCD_SET_MODE_32_S_PcdFuncCpuInitHook(Value)  ((_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdFuncCpuInitHook_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFuncCpuInitHook _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook
extern UINTN _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook; 
#define _PCD_TOKEN_PcdSerialUseMmio  0U
extern volatile  BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseMmio;
#define _PCD_GET_MODE_BOOL_PcdSerialUseMmio  _gPcd_BinaryPatch_PcdSerialUseMmio
#define _PCD_SET_MODE_BOOL_PcdSerialUseMmio(Value)  (_gPcd_BinaryPatch_PcdSerialUseMmio = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseMmio(Value)  ((_gPcd_BinaryPatch_PcdSerialUseMmio = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialUseMmio_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseMmio _gPcd_BinaryPatch_Size_PcdSerialUseMmio
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio; 
#define _PCD_TOKEN_PcdSerialRegisterBase  0U
extern volatile  UINT64  _gPcd_BinaryPatch_PcdSerialRegisterBase;
#define _PCD_GET_MODE_64_PcdSerialRegisterBase  _gPcd_BinaryPatch_PcdSerialRegisterBase
#define _PCD_SET_MODE_64_PcdSerialRegisterBase(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value))
#define _PCD_SET_MODE_64_S_PcdSerialRegisterBase(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialRegisterBase_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterBase _gPcd_BinaryPatch_Size_PcdSerialRegisterBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterBase; 
#define _PCD_TOKEN_PcdSerialBaudRate  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialBaudRate;
#define _PCD_GET_MODE_32_PcdSerialBaudRate  _gPcd_BinaryPatch_PcdSerialBaudRate
#define _PCD_SET_MODE_32_PcdSerialBaudRate(Value)  (_gPcd_BinaryPatch_PcdSerialBaudRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialBaudRate(Value)  ((_gPcd_BinaryPatch_PcdSerialBaudRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialBaudRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialBaudRate _gPcd_BinaryPatch_Size_PcdSerialBaudRate
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialBaudRate; 
#define _PCD_TOKEN_PcdSerialRegisterStride  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialRegisterStride;
#define _PCD_GET_MODE_32_PcdSerialRegisterStride  _gPcd_BinaryPatch_PcdSerialRegisterStride
#define _PCD_SET_MODE_32_PcdSerialRegisterStride(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialRegisterStride(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialRegisterStride_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterStride _gPcd_BinaryPatch_Size_PcdSerialRegisterStride
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterStride; 
#define _PCD_TOKEN_PcdSerialClockRate  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSerialClockRate;
#define _PCD_GET_MODE_32_PcdSerialClockRate  _gPcd_BinaryPatch_PcdSerialClockRate
#define _PCD_SET_MODE_32_PcdSerialClockRate(Value)  (_gPcd_BinaryPatch_PcdSerialClockRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialClockRate(Value)  ((_gPcd_BinaryPatch_PcdSerialClockRate = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSerialClockRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialClockRate _gPcd_BinaryPatch_Size_PcdSerialClockRate
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialClockRate; 
#define _PCD_TOKEN_PcdGraphicsVbtAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdGraphicsVbtAddress;
#define _PCD_GET_MODE_32_PcdGraphicsVbtAddress  _gPcd_BinaryPatch_PcdGraphicsVbtAddress
#define _PCD_SET_MODE_32_PcdGraphicsVbtAddress(Value)  (_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdGraphicsVbtAddress(Value)  ((_gPcd_BinaryPatch_PcdGraphicsVbtAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdGraphicsVbtAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdGraphicsVbtAddress _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress; 
#define _PCD_TOKEN_PcdFramebufferInitEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFramebufferInitEnabled;
#define _PCD_GET_MODE_BOOL_PcdFramebufferInitEnabled  _gPcd_FixedAtBuild_PcdFramebufferInitEnabled
//#define _PCD_SET_MODE_BOOL_PcdFramebufferInitEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdSmramTsegBase  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmramTsegBase;
#define _PCD_GET_MODE_32_PcdSmramTsegBase  _gPcd_BinaryPatch_PcdSmramTsegBase
#define _PCD_SET_MODE_32_PcdSmramTsegBase(Value)  (_gPcd_BinaryPatch_PcdSmramTsegBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegBase(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegBase = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmramTsegBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegBase _gPcd_BinaryPatch_Size_PcdSmramTsegBase
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegBase; 
#define _PCD_TOKEN_PcdSmramTsegSize  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdSmramTsegSize;
#define _PCD_GET_MODE_32_PcdSmramTsegSize  _gPcd_BinaryPatch_PcdSmramTsegSize
#define _PCD_SET_MODE_32_PcdSmramTsegSize(Value)  (_gPcd_BinaryPatch_PcdSmramTsegSize = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegSize(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegSize = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmramTsegSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegSize _gPcd_BinaryPatch_Size_PcdSmramTsegSize
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegSize; 
#define _PCD_TOKEN_PcdSmmRebaseMode  0U
extern volatile  UINT8  _gPcd_BinaryPatch_PcdSmmRebaseMode;
#define _PCD_GET_MODE_8_PcdSmmRebaseMode  _gPcd_BinaryPatch_PcdSmmRebaseMode
#define _PCD_SET_MODE_8_PcdSmmRebaseMode(Value)  (_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value))
#define _PCD_SET_MODE_8_S_PcdSmmRebaseMode(Value)  ((_gPcd_BinaryPatch_PcdSmmRebaseMode = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdSmmRebaseMode_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSmmRebaseMode _gPcd_BinaryPatch_Size_PcdSmmRebaseMode
extern UINTN _gPcd_BinaryPatch_Size_PcdSmmRebaseMode; 
#define _PCD_TOKEN_PcdPsdBiosEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdPsdBiosEnabled;
#define _PCD_GET_MODE_BOOL_PcdPsdBiosEnabled  _gPcd_FixedAtBuild_PcdPsdBiosEnabled
//#define _PCD_SET_MODE_BOOL_PcdPsdBiosEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdVtdEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdFspsUpdPtr  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdFspsUpdPtr;
#define _PCD_GET_MODE_32_PcdFspsUpdPtr  _gPcd_BinaryPatch_PcdFspsUpdPtr
#define _PCD_SET_MODE_32_PcdFspsUpdPtr(Value)  (_gPcd_BinaryPatch_PcdFspsUpdPtr = (Value))
#define _PCD_SET_MODE_32_S_PcdFspsUpdPtr(Value)  ((_gPcd_BinaryPatch_PcdFspsUpdPtr = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdFspsUpdPtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFspsUpdPtr _gPcd_BinaryPatch_Size_PcdFspsUpdPtr
extern UINTN _gPcd_BinaryPatch_Size_PcdFspsUpdPtr; 
#define _PCD_TOKEN_PcdFastBootEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFastBootEnabled 0x0
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled _PCD_SIZE_PcdFastBootEnabled
#define _PCD_TOKEN_PcdTccEnabled  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdTccEnabled 0x0
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled _PCD_SIZE_PcdTccEnabled
#define _PCD_TOKEN_PcdEnablePciePm  0U
extern const BOOLEAN _gPcd_FixedAtBuild_PcdEnablePciePm;
#define _PCD_GET_MODE_BOOL_PcdEnablePciePm  _gPcd_FixedAtBuild_PcdEnablePciePm
//#define _PCD_SET_MODE_BOOL_PcdEnablePciePm  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_TOKEN_PcdBootPerformanceMask  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask;
#define _PCD_GET_MODE_32_PcdBootPerformanceMask  _gPcd_FixedAtBuild_PcdBootPerformanceMask
//#define _PCD_SET_MODE_32_PcdBootPerformanceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdBootPerformanceMask 0x1
#define _PCD_SIZE_PcdBootPerformanceMask 4
#define _PCD_GET_MODE_SIZE_PcdBootPerformanceMask _PCD_SIZE_PcdBootPerformanceMask
#define _PCD_TOKEN_PcdPciEnumHookProc  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdPciEnumHookProc;
#define _PCD_GET_MODE_32_PcdPciEnumHookProc  _gPcd_BinaryPatch_PcdPciEnumHookProc
#define _PCD_SET_MODE_32_PcdPciEnumHookProc(Value)  (_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value))
#define _PCD_SET_MODE_32_S_PcdPciEnumHookProc(Value)  ((_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdPciEnumHookProc_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciEnumHookProc _gPcd_BinaryPatch_Size_PcdPciEnumHookProc
extern UINTN _gPcd_BinaryPatch_Size_PcdPciEnumHookProc; 
#define _PCD_TOKEN_PcdFlashBaseAddress  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFlashBaseAddress 0xFF300000
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress _PCD_SIZE_PcdFlashBaseAddress
#define _PCD_TOKEN_PcdFlashSize  0U
extern const UINT32 _gPcd_FixedAtBuild_PcdFlashSize;
#define _PCD_GET_MODE_32_PcdFlashSize  _gPcd_FixedAtBuild_PcdFlashSize
//#define _PCD_SET_MODE_32_PcdFlashSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD
#define _PCD_VALUE_PcdFlashSize 0x00D00000
#define _PCD_SIZE_PcdFlashSize 4
#define _PCD_GET_MODE_SIZE_PcdFlashSize _PCD_SIZE_PcdFlashSize
#define _PCD_TOKEN_PcdIgdOpRegionAddress  0U
extern volatile  UINT32  _gPcd_BinaryPatch_PcdIgdOpRegionAddress;
#define _PCD_GET_MODE_32_PcdIgdOpRegionAddress  _gPcd_BinaryPatch_PcdIgdOpRegionAddress
#define _PCD_SET_MODE_32_PcdIgdOpRegionAddress(Value)  (_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdIgdOpRegionAddress(Value)  ((_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value)), RETURN_SUCCESS)
#define _PCD_PATCHABLE_PcdIgdOpRegionAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdIgdOpRegionAddress _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress
extern UINTN _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress; 


#ifdef __cplusplus
}
#endif

#endif
