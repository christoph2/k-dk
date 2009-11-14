/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
 *                                      cpu12.gems@googlemail.com>
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
#include "Hw_Cfg.h"
#include "HC12_Bdlc.h"

static void HC12Bdlc_NOIP(void);
static void HC12Bdlc_RXEOF(void);
static void HC12Bdlc_RXIFR(void);
static void HC12Bdlc_RDRF(void);
static void HC12Bdlc_TDRE(void);
static void HC12Bdlc_LOARB(void);
static void HC12Bdlc_CRCERR(void);
static void HC12Bdlc_SYMINV(void);
static void HC12Bdlc_WUP(void);


/*
**  Function-Pointers for Interrupts.
*/
static const VoidFunctionType HC12Bdlc_Intr[]={
    HC12Bdlc_NOIP,HC12Bdlc_RXEOF,HC12Bdlc_RXIFR,
    HC12Bdlc_RDRF,HC12Bdlc_TDRE,HC12Bdlc_LOARB,
    HC12Bdlc_CRCERR,HC12Bdlc_SYMINV,HC12Bdlc_WUP,
};


/*
**  Local Defines.
*/
#define BDLC_MAX_LSDU_LEN   ((uint8)12)

/*
**  Local Variables.
*/
static uint8 Bdlc_RxBuffer[BDLC_MAX_LSDU_LEN];
static uint8 Bdlc_RxPos=(uint8)0;

static uint8 const * Bdlc_TxBuffer=NULL;
static uint8 Bdlc_TxBytesRemaining=(uint8)0;
static uint8 Bdlc_TxPos=(uint8)0;


#if 0
$00 0000    No interrupts pending                   (NOIP)
$04 0001    Received EOF                            (RXEOF)
$08 0010    Received IFR byte                       (RXIFR)
$0C 0011    BDLC Rx data register full              (RDRF)
$10 0100    BDLC Tx data register empty             (TDRE)
$14 0101    Loss of arbitration                     (LOARB)
$18 0110    Cyclical redundancy check (CRC) error   (CRCERR)
$1C 0111    Symbol invalid or out of range          (SYMINV)
$20 1000    Wakeup                                  (WUP)
#endif

/*
**
**  todo:       Option 'HC12_BDLC_USE_LOOPBACK'.
*+  Hinweis:    Sehr gute Idee, auch für andere Module, die Loopback kennen!!!
**
**
*/

void HC12Bdlc_Init(void)
{
    Utl_MemSet(Bdlc_RxBuffer,'\0',BDLC_MAX_LSDU_LEN);
    Bdlc_RxPos=(uint8)0x00;

    Bdlc_TxBuffer=NULL;
    Bdlc_TxBytesRemaining=(uint8)0;

    /* todo: Initialisierung-Reihefolge checken!!! */
    HC12BDLC_REG8(PORTDLC)=BDLC.PortDlc;
    HC12BDLC_REG8(DDRDLC)=BDLC.DdrDlc;


    HC12BDLC_REG8(BARD)=BDLC.Bard;
    HC12BDLC_REG8(DLCSCR)=BDLC.DlcScr;
    HC12BDLC_REG8(BCR2)=BDLC.Bcr2;
    HC12BDLC_REG8(BCR1)=BDLC.Bcr1;

}


boolean HC12Bdlc_Busy(void)
{

}


boolean HC12Bdlc_Rxd(void)
{


}


uint8 HC12Bdlc_Transmit(uint8 const * buf,uint8 len)
{
    /* ASSERT(/len>(uint8)0x00) && (len<=BDLC_MAX_LSDU_LEN));  */
   /* todo: Busy-Check!!!              */

/*    return E_NOT_OK; */
/* todo: single-byte transmission. */

    Bdlc_TxBuffer=buf;
    Bdlc_TxBytesRemaining=(uint8)len;
    Bdlc_TxPos=(uint8)0;
    HC12BDLC_REG8(BDR)=Bdlc_TxBuffer[0];    /* Start transmission.  */

    return E_OK;
}


ISR1(BDLC_Vector)
{
    uint8 vec_num;

    do {
        vec_num=HC12BDLC_REG8(BSVR)>>(uint8)2;
        HC12Bdlc_Intr[vec_num]();
    } while (vec_num!=(uint8)0x00);
}


static void HC12Bdlc_NOIP(void)
{
/*
* $00 - No Interrupts Pending.  This interrupt service routine should
*       never happen.
*/
}


static void HC12Bdlc_RXEOF(void)
{
    /* OK, kompletter Frame wurde empfangen - weiterreichen falls kein Fehler auftrat. */
/*
* $04 - EOF Interrupt. First, the routine checks to see if loss of arbi--
*       tration occurred. If so, then the message that needs to be retrans-
*       mitted has already been loaded by the program and the transmit
*       RAM variables should not be cleared, only the receiver variables.
*       Next, the routine checks to see if the EOF was a result of transmit-
*       ting a message or receiving one.  If it was result of transmitting,
*       then the transmitter & receiver RAM variables are cleared. If the
*       EOF was a result of receiving a message, then the received message
*       is analyzed to see if the BDLC should switch into 4x receive mode or
*       not. If so, then it is switched and the receiver RAM variables are
*       cleared. If not, then just the receiver RAM variables are cleared.
*/
}


static void HC12Bdlc_RXIFR(void)
{
    /* not used!? */
    uint8 b=HC12BDLC_REG8(BDR);   /* Dummy read to clear interrupt source. */
/*
* $08 - RXIFR Interrupt. IFR is not used in this program, so this interrupt
*       should not happen.
*/
}


static void HC12Bdlc_RDRF(void)
{
/*
* $0C - RDRF Interrupt. This interrupt occurs when a data byte is received.
*       Two things are checked as the bytes are received. First does the
*       second byte = $55 if not then ignore the rest of the message.
*       Second, does the first 4 bytes of the message = $6c $55 $01 $04?
*       If so, then switch into 4x receive mode.
*/

    Bdlc_RxBuffer[Bdlc_RxPos++]=HC12BDLC_REG8(BDR);
    /* todo: Callback aufrufen, Receiver deaktivieren, falls dieser 'FALSE' zurück gibt. */
}


static void HC12Bdlc_TDRE(void)
{
/*
* $10 - TDRE Interrupt. This routine continues to transmit the message
*       that has been stored in the tx_message buffer.  If the last byte
*       has been sent, then an EOD is transmitted.
*/

    HC12BDLC_REG8(BDR)=Bdlc_TxBuffer[++Bdlc_TxPos];

    if ((--Bdlc_TxBytesRemaining)==(uint8)0x00) {
        /* Send EOD after last Byte. */
        HC12BDLC_REG8(BCR2)|TEOD;
    }
}


static void HC12Bdlc_LOARB(void)
{
/*
* $14 - LOA Interrupt. In this routine, the loss of arbitration and
*       retransmit RAM variables are set, and the transmit counter is
*       cleared. That way the message to be transmitted will be loaded
*       and transmitted again.
*/
}


static void HC12Bdlc_CRCERR(void)
{
    /* todo: Fehler aufzeichnen? */

/*
* $18 - CRC Error flag. If the CRC error occurred during a transmission
*       then the retransmit RAM variable is set. Also the transmit and
*       receiver RAM variables are cleared.  If the CRC error occurred
*       while receiving a message, then only the receiver RAM variables
*       are cleared.
*/
}

static void HC12Bdlc_SYMINV(void)
{
    /* todo: Fehler aufzeichnen? */

/*
* $1C - Symbol Invalid Interrupt. Same sequence is used as for a CRC error,
*       except that an EOF delay (~280 us) is added before the software
*       returns from the interrupt service routine. The delay is added
*       because after an invalid symbol interrupt the BDLC module needs to
*       see the bus idle for an EOF time period.  This ensures that there
*       isn't still a fault on the bus.  An EOF interrupt will be generated
*       once the EOF time period has expired.
*/

/*
The invalid symbol or out-of-range error flag is handled slightly
differently than the CRC error. This error flag encompasses all errors on
the bus outside of the CRC error. Therefore, the user will not be able to
determine exactly what caused the invalid symbol error. For this reason,
the BDLC will stop transmitting a byte immediately if an error occurs
during transmission and will set the invalid symbol flag. Likewise, if the
BDLC receives a bad byte, it immediately will discard the incoming byte
and set the invalid symbol flag. In this case, the BDLC waits until the bus
is idle for an EOF time period (~280ms) before receiving any new
messages. The BDLC will signal that an EOF time period has expired by
setting the EOF flag. After the invalid symbol and EOF flags are cleared,
the BDLC is ready to continue communicating on the J1850 bus.
*/
}

static void HC12Bdlc_WUP(void)
{
/*
* $20 - Wakeup flag. Low power modes are not being used in this program,
*       so this interrupt should never occur.
*/
}
