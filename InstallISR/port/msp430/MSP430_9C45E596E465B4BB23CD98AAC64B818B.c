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
 *      msp430fr5721
 *      msp430fr5725
 *      msp430fr5729
 *      msp430fr5731
 *      msp430fr5735
 *      msp430fr5739
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(RTC_VECTOR)
#define RTC_VECTOR              DUMMY_VECTOR
#endif  /* RTC_VECTOR           */

#if !defined(PORT4_VECTOR)
#define PORT4_VECTOR            DUMMY_VECTOR
#endif  /* PORT4_VECTOR         */

#if !defined(PORT3_VECTOR)
#define PORT3_VECTOR            DUMMY_VECTOR
#endif  /* PORT3_VECTOR         */

#if !defined(TIMER2_B1_VECTOR)
#define TIMER2_B1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER2_B1_VECTOR     */

#if !defined(TIMER2_B0_VECTOR)
#define TIMER2_B0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER2_B0_VECTOR     */

#if !defined(PORT2_VECTOR)
#define PORT2_VECTOR            DUMMY_VECTOR
#endif  /* PORT2_VECTOR         */

#if !defined(TIMER1_B1_VECTOR)
#define TIMER1_B1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_B1_VECTOR     */

#if !defined(TIMER1_B0_VECTOR)
#define TIMER1_B0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_B0_VECTOR     */

#if !defined(PORT1_VECTOR)
#define PORT1_VECTOR            DUMMY_VECTOR
#endif  /* PORT1_VECTOR         */

#if !defined(TIMER1_A1_VECTOR)
#define TIMER1_A1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_A1_VECTOR     */

#if !defined(TIMER1_A0_VECTOR)
#define TIMER1_A0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER1_A0_VECTOR     */

#if !defined(DMA_VECTOR)
#define DMA_VECTOR              DUMMY_VECTOR
#endif  /* DMA_VECTOR           */

#if !defined(USCI_A1_VECTOR)
#define USCI_A1_VECTOR          DUMMY_VECTOR
#endif  /* USCI_A1_VECTOR       */

#if !defined(TIMER0_A1_VECTOR)
#define TIMER0_A1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A1_VECTOR     */

#if !defined(TIMER0_A0_VECTOR)
#define TIMER0_A0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_A0_VECTOR     */

#if !defined(ADC10_VECTOR)
#define ADC10_VECTOR            DUMMY_VECTOR
#endif  /* ADC10_VECTOR         */

#if !defined(USCI_B0_VECTOR)
#define USCI_B0_VECTOR          DUMMY_VECTOR
#endif  /* USCI_B0_VECTOR       */

#if !defined(USCI_A0_VECTOR)
#define USCI_A0_VECTOR          DUMMY_VECTOR
#endif  /* USCI_A0_VECTOR       */

#if !defined(WDT_VECTOR)
#define WDT_VECTOR              DUMMY_VECTOR
#endif  /* WDT_VECTOR           */

#if !defined(TIMER0_B1_VECTOR)
#define TIMER0_B1_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_B1_VECTOR     */

#if !defined(TIMER0_B0_VECTOR)
#define TIMER0_B0_VECTOR        DUMMY_VECTOR
#endif  /* TIMER0_B0_VECTOR     */

#if !defined(COMP_D_VECTOR)
#define COMP_D_VECTOR           DUMMY_VECTOR
#endif  /* COMP_D_VECTOR        */

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

#pragma constseg = INTVEC   /* @ 0xff52 */
#pragma required = interrupt_vectors
#pragma location = 0xff90  /* Lowest Offset: 62 */
__root void(* const interrupt_vectors[]) (void) = {
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
    (IISR_IVF)RTC_VECTOR,               /* RTC                                  */
    (IISR_IVF)PORT4_VECTOR,             /* Port 4                               */
    (IISR_IVF)PORT3_VECTOR,             /* Port 3                               */
    (IISR_IVF)TIMER2_B1_VECTOR,         /* Timer2_B3 CC1-2, TB                  */
    (IISR_IVF)TIMER2_B0_VECTOR,         /* Timer2_B3 CC0                        */
    (IISR_IVF)PORT2_VECTOR,             /* Port 2                               */
    (IISR_IVF)TIMER1_B1_VECTOR,         /* Timer1_B3 CC1-2, TB                  */
    (IISR_IVF)TIMER1_B0_VECTOR,         /* Timer1_B3 CC0                        */
    (IISR_IVF)PORT1_VECTOR,             /* Port 1                               */
    (IISR_IVF)TIMER1_A1_VECTOR,         /* Timer1_A3 CC1-2, TA1                 */
    (IISR_IVF)TIMER1_A0_VECTOR,         /* Timer1_A3 CC0                        */
    (IISR_IVF)DMA_VECTOR,               /* DMA                                  */
    (IISR_IVF)USCI_A1_VECTOR,           /* USCI A1 Receive/Transmit             */
    (IISR_IVF)TIMER0_A1_VECTOR,         /* Timer0_A5 CC1-4, TA                  */
    (IISR_IVF)TIMER0_A0_VECTOR,         /* Timer0_A5 CC0                        */
    (IISR_IVF)ADC10_VECTOR,             /* ADC                                  */
    (IISR_IVF)USCI_B0_VECTOR,           /* USCI B0 Receive/Transmit             */
    (IISR_IVF)USCI_A0_VECTOR,           /* USCI A0 Receive/Transmit             */
    (IISR_IVF)WDT_VECTOR,               /* Watchdog Timer                       */
    (IISR_IVF)TIMER0_B1_VECTOR,         /* Timer0_B3 CC1-2, TB                  */
    (IISR_IVF)TIMER0_B0_VECTOR,         /* Timer0_B3 CC0                        */
    (IISR_IVF)COMP_D_VECTOR,            /* Comparator D                         */
    (IISR_IVF)UNMI_VECTOR,              /* User Non-maskable                    */
    (IISR_IVF)SYSNMI_VECTOR,            /* System Non-maskable                  */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,             /* Reset                                */
#endif
};

#pragma constseg=default

