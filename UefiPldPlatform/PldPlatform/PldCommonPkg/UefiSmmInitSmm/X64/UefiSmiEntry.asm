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
LONG_MODE_CS    EQU     28h
TSS_SEGMENT     EQU     30h
    
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
; TSS Segment for X64 specially
TssSeg      LABEL   QWORD
            DW      TSS_DESC_SIZE       ; LimitLow
            DW      0                   ; BaseLow
            DB      0                   ; BaseMid
            DB      89h
            DB      080h                ; LimitHigh
            DB      0                   ; BaseHigh
            DD      0                   ; BaseUpper
            DD      0                   ; Reserved
GDT_SIZE = $ - offset NullSeg

; Create TSS Descriptor just after GDT
TssDescriptor LABEL BYTE
            DD      0                   ; Reserved
            DQ      0                   ; RSP0
            DQ      0                   ; RSP1
            DQ      0                   ; RSP2
            DD      0                   ; Reserved
            DD      0                   ; Reserved
            DQ      0                   ; IST1
            DQ      0                   ; IST2
            DQ      0                   ; IST3
            DQ      0                   ; IST4
            DQ      0                   ; IST5
            DQ      0                   ; IST6
            DQ      0                   ; IST7
            DD      0                   ; Reserved
            DD      0                   ; Reserved
            DW      0                   ; Reserved
            DW      0                   ; I/O Map Base Address
TSS_DESC_SIZE = $ - offset TssDescriptor

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
  DB   060h                       ; pushad
  DB   00Fh, 0A8h                 ; push gs
  DB   00Fh, 0A0h                 ; push fs
  DB   006h                       ; push es
  DB   01Eh                       ; push ds
    
; save the cpu index into edx  
  DB   08Bh, 054h, 024h, 034h     ; mov  edx, [esp + 0x34]
  
; store cs into the cs descriptor for return path  
  DB   0BBh                       ; mov  ebx, offset ToProtectedCS
CodePatch1::
  DD   ?
  mov  ax, cs  
  DB   066h, 089h, 003h           ; mov  word ptr [ebx], ax

; store the smi context pointer into esi  
  DB   0BBh                       ; mov  ebx, offset gSmiContextArray
CodePatch2::
  DD   ?  
  DB   08Bh, 033h                 ; mov  esi, dword ptr [ebx]
  mov  eax, sizeof SMM_CPU_CONTEXT
  mul  edx
  add  esi, eax  
; save idt into smi context
  DB   08Dh, 046h, 006h           ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedIdtr
  DB   00Fh, 001h, 008h           ; sidt [eax]
    
; save gdt into smi context
  DB   08Dh, 006h                 ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedGdtr
  DB   00Fh, 001h, 000h           ; sgdt [eax]
      
; save old stack into smi context
  DB   08Dh, 046h, 00Ch           ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedStack
  DB   089h, 020h                 ; mov [eax], esp
    
; load smm gdt from smi context
  DB   08Dh, 046h, 010h           ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SmiGdtr
  DB   00Fh, 001h, 010h           ; lgdt fword ptr [eax]
  
; jmp to smi code segments
  DB      0eah
CodePatch3::
  DD      ?
  DW      PROTECT_MODE_CS
  
@SmiProtected::
  mov     ax, PROTECT_MODE_DS
  mov     ds, ax
  mov     es, ax
  mov     fs, ax
  mov     gs, ax
  mov     cx, ss
  mov     ss, ax
  
; load new stack
  DB   08Dh, 05Eh, 016h           ; lea  ebx, (SMM_CPU_CONTEXT ptr [esi]).SmiStack
  DB   08Bh, 003h                 ; mov  eax, dword ptr [ebx]
  mov esp, eax
  
; push smi context pointer
  DB   056h              ; push    esi       
  
; push old ss
  push    cx
 
; load page table 
  DB   08Dh, 05Eh, 01Ah           ; lea  ebx, (SMM_CPU_CONTEXT ptr [esi]).SmiCr3
  DB   08Bh, 003h                 ; mov  eax, dword ptr [ebx]
  DB 0Fh,  22h,  0D8h   ; mov  cr3, eax 
  
  mov     rax, cr4
  DB 050h               ; push    eax        
; enable PAE
  mov     eax, 668h                   
  mov     cr4, rax
  
; Get the gdt base
  sub     esp, 8                      
  sgdt    fword ptr [rsp]
  mov     eax, [rsp + 2]              ; eax = GDT base
  add     esp, 8
  mov     edx, eax
  add     edx, GDT_SIZE
; Configure the tss descriptor
  mov     [rax + TSS_SEGMENT + 2], dl
  mov     [rax + TSS_SEGMENT + 3], dh
  DB      0c1h, 0eah, 10h             ; shr     edx, 16
  mov     [rax + TSS_SEGMENT + 4], dl
  mov     [rax + TSS_SEGMENT + 7], dh
  mov     edx, eax
  mov     dl, 89h
  mov     [rax + TSS_SEGMENT + 5], dl ; clear busy flag
; load TSS
  mov     eax, TSS_SEGMENT
  ltr     ax
             
; switch to long mode
  push    LONG_MODE_CS               
  call    Base                       
Base:
  add     dword ptr [rsp], @LongMode - Base
  mov     ecx, 0c0000080h
  rdmsr
  or      ah, 1
  wrmsr
  mov     rbx, cr0
  bts     ebx, 31
  mov     cr0, rbx
  retf
@LongMode:
; load smm idt
  mov     rax, offset gSmiIdtr
  lidt    fword ptr [rax]
  
; call the x64 handler
  mov     rcx, [rsp + 10]                  ; rcx <- CpuIndex
  mov     rax, SmiRendezvous          ; rax <- absolute addr of SmiRedezvous
  
  add     rsp, -20h
  call    rax
  add     rsp, 20h
  
  mov     rcx, PROTECT_MODE_CS            
  shl     rcx, 32
  mov     rdx, offset ToSmiProtected      
  or      rcx, rdx
  push    rcx
  retf

ToSmiProtected:

; switch back to protected mode 
  mov     rbx, cr0
  btr     ebx, 31
  mov     cr0, rbx
  
  mov     ecx, 0c0000080h
  rdmsr
  and     ah, NOT 1
  wrmsr
  
  xor eax, eax
  DB   058h                       ; pop eax             
  mov cr4, rax
  
  pop  cx
  DB   05Eh                       ; pop  esi            
; restore gdt
  DB   08Dh, 006h                 ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedGdtr
  DB   00Fh, 001h, 010h           ; lgdt fword ptr [eax]
  
  DB      0eah
CodePatch4::
  DD      ?
ToProtectedCS::
  DW      ?
  
@ToProtected::
; restore stack
  mov  ss, cx
  DB   08Dh, 05Eh, 00Ch           ; lea  ebx, (SMM_CPU_CONTEXT ptr [esi]).SavedStack
  DB   08Bh, 003h                 ; mov  eax, dword ptr [ebx]
  mov  esp, eax
  
; restore idt
  DB   08Dh, 046h, 006h           ; lea  eax, (SMM_CPU_CONTEXT ptr [esi]).SavedIdtr
  DB   00Fh, 001h, 018h           ; lidt fword ptr [eax]
  
  DB   01Fh        ; pop ds
  DB   007h        ; pop es
  DB   00Fh, 0A1h  ; pop fs
  DB   00Fh, 0A9h  ; pop gs
  DB   061h        ; popad
  ret
UefiSmiEntryPoint ENDP


AsmGetAddressMap   PROC
  mov         rax, offset CodePatch1
  mov         qword ptr [rcx], rax             ; CodePatchAddr1
  mov         rax, offset ToProtectedCS
  mov         qword ptr [rcx + 08h], rax       ; CodePatchValue1
  
  mov         rax, offset CodePatch2
  mov         qword ptr [rcx + 010h], rax      ; CodePatchAddr2
  mov         rax, offset gSmiContextArray
  mov         qword ptr [rcx + 018h], rax      ; CodePatchValue2
  
  mov         rax, offset CodePatch3
  mov         qword ptr [rcx + 020h], rax      ; CodePatchAddr3
  mov         rax, offset @SmiProtected
  mov         qword ptr [rcx + 028h], rax      ; CodePatchValue3
    
  mov         rax, offset CodePatch4
  mov         qword ptr [rcx + 030h], rax      ; CodePatchAddr4
  mov         rax, offset @ToProtected
  mov         qword ptr [rcx + 038h], rax      ; CodePatchValue4
  ret
AsmGetAddressMap   ENDP

    END
