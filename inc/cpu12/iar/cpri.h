#if !defined(__CPRI_H)
#define __CPRI_H

#include <intrinsics.h>

/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_POWERDOWN_MODE()            __wait_for_interrupt()

/* __stop_CPU() */

/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __software_interrupt()


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     asm("rti")


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                asm("bgnd")


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __no_operation()


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __disable_interrupt()


/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        __enable_interrupt();               \
        __no_operation();                   \
    _END_BLOCK


/*
**  Check for Interrupts disabled.
*/
#define Cpu_InterruptsDisabled()  (((uint8)__get_ccr_register() & ((uint8)0x10))==((uint8)0x10))

#endif /* __CPRI_H */
