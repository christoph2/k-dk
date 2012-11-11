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
 *
 */

/*
**
**  REFERENCES:
**  ==========
**  Motorola MSCAN Block Guide V02.14
**
*/

#if 0
== == == == == == == == == == == == == == == == == == == == == == == == == == ==
s.EB386(HCS12 D - Family Compatibility Considerations)
== == == == == == == == == == == == == == == == == == == == == == == == == == ==

MC9S12DP256B MC9S12DT256B MC9S12DJ256B MC9S12DG256B MC9S12A256B MC9S12DP256C MC9S12DT256C MC9S12DJ256C MC9S12DG256C
----------------------------------------------------------------------------------------------------------------------------------
-------------- -
# of \
    CANs   5               3               2               2               0           5               3               2             2
CAN0 x x x x x x x x
CAN1 x x x x
CAN2 x x
CAN3 x x
CAN4 x x x x x x x x
#endif

#define S12CAN_NUMBER_OF_BUSSES ((uint8)0x05)   /* TODO: CFG!!! */

#include "mcu/s12/inc/S12_Can.h"
#include "Hw_Cfg.h"

/*
**  todo: SetSDU / getSDU Funktionen!!!
*/

/*
**  Global Variables.
*/
S12Can_ConfigType const * CAN;

/*
**  Local Defines.
*/
#define S12CAN_RSTAT_OK     ((uint8)0x00)       /* RxOK: 0 <= Receive Error Counter <= 96       */
#define S12CAN_RSTAT_WRN    ((uint8)0x10)       /* RxWRN: 96 < Receive Error Counter <= 127     */
#define S12CAN_RSTAT_ERR    ((uint8)0x20)       /* RxERR: 127 < Receive Error Counter           */
#define S12CAN_RSTAT_BUSOFF ((uint8)0x30)       /* Bus-Off: Transmit Error Counter > 255        */

#define S12CAN_TSTAT_OK     ((uint8)0x00)       /* TxOK: 0 <= Transmit Error Counter <= 96      */
#define S12CAN_TSTAT_WRN    ((uint8)0x04)       /* TxWRN: 96 < Transmit Error Counter <= 127    */
#define S12CAN_TSTAT_ERR    ((uint8)0x08)       /* TxERR: 127 < Transmit Error Counter <= 255   */
#define S12CAN_TSTAT_BUSOFF ((uint8)0x0C)       /* Bus-Off: Transmit Error Counter > 255        */

/*
**  Local Constants.
*/
static uint16 S12Can_ControllerMapping[SC12_CAN_NUM_CONTROLLERS] = {   /* depends on derivate!!! */
    BASE_ADDR_CAN0,
    BASE_ADDR_CAN1,
    BASE_ADDR_CAN2,
    BASE_ADDR_CAN3,
    BASE_ADDR_CAN4,
};

/*
**  Local Variables.
*/
static MSCan_IdType S12Can_TxBufferToID[S12CAN_NUMBER_OF_BUSSES][3];
static uint8        S12Can_AbortRequests[S12CAN_NUMBER_OF_BUSSES];

/*
**  Local Function Prototypes.
*/
static void S12Can_SetIdentifier(uint16 addr, MSCan_IdentifierOverlayType value);
static void S12Can_GetIdentifier(uint16 addr, MSCan_IdentifierOverlayType * /*@out@*/ value);


/*
**  Local Function-like Macros.
*/

#define S12CAN_RECEIVER_ACTIVE(contr)   ((S12CAN_REG8((contr), CANCTL0) & RXACT) == RXACT)
#define S12CAN_RECEIVED_FRAME(contr)    ((S12CAN_REG8((contr), CANCTL0) & RXFRM) == RXFRM)
#define S12CAN_CLEAR_RX_FRAME(contr)    (S12CAN_REG8((contr), CANCTL0) = RXFRM)

#define S12CAN_ACKNOWLEDGE_RECEPTION(n) S12CAN_REG8(n, CANRFLG)    = RXF
#define S12CAN_ACKNOWLEDGE_WUP_INTR(n)  S12CAN_REG8(n, CANRFLG)    = WUPIF

/*
**  Global Functions.
*/

 #if 0
/* Initialization-Mode --> "Soft Reset State" in Rev 0.11 */
/* Sleep-Mode. */
/* Power-Down-Mode. */
/* Listen-only Mode n/a in Rev 0.11. */
typedef enum tagS12Can_ModeType {
    S12CAN_MODE_INITIALISATION,     /* "Soft Reset State" */
    S12CAN_MODE_NORMAL,
    S12CAN_MODE_SLEEP,
    /* [TRANSITION_TO | TRANSITION_FROM]_SLEEP */
    S12CAN_MODE_POWER_DOWN
} S12Can_ModeType;
#endif

/*  Refactored common stuff to 'mscan'. */

void S12Can_Init(S12Can_ConfigType const * const ConfigPtr)
{
    CAN = ConfigPtr;

    S12Can_InitController((uint8)0);
    S12Can_InitController((uint8)1);
    S12Can_InitController((uint8)2);
    S12Can_InitController((uint8)3);
    S12Can_InitController((uint8)4);
}


void S12Can_InitController(uint8 Controller)
{
    uint16                          Base       = S12Can_ControllerMapping[Controller];
    S12Can_ConfigType const * const ConfigPtr  = &CAN[Controller];

#if 0                             /* todo: Option 'ENTER_SLEEP_MODE_BEFORE_SOFT_RESET' */
    S12Can_RequestEnterSleepMode(Controller);
    WAIT_FOR(S12Can_InSleepMode(Controller));
#endif

    S12Can_EnterInitialisationMode(Controller);

    if ((ConfigPtr->CanCtl1 & CANE) == (uint8)0x00) {
        S12CAN_REG8(Base, CANCTL1) = (uint8)0x11;
        return;
    }

    S12CAN_REG8(Base, CANCTL1) = ConfigPtr->CanCtl1;

    S12CAN_REG8(Base, CANBTR0) = ConfigPtr->CanBtr0;
    S12CAN_REG8(Base, CANBTR1) = ConfigPtr->CanBtr1;

    S12CAN_REG8(Base, CANIDAC) = ConfigPtr->CanIdac;

    S12Can_SetIdentifier(Base + CANIDMR0, ConfigPtr->Filter[0].IdentifierMask);
    S12Can_SetIdentifier(Base + CANIDMR4, ConfigPtr->Filter[1].IdentifierMask);
    S12Can_SetIdentifier(Base + CANIDAR0, ConfigPtr->Filter[0].IdentifierAcceptance);
    S12Can_SetIdentifier(Base + CANIDAR4, ConfigPtr->Filter[1].IdentifierAcceptance);

#if 0
    S12Can_RequestLeaveSleepMode(Controller);
    WAIT_FOR(!S12Can_InSleepMode(Controller));
#endif
    S12Can_LeaveInitialisationMode(Controller);

    S12CAN_REG8(Base, CANCTL0) = ConfigPtr->CanCtl0;
    S12CAN_REG8(Base, CANRIER) = ConfigPtr->CanRier;
}


boolean S12Can_Transmit(uint8 Controller, MSCan_MessageType const * Message, uint8 priority,
                        /*@out@*/ uint8 * SentOnBuffer)
{
    uint16                  Base = S12Can_ControllerMapping[Controller];
    S12Can_TxBufferType *   TxFG;
    uint8                   NumberOfBuffer;

    TxFG = (S12Can_TxBufferType *)&S12CAN_REG8(Base, CANTXFG);

    NumberOfBuffer                 = S12CAN_REG8(Base, CANTFLG);
    S12CAN_REG8(Base, CANTBSEL)    = NumberOfBuffer; /* Select Buffer. */
    NumberOfBuffer                 = S12CAN_REG8(Base, CANTBSEL);

    if (NumberOfBuffer == (uint8)0x00) {
        return FALSE;
    }

    TxFG->DLR = Message->DLR;

    TxFG->TBPR = priority;  /* todo: keep track of the lowest priority msg. (Cancelation !!!). */

    if (MSCAN_IS_EXTENDED_ID(Message->ID)) {
        MSCan_Set29BitIdentifier(&TxFG->IDR, Message->ID);

        if (MSCAN_IS_RTR(Message->ID)) {
            TxFG->IDR.b[3] |= BIT0;
        }
    } else {
        MSCan_Set11BitIdentifier(&TxFG->IDR, Message->ID);

        if (MSCAN_IS_RTR(Message->ID)) {
            TxFG->IDR.b[1] |= BIT4;
        }
    }

    if ((Message->DLR != (uint8)0x00) && (!MSCAN_IS_RTR(Message->ID))) {

        Utl_MemCopy((void *)&TxFG->DSR, (void *)Message->SDU, (uint16)Message->DLR);

    }

    S12CAN_REG8(Base, CANTFLG)     = NumberOfBuffer; /* Transmit Buffer. */
    S12CAN_REG8(Base, CANTIER)    |= NumberOfBuffer;

    if (SentOnBuffer != (uint8 *)NULL) {
        *SentOnBuffer = NumberOfBuffer;
    }

    S12Can_TxBufferToID[Controller][NumberOfBuffer] = (Message->ID & (uint32)0x1FFFFFFFUL);

    return TRUE;
}


/* Lokale Prioritäten offline berechnen!? (AUTOSAR). - Was ist mit dynamischen PDUs? */

void S12Can_AbortTransmission(uint8 Controller, uint8 Number)
{
/*  static boolean AbortRequest[5][3]; */
    uint16 Base = S12Can_ControllerMapping[Controller];

    /* Hinweis: der Transmit-Interrupt muss enabled sein!!! */
    S12CAN_REG8(Base, CANTARQ)        |= (1 << Number);
    S12Can_AbortRequests[Controller]  |= Number;
}


S12Can_ModeType S12Can_GetMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    if ((S12CAN_REG8(Base, CANCTL0) & INITAK) == INITAK) {
        return S12CAN_MODE_INITIALISATION;
    }

    return S12CAN_MODE_NORMAL;
}


void  S12Can_EnterInitialisationMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    S12CAN_REG8(Base, CANCTL0) |= INITRQ;

    WAIT_FOR((S12CAN_REG8(Base, CANCTL0) & INITAK) == INITAK);
}


void  S12Can_LeaveInitialisationMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    S12CAN_REG8(Base, CANCTL0) &= ~INITRQ;

    WAIT_FOR((S12CAN_REG8(Base, CANCTL0) & INITAK) == (uint8)0x00);
}


/*  Request_SleepMode | Request_WakeUp */
void  S12Can_RequestEnterSleepMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    S12CAN_REG8(Base, CANCTL0) |= SLPRQ;
}


void  S12Can_RequestLeaveSleepMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    S12CAN_REG8(Base, CANCTL0) &= ~SLPRQ;
}


#if 0
boolean S12Can_Sleeping(S12Can_ConfigType const * const Cfg)

{

    return ((S12_REG8(Cfg, CANCTL0) & SLPRQ) == SLPRQ) && ((S12_REG8(Cfg, CANCTL1) & SLPAK) == SLPAK);

}


boolean S12Can_Initializing(S12Can_ConfigType const * const Cfg)

{

    return ((S12_REG8(Cfg, CANCTL0) & INITRQ) == INITRQ) && ((S12_REG8(Cfg, CANCTL1) & INITAK) == INITAK);

}


boolean S12Can_Synchronized(S12Can_ConfigType const * const Cfg)

{

    return (S12_REG8(Cfg, CANCTL0) & SYNCH) == SYNCH;

}


#endif

boolean S12Can_InSleepMode(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    return (S12CAN_REG8(Base, CANCTL1) & SLPAK) == SLPAK;

}


boolean S12Can_ReceivedMessage(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    return (S12CAN_REG8(Base, CANRFLG) & RXF) == RXF;
}


boolean S12Can_ControllerSynchedToBus(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    return (S12CAN_REG8(Base, CANCTL0) & SYNCH) == SYNCH;
}


/*
**  Local Functions.
*/
static void S12Can_SetIdentifier(uint16 addr, MSCan_IdentifierOverlayType value)
{
    *(uint8 *)(addr + 0)   = value.b[0];
    *(uint8 *)(addr + 1)   = value.b[1];
    *(uint8 *)(addr + 2)   = value.b[2];
    *(uint8 *)(addr + 3)   = value.b[3];
}


static void S12Can_GetIdentifier(uint16 addr, MSCan_IdentifierOverlayType * value)
{
    value->b[0]    = *(uint8 *)(addr + 0);
    value->b[1]    = *(uint8 *)(addr + 1);
    value->b[2]    = *(uint8 *)(addr + 2);
    value->b[3]    = *(uint8 *)(addr + 3);
}


void S12Can_SetSDU()
{

}

void S12Can_GetSDU()
{

}


/*
**  ISRs.
*/

void TxCallback(uint8 Controller, MSCan_IdType id)
{
    static uint16   cnt;
    static uint8    c2;

    cnt++;

    if ((cnt % 0x100) == 0) {
        c2++;
    }
}


void AbortCallback(uint8 Controller, MSCan_IdType id)
{

}


/* static */ void S12Can_HandleTx(uint8 Controller)
{
    uint16  Base = S12Can_ControllerMapping[Controller];
    uint8   flags;
    uint8   idx;

    if (S12Can_AbortRequests[Controller] != (uint8)0x00) {
        flags = S12CAN_REG8(Base, CANTAAK);

        flags                              = S12Can_AbortRequests[Controller] & S12CAN_REG8(Base, CANTFLG);
        S12Can_AbortRequests[Controller]   = flags;

        idx = (uint8)0;

        while (flags != (uint8)0) {
            if ((flags & BIT0) == BIT0) {
                AbortCallback(Controller, S12Can_TxBufferToID[Controller][idx]);
            }

            idx++;
            flags >>= 1;
        }
    } else {    /* funktioniert dieses XOR-Handling wirklich??? */
        idx = (uint8)0;

        flags = S12CAN_REG8(Base, CANTFLG);

        while (flags != (uint8)0) {
            if ((flags & BIT0) == BIT0) {
                TxCallback(Controller, S12Can_TxBufferToID[Controller][idx]);
            }

            idx++;
            flags >>= 1;
        }
    }

    flags  = ~S12CAN_REG8(Base, CANTFLG);
    flags &=  S12CAN_REG8(Base, CANTIER) & (uint8)0x07;

    S12CAN_REG8(Base, CANTIER) = flags;
}


static void S12Can_HandleRx(uint8 Controller)
{
    /* AUTOSAR-Handler: discard RTR-Frames!!! */
    /* check: FilterID als Callback-Parameter!? */
    uint16                      Base = S12Can_ControllerMapping[Controller];
    S12Can_RxBufferType const * RxFG;
    MSCan_IdType                id;

    uint8 len;

    RxFG = (S12Can_RxBufferType *)&S12CAN_REG8(Base, CANRXFG);

    if ((RxFG->IDR.b[1] & BIT3) == BIT3) {
        MSCan_Get29BitIdentifier(&RxFG->IDR, &id);
    } else {
        MSCan_Get11BitIdentifier(&RxFG->IDR, &id);
    }

    /* todo: Callback!!! */

    len = MAX(MSCAN_MAX_LSDU_LEN, RxFG->DLR);

    S12CAN_ACKNOWLEDGE_RECEPTION(Base);
}


static void S12Can_HandleError(uint8 Controller)
{
    uint16  Base = S12Can_ControllerMapping[Controller];
    uint8   error, status;
    uint8   flags;

    flags  = S12CAN_REG8(Base, CANRFLG);
    status = ( flags & 0x3c) >> 2;

    if ((flags & CSCIF) == CSCIF) {
        S12CAN_REG8(Base, CANRFLG) = CSCIF;
    } else if ((flags & OVRIF) == OVRIF) {
        S12CAN_REG8(Base, CANRFLG) = OVRIF;
    }
}


static void S12Can_HandleWakeUp(uint8 Controller)
{
    uint16 Base = S12Can_ControllerMapping[Controller];

    S12CAN_ACKNOWLEDGE_WUP_INTR(Base);
}


/* ///////////////// */
/* ///////////////// */
/* ///////////////// */

/*
** CAN #0
*/
ISR1(S12Can0_TxHandler)
{
    S12Can_HandleTx(0);
}

ISR1(S12Can0_RxHandler)
{
    S12Can_HandleRx(0);
}

ISR1(S12Can0_ErrHandler)
{
    S12Can_HandleError(0);
}

ISR1(S12Can0_WupHandler)
{
    S12Can_HandleWakeUp(0);
}

/*
** CAN #1
*/
ISR1(S12Can1_TxHandler)
{
    S12Can_HandleTx(1);
}

ISR1(S12Can1_RxHandler)
{
    S12Can_HandleRx(1);
}

ISR1(S12Can1_ErrHandler)
{
    S12Can_HandleError(1);
}

ISR1(S12Can1_WupHandler)
{
    S12Can_HandleWakeUp(1);
}

/*
** CAN #2
*/
ISR1(S12Can2_TxHandler)
{
    S12Can_HandleTx(2);
}

ISR1(S12Can2_RxHandler)
{
    S12Can_HandleRx(2);
}

ISR1(S12Can2_ErrHandler)
{
    S12Can_HandleError(2);
}

ISR1(S12Can2_WupHandler)
{
    S12Can_HandleWakeUp(2);
}

