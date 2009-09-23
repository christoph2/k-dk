#if !defined(__ISR_MW_H)
#define __ISR_MW_H

#if defined(__HC12__)
    #define II_INC_TARGET_H    "metrowerks/hcs12/ISR_MW_HCS12.h"
#else
    #error Unsupported Target for Metrowerks.
#endif

/* #include II_INC_COMP_H */

/* #include INC_PATH_H */
#include II_INC_TARGET_H
        
#endif /* __ISR_MW_H */
