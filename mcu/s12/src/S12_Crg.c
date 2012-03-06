/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#include "mcu/s12/inc/S12_Crg.h"
#include "Hw_Cfg.h"

static boolean CRG_PowerOnRest;

S12Crg_StatusType S12Crg_Init(void)
{
    S12Crg_StatusType status;

    if ((S12CRG_REG8(CRGFLG) & PORF) == PORF) {
        S12CRG_REG8(CRGFLG)    = PORF;
        CRG_PowerOnRest        = TRUE;  /* Power-on Reset.      */
    } else {
        CRG_PowerOnRest = FALSE;        /* Other Reset Reason.  */
    }

    S12Crg_UnselectPll();
    S12Crg_DisablePll();

    S12CRG_REG8(CLKSEL)    = /*ROAWAI*/ PSTP | COPWAI; /* todo: Cfg. */
    S12CRG_REG8(PLLCTL)    = CME | AUTO | SCME;

    if ((S12Mebi_SpecialMode() == FALSE) && (CRG.EnablePll == TRUE)) {  /* we don't use PLL-Clock in Specialmodes (==> BDM). */
        status = S12Crg_SetPllFreq(CRG.Frequency);

        if (status != S12CRG_OK) {
            return status;
        }

        status = S12Crg_EnablePll();

        if (status != S12CRG_OK) {
            return status;
        }
    }

    if (CRG.EnableRTI == TRUE) {
        status = S12Crg_SetRTIRate(((CRG.RTIPrescaler & (uint8)0x07) << 4) | (CRG.RTIModulo & ((uint8)0x0f)));

        if (status != S12CRG_OK) {
            return status;
        }

        status = S12Crg_EnableRTI();
    } else {
        status = S12Crg_DisableRTI();
    }

    if (status != S12CRG_OK) {
        return status;
    }

    return S12CRG_OK;
}


void S12Crg_Uninit(void)
{
    S12Crg_UnselectPll();
    S12Crg_DisablePll();

    if (CRG.EnableRTI == TRUE) {
        S12Crg_DisableRTI();
    }
}


S12Crg_StatusType S12Crg_EnablePll(void)
{
    if (S12Crg_PllEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(PLLCTL) |= PLLON;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisablePll(void)
{
    if (!S12Crg_PllEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(PLLCTL) &= ~PLLON;

    return S12CRG_OK;
}


boolean S12Crg_PllEnabled(void)
{
    return (S12CRG_REG8(PLLCTL) & PLLON) == PLLON;
}


/*
**  PLL_CLOCK = 2 * OSC_CLOCK * ((SYNR+1)/(REFDV+1))
*/
S12Crg_StatusType S12Crg_SetPllFreq(uint8 freq)
{
    if ((freq == ((uint8)0)) || freq > (uint8)(BUS_FREQUENCY_MAX / 1000u) ) {
        return S12CRG_VALUE;
    }

    if (S12Crg_PllEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(REFDV) = (uint8)(XTAL_FREQUENCY / 1000u)  - ((uint8)1);  /* divide, to get 1MHz. */
    S12CRG_REG8(SYNR)  = freq - ((uint8)1);

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetPllParams(uint8 refdv, uint8 synr)
{
    /* todo: check resulting Frequency!!! */
    if (S12Crg_PllEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(REFDV) = refdv;
    S12CRG_REG8(SYNR)  = synr;

    return S12CRG_OK;
}


boolean S12Crg_PllLocked(void)
{
    if (S12Crg_PllEnabled()) {
        return (S12CRG_REG8(CRGFLG) & LOCK) == LOCK;
    } else {
        return TRUE;
    }
}


void S12Crg_SelectPll(void)
{
    S12CRG_REG8(CLKSEL) |= PLLSEL;
}


void S12Crg_UnselectPll(void)
{
    S12CRG_REG8(CLKSEL) &= ~PLLSEL;
}


boolean S12Crg_PllSelected(void)
{
    return (S12CRG_REG8(CLKSEL) & PLLSEL) == PLLSEL;
}


uint8 S12Crg_GetBusFreq(void)
{
    uint8 bus_freq;

    if (S12Crg_PllEnabled()) {
        bus_freq   = (uint8)(XTAL_FREQUENCY / 1000u) / (S12CRG_REG8(REFDV) + 1);
        bus_freq  *= (S12CRG_REG8(SYNR) + 1);
    } else {
        bus_freq = (uint8)(XTAL_FREQUENCY / 1000u) / (uint8)2;
    }

    return bus_freq;
}


uint8 S12Crg_GetOscFreq(void)
{
    return (uint8)(XTAL_FREQUENCY / 1000u);
}


S12Crg_StatusType S12Crg_EnableRTI(void)
{
    if (S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(CRGFLG)    = RTIF;
    S12CRG_REG8(CRGINT)   |= RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisableRTI(void)
{
    if (!S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(RTICTL)    = ((uint8)0x00);
    S12CRG_REG8(CRGINT)   &= ~RTIE;
    S12CRG_REG8(CRGFLG)    = RTIF;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetRTIRate(uint8 rate)
{
    if (S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(RTICTL) = rate;

    return S12CRG_OK;
}


boolean S12Crg_RTIEnabled(void)
{
    return (S12CRG_REG8(CRGINT) & RTIE) == RTIE;
}


void S12Crg_EnableWatchdog(void)
{
    S12CRG_REG8(COPCTL) = (RSBCK | (CRG.WatchdogPrescaler & (uint8)0x07));
}


void S12Crg_TriggerWatchdog(void)
{
    S12CRG_REG8(ARMCOP)    = (uint8)0x55;
    S12CRG_REG8(ARMCOP)    = (uint8)0xaa;
}


void S12Crg_ResetMCU(void)
{
    if (!(S12CRG_REG8(COPCTL) & (CR2 | CR1 | CR0))) {
        S12CRG_REG8(COPCTL) = (RSBCK | CR0);    /* Enable COP if disabled.                      */
    }

    S12CRG_REG8(ARMCOP) = (uint8)0xcc;        /* Write garbage to 'ARMCOP' ==> instant RESET. */
}


#if defined(S12CRG_USE_LOCK_INTERRUPT)
ISR1(CRG_LockInterrupt)
{
    /* State-Change: [LOCKED,UNLOCKED] */
    /* todo: Callout */
    S12Crg_PllLockType lock;

    lock = ((S12CRG_REG8(CRGFLG) & LOCK) == LOCK) ? S12CRG_PLL_LOCKED : S12CRG_PLL_UNLOCKED;

    S12CRG_REG8(CRGFLG) = LOCKIF;
}
#endif /* S12CRG_USE_LOCK_INTERRUPT */

#if defined(S12CRG_USE_SELF_CLOCK_MODE_INTERRUPT)
ISR1(CRG_SelfClockModeInterrupt)
{
    /* SCM-Condition Changed: [ENTERED|EXITED]Self-Clock-Mode.    */
    /* todo: Callout */
    S12CRG_REG8(CRGFLG) = SCMIF;
}
#endif  /* S12CRG_USE_SELF_CLOCK_MODE_INTERRUPT */

#if defined(S12CRG_USE_REALTIME_INTERRUPT)
ISR1(RTI_Vector)
{
    static uint32 cnt;

    S12CRG_REG8(CRGFLG) = RTIF;

    cnt++;
}
#endif  /* S12CRG_USE_REALTIME_INTERRUPT */
