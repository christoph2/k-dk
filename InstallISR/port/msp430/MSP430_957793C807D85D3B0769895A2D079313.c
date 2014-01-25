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
 *      msp430g2203
 *      msp430g2303
 *      msp430g2403
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

#if !defined(USCIAB0TX_VECTOR)
#define USCIAB0TX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0TX_VECTOR     */

#if !defined(USCIAB0RX_VECTOR)
#define USCIAB0RX_VECTOR        DUMMY_VECTOR
#endif  /* USCIAB0RX_VECTOR     */

#if !defined(TIMER0_A1_VECTOR)
#define TIMER0_A1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A1_VECTOR     */

#if !defined(TIMER0_A0_VECTOR)
#define TIMER0_A0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A0_VECTOR     */

#if !defined(WDT_VECTOR)
#define WDT_VECTOR              DUMMY_VECTOR
#endif  /* WDT_VECTOR           */

#if !defined(TIMER1_A1_VECTOR)
#define TIMER1_A1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_A1_VECTOR     */

#if !defined(TIMER1_A0_VECTOR)
#define TIMER1_A0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_A0_VECTOR     */

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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffea                    */
    (IISR_IVF)USCIAB0TX_VECTOR,         /* USCI A0/B0 Transmit                  */
    (IISR_IVF)USCIAB0RX_VECTOR,         /* USCI A0/B0 Receive                   */
    (IISR_IVF)TIMER0_A1_VECTOR,         /* Timer0)A CC1, TA0                    */
    (IISR_IVF)TIMER0_A0_VECTOR,         /* Timer0_A CC0                         */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff6                    */
    (IISR_IVF)TIMER1_A1_VECTOR,         /* Timer1_A CC1-4, TA1                  */
    (IISR_IVF)TIMER1_A0_VECTOR,         /* Timer1_A CC0                         */
    (IISR_IVF)NMI_VECTOR,               /* Non-maskable                         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

