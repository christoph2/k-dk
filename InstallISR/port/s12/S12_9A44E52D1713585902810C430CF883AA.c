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
 *      MC9S12NE64
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(EMACEC_VECTOR)
#define EMACEC_VECTOR           DUMMY_VECTOR
#endif  /* EMACEC_VECTOR        */

#if !defined(EMACLC_VECTOR)
#define EMACLC_VECTOR           DUMMY_VECTOR
#endif  /* EMACLC_VECTOR        */

#if !defined(EMACBRXERR_VECTOR)
#define EMACBRXERR_VECTOR       DUMMY_VECTOR
#endif  /* EMACBRXERR_VECTOR    */

#if !defined(EMACRXBBO_VECTOR)
#define EMACRXBBO_VECTOR        DUMMY_VECTOR
#endif  /* EMACRXBBO_VECTOR     */

#if !defined(EMACRXBAO_VECTOR)
#define EMACRXBAO_VECTOR        DUMMY_VECTOR
#endif  /* EMACRXBAO_VECTOR     */

#if !defined(EMACRXERR_VECTOR)
#define EMACRXERR_VECTOR        DUMMY_VECTOR
#endif  /* EMACRXERR_VECTOR     */

#if !defined(EMACMII_VECTOR)
#define EMACMII_VECTOR          DUMMY_VECTOR
#endif  /* EMACMII_VECTOR       */

#if !defined(EMACRXFC_VECTOR)
#define EMACRXFC_VECTOR         DUMMY_VECTOR
#endif  /* EMACRXFC_VECTOR      */

#if !defined(EMACTXC_VECTOR)
#define EMACTXC_VECTOR          DUMMY_VECTOR
#endif  /* EMACTXC_VECTOR       */

#if !defined(EMACRXBBC_VECTOR)
#define EMACRXBBC_VECTOR        DUMMY_VECTOR
#endif  /* EMACRXBBC_VECTOR     */

#if !defined(EMACRXBAC_VECTOR)
#define EMACRXBAC_VECTOR        DUMMY_VECTOR
#endif  /* EMACRXBAC_VECTOR     */

#if !defined(EPHY_VECTOR)
#define EPHY_VECTOR             DUMMY_VECTOR
#endif  /* EPHY_VECTOR          */

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

#if !defined(PORTG_VECTOR)
#define PORTG_VECTOR            DUMMY_VECTOR
#endif  /* PORTG_VECTOR         */

#if !defined(PORTH_VECTOR)
#define PORTH_VECTOR            DUMMY_VECTOR
#endif  /* PORTH_VECTOR         */

#if !defined(PORTJ_VECTOR)
#define PORTJ_VECTOR            DUMMY_VECTOR
#endif  /* PORTJ_VECTOR         */

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

#if !defined(TIMPAIE_VECTOR)
#define TIMPAIE_VECTOR          DUMMY_VECTOR
#endif  /* TIMPAIE_VECTOR       */

#if !defined(TIMPAOVF_VECTOR)
#define TIMPAOVF_VECTOR         DUMMY_VECTOR
#endif  /* TIMPAOVF_VECTOR      */

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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff88 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8e */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff90 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff92 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff94 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff96 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff98 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9a */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9c */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff9e */
    (IISR_IVF)EMACEC_VECTOR,       
    (IISR_IVF)EMACLC_VECTOR,       
    (IISR_IVF)EMACBRXERR_VECTOR,   
    (IISR_IVF)EMACRXBBO_VECTOR,    
    (IISR_IVF)EMACRXBAO_VECTOR,    
    (IISR_IVF)EMACRXERR_VECTOR,    
    (IISR_IVF)EMACMII_VECTOR,      
    (IISR_IVF)EMACRXFC_VECTOR,     
    (IISR_IVF)EMACTXC_VECTOR,      
    (IISR_IVF)EMACRXBBC_VECTOR,    
    (IISR_IVF)EMACRXBAC_VECTOR,    
    (IISR_IVF)EPHY_VECTOR,         
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)IIC_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8 */
    (IISR_IVF)PORTG_VECTOR,        
    (IISR_IVF)PORTH_VECTOR,        
    (IISR_IVF)PORTJ_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)ATD_VECTOR,          
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)SPI_VECTOR,          
    (IISR_IVF)TIMPAIE_VECTOR,      
    (IISR_IVF)TIMPAOVF_VECTOR,     
    (IISR_IVF)TIMOVF_VECTOR,       
    (IISR_IVF)TIMCH7_VECTOR,       
    (IISR_IVF)TIMCH6_VECTOR,       
    (IISR_IVF)TIMCH5_VECTOR,       
    (IISR_IVF)TIMCH4_VECTOR,       
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




