#if !defined(__ISR_ICC_HCS12_H)
#define __ISR_ICC_HCS12_H

#define DECLARE_ISR(IsrName) void IsrName(void) __attribute__((interrupt))

extern void (* const  interrupt_vectors[])(void);

void _start(void);
#define IISR_ENTRY_POINT  _start
#define IISR_INTERUPT     #pragma interrupt_handler

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_GCC_HCS12_H */
