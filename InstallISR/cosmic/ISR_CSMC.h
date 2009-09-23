#if !defined(__ISR_CSMC_H)
#define __ISR_CSMC_H

#if !defined(S_SPLINT_S)
#define INTERRUPT @interrupt
#else
#define INTERRUPT
#endif

#define IISR_ENTRY_POINT  _stext

void _stext(void);

#if defined(__CSMC__)
    #define II_INC_TARGET_H    "cosmic/hcs12/ISR_CSMC_HCS12.h"
#else
    #error Unsupported Target for Cosmic-Compiler.
#endif

#if 0
#include II_INC_PATH_COMP II_INC_TARGET_H
#include INC_PATH_H
#endif
#include II_INC_TARGET_H


#endif /* __ISR_CSMC_H */

