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
#include "mcu/s12/inc/S12_Pwm.h"
#include "Hw_Cfg.h"

/*
**  Global Variables.
*/
S12Pwm_ConfigType const * PWM;

/*
**
**  REFERENCES:
**  ===========
**  AN2612          - PWM GENERATION USING HCS12 TIMER CHANNELS.
**  S12PWM8B8CV1    - HCS12 8-BIT, 8-CHANNEL PULSE WIDTH MODULATOR (PWM) BLOCK USER GUIDE.
**
*/

/*
**  Global Functions.
*/
void S12Pwm_Init(S12Pwm_ConfigType const * const ConfigPtr)
{

    PWM = ConfigPtr;

    /* Setup Initial Periods and Duty-Cycles. */
    S12PWM_REG16(PWMPER01) = ConfigPtr->PwmPer01;
    S12PWM_REG16(PWMPER23) = ConfigPtr->PwmPer23;
    S12PWM_REG16(PWMPER45) = ConfigPtr->PwmPer45;
    S12PWM_REG16(PWMPER67) = ConfigPtr->PwmPer67;

    S12PWM_REG16(PWMDTY01) = ConfigPtr->PwmDty01;
    S12PWM_REG16(PWMDTY23) = ConfigPtr->PwmDty23;
    S12PWM_REG16(PWMDTY45) = ConfigPtr->PwmDty45;
    S12PWM_REG16(PWMDTY67) = ConfigPtr->PwmDty67;

    /* Reset Counters. */
    S12PWM_REG16(PWMCNT0)  = (uint16)0x0000U;
    S12PWM_REG16(PWMCNT2)  = (uint16)0x0000U;
    S12PWM_REG16(PWMCNT4)  = (uint16)0x0000U;
    S12PWM_REG16(PWMCNT6)  = (uint16)0x0000U;

    /* Configure PWM. */
    S12PWM_REG8(PWMPOL)    = ConfigPtr->PwmPol;
    S12PWM_REG8(PWMCLK)    = ConfigPtr->PwmClk;
    S12PWM_REG8(PWMPRCLK)  = ConfigPtr->PwmPrClk;
    S12PWM_REG8(PWMCAE)    = ConfigPtr->PwmCae;
    S12PWM_REG8(PWMSCLA)   = ConfigPtr->PwmSclA;
    S12PWM_REG8(PWMSCLB)   = ConfigPtr->PwmSclB;
    S12PWM_REG8(PWMSDN)    = ConfigPtr->PwmSdn;
    S12PWM_REG8(PWMCTL)    = ConfigPtr->PwmCtl;

    /* Enable Channels. */
    S12PWM_REG8(PWME) = ConfigPtr->PwmE;
/* prescaler = (E-Clock * 4)/10 */

}


//#if defined(S12_PWM_DEINIT_API)
void S12Pwm_DeInit(void)
{
    /* Shutdown all PWM-Channels. */
    S12PWM_REG8(PWME) = (uint8)0x00;

    /* Reinitialize PortP. */
    S12PIM_REG8(PTP)       = PWM->IdleState;
    S12PIM_REG8(DDRP)      = (uint8)0xff;
}
//#endif /* HC12_PWM_DEINIT_API */


void S12Pwm_SetTimebase(void)
{

}


void S12Pwm_SetDutyCycle(S12Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
    if (!S12Pwm_ChannelActivated(ChannelNumber)) {
       S12Pwm_ActivateChannel(ChannelNumber);
    }
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        S12PWM_REG16(PWMDTY0 + (ChannelNumber & (uint8)0x06)) = DutyCycle;
    } else {
        S12PWM_REG8(PWMDTY0 + ChannelNumber) = (uint8)DutyCycle;
    }
}


void S12Pwm_SetPeriodAndDuty(S12Pwm_ChannelType ChannelNumber, uint16 Period, uint16 DutyCycle)
{
    if (!S12Pwm_ChannelActivated(ChannelNumber)) {
       S12Pwm_ActivateChannel(ChannelNumber);
    }
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        S12PWM_REG16(PWMPER0 + (ChannelNumber & (uint8)0x06)) = Period;
    } else {
        S12PWM_REG8(PWMPER0 + ChannelNumber) = (uint8)Period;
    }
    S12Pwm_SetDutyCycle(ChannelNumber, DutyCycle);
}


void S12Pwm_SetOutputToIdle(S12Pwm_ChannelType ChannelNumber)
{
    uint8 channel;
    uint8 mask;

    channel = 1 << ChannelNumber;
    mask = PWM->IdleState & channel;

    S12PWM_REG8(PTP)    = (S12PWM_REG8(PTP) & ~mask) | mask;
    S12PWM_REG8(DDRP)    |= channel;
    S12Pwm_DeactivateChannel(ChannelNumber);
}


uint8 S12Pwm_GetOutputState(S12Pwm_ChannelType ChannelNumber)
{
    /* read 'PTIP' !? */
    return (S12Pwm_GetCounter(ChannelNumber) > S12Pwm_GetDutyCycle(ChannelNumber)) ^ S12Pwm_GetPolarity(ChannelNumber);
}


uint16 S12Pwm_GetCounter(S12Pwm_ChannelType ChannelNumber)
{
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        return S12PWM_REG16(PWMCNT0 + (ChannelNumber & (uint8)0x06));
    } else {
        return (uint16)S12PWM_REG8(PWMCNT0 + ChannelNumber);
    }
}


uint16 S12Pwm_GetPeriod(S12Pwm_ChannelType ChannelNumber)
{
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        return S12PWM_REG16(PWMPER0 + (ChannelNumber & (uint8)0x06));
    } else {
        return (uint16)S12PWM_REG8(PWMPER0 + ChannelNumber);
    }
}


uint16 S12Pwm_GetDutyCycle(S12Pwm_ChannelType ChannelNumber)
{
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        return S12PWM_REG16(PWMDTY0 + (ChannelNumber & (uint8)0x06));
    } else {
        return (uint16)S12PWM_REG8(PWMDTY0 + ChannelNumber);
    }
}


uint8 S12Pwm_GetPolarity(S12Pwm_ChannelType ChannelNumber)
{
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        ChannelNumber &= (uint8)0x06;
    }

    return ((S12PWM_REG8(PWMPOL)) & ((uint8)0x01 << ChannelNumber)) >> ChannelNumber;
}


void S12Pwm_ResetCounter(S12Pwm_ChannelType ChannelNumber)
{
    if (S12Pwm_Is16BitChannel(ChannelNumber)) {
        S12PWM_REG16(PWMCNT0 + (ChannelNumber & (uint8)0x06)) = (uint16)0x0000u;
    } else {
        S12PWM_REG8(PWMCNT0 + ChannelNumber) = (uint8)0x00;
    }
}


boolean S12Pwm_Is16BitChannel(S12Pwm_ChannelType ChannelNumber)
{
    boolean result = FALSE;

    switch (ChannelNumber) {
        case 0:
        case 1:

            if ((S12PWM_REG8(PWMCTL) & CON01) == CON01) {
                result = TRUE;
            }

            break;
        case 2:
        case 3:

            if ((S12PWM_REG8(PWMCTL) & CON23) == CON23) {
                result = TRUE;
            }

            break;
        case 4:
        case 5:

            if ((S12PWM_REG8(PWMCTL) & CON45) == CON45) {
                result = TRUE;
            }

            break;
        case 6:
        case 7:

            if ((S12PWM_REG8(PWMCTL) & CON67) == CON67) {
                result = TRUE;
            }

            break;
        default:
            ASSERT(FALSE); /* todo: ErrorHandling!!! */
    }

    return result;
}


void S12Pwm_ActivateChannel(S12Pwm_ChannelType ChannelNumber)
{
    S12Pwm_ResetCounter(ChannelNumber);
    S12PWM_REG8(PWME) |= (1 << ChannelNumber);
}


void S12Pwm_DeactivateChannel(S12Pwm_ChannelType ChannelNumber)
{
    S12PWM_REG8(PWME) &= ~(1 << ChannelNumber);
}


boolean S12Pwm_ChannelActivated(S12Pwm_ChannelType ChannelNumber)
{
    uint8 channel;

    channel=(1 << ChannelNumber);
    return (S12PWM_REG8(PWME) & channel)==channel;
}
