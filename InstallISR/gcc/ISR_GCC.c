
#if defined(__arm__)
    #define II_INC_TARGET_C   "./arm/ISR_GCC_ARM.c"
#elif defined(__AVR__)
    #define II_INC_TARGET_C   "./avr/ISR_GCC_AVR.c"
#elif defined(MC6812)
    #define II_INC_TARGET_C   "./hcs12/ISR_GCC_HCS12.c"
#elif defined(__MSP430__)
    #define II_INC_TARGET_C   "./msp430/ISR_GCC_MSP430.c"
#else
    #error Unsupported Target for GCC-Compiler.
#endif

#include II_INC_TARGET_C

