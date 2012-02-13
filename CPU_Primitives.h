/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__CPU_PRIMITIVES_H)
#define __CPU_PRIMITIVES_H

#if defined(__CSMC__)               /* Cosmic               */
    #define CP_COMP         "cosmic/"
    #define CP_TARGET       "compiler/cpu12/cosmic/CPU_Primitives.h"
#elif defined(__GNUC__)             /* GNU GCC              */

    #if defined(__arm__)
        #define CP_TARGET   "compiler/arm/gcc/CPU_Primitives.h"
    #elif defined(__AVR__)
        #define CP_TARGET   "compiler/avr/gcc/CPU_Primitives.h"
    #elif defined(MC6812)
        #define CP_TARGET   "compiler/cpu12/gcc/CPU_Primitives.h"
    #elif defined(__MSP430__)
        #define CP_TARGET   "compiler/msp430/gcc/CPU_Primitives.h"
    #elif defined( __CYGWIN32__) /* && defined(__I386__) */
/* Dummy-Target */
        #define CP_TARGET   "compiler/i386/gcc/CPU_Primitives.h"
    #else
        #error Unsupported Target for GCC.
    #endif

#elif defined(__HIWARE__)           /* Metrowerks/Freescale */

    #if defined(__HC12__)
        #define CP_TARGET "compiler/cpu12/codewarrior/CPU_Primitives.h"
    #else
        #error Unsupported Target for Metrowerks.
    #endif

#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */

    #if defined(__ICCARM__)
        #define CP_TARGET   "compiler/arm/iar/CPU_Primitives.h"
    #elif defined(__ICCHCS12__)
        #define CP_TARGET   "compiler/cpu12/iar/CPU_Primitives.h"
    #else
        #error Unsupported Target for IAR-ICC.
    #endif

#elif defined(__IMAGECRAFT__)       /* Imagecraft           */

    #define CP_TARGET   "compiler/cpu12/imagecraft/CPU_Primitives.h"

#elif defined(__18CXX )

    #define CP_TARGET   "compiler/pic/mpl_c18/CPU_Primitives.h"

#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)

    #define CP_TARGET   "compiler/pic/ccsc/CPU_Primitives.h"
#elif defined(_MSC_VER)

/* Microsoft Visual C. */
    #define CP_TARGET   "compiler/i386/msvc/CPU_Primitives.h"

#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

typedef uint8 InterruptStateType;

#include    CP_TARGET
#undef      CP_TARGET

#endif /* __CPU_PRIMITIVES_H */

