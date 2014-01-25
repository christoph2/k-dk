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
 *      MC9S12E128
 *      MC9S12E256
 *      MC9S12E32
 *      MC9S12E64
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(PWMESDN_VECTOR)
#define PWMESDN_VECTOR          DUMMY_VECTOR
#endif  /* PWMESDN_VECTOR       */

#if !defined(VREGLVI_VECTOR)
#define VREGLVI_VECTOR          DUMMY_VECTOR
#endif  /* VREGLVI_VECTOR       */

#if !defined(PMFFAULT3_VECTOR)
#define PMFFAULT3_VECTOR        DUMMY_VECTOR
#endif  /* PMFFAULT3_VECTOR     */

#if !defined(PMFFAULT2_VECTOR)
#define PMFFAULT2_VECTOR        DUMMY_VECTOR
#endif  /* PMFFAULT2_VECTOR     */

#if !defined(PMFFAULT1_VECTOR)
#define PMFFAULT1_VECTOR        DUMMY_VECTOR
#endif  /* PMFFAULT1_VECTOR     */

#if !defined(PMFFAULT0_VECTOR)
#define PMFFAULT0_VECTOR        DUMMY_VECTOR
#endif  /* PMFFAULT0_VECTOR     */

#if !defined(PMFGCR_VECTOR)
#define PMFGCR_VECTOR           DUMMY_VECTOR
#endif  /* PMFGCR_VECTOR        */

#if !defined(PMFGBR_VECTOR)
#define PMFGBR_VECTOR           DUMMY_VECTOR
#endif  /* PMFGBR_VECTOR        */

#if !defined(PMFGAR_VECTOR)
#define PMFGAR_VECTOR           DUMMY_VECTOR
#endif  /* PMFGAR_VECTOR        */

#if !defined(TIM2PAIE_VECTOR)
#define TIM2PAIE_VECTOR         DUMMY_VECTOR
#endif  /* TIM2PAIE_VECTOR      */

#if !defined(TIM2PAOVF_VECTOR)
#define TIM2PAOVF_VECTOR        DUMMY_VECTOR
#endif  /* TIM2PAOVF_VECTOR     */

#if !defined(TIM2OVF_VECTOR)
#define TIM2OVF_VECTOR          DUMMY_VECTOR
#endif  /* TIM2OVF_VECTOR       */

#if !defined(TIM2CH7_VECTOR)
#define TIM2CH7_VECTOR          DUMMY_VECTOR
#endif  /* TIM2CH7_VECTOR       */

#if !defined(TIM2CH6_VECTOR)
#define TIM2CH6_VECTOR          DUMMY_VECTOR
#endif  /* TIM2CH6_VECTOR       */

#if !defined(TIM2CH5_VECTOR)
#define TIM2CH5_VECTOR          DUMMY_VECTOR
#endif  /* TIM2CH5_VECTOR       */

#if !defined(TIM2CH4_VECTOR)
#define TIM2CH4_VECTOR          DUMMY_VECTOR
#endif  /* TIM2CH4_VECTOR       */

#if !defined(TIM1PAIE_VECTOR)
#define TIM1PAIE_VECTOR         DUMMY_VECTOR
#endif  /* TIM1PAIE_VECTOR      */

#if !defined(TIM1PAOVF_VECTOR)
#define TIM1PAOVF_VECTOR        DUMMY_VECTOR
#endif  /* TIM1PAOVF_VECTOR     */

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

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(IIC_VECTOR)
#define IIC_VECTOR              DUMMY_VECTOR
#endif  /* IIC_VECTOR           */

#if !defined(CRGSCM_VECTOR)
#define CRGSCM_VECTOR           DUMMY_VECTOR
#endif  /* CRGSCM_VECTOR        */

#if !defined(CRGPLLLCK_VECTOR)
#define CRGPLLLCK_VECTOR        DUMMY_VECTOR
#endif  /* CRGPLLLCK_VECTOR     */

#if !defined(PORTAD_VECTOR)
#define PORTAD_VECTOR           DUMMY_VECTOR
#endif  /* PORTAD_VECTOR        */

#if !defined(ATD0_VECTOR)
#define ATD0_VECTOR             DUMMY_VECTOR
#endif  /* ATD0_VECTOR          */

#if !defined(SCI2_VECTOR)
#define SCI2_VECTOR             DUMMY_VECTOR
#endif  /* SCI2_VECTOR          */

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

#if !defined(TIM0PAOVF_VECTOR)
#define TIM0PAOVF_VECTOR        DUMMY_VECTOR
#endif  /* TIM0PAOVF_VECTOR     */

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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff80 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff82 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff84 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff86 */
    (IISR_IVF)PWMESDN_VECTOR,      
    (IISR_IVF)VREGLVI_VECTOR,      
    (IISR_IVF)PMFFAULT3_VECTOR,    
    (IISR_IVF)PMFFAULT2_VECTOR,    
    (IISR_IVF)PMFFAULT1_VECTOR,    
    (IISR_IVF)PMFFAULT0_VECTOR,    
    (IISR_IVF)PMFGCR_VECTOR,       
    (IISR_IVF)PMFGBR_VECTOR,       
    (IISR_IVF)PMFGAR_VECTOR,       
    (IISR_IVF)TIM2PAIE_VECTOR,     
    (IISR_IVF)TIM2PAOVF_VECTOR,    
    (IISR_IVF)TIM2OVF_VECTOR,      
    (IISR_IVF)TIM2CH7_VECTOR,      
    (IISR_IVF)TIM2CH6_VECTOR,      
    (IISR_IVF)TIM2CH5_VECTOR,      
    (IISR_IVF)TIM2CH4_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffa8 */
    (IISR_IVF)TIM1PAIE_VECTOR,     
    (IISR_IVF)TIM1PAOVF_VECTOR,    
    (IISR_IVF)TIM1OVF_VECTOR,      
    (IISR_IVF)TIM1CH7_VECTOR,      
    (IISR_IVF)TIM1CH6_VECTOR,      
    (IISR_IVF)TIM1CH5_VECTOR,      
    (IISR_IVF)TIM1CH4_VECTOR,      
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)IIC_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffca */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffcc */
    (IISR_IVF)PORTAD_VECTOR,       
    (IISR_IVF)ATD0_VECTOR,         
    (IISR_IVF)SCI2_VECTOR,         
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)SPI_VECTOR,          
    (IISR_IVF)TIM0PAIE_VECTOR,     
    (IISR_IVF)TIM0PAOVF_VECTOR,    
    (IISR_IVF)TIM0OVF_VECTOR,      
    (IISR_IVF)TIM0CH7_VECTOR,      
    (IISR_IVF)TIM0CH6_VECTOR,      
    (IISR_IVF)TIM0CH5_VECTOR,      
    (IISR_IVF)TIM0CH4_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe8 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffea */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffec */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffee */
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




