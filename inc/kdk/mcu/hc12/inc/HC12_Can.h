/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
 * s. FLOSS-EXCEPTION.txt
 */
#if !defined(__HC12CAN_H)
#define __HC12CAN_H

#include "mcu/inc/mscan.h"

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#define HC12_DG128_CAN_BASE ((uint16)0x0100)

#define CMCR0               ((uint8)0x00)
/* CMCR0-Bits. */
    #define CSWAI           ((uint8)0x20)
    #define SYNCH           ((uint8)0x10)
    #define TLNKEN          ((uint8)0x08)
    #define SLPAK           ((uint8)0x04)
    #define SLPRQ           ((uint8)0x02)
    #define SFTRES          ((uint8)0x01)

#define CMCR1               ((uint8)0x01)
/* CMCR1-Bits. */
   #define LOOPB            ((uint8)0x04)
   #define WUPM             ((uint8)0x02)
   #define CLKSRC           ((uint8)0x01)

#define CBTR0               ((uint8)0x02)
/* CBTR0-Bits. */
   #define SJW1             ((uint8)0x80)
   #define SJW0             ((uint8)0x40)
   #define BRP5             ((uint8)0x20)
   #define BRP4             ((uint8)0x10)
   #define BRP3             ((uint8)0x08)
   #define BRP2             ((uint8)0x04)
   #define BRP1             ((uint8)0x02)
   #define BRP0             ((uint8)0x01)

#define CBTR1               ((uint8)0x03)
/* CBTR1-Bits. */
   #define SAMP             ((uint8)0x80)
   #define TSEG22           ((uint8)0x40)
   #define TSEG21           ((uint8)0x20)
   #define TSEG20           ((uint8)0x10)
   #define TSEG13           ((uint8)0x08)
   #define TSEG12           ((uint8)0x04)
   #define TSEG11           ((uint8)0x02)
   #define TSEG10           ((uint8)0x01)

#define CRFLG               ((uint8)0x04)
/* CRFLG-Bits. */
   #define WUPIF            ((uint8)0x80)
   #define RWRNIF           ((uint8)0x40)
   #define TWRNIF           ((uint8)0x20)
   #define RERRIF           ((uint8)0x10)
   #define TERRIF           ((uint8)0x08)
   #define BOFFIF           ((uint8)0x04)
   #define OVRIF            ((uint8)0x02)
   #define RXF              ((uint8)0x01)

#define CRIER               ((uint8)0x05)
/* CRIER-Bits.  */
   #define WUPIE            ((uint8)0x80)
   #define RWRNIE           ((uint8)0x40)
   #define TWRNIE           ((uint8)0x20)
   #define RERRIE           ((uint8)0x10)
   #define TERRIE           ((uint8)0x08)
   #define BOFFIE           ((uint8)0x04)
   #define OVRIE            ((uint8)0x02)
   #define RXFIE            ((uint8)0x01)

#define CTFLG               ((uint8)0x06)
/* CTFLG-Bits. */
   #define ABTAK2           ((uint8)0x40)
   #define ABTAK1           ((uint8)0x20)
   #define ABTAK0           ((uint8)0x10)
   #define TXE2             ((uint8)0x04)
   #define TXE1             ((uint8)0x02)
   #define TXE0             ((uint8)0x01)

#define CTCR                ((uint8)0x07)
/* CTCR-Bits. */
   #define ABTRQ2           ((uint8)0x40)
   #define ABTRQ1           ((uint8)0x20)
   #define ABTRQ0           ((uint8)0x10)
   #define TXEIE2           ((uint8)0x04)
   #define TXEIE1           ((uint8)0x02)
   #define TXEIE0           ((uint8)0x01)

#define CIDAC               ((uint8)0x08)
/* CIDAC-Bits .*/
   #define IDAM1            ((uint8)0x20)
   #define IDAM0            ((uint8)0x10)
   #define IDHIT2           ((uint8)0x04)
   #define IDHIT1           ((uint8)0x02)
   #define IDHIT0           ((uint8)0x01)

#define CRXERR              ((uint8)0x0e)

#define CTXERR              ((uint8)0x0f)

/* Identifier Acceptance Registers (1st bank). */
#define CIDAR0              ((uint8)0x10)
#define CIDAR1              ((uint8)0x11)
#define CIDAR2              ((uint8)0x12)
#define CIDAR3              ((uint8)0x13)

/* Identifier Mask Registers (1st bank). */
#define CIDMR0              ((uint8)0x14)
#define CIDMR1              ((uint8)0x15)
#define CIDMR2              ((uint8)0x16)
#define CIDMR3              ((uint8)0x17)

/* Identifier Acceptance Registers (2nd bank). */
#define CIDAR4              ((uint8)0x18)
#define CIDAR5              ((uint8)0x19)
#define CIDAR6              ((uint8)0x1a)
#define CIDAR7              ((uint8)0x1b)

/* Identifier Mask Registers (2nd bank). */
#define CIDMR4              ((uint8)0x1c)
#define CIDMR5              ((uint8)0x1d)
#define CIDMR6              ((uint8)0x1e)
#define CIDMR7              ((uint8)0x1f)

#define PCTLCAN             ((uint8)0x3d)
/* PCTLCAN-Bits. */
   #define PUPCAN           ((uint8)0x02)
   #define RDPCAN           ((uint8)0x01)

#define PORTCAN             ((uint8)0x3e)
/* PORTCAN-Bits. */
   #define PCAN7            ((uint8)0x80)
   #define PCAN6            ((uint8)0x40)
   #define PCAN5            ((uint8)0x20)
   #define PCAN4            ((uint8)0x10)
   #define PCAN3            ((uint8)0x08)
   #define PCAN2            ((uint8)0x04)
   #define TxCAN            ((uint8)0x02)
   #define RxCAN            ((uint8)0x01)

#define DDRCAN              ((uint8)0x3f)
/* DDRCAN-Bits. */
   #define DDCAN7           ((uint8)0x80)
   #define DDCAN6           ((uint8)0x40)
   #define DDCAN5           ((uint8)0x20)
   #define DDCAN4           ((uint8)0x10)
   #define DDCAN3           ((uint8)0x08)
   #define DDCAN2           ((uint8)0x04)

#define CAN_RxFG            ((uint8)0x40)

#define CAN_Tx0             ((uint8)0x50)

#define CAN_Tx1             ((uint8)0x60)

#define CAN_Tx2             ((uint8)0x70)
/*
   0x40 - 0x4f - Receiver buffer window.
   0x50 - 0x5f - Transmit-Buffer #0
   0x60 - 0x6f - Transmit-Buffer #1
   0x70 - 0x7f - Transmit-Buffer #2
 */

/*
** Global Types.
*/
typedef uint32 HC12Can_IdentifierType;

typedef enum tagHC12Can_ModeType {
    HC12CAN_MODE_INITIALISATION,     /* "Soft Reset State" */
    HC12CAN_MODE_NORMAL,
    HC12CAN_MODE_SLEEP,
    HC12CAN_MODE_POWER_DOWN
} HC12Can_ModeType;

typedef struct tagHC12Can_TxBufferType {
    MSCan_IdentifierOverlayType IDR;
    uint8                       DSR[MSCAN_MAX_LSDU_LEN];
    uint8                       DLR;
    uint8                       TBBR;
    uint8                       Unused[2];
} HC12Can_TxBufferType;

typedef struct tagHC12Can_RxBufferType {
    MSCan_IdentifierOverlayType IDR;
    uint8                       DSR[MSCAN_MAX_LSDU_LEN];
    uint8                       DLR;
    uint8                       Unused[3];
} HC12Can_RxBufferType;

typedef struct tagHC12Can_ConfigType {
    uint8                       Cmcr0;
    uint8                       Cmcr1;
    uint8                       Cbtr0;
    uint8                       Cbtr1;
    uint8                       Cidac;
    uint8                       Crier;
    uint8                       Ctcr;
    MSCan_IdentifierOverlayType IdentifierMask[2];
    MSCan_IdentifierOverlayType IdentifierAcceptance[2];
} HC12Can_ConfigType;

typedef enum tagHC12_TxBufferNumberType {
    HC12_CAN_TX_BUFFER_NONE    = 0x00,
    HC12_CAN_TX_BUFFER_TXE0    = 0x01,
    HC12_CAN_TX_BUFFER_TXE1    = 0x02,
    HC12_CAN_TX_BUFFER_TXE2    = 0x04
} HC12_TxBufferNumberType;

/*
** Global Variables.
*/
extern HC12Can_ConfigType const * CAN;

/*
**  Function-Prototypes.
*/
void                    HC12Can_Init(HC12Can_ConfigType const * const ConfigPtr);
void                    HC12Can_InitController(uint8 Controller);
HC12Can_ModeType        HC12Can_GetMode(uint8 Controller);
void                    HC12Can_EnterSoftResetMode(uint8 Controller);
void                    HC12Can_LeaveSoftResetMode(uint8 Controller);
void                    HC12Can_RequestEnterSleepMode(uint8 Controller);
void                    HC12Can_RequestLeaveSleepMode(uint8 Controller);
boolean                 HC12Can_InSleepMode(uint8 Controller);
boolean                 HC12Can_ReceivedMessage(uint8 Controller);
boolean                 HC12Can_ControllerSynchedToBus(uint8 Controller);
HC12Can_TxBufferType *  HC12Can_GetTxBuffer(uint8 Controller);

void HC12Can_AbortTransmission(uint8 Controller, uint8 buffer);


/*
**  Function-like Macros.
*/

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__HC12CAN_H */

