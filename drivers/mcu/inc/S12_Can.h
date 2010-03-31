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
#if !defined(__S12CAN_H)
#define __S12CAN_H

#include "S12_Hw.h"
#include "Utl.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** Register-Offsets
*/
#define CANCTL0         ((uint8)0)
	/*  CANCTL0-Bits. */
    #define RXFRM       ((uint8)0x80)
    #define RXACT       ((uint8)0x40)
    #define CSWAI       ((uint8)0x20)
    #define SYNCH       ((uint8)0x10)
    #define TIME        ((uint8)0x08)
    #define WUPE        ((uint8)0x04)
    #define SLPRQ       ((uint8)0x02)
    #define INITRQ      ((uint8)0x01)

#define CANCTL1         ((uint8)1)
    /*  CANCTL1-Bits. */
    #define CANE        ((uint8)0x80)
    #define CLKSRC      ((uint8)0x40)
    #define LOOPB       ((uint8)0x20)
    #define LISTEN      ((uint8)0x10)
    #define WUPM        ((uint8)0x04)
    #define SLPAK       ((uint8)0x02)
    #define INITAK      ((uint8)0x01)

#define CANBTR0         ((uint8)2)
        /*  CANBTR0-Bits. */
    #define SJW1        ((uint8)0x80)
    #define SJW0        ((uint8)0x40)
    #define BRP5        ((uint8)0x20)
    #define BRP4        ((uint8)0x10)
    #define BRP3        ((uint8)0x08)
    #define BRP2        ((uint8)0x04)
    #define BRP1        ((uint8)0x02)
    #define BRP0        ((uint8)0x01)

#define CANBTR1         ((uint8)3)
    /*  CANBTR1-Bits. */
    #define SAMP        ((uint8)0x80)
    #define TSEG22      ((uint8)0x40)
    #define TSEG21      ((uint8)0x20)
    #define TSEG20      ((uint8)0x10)
    #define TSEG13      ((uint8)0x08)
    #define TSEG12      ((uint8)0x04)
    #define TSEG11      ((uint8)0x02)
    #define TSEG10      ((uint8)0x01)

#define CANRFLG         ((uint8)4)
    /*  CANRFLG-Bits. */
    #define WUPIF       ((uint8)0x80)
    #define CSCIF       ((uint8)0x40)
    #define RSTAT1      ((uint8)0x20)
    #define RSTAT0      ((uint8)0x10)
    #define TSTAT1      ((uint8)0x08)
    #define TSTAT0      ((uint8)0x04)
    #define OVRIF       ((uint8)0x02)
    #define RXF         ((uint8)0x01)

#define CANRIER         ((uint8)5)
    /*  CANRIER-Bits. */
    #define WUPIE       ((uint8)0x80)
    #define CSCIE       ((uint8)0x40)
    #define RSTATE1     ((uint8)0x20)
    #define RSTATE0     ((uint8)0x10)
    #define TSTATE1     ((uint8)0x08)
    #define TSTATE0     ((uint8)0x04)
    #define OVRIE       ((uint8)0x02)
    #define RXFIE       ((uint8)0x01)

#define CANTFLG         ((uint8)6)
    /*  CANTFLG-Bits. */
    #define TXE2        ((uint8)0x04)
    #define TXE1        ((uint8)0x02)
    #define TXE0        ((uint8)0x01)

#define CANTIER         ((uint8)7)
    /*  CANTIER-Bits. */
    #define TXEIE2      ((uint8)0x04)
    #define TXEIE1      ((uint8)0x02)
    #define TXEIE0      ((uint8)0x01)

#define CANTARQ         ((uint8)8)
    /*  CANTARQ-Bits. */
    #define ABTRQ2      ((uint8)0x04)
    #define ABTRQ1      ((uint8)0x02)
    #define ABTRQ0      ((uint8)0x01)

#define CANTAAK         ((uint8)9)
    /*  CANTAAK-Bits. */
    #define ABTAK2      ((uint8)0x04)
    #define ABTAK1      ((uint8)0x02)
    #define ABTAK0      ((uint8)0x01)

#define CANTBSEL        ((uint8)0x0a)
    /*  CANTBSEL-Bits.  */
    #define TX2         ((uint8)0x04)
    #define TX1         ((uint8)0x02)
    #define TX0         ((uint8)0x01)

#define CANIDAC         ((uint8)0x0b)
    /*  CANIDAC-Bits. */
    #define IDAM1       ((uint8)0x20)
    #define IDAM0       ((uint8)0x10)
    #define IDHIT2      ((uint8)0x04)
    #define IDHIT1      ((uint8)0x02)
    #define IDHIT0      ((uint8)0x01)

/*
0x0C-0x0D Reserved
*/

#define CANRXERR        ((uint8)0x0e)
    /*  CANRXERR-Bits.  */
    #define RXERR7      ((uint8)0x80)
    #define RXERR6      ((uint8)0x40)
    #define RXERR5      ((uint8)0x20)
    #define RXERR4      ((uint8)0x10)
    #define RXERR3      ((uint8)0x08)
    #define RXERR2      ((uint8)0x04)
    #define RXERR1      ((uint8)0x02)
    #define RXERR0      ((uint8)0x01)

#define CANTXERR        ((uint8)0x0f)
    /*  CANTXERR-Bits.  */
    #define TXERR7      ((uint8)0x80)
    #define TXERR6      ((uint8)0x40)
    #define TXERR5      ((uint8)0x20)
    #define TXERR4      ((uint8)0x10)
    #define TXERR3      ((uint8)0x08)
    #define TXERR2      ((uint8)0x04)
    #define TXERR1      ((uint8)0x02)
    #define TXERR0      ((uint8)0x01)

#define CANIDAR0        ((uint8)0x10)
    /*  CANIDAR-Bits. */
    #define AC7         ((uint8)0x80)
    #define AC6         ((uint8)0x40)
    #define AC5         ((uint8)0x20)
    #define AC4         ((uint8)0x10)
    #define AC3         ((uint8)0x08)
    #define AC2         ((uint8)0x04)
    #define AC1         ((uint8)0x02)
    #define AC0         ((uint8)0x01)

#define CANIDAR1        ((uint8)0x11)
#define CANIDAR2        ((uint8)0x12)
#define CANIDAR3        ((uint8)0x13)

#define CANIDMR0        ((uint8)0x14)
    /* CANIDMR-Bits. */
    #define AM7         ((uint8)0x80)
    #define AM6         ((uint8)0x40)
    #define AM5         ((uint8)0x20)
    #define AM4         ((uint8)0x10)
    #define AM3         ((uint8)0x08)
    #define AM2         ((uint8)0x04)
    #define AM1         ((uint8)0x02)
    #define AM0         ((uint8)0x01)

#define CANIDMR1        ((uint8)0x15)
#define CANIDMR2        ((uint8)0x16)
#define CANIDMR3        ((uint8)0x17)

#define CANIDAR4        ((uint8)0x18)
#define CANIDAR5        ((uint8)0x19)
#define CANIDAR6        ((uint8)0x1a)
#define CANIDAR7        ((uint8)0x1b)

#define CANIDMR4        ((uint8)0x1c)
#define CANIDMR5        ((uint8)0x1d)
#define CANIDMR6        ((uint8)0x1e)
#define CANIDMR7        ((uint8)0x1f)

#define CANRXFG         ((uint8)0x20)
#define CANTXFG         ((uint8)0x30)
    /*  FOREGROUND-BUFFER-Offsets.  */
    #define CANIDR0     ((uint8)0x00)
    #define CANIDR1     ((uint8)0x01)
    #define CANIDR2     ((uint8)0x02)
    #define CANIDR3     ((uint8)0x03)
    #define CANDSR0     ((uint8)0x04)
    #define CANDSR1     ((uint8)0x05)
    #define CANDSR2     ((uint8)0x06)
    #define CANDSR3     ((uint8)0x07)
    #define CANDSR4     ((uint8)0x08)
    #define CANDSR5     ((uint8)0x09)
    #define CANDSR6     ((uint8)0x0A)
    #define CANDSR7     ((uint8)0x0B)
    #define CANDLR      ((uint8)0x0C)
    #define CANTBPR     ((uint8)0x0D)
    #define CANTSRH     ((uint8)0x0E)
    #define CANTSRL     ((uint8)0x0F)

#define CAN_MAX_LSDU_LEN    ((uint8)0x08)
#define S12CAN_FILTER_LEN   ((uint8)0x08)

#define S12CAN_8_8_FILTERS(a,b,c,d,e,f,g,h) {(uint8)(a),(uint8)(b),(uint8)(c),(uint8)(d),   \
    (uint8)(e),(uint8)(f),(uint8)(g),(uint8)(h)}

#define S12CAN_4_16_FILTERS(a,b,c,d) {HIBYTE(a),LOBYTE(a),HIBYTE(b),LOBYTE(b),HIBYTE(c),    \
    LOBYTE(c),HIBYTE(d),LOBYTE(d)}

#define S12CAN_2_32_FILTERS(a,b) {HIBYTE(HIWORD(a)),LOBYTE(HIWORD(a)),HIBYTE(LOWORD(a)),    \
    LOBYTE(LOWORD(a)),HIBYTE(HIWORD(b)),LOBYTE(HIWORD(b)),HIBYTE(LOWORD(b)),LOBYTE(LOWORD(b))}


typedef enum tagS12Can_StatusType {
    S12CAN_OK,
    S12CAN_UNINIT,
    S12CAN_ID,
    S12CAN_STATE,
    S12CAN_VALUE

} S12Can_StatusType;

typedef struct tagS12Can_BufferType {
    uint8 IDR0;
    uint8 IDR1;
    uint8 IDR2;
    uint8 IDR3;
    uint8 DSR0;
    uint8 DSR1;
    uint8 DSR2;
    uint8 DSR3;
    uint8 DSR4;
    uint8 DSR5;
    uint8 DSR6;
    uint8 DSR7;
    uint8 DLR;
    uint8 TBPR;
    uint8 TSRH;
    uint8 TSRL;
} S12Can_BufferType;  /* Can_MsgBufferType */

typedef uint8 S12Can_IdentifierType[S12CAN_FILTER_LEN];
typedef uint8 S12Can_SDUType[CAN_MAX_LSDU_LEN];

typedef struct tagS12Can_BusTimingType {
    uint8 BRT0;
    uint8 BRT1;
} S12Can_BusTimingType;

typedef struct tagS12Can_MessageType {
    uint32 ID;
    uint8 DLR;
    S12Can_SDUType SDU;
} S12Can_MessageType;

typedef struct tagS12Can_FilterType {
    uint8 FilterMode;
    S12Can_IdentifierType IdentifierAcceptance;
    S12Can_IdentifierType IdentifierMask;
} S12Can_FilterType;

typedef struct tagS12Can_ConfigType {
    uint16 BaseAddr;
    S12Can_FilterType Filter;
} S12Can_ConfigType;

/*
**  Global Defines.
*/
#define S12CAN_ACC_FLT_TWO_32   ((uint8)0x00)   /* Two 32 bit Acceptance Filters.               */
#define S12CAN_ACC_FLT_FOUR_16  ((uint8)0x10)   /* Four 16 bit Acceptance Filters.              */
#define S12CAN_ACC_FLT_EIGHT_8  ((uint8)0x20)   /* Eight 8 bit Acceptance Filters.              */
#define S12CAN_ACC_FLT_CLOSED   ((uint8)0x30)   /* Filter Closed.                               */

/*
**  Hinweis: Wie wärs mit Debug-Statistiken: Receive-/Transmit-Errors on Last Message!?
*/
#define S12CAN_RSTAT_OK          ((uint8)0x00)  /* RxOK: 0 <= Receive Error Counter <= 96       */
#define S12CAN_RSTAT_WRN         ((uint8)0x10)  /* RxWRN: 96 < Receive Error Counter <= 127     */
#define S12CAN_RSTAT_ERR         ((uint8)0x20)  /* RxERR: 127 < Receive Error Counter           */
#define S12CAN_RSTAT_BUSOFF      ((uint8)0x30)  /* Bus-Off: Transmit Error Counter > 255        */

#define S12CAN_TSTAT_OK          ((uint8)0x00)  /* TxOK: 0 <= Transmit Error Counter <= 96      */
#define S12CAN_TSTAT_WRN         ((uint8)0x04)  /* TxWRN: 96 < Transmit Error Counter <= 127    */
#define S12CAN_TSTAT_ERR         ((uint8)0x08)  /* TxERR: 127 < Transmit Error Counter <= 255   */
#define S12CAN_TSTAT_BUSOFF      ((uint8)0x0C)  /* Bus-Off: Transmit Error Counter > 255        */


/*
** Global Functions.
*/
S12Can_StatusType S12Can_Init(S12Can_ConfigType const * const Cfg,uint8 btr0,uint8 btr1);
S12Can_StatusType S12Can_Stop(S12Can_ConfigType const * const Cfg);
S12Can_StatusType S12Can_InitializationMode(S12Can_ConfigType const * const  Cfg,boolean enable);
S12Can_StatusType S12Can_SleepMode(S12Can_ConfigType const * const Cfg,boolean enable);

boolean S12Can_Enabled(S12Can_ConfigType const * const Cfg);
boolean S12Can_Sleeping(S12Can_ConfigType const * const Cfg);
boolean S12Can_Initializing(S12Can_ConfigType const * const  Cfg);
boolean S12Can_Synchronized(S12Can_ConfigType const * const Cfg);

S12Can_StatusType S12Can_SetBusTiming(S12Can_ConfigType const * const  Cfg,uint8 btr0,uint8 btr1);
S12Can_StatusType S12Can_SetFilter(S12Can_ConfigType const * const Cfg,const S12Can_FilterType *Filter);
S12Can_StatusType S12Can_EnableInterrupts(S12Can_ConfigType const * const Cfg,boolean enable);
S12Can_StatusType S12Can_Transmit(S12Can_ConfigType const * const Cfg,S12Can_MessageType const * Msg,uint8 priority,/*@out@*/uint8 *SentOnBuffer);
S12Can_StatusType S12Can_Ready(S12Can_ConfigType const * const Cfg,/*@out@*/boolean *ready);
S12Can_StatusType S12Can_RxD(S12Can_ConfigType const * const Cfg,/*@out@*/boolean *rxd);
S12Can_StatusType S12Can_WaitSynch(S12Can_ConfigType const * const Cfg);
S12Can_StatusType S12Can_CancelMessage(S12Can_ConfigType const * const Cfg,uint8 Number);
S12Can_StatusType S12Can_CopyRxBuffer(S12Can_ConfigType const * const Cfg,/*@out@*/S12Can_MessageType *Msg);
S12Can_StatusType S12Can_GetErrorCounters(S12Can_ConfigType const * const Cfg,uint8 *RxErrors,/*@out@*/uint8 *TxErrors);


/*
**  ISR-Handlers.
*/
void Can_HandleIrqTx(S12Can_ConfigType const * const Cfg);
void Can_HandleIrqRx(S12Can_ConfigType const * const Cfg);
void Can_HandleIrqErr(S12Can_ConfigType const * const Cfg);
void Can_HandleIrqWup(S12Can_ConfigType const * const Cfg);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12CAN_H */
