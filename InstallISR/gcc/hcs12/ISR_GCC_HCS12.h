#if !defined(__ISR_GCC_HCS12_H)
#define __ISR_GCC_HCS12_H

#if 0
#define DECLARE_ISR(IsrName) void IsrName(void) __attribute__((interrupt))
#endif

#define DECLARE_ISR2_VECTOR(IsrName) void IsrName(void) __attribute__((interrupt))
#define DECLARE_ISR1_VECTOR(IsrName) void IsrName(void) __attribute__((interrupt))
#define ISR1(IsrName) void IsrName(void) __attribute__((interrupt))

extern void (* const  interrupt_vectors[])(void);

void _start(void);

#define IISR_ENTRY_POINT  _start
#define IISR_INTERUPT     __attribute__((interrupt))

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_GCC_HCS12_H */


