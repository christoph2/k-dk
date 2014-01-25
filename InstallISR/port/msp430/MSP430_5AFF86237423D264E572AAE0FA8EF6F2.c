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
 *      msp430f2471
 *      msp430f2481
 *      msp430f2491
 *      msp430x24x1
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(RESERVED0_VECTOR)
#define RESERVED0_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED0_VECTOR     */

#if !defined(RESERVED1_VECTOR)
#define RESERVED1_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED1_VECTOR     */

#if !defined(RESERVED2_VECTOR)
#define RESERVED2_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED2_VECTOR     */

#if !defined(RESERVED3_VECTOR)
#define RESERVED3_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED3_VECTOR     */

#if !defined(RESERVED4_VECTOR)
#define RESERVED4_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED4_VECTOR     */

#if !defined(RESERVED5_VECTOR)
#define RESERVED5_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED5_VECTOR     */

#if !defined(RESERVED6_VECTOR)
#define RESERVED6_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED6_VECTOR     */

#if !defined(RESERVED7_VECTOR)
#define RESERVED7_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED7_VECTOR     */

#if !defined(RESERVED8_VECTOR)
#define RESERVED8_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED8_VECTOR     */

#if !defined(RESERVED9_VECTOR)
#define RESERVED9_VECTOR        DUMMY_VECTOR
#endif  /* RESERVED9_VECTOR     */

#if !defined(RESERVED10_VECTOR)
#define RESERVED10_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED10_VECTOR    */

#if !defined(RESERVED11_VECTOR)
#define RESERVED11_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED11_VECTOR    */

#if !defined(RESERVED12_VECTOR)
#define RESERVED12_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED12_VECTOR    */

#if !defined(RESERVED13_VECTOR)
#define RESERVED13_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED13_VECTOR    */

#if !defined(RESERVED14_VECTOR)
#define RESERVED14_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED14_VECTOR    */

#if !defined(RESERVED15_VECTOR)
#define RESERVED15_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED15_VECTOR    */

#if !defined(USCIAB1TX_VECTOR)
#define USCIAB1TX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB1TX_VECTOR     */

#if !defined(USCIAB1RX_VECTOR)
#define USCIAB1RX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB1RX_VECTOR     */

#if !defined(PORT1_VECTOR)
#define PORT1_VECTOR            DUMMY_VECTOR
#endif  /* PORT1_VECTOR         */

#if !defined(PORT2_VECTOR)
#define PORT2_VECTOR            DUMMY_VECTOR
#endif  /* PORT2_VECTOR         */

#if !defined(RESERVED20_VECTOR)
#define RESERVED20_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED20_VECTOR    */

#if !defined(RESERVED21_VECTOR)
#define RESERVED21_VECTOR       DUMMY_VECTOR
#endif  /* RESERVED21_VECTOR    */

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

#if !defined(COMPARATORA_VECTOR)
#define COMPARATORA_VECTOR      DUMMY_VECTOR
#endif  /* COMPARATORA_VECTOR   */

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

#pragma constseg = INTVEC   /* @ 0xffc0 */
#pragma required = interrupt_vectors
#pragma location = 0xffc0  /* Lowest Offset: 0 */
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)RESERVED0_VECTOR,         /* Reserved Int. Vector 0               */
    (IISR_IVF)RESERVED1_VECTOR,         /* Reserved Int. Vector 1               */
    (IISR_IVF)RESERVED2_VECTOR,         /* Reserved Int. Vector 2               */
    (IISR_IVF)RESERVED3_VECTOR,         /* Reserved Int. Vector 3               */
    (IISR_IVF)RESERVED4_VECTOR,         /* Reserved Int. Vector 4               */
    (IISR_IVF)RESERVED5_VECTOR,         /* Reserved Int. Vector 5               */
    (IISR_IVF)RESERVED6_VECTOR,         /* Reserved Int. Vector 6               */
    (IISR_IVF)RESERVED7_VECTOR,         /* Reserved Int. Vector 7               */
    (IISR_IVF)RESERVED8_VECTOR,         /* Reserved Int. Vector 8               */
    (IISR_IVF)RESERVED9_VECTOR,         /* Reserved Int. Vector 9               */
    (IISR_IVF)RESERVED10_VECTOR,        /* Reserved Int. Vector 10              */
    (IISR_IVF)RESERVED11_VECTOR,        /* Reserved Int. Vector 11              */
    (IISR_IVF)RESERVED12_VECTOR,        /* Reserved Int. Vector 12              */
    (IISR_IVF)RESERVED13_VECTOR,        /* Reserved Int. Vector 13              */
    (IISR_IVF)RESERVED14_VECTOR,        /* Reserved Int. Vector 14              */
    (IISR_IVF)RESERVED15_VECTOR,        /* Reserved Int. Vector 15              */
    (IISR_IVF)USCIAB1TX_VECTOR,         /* USCI A1/B1 Transmit                  */
    (IISR_IVF)USCIAB1RX_VECTOR,         /* USCI A1/B1 Receive                   */
    (IISR_IVF)PORT1_VECTOR,             /* Port 1                               */
    (IISR_IVF)PORT2_VECTOR,             /* Port 2                               */
    (IISR_IVF)RESERVED20_VECTOR,        /* Reserved Int. Vector 20              */
    (IISR_IVF)RESERVED21_VECTOR,        /* Reserved Int. Vector 21              */
    (IISR_IVF)USCIAB0TX_VECTOR,         /* USCI A0/B0 Transmit                  */
    (IISR_IVF)USCIAB0RX_VECTOR,         /* USCI A0/B0 Receive                   */
    (IISR_IVF)TIMERA1_VECTOR,           /* Timer A CC1-2, TA                    */
    (IISR_IVF)TIMERA0_VECTOR,           /* Timer A CC0                          */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)COMPARATORA_VECTOR,       /* Comparator A                         */
    (IISR_IVF)TIMERB1_VECTOR,           /* Timer B CC1-6, TB                    */
    (IISR_IVF)TIMERB0_VECTOR,           /* Timer B CC0                          */
    (IISR_IVF)NMI_VECTOR,               /* Non-maskable                         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

