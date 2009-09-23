
#if defined(__HC12__)
    #define II_INC_TARGET_C    "metrowerks/hcs12/ISR_MW_HCS12.c"
#else
    #error Unsupported Target for Metrowerks-Compiler.
#endif

/*  #include INC_PATH_C */
#include II_INC_TARGET_C
