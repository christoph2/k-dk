#if !defined(__ISR_IAR_H)
#define __ISR_IAR_H

#if defined(__ICCARM__)
    #define II_INC_TARGET_H    "arm/ISR_IAR_ARM.h"
#elif defined(__ICCHCS12__)
    #define II_INC_TARGET_H    "hcs12/ISR_IAR_HCS12.h"
#else
    #error Unsupported Target for IAR-ICC.
#endif

#include II_INC_TARGET_H


#endif /* __ISR_IAR_H */
