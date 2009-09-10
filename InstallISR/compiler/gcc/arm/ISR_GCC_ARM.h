#if !defined(__ISR_GCC_ARM_H)
#define __ISR_GCC_ARM_H

#define DECLARE_ISR(IsrName) void IsrName(void) __attribute__((interrupt))

#endif /* __ISR_GCC_ARM_H */
