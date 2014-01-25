
    (IISR_IVF)IRQ_VECTOR,       /* IRQ                              */
    (IISR_IVF)XIRQ_VECTOR,      /* XIRQ                             */
    (IISR_IVF)SWI_VECTOR,       /* SWI                              */
    (IISR_IVF)TRAP_VECTOR,      /* Unimplement Intruction Trap      */
    (IISR_IVF)COP_VECTOR,       /* COP failure reset                */
    (IISR_IVF)CMF_VECTOR,       /* Clock monitor fail reset         */
#if !defined(__IAR_SYSTEMS_ICC__)
    (IISR_IVF)RESET_VECTOR,     /* Reset                            */
#endif
