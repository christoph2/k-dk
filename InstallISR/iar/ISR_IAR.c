
#if defined(__ICCARM__)
    #define II_INC_TARGET_C   "./arm/ISR_IAR_ARM.c"
#elif defined(__ICCHCS12__)
    #define II_INC_TARGET_C   "./hcs12/ISR_IAR_HCS12.c"
#else
    #error Unsupported Target for IAR-Compiler.
#endif

#include II_INC_TARGET_C
