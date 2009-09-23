#if !defined(__ISR_GCC_H)
#define __ISR_GCC_H

#define IISR_ENTRY_POINT  _start

#if defined(__arm__)
    #define II_INC_TARGET_H   "./arm/ISR_GCC_ARM.h"
#elif defined(__AVR__)
    #define II_INC_TARGET_H   "./avr/ISR_GCC_AVR.h"
#elif defined(MC6812)
    #define II_INC_TARGET_H   "./hcs12/ISR_GCC_HCS12.h"
#elif defined(__MSP430__)
    #define II_INC_TARGET_H   "./msp430/ISR_GCC_MSP430.h"
#else
    #error Unsupported Target for GCC.
#endif

#include II_INC_TARGET_H

#endif /* __ISR_GCC_H */
