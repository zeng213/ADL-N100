/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.h
  Abstract:       Auto-generated AutoGen.h for building module or library.
**/

#ifndef _AUTOGENH_A3FF0EF5_0C28_42f5_B544_8C7DE1E80014
#define _AUTOGENH_A3FF0EF5_0C28_42f5_B544_8C7DE1E80014

#ifdef __cplusplus
extern "C" {
#endif

#include <PiDxe.h>
#include <Library/PcdLib.h>

extern GUID  gEfiCallerIdGuid;
extern CHAR8 *gEfiCallerBaseName;

#define EFI_CALLER_ID_GUID \
  {0xA3FF0EF5, 0x0C28, 0x42f5, {0xB5, 0x44, 0x8C, 0x7D, 0xE1, 0xE8, 0x00, 0x14}}

// Guids
extern EFI_GUID gEfiAcpiVariableGuid;
extern EFI_GUID gEdkiiPiSmmMemoryAttributesTableGuid;
extern EFI_GUID gEfiMemoryAttributesTableGuid;
extern EFI_GUID gUefiCpuPkgTokenSpaceGuid;
extern EFI_GUID gEfiMdeModulePkgTokenSpaceGuid;
extern EFI_GUID gEfiMdePkgTokenSpaceGuid;
extern EFI_GUID gUefiSystemTableInfoGuid;
extern EFI_GUID gUefiSerialPortInfoGuid;
extern EFI_GUID gLoaderMemoryMapInfoGuid;
extern EFI_GUID gEfiGraphicsInfoHobGuid;
extern EFI_GUID gEfiGraphicsDeviceInfoHobGuid;
extern EFI_GUID gUefiPayloadPkgTokenSpaceGuid;
extern EFI_GUID gEfiVTUTF8Guid;
extern EFI_GUID gEfiVT100Guid;
extern EFI_GUID gEfiVT100PlusGuid;
extern EFI_GUID gEfiPcAnsiGuid;
extern EFI_GUID gEfiUartDevicePathGuid;
extern EFI_GUID gEfiSasDevicePathGuid;
extern EFI_GUID gEfiVirtualDiskGuid;
extern EFI_GUID gEfiVirtualCdGuid;
extern EFI_GUID gEfiPersistentVirtualDiskGuid;
extern EFI_GUID gEfiPersistentVirtualCdGuid;
extern EFI_GUID gEfiEventReadyToBootGuid;
extern EFI_GUID gEfiEventLegacyBootGuid;
extern EFI_GUID gEfiGlobalVariableGuid;
extern EFI_GUID gEfiAcpi20TableGuid;
extern EFI_GUID gEfiAcpi10TableGuid;
extern EFI_GUID gEfiHobListGuid;
extern EFI_GUID gUefiAcpiBoardInfoGuid;
extern EFI_GUID gEfiDxeServicesTableGuid;

// Protocols
extern EFI_GUID gEfiSmmAccess2ProtocolGuid;
extern EFI_GUID gEfiMpServiceProtocolGuid;
extern EFI_GUID gEfiSmmConfigurationProtocolGuid;
extern EFI_GUID gEfiSmmCpuProtocolGuid;
extern EFI_GUID gEfiSmmReadyToLockProtocolGuid;
extern EFI_GUID gEfiSmmCpuServiceProtocolGuid;
extern EFI_GUID gEdkiiSmmMemoryAttributeProtocolGuid;
extern EFI_GUID gEfiMmMpProtocolGuid;
extern EFI_GUID gPcdProtocolGuid;
extern EFI_GUID gEfiPcdProtocolGuid;
extern EFI_GUID gGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiGetPcdInfoProtocolGuid;
extern EFI_GUID gEfiSmmBase2ProtocolGuid;
extern EFI_GUID gEfiDevicePathProtocolGuid;
extern EFI_GUID gEfiDebugPortProtocolGuid;
extern EFI_GUID gEfiDriverBindingProtocolGuid;
extern EFI_GUID gEfiSimpleTextOutProtocolGuid;
extern EFI_GUID gEfiGraphicsOutputProtocolGuid;
extern EFI_GUID gEfiHiiFontProtocolGuid;
extern EFI_GUID gEfiSimpleFileSystemProtocolGuid;
extern EFI_GUID gEfiUgaDrawProtocolGuid;
extern EFI_GUID gEfiComponentNameProtocolGuid;
extern EFI_GUID gEfiComponentName2ProtocolGuid;
extern EFI_GUID gEfiDriverConfigurationProtocolGuid;
extern EFI_GUID gEfiDriverConfiguration2ProtocolGuid;
extern EFI_GUID gEfiDriverDiagnosticsProtocolGuid;
extern EFI_GUID gEfiDriverDiagnostics2ProtocolGuid;
extern EFI_GUID gEfiLoadedImageProtocolGuid;

// Definition of SkuId Array
extern UINT64 _gPcd_SkuId_Array[];

// Definition of PCDs used in this module

#define _PCD_TOKEN_PcdCpuSmmMpTokenCountPerChunk  271U
#define _PCD_SIZE_PcdCpuSmmMpTokenCountPerChunk 4
#define _PCD_GET_MODE_SIZE_PcdCpuSmmMpTokenCountPerChunk  _PCD_SIZE_PcdCpuSmmMpTokenCountPerChunk 
#define _PCD_VALUE_PcdCpuSmmMpTokenCountPerChunk  64U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuSmmMpTokenCountPerChunk;
#define _PCD_GET_MODE_32_PcdCpuSmmMpTokenCountPerChunk  _gPcd_FixedAtBuild_PcdCpuSmmMpTokenCountPerChunk
//#define _PCD_SET_MODE_32_PcdCpuSmmMpTokenCountPerChunk  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmDebug  268U
#define _PCD_SIZE_PcdCpuSmmDebug 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmDebug  _PCD_SIZE_PcdCpuSmmDebug 
#define _PCD_VALUE_PcdCpuSmmDebug  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmDebug;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmDebug  _gPcd_FixedAtBuild_PcdCpuSmmDebug
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmDebug  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmBlockStartupThisAp  266U
#define _PCD_SIZE_PcdCpuSmmBlockStartupThisAp 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmBlockStartupThisAp  _PCD_SIZE_PcdCpuSmmBlockStartupThisAp 
#define _PCD_VALUE_PcdCpuSmmBlockStartupThisAp  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmBlockStartupThisAp;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmBlockStartupThisAp  _gPcd_FixedAtBuild_PcdCpuSmmBlockStartupThisAp
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmBlockStartupThisAp  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmEnableBspElection  269U
#define _PCD_SIZE_PcdCpuSmmEnableBspElection 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmEnableBspElection  _PCD_SIZE_PcdCpuSmmEnableBspElection 
#define _PCD_VALUE_PcdCpuSmmEnableBspElection  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmEnableBspElection;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmEnableBspElection  _gPcd_FixedAtBuild_PcdCpuSmmEnableBspElection
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmEnableBspElection  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuHotPlugSupport  257U
#define _PCD_SIZE_PcdCpuHotPlugSupport 1
#define _PCD_GET_MODE_SIZE_PcdCpuHotPlugSupport  _PCD_SIZE_PcdCpuHotPlugSupport 
#define _PCD_VALUE_PcdCpuHotPlugSupport  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuHotPlugSupport;
#define _PCD_GET_MODE_BOOL_PcdCpuHotPlugSupport  _gPcd_FixedAtBuild_PcdCpuHotPlugSupport
//#define _PCD_SET_MODE_BOOL_PcdCpuHotPlugSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmStackGuard  277U
#define _PCD_SIZE_PcdCpuSmmStackGuard 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmStackGuard  _PCD_SIZE_PcdCpuSmmStackGuard 
#define _PCD_VALUE_PcdCpuSmmStackGuard  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmStackGuard;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmStackGuard  _gPcd_FixedAtBuild_PcdCpuSmmStackGuard
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmStackGuard  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmProfileEnable  272U
#define _PCD_SIZE_PcdCpuSmmProfileEnable 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmProfileEnable  _PCD_SIZE_PcdCpuSmmProfileEnable 
#define _PCD_VALUE_PcdCpuSmmProfileEnable  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmProfileEnable;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmProfileEnable  _gPcd_FixedAtBuild_PcdCpuSmmProfileEnable
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmProfileEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmProfileRingBuffer  273U
#define _PCD_SIZE_PcdCpuSmmProfileRingBuffer 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmProfileRingBuffer  _PCD_SIZE_PcdCpuSmmProfileRingBuffer 
#define _PCD_VALUE_PcdCpuSmmProfileRingBuffer  ((BOOLEAN)0U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmProfileRingBuffer;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmProfileRingBuffer  _gPcd_FixedAtBuild_PcdCpuSmmProfileRingBuffer
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmProfileRingBuffer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmFeatureControlMsrLock  270U
#define _PCD_SIZE_PcdCpuSmmFeatureControlMsrLock 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmFeatureControlMsrLock  _PCD_SIZE_PcdCpuSmmFeatureControlMsrLock 
#define _PCD_VALUE_PcdCpuSmmFeatureControlMsrLock  ((BOOLEAN)1U)
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmFeatureControlMsrLock;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmFeatureControlMsrLock  _gPcd_FixedAtBuild_PcdCpuSmmFeatureControlMsrLock
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmFeatureControlMsrLock  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuMaxLogicalProcessorNumber  261U
#define _PCD_PATCHABLE_VALUE_PcdCpuMaxLogicalProcessorNumber  ((UINT32)64U)
extern volatile   UINT32  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuMaxLogicalProcessorNumber  _gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber
#define _PCD_PATCHABLE_PcdCpuMaxLogicalProcessorNumber_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdCpuMaxLogicalProcessorNumber  _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber 
extern UINTN _gPcd_BinaryPatch_Size_PcdCpuMaxLogicalProcessorNumber; 
#define _PCD_SET_MODE_32_PcdCpuMaxLogicalProcessorNumber(Value)  (_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value))
#define _PCD_SET_MODE_32_S_PcdCpuMaxLogicalProcessorNumber(Value)  ((_gPcd_BinaryPatch_PcdCpuMaxLogicalProcessorNumber = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdCpuSmmProfileSize  274U
#define _PCD_SIZE_PcdCpuSmmProfileSize 4
#define _PCD_GET_MODE_SIZE_PcdCpuSmmProfileSize  _PCD_SIZE_PcdCpuSmmProfileSize 
#define _PCD_VALUE_PcdCpuSmmProfileSize  0x200000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuSmmProfileSize;
#define _PCD_GET_MODE_32_PcdCpuSmmProfileSize  _gPcd_FixedAtBuild_PcdCpuSmmProfileSize
//#define _PCD_SET_MODE_32_PcdCpuSmmProfileSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmStackSize  278U
#define _PCD_SIZE_PcdCpuSmmStackSize 4
#define _PCD_GET_MODE_SIZE_PcdCpuSmmStackSize  _PCD_SIZE_PcdCpuSmmStackSize 
#define _PCD_VALUE_PcdCpuSmmStackSize  0x4000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuSmmStackSize;
#define _PCD_GET_MODE_32_PcdCpuSmmStackSize  _gPcd_FixedAtBuild_PcdCpuSmmStackSize
//#define _PCD_SET_MODE_32_PcdCpuSmmStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmApSyncTimeout  265U
#define _PCD_SIZE_PcdCpuSmmApSyncTimeout 8
#define _PCD_GET_MODE_SIZE_PcdCpuSmmApSyncTimeout  _PCD_SIZE_PcdCpuSmmApSyncTimeout 
#define _PCD_VALUE_PcdCpuSmmApSyncTimeout  1000000ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdCpuSmmApSyncTimeout;
#define _PCD_GET_MODE_64_PcdCpuSmmApSyncTimeout  _gPcd_FixedAtBuild_PcdCpuSmmApSyncTimeout
//#define _PCD_SET_MODE_64_PcdCpuSmmApSyncTimeout  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuS3DataAddress  35U
#define _PCD_GET_MODE_64_PcdCpuS3DataAddress  LibPcdGet64(_PCD_TOKEN_PcdCpuS3DataAddress)
#define _PCD_GET_MODE_SIZE_PcdCpuS3DataAddress  LibPcdGetSize(_PCD_TOKEN_PcdCpuS3DataAddress)
#define _PCD_SET_MODE_64_PcdCpuS3DataAddress(Value)  LibPcdSet64(_PCD_TOKEN_PcdCpuS3DataAddress, (Value))
#define _PCD_SET_MODE_64_S_PcdCpuS3DataAddress(Value)  LibPcdSet64S(_PCD_TOKEN_PcdCpuS3DataAddress, (Value))

#define _PCD_TOKEN_PcdCpuHotPlugDataAddress  34U
#define _PCD_GET_MODE_64_PcdCpuHotPlugDataAddress  LibPcdGet64(_PCD_TOKEN_PcdCpuHotPlugDataAddress)
#define _PCD_GET_MODE_SIZE_PcdCpuHotPlugDataAddress  LibPcdGetSize(_PCD_TOKEN_PcdCpuHotPlugDataAddress)
#define _PCD_SET_MODE_64_PcdCpuHotPlugDataAddress(Value)  LibPcdSet64(_PCD_TOKEN_PcdCpuHotPlugDataAddress, (Value))
#define _PCD_SET_MODE_64_S_PcdCpuHotPlugDataAddress(Value)  LibPcdSet64S(_PCD_TOKEN_PcdCpuHotPlugDataAddress, (Value))

#define _PCD_TOKEN_PcdCpuSmmCodeAccessCheckEnable  267U
#define _PCD_SIZE_PcdCpuSmmCodeAccessCheckEnable 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmCodeAccessCheckEnable  _PCD_SIZE_PcdCpuSmmCodeAccessCheckEnable 
#define _PCD_VALUE_PcdCpuSmmCodeAccessCheckEnable  1U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmCodeAccessCheckEnable;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmCodeAccessCheckEnable  _gPcd_FixedAtBuild_PcdCpuSmmCodeAccessCheckEnable
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmCodeAccessCheckEnable  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmSyncMode  279U
#define _PCD_SIZE_PcdCpuSmmSyncMode 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmSyncMode  _PCD_SIZE_PcdCpuSmmSyncMode 
#define _PCD_VALUE_PcdCpuSmmSyncMode  0x00U
extern const  UINT8  _gPcd_FixedAtBuild_PcdCpuSmmSyncMode;
#define _PCD_GET_MODE_8_PcdCpuSmmSyncMode  _gPcd_FixedAtBuild_PcdCpuSmmSyncMode
//#define _PCD_SET_MODE_8_PcdCpuSmmSyncMode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmShadowStackSize  276U
#define _PCD_SIZE_PcdCpuSmmShadowStackSize 4
#define _PCD_GET_MODE_SIZE_PcdCpuSmmShadowStackSize  _PCD_SIZE_PcdCpuSmmShadowStackSize 
#define _PCD_VALUE_PcdCpuSmmShadowStackSize  0x2000U
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuSmmShadowStackSize;
#define _PCD_GET_MODE_32_PcdCpuSmmShadowStackSize  _gPcd_FixedAtBuild_PcdCpuSmmShadowStackSize
//#define _PCD_SET_MODE_32_PcdCpuSmmShadowStackSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiS3Enable  1U
#define _PCD_GET_MODE_BOOL_PcdAcpiS3Enable  LibPcdGetBool(_PCD_TOKEN_PcdAcpiS3Enable)
#define _PCD_GET_MODE_SIZE_PcdAcpiS3Enable  LibPcdGetSize(_PCD_TOKEN_PcdAcpiS3Enable)
#define _PCD_SET_MODE_BOOL_PcdAcpiS3Enable(Value)  LibPcdSetBool(_PCD_TOKEN_PcdAcpiS3Enable, (Value))
#define _PCD_SET_MODE_BOOL_S_PcdAcpiS3Enable(Value)  LibPcdSetBoolS(_PCD_TOKEN_PcdAcpiS3Enable, (Value))

#define _PCD_TOKEN_PcdPteMemoryEncryptionAddressOrMask  114U
#define _PCD_SIZE_PcdPteMemoryEncryptionAddressOrMask 8
#define _PCD_GET_MODE_SIZE_PcdPteMemoryEncryptionAddressOrMask  _PCD_SIZE_PcdPteMemoryEncryptionAddressOrMask 
#define _PCD_VALUE_PcdPteMemoryEncryptionAddressOrMask  0x0ULL
extern const  UINT64  _gPcd_FixedAtBuild_PcdPteMemoryEncryptionAddressOrMask;
#define _PCD_GET_MODE_64_PcdPteMemoryEncryptionAddressOrMask  _gPcd_FixedAtBuild_PcdPteMemoryEncryptionAddressOrMask
//#define _PCD_SET_MODE_64_PcdPteMemoryEncryptionAddressOrMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdNullPointerDetectionPropertyMask  105U
#define _PCD_SIZE_PcdNullPointerDetectionPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdNullPointerDetectionPropertyMask  _PCD_SIZE_PcdNullPointerDetectionPropertyMask 
#define _PCD_VALUE_PcdNullPointerDetectionPropertyMask  0x0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdNullPointerDetectionPropertyMask;
#define _PCD_GET_MODE_8_PcdNullPointerDetectionPropertyMask  _gPcd_FixedAtBuild_PcdNullPointerDetectionPropertyMask
//#define _PCD_SET_MODE_8_PcdNullPointerDetectionPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdHeapGuardPropertyMask  83U
#define _PCD_SIZE_PcdHeapGuardPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdHeapGuardPropertyMask  _PCD_SIZE_PcdHeapGuardPropertyMask 
#define _PCD_VALUE_PcdHeapGuardPropertyMask  0x0U
extern const  UINT8  _gPcd_FixedAtBuild_PcdHeapGuardPropertyMask;
#define _PCD_GET_MODE_8_PcdHeapGuardPropertyMask  _gPcd_FixedAtBuild_PcdHeapGuardPropertyMask
//#define _PCD_SET_MODE_8_PcdHeapGuardPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  157U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSmmRestrictedMemoryAccess  275U
#define _PCD_SIZE_PcdCpuSmmRestrictedMemoryAccess 1
#define _PCD_GET_MODE_SIZE_PcdCpuSmmRestrictedMemoryAccess  _PCD_SIZE_PcdCpuSmmRestrictedMemoryAccess 
#define _PCD_VALUE_PcdCpuSmmRestrictedMemoryAccess  0U
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuSmmRestrictedMemoryAccess;
#define _PCD_GET_MODE_BOOL_PcdCpuSmmRestrictedMemoryAccess  _gPcd_FixedAtBuild_PcdCpuSmmRestrictedMemoryAccess
//#define _PCD_SET_MODE_BOOL_PcdCpuSmmRestrictedMemoryAccess  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

// Definition of PCDs used in libraries is in AutoGen.c


EFI_STATUS
EFIAPI
PiCpuSmmEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  );





#ifdef __cplusplus
}
#endif

#endif
