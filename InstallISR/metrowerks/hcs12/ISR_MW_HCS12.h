#if !defined(__ISR_MW_HCS12_H)
#define __ISR_MW_HCS12_H


#define DECLARE_ISR2_VECTOR(IsrName) __interrupt void IsrName(void)
#define DECLARE_ISR1_VECTOR(IsrName) __interrupt void IsrName(void)
#define ISR1(IsrName) __interrupt void IsrName(void)

void __near _Startup(void);
#define IISR_ENTRY_POINT  _Startup

extern void (* const  interrupt_vectors[])(void);

#define IISR_DECLARE_VECTOR_TABLE()
#define IISR_BEGIN_VECTOR_TABLE()
#define IISR_END_VECTOR_TABLE()


#endif /* __ISR_MW_HCS12_H */
