#if !defined(__ISR_GCC_AVR_H)
#define __ISR_GCC_AVR_H

/* __attribute__((signal,naked)) */

#define DECLARE_ISR(IsrName) void IsrName(void) __attribute__ (( signal ))

#endif /* __ISR_GCC_AVR_H */
