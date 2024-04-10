/** @file
  Agent Module to load other modules to deploy SMM Entry Vector for X86 CPU.
  
  Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/
#ifndef _UEFI_SMM_INIT_SMM_H_
#define _UEFI_SMM_INIT_SMM_H_
#include <PiSmm.h>

#include <Protocol/SmmConfiguration.h>
#include <Protocol/SmmAccess2.h>

#include <Library/BaseLib.h>
#include <Library/DebugLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/PcdLib.h>
#include <Library/SmmServicesTableLib.h>
#include <Library/MemoryAllocationLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/UefiRuntimeServicesTableLib.h>

//
// Size of Task-State Segment defined in IA32 Manual
//
#define TSS_SIZE              104
#define TSS_X64_IST1_OFFSET   36
#define TSS_IA32_CR3_OFFSET   28
#define TSS_IA32_ESP_OFFSET   56


#define SMM_INIT_PRIVATE_DATA_SIGNATURE  SIGNATURE_32 ('s', 'i', 'n', 'i')

typedef struct {
  UINTN                           Signature;
  EFI_HANDLE                      SmmInitHandle;

  EFI_SMM_RESERVED_SMRAM_REGION   SmmReservedSmramRegion[1];
  EFI_SMM_ENTRY_CONTEXT           SmmCoreEntryContext;
  EFI_SMM_ENTRY_POINT             SmmCoreEntry;

  EFI_SMM_CONFIGURATION_PROTOCOL  SmmConfiguration;
} SMM_INIT_PRIVATE_DATA;


#pragma pack (1)

typedef struct {
  UINT16  Limit;
  UINT32  Base;
} SMM_IA32_DESCRIPTOR;

typedef struct {
	SMM_IA32_DESCRIPTOR  SavedGdtr;
	SMM_IA32_DESCRIPTOR  SavedIdtr;	
	UINT32               SavedStack;
	
	SMM_IA32_DESCRIPTOR  SmiGdtr;
	UINT32               SmiStack;
	UINT32               SmiCr3;	
} SMM_CPU_CONTEXT;

#define SMM_UEFI_COMMUNICATION_SIGNATURE SIGNATURE_64 ('$', 'S', 'M', 'U', 'F', 'C', 'O', 'M')
typedef struct {
	UINT64    Signature;
	UINT64    UefiEntry;
	UINT32    RunningCpuIdx;
	UINT32    NumberofCpus;
	UINT8     CpuApicId[1];	
} SMM_UEFI_COMMUNICATION;

#pragma pack ()

typedef struct {
  UINT32 *CodePatchAddr1;
  UINT64 CodePatchValue1;
  UINT32 *CodePatchAddr2;
  UINT64 CodePatchValue2;
  UINT32 *CodePatchAddr3;
  UINT64 CodePatchValue3;
  UINT32 *CodePatchAddr4;
  UINT64 CodePatchValue4; 
} SMM_ASSEMBLY_ADDRESS_MAP;

extern SMM_INIT_PRIVATE_DATA  *gSmmInitPrivate;
extern UINTN                  mNumberOfCpus;
extern IA32_DESCRIPTOR        gSampleSmiGdtr;
extern IA32_DESCRIPTOR        gSmiIdtr;
extern volatile UINT32        gSmiContextArray;

/**

  Register the SMM Foundation entry point.

  @param          This              Pointer to EFI_SMM_CONFIGURATION_PROTOCOL instance
  @param          SmmEntryPoint     SMM Foundation EntryPoint

  @retval         EFI_SUCCESS       Successfully to register SMM foundation entry point

**/
EFI_STATUS
EFIAPI
RegisterSmmEntry (
  IN CONST EFI_SMM_CONFIGURATION_PROTOCOL  *This,
  IN EFI_SMM_ENTRY_POINT                   SmmEntryPoint
  );

void UefiSmiEntryPoint (UINT32 CpuIndex);

VOID
EFIAPI
AsmGetAddressMap (
  OUT SMM_ASSEMBLY_ADDRESS_MAP    *AddressMap
  );

#endif
