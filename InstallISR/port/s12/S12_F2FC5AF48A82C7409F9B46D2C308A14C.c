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
 *      MC9S12XDP512
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(SI_VECTOR)
#define SI_VECTOR               DUMMY_VECTOR
#endif  /* SI_VECTOR            */

#if !defined(XSRAMAV_VECTOR)
#define XSRAMAV_VECTOR          DUMMY_VECTOR
#endif  /* XSRAMAV_VECTOR       */

#if !defined(XSEI_VECTOR)
#define XSEI_VECTOR             DUMMY_VECTOR
#endif  /* XSEI_VECTOR          */

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

#if !defined(CAN3TX_VECTOR)
#define CAN3TX_VECTOR           DUMMY_VECTOR
#endif  /* CAN3TX_VECTOR        */

#if !defined(CAN3RX_VECTOR)
#define CAN3RX_VECTOR           DUMMY_VECTOR
#endif  /* CAN3RX_VECTOR        */

#if !defined(CAN3ERR_VECTOR)
#define CAN3ERR_VECTOR          DUMMY_VECTOR
#endif  /* CAN3ERR_VECTOR       */

#if !defined(CAN3WKUP_VECTOR)
#define CAN3WKUP_VECTOR         DUMMY_VECTOR
#endif  /* CAN3WKUP_VECTOR      */

#if !defined(CAN2TX_VECTOR)
#define CAN2TX_VECTOR           DUMMY_VECTOR
#endif  /* CAN2TX_VECTOR        */

#if !defined(CAN2RX_VECTOR)
#define CAN2RX_VECTOR           DUMMY_VECTOR
#endif  /* CAN2RX_VECTOR        */

#if !defined(CAN2ERR_VECTOR)
#define CAN2ERR_VECTOR          DUMMY_VECTOR
#endif  /* CAN2ERR_VECTOR       */

#if !defined(CAN2WKUP_VECTOR)
#define CAN2WKUP_VECTOR         DUMMY_VECTOR
#endif  /* CAN2WKUP_VECTOR      */

#if !defined(CAN1TX_VECTOR)
#define CAN1TX_VECTOR           DUMMY_VECTOR
#endif  /* CAN1TX_VECTOR        */

#if !defined(CAN1RX_VECTOR)
#define CAN1RX_VECTOR           DUMMY_VECTOR
#endif  /* CAN1RX_VECTOR        */

#if !defined(CAN1ERR_VECTOR)
#define CAN1ERR_VECTOR          DUMMY_VECTOR
#endif  /* CAN1ERR_VECTOR       */

#if !defined(CAN1WKUP_VECTOR)
#define CAN1WKUP_VECTOR         DUMMY_VECTOR
#endif  /* CAN1WKUP_VECTOR      */

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

#if !defined(EEPROM_VECTOR)
#define EEPROM_VECTOR           DUMMY_VECTOR
#endif  /* EEPROM_VECTOR        */

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

#if !defined(TIMPABOVF_VECTOR)
#define TIMPABOVF_VECTOR        DUMMY_VECTOR
#endif  /* TIMPABOVF_VECTOR     */

#if !defined(TIMMDCU_VECTOR)
#define TIMMDCU_VECTOR          DUMMY_VECTOR
#endif  /* TIMMDCU_VECTOR       */

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

#if !defined(TIMPAIE_VECTOR)
#define TIMPAIE_VECTOR          DUMMY_VECTOR
#endif  /* TIMPAIE_VECTOR       */

#if !defined(TIMPAAOVF_VECTOR)
#define TIMPAAOVF_VECTOR        DUMMY_VECTOR
#endif  /* TIMPAAOVF_VECTOR     */

#if !defined(TIMOVF_VECTOR)
#define TIMOVF_VECTOR           DUMMY_VECTOR
#endif  /* TIMOVF_VECTOR        */

#if !defined(TIMCH7_VECTOR)
#define TIMCH7_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH7_VECTOR        */

#if !defined(TIMCH6_VECTOR)
#define TIMCH6_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH6_VECTOR        */

#if !defined(TIMCH5_VECTOR)
#define TIMCH5_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH5_VECTOR        */

#if !defined(TIMCH4_VECTOR)
#define TIMCH4_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH4_VECTOR        */

#if !defined(TIMCH3_VECTOR)
#define TIMCH3_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH3_VECTOR        */

#if !defined(TIMCH2_VECTOR)
#define TIMCH2_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH2_VECTOR        */

#if !defined(TIMCH1_VECTOR)
#define TIMCH1_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH1_VECTOR        */

#if !defined(TIMCH0_VECTOR)
#define TIMCH0_VECTOR           DUMMY_VECTOR
#endif  /* TIMCH0_VECTOR        */

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


#pragma CODE_SEG NON_BANKED
ISR1(DUMMY_VECTOR)
{
}
#pragma CODE_SEG DEFAULT

#if defined(__IAR_SYSTEMS_ICC__)
#pragma constseg = INTVEC
#pragma required = interrupt_vectors
#pragma location = 0xff10
__root void ( * const interrupt_vectors[])(void) = {
#elif defined(__HIWARE__) 
#pragma push
#pragma CONST_SEG __SHORT_SEG MY_VECTORS
const void ( * __near const interrupt_vectors[])(void) @ 0xff10 = {
#elif defined(__CSMC__)
#pragma section const {vector}
void ( * const interrupt_vectors[])(void) /* @ 0xff10 */ = {
#elif defined(__GNUC__)
void ( * const interrupt_vectors[])(void) __attribute__((section(".vectors"))) = {
#elif defined(__IMAGECRAFT__)
#pragma abs_address:0xff10
void ( * const interrupt_vectors[])(void) = {
#endif
    (IISR_IVF)SI_VECTOR,           
    (IISR_IVF)XSRAMAV_VECTOR,      
    (IISR_IVF)XSEI_VECTOR,         
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff7c */
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
    (IISR_IVF)CAN3TX_VECTOR,       
    (IISR_IVF)CAN3RX_VECTOR,       
    (IISR_IVF)CAN3ERR_VECTOR,      
    (IISR_IVF)CAN3WKUP_VECTOR,     
    (IISR_IVF)CAN2TX_VECTOR,       
    (IISR_IVF)CAN2RX_VECTOR,       
    (IISR_IVF)CAN2ERR_VECTOR,      
    (IISR_IVF)CAN2WKUP_VECTOR,     
    (IISR_IVF)CAN1TX_VECTOR,       
    (IISR_IVF)CAN1RX_VECTOR,       
    (IISR_IVF)CAN1ERR_VECTOR,      
    (IISR_IVF)CAN1WKUP_VECTOR,     
    (IISR_IVF)CAN0TX_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb0 */
    (IISR_IVF)CAN0RX_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb2 */
    (IISR_IVF)CAN0ERR_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb4 */
    (IISR_IVF)CAN0WKUP_VECTOR,     
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb6 */
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb8 */
    (IISR_IVF)EEPROM_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba */
    (IISR_IVF)SPI2_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)SPI1_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)IIC0_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc4 */
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc6 */
    (IISR_IVF)TIMPABOVF_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8 */
    (IISR_IVF)TIMMDCU_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffca */
    (IISR_IVF)PORTH_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffcc */
    (IISR_IVF)PORTJ_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffce */
    (IISR_IVF)ATD1_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)ATD0_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd2 */
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd4 */
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd6 */
    (IISR_IVF)SPI0_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd8 */
    (IISR_IVF)TIMPAIE_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffda */
    (IISR_IVF)TIMPAAOVF_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffdc */
    (IISR_IVF)TIMOVF_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffde */
    (IISR_IVF)TIMCH7_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe0 */
    (IISR_IVF)TIMCH6_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe2 */
    (IISR_IVF)TIMCH5_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe4 */
    (IISR_IVF)TIMCH4_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe6 */
    (IISR_IVF)TIMCH3_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe8 */
    (IISR_IVF)TIMCH2_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffea */
    (IISR_IVF)TIMCH1_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffec */
    (IISR_IVF)TIMCH0_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffee */
    (IISR_IVF)RTI_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff0 */
    (IISR_IVF)IRQ_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff2 */
    (IISR_IVF)XIRQ_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff4 */
    (IISR_IVF)SWI_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff6 */
    (IISR_IVF)TRAP_VECTOR,         
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfff8 */
    (IISR_IVF)COP_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfffa */
    (IISR_IVF)CLKMON_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfffc */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,
#endif
};

#if defined(__HIWARE__)
#pragma pop
#pragma CONST_SEG DEFAULT
#elif defined(__CSMC__)
#pragma section const {}
#elif defined(__IMAGECRAFT__)
#pragma end_abs_address
#endif




