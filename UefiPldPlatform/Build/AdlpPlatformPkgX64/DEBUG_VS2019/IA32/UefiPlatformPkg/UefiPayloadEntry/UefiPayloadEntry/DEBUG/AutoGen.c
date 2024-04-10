/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <PiPei.h>
#include <Library/DebugLib.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0x2119BBD7, 0x9432, 0x4f47, {0xB5, 0xE2, 0x5C, 0x4E, 0xA3, 0x1B, 0x6B, 0xDC}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "PayloadEntry";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMemoryTypeInformationGuid = { 0x4C19049F, 0x4137, 0x4DD3, { 0x9C, 0x10, 0x8B, 0x97, 0xA8, 0x3F, 0xFD, 0xFA }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiFirmwareFileSystem2Guid = { 0x8c8ce578, 0x8a3d, 0x4f1c, { 0x99, 0x35, 0x89, 0x61, 0x85, 0xc3, 0x2d, 0xd3 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiSystemTableInfoGuid = {0x16c8a6d0, 0xfe8a, 0x4082, {0xa2, 0x8, 0xcf, 0x89, 0xc4, 0x29, 0x4, 0x33}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsInfoHobGuid = { 0x39f62cce, 0x6825, 0x4669, { 0xbb, 0x56, 0x54, 0x1a, 0xba, 0x75, 0x3a, 0x07 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsDeviceInfoHobGuid = { 0xe5cb2ac9, 0xd35d, 0x4430, { 0x93, 0x6e, 0x1d, 0xe3, 0x32, 0x47, 0x8d, 0xe7 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiAcpiBoardInfoGuid = {0xad3d31b, 0xb3d8, 0x4506, {0xae, 0x71, 0x2e, 0xf1, 0x10, 0x6, 0xd9, 0xf}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdeModulePkgTokenSpaceGuid = { 0xA1AFF049, 0xFDEB, 0x442a, { 0xB3, 0x20, 0x13, 0xAB, 0x4C, 0xB7, 0x2B, 0xBC }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiPayloadPkgTokenSpaceGuid = {0x1d127ea, 0xf6f1, 0x4ef6, {0x94, 0x15, 0x8a, 0x0, 0x0, 0x93, 0xf8, 0x9d}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiPlatformPkgTokenSpaceGuid = {0xd4a87cb3, 0x9de7, 0x4029, {0x96, 0x78, 0x69, 0xd8, 0x94, 0x88, 0xc4, 0x9b}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHobMemoryAllocModuleGuid = { 0xF8E21975, 0x0899, 0x4F58, { 0xA4, 0xBE, 0x55, 0x25, 0xA9, 0xC6, 0xD7, 0x7A }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiHobMemoryAllocStackGuid = { 0x4ED4BF27, 0x4092, 0x42E9, { 0x80, 0x7D, 0x52, 0x7B, 0x1D, 0x00, 0xC9, 0xBD }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEmbeddedTokenSpaceGuid = { 0xe0d8ca17, 0x4276, 0x4386, { 0xbb, 0x79, 0x48, 0xcb, 0x81, 0x3d, 0x3c, 0x4f }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUefiSerialPortInfoGuid = { 0x6c6872fe, 0x56a9, 0x4403, { 0xbb, 0x98, 0x95, 0x8d, 0x62, 0xde, 0x87, 0xf1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderMemoryMapInfoGuid = { 0xa1ff7424, 0x7a1a, 0x478e, { 0xa9, 0xe4, 0x92, 0xf3, 0x57, 0xd1, 0x28, 0x32 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderFspInfoGuid = { 0xbd42bc23, 0x1efe, 0x4b2b, { 0xa5, 0x8e, 0x08, 0x8b, 0x5b, 0xa2, 0xf5, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSmmInformationGuid = { 0x2d939d66, 0xceec, 0x4244, {0x94, 0x97, 0x6e, 0x1c, 0x6f, 0x92, 0x54, 0x2c}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTpmEventLogInfoGuid = { 0xcdaffea5, 0x5e2, 0x4c2f,  {0x8b, 0xa7, 0xad, 0xbc, 0x8d, 0xfd, 0x5a, 0x9e}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSpiFlashVariableInfoGuid = { 0x2d4aac1b, 0x91a5, 0x4cd5, { 0x9b, 0x5c, 0xb4, 0x0f, 0x5d, 0x28, 0x51, 0xa1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPlatformInfoGuid = { 0x7b6bad42, 0xd3ab, 0x4947, { 0xa2, 0x6e, 0xd6, 0xf9, 0xa9, 0xac, 0x4a, 0x2a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gDeviceTableHobGuid = { 0xd21fc32c, 0x7fd2, 0x435b, { 0xb8, 0xef, 0xc0, 0x42, 0x66, 0xa8, 0xf4, 0xf5 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFlashMapInfoGuid = { 0xaf7f452c, 0x5b00, 0x4598, { 0xb4, 0x8c, 0xbf, 0x57, 0xa2, 0x08, 0x71, 0xa1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPerformanceInfoGuid = { 0x868204be, 0x23d0, 0x4ff9, { 0xac, 0x34, 0xb9, 0x95, 0xac, 0x04, 0xb1, 0xb9 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSecurityPkgTokenSpaceGuid = { 0xd3fb176, 0x9569, 0x4d51, { 0xa3, 0xef, 0x7d, 0x61, 0xc6, 0x4f, 0xea, 0xba }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiTpmDeviceInstanceNoneGuid = { 0x00000000, 0x0000, 0x0000, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiTpmDeviceInstanceTpm20DtpmGuid = { 0x286bf25a, 0xc2c3, 0x408c, { 0xb3, 0xb4, 0x25, 0xe6, 0x75, 0x8b, 0x73, 0x17 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTpmDeviceInstanceTpm20PttPtpGuid = { 0x93d66f66, 0x55da, 0x4f03, { 0x9b, 0x5f, 0x32, 0xcf, 0x9e, 0x54, 0x3b, 0x3a }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPciRootBridgeInfoGuid = { 0xb7f3d111, 0xb98d, 0x422f, { 0x84, 0x31, 0xa7, 0xd8, 0x29, 0xec, 0x00, 0x87 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSecureBootInfoGuid = { 0xd970f847, 0x07dd, 0x4b24, { 0x9e, 0x1e, 0xae, 0x6c, 0x80, 0x9b, 0x1d, 0x38 } };

// Protocols
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPeCoffLoaderProtocolGuid = { 0xB323179B, 0x97FB, 0x477E, { 0xB0, 0xFE, 0xD8, 0x85, 0x91, 0xFA, 0x11, 0xAB } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in this module
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdDxeIplSwitchToLongMode = _PCD_VALUE_PcdDxeIplSwitchToLongMode;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdUse1GPageTable = _PCD_VALUE_PcdUse1GPageTable;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPteMemoryEncryptionAddressOrMask = _PCD_VALUE_PcdPteMemoryEncryptionAddressOrMask;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdNullPointerDetectionPropertyMask = _PCD_VALUE_PcdNullPointerDetectionPropertyMask;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdHeapGuardPropertyMask = _PCD_VALUE_PcdHeapGuardPropertyMask;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdCpuStackGuard = _PCD_VALUE_PcdCpuStackGuard;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdUse5LevelPageTable = _PCD_VALUE_PcdUse5LevelPageTable;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadFdMemBase = _PCD_VALUE_PcdPayloadFdMemBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadFdMemSize = _PCD_VALUE_PcdPayloadFdMemSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadStackTop = _PCD_VALUE_PcdPayloadStackTop;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSystemMemoryUefiRegionSize = _PCD_VALUE_PcdSystemMemoryUefiRegionSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSetNxForStack = _PCD_VALUE_PcdSetNxForStack;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdDxeNxMemoryProtectionPolicy = _PCD_VALUE_PcdDxeNxMemoryProtectionPolicy;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdImageProtectionPolicy = _PCD_VALUE_PcdImageProtectionPolicy;

// Definition of PCDs used in libraries

#define _PCD_TOKEN_PcdVerifyNodeInList  76U
#define _PCD_SIZE_PcdVerifyNodeInList 1
#define _PCD_GET_MODE_SIZE_PcdVerifyNodeInList  _PCD_SIZE_PcdVerifyNodeInList 
#define _PCD_VALUE_PcdVerifyNodeInList  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifyNodeInList = _PCD_VALUE_PcdVerifyNodeInList;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifyNodeInList;
#define _PCD_GET_MODE_BOOL_PcdVerifyNodeInList  _gPcd_FixedAtBuild_PcdVerifyNodeInList
//#define _PCD_SET_MODE_BOOL_PcdVerifyNodeInList  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumLinkedListLength  71U
#define _PCD_SIZE_PcdMaximumLinkedListLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumLinkedListLength  _PCD_SIZE_PcdMaximumLinkedListLength 
#define _PCD_VALUE_PcdMaximumLinkedListLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumLinkedListLength = _PCD_VALUE_PcdMaximumLinkedListLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength;
#define _PCD_GET_MODE_32_PcdMaximumLinkedListLength  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength
//#define _PCD_SET_MODE_32_PcdMaximumLinkedListLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumAsciiStringLength  69U
#define _PCD_SIZE_PcdMaximumAsciiStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumAsciiStringLength  _PCD_SIZE_PcdMaximumAsciiStringLength 
#define _PCD_VALUE_PcdMaximumAsciiStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength = _PCD_VALUE_PcdMaximumAsciiStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength;
#define _PCD_GET_MODE_32_PcdMaximumAsciiStringLength  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength
//#define _PCD_SET_MODE_32_PcdMaximumAsciiStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumUnicodeStringLength  72U
#define _PCD_SIZE_PcdMaximumUnicodeStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumUnicodeStringLength  _PCD_SIZE_PcdMaximumUnicodeStringLength 
#define _PCD_VALUE_PcdMaximumUnicodeStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength = _PCD_VALUE_PcdMaximumUnicodeStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength;
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength
//#define _PCD_SET_MODE_32_PcdMaximumUnicodeStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  64U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask = _PCD_VALUE_PcdControlFlowEnforcementPropertyMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpeculationBarrierType  74U
#define _PCD_SIZE_PcdSpeculationBarrierType 1
#define _PCD_GET_MODE_SIZE_PcdSpeculationBarrierType  _PCD_SIZE_PcdSpeculationBarrierType 
#define _PCD_VALUE_PcdSpeculationBarrierType  0x01U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpeculationBarrierType = _PCD_VALUE_PcdSpeculationBarrierType;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpeculationBarrierType;
#define _PCD_GET_MODE_8_PcdSpeculationBarrierType  _gPcd_FixedAtBuild_PcdSpeculationBarrierType
//#define _PCD_SET_MODE_8_PcdSpeculationBarrierType  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciExpressBaseAddress  18U
#define _PCD_GET_MODE_64_PcdPciExpressBaseAddress  LibPcdGet64(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseAddress  LibPcdGetSize(_PCD_TOKEN_PcdPciExpressBaseAddress)
#define _PCD_SET_MODE_64_PcdPciExpressBaseAddress(Value)  LibPcdSet64(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))
#define _PCD_SET_MODE_64_S_PcdPciExpressBaseAddress(Value)  LibPcdSet64S(_PCD_TOKEN_PcdPciExpressBaseAddress, (Value))

#define _PCD_TOKEN_PcdDebugPrintErrorLevel  66U
#define _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel  ((UINT32)0x8000004FU)
volatile  UINT32 _gPcd_BinaryPatch_PcdDebugPrintErrorLevel = _PCD_PATCHABLE_VALUE_PcdDebugPrintErrorLevel;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_PcdDebugPrintErrorLevel
#define _PCD_PATCHABLE_PcdDebugPrintErrorLevel_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdDebugPrintErrorLevel  _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel 
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdDebugPrintErrorLevel = 4;
#define _PCD_SET_MODE_32_PcdDebugPrintErrorLevel(Value)  (_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value))
#define _PCD_SET_MODE_32_S_PcdDebugPrintErrorLevel(Value)  ((_gPcd_BinaryPatch_PcdDebugPrintErrorLevel = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialRegisterAccessWidth  56U
#define _PCD_SIZE_PcdSerialRegisterAccessWidth 1
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterAccessWidth  _PCD_SIZE_PcdSerialRegisterAccessWidth 
#define _PCD_VALUE_PcdSerialRegisterAccessWidth  8U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSerialRegisterAccessWidth = _PCD_VALUE_PcdSerialRegisterAccessWidth;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSerialRegisterAccessWidth;
#define _PCD_GET_MODE_8_PcdSerialRegisterAccessWidth  _gPcd_FixedAtBuild_PcdSerialRegisterAccessWidth
//#define _PCD_SET_MODE_8_PcdSerialRegisterAccessWidth  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSerialUseMmio  60U
#define _PCD_PATCHABLE_VALUE_PcdSerialUseMmio  ((BOOLEAN)1U)
volatile  BOOLEAN _gPcd_BinaryPatch_PcdSerialUseMmio = _PCD_PATCHABLE_VALUE_PcdSerialUseMmio;
extern volatile   BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseMmio;
#define _PCD_GET_MODE_BOOL_PcdSerialUseMmio  _gPcd_BinaryPatch_PcdSerialUseMmio
#define _PCD_PATCHABLE_PcdSerialUseMmio_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseMmio  _gPcd_BinaryPatch_Size_PcdSerialUseMmio 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio = 1;
#define _PCD_SET_MODE_BOOL_PcdSerialUseMmio(Value)  (_gPcd_BinaryPatch_PcdSerialUseMmio = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseMmio(Value)  ((_gPcd_BinaryPatch_PcdSerialUseMmio = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialUseHardwareFlowControl  59U
#define _PCD_PATCHABLE_VALUE_PcdSerialUseHardwareFlowControl  ((BOOLEAN)0U)
volatile  BOOLEAN _gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl = _PCD_PATCHABLE_VALUE_PcdSerialUseHardwareFlowControl;
extern volatile   BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl;
#define _PCD_GET_MODE_BOOL_PcdSerialUseHardwareFlowControl  _gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl
#define _PCD_PATCHABLE_PcdSerialUseHardwareFlowControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseHardwareFlowControl  _gPcd_BinaryPatch_Size_PcdSerialUseHardwareFlowControl 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseHardwareFlowControl; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialUseHardwareFlowControl = 1;
#define _PCD_SET_MODE_BOOL_PcdSerialUseHardwareFlowControl(Value)  (_gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseHardwareFlowControl(Value)  ((_gPcd_BinaryPatch_PcdSerialUseHardwareFlowControl = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialDetectCable  51U
#define _PCD_PATCHABLE_VALUE_PcdSerialDetectCable  ((BOOLEAN)0U)
volatile  BOOLEAN _gPcd_BinaryPatch_PcdSerialDetectCable = _PCD_PATCHABLE_VALUE_PcdSerialDetectCable;
extern volatile   BOOLEAN  _gPcd_BinaryPatch_PcdSerialDetectCable;
#define _PCD_GET_MODE_BOOL_PcdSerialDetectCable  _gPcd_BinaryPatch_PcdSerialDetectCable
#define _PCD_PATCHABLE_PcdSerialDetectCable_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialDetectCable  _gPcd_BinaryPatch_Size_PcdSerialDetectCable 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialDetectCable; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialDetectCable = 1;
#define _PCD_SET_MODE_BOOL_PcdSerialDetectCable(Value)  (_gPcd_BinaryPatch_PcdSerialDetectCable = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialDetectCable(Value)  ((_gPcd_BinaryPatch_PcdSerialDetectCable = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialRegisterBase  57U
#define _PCD_PATCHABLE_VALUE_PcdSerialRegisterBase  ((UINT64)0ULL)
volatile  UINT64 _gPcd_BinaryPatch_PcdSerialRegisterBase = _PCD_PATCHABLE_VALUE_PcdSerialRegisterBase;
extern volatile   UINT64  _gPcd_BinaryPatch_PcdSerialRegisterBase;
#define _PCD_GET_MODE_64_PcdSerialRegisterBase  _gPcd_BinaryPatch_PcdSerialRegisterBase
#define _PCD_PATCHABLE_PcdSerialRegisterBase_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterBase  _gPcd_BinaryPatch_Size_PcdSerialRegisterBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterBase = 8;
#define _PCD_SET_MODE_64_PcdSerialRegisterBase(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value))
#define _PCD_SET_MODE_64_S_PcdSerialRegisterBase(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialBaudRate  49U
#define _PCD_PATCHABLE_VALUE_PcdSerialBaudRate  ((UINT32)0U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSerialBaudRate = _PCD_PATCHABLE_VALUE_PcdSerialBaudRate;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSerialBaudRate;
#define _PCD_GET_MODE_32_PcdSerialBaudRate  _gPcd_BinaryPatch_PcdSerialBaudRate
#define _PCD_PATCHABLE_PcdSerialBaudRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialBaudRate  _gPcd_BinaryPatch_Size_PcdSerialBaudRate 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialBaudRate; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialBaudRate = 4;
#define _PCD_SET_MODE_32_PcdSerialBaudRate(Value)  (_gPcd_BinaryPatch_PcdSerialBaudRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialBaudRate(Value)  ((_gPcd_BinaryPatch_PcdSerialBaudRate = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialLineControl  54U
#define _PCD_PATCHABLE_VALUE_PcdSerialLineControl  ((UINT8)3U)
volatile  UINT8 _gPcd_BinaryPatch_PcdSerialLineControl = _PCD_PATCHABLE_VALUE_PcdSerialLineControl;
extern volatile   UINT8  _gPcd_BinaryPatch_PcdSerialLineControl;
#define _PCD_GET_MODE_8_PcdSerialLineControl  _gPcd_BinaryPatch_PcdSerialLineControl
#define _PCD_PATCHABLE_PcdSerialLineControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialLineControl  _gPcd_BinaryPatch_Size_PcdSerialLineControl 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialLineControl; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialLineControl = 1;
#define _PCD_SET_MODE_8_PcdSerialLineControl(Value)  (_gPcd_BinaryPatch_PcdSerialLineControl = (Value))
#define _PCD_SET_MODE_8_S_PcdSerialLineControl(Value)  ((_gPcd_BinaryPatch_PcdSerialLineControl = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialFifoControl  53U
#define _PCD_PATCHABLE_VALUE_PcdSerialFifoControl  ((UINT8)7U)
volatile  UINT8 _gPcd_BinaryPatch_PcdSerialFifoControl = _PCD_PATCHABLE_VALUE_PcdSerialFifoControl;
extern volatile   UINT8  _gPcd_BinaryPatch_PcdSerialFifoControl;
#define _PCD_GET_MODE_8_PcdSerialFifoControl  _gPcd_BinaryPatch_PcdSerialFifoControl
#define _PCD_PATCHABLE_PcdSerialFifoControl_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialFifoControl  _gPcd_BinaryPatch_Size_PcdSerialFifoControl 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialFifoControl; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialFifoControl = 1;
#define _PCD_SET_MODE_8_PcdSerialFifoControl(Value)  (_gPcd_BinaryPatch_PcdSerialFifoControl = (Value))
#define _PCD_SET_MODE_8_S_PcdSerialFifoControl(Value)  ((_gPcd_BinaryPatch_PcdSerialFifoControl = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialClockRate  50U
#define _PCD_PATCHABLE_VALUE_PcdSerialClockRate  ((UINT32)0U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSerialClockRate = _PCD_PATCHABLE_VALUE_PcdSerialClockRate;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSerialClockRate;
#define _PCD_GET_MODE_32_PcdSerialClockRate  _gPcd_BinaryPatch_PcdSerialClockRate
#define _PCD_PATCHABLE_PcdSerialClockRate_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialClockRate  _gPcd_BinaryPatch_Size_PcdSerialClockRate 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialClockRate; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialClockRate = 4;
#define _PCD_SET_MODE_32_PcdSerialClockRate(Value)  (_gPcd_BinaryPatch_PcdSerialClockRate = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialClockRate(Value)  ((_gPcd_BinaryPatch_PcdSerialClockRate = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialPciDeviceInfo  55U
#define _PCD_VALUE_PcdSerialPciDeviceInfo  (VOID *)_gPcd_FixedAtBuild_PcdSerialPciDeviceInfo
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSerialPciDeviceInfo[1] = {0xFF};
extern const UINT8 _gPcd_FixedAtBuild_PcdSerialPciDeviceInfo[1];
#define _PCD_GET_MODE_PTR_PcdSerialPciDeviceInfo  (VOID *)_gPcd_FixedAtBuild_PcdSerialPciDeviceInfo
#define _PCD_SIZE_PcdSerialPciDeviceInfo 1
#define _PCD_GET_MODE_SIZE_PcdSerialPciDeviceInfo  _PCD_SIZE_PcdSerialPciDeviceInfo 
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_FixedAtBuild_Size_PcdSerialPciDeviceInfo = 1;
//#define _PCD_SET_MODE_PTR_PcdSerialPciDeviceInfo  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSerialExtendedTxFifoSize  52U
#define _PCD_PATCHABLE_VALUE_PcdSerialExtendedTxFifoSize  ((UINT32)16U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize = _PCD_PATCHABLE_VALUE_PcdSerialExtendedTxFifoSize;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize;
#define _PCD_GET_MODE_32_PcdSerialExtendedTxFifoSize  _gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize
#define _PCD_PATCHABLE_PcdSerialExtendedTxFifoSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialExtendedTxFifoSize  _gPcd_BinaryPatch_Size_PcdSerialExtendedTxFifoSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialExtendedTxFifoSize; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialExtendedTxFifoSize = 4;
#define _PCD_SET_MODE_32_PcdSerialExtendedTxFifoSize(Value)  (_gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialExtendedTxFifoSize(Value)  ((_gPcd_BinaryPatch_PcdSerialExtendedTxFifoSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialRegisterStride  58U
#define _PCD_PATCHABLE_VALUE_PcdSerialRegisterStride  ((UINT32)0U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSerialRegisterStride = _PCD_PATCHABLE_VALUE_PcdSerialRegisterStride;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSerialRegisterStride;
#define _PCD_GET_MODE_32_PcdSerialRegisterStride  _gPcd_BinaryPatch_PcdSerialRegisterStride
#define _PCD_PATCHABLE_PcdSerialRegisterStride_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSerialRegisterStride  _gPcd_BinaryPatch_Size_PcdSerialRegisterStride 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterStride; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialRegisterStride = 4;
#define _PCD_SET_MODE_32_PcdSerialRegisterStride(Value)  (_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value))
#define _PCD_SET_MODE_32_S_PcdSerialRegisterStride(Value)  ((_gPcd_BinaryPatch_PcdSerialRegisterStride = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdDebugClearMemoryValue  65U
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue  _PCD_SIZE_PcdDebugClearMemoryValue 
#define _PCD_VALUE_PcdDebugClearMemoryValue  0xAFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue = _PCD_VALUE_PcdDebugClearMemoryValue;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPropertyMask  67U
#define _PCD_PATCHABLE_VALUE_PcdDebugPropertyMask  ((UINT8)0x2FU)
volatile  UINT8 _gPcd_BinaryPatch_PcdDebugPropertyMask = _PCD_PATCHABLE_VALUE_PcdDebugPropertyMask;
extern volatile   UINT8  _gPcd_BinaryPatch_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_BinaryPatch_PcdDebugPropertyMask
#define _PCD_PATCHABLE_PcdDebugPropertyMask_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask  _gPcd_BinaryPatch_Size_PcdDebugPropertyMask 
extern UINTN _gPcd_BinaryPatch_Size_PcdDebugPropertyMask; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdDebugPropertyMask = 1;
#define _PCD_SET_MODE_8_PcdDebugPropertyMask(Value)  (_gPcd_BinaryPatch_PcdDebugPropertyMask = (Value))
#define _PCD_SET_MODE_8_S_PcdDebugPropertyMask(Value)  ((_gPcd_BinaryPatch_PcdDebugPropertyMask = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  68U
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel  _PCD_SIZE_PcdFixedDebugPrintErrorLevel 
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel  0xFFFFFFFFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel = _PCD_VALUE_PcdFixedDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiACPIReclaimMemory  78U
#define _PCD_SIZE_PcdMemoryTypeEfiACPIReclaimMemory 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiACPIReclaimMemory  _PCD_SIZE_PcdMemoryTypeEfiACPIReclaimMemory 
#define _PCD_VALUE_PcdMemoryTypeEfiACPIReclaimMemory  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIReclaimMemory = _PCD_VALUE_PcdMemoryTypeEfiACPIReclaimMemory;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIReclaimMemory;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiACPIReclaimMemory  _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIReclaimMemory
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiACPIReclaimMemory  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiACPIMemoryNVS  77U
#define _PCD_SIZE_PcdMemoryTypeEfiACPIMemoryNVS 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiACPIMemoryNVS  _PCD_SIZE_PcdMemoryTypeEfiACPIMemoryNVS 
#define _PCD_VALUE_PcdMemoryTypeEfiACPIMemoryNVS  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIMemoryNVS = _PCD_VALUE_PcdMemoryTypeEfiACPIMemoryNVS;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIMemoryNVS;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiACPIMemoryNVS  _gPcd_FixedAtBuild_PcdMemoryTypeEfiACPIMemoryNVS
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiACPIMemoryNVS  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiReservedMemoryType  83U
#define _PCD_SIZE_PcdMemoryTypeEfiReservedMemoryType 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiReservedMemoryType  _PCD_SIZE_PcdMemoryTypeEfiReservedMemoryType 
#define _PCD_VALUE_PcdMemoryTypeEfiReservedMemoryType  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiReservedMemoryType = _PCD_VALUE_PcdMemoryTypeEfiReservedMemoryType;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiReservedMemoryType;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiReservedMemoryType  _gPcd_FixedAtBuild_PcdMemoryTypeEfiReservedMemoryType
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiReservedMemoryType  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiRuntimeServicesData  85U
#define _PCD_SIZE_PcdMemoryTypeEfiRuntimeServicesData 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiRuntimeServicesData  _PCD_SIZE_PcdMemoryTypeEfiRuntimeServicesData 
#define _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesData  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesData = _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesData;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesData;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiRuntimeServicesData  _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesData
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiRuntimeServicesData  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiRuntimeServicesCode  84U
#define _PCD_SIZE_PcdMemoryTypeEfiRuntimeServicesCode 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiRuntimeServicesCode  _PCD_SIZE_PcdMemoryTypeEfiRuntimeServicesCode 
#define _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesCode  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesCode = _PCD_VALUE_PcdMemoryTypeEfiRuntimeServicesCode;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesCode;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiRuntimeServicesCode  _gPcd_FixedAtBuild_PcdMemoryTypeEfiRuntimeServicesCode
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiRuntimeServicesCode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiBootServicesCode  79U
#define _PCD_SIZE_PcdMemoryTypeEfiBootServicesCode 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiBootServicesCode  _PCD_SIZE_PcdMemoryTypeEfiBootServicesCode 
#define _PCD_VALUE_PcdMemoryTypeEfiBootServicesCode  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesCode = _PCD_VALUE_PcdMemoryTypeEfiBootServicesCode;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesCode;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiBootServicesCode  _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesCode
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiBootServicesCode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiBootServicesData  80U
#define _PCD_SIZE_PcdMemoryTypeEfiBootServicesData 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiBootServicesData  _PCD_SIZE_PcdMemoryTypeEfiBootServicesData 
#define _PCD_VALUE_PcdMemoryTypeEfiBootServicesData  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesData = _PCD_VALUE_PcdMemoryTypeEfiBootServicesData;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesData;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiBootServicesData  _gPcd_FixedAtBuild_PcdMemoryTypeEfiBootServicesData
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiBootServicesData  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiLoaderCode  81U
#define _PCD_SIZE_PcdMemoryTypeEfiLoaderCode 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiLoaderCode  _PCD_SIZE_PcdMemoryTypeEfiLoaderCode 
#define _PCD_VALUE_PcdMemoryTypeEfiLoaderCode  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderCode = _PCD_VALUE_PcdMemoryTypeEfiLoaderCode;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderCode;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiLoaderCode  _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderCode
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiLoaderCode  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMemoryTypeEfiLoaderData  82U
#define _PCD_SIZE_PcdMemoryTypeEfiLoaderData 4
#define _PCD_GET_MODE_SIZE_PcdMemoryTypeEfiLoaderData  _PCD_SIZE_PcdMemoryTypeEfiLoaderData 
#define _PCD_VALUE_PcdMemoryTypeEfiLoaderData  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderData = _PCD_VALUE_PcdMemoryTypeEfiLoaderData;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderData;
#define _PCD_GET_MODE_32_PcdMemoryTypeEfiLoaderData  _gPcd_FixedAtBuild_PcdMemoryTypeEfiLoaderData
//#define _PCD_SET_MODE_32_PcdMemoryTypeEfiLoaderData  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPrePiProduceMemoryTypeInformationHob  87U
#define _PCD_SIZE_PcdPrePiProduceMemoryTypeInformationHob 1
#define _PCD_GET_MODE_SIZE_PcdPrePiProduceMemoryTypeInformationHob  _PCD_SIZE_PcdPrePiProduceMemoryTypeInformationHob 
#define _PCD_VALUE_PcdPrePiProduceMemoryTypeInformationHob  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdPrePiProduceMemoryTypeInformationHob = _PCD_VALUE_PcdPrePiProduceMemoryTypeInformationHob;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdPrePiProduceMemoryTypeInformationHob;
#define _PCD_GET_MODE_BOOL_PcdPrePiProduceMemoryTypeInformationHob  _gPcd_FixedAtBuild_PcdPrePiProduceMemoryTypeInformationHob
//#define _PCD_SET_MODE_BOOL_PcdPrePiProduceMemoryTypeInformationHob  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUartDefaultBaudRate  75U
#define _PCD_PATCHABLE_VALUE_PcdUartDefaultBaudRate  ((UINT64)0ULL)
volatile  UINT64 _gPcd_BinaryPatch_PcdUartDefaultBaudRate = _PCD_PATCHABLE_VALUE_PcdUartDefaultBaudRate;
extern volatile   UINT64  _gPcd_BinaryPatch_PcdUartDefaultBaudRate;
#define _PCD_GET_MODE_64_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_PcdUartDefaultBaudRate
#define _PCD_PATCHABLE_PcdUartDefaultBaudRate_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdUartDefaultBaudRate  _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate 
extern UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdUartDefaultBaudRate = 8;
#define _PCD_SET_MODE_64_PcdUartDefaultBaudRate(Value)  (_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value))
#define _PCD_SET_MODE_64_S_PcdUartDefaultBaudRate(Value)  ((_gPcd_BinaryPatch_PcdUartDefaultBaudRate = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPciSerialParameters  47U
#define _PCD_PATCHABLE_VALUE_PcdPciSerialParameters  (VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters
GLOBAL_REMOVE_IF_UNREFERENCED  UINT8 _gPcd_BinaryPatch_PcdPciSerialParameters[26] = {0xff,0xff, 0x00,0x00, 0x0,0x20,0x1c,0x00, 0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0, 0x00,    0x01, 0x0,0x0, 0x0,0x0, 0x0,0x0, 0xff,0xff};
extern  UINT8 _gPcd_BinaryPatch_PcdPciSerialParameters[26];
#define _PCD_GET_MODE_PTR_PcdPciSerialParameters  (VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters
#define _PCD_PATCHABLE_PcdPciSerialParameters_SIZE 26
#define _PCD_GET_MODE_SIZE_PcdPciSerialParameters  _gPcd_BinaryPatch_Size_PcdPciSerialParameters 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciSerialParameters; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciSerialParameters = 26;
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_BinaryPatch_MaxSize_PcdPciSerialParameters = 26;
#define _PCD_SET_MODE_PTR_PcdPciSerialParameters(SizeOfBuffer, Buffer)  LibPatchPcdSetPtrAndSize((VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters, &_gPcd_BinaryPatch_Size_PcdPciSerialParameters, (UINTN)_PCD_PATCHABLE_PcdPciSerialParameters_SIZE, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdPciSerialParameters(SizeOfBuffer, Buffer)  LibPatchPcdSetPtrAndSizeS((VOID *)_gPcd_BinaryPatch_PcdPciSerialParameters, &_gPcd_BinaryPatch_Size_PcdPciSerialParameters, (UINTN)_PCD_PATCHABLE_PcdPciSerialParameters_SIZE, (SizeOfBuffer), (Buffer))

#define _PCD_TOKEN_PcdPerformanceLibraryPropertyMask  73U
#define _PCD_SIZE_PcdPerformanceLibraryPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdPerformanceLibraryPropertyMask  _PCD_SIZE_PcdPerformanceLibraryPropertyMask 
#define _PCD_VALUE_PcdPerformanceLibraryPropertyMask  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask = _PCD_VALUE_PcdPerformanceLibraryPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask;
#define _PCD_GET_MODE_8_PcdPerformanceLibraryPropertyMask  _gPcd_FixedAtBuild_PcdPerformanceLibraryPropertyMask
//#define _PCD_SET_MODE_8_PcdPerformanceLibraryPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumGuidedExtractHandler  70U
#define _PCD_SIZE_PcdMaximumGuidedExtractHandler 4
#define _PCD_GET_MODE_SIZE_PcdMaximumGuidedExtractHandler  _PCD_SIZE_PcdMaximumGuidedExtractHandler 
#define _PCD_VALUE_PcdMaximumGuidedExtractHandler  0x10U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler = _PCD_VALUE_PcdMaximumGuidedExtractHandler;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler;
#define _PCD_GET_MODE_32_PcdMaximumGuidedExtractHandler  _gPcd_FixedAtBuild_PcdMaximumGuidedExtractHandler
//#define _PCD_SET_MODE_32_PcdMaximumGuidedExtractHandler  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPrePiCpuIoSize  86U
#define _PCD_SIZE_PcdPrePiCpuIoSize 1
#define _PCD_GET_MODE_SIZE_PcdPrePiCpuIoSize  _PCD_SIZE_PcdPrePiCpuIoSize 
#define _PCD_VALUE_PcdPrePiCpuIoSize  16U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPrePiCpuIoSize = _PCD_VALUE_PcdPrePiCpuIoSize;
extern const  UINT8  _gPcd_FixedAtBuild_PcdPrePiCpuIoSize;
#define _PCD_GET_MODE_8_PcdPrePiCpuIoSize  _gPcd_FixedAtBuild_PcdPrePiCpuIoSize
//#define _PCD_SET_MODE_8_PcdPrePiCpuIoSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpmInstanceGuid  25U
#define _PCD_GET_MODE_PTR_PcdTpmInstanceGuid  LibPcdGetPtr(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_GET_MODE_SIZE_PcdTpmInstanceGuid  LibPcdGetSize(_PCD_TOKEN_PcdTpmInstanceGuid)
#define _PCD_SET_MODE_PTR_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtr(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))
#define _PCD_SET_MODE_PTR_S_PcdTpmInstanceGuid(SizeOfBuffer, Buffer)  LibPcdSetPtrS(_PCD_TOKEN_PcdTpmInstanceGuid, (SizeOfBuffer), (Buffer))


RETURN_STATUS
EFIAPI
BaseDebugLibSerialPortConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
PlatformHookSerialPortInitialize (
  VOID
  );

RETURN_STATUS
EFIAPI
AcpiTimerLibConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
ExtractGuidedSectionLibConstructor (
  VOID
  );


VOID
EFIAPI
ProcessLibraryConstructorList (
  VOID
  )
{
  RETURN_STATUS  Status;

  Status = BaseDebugLibSerialPortConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = PlatformHookSerialPortInitialize ();
  ASSERT_RETURN_ERROR (Status);

  Status = AcpiTimerLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = ExtractGuidedSectionLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  VOID
  )
{

}
