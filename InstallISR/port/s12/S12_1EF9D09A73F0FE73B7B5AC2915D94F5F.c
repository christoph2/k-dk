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
 *      MC9S12I32
 *
 */

#include "ISR.h"

DECLARE_ISR1_VECTOR(DUMMY_VECTOR);

#if !defined(SI_VECTOR)
#define SI_VECTOR               DUMMY_VECTOR
#endif  /* SI_VECTOR            */

#if !defined(FLASH_VECTOR)
#define FLASH_VECTOR            DUMMY_VECTOR
#endif  /* FLASH_VECTOR         */

#if !defined(CRGFLLLCK_VECTOR)
#define CRGFLLLCK_VECTOR        DUMMY_VECTOR
#endif  /* CRGFLLLCK_VECTOR     */

#if !defined(SPI_VECTOR)
#define SPI_VECTOR              DUMMY_VECTOR
#endif  /* SPI_VECTOR           */

#if !defined(RTI_VECTOR)
#define RTI_VECTOR              DUMMY_VECTOR
#endif  /* RTI_VECTOR           */

#if !defined(D2DIEXTERR_VECTOR)
#define D2DIEXTERR_VECTOR       DUMMY_VECTOR
#endif  /* D2DIEXTERR_VECTOR    */

#if !defined(D2DIERR_VECTOR)
#define D2DIERR_VECTOR          DUMMY_VECTOR
#endif  /* D2DIERR_VECTOR       */

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
    (IISR_IVF)SI_VECTOR,           
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
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffba */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffbe */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc4 */
    (IISR_IVF)CRGFLLLCK_VECTOR,    
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffc8 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffca */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffcc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffce */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd4 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffd6 */
    (IISR_IVF)SPI_VECTOR,          
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffda */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffdc */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffde */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe0 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe2 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe4 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe6 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffe8 */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffea */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffec */
    (IISR_IVF)DUMMY_VECTOR,             /* Reserved - 0xffee */
    (IISR_IVF)RTI_VECTOR,          
    (IISR_IVF)D2DIEXTERR_VECTOR,   
    (IISR_IVF)D2DIERR_VECTOR,      
    (IISR_IVF)SWI_VECTOR,          
    (IISR_IVF)TRAP_VECTOR,         
    (IISR_IVF)COP_VECTOR,          
    (IISR_IVF)CLKMON_VECTOR,       
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,
#endif
};

#pragma constseg=default

