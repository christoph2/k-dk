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
 *      MC9S12HY32
 *      MC9S12HY48
 *      MC9S12HY64
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(SI_VECTOR)
#define SI_VECTOR               DUMMY_VECTOR
#endif  /* SI_VECTOR            */

#if !defined(ATDCOMPARE_VECTOR)
#define ATDCOMPARE_VECTOR       DUMMY_VECTOR
#endif  /* ATDCOMPARE_VECTOR    */

#if !defined(HTI_VECTOR)
#define HTI_VECTOR              DUMMY_VECTOR
#endif  /* HTI_VECTOR           */

#if !defined(API_VECTOR)
#define API_VECTOR              DUMMY_VECTOR
#endif  /* API_VECTOR           */

#if !defined(LVI_VECTOR)
#define LVI_VECTOR              DUMMY_VECTOR
#endif  /* LVI_VECTOR           */

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

#if !defined(CANTX_VECTOR)
#define CANTX_VECTOR            DUMMY_VECTOR
#endif  /* CANTX_VECTOR         */

#if !defined(CANRX_VECTOR)
#define CANRX_VECTOR            DUMMY_VECTOR
#endif  /* CANRX_VECTOR         */

#if !defined(CANERR_VECTOR)
#define CANERR_VECTOR           DUMMY_VECTOR
#endif  /* CANERR_VECTOR        */

#if !defined(CANWKUP_VECTOR)
#define CANWKUP_VECTOR          DUMMY_VECTOR
#endif  /* CANWKUP_VECTOR       */

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(FLASHFD_VECTOR)
#define FLASHFD_VECTOR          DUMMY_VECTOR
#endif  /* FLASHFD_VECTOR       */

#if !defined(IIC_VECTOR)
#define IIC_VECTOR              DUMMY_VECTOR
#endif  /* IIC_VECTOR           */

#if !defined(CPMUPLLLCK_VECTOR)
#define CPMUPLLLCK_VECTOR       DUMMY_VECTOR
#endif  /* CPMUPLLLCK_VECTOR    */

#if !defined(CPMUOCSNS_VECTOR)
#define CPMUOCSNS_VECTOR        DUMMY_VECTOR
#endif  /* CPMUOCSNS_VECTOR     */

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

#if !defined(SCI_VECTOR)
#define SCI_VECTOR              DUMMY_VECTOR
#endif  /* SCI_VECTOR           */

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
#pragma location = 0xff80
__root void ( * const interrupt_vectors[])(void) = {
#elif defined(__HIWARE__) 
#pragma push
#pragma CONST_SEG __SHORT_SEG MY_VECTORS
const void ( * __near const interrupt_vectors[])(void) @ 0xff80 = {
#elif defined(__CSMC__)
#pragma section const {vector}
void ( * const interrupt_vectors[])(void) /* @ 0xff80 */ = {
#elif defined(__GNUC__)
void ( * const interrupt_vectors[])(void) __attribute__((section(".vectors"))) = {
#elif defined(__IMAGECRAFT__)
#pragma abs_address:0xff80
void ( * const interrupt_vectors[])(void) = {
#endif
    (IISR_IVF)SI_VECTOR,           
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff82 */
    (IISR_IVF)ATDCOMPARE_VECTOR,   
    (IISR_IVF)HTI_VECTOR,          
    (IISR_IVF)API_VECTOR,          
    (IISR_IVF)LVI_VECTOR,          
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
    (IISR_IVF)CANTX_VECTOR,        
    (IISR_IVF)CANRX_VECTOR,        
    (IISR_IVF)CANERR_VECTOR,       
    (IISR_IVF)CANWKUP_VECTOR,      
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)FLASHFD_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)IIC_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc4 */
    (IISR_IVF)CPMUPLLLCK_VECTOR,   
    (IISR_IVF)CPMUOCSNS_VECTOR,    
    (IISR_IVF)PORTS_VECTOR,        
    (IISR_IVF)PORTR_VECTOR,        
    (IISR_IVF)PORTAD_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)ATD_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd4 */
    (IISR_IVF)SCI_VECTOR,          
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




