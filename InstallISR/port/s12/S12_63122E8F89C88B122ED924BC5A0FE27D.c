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
 *      MC9S12UF32
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(SMHCS_VECTOR)
#define SMHCS_VECTOR            DUMMY_VECTOR
#endif  /* SMHCS_VECTOR         */

#if !defined(SMHCE_VECTOR)
#define SMHCE_VECTOR            DUMMY_VECTOR
#endif  /* SMHCE_VECTOR         */

#if !defined(SDHC_VECTOR)
#define SDHC_VECTOR             DUMMY_VECTOR
#endif  /* SDHC_VECTOR          */

#if !defined(MSHC_VECTOR)
#define MSHC_VECTOR             DUMMY_VECTOR
#endif  /* MSHC_VECTOR          */

#if !defined(CFIREQHC_VECTOR)
#define CFIREQHC_VECTOR         DUMMY_VECTOR
#endif  /* CFIREQHC_VECTOR      */

#if !defined(CFSFTHC_VECTOR)
#define CFSFTHC_VECTOR          DUMMY_VECTOR
#endif  /* CFSFTHC_VECTOR       */

#if !defined(ATA5HC_VECTOR)
#define ATA5HC_VECTOR           DUMMY_VECTOR
#endif  /* ATA5HC_VECTOR        */

#if !defined(IQUECH34DBTC_VECTOR)
#define IQUECH34DBTC_VECTOR     DUMMY_VECTOR
#endif  /* IQUECH34DBTC_VECTOR  */

#if !defined(IQUECH34DBE_VECTOR)
#define IQUECH34DBE_VECTOR      DUMMY_VECTOR
#endif  /* IQUECH34DBE_VECTOR   */

#if !defined(IQUECH34DBF_VECTOR)
#define IQUECH34DBF_VECTOR      DUMMY_VECTOR
#endif  /* IQUECH34DBF_VECTOR   */

#if !defined(IQUECH12DBTC_VECTOR)
#define IQUECH12DBTC_VECTOR     DUMMY_VECTOR
#endif  /* IQUECH12DBTC_VECTOR  */

#if !defined(IQUECH12DBE_VECTOR)
#define IQUECH12DBE_VECTOR      DUMMY_VECTOR
#endif  /* IQUECH12DBE_VECTOR   */

#if !defined(IQUECH12DBF_VECTOR)
#define IQUECH12DBF_VECTOR      DUMMY_VECTOR
#endif  /* IQUECH12DBF_VECTOR   */

#if !defined(IQUECH4V_VECTOR)
#define IQUECH4V_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH4V_VECTOR      */

#if !defined(IQUECH4E_VECTOR)
#define IQUECH4E_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH4E_VECTOR      */

#if !defined(IQUECH4F_VECTOR)
#define IQUECH4F_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH4F_VECTOR      */

#if !defined(IQUECH3V_VECTOR)
#define IQUECH3V_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH3V_VECTOR      */

#if !defined(IQUECH3E_VECTOR)
#define IQUECH3E_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH3E_VECTOR      */

#if !defined(IQUECH3F_VECTOR)
#define IQUECH3F_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH3F_VECTOR      */

#if !defined(IQUECH2V_VECTOR)
#define IQUECH2V_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH2V_VECTOR      */

#if !defined(IQUECH2E_VECTOR)
#define IQUECH2E_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH2E_VECTOR      */

#if !defined(IQUECH2F_VECTOR)
#define IQUECH2F_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH2F_VECTOR      */

#if !defined(IQUECH1V_VECTOR)
#define IQUECH1V_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH1V_VECTOR      */

#if !defined(IQUECH1E_VECTOR)
#define IQUECH1E_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH1E_VECTOR      */

#if !defined(IQUECH1F_VECTOR)
#define IQUECH1F_VECTOR         DUMMY_VECTOR
#endif  /* IQUECH1F_VECTOR      */

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(USBSOF_VECTOR)
#define USBSOF_VECTOR           DUMMY_VECTOR
#endif  /* USBSOF_VECTOR        */

#if !defined(USBE6_VECTOR)
#define USBE6_VECTOR            DUMMY_VECTOR
#endif  /* USBE6_VECTOR         */

#if !defined(USBE5_VECTOR)
#define USBE5_VECTOR            DUMMY_VECTOR
#endif  /* USBE5_VECTOR         */

#if !defined(USBE4_VECTOR)
#define USBE4_VECTOR            DUMMY_VECTOR
#endif  /* USBE4_VECTOR         */

#if !defined(CRGPLLLCK_VECTOR)
#define CRGPLLLCK_VECTOR        DUMMY_VECTOR
#endif  /* CRGPLLLCK_VECTOR     */

#if !defined(USBE3_VECTOR)
#define USBE3_VECTOR            DUMMY_VECTOR
#endif  /* USBE3_VECTOR         */

#if !defined(USBE2_VECTOR)
#define USBE2_VECTOR            DUMMY_VECTOR
#endif  /* USBE2_VECTOR         */

#if !defined(USBE0O_VECTOR)
#define USBE0O_VECTOR           DUMMY_VECTOR
#endif  /* USBE0O_VECTOR        */

#if !defined(USBE0I_VECTOR)
#define USBE0I_VECTOR           DUMMY_VECTOR
#endif  /* USBE0I_VECTOR        */

#if !defined(USBSECRR_VECTOR)
#define USBSECRR_VECTOR         DUMMY_VECTOR
#endif  /* USBSECRR_VECTOR      */

#if !defined(USBSCR_VECTOR)
#define USBSCR_VECTOR           DUMMY_VECTOR
#endif  /* USBSCR_VECTOR        */

#if !defined(USBSC_VECTOR)
#define USBSC_VECTOR            DUMMY_VECTOR
#endif  /* USBSC_VECTOR         */

#if !defined(SCI_VECTOR)
#define SCI_VECTOR              DUMMY_VECTOR
#endif  /* SCI_VECTOR           */

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
    (IISR_IVF)SMHCS_VECTOR,        
    (IISR_IVF)SMHCE_VECTOR,        
    (IISR_IVF)SDHC_VECTOR,         
    (IISR_IVF)MSHC_VECTOR,         
    (IISR_IVF)CFIREQHC_VECTOR,     
    (IISR_IVF)CFSFTHC_VECTOR,      
    (IISR_IVF)ATA5HC_VECTOR,       
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff90 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xff92 */
    (IISR_IVF)IQUECH34DBTC_VECTOR, 
    (IISR_IVF)IQUECH34DBE_VECTOR,  
    (IISR_IVF)IQUECH34DBF_VECTOR,  
    (IISR_IVF)IQUECH12DBTC_VECTOR, 
    (IISR_IVF)IQUECH12DBE_VECTOR,  
    (IISR_IVF)IQUECH12DBF_VECTOR,  
    (IISR_IVF)IQUECH4V_VECTOR,     
    (IISR_IVF)IQUECH4E_VECTOR,     
    (IISR_IVF)IQUECH4F_VECTOR,     
    (IISR_IVF)IQUECH3V_VECTOR,     
    (IISR_IVF)IQUECH3E_VECTOR,     
    (IISR_IVF)IQUECH3F_VECTOR,     
    (IISR_IVF)IQUECH2V_VECTOR,     
    (IISR_IVF)IQUECH2E_VECTOR,     
    (IISR_IVF)IQUECH2F_VECTOR,     
    (IISR_IVF)IQUECH1V_VECTOR,     
    (IISR_IVF)IQUECH1E_VECTOR,     
    (IISR_IVF)IQUECH1F_VECTOR,     
    (IISR_IVF)FLASH_VECTOR,        
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)USBSOF_VECTOR,       
    (IISR_IVF)USBE6_VECTOR,        
    (IISR_IVF)USBE5_VECTOR,        
    (IISR_IVF)USBE4_VECTOR,        
    (IISR_IVF)CRGPLLLCK_VECTOR,    
    (IISR_IVF)USBE3_VECTOR,        
    (IISR_IVF)USBE2_VECTOR,        
    (IISR_IVF)USBE0O_VECTOR,       
    (IISR_IVF)USBE0I_VECTOR,       
    (IISR_IVF)USBSECRR_VECTOR,     
    (IISR_IVF)USBSCR_VECTOR,       
    (IISR_IVF)USBSC_VECTOR,        
    (IISR_IVF)SCI_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd8 */
    (IISR_IVF)TIMPAIE_VECTOR,      
    (IISR_IVF)TIMPAOVF_VECTOR,     
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xfffc */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,
#endif
};

#pragma constseg=default

