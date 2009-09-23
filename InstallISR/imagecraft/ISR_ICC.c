
#if defined(_AVR)
    #define II_INC_TARGET_C   "./avr/ISR_ICC_AVR.c"
#elif defined(_HC12)
    #define II_INC_TARGET_C   "./hcs12/ISR_ICC_HCS12.c"
#elif defined(_MSP430)
    #define II_INC_TARGET_C   "./msp430/ISR_ICC_MSP430.c"
#else
    #error Unsupported Target for Imagecraft-Compiler.
#endif

#include II_INC_TARGET_C
