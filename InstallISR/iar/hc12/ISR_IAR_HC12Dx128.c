/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
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
 */
/*
**
**       Interrupt-Vectors HC12D128x-Series.
**
*/

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(RESET_VECTOR)
#define RESET_VECTOR        IISR_ENTRY_POINT
#endif  /*  RESET_VECTOR */

#if !defined(CMF_VECTOR)
#define CMF_VECTOR          IISR_ENTRY_POINT
#endif  /*  CMF_VECTOR  */

#if !defined(COP_VECTOR)
#define COP_VECTOR          IISR_ENTRY_POINT
#endif  /*  COP_VECTOR  */

#if !defined(TRAP_VECTOR)
#define TRAP_VECTOR         DUMMY_VECTOR
#endif  /*  TRAP_VECTOR */

#if !defined(SWI_VECTOR)
#define SWI_VECTOR          DUMMY_VECTOR
#endif  /*  SWI_VECTOR  */

#if !defined(XIRQ_VECTOR)
#define XIRQ_VECTOR         DUMMY_VECTOR
#endif  /*  XIRQ_VECTOR */

#if !defined(IRQ_VECTOR)
#define IRQ_VECTOR          DUMMY_VECTOR
#endif  /*  IRQ_VECTOR  */

#if !defined(RTI_VECTOR)
#define RTI_VECTOR          DUMMY_VECTOR
#endif  /*  RTI_VECTOR  */

#if !defined(TC0_VECTOR)
#define TC0_VECTOR          DUMMY_VECTOR
#endif  /*  TC0_VECTOR  */

#if !defined(TC1_VECTOR)
#define TC1_VECTOR          DUMMY_VECTOR
#endif  /*  TC1_VECTOR  */

#if !defined(TC2_VECTOR)
#define TC2_VECTOR          DUMMY_VECTOR
#endif  /*  TC2_VECTOR  */

#if !defined(TC3_VECTOR)
#define TC3_VECTOR          DUMMY_VECTOR
#endif  /*  TC3_VECTOR  */

#if !defined(TC4_VECTOR)
#define TC4_VECTOR          DUMMY_VECTOR
#endif  /*  TC4_VECTOR  */

#if !defined(TC5_VECTOR)
#define TC5_VECTOR          DUMMY_VECTOR
#endif  /*  TC5_VECTOR  */

#if !defined(TC6_VECTOR)
#define TC6_VECTOR          DUMMY_VECTOR
#endif  /*  TC6_VECTOR  */

#if !defined(TC7_VECTOR)
#define TC7_VECTOR          DUMMY_VECTOR
#endif  /*  TC7_VECTOR  */

#if !defined(TOF_VECTOR)
#define TOF_VECTOR          DUMMY_VECTOR
#endif  /*  TOF_VECTOR  */

#if !defined(PAOF_VECTOR)
#define PAOF_VECTOR         DUMMY_VECTOR
#endif  /*  PAOF_VECTOR */

#if !defined(PAIE_VECTOR)
#define PAIE_VECTOR         DUMMY_VECTOR
#endif  /*  PAIE_VECTOR */

#if !defined(SPI_VECTOR)
#define SPI_VECTOR          DUMMY_VECTOR
#endif  /*  SPI_VECTOR */

#if !defined(SCI0_VECTOR)
#define SCI0_VECTOR         DUMMY_VECTOR
#endif  /*  SCI0_VECTOR */

#if !defined(SCI1_VECTOR)
#define SCI1_VECTOR         DUMMY_VECTOR
#endif  /*  SCI1_VECTOR */

#if !defined(ATD_VECTOR)
#define ATD_VECTOR          DUMMY_VECTOR
#endif  /*  ATD_VECTOR */

#if !defined(CAN0W_VECTOR)
#define CAN0W_VECTOR        DUMMY_VECTOR
#endif  /*  CAN0W_VECTOR  */

#if !defined(CAN0E_VECTOR)
#define CAN0E_VECTOR        DUMMY_VECTOR
#endif  /*  CAN0E_VECTOR  */

#if !defined(CAN0R_VECTOR)
#define CAN0R_VECTOR        DUMMY_VECTOR
#endif  /*  CAN0R_VECTOR  */

#if !defined(CAN0T_VECTOR)
#define CAN0T_VECTOR        DUMMY_VECTOR
#endif  /*  CAN0T_VECTOR  */

#if !defined(MDCU_VECTOR)
#define MDCU_VECTOR         DUMMY_VECTOR
#endif  /*  MDCU_VECTOR */

#if !defined(PBOF_VECTOR)
#define PBOF_VECTOR         DUMMY_VECTOR
#endif  /*  PBOF_VECTOR */

#if !defined(KWU_VECTOR)
#define KWU_VECTOR          DUMMY_VECTOR
#endif  /*  KWU_VECTOR */

#if !defined(CGM_VECTOR)
#define CGM_VECTOR          DUMMY_VECTOR
#endif  /*  CGM_VECTOR */

#if !defined(IIC_VECTOR)
#define IIC_VECTOR          DUMMY_VECTOR
#endif  /*  IIC_VECTOR */

#if !defined(CAN1W_VECTOR)
#define CAN1W_VECTOR        DUMMY_VECTOR
#endif  /*  CAN1W_VECTOR  */

#if !defined(CAN1E_VECTOR)
#define CAN1E_VECTOR        DUMMY_VECTOR
#endif  /*  CAN1E_VECTOR  */

#if !defined(CAN1R_VECTOR)
#define CAN1R_VECTOR        DUMMY_VECTOR
#endif  /*  CAN1R_VECTOR  */

#if !defined(CAN1T_VECTOR)
#define CAN1T_VECTOR        DUMMY_VECTOR
#endif  /*  CAN1T_VECTOR  */

#if CPU_DERIVATE == CPU12_HC12DT128A
    #if !defined(CAN2W_VECTOR)
    #define CAN2W_VECTOR    DUMMY_VECTOR
    #endif  /*  CAN2W_VECTOR  */

    #if !defined(CAN2E_VECTOR)
    #define CAN2E_VECTOR    DUMMY_VECTOR
    #endif  /*  CAN2E_VECTOR  */

    #if !defined(CAN2R_VECTOR)
    #define CAN2R_VECTOR    DUMMY_VECTOR
    #endif  /*  CAN2R_VECTOR  */

    #if !defined(CAN2T_VECTOR)
    #define CAN2T_VECTOR    DUMMY_VECTOR
    #endif  /*  CAN2T_VECTOR  */
#endif      /* CPU12_HC12DT128A */

ISR1(DUMMY_VECTOR)
{
}

#pragma constseg=INTVEC
#pragma required=interrupt_vectors
__root void(* const interrupt_vectors[]) (void) =
{
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
#if CPU_DERIVATE == CPU12_HC12DT128A
    (IISR_IVF)CAN2T_VECTOR,     /* MSCAN2  Transmit                 */
    (IISR_IVF)CAN2R_VECTOR,     /* MSCAN2  Receive                  */
    (IISR_IVF)CAN2E_VECTOR,     /* MSCAN2  Error                    */
    (IISR_IVF)CAN2W_VECTOR,     /* MSCAN2  Wake-up                  */
#else
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB0                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB2                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB4                   */
    (IISR_IVF)DUMMY_VECTOR,     /* Reserved $FFB6                   */
#endif
    (IISR_IVF)CAN1T_VECTOR,     /* MSCAN1  Transmit                 */
    (IISR_IVF)CAN1R_VECTOR,     /* MSCAN1  Receive                  */
    (IISR_IVF)CAN1E_VECTOR,     /* MSCAN1  Error                    */
    (IISR_IVF)CAN1W_VECTOR,     /* MSCAN1  Wake-up                  */
    (IISR_IVF)IIC_VECTOR,       /* IIC-Bus                          */
    (IISR_IVF)CGM_VECTOR,       /* RCGM lock and limp home          */
    (IISR_IVF)CAN0T_VECTOR,     /* MSCAN0  Transmit                 */
    (IISR_IVF)CAN0R_VECTOR,     /* MSCAN0  Receive                  */
    (IISR_IVF)CAN0E_VECTOR,     /* MSCAN0  Error                    */
    (IISR_IVF)PBOF_VECTOR,      /* Pulse Accumulator B Overflow     */
    (IISR_IVF)MDCU_VECTOR,      /* Modulus Down Counter Underflow   */
    (IISR_IVF)KWU_VECTOR,       /* Key wake-up Port J or H          */
    (IISR_IVF)CAN0W_VECTOR,     /* MSCAN0  Wake-up                  */
    (IISR_IVF)ATD_VECTOR,       /* ATD0 or ATD1                     */
    (IISR_IVF)SCI1_VECTOR,      /* SCI1                             */
    (IISR_IVF)SCI0_VECTOR,      /* SCI0                             */
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


