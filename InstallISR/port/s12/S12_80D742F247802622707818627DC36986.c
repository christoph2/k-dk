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
 *      MC9S12XHY128
 *      MC9S12XHY256
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

#if !defined(ATDCOMPARE_VECTOR)
#define ATDCOMPARE_VECTOR       DUMMY_VECTOR
#endif  /* ATDCOMPARE_VECTOR    */

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

#if !defined(HTI_VECTOR)
#define HTI_VECTOR              DUMMY_VECTOR
#endif  /* HTI_VECTOR           */

#if !defined(API_VECTOR)
#define API_VECTOR              DUMMY_VECTOR
#endif  /* API_VECTOR           */

#if !defined(LVI_VECTOR)
#define LVI_VECTOR              DUMMY_VECTOR
#endif  /* LVI_VECTOR           */

#if !defined(SSD3_VECTOR)
#define SSD3_VECTOR             DUMMY_VECTOR
#endif  /* SSD3_VECTOR          */

#if !defined(SSD2_VECTOR)
#define SSD2_VECTOR             DUMMY_VECTOR
#endif  /* SSD2_VECTOR          */

#if !defined(SSD1_VECTOR)
#define SSD1_VECTOR             DUMMY_VECTOR
#endif  /* SSD1_VECTOR          */

#if !defined(SSD0_VECTOR)
#define SSD0_VECTOR             DUMMY_VECTOR
#endif  /* SSD0_VECTOR          */

#if !defined(PWMESDN_VECTOR)
#define PWMESDN_VECTOR          DUMMY_VECTOR
#endif  /* PWMESDN_VECTOR       */

#if !defined(PORTT_VECTOR)
#define PORTT_VECTOR            DUMMY_VECTOR
#endif  /* PORTT_VECTOR         */

#if !defined(MCTIMOVF_VECTOR)
#define MCTIMOVF_VECTOR         DUMMY_VECTOR
#endif  /* MCTIMOVF_VECTOR      */

#if !defined(TIM1PAIE_VECTOR)
#define TIM1PAIE_VECTOR         DUMMY_VECTOR
#endif  /* TIM1PAIE_VECTOR      */

#if !defined(TIM1PAAOVF_VECTOR)
#define TIM1PAAOVF_VECTOR       DUMMY_VECTOR
#endif  /* TIM1PAAOVF_VECTOR    */

#if !defined(TIM1OVF_VECTOR)
#define TIM1OVF_VECTOR          DUMMY_VECTOR
#endif  /* TIM1OVF_VECTOR       */

#if !defined(TIM1CH7_VECTOR)
#define TIM1CH7_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH7_VECTOR       */

#if !defined(TIM1CH6_VECTOR)
#define TIM1CH6_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH6_VECTOR       */

#if !defined(TIM1CH5_VECTOR)
#define TIM1CH5_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH5_VECTOR       */

#if !defined(TIM1CH4_VECTOR)
#define TIM1CH4_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH4_VECTOR       */

#if !defined(TIM1CH3_VECTOR)
#define TIM1CH3_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH3_VECTOR       */

#if !defined(TIM1CH2_VECTOR)
#define TIM1CH2_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH2_VECTOR       */

#if !defined(TIM1CH1_VECTOR)
#define TIM1CH1_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH1_VECTOR       */

#if !defined(TIM1CH0_VECTOR)
#define TIM1CH0_VECTOR          DUMMY_VECTOR
#endif  /* TIM1CH0_VECTOR       */

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

#if !defined(IIC_VECTOR)
#define IIC_VECTOR              DUMMY_VECTOR
#endif  /* IIC_VECTOR           */

#if !defined(CRGSCM_VECTOR)
#define CRGSCM_VECTOR           DUMMY_VECTOR
#endif  /* CRGSCM_VECTOR        */

#if !defined(CRGPLLLCK_VECTOR)
#define CRGPLLLCK_VECTOR        DUMMY_VECTOR
#endif  /* CRGPLLLCK_VECTOR     */

#if !defined(PORTS_VECTOR)
#define PORTS_VECTOR            DUMMY_VECTOR
#endif  /* PORTS_VECTOR         */

#if !defined(PORTR_VECTOR)
#define PORTR_VECTOR            DUMMY_VECTOR
#endif  /* PORTR_VECTOR         */

#if !defined(PORTAD_VECTOR)
#define PORTAD_VECTOR           DUMMY_VECTOR
#endif  /* PORTAD_VECTOR        */

#if !defined(ATD_VECTOR)
#define ATD_VECTOR              DUMMY_VECTOR
#endif  /* ATD_VECTOR           */

#if !defined(SCI1_VECTOR)
#define SCI1_VECTOR             DUMMY_VECTOR
#endif  /* SCI1_VECTOR          */

#if !defined(SCI0_VECTOR)
#define SCI0_VECTOR             DUMMY_VECTOR
#endif  /* SCI0_VECTOR          */

#if !defined(SPI_VECTOR)
#define SPI_VECTOR              DUMMY_VECTOR
#endif  /* SPI_VECTOR           */

#if !defined(TIM0PAIE_VECTOR)
#define TIM0PAIE_VECTOR         DUMMY_VECTOR
#endif  /* TIM0PAIE_VECTOR      */

#if !defined(TIM0PAAOVF_VECTOR)
#define TIM0PAAOVF_VECTOR       DUMMY_VECTOR
#endif  /* TIM0PAAOVF_VECTOR    */

#if !defined(TIM0OVF_VECTOR)
#define TIM0OVF_VECTOR          DUMMY_VECTOR
#endif  /* TIM0OVF_VECTOR       */

#if !defined(TIM0CH7_VECTOR)
#define TIM0CH7_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH7_VECTOR       */

#if !defined(TIM0CH6_VECTOR)
#define TIM0CH6_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH6_VECTOR       */

#if !defined(TIM0CH5_VECTOR)
#define TIM0CH5_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH5_VECTOR       */

#if !defined(TIM0CH4_VECTOR)
#define TIM0CH4_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH4_VECTOR       */

#if !defined(TIM0CH3_VECTOR)
#define TIM0CH3_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH3_VECTOR       */

#if !defined(TIM0CH2_VECTOR)
#define TIM0CH2_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH2_VECTOR       */

#if !defined(TIM0CH1_VECTOR)
#define TIM0CH1_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH1_VECTOR       */

#if !defined(TIM0CH0_VECTOR)
#define TIM0CH0_VECTOR          DUMMY_VECTOR
#endif  /* TIM0CH0_VECTOR       */

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
    (IISR_IVF)SYSCALL_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff14 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff16 */
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff3c */
    (IISR_IVF)ATDCOMPARE_VECTOR,   
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff64 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff66 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff68 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff6a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff6c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff6e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff70 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff72 */
    (IISR_IVF)CAN1TX_VECTOR,       
    (IISR_IVF)CAN1RX_VECTOR,       
    (IISR_IVF)CAN1ERR_VECTOR,      
    (IISR_IVF)CAN1WKUP_VECTOR,     
    (IISR_IVF)HTI_VECTOR,          
    (IISR_IVF)API_VECTOR,          
    (IISR_IVF)LVI_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff82 */
    (IISR_IVF)SSD3_VECTOR,         
    (IISR_IVF)SSD2_VECTOR,         
    (IISR_IVF)SSD1_VECTOR,         
    (IISR_IVF)SSD0_VECTOR,         
    (IISR_IVF)PWMESDN_VECTOR,      
    (IISR_IVF)PORTT_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff90 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff92 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff94 */
    (IISR_IVF)MCTIMOVF_VECTOR,     
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff98 */
    (IISR_IVF)TIM1PAIE_VECTOR,     
    (IISR_IVF)TIM1PAAOVF_VECTOR,   
    (IISR_IVF)TIM1OVF_VECTOR,      
    (IISR_IVF)TIM1CH7_VECTOR,      
    (IISR_IVF)TIM1CH6_VECTOR,      
    (IISR_IVF)TIM1CH5_VECTOR,      
    (IISR_IVF)TIM1CH4_VECTOR,      
    (IISR_IVF)TIM1CH3_VECTOR,      
    (IISR_IVF)TIM1CH2_VECTOR,      
    (IISR_IVF)TIM1CH1_VECTOR,      
    (IISR_IVF)TIM1CH0_VECTOR,      
    (IISR_IVF)CAN0TX_VECTOR,       
    (IISR_IVF)CAN0RX_VECTOR,       
    (IISR_IVF)CAN0ERR_VECTOR,      
    (IISR_IVF)CAN0WKUP_VECTOR,     
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)FLASHFD_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)IIC_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8 */
    (IISR_IVF)PORTS_VECTOR,        
    (IISR_IVF)PORTR_VECTOR,        
    (IISR_IVF)PORTAD_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)ATD_VECTOR,          
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)SPI_VECTOR,          
    (IISR_IVF)TIM0PAIE_VECTOR,     
    (IISR_IVF)TIM0PAAOVF_VECTOR,   
    (IISR_IVF)TIM0OVF_VECTOR,      
    (IISR_IVF)TIM0CH7_VECTOR,      
    (IISR_IVF)TIM0CH6_VECTOR,      
    (IISR_IVF)TIM0CH5_VECTOR,      
    (IISR_IVF)TIM0CH4_VECTOR,      
    (IISR_IVF)TIM0CH3_VECTOR,      
    (IISR_IVF)TIM0CH2_VECTOR,      
    (IISR_IVF)TIM0CH1_VECTOR,      
    (IISR_IVF)TIM0CH0_VECTOR,      
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

#if defined(__HIWARE__)
#pragma pop
#pragma CONST_SEG DEFAULT
#elif defined(__CSMC__)
#pragma section const {}
#elif defined(__IMAGECRAFT__)
#pragma end_abs_address
#endif




