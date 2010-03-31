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
#include "S12_Crg.h"
#include "Hw_Cfg.h"

static boolean CRG_PowerOnRest;

/*
**
**  todo: S12_(CPU12_)TimerIf !?.
**
*/

/*
**
**  todo: Clock-Failure Interrupts und dgl.
**
*/

S12Crg_StatusType S12Crg_Init(uint8 freq)
{
    S12Crg_StatusType status;

    if ((S12CRG_REG8(CRGFLG) & PORF)==PORF) {
        S12CRG_REG8(CRGFLG)=PORF;
        CRG_PowerOnRest=TRUE;   /* Power-on Reset.      */
    } else {
        CRG_PowerOnRest=FALSE;  /* Other Reset Reason.  */
    }

/*    S12CRG_REG8(CLKSEL)&=~PLLSEL; */
    S12CRG_REG8(CLKSEL)=/*PSTP|ROAWAI*/COPWAI;
    S12CRG_REG8(PLLCTL)=CME|PLLON|AUTO|ACQ|SCME;    /*todo: Die PLL erst zu einem späteren Zeitpunkt auswählen!!! */

    if (S12Mebi_SpecialMode()==FALSE) {
        status=S12Crg_SetPLLFreq(freq);
        if (status!=S12CRG_OK) {
            return status;
        }
        status=S12Crg_EnablePLL();
        if (status!=S12CRG_OK) {
            return status;
        }
    } else {
        /* we don't use PLL-Clock in Specialmodes (==> BDM). */
        (void)S12Crg_DisablePLL();
    }

    if (CRG.EnableRTI==TRUE) {
        status=S12Crg_SetRTIRate(((CRG.RTIPrescaler & (uint8)0x07)<<4) | (CRG.RTIModulo & ((uint8)0x0f)));
        if (status!=S12CRG_OK) {
            return status;
        }
        status=S12Crg_EnableRTI();
    } else {
        status=S12Crg_DisableRTI();
    }
    if (status!=S12CRG_OK) {
        return status;
    }

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_EnablePLL(void)
{
    if (S12Crg_PLLEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(CLKSEL)|=PLLSEL;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisablePLL(void)
{
    if (!S12Crg_PLLEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(CLKSEL)&=~PLLSEL;

    return S12CRG_OK;
}


boolean S12Crg_PLLEnabled(void)
{
    return ((S12CRG_REG8(CLKSEL) & PLLSEL)==PLLSEL);
}

/*
**  PLL_CLOCK = 2 * OSC_CLOCK * ((SYNR+1)/(REFDV+1))
*/


S12Crg_StatusType S12Crg_SetPLLFreq(uint8 freq)
{
    if ((freq==((uint8)0)) || freq > CRG.MaxBusFreq) {  /* MaxBusFreq: PRE_COMPILE!? */
        return S12CRG_VALUE;
    }

    if (S12Crg_PLLEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(REFDV)=CRG.OscFreq-((uint8)1);  /* divide, to get 1MHz. */
    S12CRG_REG8(SYNR)=freq-((uint8)1);

#if (S12CRG_SYNCH_PLL==1)
    WAIT_FOR((S12CRG_REG8(CRGFLG) & LOCK)==LOCK);
#endif

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetPLLParams(uint8 refdv,uint8 synr)
{
    /* todo: Frequenz-Check!!!  */
    if (S12Crg_PLLEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(REFDV)=refdv;
    S12CRG_REG8(SYNR)=synr;

    return S12CRG_OK;
}

boolean S12Crg_PLLLocked(void)
{
    if (S12Crg_PLLEnabled()) {
        return (S12CRG_REG8(CRGFLG) & LOCK)==LOCK;
    } else {
        return TRUE;
    }
}


uint8 S12Crg_GetBusFreq(void)
{
    uint8 bus_freq;

    if (S12Crg_PLLEnabled()) {
        bus_freq=CRG.OscFreq / (S12CRG_REG8(REFDV) + 1);
        bus_freq*=(S12CRG_REG8(SYNR)+1);
    } else {
        bus_freq=CRG.OscFreq/(uint8)2;  /* todo: OSC-Freq. Precompile Parameter !? */
    }

    return bus_freq;
}


uint8 S12Crg_GetOscFreq(void)
{
    return CRG.OscFreq;
}


S12Crg_StatusType S12Crg_EnableRTI(void)
{
    if (S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(CRGFLG)=RTIF;
    S12CRG_REG8(CRGINT)|=RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisableRTI(void)
{
    if (!S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(RTICTL)=((uint8)0x00);
    S12CRG_REG8(CRGINT)&=~RTIE;
    S12CRG_REG8(CRGFLG)=RTIF;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetRTIRate(uint8 rate)
{
    if (S12Crg_RTIEnabled()) {
        return S12CRG_STATE;
    }

    S12CRG_REG8(RTICTL)=rate;

    return S12CRG_OK;
}


boolean S12Crg_RTIEnabled(void)
{
    return (S12CRG_REG8(CRGINT) & RTIE)==RTIE;
}


void S12Crg_TriggerWDG(void)
{
    S12CRG_REG8(ARMCOP)=(uint8)0x55;
    S12CRG_REG8(ARMCOP)=(uint8)0xaa;;
}


void S12Crg_ResetMCU(void)
{
    if (!(S12CRG_REG8(COPCTL) & (CR2|CR1|CR0))) {
        S12CRG_REG8(COPCTL)=(RSBCK|CR0);    /* Enable COP if disabled.                      */
    }
    S12CRG_REG8(ARMCOP)=(uint8)0xcc;        /* Write garbage to 'ARMCOP' ==> instant RESET. */
}

/*
**  todo: CFG-Parameter f. die ISRs!!!
*/

ISR1(CRG_LockInterrupt)
{
    /* State-Change: [LOCKED,UNLOCKED] */
    /* todo: Callout */
    S12Crg_PllLockType lock;

    lock=((S12CRG_REG8(CRGFLG) & LOCK)==LOCK) ? S12CRG_PLL_LOCKED : S12CRG_PLL_UNLOCKED;

    S12CRG_REG8(CRGFLG)=LOCKIF;
}


ISR1(CRG_SelfClockModeInterrupt)
{
    /* SCM-Condition Changed: [ENTERED|EXITED]Self-Clock-Mode.    */
    /* todo: Callout */
    S12CRG_REG8(CRGFLG)=SCMIF;
}


#if 0
ISR1(RTI_Vector)
{
    static uint32 cnt;

    S12CRG_REG8(CRGFLG)=RTIF;

    cnt++;
}
#endif
