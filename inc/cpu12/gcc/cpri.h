#if !defined(__CPRI_H)
#define __CPRI_H


/*
**      Port-Macros.
*/

/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_POWERDOWN_MODE()            __asm__("wai")


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __asm__("swi")


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     __asm__("rti")


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                __asm__("bgnd")


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __asm__("nop")


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __asm__("sei")


/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        __asm__("cli");                     \
        __asm__("nop");                     \
    _END_BLOCK


/*
**  Check for Interrupts disabled.
*/
boolean Cpu_InterruptsDisabled(void);

#endif /* __CPRI_H */

