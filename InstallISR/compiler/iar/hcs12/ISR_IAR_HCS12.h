#if !defined(__ISR_IAR_HCS12_H)
#define __ISR_IAR_HCS12_H

#if defined(ISR)
    #undef ISR
    #define ISR(IsrName) __interrupt void IsrName(void)
#endif

#define DECLARE_ISR(IsrName) __interrupt void IsrName(void)
#define IISR_ENTRY_POINT __program_start
void __program_start(void);
extern void (* const  interrupt_vectors[])(void);

#endif /* __ISR_IAR_HCS12_H */
