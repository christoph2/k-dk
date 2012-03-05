/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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

#include "HC12_Ect.h"
#include "Hw_Cfg.h"
#include "Utl.h"

/* */
/* todo: Enable/Disable-PulseAccu-A/B */
/*       SetDelayCount */
/* */

/*
** Global Variables.
*/
HC12Ect_ConfigType const * ECT;

/*
**	Global Functions.
*/
void HC12Ect_Init(HC12Ect_ConfigType const * const ConfigPtr)
{
    ECT = ConfigPtr;

    /* PortT Setup. */
    HC12ECT_REG8(PORTT)    = ConfigPtr->PortT;
    HC12ECT_REG8(DDRT)     = ConfigPtr->DdrT;

    /* Main Timer Setup */
    HC12ECT_REG8(TIOS)     = ConfigPtr->TIos;
    HC12ECT_REG8(OC7M)     = ConfigPtr->Oc7m;
    HC12ECT_REG8(OC7D)     = ConfigPtr->Oc7d;
    HC12ECT_REG8(TCTL1)    = ConfigPtr->TCtl1;
    HC12ECT_REG8(TCTL2)    = ConfigPtr->TCtl2;
    HC12ECT_REG8(TCTL3)    = ConfigPtr->TCtl3;
    HC12ECT_REG8(TCTL4)    = ConfigPtr->TCtl4;
    HC12ECT_REG8(TMSK1)    = ConfigPtr->Tmsk1;
    HC12ECT_REG8(TMSK2)    = ConfigPtr->Tmsk2;
    HC12ECT_REG8(DLYCT)    = ConfigPtr->DLyct;
    HC12ECT_REG8(ICOVW)    = ConfigPtr->ICovw;
    HC12ECT_REG8(ICSYS)    = ConfigPtr->ICsys;

    /* Pulse Accus      */
    HC12ECT_REG8(ICPAR)    = ConfigPtr->ICpar;
    HC12ECT_REG8(PACTL)    = ConfigPtr->PActl;
    HC12ECT_REG8(PBCTL)    = ConfigPtr->PBctl;

    /* Modulus Counter  */
    HC12ECT_REG8(MCCTL)    = ConfigPtr->MCctl;
    HC12ECT_REG16(MCCNT)   = ConfigPtr->MCcnt;

    /*
    **  ns_per_mhz=1000
    **  cycle=ns_per_mhz/bus_clock
    **  presc=log2(timer_cycle/cycle) (if timer_cycle>cycle)
    */
    HC12ECT_REG8(TFLG1)    = (uint8)0xFF; /* Clear pending interrupts. */
    HC12ECT_REG8(TFLG2)    = (uint8)0x80;

    HC12ECT_REG8(TSCR) = ConfigPtr->TScr;
}


void HC12Ect_ForceOutputCompare(HC12Ect_ChannelType Channel)
{
    HC12ECT_REG8(CFORC) = Utl_SetBitTab8[Channel];
}


void HC12Ect_SetChannelMode(HC12Ect_ChannelType Channel, HC12Ect_ChannelModeType Mode)
{
    if (Mode == HC12ECT_OUTPUT_COMPARE) {
        UTL_BIT_SET8(HC12ECT_REG8(TIOS), Channel);
    } else if (Mode == HC12ECT_INPUT_CAPTURE) {
        UTL_BIT_RESET8(HC12ECT_REG8(TIOS), Channel);
    } else {
        /* todo: Error-Handling! */
    }
}


void HC12Ect_SetChannelCaptureMode(HC12Ect_ChannelType Channel, HC12Ect_ChannelCaptureEdgeType CaptureEdge)
{
    uint8 edge = ((uint8)CaptureEdge) & (uint8)0x03;

    /* todo: Wir benötigen eine 'SetBitPattern' oder so Funktion!!! */
    HC12ECT_REG16(TCTL3) = 0x0000;
}


/* unc.bat:						 uncrustify --nobackup -c my.cfg -f myFile */

void HC12Ect_EnableInterrupt(HC12Ect_InterruptSourceType Source)
{
    if ((Source >= HC12ECT_INTERRUPT_SOURCE_TC0) && (Source <= HC12ECT_INTERRUPT_SOURCE_TC7)) {
        UTL_BIT_SET8(HC12ECT_REG8(TMSK1), Source);
    } else {
        switch (Source) {
            case HC12ECT_INTERRUPT_SOURCE_TOF:
                UTL_BIT_SET8(HC12ECT_REG8(TMSK2), TOI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_MDCU:
                UTL_BIT_SET8(HC12ECT_REG8(MCCTL), MCZI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PAOVR:
                UTL_BIT_SET8(HC12ECT_REG8(PACTL), PAOVI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PA:
                UTL_BIT_SET8(HC12ECT_REG8(PACTL), PAI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PBOVR:
                UTL_BIT_SET8(HC12ECT_REG8(PBCTL), PBOVI);
                break;
            default:
                ASSERT(FALSE);                    /* todo: DevErrorHandler. */
        }
    }
}


void HC12Ect_DisableInterrupt(HC12Ect_InterruptSourceType Source)
{
    if ((Source >= HC12ECT_INTERRUPT_SOURCE_TC0) && (Source <= HC12ECT_INTERRUPT_SOURCE_TC7)) {
        UTL_BIT_RESET8(HC12ECT_REG8(TMSK1), Source);
    } else {
        switch (Source) {
            case HC12ECT_INTERRUPT_SOURCE_TOF:
                UTL_BIT_RESET8(HC12ECT_REG8(TMSK2), TOI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_MDCU:
                UTL_BIT_RESET8(HC12ECT_REG8(MCCTL), MCZI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PAOVR:
                UTL_BIT_RESET8(HC12ECT_REG8(PACTL), PAOVI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PA:
                UTL_BIT_RESET8(HC12ECT_REG8(PACTL), PAI);
                break;
            case HC12ECT_INTERRUPT_SOURCE_PBOVR:
                UTL_BIT_RESET8(HC12ECT_REG8(PBCTL), PBOVI);
                break;
            default:
                ASSERT(FALSE);                    /* todo: DevErrorHandler. */
        }
    }
}


/*
** ISR-Handlers.
*/
#if defined(HC12ECT_FEATURE_TIMER_OVERFLOW_INTR)
ISR1(HC12Ect_TofHandler)
{
/*    HC12Ect_OverflowCount++; */
#if !defined(HC12ECT_TIMER_OVERFLOW_CALLBACK)
#error Symbol HC12ECT_TIMER_OVERFLOW_CALLBACK must be defined.
#else
    HC12ECT_TIMER_OVERFLOW_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TOF_INTR();
#endif /* HC12ECT_TIMER_OVERFLOW_CALLBACK */
}
#endif

#if defined(HC12ECT_FEATURE_TC0_INTR)
ISR1(HC12Ect_TC0Handler)
{
#if !defined(HC12ECT_TC0_CALLBACK)
#error Symbol HC12ECT_TC0_CALLBACK must be defined.
#else
    HC12ECT_TC0_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC0_INTR();
#endif  /* HC12ECT_TC0_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC0_INTR */

#if defined(HC12ECT_FEATURE_TC1_INTR)
ISR1(HC12Ect_TC1Handler)
{
#if !defined(HC12ECT_TC1_CALLBACK)
#error Symbol HC12ECT_TC1_CALLBACK must be defined.
#else
    HC12ECT_TC1_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC1_INTR();
#endif  /* HC12ECT_TC1_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC1_INTR */

#if defined(HC12ECT_FEATURE_TC2_INTR)
ISR1(HC12Ect_TC2Handler)
{
#if !defined(HC12ECT_TC2_CALLBACK)
#error Symbol HC12ECT_TC2_CALLBACK must be defined.
#else
    HC12ECT_TC2_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC2_INTR();
#endif  /* HC12ECT_TC2_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC2_INTR */

#if defined(HC12ECT_FEATURE_TC3_INTR)
ISR1(HC12Ect_TC3Handler)
{
#if !defined(HC12ECT_TC3_CALLBACK)
#error Symbol HC12ECT_TC3_CALLBACK must be defined.
#else
    HC12ECT_TC3_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC3_INTR();
#endif  /* HC12ECT_TC3_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC3_INTR */

#if defined(HC12ECT_FEATURE_TC4_INTR)
ISR1(HC12Ect_TC4Handler)
{
#if !defined(HC12ECT_TC4_CALLBACK)
#error Symbol HC12ECT_TC4_CALLBACK must be defined.
#else
    HC12ECT_TC4_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC4_INTR();
#endif  /* HC12ECT_TC4_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC4_INTR */

#if defined(HC12ECT_FEATURE_TC5_INTR)
ISR1(HC12Ect_TC5Handler)
{
#if !defined(HC12ECT_TC5_CALLBACK)
#error Symbol HC12ECT_TC5_CALLBACK must be defined.
#else
    HC12ECT_TC5_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC5_INTR();
#endif  /* HC12ECT_TC5_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC5_INTR */

#if defined(HC12ECT_FEATURE_TC6_INTR)
ISR1(HC12Ect_TC6Handler)
{
#if !defined(HC12ECT_TC6_CALLBACK)
#error Symbol HC12ECT_TC6_CALLBACK must be defined.
#else
    HC12ECT_TC6_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC6_INTR();
#endif  /* HC12ECT_TC6_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC6_INTR */

#if defined(HC12ECT_FEATURE_TC7_INTR)
ISR1(HC12Ect_TC7Handler)
{
#if !defined(HC12ECT_TC7_CALLBACK)
#error Symbol HC12ECT_TC7_CALLBACK must be defined.
#else
    HC12ECT_TC7_CALLBACK();
    HC12ECT_ACKNOWLEDGE_TC7_INTR();
#endif  /* HC12ECT_TC7_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_TC7_INTR */

#if defined(HC12ECT_FEATURE_MDCU_INTR)
ISR1(HC12Ect_MDCUHandler)
{
#if !defined(HC12ECT_MDCU_CALLBACK)
#error Symbol HC12ECT_TC0_CALLBACK must be defined.
#else
    HC12ECT_MDCU_CALLBACK();
    HC12ECT_ACKNOWLEDGE_MDCU_INTR();
#endif  /* HC12ECT_MDCU_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_MDCU_INTR */

#if defined(HC12ECT_FEATURE_PA_INTR)
ISR1(HC12Ect_PAHandler)
{
#if !defined(HC12ECT_PA_CALLBACK)
#error Symbol HC12ECT_PA_CALLBACK must be defined.
#else
    HC12ECT_PA_CALLBACK();
    HC12ECT_ACKNOWLEDGE_PA_INTR();
#endif  /* HC12ECT_PA_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_PA_INTR */

#if defined(HC12ECT_FEATURE_PAOVR_INTR)
ISR1(HC12Ect_PAOVRHandler)
{
#if !defined(HC12ECT_PAOVR_CALLBACK)
#error Symbol HC12ECT_PAOVR_CALLBACK must be defined.
#else
    HC12ECT_PAOVR_CALLBACK();
    HC12ECT_ACKNOWLEDGE_PAOVR_INTR();
#endif  /* HC12ECT_PAOVR_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_PAOVR_INTR */

#if defined(HC12ECT_FEATURE_PBOVR_INTR)
ISR1(HC12Ect_PBOVRHandler)
{
#if !defined(HC12ECT_PBOVR_CALLBACK)
#error Symbol HC12ECT_PBOVR_CALLBACK must be defined.
#else
    HC12ECT_PBOVR_CALLBACK();
    HC12ECT_ACKNOWLEDGE_PBOVR_INTR();
#endif  /* HC12ECT_PBOVR_CALLBACK */
}
#endif  /* HC12ECT_FEATURE_PBOVR_INTR */

