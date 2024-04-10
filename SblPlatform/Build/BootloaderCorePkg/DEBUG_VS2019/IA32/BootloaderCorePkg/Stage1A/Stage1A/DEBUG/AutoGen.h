/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A0FC7906_3519_4605_BACD_50B7C4392F84
#define _AUTOGENH_A0FC7906_3519_4605_BACD_50B7C4392F84

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA0FC7906, 0x3519, 0x4605, {0xBA, 0xCD, 0x50, 0xB7, 0xC4, 0x39, 0x2F, 0x84}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern EFI_GUID gPlatformModuleTokenSpaceGuid;
extern EFI_GUID gPlatformCommonLibTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gPlatformAlderLakeTokenSpaceGuid;
extern EFI_GUID gPeiFirmwarePerformanceGuid;
extern EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid;
extern EFI_GUID gLoaderFspInfoGuid;
extern EFI_GUID gCsmePerformanceInfoGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdMaxLibraryDataEntry  0U
#define _PCD_SIZE_PcdMaxLibraryDataEntry 4
#define _PCD_GET_MODE_SIZE_PcdMaxLibraryDataEntry  _PCD_SIZE_PcdMaxLibraryDataEntry 
#define _PCD_VALUE_PcdMaxLibraryDataEntry  8U
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry;
#define _PCD_GET_MODE_32_PcdMaxLibraryDataEntry  _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry
//#define _PCD_SET_MODE_32_PcdMaxLibraryDataEntry  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifiedBootEnabled  0U
#define _PCD_SIZE_PcdVerifiedBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVerifiedBootEnabled  _PCD_SIZE_PcdVerifiedBootEnabled 
#define _PCD_VALUE_PcdVerifiedBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootEnabled  _gPcd_FixedAtBuild_PcdVerifiedBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugOutputDeviceMask  0U
#define _PCD_SIZE_PcdDebugOutputDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdDebugOutputDeviceMask  _PCD_SIZE_PcdDebugOutputDeviceMask 
#define _PCD_VALUE_PcdDebugOutputDeviceMask  3U
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask;
#define _PCD_GET_MODE_32_PcdDebugOutputDeviceMask  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask
//#define _PCD_SET_MODE_32_PcdDebugOutputDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdContainerMaxNumber  0U
#define _PCD_SIZE_PcdContainerMaxNumber 4
#define _PCD_GET_MODE_SIZE_PcdContainerMaxNumber  _PCD_SIZE_PcdContainerMaxNumber 
#define _PCD_VALUE_PcdContainerMaxNumber  8U
extern const  UINT32  _gPcd_FixedAtBuild_PcdContainerMaxNumber;
#define _PCD_GET_MODE_32_PcdContainerMaxNumber  _gPcd_FixedAtBuild_PcdContainerMaxNumber
//#define _PCD_SET_MODE_32_PcdContainerMaxNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1StackSize  0U
#define _PCD_SIZE_PcdStage1StackSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackSize  _PCD_SIZE_PcdStage1StackSize 
#define _PCD_VALUE_PcdStage1StackSize  0x00002000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1StackSize;
#define _PCD_GET_MODE_32_PcdStage1StackSize  _gPcd_FixedAtBuild_PcdStage1StackSize
//#define _PCD_SET_MODE_32_PcdStage1StackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdBase  0U
#define _PCD_SIZE_PcdStage1BFdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdBase  _PCD_SIZE_PcdStage1BFdBase 
#define _PCD_VALUE_PcdStage1BFdBase  0xFFD00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdBase;
#define _PCD_GET_MODE_32_PcdStage1BFdBase  _gPcd_FixedAtBuild_PcdStage1BFdBase
//#define _PCD_SET_MODE_32_PcdStage1BFdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BLoadBase  0U
#define _PCD_SIZE_PcdStage1BLoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BLoadBase  _PCD_SIZE_PcdStage1BLoadBase 
#define _PCD_VALUE_PcdStage1BLoadBase  0xFFD00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BLoadBase;
#define _PCD_GET_MODE_32_PcdStage1BLoadBase  _gPcd_FixedAtBuild_PcdStage1BLoadBase
//#define _PCD_SET_MODE_32_PcdStage1BLoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHashStoreBase  0U
#define _PCD_PATCHABLE_VALUE_PcdHashStoreBase  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdHashStoreBase;
#define _PCD_GET_MODE_32_PcdHashStoreBase  _gPcd_BinaryPatch_PcdHashStoreBase
#define _PCD_PATCHABLE_PcdHashStoreBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdHashStoreBase  _gPcd_BinaryPatch_Size_PcdHashStoreBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdHashStoreBase; 
#define _PCD_SET_MODE_32_PcdHashStoreBase(Value)  (_gPcd_BinaryPatch_PcdHashStoreBase = (Value))
#define _PCD_SET_MODE_32_S_PcdHashStoreBase(Value)  ((_gPcd_BinaryPatch_PcdHashStoreBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdVerInfoBase  0U
#define _PCD_PATCHABLE_VALUE_PcdVerInfoBase  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdVerInfoBase;
#define _PCD_GET_MODE_32_PcdVerInfoBase  _gPcd_BinaryPatch_PcdVerInfoBase
#define _PCD_PATCHABLE_PcdVerInfoBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdVerInfoBase  _gPcd_BinaryPatch_Size_PcdVerInfoBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdVerInfoBase; 
#define _PCD_SET_MODE_32_PcdVerInfoBase(Value)  (_gPcd_BinaryPatch_PcdVerInfoBase = (Value))
#define _PCD_SET_MODE_32_S_PcdVerInfoBase(Value)  ((_gPcd_BinaryPatch_PcdVerInfoBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdStage1DataSize  0U
#define _PCD_SIZE_PcdStage1DataSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1DataSize  _PCD_SIZE_PcdStage1DataSize 
#define _PCD_VALUE_PcdStage1DataSize  0x00014000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1DataSize;
#define _PCD_GET_MODE_32_PcdStage1DataSize  _gPcd_FixedAtBuild_PcdStage1DataSize
//#define _PCD_SET_MODE_32_PcdStage1DataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1StackBaseOffset  0U
#define _PCD_SIZE_PcdStage1StackBaseOffset 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackBaseOffset  _PCD_SIZE_PcdStage1StackBaseOffset 
#define _PCD_VALUE_PcdStage1StackBaseOffset  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1StackBaseOffset;
#define _PCD_GET_MODE_32_PcdStage1StackBaseOffset  _gPcd_FixedAtBuild_PcdStage1StackBaseOffset
//#define _PCD_SET_MODE_32_PcdStage1StackBaseOffset  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BXip  0U
#define _PCD_SIZE_PcdStage1BXip 1
#define _PCD_GET_MODE_SIZE_PcdStage1BXip  _PCD_SIZE_PcdStage1BXip 
#define _PCD_VALUE_PcdStage1BXip  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStage1BXip;
#define _PCD_GET_MODE_BOOL_PcdStage1BXip  _gPcd_FixedAtBuild_PcdStage1BXip
//#define _PCD_SET_MODE_BOOL_PcdStage1BXip  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDatabaseSize  0U
#define _PCD_SIZE_PcdCfgDatabaseSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDatabaseSize  _PCD_SIZE_PcdCfgDatabaseSize 
#define _PCD_VALUE_PcdCfgDatabaseSize  0x00004000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDatabaseSize;
#define _PCD_GET_MODE_32_PcdCfgDatabaseSize  _gPcd_FixedAtBuild_PcdCfgDatabaseSize
//#define _PCD_SET_MODE_32_PcdCfgDatabaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1AXip  0U
#define _PCD_SIZE_PcdStage1AXip 1
#define _PCD_GET_MODE_SIZE_PcdStage1AXip  _PCD_SIZE_PcdStage1AXip 
#define _PCD_VALUE_PcdStage1AXip  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStage1AXip;
#define _PCD_GET_MODE_BOOL_PcdStage1AXip  _gPcd_FixedAtBuild_PcdStage1AXip
//#define _PCD_SET_MODE_BOOL_PcdStage1AXip  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1ALoadBase  0U
#define _PCD_SIZE_PcdStage1ALoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1ALoadBase  _PCD_SIZE_PcdStage1ALoadBase 
#define _PCD_VALUE_PcdStage1ALoadBase  0xFFFE5000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1ALoadBase;
#define _PCD_GET_MODE_32_PcdStage1ALoadBase  _gPcd_FixedAtBuild_PcdStage1ALoadBase
//#define _PCD_SET_MODE_32_PcdStage1ALoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1AFdBase  0U
#define _PCD_SIZE_PcdStage1AFdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1AFdBase  _PCD_SIZE_PcdStage1AFdBase 
#define _PCD_VALUE_PcdStage1AFdBase  0xFFFE5000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1AFdBase;
#define _PCD_GET_MODE_32_PcdStage1AFdBase  _gPcd_FixedAtBuild_PcdStage1AFdBase
//#define _PCD_SET_MODE_32_PcdStage1AFdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1AFvSize  0U
#define _PCD_SIZE_PcdStage1AFvSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1AFvSize  _PCD_SIZE_PcdStage1AFvSize 
#define _PCD_VALUE_PcdStage1AFvSize  0x0000B000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1AFvSize;
#define _PCD_GET_MODE_32_PcdStage1AFvSize  _gPcd_FixedAtBuild_PcdStage1AFvSize
//#define _PCD_SET_MODE_32_PcdStage1AFvSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPTSize  0U
#define _PCD_SIZE_PcdFSPTSize 4
#define _PCD_GET_MODE_SIZE_PcdFSPTSize  _PCD_SIZE_PcdFSPTSize 
#define _PCD_VALUE_PcdFSPTSize  0x00010000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPTSize;
#define _PCD_GET_MODE_32_PcdFSPTSize  _gPcd_FixedAtBuild_PcdFSPTSize
//#define _PCD_SET_MODE_32_PcdFSPTSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPTBase  0U
#define _PCD_SIZE_PcdFSPTBase 4
#define _PCD_GET_MODE_SIZE_PcdFSPTBase  _PCD_SIZE_PcdFSPTBase 
#define _PCD_VALUE_PcdFSPTBase  0xFFFE5000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPTBase;
#define _PCD_GET_MODE_32_PcdFSPTBase  _gPcd_FixedAtBuild_PcdFSPTBase
//#define _PCD_SET_MODE_32_PcdFSPTBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaxServiceNumber  0U
#define _PCD_SIZE_PcdMaxServiceNumber 4
#define _PCD_GET_MODE_SIZE_PcdMaxServiceNumber  _PCD_SIZE_PcdMaxServiceNumber 
#define _PCD_VALUE_PcdMaxServiceNumber  8U
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaxServiceNumber;
#define _PCD_GET_MODE_32_PcdMaxServiceNumber  _gPcd_FixedAtBuild_PcdMaxServiceNumber
//#define _PCD_SET_MODE_32_PcdMaxServiceNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEarlyLogBufferSize  0U
#define _PCD_SIZE_PcdEarlyLogBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdEarlyLogBufferSize  _PCD_SIZE_PcdEarlyLogBufferSize 
#define _PCD_VALUE_PcdEarlyLogBufferSize  0x00000400U
extern const  UINT32  _gPcd_FixedAtBuild_PcdEarlyLogBufferSize;
#define _PCD_GET_MODE_32_PcdEarlyLogBufferSize  _gPcd_FixedAtBuild_PcdEarlyLogBufferSize
//#define _PCD_SET_MODE_32_PcdEarlyLogBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  0U
#define _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel  ((UINT32)0x8000004FU)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel
#define _PCD_PATCHABLE_PcdDebugPrintErrorLevel_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel 
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel; 
#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel(Value)  (_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value))
#define _PCD_SET_MODE_32_S_PcdDebugPrintErrorLevel(Value)  ((_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFileDataBase  0U
#define _PCD_PATCHABLE_VALUE_PcdFileDataBase  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFileDataBase;
#define _PCD_GET_MODE_32_PcdFileDataBase  _gPcd_BinaryPatch_PcdFileDataBase
#define _PCD_PATCHABLE_PcdFileDataBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFileDataBase  _gPcd_BinaryPatch_Size_PcdFileDataBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdFileDataBase; 
#define _PCD_SET_MODE_32_PcdFileDataBase(Value)  (_gPcd_BinaryPatch_PcdFileDataBase = (Value))
#define _PCD_SET_MODE_32_S_PcdFileDataBase(Value)  ((_gPcd_BinaryPatch_PcdFileDataBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdVerifiedBootStage1B  0U
#define _PCD_SIZE_PcdVerifiedBootStage1B 1
#define _PCD_GET_MODE_SIZE_PcdVerifiedBootStage1B  _PCD_SIZE_PcdVerifiedBootStage1B 
#define _PCD_VALUE_PcdVerifiedBootStage1B  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifiedBootStage1B;
#define _PCD_GET_MODE_BOOL_PcdVerifiedBootStage1B  _gPcd_FixedAtBuild_PcdVerifiedBootStage1B
//#define _PCD_SET_MODE_BOOL_PcdVerifiedBootStage1B  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHashStoreSize  0U
#define _PCD_SIZE_PcdHashStoreSize 4
#define _PCD_GET_MODE_SIZE_PcdHashStoreSize  _PCD_SIZE_PcdHashStoreSize 
#define _PCD_VALUE_PcdHashStoreSize  0x00000400U
extern const  UINT32  _gPcd_FixedAtBuild_PcdHashStoreSize;
#define _PCD_GET_MODE_32_PcdHashStoreSize  _gPcd_FixedAtBuild_PcdHashStoreSize
//#define _PCD_SET_MODE_32_PcdHashStoreSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPcdLibId  0U
#define _PCD_SIZE_PcdPcdLibId 1
#define _PCD_GET_MODE_SIZE_PcdPcdLibId  _PCD_SIZE_PcdPcdLibId 
#define _PCD_VALUE_PcdPcdLibId  0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdPcdLibId;
#define _PCD_GET_MODE_8_PcdPcdLibId  _gPcd_FixedAtBuild_PcdPcdLibId
//#define _PCD_SET_MODE_8_PcdPcdLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCompSignHashAlg  0U
#define _PCD_SIZE_PcdCompSignHashAlg 1
#define _PCD_GET_MODE_SIZE_PcdCompSignHashAlg  _PCD_SIZE_PcdCompSignHashAlg 
#define _PCD_VALUE_PcdCompSignHashAlg  0x00000002U
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignHashAlg;
#define _PCD_GET_MODE_8_PcdCompSignHashAlg  _gPcd_FixedAtBuild_PcdCompSignHashAlg
//#define _PCD_SET_MODE_8_PcdCompSignHashAlg  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIdenticalTopSwapsBuilt  0U
#define _PCD_SIZE_PcdIdenticalTopSwapsBuilt 1
#define _PCD_GET_MODE_SIZE_PcdIdenticalTopSwapsBuilt  _PCD_SIZE_PcdIdenticalTopSwapsBuilt 
#define _PCD_VALUE_PcdIdenticalTopSwapsBuilt  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIdenticalTopSwapsBuilt;
#define _PCD_GET_MODE_BOOL_PcdIdenticalTopSwapsBuilt  _gPcd_FixedAtBuild_PcdIdenticalTopSwapsBuilt
//#define _PCD_SET_MODE_BOOL_PcdIdenticalTopSwapsBuilt  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c






#ifdef __cplusplus
}
#endif

#endif
