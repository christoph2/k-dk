#if !defined(__ISR_GCC_HCS12_H)
#define __ISR_GCC_HCS12_H

#define DECLARE_ISR(IsrName) void IsrName(void) __attribute__((interrupt))

extern void (* const  interrupt_vectors[])(void);

#endif /* __ISR_GCC_HCS12_H */
