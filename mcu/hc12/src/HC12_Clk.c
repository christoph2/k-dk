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
 * s. FLOSS-EXCEPTION.txt
 */
#include "HC12_Clk.h"
#include "Hw_Cfg.h"

void HC12Clk_Init(void)
{
    HC12Clk_StatusType status;

    if (CLK.EnableRTI == TRUE) {
        status = HC12Clk_SetRTIRate(((CLK.RTIPrescaler & (uint8)0x07) << 4) | (CLK.RTIModulo & ((uint8)0x0f)));

        if (status != HC12CLK_OK) {
/*            return status; */
        }

        status = HC12Clk_EnableRTI();
    } else {
        status = HC12Clk_DisableRTI();
    }
}


HC12Clk_StatusType HC12Clk_EnableRTI(void)  /* todo: Rate. */
{
    if (HC12Clk_RTIEnabled()) {
        return HC12CLK_STATE;
    }

    HC12CLK_REG8(RTIFLG)   = RTIF;
    HC12CLK_REG8(RTICTL)  |= (RTIE | RSWAI | RSBCK);

    return HC12CLK_OK;
}


HC12Clk_StatusType HC12Clk_DisableRTI(void)
{
    if (!HC12Clk_RTIEnabled()) {
        return HC12CLK_STATE;
    }

    HC12CLK_REG8(RTICTL)   = (uint8)0x00;
    HC12CLK_REG8(RTIFLG)   = RTIF;

    return HC12CLK_OK;
}


HC12Clk_StatusType HC12Clk_SetRTIRate(uint8 rate)
{
    if (HC12Clk_RTIEnabled()) {
        return HC12CLK_STATE;
    }

    HC12CLK_REG8(RTICTL) |= (rate & (uint8)0x07);

    return HC12CLK_OK;
}


boolean HC12Clk_RTIEnabled(void)
{
    return (HC12CLK_REG8(RTICTL) & RTIE) == RTIE;
}


void HC12Clk_EnableWatchdog(void)
{
    HC12CLK_REG8(COPCTL) = (CME | FCME | (CLK.WatchdogPrescaler & (uint8)0x07));
}


void HC12Clk_TriggerWatchdog(void)
{
    HC12CLK_REG8(COPRST)   = (uint8)0x55;
    HC12CLK_REG8(COPRST)   = (uint8)0xaa;
}


void HC12Clk_ResetMCU(void)
{
    if (!(HC12CLK_REG8(COPCTL) & (CR2 | CR1 | CR0))) {
        HC12CLK_REG8(COPCTL) = CR0;           /* Enable COP if disabled.                      */
    }

    HC12CLK_REG8(COPRST) = (uint8)0xcc;       /* Write garbage to 'ARMCOP' ==> instant RESET. */
}


#if defined(HC12CLK_USE_REALTIME_INTERRUPT)
ISR1(RTI_Vector)
{
    static uint32 cnt;

    HC12PLL_REG8(RTIFLG) = RTIF;

    cnt++;
}
#endif  /* HC12CLK_USE_REALTIME_INTERRUPT */

