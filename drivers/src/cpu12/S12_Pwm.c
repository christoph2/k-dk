/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
#include "S12_Pwm.h"
#include "Hw_Cfg.h"

/*
** todo:    Functions for 8- and 16-Bit PWM.
*/

/*
**
**  REFERENCES:
**  ===========
**  AN2612          - PWM GENERATION USING HCS12 TIMER CHANNELS
**  S12PWM8B8CV1    - HCS12 8-BIT, 8-CHANNEL PULSE WIDTH MODULATOR (PWM) BLOCK GUI
**
*/

void S12Pwm_Init(void)
{
    S12PWM_REG16(PWMPER01)=PWM.PwmPer01;
    S12PWM_REG16(PWMPER23)=PWM.PwmPer23;
    S12PWM_REG16(PWMPER45)=PWM.PwmPer45;
    S12PWM_REG16(PWMPER67)=PWM.PwmPer67;

    S12PWM_REG16(PWMDTY01)=PWM.PwmDty01;
    S12PWM_REG16(PWMDTY23)=PWM.PwmDty23;
    S12PWM_REG16(PWMDTY45)=PWM.PwmDty45;
    S12PWM_REG16(PWMDTY67)=PWM.PwmDty67;

    S12PWM_REG16(PWMCNT0)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT2)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT4)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT6)=(uint16)0x0000U;

    S12PWM_REG8(PWMPOL)=PWM.PwmPol;
    S12PWM_REG8(PWMCLK)=PWM.PwmClk;
    S12PWM_REG8(PWMPRCLK)=PWM.PwmPrClk;
    S12PWM_REG8(PWMCAE)=PWM.PwmCae;
    S12PWM_REG8(PWMSCLA)=PWM.PwmSclA;
    S12PWM_REG8(PWMSCLB)=PWM.PwmSclB;

    S12PWM_REG8(PWMSDN)=PWM.PwmSdn;
    S12PWM_REG8(PWMCTL)=PWM.PwmCtl;
    S12PWM_REG8(PWME)=PWM.PwmE;         /* OK, start PWM.   */
/* prescaler = (E-Clock * 4)/10 */

}


void S12Pwm_SetTimebase(void)
{
}


void S12Pwm_SetDutyCycle(uint8 ChannelNumber,uint16 DutyCycle)
{
}


void S12Pwm_SetPeriodAndDuty(uint8 ChannelNumber,uint16 Period,uint16 DutyCycle)
{

}


void S12Pwm_SetOutputToIdle(uint8 ChannelNumber)
{

}


uint8 S12Pwm_GetOutputState(uint8 ChannelNumber)
{
    /* todo: read 'PTIP' */
}


void S12Pwm_ResetCounter(uint8 ChannelNumber)
{
    S12PWM_REG8(PWMCNT0+ChannelNumber)=(uint8)0x00;
}


uint8 S12Pwm_GetCounter8(uint8 ChannelNumber)
{
    return S12PWM_REG8(PWMCNT0+ChannelNumber);
}


uint16 S12Pwm_GetCounter16(uint8 ChannelNumber)
{
    return S12PWM_REG16(PWMCNT0+(ChannelNumber<<1));
}