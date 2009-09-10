
#include "S12_Can.h"
#include "Hw_Cfg.h"

/* Parameter according to CiA-DS-102: */

/*
    Speed       NBT     NTQs    L/TQ    Samp.-Pt.   TSEG1   TSEG2   BPR         BTR0    BTR1
    ========================================================================================
    1MBit/s     1µS     8       125ns   6tq         5       2       1           0x01    0x14
    800KBit/s   1,25µS  10      125ns   8tq         7       2       1           0x01    0x16
    500KBit/s   2µS     16      125ns   14tq        13      2       1           0x01    0x1C
    250KBit/s   4µS     16      250ns   14tq        13      2       3           0x03    0x1C
    125KBit/s   8µS     16      500ns   14tq        13      2       7           0x07    0x1C
    50KBit/s    20µS    16      1,25µS  14tq        13      2       19          0x13    0x1C
    20KBit/s    50µS    16      3,125µS 14tq        13      2       49          0x31    0x1C
    10KBit/s    100µS   16      6,25µS  14tq        13      2       99 (n/a)
*/

/*  Speed   NBT         NTQs    L/TQ                                BPR         BTR0    BTR1
    =========================================================================================
    62,5    16µS.       16      1µS     14          13      2       15          0x0F    0x1C
    83,3    12µS.       16      750ns   14          13      2       11          0x0B    0x1C
*/


#define ID_EXTENDED ((uint8)0x08)
#define ID_MASK_11  ((uint32)0x000007FF)
#define ID_MASK_29  ((uint32)0x1FFFFFFF)

enum {
  CAN_SPEED_1000,
  CAN_SPEED_800,
  CAN_SPEED_500,
  CAN_SPEED_250,
  CAN_SPEED_125,
  CAN_SPEED_83,
  CAN_SPEED_62,
  CAN_SPEED_50,
  CAN_SPEED_20
};

/* Bustiming / 16MHz Osc. */
static const S12Can_BusTimingType Can_SpeedTable[]={
    {0x01,0x14},    /* 1MBit/s      */
    {0x01,0x16},    /* 800KBit/s    */
    {0x01,0x1C},    /* 500KBit/s    */
    {0x03,0x1C},    /* 250KBit/s    */
    {0x07,0x1C},    /* 125KBit/s    */
    {0x0B,0x1C},    /* 83,3KBit/s   */
    {0x0F,0x1C},    /* 62,5KBit/s   */
    {0x13,0x1C},    /* 50KBit/s     */
    {0x31,0x1C},    /* 20KBit/s     */
};



/*
todo: Makros für die Filter-Register
====================================
MAKE_|SET_REG[32|16|8]
*/


/* todo: die meisten Funktionen benötigen einen Check auf Init- und Sleep-Mode!!! */

S12Can_StatusType S12Can_Init(S12Can_ConfigType const * const Cfg,uint8 btr0,uint8 btr1)
{
    S12Can_StatusType ret;
    
    ret=S12Can_InitializationMode(Cfg,TRUE);
    if (ret!=S12CAN_OK) {
        return ret;   
    }

    BYTE_REG(Cfg->BaseAddr,CANCTL1)=CANE|LOOPB|WUPM;
    
    (void)S12Can_SetBusTiming(Cfg,btr0,btr1);
    (void)S12Can_SetFilter(Cfg,&Cfg->Filter);

    ret=S12Can_InitializationMode(Cfg,FALSE);
    if (ret!=S12CAN_OK) {
        return ret;   
    }    

    BYTE_REG(Cfg->BaseAddr,CANCTL0)=(CSWAI|TIME|WUPE);
 
    (void)S12Can_EnableInterrupts(Cfg,TRUE);   /* check: dem Anwender überlassen!? */

    return S12CAN_OK;
}



S12Can_StatusType S12Can_EnableInterrupts(S12Can_ConfigType const * const Cfg,boolean enable)
{
    boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);
    if (initializing) {
        return S12CAN_STATE;        
    }
    
    if (enable) {
        /* check: evtl. nur Busoff berücksichtigen??? */
        /* check: oder einen Parameter 'errorLevel' ??? */
        BYTE_REG(Cfg->BaseAddr,CANRIER)=WUPIE|CSCIE|RSTATE0|RSTATE1|TSTATE0|TSTATE1|OVRIE|RXFIE;
/*        BYTE_REG(Cfg->BaseAddr,CANTIER)=TXEIE0|TXEIE1|TXEIE2; */
    } else {
        BYTE_REG(Cfg->BaseAddr,CANRIER)=(uint8)0x00;
        BYTE_REG(Cfg->BaseAddr,CANTIER)=(uint8)0x00;
    }

    return S12CAN_OK;
}

S12Can_StatusType S12Can_Sleeping(S12Can_ConfigType const * const Cfg,boolean *sleeping)
{
    *sleeping=((BYTE_REG(Cfg->BaseAddr,CANCTL1) & SLPAK)==SLPAK);

    return S12CAN_OK;
}

S12Can_StatusType S12Can_Initializing(S12Can_ConfigType const * const Cfg,boolean *initializing)
{
    *initializing=((BYTE_REG(Cfg->BaseAddr,CANCTL1) & INITAK)==INITAK);

    return S12CAN_OK;
}

S12Can_StatusType S12Can_SetBusTiming(S12Can_ConfigType const * const Cfg,uint8 btr0,uint8 btr1)
{
   boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);    
    if (!initializing) {
        return S12CAN_STATE;        
    }    

    BYTE_REG(Cfg->BaseAddr,CANBTR0)=btr0;
    BYTE_REG(Cfg->BaseAddr,CANBTR1)=btr1;

    return S12CAN_OK;
}

S12Can_StatusType S12Can_SetFilter(S12Can_ConfigType const * const Cfg,const S12Can_FilterType *Filter)
{
    boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);    
    if (!initializing) {
        return S12CAN_STATE;        
    }
    
    BYTE_REG(Cfg->BaseAddr,CANIDAC)=Filter->FilterMode;

    BYTE_REG(Cfg->BaseAddr,CANIDAR0)=Filter->IdentifierAcceptance[0];
    BYTE_REG(Cfg->BaseAddr,CANIDAR1)=Filter->IdentifierAcceptance[1];
    BYTE_REG(Cfg->BaseAddr,CANIDAR2)=Filter->IdentifierAcceptance[2];
    BYTE_REG(Cfg->BaseAddr,CANIDAR3)=Filter->IdentifierAcceptance[3];
    BYTE_REG(Cfg->BaseAddr,CANIDAR4)=Filter->IdentifierAcceptance[4];
    BYTE_REG(Cfg->BaseAddr,CANIDAR5)=Filter->IdentifierAcceptance[5];
    BYTE_REG(Cfg->BaseAddr,CANIDAR6)=Filter->IdentifierAcceptance[6];
    BYTE_REG(Cfg->BaseAddr,CANIDAR7)=Filter->IdentifierAcceptance[7];

    BYTE_REG(Cfg->BaseAddr,CANIDMR0)=Filter->IdentifierMask[0];
    BYTE_REG(Cfg->BaseAddr,CANIDMR1)=Filter->IdentifierMask[1];
    BYTE_REG(Cfg->BaseAddr,CANIDMR2)=Filter->IdentifierMask[2];
    BYTE_REG(Cfg->BaseAddr,CANIDMR3)=Filter->IdentifierMask[3];
    BYTE_REG(Cfg->BaseAddr,CANIDMR4)=Filter->IdentifierMask[4];
    BYTE_REG(Cfg->BaseAddr,CANIDMR5)=Filter->IdentifierMask[5];
    BYTE_REG(Cfg->BaseAddr,CANIDMR6)=Filter->IdentifierMask[6];
    BYTE_REG(Cfg->BaseAddr,CANIDMR7)=Filter->IdentifierMask[7];    

    return S12CAN_OK;
}

S12Can_StatusType S12Can_Stop(S12Can_ConfigType const * const Cfg)
{
    /* Funktioniert so nicht!!! */
    (void)S12Can_InitializationMode(Cfg,TRUE);
    BYTE_REG(Cfg->BaseAddr,CANCTL1)&=~CANE; /* only in special system operation modes. */
    BYTE_REG(Cfg->BaseAddr,CANRIER)=(uint8)0x00;
    BYTE_REG(Cfg->BaseAddr,CANTIER)=(uint8)0x00;
    
    return S12CAN_OK;
}


S12Can_StatusType S12Can_InitializationMode(S12Can_ConfigType const * const Cfg,boolean enable)
{
    /*
        The following registers enter their hard reset state and restore their default values:
        CANCTL0, CANRFLG, CANRIER, CANTFLG, CANTIER, CANTARQ,
        CANTAAK, CANTBSEL.
    */
    if (enable) {
        BYTE_REG(Cfg->BaseAddr,CANCTL0)|=INITRQ;
        WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANCTL1) & INITAK)==INITAK);
    } else {
        if (!((BYTE_REG(Cfg->BaseAddr,CANCTL0) & INITRQ) && (BYTE_REG(Cfg->BaseAddr,CANCTL1) & INITAK))) {
            return S12CAN_STATE; /* must be in Initialization Mode. */
        }
        BYTE_REG(Cfg->BaseAddr,CANCTL0)&=~INITRQ;
        WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANCTL1) & INITAK)!=INITAK);
        (void)S12Can_WaitSynch(Cfg);
    }
    return S12CAN_OK;
}

S12Can_StatusType S12Can_SleepMode(S12Can_ConfigType const * const Cfg,boolean enable)
{
    if (enable) {
        BYTE_REG(Cfg->BaseAddr,CANCTL0)|=SLPRQ;
        WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANCTL1) & SLPAK)==SLPAK)

    } else {
        if (!((BYTE_REG(Cfg->BaseAddr,CANCTL0) & SLPRQ) && (BYTE_REG(Cfg->BaseAddr,CANCTL1) & SLPAK))) {
            return S12CAN_STATE; /* must be in Sleep Mode. */
        }
        BYTE_REG(Cfg->BaseAddr,CANCTL0)&=~SLPRQ;
        WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANCTL1) & SLPAK)!=SLPAK);
        (void)S12Can_WaitSynch(Cfg);
    }    
    return S12CAN_OK;
}


S12Can_StatusType S12Can_CancelMessage(S12Can_ConfigType const * const Cfg,uint8 Number)
{
    uint8 Mask;
    boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);
    if (initializing) {
        return S12CAN_STATE;        
    }
    
    if (Number>(uint8)2) {
        return S12CAN_VALUE;
    }

    Mask=(uint8)1<<Number;
    
    if ((BYTE_REG(Cfg->BaseAddr,CANTARQ) & Mask)==Mask) {
        return S12CAN_STATE; /* request already pending. */
    }
    BYTE_REG(Cfg->BaseAddr,CANTARQ)|=Mask;

    WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANTAAK) & Mask)==Mask);   /* check: kann das blockieren??? */
    
    
    return S12CAN_OK;
}

S12Can_StatusType S12Can_Ready(S12Can_ConfigType const * const Cfg,boolean *ready)
{
    *ready=(BYTE_REG(Cfg->BaseAddr,CANTFLG) & (TXE0|TXE1|TXE2)!=(uint8)0x00);

    return S12CAN_OK;
}

S12Can_StatusType S12Can_RxD(S12Can_ConfigType const * const Cfg,boolean *rxd)
{
    *rxd=((BYTE_REG(Cfg->BaseAddr,CANRFLG) & RXF)==RXF);
    
    return S12CAN_OK;
}

S12Can_StatusType S12Can_Transmit(S12Can_ConfigType const * const Cfg,const S12Can_MessageType *Msg,uint8 priority,uint8 *SentOnBuffer)
{
    S12Can_BufferType *TxFG;
    uint8 number_of_buffer;
    boolean ready;
    boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);
    if (initializing) {
        return S12CAN_STATE;        
    }

    if (Msg->DLR>CAN_MAX_LSDU_LEN) {
        return S12CAN_VALUE;
    }

    /* wait for at least one free buffer */
    ready=FALSE;
    while (!ready) {
        (void)S12Can_Ready(Cfg,&ready); 
    }

    TxFG=(S12Can_BufferType*)BYTE_REG(Cfg->BaseAddr,CANTXFG);
    
    BYTE_REG(Cfg->BaseAddr,CANTBSEL)=BYTE_REG(Cfg->BaseAddr,CANTFLG);    /* Select Buffer. */
    number_of_buffer=BYTE_REG(Cfg->BaseAddr,CANTBSEL);

    TxFG->DLR=Msg->DLR;
    TxFG->TBPR=priority;

    /* todo: ID einbauen - Makro für Standard- und Extended-Identifier!!! */
    if (Msg->ExtendedID) {
/* todo: Implementieren!!! */
        if (Msg->RTR) {
            TxFG->IDR1|=(uint8)0x10;
        }
    } else {
        TxFG->IDR0=(uint8)(Msg->ID & (uint32)0x07FF)>>3;
        TxFG->IDR1=(uint8)(Msg->ID & (uint32)0x0007)<<5;
        if (Msg->RTR) {
            TxFG->IDR3|=(uint8)0x01;
        }
    }

    if ((Msg->DLR) && (!Msg->RTR)) {
        Utl_MemCopy((void*)&TxFG->DSR0,(void*)Msg->SDU,(uint16)Msg->DLR);
    }

    if (SentOnBuffer!=(uint8)NULL) {
        *SentOnBuffer=number_of_buffer;
    }

    BYTE_REG(Cfg->BaseAddr,CANTFLG)=number_of_buffer;   /* Send Buffer. */  
    
    return S12CAN_OK;
}

S12Can_StatusType S12Can_CopyRxBuffer(S12Can_ConfigType const * const Cfg,S12Can_MessageType *Msg)
{
    S12Can_BufferType *RxFG;
    uint32 ID;
    boolean ExtendedID;
    boolean RTR;
    boolean initializing;
    
    (void)S12Can_Initializing(Cfg,&initializing);
    if (initializing) {
        return S12CAN_STATE;        
    }

    if (!(BYTE_REG(Cfg->BaseAddr,CANRFLG) & RXF)) {
        return S12CAN_STATE;   /* Foreground receive buffer is empty. */
    }
    
    RxFG=(S12Can_BufferType*)BYTE_REG(Cfg->BaseAddr,CANRXFG);
    Msg->DLR=RxFG->DLR;

    ExtendedID=((RxFG->IDR1 & ID_EXTENDED)==ID_EXTENDED);
    Msg->ExtendedID=ExtendedID;

    if (ExtendedID) {
        RTR=((RxFG->IDR3 & (uint8)0x01)==(uint8)0x01);
        ID=(((uint32)RxFG->IDR0) << 21) | (((uint32)(RxFG->IDR1 & 0xe0)) << 18) |
           (((uint32)(RxFG->IDR1 & 0x07)) << 15) | (((uint32)RxFG->IDR2) << 7) | 
           (((uint32)(RxFG->IDR3 & 0xfe)) >> 1);

    } else {
        RTR=((RxFG->IDR1 & (uint8)0x10)==(uint8)0x10);
        ID=(uint32)(RxFG->IDR0 << (uint8)3) | (RxFG->IDR1 >> (uint8)5);
    }

    Msg->ID=ID;
    Msg->RTR=RTR;
    
    if (!RTR && (Msg->DLR)) {
        Utl_MemCopy((void*)Msg->SDU,(void*)&RxFG->DSR0,(uint16)Msg->DLR);
    }    
    

    BYTE_REG(Cfg->BaseAddr,CANRFLG)=RXF;  /* clear receive buffer full flag. */

    return S12CAN_OK;
}

S12Can_StatusType S12Can_GetErrorCounters(S12Can_ConfigType const * const Cfg,uint8 *RxErrors,uint8 *TxErrors)
{
    /* Hinweis: Funktioniert nur im Sleep- oder Init-Mode!!! */
    *RxErrors=BYTE_REG(Cfg->BaseAddr,CANRXERR);
    *TxErrors=BYTE_REG(Cfg->BaseAddr,CANTXERR);

    return S12CAN_OK;
}

S12Can_StatusType S12Can_WaitSynch(S12Can_ConfigType const * const Cfg)
{
    WAIT_FOR((BYTE_REG(Cfg->BaseAddr,CANCTL0) & SYNCH)==SYNCH);
    
    BYTE_REG(Cfg->BaseAddr,CANRFLG)=WUPIF|CSCIF|OVRIF|RXF;
    
    return S12CAN_OK;
}

/*
**
** Interrupt-Handler.
**
*/
ISR1(CAN0TxVector)
{
    BYTE_REG(CAN0.BaseAddr,CANTFLG)=(uint8)TXE2|TXE1|TXE0;
}

S12Can_MessageType Msg;

ISR1(CAN0RxVector)
{    
/*** TEST ***/
    S12Can_StatusType ret;
    ret=S12Can_CopyRxBuffer(CAN0,&Msg);
/*** TEST ***/        
        
    /* If Vector: call, else clear flag (???). */    
    BYTE_REG(CAN0.BaseAddr,CANRFLG)=RXF;
}

ISR1(CAN0ErrorVector)
{
    uint8 rflags;
    uint8 state;
 
    rflags=BYTE_REG(CAN0.BaseAddr,CANRFLG);
    
    if ((rflags & CSCIF)==CSCIF) {
        state=rflags & (RSTAT1|RSTAT0|TSTAT1|TSTAT0);
        
        if (((state & S12CAN_RSTAT_BUSOFF)==S12CAN_RSTAT_BUSOFF) || ((state & S12CAN_TSTAT_BUSOFF)==S12CAN_TSTAT_BUSOFF)) {
/* todo: Busoff-Callout, wenn konfiguriert.*/   
        }
        BYTE_REG(CAN0.BaseAddr,CANRFLG)=CSCIF;
    } else if ((rflags & OVRIF)==OVRIF) {
/* todo: Overflow-Vector, falls konfiguriert!!! */        
        BYTE_REG(CAN0.BaseAddr,CANRFLG)=OVRIF;
    }
}

ISR1(CAN0WakupVector)
{
    BYTE_REG(CAN0.BaseAddr,CANRFLG)=WUPIF;
}
