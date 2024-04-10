/**
  DO NOT EDIT
  FILE auto-generated
  Module name:
    AutoGen.c
  Abstract:       Auto-generated AutoGen.c for building module or library.
**/
#include <PiPei.h>
#include <Library/DebugLib.h>
#include <Library/PeimEntryPoint.h>

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEfiCallerIdGuid = {0x1BB388F8, 0x77D8, 0x4c00, {0x98, 0xA7, 0x38, 0xF4, 0x59, 0x31, 0xB2, 0xA4}};

GLOBAL_REMOVE_IF_UNREFERENCED GUID gEdkiiDscPlatformGuid = {0x0E8F73FA, 0xCF73, 0x4AA2, {0xA4, 0x06, 0x16, 0x10, 0xCC, 0xF4, 0x9E, 0xF1}};

GLOBAL_REMOVE_IF_UNREFERENCED CHAR8 *gEfiCallerBaseName = "Stage2";

// Guids
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspReservedMemoryResourceHobGuid = { 0x69a79759, 0x1373, 0x4367, { 0xa6, 0xc4, 0xc7, 0xf5, 0x9e, 0xfd, 0x98, 0x6e } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderSerialPortInfoGuid = { 0x6c6872fe, 0x56a9, 0x4403, { 0xbb, 0x98, 0x95, 0x8d, 0x62, 0xde, 0x87, 0xf1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPlatformDeviceInfoGuid = { 0x74f136fd, 0x518f, 0x4884, { 0x83, 0x90, 0x4a, 0xcd, 0x50, 0x28, 0x11, 0xb6 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderSystemTableInfoGuid = { 0x16c8a6d0, 0xfe8a, 0x4082, { 0xa2, 0x08, 0xcf, 0x89, 0xc4, 0x29, 0x04, 0x33 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPerformanceInfoGuid = { 0x868204be, 0x23d0, 0x4ff9, { 0xac, 0x34, 0xb9, 0x95, 0xac, 0x04, 0xb1, 0xb9 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderLibraryDataGuid = { 0xb803281e, 0xe5aa, 0x42a6, { 0xa7, 0x90, 0x8b, 0x23, 0x52, 0x31, 0x6a, 0xe6 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderMemoryMapInfoGuid = { 0xa1ff7424, 0x7a1a, 0x478e, { 0xa9, 0xe4, 0x92, 0xf3, 0x57, 0xd1, 0x28, 0x32 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderFspInfoGuid = { 0xbd42bc23, 0x1efe, 0x4b2b, { 0xa5, 0x8e, 0x08, 0x8b, 0x5b, 0xa2, 0xf5, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsInfoHobGuid = { 0x39f62cce, 0x6825, 0x4669, { 0xbb, 0x56, 0x54, 0x1a, 0xba, 0x75, 0x3a, 0x07 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiGraphicsDeviceInfoHobGuid = { 0xe5cb2ac9, 0xd35d, 0x4430, { 0x93, 0x6e, 0x1d, 0xe3, 0x32, 0x47, 0x8d, 0xe7 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPayloadKeyHashGuid = { 0xbf16846f, 0xfde9, 0x487a, { 0xb6, 0x9d, 0xac, 0xad, 0x39, 0x79, 0x5c, 0x4e } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gOsBootOptionGuid = { 0xa9e97fe1, 0xe2e0, 0x4550, { 0x86, 0xb3, 0x8d, 0x93, 0x66, 0x5e, 0x6f, 0x6d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gBootLoaderServiceGuid = { 0x5ce78dbc, 0xe342, 0x4108, { 0x8f, 0xbf, 0x37, 0xa9, 0x3b, 0x10, 0xf2, 0xf9 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gBootLoaderVersionGuid = { 0x6897f304, 0x45db, 0x4048, { 0xb0, 0xda, 0x04, 0x4d, 0x76, 0x2f, 0x70, 0x1d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFlashMapInfoGuid = { 0xaf7f452c, 0x5b00, 0x4598, { 0xb4, 0x8c, 0xbf, 0x57, 0xa2, 0x08, 0x71, 0xa1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPlatformInfoGuid = { 0x7b6bad42, 0xd3ab, 0x4947, { 0xa2, 0x6e, 0xd6, 0xf9, 0xa9, 0xac, 0x4a, 0x2a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSeedListInfoHobGuid = { 0x5e9f5b2f, 0xfeeb, 0x4344, { 0xb3, 0x0e, 0x4e, 0xf2, 0x17, 0xa3, 0x91, 0xcc } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPlatformDataGuid = { 0x559265da, 0x0982, 0x46ca, { 0x92, 0x48, 0xa4, 0x36, 0x74, 0x34, 0x07, 0x78 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gDeviceTableHobGuid = { 0xd21fc32c, 0x7fd2, 0x435b, { 0xb8, 0xef, 0xc0, 0x42, 0x66, 0xa8, 0xf4, 0xf5 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSmmInformationGuid = { 0x2d939d66, 0xceec, 0x4244, { 0x94, 0x97, 0x6e, 0x1c, 0x6f, 0x92, 0x54, 0x2c } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderMpCpuTaskInfoGuid = { 0xb2d12dd3, 0x1a61, 0x4ef8, { 0xa6, 0xb8, 0xd9, 0x48, 0x92, 0x39, 0x4c, 0xc0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUniversalPayloadPciRootBridgeInfoGuid = { 0xec4ebacb, 0x2638, 0x416e, { 0xbe, 0x80, 0xe5, 0xfa, 0x4b, 0x51, 0x19, 0x01 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUniversalPayloadAcpiTableGuid = { 0x9f9a9506, 0x5597, 0x4515, { 0xba, 0xb6, 0x8b, 0xcd, 0xe7, 0x84, 0xba, 0x87 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUniversalPayloadSmbiosTableGuid = { 0x590a0d26, 0x06e5, 0x4d20, { 0x8a, 0x82, 0x59, 0xea, 0x1b, 0x34, 0x98, 0x2d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUniversalPayloadSerialPortInfoGuid = { 0xaa7e190d, 0xbe21, 0x4409, { 0x8e, 0x67, 0xa2, 0xcd, 0xf, 0x61, 0xe1, 0x70 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gUniversalPayloadExtraDataGuid = {0x15a5baf6, 0x1c91, 0x467d, {0x9d, 0xfb, 0x31, 0x9d, 0x17, 0x8d, 0x4b, 0xb4}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPldSmmRegisterInfoGuid = { 0xaa9bd7a7, 0xcafb, 0x4499, { 0xa4, 0xa9, 0xb, 0x34, 0x6b, 0x40, 0xa6, 0x22 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiSmmSmramMemoryGuid = { 0x6dadf1d1, 0xd4cc, 0x4910, { 0xbb, 0x6e, 0x82, 0xb1, 0xfd, 0x80, 0xff, 0x3d }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSpiFlashInfoGuid = { 0x2d4aac1b, 0x91a5, 0x4cd5, { 0x9b, 0x5c, 0xb4, 0x0f, 0x5d, 0x28, 0x51, 0xa1 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gNvVariableInfoGuid = { 0x7a345dca, 0xc26, 0x4f2a,  { 0xa8, 0x9a, 0x57, 0xc0, 0x8d, 0xdd, 0x22, 0xee } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPldS3CommunicationGuid = { 0x88e31ba1, 0x1856, 0x4b8b, { 0xbb, 0xdf, 0xf8, 0x16, 0xdd, 0x94, 0xa, 0xef } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTpmEventLogInfoGuid = { 0xcdaffea5, 0x5e2,  0x4c2f, { 0x8b, 0xa7, 0xad, 0xbc, 0x8d, 0xfd, 0x5a, 0x9e } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSecureBootInfoGuid = { 0xd970f847, 0x07dd, 0x4b24, { 0x9e, 0x1e, 0xae, 0x6c, 0x80, 0x9b, 0x1d, 0x38 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformCommonLibTokenSpaceGuid = { 0x373657df, 0x5dc0, 0x4cbb, { 0x87, 0xad, 0x50, 0x1e, 0xb8, 0x89, 0xbf, 0x89 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformModuleTokenSpaceGuid = { 0x69d13bf0, 0xaf91, 0x4d96, { 0xaa, 0x9f, 0x21, 0x84, 0xc5, 0xce, 0x3b, 0xc0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEfiMdePkgTokenSpaceGuid = { 0x914AEBE7, 0x4635, 0x459b, { 0xAA, 0x1C, 0x11, 0xE2, 0x19, 0xB0, 0x3A, 0x10 }};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPlatformAlderLakeTokenSpaceGuid = { 0xfec38282, 0xab42, 0x4aba, {0x8c, 0x25, 0xa4, 0x4e, 0x46, 0x23, 0xf7, 0x6e}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gMeBiosPayloadHobGuid = { 0x992c52c8, 0xbc01, 0x4ecd, { 0x20, 0xbf, 0xf9, 0x57, 0x16, 0x0e, 0x9e, 0xf7 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTccRtctHobGuid = { 0x6bddb43d, 0x1782, 0x4d9c, { 0xb6, 0x80, 0xe3, 0xde, 0x45, 0xe0, 0x37, 0x4a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gTcgEvent2EntryHobGuid = { 0xd26c221e, 0x2430, 0x4c8a, { 0x91, 0x70, 0x3f, 0xcb, 0x45, 0x0, 0x41, 0x3f  } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gSchemaListGuid = { 0x3047c2ac, 0x5e8e, 0x4c55, { 0xa1, 0xcb, 0xea, 0xad, 0x0a, 0x88, 0x86, 0x1b } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gOsConfigDataGuid = { 0x84a0b43c, 0xbdb3, 0x43e3, { 0xa6, 0x39, 0xe8, 0x9c, 0x8e, 0x86, 0xd3, 0xef } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gZeroGuid = { 0x0,        0x0,    0x0,    { 0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0,  0x0  } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspNonVolatileStorageHobGuid = { 0x721acf02, 0x4d77, 0x4c2a, { 0xb3, 0xdc, 0x27, 0x0b, 0x7b, 0xa9, 0xe4, 0xb0 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspNonVolatileStorageHob2Guid = { 0x4866788f, 0x6ba8, 0x47d8, { 0x83, 0x06, 0xac, 0xf7, 0x7f, 0x55, 0x10, 0x46 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gFspVariableNvDataHobGuid = { 0xa034147d, 0x690c, 0x4154, {0x8d, 0xe6, 0xc0, 0x44, 0x64, 0x1d, 0xe9, 0x42}};
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gCpuInitDataHobGuid = { 0x266e31cc, 0x13c5, 0x4807, { 0xb9, 0xdc, 0x39, 0xa6, 0xba, 0x88, 0xff, 0x1a } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gCsmePerformanceInfoGuid = { 0x7add2938, 0xf96a, 0x45c2, { 0x8f, 0x99, 0x23, 0xf4, 0xf2, 0xf0, 0x6f, 0xb8 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gLoaderPciRootBridgeInfoGuid = { 0xb7f3d111, 0xb98d, 0x422f, { 0x84, 0x31, 0xa7, 0xd8, 0x29, 0xec, 0x00, 0x87 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEsrtSystemFirmwareGuid = { 0xbfbaf62d, 0x0a27, 0x4390, { 0x99, 0xf6, 0x8a, 0xe1, 0xca, 0x62, 0x62, 0x77 } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gCsmeFWUDriverImageFileGuid = { 0x4A467997, 0xA909, 0x4678, { 0x91, 0x0C, 0xE0, 0xFE, 0x1C, 0x90, 0x56, 0xEA } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gPeiFirmwarePerformanceGuid = { 0x55765e8f, 0x021a, 0x41f9, { 0x93, 0x2d, 0x4c, 0x49, 0xc5, 0xb7, 0xef, 0x5d } };
GLOBAL_REMOVE_IF_UNREFERENCED EFI_GUID gEdkiiFpdtExtendedFirmwarePerformanceGuid = { 0x3b387bfd, 0x7abc, 0x4cf2, { 0xa0, 0xca, 0xb6, 0xa1, 0x6c, 0x1b, 0x1b, 0x25 } };

// Definition of SkuId Array
GLOBAL_REMOVE_IF_UNREFERENCED UINT64 _gPcd_SkuId_Array[] = {0x0};

// Definition of PCDs used in this module
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaxLibraryDataEntry = _PCD_VALUE_PcdMaxLibraryDataEntry;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifiedBootEnabled = _PCD_VALUE_PcdVerifiedBootEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2FdBase = _PCD_VALUE_PcdStage2FdBase;
volatile  UINT32 _gPcd_BinaryPatch_PcdAcpiTablesAddress = _PCD_PATCHABLE_VALUE_PcdAcpiTablesAddress;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesAddress = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdPayloadLoadHigh = _PCD_VALUE_PcdPayloadLoadHigh;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadExeBase = _PCD_VALUE_PcdPayloadExeBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadLoadBase = _PCD_VALUE_PcdPayloadLoadBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadLoadBase = _PCD_VALUE_PcdFwuPayloadLoadBase;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderHobStackSize = _PCD_VALUE_PcdLoaderHobStackSize;
volatile  UINT32 _gPcd_BinaryPatch_PcdPayloadReservedMemSize = _PCD_PATCHABLE_VALUE_PcdPayloadReservedMemSize;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPayloadReservedMemSize = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderAcpiNvsSize = _PCD_VALUE_PcdLoaderAcpiNvsSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLoaderAcpiReclaimSize = _PCD_VALUE_PcdLoaderAcpiReclaimSize;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMemoryMapEntryNumber = _PCD_VALUE_PcdMemoryMapEntryNumber;
volatile  UINT32 _gPcd_BinaryPatch_PcdAcpiGnvsAddress = _PCD_PATCHABLE_VALUE_PcdAcpiGnvsAddress;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiGnvsAddress = 4;
volatile  UINT32 _gPcd_BinaryPatch_PcdGraphicsVbtAddress = _PCD_PATCHABLE_VALUE_PcdGraphicsVbtAddress;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdGraphicsVbtAddress = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdPsdBiosEnabled = _PCD_VALUE_PcdPsdBiosEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAcpiEnabled = _PCD_VALUE_PcdAcpiEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSmpEnabled = _PCD_VALUE_PcdSmpEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdPciEnumEnabled = _PCD_VALUE_PcdPciEnumEnabled;
volatile  UINT32 _gPcd_BinaryPatch_PcdFSPSBase = _PCD_PATCHABLE_VALUE_PcdFSPSBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdFSPSBase = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashBaseAddress = _PCD_VALUE_PcdFlashBaseAddress;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFlashSize = _PCD_VALUE_PcdFlashSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSplashEnabled = _PCD_VALUE_PcdSplashEnabled;
volatile  UINT32 _gPcd_BinaryPatch_PcdSplashLogoAddress = _PCD_PATCHABLE_VALUE_PcdSplashLogoAddress;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSplashLogoAddress = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdOsBootOptionNumber = _PCD_VALUE_PcdOsBootOptionNumber;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdServiceNumber = _PCD_VALUE_PcdServiceNumber;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdMeasuredBootEnabled = _PCD_VALUE_PcdMeasuredBootEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSeedListBufferSize = _PCD_VALUE_PcdSeedListBufferSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSeedListEnabled = _PCD_VALUE_PcdSeedListEnabled;
volatile  UINT64 _gPcd_BinaryPatch_PcdPciExpressBaseAddress = _PCD_PATCHABLE_VALUE_PcdPciExpressBaseAddress;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciExpressBaseAddress = 8;
volatile  UINT32 _gPcd_BinaryPatch_PcdSmbiosTablesBase = _PCD_PATCHABLE_VALUE_PcdSmbiosTablesBase;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmbiosTablesBase = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdSmbiosTablesSize = _PCD_VALUE_PcdSmbiosTablesSize;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSmbiosEnabled = _PCD_VALUE_PcdSmbiosEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdLinuxPayloadEnabled = _PCD_VALUE_PcdLinuxPayloadEnabled;
volatile  UINT8 _gPcd_BinaryPatch_PcdSmmRebaseMode = _PCD_PATCHABLE_VALUE_PcdSmmRebaseMode;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmmRebaseMode = 1;
volatile  UINT32 _gPcd_BinaryPatch_PcdAcpiTablesRsdp = _PCD_PATCHABLE_VALUE_PcdAcpiTablesRsdp;
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiTablesRsdp = 4;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdBuildSmmHobs = _PCD_VALUE_PcdBuildSmmHobs;
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdBootPerformanceMask = _PCD_VALUE_PcdBootPerformanceMask;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSblResiliencyEnabled = _PCD_VALUE_PcdSblResiliencyEnabled;
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdEnableFwuNotify = _PCD_VALUE_PcdEnableFwuNotify;

// Definition of PCDs used in libraries

#define _PCD_TOKEN_PcdPciExpressBaseSize  0U
#define _PCD_SIZE_PcdPciExpressBaseSize 8
#define _PCD_GET_MODE_SIZE_PcdPciExpressBaseSize  _PCD_SIZE_PcdPciExpressBaseSize 
#define _PCD_VALUE_PcdPciExpressBaseSize  0x10000000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdPciExpressBaseSize = _PCD_VALUE_PcdPciExpressBaseSize;
extern const  UINT64  _gPcd_FixedAtBuild_PcdPciExpressBaseSize;
#define _PCD_GET_MODE_64_PcdPciExpressBaseSize  _gPcd_FixedAtBuild_PcdPciExpressBaseSize
//#define _PCD_SET_MODE_64_PcdPciExpressBaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAdlLpSupport  0U
#define _PCD_SIZE_PcdAdlLpSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlLpSupport  _PCD_SIZE_PcdAdlLpSupport 
#define _PCD_VALUE_PcdAdlLpSupport  1U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAdlLpSupport = _PCD_VALUE_PcdAdlLpSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAdlLpSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlLpSupport  _gPcd_FixedAtBuild_PcdAdlLpSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlLpSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugOutputDeviceMask  0U
#define _PCD_SIZE_PcdDebugOutputDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdDebugOutputDeviceMask  _PCD_SIZE_PcdDebugOutputDeviceMask 
#define _PCD_VALUE_PcdDebugOutputDeviceMask  3U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask = _PCD_VALUE_PcdDebugOutputDeviceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask;
#define _PCD_GET_MODE_32_PcdDebugOutputDeviceMask  _gPcd_FixedAtBuild_PcdDebugOutputDeviceMask
//#define _PCD_SET_MODE_32_PcdDebugOutputDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumAsciiStringLength  0U
#define _PCD_SIZE_PcdMaximumAsciiStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumAsciiStringLength  _PCD_SIZE_PcdMaximumAsciiStringLength 
#define _PCD_VALUE_PcdMaximumAsciiStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength = _PCD_VALUE_PcdMaximumAsciiStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength;
#define _PCD_GET_MODE_32_PcdMaximumAsciiStringLength  _gPcd_FixedAtBuild_PcdMaximumAsciiStringLength
//#define _PCD_SET_MODE_32_PcdMaximumAsciiStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumUnicodeStringLength  0U
#define _PCD_SIZE_PcdMaximumUnicodeStringLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumUnicodeStringLength  _PCD_SIZE_PcdMaximumUnicodeStringLength 
#define _PCD_VALUE_PcdMaximumUnicodeStringLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength = _PCD_VALUE_PcdMaximumUnicodeStringLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength;
#define _PCD_GET_MODE_32_PcdMaximumUnicodeStringLength  _gPcd_FixedAtBuild_PcdMaximumUnicodeStringLength
//#define _PCD_SET_MODE_32_PcdMaximumUnicodeStringLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdConsoleOutDeviceMask  0U
#define _PCD_SIZE_PcdConsoleOutDeviceMask 4
#define _PCD_GET_MODE_SIZE_PcdConsoleOutDeviceMask  _PCD_SIZE_PcdConsoleOutDeviceMask 
#define _PCD_VALUE_PcdConsoleOutDeviceMask  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask = _PCD_VALUE_PcdConsoleOutDeviceMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask;
#define _PCD_GET_MODE_32_PcdConsoleOutDeviceMask  _gPcd_FixedAtBuild_PcdConsoleOutDeviceMask
//#define _PCD_SET_MODE_32_PcdConsoleOutDeviceMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdForceToInitSerialPort  0U
#define _PCD_SIZE_PcdForceToInitSerialPort 1
#define _PCD_GET_MODE_SIZE_PcdForceToInitSerialPort  _PCD_SIZE_PcdForceToInitSerialPort 
#define _PCD_VALUE_PcdForceToInitSerialPort  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdForceToInitSerialPort = _PCD_VALUE_PcdForceToInitSerialPort;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdForceToInitSerialPort;
#define _PCD_GET_MODE_BOOL_PcdForceToInitSerialPort  _gPcd_FixedAtBuild_PcdForceToInitSerialPort
//#define _PCD_SET_MODE_BOOL_PcdForceToInitSerialPort  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugClearMemoryValue  0U
#define _PCD_SIZE_PcdDebugClearMemoryValue 1
#define _PCD_GET_MODE_SIZE_PcdDebugClearMemoryValue  _PCD_SIZE_PcdDebugClearMemoryValue 
#define _PCD_VALUE_PcdDebugClearMemoryValue  0xAFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugClearMemoryValue = _PCD_VALUE_PcdDebugClearMemoryValue;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue;
#define _PCD_GET_MODE_8_PcdDebugClearMemoryValue  _gPcd_FixedAtBuild_PcdDebugClearMemoryValue
//#define _PCD_SET_MODE_8_PcdDebugClearMemoryValue  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDebugPropertyMask  0U
#define _PCD_SIZE_PcdDebugPropertyMask 1
#define _PCD_GET_MODE_SIZE_PcdDebugPropertyMask  _PCD_SIZE_PcdDebugPropertyMask 
#define _PCD_VALUE_PcdDebugPropertyMask  0x27U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdDebugPropertyMask = _PCD_VALUE_PcdDebugPropertyMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdDebugPropertyMask;
#define _PCD_GET_MODE_8_PcdDebugPropertyMask  _gPcd_FixedAtBuild_PcdDebugPropertyMask
//#define _PCD_SET_MODE_8_PcdDebugPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFixedDebugPrintErrorLevel  0U
#define _PCD_SIZE_PcdFixedDebugPrintErrorLevel 4
#define _PCD_GET_MODE_SIZE_PcdFixedDebugPrintErrorLevel  _PCD_SIZE_PcdFixedDebugPrintErrorLevel 
#define _PCD_VALUE_PcdFixedDebugPrintErrorLevel  0xFFFFFFFFU
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel = _PCD_VALUE_PcdFixedDebugPrintErrorLevel;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel;
#define _PCD_GET_MODE_32_PcdFixedDebugPrintErrorLevel  _gPcd_FixedAtBuild_PcdFixedDebugPrintErrorLevel
//#define _PCD_SET_MODE_32_PcdFixedDebugPrintErrorLevel  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdRedundantRegionSize  0U
#define _PCD_SIZE_PcdRedundantRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdRedundantRegionSize  _PCD_SIZE_PcdRedundantRegionSize 
#define _PCD_VALUE_PcdRedundantRegionSize  0x003D3000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdRedundantRegionSize = _PCD_VALUE_PcdRedundantRegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdRedundantRegionSize;
#define _PCD_GET_MODE_32_PcdRedundantRegionSize  _gPcd_FixedAtBuild_PcdRedundantRegionSize
//#define _PCD_SET_MODE_32_PcdRedundantRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTopSwapRegionSize  0U
#define _PCD_SIZE_PcdTopSwapRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdTopSwapRegionSize  _PCD_SIZE_PcdTopSwapRegionSize 
#define _PCD_VALUE_PcdTopSwapRegionSize  0x00080000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdTopSwapRegionSize = _PCD_VALUE_PcdTopSwapRegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdTopSwapRegionSize;
#define _PCD_GET_MODE_32_PcdTopSwapRegionSize  _gPcd_FixedAtBuild_PcdTopSwapRegionSize
//#define _PCD_SET_MODE_32_PcdTopSwapRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1ABase  0U
#define _PCD_SIZE_PcdStage1ABase 4
#define _PCD_GET_MODE_SIZE_PcdStage1ABase  _PCD_SIZE_PcdStage1ABase 
#define _PCD_VALUE_PcdStage1ABase  0xFFFE5000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1ABase = _PCD_VALUE_PcdStage1ABase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1ABase;
#define _PCD_GET_MODE_32_PcdStage1ABase  _gPcd_FixedAtBuild_PcdStage1ABase
//#define _PCD_SET_MODE_32_PcdStage1ABase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1ASize  0U
#define _PCD_SIZE_PcdStage1ASize 4
#define _PCD_GET_MODE_SIZE_PcdStage1ASize  _PCD_SIZE_PcdStage1ASize 
#define _PCD_VALUE_PcdStage1ASize  0x0001B000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1ASize = _PCD_VALUE_PcdStage1ASize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1ASize;
#define _PCD_GET_MODE_32_PcdStage1ASize  _gPcd_FixedAtBuild_PcdStage1ASize
//#define _PCD_SET_MODE_32_PcdStage1ASize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BBase  0U
#define _PCD_SIZE_PcdStage1BBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BBase  _PCD_SIZE_PcdStage1BBase 
#define _PCD_VALUE_PcdStage1BBase  0xFFD00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BBase = _PCD_VALUE_PcdStage1BBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BBase;
#define _PCD_GET_MODE_32_PcdStage1BBase  _gPcd_FixedAtBuild_PcdStage1BBase
//#define _PCD_SET_MODE_32_PcdStage1BBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BSize  0U
#define _PCD_SIZE_PcdStage1BSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BSize  _PCD_SIZE_PcdStage1BSize 
#define _PCD_VALUE_PcdStage1BSize  0x00200000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BSize = _PCD_VALUE_PcdStage1BSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BSize;
#define _PCD_GET_MODE_32_PcdStage1BSize  _gPcd_FixedAtBuild_PcdStage1BSize
//#define _PCD_SET_MODE_32_PcdStage1BSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2Base  0U
#define _PCD_SIZE_PcdStage2Base 4
#define _PCD_GET_MODE_SIZE_PcdStage2Base  _PCD_SIZE_PcdStage2Base 
#define _PCD_VALUE_PcdStage2Base  0xFFC19000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2Base = _PCD_VALUE_PcdStage2Base;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2Base;
#define _PCD_GET_MODE_32_PcdStage2Base  _gPcd_FixedAtBuild_PcdStage2Base
//#define _PCD_SET_MODE_32_PcdStage2Base  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage2Size  0U
#define _PCD_SIZE_PcdStage2Size 4
#define _PCD_GET_MODE_SIZE_PcdStage2Size  _PCD_SIZE_PcdStage2Size 
#define _PCD_VALUE_PcdStage2Size  0x000C2000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage2Size = _PCD_VALUE_PcdStage2Size;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage2Size;
#define _PCD_GET_MODE_32_PcdStage2Size  _gPcd_FixedAtBuild_PcdStage2Size
//#define _PCD_SET_MODE_32_PcdStage2Size  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadBase  0U
#define _PCD_SIZE_PcdPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdPayloadBase  _PCD_SIZE_PcdPayloadBase 
#define _PCD_VALUE_PcdPayloadBase  0xFF72A000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadBase = _PCD_VALUE_PcdPayloadBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadBase;
#define _PCD_GET_MODE_32_PcdPayloadBase  _gPcd_FixedAtBuild_PcdPayloadBase
//#define _PCD_SET_MODE_32_PcdPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPayloadSize  0U
#define _PCD_SIZE_PcdPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdPayloadSize  _PCD_SIZE_PcdPayloadSize 
#define _PCD_VALUE_PcdPayloadSize  0x00030000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdPayloadSize = _PCD_VALUE_PcdPayloadSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdPayloadSize;
#define _PCD_GET_MODE_32_PcdPayloadSize  _gPcd_FixedAtBuild_PcdPayloadSize
//#define _PCD_SET_MODE_32_PcdPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMrcDataBase  0U
#define _PCD_SIZE_PcdMrcDataBase 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataBase  _PCD_SIZE_PcdMrcDataBase 
#define _PCD_VALUE_PcdMrcDataBase  0xFF579000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMrcDataBase = _PCD_VALUE_PcdMrcDataBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMrcDataBase;
#define _PCD_GET_MODE_32_PcdMrcDataBase  _gPcd_FixedAtBuild_PcdMrcDataBase
//#define _PCD_SET_MODE_32_PcdMrcDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMrcDataSize  0U
#define _PCD_SIZE_PcdMrcDataSize 4
#define _PCD_GET_MODE_SIZE_PcdMrcDataSize  _PCD_SIZE_PcdMrcDataSize 
#define _PCD_VALUE_PcdMrcDataSize  0x00010000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMrcDataSize = _PCD_VALUE_PcdMrcDataSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMrcDataSize;
#define _PCD_GET_MODE_32_PcdMrcDataSize  _gPcd_FixedAtBuild_PcdMrcDataSize
//#define _PCD_SET_MODE_32_PcdMrcDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUcodeBase  0U
#define _PCD_SIZE_PcdUcodeBase 4
#define _PCD_GET_MODE_SIZE_PcdUcodeBase  _PCD_SIZE_PcdUcodeBase 
#define _PCD_VALUE_PcdUcodeBase  0xFFB2D000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdUcodeBase = _PCD_VALUE_PcdUcodeBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdUcodeBase;
#define _PCD_GET_MODE_32_PcdUcodeBase  _gPcd_FixedAtBuild_PcdUcodeBase
//#define _PCD_SET_MODE_32_PcdUcodeBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdUcodeSize  0U
#define _PCD_SIZE_PcdUcodeSize 4
#define _PCD_GET_MODE_SIZE_PcdUcodeSize  _PCD_SIZE_PcdUcodeSize 
#define _PCD_VALUE_PcdUcodeSize  0x000EC000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdUcodeSize = _PCD_VALUE_PcdUcodeSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdUcodeSize;
#define _PCD_GET_MODE_32_PcdUcodeSize  _gPcd_FixedAtBuild_PcdUcodeSize
//#define _PCD_SET_MODE_32_PcdUcodeSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage1RegionBase  0U
#define _PCD_SIZE_PcdSpiIasImage1RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionBase  _PCD_SIZE_PcdSpiIasImage1RegionBase 
#define _PCD_VALUE_PcdSpiIasImage1RegionBase  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase = _PCD_VALUE_PcdSpiIasImage1RegionBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage1RegionSize  0U
#define _PCD_SIZE_PcdSpiIasImage1RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage1RegionSize  _PCD_SIZE_PcdSpiIasImage1RegionSize 
#define _PCD_VALUE_PcdSpiIasImage1RegionSize  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize = _PCD_VALUE_PcdSpiIasImage1RegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage1RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage1RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage1RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage2RegionBase  0U
#define _PCD_SIZE_PcdSpiIasImage2RegionBase 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionBase  _PCD_SIZE_PcdSpiIasImage2RegionBase 
#define _PCD_VALUE_PcdSpiIasImage2RegionBase  0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase = _PCD_VALUE_PcdSpiIasImage2RegionBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionBase  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionBase
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiIasImage2RegionSize  0U
#define _PCD_SIZE_PcdSpiIasImage2RegionSize 4
#define _PCD_GET_MODE_SIZE_PcdSpiIasImage2RegionSize  _PCD_SIZE_PcdSpiIasImage2RegionSize 
#define _PCD_VALUE_PcdSpiIasImage2RegionSize  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize = _PCD_VALUE_PcdSpiIasImage2RegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize;
#define _PCD_GET_MODE_32_PcdSpiIasImage2RegionSize  _gPcd_FixedAtBuild_PcdSpiIasImage2RegionSize
//#define _PCD_SET_MODE_32_PcdSpiIasImage2RegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFwuPayloadBase  0U
#define _PCD_SIZE_PcdFwuPayloadBase 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadBase  _PCD_SIZE_PcdFwuPayloadBase 
#define _PCD_VALUE_PcdFwuPayloadBase  0xFFCDB000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadBase = _PCD_VALUE_PcdFwuPayloadBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFwuPayloadBase;
#define _PCD_GET_MODE_32_PcdFwuPayloadBase  _gPcd_FixedAtBuild_PcdFwuPayloadBase
//#define _PCD_SET_MODE_32_PcdFwuPayloadBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFwuPayloadSize  0U
#define _PCD_SIZE_PcdFwuPayloadSize 4
#define _PCD_GET_MODE_SIZE_PcdFwuPayloadSize  _PCD_SIZE_PcdFwuPayloadSize 
#define _PCD_VALUE_PcdFwuPayloadSize  0x00020000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFwuPayloadSize = _PCD_VALUE_PcdFwuPayloadSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFwuPayloadSize;
#define _PCD_GET_MODE_32_PcdFwuPayloadSize  _gPcd_FixedAtBuild_PcdFwuPayloadSize
//#define _PCD_SET_MODE_32_PcdFwuPayloadSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataBase  0U
#define _PCD_SIZE_PcdCfgDataBase 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataBase  _PCD_SIZE_PcdCfgDataBase 
#define _PCD_VALUE_PcdCfgDataBase  0xFFCFB000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataBase = _PCD_VALUE_PcdCfgDataBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataBase;
#define _PCD_GET_MODE_32_PcdCfgDataBase  _gPcd_FixedAtBuild_PcdCfgDataBase
//#define _PCD_SET_MODE_32_PcdCfgDataBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDataSize  0U
#define _PCD_SIZE_PcdCfgDataSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataSize  _PCD_SIZE_PcdCfgDataSize 
#define _PCD_VALUE_PcdCfgDataSize  0x00004000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataSize = _PCD_VALUE_PcdCfgDataSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataSize;
#define _PCD_GET_MODE_32_PcdCfgDataSize  _gPcd_FixedAtBuild_PcdCfgDataSize
//#define _PCD_SET_MODE_32_PcdCfgDataSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVerifyNodeInList  0U
#define _PCD_SIZE_PcdVerifyNodeInList 1
#define _PCD_GET_MODE_SIZE_PcdVerifyNodeInList  _PCD_SIZE_PcdVerifyNodeInList 
#define _PCD_VALUE_PcdVerifyNodeInList  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVerifyNodeInList = _PCD_VALUE_PcdVerifyNodeInList;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVerifyNodeInList;
#define _PCD_GET_MODE_BOOL_PcdVerifyNodeInList  _gPcd_FixedAtBuild_PcdVerifyNodeInList
//#define _PCD_SET_MODE_BOOL_PcdVerifyNodeInList  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdMaximumLinkedListLength  0U
#define _PCD_SIZE_PcdMaximumLinkedListLength 4
#define _PCD_GET_MODE_SIZE_PcdMaximumLinkedListLength  _PCD_SIZE_PcdMaximumLinkedListLength 
#define _PCD_VALUE_PcdMaximumLinkedListLength  1000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdMaximumLinkedListLength = _PCD_VALUE_PcdMaximumLinkedListLength;
extern const  UINT32  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength;
#define _PCD_GET_MODE_32_PcdMaximumLinkedListLength  _gPcd_FixedAtBuild_PcdMaximumLinkedListLength
//#define _PCD_SET_MODE_32_PcdMaximumLinkedListLength  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdControlFlowEnforcementPropertyMask  0U
#define _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 4
#define _PCD_GET_MODE_SIZE_PcdControlFlowEnforcementPropertyMask  _PCD_SIZE_PcdControlFlowEnforcementPropertyMask 
#define _PCD_VALUE_PcdControlFlowEnforcementPropertyMask  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask = _PCD_VALUE_PcdControlFlowEnforcementPropertyMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask;
#define _PCD_GET_MODE_32_PcdControlFlowEnforcementPropertyMask  _gPcd_FixedAtBuild_PcdControlFlowEnforcementPropertyMask
//#define _PCD_SET_MODE_32_PcdControlFlowEnforcementPropertyMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpeculationBarrierType  0U
#define _PCD_SIZE_PcdSpeculationBarrierType 1
#define _PCD_GET_MODE_SIZE_PcdSpeculationBarrierType  _PCD_SIZE_PcdSpeculationBarrierType 
#define _PCD_VALUE_PcdSpeculationBarrierType  0x01U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpeculationBarrierType = _PCD_VALUE_PcdSpeculationBarrierType;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpeculationBarrierType;
#define _PCD_GET_MODE_8_PcdSpeculationBarrierType  _gPcd_FixedAtBuild_PcdSpeculationBarrierType
//#define _PCD_SET_MODE_8_PcdSpeculationBarrierType  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCryptoShaOptMask  0U
#define _PCD_SIZE_PcdCryptoShaOptMask 4
#define _PCD_GET_MODE_SIZE_PcdCryptoShaOptMask  _PCD_SIZE_PcdCryptoShaOptMask 
#define _PCD_VALUE_PcdCryptoShaOptMask  0x00000006U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCryptoShaOptMask = _PCD_VALUE_PcdCryptoShaOptMask;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCryptoShaOptMask;
#define _PCD_GET_MODE_32_PcdCryptoShaOptMask  _gPcd_FixedAtBuild_PcdCryptoShaOptMask
//#define _PCD_SET_MODE_32_PcdCryptoShaOptMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIppHashLibSupportedMask  0U
#define _PCD_SIZE_PcdIppHashLibSupportedMask 2
#define _PCD_GET_MODE_SIZE_PcdIppHashLibSupportedMask  _PCD_SIZE_PcdIppHashLibSupportedMask 
#define _PCD_VALUE_PcdIppHashLibSupportedMask  0x00000006U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT16 _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask = _PCD_VALUE_PcdIppHashLibSupportedMask;
extern const  UINT16  _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask;
#define _PCD_GET_MODE_16_PcdIppHashLibSupportedMask  _gPcd_FixedAtBuild_PcdIppHashLibSupportedMask
//#define _PCD_SET_MODE_16_PcdIppHashLibSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCompSignSchemeSupportedMask  0U
#define _PCD_SIZE_PcdCompSignSchemeSupportedMask 1
#define _PCD_GET_MODE_SIZE_PcdCompSignSchemeSupportedMask  _PCD_SIZE_PcdCompSignSchemeSupportedMask 
#define _PCD_VALUE_PcdCompSignSchemeSupportedMask  0x03U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask = _PCD_VALUE_PcdCompSignSchemeSupportedMask;
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask;
#define _PCD_GET_MODE_8_PcdCompSignSchemeSupportedMask  _gPcd_FixedAtBuild_PcdCompSignSchemeSupportedMask
//#define _PCD_SET_MODE_8_PcdCompSignSchemeSupportedMask  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiPmTimerBase  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiPmTimerBase  ((UINT16)0x00001808U)
volatile  UINT16 _gPcd_BinaryPatch_PcdAcpiPmTimerBase = _PCD_PATCHABLE_VALUE_PcdAcpiPmTimerBase;
extern volatile   UINT16  _gPcd_BinaryPatch_PcdAcpiPmTimerBase;
#define _PCD_GET_MODE_16_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_PcdAcpiPmTimerBase
#define _PCD_PATCHABLE_PcdAcpiPmTimerBase_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdAcpiPmTimerBase  _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiPmTimerBase = 2;
#define _PCD_SET_MODE_16_PcdAcpiPmTimerBase(Value)  (_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value))
#define _PCD_SET_MODE_16_S_PcdAcpiPmTimerBase(Value)  ((_gPcd_BinaryPatch_PcdAcpiPmTimerBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdMinDecompression  0U
#define _PCD_SIZE_PcdMinDecompression 1
#define _PCD_GET_MODE_SIZE_PcdMinDecompression  _PCD_SIZE_PcdMinDecompression 
#define _PCD_VALUE_PcdMinDecompression  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdMinDecompression = _PCD_VALUE_PcdMinDecompression;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdMinDecompression;
#define _PCD_GET_MODE_BOOL_PcdMinDecompression  _gPcd_FixedAtBuild_PcdMinDecompression
//#define _PCD_SET_MODE_BOOL_PcdMinDecompression  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpiFlashLibId  0U
#define _PCD_SIZE_PcdSpiFlashLibId 1
#define _PCD_GET_MODE_SIZE_PcdSpiFlashLibId  _PCD_SIZE_PcdSpiFlashLibId 
#define _PCD_VALUE_PcdSpiFlashLibId  2U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdSpiFlashLibId = _PCD_VALUE_PcdSpiFlashLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdSpiFlashLibId;
#define _PCD_GET_MODE_8_PcdSpiFlashLibId  _gPcd_FixedAtBuild_PcdSpiFlashLibId
//#define _PCD_SET_MODE_8_PcdSpiFlashLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdContainerMaxNumber  0U
#define _PCD_SIZE_PcdContainerMaxNumber 4
#define _PCD_GET_MODE_SIZE_PcdContainerMaxNumber  _PCD_SIZE_PcdContainerMaxNumber 
#define _PCD_VALUE_PcdContainerMaxNumber  8U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdContainerMaxNumber = _PCD_VALUE_PcdContainerMaxNumber;
extern const  UINT32  _gPcd_FixedAtBuild_PcdContainerMaxNumber;
#define _PCD_GET_MODE_32_PcdContainerMaxNumber  _gPcd_FixedAtBuild_PcdContainerMaxNumber
//#define _PCD_SET_MODE_32_PcdContainerMaxNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCompSignHashAlg  0U
#define _PCD_SIZE_PcdCompSignHashAlg 1
#define _PCD_GET_MODE_SIZE_PcdCompSignHashAlg  _PCD_SIZE_PcdCompSignHashAlg 
#define _PCD_VALUE_PcdCompSignHashAlg  0x00000002U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdCompSignHashAlg = _PCD_VALUE_PcdCompSignHashAlg;
extern const  UINT8  _gPcd_FixedAtBuild_PcdCompSignHashAlg;
#define _PCD_GET_MODE_8_PcdCompSignHashAlg  _gPcd_FixedAtBuild_PcdCompSignHashAlg
//#define _PCD_SET_MODE_8_PcdCompSignHashAlg  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFspResetStatus  3U
#define _PCD_GET_MODE_32_PcdFspResetStatus  LibPcdGet32(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_GET_MODE_SIZE_PcdFspResetStatus  LibPcdGetSize(_PCD_TOKEN_PcdFspResetStatus)
#define _PCD_SET_MODE_32_PcdFspResetStatus(Value)  LibPcdSet32(_PCD_TOKEN_PcdFspResetStatus, (Value))
#define _PCD_SET_MODE_32_S_PcdFspResetStatus(Value)  LibPcdSet32S(_PCD_TOKEN_PcdFspResetStatus, (Value))

#define _PCD_TOKEN_PcdTpmBaseAddress  0U
#define _PCD_SIZE_PcdTpmBaseAddress 8
#define _PCD_GET_MODE_SIZE_PcdTpmBaseAddress  _PCD_SIZE_PcdTpmBaseAddress 
#define _PCD_VALUE_PcdTpmBaseAddress  0xFED40000ULL
GLOBAL_REMOVE_IF_UNREFERENCED const UINT64 _gPcd_FixedAtBuild_PcdTpmBaseAddress = _PCD_VALUE_PcdTpmBaseAddress;
extern const  UINT64  _gPcd_FixedAtBuild_PcdTpmBaseAddress;
#define _PCD_GET_MODE_64_PcdTpmBaseAddress  _gPcd_FixedAtBuild_PcdTpmBaseAddress
//#define _PCD_SET_MODE_64_PcdTpmBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTcgLogAreaMinLen  0U
#define _PCD_SIZE_PcdTcgLogAreaMinLen 4
#define _PCD_GET_MODE_SIZE_PcdTcgLogAreaMinLen  _PCD_SIZE_PcdTcgLogAreaMinLen 
#define _PCD_VALUE_PcdTcgLogAreaMinLen  0x10000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen = _PCD_VALUE_PcdTcgLogAreaMinLen;
extern const  UINT32  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen;
#define _PCD_GET_MODE_32_PcdTcgLogAreaMinLen  _gPcd_FixedAtBuild_PcdTcgLogAreaMinLen
//#define _PCD_SET_MODE_32_PcdTcgLogAreaMinLen  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTpmLibId  0U
#define _PCD_SIZE_PcdTpmLibId 1
#define _PCD_GET_MODE_SIZE_PcdTpmLibId  _PCD_SIZE_PcdTpmLibId 
#define _PCD_VALUE_PcdTpmLibId  4U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdTpmLibId = _PCD_VALUE_PcdTpmLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdTpmLibId;
#define _PCD_GET_MODE_8_PcdTpmLibId  _gPcd_FixedAtBuild_PcdTpmLibId
//#define _PCD_SET_MODE_8_PcdTpmLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDmaProtectionEnabled  0U
#define _PCD_SIZE_PcdDmaProtectionEnabled 1
#define _PCD_GET_MODE_SIZE_PcdDmaProtectionEnabled  _PCD_SIZE_PcdDmaProtectionEnabled 
#define _PCD_VALUE_PcdDmaProtectionEnabled  ((BOOLEAN)0x0)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdDmaProtectionEnabled = _PCD_VALUE_PcdDmaProtectionEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled;
#define _PCD_GET_MODE_BOOL_PcdDmaProtectionEnabled  _gPcd_FixedAtBuild_PcdDmaProtectionEnabled
//#define _PCD_SET_MODE_BOOL_PcdDmaProtectionEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSpinLockTimeout  0U
#define _PCD_SIZE_PcdSpinLockTimeout 4
#define _PCD_GET_MODE_SIZE_PcdSpinLockTimeout  _PCD_SIZE_PcdSpinLockTimeout 
#define _PCD_VALUE_PcdSpinLockTimeout  10000000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdSpinLockTimeout = _PCD_VALUE_PcdSpinLockTimeout;
extern const  UINT32  _gPcd_FixedAtBuild_PcdSpinLockTimeout;
#define _PCD_GET_MODE_32_PcdSpinLockTimeout  _gPcd_FixedAtBuild_PcdSpinLockTimeout
//#define _PCD_SET_MODE_32_PcdSpinLockTimeout  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuInitIpiDelayInMicroSeconds  0U
#define _PCD_SIZE_PcdCpuInitIpiDelayInMicroSeconds 4
#define _PCD_GET_MODE_SIZE_PcdCpuInitIpiDelayInMicroSeconds  _PCD_SIZE_PcdCpuInitIpiDelayInMicroSeconds 
#define _PCD_VALUE_PcdCpuInitIpiDelayInMicroSeconds  100U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds = _PCD_VALUE_PcdCpuInitIpiDelayInMicroSeconds;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds;
#define _PCD_GET_MODE_32_PcdCpuInitIpiDelayInMicroSeconds  _gPcd_FixedAtBuild_PcdCpuInitIpiDelayInMicroSeconds
//#define _PCD_SET_MODE_32_PcdCpuInitIpiDelayInMicroSeconds  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuLocalApicBaseAddress  0U
#define _PCD_SIZE_PcdCpuLocalApicBaseAddress 4
#define _PCD_GET_MODE_SIZE_PcdCpuLocalApicBaseAddress  _PCD_SIZE_PcdCpuLocalApicBaseAddress 
#define _PCD_VALUE_PcdCpuLocalApicBaseAddress  0xFEE00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress = _PCD_VALUE_PcdCpuLocalApicBaseAddress;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress;
#define _PCD_GET_MODE_32_PcdCpuLocalApicBaseAddress  _gPcd_FixedAtBuild_PcdCpuLocalApicBaseAddress
//#define _PCD_SET_MODE_32_PcdCpuLocalApicBaseAddress  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdTccEnabled  0U
#define _PCD_SIZE_PcdTccEnabled 1
#define _PCD_GET_MODE_SIZE_PcdTccEnabled  _PCD_SIZE_PcdTccEnabled 
#define _PCD_VALUE_PcdTccEnabled  0x0
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdTccEnabled = _PCD_VALUE_PcdTccEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdTccEnabled;
#define _PCD_GET_MODE_BOOL_PcdTccEnabled  _gPcd_FixedAtBuild_PcdTccEnabled
//#define _PCD_SET_MODE_BOOL_PcdTccEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAdlNSupport  0U
#define _PCD_SIZE_PcdAdlNSupport 1
#define _PCD_GET_MODE_SIZE_PcdAdlNSupport  _PCD_SIZE_PcdAdlNSupport 
#define _PCD_VALUE_PcdAdlNSupport  1U
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAdlNSupport = _PCD_VALUE_PcdAdlNSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAdlNSupport;
#define _PCD_GET_MODE_BOOL_PcdAdlNSupport  _gPcd_FixedAtBuild_PcdAdlNSupport
//#define _PCD_SET_MODE_BOOL_PcdAdlNSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFramebufferInitEnabled  0U
#define _PCD_SIZE_PcdFramebufferInitEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFramebufferInitEnabled  _PCD_SIZE_PcdFramebufferInitEnabled 
#define _PCD_VALUE_PcdFramebufferInitEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdFramebufferInitEnabled = _PCD_VALUE_PcdFramebufferInitEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFramebufferInitEnabled;
#define _PCD_GET_MODE_BOOL_PcdFramebufferInitEnabled  _gPcd_FixedAtBuild_PcdFramebufferInitEnabled
//#define _PCD_SET_MODE_BOOL_PcdFramebufferInitEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEnablePciePm  0U
#define _PCD_SIZE_PcdEnablePciePm 1
#define _PCD_GET_MODE_SIZE_PcdEnablePciePm  _PCD_SIZE_PcdEnablePciePm 
#define _PCD_VALUE_PcdEnablePciePm  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdEnablePciePm = _PCD_VALUE_PcdEnablePciePm;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEnablePciePm;
#define _PCD_GET_MODE_BOOL_PcdEnablePciePm  _gPcd_FixedAtBuild_PcdEnablePciePm
//#define _PCD_SET_MODE_BOOL_PcdEnablePciePm  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFastBootEnabled  0U
#define _PCD_SIZE_PcdFastBootEnabled 1
#define _PCD_GET_MODE_SIZE_PcdFastBootEnabled  _PCD_SIZE_PcdFastBootEnabled 
#define _PCD_VALUE_PcdFastBootEnabled  0x0
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdFastBootEnabled = _PCD_VALUE_PcdFastBootEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdFastBootEnabled;
#define _PCD_GET_MODE_BOOL_PcdFastBootEnabled  _gPcd_FixedAtBuild_PcdFastBootEnabled
//#define _PCD_SET_MODE_BOOL_PcdFastBootEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVtdEnabled  0U
#define _PCD_SIZE_PcdVtdEnabled 1
#define _PCD_GET_MODE_SIZE_PcdVtdEnabled  _PCD_SIZE_PcdVtdEnabled 
#define _PCD_VALUE_PcdVtdEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdVtdEnabled = _PCD_VALUE_PcdVtdEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdVtdEnabled;
#define _PCD_GET_MODE_BOOL_PcdVtdEnabled  _gPcd_FixedAtBuild_PcdVtdEnabled
//#define _PCD_SET_MODE_BOOL_PcdVtdEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIgdOpRegionAddress  0U
#define _PCD_PATCHABLE_VALUE_PcdIgdOpRegionAddress  ((UINT32)0xFF000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdIgdOpRegionAddress = _PCD_PATCHABLE_VALUE_PcdIgdOpRegionAddress;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdIgdOpRegionAddress;
#define _PCD_GET_MODE_32_PcdIgdOpRegionAddress  _gPcd_BinaryPatch_PcdIgdOpRegionAddress
#define _PCD_PATCHABLE_PcdIgdOpRegionAddress_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdIgdOpRegionAddress  _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress 
extern UINTN _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdIgdOpRegionAddress = 4;
#define _PCD_SET_MODE_32_PcdIgdOpRegionAddress(Value)  (_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value))
#define _PCD_SET_MODE_32_S_PcdIgdOpRegionAddress(Value)  ((_gPcd_BinaryPatch_PcdIgdOpRegionAddress = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdCfgDataLoadSource  0U
#define _PCD_SIZE_PcdCfgDataLoadSource 4
#define _PCD_GET_MODE_SIZE_PcdCfgDataLoadSource  _PCD_SIZE_PcdCfgDataLoadSource 
#define _PCD_VALUE_PcdCfgDataLoadSource  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDataLoadSource = _PCD_VALUE_PcdCfgDataLoadSource;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDataLoadSource;
#define _PCD_GET_MODE_32_PcdCfgDataLoadSource  _gPcd_FixedAtBuild_PcdCfgDataLoadSource
//#define _PCD_SET_MODE_32_PcdCfgDataLoadSource  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCfgDatabaseSize  0U
#define _PCD_SIZE_PcdCfgDatabaseSize 4
#define _PCD_GET_MODE_SIZE_PcdCfgDatabaseSize  _PCD_SIZE_PcdCfgDatabaseSize 
#define _PCD_VALUE_PcdCfgDatabaseSize  0x00004000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCfgDatabaseSize = _PCD_VALUE_PcdCfgDatabaseSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCfgDatabaseSize;
#define _PCD_GET_MODE_32_PcdCfgDatabaseSize  _gPcd_FixedAtBuild_PcdCfgDatabaseSize
//#define _PCD_SET_MODE_32_PcdCfgDatabaseSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEmmcBlockDeviceLibId  0U
#define _PCD_SIZE_PcdEmmcBlockDeviceLibId 1
#define _PCD_GET_MODE_SIZE_PcdEmmcBlockDeviceLibId  _PCD_SIZE_PcdEmmcBlockDeviceLibId 
#define _PCD_VALUE_PcdEmmcBlockDeviceLibId  3U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdEmmcBlockDeviceLibId = _PCD_VALUE_PcdEmmcBlockDeviceLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdEmmcBlockDeviceLibId;
#define _PCD_GET_MODE_8_PcdEmmcBlockDeviceLibId  _gPcd_FixedAtBuild_PcdEmmcBlockDeviceLibId
//#define _PCD_SET_MODE_8_PcdEmmcBlockDeviceLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdEmmcMaxRwBlockNumber  0U
#define _PCD_PATCHABLE_VALUE_PcdEmmcMaxRwBlockNumber  ((UINT16)0xFFFFU)
volatile  UINT16 _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = _PCD_PATCHABLE_VALUE_PcdEmmcMaxRwBlockNumber;
extern volatile   UINT16  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber;
#define _PCD_GET_MODE_16_PcdEmmcMaxRwBlockNumber  _gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber
#define _PCD_PATCHABLE_PcdEmmcMaxRwBlockNumber_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdEmmcMaxRwBlockNumber  _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber 
extern UINTN _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdEmmcMaxRwBlockNumber = 2;
#define _PCD_SET_MODE_16_PcdEmmcMaxRwBlockNumber(Value)  (_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value))
#define _PCD_SET_MODE_16_S_PcdEmmcMaxRwBlockNumber(Value)  ((_gPcd_BinaryPatch_PcdEmmcMaxRwBlockNumber = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdEmmcHs400SupportEnabled  0U
#define _PCD_SIZE_PcdEmmcHs400SupportEnabled 1
#define _PCD_GET_MODE_SIZE_PcdEmmcHs400SupportEnabled  _PCD_SIZE_PcdEmmcHs400SupportEnabled 
#define _PCD_VALUE_PcdEmmcHs400SupportEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled = _PCD_VALUE_PcdEmmcHs400SupportEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled;
#define _PCD_GET_MODE_BOOL_PcdEmmcHs400SupportEnabled  _gPcd_FixedAtBuild_PcdEmmcHs400SupportEnabled
//#define _PCD_SET_MODE_BOOL_PcdEmmcHs400SupportEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdDmaBufferSize  0U
#define _PCD_SIZE_PcdDmaBufferSize 4
#define _PCD_GET_MODE_SIZE_PcdDmaBufferSize  _PCD_SIZE_PcdDmaBufferSize 
#define _PCD_VALUE_PcdDmaBufferSize  0x00400000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdDmaBufferSize = _PCD_VALUE_PcdDmaBufferSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdDmaBufferSize;
#define _PCD_GET_MODE_32_PcdDmaBufferSize  _gPcd_FixedAtBuild_PcdDmaBufferSize
//#define _PCD_SET_MODE_32_PcdDmaBufferSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdVariableLibId  0U
#define _PCD_SIZE_PcdVariableLibId 1
#define _PCD_GET_MODE_SIZE_PcdVariableLibId  _PCD_SIZE_PcdVariableLibId 
#define _PCD_VALUE_PcdVariableLibId  1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdVariableLibId = _PCD_VALUE_PcdVariableLibId;
extern const  UINT8  _gPcd_FixedAtBuild_PcdVariableLibId;
#define _PCD_GET_MODE_8_PcdVariableLibId  _gPcd_FixedAtBuild_PcdVariableLibId
//#define _PCD_SET_MODE_8_PcdVariableLibId  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuMaxLogicalProcessorNumber  0U
#define _PCD_SIZE_PcdCpuMaxLogicalProcessorNumber 4
#define _PCD_GET_MODE_SIZE_PcdCpuMaxLogicalProcessorNumber  _PCD_SIZE_PcdCpuMaxLogicalProcessorNumber 
#define _PCD_VALUE_PcdCpuMaxLogicalProcessorNumber  0x00000018U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuMaxLogicalProcessorNumber = _PCD_VALUE_PcdCpuMaxLogicalProcessorNumber;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuMaxLogicalProcessorNumber;
#define _PCD_GET_MODE_32_PcdCpuMaxLogicalProcessorNumber  _gPcd_FixedAtBuild_PcdCpuMaxLogicalProcessorNumber
//#define _PCD_SET_MODE_32_PcdCpuMaxLogicalProcessorNumber  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdCpuSortMethod  0U
#define _PCD_SIZE_PcdCpuSortMethod 4
#define _PCD_GET_MODE_SIZE_PcdCpuSortMethod  _PCD_SIZE_PcdCpuSortMethod 
#define _PCD_VALUE_PcdCpuSortMethod  0x0U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdCpuSortMethod = _PCD_VALUE_PcdCpuSortMethod;
extern const  UINT32  _gPcd_FixedAtBuild_PcdCpuSortMethod;
#define _PCD_GET_MODE_32_PcdCpuSortMethod  _gPcd_FixedAtBuild_PcdCpuSortMethod
//#define _PCD_SET_MODE_32_PcdCpuSortMethod  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSmramTsegBase  0U
#define _PCD_PATCHABLE_VALUE_PcdSmramTsegBase  ((UINT32)0xFF000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSmramTsegBase = _PCD_PATCHABLE_VALUE_PcdSmramTsegBase;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSmramTsegBase;
#define _PCD_GET_MODE_32_PcdSmramTsegBase  _gPcd_BinaryPatch_PcdSmramTsegBase
#define _PCD_PATCHABLE_PcdSmramTsegBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegBase  _gPcd_BinaryPatch_Size_PcdSmramTsegBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegBase = 4;
#define _PCD_SET_MODE_32_PcdSmramTsegBase(Value)  (_gPcd_BinaryPatch_PcdSmramTsegBase = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegBase(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSmramTsegSize  0U
#define _PCD_PATCHABLE_VALUE_PcdSmramTsegSize  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSmramTsegSize = _PCD_PATCHABLE_VALUE_PcdSmramTsegSize;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSmramTsegSize;
#define _PCD_GET_MODE_32_PcdSmramTsegSize  _gPcd_BinaryPatch_PcdSmramTsegSize
#define _PCD_PATCHABLE_PcdSmramTsegSize_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmramTsegSize  _gPcd_BinaryPatch_Size_PcdSmramTsegSize 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegSize; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmramTsegSize = 4;
#define _PCD_SET_MODE_32_PcdSmramTsegSize(Value)  (_gPcd_BinaryPatch_PcdSmramTsegSize = (Value))
#define _PCD_SET_MODE_32_S_PcdSmramTsegSize(Value)  ((_gPcd_BinaryPatch_PcdSmramTsegSize = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdFuncCpuInitHook  0U
#define _PCD_PATCHABLE_VALUE_PcdFuncCpuInitHook  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdFuncCpuInitHook = _PCD_PATCHABLE_VALUE_PcdFuncCpuInitHook;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFuncCpuInitHook;
#define _PCD_GET_MODE_32_PcdFuncCpuInitHook  _gPcd_BinaryPatch_PcdFuncCpuInitHook
#define _PCD_PATCHABLE_PcdFuncCpuInitHook_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFuncCpuInitHook  _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook 
extern UINTN _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdFuncCpuInitHook = 4;
#define _PCD_SET_MODE_32_PcdFuncCpuInitHook(Value)  (_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value))
#define _PCD_SET_MODE_32_S_PcdFuncCpuInitHook(Value)  ((_gPcd_BinaryPatch_PcdFuncCpuInitHook = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdCpuX2ApicEnabled  0U
#define _PCD_SIZE_PcdCpuX2ApicEnabled 1
#define _PCD_GET_MODE_SIZE_PcdCpuX2ApicEnabled  _PCD_SIZE_PcdCpuX2ApicEnabled 
#define _PCD_VALUE_PcdCpuX2ApicEnabled  ((BOOLEAN)0x0)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled = _PCD_VALUE_PcdCpuX2ApicEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled;
#define _PCD_GET_MODE_BOOL_PcdCpuX2ApicEnabled  _gPcd_FixedAtBuild_PcdCpuX2ApicEnabled
//#define _PCD_SET_MODE_BOOL_PcdCpuX2ApicEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciResourceIoBase  0U
#define _PCD_PATCHABLE_VALUE_PcdPciResourceIoBase  ((UINT32)0x00002000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdPciResourceIoBase = _PCD_PATCHABLE_VALUE_PcdPciResourceIoBase;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPciResourceIoBase;
#define _PCD_GET_MODE_32_PcdPciResourceIoBase  _gPcd_BinaryPatch_PcdPciResourceIoBase
#define _PCD_PATCHABLE_PcdPciResourceIoBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceIoBase  _gPcd_BinaryPatch_Size_PcdPciResourceIoBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceIoBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciResourceIoBase = 4;
#define _PCD_SET_MODE_32_PcdPciResourceIoBase(Value)  (_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceIoBase(Value)  ((_gPcd_BinaryPatch_PcdPciResourceIoBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPciResourceMem32Base  0U
#define _PCD_PATCHABLE_VALUE_PcdPciResourceMem32Base  ((UINT32)0x80000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdPciResourceMem32Base = _PCD_PATCHABLE_VALUE_PcdPciResourceMem32Base;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPciResourceMem32Base;
#define _PCD_GET_MODE_32_PcdPciResourceMem32Base  _gPcd_BinaryPatch_PcdPciResourceMem32Base
#define _PCD_PATCHABLE_PcdPciResourceMem32Base_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResourceMem32Base  _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem32Base = 4;
#define _PCD_SET_MODE_32_PcdPciResourceMem32Base(Value)  (_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResourceMem32Base(Value)  ((_gPcd_BinaryPatch_PcdPciResourceMem32Base = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdVariableRegionSize  0U
#define _PCD_SIZE_PcdVariableRegionSize 4
#define _PCD_GET_MODE_SIZE_PcdVariableRegionSize  _PCD_SIZE_PcdVariableRegionSize 
#define _PCD_VALUE_PcdVariableRegionSize  0x00002000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdVariableRegionSize = _PCD_VALUE_PcdVariableRegionSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdVariableRegionSize;
#define _PCD_GET_MODE_32_PcdVariableRegionSize  _gPcd_FixedAtBuild_PcdVariableRegionSize
//#define _PCD_SET_MODE_32_PcdVariableRegionSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdIntelGfxEnabled  0U
#define _PCD_SIZE_PcdIntelGfxEnabled 1
#define _PCD_GET_MODE_SIZE_PcdIntelGfxEnabled  _PCD_SIZE_PcdIntelGfxEnabled 
#define _PCD_VALUE_PcdIntelGfxEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdIntelGfxEnabled = _PCD_VALUE_PcdIntelGfxEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdIntelGfxEnabled;
#define _PCD_GET_MODE_BOOL_PcdIntelGfxEnabled  _gPcd_FixedAtBuild_PcdIntelGfxEnabled
//#define _PCD_SET_MODE_BOOL_PcdIntelGfxEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSmbiosStringsPtr  0U
#define _PCD_PATCHABLE_VALUE_PcdSmbiosStringsPtr  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdSmbiosStringsPtr = _PCD_PATCHABLE_VALUE_PcdSmbiosStringsPtr;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdSmbiosStringsPtr;
#define _PCD_GET_MODE_32_PcdSmbiosStringsPtr  _gPcd_BinaryPatch_PcdSmbiosStringsPtr
#define _PCD_PATCHABLE_PcdSmbiosStringsPtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsPtr  _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsPtr = 4;
#define _PCD_SET_MODE_32_PcdSmbiosStringsPtr(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value))
#define _PCD_SET_MODE_32_S_PcdSmbiosStringsPtr(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsPtr = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSmbiosStringsCnt  0U
#define _PCD_PATCHABLE_VALUE_PcdSmbiosStringsCnt  ((UINT16)0x40U)
volatile  UINT16 _gPcd_BinaryPatch_PcdSmbiosStringsCnt = _PCD_PATCHABLE_VALUE_PcdSmbiosStringsCnt;
extern volatile   UINT16  _gPcd_BinaryPatch_PcdSmbiosStringsCnt;
#define _PCD_GET_MODE_16_PcdSmbiosStringsCnt  _gPcd_BinaryPatch_PcdSmbiosStringsCnt
#define _PCD_PATCHABLE_PcdSmbiosStringsCnt_SIZE 2
#define _PCD_GET_MODE_SIZE_PcdSmbiosStringsCnt  _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt 
extern UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSmbiosStringsCnt = 2;
#define _PCD_SET_MODE_16_PcdSmbiosStringsCnt(Value)  (_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value))
#define _PCD_SET_MODE_16_S_PcdSmbiosStringsCnt(Value)  ((_gPcd_BinaryPatch_PcdSmbiosStringsCnt = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialUseMmio  0U
#define _PCD_PATCHABLE_VALUE_PcdSerialUseMmio  ((BOOLEAN)0U)
volatile  BOOLEAN _gPcd_BinaryPatch_PcdSerialUseMmio = _PCD_PATCHABLE_VALUE_PcdSerialUseMmio;
extern volatile   BOOLEAN  _gPcd_BinaryPatch_PcdSerialUseMmio;
#define _PCD_GET_MODE_BOOL_PcdSerialUseMmio  _gPcd_BinaryPatch_PcdSerialUseMmio
#define _PCD_PATCHABLE_PcdSerialUseMmio_SIZE 1
#define _PCD_GET_MODE_SIZE_PcdSerialUseMmio  _gPcd_BinaryPatch_Size_PcdSerialUseMmio 
extern UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdSerialUseMmio = 1;
#define _PCD_SET_MODE_BOOL_PcdSerialUseMmio(Value)  (_gPcd_BinaryPatch_PcdSerialUseMmio = (Value))
#define _PCD_SET_MODE_BOOL_S_PcdSerialUseMmio(Value)  ((_gPcd_BinaryPatch_PcdSerialUseMmio = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdSerialRegisterBase  0U
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

#define _PCD_TOKEN_PcdSerialBaudRate  0U
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

#define _PCD_TOKEN_PcdSerialRegisterStride  0U
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

#define _PCD_TOKEN_PcdSerialClockRate  0U
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

#define _PCD_TOKEN_PcdFspsUpdPtr  0U
#define _PCD_PATCHABLE_VALUE_PcdFspsUpdPtr  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdFspsUpdPtr = _PCD_PATCHABLE_VALUE_PcdFspsUpdPtr;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdFspsUpdPtr;
#define _PCD_GET_MODE_32_PcdFspsUpdPtr  _gPcd_BinaryPatch_PcdFspsUpdPtr
#define _PCD_PATCHABLE_PcdFspsUpdPtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdFspsUpdPtr  _gPcd_BinaryPatch_Size_PcdFspsUpdPtr 
extern UINTN _gPcd_BinaryPatch_Size_PcdFspsUpdPtr; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdFspsUpdPtr = 4;
#define _PCD_SET_MODE_32_PcdFspsUpdPtr(Value)  (_gPcd_BinaryPatch_PcdFspsUpdPtr = (Value))
#define _PCD_SET_MODE_32_S_PcdFspsUpdPtr(Value)  ((_gPcd_BinaryPatch_PcdFspsUpdPtr = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPciEnumHookProc  0U
#define _PCD_PATCHABLE_VALUE_PcdPciEnumHookProc  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdPciEnumHookProc = _PCD_PATCHABLE_VALUE_PcdPciEnumHookProc;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPciEnumHookProc;
#define _PCD_GET_MODE_32_PcdPciEnumHookProc  _gPcd_BinaryPatch_PcdPciEnumHookProc
#define _PCD_PATCHABLE_PcdPciEnumHookProc_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciEnumHookProc  _gPcd_BinaryPatch_Size_PcdPciEnumHookProc 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciEnumHookProc; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciEnumHookProc = 4;
#define _PCD_SET_MODE_32_PcdPciEnumHookProc(Value)  (_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value))
#define _PCD_SET_MODE_32_S_PcdPciEnumHookProc(Value)  ((_gPcd_BinaryPatch_PcdPciEnumHookProc = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdPciEnumPolicyInfo  0U
#define _PCD_VALUE_PcdPciEnumPolicyInfo  (VOID *)_gPcd_FixedAtBuild_PcdPciEnumPolicyInfo
GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gPcd_FixedAtBuild_PcdPciEnumPolicyInfo[7] = {0x0f,0x00,0x00,0x00,0x00,0x01,0x00};
extern const UINT8 _gPcd_FixedAtBuild_PcdPciEnumPolicyInfo[7];
#define _PCD_GET_MODE_PTR_PcdPciEnumPolicyInfo  (VOID *)_gPcd_FixedAtBuild_PcdPciEnumPolicyInfo
#define _PCD_SIZE_PcdPciEnumPolicyInfo 7
#define _PCD_GET_MODE_SIZE_PcdPciEnumPolicyInfo  _PCD_SIZE_PcdPciEnumPolicyInfo 
GLOBAL_REMOVE_IF_UNREFERENCED const UINTN _gPcd_FixedAtBuild_Size_PcdPciEnumPolicyInfo = 7;
//#define _PCD_SET_MODE_PTR_PcdPciEnumPolicyInfo  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciResourceMem64Base  0U
#define _PCD_PATCHABLE_VALUE_PcdPciResourceMem64Base  ((UINT64)0x0ULL)
volatile  UINT64 _gPcd_BinaryPatch_PcdPciResourceMem64Base = _PCD_PATCHABLE_VALUE_PcdPciResourceMem64Base;
extern volatile   UINT64  _gPcd_BinaryPatch_PcdPciResourceMem64Base;
#define _PCD_GET_MODE_64_PcdPciResourceMem64Base  _gPcd_BinaryPatch_PcdPciResourceMem64Base
#define _PCD_PATCHABLE_PcdPciResourceMem64Base_SIZE 8
#define _PCD_GET_MODE_SIZE_PcdPciResourceMem64Base  _gPcd_BinaryPatch_Size_PcdPciResourceMem64Base 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem64Base; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciResourceMem64Base = 8;
#define _PCD_SET_MODE_64_PcdPciResourceMem64Base(Value)  (_gPcd_BinaryPatch_PcdPciResourceMem64Base = (Value))
#define _PCD_SET_MODE_64_S_PcdPciResourceMem64Base(Value)  ((_gPcd_BinaryPatch_PcdPciResourceMem64Base = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdAriSupport  0U
#define _PCD_SIZE_PcdAriSupport 1
#define _PCD_GET_MODE_SIZE_PcdAriSupport  _PCD_SIZE_PcdAriSupport 
#define _PCD_VALUE_PcdAriSupport  ((BOOLEAN)0x0)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdAriSupport = _PCD_VALUE_PcdAriSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdAriSupport;
#define _PCD_GET_MODE_BOOL_PcdAriSupport  _gPcd_FixedAtBuild_PcdAriSupport
//#define _PCD_SET_MODE_BOOL_PcdAriSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdSrIovSupport  0U
#define _PCD_SIZE_PcdSrIovSupport 1
#define _PCD_GET_MODE_SIZE_PcdSrIovSupport  _PCD_SIZE_PcdSrIovSupport 
#define _PCD_VALUE_PcdSrIovSupport  ((BOOLEAN)0x0)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdSrIovSupport = _PCD_VALUE_PcdSrIovSupport;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdSrIovSupport;
#define _PCD_GET_MODE_BOOL_PcdSrIovSupport  _gPcd_FixedAtBuild_PcdSrIovSupport
//#define _PCD_SET_MODE_BOOL_PcdSrIovSupport  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdPciResAllocTableBase  0U
#define _PCD_PATCHABLE_VALUE_PcdPciResAllocTableBase  ((UINT32)0x00000000U)
volatile  UINT32 _gPcd_BinaryPatch_PcdPciResAllocTableBase = _PCD_PATCHABLE_VALUE_PcdPciResAllocTableBase;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdPciResAllocTableBase;
#define _PCD_GET_MODE_32_PcdPciResAllocTableBase  _gPcd_BinaryPatch_PcdPciResAllocTableBase
#define _PCD_PATCHABLE_PcdPciResAllocTableBase_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdPciResAllocTableBase  _gPcd_BinaryPatch_Size_PcdPciResAllocTableBase 
extern UINTN _gPcd_BinaryPatch_Size_PcdPciResAllocTableBase; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdPciResAllocTableBase = 4;
#define _PCD_SET_MODE_32_PcdPciResAllocTableBase(Value)  (_gPcd_BinaryPatch_PcdPciResAllocTableBase = (Value))
#define _PCD_SET_MODE_32_S_PcdPciResAllocTableBase(Value)  ((_gPcd_BinaryPatch_PcdPciResAllocTableBase = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdAcpiTablesMaxEntry  0U
#define _PCD_SIZE_PcdAcpiTablesMaxEntry 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTablesMaxEntry  _PCD_SIZE_PcdAcpiTablesMaxEntry 
#define _PCD_VALUE_PcdAcpiTablesMaxEntry  40U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdAcpiTablesMaxEntry = _PCD_VALUE_PcdAcpiTablesMaxEntry;
extern const  UINT32  _gPcd_FixedAtBuild_PcdAcpiTablesMaxEntry;
#define _PCD_GET_MODE_32_PcdAcpiTablesMaxEntry  _gPcd_FixedAtBuild_PcdAcpiTablesMaxEntry
//#define _PCD_SET_MODE_32_PcdAcpiTablesMaxEntry  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdS3DebugEnabled  0U
#define _PCD_SIZE_PcdS3DebugEnabled 1
#define _PCD_GET_MODE_SIZE_PcdS3DebugEnabled  _PCD_SIZE_PcdS3DebugEnabled 
#define _PCD_VALUE_PcdS3DebugEnabled  ((BOOLEAN)0U)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdS3DebugEnabled = _PCD_VALUE_PcdS3DebugEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdS3DebugEnabled;
#define _PCD_GET_MODE_BOOL_PcdS3DebugEnabled  _gPcd_FixedAtBuild_PcdS3DebugEnabled
//#define _PCD_SET_MODE_BOOL_PcdS3DebugEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLowestSupportedFwVer  0U
#define _PCD_SIZE_PcdLowestSupportedFwVer 4
#define _PCD_GET_MODE_SIZE_PcdLowestSupportedFwVer  _PCD_SIZE_PcdLowestSupportedFwVer 
#define _PCD_VALUE_PcdLowestSupportedFwVer  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdLowestSupportedFwVer = _PCD_VALUE_PcdLowestSupportedFwVer;
extern const  UINT32  _gPcd_FixedAtBuild_PcdLowestSupportedFwVer;
#define _PCD_GET_MODE_32_PcdLowestSupportedFwVer  _gPcd_FixedAtBuild_PcdLowestSupportedFwVer
//#define _PCD_SET_MODE_32_PcdLowestSupportedFwVer  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdLegacyEfSegmentEnabled  0U
#define _PCD_SIZE_PcdLegacyEfSegmentEnabled 1
#define _PCD_GET_MODE_SIZE_PcdLegacyEfSegmentEnabled  _PCD_SIZE_PcdLegacyEfSegmentEnabled 
#define _PCD_VALUE_PcdLegacyEfSegmentEnabled  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled = _PCD_VALUE_PcdLegacyEfSegmentEnabled;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled;
#define _PCD_GET_MODE_BOOL_PcdLegacyEfSegmentEnabled  _gPcd_FixedAtBuild_PcdLegacyEfSegmentEnabled
//#define _PCD_SET_MODE_BOOL_PcdLegacyEfSegmentEnabled  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdAcpiTableTemplatePtr  0U
#define _PCD_PATCHABLE_VALUE_PcdAcpiTableTemplatePtr  ((UINT32)0U)
volatile  UINT32 _gPcd_BinaryPatch_PcdAcpiTableTemplatePtr = _PCD_PATCHABLE_VALUE_PcdAcpiTableTemplatePtr;
extern volatile   UINT32  _gPcd_BinaryPatch_PcdAcpiTableTemplatePtr;
#define _PCD_GET_MODE_32_PcdAcpiTableTemplatePtr  _gPcd_BinaryPatch_PcdAcpiTableTemplatePtr
#define _PCD_PATCHABLE_PcdAcpiTableTemplatePtr_SIZE 4
#define _PCD_GET_MODE_SIZE_PcdAcpiTableTemplatePtr  _gPcd_BinaryPatch_Size_PcdAcpiTableTemplatePtr 
extern UINTN _gPcd_BinaryPatch_Size_PcdAcpiTableTemplatePtr; 
GLOBAL_REMOVE_IF_UNREFERENCED UINTN _gPcd_BinaryPatch_Size_PcdAcpiTableTemplatePtr = 4;
#define _PCD_SET_MODE_32_PcdAcpiTableTemplatePtr(Value)  (_gPcd_BinaryPatch_PcdAcpiTableTemplatePtr = (Value))
#define _PCD_SET_MODE_32_S_PcdAcpiTableTemplatePtr(Value)  ((_gPcd_BinaryPatch_PcdAcpiTableTemplatePtr = (Value)), RETURN_SUCCESS) 

#define _PCD_TOKEN_PcdAcpiProcessorIdBase  0U
#define _PCD_SIZE_PcdAcpiProcessorIdBase 4
#define _PCD_GET_MODE_SIZE_PcdAcpiProcessorIdBase  _PCD_SIZE_PcdAcpiProcessorIdBase 
#define _PCD_VALUE_PcdAcpiProcessorIdBase  0x1U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdAcpiProcessorIdBase = _PCD_VALUE_PcdAcpiProcessorIdBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdAcpiProcessorIdBase;
#define _PCD_GET_MODE_32_PcdAcpiProcessorIdBase  _gPcd_FixedAtBuild_PcdAcpiProcessorIdBase
//#define _PCD_SET_MODE_32_PcdAcpiProcessorIdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdFSPSUpdSize  0U
#define _PCD_SIZE_PcdFSPSUpdSize 4
#define _PCD_GET_MODE_SIZE_PcdFSPSUpdSize  _PCD_SIZE_PcdFSPSUpdSize 
#define _PCD_VALUE_PcdFSPSUpdSize  0x00001140U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdFSPSUpdSize = _PCD_VALUE_PcdFSPSUpdSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdFSPSUpdSize;
#define _PCD_GET_MODE_32_PcdFSPSUpdSize  _gPcd_FixedAtBuild_PcdFSPSUpdSize
//#define _PCD_SET_MODE_32_PcdFSPSUpdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BXip  0U
#define _PCD_SIZE_PcdStage1BXip 1
#define _PCD_GET_MODE_SIZE_PcdStage1BXip  _PCD_SIZE_PcdStage1BXip 
#define _PCD_VALUE_PcdStage1BXip  ((BOOLEAN)0x1)
GLOBAL_REMOVE_IF_UNREFERENCED const BOOLEAN _gPcd_FixedAtBuild_PcdStage1BXip = _PCD_VALUE_PcdStage1BXip;
extern const  BOOLEAN  _gPcd_FixedAtBuild_PcdStage1BXip;
#define _PCD_GET_MODE_BOOL_PcdStage1BXip  _gPcd_FixedAtBuild_PcdStage1BXip
//#define _PCD_SET_MODE_BOOL_PcdStage1BXip  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdBase  0U
#define _PCD_SIZE_PcdStage1BFdBase 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdBase  _PCD_SIZE_PcdStage1BFdBase 
#define _PCD_VALUE_PcdStage1BFdBase  0xFFD00000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdBase = _PCD_VALUE_PcdStage1BFdBase;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdBase;
#define _PCD_GET_MODE_32_PcdStage1BFdBase  _gPcd_FixedAtBuild_PcdStage1BFdBase
//#define _PCD_SET_MODE_32_PcdStage1BFdBase  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD

#define _PCD_TOKEN_PcdStage1BFdSize  0U
#define _PCD_SIZE_PcdStage1BFdSize 4
#define _PCD_GET_MODE_SIZE_PcdStage1BFdSize  _PCD_SIZE_PcdStage1BFdSize 
#define _PCD_VALUE_PcdStage1BFdSize  0x00200000U
GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPcd_FixedAtBuild_PcdStage1BFdSize = _PCD_VALUE_PcdStage1BFdSize;
extern const  UINT32  _gPcd_FixedAtBuild_PcdStage1BFdSize;
#define _PCD_GET_MODE_32_PcdStage1BFdSize  _gPcd_FixedAtBuild_PcdStage1BFdSize
//#define _PCD_SET_MODE_32_PcdStage1BFdSize  ASSERT(FALSE)  // It is not allowed to set value for a FIXED_AT_BUILD PCD


RETURN_STATUS
EFIAPI
BaseRngLibConstructor (
  VOID
  );

RETURN_STATUS
EFIAPI
SpiConstructor (
  VOID
  );


VOID
EFIAPI
ProcessLibraryConstructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{
  EFI_STATUS  Status;

  Status = BaseRngLibConstructor ();
  ASSERT_RETURN_ERROR (Status);

  Status = SpiConstructor ();
  ASSERT_RETURN_ERROR (Status);

}



VOID
EFIAPI
ProcessLibraryDestructorList (
  IN       EFI_PEI_FILE_HANDLE       FileHandle,
  IN CONST EFI_PEI_SERVICES          **PeiServices
  )
{

}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT32 _gPeimRevision = 0x00000000U;

EFI_STATUS
EFIAPI
ProcessModuleEntryPointList (
  IN       EFI_PEI_FILE_HANDLE  FileHandle,
  IN CONST EFI_PEI_SERVICES     **PeiServices
  )

{
  return EFI_SUCCESS;
}

GLOBAL_REMOVE_IF_UNREFERENCED const UINT8 _gDriverUnloadImageCount = 0U;

EFI_STATUS
EFIAPI
ProcessModuleUnloadList (
  IN EFI_HANDLE        ImageHandle
  )
{
  return EFI_SUCCESS;
}
