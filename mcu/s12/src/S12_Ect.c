/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "kdk/mcu/s12/S12_Ect.h"
#include "Hw_Cfg.h"

S12Ect_ConfigType const * ECT;

void S12Ect_Init(S12Ect_ConfigType const * const ConfigPtr)
{
    ECT = ConfigPtr;

    /* Main Timer Setup */
    S12ECT_REG8(TIOS)  = ConfigPtr->TIos;
    S12ECT_REG8(TCTL1) = ConfigPtr->TCtl1;
    S12ECT_REG8(TCTL2) = ConfigPtr->TCtl2;
    S12ECT_REG8(TCTL3) = ConfigPtr->TCtl3;
    S12ECT_REG8(TCTL4) = ConfigPtr->TCtl4;
    S12ECT_REG8(TIE)   = ConfigPtr->TIe;

    /* Pulse Accus      */
    S12ECT_REG8(ICPAR) = ConfigPtr->ICpar;
    S12ECT_REG8(PACTL) = ConfigPtr->PActl;
    S12ECT_REG8(PBCTL) = ConfigPtr->PBctl;

    /* Modulus Counter  */
    S12ECT_REG8(MCCTL)     = ConfigPtr->MCctl;
    S12ECT_REG16(MCCNT)    = ConfigPtr->MCcnt;

    /*
    **  ns_per_mhz=1000
    **  cycle=ns_per_mhz/bus_clock
    **  presc=log2(timer_cycle/cycle) (if timer_cycle>cycle)
    */
    S12ECT_REG8(DLYCT) = ConfigPtr->DLyct;
    S12ECT_REG8(ICOVW) = ConfigPtr->ICovw;
    S12ECT_REG8(ICSYS) = ConfigPtr->ICsys;
    S12ECT_REG8(TFLG1) = (uint8)0xFF;     /*  Clear pending interrupts. */
    S12ECT_REG8(TFLG2) = (uint8)0x80;

    S12ECT_REG8(TSCR2) = ConfigPtr->TScr2;
    S12ECT_REG8(TSCR1) = ConfigPtr->TScr1;
}


void S12Ect_ForceOutputCompare(S12Ect_ChannelType channel)
{
    S12ECT_REG8(TCFORC) = (uint8)(1 << channel);
}


void S12Ect_SetMode(S12Ect_ChannelType channel, S12Ect_ModeType mode)
{
  UNREFERENCED_PARAMETER(channel);
  UNREFERENCED_PARAMETER(mode);
}


void S12Ect_EnableInterrupt(S12Ect_InterruptSourceType Source)
{
  UNREFERENCED_PARAMETER(Source);
}


void S12Ect_DisableInterrupt(S12Ect_InterruptSourceType Source)
{
  UNREFERENCED_PARAMETER(Source);
}


/*
** ISR-Handlers.
*/
#if defined(S12ECT_FEATURE_TIMER_OVERFLOW_INTR)
ISR1(S12Ect_TofHandler)
{
#if !defined(S12ECT_TIMER_OVERFLOW_CALLBACK)
#error Symbol S12ECT_TIMER_OVERFLOW_CALLBACK must be defined.
#else
    S12ECT_TIMER_OVERFLOW_CALLBACK();
    S12ECT_ACKNOWLEDGE_TOF_INTR();
#endif /* S12ECT_TIMER_OVERFLOW_CALLBACK */
}
#endif

#if defined(S12ECT_FEATURE_TC0_INTR)
ISR1(S12Ect_TC0Handler)
{
#if !defined(S12ECT_TC0_CALLBACK)
#error Symbol S12ECT_TC0_CALLBACK must be defined.
#else
    S12ECT_TC0_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC0_INTR();
#endif  /* S12ECT_TC0_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC0_INTR */

#if defined(S12ECT_FEATURE_TC1_INTR)
ISR1(S12Ect_TC1Handler)
{
#if !defined(S12ECT_TC1_CALLBACK)
#error Symbol S12ECT_TC1_CALLBACK must be defined.
#else
    S12ECT_TC1_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC1_INTR();
#endif  /* S12ECT_TC1_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC1_INTR */

#if defined(S12ECT_FEATURE_TC2_INTR)
ISR1(S12Ect_TC2Handler)
{
#if !defined(S12ECT_TC2_CALLBACK)
#error Symbol S12ECT_TC2_CALLBACK must be defined.
#else
    S12ECT_TC2_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC2_INTR();
#endif  /* S12ECT_TC2_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC2_INTR */

#if defined(S12ECT_FEATURE_TC3_INTR)
ISR1(S12Ect_TC3Handler)
{
#if !defined(S12ECT_TC3_CALLBACK)
#error Symbol S12ECT_TC3_CALLBACK must be defined.
#else
    S12ECT_TC3_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC3_INTR();
#endif  /* S12ECT_TC3_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC3_INTR */

#if defined(S12ECT_FEATURE_TC4_INTR)
ISR1(S12Ect_TC4Handler)
{
#if !defined(S12ECT_TC4_CALLBACK)
#error Symbol S12ECT_TC4_CALLBACK must be defined.
#else
    S12ECT_TC4_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC4_INTR();
#endif  /* S12ECT_TC4_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC4_INTR */

#if defined(S12ECT_FEATURE_TC5_INTR)
ISR1(S12Ect_TC5Handler)
{
#if !defined(S12ECT_TC5_CALLBACK)
#error Symbol S12ECT_TC5_CALLBACK must be defined.
#else
    S12ECT_TC5_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC5_INTR();
#endif  /* S12ECT_TC5_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC5_INTR */

#if defined(S12ECT_FEATURE_TC6_INTR)
ISR1(S12Ect_TC6Handler)
{
#if !defined(S12ECT_TC6_CALLBACK)
#error Symbol S12ECT_TC6_CALLBACK must be defined.
#else
    S12ECT_TC6_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC6_INTR();
#endif  /* S12ECT_TC6_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC6_INTR */

#if defined(S12ECT_FEATURE_TC7_INTR)
ISR1(S12Ect_TC7Handler)
{
#if !defined(S12ECT_TC7_CALLBACK)
#error Symbol S12ECT_TC7_CALLBACK must be defined.
#else
    S12ECT_TC7_CALLBACK();
    S12ECT_ACKNOWLEDGE_TC7_INTR();
#endif  /* S12ECT_TC7_CALLBACK */
}
#endif  /* S12ECT_FEATURE_TC7_INTR */

#if defined(S12ECT_FEATURE_MDCU_INTR)
ISR1(S12Ect_MDCUHandler)
{
#if !defined(S12ECT_MDCU_CALLBACK)
#error Symbol S12ECT_TC0_CALLBACK must be defined.
#else
    S12ECT_MDCU_CALLBACK();
    S12ECT_ACKNOWLEDGE_MDCU_INTR();
#endif  /* S12ECT_MDCU_CALLBACK */
}
#endif  /* S12ECT_FEATURE_MDCU_INTR */

#if defined(S12ECT_FEATURE_PA_INTR)
ISR1(S12Ect_PAHandler)
{
#if !defined(S12ECT_PA_CALLBACK)
#error Symbol S12ECT_PA_CALLBACK must be defined.
#else
    S12ECT_PA_CALLBACK();
    S12ECT_ACKNOWLEDGE_PA_INTR();
#endif  /* S12ECT_PA_CALLBACK */
}
#endif  /* S12ECT_FEATURE_PA_INTR */

#if defined(S12ECT_FEATURE_PAOVR_INTR)
ISR1(S12Ect_PAOVRHandler)
{
#if !defined(S12ECT_PAOVR_CALLBACK)
#error Symbol S12ECT_PAOVR_CALLBACK must be defined.
#else
    S12ECT_PAOVR_CALLBACK();
    S12ECT_ACKNOWLEDGE_PAOVR_INTR();
#endif  /* S12ECT_PAOVR_CALLBACK */
}
#endif  /* S12ECT_FEATURE_PAOVR_INTR */

#if defined(S12ECT_FEATURE_PBOVR_INTR)
ISR1(S12Ect_PBOVRHandler)
{
#if !defined(S12ECT_PBOVR_CALLBACK)
#error Symbol S12ECT_PBOVR_CALLBACK must be defined.
#else
    S12ECT_PBOVR_CALLBACK();
    S12ECT_ACKNOWLEDGE_PBOVR_INTR();
#endif  /* S12ECT_PBOVR_CALLBACK */
}
#endif  /* S12ECT_FEATURE_PBOVR_INTR */
