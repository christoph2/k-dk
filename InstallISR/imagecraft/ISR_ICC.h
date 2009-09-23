#if !defined(__ISR_ICC_H)
#define __ISR_ICC_H

void _start(void);
#define IISR_ENTRY_POINT  _start

#if defined(_AVR)
    #define II_INC_TARGET_H    "./avr/ISR_ICC_AVR.h"
#elif defined(_HC12)
    #define II_INC_TARGET_H    "hcs12/ISR_ICC_HCS12.h"
#elif defined(_MSP430)
    #define II_INC_TARGET_H    "./msp430/ISR_ICC_MSP430.h"
#else
    #error Unspupported Target for Imagecraft ICC.
#endif

/* #include II_INC_TARGET_H */
#include II_INC_PATH_H

#endif /* __ISR_ICC_H */

