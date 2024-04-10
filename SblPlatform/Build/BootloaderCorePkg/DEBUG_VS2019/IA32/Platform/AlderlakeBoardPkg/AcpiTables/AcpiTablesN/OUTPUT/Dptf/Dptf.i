#undef MIN
#undef MAX
/** @file
  Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology

  Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
  SPDX-License-Identifier: BSD-2-Clause-Patent
**/

#include "CpuPowerMgmt.h"
#include <Include/AcpiDebug.h>
#include "PlatformBoardId.h"

#include "CpuRegs.h"
//#include "CpuGenInfo.h"
#include "Hid.h"

DefinitionBlock (
  "Dptf.aml",
  "SSDT",
  2,
  "DptfTb",
  "DptfTabl",
  0x1000
  )
{

External(\P8XH, MethodObj)
External(\TSOD, IntObj)
External(\PNHM, IntObj)
External(\TCNT, IntObj)
External(\PWRS, IntObj)
External(\CRTT, IntObj)
External(\ACTT, IntObj)
External(\PSVT, IntObj)
External(\ATPC, IntObj)
External(\PTPC, IntObj)

External(\PLID, IntObj) // PlatformId
External(\DPTF, IntObj) // EnableDptf
External(\DCFE, IntObj) // EnableDCFG

External(\SADE, IntObj) // EnableSaDevice

External(\FND1, IntObj) // EnableFan1Device
External(\FND2, IntObj) // EnableFan2Device
External(\FND3, IntObj) // EnableFan3Device

External(\S1DE, IntObj) // EnableSen1Participant
External(\SSP1, IntObj) // SensorSamplingPeriodSen1

External(\S2DE, IntObj) // EnableSen2Participant
External(\SSP2, IntObj) // SensorSamplingPeriodSen2

External(\S3DE, IntObj) // EnableSen3Participant
External(\SSP3, IntObj) // SensorSamplingPeriodSen3

External(\S4DE, IntObj) // EnableSen4Participant
External(\SSP4, IntObj) // SensorSamplingPeriodSen4

External(\S5DE, IntObj) // EnableSen5Participant
External(\SSP5, IntObj) // SensorSamplingPeriodSen5

External(\S6DE, IntObj) // EnableDgpuParticipant
External(\S6P2, IntObj) // Thermal Sampling Period

External(\CHGE, IntObj) // EnableChargerParticipant
External(\PWRE, IntObj) // EnablePowerParticipant
External(\PPPR, IntObj) // PowerParticipantPollingRate

External(\BATR, IntObj) // EnableBatteryParticipant
External(\IN34, IntObj) // EnableInt3400Device.

External(\PPSZ, IntObj) // PPCC Step Size
External(\PF00, IntObj) // PR00 _PDC Flags

External(\ODV0, IntObj) // OemDesignVariable0
External(\ODV1, IntObj) // OemDesignVariable1
External(\ODV2, IntObj) // OemDesignVariable2
External(\ODV3, IntObj) // OemDesignVariable3
External(\ODV4, IntObj) // OemDesignVariable4
External(\ODV5, IntObj) // OemDesignVariable5

External(\_TZ.ETMD, IntObj)
External(\_TZ.TZ00, ThermalZoneObj)

External(\_SB.PC00, DeviceObj)
External(\_SB.PC00.TCPU, DeviceObj)
External(\_SB.PC00.MC.MHBR, FieldUnitObj)

External(\ECON, IntObj)
External(\_SB.PC00.LPCB.H_EC, DeviceObj)

External(\_SB.PC00.LPCB.ITE8.TFN1, DeviceObj)
External(\_SB.PC00.LPCB.ITE8.SEN1, DeviceObj)
External(\_SB.PC00.LPCB.ITE8.SEN2, DeviceObj)

External(\_SB.PC00.LPCB.H_EC.ECAV, IntObj)
External(\_SB.PC00.LPCB.H_EC.ECMD, MethodObj)    // EC Command Method
External(\_SB.PC00.LPCB.H_EC.ECRD, MethodObj)    // EC Read Method
External(\_SB.PC00.LPCB.H_EC.ECWT, MethodObj)    // EC Write Method
External(\_SB.PC00.LPCB.H_EC.ECF2, OpRegionObj)

//
// Sensors
//
External(\_SB.PC00.LPCB.H_EC.TSR1, FieldUnitObj) // Sensor Temperature Values
External(\_SB.PC00.LPCB.H_EC.TSR2, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSR3, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSR4, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSR5, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSI,  FieldUnitObj)  // Sensor Select
External(\_SB.PC00.LPCB.H_EC.HYST, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSHT, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSLT, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.TSSR, FieldUnitObj)

External(\_SB.PC00.LPCB.H_EC.PPSL, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PPSH, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PINV, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PENV, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PSTP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CMDR, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CFSP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.DFSP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.GFSP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CPUP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PMAX, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PLMX, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PECH, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CFAN, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.B1RC, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.B1FC, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.BAT1._BST, MethodObj)
External(\_SB.PC00.LPCB.H_EC.BAT1._BIX, MethodObj)
External(\_SB.PC00.LPCB.H_EC.BMAX, FieldUnitObj)
//
// Power Boss
//
External(\_SB.PC00.LPCB.H_EC.PWRT, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PBSS, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.VMIN, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PSOC, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.AVOL, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.ACUR, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.ARTG, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CTYP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.BICC, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.PROP, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.AP01, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.AP02, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.AP10, FieldUnitObj)

External(\_SB.PC00.LPCB.H_EC.PPWR, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.CHGR, FieldUnitObj)
External(\_SB.PC00.LPCB.H_EC.FCHG, FieldUnitObj)

External(\_SB.CPPC, FieldUnitObj)
External(\_SB.PR00, ProcessorObj)
External(\_SB.PR00._PSS, MethodObj)
External(\_SB.PR00.TPSS, PkgObj)
External(\_SB.PR00.LPSS, PkgObj)
External(\_SB.PR00._PPC, MethodObj)
External(\_SB.PR00._TSS, MethodObj)
External(\_SB.CFGD, FieldUnitObj)
External(\_SB.PR00.TSMF, PkgObj)
External(\_SB.PR00.TSMC, PkgObj)
External(\_SB.PR00._PTC, MethodObj)
External(\_SB.PR00._TSD, MethodObj)
External(\_SB.PR00._TPC, IntObj)
External(\_SB.PR01, ProcessorObj)
External(\_SB.PR02, ProcessorObj)
External(\_SB.PR03, ProcessorObj)
External(\_SB.PR04, ProcessorObj)
External(\_SB.PR05, ProcessorObj)
External(\_SB.PR06, ProcessorObj)
External(\_SB.PR07, ProcessorObj)
External(\_SB.PR08, ProcessorObj)
External(\_SB.PR09, ProcessorObj)
External(\_SB.PR10, ProcessorObj)
External(\_SB.PR11, ProcessorObj)
External(\_SB.PR12, ProcessorObj)
External(\_SB.PR13, ProcessorObj)
External(\_SB.PR14, ProcessorObj)
External(\_SB.PR15, ProcessorObj)
External(\_SB.PR16, ProcessorObj)
External(\_SB.PR17, ProcessorObj)
External(\_SB.PR18, ProcessorObj)
External(\_SB.PR19, ProcessorObj)
External(\_SB.PR20, ProcessorObj)
External(\_SB.PR21, ProcessorObj)
External(\_SB.PR22, ProcessorObj)
External(\_SB.PR23, ProcessorObj)
External(\_SB.PR24, ProcessorObj)
External(\_SB.PR25, ProcessorObj)
External(\_SB.PR26, ProcessorObj)
External(\_SB.PR27, ProcessorObj)
External(\_SB.PR28, ProcessorObj)
External(\_SB.PR29, ProcessorObj)
External(\_SB.PR30, ProcessorObj)
External(\_SB.PR31, ProcessorObj)

External(\_SB.CLVL, FieldUnitObj)
External(\_SB.CBMI, FieldUnitObj)
External(\_SB.PL10, FieldUnitObj)
External(\_SB.PL20, FieldUnitObj)
External(\_SB.PLW0, FieldUnitObj)
External(\_SB.CTC0, FieldUnitObj)
External(\_SB.TAR0, FieldUnitObj)
External(\_SB.PL11, FieldUnitObj)
External(\_SB.PL21, FieldUnitObj)
External(\_SB.PLW1, FieldUnitObj)
External(\_SB.CTC1, FieldUnitObj)
External(\_SB.TAR1, FieldUnitObj)
External(\_SB.PL12, FieldUnitObj)
External(\_SB.PL22, FieldUnitObj)
External(\_SB.PLW2, FieldUnitObj)
External(\_SB.CTC2, FieldUnitObj)
External(\_SB.TAR2, FieldUnitObj)
External(\_SB.APSV, FieldUnitObj)
External(\_SB.AAC0, FieldUnitObj)
External(\_SB.ACRT, FieldUnitObj)
External(\_SB.PAGD, DeviceObj)
External(\_SB.PAGD._PUR, PkgObj)
External(\_SB.PAGD._STA, MethodObj)

// Platform-Wide OS Capable externals
External(\_SB.OSCP, IntObj)

// Intel Proprietary Wake up Event support externals.
External(\_SB.HIDD.HPEM, MethodObj)
External(\_SB.SLPB, DeviceObj)
External(HIDW, MethodObj)
External(HIWC, MethodObj)
External(\PCHE, FieldUnitObj) // EnablePchFivrParticipant
External(\_SB.CPID)

Scope(\_SB)
{
  //
  // DPTF Thermal Zone Device
  //
  //
  Device(IETM)
  {
      Name(_ADR,0)
      // GHID (Get HID)
      //
      // This method returns the HID value of the device
      //
      // Arguments: (1)
      //   Arg0: _UID Unique ID for the Device
      // Return Value:
      //   Returns appropriate HID for the respective participant
      //   "XXXX9999": return value if _UID doesn't match existing participants
      //

      Method(GHID, 1, Serialized,,StrObj)
      {
        If (LEqual(Arg0, "IETM")) {
          Return(IETM_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "SEN1")) {
          Return(SENX_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "SEN2")) {
          Return(SENX_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "SEN3")) {
          Return(SENX_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "SEN4")) {
          Return(SENX_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "SEN5")) {
          Return(SENX_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "TPCH")) {
          Return(PCHP_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "TFN1")) {
          Return(TFN1_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "TFN2")) {
          Return(TFN1_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "TFN3")) {
          Return(TFN1_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "TPWR")) {
          Return(TPWR_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "1")) {
          Return(BAT1_PARTICIPANT_HID_ADL)
        }
        If (LEqual(Arg0, "CHRG")) {
          Return(CHRG_PARTICIPANT_HID_ADL)
        }
        Return("XXXX9999")
      }

      //
      // Intel DPTF Thermal Framework Device
      //
      //Name (_UID, "IETM")
      /*Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel (R) Dynamic Tuning Technology IETM device
      }*/
      Name(_HID,IETM_PARTICIPANT_HID_ADL)

      //-------------------------------------------
      //  Intel Proprietary Wake up Event solution
      //-------------------------------------------
      Method(_DSM, 0x4, Serialized, 0, {IntObj, BuffObj}, {BuffObj, IntObj, IntObj, PkgObj})
      {
        If(CondRefOf(HIWC)) {
          If(HIWC(Arg0)) {
            If(CondRefOf(HIDW)) {
              Return (HIDW(Arg0, Arg1, Arg2, Arg3))
            }
          }
        }
        Return(Buffer(One) { 0x00 }) // Guid mismatch
      }

      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
      If(LAnd(LEqual(\DPTF,1),LEqual(\IN34,1))){
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }

      //
      // Save original trip points so _OSC method can enable/disable Legacy thermal policies by manipulating trip points.
      //
      Name (PTRP,0)  // Passive trip point
      Name (PSEM,0)  // Passive semaphore
      Name (ATRP,0)  // Active trip point
      Name (ASEM,0)  // Active semaphore
      Name (YTRP,0)  // Critical trip point
      Name (YSEM,0)  // Critical semaphore

      // _OSC (Operating System Capabilities)
      //
      // This object is evaluated by each DPTF policy implementation to communicate to the platform of the existence and/or control transfer.
      //
      // Arguments: (4)
      //   Arg0 - A Buffer containing a UUID
      //   Arg1 - An Integer containing a Revision ID of the buffer format
      //   Arg2 - An Integer containing a count of entries in Arg3
      //   Arg3 - A Buffer containing a list of DWORD capabilities
      // Return Value:
      //   A Buffer containing a list of capabilities
      //
      Method(_OSC, 4,Serialized,,BuffObj,{BuffObj,IntObj,IntObj,BuffObj})
      {

        // Point to Status DWORD in the Arg3 buffer (STATUS)
        CreateDWordField(Arg3, 0, STS1)

        // Point to Caps DWORDs of the Arg3 buffer (CAPABILITIES)
        CreateDWordField(Arg3, 4, CAP1)

        //
        // _OSC needs to validate the Revision.
        //
        // IF Unsupported Revision
        //  Return Unsupported Revision _OSC Failure
        //
        //    STS0[0] = Reserved
        //    STS0[1] = _OSC Failure
        //    STS0[2] = Unrecognized UUID // IDSP is no longer required for Intel(R) Dynamic Tuning dynamic participants.
                                          // Hence bios do not need to report Unrecognized UUID
        //    STS0[3] = Unsupported Revision
        //    STS0[4] = Capabilities masked
        //

        If(LNot(LEqual(Arg1, 1)))
        {
          //
          // Return Unsupported Revision _OSC Failure
          //
          And(STS1,0xFFFFFF00,STS1)
          Or(STS1,0xA,STS1)
          Return(Arg3)
        }

        If(LNot(LEqual(Arg2, 2)))
        {
          //
          // Return Argument 3 Buffer Count not sufficient
          //
          And(STS1,0xFFFFFF00,STS1)
          Or(STS1,0x2,STS1)
          Return(Arg3)
        }

        //
        // Save Auto Passive Trip Point
        //
        If(CondRefOf(\_SB.APSV)){
          If(LEqual(PSEM,0)){
            Store(1,PSEM)
            Store(\_SB.APSV,PTRP)  // use semaphore so variable is only initialized once
          }
        }
        //
        // Save Auto Active Trip Point
        //
        If(CondRefOf(\_SB.AAC0)){
          If(LEqual(ASEM,0)){
            Store(1,ASEM)
            Store(\_SB.AAC0,ATRP)  // use semaphore so variable is only initialized once
          }
        }
        //
        // Save Auto Critical Trip Point
        //
        If(CondRefOf(\_SB.ACRT)){
          If(LEqual(YSEM,0)){
            Store(1,YSEM)
            Store(\_SB.ACRT,YTRP)  // use semaphore so variable is only initialized once
          }
        }

        // CAP1 contains 4 bits. 1st bit is to indicate that Intel(R) Dynamic Tuning is enabled and wants to enabled some policy.
        // Bios can ignore that 1st bit(indicated by "x" in following table) and
        // only look at bits which are dedicated to each policy as shown in following table.
        // When the bit0 is zero the all CAP bits will be zero.
        // 001x: Enable Active Policy
        // 010x: Enable Passive Policy
        // 100x: Enable Critical Policy
        // 011x: Enable Active/Passive Policy
        // 101x: Enable Active/Critical Policy
        // 110x: Enable Passive/Critical Policy
        // 111x: Enable Active/Passive/Critical Policy
        // xxx0: Disabled all of the Intel(R) Dynamic Tuning Policies.

        //
        // Verify the Intel(R) Dynamic Tuning UUID.
        //
        If(LEqual(Arg0, ToUUID ("B23BA85D-C8B7-3542-88DE-8DE2FFCFD698"))){  // Intel(R) Dynamic Tuning GUID
          If(Not(And(STS1, 0x01))) // Test Query Flag
          { // Not a query operation, so process the request
            If(And(CAP1, 0x1)){  // Validate Intel(R) Dynamic Tuning input, When the bit0 is zero then no Intel(R) Dynamic Tuning policy is enabled.
              If(And(CAP1, 0x2)){  // Enable Active Policy. Nullify the legacy thermal zone.
                Store(110,\_SB.AAC0)
                Store(0, \_TZ.ETMD)  // Legacy Active TM Management relies on this variable.
              } Else{  // re-enable legacy thermal zone with active trip point
                Store(ATRP,\_SB.AAC0)
                Store(1, \_TZ.ETMD)
              }
              If(And(CAP1,0x4)){  // Enable Passive Policy. Nullify the legacy thermal zone.
                Store(110,\_SB.APSV)
              }Else{  // re-enable legacy thermal zone with passive trip point
                Store(PTRP,\_SB.APSV)
              }
              If(And(CAP1, 0x8)){  // Enable Critical Policy. Nullify the legacy thermal zone.
                Store(210,\_SB.ACRT)
              }Else{  // re-enable legacy thermal zone with critical trip point
                Store(YTRP,\_SB.ACRT)
              }
              // Send notification to legacy thermal zone for legacy policy to be enabled/disabled
              If(CondRefOf(\_TZ.TZ00)){
                Notify(\_TZ.TZ00, 0x81)
              }
            } Else{
              Store(YTRP,\_SB.ACRT) // re-enable legacy thermal zone with critical trip point
              Store(PTRP,\_SB.APSV) // re-enable legacy thermal zone with passive trip point
              Store(ATRP,\_SB.AAC0) // re-enable legacy thermal zone with active trip point
              Store(1, \_TZ.ETMD)
            }
            // Send notification to legacy thermal zone for legacy policy to be enabled/disabled
            If(CondRefOf(\_TZ.TZ00)){
              Notify(\_TZ.TZ00, 0x81)
            }
          }
          Return(Arg3)
        }

        Return(Arg3)
      }

      // DCFG (DPTF Configuration)
      //
      // Returns a DWORD data representing the desired behavior of DPTF besides supported DSP and participants.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the DPTF Configuration bitmap:
      //    Bit 0 = Generic UI Access Control (0 - enable as default, 1 - disable access)
      //    Bit 1 = Restricted UI Access Control ( 0 - enable as default, 1 - disable access )
      //    Bit 2 = Shell Access Control ( 0 - enable as default, 1 - disable access)
      //    Bit 3 = Environment Monitoring Report Control ( 0 - report is allowed as default, 1 - No environmental monitoring report to Microsoft )
      //    Bit 4 = Thermal Mitigation Report Control ( 0 - No mitigation report to Microsoft as default, 1 - report is allowed)
      //    Bit 5 = Thermal Policy Report Control ( 0 - No policy report to Microsoft as default, 1 - report is allowed)
      //    Bits[31:6] - Reserved (must be cleared).
      //
      Method(DCFG)
      {
        Return(\DCFE)
      }

      // ODVP (Oem Design Variables Package)
      //
      // Variables for OEM's to customize DPTF behavior based on platform changes.
      //
      Name(ODVX,Package(){0,0,0,0,0,0})

      // ODVP (Oem Design Variables Package)
      //
      // Variables for OEM's to customize DPTF behavior based on platform changes.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   Package of integers
      //
      Method(ODVP,0,Serialized,,PkgObj)
      {
        Store(\ODV0,Index(ODVX,0))
        Store(\ODV1,Index(ODVX,1))
        Store(\ODV2,Index(ODVX,2))
        Store(\ODV3,Index(ODVX,3))
        Store(\ODV4,Index(ODVX,4))
        Store(\ODV5,Index(ODVX,5))
        Return(ODVX)
      }

    } // End IETM Device
} // End \_SB Scope

If (LEqual(ECON,1)) {
//
// EC support code
//
Scope(\_SB.PC00.LPCB.H_EC) // Open scope to Embedded Controller
{
  //
  // Create a Mutex for PATx methods to prevent Sx resume race condition problems asscociated with EC commands.
  //
  Mutex(PATM, 0)

  // _QF1 (Query - Embedded Controller Query F1)
  //
  // Handler for EC generated SCI number F1.
  //
  // Arguments: (0)
  //   None
  // Return Value:
  //   None
  //
  Method(_QF1)
  { // Thermal sensor threshold crossing event handler
    Store(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSSR)), Local0)
    While(Local0) // Ensure that events occuring during execution
    {             // of this handler are not dropped
      \_SB.PC00.LPCB.H_EC.ECWT(0, RefOf(\_SB.PC00.LPCB.H_EC.TSSR)) // clear all status bits
      If(And(Local0, 0x10))
      { // BIT4: Sensor 5 Threshold Crossed
        Notify(\_SB.PC00.LPCB.H_EC.SEN5, 0x90)
      }
      If(And(Local0, 0x8))
      { // BIT3: Sensor 4 Threshold Crossed
        Notify(\_SB.PC00.LPCB.H_EC.SEN4, 0x90)
      }
      If(And(Local0, 0x4))
      { // BIT2: Sensor 3 Threshold Crossed
        Notify(\_SB.PC00.LPCB.H_EC.SEN3, 0x90)
      }
      If(And(Local0, 0x2))
      { // BIT1: Sensor 2 Threshold Crossed
        Notify(\_SB.PC00.LPCB.H_EC.SEN2, 0x90)
      }
      If(And(Local0, 0x1))
      { // BIT0: Sensor 1 (Dgpu) Threshold Crossed
        Notify(\_SB.PC00.LPCB.H_EC.DGPU, 0x90)
      }
      Store(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSSR)), Local0)
    }
  }

} // End \_SB.PC00.LPCB.H_EC Scope

//
// Fan participant.
//
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(TFN1)
    {
      Name(_UID, "TFN1")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Fan Device
      }
      Name(_STR, Unicode ("Fan 1"))
      Name(PTYP, 0x04)
  
      Name(FON, 1) // Indicates if Fan is ON Currently
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(FND1,1)){
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _FIF (Fan Information)
      //
      // The optional _FIF object provides OSPM with fan device capability information.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A Package containing the fan device parameters.
      //
      Method(_FIF)
      {
          Return (Package (){
          0,                            // Revision:Integer
          1,                            // FineGrainControl:Integer Boolean
          2,                            // StepSize:Integer DWORD
          0                             // LowSpeedNotificationSupport:Integer Boolean
          })
      }
  
      // _FPS (Fan Performance States)
      //
      // Evaluates to a variable-length package containing a list of packages that describe the fan device's performance states.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A variable-length Package containing a Revision ID and a list of Packages that describe the fan device's performance states.
      //
      Method(_FPS,,,,PkgObj)
      {
          Return (Package()
          {
            0,    // Revision:Integer
            //        Control,  TripPoint,    Speed,  NoiseLevel, Power
            Package(){100,      0xFFFFFFFF,   12000,  500,        5000},
            Package(){ 95,      0xFFFFFFFF,   11600,  475,        4750},
            Package(){ 90,      0xFFFFFFFF,   11200,  450,        4500},
            Package(){ 85,      0xFFFFFFFF,   10500,  425,        4250},
            Package(){ 80,      0xFFFFFFFF,    9800,  400,        4000},
            Package(){ 70,      0xFFFFFFFF,    9300,  350,        3500},
            Package(){ 60,      0xFFFFFFFF,    7400,  300,        3000},
            Package(){ 50,      0xFFFFFFFF,    6300,  250,        2500},
            Package(){ 40,      0xFFFFFFFF,    5100,  200,        2000},
            Package(){ 30,      0xFFFFFFFF,    3800,  150,        1500},
            Package(){ 25,      0xFFFFFFFF,    3200,  125,        1250},
            Package(){  0,      0xFFFFFFFF,       0,    0,           0} // OFF
          })
      }
  
      Name (FSLV, 0)
  
      // _FSL (Fan Set Level)
      //
      // The optional _FSL object is a control method that OSPM evaluates to set a fan device's speed (performance state) to a specific level.
      //
      // Arguments: (1)
      //  Arg0 - Level (Integer): conveys to the platform the fan speed level to be set.
      // Return Value:
      //  None
      //
      // Argument Information
      //  Arg0: Level. If the fan supports fine-grained control, Level is a percentage of maximum level (0-100)
      //  that the platform is to engage the fan. If the fan does not support fine-grained control,
      //  Level is a Control field value from a package in the _FPS object's package list.
      //  A Level value of zero causes the platform to turn off the fan.
      //
      Method(_FSL,1,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          If(LNot(LEqual(Arg0,\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)))))
          { // EC implementation-specific PWM port control
            \_SB.PC00.LPCB.H_EC.ECWT(0, RefOf(\_SB.PC00.LPCB.H_EC.PPSL))
            \_SB.PC00.LPCB.H_EC.ECWT(0, RefOf(\_SB.PC00.LPCB.H_EC.PPSH))
            \_SB.PC00.LPCB.H_EC.ECWT(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)), RefOf(\_SB.PC00.LPCB.H_EC.PINV))
            \_SB.PC00.LPCB.H_EC.ECWT(Arg0, RefOf(\_SB.PC00.LPCB.H_EC.PENV))
             Store(Arg0, FSLV)
            \_SB.PC00.LPCB.H_EC.ECWT(100, RefOf(\_SB.PC00.LPCB.H_EC.PSTP))
            \_SB.PC00.LPCB.H_EC.ECMD(0x1a)      // Command to turn the fan on
          }
        }
      }
  
      Name(TFST, Package()
      {
          0,          // Revision:Integer
          0xFFFFFFFF, // Control:Integer DWORD
          0xFFFFFFFF  // Speed:Integer DWORD
      })
  
      //_FST (Fan Status)
      //
      // The optional _FST object provides status information for the fan device.
      //
      // Arguments: (0)
      //  None
      // Return Value:
      //  A Package containing fan device status information
      //
      Method(_FST,0,Serialized,,PkgObj)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store(FSLV, Index(TFST, 1))
          Store(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.CFSP)), Index(TFST, 2))
        }
        Return(TFST)
      }
  
    } // End TFN1 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(TFN2)
    {
      Name(_HID, "INTC1048")  // Intel DPTF Fan Device
      Name(_UID, "TFN2")
      Name(_STR, Unicode ("DDR Fan"))
      Name(PTYP, 0x04)
  
      Name(FON, 1) // Indicates if Fan is ON Currently
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(FND2,1)){
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _FIF (Fan Information)
      //
      // The optional _FIF object provides OSPM with fan device capability information.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A Package containing the fan device parameters.
      //
      Method(_FIF)
      {
          Return (Package (){
          0,                            // Revision:Integer
          1,                            // FineGrainControl:Integer Boolean
          2,                            // StepSize:Integer DWORD
          0                             // LowSpeedNotificationSupport:Integer Boolean
          })
      }
  
      // _FPS (Fan Performance States)
      //
      // Evaluates to a variable-length package containing a list of packages that describe the fan device's performance states.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A variable-length Package containing a Revision ID and a list of Packages that describe the fan device's performance states.
      //
      Method(_FPS,,,,PkgObj)
      {
          Return (Package()
          {
            0,    // Revision:Integer
            //        Control,  TripPoint,    Speed,  NoiseLevel, Power
            Package(){100,      0xFFFFFFFF,   12000,  500,        5000},
            Package(){ 95,      0xFFFFFFFF,   11600,  475,        4750},
            Package(){ 90,      0xFFFFFFFF,   11200,  450,        4500},
            Package(){ 85,      0xFFFFFFFF,   10500,  425,        4250},
            Package(){ 80,      0xFFFFFFFF,    9800,  400,        4000},
            Package(){ 70,      0xFFFFFFFF,    9300,  350,        3500},
            Package(){ 60,      0xFFFFFFFF,    7400,  300,        3000},
            Package(){ 50,      0xFFFFFFFF,    6300,  250,        2500},
            Package(){ 40,      0xFFFFFFFF,    5100,  200,        2000},
            Package(){ 30,      0xFFFFFFFF,    3800,  150,        1500},
            Package(){ 25,      0xFFFFFFFF,    3200,  125,        1250},
            Package(){  0,      0xFFFFFFFF,       0,    0,           0} // OFF
          })
      }
  
      Name (FSLV, 0)
  
      // _FSL (Fan Set Level)
      //
      // The optional _FSL object is a control method that OSPM evaluates to set a fan device's speed (performance state) to a specific level.
      //
      // Arguments: (1)
      //  Arg0 - Level (Integer): conveys to the platform the fan speed level to be set.
      // Return Value:
      //  None
      //
      // Argument Information
      //  Arg0: Level. If the fan supports fine-grained control, Level is a percentage of maximum level (0-100)
      //  that the platform is to engage the fan. If the fan does not support fine-grained control,
      //  Level is a Control field value from a package in the _FPS object's package list.
      //  A Level value of zero causes the platform to turn off the fan.
      //
      Method(_FSL,1,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          If(LNot(LEqual(Arg0,\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)))))
          { // EC implementation-specific PWM port control
            \_SB.PC00.LPCB.H_EC.ECWT(1, RefOf(\_SB.PC00.LPCB.H_EC.PPSL))
            \_SB.PC00.LPCB.H_EC.ECWT(0, RefOf(\_SB.PC00.LPCB.H_EC.PPSH))
            \_SB.PC00.LPCB.H_EC.ECWT(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)), RefOf(\_SB.PC00.LPCB.H_EC.PINV))
            \_SB.PC00.LPCB.H_EC.ECWT(Arg0, RefOf(\_SB.PC00.LPCB.H_EC.PENV))
             Store(Arg0, FSLV)
            \_SB.PC00.LPCB.H_EC.ECWT(100, RefOf(\_SB.PC00.LPCB.H_EC.PSTP))
            \_SB.PC00.LPCB.H_EC.ECMD(0x1a)      // Command to turn the fan on
          }
        }
      }
  
      Name(TFST, Package()
      {
          0,          // Revision:Integer
          0xFFFFFFFF, // Control:Integer DWORD
          0xFFFFFFFF  // Speed:Integer DWORD
      })
  
      //_FST (Fan Status)
      //
      // The optional _FST object provides status information for the fan device.
      //
      // Arguments: (0)
      //  None
      // Return Value:
      //  A Package containing fan device status information
      //
      Method(_FST,0,Serialized,,PkgObj)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store(FSLV, Index(TFST, 1))
          Store(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.DFSP)), Index(TFST, 2))
        }
        Return(TFST)
      }
    } // End TFN1 Device
  
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(TFN3)
    {
      Name(_HID, "INTC1048")  // Intel DPTF Fan Device
      Name(_UID, "TFN3")
      Name(_STR, Unicode ("GFX Fan"))
      Name(PTYP, 0x04)
  
      Name(FON, 1) // Indicates if Fan is ON Currently
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(FND3,1)){
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _FIF (Fan Information)
      //
      // The optional _FIF object provides OSPM with fan device capability information.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A Package containing the fan device parameters.
      //
      Method(_FIF)
      {
          Return (Package (){
          0,                            // Revision:Integer
          1,                            // FineGrainControl:Integer Boolean
          2,                            // StepSize:Integer DWORD
          0                             // LowSpeedNotificationSupport:Integer Boolean
          })
      }
  
      // _FPS (Fan Performance States)
      //
      // Evaluates to a variable-length package containing a list of packages that describe the fan device's performance states.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //  A variable-length Package containing a Revision ID and a list of Packages that describe the fan device's performance states.
      //
      Method(_FPS,,,,PkgObj)
      {
          Return (Package()
          {
            0,    // Revision:Integer
            //        Control,  TripPoint,    Speed,  NoiseLevel, Power
            Package(){100,      0xFFFFFFFF,   12000,  500,        5000},
            Package(){ 95,      0xFFFFFFFF,   11600,  475,        4750},
            Package(){ 90,      0xFFFFFFFF,   11200,  450,        4500},
            Package(){ 85,      0xFFFFFFFF,   10500,  425,        4250},
            Package(){ 80,      0xFFFFFFFF,    9800,  400,        4000},
            Package(){ 70,      0xFFFFFFFF,    9300,  350,        3500},
            Package(){ 60,      0xFFFFFFFF,    7400,  300,        3000},
            Package(){ 50,      0xFFFFFFFF,    6300,  250,        2500},
            Package(){ 40,      0xFFFFFFFF,    5100,  200,        2000},
            Package(){ 30,      0xFFFFFFFF,    3800,  150,        1500},
            Package(){ 25,      0xFFFFFFFF,    3200,  125,        1250},
            Package(){  0,      0xFFFFFFFF,       0,    0,           0} // OFF
          })
      }
  
      Name (FSLV, 0)
  
      // _FSL (Fan Set Level)
      //
      // The optional _FSL object is a control method that OSPM evaluates to set a fan device's speed (performance state) to a specific level.
      //
      // Arguments: (1)
      //  Arg0 - Level (Integer): conveys to the platform the fan speed level to be set.
      // Return Value:
      //  None
      //
      // Argument Information
      //  Arg0: Level. If the fan supports fine-grained control, Level is a percentage of maximum level (0-100)
      //  that the platform is to engage the fan. If the fan does not support fine-grained control,
      //  Level is a Control field value from a package in the _FPS object's package list.
      //  A Level value of zero causes the platform to turn off the fan.
      //
      Method(_FSL,1,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          If(LNot(LEqual(Arg0,\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)))))
          { // EC implementation-specific PWM port control
            \_SB.PC00.LPCB.H_EC.ECWT(2, RefOf(\_SB.PC00.LPCB.H_EC.PPSL))
            \_SB.PC00.LPCB.H_EC.ECWT(0, RefOf(\_SB.PC00.LPCB.H_EC.PPSH))
            \_SB.PC00.LPCB.H_EC.ECWT(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.PENV)), RefOf(\_SB.PC00.LPCB.H_EC.PINV))
            \_SB.PC00.LPCB.H_EC.ECWT(Arg0, RefOf(\_SB.PC00.LPCB.H_EC.PENV))
             Store(Arg0, FSLV)
            \_SB.PC00.LPCB.H_EC.ECWT(100, RefOf(\_SB.PC00.LPCB.H_EC.PSTP))
            \_SB.PC00.LPCB.H_EC.ECMD(0x1a)      // Command to turn the fan on
          }
        }
      }
  
      Name(TFST, Package()
      {
          0,          // Revision:Integer
          0xFFFFFFFF, // Control:Integer DWORD
          0xFFFFFFFF  // Speed:Integer DWORD
      })
  
      //_FST (Fan Status)
      //
      // The optional _FST object provides status information for the fan device.
      //
      // Arguments: (0)
      //  None
      // Return Value:
      //  A Package containing fan device status information
      //
      Method(_FST,0,Serialized,,PkgObj)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store(FSLV, Index(TFST, 1))
          Store(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.GFSP)), Index(TFST, 2))
        }
        Return(TFST)
      }
  
    } // End TFN1 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

//
// Participants using device sensors.
//

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  External (\_SB.PC00.LPCB.H_EC.PBOK, FieldUnitObj)
  
  Scope(\_SB)
  {
  
    Device(TPWR)  // Power participant
    {
      Name(_UID, "TPWR")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  //Intel(R) Dynamic Tuning Technology platform power device
      }
      Name(_STR, Unicode ("Platform Power"))
      Name(PTYP, 0x11)
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If(LEqual(\PWRE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // PSOC (Platform State of Charge)
      //
      // This object evaluates to the remaining battery state of charge in %.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   remaining battery charge in %
      //
      Method(PSOC)
      {
        If(LEqual(\_SB.PC00.LPCB.H_EC.ECAV,0)) // check EC opregion available
        {
          Return (0) // EC not available
        }
        If(LEqual(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)),0)) // prevent divide by zero
        {
          Return (0) // Full charge cannot be 0, indicate malfunction in battery
        }
        If(LGreater(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1RC)),\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)))) // remaining charge > full charge
        {
          Return(0) // Remaining Charge cannot be greater than Full Charge, this illegal value indicates the battery is malfunctioning
        }
        If(LEqual(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1RC)),\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)))) // remaining charge == full charge
        {
          Return(100) // indicate battery is fully charged
        }
        If(LLess(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1RC)),\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)))) // (RC*100)/FC=percent
        {
          Multiply(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1RC)),100,Local0) // RC*100
          Divide(Local0,\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)),Local2,Local1) // divide by FC
          Divide(Local2,100,,Local2) // account for the remainder in percent
          Divide(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.B1FC)),200,,Local3) // what number is 0.5%?
          If(LGreaterEqual(Local2,Local3)){ // round up if the remainder is equal or above .5
            Add(Local1,1,Local1)
          }
          Return(Local1) // current charge in percent
        } Else {
          Return (0) // avoid compiler warning
        }
      }
  
      // PSRC (Power SouRCe)
      //
      // The PSRC object provides power source type.
      //
      // Arguments: (0)
      //   None
      // Return Value:(enumeration which Intel(R) Dynamic Tuning Technology driver expects)
      //   Bit[3:0] = Power Resource Type
      //   0x00 = DC
      //   0x01 = AC
      //   0x02 = USB
      //   Bit[7:4] = Power Delivery State Change Sequence Number
      //
      // Notes: (Bitmap from EC)
      // PwrSrcType Bit[0] = 0 <DC>, Bit[0] = 1 <AC>, Bit[1] = 1 <USB-PD>, Bit[2] = 1 <Wireless Charging>
      // Bit[7:4]  = Power Delivery State Change Sequence Number
  
      Method (PSRC, 0, Serialized)
      {
       If (LEqual(\_SB.PC00.LPCB.H_EC.ECAV,0))
        {
          Return(0) // EC not available, default to battery
        } Else {
          Store (\_SB.PC00.LPCB.H_EC.ECRD (RefOf(\_SB.PC00.LPCB.H_EC.PWRT)),Local0)
          And (Local0, 0xF0, Local1) // Keep Bit[7:4], clear Bit[3:0] in Local1
        }
  
          Switch (ToInteger(And(ToInteger(Local0),0x07))) // Switch Power Source Type Bits [3:0]
          {
            Case (0x0) { // Power source is DC
              Or (Local1, 0x00, Local1)
            }
            Case (0x1) { // Power source is AC
              Or (Local1, 0x01, Local1)
            }
            Case (0x2) { // Power source is USB-PD
              Or (Local1, 0x02, Local1)
            }
            Default {
              Or (Local1, 0x00, Local1) //default to battery
            }
          } // end of switch case check
        Return(Local1)
      }
  
      // ARTG (Adapter RaTinG)
      //
      // The ARTG object provides AC adapter rating in mW.
      // ARTG should return 0 if PSRC is DC (0).
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   AC adapter rating in mW
      //
      Method(ARTG)
      {
        If(LEqual((And(PSRC(),0x07)),1)) // Check Power Source Type Bits [3:0]
        {
          If(LEqual(\_SB.PC00.LPCB.H_EC.ECAV,1)) // Check If EC opregion is available
          {
            Multiply(\_SB.PC00.LPCB.H_EC.ARTG,10,Local0) // Becasue of EC-space constraint EC can only send 2bytes=15000mW but system uses 150000mW, hence bios is multiplying this value by 10.
            Return(Local0)
          } Else {
            Return(90000) // 90 watts
          }
        } Else {
          Return(0)
        }
      }
  
      // PROP (Platform Rest Of worst case Power)
      //
      // This object provides maximum worst case platform rest of power.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   power in milliwatts
      //
      Method(PROP)
      {
        If(LEqual(\_SB.PC00.LPCB.H_EC.ECAV,1)) // Check If EC opregion is available
        {
          Multiply(\_SB.PC00.LPCB.H_EC.PROP,1000,Local0) // EC sending value in Watts, converting it to mW
          Return(Local0)
        } Else {
         Return(25000) // 25 watts
        }
      }
  
      // PBOK
      //
      // PBOK is a command which BIOS sends to EC.
      // It will have a parameter which is the sequence number.
      //
      // Arguments: (1)
      //   Arg0 should be sent by Intel(R) Dynamic Tuning Technology driver which will be corresponding to Power delivery state change sequence number.
      //   Bit[3:0] = Power Delivery State Change Sequence number
      // Return Value:
      //   None
      //
      Method(PBOK,1,Serialized)
      {
        If (LEqual(\_SB.PC00.LPCB.H_EC.ECAV,1)) // Check If EC opregion is available
        {
          Store (And(Arg0, 0x000F), Local0)
          \_SB.PC00.LPCB.H_EC.ECWT (Local0, RefOf(\_SB.PC00.LPCB.H_EC.PBOK)) // Store sequence number
          \_SB.PC00.LPCB.H_EC.ECMD (0x15)
        }
      }
  
    } // End TPWR Device
  }// end Scope(\_SB)


//
// Participants using battery.
//


//
// Participants using motherboard sensors.
//
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(SEN1)
    {
      Name(_UID, "SEN1")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Temperature Sensor Device
      }
      Name(_STR, Unicode ("Thermistor PCH VR")) // Near PCH VR
      Name(PTYP, 0x03)
      Name(CTYP,0)  // Mode
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\S1DE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP,0,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Return(\_SB.IETM.C10K(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSR1))))
        } Else {
          Return(3000)
        }
      }
  
      Name(PATC, 2) // Returns Number of Aux Trips available
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT0,1,Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x0, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST))  // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSLT)) // Sensor Low Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT1,1,Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x0, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST))  // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSHT)) // Sensor High Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // Thermal Sensor Hysteresis, 2 degrees
      Name(GTSH, 20)
  
      Name(LSTM,0)  // Last temperature reported
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.LPCB.H_EC.SEN1, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
     // Default values for trip points for the validation purpose.
      Name (S1AC,60)  // Active0 trip point in celsius
      Name (S1A1,50)  // Active1 trip point in celsius
      Name (S1A2,40)  // Active2 trip point in celsius
      Name (S1PV,65)  // Passive trip point in celsius
      Name (S1CC,80)  // Critical trip point in celsius
      Name (S1C3,70)  // Critical s3 trip point in celsius
      Name (S1HP,75)  // Hot trip point in celsius
      Name (SSP1,0)   // Thermal Sampling Period
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        Return(SSP1)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC0,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(S1AC),Local1) // Active Cooling Policy
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC1,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1A1))
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC2,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1A2))
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1PV)) // Passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1CC))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1C3))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S1HP))
      }
  
    } // End SEN1 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(SEN2)
    {
      Name(_UID, "SEN2")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Temperature Sensor Device
      }
      Name(_STR, Unicode ("Thermistor GT VR")) // Near GT VR
      Name(PTYP, 0x03)
      Name(CTYP,0)  // Mode
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\S2DE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP, 0, Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Return(\_SB.IETM.C10K(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSR2))))
        } Else {
          Return(3000)
        }
      }
  
      // Number of Aux Trips available
      Name(PATC, 2)
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT0, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x1, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSLT)) // Sensor Low Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT1, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x1, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSHT)) // Sensor High Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // Thermal Sensor Hysteresis, 2 degrees
      Name(GTSH, 20)
  
      Name(LSTM,0)  // Last temperature reported
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.LPCB.H_EC.SEN2, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
     // Default values for trip points for the validation purpose.
      Name (S2AC,60)  // Active0 trip point in celsius
      Name (S2A1,50)  // Active1 trip point in celsius
      Name (S2A2,40)  // Active2 trip point in celsius
      Name (S2PV,65)  // Passive trip point in celsius
      Name (S2CC,80)  // Critical trip point in celsius
      Name (S2C3,70)  // Critical s3 trip point in celsius
      Name (S2HP,75)  // Hot trip point in celsius
      Name (SSP2,0)   // Thermal Sampling Period
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        Return(SSP2)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC0,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(S2AC),Local1) // Active Cooling Policy
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC1,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2A1))
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC2,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2A2))
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2PV)) // Passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2CC))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2C3))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S2HP))
      }
  
    } // End SEN2 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(SEN3)
    {
      Name(_UID, "SEN3")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Temperature Sensor Device
      }
      Name(_STR, Unicode ("Thermistor Ambient")) // Ambient
      Name(PTYP, 0x03)
      Name(CTYP,0)  // Mode
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\S3DE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP,0,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Return(\_SB.IETM.C10K(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSR3))))
        } Else {
          Return(3000)
        }
      }
  
      // Number of Aux Trips available
      Name(PATC, 2)
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT0, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSLT)) // Sensor Low Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A)// Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT1, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSHT)) // Sensor High Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // Thermal Sensor Hysteresis, 2 degrees
      Name(GTSH, 20)
  
      Name(LSTM,0)  // Last temperature reported
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.LPCB.H_EC.SEN3, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
     // Default values for trip points for the validation purpose.
      Name (S3AC,60)  // Active0 trip point in celsius
      Name (S3A1,50)  // Active1 trip point in celsius
      Name (S3A2,40)  // Active2 trip point in celsius
      Name (S3PV,65)  // Passive trip point in celsius
      Name (S3CC,80)  // Critical trip point in celsius
      Name (S3C3,70)  // Critical s3 trip point in celsius
      Name (S3HP,75)  // Hot trip point in celsius
      Name (SSP3,0)   // Thermal Sampling Period
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        Return(SSP3)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC3,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(S3AC),Local1) // Active Cooling Policy
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC4,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3A1))
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC5,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3A2))
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3PV)) // Passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3CC))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3C3))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S3HP) )
      }
  
    } // End SEN3 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(SEN4)
    {
      Name(_UID, "SEN4")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Temperature Sensor Device
      }
      Name(_STR, Unicode ("Thermistor Battery Charger")) // Near Battery Charger
      Name(PTYP, 0x03)
      Name(CTYP,0)  // Mode
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\S4DE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP,0,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Return(\_SB.IETM.C10K(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSR4))))
        } Else {
          Return(3000)
        }
      }
  
      // Number of Aux Trips available
      Name(PATC, 2)
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT0, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x3, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSLT)) // Sensor Low Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) //Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT1, 1, Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x3, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSHT)) // Sensor High Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // Thermal Sensor Hysteresis, 2 degrees
      Name(GTSH, 20)
  
      Name(LSTM,0)  // Last temperature reported
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.LPCB.H_EC.SEN4, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
     // Default values for trip points for the validation purpose.
      Name (S4AC,60)  // Active0 trip point in celsius
      Name (S4A1,50)  // Active1 trip point in celsius
      Name (S4A2,40)  // Active2 trip point in celsius
      Name (S4PV,65)  // Passive trip point in celsius
      Name (S4CC,80)  // Critical trip point in celsius
      Name (S4C3,70)  // Critical s3 trip point in celsius
      Name (S4HP,75)  // Hot trip point in celsius
      Name (SSP4,0)   // Thermal Sampling Period
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        Return(SSP4)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC0,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(S4AC),Local1) // Active Cooling Policy
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC1,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4A1))
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC2,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4A2))
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4PV)) // Passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4CC))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4C3))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S4HP))
      }
  
    } // End SEN4 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)

  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.PC00.LPCB.H_EC)
  {
  
    Device(SEN5)
    {
      Name(_UID, "SEN5")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology Temperature Sensor Device
      }
      Name(_STR, Unicode ("Thermistor Memory")) // Near memory
      Name(PTYP, 0x03)
      Name(CTYP,0)  // Mode
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\S5DE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP,0,Serialized)
      {
        If(\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Return(\_SB.IETM.C10K(\_SB.PC00.LPCB.H_EC.ECRD(RefOf(\_SB.PC00.LPCB.H_EC.TSR5))))
        } Else {
          Return(3000)
        }
      }
  
      // Number of Aux Trips available
      Name(PATC, 2)
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT0,1,Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x4, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSLT)) // Sensor Low Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) // Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // PATx (Participant Programmable Auxiliary Trip) - Sets Aux Trip Point
      //
      // The PATx objects shall take a single integer parameter, in tenths of degree Kelvin, which
      // represents the temperature at which the device should notify the participant driver of
      // an auxiliary trip event. A PATx control method returns no value.
      //
      //  Arguments: (1)
      //    Arg0 - temperature in tenths of degree Kelvin
      //  Return Value:
      //    None
      //
      Method(PAT1,1,Serialized)
      {
        If (\_SB.PC00.LPCB.H_EC.ECAV)
        {
          Store (Acquire(\_SB.PC00.LPCB.H_EC.PATM, 100),Local0)  // Save Acquire result so we can check for Mutex acquired
          If (LEqual(Local0, Zero))  // Check for Mutex acquired
          {
            Store(\_SB.IETM.K10C(Arg0),Local1)
            \_SB.PC00.LPCB.H_EC.ECWT(0x4, RefOf(\_SB.PC00.LPCB.H_EC.TSI)) // Select Thermal Sensor
            \_SB.PC00.LPCB.H_EC.ECWT(0x2, RefOf(\_SB.PC00.LPCB.H_EC.HYST)) // Thermal Sensor Hysteresis, 2 degrees
            \_SB.PC00.LPCB.H_EC.ECWT(Local1, RefOf(\_SB.PC00.LPCB.H_EC.TSHT)) // Sensor High Trip Point
            \_SB.PC00.LPCB.H_EC.ECMD(0x4A) //Set Trip point.
            Release(\_SB.PC00.LPCB.H_EC.PATM)
          }
        }
      }
  
      // Thermal Sensor Hysteresis, 2 degrees
      Name(GTSH, 20)
  
      Name(LSTM,0)  // Last temperature reported
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.LPCB.H_EC.SEN5, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
     // Default values for trip points for the validation purpose.
      Name (S5AC,60)  // Active0 trip point in celsius
      Name (S5A1,50)  // Active1 trip point in celsius
      Name (S5A2,40)  // Active2 trip point in celsius
      Name (S5PV,65)  // Passive trip point in celsius
      Name (S5CC,80)  // Critical trip point in celsius
      Name (S5C3,70)  // Critical s3 trip point in celsius
      Name (S5HP,75)  // Hot trip point in celsius
      Name (SSP5,0)   // Thermal Sampling Period
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        Return(SSP5)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC0,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(S5AC),Local1) // Active Cooling Policy
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        } Else {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC1,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5A1))
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC2,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5A2))
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5PV)) // Passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5CC))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5C3))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant and then export the value to BIOS GDDV for storage.
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(S5HP) )
      }
  
    } // End SEN5 Device
  }// end Scope(\_SB.PC00.LPCB.H_EC)



//
// Policy support files
//
  /** @file
    Intel ACPI Reference Code for Intel Dynamic Power Performance Management
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.IETM)
  {
  
    // PTTL (Participant Temperature Tolerance Level)
    // This object evaluates to an integer representing the temperature range within which any change
    // in participant temperature is considered acceptable and no policy actions will be taken by the
    // policy. The temperature tolerance level is expressed in the units of 10s of Kelvin.
    //
    Name (PTTL, 20) // ToleranceLevel
  
    // Used by passive policy 2.0
    //
    //  Name (PSVT, Package()
    //  {
    //    0x80000000,     // Revision: 1 = true proportional limit, 2 = depth limit
    //    Package() {
    //      "Source",     // Source device: String
    //      "Target",     // Target device: String
    //      0x80000000,   // Priority: for use by passive policy 2.0
    //      0x80000000,   // Sampling Period: in 1/10 of seconds unit
    //      0x80000000,   // Passive Temp: Threshold(1/10 of K) at which Passive Policy 2.0 will take action
    //      0x80000000,   // Domain: type under the source that is controlled
    //      0x80000000,   // Control Knob: type of control knob that need to be exercised
    //      0x80000000,   // Control Value: Depth Limit or Target State which policy will jump to on a thermal condition(based on revision).
    //      0x80000000,   // Step size for this specific control knob
    //      0x80000000,   // Limit Coefficient: 1/10 of units, used with StepSize to control limiting action
    //      0x80000000,   // UnLimit Coefficient: 1/10 of units, used with StepSize to control unlimiting action
    //      0x80000000    // Reserved1
    //    }
    //  })
    Name (PSVT, Package()
    {
      2,
      Package(){\_SB.PC00.LPCB.H_EC.CHRG, \_SB.PC00.LPCB.H_EC.SEN3, 1, 200, 3182, 14, 0x000A0000, "MAX",   1, 10, 10, 0},
      Package(){\_SB.PC00.LPCB.H_EC.CHRG, \_SB.PC00.LPCB.H_EC.SEN3, 1, 200, 3232, 14, 0x000A0000,     1,   1, 10, 10, 0},
      Package(){\_SB.PC00.LPCB.H_EC.CHRG, \_SB.PC00.LPCB.H_EC.SEN3, 1, 200, 3282, 14, 0x000A0000,     2,   1, 10, 10, 0},
      Package(){\_SB.PC00.LPCB.H_EC.CHRG, \_SB.PC00.LPCB.H_EC.SEN3, 1, 200, 3382, 14, 0x000A0000, "MIN",   1, 10, 10, 0}
    })
  
  }// end Scope(\_SB.IETM)



}
//#endif // FixedPcdGetBool(PcdEcEnable) == 1

// Policy support files for EC and SIO
  /** @file
    Intel ACPI Reference Code for Intel Dynamic Power Performance Management
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.IETM)
  {
  
     Name(TRT0, Package()    // TRT package when TFN1 is at 100% speed
     {
        // Source                           Target                    Influence  Period    Reserved
        Package(){\_SB.PC00.TCPU,           \_SB.PC00.LPCB.H_EC.SEN2, 40,        100,      0, 0, 0, 0},
        Package(){\_SB.PC00.LPCB.H_EC.CHRG, \_SB.PC00.LPCB.H_EC.SEN4, 20,        200,      0, 0, 0, 0}
      })
  
     Name(TRT1, Package()    // TRT package when TFN1 is at 100% speed
     {
        // Source                           Target                    Influence  Period    Reserved
        Package(){\_SB.PC00.TCPU,           \_SB.PC00.LPCB.ITE8.SEN2, 40,        100,      0, 0, 0, 0}
      })
  
      // _TRT (Thermal Relationship Table)
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   A variable-length Package containing a list of Thermal Relationship Packages as described below.
      //
      // Return Value Information
      //   Package {
      //   ThermalRelationship[0] // Package
      //    ...
      //   ThermalRelationship[n] // Package
      //   }
      //
      Method(_TRT,,,,PkgObj)
      {
        If (LEqual(ECON,1))
        {
          Return(TRT0)
        } Else {
          Return(TRT1)
        }
      } // End _TRT
  }

  /** @file
    Intel ACPI Reference Code for Intel Dynamic Power Performance Management
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  
  Scope(\_SB.IETM)
  {
  
      Name(ART1, Package()    // ART package when in Quiet Mode / Passive Cooling Mode
      {
        0, // Revision
        // Source                           Target                    Weight, AC0MaxLevel, AC1MaxLevel, AC21MaxLevel, AC31MaxLevel, AC41MaxLevel, AC51MaxLevel, AC61MaxLevel, AC71MaxLevel, AC81MaxLevel, AC91MaxLevel
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.TCPU,           100,             80,          60,           40,           30,           20,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN2, 100,             80,          60,           30,    0xFFFFFFFF,  0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN3, 100,     0xFFFFFFFF,  0xFFFFFFFF,   0xFFFFFFFF,           80,           60,           30,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN4, 100,             80,          60,           30,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN5, 100,             80,          60,           30,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
      })
  
      Name(ART0, Package()    // ART package when in Performance Mode / Active Cooling Mode
      {
        0,    // Revision
        // Source                           Target                    Weight, AC0MaxLevel, AC1MaxLevel, AC21MaxLevel, AC31MaxLevel, AC41MaxLevel, AC51MaxLevel, AC61MaxLevel, AC71MaxLevel, AC81MaxLevel, AC91MaxLevel
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.TCPU,           100,            100,          80,           50,           40,           30,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN2, 100,             80,          50,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN3, 100,     0xFFFFFFFF,  0xFFFFFFFF,   0xFFFFFFFF,          100,           80,           50,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN4, 100,            100,          80,           50,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.H_EC.TFN1, \_SB.PC00.LPCB.H_EC.SEN5, 100,            100,          80,           50,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF}
      })
  
      Name(ART2, Package()    // ART package when in Performance Mode / Active Cooling Mode
      {
        0,    // Revision
        // Source                           Target                    Weight, AC0MaxLevel, AC1MaxLevel, AC21MaxLevel, AC31MaxLevel, AC41MaxLevel, AC51MaxLevel, AC61MaxLevel, AC71MaxLevel, AC81MaxLevel, AC91MaxLevel
        Package(){\_SB.PC00.LPCB.ITE8.TFN1, \_SB.PC00.TCPU,           100,            100,          80,           50,           40,           30,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF},
        Package(){\_SB.PC00.LPCB.ITE8.TFN1, \_SB.PC00.LPCB.ITE8.SEN1, 100,             80,          50,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF,   0xFFFFFFFF}
      })
  
      // _ART (Active Cooling Relationship Table)
      //
      // Arguments:
      //   None
      // Return Value:
      //   A variable-length Package containing a Revision ID and a list of Active Relationship Packages as described below:
      //
      // Return Value Information
      //   Package {
      //   Revision, // Integer - Current revision is: 0
      //   ActiveRelationship[0] // Package
      //   ...
      //   ActiveRelationship[n] // Package
      //   }
      //
      Method(_ART,,,,PkgObj)
      {
        If (LEqual(ECON,1))
        {
          If(\_SB.PC00.LPCB.H_EC.SEN3.CTYP)
          {
            Return(ART1)
          } Else {
            Return(ART0)
          }
        } Else {
          Return(ART2)
        }
      } // End _ART
  }


//
// DPTF Helper functions.
//
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.IETM)
  {
      // KTOC (Kelvin to Celsius)
      //
      // This control method converts from 10ths of degree Kelvin to Celsius.
      //
      // Arguments: (1)
      //   Arg0 - Temperature in 10ths of degree Kelvin
      // Return Value:
      //   Temperature in Celsius
      //
      Method(KTOC,1,Serialized)
      {
        If(LGreater(Arg0,2732)) // make sure we have a temperature above zero Celcius
        {
          Return(Divide(Subtract(Arg0, 2732), 10))
        } Else {
          Return(0) // negative temperatures Celcius are changed to 0 degrees Celcius
        }
      }
  
      // CTOK (Celsius to Kelvin)
      //
      // This control method converts from Celsius to 10ths of degree Kelvin.
      //
      // Arguments: (1)
      //   Arg0 - Temperature in Celsius
      // Return Value:
      //   Temperature in 10ths of degree Kelvin
      //
      Method(CTOK,1,Serialized)
      {
        Return(Add(Multiply(Arg0,10),2732))
      }
  
      // C10K (Celsius to Kelvin)
      //
      // This control method converts from 10ths of degree Celsius (16 bit signed) to 10ths of degree Kelvin.
      // This method works only for temperatures upto absolute 0 Kelvin.
      //
      // Arguments: (1)
      //   Arg0 - Temperature in 10ths of degree Celsius (16 bit signed value)
      // Return Value:
      //   Temperature in 10ths of degree Kelvin
      //
      Method(C10K,1,Serialized)
      {
        Name(TMP1, Buffer(16) {0})
        CreateByteField(TMP1, 0x00, TMPL)
        CreateByteField(TMP1, 0x01, TMPH)
  
        Add(Arg0, 2732, Local0)
        Store(And(Local0,0xFF),TMPL)
        Store(ShiftRight(And(Local0,0xFF00),0x8),TMPH)
  
        ToInteger(TMP1, Local1)
        Return(Local1)
  
      }
  
      // K10C (Kelvin to Celsius)
      //
      // This control method converts from 10ths of degree Kelvin to 10ths of degree Celsius (16 bit signed).
      // This method works only for temperatures upto 0 degree celsius. Temperatures below 0 deg celsius are changed to 0 deg C.
      //
      // Arguments: (1)
      //   Arg0 - Temperature in 10ths of degree Kelvin
      // Return Value:
      //   Temperature in 10ths of degree Celsius (16 bit signed value)
      //
      Method(K10C,1,Serialized)
      {
        If(LGreater(Arg0,2732)) // make sure we have a temperature above zero Celcius
        {
          Return(Subtract(Arg0, 2732))
        } Else {
          Return(0) // negative temperatures Celcius are changed to 0 degrees Celcius
        }
  
      }
  }



//
// Processor participant.
//
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  External (\_SB.PC00.LPCB.H_EC.UVTH, FieldUnitObj)
  
  Scope(\_SB.PC00.TCPU) // SA Thermal Device
  {
      // PFLG
      //   0 - Default, participant is on the main board
      //   1 - Participant device is on the docking station
      //   2 - Participant device is on the detachable base
      //   3 - Participant device is an external device (such as a USB device, Intel(R) Dynamic Tuning Technology does not support this type of device today)
      Name(PFLG, 0)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If (LEqual(\SADE,1)){
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      //
      // Define an OpRegion for the Intel(R) Dynamic Tuning Technology MSR's accessed via MCHBAR+0x5000
      //
      OperationRegion (CPWR, SystemMemory, Add(ShiftLeft(\_SB.PC00.MC.MHBR,15),0x5000), 0x1000)
        Field (CPWR, ByteAcc, NoLock, Preserve)
        {
          Offset (0x930), // PACKAGE_POWER_SKU (MCHBAR+0x5930)
          PTDP, 15,       // TDP Package Power [14:0]
          ,      1,       // reserved [15]
          PMIN, 15,       // Minimal Package Power [30:16]
          ,      1,       // Reserved [31]
          PMAX, 15,       // Maximal Package Power [46:32]
          ,      1,       // Reserved [47]
          TMAX,  7,       // Maximal Time Window [54:48]
          Offset (0x938), // PACKAGE_POWER_SKU_UNIT (MCHBAR+0x5938)
          PWRU,  4,       // Power Units [3:0]
          ,      4,       // Reserved [7:4]
          EGYU,  5,       // Energy Units [12:8]
          ,      3,       // Reserved [15:13]
          TIMU,  4,       // Time Units [19:16]
          Offset (0x958), // PLATFORM_INFO (MCHBAR+0x5958)
              , 32,       // [31:0]
          LPMS,  1,       // LPM Support [32]
          CTNL,  2,       // CONFIG_TDP_NUM_LEVELS [34:33]
          Offset(0x978),
          PCTP,  8,       // Package Temperature.(MCHBAR+ 0x5978)
          Offset (0x998), // RP_STATE_CAP_0_0_0_MCHBAR_PCU (MCHBAR+0x5998)
          RP0C,  8,       // [7:0] RP0_CAP,  These fields indicate the maximum RPx base frequency capability for the Integrated GFX Engine (GT).
          RP1C,  8,       // [15:8] RP1_CAP,  Values are in units of 100 MHz.
          RPNC,  8,       // [23:16] RPN_CAP
          Offset (0xF3C), // CONFIG_TDP_NOMINAL (MCHBAR+0x5F3C)
          TRAT,  8,       // TDP Ratio [7:0]
          Offset (0xF40), // CONFIG_TDP_LEVEL1 (MCHBAR+0x5F40)
          PTD1, 15,       // Package TDP [14:0]
          ,      1,       // reserved [15]
          TRA1,  8,       // TDP Ratio [23:16]
          ,      8,       // reserved [31:24]
          PMX1, 15,       // Package MAX Power [46:32]
          ,      1,       // reserved [47]
          PMN1, 15,       // Package MIN Power [62:48]
          Offset (0xF48), // CONFIG_TDP_LEVEL2 (MCHBAR+0x5F48)
          PTD2, 15,       // Package TDP [14:0]
          ,      1,       // reserved [15]
          TRA2,  8,       // TDP Ratio [23:16]
          ,      8,       // reserved [31:24]
          PMX2, 15,       // Package MAX Power [46:32]
          ,      1,       // reserved [47]
          PMN2, 15,       // Package MIN Power [62:48]
          Offset (0xF50), // CONFIG_TDP_CONTROL (MCHBAR+0x5F50)
          CTCL,  2,       // TDP Level [1:0]
          ,     29,       // reserved [30:2]
          CLCK,  1,       // Config TDP Lock [31]
          Offset (0xF54), // TURBO_ACTIVATION_RATIO (MCHBAR+0x5F54)
          MNTR,  8,       // Max Non Turbo Ratio [7:0]
        }
  
      Name(XPCC,0) // semaphore to record when PPCC gets called for the first time
  
      // PPCC (Participant Power Control Capabilities)
      //
      // The PPCC object evaluates to a package of packages that indicates to Intel(R) Dynamic Tuning Technology processor
      // participant the power control capabilities.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   PPCC package of packages
      //
      Method(PPCC,0,Serialized,,PkgObj)
      {
        If(LAnd(LEqual(XPCC,0),CondRefOf(\_SB.CBMI))){
          Switch(ToInteger(\_SB.CBMI)){ // use the boot index from PPM to choose the PL for PPCC
            case(0){
              If(LAnd(LGreaterEqual(\_SB.CLVL,1),LLessEqual(\_SB.CLVL,3))){
                CPL0() // copy PL0 values to PPCC
                Store(1,XPCC)
              }
            }
            case(1){
              If(LOr(LEqual(\_SB.CLVL,2),LEqual(\_SB.CLVL,3))){
                CPL1() // copy PL1 values to PPCC
                Store(1,XPCC)
              }
            }
            case(2){
              If(LEqual(\_SB.CLVL,3)){
                CPL2() // copy PL2 values to PPCC
                Store(1,XPCC)
              }
            }
          }
        }
        Return(NPCC)
      }
  
      // PPCC (Participant Power Control Capabilities)
      //
      // The PPCC object evaluates to a package of packages that indicates to Intel(R) Dynamic Tuning Technology processor
      // participant the power control capabilities.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   PPCC package of packages
      //
      // PPCC will be initialized by the _INI method with power on default values from the PPM code.
      //
      Name (NPCC, Package()
      {                          // Field Name : Field Type
        2,                       // Revision : DWordConst
  
        Package ()               // Power Limit 1
        {
          0,                     // PowerLimitIndex : DWordConst = 0
          35000,                 // PowerLimitMinimum : DWordConst
          45000,                 // PowerLimitMaximum : DWordConst
          28000,                 // TimeWindowMinimum : DWordConst
          32000,                 // TimeWindowMaximum : DWordConst
          1000                   // StepSize : DWordConst
        },
        Package ()               // Power Limit 2
        {
          1,                     // PowerLimitIndex : DWordConst = 1
          56250,                 // PowerLimitMinimum : DWordConst
          56250,                 // PowerLimitMaximum : DWordConst
          0,                     // TimeWindowMinimum : DWordConst
          0,                     // TimeWindowMaximum : DWordConst
          1000                   // StepSize : DWordConst
        }
      }) // End of PPCC object
  
      // CPNU (Convert Power Number from MMIO register to correct Units)
      //
      // Arguments: (1)
      //   Arg0 = Number to be converted
      //   Arg1 = Units desired
      //     0 = Watts
      //     1 = MilliWatts
      // Return Value:
      //   Converted integer
      //
      Method(CPNU,2,Serialized,,IntObj)
      {
        Name(CNVT,0) // converted number
        Name(PPUU,0) // units
        Name(RMDR,0) // remainder
  
        if (LEqual(PWRU,0)) {  // use PACKAGE_POWER_SKU_UNIT - Power Units[3:0]
          Store(1,PPUU)
        } else {
          ShiftLeft(Decrement(PWRU),2,PPUU) // get units
        }
        Divide(Arg0,PPUU,RMDR,CNVT) // convert Arg0 to Watts
  
        if(LEqual(Arg1,0)){
          Return(CNVT)              // return in watts
        } else {
          Multiply(CNVT,1000,CNVT)  // convert to milliwatts
          Multiply(RMDR,1000,RMDR)  // convert remainder to a useful integer
          Divide(RMDR,PPUU,,RMDR)   // convert remainder to watts
          Add(CNVT,RMDR,CNVT)       // add the integer part and the fraction part together
          Return(CNVT)              // return in milliwatts
        }
      }
  
      // CPL0 (Copy PL0 power limits to PPCC)
      //
      // Arguments:
      //   None
      // Return Value:
      //   None
      //
      Method(CPL0,0)
      {
        Store (2,Index(\_SB.PC00.TCPU.NPCC,0))                                         // Revision
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),0))                       // PowerLimitIndex
        Store (125,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),1))                     // PowerLimitMinimum
        Store (CPNU(\_SB.PL10,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),2))       // PowerLimitMaximum
        Multiply (\_SB.PLW0,1000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),3))       // TimeWindowMinimum
        Add (Multiply(\_SB.PLW0,1000),4000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),4))// TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),5))                    // StepSize
        Store (1,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),0))                       // PowerLimitIndex
        Store (CPNU(\_SB.PL20,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),1))       // PowerLimitMinimum
        Store (CPNU(\_SB.PL20,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),2))       // PowerLimitMaximum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),3))                       // TimeWindowMinimum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),4))                       // TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),5))                    // StepSize
      }
  
      // CPL1 (Copy PL1 power limits to PPCC)
      //
      // Arguments:
      //   None
      // Return Value:
      //   None
      //
      Method(CPL1,0)
      {
        Store (2,Index(\_SB.PC00.TCPU.NPCC,0))                                         // Revision
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),0))                       // PowerLimitIndex
        Store (125,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),1))                     // PowerLimitMinimum
        Store (CPNU(\_SB.PL11,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),2))       // PowerLimitMaximum
        Multiply (\_SB.PLW1,1000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),3))       // TimeWindowMinimum
        Add (Multiply(\_SB.PLW1,1000),4000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),4))// TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),5))                    // StepSize
        Store (1,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),0))                       // PowerLimitIndex
        Store (CPNU(\_SB.PL21,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),1))       // PowerLimitMinimum
        Store (CPNU(\_SB.PL21,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),2))       // PowerLimitMaximum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),3))                       // TimeWindowMinimum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),4))                       // TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),5))                    // StepSize
      }
  
      // CPL2 (Copy PL2 power limits to PPCC)
      //
      // Arguments:
      //   None
      // Return Value:
      //   None
      //
      Method(CPL2,0)
      {
        Store (2,Index(\_SB.PC00.TCPU.NPCC,0))                                         // Revision
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),0))                       // PowerLimitIndex
        Store (125,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),1))                     // PowerLimitMinimum
        Store (CPNU(\_SB.PL12,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),2))       // PowerLimitMaximum
        Multiply (\_SB.PLW2,1000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),3))       // TimeWindowMinimum
        Add (Multiply(\_SB.PLW2,1000),4000,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),4))// TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,1)),5))                    // StepSize
        Store (1,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),0))                       // PowerLimitIndex
        Store (CPNU(\_SB.PL22,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),1))       // PowerLimitMinimum
        Store (CPNU(\_SB.PL22,1),Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),2))       // PowerLimitMaximum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),3))                       // TimeWindowMinimum
        Store (0,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),4))                       // TimeWindowMaximum
        Store (PPSZ,Index(DerefOf(Index(\_SB.PC00.TCPU.NPCC,2)),5))                    // StepSize
      }
  
      Name (LSTM,0)            // Last temperature reported
  
      // _PPC (Performance Present Capabilities)
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the range of states supported
      //   0 - States 0 through nth state are available (all states available)
      //   1 - States 1 through nth state are available
      //   2 - States 2 through nth state are available
      //   ...
      //   n - State n is available only
      //
      Name(_PPC,0)
  
      // SPPC (Set Participant Performance Capability)
      //
      // SPPC is a control method object that takes one integer parameter that will indicate the maximum allowable
      // P-State for OSPM to use at any given time.
      //
      // Arguments: (1)
      //   Arg0 - integer
      // Return Value:
      //   None
      //
      Method(SPPC,1,Serialized)
      {
        If (CondRefOf(\_SB.CPPC)){
          Store(Arg0, \_SB.CPPC) // Note: \_SB.CPPC must be an Integer not a Method
        }
  
        If (LGreater(ToInteger(\TCNT),0)) {
          Notify(\_SB.PR00, 0x80)  // Tell PR00 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),1)) {
          Notify(\_SB.PR01, 0x80)  // Tell PR01 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),2)) {
          Notify(\_SB.PR02, 0x80)  // Tell PR02 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),3)) {
          Notify(\_SB.PR03, 0x80)  // Tell PR03 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),4)) {
          Notify(\_SB.PR04, 0x80)  // Tell PR04 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),5)) {
          Notify(\_SB.PR05, 0x80)  // Tell PR05 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),6)) {
          Notify(\_SB.PR06, 0x80)  // Tell PR06 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),7)) {
          Notify(\_SB.PR07, 0x80)  // Tell PR07 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),8)) {
          Notify(\_SB.PR08, 0x80)  // Tell PR08 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),9)) {
          Notify(\_SB.PR09, 0x80)  // Tell PR09 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),10)) {
          Notify(\_SB.PR10, 0x80)  // Tell PR10 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),11)) {
          Notify(\_SB.PR11, 0x80)  // Tell PR11 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),12)) {
          Notify(\_SB.PR12, 0x80)  // Tell PR12 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),13)) {
          Notify(\_SB.PR13, 0x80)  // Tell PR13 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),14)) {
          Notify(\_SB.PR14, 0x80)  // Tell PR14 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),15)) {
          Notify(\_SB.PR15, 0x80)  // Tell PR15 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),16)) {
          Notify(\_SB.PR16, 0x80)  // Tell PR16 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),17)) {
          Notify(\_SB.PR17, 0x80)  // Tell PR17 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),18)) {
          Notify(\_SB.PR18, 0x80)  // Tell PR18 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),19)) {
          Notify(\_SB.PR19, 0x80)  // Tell PR19 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),20)) {
          Notify(\_SB.PR20, 0x80)  // Tell PR20 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),21)) {
          Notify(\_SB.PR21, 0x80)  // Tell PR21 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),22)) {
          Notify(\_SB.PR22, 0x80)  // Tell PR22 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),23)) {
          Notify(\_SB.PR23, 0x80)  // Tell PR23 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),24)) {
          Notify(\_SB.PR24, 0x80)  // Tell PR24 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),25)) {
          Notify(\_SB.PR25, 0x80)  // Tell PR25 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),26)) {
          Notify(\_SB.PR26, 0x80)  // Tell PR26 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),27)) {
          Notify(\_SB.PR27, 0x80)  // Tell PR27 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),28)) {
          Notify(\_SB.PR28, 0x80)  // Tell PR28 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),29)) {
          Notify(\_SB.PR29, 0x80)  // Tell PR29 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),30)) {
          Notify(\_SB.PR30, 0x80)  // Tell PR30 driver to re-eval _PPC
        }
        If (LGreater(ToInteger(\TCNT),31)) {
          Notify(\_SB.PR31, 0x80)  // Tell PR31 driver to re-eval _PPC
        }
      }
  
      // SPUR (Set _PUR)
      //
      // This object takes an integer as argument that indicates the number of Logical processors that
      // must be idled by the OSPM. This object's implementation must modify the NumProcessors field
      // of the _PUR object implemented in the processor aggregator object definition and also must
      // notify the processor aggregator object with code 0x80 to allow the OSPM to re-evaluate _PUR.
      //
      // Arguments: (1)
      //   number of Logical processors that that must be idled by the OSPM
      // Return Value:
      //   None
      //
      Method(SPUR,1,,,IntObj)
      {
        If(LLessEqual(Arg0,\TCNT)){ // bounds check the argument
          If(LEqual(\_SB.PAGD._STA, 0x0F)){ // check if _PUR is enabled
            Store(Arg0, Index(\_SB.PAGD._PUR, 1))
            Notify (\_SB.PAGD, 0x80)
          }
        }
      }
  
      // PCCC (Participant Current Control Capabilities)
      //
      // The PCCC object evaluates to a package of packages that indicates to Intel(R) Dynamic Tuning Technology processor participant the Icc control capabilities.
      //
      // Arguments: (0)
      //   None
      //
      // Return Value:
      //   A package of packages as described below:
      //
      //    Package()
      //    {
      //      0x80000000,       // DWordConst, Revision
      //      Package ()
      //      {
      //        0x80000000,     // DWordConst, CurrentLimitMinimum in milli Amps
      //        0x80000000,     // DWordConst, CurrentLimitMaximum in milli Amps
      //      }
      //    }
      Method(PCCC,0,Serialized,,PkgObj)
      {
        Store (1,Index(PCCX,0))  // Revision
        Switch(ToInteger(CPNU(PTDP,0))){    // SKU check
          case(57){
            Store (43000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (95000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          case(47){
            Store (39000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (85000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          case(37){
            Store (29000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (55000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          case(25){
            Store (16000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (32000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          case(15){
            Store (14000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (32000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          case(11){
            Store (14000,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (25000,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
          Default{ // UNKNOWN SKU
            Store (0xFF,Index(DerefOf(Index(PCCX,1)),0))       // CurrentLimitMinimum
            Store (0xFF,Index(DerefOf(Index(PCCX,1)),1))       // CurrentLimitMaximum
          }
        } // End of Switch(PTDP)
  
        Return(PCCX)
      } // End of PCCC object
  
      // PCCX (Participant Current Control Capabilities temp structure)
      //
      // This is used to pass data from the PCCC object to the PDRT object.
      //
      Name (PCCX, Package()
      {
        0x80000000,       // DWordConst, Revision
  
        Package ()
        {
          0x80000000,     // DWordConst, CurrentLimitMinimum
          0x80000000      // DWordConst, CurrentLimitMaximum
        }
      }) // End of PCCC object
  
      // KEFF (VR efficiency Table)
      //
      // This object evaluates to a package of packages that indicates the VR efficiency factor for various processor power.
      //
      // Arguments: (0)
      //   None
      //
      // Return Value:
      //   A package of packages.
      //
      Name(KEFF, Package()
      {
        // Processor PMAX, Efficiency
        Package () {444, 0},
        Package () {463, 39},
        Package () {481, 75},
        Package () {499, 108},
        Package () {518, 139},
        Package () {536, 168},
        Package () {554, 195},
        Package () {573, 221},
        Package () {591, 244},
        Package () {609, 267},
        Package () {628, 287},
        Package () {812, 445},
        Package () {983, 551},
        Package () {1163, 621},
        Package () {1342, 673},
        Package () {1527, 710},
        Package () {1704, 742},
        Package () {1885, 767},
        Package () {2072, 785},
        Package () {2255, 802},
        Package () {6044, 897},
        Package () {11740, 924},
        Package () {17576, 926},
        Package () {23605, 919},
        Package () {29821, 909},
        Package () {36223, 898},
        Package () {42856, 886},
        Package () {49723, 873},
        Package () {56870, 858},
        Package () {64380, 842}
      })
  
      Name (CEUP, Package()
      {
        0x80000000,
        0x80000000,
        0x80000000,
        0x80000000,
        0x80000000,
        0x80000000
      })
  
      // _TMP (Temperature)
      //
      // This control method returns the thermal zone's current operating temperature.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the current temperature of the thermal zone (in tenths of degrees Kelvin)
      //
      Method(_TMP,0,Serialized)
      {
        Return((\_SB.IETM.CTOK(PCTP)))
      }
  
      // _DTI (Device Temperature Indication)
      //
      // Conveys the temperature of a device's internal temperature sensor to the platform when a temperature trip point
      // is crossed or when a meaningful temperature change occurs.
      //
      // Arguments: (1)
      //   Arg0 - An Integer containing the current value of the temperature sensor (in tenths Kelvin)
      // Return Value:
      //   None
      //
      Method(_DTI, 1)
      {
        Store(Arg0,LSTM)
        Notify(\_SB.PC00.TCPU, 0x91) // notify the participant of a trip point change event
      }
  
      // _NTT (Notification Temperature Threshold)
      //
      // Returns the temperature change threshold for devices containing native temperature sensors to cause
      // evaluation of the _DTI object
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the temperature threshold in tenths of degrees Kelvin.
      //
      Method(_NTT, 0)
      {
        Return(2782)  // 5 degree Celcius, this could be a platform policy with setup item
      }
  
      Name(PTYP, 0x00)
  
      // _PSS (Performance Supported States)
      //
      // This optional object indicates to OSPM the number of supported processor performance states that any given system can support.
      //
      // Arguments: (1)
      //   None
      // Return Value:
      //   A variable-length Package containing a list of Pstate sub-packages as described below
      //
      // Return Value Information
      //   Package {
      //   PState [0] // Package - Performance state 0
      //   ....
      //   PState [n] // Package - Performance state n
      //   }
      //
      //   Each Pstate sub-Package contains the elements described below:
      //   Package {
      //     CoreFrequency     // Integer (DWORD)
      //     Power             // Integer (DWORD)
      //     Latency           // Integer (DWORD)
      //     BusMasterLatency  // Integer (DWORD)
      //     Control           // Integer (DWORD)
      //     Status            // Integer (DWORD)
      //   }
      //
      // Stub for the Actual CPU _PSS method.
      //
      Method(_PSS,,,,PkgObj)
      {
        If(CondRefOf(\_SB.PR00._PSS))
        { // Ensure _PSS is present
          Return(\_SB.PR00._PSS())
        } Else {
          Return(Package()
            {
              Package(){0,0,0,0,0,0},
              Package(){0,0,0,0,0,0}
            }
          )
        }
      }
  
      // _TSS (Throttling Supported States)
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   A variable-length Package containing a list of Tstate sub-packages as described below
      //
      // Return Value Information
      //   Package {
      //   TState [0] // Package - Throttling state 0
      //   ....
      //   TState [n] // Package - Throttling state n
      //   }
      //
      //   Each Tstate sub-Package contains the elements described below:
      //   Package {
      //     Percent // Integer (DWORD)
      //     Power   // Integer (DWORD)
      //     Latency // Integer (DWORD)
      //     Control // Integer (DWORD)
      //     Status  // Integer (DWORD)
      //   }
      //
      Method(_TSS,)
      {
        If(CondRefOf(\_SB.PR00._TSS))
        { // Ensure _TSS is present
          Return(\_SB.PR00._TSS())
        } Else {
          Return(Package()
            {
              Package(){1,0,0,0,0}
            }
          )
        }
      }
  
      // _TPC (Throttling Present Capabilities)
      //
      // This optional object is a method that dynamically indicates to OSPM the number of throttling states currently supported by the platform.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the number of states supported:
      //   0 - states 0 .. nth state available (all states available)
      //   1 - state 1 .. nth state available
      //   2 - state 2 .. nth state available
      //   ...
      //   n - state n available only
      //
      Method(_TPC)
      {
        If(CondRefOf(\_SB.PR00._TPC))
        { // Ensure _TPC is present
          Return(\_SB.PR00._TPC)
        } Else {
          Return(0)
        }
      }
  
      // _PTC (Processor Throttling Control)
      //
      // _PTC is an optional object that defines a processor throttling control interface alternative to the I/O address spaced-based P_BLK throttling control register (P_CNT)
      //
      //  PF00[2] = ACPI object indicating if OSPM is capable of direct access to On Demand throttling MSR
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   A Package as described below
      //
      // Return Value Information
      //   Package {
      //     ControlRegister // Buffer (Resource Descriptor)
      //     StatusRegister // Buffer (Resource Descriptor)
      //   }
      //
      Method(_PTC,,,,PkgObj)
      {
        If(LAnd(CondRefOf(\PF00),LNotEqual(\PF00,0x80000000))) // is object present and initialized?
        {
          If(And(\PF00, 0x0004)) { // does OS support MSR interface?
            Return(Package() {
            ResourceTemplate(){Register(FFixedHW, 0, 0, 0)},
            ResourceTemplate(){Register(FFixedHW, 0, 0, 0)} }) // if OS supports MSR interface
          } Else {
            Return(Package() {
            ResourceTemplate(){Register(SystemIO, 5, 0, PCH_ACPI_PBLK)},
            ResourceTemplate(){Register(SystemIO, 5, 0, PCH_ACPI_PBLK)} }) // if OS support IO based interface
          }
        } Else {
          Return(Package() {
          ResourceTemplate(){Register(FFixedHW, 0, 0, 0)},
          ResourceTemplate(){Register(FFixedHW, 0, 0, 0)} }) // if object is not present or not initialized then return MSR interface
        }
      }
  
      // _TSD (T-State Dependency)
      //
      // This optional object provides T-state control cross logical processor dependency information to OSPM.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   A variable-length Package containing a list of T-state dependency Packages as described below.
      //
      // Return Value Information
      //   Package {
      //     NumEntries    // Integer
      //     Revision      // Integer (BYTE)
      //     Domain        // Integer (DWORD)
      //     CoordType     // Integer (DWORD)
      //     NumProcessors // Integer (DWORD)
      //   }
      //
      Method(_TSD,)
      {
        If(CondRefOf(\_SB.PR00._TSD))
        { // Ensure _TSD is present
          Return(\_SB.PR00._TSD())
        } Else {
          Return(Package()
            {
              Package(){5,0,0,0xFC,0}
            }
          )
        }
      }
  
      // _TDL (T-state Depth Limit)
      //
      // This optional object evaluates to the _TSS entry number of the lowest power throttling state that OSPM may use.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the Throttling Depth Limit _TSS entry number:
      //   0 - throttling disabled.
      //   1 - state 1 is the lowest power T-state available.
      //   2 - state 2 is the lowest power T-state available.
      //   ...
      //   n - state n is the lowest power T-state available.
      //
      Method(_TDL)
      {
        If(LAnd(CondRefOf(\_SB.PR00._TSS),CondRefOf(\_SB.CFGD)))
        { // Ensure _TSS is present
          If(And(\_SB.CFGD, PPM_TSTATE_FINE_GRAINED))
          {
            Return(Subtract(SizeOf(\_SB.PR00.TSMF),1))
          } Else {
            Return(Subtract(SizeOf(\_SB.PR00.TSMC),1))
          }
        } Else {
          Return(0)
        }
      }
  
      // _PDL (P-state Depth Limit)
      //
      // This optional object evaluates to the _PSS entry number of the lowest performance P-state
      // that OSPM may use when performing passive thermal control.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the P-state Depth Limit _PSS entry number:
      //   Integer containing the P-state Depth Limit _PSS entry number:
      //   0 - P0 is the only P-state available for OSPM use
      //   1 - state 1 is the lowest power P-state available
      //   2 - state 2 is the lowest power P-state available
      //   ...
      //   n - state n is the lowest power P-state available
      //
      Method(_PDL)
      {
        If(CondRefOf(\_SB.PR00._PSS))
        { // Ensure _PSS is present
          //
          // \_SB.OSCP[10] = Platform-Wide OS Capable for no limit 16 P-states
          //
          If(And(\_SB.OSCP, 0x0400))
          {
            Return(Subtract(SizeOf(\_SB.PR00.TPSS),1))
          } Else {
            Return(Subtract(SizeOf(\_SB.PR00.LPSS),1))
          }
        } Else {
          Return(0)
        }
      }
  
      // Default values for Tjmax.
      Name (TJMX,110)  // Tjmax to calculate ACx trip point
  
      // _TSP (Thermal Sampling Period)
      //
      // Sets the polling interval in 10ths of seconds. A value of 0 tells the driver to use interrupts.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing the polling rate in tenths of seconds.
      //   A value of 0 will specify using interrupts through the ACPI notifications.
      //
      //   The granularity of the sampling period is 0.1 seconds. For example, if the sampling period is 30.0
      //   seconds, then _TSP needs to report 300; if the sampling period is 0.5 seconds, then it will report 5.
      //
      Method(_TSP,0,Serialized)
      {
        // OxMs can change this to a non-zero value if the polling is desired
        Return(0)
      }
  
      // _ACx (Active Cooling)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary
      // x is a value between 0 and 9 that designates multiple active cooling levels of the thermal zone.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC0,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(TJMX),Local1) // Tjmax
        Subtract(Local1, 10, Local1)       // AC0 = Tjmax-10
  
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _ACx (Active Cooling)
      //
      // This optional object, if present under a thermal zone, returns the
      //  temperature trip point at which OSPM must start or stop Active cooling,
      //  where x is a value between 0 and 9 that designates multiple active cooling levels of the thermal zone.
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the active cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_AC1,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(TJMX),Local1) // Tjmax
        Subtract(Local1, 30, Local1)       // AC1 = AC0-20 or  Tjmax-30
  
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      Method(_AC2,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(TJMX),Local1) // Tjmax
        Subtract(Local1, 40, Local1)       // AC2 = AC0-30 or  Tjmax-40
  
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      Method(_AC3,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(TJMX),Local1) // Tjmax
        Subtract(Local1, 55, Local1)       // AC3 = AC0-45 or  Tjmax-55
  
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      Method(_AC4,0,Serialized)
      {
        Store(\_SB.IETM.CTOK(TJMX),Local1) // Tjmax
        Subtract(Local1, 70, Local1)       // AC4 = AC0-60 or  Tjmax-70
  
        If(LGreaterEqual(LSTM,Local1))
        {
          Return(Subtract(Local1,20)) // subtract 2 degrees which is the Hysteresis
        }
        Else
        {
          Return(Local1)
        }
      }
  
      // _PSV (Passive)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the passive cooling temperature threshold in tenths of degrees Kelvin
      //
      Method(_PSV,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(TJMX)) // passive Cooling Policy
      }
  
      // _CRT (Critical Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CRT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(TJMX))
      }
  
      // _CR3 (Critical Temperature for S3/CS)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    An Integer containing the critical temperature threshold in tenths of degrees Kelvin
      //
      Method(_CR3,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(TJMX))
      }
  
      // _HOT (Hot Temperature)
      //
      // This ACPI method is optional.
      // OEM/ODM can directly set the value on Intel(R) Dynamic Tuning Technology UI for the participant
      // The value programmed here is the default value used on Intel RVP for the validation purpose.
      // OEM/ODM can set a different default value for a specific platform if necessary
      //
      //  Arguments: (0)
      //    None
      //  Return Value:
      //    The return value is an integer that represents the critical sleep threshold tenths of degrees Kelvin.
      //
      Method(_HOT,0,Serialized)
      {
        Return(\_SB.IETM.CTOK(TJMX))
      }
  
      // UVTH (Under Voltage Threshold.)
      // UVTH is a command which BIOS sends to EC. [15:0]
      //
      // Arguments: (1)
      //   Arg0 should be sent by Intel(R) Dynamic Tuning Technology driver in response to power delivery capability changes. The unit is 1mV.
      // Return Value:
      //   None
      //
      Method(UVTH,1,Serialized)
      {
        If (LAnd(LEqual(\ECON,1), LEqual(\_SB.PC00.LPCB.H_EC.ECAV,1))) // Check If EC opregion is available
        {
          \_SB.PC00.LPCB.H_EC.ECWT (Arg0, RefOf(\_SB.PC00.LPCB.H_EC.UVTH)) // power delivery capability changed
          \_SB.PC00.LPCB.H_EC.ECMD (0x17)
        }
      }
  
  }// End Scope(\_SB.PC00.TCPU)

  /** @file
    Intel ACPI Reference Code for Intel Configurable TDP
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.IETM)
  {
     Name (CTSP, Package ()
      {
      //
      // ConfigTDP Policy
      //
        ToUUID("E145970A-E4C1-4d73-900E-C9C5A69DD067")
      })
  }
  
  Scope(\_SB.PC00.TCPU)
  {
      // TDPL (Thermal Design Power List)
      //
      // Returns the list of all supported Configurable TDP points available for the participant device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   Package () // Zeroth TDP State
      //   {
      //     TDPPower, // DWordConst
      //     Frequency, // DWordConst
      //     TDPControl, // DWordConst
      //     FrequencyControl, // DWordConst
      //     Reserved1, // DWordConst
      //   },
      //     .
      //     .
      //     .
      //   Package () // Last TDP State
      //   {
      //     TDPPower, // DWordConst
      //     Frequency, // DWordConst
      //     TDPControl, // DWordConst
      //     FrequencyControl, // DWordConst
      //     Reserved1, // DWordConst
      //   }
      //
      Method(TDPL,0,Serialized,,PkgObj)
      {
          Name(AAAA,0) // PACKAGE_POWER_SKU
          Name(BBBB,0) // CONFIG_TDP_LEVEL1
          Name(CCCC,0) // CONFIG_TDP_LEVEL2
  
          Store(CTNL, Local0)  // CONFIG_TDP_NUM_LEVELS
          If(LOr(LEqual(Local0,1),LEqual(Local0,2))){ // check for CTDP support
            Store(\_SB.CLVL,Local0)  // use PPM supplied value for CTDP level
          }
          Else{
            Return(Package (){0}) // no CTDP support
          }
  
          If(LEqual(CLCK,1)){  // check the CONFIG_TDP_LOCK bit
            Store(1,Local0)
          }
  
          Store(CPNU(\_SB.PL10,1),AAAA)  // convert Custom 0 Power Limit1 to milliwatts
          Store(CPNU(\_SB.PL11,1),BBBB)  // convert Custom 1 Power Limit1 to milliwatts
          Store(CPNU(\_SB.PL12,1),CCCC)  // convert Custom 2 Power Limit1 to milliwatts
  
          //
          // Define a package of packages that contain 5 DWords.
          //
          Name (TMP1, Package (1){
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000}
          })
          Name (TMP2, Package (2){
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000},
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000}
          })
          Name (TMP3, Package (3){
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000},
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000},
              Package (){0x80000000,0x80000000,0x80000000,0x80000000,0x80000000}
          })
  
          //
          // if 3 TDP's, use PL0, PL1 and PL2 values
          //
          If(LEqual(Local0,3)){
            If (LGreater(AAAA,BBBB)){
              If (LGreater(AAAA,CCCC)){
                If (LGreater(BBBB,CCCC)){
                  // abc
                  Store(0,Local3)
                  Store(0,LEV0)
                  Store(1,Local4)
                  Store(1,LEV1)
                  Store(2,Local5)
                  Store(2,LEV2)
                  }Else{
                  // acb
                  Store(0,Local3)
                  Store(0,LEV0)
                  Store(1,Local5)
                  Store(2,LEV1)
                  Store(2,Local4)
                  Store(1,LEV2)
                }
              }Else{
                // cab
                Store(0,Local5)
                Store(2,LEV0)
                Store(1,Local3)
                Store(0,LEV1)
                Store(2,Local4)
                Store(1,LEV2)
              }
            }Else{  // b > a here
              If(LGreater(BBBB,CCCC)){
                If(LGreater(AAAA,CCCC)){
                  // bac
                  Store(0,Local4)
                  Store(1,LEV0)
                  Store(1,Local3)
                  Store(0,LEV1)
                  Store(2,Local5)
                  Store(2,LEV2)
                }Else{
                  // bca
                  Store(0,Local4)
                  Store(1,LEV0)
                  Store(1,Local5)
                  Store(2,LEV1)
                  Store(2,Local3)
                  Store(0,LEV2)
                }
              }Else{
                // cba
                Store(0,Local5)
                Store(2,LEV0)
                Store(1,Local4)
                Store(1,LEV1)
                Store(2,Local3)
                Store(0,LEV2)
              }
            }
  
            // copy for PL0
            Store(Add(\_SB.TAR0,1),Local1)
            Multiply(Local1,100,Local2)
            Store(AAAA,Index(DeRefOf(Index(TMP3, Local3)),0))
            Store(Local2,Index(DeRefOf(Index(TMP3, Local3)),1))
            Store(\_SB.CTC0,Index(DeRefOf(Index(TMP3, Local3)),2))
            Store(Local1,Index(DeRefOf(Index(TMP3, Local3)),3))
            Store(0,Index(DeRefOf(Index(TMP3, Local3)),4))
  
            // copy for PL1
            Store(Add(\_SB.TAR1,1),Local1)
            Multiply(Local1,100,Local2)
            Store(BBBB,Index(DeRefOf(Index(TMP3, Local4)),0))
            Store(Local2,Index(DeRefOf(Index(TMP3, Local4)),1))
            Store(\_SB.CTC1,Index(DeRefOf(Index(TMP3, Local4)),2))
            Store(Local1,Index(DeRefOf(Index(TMP3, Local4)),3))
            Store(0,Index(DeRefOf(Index(TMP3, Local4)),4))
  
            // copy for PL2
            Store(Add(\_SB.TAR2,1),Local1)
            Multiply(Local1,100,Local2)
            Store(CCCC,Index(DeRefOf(Index(TMP3, Local5)),0))
            Store(Local2,Index(DeRefOf(Index(TMP3, Local5)),1))
            Store(\_SB.CTC2,Index(DeRefOf(Index(TMP3, Local5)),2))
            Store(Local1,Index(DeRefOf(Index(TMP3, Local5)),3))
            Store(0,Index(DeRefOf(Index(TMP3, Local5)),4))
  
            Return(TMP3)
          }
  
          //
          // if 2 TDP's, use PL0 and PL1 values
          //
          If(LEqual(Local0,2)){
            If(LGreater(AAAA,BBBB)){
              Store(0,Local3) // store PL0 in Zeroth package
              Store(1,Local4) // store PL1 in next package
              Store(0,LEV0)
              Store(1,LEV1)
              Store(0,LEV2) // level 2 is not used so put 0 for safety
            }Else{
              Store(0,Local4) // store PL1 in Zeroth package
              Store(1,Local3) // store PL0 in next package
              Store(1,LEV0)
              Store(0,LEV1)
              Store(0,LEV2) // level 2 is not used so put 0 for safety
            }
  
            // copy for PL0
            Store(Add(\_SB.TAR0,1),Local1)
            Multiply(Local1,100,Local2)
            Store(AAAA,Index(DeRefOf(Index(TMP2, Local3)),0))
            Store(Local2,Index(DeRefOf(Index(TMP2, Local3)),1))
            Store(\_SB.CTC0,Index(DeRefOf(Index(TMP2, Local3)),2))
            Store(Local1,Index(DeRefOf(Index(TMP2, Local3)),3))
            Store(0,Index(DeRefOf(Index(TMP2, Local3)),4))
  
            // copy for PL1
            Store(Add(\_SB.TAR1,1),Local1)
            Multiply(Local1,100,Local2)
            Store(BBBB,Index(DeRefOf(Index(TMP2, Local4)),0))
            Store(Local2,Index(DeRefOf(Index(TMP2, Local4)),1))
            Store(\_SB.CTC1,Index(DeRefOf(Index(TMP2, Local4)),2))
            Store(Local1,Index(DeRefOf(Index(TMP2, Local4)),3))
            Store(0,Index(DeRefOf(Index(TMP2, Local4)),4))
  
            Return(TMP2)
          }
  
          //
          // if 1 TDP, return one PL based on boot index
          //
          If(LEqual(Local0,1)){
            Switch(ToInteger(\_SB.CBMI)){
              case(0){
                // copy for PL0
                Store(Add(\_SB.TAR0,1),Local1)
                Multiply(Local1,100,Local2)
                Store(AAAA,Index(DeRefOf(Index(TMP1, 0)),0))
                Store(Local2,Index(DeRefOf(Index(TMP1, 0)),1))
                Store(\_SB.CTC0,Index(DeRefOf(Index(TMP1, 0)),2))
                Store(Local1,Index(DeRefOf(Index(TMP1, 0)),3))
                Store(0,Index(DeRefOf(Index(TMP1, 0)),4))
                Store(0,LEV0)
                Store(0,LEV1)
                Store(0,LEV2)
              }
  
              case(1){
                // copy for PL1
                Store(Add(\_SB.TAR1,1),Local1)
                Multiply(Local1,100,Local2)
                Store(BBBB,Index(DeRefOf(Index(TMP1, 0)),0))
                Store(Local2,Index(DeRefOf(Index(TMP1, 0)),1))
                Store(\_SB.CTC1,Index(DeRefOf(Index(TMP1, 0)),2))
                Store(Local1,Index(DeRefOf(Index(TMP1, 0)),3))
                Store(0,Index(DeRefOf(Index(TMP1, 0)),4))
                Store(1,LEV0)
                Store(1,LEV1)
                Store(1,LEV2)
              }
  
              case(2){
                // copy for PL2
                Store(Add(\_SB.TAR2,1),Local1)
                Multiply(Local1,100,Local2)
                Store(CCCC,Index(DeRefOf(Index(TMP1, 0)),0))
                Store(Local2,Index(DeRefOf(Index(TMP1, 0)),1))
                Store(\_SB.CTC2,Index(DeRefOf(Index(TMP1, 0)),2))
                Store(Local1,Index(DeRefOf(Index(TMP1, 0)),3))
                Store(0,Index(DeRefOf(Index(TMP1, 0)),4))
                Store(2,LEV0)
                Store(2,LEV1)
                Store(2,LEV2)
              }
            }
  
            Return(TMP1)
          }
  
          Return(0) // we should never get here, this eliminates a compiler warning
      } // End of TDPL object
  
      //
      // Returns the max TDP configurable for the platform.
      //
      Name(MAXT,0)
  
      // TDPC (Thermal Design Power Capabilities)
      //
      // The TDPC object evaluates to an integer that identifies the maximum usable TDP point
      // from the table returned by the TDPL object at any given time.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   This value is the zero based index into the TDPL object's entries.
      //
      Method(TDPC)  // For CRB, please return 0.
      {
        Return(MAXT)    // Return valid TDP point.
      }//end Method(TDPC)
  
      Name(LEV0,0)
      Name(LEV1,0)
      Name(LEV2,0)
  
      // STDP (Set current operating TDP Point)
      //
      // The STDP object communicates to the platform BIOS the current operating TDP point whenever it is changed due to any reason.
      // In response to this object evaluation, the platform BIOS modifies the packages returned in PPCC object and notifies the driver of
      // a change in power limit capabilities as appropriate.
      //
      // Arguments: (1)
      //   Arg0 = Config TDP level selected
      //     0 = Highest Level values from MSR
      //     1 = Middle Level values from MSR
      //     2 = Lowest Level values from MSR
      //     3 = reserved
      // Return Value:
      //   None
      //
      // Currently we are using hard coded values for the PPCC values.
      // A future reference code release will use PPCC values from the PPM reference code.
      // This will allow PPCC values to be selected from SETUP options.
      //
      Method(STDP,1,Serialized)
      {
        If (LGreaterEqual(Arg0,\_SB.CLVL)){ // bounds check the input
          Return() // invalid input
        }
  
        //
        // translate requested index value to the correct PL using the sorted TDPL value.
        //
        Switch (ToInteger(Arg0)){
          Case (0) {
            Store(LEV0,Local0)
          }
          Case (1) {
            Store(LEV1,Local0)
          }
          Case (2) {
            Store(LEV2,Local0)
          }
        }
  
        Switch (ToInteger(Local0)){
          Case (0) {
            CPL0() // copy PL0 values to PPCC
          }
          Case (1) {
            CPL1() // copy PL1 values to PPCC
          }
          Case (2) {
            CPL2() // copy PL2 values to PPCC
          }
        }
  
        Notify (\_SB.PC00.TCPU, 0x83)    // Send a Power Capabilities Changed notification to self
      }//end Method(STDP)
  
  }//end Scope(\_SB.PC00.TCPU)
  


  //
  // PCH FIVR Participant
  //
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  #include <Register/PmcRegs.h>
  #include <Register/TcoRegs.h>
  
  External(IPCS, MethodObj)  // IPC Command Send (Read/Write)
  
  Scope(\_SB)
  {
    Device(TPCH)  // PCH FIVR Participant
    {
      Name(_UID, "TPCH")
      Method(_HID)
      {
        Return(\_SB.IETM.GHID(_UID))  // Intel(R) Dynamic Tuning Technology PCH Device
      }
      Name(_STR, Unicode("Intel PCH FIVR Participant"))
      Name(PTYP, 0x05)
  
      // _STA (Status)
      //
      // This object returns the current status of a device.
      //
      // Arguments: (0)
      //   None
      // Return Value:
      //   An Integer containing a device status bitmap:
      //    Bit 0 - Set if the device is present.
      //    Bit 1 - Set if the device is enabled and decoding its resources.
      //    Bit 2 - Set if the device should be shown in the UI.
      //    Bit 3 - Set if the device is functioning properly (cleared if device failed its diagnostics).
      //    Bit 4 - Set if the battery is present.
      //    Bits 5-31 - Reserved (must be cleared).
      //
      Method(_STA)
      {
        If(LEqual(\PCHE,1)) {
          Return(0x0F)
        } Else {
          Return(0x00)
        }
      }
  
      // RFC0 (Set PCH FIVR RFI value)
      //
      // Set PCH FIVR RFI Value
      //
      // Arguments:
      //   Arg0: PCH FIVR RFI Control0 Setting Value.
      // Return Value:
      //   An empty package as w/a to resolve EVAL failure in DPTF driver ESIF shell
      //
      Method(RFC0, 1, Serialized)
      {
        //
        // Need to perform Logic Write (subcommand 0x01)
        //
        IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_WRITE, 0x8, V_PMC_PWRM_IPC_SUBCMD_RFI_CTRL0_LOGIC, Arg0, 0, 0)
        Return(Package(){0})
      }
  
      // RFC1 (Set PCH FIVR RFI value)
      //
      // Set PCH FIVR RFI Value
      //
      // Arguments:
      //   Arg0: PCH FIVR RFI Control4 Setting Value.
      // Return Value:
      //   An empty package as w/a to resolve EVAL failure in DPTF driver ESIF shell
      //
      Method(RFC1, 1, Serialized)
      {
        //
        // Need to perform Logic Write (subcommand 0x01)
        //
        IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_WRITE, 0x8, V_PMC_PWRM_IPC_SUBCMD_RFI_CTRL4_LOGIC, Arg0, 0, 0)
        Return(Package(){0})
      }
  
      // SEMI (Set PCH FIVR EMI value)
      //
      // Set PCH FIVR EMI Value
      //
      // Arguments:
      //   Arg0: PCH FIVR EMI Control Setting Value.
      // Return Value:
      //   An empty package as w/a to resolve EVAL failure in DPTF driver ESIF shell
      //
      Method(SEMI, 1, Serialized)
      {
        //
        // Need to perform Logic Write (subcommand 0x01)
        //
        IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_WRITE, 0x8, V_PMC_PWRM_IPC_SUBCMD_EMI_CTRL0_LOGIC, Arg0, 0, 0)
        Return(Package(){0})
      }
  
      // PKG (Truncate Package recieved from IPC)
      //
      // Arguments:
      //   Arg0: Package returned from the IPCS read call from the Pmc.
      // Return Value:
      //   Return Package with just the Status and ReadBuf0.
      //   Status returns 0 for success and 2 for device error
      //
      Method(PKGC, 1, Serialized)
      {
        //
        // Convert to Pchp Return Package
        //
        Name(PPKG, Package (2) {
          Zero, // Status (DWORD)
          Zero  // ReadBuf0 (DWORD)
        })
        Store(DerefOf(Index(Arg0, 0)), Index(PPKG, 0))
        Store(DerefOf(Index(Arg0, 1)), Index(PPKG, 1))
        Return(PPKG)
      }
  
      // GFC0 (Get PCH FIVR RFI_CONTROL0 register)
      //
      // Get PCH FIVR RFI_CONTROL0 register
      //
      // Arguments:
      //   None.
      // Return Value:
      //   Package containing two ACPI integers- IPCS Status & PCH FIVR RFI_CONTROL0 register value
      //
      Method(GFC0, 0, Serialized)
      {
        //
        // Need to perform Logic Read (subcommand 0x00)
        //
        Store(IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_READ, 0x8, V_PMC_PWRM_IPC_SUBCMD_RFI_CTRL0_LOGIC, 0, 0, 0), Local0)
        Store(\_SB.TPCH.PKGC(Local0), Local1)
        Return(Local1)
      }
  
      // GFC1 (Get PCH FIVR RFI_CONTROL4 register)
      //
      // Get PCH FIVR RFI_CONTROL4 register
      //
      // Arguments:
      //   None.
      // Return Value:
      //   Package containing two ACPI integers- IPCS Status & PCH FIVR RFI_CONTROL4 register value
      //
      Method(GFC1, 0, Serialized)
      {
        //
        // Need to perform Logic Read (subcommand 0x00)
        //
        Store(IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_READ, 0x8, V_PMC_PWRM_IPC_SUBCMD_RFI_CTRL4_LOGIC, 0, 0, 0), Local0)
        Store(\_SB.TPCH.PKGC(Local0), Local1)
        Return(Local1)
      }
  
      // GEMI (Get PCH FIVR EMI value)
      //
      // Get PCH FIVR EMI Value
      //
      // Arguments:
      //   None.
      // Return Value:
      //   Package containing two ACPI integers- IPCS Status & PCH FIVR EMI Control Setting Value.
      //
      Method(GEMI, 0, Serialized)
      {
        //
        // Need to perform Logic Read (subcommand 0x00)
        //
        Store(IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_READ, 0x8, V_PMC_PWRM_IPC_SUBCMD_EMI_CTRL0_LOGIC, 0, 0, 0), Local0)
        Store(\_SB.TPCH.PKGC(Local0), Local1)
        Return(Local1)
      }
  
      // GFFS (Get PCH FIVR FFFC_FAULT_STATUS register)
      //
      // Get PCH FIVR FFFC_FAULT_STATUS register
      //
      // Arguments:
      //   None.
      // Return Value:
      //   Package containing two ACPI integers- IPCS Status & PCH FIVR FFFC_FAULT_STATUS register value
      //
      Method(GFFS, 0, Serialized)
      {
        //
        // Need to perform Logic Read (subcommand 0x00)
        //
        Store(IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_READ, 0x8, V_PMC_PWRM_IPC_SUBCMD_FFFC_FAULT_STATUS, 0, 0, 0), Local0)
        Store(\_SB.TPCH.PKGC(Local0), Local1)
        Return(Local1)
      }
  
      // GFCS (Get PCH FIVR FFFC_RFI_STATUS register)
      //
      // Get PCH FIVR FFFC_RFI_STATUS register
      //
      // Arguments:
      //   None.
      // Return Value:
      //   Package containing two ACPI integers- IPCS Status & PCH FIVR FFFC_RFI_STATUS register value
      //
      Method(GFCS, 0, Serialized)
      {
        //
        // Need to perform Logic Read (subcommand 0x00)
        //
        Store(IPCS(V_PMC_PWRM_IPC_CMD_COMMAND_FIVR, V_PMC_PWRM_IPC_CMD_CMD_ID_FIVR_READ, 0x8, V_PMC_PWRM_IPC_SUBCMD_FFFC_RFI_STATUS, 0, 0, 0), Local0)
        Store(\_SB.TPCH.PKGC(Local0), Local1)
        Return(Local1)
      }
  
    } // End TPCH device
  } // End Scope (\_SB)


  /** @file
    Intel ACPI Reference Code for Intel Dynamic Power Performance Management
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  Scope(\_SB.IETM)
  {
  
      //
      // DPPM Passive Policy 2.0
      //
      Name (DP2P, Package ()
      {
        ToUUID("9E04115A-AE87-4D1C-9500-0F3E340BFE75")
      })
  
      //
      // DPPM Passive Policy 1.0
      //
      Name (DPSP, Package ()
      {
        ToUUID("42A441D6-AE6A-462B-A84B-4A8CE79027D3")
      })
  
      //
      // DPPM Active Policy 1.0
      //
      Name (DASP, Package ()
      {
        ToUUID("3A95C389-E4B8-4629-A526-C52C88626BAE")
      })
  
      //
      // DPPM Active Policy 2.0
      //
      Name (DA2P, Package ()
      {
        ToUUID("0E56FAB6-BDFC-4E8C-8246-40ECFD4D74EA")
      })
  
      //
      // DPPM Critical Policy
      //
      Name (DCSP, Package ()
      {
        ToUUID("97C68AE7-15FA-499c-B8C9-5DA81D606E0A")
      })
  
      //
      // Radio Frequency Interference Mitigation
      //
      Name (RFIP, Package ()
      {
        ToUUID("C4CE1849-243A-49F3-B8D5-F97002F38E6A")
      })
  
      //
      // Power Boss Policy
      //
      Name (POBP, Package ()
      {
        ToUUID("F5A35014-C209-46A4-993A-EB56DE7530A1")
      })
  
      //
      // Adaptive Performance Policy
      //
      Name (DAPP, Package ()
      {
        ToUUID("63BE270F-1C11-48fd-A6F7-3AF253FF3E2D")
      })
  
      //
      // Virtual Sensor Policy
      //
      Name (DVSP, Package ()
      {
        ToUUID("6ED722A7-9240-48a5-B479-31EEF723D7CF")
      })
  
      //
      // PID Policy
      //
      Name (DPID, Package ()
      {
        ToUUID("42496E14-BC1B-46E8-A798-CA915464426F")
      })
  
  
  } // End Scope(\_SB.IETM)


//
// DPTF Trigger Event function.
//
  /** @file
    Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
    Used for driver debugging and validation.
  
    Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
    SPDX-License-Identifier: BSD-2-Clause-Patent
  **/
  
  External(\_SB.PC00.LPCB.H_EC.CHRG, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.DGPU, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.SEN2, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.SEN3, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.SEN4, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.SEN5, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.TFN1, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.TFN2, DeviceObj)
  External(\_SB.PC00.LPCB.H_EC.TFN3, DeviceObj)
  External(\_SB.PC00.LPCB.ITE8.TFN1, DeviceObj)
  External(\_SB.PC00.LPCB.ITE8.TFN2, DeviceObj)
  External(\_SB.PC00.LPCB.ITE8.SEN1, DeviceObj)
  External(\_SB.PC00.LPCB.ITE8.SEN2, DeviceObj)
  External(\_SB.PC00.LPCB.ITE8.SEN3, DeviceObj)
  External(\_SB.TPWR, DeviceObj)
  
  Scope(\_SB.IETM)
  {
    // TEVT (Trigger EvenT)
    // Used for Intel(R) Dynamic Tuning Technology driver debugging and validation
    // This function will generate an event of the event code as given in arg1 for the participant given in parameter arg0.
    // Arguments: (2)
    //   Arg0 - The device object name string.
    //   Arg1 - An Integer containing the notification code to be used in Notify.
    // Return Value:
    //   None
    //
    Method(TEVT,2,Serialized,,,{StrObj,IntObj})
    {
      Switch(ToInteger(Arg0))
      {
        case("IETM") {
          Notify(\_SB.IETM, Arg1) // Intel Extended Thermal Manager (Intel(R) Dynamic Tuning Technology Manager)
        }
  
        case("TCPU") {
          Notify(\_SB.PC00.TCPU, Arg1) // TCPU Participant (SA Thermal Device)
        }
  
        case("TPCH") {
          Notify(\_SB.TPCH, Arg1) // PCH FIVR Participant
        }
      }
  
      If (\ECON) {
        Switch(ToInteger(Arg0))
        {
          case("CHRG") {
            Notify(\_SB.PC00.LPCB.H_EC.CHRG, Arg1) // Charger Participant
          }
  
          case("DGPU") {
            Notify(\_SB.PC00.LPCB.H_EC.DGPU, Arg1) // Sensor Participant
          }
  
          case("SEN2") {
            Notify(\_SB.PC00.LPCB.H_EC.SEN2, Arg1) // Sensor Participant
          }
  
          case("SEN3") {
            Notify(\_SB.PC00.LPCB.H_EC.SEN3, Arg1) // Sensor Participant
          }
  
          case("SEN4") {
            Notify(\_SB.PC00.LPCB.H_EC.SEN4, Arg1) // Sensor Participant
          }
  
          case("SEN5") {
            Notify(\_SB.PC00.LPCB.H_EC.SEN5, Arg1) // Sensor Participant
          }
  
          case("TFN1") {
            Notify(\_SB.PC00.LPCB.H_EC.TFN1, Arg1) // Fan Participant
          }
  
          case("TFN2") {
            Notify(\_SB.PC00.LPCB.H_EC.TFN2, Arg1) // Fan Participant
          }
  
          case("TFN3") {
            Notify(\_SB.PC00.LPCB.H_EC.TFN3, Arg1) // Fan Participant
          }
  
          case("TPWR") {
            Notify(\_SB.TPWR, Arg1) // Power Participant
          }
        }
      } Else {
          Switch(ToInteger(Arg0))
        {
          case("SEN1") {
            Notify(\_SB.PC00.LPCB.ITE8.SEN1, Arg1) // Sensor Participant
          }
  
          case("SEN2") {
            Notify(\_SB.PC00.LPCB.ITE8.SEN2, Arg1) // Sensor Participant
          }
  
          case("SEN3") {
            Notify(\_SB.PC00.LPCB.ITE8.SEN3, Arg1) // Sensor Participant
          }
  
          case("TFN1") {
            Notify(\_SB.PC00.LPCB.ITE8.TFN1, Arg1) // Fan1 Participant
          }
  
          case("TFN2") {
            Notify(\_SB.PC00.LPCB.ITE8.TFN2, Arg1) // Fan2 Participant
          }
        }
      }
    }
  
  } // End Scope(\_SB.IETM)


Scope(\_SB.IETM)
{
  // GDDV (Get Dptf Data Vault)
  //
  // The data vault can contain APCT, APAT, and PSVT tables.
  //
  //  Arguments: (0)
  //    None
  //  Return Value:
  //    A package containing the data vault
  //
  Method(GDDV,0,Serialized,0,PkgObj)
  {
    If (LEqual(ECON,1))
    {
      Return(Package()
      {
        Buffer()
        {
          /** @file
            Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
          
            Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
            SPDX-License-Identifier: BSD-2-Clause-Patent
          **/
          0xE5,0x1F,0x94,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x67,0x64,0x64,0x76,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4F,0x45,0x4D,0x20,
          0x45,0x6D,0x62,0x65,0x64,0x64,0x65,0x64,0x20,0x44,0x61,0x74,0x61,0x56,0x61,0x75,
          0x6C,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x21,0x27,0x73,0xE6,
          0x10,0x52,0x5C,0xAC,0x87,0xA8,0x4E,0xC2,0x61,0x22,0xB7,0x21,0xF4,0xEA,0x60,0xC1,
          0x99,0xBB,0xA8,0x9F,0xA6,0x6B,0x0B,0x73,0xE1,0x42,0xC0,0x4F,0xEB,0x00,0x00,0x00,
          0x52,0x45,0x50,0x4F,0x5D,0x00,0x00,0x00,0x01,0x94,0x05,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x72,0x87,0xCD,0xFF,0x6D,0x24,0x47,0xDB,0x3D,0x24,0x92,0xB4,0x16,0x6F,
          0x45,0xD8,0xC3,0xF5,0x66,0x14,0x9F,0x22,0xD7,0xF7,0xDE,0x67,0x90,0x9A,0xA2,0x0D,
          0x39,0x25,0xAD,0xC3,0x1A,0xAD,0x52,0x0B,0x75,0x38,0xE1,0xA4,0x14,0x43,0x9C,0xF1,
          0x7A,0xD3,0x23,0x3E,0x0C,0xFD,0x9C,0xBB,0x48,0x8A,0x0C,0x3A,0x02,0xFF,0x4B,0x8D,
          0xC0,0x54,0x72,0x0C,0x61,0xE9,0x8A,0x92,0x65,0x6D,0xFB,0x84,0x3B,0x27,0xE6,0x18,
          0xDA,0x84,0x22,0xC5,0x23,0xE7,0x49,0x75,0xA1,0x99,0xC3,0x7E,0x71,0x2C,0x02,0xCC,
          0x76,0x57,0x44,0xC6,0x05,0xB7,0xEF,0x65,0xDA,0x69,0x05,0x5B,0x43,0x1F,0x9E,0x9B,
          0x04,0xF8,0x02,0xB5,0x37,0x7F,0x63,0xDC,0xD9,0x38,0xA6,0xB6,0x43,0x1F,0x4D,0x94,
          0x8C,0xF3,0xDE,0x9E,0x39,0x6D,0xF0,0x25,0x53,0xE9,0x37,0x09,0x7D,0x18,0x8A,0x76,
          0x00,0x78,0x70,0x41,0x58,0xF7,0x5C,0x92,0xD1,0xD4,0xAD,0xF7,0xE4,0xDC,0xB0,0x80,
          0x97,0x51,0xE8,0x2F,0x99,0x0F,0x54,0xB6,0xB7,0x9C,0x8E,0x3F,0xE5,0xE5,0x71,0xF5,
          0x08,0xB0,0xED,0x11,0x3A,0xBD,0xB2,0x52,0x2A,0x0B,0x55,0x39,0xE1,0x26,0x70,0x46,
          0xF8,0x75,0x3E,0x4B,0x5A,0x87,0x7B,0x63,0x03,0x3A,0xEB,0xB6,0x70,0xEC,0xCC,0x83,
          0x34,0xD4,0xF9,0xD6,0x81,0x60,0xAB,0xC9,0x29,0x0C,0xEB,0xC6,0x62,0x83,0x00

        }
      })
      } Else{
      Return(Package()
      {
        Buffer()
        {
          /** @file
            Intel ACPI Reference Code for Intel(R) Dynamic Tuning Technology
          
            Copyright (c) 2022, Intel Corporation. All rights reserved.<BR>
            SPDX-License-Identifier: BSD-2-Clause-Patent
          **/
          0xE5,0x1F,0x94,0x00,0x00,0x00,0x00,0x02,0x00,0x00,0x00,0x40,0x67,0x64,0x64,0x76,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x4F,0x45,0x4D,0x20,
          0x45,0x78,0x70,0x6F,0x72,0x74,0x65,0x64,0x20,0x44,0x61,0x74,0x61,0x56,0x61,0x75,
          0x6C,0x74,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA6,0xE3,0xF7,0x09,
          0xF8,0xB0,0xFB,0xE6,0xE9,0xFF,0x6F,0xBF,0xDF,0x33,0x62,0x4B,0xB3,0xE6,0x5F,0x8C,
          0x10,0xE0,0xCA,0xB6,0xFA,0x6E,0x04,0x52,0x9A,0x03,0x8D,0x94,0x6C,0x03,0x00,0x00,
          0x52,0x45,0x50,0x4F,0x5D,0x00,0x00,0x00,0x01,0x0F,0x34,0x00,0x00,0x00,0x00,0x00,
          0x00,0x00,0x72,0x87,0xCD,0xFF,0x6D,0x24,0x47,0xDB,0x3D,0x24,0x92,0xB4,0x16,0x6F,
          0x45,0xD8,0xC3,0xF5,0x66,0x14,0x9F,0x22,0xD7,0xF7,0xDE,0x67,0x90,0x9A,0xA2,0x0D,
          0x39,0x25,0xAD,0xC3,0x1A,0xAD,0x52,0x0B,0x75,0x38,0xE1,0xA4,0x14,0x41,0x12,0x65,
          0xE2,0x0B,0x35,0x69,0xD5,0x59,0x19,0x49,0x75,0xA5,0xC3,0x39,0x04,0x39,0x8F,0x72,
          0xCA,0x0E,0xF3,0xF5,0x27,0x62,0xD5,0x33,0xE3,0xE5,0xD7,0x0A,0xB4,0x00,0x12,0xA6,
          0x17,0xC6,0x85,0x42,0x4F,0x5A,0x70,0xB0,0x81,0xF1,0x2C,0xE6,0x1E,0xA7,0x74,0xCE,
          0xEE,0x13,0x3B,0xF0,0xAE,0x26,0x89,0x0F,0xB7,0x3F,0x5F,0xD1,0x70,0x1C,0xC7,0x93,
          0xBA,0x1B,0x61,0x3E,0x4B,0xC2,0x95,0x71,0x9F,0xD9,0x71,0x3E,0x77,0xAD,0x93,0x2F,
          0x1A,0xDA,0xE8,0xA6,0x39,0x51,0x11,0xB9,0x67,0xFB,0xAE,0x8F,0x13,0x4F,0xAB,0x40,
          0x23,0x0F,0x6F,0x0C,0x4B,0xF3,0x1B,0x5C,0xE5,0x40,0x0A,0x0D,0x57,0xC1,0x79,0x9F,
          0xB7,0x01,0x5B,0xD5,0x27,0x13,0x86,0x06,0x5E,0x77,0xE7,0x4B,0x63,0x9B,0xEB,0x00,
          0x43,0x2C,0xEA,0x40,0x1D,0x6B,0x2B,0xE0,0x53,0xA3,0x79,0x98,0x88,0x81,0xDC,0xC2,
          0xA4,0x31,0x5B,0x78,0x94,0xFA,0xE9,0xB0,0xF0,0x40,0xFD,0xE9,0xA5,0xFA,0x7C,0x3F,
          0xF9,0x48,0x45,0xCC,0xB6,0x6B,0xE3,0xF7,0xEA,0x9F,0xBF,0x48,0x6C,0x3E,0xEB,0xEF,
          0x91,0x4D,0x6B,0x77,0x82,0xAD,0x16,0x3C,0xDB,0xAD,0x7D,0x8B,0xF1,0x4D,0x7C,0xEE,
          0x60,0x06,0xF3,0x58,0x80,0x06,0x47,0x23,0xDE,0x02,0x20,0xB2,0xAF,0x05,0x21,0x45,
          0xCF,0xE7,0x08,0xA2,0xB8,0xC9,0xE2,0xB9,0xAE,0xD5,0xDE,0xCA,0x37,0xEE,0xC9,0x36,
          0xD4,0xFE,0xEF,0x86,0x84,0xBE,0x39,0x06,0x49,0x99,0xF7,0x18,0x3C,0x4A,0xC8,0xFB,
          0xAE,0x75,0xF7,0x4A,0x50,0x8F,0x43,0x8F,0x4E,0x3A,0x0D,0x2B,0xC9,0x5B,0xDB,0xD2,
          0x4D,0xC6,0x33,0x3A,0x13,0x54,0xEF,0x23,0x7E,0x18,0xAF,0x32,0x3F,0xB9,0x15,0x86,
          0xCF,0x5C,0xBC,0x13,0x14,0x16,0x7B,0xF0,0xD2,0xD1,0xFF,0x42,0x02,0x6B,0x08,0x7A,
          0x6E,0x96,0x1F,0x0C,0x6B,0xBD,0x62,0xC8,0x83,0xA9,0xB4,0x6C,0x54,0x14,0xC8,0xC9,
          0x0E,0x83,0xC0,0x86,0xDB,0x41,0x54,0x5E,0xA7,0xC4,0x71,0x49,0xFB,0xF3,0xF4,0xA3,
          0xD2,0x0D,0x26,0x69,0xD9,0x04,0xD0,0xD3,0x79,0xFE,0x98,0xE5,0x67,0xB2,0x98,0xC8,
          0x36,0x60,0x65,0xB1,0xD0,0xFE,0x7E,0xF5,0xD1,0x60,0x2F,0x88,0xA1,0x20,0xDA,0xAB,
          0xFF,0xEE,0x86,0x15,0xCF,0x9E,0x08,0xE8,0xC9,0x94,0x8C,0xC3,0xC4,0xB9,0x51,0xAC,
          0x69,0x4E,0x4D,0x74,0x5B,0x0D,0xEE,0x58,0x98,0xB7,0xB5,0x2F,0x22,0xF3,0xEB,0x31,
          0x89,0x2F,0xBD,0x85,0x3D,0xE1,0xEC,0xD1,0xE6,0xDB,0x73,0xB5,0x11,0x7B,0x65,0x0D,
          0x49,0xEC,0x9A,0x4B,0x12,0xDB,0xD8,0x08,0xA5,0x44,0x42,0x54,0x28,0x3D,0x9E,0x03,
          0x94,0x3C,0x56,0xDF,0x90,0x93,0xCC,0x9C,0xAB,0x23,0x7D,0xBB,0x8A,0x53,0x64,0x70,
          0x26,0x18,0xE7,0x98,0x43,0x47,0x06,0x67,0xF2,0x06,0x0F,0x28,0x9E,0x70,0xE5,0xFB,
          0xB0,0x70,0xD5,0xE2,0x7F,0x58,0x43,0xEF,0x9D,0x26,0xE3,0xAE,0x84,0x8E,0xB0,0x6A,
          0xB1,0xB3,0xA2,0x73,0x37,0x16,0x2C,0x1A,0xF6,0xEA,0xE6,0x7E,0x37,0xAB,0xE5,0x26,
          0x97,0x34,0xF9,0x26,0x69,0x7C,0x1E,0x37,0x92,0x79,0x57,0x16,0x07,0xD9,0xFB,0x5C,
          0x6C,0x49,0x86,0xFB,0x51,0x99,0xF1,0x3C,0x0B,0x1B,0xDB,0x7D,0xB9,0xF9,0x9E,0x67,
          0xCD,0x92,0x23,0x17,0xE5,0x3A,0x30,0xCE,0x4B,0x64,0x55,0xD1,0x90,0xB7,0x63,0x72,
          0x0C,0x9F,0x37,0xA4,0x3F,0x47,0x00,0x0E,0xEE,0x8D,0xD6,0x43,0x35,0xED,0x9A,0xEB,
          0xB3,0xD2,0xAC,0x23,0xDE,0xF4,0x8B,0xAA,0x01,0x7A,0x4B,0x08,0xDE,0xDA,0xC1,0x6C,
          0x03,0xCD,0x53,0x22,0x56,0x21,0xCD,0xDD,0x7E,0xCC,0x70,0x5F,0x42,0x29,0x07,0x73,
          0xF0,0x9B,0x37,0x25,0x7C,0x43,0xAF,0x8C,0xB3,0xB1,0xFF,0xBF,0x79,0xEB,0x55,0xD8,
          0x78,0xFC,0x0B,0xF6,0x81,0xCD,0x15,0x6F,0x0D,0xA6,0xD5,0xE9,0x3F,0x2A,0x01,0xFD,
          0x11,0x35,0x36,0x4E,0x23,0xC7,0x61,0x96,0x98,0x70,0xDC,0x78,0x53,0x6A,0xEE,0x0C,
          0x50,0x5D,0x3A,0xC6,0x54,0xCC,0x94,0x30,0x75,0xC6,0xE2,0x70,0x15,0x93,0xBB,0x8B,
          0xA0,0x92,0x18,0x0D,0x5D,0xEA,0x38,0xB4,0xE7,0xEC,0x3D,0xB8,0x85,0x71,0x1E,0x14,
          0xBE,0x6E,0xAE,0xFB,0xD6,0x5C,0x6B,0xDA,0x46,0x17,0x6F,0x16,0xD1,0xBF,0xA3,0xF9,
          0x2A,0xC2,0x73,0xE3,0x5F,0xB1,0x37,0x22,0x6E,0xE6,0x91,0xDE,0x3C,0xEB,0x5F,0x8C,
          0x0F,0x5F,0xC6,0x1C,0x1F,0xDC,0x72,0x61,0x71,0x06,0xFE,0xA8,0x36,0x42,0x50,0xE9,
          0x4B,0x4F,0x1F,0x7F,0x61,0xCD,0xC5,0x61,0x26,0xCE,0x0E,0x60,0xF2,0x6F,0x41,0xA2,
          0x2C,0x47,0xDE,0x87,0xFE,0x8C,0x6B,0xE4,0x46,0xC6,0x37,0xD6,0xC8,0x30,0xBA,0xDF,
          0x35,0xD6,0x41,0xA7,0xFC,0x23,0x6C,0xFA,0x55,0x29,0xC1,0xEA,0x25,0xF0,0xE1,0xBB,
          0x61,0x14,0x63,0xAE,0x43,0x1D,0x70,0x9D,0x06,0x80,0x60,0x33,0x8A,0x17,0x32,0x79,
          0xBE,0x8D,0x67,0x5E,0xBB,0x26,0xC3,0x8F,0xC6,0x6C,0x30,0x86,0xE8,0x99,0x6C,0x86,
          0xAA,0xFA,0x79,0xA4,0x51,0xDD,0x13,0x12,0x66,0x1E,0x47,0xEE,0x97,0x00,0x80,0x19,
          0x0B,0xDF,0xC3,0x86,0x88,0xBD,0x55,0xA3,0x2F,0xCA,0x1C,0x32,0xB6,0xE8,0x1D,0x94

        }
      })
    }
  }

  // IMOK
  //
  // IMOK to test if DPTF is OK and alive.
  //
  // Arguments: (1)
  //   Arg0 - integer
  //  Return Value: (0)
  //    An Integer containing the status of IMOK
  //
  Method(IMOK,1,,,IntObj)
  {
    //It is mainly a stub placeholder
    //OEMs can implement it in a way they choose
    Return (Arg0)
  }

} // End Scope(\_SB.IETM)


} // End SSDT
