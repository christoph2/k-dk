
#if defined(__CSMC__)
    #define II_INC_TARGET_C    "cosmic/hcs12/ISR_CSMC_HCS12.c"
#else
    #error Unsupported Target for Cosmic-Compiler.
#endif

#include II_INC_TARGET_C
/* #include INC_PATH_C */

