#if !defined(__ISR_ICC_H)
#define __ISR_ICC_H

void _start(void);
#define IISR_ENTRY_POINT  _start

#if defined(_AVR)

#elif defined(_HC12)

#elif defined(_MSP430)
    #error Unspupported Target for Imagecraft ICC.
#endif

#endif /* __ISR_ICC_H */
