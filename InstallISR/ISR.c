/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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

#include "ISR.h"

#if defined(__CSMC__)               /* Cosmic               */
    #define II_INC_COMP_C   "cosmic/ISR_CSMC.c"
#elif defined(__GNUC__)             /* GNU GCC              */
    #define II_INC_COMP_C   "gcc/ISR_GCC.c"
#elif defined(__HIWARE__)           /* Metrowerks/Freescale */
    #define II_INC_COMP_C   "metrowerks/ISR_MW.c"
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */
    #define II_INC_COMP_C   "iar/ISR_IAR.c"
#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #define II_INC_COMP_C   "imagecraft/ISR_ICC.c"
#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)
   #define II_INC_COMP_C    "ccsc/ISR_CCSC.c"
#elif defined(_MSC_VER)             /* Microsoft            */
   #define II_INC_COMP_C    "msvc/ISR_MSVC.c"
#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

#include II_INC_COMP_C
