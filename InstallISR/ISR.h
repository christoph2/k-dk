/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__ISR_H)
#define __ISR_H

#if defined(__cplusplus)
extern "C" {
#endif

#include "Sys_Cfg.h"
/* todo: using #include "Compiler.h" would be a very good idea!!! */

#if !defined(CPU_FAMILY)
    #error CPU_FAMILY must be specified. Valid: [CPU12_HC12|CPU12_S12|PIC_F18].
#elif (CPU_FAMILY != CPU12_HC12) && (CPU_FAMILY != CPU12_S12) && (CPU_FAMILY != PIC_F18)
    #error wrong CPU_FAMILY specified. Valid: [CPU12_HC12|CPU12_S12|PIC_F18].
#endif  /* CPU_FAMILY */

#if !defined(CPU_DERIVATE)
    #error CPU_DERIVATE must be specified (depends on CPU_FAMILY) !!!
#else
    #if CPU_FAMILY == CPU12_HC12
        #if CPU_DERIVATE != CPU12_HC12B32 && CPU_DERIVATE != CPU12_HC12BC32 && CPU_DERIVATE != CPU12_HC12DG128A && \
    CPU_DERIVATE != CPU12_HC12DT128A && CPU_DERIVATE != CPU12_HC12A4
            #error \
    wrong CPU_DERIVATE specified. Valid for CPU12_HC12: [CPU12_HC12A4|CPU12_HC12B32|CPU12_HC12BC32|CPU12_HC12DG128A|CPU12_HC12DT128A].
        #endif
    #elif CPU_FAMILY == CPU12_S12
        #if CPU_DERIVATE != CPU12_S12DP256B
            #error wrong CPU_DERIVATE specified. Valid for CPU12_S12: [CPU12_S12DP256B].
        #endif
    #endif
#endif  /* CPU_DERIVATE */

#if 0
CPU_FAMILY    == > CPU12_HC12, CPU12_S12 | CPU12_S12X
CPU_DERIVATE  == >
CPU12_HC12:   CPU12_HC12A4 | CPU12_HC12B32 | CPU12_HC12BC32 | CPU12_HC12DG128A | CPU12_HC12DT128A
CPU12_S12:    CPU12_S12DP256B
#endif

/*   *** Compiler ***   */
/*======================*/
#if defined(__CSMC__)               /* Cosmic               */
    #define II_INC_COMP_H       "cosmic/ISR_CSMC.h"
    #define II_INC_PATH_COMP    "cosmic/"
#elif defined(__GNUC__)             /* GNU GCC              */
    #define II_INC_COMP_H       "gcc/ISR_GCC.h"
    #define II_INC_PATH_COMP    "gcc/"
#elif defined(__HIWARE__)           /* Metrowerks/ Freescale */
    #define II_INC_COMP_H       "metrowerks/ISR_MW.h"
    #define II_INC_PATH_COMP    "metrowerks"
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */
    #define II_INC_COMP_H       "iar/ISR_IAR.h"
    #define II_INC_PATH_COMP    "iar/"
#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #define II_INC_COMP_H       "imagecraft/ISR_ICC.h"
    #define II_INC_PATH_COMP    "imagecraft/"
#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)
    #define II_INC_COMP_H       "ccsc/ISR_CCSC.h"
    #define II_INC_PATH_COMP    "ccsc/"
#elif defined(_MSC_VER)
    #define II_INC_COMP_H       "msvc/ISR_MSVC.h"
    #define II_INC_PATH_COMP    "msvc/"
#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

typedef  void (*const IISR_IVF)(void);

/*
**  OSEK-ISR2-Wrapper.
*/
#if defined(USE_ORTI)
#define OS_SET_ISRID(id) (OsCurrentISRID = (id))
#else
#define OS_SET_ISRID(id)
#endif

#define DEFINE_ISR2_VECTOR DECLARE_ISR2_VECTOR

/*
**  ISR2_HANDLER: Handler, that is implemented /w 'ISR()'.
*/
#define DECLARE_ISR2_USER_HANDLER(IsrName) void IsrName ## _Handler(void)

#define IMPLEMENT_ISR2_VECTOR(IsrName)   \
    DEFINE_ISR2_VECTOR(IsrName)          \
    {                                    \
        _BEGIN_BLOCK                     \
        OSEnterISR();                    \
        OS_SET_ISRID(ISRID_ ## IsrName); \
        IsrName ## _Handler();           \
        OS_SET_ISRID(ISRID_NONE);        \
        OSLeaveISR();                    \
        _END_BLOCK;                      \
    }

#define INC_PATH_H  II_INC_PATH_COMP ## II_INC_TARGET_H
#define INC_PATH_C  II_INC_PATH_COMP II_INC_TARGET_C

#include II_INC_COMP_H

#include "ISR_Cfg.h"

#if !defined(ISR)
#define ISR(IsrName) void IsrName ## _Handler(void)
#endif

void ISR_Init(void);


#if defined(__cplusplus)
}
#endif

#endif /* __ISR_H */
