#if !defined(__ISR_CSMC_HCS12_H)
#define __ISR_CSMC_HCS12_H

#define DECLARE_ISR2_VECTOR(IsrName) INTERRUPT void IsrName(void)
#define DECLARE_ISR1_VECTOR(IsrName) INTERRUPT void IsrName(void)

#define ISR1(IsrName) INTERRUPT void IsrName(void)

extern void (* const  interrupt_vectors[])(void);

#define IISR_DECLARE_VECTOR_TABLE
#define IISR_BEGIN_VECTOR_TABLE
#define IISR_END_VECTOR_TABLE

#endif /* __ISR_CSMC_HCS12_H */

