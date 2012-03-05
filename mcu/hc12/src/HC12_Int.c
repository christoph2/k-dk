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

#include "HC12_Int.h"
#include "Hw_Cfg.h"

/*
** Global Variables.
*/
HC12Int_ConfigType const * INT;

/*
** Global Functions.
*/
void HC12Int_Init(HC12Int_ConfigType const * const ConfigPtr)
{
    INT                    = ConfigPtr;
    HC12INT_REG8(INTCR)    = ConfigPtr->IntCr;
    HC12INT_REG8(HPRIO)    = ConfigPtr->HPrio;
}


void HC12Int_SetHighestPriorityInterrupt(uint8 value)
{
    HC12INT_REG8(HPRIO) = value;
}


/*
** ISR-Handlers.
*/
#if defined(HC12_FEATURE_XIRQ)
ISR1(HC12Int_XIRQHandler)
{
#if !defined(HC12INT_XIRQ_CALLBACK)
#error Symbol HC12INT_XIRQ_CALLBACK must be defined.
#else
    HC12INT_XIRQ_CALLBACK();
#endif  /* HC12INT_XIRQ_CALLBACK */
}
#endif  /* HC12_FEATURE_XIRQ */

#if defined(HC12_FEATURE_IRQ)
ISR1(HC12Int_IRQHandler)
{
#if !defined(HC12INT_IRQ_CALLBACK)
#error Symbol HC12INT_IRQ_CALLBACK must be defined.
#else
    HC12INT_IRQ_CALLBACK();
#endif  /* HC12INT_IRQ_CALLBACK */
}
#endif  /* HC12_FEATURE_IRQ */

