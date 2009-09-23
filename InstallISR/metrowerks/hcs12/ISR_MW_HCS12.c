/*
**
**       Interrupt-Vektoren S12DP256.
**
*/

#include "ISR.h"

#if     !defined(RESET_VECTOR)
#define RESET_VECTOR    IISR_ENTRY_POINT
#endif  /*  RESET_VECTOR */

#if     !defined(CMF_VECTOR)
#define CMF_VECTOR      IISR_ENTRY_POINT
#endif  /*  CMF_VECTOR  */

#if     !defined(COP_VECTOR)
#define COP_VECTOR      IISR_ENTRY_POINT
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

static ISR1(DUMMY_VECTOR)
{       
}

/*  void (*interrupt_vectors[])(void) @0xFF80 = */
#pragma CONST_SEG VECTORS
void (*const interrupt_vectors[])(void) = 
{
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF80                   */
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF82                   */
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF84                   */
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF86                   */
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF88                   */
    (IISR_IVF)DUMMY_VECTOR,      /* Reserved $FF8A                   */
    (IISR_IVF)PWMES_VECTOR,      /* PWM Emergency Shutdown           */
    (IISR_IVF)PP_VECTOR,         /* Port P Interrupt                 */
    (IISR_IVF)CAN4T_VECTOR,      /* MSCAN 4 Transmit                 */
    (IISR_IVF)CAN4R_VECTOR,      /* MSCAN 4 Receive                  */
    (IISR_IVF)CAN4E_VECTOR,      /* MSCAN 4 Error                    */
    (IISR_IVF)CAN4W_VECTOR,      /* MSCAN 4 Wake-up                  */
    (IISR_IVF)CAN3T_VECTOR,      /* MSCAN 3 Transmit                 */
    (IISR_IVF)CAN3R_VECTOR,      /* MSCAN 3 Receive                  */
    (IISR_IVF)CAN3E_VECTOR,      /* MSCAN 3 Error                    */
    (IISR_IVF)CAN3E_VECTOR,      /* MSCAN 3 Wake-up                  */
    (IISR_IVF)CAN2T_VECTOR,      /* MSCAN 2 Transmit                 */
    (IISR_IVF)CAN2R_VECTOR,      /* MSCAN 2 Receive                  */
    (IISR_IVF)CAN2E_VECTOR,      /* MSCAN 2 Error                    */
    (IISR_IVF)CAN2W_VECTOR,      /* MSCAN 2 Wake-up                  */
    (IISR_IVF)CAN1T_VECTOR,      /* MSCAN 1 Transmit                 */
    (IISR_IVF)CAN1R_VECTOR,      /* MSCAN 1 Receive                  */
    (IISR_IVF)CAN1E_VECTOR,      /* MSCAN 1 Error                    */
    (IISR_IVF)CAN1W_VECTOR,      /* MSCAN 1 Wake-up                  */
    (IISR_IVF)CAN0T_VECTOR,      /* MSCAN 0 Transmit                 */
    (IISR_IVF)CAN0R_VECTOR,      /* MSCAN 0 Receive                  */
    (IISR_IVF)CAN0E_VECTOR,      /* MSCAN 0 Error                    */
    (IISR_IVF)CAN0W_VECTOR,      /* MSCAN 0 Wake-up                  */
    (IISR_IVF)FLS_VECTOR,        /* Flash                            */
    (IISR_IVF)EEP_VECTOR,        /* EEPROM                           */
    (IISR_IVF)SPI2_VECTOR,       /* SPI2                             */
    (IISR_IVF)SPI1_VECTOR,       /* SPI1                             */
    (IISR_IVF)IIC_VECTOR,        /* IIC Bus                          */
    (IISR_IVF)DLC_VECTOR,        /* DLC                              */
    (IISR_IVF)SCME_VECTOR,       /* SCME                             */
    (IISR_IVF)CRG_VECTOR,        /* CRG Lock                         */
    (IISR_IVF)PBOF_VECTOR,       /* Pulse Accumulator B Overflow     */
    (IISR_IVF)MDCU_VECTOR,       /* Modulus Down Counter Underflow   */
    (IISR_IVF)PH_VECTOR,         /* Port H Interrupt                 */
    (IISR_IVF)PJ_VECTOR,         /* Port J Interrupt                 */
    (IISR_IVF)ATD1_VECTOR,       /* ATD1                             */
    (IISR_IVF)ATD0_VECTOR,       /* ATD0                             */
    (IISR_IVF)SCI1_VECTOR,       /* SCI1                             */
    (IISR_IVF)SCI0_VECTOR,       /* SCI0                             */
    (IISR_IVF)SPI0_VECTOR,       /* SPI0                             */
    (IISR_IVF)PAIE_VECTOR,       /* Pulse Accumulator A Input Edge   */
    (IISR_IVF)PAOF_VECTOR,       /* Pulse Accumulator A Overflow     */
    (IISR_IVF)TOF_VECTOR,        /* Timer Overflow                   */
    (IISR_IVF)TC7_VECTOR,        /* Timer Channel 7                  */
    (IISR_IVF)TC6_VECTOR,        /* Timer Channel 6                  */
    (IISR_IVF)TC5_VECTOR,        /* Timer Channel 5                  */
    (IISR_IVF)TC4_VECTOR,        /* Timer Channel 4                  */
    (IISR_IVF)TC3_VECTOR,        /* Timer Channel 3                  */
    (IISR_IVF)TC2_VECTOR,        /* Timer Channel 2                  */
    (IISR_IVF)TC1_VECTOR,        /* Timer Channel 1                  */
    (IISR_IVF)TC0_VECTOR,        /* Timer Channel 0                  */
    (IISR_IVF)RTI_VECTOR,        /* Real Time Interrupt              */
    (IISR_IVF)IRQ_VECTOR,        /* IRQ                              */
    (IISR_IVF)XIRQ_VECTOR,       /* XIRQ                             */
    (IISR_IVF)SWI_VECTOR,        /* SWI                              */
    (IISR_IVF)TRAP_VECTOR,       /* Unimplement Intruction Trap      */
    (IISR_IVF)COP_VECTOR,        /* COP failure reset                */
    (IISR_IVF)CMF_VECTOR,        /* Clock monitor fail reset         */
    (IISR_IVF)RESET_VECTOR,      /* Reset                            */
};

#pragma CONST_SEG DEFAULT

