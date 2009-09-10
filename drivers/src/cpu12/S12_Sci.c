
#include "S12_Sci.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES
**
**  S12SCIV3 - HCS12 SERIAL COMMUNICATIONS INTERFACE (SCI) BLOCK GUIDE
**
*/

#define	SCI_FIXED_PRESCALER ((uint8)16)
#define SCI_INTR_MSK        RIE         /* do not enable Transmit-Interrupt(TIE)!!! */

static uint16 SCI_CalculateBaudratePrescaler(uint32 br);


S12Sci_StatusType SCI_Init(S12Sci_ConfigType const * const Cfg)   /* todo: Baudrate und Interrupts als Parameter. */
{        
    BYTE_REG(Cfg->BaseAddr,SCICR2)=((uint8)0x00);    /* Schnittstelle deaktivieren - check!!! */
        
    SCI_SetFormat(Cfg,Cfg->BaudRate,Cfg->Parity,Cfg->NBits);
    BYTE_REG(Cfg->BaseAddr,SCISR2)=(BRK13);


    SCI_SetRxBuffer(Cfg,Cfg->RxBufAddr,Cfg->RxBufLength);
    SCI_RxBufFlush(Cfg);

    SCI_SetTxBuffer(Cfg,(uint8*)NULL,(uint8)0);
    SCI_TxBufFlush(Cfg);

    BYTE_REG(Cfg->BaseAddr,SCICR1)=((uint8)0x00);
    BYTE_REG(Cfg->BaseAddr,SCICR2)=(TE|RE);

    SCI_EnableInterrupts(Cfg,FALSE);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_EnableInterrupts(S12Sci_ConfigType const * const Cfg,boolean ena)
{
    uint8 ch;   
    
    if (ena==TRUE) {
        ch=BYTE_REG(Cfg->BaseAddr,SCIDRL);
        BYTE_REG(Cfg->BaseAddr,SCICR2)|=SCI_INTR_MSK;
    } else {
        BYTE_REG(Cfg->BaseAddr,SCICR2)&=~SCI_INTR_MSK;
    }
    
    return S12SCI_OK;
}


S12Sci_StatusType SCI_SetBaud(S12Sci_ConfigType const * const Cfg,uint32 baud)
{    
    WORD_REG(Cfg->BaseAddr,SCIBD)=SCI_CalculateBaudratePrescaler(baud);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_SetFormat(S12Sci_ConfigType const * const Cfg,uint32 baudrate,uint8 parity,uint8 nbits)
{
    uint8 set_msk=(uint8)0,clr_msk=(uint8)0;
    uint8 ch;    
    /* todo: Aktuelle Konfiguration sichern!!! */
    
    WORD_REG(Cfg->BaseAddr,SCIBD)=SCI_CalculateBaudratePrescaler(baudrate);
        
    if (parity>SCI_PARITY_EVEN) {
        parity=SCI_PARITY_NONE;
    }

    if ((nbits<((uint8)7)) || (nbits>((uint8)8))) {
        nbits=((uint8)8);
    }
        
    if (nbits==((uint8)8)) {
        switch  (parity) {
            case SCI_PARITY_NONE:
                clr_msk=(M|PE);
                set_msk=(uint8)0x00;
                break;
            case SCI_PARITY_ODD:
                clr_msk=(uint8)0x00;
                set_msk=(M|PE|PT);
                break;
            case SCI_PARITY_EVEN:
                clr_msk=PT;
                set_msk=(M|PE);
                break;
            default:
                ASSERT(FALSE);
              break;
        }
    } else {
        switch  (parity) {
            case SCI_PARITY_ODD:
                clr_msk=M;
                set_msk=(PE|PT);
                break;
            case SCI_PARITY_NONE:       /* invalid format. */
            case SCI_PARITY_EVEN:
                clr_msk=(M|PT);
                set_msk=PE;
                break;
            default:
                ASSERT(FALSE);
              break;
        }
    }
    BYTE_REG(Cfg->BaseAddr,SCICR1)&=~(clr_msk);
    BYTE_REG(Cfg->BaseAddr,SCICR1)|=set_msk;
    
    ch=BYTE_REG(Cfg->BaseAddr,SCIDRL);    /* clear spurious interrupts. */
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_SetRxBuffer(S12Sci_ConfigType const * const Cfg,uint8 *buf,uint8 len)
{   
    Cfg->Vars->RxBufAddr=buf;
    Cfg->Vars->RxBufLength=len;
    SCI_RxBufFlush(Cfg);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_SetTxBuffer(S12Sci_ConfigType const * const Cfg,uint8 *buf,uint8 len)
{    
    Cfg->Vars->TxBufAddr=buf;
    Cfg->Vars->TxBufLength=len;
    SCI_TxBufFlush(Cfg);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_Get(S12Sci_ConfigType const * const Cfg,uint8 *ch)
{    
    WAIT_FOR(((BYTE_REG(Cfg->BaseAddr,SCISR1)) & RDRF)!=((uint8)0x00));

    *ch=BYTE_REG(Cfg->BaseAddr,SCIDRL);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_Put(S12Sci_ConfigType const * const Cfg,uint8 ch)
{    
    WAIT_FOR(((BYTE_REG(Cfg->BaseAddr,SCISR1)) & TDRE)!=((uint8)0x00));
    BYTE_REG(Cfg->BaseAddr,SCIDRL)=ch;
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_PutString(S12Sci_ConfigType const * const Cfg,uint8 *str)
{    
    uint8 ch;
   
    while ((ch=*str++)!=NULL) {
        SCI_Put(Cfg,ch);
    }
    
    return S12SCI_OK;
}

/* void SCI_PutString(uint16 base,char *str,uint8 max_len) */

S12Sci_StatusType SCI_SendBreak(S12Sci_ConfigType const * const Cfg)
{    
    BYTE_REG(Cfg->BaseAddr,SCICR2)|=SBK;

    CPU_NO_OPERATION();

    BYTE_REG(Cfg->BaseAddr,SCICR2)&=~SBK;
    
    return S12SCI_OK;
}

/*! \fn SCITxSendBuffer
 *      <param name="base"></param>
 *      <param name="Vars"></param>
 *      <param name="buf"></param>
 *      <param name="len"></param>
 *
 * <remarks>Der Aufrufer hat Sorge zu tragen,
 *      das der vorherige Transfer abgeschlossen wurde
 *  s. #SCITxReady. </remarks>
 *
 */
S12Sci_StatusType SCI_SendBuffer(S12Sci_ConfigType const * const Cfg,uint8 *buf,uint8 len)
{    
    if (len) {

        WAIT_FOR(SCI_TxReady(Cfg));

        if (len==((uint8)1)) {
            SCI_Put(Cfg,buf[0]);               
        } else {
            Cfg->Vars->TxBufLength=len;
            Cfg->Vars->TxBufAddr=buf;
            Cfg->Vars->TxBufPtr=((uint8)1);
            BYTE_REG(Cfg->BaseAddr,SCIDRL)=buf[0];
            BYTE_REG(Cfg->BaseAddr,SCICR2)|=SCTIE;
        }
    }
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_RxBufGetCh(S12Sci_ConfigType const * const Cfg,uint8 *ch)
{    
    if (SCI_RxBufIsEmpty(Cfg)==S12SCI_OK) {
        return S12SCI_STATE;    /* check: geht das nicht sinnvoller??? */
    }
        
    *ch=Cfg->Vars->RxBufAddr[Cfg->Vars->RxHead++];
        
    if (Cfg->Vars->RxHead>=Cfg->Vars->RxBufLength) {
        Cfg->Vars->RxHead=((uint8)0x00);
    }                                           
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_RxBufIsEmpty(S12Sci_ConfigType const * const Cfg)    /* todo: Überarbeiten!!! */
{
    uint8 h,t;
    
    t=Cfg->Vars->RxTail;
    h=Cfg->Vars->RxHead;
    
    if (t==h) {
        return S12SCI_OK;
    } else {
        return S12SCI_STATE;
    }        
}

S12Sci_StatusType SCI_RxBufFlush(S12Sci_ConfigType const * const Cfg)
{    
    Utl_MemSet((void*)Cfg->Vars->RxBufAddr,((uint8)0x00),Cfg->Vars->RxBufLength);
    Cfg->Vars->RxHead=((uint8)0x00);
    Cfg->Vars->RxTail=((uint8)0x00);
    
    return S12SCI_OK;
}

S12Sci_StatusType SCI_TxBufFlush(S12Sci_ConfigType const * const Cfg)
{    
    Cfg->Vars->TxBufPtr=(uint8)0;
    
    return S12SCI_OK;
}

/*! \fn SCITxReady
 *      t.b.d
 *
 */
S12Sci_StatusType SCI_TxReady(S12Sci_ConfigType const * const Cfg)     /* todo: Überarbeiten!!! */
{
    if ((BYTE_REG(Cfg->BaseAddr,SCICR2) & SCTIE) || !(BYTE_REG(Cfg->BaseAddr,SCISR1) & TDRE)) {
        return S12SCI_STATE;
    } else {        
        return S12SCI_OK;
    }   
}


/*
**
**      Interrupt-Handler.
**
*/

S12Sci_StatusType SCI_Handler(S12Sci_ConfigType const * const Cfg)
{    
    if ((BYTE_REG(Cfg->BaseAddr,SCICR2) & RIE) && (BYTE_REG(Cfg->BaseAddr,SCISR1) & RDRF)) {
        Cfg->Vars->RxBufAddr[Cfg->Vars->RxTail++]=BYTE_REG(Cfg->BaseAddr,SCIDRL); /* todo: Sequence-Point wg. volatile Variablen!!! */
        if (Cfg->Vars->RxTail>=Cfg->Vars->RxBufLength) {
            Cfg->Vars->RxTail=((uint8)0x00);
        }
        /* todo: Callback ('(HW_EventNotifyFunc)NULL') falls konfiguriert!!! */
    } else if ((BYTE_REG(Cfg->BaseAddr,SCICR2) & SCTIE) && (BYTE_REG(Cfg->BaseAddr,SCISR1) & TDRE)) {
        if (Cfg->Vars->TxBufPtr<Cfg->Vars->TxBufLength) {
            BYTE_REG(Cfg->BaseAddr,SCIDRL)=Cfg->Vars->TxBufAddr[Cfg->Vars->TxBufPtr++];
        } else {
            BYTE_REG(Cfg->BaseAddr,SCICR2)&=~(SCTIE);   /* OK, disable Tx-Interrupt-Source. */
            /* todo: Callback ('(HW_EventNotifyFunc)NULL') falls konfiguriert!!! */
        }
    }
    
    return S12SCI_OK;
}


/*
**      Helper-Functions.
*/
static uint16 SCI_CalculateBaudratePrescaler(uint32 br)
{
    uint8 freq;
    
    (void)S12Crg_GetBusFreq(&freq);
    
    return (uint16)((freq*((uint32)1000000UL)/SCI_FIXED_PRESCALER)/br);
}
