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

/*
**
** todo:    Functions for 8- and 16-Bit PWM.
**          Channel enable-/disable-Functions.
**          if disabled: as input or output (which level?)).
*/

HC12Pwm_ConfigType const * PWM;

/*
**
**	   AUTOSAR:
**	   ========
**	   16-Bit duty-cycle resolution.
**
**	   0x0000 ==> 0%
**	   0x8000 ==> 100%
**
**	   AbsoluteDutyCycle = ((uint32)AbsolutePeriodTime * RelativeDutyCycle) >> 15;
**	                                                   / (uint16)32768U
**
*/

#define HC12_PWM_DEINIT_API /* todo: CFG!!! */

#define HC12_PWM_SCALE_DUTY_CYCLE1(ap, rd)  ((uint16)((uint32)(ap) * (rd)) / (uint16)32768U)
#define HC12_PWM_SCALE_DUTY_CYCLE2(ap, rd)  ((uint16)(HIWORD(((uint32)(ap) * (rd)))) >> 1)

static uint16   scale0(uint16 ap, uint16 rd);
static uint16   scale1(uint16 ap, uint16 rd);

/* todo: IdleState durch PortP ersetzen!!! */

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

void HC12Pwm_ResetCounter(uint8 ChannelNumber)
{
    HC12PWM_REG8(PWCNT0 + ChannelNumber) = (uint8)0x00;
}

uint8 HC12Pwm_GetCounter8(uint8 ChannelNumber)
{
    return HC12PWM_REG8(PWCNT0 + ChannelNumber);
}

uint16 HC12Pwm_GetCounter16(uint8 ChannelNumber)
{
    return HC12PWM_REG16(PWCNT0 + (ChannelNumber << 1));
}

void HC12Pwm_SetTimebase(void)
{

}

void HC12Pwm_SetDutyCycle(uint8 ChannelNumber, uint16 DutyCycle)
{

}

void HC12Pwm_SetPeriodAndDuty(uint8 ChannelNumber, uint16 Period, uint16 DutyCycle)
{

}

#if 0
S12PIM_REG8(S12PIM_PORT_BASE(group->port) + S12PIM_PT) =
    (S12PIM_REG8(S12PIM_PORT_BASE(group->port) + S12PIM_PT) & ~group->mask) |
    (group->mask & (level << group->offset)       /* todo: Table!!! */
    );
#endif

void HC12Pwm_SetOutputToIdle(uint8 ChannelNumber)
{
    uint8 channel;

    channel = PWM->IdleState & (1 << ChannelNumber);

    HC12PWM_REG8(PORTP)    = PWM->IdleState & channel;
    HC12PWM_REG8(DDRP)    |= channel;
    HC12PWM_REG8(PWEN)    &= ~channel;
}

void HC12Pwm_SetOutputToActive(uint8 ChannelNumber)
{
    uint8 channel;

    channel = PWM->IdleState & (1 << ChannelNumber);

    HC12PWM_REG8(DDRP)    &= ~channel;
    HC12PWM_REG8(PWEN)    |= channel;
}

uint8 HC12Pwm_GetOutputState(uint8 ChannelNumber)
{

}

/* Scale duty-cycle to [0x0000 .. 0x8000] */
uint16 Pwm_CalculateAbsoluteDutyCycle(uint16 AbsolutePeriodTime, uint16 RelativeDutyCycle)
{
    return (uint16)(HIWORD(((uint32)(AbsolutePeriodTime) * (RelativeDutyCycle)))) << 1;
}

