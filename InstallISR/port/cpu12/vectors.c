/*
**
**       Interrupt-Vektoren S12DP256.
**
*/

/*
 *
 * todo: Makros 'BEGIN_INTERRUPT_VECTOR_TABLE()' und 'END_INTERRUPT_VECTOR_TABLE()'!
 *
 */

#include "vectors.h"

#if     !defined(RESET_VECTOR)
#define RESET_VECTOR    II_ENTRY_POINT
#endif  /*  RESET_VECTOR */

#if     !defined(CMF_VECTOR)
#define CMF_VECTOR      II_ENTRY_POINT
#endif  /*  CMF_VECTOR  */

#if     !defined(COP_VECTOR)
#define COP_VECTOR      II_ENTRY_POINT
#endif  /*  COP_VECTOR  */

#if     !defined(TRAP_VECTOR)
#define TRAP_VECTOR DUMMY_VECTOR
#endif  /*  TRAP_VECTOR */

#if     !defined(SWI_VECTOR)
#define SWI_VECTOR DUMMY_VECTOR
#endif  /*  SWI_VECTOR  */

#if     !defined(XIRQ_VECTOR)
#define XIRQ_VECTOR DUMMY_VECTOR
#endif  /*  XIRQ_VECTOR */

#if     !defined(IRQ_VECTOR)
#define IRQ_VECTOR DUMMY_VECTOR
#endif  /*  IRQ_VECTOR  */

#if     !defined(RTI_VECTOR)
#define RTI_VECTOR DUMMY_VECTOR
#endif  /*  RTI_VECTOR  */

#if     !defined(TC0_VECTOR)
#define TC0_VECTOR DUMMY_VECTOR
#endif  /*  TC0_VECTOR  */

#if     !defined(TC1_VECTOR)
#define TC1_VECTOR DUMMY_VECTOR
#endif  /*  TC1_VECTOR  */

#if     !defined(TC2_VECTOR)
#define TC2_VECTOR DUMMY_VECTOR
#endif  /*  TC2_VECTOR  */

#if     !defined(TC3_VECTOR)
#define TC3_VECTOR DUMMY_VECTOR
#endif  /*  TC3_VECTOR  */

#if     !defined(TC4_VECTOR)
#define TC4_VECTOR DUMMY_VECTOR
#endif  /*  TC4_VECTOR  */

#if     !defined(TC5_VECTOR)
#define TC5_VECTOR DUMMY_VECTOR
#endif  /*  TC5_VECTOR  */

#if     !defined(TC6_VECTOR)
#define TC6_VECTOR DUMMY_VECTOR
#endif  /*  TC6_VECTOR  */

#if     !defined(TC7_VECTOR)
#define TC7_VECTOR DUMMY_VECTOR
#endif  /*  TC7_VECTOR  */

#if     !defined(TOF_VECTOR)
#define TOF_VECTOR DUMMY_VECTOR
#endif  /*  TOF_VECTOR  */

#if     !defined(PAOF_VECTOR)
#define PAOF_VECTOR DUMMY_VECTOR
#endif  /*  PAOF_VECTOR */

#if     !defined(PAIE_VECTOR)
#define PAIE_VECTOR DUMMY_VECTOR
#endif  /*  PAIE_VECTOR */

#if     !defined(SPI0_VECTOR)
#define SPI0_VECTOR DUMMY_VECTOR
#endif  /*  SPI0_VECTOR */

#if     !defined(SCI0_VECTOR)
#define SCI0_VECTOR DUMMY_VECTOR
#endif  /*  SCI0_VECTOR */

#if     !defined(SCI1_VECTOR)
#define SCI1_VECTOR DUMMY_VECTOR
#endif  /*  SCI1_VECTOR */

#if     !defined(ATD0_VECTOR)
#define ATD0_VECTOR DUMMY_VECTOR
#endif  /*  ATD0_VECTOR */
        
#if     !defined(ATD1_VECTOR)
#define ATD1_VECTOR DUMMY_VECTOR
#endif  /*  ATD1_VECTOR */
        
#if     !defined(PJ_VECTOR)
#define PJ_VECTOR DUMMY_VECTOR
#endif  /*  PJ_VECTOR */

#if     !defined(PH_VECTOR)
#define PH_VECTOR DUMMY_VECTOR
#endif  /*  PH_VECTOR */

#if     !defined(MDCU_VECTOR)
#define MDCU_VECTOR     DUMMY_VECTOR
#endif  /*  MDCU_VECTOR */

#if     !defined(PBOF_VECTOR)
#define PBOF_VECTOR DUMMY_VECTOR
#endif  /*  PBOF_VECTOR */

#if     !defined(CRG_VECTOR)
#define CRG_VECTOR DUMMY_VECTOR
#endif  /*  CRG_VECTOR  */

#if     !defined(SCME_VECTOR)
#define SCME_VECTOR DUMMY_VECTOR
#endif  /*  SCME_VECTOR */

#if     !defined(DLC_VECTOR)
#define DLC_VECTOR DUMMY_VECTOR
#endif  /*  DLC_VECTOR  */

#if     !defined(IIC_VECTOR)
#define IIC_VECTOR DUMMY_VECTOR
#endif  /*  IIC_VECTOR  */

#if     !defined(SPI1_VECTOR)
#define SPI1_VECTOR DUMMY_VECTOR
#endif  /*  SPI1_VECTOR */

#if     !defined(SPI2_VECTOR)
#define SPI2_VECTOR DUMMY_VECTOR
#endif  /*  SPI2_VECTOR */

#if     !defined(EEP_VECTOR)
#define EEP_VECTOR DUMMY_VECTOR
#endif  /*  EEP_VECTOR  */
                        
#if     !defined(FLS_VECTOR)
#define FLS_VECTOR DUMMY_VECTOR
#endif  /*  FLS_VECTOR  */
                
#if     !defined(CAN0W_VECTOR)
#define CAN0W_VECTOR DUMMY_VECTOR
#endif  /*  CAN0W_VECTOR  */

#if     !defined(CAN0E_VECTOR)
#define CAN0E_VECTOR DUMMY_VECTOR
#endif  /*  CAN0E_VECTOR  */

#if     !defined(CAN0R_VECTOR)
#define CAN0R_VECTOR DUMMY_VECTOR
#endif  /*  CAN0R_VECTOR  */

#if     !defined(CAN0T_VECTOR)
#define CAN0T_VECTOR DUMMY_VECTOR
#endif  /*  CAN0T_VECTOR  */

#if     !defined(CAN1W_VECTOR)
#define CAN1W_VECTOR DUMMY_VECTOR
#endif  /*  CAN1W_VECTOR  */

#if     !defined(CAN1E_VECTOR)
#define CAN1E_VECTOR DUMMY_VECTOR
#endif  /*  CAN1E_VECTOR  */

#if     !defined(CAN1R_VECTOR)
#define CAN1R_VECTOR DUMMY_VECTOR
#endif  /*  CAN1R_VECTOR  */

#if     !defined(CAN1T_VECTOR)
#define CAN1T_VECTOR DUMMY_VECTOR
#endif  /*  CAN1T_VECTOR  */

#if     !defined(CAN2W_VECTOR)
#define CAN2W_VECTOR DUMMY_VECTOR
#endif  /*  CAN2W_VECTOR  */

#if     !defined(CAN2E_VECTOR)
#define CAN2E_VECTOR DUMMY_VECTOR
#endif  /*  CAN2E_VECTOR  */

#if     !defined(CAN2R_VECTOR)
#define CAN2R_VECTOR DUMMY_VECTOR
#endif  /*  CAN2R_VECTOR  */

#if     !defined(CAN2T_VECTOR)
#define CAN2T_VECTOR DUMMY_VECTOR
#endif  /*  CAN2T_VECTOR  */

#if     !defined(CAN3W_VECTOR)
#define CAN3W_VECTOR DUMMY_VECTOR
#endif  /*  CAN3W_VECTOR  */

#if     !defined(CAN3E_VECTOR)
#define CAN3E_VECTOR DUMMY_VECTOR
#endif  /*  CAN3E_VECTOR  */

#if     !defined(CAN3R_VECTOR)
#define CAN3R_VECTOR DUMMY_VECTOR
#endif  /*  CAN3R_VECTOR  */

#if     !defined(CAN3T_VECTOR)
#define CAN3T_VECTOR DUMMY_VECTOR
#endif  /*  CAN3T_VECTOR  */

#if     !defined(CAN4W_VECTOR)
#define CAN4W_VECTOR DUMMY_VECTOR
#endif  /*  CAN4W_VECTOR  */

#if     !defined(CAN4E_VECTOR)
#define CAN4E_VECTOR DUMMY_VECTOR
#endif  /*  CAN4E_VECTOR  */

#if     !defined(CAN4R_VECTOR)
#define CAN4R_VECTOR DUMMY_VECTOR
#endif  /*  CAN4R_VECTOR  */

#if     !defined(CAN4T_VECTOR)
#define CAN4T_VECTOR DUMMY_VECTOR
#endif  /*  CAN4T_VECTOR  */

#if     !defined(PP_VECTOR)
#define PP_VECTOR DUMMY_VECTOR
#endif  /*  PP_VECTOR */

#if     !defined(PWMES_VECTOR)
#define PWMES_VECTOR DUMMY_VECTOR
#endif  /*  PWMES_VECTOR  */

#if 0
#if defined(__IMAGECRAFT__)
#pragma interrupt_handler DUMMY_VECTOR
#elif defined(__HIWARE__)
#pragma TRAP_PROC
#elif defined(__IAR_SYSTEMS_ICC__)
__interrupt
#elif defined (__CSMC__)
@interrupt 
#endif
#endif

static ISR(DUMMY_VECTOR)
{       
}

#if defined(__IMAGECRAFT__)

#pragma abs_address:0xFF80
void (*const interrupt_vectors[])(void) =

#elif defined(__HIWARE__)

/*  void (*interrupt_vectors[])(void) @0xFF80 = */
#pragma CONST_SEG VECTORS
void (*const interrupt_vectors[])(void) = 

#elif defined(__CSMC__)

#if 0
#pragma section const {vector}
#endif

/*      vector table to be located at address 0xFF80 */
@interrupt void (*const interrupt_vectors[])(void) =

/* @interrupt @near void (* const _vectab[])(void) = { */

#elif defined(__IAR_SYSTEMS_ICC__)

 #pragma constseg=INTVEC

#if 0
#pragma location=0xFF80
#endif

#pragma required=interrupt_vectors

__root void (* const interrupt_vectors[])(void) =

#elif defined(__GNUC__)
void (*const interrupt_vectors[])(void) __attribute__((section(".vectors"))) = 
#endif 
{
    (IVF)DUMMY_VECTOR,      /* Reserved $FF80                   */
    (IVF)DUMMY_VECTOR,      /* Reserved $FF82                   */
    (IVF)DUMMY_VECTOR,      /* Reserved $FF84                   */
    (IVF)DUMMY_VECTOR,      /* Reserved $FF86                   */
    (IVF)DUMMY_VECTOR,      /* Reserved $FF88                   */
    (IVF)DUMMY_VECTOR,      /* Reserved $FF8A                   */
    (IVF)PWMES_VECTOR,      /* PWM Emergency Shutdown           */
    (IVF)PP_VECTOR,         /* Port P Interrupt                 */
    (IVF)CAN4T_VECTOR,      /* MSCAN 4 Transmit                 */
    (IVF)CAN4R_VECTOR,      /* MSCAN 4 Receive                  */
    (IVF)CAN4E_VECTOR,      /* MSCAN 4 Error                    */
    (IVF)CAN4W_VECTOR,      /* MSCAN 4 Wake-up                  */
    (IVF)CAN3T_VECTOR,      /* MSCAN 3 Transmit                 */
    (IVF)CAN3R_VECTOR,      /* MSCAN 3 Receive                  */
    (IVF)CAN3E_VECTOR,      /* MSCAN 3 Error                    */
    (IVF)CAN3E_VECTOR,      /* MSCAN 3 Wake-up                  */
    (IVF)CAN2T_VECTOR,      /* MSCAN 2 Transmit                 */
    (IVF)CAN2R_VECTOR,      /* MSCAN 2 Receive                  */
    (IVF)CAN2E_VECTOR,      /* MSCAN 2 Error                    */
    (IVF)CAN2W_VECTOR,      /* MSCAN 2 Wake-up                  */
    (IVF)CAN1T_VECTOR,      /* MSCAN 1 Transmit                 */
    (IVF)CAN1R_VECTOR,      /* MSCAN 1 Receive                  */
    (IVF)CAN1E_VECTOR,      /* MSCAN 1 Error                    */
    (IVF)CAN1W_VECTOR,      /* MSCAN 1 Wake-up                  */
    (IVF)CAN0T_VECTOR,      /* MSCAN 0 Transmit                 */
    (IVF)CAN0R_VECTOR,      /* MSCAN 0 Receive                  */
    (IVF)CAN0E_VECTOR,      /* MSCAN 0 Error                    */
    (IVF)CAN0W_VECTOR,      /* MSCAN 0 Wake-up                  */
    (IVF)FLS_VECTOR,        /* Flash                            */
    (IVF)EEP_VECTOR,        /* EEPROM                           */
    (IVF)SPI2_VECTOR,       /* SPI2                             */
    (IVF)SPI1_VECTOR,       /* SPI1                             */
    (IVF)IIC_VECTOR,        /* IIC Bus                          */
    (IVF)DLC_VECTOR,        /* DLC                              */
    (IVF)SCME_VECTOR,       /* SCME                             */
    (IVF)CRG_VECTOR,        /* CRG Lock                         */
    (IVF)PBOF_VECTOR,       /* Pulse Accumulator B Overflow     */
    (IVF)MDCU_VECTOR,       /* Modulus Down Counter Underflow   */
    (IVF)PH_VECTOR,         /* Port H Interrupt                 */
    (IVF)PJ_VECTOR,         /* Port J Interrupt                 */
    (IVF)ATD1_VECTOR,       /* ATD1                             */
    (IVF)ATD0_VECTOR,       /* ATD0                             */
    (IVF)SCI1_VECTOR,       /* SCI1                             */
    (IVF)SCI0_VECTOR,       /* SCI0                             */
    (IVF)SPI0_VECTOR,       /* SPI0                             */
    (IVF)PAIE_VECTOR,       /* Pulse Accumulator A Input Edge   */
    (IVF)PAOF_VECTOR,       /* Pulse Accumulator A Overflow     */
    (IVF)TOF_VECTOR,        /* Timer Overflow                   */
    (IVF)TC7_VECTOR,        /* Timer Channel 7                  */
    (IVF)TC6_VECTOR,        /* Timer Channel 6                  */
    (IVF)TC5_VECTOR,        /* Timer Channel 5                  */
    (IVF)TC4_VECTOR,        /* Timer Channel 4                  */
    (IVF)TC3_VECTOR,        /* Timer Channel 3                  */
    (IVF)TC2_VECTOR,        /* Timer Channel 2                  */
    (IVF)TC1_VECTOR,        /* Timer Channel 1                  */
    (IVF)TC0_VECTOR,        /* Timer Channel 0                  */
    (IVF)RTI_VECTOR,        /* Real Time Interrupt              */
    (IVF)IRQ_VECTOR,        /* IRQ                              */
    (IVF)XIRQ_VECTOR,       /* XIRQ                             */
    (IVF)SWI_VECTOR,        /* SWI                              */
    (IVF)TRAP_VECTOR,       /* Unimplement Intruction Trap      */
    (IVF)COP_VECTOR,        /* COP failure reset                */
    (IVF)CMF_VECTOR,        /* Clock monitor fail reset         */
#if !defined(__IAR_SYSTEMS_ICC__)       
    (IVF)RESET_VECTOR,      /* Reset                            */
#endif        
};
#if defined(__IMAGECRAFT__)    
#pragma end_abs_address
#elif defined(__HIWARE__)
#pragma CONST_SEG DEFAULT
#elif defined(__CSMC__)
#pragma section const {}
#elif defined(__IAR_SYSTEMS_ICC__)
/*****/
#endif

