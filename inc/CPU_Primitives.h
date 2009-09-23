#if !defined(__CPU_PRIMITIVES_H)
#define __CPU_PRIMITIVES_H

#if defined(__CSMC__)               /* Cosmic               */
    #define CP_COMP             "cosmic/"
#elif defined(__GNUC__)             /* GNU GCC              */

    #if defined(__arm__)
        #define CP_TARGET       "arm/gcc/cpri.h"
    #elif defined(__AVR__)
        #define CP_TARGET       "avr/gcc/cpri.h"
    #elif defined(MC6812)
        #define CP_TARGET       "cpu12/gcc/cpri.h"
    #elif defined(__MSP430__)
        #define CP_TARGET       "msp430/gcc/cpri.h"
    #elif defined( __CYGWIN32__) && defined(__I386__)
        /* Dummy-Target */
        #define CP_TARGET       "cygwin/gcc/cpri.h"
    #else
        #error Unsupported Target for GCC.
    #endif

#elif defined(__HIWARE__)           /* Metrowerks/Freescale */

    #if defined(__HC12__)
        #define CP_TARGET       "cpu12/codewarrior/cpri.h"
    #else
        #error Unsupported Target for Metrowerks.
    #endif
    
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */

    #if defined(__ICCARM__)
        #define CP_TARGET       "arm/iar/cpri.h"
    #elif defined(__ICCHCS12__)
        #define CP_TARGET       "cpu12/iar/cpri.h"
    #else
        #error Unsupported Target for IAR-ICC.
    #endif

#elif defined(__IMAGECRAFT__)       /* Imagecraft           */
    #define CP_COMP             "imagecraft/"
#else                               /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

#include    CP_TARGET
#undef      CP_TARGET

#endif /* __CPU_PRIMITIVES_H */
