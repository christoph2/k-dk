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
#include "S12_Ect.h"
#include "Hw_Cfg.h"

S12Ect_StatusType S12Ect_Init(void)
{
    /* Main Timer Setup */
    S12ECT_REG8(TIOS)=ECT.TIos;
    S12ECT_REG8(TCTL1)=ECT.TCtl1;
    S12ECT_REG8(TCTL2)=ECT.TCtl2;
    S12ECT_REG8(TCTL3)=ECT.TCtl3;
    S12ECT_REG8(TCTL4)=ECT.TCtl4;
    S12ECT_REG8(TIE)=ECT.TIe;
    S12ECT_REG8(ICPAR)=ECT.ICpar;

    /* Pulse Accus      */
    S12ECT_REG8(PACTL)=ECT.PActl;
    S12ECT_REG8(PBCTL)=ECT.PBctl;

    /* Modulus Counter  */
    S12ECT_REG8(MCCTL)=ECT.MCctl;
    S12ECT_REG16(MCCNT)=ECT.MCcnt;

    /*
    **  ns_per_mhz=1000
    **  cycle=ns_per_mhz/bus_clock
    **  presc=log2(timer_cycle/cycle) (if timer_cycle>cycle)
    */
    S12ECT_REG8(DLYCT)=ECT.DLyct;
    S12ECT_REG8(ICOVW)=ECT.ICovw;
    S12ECT_REG8(ICSYS)=ECT.ICsys;
    S12ECT_REG8(TFLG1)=(uint8)0xFF;     /*  Clear pending interrupts. */
    S12ECT_REG8(TFLG2)=(uint8)0x80;

    S12ECT_REG8(TSCR2)=ECT.TScr2;
    S12ECT_REG8(TSCR1)=ECT.TScr1;

    return S12ECT_OK;
}
