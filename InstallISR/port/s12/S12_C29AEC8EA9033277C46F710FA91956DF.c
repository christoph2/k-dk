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
 *      MC9S12XEG384
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(SI_VECTOR)
#define SI_VECTOR               DUMMY_VECTOR
#endif  /* SI_VECTOR            */

#if !defined(SYSCALL_VECTOR)
#define SYSCALL_VECTOR          DUMMY_VECTOR
#endif  /* SYSCALL_VECTOR       */

#if !defined(MPUACCESSERR_VECTOR)
#define MPUACCESSERR_VECTOR     DUMMY_VECTOR
#endif  /* MPUACCESSERR_VECTOR  */

#if !defined(XSEI_VECTOR)
#define XSEI_VECTOR             DUMMY_VECTOR
#endif  /* XSEI_VECTOR          */

#if !defined(ATD1COMPARE_VECTOR)
#define ATD1COMPARE_VECTOR      DUMMY_VECTOR
#endif  /* ATD1COMPARE_VECTOR   */

#if !defined(ATD0COMPARE_VECTOR)
#define ATD0COMPARE_VECTOR      DUMMY_VECTOR
#endif  /* ATD0COMPARE_VECTOR   */

#if !defined(XST7_VECTOR)
#define XST7_VECTOR             DUMMY_VECTOR
#endif  /* XST7_VECTOR          */

#if !defined(XST6_VECTOR)
#define XST6_VECTOR             DUMMY_VECTOR
#endif  /* XST6_VECTOR          */

#if !defined(XST5_VECTOR)
#define XST5_VECTOR             DUMMY_VECTOR
#endif  /* XST5_VECTOR          */

#if !defined(XST4_VECTOR)
#define XST4_VECTOR             DUMMY_VECTOR
#endif  /* XST4_VECTOR          */

#if !defined(XST3_VECTOR)
#define XST3_VECTOR             DUMMY_VECTOR
#endif  /* XST3_VECTOR          */

#if !defined(XST2_VECTOR)
#define XST2_VECTOR             DUMMY_VECTOR
#endif  /* XST2_VECTOR          */

#if !defined(XST1_VECTOR)
#define XST1_VECTOR             DUMMY_VECTOR
#endif  /* XST1_VECTOR          */

#if !defined(XST0_VECTOR)
#define XST0_VECTOR             DUMMY_VECTOR
#endif  /* XST0_VECTOR          */

#if !defined(PIT3_VECTOR)
#define PIT3_VECTOR             DUMMY_VECTOR
#endif  /* PIT3_VECTOR          */

#if !defined(PIT2_VECTOR)
#define PIT2_VECTOR             DUMMY_VECTOR
#endif  /* PIT2_VECTOR          */

#if !defined(PIT1_VECTOR)
#define PIT1_VECTOR             DUMMY_VECTOR
#endif  /* PIT1_VECTOR          */

#if !defined(PIT0_VECTOR)
#define PIT0_VECTOR             DUMMY_VECTOR
#endif  /* PIT0_VECTOR          */

#if !defined(HTI_VECTOR)
#define HTI_VECTOR              DUMMY_VECTOR
#endif  /* HTI_VECTOR           */

#if !defined(API_VECTOR)
#define API_VECTOR              DUMMY_VECTOR
#endif  /* API_VECTOR           */

#if !defined(LVI_VECTOR)
#define LVI_VECTOR              DUMMY_VECTOR
#endif  /* LVI_VECTOR           */

#if !defined(IIC1_VECTOR)
#define IIC1_VECTOR             DUMMY_VECTOR
#endif  /* IIC1_VECTOR          */

#if !defined(SCI5_VECTOR)
#define SCI5_VECTOR             DUMMY_VECTOR
#endif  /* SCI5_VECTOR          */

#if !defined(SCI4_VECTOR)
#define SCI4_VECTOR             DUMMY_VECTOR
#endif  /* SCI4_VECTOR          */

#if !defined(SCI3_VECTOR)
#define SCI3_VECTOR             DUMMY_VECTOR
#endif  /* SCI3_VECTOR          */

#if !defined(SCI2_VECTOR)
#define SCI2_VECTOR             DUMMY_VECTOR
#endif  /* SCI2_VECTOR          */

#if !defined(PWMESDN_VECTOR)
#define PWMESDN_VECTOR          DUMMY_VECTOR
#endif  /* PWMESDN_VECTOR       */

#if !defined(PORTP_VECTOR)
#define PORTP_VECTOR            DUMMY_VECTOR
#endif  /* PORTP_VECTOR         */

#if !defined(CAN4TX_VECTOR)
#define CAN4TX_VECTOR           DUMMY_VECTOR
#endif  /* CAN4TX_VECTOR        */

#if !defined(CAN4RX_VECTOR)
#define CAN4RX_VECTOR           DUMMY_VECTOR
#endif  /* CAN4RX_VECTOR        */

#if !defined(CAN4ERR_VECTOR)
#define CAN4ERR_VECTOR          DUMMY_VECTOR
#endif  /* CAN4ERR_VECTOR       */

#if !defined(CAN4WKUP_VECTOR)
#define CAN4WKUP_VECTOR         DUMMY_VECTOR
#endif  /* CAN4WKUP_VECTOR      */

#if !defined(CAN0TX_VECTOR)
#define CAN0TX_VECTOR           DUMMY_VECTOR
#endif  /* CAN0TX_VECTOR        */

#if !defined(CAN0RX_VECTOR)
#define CAN0RX_VECTOR           DUMMY_VECTOR
#endif  /* CAN0RX_VECTOR        */

#if !defined(CAN0ERR_VECTOR)
#define CAN0ERR_VECTOR          DUMMY_VECTOR
#endif  /* CAN0ERR_VECTOR       */

#if !defined(CAN0WKUP_VECTOR)
#define CAN0WKUP_VECTOR         DUMMY_VECTOR
#endif  /* CAN0WKUP_VECTOR      */

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(FLASHFD_VECTOR)
#define FLASHFD_VECTOR          DUMMY_VECTOR
#endif  /* FLASHFD_VECTOR       */

#if !defined(SPI2_VECTOR)
#define SPI2_VECTOR             DUMMY_VECTOR
#endif  /* SPI2_VECTOR          */

#if !defined(SPI1_VECTOR)
#define SPI1_VECTOR             DUMMY_VECTOR
#endif  /* SPI1_VECTOR          */

#if !defined(IIC0_VECTOR)
#define IIC0_VECTOR             DUMMY_VECTOR
#endif  /* IIC0_VECTOR          */

#if !defined(CRGSCM_VECTOR)
#define CRGSCM_VECTOR           DUMMY_VECTOR
#endif  /* CRGSCM_VECTOR        */

#if !defined(CRGPLLLCK_VECTOR)
#define CRGPLLLCK_VECTOR        DUMMY_VECTOR
#endif  /* CRGPLLLCK_VECTOR     */

#if !defined(ECTPABOVF_VECTOR)
#define ECTPABOVF_VECTOR        DUMMY_VECTOR
#endif  /* ECTPABOVF_VECTOR     */

#if !defined(ECTMDCU_VECTOR)
#define ECTMDCU_VECTOR          DUMMY_VECTOR
#endif  /* ECTMDCU_VECTOR       */

#if !defined(PORTH_VECTOR)
#define PORTH_VECTOR            DUMMY_VECTOR
#endif  /* PORTH_VECTOR         */

#if !defined(PORTJ_VECTOR)
#define PORTJ_VECTOR            DUMMY_VECTOR
#endif  /* PORTJ_VECTOR         */

#if !defined(ATD1_VECTOR)
#define ATD1_VECTOR             DUMMY_VECTOR
#endif  /* ATD1_VECTOR          */

#if !defined(ATD0_VECTOR)
#define ATD0_VECTOR             DUMMY_VECTOR
#endif  /* ATD0_VECTOR          */

#if !defined(SCI1_VECTOR)
#define SCI1_VECTOR             DUMMY_VECTOR
#endif  /* SCI1_VECTOR          */

#if !defined(SCI0_VECTOR)
#define SCI0_VECTOR             DUMMY_VECTOR
#endif  /* SCI0_VECTOR          */

#if !defined(SPI0_VECTOR)
#define SPI0_VECTOR             DUMMY_VECTOR
#endif  /* SPI0_VECTOR          */

#if !defined(ECTPAIE_VECTOR)
#define ECTPAIE_VECTOR          DUMMY_VECTOR
#endif  /* ECTPAIE_VECTOR       */

#if !defined(ECTPAAOVF_VECTOR)
#define ECTPAAOVF_VECTOR        DUMMY_VECTOR
#endif  /* ECTPAAOVF_VECTOR     */

#if !defined(ECTOVF_VECTOR)
#define ECTOVF_VECTOR           DUMMY_VECTOR
#endif  /* ECTOVF_VECTOR        */

#if !defined(ECTCH7_VECTOR)
#define ECTCH7_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH7_VECTOR        */

#if !defined(ECTCH6_VECTOR)
#define ECTCH6_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH6_VECTOR        */

#if !defined(ECTCH5_VECTOR)
#define ECTCH5_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH5_VECTOR        */

#if !defined(ECTCH4_VECTOR)
#define ECTCH4_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH4_VECTOR        */

#if !defined(ECTCH3_VECTOR)
#define ECTCH3_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH3_VECTOR        */

#if !defined(ECTCH2_VECTOR)
#define ECTCH2_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH2_VECTOR        */

#if !defined(ECTCH1_VECTOR)
#define ECTCH1_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH1_VECTOR        */

#if !defined(ECTCH0_VECTOR)
#define ECTCH0_VECTOR           DUMMY_VECTOR
#endif  /* ECTCH0_VECTOR        */

#if !defined(RTI_VECTOR)
#define RTI_VECTOR              DUMMY_VECTOR
#endif  /* RTI_VECTOR           */

#if !defined(IRQ_VECTOR)
#define IRQ_VECTOR              DUMMY_VECTOR
#endif  /* IRQ_VECTOR           */

#if !defined(XIRQ_VECTOR)
#define XIRQ_VECTOR             DUMMY_VECTOR
#endif  /* XIRQ_VECTOR          */

#if !defined(SWI_VECTOR)
#define SWI_VECTOR              DUMMY_VECTOR
#endif  /* SWI_VECTOR           */

#if !defined(TRAP_VECTOR)
#define TRAP_VECTOR             DUMMY_VECTOR
#endif  /* TRAP_VECTOR          */

#if !defined(COP_VECTOR)
#define COP_VECTOR              DUMMY_VECTOR
#endif  /* COP_VECTOR           */

#if !defined(CLKMON_VECTOR)
#define CLKMON_VECTOR           DUMMY_VECTOR
#endif  /* CLKMON_VECTOR        */

#if !defined(RESET_VECTOR)
#define RESET_VECTOR            IISR_ENTRY_POINT
#endif  /* RESET_VECTOR         */


ISR1(DUMMY_VECTOR)
{
}

#pragma constseg = INTVEC
#pragma required = interrupt_vectors
#pragma location = 0xff10
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)SI_VECTOR,           
    (IISR_IVF)SYSCALL_VECTOR,      
    (IISR_IVF)MPUACCESSERR_VECTOR, 
    (IISR_IVF)XSEI_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff18 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff1a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff1c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff1e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff20 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff22 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff24 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff26 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff28 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff2a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff2c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff2e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff30 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff32 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff34 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff36 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff38 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff3a */
    (IISR_IVF)ATD1COMPARE_VECTOR,  
    (IISR_IVF)ATD0COMPARE_VECTOR,  
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff40 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff42 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff44 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff46 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff48 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff4a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff4c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff4e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff50 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff52 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff54 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff56 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff58 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff5a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff5c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff5e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff60 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff62 */
    (IISR_IVF)XST7_VECTOR,         
    (IISR_IVF)XST6_VECTOR,         
    (IISR_IVF)XST5_VECTOR,         
    (IISR_IVF)XST4_VECTOR,         
    (IISR_IVF)XST3_VECTOR,         
    (IISR_IVF)XST2_VECTOR,         
    (IISR_IVF)XST1_VECTOR,         
    (IISR_IVF)XST0_VECTOR,         
    (IISR_IVF)PIT3_VECTOR,         
    (IISR_IVF)PIT2_VECTOR,         
    (IISR_IVF)PIT1_VECTOR,         
    (IISR_IVF)PIT0_VECTOR,         
    (IISR_IVF)HTI_VECTOR,          
    (IISR_IVF)API_VECTOR,          
    (IISR_IVF)LVI_VECTOR,          
    (IISR_IVF)IIC1_VECTOR,         
    (IISR_IVF)SCI5_VECTOR,         
    (IISR_IVF)SCI4_VECTOR,         
    (IISR_IVF)SCI3_VECTOR,         
    (IISR_IVF)SCI2_VECTOR,         
    (IISR_IVF)PWMESDN_VECTOR,      
    (IISR_IVF)PORTP_VECTOR,        
    (IISR_IVF)CAN4TX_VECTOR,       
    (IISR_IVF)CAN4RX_VECTOR,       
    (IISR_IVF)CAN4ERR_VECTOR,      
    (IISR_IVF)CAN4WKUP_VECTOR,     
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff98 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa4 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa6 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa8 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffaa */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffac */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffae */
    (IISR_IVF)CAN0TX_VECTOR,       
    (IISR_IVF)CAN0RX_VECTOR,       
    (IISR_IVF)CAN0ERR_VECTOR,      
    (IISR_IVF)CAN0WKUP_VECTOR,     
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)FLASHFD_VECTOR,      
    (IISR_IVF)SPI2_VECTOR,         
    (IISR_IVF)SPI1_VECTOR,         
    (IISR_IVF)IIC0_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)ECTPABOVF_VECTOR,    
    (IISR_IVF)ECTMDCU_VECTOR,      
    (IISR_IVF)PORTH_VECTOR,        
    (IISR_IVF)PORTJ_VECTOR,        
    (IISR_IVF)ATD1_VECTOR,         
    (IISR_IVF)ATD0_VECTOR,         
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)SPI0_VECTOR,         
    (IISR_IVF)ECTPAIE_VECTOR,      
    (IISR_IVF)ECTPAAOVF_VECTOR,    
    (IISR_IVF)ECTOVF_VECTOR,       
    (IISR_IVF)ECTCH7_VECTOR,       
    (IISR_IVF)ECTCH6_VECTOR,       
    (IISR_IVF)ECTCH5_VECTOR,       
    (IISR_IVF)ECTCH4_VECTOR,       
    (IISR_IVF)ECTCH3_VECTOR,       
    (IISR_IVF)ECTCH2_VECTOR,       
    (IISR_IVF)ECTCH1_VECTOR,       
    (IISR_IVF)ECTCH0_VECTOR,       
    (IISR_IVF)RTI_VECTOR,          
    (IISR_IVF)IRQ_VECTOR,          
    (IISR_IVF)XIRQ_VECTOR,         
    (IISR_IVF)SWI_VECTOR,          
    (IISR_IVF)TRAP_VECTOR,         
    (IISR_IVF)COP_VECTOR,          
    (IISR_IVF)CLKMON_VECTOR,       
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,
#endif
};

#pragma constseg=default

