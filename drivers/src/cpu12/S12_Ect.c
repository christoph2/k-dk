
#include "S12_Ect.h"
#include "Hw_Cfg.h"

/*
**
**  todo:   - Timer konfigurieren.
**          - OCs/IC2 konfigurieren.
**          - Modulus-Counter konfigurieren.
**
*/

/*
**
**  todo: Header-Datei, in der die Timer-Prescaler (auch RTI) berechnet werden!!!
**
*/

#define OS_SYSTEM_TIMER_FREQ    ((uint16)1000)        /* todo: nach 'os_config.h' */

void S12Ect_Init(void);

void S12Ect_Init(void)
{
/*
**
**  todo:   Conditionals für die verschiedenen Timer!!!
**          PLL-Initialisierung!!!
**
*/
    
/*  __OS_MS_COUNTER=0L; */
        
        /*  Setup Timer-System. */
/* BYTE_REG(ECT->BaseAddr,     */
    
        BYTE_REG(ECT.BaseAddr,TSCR1)=(uint8)0x00;              /*  Disable-Timer.  */
        
        BYTE_REG(ECT.BaseAddr,TIOS)=IOS0;

        BYTE_REG(ECT.BaseAddr,TCTL1)=(uint8)0x00;
        BYTE_REG(ECT.BaseAddr,TCTL2)=(uint8)0x00;
/*  TIE=C0I;  */
        
        BYTE_REG(ECT.BaseAddr,TSCR2)=/*TOI|*/PR0|PR1;  /*  Hinweis: Prescaler in Abhängigkeit der Taktfrequenz!!!  */
        
        BYTE_REG(ECT.BaseAddr,TFLG1)=(uint8)0xFF;              /*  Clear pending interrupts. */
/*      TC0=TCNT+TICKS_PER_MS;  */
        
        BYTE_REG(ECT.BaseAddr,TSCR1)=TEN|TSFRZ/*|TFFCA*/;      /*  Enable Timer. - zuletzt !!?? */

/*
*       Modulus-Counter Setup.
*/

/*      MCCTL=0x00; */
        BYTE_REG(ECT.BaseAddr,MCCTL)=MCZI|MODMC|MCEN|MCPR1;

        WORD_REG(ECT.BaseAddr,MCCNT)=OS_SYSTEM_TIMER_FREQ/*-1*/;       /*  'TICK_BASE' oder so!? */
        BYTE_REG(ECT.BaseAddr,MCCTL)|=FLMC;    /*  Force Load Register into the Modulus Counter Count Register.  */

        /*  Watchdog aktivieren. */
}
