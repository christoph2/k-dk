#if !defined(__CPRI_H)
#define __CPRI_H


/*
**  Powerdown(Wait)-Mode.
*/
#define CPU_POWERDOWN_MODE()            _asm("wai")


/*
**  Software-Interrupt.
*/
#define CPU_SOFTWARE_INTERRUPT()        _asm("swi")


/*
**  Return from Interrupt.
*/
#define CPU_RETURN_FROM_INTERRUPT()     _asm("rti")


/*
**  Software-Breakpoint.
*/
#define CPU_BREAKPOINT()                _asm("bgnd")


/*
**  No-Operation.
*/
#define CPU_NO_OPERATION()              _asm("nop")


/*
**  Disable All Interrupts.
*/
#define CPU_DISABLE_ALL_INTERRUPTS()    _asm("sei")


/*
**  Enable All Interrupts.
*/
#define CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        _asm("cli");                        \
        _asm("nop");                        \
    _END_BLOCK


/*
**
**  COSMIC-Makros
**  --------------
**  #define SWI _asm("swi")
**  #define GET_CCR (unsigned char)(_asm("tfr ccr, b") )
**  #define PUT_CCR(X) (_asm("tfr b,ccr", ((unsigned char)X )) )
*/

/*
**  Check for Interrupts disabled.
*/
#define Cpu_InterruptsDisabled()  (((uint8)_asm("tfr ccr,b\n") & ((uint8)0x10))==((uint8)0x10))

#endif /* __CPRI_H */

