/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__VCAN_H)
#define __VCAN_H

#include "mcu/inc/mscan.h"  // ??

#include "Utl.h"


#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**      Global Types.
*/
typedef enum tagVCan_ModeType {
    VCAN_MODE_INITIALISATION,
    VCAN_MODE_NORMAL,
    VCAN_MODE_SLEEP,
    VCAN_MODE_POWER_DOWN,
    VCAN_MODE_BUSOFF
} VCan_ModeType;

typedef enum tagVCan_StatusType {
    VCAN_OK,
    VCAN_UNINIT,
    VCAN_ID,
    VCAN_STATE,
    VCAN_VALUE

} VCan_StatusType;

typedef struct tagVCan_TxBufferType {
    MSCan_IdentifierOverlayType IDR;
    uint8                       DSR[MSCAN_MAX_LSDU_LEN];
    uint8                       DLR;
    uint8                       TBPR;
    uint8                       Unused[2];
} VCan_TxBufferType;

typedef struct tagVCan_RxBufferType {
    MSCan_IdentifierOverlayType IDR;
    uint8                       DSR[MSCAN_MAX_LSDU_LEN];
    uint8                       DLR;
    uint8                       Unused[1];
    uint8                       TSRH;
    uint8                       TSRL;
} VCan_RxBufferType;

typedef struct tagVCan_ConfigType {
    MSCan_FilterType    Filter[2];
    uint8               CanCtl0;
    uint8               CanCtl1;
    uint8               CanBtr0;
    uint8               CanBtr1;
    uint8               CanRier;
    uint8               CanIdac;
} VCan_ConfigType;

/*
** Global Functions.
*/
void    VCan_Init(VCan_ConfigType const * const Cfg);
void    VCan_InitController(uint8 Controller);

boolean VCan_Transmit(uint8 Controller, MSCan_MessageType const * Message, uint8 Priority, /*@out@*/ uint8 * SentOnBuffer);
void    VCan_AbortTransmission(uint8 Controller, uint8 Number);

void    VCan_EnterInitialisationMode(uint8 Controller);
void    VCan_LeaveInitialisationMode(uint8 Controller);
void    VCan_RequestEnterSleepMode(uint8 Controller);
void    VCan_RequestLeaveSleepMode(uint8 Controller);
boolean VCan_InSleepMode(uint8 Controller);

VCan_StatusType   VCan_Stop(VCan_ConfigType const * const Cfg);
VCan_StatusType   VCan_InitializationMode(VCan_ConfigType const * const Cfg, boolean enable);
VCan_StatusType   VCan_SleepMode(VCan_ConfigType const * const Cfg, boolean enable);

boolean VCan_Enabled(VCan_ConfigType const * const Cfg);
boolean VCan_Sleeping(VCan_ConfigType const * const Cfg);
boolean VCan_Initializing(VCan_ConfigType const * const Cfg);
boolean VCan_Synchronized(VCan_ConfigType const * const Cfg);

VCan_StatusType   VCan_SetBusTiming(VCan_ConfigType const * const Cfg, uint8 btr0, uint8 btr1);
VCan_StatusType   VCan_SetFilter(VCan_ConfigType const * const Cfg, const MSCan_FilterType * Filter);
VCan_StatusType   VCan_EnableInterrupts(VCan_ConfigType const * const Cfg, boolean enable);
VCan_StatusType   VCan_Ready(VCan_ConfigType const * const Cfg, /*@out@*/ boolean * ready);
VCan_StatusType   VCan_RxD(VCan_ConfigType const * const Cfg, /*@out@*/ boolean * rxd);
VCan_StatusType   VCan_WaitSynch(VCan_ConfigType const * const Cfg);
VCan_StatusType   VCan_CopyRxBuffer(VCan_ConfigType const * const Cfg, /*@out@*/ MSCan_MessageType * Message);
VCan_StatusType   VCan_GetErrorCounters(VCan_ConfigType const * const Cfg, uint8 * RxErrors, /*@out@*/ uint8 * TxErrors);


/*
**  ISR-Handlers.
*/
void    Can_HandleIrqTx(VCan_ConfigType const * const Cfg);
void    Can_HandleIrqRx(VCan_ConfigType const * const Cfg);
void    Can_HandleIrqErr(VCan_ConfigType const * const Cfg);
void    Can_HandleIrqWup(VCan_ConfigType const * const Cfg);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __VCAN_H */
