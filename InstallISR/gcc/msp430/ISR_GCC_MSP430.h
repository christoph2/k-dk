#if !defined(__ISR_GCC_MSP430_H)
#define __ISR_GCC_MSP430_H

#define DECLARE_ISR(IsrName) void __attribute__((interrupt(0xff))) IsrName(void)

#endif /* __ISR_GCC_MSP430_H */
