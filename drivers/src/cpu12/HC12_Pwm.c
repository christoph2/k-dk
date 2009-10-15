/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
#include "Hw_Cfg.h"

extern const HC12Pwm_ConfigType PWM;    /* hier??? */

/*
**
** todo:    Functions for 8- and 16-Bit PWM.
**          Channel enable-/disable-Functions.
**          Channel Phase/Shift-Function (Paramter: disable before Reset?/
**              if disabled: as input or output (which level?)).
*/

void HC12Pwm_Init(void)
{
    HC12PWM_REG8(PWPER0)=PWM.PwPer0;
    HC12PWM_REG8(PWPER1)=PWM.PwPer1;
    HC12PWM_REG8(PWPER2)=PWM.PwPer2;
    HC12PWM_REG8(PWPER3)=PWM.PwPer3;

    HC12PWM_REG8(PWDTY0)=PWM.PwDty0;
    HC12PWM_REG8(PWDTY1)=PWM.PwDty1;
    HC12PWM_REG8(PWDTY2)=PWM.PwDty2;
    HC12PWM_REG8(PWDTY3)=PWM.PwDty3;

    HC12PWM_REG8(PWCNT0)=((uint8)0x00);
    HC12PWM_REG8(PWCNT1)=((uint8)0x00);
    HC12PWM_REG8(PWCNT2)=((uint8)0x00);
    HC12PWM_REG8(PWCNT3)=((uint8)0x00);

    HC12PWM_REG8(PWCTL)=PWM.PwCtl;
    HC12PWM_REG8(PWCLK)=PWM.PwClk;
    HC12PWM_REG8(PWPOL)=PWM.PwPol;
    HC12PWM_REG8(PWSCAL0)=PWM.PwScal0;
    HC12PWM_REG8(PWSCAL1)=PWM.PwScal1;

    HC12PWM_REG8(PWEN)=PWM.PwEn;
}


void HC12Pwm_ResetCounter(uint8 ChannelNumber)
{
    HC12PWM_REG8(PWCNT0+ChannelNumber)=(uint8)0x00;
}


uint8 HC12Pwm_GetCounter8(uint8 ChannelNumber)
{
    return HC12PWM_REG8(PWCNT0+ChannelNumber);
}

uint16 HC12Pwm_GetCounter16(uint8 ChannelNumber)
{
    return HC12PWM_REG16(PWCNT0+(ChannelNumber<<1));
}


void HC12Pwm_SetTimebase(void)
{

}


void HC12Pwm_SetDutyCycle(uint8 ChannelNumber,uint16 DutyCycle)
{

}


void HC12Pwm_SetPeriodAndDuty(uint8 ChannelNumber,uint16 Period,uint16 DutyCycle)
{

}


void HC12Pwm_SetOutputToIdle(uint8 ChannelNumber)
{

}


uint8 HC12Pwm_GetOutputState(uint8 ChannelNumber)
{

}
