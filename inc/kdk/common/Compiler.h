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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__COMPILER_H)
#define   __COMPILER_H

#if 0
#include "Std_Macros.h"
#include "Compiler_Cfg.h"
#endif

/* todo: spezifische Include-Files!!! */
#if defined(__CSMC__)               /* Cosmic               */
    #if (CPU_FAMILY == CPU12_S12) || (CPU_FAMILY == CPU12_HC12)
/*    #if defined(CPU12_HC12) || defined(CPU12_S12) */
        #define _COSMIC_C_CPU12_
    #else
        #error Unsupported Target for Cosmic Compiler.
    #endif
#elif defined(__GNUC__)             /* GNU GCC              */
    #if defined(__arm__)
        #define _GNU_C_ARM_
    #elif defined(__AVR__)
        #define _GNU_C_AVR_
    #elif defined(MC6812)
        #define _GNU_C_CPU12_
    #elif defined(__MSP430__)
        #define _GNU_C_MSP430_
    #elif defined( __CYGWIN32__) /* && defined(__I386__) */
        #define KAR_DUMMY_TARGET
    #else
        #error Unsupported Target for GCC-Compiler.
    #endif
#elif defined(__HIWARE__)           /* Metrowerks/Freescale */
    #if defined(__HC12__)
        #define _METROWERKS_C_CPU12_
    #else
        #error Unsupported Target for Metrowerks-Compiler.
    #endif
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */
    #if defined(__ICCARM__)
        #define _IAR_C_ARM_
    #elif defined(__ICCHCS12__)
        #define _IAR_C_CPU12_
    #elif defined(__ICC430__)
        #define _IAR_C_MSP430_
    #else
        #error Unsupported Target for IAR Compiler.
    #endif
#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #if defined(_AVR)
        #define _IMAGECRAFT_C_AVR_
    #elif defined(_HC12)
        #define _IMAGECRAFT_C_CPU12_
    #elif defined(_MSP430)
        #define _IMAGECRAFT_C_MSP430_
    #else
        #error Unsupported Target for Imagecraft-Compiler.
    #endif
#elif defined(__18CXX )
/* MPlab C18 Compiler for the PIC family. */

    #define _MPLAB_C18_

    #if defined(__SMALL__)
        #define _MPLAB_C18_SMALL_
    #elif defined(__LARGE__)
        #define _MPLAB_C18_LARGE_
    #elif defined(__TRADITIONAL18__)
        #define _MPLAB_C18_TRADITIONAL18_
    #elif defined(__EXTENDED18__)
        #define _MPLAB_C18_EXTENDED18_
    #endif

#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)

/* CCSC Compiler for the PIC family. */

   #define _CCSC_C_PIC_
#elif defined(_MSC_VER)
/* Microsoft Visual C. */
    #define KAR_DUMMY_TARGET

#else
    #error Unsupported Compiler.
#endif

#define AUTOMATIC
#define TYPEDEF
#define STATIC      static
#define NULL_PTR    ((void *)0)
/* 'INLINE ' defined in 'Std_Macros.h'. */

/*
**  IAR.
*/

/*
**  Macros for Functions.
*/
#define   FUNC(rettype, memclass)                   memclass rettype

/*
**  Macros for Pointers.
*/
#define P2VAR(ptrtype, memclass, ptrclass)          memclass ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass)        memclass ptrtype const *
#define CONSTP2VAR(ptrtype, memclass, ptrclass)     memclass ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass)   memclass ptrtype const * const
#define P2FUNC(rettype, ptrclass, fctname)          rettype(*fctname)

/*
**  Keywords for Constants.
*/
#define CONST(type, memclass)                       memclass const type

/*
**  Keywords for Variables.
*/
#define VAR(type, memclass)                         memclass type

#include "Std_Macros.h"
#include "Compiler_Cfg.h"

/*
**  Other Compilers.
*/

#endif   /*  __COMPILER_H  */
