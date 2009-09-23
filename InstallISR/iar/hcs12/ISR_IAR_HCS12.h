#if !defined(__ISR_IAR_HCS12_H)
#define __ISR_IAR_HCS12_H

#define DECLARE_ISR2_VECTOR(IsrName) __interrupt void IsrName(void)
#define DECLARE_ISR1_VECTOR(IsrName) __interrupt void IsrName(void)
#define ISR1(IsrName) __interrupt void IsrName(void)

#define IISR_ENTRY_POINT __program_start
void __program_start(void);
extern void (* const  interrupt_vectors[])(void);

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_IAR_HCS12_H */
