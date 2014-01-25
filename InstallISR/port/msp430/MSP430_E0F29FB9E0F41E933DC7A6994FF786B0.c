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
 *      msp430f47126
 *      msp430f47127
 *      msp430f47163
 *      msp430f47166
 *      msp430f47167
 *      msp430f47173
 *      msp430f47176
 *      msp430f47177
 *      msp430f47183
 *      msp430f47186
 *      msp430f47187
 *      msp430f47193
 *      msp430f47196
 *      msp430f47197
 *      msp430x471x6
 *      msp430x471x7
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(DMA_VECTOR)
#define DMA_VECTOR              DUMMY_VECTOR
#endif  /* DMA_VECTOR           */

#if !defined(BASICTIMER_VECTOR)
#define BASICTIMER_VECTOR       DUMMY_VECTOR
#endif  /* BASICTIMER_VECTOR    */

#if !defined(PORT2_VECTOR)
#define PORT2_VECTOR            DUMMY_VECTOR
#endif  /* PORT2_VECTOR         */

#if !defined(USCIAB1TX_VECTOR)
#define USCIAB1TX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB1TX_VECTOR     */

#if !defined(USCIAB1RX_VECTOR)
#define USCIAB1RX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB1RX_VECTOR     */

#if !defined(PORT1_VECTOR)
#define PORT1_VECTOR            DUMMY_VECTOR
#endif  /* PORT1_VECTOR         */

#if !defined(TIMERA1_VECTOR)
#define TIMERA1_VECTOR          DUMMY_VECTOR
#endif  /* TIMERA1_VECTOR       */

#if !defined(TIMERA0_VECTOR)
#define TIMERA0_VECTOR          DUMMY_VECTOR
#endif  /* TIMERA0_VECTOR       */

#if !defined(SD16A_VECTOR)
#define SD16A_VECTOR            DUMMY_VECTOR
#endif  /* SD16A_VECTOR         */

#if !defined(USCIAB0TX_VECTOR)
#define USCIAB0TX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0TX_VECTOR     */

#if !defined(USCIAB0RX_VECTOR)
#define USCIAB0RX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0RX_VECTOR     */

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

#pragma constseg = INTVEC   /* @ 0xffa2 */
#pragma required = interrupt_vectors
#pragma location = 0xffc0  /* Lowest Offset: 30 */
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc4                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc6                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffca                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffcc                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffce                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd2                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd4                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd6                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd8                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffda                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffdc                    */
    (IISR_IVF)DMA_VECTOR,               /* DMA                                  */
    (IISR_IVF)BASICTIMER_VECTOR,        /* Basic Timer / RTC                    */
    (IISR_IVF)PORT2_VECTOR,             /* Port 2                               */
    (IISR_IVF)USCIAB1TX_VECTOR,         /* USCI A1/B1 Transmit                  */
    (IISR_IVF)USCIAB1RX_VECTOR,         /* USCI A1/B1 Receive                   */
    (IISR_IVF)PORT1_VECTOR,             /* Port 1                               */
    (IISR_IVF)TIMERA1_VECTOR,           /* Timer A CC1-2, TA                    */
    (IISR_IVF)TIMERA0_VECTOR,           /* Timer A CC0                          */
    (IISR_IVF)SD16A_VECTOR,             /* ADC                                  */
    (IISR_IVF)USCIAB0TX_VECTOR,         /* USCI A0/B0 Transmit                  */
    (IISR_IVF)USCIAB0RX_VECTOR,         /* USCI A0/B0 Receive                   */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)COMPARATORA_VECTOR,       /* Comparator A                         */
    (IISR_IVF)TIMERB1_VECTOR,           /* Timer B CC1-2, TB                    */
    (IISR_IVF)TIMERB0_VECTOR,           /* Timer B CC0                          */
    (IISR_IVF)NMI_VECTOR,               /* Non-maskable                         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

