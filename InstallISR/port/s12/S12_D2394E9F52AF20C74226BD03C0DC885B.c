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
 *      MC9S12A32
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(PWMESDN_VECTOR)
#define PWMESDN_VECTOR          DUMMY_VECTOR
#endif  /* PWMESDN_VECTOR       */

#if !defined(PORTP_VECTOR)
#define PORTP_VECTOR            DUMMY_VECTOR
#endif  /* PORTP_VECTOR         */

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(EEPROM_VECTOR)
#define EEPROM_VECTOR           DUMMY_VECTOR
#endif  /* EEPROM_VECTOR        */

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

#if !defined(PORTJ_VECTOR)
#define PORTJ_VECTOR            DUMMY_VECTOR
#endif  /* PORTJ_VECTOR         */

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


ISR1(DUMMY_VECTOR)
{
}

#pragma constseg = INTVEC
#pragma required = interrupt_vectors
#pragma location = 0xff80
__root void(* const interrupt_vectors[]) (void) = {
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff80 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff82 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff84 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff86 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff88 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff8a */
    (IISR_IVF)PWMESDN_VECTOR,      
    (IISR_IVF)PORTP_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff90 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff92 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff94 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff96 */
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb4 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffb6 */
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)EEPROM_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)CRGSCM_VECTOR,       
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)TIMPABOVF_VECTOR,    
    (IISR_IVF)TIMMDCU_VECTOR,      
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffcc */
    (IISR_IVF)PORTJ_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)ATD0_VECTOR,         
    (IISR_IVF)SCI1_VECTOR,         
    (IISR_IVF)SCI0_VECTOR,         
    (IISR_IVF)SPI0_VECTOR,         
    (IISR_IVF)TIMPAIE_VECTOR,      
    (IISR_IVF)TIMPAAOVF_VECTOR,    
    (IISR_IVF)TIMOVF_VECTOR,       
    (IISR_IVF)TIMCH7_VECTOR,       
    (IISR_IVF)TIMCH6_VECTOR,       
    (IISR_IVF)TIMCH5_VECTOR,       
    (IISR_IVF)TIMCH4_VECTOR,       
    (IISR_IVF)TIMCH3_VECTOR,       
    (IISR_IVF)TIMCH2_VECTOR,       
    (IISR_IVF)TIMCH1_VECTOR,       
    (IISR_IVF)TIMCH0_VECTOR,       
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

