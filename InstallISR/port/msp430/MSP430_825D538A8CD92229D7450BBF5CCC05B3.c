/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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

/*
 *
 *  Interrupt-Vectors for:
 *      msp430c311s
 *      msp430c312
 *      msp430c313
 *      msp430c314
 *      msp430c315
 *      msp430e313
 *      msp430e315
 *      msp430p313
 *      msp430p315
 *      msp430p315s
 *      msp430x31x
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(PORT0_VECTOR)
#define PORT0_VECTOR            DUMMY_VECTOR
#endif  /* PORT0_VECTOR         */

#if !defined(BASICTIMER_VECTOR)
#define BASICTIMER_VECTOR       DUMMY_VECTOR
#endif  /* BASICTIMER_VECTOR    */

#if !defined(TIMERPORT_VECTOR)
#define TIMERPORT_VECTOR        DUMMY_VECTOR
#endif  /* TIMERPORT_VECTOR     */

#if !defined(WDT_VECTOR)
#define WDT_VECTOR              DUMMY_VECTOR
#endif  /* WDT_VECTOR           */

#if !defined(IO1_VECTOR)
#define IO1_VECTOR              DUMMY_VECTOR
#endif  /* IO1_VECTOR           */

#if !defined(IO0_VECTOR)
#define IO0_VECTOR              DUMMY_VECTOR
#endif  /* IO0_VECTOR           */

#if !defined(NMI_VECTOR)
#define NMI_VECTOR              DUMMY_VECTOR
#endif  /* NMI_VECTOR           */

#if !defined(RESET_VECTOR)
#define RESET_VECTOR            IISR_ENTRY_POINT
#endif  /* RESET_VECTOR         */


ISR1(DUMMY_VECTOR)
{
}

#pragma constseg = INTVEC   /* @ 0xffe0 */
#pragma required = interrupt_vectors
#pragma location = 0xffe0  /* Lowest Offset: 0 */
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)PORT0_VECTOR,             /* Port 0 Bits 2-7 [Lowest Priority]    */
    (IISR_IVF)BASICTIMER_VECTOR,        /* Basic Timer                          */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe4                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe6                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe8                    */
    (IISR_IVF)TIMERPORT_VECTOR,         /* Timer/Port                           */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffec                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffee                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff2                    */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff6                    */
    (IISR_IVF)IO1_VECTOR,               /* Dedicated IO (P0.1)                  */
    (IISR_IVF)IO0_VECTOR,               /* Dedicated IO (P0.0)                  */
    (IISR_IVF)NMI_VECTOR,               /* Non-maskable                         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

