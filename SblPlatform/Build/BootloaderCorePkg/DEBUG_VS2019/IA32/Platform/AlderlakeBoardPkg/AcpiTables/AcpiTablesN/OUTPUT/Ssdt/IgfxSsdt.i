#undef MIN
#undef MAX
/** @file
  This file contains the Intel Graphics SSDT Table ASL code.

  Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/
#include <AcpiDebug.h>

DefinitionBlock (
  "IgfxSsdt.aml",
  "SSDT",
  2,
  "INTEL ",
  "IgfxSsdt",
  0x3000
  )
{
  External(\_SB.PC00, DeviceObj)
  External(\_SB.PC00.MC, DeviceObj)
  External(\_SB.PC00.GFX0, DeviceObj)
  External(\NDID)
  External(\DID1)
  External(\DID2)
  External(\DID3)
  External(\DID4)
  External(\DID5)
  External(\DID6)
  External(\DID7)
  External(\DID8)
  External(\DID9)
  External(\DIDA)
  External(\DIDB)
  External(\DIDC)
  External(\DIDD)
  External(\DIDE)
  External(\DIDF)
  External(\DIDX)
  External(\DIDY)

  External(\NXD1)
  External(\NXD2)
  External(\NXD3)
  External(\NXD4)
  External(\NXD5)
  External(\NXD6)
  External(\NXD7)
  External(\NXD8)
  External(\NXDY)

  External(\IPTP)
  External(\EDPV)
  External(\NXDX)
  External(\HGMD)
  External(\LIDS)
  External(\BRTL)
  External(\NSTE)
  External(\CSTE)
  External(\ASLB)
  External(\IBTT)
  External(\IPSC)
  External(\IPAT)
  External(\IBIA)
  External(\IDMS)
  External(\HVCO)
  External(\ISSC)
  External(\KSV0)
  External(\KSV1)
  External(\IF1E)
  External(\PAVP)

  Scope (\_SB.PC00.GFX0)
  {
    /** @file
      This file contains the IGD OpRegion/Software ACPI Reference
      Code.
      It defines the methods to enable/disable output switching,
      store display switching and LCD brightness BIOS control
      and return valid addresses for all display device encoders
      present in the system, etc.
    
      Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
      SPDX-License-Identifier: BSD-2-Clause-Patent
    **/
    
    External(\PLD1, MethodObj)
    External(\PLD2, MethodObj)
    External(\ECST, MethodObj)
    External(\PBCL, MethodObj)
    External(HDOS, MethodObj)
    External(\ECON, IntObj)
    External(\PNHM, IntObj)
    External(OSYS, IntObj)
    External(CPSC)
    External(\GUAM, MethodObj)
    External(DSEN)
    External(S0ID)
    
    //
    // Default Physical Location of Device
    //
    Name (DPLD, Package (0x1) {
                 ToPLD (
                   PLD_Revision         = 0x2,
                   PLD_IgnoreColor      = 0x1,
                   PLD_Red              = 0x0,
                   PLD_Green            = 0x0,
                   PLD_Blue             = 0x0,
                   PLD_Width            = 0x320, //800 mm
                   PLD_Height           = 0x7D0, //2000 mm
                   PLD_UserVisible      = 0x1, //Set if the device connection point can be seen by the user without disassembly.
                   PLD_Dock             = 0x0, // Set if the device connection point resides in a docking station or port replicator.
                   PLD_Lid              = 0x0, // Set if this device connection point resides on the lid of laptop system.
                   PLD_Panel              = "TOP",    // Describes which panel surface of the systems housing the device connection point resides on.
                   PLD_VerticalPosition   = "CENTER", // Vertical Position on the panel where the device connection point resides.
                   PLD_HorizontalPosition = "RIGHT",  // Horizontal Position on the panel where the device connection point resides.
                   PLD_Shape              = "VERTICALRECTANGLE",
                   PLD_GroupOrientation = 0x0, // if Set, indicates vertical grouping, otherwise horizontal is assumed.
                   PLD_GroupToken       = 0x0, // Unique numerical value identifying a group.
                   PLD_GroupPosition    = 0x0, // Identifies this device connection points position in the group (i.e. 1st, 2nd)
                   PLD_Bay              = 0x0, // Set if describing a device in a bay or if device connection point is a bay.
                   PLD_Ejectable        = 0x0, // Set if the device is ejectable. Indicates ejectability in the absence of _EJx objects
                   PLD_EjectRequired    = 0x0, // OSPM Ejection required: Set if OSPM needs to be involved with ejection process. User-operated physical hardware ejection is not possible.
                   PLD_CabinetNumber    = 0x0, // For single cabinet system, this field is always 0.
                   PLD_CardCageNumber   = 0x0, // For single card cage system, this field is always 0.
                   PLD_Reference        = 0x0, // if Set, this _PLD defines a reference shape that is used to help orient the user with respect to the other shapes when rendering _PLDs.
                   PLD_Rotation         = 0x0, // 0 - 0deg, 1 - 45deg, 2 - 90deg, 3 - 135deg, 4 - 180deg, 5 - 225deg, 6 - 270deg, 7 - 315deg
                   PLD_Order            = 0x3, // Identifies the drawing order of the connection point described by a _PLD
                   PLD_VerticalOffset   = 0x0,
                   PLD_HorizontalOffset = 0x0
                  )
                } // Package
    ) //DPLD
    
    // Enable/Disable Output Switching.  In WIN2K/WINXP, _DOS = 0 will
    // get called during initialization to prepare for an ACPI Display
    // Switch Event.  During an ACPI Display Switch, the OS will call
    // _DOS = 2 immediately after a Notify=0x80 to temporarily disable
    // all Display Switching.  After ACPI Display Switching is complete,
    // the OS will call _DOS = 0 to re-enable ACPI Display Switching.
    Method(_DOS,1)
    {
      //
      // Store Display Switching and LCD brightness BIOS control bit
      //
      Store(And(Arg0,7),DSEN)
    
      If(LEqual(And(Arg0,  0x3), 0))     // If _DOS[1:0]=0
      {
        If(CondRefOf(HDOS))
        {
          HDOS()
        }
      }
    }
    
    //
    // Enumerate the Display Environment.  This method will return
    // valid addresses for all display device encoders present in the
    // system.  The Miniport Driver will reject the addresses for every
    // encoder that does not have an attached display device.  After
    // enumeration is complete, the OS will call the _DGS methods
    // during a display switch only for the addresses accepted by the
    // Miniport Driver.  For hot-insertion and removal of display
    // devices, a re-enumeration notification will be required so the
    // address of the newly present display device will be accepted by
    // the Miniport Driver.
    //
    Method(_DOD,0)
    {
      //
      // Two LFP devices are supporte by default
      //
      Store(2, NDID)
      If(LNotEqual(DIDL, Zero))
      {
        Store(SDDL(DIDL),DID1)
      }
      If(LNotEqual(DDL2, Zero))
      {
        Store(SDDL(DDL2),DID2)
      }
      If(LNotEqual(DDL3, Zero))
      {
        Store(SDDL(DDL3),DID3)
      }
      If(LNotEqual(DDL4, Zero))
      {
        Store(SDDL(DDL4),DID4)
      }
      If(LNotEqual(DDL5, Zero))
      {
        Store(SDDL(DDL5),DID5)
      }
      If(LNotEqual(DDL6, Zero))
      {
        Store(SDDL(DDL6),DID6)
      }
      If(LNotEqual(DDL7, Zero))
      {
        Store(SDDL(DDL7),DID7)
      }
      If(LNotEqual(DDL8, Zero))
      {
        Store(SDDL(DDL8),DID8)
      }
      If(LNotEqual(DDL9, Zero))
      {
        Store(SDDL(DDL9),DID9)
      }
      If(LNotEqual(DD10, Zero))
      {
        Store(SDDL(DD10),DIDA)
      }
      If(LNotEqual(DD11, Zero))
      {
        Store(SDDL(DD11),DIDB)
      }
      If(LNotEqual(DD12, Zero))
      {
        Store(SDDL(DD12),DIDC)
      }
      If(LNotEqual(DD13, Zero))
      {
        Store(SDDL(DD13),DIDD)
      }
      If(LNotEqual(DD14, Zero))
      {
        Store(SDDL(DD14),DIDE)
      }
      If(LNotEqual(DD15, Zero))
      {
        Store(SDDL(DD15),DIDF)
      }
    
      //
      // Enumerate the encoders. Note that for
      // current silicon, the maximum number of encoders
      // possible is 15.
      //
      If(LEqual(NDID,1))
      {
        Name(TMP1,Package() {
              0xFFFFFFFF})
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP1,0))
        } Else {
          Store(Or(0x10000,DID1),Index(TMP1,0))
        }
        Return(TMP1)
      }
    
      If(LEqual(NDID,2))
      {
        Name(TMP2,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP2,0))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP2,1))
        } Else {
          Store(Or(0x10000,DID2),Index(TMP2,1))
        }
        Return(TMP2)
      }
    
      If(LEqual(NDID,3))
      {
        Name(TMP3,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP3,0))
        Store(Or(0x10000,DID2),Index(TMP3,1))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP3,2))
        } Else {
          Store(Or(0x10000,DID3),Index(TMP3,2))
        }
        Return(TMP3)
      }
    
      If(LEqual(NDID,4))
      {
        Name(TMP4,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP4,0))
        Store(Or(0x10000,DID2),Index(TMP4,1))
        Store(Or(0x10000,DID3),Index(TMP4,2))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP4,3))
        } Else {
          Store(Or(0x10000,DID4),Index(TMP4,3))
        }
        Return(TMP4)
      }
    
      If(LEqual(NDID,5))
      {
        Name(TMP5,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP5,0))
        Store(Or(0x10000,DID2),Index(TMP5,1))
        Store(Or(0x10000,DID3),Index(TMP5,2))
        Store(Or(0x10000,DID4),Index(TMP5,3))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP5,4))
        } Else {
          Store(Or(0x10000,DID5),Index(TMP5,4))
        }
        Return(TMP5)
      }
    
      If(LEqual(NDID,6))
      {
        Name(TMP6,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP6,0))
        Store(Or(0x10000,DID2),Index(TMP6,1))
        Store(Or(0x10000,DID3),Index(TMP6,2))
        Store(Or(0x10000,DID4),Index(TMP6,3))
        Store(Or(0x10000,DID5),Index(TMP6,4))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP6,5))
        } Else {
          Store(Or(0x10000,DID6),Index(TMP6,5))
        }
        Return(TMP6)
      }
    
      If(LEqual(NDID,7))
      {
        Name(TMP7,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP7,0))
        Store(Or(0x10000,DID2),Index(TMP7,1))
        Store(Or(0x10000,DID3),Index(TMP7,2))
        Store(Or(0x10000,DID4),Index(TMP7,3))
        Store(Or(0x10000,DID5),Index(TMP7,4))
        Store(Or(0x10000,DID6),Index(TMP7,5))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP7,6))
        } Else {
          Store(Or(0x10000,DID7),Index(TMP7,6))
        }
        Return(TMP7)
      }
    
      If(LEqual(NDID,8))
      {
        Name(TMP8,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP8,0))
        Store(Or(0x10000,DID2),Index(TMP8,1))
        Store(Or(0x10000,DID3),Index(TMP8,2))
        Store(Or(0x10000,DID4),Index(TMP8,3))
        Store(Or(0x10000,DID5),Index(TMP8,4))
        Store(Or(0x10000,DID6),Index(TMP8,5))
        Store(Or(0x10000,DID7),Index(TMP8,6))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP8,7))
        } Else {
          Store(Or(0x10000,DID8),Index(TMP8,7))
        }
        Return(TMP8)
      }
    
      If(LEqual(NDID,9))
      {
        Name(TMP9,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMP9,0))
        Store(Or(0x10000,DID2),Index(TMP9,1))
        Store(Or(0x10000,DID3),Index(TMP9,2))
        Store(Or(0x10000,DID4),Index(TMP9,3))
        Store(Or(0x10000,DID5),Index(TMP9,4))
        Store(Or(0x10000,DID6),Index(TMP9,5))
        Store(Or(0x10000,DID7),Index(TMP9,6))
        Store(Or(0x10000,DID8),Index(TMP9,7))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMP9,8))
        } Else {
          Store(Or(0x10000,DID9),Index(TMP9,8))
        }
        Return(TMP9)
      }
    
      If(LEqual(NDID,0x0A))
      {
        Name(TMPA,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPA,0))
        Store(Or(0x10000,DID2),Index(TMPA,1))
        Store(Or(0x10000,DID3),Index(TMPA,2))
        Store(Or(0x10000,DID4),Index(TMPA,3))
        Store(Or(0x10000,DID5),Index(TMPA,4))
        Store(Or(0x10000,DID6),Index(TMPA,5))
        Store(Or(0x10000,DID7),Index(TMPA,6))
        Store(Or(0x10000,DID8),Index(TMPA,7))
        Store(Or(0x10000,DID9),Index(TMPA,8))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPA,9))
        } Else {
          Store(Or(0x10000,DIDA),Index(TMPA,9))
        }
        Return(TMPA)
      }
    
      If(LEqual(NDID,0x0B))
      {
        Name(TMPB,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPB,0))
        Store(Or(0x10000,DID2),Index(TMPB,1))
        Store(Or(0x10000,DID3),Index(TMPB,2))
        Store(Or(0x10000,DID4),Index(TMPB,3))
        Store(Or(0x10000,DID5),Index(TMPB,4))
        Store(Or(0x10000,DID6),Index(TMPB,5))
        Store(Or(0x10000,DID7),Index(TMPB,6))
        Store(Or(0x10000,DID8),Index(TMPB,7))
        Store(Or(0x10000,DID9),Index(TMPB,8))
        Store(Or(0x10000,DIDA),Index(TMPB,9))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPB,10))
        } Else {
          Store(Or(0x10000,DIDB),Index(TMPB,10))
        }
        Return(TMPB)
      }
    
      If(LEqual(NDID,0x0C))
      {
        Name(TMPC,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPC,0))
        Store(Or(0x10000,DID2),Index(TMPC,1))
        Store(Or(0x10000,DID3),Index(TMPC,2))
        Store(Or(0x10000,DID4),Index(TMPC,3))
        Store(Or(0x10000,DID5),Index(TMPC,4))
        Store(Or(0x10000,DID6),Index(TMPC,5))
        Store(Or(0x10000,DID7),Index(TMPC,6))
        Store(Or(0x10000,DID8),Index(TMPC,7))
        Store(Or(0x10000,DID9),Index(TMPC,8))
        Store(Or(0x10000,DIDA),Index(TMPC,9))
        Store(Or(0x10000,DIDB),Index(TMPC,10))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPC,11))
        } Else {
          Store(Or(0x10000,DIDC),Index(TMPC,11))
        }
        Return(TMPC)
      }
    
      If(LEqual(NDID,0x0D))
      {
        Name(TMPD,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPD,0))
        Store(Or(0x10000,DID2),Index(TMPD,1))
        Store(Or(0x10000,DID3),Index(TMPD,2))
        Store(Or(0x10000,DID4),Index(TMPD,3))
        Store(Or(0x10000,DID5),Index(TMPD,4))
        Store(Or(0x10000,DID6),Index(TMPD,5))
        Store(Or(0x10000,DID7),Index(TMPD,6))
        Store(Or(0x10000,DID8),Index(TMPD,7))
        Store(Or(0x10000,DID9),Index(TMPD,8))
        Store(Or(0x10000,DIDA),Index(TMPD,9))
        Store(Or(0x10000,DIDB),Index(TMPD,10))
        Store(Or(0x10000,DIDC),Index(TMPD,11))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPD,12))
        } Else {
          Store(Or(0x10000,DIDD),Index(TMPD,12))
        }
        Return(TMPD)
      }
    
      If(LEqual(NDID,0x0E))
      {
        Name(TMPE,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPE,0))
        Store(Or(0x10000,DID2),Index(TMPE,1))
        Store(Or(0x10000,DID3),Index(TMPE,2))
        Store(Or(0x10000,DID4),Index(TMPE,3))
        Store(Or(0x10000,DID5),Index(TMPE,4))
        Store(Or(0x10000,DID6),Index(TMPE,5))
        Store(Or(0x10000,DID7),Index(TMPE,6))
        Store(Or(0x10000,DID8),Index(TMPE,7))
        Store(Or(0x10000,DID9),Index(TMPE,8))
        Store(Or(0x10000,DIDA),Index(TMPE,9))
        Store(Or(0x10000,DIDB),Index(TMPE,10))
        Store(Or(0x10000,DIDC),Index(TMPE,11))
        Store(Or(0x10000,DIDD),Index(TMPE,12))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPE,13))
        } Else {
          Store(Or(0x10000,DIDE),Index(TMPE,13))
        }
        Return(TMPE)
      }
    
      If(LEqual(NDID,0x0F))
      {
        Name(TMPF,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPF,0))
        Store(Or(0x10000,DID2),Index(TMPF,1))
        Store(Or(0x10000,DID3),Index(TMPF,2))
        Store(Or(0x10000,DID4),Index(TMPF,3))
        Store(Or(0x10000,DID5),Index(TMPF,4))
        Store(Or(0x10000,DID6),Index(TMPF,5))
        Store(Or(0x10000,DID7),Index(TMPF,6))
        Store(Or(0x10000,DID8),Index(TMPF,7))
        Store(Or(0x10000,DID9),Index(TMPF,8))
        Store(Or(0x10000,DIDA),Index(TMPF,9))
        Store(Or(0x10000,DIDB),Index(TMPF,10))
        Store(Or(0x10000,DIDC),Index(TMPF,11))
        Store(Or(0x10000,DIDD),Index(TMPF,12))
        Store(Or(0x10000,DIDE),Index(TMPF,13))
        If (LEqual(IPTP,1)) {
          //
          // IGFX need report IPUA as GFX0 child
          //
          Store(0x00023480,Index(TMPF,14))
        } Else {
          Store(Or(0x10000,DIDF),Index(TMPF,14))
        }
        Return(TMPF)
      }
    
      If(LEqual(NDID,0x10))
      {
        Name(TMPG,Package() {
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF,
              0xFFFFFFFF})
        Store(Or(0x10000,DID1),Index(TMPG,0))
        Store(Or(0x10000,DID2),Index(TMPG,1))
        Store(Or(0x10000,DID3),Index(TMPG,2))
        Store(Or(0x10000,DID4),Index(TMPG,3))
        Store(Or(0x10000,DID5),Index(TMPG,4))
        Store(Or(0x10000,DID6),Index(TMPG,5))
        Store(Or(0x10000,DID7),Index(TMPG,6))
        Store(Or(0x10000,DID8),Index(TMPG,7))
        Store(Or(0x10000,DID9),Index(TMPG,8))
        Store(Or(0x10000,DIDA),Index(TMPG,9))
        Store(Or(0x10000,DIDB),Index(TMPG,10))
        Store(Or(0x10000,DIDC),Index(TMPG,11))
        Store(Or(0x10000,DIDD),Index(TMPG,12))
        Store(Or(0x10000,DIDE),Index(TMPG,13))
        Store(Or(0x10000,DIDF),Index(TMPG,14))
        //
        // IGFX need report IPUA as GFX0 child
        // NDID can only be 0x10 if IPU is enabled
        //
        Store(0x00023480,Index(TMPG,15))
        Return(TMPG)
      }
    
      //
      // If nothing else, return Unknown LFP.
      // (Prevents compiler warning.)
      //
      Return(Package() {0x00000400})
    }
    
    Device(DD01)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID1),0x400))
        {
          Store(0x1, EDPV)
          Store(NXD1, NXDX)
          Store(DID1, DIDX)
          Return(1)
        }
        If(LEqual(DID1,0))
        {
          Return(1)
        }
        Else
        {
          Return(And(0xFFFF,DID1))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        Return(CDDS(DID1))
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD1)
        }
        Return(NDDS(DID1))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD02)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID2),0x400))
        {
          If(LEqual(And(0xF,DID2),0x1))
          {
            Store(0x2, EDPV)
            Store(NXD2, NXDY)
            Store(DID2, DIDY)
            Return(2)
          }
          Store(0x2, EDPV)
          Store(NXD2, NXDX)
          Store(DID2, DIDX)
          Return(2)
        }
        If(LEqual(DID2,0))
        {
          Return(2)
        }
        Else
        {
          Return(And(0xFFFF,DID2))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(LIDS,0))
        {
          Return(0x0)
        }
        Return(CDDS(DID2))
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        //
        // Return the Next State.
        //
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD2)
        }
        Return(NDDS(DID2))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD03)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID3),0x400))
        {
          Store(0x3, EDPV)
          Store(NXD3, NXDX)
          Store(DID3, DIDX)
          Return(3)
        }
        If(LEqual(DID3,0))
        {
          Return(3)
        }
        Else
        {
        Return(And(0xFFFF,DID3))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID3,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID3))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD3)
        }
        Return(NDDS(DID3))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD04)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID4),0x400))
        {
          Store(0x4, EDPV)
          Store(NXD4, NXDX)
          Store(DID4, DIDX)
          Return(4)
        }
        If(LEqual(DID4,0))
        {
          Return(4)
        }
        Else
        {
          Return(And(0xFFFF,DID4))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID4,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID4))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD4)
        }
        Return(NDDS(DID4))
      }
    
      //
      // Device Set State. (See table above.)
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD05)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID5),0x400))
        {
          Store(0x5, EDPV)
          Store(NXD5, NXDX)
          Store(DID5, DIDX)
          Return(5)
        }
        If(LEqual(DID5,0))
        {
          Return(5)
        }
        Else
        {
          Return(And(0xFFFF,DID5))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID5,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID5))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD5)
        }
        Return(NDDS(DID5))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD06)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID6),0x400))
        {
          Store(0x6, EDPV)
          Store(NXD6, NXDX)
          Store(DID6, DIDX)
          Return(6)
        }
        If(LEqual(DID6,0))
        {
          Return(6)
        }
        Else
        {
          Return(And(0xFFFF,DID6))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID6,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID6))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD6)
        }
        Return(NDDS(DID6))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD07)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID7),0x400))
        {
          Store(0x7, EDPV)
          Store(NXD7, NXDX)
          Store(DID7, DIDX)
          Return(7)
        }
        If(LEqual(DID7,0))
        {
          Return(7)
        }
        Else
        {
          Return(And(0xFFFF,DID7))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID7,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID7))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD7)
        }
        Return(NDDS(DID7))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD08)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID8),0x400))
        {
          Store(0x8, EDPV)
          Store(NXD8, NXDX)
          Store(DID8, DIDX)
          Return(8)
        }
        If(LEqual(DID8,0))
        {
          Return(8)
        }
        Else
        {
          Return(And(0xFFFF,DID8))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID8,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID8))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DID8))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD09)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DID9),0x400))
        {
          Store(0x9, EDPV)
          Store(NXD8, NXDX)
          Store(DID9, DIDX)
          Return(9)
        }
        If(LEqual(DID9,0))
        {
          Return(9)
        }
        Else
        {
          Return(And(0xFFFF,DID9))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DID9,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DID9))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DID9))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0A)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDA),0x400))
        {
          Store(0xA, EDPV)
          Store(NXD8, NXDX)
          Store(DIDA, DIDX)
          Return(0x0A)
        }
        If(LEqual(DIDA,0))
        {
          Return(0x0A)
        }
        Else
        {
          Return(And(0xFFFF,DIDA))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDA,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DIDA))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDA))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0B)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDB),0x400))
        {
          Store(0xB, EDPV)
          Store(NXD8, NXDX)
          Store(DIDB, DIDX)
          Return(0X0B)
        }
        If(LEqual(DIDB,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(And(0xFFFF,DIDB))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDB,0))
        {
          Return(0x0B)
        }
        Else
        {
          Return(CDDS(DIDB))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDB))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0C)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDC),0x400))
        {
          Store(0xC, EDPV)
          Store(NXD8, NXDX)
          Store(DIDC, DIDX)
          Return(0X0C)
        }
        If(LEqual(DIDC,0))
        {
          Return(0x0C)
        }
        Else
        {
          Return(And(0xFFFF,DIDC))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDC,0))
        {
          Return(0x0C)
        }
        Else
        {
          Return(CDDS(DIDC))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDC))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0D)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDD),0x400))
        {
          Store(0xD, EDPV)
          Store(NXD8, NXDX)
          Store(DIDD, DIDX)
          Return(0X0D)
        }
        If(LEqual(DIDD,0))
        {
          Return(0x0D)
        }
        Else
        {
          Return(And(0xFFFF,DIDD))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDD,0))
        {
          Return(0x0D)
        }
        Else
        {
          Return(CDDS(DIDD))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDD))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0E)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDE),0x400))
        {
          Store(0xE, EDPV)
          Store(NXD8, NXDX)
          Store(DIDE, DIDX)
          Return(0X0E)
        }
        If(LEqual(DIDE,0))
        {
          Return(0x0E)
        }
        Else
        {
          Return(And(0xFFFF,DIDE))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDE,0))
        {
          Return(0x0E)
        }
        Else
        {
          Return(CDDS(DIDE))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDE))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    Device(DD0F)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(And(0x0F00,DIDF),0x400))
        {
          Store(0xF, EDPV)
          Store(NXD8, NXDX)
          Store(DIDF, DIDX)
          Return(0X0F)
        }
        If(LEqual(DIDF,0))
        {
          Return(0x0F)
        }
        Else
        {
          Return(And(0xFFFF,DIDF))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(DIDC,0))
        {
          Return(0x0F)
        }
        Else
        {
          Return(CDDS(DIDF))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXD8)
        }
        Return(NDDS(DIDF))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    }
    
    //
    //Device for eDP
    //
    Device(DD1F)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(EDPV, 0x0))
        {
          Return(0x1F)
        }
        Else
        {
          Return(And(0xFFFF,DIDX))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(EDPV, 0x0))
        {
          Return(0x00)
        }
        Else
        {
          Return(CDDS(DIDX))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXDX)
        }
        Return(NDDS(DIDX))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    
      //
      // Query List of Brightness Control Levels Supported.
      //
      Method(_BCL,0)
      {
        //
        // List of supported brightness levels in the following sequence.
        // Level when machine has full power.
        // Level when machine is on batteries.
        // Other supported levels.
        //
        If(CondRefOf(\PBCL)) {
          Return (PBCL())
        } Else {
          Return(Package(){80, 50, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100})
        }
      }
    
      //
      // Set the Brightness Level.
      //
      Method (_BCM,1)
      {
        //
        // Set the requested level if it is between 0 and 100%.
        //
        If(LAnd(LGreaterEqual(Arg0,0),LLessEqual(Arg0,100)))
        {
          \_SB.PC00.GFX0.AINT(1, Arg0)
          Store(Arg0,BRTL)  // Store Brightness Level.
        }
      }
    
      //
      // Brightness Query Current level.
      //
      Method (_BQC,0)
      {
        Return(BRTL)
      }
    
      //
      // Physical Location of Device
      //
      Method (_PLD,0)
      {
        If(CondRefOf(\PLD1)) {
          Return (PLD1())
        } Else {
          Return (DPLD)
        }
      }
    }
    
    //
    // Second Display
    //
    Device(DD2F)
    {
      //
      // Return Unique ID.
      //
      Method(_ADR,0,Serialized)
      {
        If(LEqual(EDPV, 0x0))
        {
          Return(0x1F)
        }
        If(LEqual(EDPV, 0x1))
        {
          Return(0x1F)
        }
        Else
        {
          Return(And(0xFFFF,DIDY))
        }
      }
    
      //
      // Return the Current Status.
      //
      Method(_DCS,0)
      {
        If(LEqual(EDPV, 0x0))
        {
          Return(0x00)
        }
        If(LEqual(EDPV, 0x1))
        {
          Return(0x0)
        }
        Else
        {
          Return(CDDS(DIDY))
        }
      }
    
      //
      // Query Graphics State (active or inactive).
      //
      Method(_DGS,0)
      {
        If(LAnd(LEqual(And(HGMD,0x7F),0x01),CondRefOf(SNXD)))
        {
          Return (NXDY)
        }
        Return(NDDS(DIDY))
      }
    
      //
      // Device Set State.
      //
      Method(_DSS,1)
      {
        DSST(Arg0)
      }
    
      //
      // Query List of Brightness Control Levels Supported.
      //
      Method(_BCL,0)
      {
        //
        // List of supported brightness levels in the following sequence.
        // Level when machine has full power.
        // Level when machine is on batteries.
        // Other supported levels.
        //
        If(CondRefOf(\PBCL)) {
          Return (PBCL())
        } Else {
          Return(Package(){80, 50, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100})
        }
      }
    
      //
      // Set the Brightness Level.
      //
      Method (_BCM,1)
      {
        //
        // Set the requested level if it is between 0 and 100%.
        //
        If(LAnd(LGreaterEqual(Arg0,0),LLessEqual(Arg0,100)))
        {
          \_SB.PC00.GFX0.AINT(1, Arg0)
          Store(Arg0,BRTL)  // Store Brightness Level.
        }
      }
    
      //
      // Brightness Query Current level.
      //
      Method (_BQC,0)
      {
        Return(BRTL)
      }
    
      Method (_PLD,0)
      {
        If(CondRefOf(\PLD2)) {
          Return (PLD2())
        } Else {
          Return (DPLD)
        }
      }
    }
    
    Method(SDDL,1)
    {
      Increment(NDID)
      Store(And(Arg0,0xF0F),Local0)
      Or(0x80000000,Local0, Local1)
      If(LEqual(DIDL,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL2,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL3,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL4,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL5,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL6,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL7,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL8,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DDL9,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD10,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD11,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD12,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD13,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD14,Local0))
      {
        Return(Local1)
      }
      If(LEqual(DD15,Local0))
      {
        Return(Local1)
      }
      Return(0)
    }
    
    Method(CDDS,1)
    {
      Store(And(Arg0,0xF0F),Local0)
    
      If(LEqual(0, Local0))
      {
        Return(0x1D)
      }
      If(LEqual(CADL, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL2, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL3, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL4, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL5, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL6, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL7, Local0))
      {
        Return(0x1F)
      }
      If(LEqual(CAL8, Local0))
      {
        Return(0x1F)
      }
      Return(0x1D)
    }
    
    Method(NDDS,1)
    {
      Store(And(Arg0,0xF0F),Local0)
    
      If(LEqual(0, Local0))
      {
        Return(0)
      }
      If(LEqual(NADL, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL2, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL3, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL4, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL5, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL6, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL7, Local0))
      {
        Return(1)
      }
      If(LEqual(NDL8, Local0))
      {
        Return(1)
      }
      Return(0)
    }
    
    //
    // Device Set State Table
    //  BIT31  BIT30  Execution
    //  0  0  Don't implement.
    //  0  1  Cache change.  Nothing to Implement.
    //  1  0  Don't Implement.
    //  1  1  Display Switch Complete.  Implement.
    //
    Method(DSST,1)
    {
      If(LEqual(And(Arg0,0xC0000000),0xC0000000))
      {
        //
        // State change was performed by the
        // Video Drivers.  Simply update the
        // New State.
        //
        Store(NSTE,CSTE)
      }
    }
    
    //
    // Include IGD OpRegion/Software SCI interrupt handler/DSM which is used by
    // the graphics drivers to request data from system BIOS.
    //
    /** @file
      IGD OpRegion/Software SCI Reference Code.
      This file contains the interrupt handler code for the Integrated
      Graphics Device (IGD) OpRegion/Software SCI mechanism.
      It defines OperationRegions to cover the IGD PCI configuration space
      as described in the IGD OpRegion specification.
    
      Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
      SPDX-License-Identifier: BSD-2-Clause-Patent
    **/
    //
    //NOTES:
    //
    // (1) The code contained in this file inherits the scope in which it
    //     was included.  So BIOS developers must be sure to include this
    //     file in the scope associated with the graphics device
    //     (ex. \_SB.PC00.GFX0).
    // (2) Create a _L06 method under the GPE scope to handle the event
    //     generated by the graphics driver.  The _L06 method must call
    //     the GSCI method in this file.
    // (3) The MCHP operation region assumes that _ADR and _BBN names
    //     corresponding to bus 0, device0, function 0 have been declared
    //     under the PC00 scope.
    // (4) Before the first execution of the GSCI method, the base address
    //     of the GMCH SCI OpRegion must be programmed where the driver can
    //     access it. A 32bit scratch register at 0xFC in the IGD PCI
    //     configuration space (B0/D2/F0/R0FCh) is used for this purpose.
    
    //  Define an OperationRegion to cover the GMCH PCI configuration space as
    //  described in the IGD OpRegion specificiation.
    //
    Scope(\_SB.PC00.MC)
    {
      OperationRegion(MCHP, PCI_Config, 0x40, 0xC0)
      Field(MCHP, AnyAcc, NoLock, Preserve)
      {
        Offset(0x14),
        AUDE, 8,
    
        Offset(0x60), // Top of Memory register
        TASM, 10,     // Total system memory (64MB gran)
            , 6,
      }
    }
    
    //
    //  Define an OperationRegion to cover the IGD PCI configuration space as
    //  described in the IGD OpRegion specificiation.
    //
    OperationRegion(IGDP, PCI_Config, 0x40, 0xC0)
    Field(IGDP, AnyAcc, NoLock, Preserve)
    {
      Offset(0x10), // Mirror of gfx control reg
          , 1,
      GIVD, 1,      // IGD VGA disable bit
          , 2,
      GUMA, 3,      // Stolen memory size
          , 9,
      Offset(0x14),
          , 4,
      GMFN, 1,      // Gfx function 1 enable
          , 27,
      Offset(0xA4),
      ASLE, 8,      // Reg 0xE4, ASLE interrupt register
          , 24,     // Only use first byte of ASLE reg
      Offset(0xA8), // Reg 0xE8, SWSCI control register
      GSSE, 1,      // Graphics SCI event (1=event pending)
      GSSB, 14,     // Graphics SCI scratchpad bits
      GSES, 1,      // Graphics event select (1=SCI)
      Offset(0xB0), // Gfx Clk Frequency and Gating Control
          , 12,
      CDVL, 1,      // Core display clock value
          , 3,      // Graphics Core Display Clock Select
      Offset(0xB5),
      LBPC, 8,      // Legacy brightness control
      Offset(0xBC),
      ASLS, 32,     // Reg 0xFC, Address of the IGD OpRegion
    }
    
    //
    //  Define an OperationRegion to cover the IGD OpRegion layout.
    //
    OperationRegion(IGDM, SystemMemory, ASLB, 0x2000)
    Field(IGDM, AnyAcc, NoLock, Preserve)
    {
      //
      // OpRegion Header
      //
      SIGN, 128,     // Signature-"IntelGraphicsMem"
      SIZE, 32,      // OpRegion Size
      OVER, 32,      // OpRegion Version
      SVER, 256,     // System BIOS Version
      VVER, 128,     // VBIOS Version
      GVER, 128,     // Driver version
      MBOX, 32,      // Mailboxes supported
      DMOD, 32,      // Driver Model
      PCON, 32,      // Platform Configuration
      DVER, 64,      // GOP Version
      //
      // OpRegion Mailbox 1 (Public ACPI Methods)
      // Note: Mailbox 1 is normally reserved for desktop platforms.
      //
      Offset(0x100),
      DRDY, 32,      // Driver readiness (ACPI notification)
      CSTS, 32,      // Notification status
      CEVT, 32,      // Current event
      Offset(0x120),
      DIDL, 32,      // Supported display device ID list
      DDL2, 32,      // Allows for 8 devices
      DDL3, 32,
      DDL4, 32,
      DDL5, 32,
      DDL6, 32,
      DDL7, 32,
      DDL8, 32,
      CPDL, 32,      // Currently present display list
      CPL2, 32,      // Allows for 8 devices
      CPL3, 32,
      CPL4, 32,
      CPL5, 32,
      CPL6, 32,
      CPL7, 32,
      CPL8, 32,
      CADL, 32,      // Currently active display list
      CAL2, 32,      // Allows for 8 devices
      CAL3, 32,
      CAL4, 32,
      CAL5, 32,
      CAL6, 32,
      CAL7, 32,
      CAL8, 32,
      NADL, 32,      // Next active display list
      NDL2, 32,      // Allows for 8 devices
      NDL3, 32,
      NDL4, 32,
      NDL5, 32,
      NDL6, 32,
      NDL7, 32,
      NDL8, 32,
      ASLP, 32,      // ASL sleep timeout
      TIDX, 32,      // Toggle table index
      CHPD, 32,      // Current hot plug enable indicator
      CLID, 32,      // Current lid state indicator
      CDCK, 32,      // Current docking state indicator
      SXSW, 32,      // Display switch notify on resume
      EVTS, 32,      // Events supported by ASL (diag only)
      CNOT, 32,      // Current OS notifications (diag only)
      NRDY, 32,
      //
      //Extended DIDL list
      //
      DDL9, 32,
      DD10, 32,
      DD11, 32,
      DD12, 32,
      DD13, 32,
      DD14, 32,
      DD15, 32,
      //
      //Extended Currently attached Display Device List  CPD2
      //
      CPL9, 32,
      CP10, 32,
      CP11, 32,
      CP12, 32,
      CP13, 32,
      CP14, 32,
      CP15, 32,
      //
      // OpRegion Mailbox 2 (Software SCI Interface)
      //
      Offset(0x200), // SCIC
      SCIE, 1,       // SCI entry bit (1=call unserviced)
      GEFC, 4,       // Entry function code
      GXFC, 3,       // Exit result
      GESF, 8,       // Entry/exit sub-function/parameter
          , 16,      // SCIC[31:16] reserved
      Offset(0x204), // PARM
      PARM, 32,      // PARM register (extra parameters)
      DSLP,  32,     // Driver sleep time out
      //
      // OpRegion Mailbox 3 (BIOS to Driver Notification)
      // Note: Mailbox 3 is normally reserved for desktop platforms.
      //
      Offset(0x300),
      ARDY, 32,      // Driver readiness (power conservation)
      ASLC, 32,      // ASLE interrupt command/status
      TCHE, 32,      // Technology enabled indicator
      ALSI, 32,      // Current ALS illuminance reading
      BCLP, 32,      // Backlight brightness
      PFIT, 32,      // Panel fitting state or request
      CBLV, 32,      // Current brightness level
      BCLM, 320,     // Backlight brightness level duty cycle mapping table
      CPFM, 32,      // Current panel fitting mode
      EPFM, 32,      // Enabled panel fitting modes
      PLUT, 592,     // Optional. 74-byte Panel LUT Table
      PFMB, 32,      // Optional. PWM Frequency and Minimum Brightness
      CCDV, 32,      // Optional. Gamma, Brightness, Contrast values.
      PCFT, 32,      // Optional. Power Conservation Features
      SROT, 32,      // Supported rotation angle.
      IUER, 32,      // Optional. Intel Ultrabook Event Register.
      FDSS, 64,      // Optional. FFS Display Physical address
      FDSP, 32,      // Optional. FFS Display Size
      STAT, 32,      // State Indicator
      RVDA, 64,      // Physical address of Raw VBT data
      RVDS, 32,      // Size of Raw VBT data
      //
      // OpRegion Mailbox 4 (VBT)
      //
      Offset(0x400),
      RVBT, 0xC000,  // 6K bytes maximum VBT image
      //
      // OpRegion Mailbox 5 (BIOS to Driver Notification Extension)
      //
      Offset(0x1C00),
      PHED, 32,      // Panel Header
      BDDC, 2048,    // Panel EDID (Max 256 bytes)
    
    }
    
    //
    // Convert boot display type into a port mask.
    //
    Name (DBTB, Package()
    {
      0x0000,        // Automatic
      0x0007,        // Port-0 : Integrated CRT
      0x0038,        // Port-1 : DVO-A, or Integrated LVDS
      0x01C0,        // Port-2 : SDVO-B, or SDVO-B/C
      0x0E00,        // Port-3 : SDVO-C
      0x003F,        // [CRT + DVO-A / Integrated LVDS]
      0x01C7,        // [CRT + SDVO-B] or [CRT + SDVO-B/C]
      0x0E07,        // [CRT + SDVO-C]
      0x01F8,        // [DVO-A / Integrated LVDS + SDVO-B]
      0x0E38,        // [DVO-A / Integrated LVDS + SDVO-C]
      0x0FC0,        // [SDVO-B + SDVO-C]
      0x0000,        // Reserved
      0x0000,        // Reserved
      0x0000,        // Reserved
      0x0000,        // Reserved
      0x0000,        // Reserved
      0x7000,        // Port-4: Integrated TV
      0x7007,        // [Integrated TV + CRT]
      0x7038,        // [Integrated TV + LVDS]
      0x71C0,        // [Integrated TV + DVOB]
      0x7E00         // [Integrated TV + DVOC]
    })
    
    //
    // Core display clock value table.
    //
    Name (CDCT, Package()
    {
      Package() {228, 320},
      Package() {222, 333},
      Package() {222, 333},
      Package() {  0,   0},
      Package() {222, 333},
    })
    
    //
    // Defined exit result values:
    //
    Name (SUCC, 1)   // Exit result: Success
    Name (NVLD, 2)   // Exit result: Invalid parameter
    Name (CRIT, 4)   // Exit result: Critical failure
    Name (NCRT, 6)   // Exit result: Non-critical failure
    
    /************************************************************************;
    ;*
    ;* Name: GSCI
    ;*
    ;* Description: Handles an SCI generated by the graphics driver.  The
    ;*              PARM and SCIC input fields are parsed to determine the
    ;*              functionality requested by the driver.  GBDA or SBCB
    ;*              is called based on the input data in SCIC.
    ;*
    ;* Usage:       The method must be called in response to a GPE 06 event
    ;*              which will be generated by the graphics driver.
    ;*              Ex: Method(\_GPE._L06) {Return(\_SB.PC00.GFX0.GSCI())}
    ;*
    ;* Input:       PARM and SCIC are indirect inputs
    ;*
    ;* Output:      PARM and SIC are indirect outputs
    ;*
    ;* References:  GBDA (Get BIOS Data method), SBCB (System BIOS Callback
    ;*              method)
    ;*
    ;************************************************************************/
    
    Method (GSCI, 0, Serialized)
    {
      /** @file
        IGD OpRegion/Software SCI Reference Code.
        This file contains Get BIOS Data Area funciton support for
        the Integrated Graphics Device (IGD) OpRegion/Software SCI mechanism
      
        Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
        SPDX-License-Identifier: BSD-2-Clause-Patent
      **/
      Method (GBDA, 0, Serialized)
      {
        //
        // Supported calls: Sub-function 0
        //
        If (LEqual(GESF, 0))
        {
          //
          //<NOTE> Reference code is set to Intel's validated implementation.
          //
          Store(0x0000659, PARM)
          Store(Zero, GESF) // Clear the exit parameter
          Return(SUCC) // Success
        }
        //
        // Requested callbacks: Sub-function 1
        //
        If (LEqual(GESF, 1))
        {
          //
          //<NOTE> Call back functions are where the driver calls the
          // system BIOS at function indicated event.
          //
          Store(0x300482, PARM)
          If(LEqual(S0ID, One)){
            Or(PARM, 0x100, PARM) //Request Fn 8 callback in CS systems
          }
          Store(Zero, GESF) // Clear the exit parameter
          Return(SUCC) // Success
        }
        //
        // Get Boot display Preferences: Sub-function 4
        //
        If (LEqual(GESF, 4))
        {
          //
          //<NOTE> Get Boot Display Preferences function.
          //
          And(PARM, 0xEFFF0000, PARM) // PARM[30:16] = Boot device ports
          And(PARM, ShiftLeft(DeRefOf(Index(DBTB, IBTT)), 16), PARM)
          Or(IBTT, PARM, PARM) // PARM[7:0] = Boot device type
          Store(Zero, GESF) // Clear the exit parameter
          Return(SUCC) // Success
        }
        //
        // Panel details: Sub-function 5
        //
        If (LEqual(GESF, 5))
        {
          //
          //<NOTE> Get Panel Details function.
          //
          Store(IPSC, PARM) // Report the scaling setting
          Or(PARM, ShiftLeft(IPAT, 8), PARM)
          Add(PARM, 0x100, PARM) // Adjust panel type, 0 = VBT default
          Or(PARM, ShiftLeft(LIDS, 16), PARM) // Report the lid state
          Add(PARM, 0x10000, PARM) // Adjust the lid state, 0 = Unknown
          Or(PARM, ShiftLeft(IBIA, 20), PARM) // Report the BIA setting
          Store(Zero, GESF)
          Return(SUCC)
        }
        //
        // Internal graphics: Sub-function 7
        //
        If (LEqual(GESF, 7))
        {
          Store(GIVD, PARM) // PARM[0]      - VGA mode(1=VGA)
          Xor(PARM, 1, PARM) // Invert the VGA mode polarity
          Or(PARM, ShiftLeft(GMFN, 1), PARM) // PARM[1]   - # IGD PCI functions-1
                                             // PARM[3:2]    - Reserved
                                             // PARM[4]      - IGD D3 support(0=cold)
                                             // PARM[10:5]   - Reserved
          Or(PARM, ShiftLeft(3, 11), PARM) // PARM[12:11] - DVMT mode(11b = 5.0)
      
          //
          // Report DVMT 5.0 Total Graphics memory size.
          //
          Or(PARM, ShiftLeft(IDMS, 17), PARM) // Bits 20:17 are for Gfx total memory size
          //
          // If the "Set Internal Graphics" call is supported, the modified
          // settings flag must be programmed per the specification.  This means
          // that the flag must be set to indicate that system BIOS requests
          // these settings.  Once "Set Internal Graphics" is called, the
          //  modified settings flag must be cleared on all subsequent calls to
          // this function.
          // Report the graphics frequency based on B0:D2:F0:RF0h[12].  Must
          // take into account the current VCO.
          //
          Or(ShiftLeft(Derefof(Index(Derefof(Index(CDCT, HVCO)), CDVL)), 21),PARM, PARM)
          Store(1, GESF) // Set the modified settings flag
          Return(SUCC)
        }
        //
        // Spread spectrum clocks: Sub-function 10
        //
        If (LEqual(GESF, 10))
        {
          Store(0, PARM) // Assume SSC is disabled
          If(ISSC)
          {
            Or(PARM, 3, PARM) // If SSC enabled, return SSC1+Enabled
          }
          Store(0, GESF) // Set the modified settings flag
          Return(SUCC) // Success
        }
      
        If (LEqual(GESF, 11))
        {
          Store(KSV0, PARM) // First four bytes of AKSV
          Store(KSV1, GESF) // Fifth byte of AKSV
      
          Return(SUCC) // Success
        }
        //
        // A call to a reserved "Get BIOS data" function was received.
        //
        Store(Zero, GESF) // Clear the exit parameter
        Return(CRIT) // Reserved, "Critical failure"
      }

      /** @file
        This file contains the system BIOS call back functionality for the
        OpRegion/Software SCI mechanism.
      
        Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
        SPDX-License-Identifier: BSD-2-Clause-Patent
      **/
      
      Method (SBCB, 0, Serialized)
      {
        //
        // Supported Callbacks: Sub-function 0
        //
        If (LEqual(GESF, 0x0))
        {
          //
          //<NOTE> An OEM may support the driver->SBIOS status callbacks, but
          // the supported callbacks value must be modified.  The code that is
          // executed upon reception of the callbacks must be also be updated
          // to perform the desired functionality.
          //
          Store(0x00000000, PARM)   // No callbacks supported
          //Store(0x000787FD, PARM) // Used for Intel test implementaion
          Store(0x000F87DD, PARM)
          Store(Zero, GESF)         // Clear the exit parameter
          Return(SUCC)              // "Success"
        }
        //
        // BIOS POST Completion: Sub-function 1
        //
        If (LEqual(GESF, 1))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Pre-Hires Set Mode: Sub-function 3
        //
        If (LEqual(GESF, 3))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Post-Hires Set Mode: Sub-function 4
        //
        If (LEqual(GESF, 4))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Display Switch: Sub-function 5
        //
        If (LEqual(GESF, 5))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Adapter Power State: Sub-function 7
        //
        If (LEqual(GESF, 7))
        {
          //
          // Handle Low Power S0 Idle Capability if enabled
          //
          If(LAnd(LEqual(S0ID, 1),LLess(OSYS, 2015))) {
            //
            // Call GUAM to trigger CS Entry
            //   If Adapter Power State Notification = D1 (PARM[7:0]=0x01)
            //
            If (LEqual (And(PARM,0xFF), 0x01)) {
              // GUAM - Global User Absent Mode Notification Method
              \GUAM(One) // 0x01 - Power State Standby (CS Entry)
            }
            If (LEqual (And(PARM,0xFF), 0x00)) {
              // GUAM - Global User Absent Mode Notification Method
              \GUAM(0)
            }
          }
          //
          // Upon notification from driver that the Adapter Power State = D0,
          // check if previous lid event failed.  If it did, retry the lid
          // event here.
          //
          If(LEqual(PARM, 0))
          {
            Store(CLID, Local0)
            If(And(0x80000000,Local0))
            {
              And(CLID, 0x0000000F, CLID)
              GLID(CLID)
            }
          }
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Display Power State: Sub-function 8
        //
        If (LEqual(GESF, 8))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // Set Boot Display: Sub-function 9
        //
        If (LEqual(GESF, 9))
        {
          //
          //<NOTE> An OEM may elect to implement this method.  In that case,
          // the input values must be saved into non-volatile storage for
          // parsing during the next boot.  The following Sample code is Intel
          // validated implementation.
          //
          And(PARM, 0xFF, IBTT) // Save the boot display to NVS
          Store(Zero, GESF)     // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)          // Reserved, "Critical failure"
        }
        //
        // Set Panel Details: Sub-function 10 (0Ah)
        //
        If (LEqual(GESF, 10))
        {
          //
          //<NOTE> An OEM may elect to implement this method.  In that case,
          // the input values must be saved into non-volatile storage for
          // parsing during the next boot.  The following Sample code is Intel
          // validated implementation.
          // Set the panel-related NVRAM variables based the input from the driver.
          //
          And(PARM, 0xFF, IPSC)
          //
          // Change panel type if a change is requested by the driver (Change if
          // panel type input is non-zero).  Zero=No change requested.
          //
          If(And(ShiftRight(PARM, 8), 0xFF))
          {
            And(ShiftRight(PARM, 8), 0xFF, IPAT)
            Decrement(IPAT)    // 0 = no change, so fit to CMOS map
          }
          And(ShiftRight(PARM, 20), 0x7, IBIA)
          Store(Zero, GESF)    // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)         // Success
        }
        //
        // Set Internal Graphics: Sub-function 11 (0Bh)
        //
        If (LEqual(GESF, 11))
        {
          //
          //<NOTE> An OEM may elect to implement this method.  In that case,
          // the input values must be saved into non-volatile storage for
          // parsing during the next boot.  The following Sample code is Intel
          // validated implementation.
          //
          And(ShiftRight(PARM, 1), 1, IF1E)      // Program the function 1 option
          If(And(PARM, ShiftLeft(0xF, 13)))      // Use fixed memory if fixed size != 0
          {
            //
            // Fixed memory
            //
            And(ShiftRight(PARM, 13), 0xF, IDMS) // Program fixed memory size
          }
          Else
          {
            //
            // DVMT memory
            //
            And(ShiftRight(PARM, 17), 0xF, IDMS) // Program fixed memory size
          }
          Store(Zero, GESF)                      // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)                           // Success
        }
        //
        // Post-Hires to DOS FS: Sub-function 16 (10h)
        //
        If (LEqual(GESF, 16))
        {
          Store(Zero, GESF) // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)      // Not supported, but no failure
        }
        //
        // APM Complete:  Sub-function 17 (11h)
        //
        If (LEqual(GESF, 17))
        {
          Store(ShiftLeft(LIDS, 8), PARM) // Report the lid state
          Add(PARM, 0x100, PARM)          // Adjust the lid state, 0 = Unknown
          Store(Zero, GESF)               // Clear the exit parameter
          Return(SUCC)                    // Not supported, but no failure
        }
        //
        // Set Spread Spectrum Clocks: Sub-function 18 (12h)
        //
        If (LEqual(GESF, 18))
        {
          //
          //<NOTE> An OEM may elect to implement this method.  In that case,
          // the input values must be saved into non-volatile storage for
          // parsing during the next boot.  The following Sample code is Intel
          // validated implementation.
          //
          If(And(PARM, 1))
          {
            If(LEqual(ShiftRight(PARM, 1), 1))
            {
              Store(1, ISSC)  // Enable HW SSC, only for clock 1
            }
            Else
            {
              Store(Zero, GESF)
              Return(CRIT)    // Failure, as the SSC clock must be 1
            }
          }
          Else
          {
            Store(0, ISSC)    // Disable SSC
          }
          Store(Zero, GESF)   // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)        // Success
        }
        //
        // Post VBE/PM Callback: Sub-function 19 (13h)
        //
        If (LEqual(GESF, 19))
        {
          Store(Zero, GESF)  // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)       // Not supported, but no failure
        }
        //
        // Set PAVP Data: Sub-function 20 (14h)
        //
        If (LEqual(GESF, 20))
        {
          And(PARM, 0xF, PAVP) // Store PAVP info
          Store(Zero, GESF)    // Clear the exit parameter
          Store(Zero, PARM)
          Return(SUCC)         // Success
        }
      
        //
        // A call to a reserved "System BIOS callbacks" function was received
        //
        Store(Zero, GESF) // Clear the exit parameter
        Return(SUCC)      // Reserved, "Critical failure"
      }

    
      If (LEqual(GEFC, 4))
      {
        Store(GBDA(), GXFC)    // Process Get BIOS Data functions
      }
    
      If (LEqual(GEFC, 6))
      {
        Store(SBCB(), GXFC)    // Process BIOS Callback functions
      }
    
      Store(0, GEFC)           // Wipe out the entry function code
      Store(1, CPSC)           // Clear CPUSCI_STS to clear the PCH TCO SCI status
      Store(0, GSSE)           // Clear the SCI generation bit in PCI space.
      Store(0, SCIE)           // Clr SCI serviced bit to signal completion
    
      Return(Zero)
    }
    
    /** @file
      IGD OpRegion/Software SCI Reference Code.
      This file contains ASL code with the purpose of handling events
      i.e. hotkeys and other system interrupts.
    
      Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
      SPDX-License-Identifier: BSD-2-Clause-Patent
    **/
    //
    // Notes:
    // 1. The following routines are to be called from the appropriate event
    //    handlers.
    // 2. This code cannot comprehend the exact implementation in the OEM's BIOS.
    //    Therefore, an OEM must call these methods from the existing event
    //    handler infrastructure.  Details on when/why to call each method is
    //    included in the method header under the "usage" section.
    //
    
    /************************************************************************;
    ;* ACPI Notification Methods
    ;************************************************************************/
    
    
    /************************************************************************;
    ;*
    ;* Name:        PDRD
    ;*
    ;* Description: Check if the graphics driver is ready to process
    ;*              notifications and video extensions.
    ;*
    ;* Usage:       This method is to be called prior to performing any
    ;*              notifications or handling video extensions.
    ;*              Ex: If (PDRD()) {Return (FAIL)}
    ;*
    ;* Input:       None
    ;*
    ;* Output:      None
    ;*
    ;* References:  DRDY (Driver ready status), ASLP (Driver recommended
    ;*              sleep timeout value).
    ;*
    ;************************************************************************/
    
    External(HNOT, MethodObj)
    
    Method(PDRD)
    {
      //
      // If DRDY is clear, the driver is not ready.  If the return value is
      // !=0, do not perform any notifications or video extension handling.
      //
      Return(LNot(DRDY))
    }
    
    /************************************************************************;
    ;*
    ;* Name:        PSTS
    ;*
    ;* Description: Check if the graphics driver has completed the previous
    ;*              "notify" command.
    ;*
    ;* Usage:       This method is called before every "notify" command.  A
    ;*              "notify" should only be set if the driver has completed the
    ;*              previous command.  Else, ignore the event and exit the parent
    ;*              method.
    ;*              Ex: If (PSTS()) {Return (FAIL)}
    ;*
    ;* Input:       None
    ;*
    ;* Output:      None
    ;*
    ;* References:  CSTS (Notification status), ASLP (Driver recommended sleep
    ;*              timeout value).
    ;*
    ;************************************************************************/
    
    Method(PSTS)
    {
      If(LGreater(CSTS, 2))
      {
        //
        // Sleep for ASLP milliseconds if the status is not "success,
        // failure, or pending"
        //
        Sleep(ASLP)
      }
    
      Return(LEqual(CSTS, 3)) // Return True if still Dispatched
    }
    
    /************************************************************************;
    ;*
    ;* Name:  GNOT
    ;*
    ;* Description: Call the appropriate methods to query the graphics driver
    ;*              status.  If all methods return success, do a notification of
    ;*              the graphics device.
    ;*
    ;* Usage:       This method is to be called when a graphics device
    ;*              notification is required (display switch hotkey, etc).
    ;*
    ;* Input:       Arg0 = Current event type:
    ;*                1 = display switch
    ;*                2 = lid
    ;*                3 = dock
    ;*              Arg1 = Notification type:
    ;*                0 = Re-enumeration
    ;*                0x80 = Display switch
    ;*
    ;* Output:      Returns 0 = success, 1 = failure
    ;*
    ;* References:  PDRD and PSTS methods.  OSYS (OS version)
    ;*
    ;************************************************************************/
    
    Method(GNOT, 2)
    {
      //
      // Check for 1. Driver loaded, 2. Driver ready.
      // If any of these cases is not met, skip this event and return failure.
      //
      If(PDRD())
      {
        Return(0x1) // Return failure if driver not loaded.
      }
    
      Store(Arg0, CEVT) // Set up the current event value
      Store(3, CSTS) // CSTS=BIOS dispatched an event
    
      If(LAnd(LEqual(CHPD, 0), LEqual(Arg1, 0))) // Do not re-enum if driver supports hotplug
      {
        //
        // Re-enumerate the Graphics Device for non-XP operating systems.
        //
        Notify(\_SB.PC00.GFX0, Arg1)
      }
    
      If(CondRefOf(HNOT))
      {
        HNOT(Arg0)  //Notification handler for Hybrid graphics
      }
      Else
      {
        Notify(\_SB.PC00.GFX0,0x80)
      }
    
      Return(0x0) // Return success
    }
    
    /************************************************************************;
    ;*
    ;* Name:        GHDS
    ;*
    ;* Description: Handle a hotkey display switching event (performs a
    ;*              Notify(GFX0, 0).
    ;*
    ;* Usage:       This method must be called when a hotkey event occurs and the
    ;*              purpose of that hotkey is to do a display switch.
    ;*
    ;* Input:       Arg0 = Toggle table number.
    ;*
    ;* Output:      Returns 0 = success, 1 = failure.
    ;*              CEVT and TIDX are indirect outputs.
    ;*
    ;* References:  TIDX, GNOT
    ;*
    ;************************************************************************/
    
    Method(GHDS, 1)
    {
      Store(Arg0, TIDX) // Store the table number
      //
      // Call GNOT for CEVT = 1 = hotkey, notify value = 0
      //
      Return(GNOT(1, 0)) // Return stats from GNOT
    }
    
    /************************************************************************;
    ;*
    ;* Name:        GLID
    ;*
    ;* Description: Handle a lid event (performs the Notify(GFX0, 0), but not the
    ;*              lid notify).
    ;*
    ;* Usage:       This method must be called when a lid event occurs.  A
    ;*              Notify(LID0, 0x80) must follow the call to this method.
    ;*
    ;* Input:       Arg0 = Lid state:
    ;*                0 = All closed
    ;*                1 = internal LFP lid open
    ;*                2 = external lid open
    ;*                3 = both external and internal open
    ;*
    ;* Output:      Returns 0=success, 1=failure.
    ;*              CLID and CEVT are indirect outputs.
    ;*
    ;* References:  CLID, GNOT
    ;*
    ;************************************************************************/
    
    Method(GLID, 1)
    {
    
      If (LEqual(Arg0,1))
      {
        Store(3,CLID)
      }
      Else
      {
        Store(Arg0, CLID)
      }
      //
      //Store(Arg0, CLID) // Store the current lid state
      // Call GNOT for CEVT=2=Lid, notify value = 0
      //
      if (GNOT(2, 0)) {
        Or (CLID, 0x80000000, CLID)
        Return (1) // Return Fail
      }
    
      Return (0) // Return Pass
    }
    
    /************************************************************************;
    ;*
    ;* Name:  GDCK
    ;*
    ;* Description: Handle a docking event by updating the current docking status
    ;*              and doing a notification.
    ;*
    ;* Usage:       This method must be called when a docking event occurs.
    ;*
    ;* Input:       Arg0 = Docking state:
    ;*                0 = Undocked
    ;*                1 = Docked
    ;*
    ;* Output:      Returns 0=success, 1=failure.
    ;*              CDCK and CEVT are indirect outputs.
    ;*
    ;* References:  CDCK, GNOT
    ;*
    ;************************************************************************/
    
    Method(GDCK, 1)
    {
      Store(Arg0, CDCK) // Store the current dock state
      //
      // Call GNOT for CEVT=4=Dock, notify value = 0
      //
      Return(GNOT(4, 0)) // Return stats from GNOT
    }
    
    /************************************************************************;
    ;* ASLE Interrupt Methods
    ;************************************************************************/
    
    /************************************************************************;
    ;*
    ;* Name:        PARD
    ;*
    ;* Description: Check if the driver is ready to handle ASLE interrupts
    ;*              generate by the system BIOS.
    ;*
    ;* Usage:       This method must be called before generating each ASLE
    ;*              interrupt.
    ;*
    ;* Input:       None
    ;*
    ;* Output:      Returns 0 = success, 1 = failure.
    ;*
    ;* References:  ARDY (Driver readiness), ASLP (Driver recommended sleep
    ;*              timeout value)
    ;*
    ;************************************************************************/
    
    Method(PARD)
    {
      If(LNot(ARDY))
      {
        //
        // Sleep for ASLP milliseconds if the driver is not ready.
        //
        Sleep(ASLP)
      }
      //
      // If ARDY is clear, the driver is not ready.  If the return value is
      // !=0, do not generate the ASLE interrupt.
      //
      Return(LNot(ARDY))
    }
    
    //
    // Intel Ultrabook Event Handler.  Arg0 represents the Ultrabook Event Bit # to pass
    // to the Intel Graphics Driver.  Note that this is a serialized method, meaning
    // sumultaneous events are not allowed.
    //
    Method(IUEH,1,Serialized)
    {
      And(IUER,0xC0,IUER) // Clear all button events on entry.
      XOr(IUER,Shiftleft(1,Arg0),IUER) // Toggle status.
    
      If(LLessEqual(Arg0,4)) // Button Event?
      {
        Return(AINT(5,0)) // Generate event and return status.
    
      }
      Else // Indicator Event.
      {
        Return(AINT(Arg0,0)) // Generate event and return status.
      }
    }
    
    /************************************************************************;
    ;*
    ;* Name:        AINT
    ;*
    ;* Description: Call the appropriate methods to generate an ASLE interrupt.
    ;*              This process includes ensuring the graphics driver is ready
    ;*              to process the interrupt, ensuring the driver supports the
    ;*              interrupt of interest, and passing information about the event
    ;*              to the graphics driver.
    ;*
    ;* Usage:       This method must called to generate an ASLE interrupt.
    ;*
    ;* Input:       Arg0 = ASLE command function code:
    ;*                0 = Set ALS illuminance
    ;*                1 = Set backlight brightness
    ;*                2 = Do Panel Fitting
    ;*                4 = Reserved
    ;*                5 = Button Indicator Event
    ;*                6 = Convertible Indicator Event
    ;*                7 = Docking Indicator Event
    ;*              Arg1 = If Arg0 = 0, current ALS reading:
    ;*                0 = Reading below sensor range
    ;*                1-0xFFFE = Current sensor reading
    ;*                0xFFFF = Reading above sensor range
    ;*              Arg1 = If Arg0 = 1, requested backlight percentage
    ;*
    ;* Output:      Returns 0 = success, 1 = failure
    ;*
    ;* References:  PARD method.
    ;*
    ;************************************************************************/
    
    Method(AINT, 2)
    {
      //
      // Return failure if the requested feature is not supported by the
      // driver.
      //
      If(LNot(And(TCHE, ShiftLeft(1, Arg0))))
      {
        Return(0x1)
      }
      //
      // Return failure if the driver is not ready to handle an ASLE
      // interrupt.
      //
      If(PARD())
      {
        Return(0x1)
      }
      //
      // Handle Intel Ultrabook Events.
      //
      If(LAnd(LGreaterEqual(Arg0,5),LLessEqual(Arg0,7)))
      {
        Store(ShiftLeft(1,Arg0), ASLC) // Set Ultrbook Event [6:4].
        Store(0x01, ASLE) // Generate ASLE interrupt
    
        Store(0,Local2) // Use Local2 as a timeout counter.  Intialize to zero.
    
        While(LAnd(LLess(Local2,250),LNotEqual(ASLC,0))) // Wait 1 second or until Driver ACKs a success.
        {
          Sleep(4) // Delay 4 ms.
          Increment(Local2) // Increment Timeout.
        }
    
        Return(0) // Return success
      }
      //
      // Evaluate the first argument (Panel fitting, backlight brightness, or ALS).
      //
      If(LEqual(Arg0, 2))         // Arg0 = 2, so request a panel fitting mode change.
      {
        If(CPFM)                  // If current mode field is non-zero use it.
        {
          And(CPFM, 0x0F, Local0) // Create variables without reserved
          And(EPFM, 0x0F, Local1) // or valid bits.
    
          If(LEqual(Local0, 1))   // If current mode is centered,
          {
            If(And(Local1, 6))    // and if stretched is enabled,
            {
              Store(6, PFIT)      // request stretched.
            }
            Else                  // Otherwise,
            {
              If(And(Local1, 8))  // if aspect ratio is enabled,
              {
                Store(8, PFIT)    // request aspect ratio.
              }
              Else                // Only centered mode is enabled
              {
                Store(1, PFIT)    // so request centered. (No change.)
              }
            }
          }
          If(LEqual(Local0, 6))   // If current mode is stretched,
          {
            If(And(Local1, 8))    // and if aspect ratio is enabled,
            {
              Store(8, PFIT)      // request aspect ratio.
            }
            Else                  // Otherwise,
            {
              If(And(Local1, 1))  // if centered is enabled,
              {
                Store(1, PFIT)    // request centered.
              }
              Else                // Only stretched mode is enabled
              {
                Store(6, PFIT)    // so request stretched. (No change.)
              }
            }
          }
          If(LEqual(Local0, 8))   // If current mode is aspect ratio,
          {
            If(And(Local1, 1))    // and if centered is enabled,
            {
              Store(1, PFIT)      // request centered.
            }
            Else                  // Otherwise,
            {
              If(And(Local1, 6))  // if stretched is enabled,
              {
                Store(6, PFIT)    // request stretched.
              }
              Else                // Only aspect ratio mode is enabled
              {
                Store(8, PFIT)    // so request aspect ratio. (No change.)
              }
            }
          }
        }
        //
        // The following code for panel fitting (within the Else condition) is retained for backward compatiblity.
        //
        Else                      // If CFPM field is zero use PFIT and toggle the
        {
          Xor(PFIT,7,PFIT)        // mode setting between stretched and centered only.
        }
        Or(PFIT,0x80000000,PFIT)  // Set the valid bit for all cases.
        Store(4, ASLC)            // Store "Panel fitting event" to ASLC[31:1]
      }
      Else
      {
        If(LEqual(Arg0, 1)) // Arg0=1, so set the backlight brightness.
        {
          Store(Divide(Multiply(Arg1, 255), 100), BCLP) // Convert from percent to 0-255.
          Or(BCLP, 0x80000000, BCLP) // Set the valid bit.
          Store(2, ASLC) // Store "Backlight control event" to ASLC[31:1]
        }
        Else
        {
          If(LEqual(Arg0, 0)) // Arg0=0, so set the ALS illuminace
          {
            Store(Arg1, ALSI)
            Store(1, ASLC) // Store "ALS event" to ASLC[31:1]
          }
          Else
          {
            Return(0x1) // Unsupported function
          }
        }
      }
    
      Store(0x01, ASLE) // Generate ASLE interrupt
      Return(0x0) // Return success
    }
    
    /************************************************************************;
    ;*
    ;* Name: IPCO
    ;*
    ;* Description:
    ;*      PCON Bit[8:7] - dGfx is valided and detected
    ;*      Bits[8] - External Gfx Adapter Field valid
    ;*         0 = External Gfx Adapter field is Not valid
    ;*         1 = External Gfx Adapter field is valid
    ;*       Bits[7] - External Gfx Adapter
    ;*         0 = No External Gfx Adapter
    ;*         1 = External Gfx Adapter Detected and Available
    ;*
    ;* Output: Returns 0 = No External Gfx Adapter Attached
    ;*                 1 = External Gfx Adapter Attached
    ;*
    ;* References: PCON
    ;************************************************************************/
    
    Method (IPCO)
    {
      If (CondRefOf (PCON)) {
        If (LEqual (And (PCON, Or (BIT7, BIT8)), Or (BIT7, BIT8))) {
          Return (0x1)
        } Else {
    
        }
      } Else {
      }
      Return (0x0)
    }


    /** @file
      IGD OpRegion/_DSM Reference Code.
      This file contains Get BIOS Data and Callback functions for
      the Integrated Graphics Device (IGD) OpRegion/DSM mechanism
    
      Copyright (c) 2021, Intel Corporation. All rights reserved.<BR>
      SPDX-License-Identifier: BSD-2-Clause-Patent
    **/
    
    External(\_SB.PC00.IMMC, MethodObj)
    External(\_SB.PC00.IMMD, MethodObj)
    
    //
    // _DSM Device Specific Method
    //
    // Arg0: UUID Unique function identifier
    // Arg1: Integer Revision Level
    // Arg2: Integer Function Index (1 = Return Supported Functions)
    // Arg3: Additional Inputs/Package Parameters Bits [31:0] input as {Byte0, Byte1, Byte2, Byte3} to BIOS which is passed as 32 bit DWORD by Driver
    //
    Method (_DSM, 4, Serialized, 0, UnknownObj, {BuffObj, IntObj, IntObj, PkgObj}) {
    
      If (LEqual(Arg0, ToUUID ("3E5B41C6-EB1D-4260-9D15-C71FBADAE414"))) {
        //
        // _DSM Definition for Igd functions
        // Arguments:
        // Arg0: UUID: 3E5B41C6-EB1D-4260-9D15-C71FBADAE414
        // Arg1: Revision ID: 1
        // Arg2: Function Index: 16
        // Arg3: Additional Inputs Bits[31:0] Arg3 {Byte0, Byte1, Byte2, Byte3}
        //
        // Return:
        // Success for simple notification, Opregion update for some routines and a Package for AKSV
        //
        If (Lor(LEqual(Arg2,18),LEqual(Arg2,19))) {
          CreateDwordField(Arg3, 0x0, DDIN)
          CreateDwordField(Arg3, 0x4, BUF1)
          //
          // OPTS is return buffer from IOM mailbox -
          // Byte[0] is Status field.
          // BYTE[1] is HDP Count.
          //
          Name(OPTS, Buffer(4){0,0,0,0})
          CreateByteField(OPTS, 0x00, CMST) // Command Status field
                                            //         Success - 0
                                            //         Fail    - 1
          CreateByteField(OPTS, 0x01, RTB1) // Return Buffer 1
    
          //
          // Gfx Empty Dongle Buffer is data for return DSM fun#
          // with below buffer format
          // Byte[0-3] is Data field.
          // Byte[4] is Status field.
          //
          Name(GEDB, Buffer(5){0,0,0,0,0})
          CreateDwordField(GEDB, 0x00, GEDF) // Gfx Empty Dongle Data Field
          CreateByteField(GEDB, 0x04, GESF)  // Gfx Empty Dongle Status Field
                                             //         Success - 0
                                             //         Fail    - None 0
        }
    
        //
        // Switch by function index
        //
        Switch(ToInteger(Arg2)) {
          //
          // Function Index: 0
          // Standard query - A bitmask of functions supported
          //
          // Return: A bitmask of functions supported
          //
          Case (0)
          {
            If (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
              Store("iGfx Supported Functions Bitmap ", Debug)
    
              Return(0xDE7FF)
            }
          }
    
          //
          // Function Index: 1
          // Adapter Power State Notification
          // Arg3 Bits [7:0]: Adapter Power State bits [7:0] from Driver 00h = D0; 01h = D1; 02h = D2; 04h = D3 (Cold/Hot); 08h = D4 (Hibernate Notification)
          // Return: Success
          //
          Case(1) {
            If (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
              Store(" Adapter Power State Notification ", Debug)
    
              //
              // Handle Low Power S0 Idle Capability if enabled
              //
              If(LAnd(LEqual(S0ID, 1),LLess(OSYS, 2015))) {
                //
                // Call GUAM to trigger CS Entry
                //   If Adapter Power State Notification = D1 (Arg3[0]=0x01)
                //
                If (LEqual (And(DerefOf (Index (Arg3,0)), 0xFF), 0x01)) {
                  // GUAM - Global User Absent Mode Notification Method
                  \GUAM(One) // 0x01 - Power State Standby (CS Entry)
                }
                Store(And(DerefOf (Index (Arg3,1)), 0xFF), Local0)
                //
                // Call GUAM
                // If Display Turn ON Notification (Arg3 [1] == 0) for CS Exit
                //
                If (LEqual (Local0, 0)) {
                  // GUAM - Global User Absent Mode Notification Method
                  \GUAM(0)
                }
              }
    
              // Upon notification from driver that the Adapter Power State = D0,
              // check if previous lid event failed.  If it did, retry the lid
              // event here.
              If(LEqual(DerefOf (Index (Arg3,0)), 0)) {
                Store(CLID, Local0)
                If(And(0x80000000,Local0)) {
                  And(CLID, 0x0000000F, CLID)
                  GLID(CLID)
                }
              }
              Return(0x01)
            }
          }
          //
          // Function Index: 2
          // Display Power State Notification
          // Arg3: Display Power State Bits [15:8]
          // 00h = On
          // 01h = Standby
          // 02h = Suspend
          // 04h = Off
          // 08h = Reduced On
          // Return: Success
          //
         Case(2) {
            if (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
    
              Store("Display Power State Notification ", Debug)
              Return(0x01)
            }
          }
    
          //
          // Function Index: 3
          // BIOS POST Completion Notification
          // Return: Success
          //
          Case(3) {
            if (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
              Store("BIOS POST Completion Notification ", Debug)
              Return(0x01)      // Not supported, but no failure
            }
          }
    
          //
          // Function Index: 4
          // Pre-Hires Set Mode
          // Return: Success
          //
          Case(4) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("Pre-Hires Set Mode ", Debug)
              Return(0x01)      // Not supported, but no failure
            }
          }
    
          //
          // Function Index: 5
          // Post-Hires Set Mode
          // Return: Success
          //
          Case(5) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("Post-Hires Set Mode ", Debug)
              Return(0x01)      // Not supported, but no failure
            }
          }
    
          //
          // Function Index: 6
          // SetDisplayDeviceNotification (Display Switch)
          // Return: Success
          //
          Case(6) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("SetDisplayDeviceNotification", Debug)
              Return(0x01)      // Not supported, but no failure
            }
          }
    
          //
          // Function Index: 7
          // SetBootDevicePreference
          // Return: Success
          //
          Case(7) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              //<TODO> An OEM may elect to implement this method.  In that case,
              // the input values must be saved into non-volatile storage for
              // parsing during the next boot.  The following Sample code is Intel
              // validated implementation.
    
              Store("SetBootDevicePreference ", Debug)
              And(DerefOf (Index (Arg3,0)), 0xFF, IBTT) // Save the boot display to NVS
              Return(0x01)
            }
          }
    
          //
          // Function Index: 8
          // SetPanelPreference
          // Return: Success
          //
          Case(8) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              // An OEM may elect to implement this method.  In that case,
              // the input values must be saved into non-volatile storage for
              // parsing during the next boot.  The following Sample code is Intel
              // validated implementation.
    
              Store("SetPanelPreference ", Debug)
    
              // Set the panel-related NVRAM variables based the input from the driver.
              And(DerefOf (Index (Arg3,0)), 0xFF, IPSC)
    
              // Change panel type if a change is requested by the driver (Change if
              // panel type input is non-zero).  Zero=No change requested.
              If(And(DerefOf (Index (Arg3,1)), 0xFF)) {
                And(DerefOf (Index (Arg3,1)), 0xFF, IPAT)
                Decrement(IPAT)    // 0 = no change, so fit to CMOS map
              }
              And(ShiftRight(DerefOf (Index (Arg3,2)), 4), 0x7, IBIA)
              Return(0x01)         // Success
            }
          }
    
          //
          // Function Index: 9
          // FullScreenDOS
          // Return: Success
          //
          Case(9) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("FullScreenDOS ", Debug)
              Return(0x01)      // Not supported, but no failure
            }
          }
    
          //
          // Function Index: 10
          // APM Complete
          // Return: Adjusted Lid State
          //
         Case(10) {
            if (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
    
              Store("APM Complete ", Debug)
              Store(ShiftLeft(LIDS, 8), Local0) // Report the lid state
              Add(Local0, 0x100, Local0)        // Adjust the lid state, 0 = Unknown
              Return(Local0)
            }
          }
    
          //
          //
          // Function Index: 13
          // GetBootDisplayPreference
          // Arg3 Bits [30:16] : Boot Device Ports
          // Arg3 Bits [7:0] : Boot Device Type
          // Return: Boot device port and Boot device type from saved configuration
          //
         Case(13) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
    
              Store("GetBootDisplayPreference ", Debug)
              Or(ShiftLeft(DerefOf (Index (Arg3,3)), 24), ShiftLeft(DerefOf (Index (Arg3,2)), 16), Local0) // Combine Arg3 Bits [31:16]
              And(Local0, 0xEFFF0000, Local0)
              And(Local0, ShiftLeft(DeRefOf(Index(DBTB, IBTT)), 16), Local0)
              Or(IBTT, Local0, Local0) // Arg3 Bits [7:0] = Boot device type
              Return(Local0)
            }
          }
    
          //
          // Function Index: 14
          // GetPanelDetails
          // Return: Different Panel Settings
          //
          Case(14) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("GetPanelDetails ", Debug)
    
              // Report the scaling setting
              // Bits [7:0] - Panel Scaling
              // Bits contain the panel scaling user setting from CMOS
              // 00h = On: Auto
              // 01h = On: Force Scaling
              // 02h = Off
              // 03h = Maintain Aspect Ratio
    
              Store(IPSC, Local0)
              Or(Local0, ShiftLeft(IPAT, 8), Local0)
    
              // Adjust panel type, 0 = VBT default
              // Bits [15:8] - Panel Type
              // Bits contain the panel type user setting from CMOS
              // 00h = Not Valid, use default Panel Type & Timings from VBT
              // 01h - 0Fh = Panel Number
    
              Add(Local0, 0x100, Local0)
    
              // Report the lid state and Adjust it
              // Bits [16] - Lid State
              // Bits contain the current panel lid state
              // 0 = Lid Open
              // 1 = Lid Closed
    
              Or(Local0, ShiftLeft(LIDS, 16), Local0)
              Add(Local0, 0x10000, Local0)
    
             // Report the BIA setting
             // Bits [22:20] - Backlight Image Adaptation (BIA) Control
             // Bits contain the backlight image adaptation control user setting from CMOS
             // 000 = VBT Default
             // 001 = BIA Disabled (BLC may still be enabled)
             // 010 - 110 = BIA Enabled at Aggressiveness Level [1 - 5]
    
              Or(Local0, ShiftLeft(IBIA, 20), Local0)
              Return(Local0)
            }
          }
    
          //
          // Function Index: 15
          // GetInternalGraphics
          // Return: Different Internal Grahics Settings
          //
    
          Case(15) {
            if (LEqual(Arg1, 1)){ // test Arg1 for Revision ID: 1
              Store("GetInternalGraphics ", Debug)
    
              Store(GIVD, Local0)                    // Local0[0]      - VGA mode(1=VGA)
              Xor(Local0, 1, Local0)                 // Invert the VGA mode polarity
    
              Or(Local0, ShiftLeft(GMFN, 1), Local0) // Local0[1]      - # IGD PCI functions-1
                                                     // Local0[3:2]    - Reserved
                                                     // Local0[4]      - IGD D3 support(0=cold)
                                                     // Local0[10:5]   - Reserved
              Or(Local0, ShiftLeft(3, 11), Local0)   // Local0[12:11]  - DVMT version (11b = 5.0)
    
              //
              // Report DVMT 5.0 Total Graphics memory size.
              //
              Or(Local0, ShiftLeft(IDMS, 17), Local0) // Bits 20:17 are for Gfx total memory size
    
              // If the "Set Internal Graphics" call is supported, the modified
              // settings flag must be programmed per the specification.  This means
              // that the flag must be set to indicate that system BIOS requests
              // these settings.  Once "Set Internal Graphics" is called, the
              //  modified settings flag must be cleared on all subsequent calls to
              // this function.
    
              // Report the graphics frequency based on B0:D2:F0:RF0h[12].  Must
              // take into account the current VCO.
    
              Or(ShiftLeft(DeRefOf(Index(DeRefOf(Index(CDCT, HVCO)), CDVL)), 21),Local0, Local0)
              Return(Local0)
            }
          }
    
          //
          // Function Index: 16
          // GetAKSV
          // Retrun: 5 bytes of AKSV
          //
          Case(16) {
            if (LEqual(Arg1, 1)) { // test Arg1 for Revision ID: 1
    
              Store("GetAKSV ", Debug)
              Name (KSVP, Package()
              {
                 0x80000000,
                 0x8000
              })
              Store(KSV0, Index(KSVP,0)) // First four bytes of AKSV
              Store(KSV1, Index(KSVP,1)) // Fifth byte of AKSV
              Return(KSVP) // Success
            }
          }
        } // End of switch(Arg2)
      } // End of if (ToUUID("3E5B41C6-EB1D-4260-9D15-C71FBADAE414D"))
    
      Return (Buffer () {0x00})
    } // End of _DSM



    Method(_S3D, 0, NotSerialized)
    {
      Return(3)
    }
    Method(_S4D, 0, NotSerialized)
    {
      Return(3)
    }
    Method(_PS0,0,Serialized)
    {
    }
    Method(_PS3,0,Serialized)
    {
    }
  }
}