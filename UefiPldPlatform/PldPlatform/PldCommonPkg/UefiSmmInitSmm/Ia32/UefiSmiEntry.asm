;------------------------------------------------------------------------------
;
; Copyright (c) 2014, Intel Corporation. All rights reserved.<BR>
; This program and the accompanying materials
; are licensed and made available under the terms and conditions of the BSD License
; which accompanies this distribution.  The full text of the license may be found at
; http://opensource.org/licenses/bsd-license.php.
;
; THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
; WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
;
; Module Name:
;
;  SmiEntry.asm
;
; Abstract:
;
;  This is the code that begins in protected mode.
;  It will transfer the control to smm core.
;
;------------------------------------------------------------------------------
#include <Base.h>

;
; Variables referrenced by C code
;

    .386p
    .model  flat,C
    
EXTERNDEF   SmiRendezvous:PROC
EXTERNDEF   gSmiContextArray:DWORD
EXTERNDEF   gSampleSmiGdtr:FWORD
EXTERNDEF   gSmiIdtr:FWORD
    
SMM_CPU_CONTEXT  STRUC   
  SavedGdtr  FWORD  ?
  SavedIdtr  FWORD  ?
  SavedStack DD     ?
  
  SmiGdtr    FWORD  ? 
  SmiStack   DD     ?  
  SmiCr3     DD     ?  
SMM_CPU_CONTEXT ENDS    

PROTECT_MODE_CS EQU     08h
PROTECT_MODE_DS EQU     10h
    
    .data 
    
NullSeg     DQ      0                   ; reserved by architecture
CodeSeg32   LABEL   QWORD
            DW      -1                  ; LimitLow
            DW      0                   ; BaseLow
            DB      0                   ; BaseMid
            DB      9bh
            DB      0cfh                ; LimitHigh
            DB      0                   ; BaseHigh
DataSeg32   LABEL   QWORD
            DW      -1                  ; LimitLow
            DW      0                   ; BaseLow
            DB      0                   ; BaseMid
            DB      93h
            DB      0cfh                ; LimitHigh
            DB      0                   ; BaseHigh
CodeSeg16   LABEL   QWORD
            DW      -1
            DW      0
            DB      0
            DB      9bh
            DB      8fh
            DB      0
DataSeg16   LABEL   QWORD
            DW      -1
            DW      0
            DB      0
            DB      93h
            DB      8fh
            DB      0
CodeSeg64   LABEL   QWORD
            DW      -1                  ; LimitLow
            DW      0                   ; BaseLow
            DB      0                   ; BaseMid
            DB      9bh
            DB      0afh                ; LimitHigh
            DB      0                   ; BaseHigh
GDT_SIZE = $ - offset NullSeg

;
; CODE & DATA segments for SMM runtime
;
CODE_SEL    = offset CodeSeg64 - offset NullSeg
DATA_SEL    = offset DataSeg32 - offset NullSeg
CODE32_SEL  = offset CodeSeg32 - offset NullSeg

gSampleSmiGdtr   LABEL   FWORD
    DW      GDT_SIZE - 1
    DQ      offset NullSeg
    
gSmiIdtr   LABEL   FWORD
    DW      IDT_SIZE - 1
    DQ      offset _SmiIDT
    
_SmiIDT     LABEL   QWORD
REPEAT      32
    DW      0                           ; Offset 0:15
    DW      CODE_SEL                    ; Segment selector
    DB      0                           ; Unused
    DB      8eh                         ; Interrupt Gate, Present
    DW      0                           ; Offset 16:31
            ENDM
IDT_SIZE = $ - offset _SmiIDT

gSmiContextArray LABEL DWORD
    DD      ?
    
    .code
        
UefiSmiEntryPoint PROC
; save all the registers
  pushad
  push gs
  push fs
  push es
  push ds
    
; save the cpu index into edx
  mov  edx, [esp + 0x34]
  
; store cs into the cs descriptor for return path
  mov  ebx, offset ToProtectedCS
  mov  ax, cs
  mov  word ptr [ebx], ax

; store the smi context pointer into esi
  mov  ebx, offset gSmiContextArray
  mov  esi, dword ptr [ebx]
  mov  eax, sizeof SMM_CPU_CONTEXT
  mul  edx
  add  esi, eax  
; save idt into smi context
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedIdtr
  sidt [eax]
    
; save gdt into smi context
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedGdtr
  sgdt [eax]
      
; save old stack into smi context
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedStack
  mov [eax], esp
    
; load smm gdt from smi context
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SmiGdtr
  lgdt fword ptr [eax]
  
; jmp to smi code segments
  DB      0eah
  DD      @SmiProtected
  DW      PROTECT_MODE_CS
  
@SmiProtected:
  mov     ax, PROTECT_MODE_DS
  mov     ds, ax
  mov     es, ax
  mov     fs, ax
  mov     gs, ax
  mov     cx, ss
  mov     ss, ax
  
; load new stack
  lea  ebx, (SMM_CPU_CONTEXT ptr [esi]).SmiStack
  mov  eax, dword ptr [ebx]
  mov esp, eax
  
; push smi context pointer
  push    esi
  
; push old ss
  push    cx
  
; load smm idt
  mov     eax, offset gSmiIdtr
  lidt    fword ptr [eax]
  
; call the ia32 handler
  mov     ecx, [esp + 6]                  ; ecx <- CpuIndex
  push    ecx
  mov     eax, SmiRendezvous
  call    eax
  pop     ecx

  pop  cx
  pop  esi
; restore gdt
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedGdtr
  lgdt fword ptr [eax]
  
  DB      0eah
  DD      @ToProtected
ToProtectedCS:
  DW      ?
  
@ToProtected:
; restore stack
  mov  ss, cx
  lea  ebx, (SMM_CPU_CONTEXT ptr [esi]).SavedStack
  mov  eax, dword ptr [ebx]
  mov  esp, eax
  
; restore idt
  lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedIdtr
  lidt fword ptr [eax]
  
  pop ds
  pop es
  pop fs
  pop gs
  popad
  ret
UefiSmiEntryPoint ENDP

AsmGetAddressMap   PROC
  ; dummy function for ia32
  ret
AsmGetAddressMap   ENDP

    END
