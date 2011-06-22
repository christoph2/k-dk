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
#include "HC12_Pwm.h"


HC12Pwm_ConfigType const * PWM;

#define HC12_PWM_DEINIT_API /* todo: CFG!!! */
/*
** Global Functions.
*/

void HC12Pwm_Init(HC12Pwm_ConfigType const * const ConfigPtr)
{
    PWM = ConfigPtr;

    /* PortP Setup. */
    HC12PWM_REG8(PORTP)    = ConfigPtr->PortP;
    HC12PWM_REG8(DDRP)     = ConfigPtr->DdrP;

    /* Setup Initial Periods and Duty-Cycles. */
    HC12PWM_REG8(PWPER0)   = ConfigPtr->PwPer0;
    HC12PWM_REG8(PWPER1)   = ConfigPtr->PwPer1;
    HC12PWM_REG8(PWPER2)   = ConfigPtr->PwPer2;
    HC12PWM_REG8(PWPER3)   = ConfigPtr->PwPer3;

    HC12PWM_REG8(PWDTY0)   = ConfigPtr->PwDty0;
    HC12PWM_REG8(PWDTY1)   = ConfigPtr->PwDty1;
    HC12PWM_REG8(PWDTY2)   = ConfigPtr->PwDty2;
    HC12PWM_REG8(PWDTY3)   = ConfigPtr->PwDty3;

    /* Reset Counters. */
    HC12PWM_REG8(PWCNT0)   = ((uint8)0x00);
    HC12PWM_REG8(PWCNT1)   = ((uint8)0x00);
    HC12PWM_REG8(PWCNT2)   = ((uint8)0x00);
    HC12PWM_REG8(PWCNT3)   = ((uint8)0x00);

    /* Configure PWM. */
    HC12PWM_REG8(PWCTL)    = ConfigPtr->PwCtl;
    HC12PWM_REG8(PWCLK)    = ConfigPtr->PwClk;
    HC12PWM_REG8(PWPOL)    = ConfigPtr->PwPol;
    HC12PWM_REG8(PWSCAL0)  = ConfigPtr->PwScal0;
    HC12PWM_REG8(PWSCAL1)  = ConfigPtr->PwScal1;

    /* Enable Channels. */
    HC12PWM_REG8(PWEN) = ConfigPtr->PwEn;
}


#if defined(HC12_PWM_DEINIT_API)
void HC12Pwm_DeInit(void)
{
    /* Shutdown all PWM-Channels. */
    HC12PWM_REG8(PWEN) = (uint8)0x00;
    /* Reinitialize PortP. */
    HC12PWM_REG8(PORTP)    = PWM->IdleState;
    HC12PWM_REG8(DDRP)     = PWM->DdrP;
}
#endif /* HC12_PWM_DEINIT_API */


void HC12Pwm_ResetCounter(HC12Pwm_ChannelType ChannelNumber)
{
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        HC12PWM_REG8(PWCNT0 +  (ChannelNumber & (uint8)0x02)) = (uint16)0x0000u;
    } else {
        HC12PWM_REG8(PWCNT0 + ChannelNumber) = (uint8)0x00;
    }
}


uint16 HC12Pwm_GetCounter(HC12Pwm_ChannelType ChannelNumber)
{
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        return HC12PWM_REG16(PWCNT0 + (ChannelNumber & (uint8)0x02));
    } else {
        return (uint16)HC12PWM_REG8(PWCNT0 + ChannelNumber);
    }
}


uint16 HC12Pwm_GetPeriod(HC12Pwm_ChannelType ChannelNumber)
{
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        return HC12PWM_REG16(PWPER0 + (ChannelNumber & (uint8)0x02));
    } else {
        return (uint16)HC12PWM_REG8(PWPER0 + ChannelNumber);
    }
}


uint16 HC12Pwm_GetDutyCycle(HC12Pwm_ChannelType ChannelNumber)
{
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        return HC12PWM_REG16(PWDTY0 + (ChannelNumber & (uint8)0x02));
    } else {
        return (uint16)HC12PWM_REG8(PWDTY0 + ChannelNumber);
    }
}


uint8 HC12Pwm_GetPolarity(HC12Pwm_ChannelType ChannelNumber)
{
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        ChannelNumber &= (uint8)0x02;
    }

    return ((HC12PWM_REG8(PWPOL) & (uint8)0x0f) & ((uint8)0x01 << ChannelNumber)) >> ChannelNumber;
}


void HC12Pwm_SetTimebase(void)
{

}


uint8 HC12Pwm_GetOutputState(HC12Pwm_ChannelType ChannelNumber)
{
    return (HC12Pwm_GetCounter(ChannelNumber) > HC12Pwm_GetDutyCycle(ChannelNumber)) ^ HC12Pwm_GetPolarity(ChannelNumber);
}


void HC12Pwm_SetDutyCycle(HC12Pwm_ChannelType ChannelNumber, uint16 DutyCycle)
{
    if (!HC12Pwm_ChannelActivated(ChannelNumber)) {
       HC12Pwm_ActivateChannel(ChannelNumber);
    }
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        HC12PWM_REG16(PWDTY0 + (ChannelNumber & (uint8)0x02)) = DutyCycle;
    } else {
        HC12PWM_REG8(PWDTY0 + ChannelNumber) = (uint8)DutyCycle;
    } 
}


void HC12Pwm_SetPeriodAndDuty(HC12Pwm_ChannelType ChannelNumber, uint16 Period, uint16 DutyCycle)
{
    if (!HC12Pwm_ChannelActivated(ChannelNumber)) {
       HC12Pwm_ActivateChannel(ChannelNumber);
    }
    if (HC12Pwm_Is16BitChannel(ChannelNumber)) {
        HC12PWM_REG16(PWPER0 + (ChannelNumber & (uint8)0x02)) = Period;
    } else {
        HC12PWM_REG8(PWPER0 + ChannelNumber) = (uint8)Period;
    }
    HC12Pwm_SetDutyCycle(ChannelNumber, DutyCycle);
}


void HC12Pwm_ActivateChannel(HC12Pwm_ChannelType ChannelNumber)
{
     HC12Pwm_ResetCounter(ChannelNumber);
     HC12PWM_REG8(PWEN) |= (1 << ChannelNumber);
}


void HC12Pwm_DeactivateChannel(HC12Pwm_ChannelType ChannelNumber)
{
     HC12PWM_REG8(PWEN) &= ~(1 << ChannelNumber);
}


boolean HC12Pwm_ChannelActivated(HC12Pwm_ChannelType ChannelNumber)
{
    uint8 channel;
 
    channel=(1 << ChannelNumber);
    return (HC12PWM_REG8(PWEN) & channel)==channel;
}


void HC12Pwm_SetOutputToIdle(HC12Pwm_ChannelType ChannelNumber)
{
    uint8 channel;
    uint8 mask;

    channel = 1 << ChannelNumber;
    mask = PWM->IdleState & channel;

    HC12PWM_REG8(PORTP)    = (HC12PWM_REG8(PORTP) & ~mask) | mask;
    HC12PWM_REG8(DDRP)    |= channel;
    HC12Pwm_DeactivateChannel(ChannelNumber);
}


boolean HC12Pwm_Is16BitChannel(HC12Pwm_ChannelType ChannelNumber)
{
    boolean result = FALSE;

    switch (ChannelNumber) {
        case 0:
        case 1:
            if ((HC12PWM_REG8(PWCLK) & CON01) == CON01) {
                result = TRUE;
            }
            break;
        case 2:
        case 3:
            if ((HC12PWM_REG8(PWCLK) & CON23) == CON23) {
                result = TRUE;
            }
            break;
        default:
            ASSERT(FALSE);   /* todo: ErrorHandling!!! */
    }

    return result;
}


/*
** Local Functions.
*/

