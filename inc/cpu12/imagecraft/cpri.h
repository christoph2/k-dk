#if !defined(__CPRI_H)
#define __CPRI_H


/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_POWERDOWN_MODE()            asm("wai")


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        asm("swi")


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
#define CPU_NO_OPERATION()              asm("nop")


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    asm("sei")


/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        asm("cli");                         \
        asm("nop");                         \
    _END_BLOCK

boolean Cpu_InterruptsDisabled(void);

#endif /* __CPRI_H */

