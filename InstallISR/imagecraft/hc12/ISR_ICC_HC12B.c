/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
**
**  Interrupt-Vectors HC12B-Series.
**
*/

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(RESET_VECTOR)
#define RESET_VECTOR    IISR_ENTRY_POINT
#endif  /*  RESET_VECTOR */

#if !defined(CMF_VECTOR)
#define CMF_VECTOR      IISR_ENTRY_POINT
#endif  /*  CMF_VECTOR  */

#if !defined(COP_VECTOR)
#define COP_VECTOR      IISR_ENTRY_POINT
#endif  /*  COP_VECTOR  */

#if !defined(TRAP_VECTOR)
#define TRAP_VECTOR     DUMMY_VECTOR
#endif  /*  TRAP_VECTOR */

#if !defined(SWI_VECTOR)
#define SWI_VECTOR      DUMMY_VECTOR
#endif  /*  SWI_VECTOR  */

#if !defined(XIRQ_VECTOR)
#define XIRQ_VECTOR     DUMMY_VECTOR
#endif  /*  XIRQ_VECTOR */

#if !defined(IRQ_VECTOR)
#define IRQ_VECTOR      DUMMY_VECTOR
#endif  /*  IRQ_VECTOR  */

#if !defined(RTI_VECTOR)
#define RTI_VECTOR      DUMMY_VECTOR
#endif  /*  RTI_VECTOR  */

#if !defined(TC0_VECTOR)
#define TC0_VECTOR      DUMMY_VECTOR
#endif  /*  TC0_VECTOR  */

#if !defined(TC1_VECTOR)
#define TC1_VECTOR      DUMMY_VECTOR
#endif  /*  TC1_VECTOR  */

#if !defined(TC2_VECTOR)
#define TC2_VECTOR      DUMMY_VECTOR
#endif  /*  TC2_VECTOR  */

#if !defined(TC3_VECTOR)
#define TC3_VECTOR      DUMMY_VECTOR
#endif  /*  TC3_VECTOR  */

#if !defined(TC4_VECTOR)
#define TC4_VECTOR      DUMMY_VECTOR
#endif  /*  TC4_VECTOR  */

#if !defined(TC5_VECTOR)
#define TC5_VECTOR      DUMMY_VECTOR
#endif  /*  TC5_VECTOR  */

#if !defined(TC6_VECTOR)
#define TC6_VECTOR      DUMMY_VECTOR
#endif  /*  TC6_VECTOR  */

#if !defined(TC7_VECTOR)
#define TC7_VECTOR      DUMMY_VECTOR
#endif  /*  TC7_VECTOR  */

#if !defined(TOF_VECTOR)
#define TOF_VECTOR      DUMMY_VECTOR
#endif  /*  TOF_VECTOR  */

#if !defined(PAOF_VECTOR)
#define PAOF_VECTOR     DUMMY_VECTOR
#endif  /*  PAOF_VECTOR */

#if !defined(PAIE_VECTOR)
#define PAIE_VECTOR     DUMMY_VECTOR
#endif  /*  PAIE_VECTOR */

#if !defined(SPI_VECTOR)
#define SPI_VECTOR      DUMMY_VECTOR
#endif  /*  SPI_VECTOR */

#if !defined(SCI_VECTOR)
#define SCI_VECTOR      DUMMY_VECTOR
#endif  /*  SCI_VECTOR */

#if CPU_DERIVATE == CPU12_HC12BC32
    #if !defined(CANW_VECTOR)
    #define CANW_VECTOR DUMMY_VECTOR
    #endif  /*  CANW_VECTOR  */
#endif      /* CPU12_HC12BC32*/

#if CPU_DERIVATE == CPU12_HC12B32
    #if !defined(BDLC_VECTOR)
    #define BDLC_VECTOR DUMMY_VECTOR
    #endif  /*  BDLC_VECTOR */
#endif      /* CPU12_HC12B32 */

#if CPU_DERIVATE == CPU12_HC12BC32
    #if !defined(CANE_VECTOR)
    #define CANE_VECTOR DUMMY_VECTOR
    #endif /*  CANE_VECTOR  */

    #if !defined(CANR_VECTOR)
    #define CANR_VECTOR DUMMY_VECTOR
    #endif /*  CANR_VECTOR  */

    #if !defined(CANT_VECTOR)
    #define CANT_VECTOR DUMMY_VECTOR
    #endif  /*  CANT_VECTOR  */
#endif      /* CPU12_HC12BC32 */

#if CPU_DERIVATE == CPU12_HC12B32
    #if !defined(MDCU_VECTOR)
    #define MDCU_VECTOR DUMMY_VECTOR
    #endif /*  MDCU_VECTOR */

    #if !defined(PBOF_VECTOR)
    #define PBOF_VECTOR DUMMY_VECTOR
    #endif  /*  PBOF_VECTOR */
#endif      /* CPU12_HC12B32  */

ISR1(DUMMY_VECTOR)
{
}

#pragma abs_address:0xFF80
void(*const interrupt_vectors[]) (void) = {
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF80                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF82                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF84                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF86                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF88                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF8A                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF8C                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF8E                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF90                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF92                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF94                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF96                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF98                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF9A                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF9C                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FF9E                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFA0                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFA2                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFA4                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFA6                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFA8                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFAA                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFAC                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFAE                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB0                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB2                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB4                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB6                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB8                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFBA                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFBC                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFBE                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFC0                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFC2                   */
#if CPU_DERIVATE == CPU12_HC12BC32
    (IISR_IVF)CANT_VECTOR,      /* MSCAN  Transmit                  */
    (IISR_IVF)CANR_VECTOR,      /* MSCAN  Receive                   */
    (IISR_IVF)CANE_VECTOR,      /* MSCAN  Error                     */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFCA                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFCC                   */
#elif CPU_DERIVATE == CPU12_HC12B32
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFC4                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFC6                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFC8                   */
    (IISR_IVF)MDCU_VECTOR,      /* Modulus Down Counter Underflow   */
    (IISR_IVF)PBOF_VECTOR,      /* Pulse Accumulator B Overflow     */
#endif
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved  $FFCE                  */
#if CPU_DERIVATE == CPU12_HC12B32
    (IISR_IVF)BDLC_VECTOR,      /* BDLC                             */
#elif CPU_DERIVATE == CPU12_HC12BC32
    (IISR_IVF)CANW_VECTOR,      /* MSCAN  Wake-up                   */
#endif
    (IISR_IVF)ATD_VECTOR,       /* ATD                              */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFD4                   */
    (IISR_IVF)SCI_VECTOR,       /* SCI                              */
    (IISR_IVF)SPI_VECTOR,       /* SPI                              */
    (IISR_IVF)PAIE_VECTOR,      /* Pulse Accumulator A Input Edge   */
    (IISR_IVF)PAOF_VECTOR,      /* Pulse Accumulator A Overflow     */
    (IISR_IVF)TOF_VECTOR,       /* Timer Overflow                   */
    (IISR_IVF)TC7_VECTOR,       /* Timer Channel 7                  */
    (IISR_IVF)TC6_VECTOR,       /* Timer Channel 6                  */
    (IISR_IVF)TC5_VECTOR,       /* Timer Channel 5                  */
    (IISR_IVF)TC4_VECTOR,       /* Timer Channel 4                  */
    (IISR_IVF)TC3_VECTOR,       /* Timer Channel 3                  */
    (IISR_IVF)TC2_VECTOR,       /* Timer Channel 2                  */
    (IISR_IVF)TC1_VECTOR,       /* Timer Channel 1                  */
    (IISR_IVF)TC0_VECTOR,       /* Timer Channel 0                  */
    (IISR_IVF)RTI_VECTOR,       /* Real Time Interrupt              */

    #include "HC12_Common_Vectors.h"
};

#pragma end_abs_address

