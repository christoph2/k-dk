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

#include "HC12_Pll.h"
#include "HC12_BcIo.h"
#include "Hw_Cfg.h"

HC12Pll_StatusType HC12Pll_Init(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)
    HC12Pll_StatusType status;

    HC12PLL_REG8(PLLCR) = AUTO | PSTP | LHIE; /* todo: Cfg. !!! */

    HC12Pll_UnselectPll();
    HC12Pll_DisablePll();

    if ((HC12BcIo_SpecialMode() == FALSE) && (PLL.EnablePll == TRUE)) { /* we don't use PLL-Clock in Specialmodes (==> BDM). */
        status = HC12Pll_SetPllFreq(PLL.Frequency);

        if (status != HC12PLL_OK) {
            return status;
        }

        status = HC12Pll_EnablePll();

        if (status != HC12PLL_OK) {
            return status;
        }
    }

    if (status != HC12PLL_OK) {
        return status;
    }

#endif /* KDK_CONTROLLER_HAS_PLL */
    return HC12PLL_OK;
}


void HC12Pll_Uninit(void)
{
    HC12Pll_UnselectPll();
    HC12Pll_DisablePll();
}


HC12Pll_StatusType HC12Pll_EnablePll(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)

    if (HC12Pll_PllEnabled()) {
        return HC12PLL_STATE;
    }

    HC12PLL_REG8(PLLCR) |= PLLON;
#endif /* KDK_CONTROLLER_HAS_PLL */
    return HC12PLL_OK;
}


HC12Pll_StatusType HC12Pll_DisablePll(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)

    if (!HC12Pll_PllEnabled()) {
        return HC12PLL_STATE;
    }

    HC12PLL_REG8(PLLCR) &= ~PLLON;
#endif
    return HC12PLL_OK;
}


boolean HC12Pll_PllEnabled(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)
    return (HC12PLL_REG8(PLLCR) & PLLON) == PLLON;
#else
    return FALSE;
#endif  /* KDK_CONTROLLER_HAS_PLL */
}


/*
**  PLL_CLOCK = 2 * OSC_CLOCK * ((SYNR+1)/(REFDV+1))
*/
HC12Pll_StatusType HC12Pll_SetPllFreq(uint8 freq)
{
#if defined(KDK_CONTROLLER_HAS_PLL)

    if ((freq == ((uint8)0)) || freq > (uint8)(BUS_FREQUENCY_MAX / 1000u) ) { /* todo: PP 'ASSERT's!!! */
        return HC12PLL_VALUE;
    }

    if (HC12Pll_PllEnabled()) {
        return HC12PLL_STATE;
    }

    HC12PLL_REG8(REFDV)    = (uint8)(XTAL_FREQUENCY / 1000u)  - ((uint8)1); /* divide, to get 1MHz. */
    HC12PLL_REG8(SYNR)     = freq - ((uint8)1);

#if (HC12PLL_SYNCH_PLL == 1)
    WAIT_FOR((HC12PLL_REG8(PLLFLG) & LOCK) == LOCK);
#endif
    return HC12PLL_OK;
#else
#error Controller-derivate has no PLL.
#endif /* KDK_CONTROLLER_HAS_PLL */
}


HC12Pll_StatusType HC12Pll_SetPllParams(uint8 refdv, uint8 synr)
{
#if defined(KDK_CONTROLLER_HAS_PLL)

    /* todo: check resulting Frequency!!! */
    if (HC12Pll_PllEnabled()) {
        return HC12PLL_STATE;
    }

    HC12PLL_REG8(REFDV)    = refdv;
    HC12PLL_REG8(SYNR)     = synr;

    return HC12PLL_OK;

#else
#error Controller-derivate has no PLL.
#endif
}


boolean HC12Pll_PllLocked(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)

    if (HC12Pll_PllEnabled()) {
        return (HC12PLL_REG8(PLLFLG) & LOCK) == LOCK;
    } else {
        return TRUE;
    }

#else
#error Controller-derivate has no PLL.
#endif  /* KDK_CONTROLLER_HAS_PLL */
}


void HC12Pll_SelectPll(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)
    HC12PLL_REG8(CLKSEL) |= BCSP;
#else
#error Controller-derivate has no PLL.
#endif  /* KDK_CONTROLLER_HAS_PLL */
}


void HC12Pll_UnselectPll(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)
    HC12PLL_REG8(CLKSEL) &= ~BCSP;
#else
#error Controller-derivate has no PLL.
#endif  /* KDK_CONTROLLER_HAS_PLL */
}


boolean HC12Pll_PllSelected(void)
{
#if defined(KDK_CONTROLLER_HAS_PLL)
    return (HC12PLL_REG8(CLKSEL) & BCSP) == BCSP;
#else
#error Controller-derivate has no PLL.
#endif  /* KDK_CONTROLLER_HAS_PLL */
}


uint8 HC12Pll_GetBusFreq(void)
{
    uint8 bus_freq;

    if (HC12Pll_PllEnabled()) {
        bus_freq   = (uint8)(XTAL_FREQUENCY / 1000u) / (HC12PLL_REG8(REFDV) + 1);
        bus_freq  *= (HC12PLL_REG8(SYNR) + 1);
    } else {
        bus_freq = (uint8)(XTAL_FREQUENCY / 1000u) / (uint8)2;
    }

    return bus_freq;
}


uint8 HC12Pll_GetOscFreq(void)
{
    return (uint8)(XTAL_FREQUENCY / 1000u);
}


#if defined(HC12PLL_USE_LOCK_INTERRUPT) && defined(KDK_CONTROLLER_HAS_PLL)
ISR1(Pll_LockInterrupt)
{
    /* State-Change: [LOCKED,UNLOCKED] */
    /* todo: Callout */
    HC12Pll_PllLockType lock;

    lock = ((HC12PLL_REG8(PLLFLG) & LOCK) == LOCK) ? HC12PLL_PLL_LOCKED : HC12PLL_PLL_UNLOCKED;

    HC12PLL_REG8(PLLFLG) = LOCKIF;
}
#endif /* HC12PLL_USE_LOCK_INTERRUPT */

#if defined(HC12PLL_USE_LIMP_HOME_INTERRUPT) && defined(KDK_CONTROLLER_HAS_PLL)
ISR1(Pll_LockInterrupt)
{
    /* todo: Callout */
    HC12Pll_LimpHomeStatupType status;

    status = ((HC12PLL_REG8(PLLFLG) & LHOME) == LHOME) ? HC12PLL_LH_LIMP_HOME : HC12PLL_LH_NORMAL_OPERATION;

    HC12PLL_REG8(PLLFLG) = LHIF;
}
#endif /* HC12PLL_USE_LIMP_HOME_INTERRUPT */
