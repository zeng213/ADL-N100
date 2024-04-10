/** @file
  SMM SwDispatch2 Protocol.

  Copyright (c) 2010 - 2019, Intel Corporation. All rights reserved.<BR>
  This program and the accompanying materials
  are licensed and made available under the terms and conditions of the BSD License
  which accompanies this distribution.  The full text of the license may be found at
  http://opensource.org/licenses/bsd-license.php.

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

**/

#include "SmmSwDispatch.h"

UINT8                  mSmiTriggerRegister = 0xB2;
UINT8                  mSmiDataRegister    = 0xB3;

EFI_SMM_CPU_PROTOCOL   *mSmmCpuProtocol;
LIST_ENTRY             mSmmSwDispatch2Queue = INITIALIZE_LIST_HEAD_VARIABLE (mSmmSwDispatch2Queue);

EFI_STATUS
SaveSmmInfo (
  VOID
  );

/**
  Find SmmSwDispatch2Context by SwSmiInputValue.

  @param[in] SwSmiInputValue      The value to indentify the SmmSwDispatch2 context

  @return Pointer to EFI_SMM_SW_DISPATCH2_CONTEXT context
**/
EFI_SMM_SW_DISPATCH2_CONTEXT *
FindContextBySwSmiInputValue (
  IN UINTN                              SwSmiInputValue
  )
{
  LIST_ENTRY                            *Node;
  EFI_SMM_SW_DISPATCH2_CONTEXT          *Dispatch2Context;

  Node = mSmmSwDispatch2Queue.ForwardLink;
  for (; Node != &mSmmSwDispatch2Queue; Node = Node->ForwardLink) {
    Dispatch2Context = BASE_CR (Node, EFI_SMM_SW_DISPATCH2_CONTEXT, Link);
    if (Dispatch2Context->SwSmiInputValue == SwSmiInputValue) {
      return Dispatch2Context;
    }
  }
  return NULL;
}

/**
  Find SmmSwDispatch2Context by DispatchHandle.

  @param DispatchHandle    The handle to indentify the SmmSwDispatch2 context

  @return Pointer to EFI_SMM_SW_DISPATCH2_CONTEXT context
**/
EFI_SMM_SW_DISPATCH2_CONTEXT *
FindContextByDispatchHandle (
  IN EFI_HANDLE                         DispatchHandle
  )
{
  LIST_ENTRY                            *Node;
  EFI_SMM_SW_DISPATCH2_CONTEXT          *Dispatch2Context;

  Node = mSmmSwDispatch2Queue.ForwardLink;
  for (; Node != &mSmmSwDispatch2Queue; Node = Node->ForwardLink) {
    Dispatch2Context = BASE_CR (Node, EFI_SMM_SW_DISPATCH2_CONTEXT, Link);
    if (Dispatch2Context->DispatchHandle == DispatchHandle) {
      return Dispatch2Context;
    }
  }
  return NULL;
}

/**
  Dispatch registered SMM handlers

  @param  DispatchHandle  The unique handle assigned to this handler by SmiHandlerRegister().
  @param  RegisterContext Points to an optional handler context which was specified when the handler was registered.
  @param  CommBuffer      A pointer to a collection of data in memory that will
                          be conveyed from a non-SMM environment into an SMM environment.
  @param  CommBufferSize  The size of the CommBuffer.

  @return Status Code

**/
EFI_STATUS
SmmSwDispatcher (
  IN     EFI_HANDLE               DispatchHandle,
  IN     CONST VOID               *RegisterContext,
  IN OUT VOID                     *CommBuffer,
  IN OUT UINTN                    *CommBufferSize
  )
{
  EFI_STATUS                      Status;
  EFI_SMM_SW_CONTEXT              SwContext;
  UINTN                           Index;
  EFI_SMM_SW_DISPATCH2_CONTEXT    *Context;
  EFI_SMM_HANDLER_ENTRY_POINT2    DispatchFunction;
  EFI_SMM_SW_REGISTER_CONTEXT     DispatchContext;
  UINTN                           Size;
  EFI_SMM_SAVE_STATE_IO_INFO      IoInfo;

  //
  // Construct new context
  //
  SwContext.SwSmiCpuIndex = 0;
  SwContext.CommandPort   = IoRead8 (mSmiTriggerRegister);
  SwContext.DataPort      = IoRead8 (mSmiDataRegister);

  //
  // Try to find which CPU trigger SWSMI
  //
  for (Index = 0; Index < gSmst->NumberOfCpus; Index++) {
    Status = mSmmCpuProtocol->ReadSaveState (
                                mSmmCpuProtocol,
                                sizeof(IoInfo),
                                EFI_SMM_SAVE_STATE_REGISTER_IO,
                                Index,
                                &IoInfo
                                );
    if (EFI_ERROR (Status)) {
      continue;
    }
    if (IoInfo.IoPort == mSmiTriggerRegister) {
      //
      // Great! Find it.
      //
      SwContext.SwSmiCpuIndex = Index;
      //DEBUG ((DEBUG_INFO, "CPU index = 0x%x/0x%x\n", Index, gSmst->NumberOfCpus));
      break;
    }
  }

  if (SwContext.CommandPort == 0) {
    //DEBUG ((DEBUG_INFO, "NOT SW SMI\n"));
    return EFI_SUCCESS;
  }

  //
  // Search context
  //
  Context = FindContextBySwSmiInputValue (SwContext.CommandPort);
  if (Context == NULL) {
    DEBUG ((DEBUG_ERROR, "No handler for SMI value 0x%x\n", SwContext.CommandPort));
    return EFI_SUCCESS;
  }

  DEBUG ((DEBUG_INFO, "Prepare to call handler for 0x%x\n", SwContext.CommandPort));

  //
  // Dispatch
  //
  DispatchContext.SwSmiInputValue = SwContext.CommandPort;
  Size = sizeof(SwContext);
  DispatchFunction = (EFI_SMM_HANDLER_ENTRY_POINT2)Context->DispatchFunction;
  Status = DispatchFunction (DispatchHandle, &DispatchContext, &SwContext, &Size);

  return Status;
}



/**
Check the SwSmiInputValue is already used

@param[in]  SwSmiInputValue      To indentify the SmmSwDispatch2 context

@retval EFI_SUCCESS              SwSmiInputValue could be used.
@retval EFI_INVALID_PARAMETER    SwSmiInputValue is already be used.

**/
EFI_STATUS
SmiInputValueCheck (
  IN UINTN                              SwSmiInputValue
  )
{
  LIST_ENTRY                            *Node;
  EFI_SMM_SW_DISPATCH2_CONTEXT          *Dispatch2Context;

  Node = mSmmSwDispatch2Queue.ForwardLink;
  for (; Node != &mSmmSwDispatch2Queue; Node = Node->ForwardLink) {
    Dispatch2Context = BASE_CR (Node, EFI_SMM_SW_DISPATCH2_CONTEXT, Link);
    if (Dispatch2Context->SwSmiInputValue == SwSmiInputValue) {
      return EFI_INVALID_PARAMETER;
    }
  }

  return EFI_SUCCESS;
}


/**
  Register a child SMI source dispatch function for the specified software SMI.

  This service registers a function (DispatchFunction) which will be called when the software
  SMI source specified by RegContext->SwSmiCpuIndex is detected. On return, DispatchHandle
  contains a unique handle which may be used later to unregister the function using UnRegister().

  @param[in]  This               Pointer to the EFI_SMM_SW_DISPATCH2_PROTOCOL instance.
  @param[in]  DispatchFunction   Function to register for handler when the specified software
                                 SMI is generated.
  @param[in, out]  RegContext    Pointer to the dispatch function's context.
                                 The caller fills this context in before calling
                                 the register function to indicate to the register
                                 function which Software SMI input value the
                                 dispatch function should be invoked for.
  @param[out] DispatchHandle     Handle generated by the dispatcher to track the
                                 function instance.

  @retval EFI_SUCCESS            The dispatch function has been successfully
                                 registered and the SMI source has been enabled.
  @retval EFI_DEVICE_ERROR       The SW driver was unable to enable the SMI source.
  @retval EFI_INVALID_PARAMETER  RegisterContext is invalid. The SW SMI input value
                                 is not within valid range.
  @retval EFI_OUT_OF_RESOURCES   There is not enough memory (system or SMM) to manage this
                                 child.
  @retval EFI_OUT_OF_RESOURCES   A unique software SMI value could not be assigned
                                 for this dispatch.
**/
EFI_STATUS
EFIAPI
SmmSwDispatch2Register (
  IN  CONST EFI_SMM_SW_DISPATCH2_PROTOCOL  *This,
  IN        EFI_SMM_HANDLER_ENTRY_POINT2   DispatchFunction,
  IN  OUT   EFI_SMM_SW_REGISTER_CONTEXT    *RegContext,
  OUT       EFI_HANDLE                     *DispatchHandle
  )
{
  EFI_STATUS                                Status;
  UINTN                                     Index;
  EFI_SMM_SW_DISPATCH2_CONTEXT             *Context;

  if (RegContext->SwSmiInputValue == (UINTN)-1) {
    //
    // If SwSmiInputValue is set to (UINTN) -1 then a unique value
    // will be assigned and returned in the structure.
    //
    Status = EFI_NOT_FOUND;
    for (Index = 1; Index < MAXIMUM_SWI_VALUE; Index++) {
      Status = SmiInputValueCheck (Index);
      if (!EFI_ERROR (Status)) {
        RegContext->SwSmiInputValue = Index;
        break;
      }
    }
    if (RegContext->SwSmiInputValue == (UINTN)-1) {
      return EFI_OUT_OF_RESOURCES;
    }
  }

  if ((RegContext->SwSmiInputValue > MAXIMUM_SWI_VALUE) || (RegContext->SwSmiInputValue == 0)) {
    DEBUG ((DEBUG_ERROR, "ERROR: SMI value range (1 ~ 0x%x)\n", MAXIMUM_SWI_VALUE));
    return EFI_INVALID_PARAMETER;
  }

  //
  // Register
  //
  Status = gSmst->SmmAllocatePool (EfiRuntimeServicesData, sizeof(*Context), (VOID **)&Context);
  ASSERT_EFI_ERROR (Status);
  if (EFI_ERROR (Status)) {
    return EFI_OUT_OF_RESOURCES;
  }

  *DispatchHandle  = (EFI_HANDLE )Context;
  Context->Signature        = SMI_SW_HANDLER_SIGNATURE;
  Context->SwSmiInputValue  = RegContext->SwSmiInputValue;
  Context->DispatchFunction = (UINTN)DispatchFunction;
  Context->DispatchHandle   = *DispatchHandle;
  InsertTailList (&mSmmSwDispatch2Queue, &Context->Link);

  return Status;
}


/**
  Unregister a child SMI source dispatch function for the specified software SMI.

  This service removes the handler associated with DispatchHandle so that it will no longer be
  called in response to a software SMI.

  @param[in] This                Pointer to the EFI_SMM_SW_DISPATCH2_PROTOCOL instance.
  @param[in] DispatchHandle      Handle of dispatch function to deregister.

  @retval EFI_SUCCESS            The dispatch function has been successfully unregistered.
  @retval EFI_INVALID_PARAMETER  The DispatchHandle was not valid.
**/
EFI_STATUS
EFIAPI
SmmSwDispatch2UnRegister (
  IN CONST EFI_SMM_SW_DISPATCH2_PROTOCOL  *This,
  IN       EFI_HANDLE                     DispatchHandle
  )
{
  EFI_SMM_SW_DISPATCH2_CONTEXT            *Context;

  //
  // Unregister
  //
  Context = FindContextByDispatchHandle (DispatchHandle);
  ASSERT (Context != NULL);
  if (Context != NULL) {
    RemoveEntryList (&Context->Link);
    gSmst->SmmFreePool (Context);
  }

  return EFI_SUCCESS;
}


EFI_SMM_SW_DISPATCH2_PROTOCOL gSmmSwDispatch2 = {
  SmmSwDispatch2Register,
  SmmSwDispatch2UnRegister,
  MAXIMUM_SWI_VALUE
};

/**
  Entry Point for this driver.

  @param[in] ImageHandle  Image handle of this driver.
  @param[in] SystemTable  A Pointer to the EFI System Table.

  @retval EFI_SUCCESS  The entry point is executed successfully.
  @retval other        Some error occurred when executing this entry point.
**/
EFI_STATUS
EFIAPI
BlSmmSupport (
  IN EFI_HANDLE            ImageHandle,
  IN EFI_SYSTEM_TABLE      *SystemTable
  )
{
  EFI_STATUS               Status;
  EFI_HANDLE               DispatchHandle;

  //
  // Save SMM information to communication area.
  //
  SaveSmmInfo ();

  //
  // Locate PI SMM CPU protocol
  //
  Status = gSmst->SmmLocateProtocol (
                    &gEfiSmmCpuProtocolGuid,
                    NULL,
                    (VOID **)&mSmmCpuProtocol
                    );
  ASSERT_EFI_ERROR (Status);

  //
  // Register a callback function to handle subsequent SW SMIs.
  //
  Status = gSmst->SmiHandlerRegister ((EFI_MM_HANDLER_ENTRY_POINT)SmmSwDispatcher, NULL, &DispatchHandle);
  ASSERT_EFI_ERROR (Status);

  //
  // Publish PI SMM SwDispatch2 Protocol
  //
  ImageHandle = NULL;
  Status = gSmst->SmmInstallProtocolInterface (
                    &ImageHandle,
                    &gEfiSmmSwDispatch2ProtocolGuid,
                    EFI_NATIVE_INTERFACE,
                    &gSmmSwDispatch2
                    );
  ASSERT_EFI_ERROR (Status);

  return Status;
}

