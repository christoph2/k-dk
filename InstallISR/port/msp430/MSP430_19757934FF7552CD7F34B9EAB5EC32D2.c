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
 *      msp430f2232
 *      msp430f2234
 *      msp430f2252
 *      msp430f2254
 *      msp430f2272
 *      msp430f2274
 *      msp430g2444
 *      msp430g2544
 *      msp430g2744
 *      msp430x22x2
 *      msp430x22x4
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(PORT1_VECTOR)
#define PORT1_VECTOR            DUMMY_VECTOR
#endif  /* PORT1_VECTOR         */

#if !defined(PORT2_VECTOR)
#define PORT2_VECTOR            DUMMY_VECTOR
#endif  /* PORT2_VECTOR         */

#if !defined(ADC10_VECTOR)
#define ADC10_VECTOR            DUMMY_VECTOR
#endif  /* ADC10_VECTOR         */

#if !defined(USCIAB0TX_VECTOR)
#define USCIAB0TX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0TX_VECTOR     */

#if !defined(USCIAB0RX_VECTOR)
#define USCIAB0RX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0RX_VECTOR     */

#if !defined(TIMERA1_VECTOR)
#define TIMERA1_VECTOR          DUMMY_VECTOR
#endif  /* TIMERA1_VECTOR       */

#if !defined(TIMERA0_VECTOR)
#define TIMERA0_VECTOR          DUMMY_VECTOR
#endif  /* TIMERA0_VECTOR       */

#if !defined(WDT_VECTOR)
#define WDT_VECTOR              DUMMY_VECTOR
#endif  /* WDT_VECTOR           */

#if !defined(TIMERB1_VECTOR)
#define TIMERB1_VECTOR          DUMMY_VECTOR
#endif  /* TIMERB1_VECTOR       */

#if !defined(TIMERB0_VECTOR)
#define TIMERB0_VECTOR          DUMMY_VECTOR
#endif  /* TIMERB0_VECTOR       */

#if !defined(NMI_VECTOR)
#define NMI_VECTOR              DUMMY_VECTOR
#endif  /* NMI_VECTOR           */

#if !defined(RESET_VECTOR)
#define RESET_VECTOR            IISR_ENTRY_POINT
#endif  /* RESET_VECTOR         */


ISR1(DUMMY_VECTOR)
{
}

#pragma constseg = INTVEC   /* @ 0xffdc */
#pragma required = interrupt_vectors
#pragma location = 0xffe0  /* Lowest Offset: 4 */
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe2                    */
    (IISR_IVF)PORT1_VECTOR,             /* Port 1                               */
    (IISR_IVF)PORT2_VECTOR,             /* Port 2                               */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe8                    */
    (IISR_IVF)ADC10_VECTOR,             /* ADC10                                */
    (IISR_IVF)USCIAB0TX_VECTOR,         /* USCI A0/B0 Transmit                  */
    (IISR_IVF)USCIAB0RX_VECTOR,         /* USCI A0/B0 Receive                   */
    (IISR_IVF)TIMERA1_VECTOR,           /* Timer A CC1-2, TA                    */
    (IISR_IVF)TIMERA0_VECTOR,           /* Timer A CC0                          */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff6                    */
    (IISR_IVF)TIMERB1_VECTOR,           /* Timer B CC1-2, TB                    */
    (IISR_IVF)TIMERB0_VECTOR,           /* Timer B CC0                          */
    (IISR_IVF)NMI_VECTOR,               /* Non-maskable                         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

