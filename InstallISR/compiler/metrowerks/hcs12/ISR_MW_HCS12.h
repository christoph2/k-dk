#if !defined(__ISR_MW_HCS12_H)
#define __ISR_MW_HCS12_H

#if 0
#if defined(ISR)
    #undef ISR
    #define ISR(IsrName) __interrupt void IsrName(void)
#endif
#endif

#define DECLARE_ISR(IsrName) __interrupt void IsrName(void)
void __near _Startup(void);
#define IISR_ENTRY_POINT  _Startup

extern void (* const  interrupt_vectors[])(void);

#endif /* __ISR_MW_HCS12_H */
