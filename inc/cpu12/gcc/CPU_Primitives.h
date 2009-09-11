#if !defined(__CPU_PRIMITIVES)
#define __CPU_PRIMITIVES

#if defined(__IAR_SYSTEMS_ICC__)
    #include <intrinsics.h>
#endif  /* __IAR_SYSTEMS_ICC__ */

/*
**	Port-Macros.
*/

/*
**  Powerdown(Wait)-Mode.
*/
#if defined(__IMAGECRAFT__)
#define CPU_POWERDOWN_MODE()            asm("wai")
#elif defined(__HIWARE__)
#define CPU_POWERDOWN_MODE()            __asm wai
#elif defined(__IAR_SYSTEMS_ICC__)
#define CPU_POWERDOWN_MODE()            __wait_for_interrupt()
#elif defined(__CSMC__)
#define CPU_POWERDOWN_MODE()            _asm("wai")
#elif defined(__GNUC__)
#define CPU_POWERDOWN_MODE()            __asm__("wai")
#endif


/*
**  Software-Interrupt.
*/
#if defined(__IMAGECRAFT__)
#define CPU_SOFTWARE_INTERRUPT()        asm("swi")
#elif defined(__HIWARE__)
#define CPU_SOFTWARE_INTERRUPT()        __asm swi
#elif defined(__IAR_SYSTEMS_ICC__)
#define CPU_SOFTWARE_INTERRUPT()        __software_interrupt()
#elif defined(__CSMC__)
#define CPU_SOFTWARE_INTERRUPT()        _asm("swi")
#elif defined(__GNUC__)
#define CPU_SOFTWARE_INTERRUPT()        __asm__("swi")
#endif


/*
**  Return from Interrupt.
*/
#if defined(__IMAGECRAFT__)
#define	CPU_RETURN_FROM_INTERRUPT()     asm("rti")
#elif defined(__HIWARE__)
#define	CPU_RETURN_FROM_INTERRUPT()     __asm rti
#elif defined(__IAR_SYSTEMS_ICC__)
#define	CPU_RETURN_FROM_INTERRUPT()     asm("rti")
#elif defined(__CSMC__)
#define	CPU_RETURN_FROM_INTERRUPT()     _asm("rti")
#elif defined(__GNUC__)
#define CPU_RETURN_FROM_INTERRUPT()     __asm__("rti")
#endif


/*
**  Software-Breakpoint.
*/
#if defined(__IMAGECRAFT__)
#define CPU_BREAKPOINT()                asm("bgnd")
#elif defined(__HIWARE__)
#define CPU_BREAKPOINT()                __asm bgnd
#elif defined(__IAR_SYSTEMS_ICC__)
#define CPU_BREAKPOINT()                asm("bgnd")
#elif defined(__CSMC__)
#define CPU_BREAKPOINT()                _asm("bgnd")
#elif defined(__GNUC__)
#define CPU_BREAKPOINT()                __asm__("bgnd")
#endif


/*
**  No-Operation.
*/
#if defined(__IMAGECRAFT__)
#define CPU_NO_OPERATION()              asm("nop")
#elif defined(__HIWARE__)
#define CPU_NO_OPERATION()              __asm nop
#elif defined(__IAR_SYSTEMS_ICC__)
#define CPU_NO_OPERATION()              asm("nop")
#elif defined(__CSMC__)
#define CPU_NO_OPERATION()              _asm("nop")
#elif defined(__GNUC__)
#define CPU_NO_OPERATION()              __asm__("nop")
#endif


/*
**  Disable All Interrupts.
*/
#if defined(__IMAGECRAFT__)
#define	CPU_DISABLE_ALL_INTERRUPTS()    asm("sei")
#elif defined(__HIWARE__)
#define	CPU_DISABLE_ALL_INTERRUPTS()    __asm sei
#elif defined(__IAR_SYSTEMS_ICC__)
#define	CPU_DISABLE_ALL_INTERRUPTS()    __disable_interrupt()
#elif defined(__CSMC__)
#define	CPU_DISABLE_ALL_INTERRUPTS()    _asm("sei")
#elif defined(__GNUC__)
#define CPU_DISABLE_ALL_INTERRUPTS()    __asm__("sei")
#endif


/*
**  Enable All Interrupts.
*/
#if defined(__IMAGECRAFT__)
#define	CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        asm("cli");                         \
        asm("nop");                         \
    _END_BLOCK
#elif defined(__HIWARE__)
#define	CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        __asm cli;                          \
        __asm nop;                          \
    _END_BLOCK
#elif defined(__IAR_SYSTEMS_ICC__)
#define	CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        __enable_interrupt();               \
        __no_operation();                   \
    _END_BLOCK
#elif defined(__CSMC__)
#define	CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        _asm("cli");                        \
        _asm("nop");                        \
    _END_BLOCK
#elif defined(__GNUC__)
#define	CPU_ENABLE_ALL_INTERRUPTS()         \
    _BEGIN_BLOCK                            \
        __asm__("cli");                     \
        __asm__("nop");                     \
    _END_BLOCK

#endif

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
#if defined(__IAR_SYSTEMS_ICC__)
#define Cpu_InterruptsDisabled()  (((uint8)__get_ccr_register() & ((uint8)0x10))==((uint8)0x10))
#elif defined(__CSMC__)
#define Cpu_InterruptsDisabled()  (((uint8)_asm("tfr ccr,b\n") & ((uint8)0x10))==((uint8)0x10))
#else
boolean Cpu_InterruptsDisabled(void);
#endif

#endif /* __CPU_PRIMITIVES */
