#if !defined(__CPU_PRIMITIVES_H)
#define __CPU_PRIMITIVES_H

#if defined(__CSMC__)           /* Cosmic               */
    #define CP_COMP             "cosmic/"
#elif defined(__GNUC__)         /* GNU GCC              */
    #define CP_INC_PATH_COMP    "gcc/"
#elif defined(__HIWARE__)       /* Metrowerks/Freescale */
    #define CP_COMP             "metrowerks"
#elif defined(__IAR_SYSTEMS_ICC__)  /* IAR Systems          */

    #if defined(__ICCARM__)
        #define CP_TARGET       "arm/iar/cpri.h"
    #elif defined(__ICCHCS12__)
        #define CP_TARGET       "cpu12/iar/cpri.h"
    #else
        #error Unsupported Target for IAR-ICC.
    #endif

#elif defined(__IMAGECRAFT__)   /* Imagecraft           */
    #define CP_COMP             "imagecraft/"
#else                           /* todo: Add Support    */
    #error Unsupported Compiler.
#endif

#include CP_TARGET
#undef CP_TARGET

#endif /* __CPU_PRIMITIVES_H */
