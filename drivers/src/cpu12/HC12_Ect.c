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
#include "Hw_Cfg.h"
#include "HC12_Ect.h"

#if defined(HC12ECT_USE_TIMER_OVERFLOW_INTR)
static uint16 HC12Ect_OverflowCount;
#endif


void HC12Ect_Init(void)
{
#if defined(HC12ECT_USE_TIMER_OVERFLOW_INTR)
    HC12Ect_OverflowCount=(uint16)0x0000;
#endif
}


/*
** todo: Interrupts.
*/


uint16 HC12Ect_GetOverflowCount(void)
{
#if defined(HC12ECT_USE_TIMER_OVERFLOW_INTR)
    return HC12Ect_OverflowCount;
#else
    return (uint16)0x0000U;
#endif
}


uint32 HC12Ect_GetTickCount(void)
{
#if defined(HC12ECT_USE_TIMER_OVERFLOW_INTR)
    return (((uint32)HC12Ect_OverflowCount)<<16) + HC12Ect_TimerCount();
#else
    return (uint32)HC12Ect_TimerCount();
#endif
}


#if defined(HC12ECT_USE_TIMER_OVERFLOW_INTR)
ISR1(HC12Ect_TofHandler)
{
    HC12ECT_ACKNOWLEDGE_TOF_INTR();

    HC12Ect_OverflowCount++;
}
#endif
