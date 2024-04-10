/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A68576FB_074E_4490_A82A_7C56121ECC56
#define _AUTOGENH_A68576FB_074E_4490_A82A_7C56121ECC56

#ifdef __cplusplus
extern "C" {
#endif

#include <PiPei.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern GUID  gEdkiiDscPlatformGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA68576FB, 0x074E, 0x4490, {0xA8, 0x2A, 0x7C, 0x56, 0x12, 0x1E, 0xCC, 0x56}}
#define EDKII_DSC_PLATFORM_GUID \
  {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}}

// Guids
extern EFI_GUID gPlatformModuleTokenSpaceGuid;
extern EFI_GUID gFspReservedMemoryResourceHobGuid;
extern EFI_GUID gPlatformCommonLibTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gPlatformAlderLakeTokenSpaceGuid;
extern EFI_GUID gTccRtctHobGuid;
extern EFI_GUID gMeBiosPayloadHobGuid;
extern EFI_GUID gTcgEvent2EntryHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gZeroGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gLoaderSystemTableInfoGuid;
extern EFI_GUID gFspNonVolatileStorageHobGuid;
extern EFI_GUID gFspNonVolatileStorageHob2Guid;
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

#define _PCD_TOKEN_PcdStage1StackSize  0U
#define _PCD_SIZE_PcdStage1StackSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1StackSize  _PCD_SIZE_PcdStage1StackSize 
#define _PCD_VALUE_PcdStage1StackSize  0x00002000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1StackSize;
#define _PCD_GET_MODE_32_PcdStage1StackSize  _gPcd_FixedAtBuild_PcdStage1StackSize
//#define _PCD_SET_MODE_32_PcdStage1StackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1DataSize  0U
#define _PCD_SIZE_PcdStage1DataSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1DataSize  _PCD_SIZE_PcdStage1DataSize 
#define _PCD_VALUE_PcdStage1DataSize  0x00014000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1DataSize;
#define _PCD_GET_MODE_32_PcdStage1DataSize  _gPcd_FixedAtBuild_PcdStage1DataSize
//#define _PCD_SET_MODE_32_PcdStage1DataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPTBase  0U
#define _PCD_SIZE_PcdFSPTBase 4
#define _PCD_GET_MODE_SIZE_PcdFSPTBase  _PCD_SIZE_PcdFSPTBase 
#define _PCD_VALUE_PcdFSPTBase  0xFFFE5000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPTBase;
#define _PCD_GET_MODE_32_PcdFSPTBase  _gPcd_FixedAtBuild_PcdFSPTBase
//#define _PCD_SET_MODE_32_PcdFSPTBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2FdBase  0U
#define _PCD_SIZE_PcdStage2FdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage2FdBase  _PCD_SIZE_PcdStage2FdBase 
#define _PCD_VALUE_PcdStage2FdBase  0x01000000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2FdBase;
#define _PCD_GET_MODE_32_PcdStage2FdBase  _gPcd_FixedAtBuild_PcdStage2FdBase
//#define _PCD_SET_MODE_32_PcdStage2FdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2FdSize  0U
#define _PCD_SIZE_PcdStage2FdSize 4
#define _PCD_GET_MODE_SIZE_PcdStage2FdSize  _PCD_SIZE_PcdStage2FdSize 
#define _PCD_VALUE_PcdStage2FdSize  0x001F0000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2FdSize;
#define _PCD_GET_MODE_32_PcdStage2FdSize  _gPcd_FixedAtBuild_PcdStage2FdSize
//#define _PCD_SET_MODE_32_PcdStage2FdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMrcDataBase  0U
#define _PCD_SIZE_PcdMrcDataBase 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataBase  _PCD_SIZE_PcdMrcDataBase 
#define _PCD_VALUE_PcdMrcDataBase  0xFF579000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdMrcDataBase;
#define _PCD_GET_MODE_32_PcdMrcDataBase  _gPcd_FixedAtBuild_PcdMrcDataBase
//#define _PCD_SET_MODE_32_PcdMrcDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdBase  0U
#define _PCD_SIZE_PcdStage1BFdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdBase  _PCD_SIZE_PcdStage1BFdBase 
#define _PCD_VALUE_PcdStage1BFdBase  0xFFD00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdBase;
#define _PCD_GET_MODE_32_PcdStage1BFdBase  _gPcd_FixedAtBuild_PcdStage1BFdBase
//#define _PCD_SET_MODE_32_PcdStage1BFdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdSize  0U
#define _PCD_SIZE_PcdStage1BFdSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdSize  _PCD_SIZE_PcdStage1BFdSize 
#define _PCD_VALUE_PcdStage1BFdSize  0x00200000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdSize;
#define _PCD_GET_MODE_32_PcdStage1BFdSize  _gPcd_FixedAtBuild_PcdStage1BFdSize
//#define _PCD_SET_MODE_32_PcdStage1BFdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2LoadBase  0U
#define _PCD_SIZE_PcdStage2LoadBase 4
#define _PCD_GET_MODE_SIZE_PcdStage2LoadBase  _PCD_SIZE_PcdStage2LoadBase 
#define _PCD_VALUE_PcdStage2LoadBase  0xFFC19000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2LoadBase;
#define _PCD_GET_MODE_32_PcdStage2LoadBase  _gPcd_FixedAtBuild_PcdStage2LoadBase
//#define _PCD_SET_MODE_32_PcdStage2LoadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLoaderReservedMemSize  0U
#define _PCD_SIZE_PcdLoaderReservedMemSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderReservedMemSize  _PCD_SIZE_PcdLoaderReservedMemSize 
#define _PCD_VALUE_PcdLoaderReservedMemSize  0x00500000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderReservedMemSize;
#define _PCD_GET_MODE_32_PcdLoaderReservedMemSize  _gPcd_FixedAtBuild_PcdLoaderReservedMemSize
//#define _PCD_SET_MODE_32_PcdLoaderReservedMemSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2LoadHigh  0U
#define _PCD_SIZE_PcdStage2LoadHigh 1
#define _PCD_GET_MODE_SIZE_PcdStage2LoadHigh  _PCD_SIZE_PcdStage2LoadHigh 
#define _PCD_VALUE_PcdStage2LoadHigh  0x1
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStage2LoadHigh;
#define _PCD_GET_MODE_BOOL_PcdStage2LoadHigh  _gPcd_FixedAtBuild_PcdStage2LoadHigh
//#define _PCD_SET_MODE_BOOL_PcdStage2LoadHigh  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLoaderHobStackSize  0U
#define _PCD_SIZE_PcdLoaderHobStackSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderHobStackSize  _PCD_SIZE_PcdLoaderHobStackSize 
#define _PCD_VALUE_PcdLoaderHobStackSize  0x00040000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderHobStackSize;
#define _PCD_GET_MODE_32_PcdLoaderHobStackSize  _gPcd_FixedAtBuild_PcdLoaderHobStackSize
//#define _PCD_SET_MODE_32_PcdLoaderHobStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadExeBase  0U
#define _PCD_SIZE_PcdPayloadExeBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadExeBase  _PCD_SIZE_PcdPayloadExeBase 
#define _PCD_VALUE_PcdPayloadExeBase  0x00800000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadExeBase;
#define _PCD_GET_MODE_32_PcdPayloadExeBase  _gPcd_FixedAtBuild_PcdPayloadExeBase
//#define _PCD_SET_MODE_32_PcdPayloadExeBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashBaseAddress  0U
#define _PCD_SIZE_PcdFlashBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdFlashBaseAddress  _PCD_SIZE_PcdFlashBaseAddress 
#define _PCD_VALUE_PcdFlashBaseAddress  0xFF300000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashBaseAddress;
#define _PCD_GET_MODE_32_PcdFlashBaseAddress  _gPcd_FixedAtBuild_PcdFlashBaseAddress
//#define _PCD_SET_MODE_32_PcdFlashBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFlashSize  0U
#define _PCD_SIZE_PcdFlashSize 4
#define _PCD_GET_MODE_SIZE_PcdFlashSize  _PCD_SIZE_PcdFlashSize 
#define _PCD_VALUE_PcdFlashSize  0x00D00000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFlashSize;
#define _PCD_GET_MODE_32_PcdFlashSize  _gPcd_FixedAtBuild_PcdFlashSize
//#define _PCD_SET_MODE_32_PcdFlashSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPMBase  0U
#define _PCD_SIZE_PcdFSPMBase 4
#define _PCD_GET_MODE_SIZE_PcdFSPMBase  _PCD_SIZE_PcdFSPMBase 
#define _PCD_VALUE_PcdFSPMBase  0xFFE40000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPMBase;
#define _PCD_GET_MODE_32_PcdFSPMBase  _gPcd_FixedAtBuild_PcdFSPMBase
//#define _PCD_SET_MODE_32_PcdFSPMBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataSize  0U
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize  _PCD_SIZE_PcdCfgDataSize 
#define _PCD_VALUE_PcdCfgDataSize  0x00004000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataBase  0U
#define _PCD_SIZE_PcdCfgDataBase 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataBase  _PCD_SIZE_PcdCfgDataBase 
#define _PCD_VALUE_PcdCfgDataBase  0xFFCFB000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataBase;
#define _PCD_GET_MODE_32_PcdCfgDataBase  _gPcd_FixedAtBuild_PcdCfgDataBase
//#define _PCD_SET_MODE_32_PcdCfgDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDatabaseSize  0U
#define _PCD_SIZE_PcdCfgDatabaseSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDatabaseSize  _PCD_SIZE_PcdCfgDatabaseSize 
#define _PCD_VALUE_PcdCfgDatabaseSize  0x00004000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDatabaseSize;
#define _PCD_GET_MODE_32_PcdCfgDatabaseSize  _gPcd_FixedAtBuild_PcdCfgDatabaseSize
//#define _PCD_SET_MODE_32_PcdCfgDatabaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BXip  0U
#define _PCD_SIZE_PcdStage1BXip 1
#define _PCD_GET_MODE_SIZE_PcdStage1BXip  _PCD_SIZE_PcdStage1BXip 
#define _PCD_VALUE_PcdStage1BXip  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStage1BXip;
#define _PCD_GET_MODE_BOOL_PcdStage1BXip  _gPcd_FixedAtBuild_PcdStage1BXip
//#define _PCD_SET_MODE_BOOL_PcdStage1BXip  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  0U
#define _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel  ((UINT32)0x8000004FU)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel
#define _PCD_PATCHABLE_PcdDebugPrintErrorLevel_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel 
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel; 
#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel(Value)  (_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value))
#define _PCD_SET_MODE_32_S_PcdDebugPrintErrorLevel(Value)  ((_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdS3DebugEnabled  0U
#define _PCD_SIZE_PcdS3DebugEnabled 1
#define _PCD_GET_MODE_SIZE_PcdS3DebugEnabled  _PCD_SIZE_PcdS3DebugEnabled 
#define _PCD_VALUE_PcdS3DebugEnabled  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdS3DebugEnabled;
#define _PCD_GET_MODE_BOOL_PcdS3DebugEnabled  _gPcd_FixedAtBuild_PcdS3DebugEnabled
//#define _PCD_SET_MODE_BOOL_PcdS3DebugEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataLoadSource  0U
#define _PCD_SIZE_PcdCfgDataLoadSource 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataLoadSource  _PCD_SIZE_PcdCfgDataLoadSource 
#define _PCD_VALUE_PcdCfgDataLoadSource  0x1U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataLoadSource;
#define _PCD_GET_MODE_32_PcdCfgDataLoadSource  _gPcd_FixedAtBuild_PcdCfgDataLoadSource
//#define _PCD_SET_MODE_32_PcdCfgDataLoadSource  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMeasuredBootEnabled  0U
#define _PCD_SIZE_PcdMeasuredBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootEnabled  _PCD_SIZE_PcdMeasuredBootEnabled 
#define _PCD_VALUE_PcdMeasuredBootEnabled  ((BOOLEAN)0x1)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdMeasuredBootEnabled  _gPcd_FixedAtBuild_PcdMeasuredBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdMeasuredBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEarlyLogBufferSize  0U
#define _PCD_SIZE_PcdEarlyLogBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdEarlyLogBufferSize  _PCD_SIZE_PcdEarlyLogBufferSize 
#define _PCD_VALUE_PcdEarlyLogBufferSize  0x00000400U
extern const  UINT32  _gPcd_FixedAtBuild_PcdEarlyLogBufferSize;
#define _PCD_GET_MODE_32_PcdEarlyLogBufferSize  _gPcd_FixedAtBuild_PcdEarlyLogBufferSize
//#define _PCD_SET_MODE_32_PcdEarlyLogBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLogBufferSize  0U
#define _PCD_SIZE_PcdLogBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdLogBufferSize  _PCD_SIZE_PcdLogBufferSize 
#define _PCD_VALUE_PcdLogBufferSize  0x00008000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLogBufferSize;
#define _PCD_GET_MODE_32_PcdLogBufferSize  _gPcd_FixedAtBuild_PcdLogBufferSize
//#define _PCD_SET_MODE_32_PcdLogBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataIntBase  0U
#define _PCD_PATCHABLE_VALUE_PcdCfgDataIntBase  ((UINT32)0xFF000000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdCfgDataIntBase;
#define _PCD_GET_MODE_32_PcdCfgDataIntBase  _gPcd_BinaryPatch_PcdCfgDataIntBase
#define _PCD_PATCHABLE_PcdCfgDataIntBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataIntBase  _gPcd_BinaryPatch_Size_PcdCfgDataIntBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdCfgDataIntBase; 
#define _PCD_SET_MODE_32_PcdCfgDataIntBase(Value)  (_gPcd_BinaryPatch_PcdCfgDataIntBase = (Value))
#define _PCD_SET_MODE_32_S_PcdCfgDataIntBase(Value)  ((_gPcd_BinaryPatch_PcdCfgDataIntBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdCompSignHashAlg  0U
#define _PCD_SIZE_PcdCompSignHashAlg 1
#define _PCD_GET_MODE_SIZE_PcdCompSignHashAlg  _PCD_SIZE_PcdCompSignHashAlg 
#define _PCD_VALUE_PcdCompSignHashAlg  0x00000002U
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignHashAlg;
#define _PCD_GET_MODE_8_PcdCompSignHashAlg  _gPcd_FixedAtBuild_PcdCompSignHashAlg
//#define _PCD_SET_MODE_8_PcdCompSignHashAlg  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMeasuredBootHashMask  2U
#define _PCD_GET_MODE_32_PcdMeasuredBootHashMask  LibPcdGet32(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_GET_MODE_SIZE_PcdMeasuredBootHashMask  LibPcdGetSize(_PCD_TOKEN_PcdMeasuredBootHashMask)
#define _PCD_SET_MODE_32_PcdMeasuredBootHashMask(Value)  LibPcdSet32(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))
#define _PCD_SET_MODE_32_S_PcdMeasuredBootHashMask(Value)  LibPcdSet32S(_PCD_TOKEN_PcdMeasuredBootHashMask, (Value))

#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
#define _PCD_SIZE_PcdDmaProtectionEnabled 1
#define _PCD_GET_MODE_SIZE_PcdDmaProtectionEnabled  _PCD_SIZE_PcdDmaProtectionEnabled 
#define _PCD_VALUE_PcdDmaProtectionEnabled  ((BOOLEAN)0x0)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDmaBufferAlignment  0U
#define _PCD_SIZE_PcdDmaBufferAlignment 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferAlignment  _PCD_SIZE_PcdDmaBufferAlignment 
#define _PCD_VALUE_PcdDmaBufferAlignment  0x00100000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdDmaBufferAlignment;
#define _PCD_GET_MODE_32_PcdDmaBufferAlignment  _gPcd_FixedAtBuild_PcdDmaBufferAlignment
//#define _PCD_SET_MODE_32_PcdDmaBufferAlignment  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDmaBufferSize  0U
#define _PCD_SIZE_PcdDmaBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferSize  _PCD_SIZE_PcdDmaBufferSize 
#define _PCD_VALUE_PcdDmaBufferSize  0x00400000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdDmaBufferSize;
#define _PCD_GET_MODE_32_PcdDmaBufferSize  _gPcd_FixedAtBuild_PcdDmaBufferSize
//#define _PCD_SET_MODE_32_PcdDmaBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadReservedMemSize  0U
#define _PCD_PATCHABLE_VALUE_PcdPayloadReservedMemSize  ((UINT32)0x00500000U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPayloadReservedMemSize;
#define _PCD_GET_MODE_32_PcdPayloadReservedMemSize  _gPcd_BinaryPatch_PcdPayloadReservedMemSize
#define _PCD_PATCHABLE_PcdPayloadReservedMemSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPayloadReservedMemSize  _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize; 
#define _PCD_SET_MODE_32_PcdPayloadReservedMemSize(Value)  (_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value))
#define _PCD_SET_MODE_32_S_PcdPayloadReservedMemSize(Value)  ((_gPcd_BinaryPatch_PcdPayloadReservedMemSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdLoaderAcpiNvsSize  0U
#define _PCD_SIZE_PcdLoaderAcpiNvsSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderAcpiNvsSize  _PCD_SIZE_PcdLoaderAcpiNvsSize 
#define _PCD_VALUE_PcdLoaderAcpiNvsSize  0x00008000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize;
#define _PCD_GET_MODE_32_PcdLoaderAcpiNvsSize  _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize
//#define _PCD_SET_MODE_32_PcdLoaderAcpiNvsSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLoaderAcpiReclaimSize  0U
#define _PCD_SIZE_PcdLoaderAcpiReclaimSize 4
#define _PCD_GET_MODE_SIZE_PcdLoaderAcpiReclaimSize  _PCD_SIZE_PcdLoaderAcpiReclaimSize 
#define _PCD_VALUE_PcdLoaderAcpiReclaimSize  0x00090000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize;
#define _PCD_GET_MODE_32_PcdLoaderAcpiReclaimSize  _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize
//#define _PCD_SET_MODE_32_PcdLoaderAcpiReclaimSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEnableSetup  0U
#define _PCD_SIZE_PcdEnableSetup 1
#define _PCD_GET_MODE_SIZE_PcdEnableSetup  _PCD_SIZE_PcdEnableSetup 
#define _PCD_VALUE_PcdEnableSetup  ((BOOLEAN)0x0)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEnableSetup;
#define _PCD_GET_MODE_BOOL_PcdEnableSetup  _gPcd_FixedAtBuild_PcdEnableSetup
//#define _PCD_SET_MODE_BOOL_PcdEnableSetup  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSblResiliencyEnabled  0U
#define _PCD_SIZE_PcdSblResiliencyEnabled 1
#define _PCD_GET_MODE_SIZE_PcdSblResiliencyEnabled  _PCD_SIZE_PcdSblResiliencyEnabled 
#define _PCD_VALUE_PcdSblResiliencyEnabled  0x0
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled;
#define _PCD_GET_MODE_BOOL_PcdSblResiliencyEnabled  _gPcd_FixedAtBuild_PcdSblResiliencyEnabled
//#define _PCD_SET_MODE_BOOL_PcdSblResiliencyEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdBootFailureThreshold  0U
#define _PCD_SIZE_PcdBootFailureThreshold 1
#define _PCD_GET_MODE_SIZE_PcdBootFailureThreshold  _PCD_SIZE_PcdBootFailureThreshold 
#define _PCD_VALUE_PcdBootFailureThreshold  3U
extern const  UINT8  _gPcd_FixedAtBuild_PcdBootFailureThreshold;
#define _PCD_GET_MODE_8_PcdBootFailureThreshold  _gPcd_FixedAtBuild_PcdBootFailureThreshold
//#define _PCD_SET_MODE_8_PcdBootFailureThreshold  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcoTimeout  0U
#define _PCD_SIZE_PcdTcoTimeout 2
#define _PCD_GET_MODE_SIZE_PcdTcoTimeout  _PCD_SIZE_PcdTcoTimeout 
#define _PCD_VALUE_PcdTcoTimeout  50U
extern const  UINT16  _gPcd_FixedAtBuild_PcdTcoTimeout;
#define _PCD_GET_MODE_16_PcdTcoTimeout  _gPcd_FixedAtBuild_PcdTcoTimeout
//#define _PCD_SET_MODE_16_PcdTcoTimeout  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c






#ifdef __cplusplus
}
#endif

#endif
