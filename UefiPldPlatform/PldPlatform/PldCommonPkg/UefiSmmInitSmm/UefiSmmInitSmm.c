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

#include "UefiSmmInitSmm.h"

//
// SMM Init Private Data structure that contains SMM Configuration Protocol 
// along its supporting fields.
//
SMM_INIT_PRIVATE_DATA  mSmmInitPrivateData = {
  SMM_INIT_PRIVATE_DATA_SIGNATURE,              // Signature
  NULL,                                         // SmmInitHandle
  { 0 },                                        // SmmReservedSmramRegion
  {
    NULL,                                       // SmmCoreEntryContext.SmmStartupThisAp
    0,                                          // SmmCoreEntryContext.CurrentlyExecutingCpu
    0,                                          // SmmCoreEntryContext.NumberOfCpus
    NULL,                                       // SmmCoreEntryContext.CpuSaveStateSize
    NULL                                        // SmmCoreEntryContext.CpuSaveState
  },
  NULL,                                         // SmmCoreEntry
  {
    mSmmInitPrivateData.SmmReservedSmramRegion, // SmmConfiguration.SmramReservedRegions
    RegisterSmmEntry                            // SmmConfiguration.RegisterSmmEntry
  },
};


//
// Global pointer used to access mSmmInitPrivateData from outside and inside SMM
//
SMM_INIT_PRIVATE_DATA  *gSmmInitPrivate = &mSmmInitPrivateData;

UINTN mNumberOfCpus = 1;
UINTN mSmmStackSize;
SMM_UEFI_COMMUNICATION  *gUefiComm = NULL;

#define PAGE_TABLE_PAGES            8
#define IA32_PG_PMNT                (1ull << 62)
#define IA32_PG_P                   1u
#define IA32_PG_RW                  (1u << 1)
#define IA32_PG_PS                  (1u << 7)
BOOLEAN                             m1GPageTableSupport = FALSE;

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
  )
{
  //
  // Record SMM Foundation EntryPoint, later invoke it on SMI entry vector.
  //
  gSmmInitPrivate->SmmCoreEntry = SmmEntryPoint;
  
  //
  // Achor our smm entry point into smm uefi communication structure
  //
  gUefiComm->UefiEntry = (UINT64)(UINTN)UefiSmiEntryPoint;
  DEBUG ((EFI_D_ERROR, "SMM: achor uefi entrypoint %p.\n", UefiSmiEntryPoint));
  return EFI_SUCCESS;
}

/**
  Create 4G PageTable in SMRAM.

  @param          ExtraPages       Additional page numbers besides for 4G memory
  @return         PageTable Address

**/
UINT32
Gen4GPageTable (
  IN      UINTN                     ExtraPages
  )
{
  VOID    *PageTable;
  UINTN   Index;
  UINT64  *Pte;
  
  //
  // Allocate the page table
  //
  PageTable = AllocatePages (ExtraPages + 5);
  ASSERT (PageTable != NULL);

  PageTable = (VOID *)((UINTN)PageTable + EFI_PAGES_TO_SIZE (ExtraPages));
  Pte = (UINT64*)PageTable;

  //
  // Zero out all page table entries first
  //
  ZeroMem (Pte, EFI_PAGES_TO_SIZE (1));

  //
  // Set Page Directory Pointers
  //
  for (Index = 0; Index < 4; Index++) {
    Pte[Index] = (UINTN)PageTable + EFI_PAGE_SIZE * (Index + 1) + IA32_PG_P;
  }
  Pte += EFI_PAGE_SIZE / sizeof (*Pte);

  //
  // Fill in Page Directory Entries
  //
  for (Index = 0; Index < EFI_PAGE_SIZE * 4 / sizeof (*Pte); Index++) {
    Pte[Index] = (Index << 21) + IA32_PG_PS + IA32_PG_RW + IA32_PG_P;
  }
  
  return (UINT32)(UINTN)PageTable;
}

/**
  Check if 1-GByte pages is supported by processor or not.
  
  @retval TRUE   1-GByte pages is supported.
  @retval FALSE  1-GByte pages is not supported.

**/
BOOLEAN
Is1GPageSupport (
  VOID
  )
{
  UINT32         RegEax;
  UINT32         RegEdx;

  AsmCpuid (0x80000000, &RegEax, NULL, NULL, NULL);
  if (RegEax >= 0x80000001) {
    AsmCpuid (0x80000001, NULL, NULL, NULL, &RegEdx);
    if ((RegEdx & BIT26) != 0) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
  Set sub-entries number in entry.
  
  @param[in, out] Entry        Pointer to entry
  @param[in]      SubEntryNum  Sub-entries number based on 0:
                               0 means there is 1 sub-entry under this entry 
                               0x1ff means there is 512 sub-entries under this entry

**/
VOID
SetSubEntriesNum (
  IN OUT UINT64               *Entry,
  IN     UINT64               SubEntryNum
  )
{
  //
  // Sub-entries number is saved in BIT52 to BIT60 (reserved field) in Entry
  //
  *Entry = BitFieldWrite64 (*Entry, 52, 60, SubEntryNum);
}

/**
  Create PageTable for SMM use.

  @return The address of PML4 (to set CR3).

**/
UINT32
SmmInitPageTable (
  VOID
  )
{
  EFI_PHYSICAL_ADDRESS              Pages;
  UINT64                            *PTEntry;
  UINTN                             Index;
  
  m1GPageTableSupport = Is1GPageSupport ();
  //
  // Generate PAE page table for the first 4GB memory space
  //
  Pages = Gen4GPageTable (PAGE_TABLE_PAGES + 1);

  //
  // Set IA32_PG_PMNT bit to mask this entry
  //
  PTEntry = (UINT64*)(UINTN)Pages;
  for (Index = 0; Index < 4; Index++) {
    PTEntry[Index] |= IA32_PG_PMNT;
  }

  //
  // Fill Page-Table-Level4 (PML4) entry
  //
  PTEntry = (UINT64*)(UINTN)(Pages - EFI_PAGES_TO_SIZE (PAGE_TABLE_PAGES + 1));
  *PTEntry = Pages + IA32_PG_P;
  ZeroMem (PTEntry + 1, EFI_PAGE_SIZE - sizeof (*PTEntry));
  //
  // Set sub-entries number 
  //
  SetSubEntriesNum (PTEntry, 3);
  
  //
  // Return the address of PML4 (to set CR3)
  //
  return (UINT32)(UINTN)PTEntry;

}

/**
  Initialize global data for MP synchronization.

  @param ImageHandle  File Image Handle.
  @param Stacks       Base address of SMI stack buffer for all processors.
  @param StackSize    Stack size for each processor in SMM.

**/
VOID
InitializeMpServiceData (
  IN EFI_HANDLE  ImageHandle,
  IN VOID        *Stacks,
  IN UINTN       StackSize
 )
{
  SMM_CPU_CONTEXT   *pCpuContextArray = NULL;
  UINTN             Index;
  UINT32            PageTableEntry = 0;
  UINTN             GdtTssTableSize;
  UINT8             *GdtTssTables;
  UINTN             GdtTableStepSize;
  UINT8             *StackPtr;
  SMM_ASSEMBLY_ADDRESS_MAP AddressMap;

  pCpuContextArray = AllocateZeroPool (mNumberOfCpus * sizeof (SMM_CPU_CONTEXT));
  ASSERT (pCpuContextArray != NULL);
  gSmiContextArray = (UINT32) (UINTN)pCpuContextArray;

  DEBUG ((EFI_D_ERROR, "SMM: cpu context array base %p.\n", pCpuContextArray));

  StackPtr = (UINT8 *)Stacks + StackSize - sizeof (UINTN);

  //
  // Create the page table
  //
  if (EFI_IMAGE_MACHINE_TYPE_SUPPORTED(EFI_IMAGE_MACHINE_X64)) {
    PageTableEntry = SmmInitPageTable ();
  }

  //
  // Create the gdt table and tss descriptor for x64
  //
  GdtTssTables    = NULL;
  GdtTssTableSize = 0;
  GdtTableStepSize = 0;
  //
  // For X64 SMM, we allocate separate GDT/TSS for each CPUs to avoid TSS load contention
  // on each SMI entry.
  //
  if (EFI_IMAGE_MACHINE_TYPE_SUPPORTED(EFI_IMAGE_MACHINE_X64)) {
    GdtTssTableSize = (gSampleSmiGdtr.Limit + 1 + TSS_SIZE + 7) & ~7; // 8 bytes aligned
    GdtTssTables = (UINT8*)AllocatePages (EFI_SIZE_TO_PAGES (GdtTssTableSize * mNumberOfCpus));
    ASSERT (GdtTssTables != NULL);
    GdtTableStepSize = GdtTssTableSize;
    
    for (Index = 0; Index < mNumberOfCpus; Index++) {
      CopyMem (GdtTssTables + GdtTableStepSize * Index, (VOID*)(UINTN)gSampleSmiGdtr.Base, gSampleSmiGdtr.Limit + 1 + TSS_SIZE);    	
    }
  }

  for (Index = 0; Index < mNumberOfCpus; Index++) {
    *((UINT32 *)StackPtr) = (UINT32)Index;

    if (EFI_IMAGE_MACHINE_TYPE_SUPPORTED(EFI_IMAGE_MACHINE_X64)) {
      //
      // For X64 SMM, set GDT to the copy allocated above.
      //
      pCpuContextArray->SmiGdtr.Base = (UINT32)(UINTN)(GdtTssTables + GdtTableStepSize * Index);
      pCpuContextArray->SmiGdtr.Limit = (UINT16)GdtTableStepSize - 1;
      pCpuContextArray->SmiCr3 = PageTableEntry;
    } else {
      pCpuContextArray->SmiGdtr.Base = (UINT32)(UINTN)gSampleSmiGdtr.Base;
      pCpuContextArray->SmiGdtr.Limit = gSampleSmiGdtr.Limit;
    }

    pCpuContextArray->SmiStack = (UINT32)(UINTN)StackPtr;

    DEBUG ((EFI_D_ERROR, "SMM: cpu %d, stack at 0x%x.\n", pCpuContextArray->SmiStack));

    StackPtr += StackSize;
    pCpuContextArray++;
  }

  //
  // Do code patch for x64 assembly
  //
  if (EFI_IMAGE_MACHINE_TYPE_SUPPORTED(EFI_IMAGE_MACHINE_X64)) {
    AsmGetAddressMap (&AddressMap);
    *(UINT32 *)AddressMap.CodePatchAddr1 = (UINT32) (UINTN)AddressMap.CodePatchValue1;
    *(UINT32 *)AddressMap.CodePatchAddr2 = (UINT32) (UINTN)AddressMap.CodePatchValue2;
    *(UINT32 *)AddressMap.CodePatchAddr3 = (UINT32) (UINTN)AddressMap.CodePatchValue3;
    *(UINT32 *)AddressMap.CodePatchAddr4 = (UINT32) (UINTN)AddressMap.CodePatchValue4;
  }
}

/**
  C function for SMI entry, each processor comes here upon SMI trigger.

  @param    CpuIndex              Cpu Index

**/
VOID
EFIAPI
SmiRendezvous (
  IN      UINTN                     CpuIndex
  )
{
  UINTN             Cr2;

  //
  // Save Cr2 because Page Fault exception in SMM may override its value
  //
  Cr2 = AsmReadCr2 ();

  //
  // Enable XMM instructions & exceptions
  //
  AsmWriteCr4 (AsmReadCr4 () | 0x600);
  
  //
  // Only one thread enters into our entry point from coreboot
  //
  
  //
  // Set running processor index
  //
  gSmmInitPrivate->SmmCoreEntryContext.CurrentlyExecutingCpu = CpuIndex;
  
  //
  // Maybe need to copy the content of cpu state
  //
  
  //
  // Invoke SMM Foundation EntryPoint with the processor information context.
  //
  gSmmInitPrivate->SmmCoreEntry (&gSmmInitPrivate->SmmCoreEntryContext);
  
  
  //
  // Restore Cr2
  //
  AsmWriteCr2 (Cr2);
}

/**

  Find out SMRAM information including SMRR base, SMRR size.

  @param          SmrrBase          SMRR base
  @param          SmrrSize          SMRR size
  
**/
VOID
FindSmramInfo (
  OUT UINT32   *SmrrBase,
  OUT UINT32   *SmrrSize
  )
{
  EFI_STATUS                        Status;
  UINTN                             Size;
  EFI_SMM_ACCESS2_PROTOCOL          *SmmAccess;
  EFI_SMRAM_DESCRIPTOR              *CurrentSmramRange;
  EFI_SMRAM_DESCRIPTOR              *SmramRanges;
  UINTN                             SmramRangeCount;
  UINTN                             Index;
  UINT64                            MaxSize;
  
  //
  // Get SMM Access Protocol
  //
  Status = gBS->LocateProtocol (&gEfiSmmAccess2ProtocolGuid, NULL, (VOID **)&SmmAccess);
  ASSERT_EFI_ERROR (Status);

  //
  // Get SMRAM information
  //
  Size = 0;
  Status = SmmAccess->GetCapabilities (SmmAccess, &Size, NULL);
  ASSERT (Status == EFI_BUFFER_TOO_SMALL);

  SmramRanges = (EFI_SMRAM_DESCRIPTOR *)AllocatePool (Size);
  ASSERT (SmramRanges != NULL);

  Status = SmmAccess->GetCapabilities (SmmAccess, &Size, SmramRanges);
  ASSERT_EFI_ERROR (Status);

  SmramRangeCount = Size / sizeof (EFI_SMRAM_DESCRIPTOR);
  
  //
  // Find the largest SMRAM range 
  //
  CurrentSmramRange = NULL;
  for (Index = 0, MaxSize = 0; Index < SmramRangeCount; Index++) {
    if (SmramRanges[Index].CpuStart >= BASE_1MB) {
      if ((SmramRanges[Index].CpuStart + SmramRanges[Index].PhysicalSize) <= BASE_4GB) {
        if (SmramRanges[Index].PhysicalSize >= MaxSize) {
          MaxSize = SmramRanges[Index].PhysicalSize;
          CurrentSmramRange = &SmramRanges[Index];
        }
      }
    }
  }
  
  ASSERT (CurrentSmramRange != NULL);
  if (SmrrBase)
    *SmrrBase = (UINT32)CurrentSmramRange->CpuStart;

  if (SmrrSize)
    *SmrrSize = (UINT32)CurrentSmramRange->PhysicalSize;
}


/**
  The module Entry Point of the SMM Init driver.

  @param  ImageHandle    The firmware allocated handle for the EFI image.
  @param  SystemTable    A pointer to the EFI System Table.

  @retval EFI_SUCCESS    The entry point is executed successfully.
  @retval Other          Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
UefiSmmInitEntry (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  UINT8                   *Stacks;
  EFI_STATUS              Status;
  UINT32                  SmmBase;

  //
  // Find the smm memory region information
  //
  SmmBase = 0;
  FindSmramInfo (&SmmBase, NULL);
  DEBUG ((EFI_D_ERROR, "SMM: smm ram base 0x%x.\n", SmmBase));
  ASSERT (SmmBase != 0);

  gUefiComm = (SMM_UEFI_COMMUNICATION *)(UINTN)(SmmBase - SIZE_4KB);
  ASSERT (gUefiComm != 0);
  if (gUefiComm->Signature != SMM_UEFI_COMMUNICATION_SIGNATURE) {
    DEBUG ((EFI_D_ERROR, "SMM: incorrect signature in the coreboot smm uefi communication structure.\n"));
    return EFI_DEVICE_ERROR;
  }

  //
  // Get the number of cpus from smm uefi communication structure
  //
  mNumberOfCpus = gUefiComm->NumberofCpus;
  DEBUG ((EFI_D_ERROR, "SMM: %d processors are detected.\n", mNumberOfCpus));
  gSmmInitPrivate->SmmCoreEntryContext.NumberOfCpus = mNumberOfCpus;
  
  mSmmStackSize = PcdGet32 (PcdCpuSmmStackSize);
  Stacks = (UINT8 *) AllocatePages (EFI_SIZE_TO_PAGES (mNumberOfCpus * mSmmStackSize));
  ASSERT (Stacks != NULL);
  
  //
  // Prepare the stack, gdt, idt for smm entrypoint 
  //
  InitializeMpServiceData (ImageHandle, Stacks, mSmmStackSize);
  
  //
  // Fill in SMM Reserved Regions
  //
  gSmmInitPrivate->SmmReservedSmramRegion[0].SmramReservedStart = 0;
  gSmmInitPrivate->SmmReservedSmramRegion[0].SmramReservedSize  = 0;

  //
  // Install the SMM Configuration Protocol 
  //
  Status = SystemTable->BootServices->InstallMultipleProtocolInterfaces (
                                        &gSmmInitPrivate->SmmInitHandle,
                                        &gEfiSmmConfigurationProtocolGuid, &gSmmInitPrivate->SmmConfiguration,
                                        NULL
                                        );
  ASSERT_EFI_ERROR (Status);
  
  DEBUG ((EFI_D_ERROR, "SMM CPU Module exit from SMRAM with EFI_SUCCESS\n"));

  return EFI_SUCCESS;
}

