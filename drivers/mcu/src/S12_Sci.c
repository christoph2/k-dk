/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "S12_Sci.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES
**
**  S12SCIV3 - HCS12 SERIAL COMMUNICATIONS INTERFACE (SCI) BLOCK GUIDE
**
*/

/*
** todo: ReturnCodes überarbeiten!!!
*/

#define	S12SCI_FIXED_PRESCALER  ((uint8)16)
#define S12SCI_PRESC_PER_MHZ    ((uint32)(1000000UL/(uint32)(S12SCI_FIXED_PRESCALER)))

#define S12SCI_INTR_MSK        RIE         /* do not enable Transmit-Interrupt(TIE)!!! */


static uint16 S12Sci_CalculateBaudratePrescaler(uint32 baudrate);


S12Sci_StatusType S12Sci_Init(S12Sci_ConfigType const * const Cfg)
{
    S12_REG8(Cfg,SCICR2)=((uint8)0x00);

    Utl_MemSet(Cfg->Vars,'\0',sizeof(S12Sci_VariablesType));

    S12Sci_SetFormat(Cfg,Cfg->BaudRate,Cfg->Parity,Cfg->NBits);
    S12_REG8(Cfg,SCISR2)=(BRK13);

    S12Sci_SetRxBuffer(Cfg,Cfg->RxBufAddr,Cfg->RxBufLength);
    S12Sci_RxBufFlush(Cfg);

    S12Sci_SetTxBuffer(Cfg,(uint8*)NULL,(uint8)0);
    S12Sci_TxBufFlush(Cfg);

    S12_REG8(Cfg,SCICR1)=((uint8)0x00);
    S12_REG8(Cfg,SCICR2)=(TE|RE);

    S12Sci_EnableInterrupts(Cfg,FALSE);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_EnableInterrupts(S12Sci_ConfigType const * const Cfg,boolean ena)
{
    uint8 ch;

    if (ena==TRUE) {
        ch=S12_REG8(Cfg,SCIDRL);
        S12_REG8(Cfg,SCICR2)|=S12SCI_INTR_MSK;
    } else {
        S12_REG8(Cfg,SCICR2)&=~S12SCI_INTR_MSK;
    }

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SetBaud(S12Sci_ConfigType const * const Cfg,uint32 baud)
{
    S12_REG16(Cfg,SCIBD)=S12Sci_CalculateBaudratePrescaler(baud);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SetFormat(S12Sci_ConfigType const * const Cfg,uint32 baudrate,uint8 parity,uint8 nbits)
{
    uint8 set_msk=(uint8)0,clr_msk=(uint8)0;
    uint8 ch;

    S12_REG16(Cfg,SCIBD)=S12Sci_CalculateBaudratePrescaler(baudrate);

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
    S12_REG8(Cfg,SCICR1)&=~(clr_msk);
    S12_REG8(Cfg,SCICR1)|=set_msk;

    ch=S12_REG8(Cfg,SCIDRL);    /* clear spurious interrupts. */

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SetRxBuffer(S12Sci_ConfigType const * const Cfg,uint8 *buf,uint8 len)
{
    Cfg->Vars->RxBufAddr=buf;
    Cfg->Vars->RxBufLength=len;
    S12Sci_RxBufFlush(Cfg);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SetTxBuffer(S12Sci_ConfigType const * const Cfg,uint8 *buf,uint8 len)
{
    Cfg->Vars->TxBufAddr=buf;
    Cfg->Vars->TxBufLength=len;
    S12Sci_TxBufFlush(Cfg);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_Get(S12Sci_ConfigType const * const Cfg,uint8 *ch)
{
    uint8 error;

    WAIT_FOR(((S12_REG8(Cfg,SCISR1)) & RDRF)==RDRF);
    error=S12_REG8(Cfg,SCISR1) & (OR|NF|FE|PF);
    if (error!=(uint8)0x00) {
        Cfg->Vars->LastError=error;
    }
    *ch=S12_REG8(Cfg,SCIDRL);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_Put(S12Sci_ConfigType const * const Cfg,uint8 ch)
{
    WAIT_FOR(((S12_REG8(Cfg,SCISR1)) & TDRE)==TDRE);
    S12_REG8(Cfg,SCIDRL)=ch;

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_PutString(S12Sci_ConfigType const * const Cfg,uint8 const * str)
{
    uint8 ch;

    while ((ch=*str++)!=NULL) {
        S12Sci_Put(Cfg,ch);
    }

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SendBreak(S12Sci_ConfigType const * const Cfg)
{
    S12_REG8(Cfg,SCICR2)|=SBK;
    CPU_NO_OPERATION();
    S12_REG8(Cfg,SCICR2)&=~SBK;

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_SendBuffer(S12Sci_ConfigType const * const Cfg,uint8 const * buf,uint8 len)
{
    boolean ready=FALSE;

    if (len) {

        do {
            (void)S12Sci_TxReady(Cfg,&ready);
        } while (ready==FALSE);

        if (len==((uint8)1)) {
            (void)S12Sci_Put(Cfg,buf[0]);
        } else {
            Cfg->Vars->TxBufLength=len;
            Cfg->Vars->TxBufAddr=buf;
            Cfg->Vars->TxBufPtr=((uint8)1);
            S12_REG8(Cfg,SCIDRL)=buf[0];
            S12_REG8(Cfg,SCICR2)|=SCTIE;
        }
    }

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_RxBufGetCh(S12Sci_ConfigType const * const Cfg,uint8 *ch)
{
    boolean empty;

    (void)S12Sci_RxBufIsEmpty(Cfg,&empty);

    if (empty==TRUE) {
        return S12SCI_STATE;
    }

    *ch=Cfg->Vars->RxBufAddr[Cfg->Vars->RxHead++];

    if (Cfg->Vars->RxHead>=Cfg->Vars->RxBufLength) {
        Cfg->Vars->RxHead=((uint8)0x00);
    }

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_RxBufIsEmpty(S12Sci_ConfigType const * const Cfg,boolean *empty)
{
    *empty= Cfg->Vars->RxTail==Cfg->Vars->RxHead;

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_RxBufFlush(S12Sci_ConfigType const * const Cfg)
{
    Utl_MemSet((void*)Cfg->Vars->RxBufAddr,((uint8)0x00),Cfg->Vars->RxBufLength);
    Cfg->Vars->RxHead=((uint8)0x00);
    Cfg->Vars->RxTail=((uint8)0x00);

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_TxBufFlush(S12Sci_ConfigType const * const Cfg)
{
    Cfg->Vars->TxBufPtr=(uint8)0;

    return S12SCI_OK;
}


S12Sci_StatusType S12Sci_TxReady(S12Sci_ConfigType const * const Cfg,boolean *ready)
{	
    *ready=(!(S12_REG8(Cfg,SCICR2) & SCTIE)==SCTIE) && ((S12_REG8(Cfg,SCISR1) & TDRE)==TDRE);

    return S12SCI_OK;
}


uint8 S12Sci_GetLastError(S12Sci_ConfigType const * const Cfg)
{
    uint8 error=Cfg->Vars->LastError;

    Cfg->Vars->LastError=(uint8)0x00;
    return error;
}


/*
**
**      Interrupt-Handler.
**
*/
S12Sci_StatusType S12Sci_Handler(S12Sci_ConfigType const * const Cfg)
{
    uint8 ch,error;

    if ((S12_REG8(Cfg,SCICR2) & RIE) && (S12_REG8(Cfg,SCISR1) & RDRF)) {
        error=S12_REG8(Cfg,SCISR1) & (OR|NF|FE|PF);
        if (error!=(uint8)0x00) {
            Cfg->Vars->LastError=error;
        }
        ch=S12_REG8(Cfg,SCIDRL);
        Cfg->Vars->RxBufAddr[Cfg->Vars->RxTail++]=ch;
        if (Cfg->Vars->RxTail>=Cfg->Vars->RxBufLength) {
            Cfg->Vars->RxTail=((uint8)0x00);
        }
        /* todo: Callback ('(HW_EventNotifyFunc)NULL') ! */
    } else if ((S12_REG8(Cfg,SCICR2) & SCTIE) && (S12_REG8(Cfg,SCISR1) & TDRE)) {
        if (Cfg->Vars->TxBufPtr<Cfg->Vars->TxBufLength) {
            S12_REG8(Cfg,SCIDRL)=Cfg->Vars->TxBufAddr[Cfg->Vars->TxBufPtr++];
        } else {
            S12_REG8(Cfg,SCICR2)&=~(SCTIE);   /* OK, disable Tx-Interrupt-Source. */
            /* todo: Callback ('(HW_EventNotifyFunc)NULL') ! */
        }
    }

    return S12SCI_OK;
}


ISR1(SCI0_Vector)
{
    S12Sci_Handler(SCI0);
}


ISR1(SCI1_Vector)
{
    S12Sci_Handler(SCI1);
}


static uint16 S12Sci_CalculateBaudratePrescaler(uint32 baudrate)
{
    uint16 tmp;

    tmp=(uint16)((S12Crg_GetBusFreq()*S12SCI_PRESC_PER_MHZ*10L)/baudrate);

    if ((tmp % (uint16)10)>=(uint16)5) {
        tmp+=(uint16)10;
    }
    return tmp/=(uint16)10;
}
