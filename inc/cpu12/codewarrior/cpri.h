#if !defined(__CPRI_H)
#define __CPRI_H


/*
**  Powerdown(Wait)-Mode.
*/
#elif defined(__HIWARE__)
#define CPU_POWERDOWN_MODE()            __asm wai


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        __asm swi


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     __asm rti


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                __asm bgnd


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              __asm nop


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    __asm sei


/*
**  Enable All Interrupts.
*/  
#define CPU_ENABLE_ALL_INTERRUPTS()     \
    _BEGIN_BLOCK                        \
        __asm cli;                      \
        __asm nop;                      \
    _END_BLOCK


/*
**  Check for Interrupts disabled.
*/
boolean Cpu_InterruptsDisabled(void);

#endif /* __CPRI_H */

