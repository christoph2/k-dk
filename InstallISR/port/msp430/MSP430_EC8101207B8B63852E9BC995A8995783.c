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
 *      msp430f5131
 *      msp430f5151
 *      msp430f5171
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(PORT2_VECTOR)
#define PORT2_VECTOR            DUMMY_VECTOR
#endif  /* PORT2_VECTOR         */

#if !defined(PORT1_VECTOR)
#define PORT1_VECTOR            DUMMY_VECTOR
#endif  /* PORT1_VECTOR         */

#if !defined(TIMER1_D1_VECTOR)
#define TIMER1_D1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_D1_VECTOR     */

#if !defined(TIMER1_D0_VECTOR)
#define TIMER1_D0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_D0_VECTOR     */

#if !defined(TEC1_VECTOR)
#define TEC1_VECTOR             DUMMY_VECTOR
#endif  /* TEC1_VECTOR          */

#if !defined(DMA_VECTOR)
#define DMA_VECTOR              DUMMY_VECTOR
#endif  /* DMA_VECTOR           */

#if !defined(TIMER0_A1_VECTOR)
#define TIMER0_A1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A1_VECTOR     */

#if !defined(TIMER0_A0_VECTOR)
#define TIMER0_A0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A0_VECTOR     */

#if !defined(USCI_B0_VECTOR)
#define USCI_B0_VECTOR          DUMMY_VECTOR
#endif  /* USCI_B0_VECTOR       */

#if !defined(USCI_A0_VECTOR)
#define USCI_A0_VECTOR          DUMMY_VECTOR
#endif  /* USCI_A0_VECTOR       */

#if !defined(WDT_VECTOR)
#define WDT_VECTOR              DUMMY_VECTOR
#endif  /* WDT_VECTOR           */

#if !defined(TIMER0_D1_VECTOR)
#define TIMER0_D1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_D1_VECTOR     */

#if !defined(TIMER0_D0_VECTOR)
#define TIMER0_D0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_D0_VECTOR     */

#if !defined(TEC0_VECTOR)
#define TEC0_VECTOR             DUMMY_VECTOR
#endif  /* TEC0_VECTOR          */

#if !defined(COMP_B_VECTOR)
#define COMP_B_VECTOR           DUMMY_VECTOR
#endif  /* COMP_B_VECTOR        */

#if !defined(UNMI_VECTOR)
#define UNMI_VECTOR             DUMMY_VECTOR
#endif  /* UNMI_VECTOR          */

#if !defined(SYSNMI_VECTOR)
#define SYSNMI_VECTOR           DUMMY_VECTOR
#endif  /* SYSNMI_VECTOR        */

#if !defined(RESET_VECTOR)
#define RESET_VECTOR            IISR_ENTRY_POINT
#endif  /* RESET_VECTOR         */


ISR1(DUMMY_VECTOR)
{
}

#pragma constseg = INTVEC   /* @ 0xff26 */
#pragma required = interrupt_vectors
#pragma location = 0xff80  /* Lowest Offset: 90 */
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff80                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff82                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff84                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff86                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff88                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8a                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8c                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8e                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff90                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff92                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff94                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff96                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff98                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9a                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9c                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9e                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa2                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa4                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa6                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa8                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffaa                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffac                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffae                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb0                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb2                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb4                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb6                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb8                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc                    */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe                    */
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
    (IISR_IVF)PORT2_VECTOR,             /* Port 2                               */
    (IISR_IVF)PORT1_VECTOR,             /* Port 1                               */
    (IISR_IVF)TIMER1_D1_VECTOR,         /* Timer1_D3 CC1-2, TA1                 */
    (IISR_IVF)TIMER1_D0_VECTOR,         /* Timer1_D3 CC0                        */
    (IISR_IVF)TEC1_VECTOR,              /* Timer Event Controller 1             */
    (IISR_IVF)DMA_VECTOR,               /* DMA                                  */
    (IISR_IVF)TIMER0_A1_VECTOR,         /* Timer0_A3 CC1-2, TA                  */
    (IISR_IVF)TIMER0_A0_VECTOR,         /* Timer0_A3 CC0                        */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffea                    */
    (IISR_IVF)USCI_B0_VECTOR,           /* USCI B0 Receive/Transmit             */
    (IISR_IVF)USCI_A0_VECTOR,           /* USCI A0 Receive/Transmit             */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)TIMER0_D1_VECTOR,         /* Timer0_D3 CC1-2, TA                  */
    (IISR_IVF)TIMER0_D0_VECTOR,         /* Timer0_D3 CC0                        */
    (IISR_IVF)TEC0_VECTOR,              /* Timer Event Controller 0             */
    (IISR_IVF)COMP_B_VECTOR,            /* Watchdog Timer                       */
    (IISR_IVF)UNMI_VECTOR,              /* User Non-maskable                    */
    (IISR_IVF)SYSNMI_VECTOR,            /* System Non-maskable                  */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

