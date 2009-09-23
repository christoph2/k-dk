
#include "S12_Ect.h"
#include "Hw_Cfg.h"

S12Ect_StatusType S12Ect_Init(void)
{
    /* Main Timer Setup */
    S12ECT_REG8(TIOS)=ECT.TIos;
    S12ECT_REG8(TCTL1)=ECT.TCtl1;
    S12ECT_REG8(TCTL2)=ECT.TCtl2;
    S12ECT_REG8(TCTL3)=ECT.TCtl3;
    S12ECT_REG8(TCTL4)=ECT.TCtl4;
    S12ECT_REG8(TIE)=ECT.TIe;
    S12ECT_REG8(ICPAR)=ECT.ICpar;
    
    /* Pulse Accus      */
    S12ECT_REG8(PACTL)=ECT.PActl;
    S12ECT_REG8(PBCTL)=ECT.PBctl;    

    /* Modulus Counter  */
    S12ECT_REG8(MCCTL)=ECT.MCctl;
    S12ECT_REG16(MCCNT)=ECT.MCcnt;

    /* 
    **  ns_per_mhz=1000
    **  cycle=ns_per_mhz/bus_clock
    **  presc=log2(timer_cycle/cycle) (if timer_cycle>cycle)
    */    
    S12ECT_REG8(DLYCT)=ECT.DLyct;
    S12ECT_REG8(ICOVW)=ECT.ICovw;
    S12ECT_REG8(ICSYS)=ECT.ICsys;
    S12ECT_REG8(TFLG1)=(uint8)0xFF;     /*  Clear pending interrupts. */
    S12ECT_REG8(TFLG2)=(uint8)0x80;

    S12ECT_REG8(TSCR2)=ECT.TScr2;
    S12ECT_REG8(TSCR1)=ECT.TScr1;

    return S12ECT_OK;
}
