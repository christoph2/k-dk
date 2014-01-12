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
 */
#if !defined(__S12SCI_H)
#define __S12SCI_H

/******************************************************************************************
 *                                     INCLUDE-FILES                                       *
 *******************************************************************************************/

#include "S12_Crg.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** Register-Offsets
*/

#define SCIBD       ((uint8)0x00)

#define SCIBDH      ((uint8)0x00)
/*  SCIBDH-Bits.  */
    #define SBR12   ((uint8)0x10)
    #define SBR11   ((uint8)0x08)
    #define SBR10   ((uint8)0x04)
    #define SBR9    ((uint8)0x02)
    #define SBR8    ((uint8)0x01)

#define SCIBDL      ((uint8)0x01)
/*  SCIBDL-Bits.  */
    #define SBR7    ((uint8)0x80)
    #define SBR6    ((uint8)0x40)
    #define SBR5    ((uint8)0x20)
    #define SBR4    ((uint8)0x10)
    #define SBR3    ((uint8)0x08)
    #define SBR2    ((uint8)0x04)
    #define SBR1    ((uint8)0x02)
    #define SBR0    ((uint8)0x01)

#define SCICR1      ((uint8)0x02)
/*  SCCR1-Bits. */
    #define LOOPS   ((uint8)0x80)
    #define SCISWAI ((uint8)0x40)
    #define RSRC    ((uint8)0x20)
    #define M       ((uint8)0x10)
    #define WAKE    ((uint8)0x08)
    #define ILT     ((uint8)0x04)
    #define PE      ((uint8)0x02)
    #define PT      ((uint8)0x01)

#define SCICR2      ((uint8)0x03)
/*  SCICR2-Bits.  */
    #define SCTIE   ((uint8)0x80)
    #define TCIE    ((uint8)0x40)
    #define RIE     ((uint8)0x20)
    #define ILIE    ((uint8)0x10)
    #define TE      ((uint8)0x08)
    #define RE      ((uint8)0x04)
    #define RWU     ((uint8)0x02)
    #define SBK     ((uint8)0x01)

#define SCISR1      ((uint8)0x04)
/*  SCISR1-Bits.  */
    #define TDRE    ((uint8)0x80)
    #define TC      ((uint8)0x40)
    #define RDRF    ((uint8)0x20)
    #define SCIDLE  ((uint8)0x10)
    #define OR      ((uint8)0x08)
    #define NF      ((uint8)0x04)
    #define FE      ((uint8)0x02)
    #define PF      ((uint8)0x01)

#define SCISR2      ((uint8)0x05)
/*  SCSR2-Bits. */
    #define BRK13   ((uint8)0x04)
    #define TXDIR   ((uint8)0x02)
    #define RAF     ((uint8)0x01)

#define SCIDR       ((uint8)0x06)

#define SCIDRH      ((uint8)0x06)

#define SCIDRL      ((uint8)0x07)

/******************************************************************************************
*                                     DATA-TYPES                                          *
******************************************************************************************/

typedef enum tagS12Sci_StatusType {
    S12SCI_OK,
    S12SCI_UNINIT,
    S12SCI_ID,
    S12SCI_STATE,
    S12SCI_VALUE

} S12Sci_StatusType;

typedef enum tagComParityType {
    SCI_PARITY_NONE,
    SCI_PARITY_ODD,
    SCI_PARITY_EVEN
} ComParityType;

typedef struct tagS12Sci_VariablesType {
    /*@only@*/ uint8 * RESTRICT RxBufAddr;
    uint8                       RxBufLength;
    uint8                       RxHead;
    uint8 volatile              RxTail;
    uint8                       LastError;

    /*@only@*/ uint8 const * RESTRICT   TxBufAddr;
    uint8                               TxBufLength;
    uint8 volatile                      TxBufPtr;
} S12Sci_VariablesType;

typedef void (*HW_EventNotifyFunc)(void);

typedef struct tagS12Sci_ConfigType {
    uint32                                              BaudRate;
    ComParityType                                       Parity;
    uint8                                               NBits;
    uint8 *                                             RxBufAddr;
    uint8                                               RxBufLength;
    /*@only@*/ S12Sci_VariablesType * RESTRICT const    Vars;
    HW_EventNotifyFunc                                  CharReceived;
    HW_EventNotifyFunc                                  TransmissionCompleted;
} S12Sci_ConfigType;

/******************************************************************************************
 *                                 GLOBAL-VARIABLES                                        *
 *******************************************************************************************/

/******************************************************************************************
 *                                     MAKROS                                              *
 *******************************************************************************************/

/******************************************************************************************
 *                                FUNCTION-PROTOTYPES                                       *
 *******************************************************************************************/

#define S12SCI_GET_CONFIGURATION() HW_GET_CONFIGURATION(S12Sci_Configuration, Cfg, id, S12SCI_ID)

void    S12Sci_Init(uint8 Controller);
void    S12Sci_EnableInterrupts(uint8 Controller, boolean ena);
void    S12Sci_SetBaud(uint8 Controller, uint32 baud);
void    S12Sci_SetFormat(uint8 Controller, uint32 baudrate, uint8 parity, uint8 nbits);
void    S12Sci_Get(uint8 Controller, /*@out@*/ uint8 * ch);
void    S12Sci_Put(uint8 Controller, uint8 ch);
void    S12Sci_PutString(uint8 Controller, /*@in@*/ uint8 const * str);
void    S12Sci_SendBuffer(uint8 Controller, /*@in@*/ uint8 const * buf, uint8 len);
void    S12Sci_SendBreak(uint8 Controller);

S12Sci_StatusType S12Sci_TxReady(S12Sci_ConfigType const * const Cfg, /*@out@*/ boolean * ready);

void    S12Sci_SetRxBuffer(S12Sci_ConfigType const * const Cfg, uint8 * buf, uint8 len);
void    S12Sci_SetTxBuffer(S12Sci_ConfigType const * const Cfg, uint8 * buf, uint8 len);

S12Sci_StatusType   S12Sci_RxBufIsEmpty(S12Sci_ConfigType const * const Cfg, /*@out@*/ boolean * empty);
S12Sci_StatusType   S12Sci_RxBufGetCh(S12Sci_ConfigType const * const Cfg, /*@out@*/ uint8 * ch);
S12Sci_StatusType   S12Sci_RxBufFlush(S12Sci_ConfigType const * const Cfg);
S12Sci_StatusType   S12Sci_TxBufFlush(S12Sci_ConfigType const * const Cfg);

uint8 S12Sci_GetLastError(S12Sci_ConfigType const * const Cfg);

S12Sci_StatusType S12Sci_Handler(S12Sci_ConfigType const * const Cfg);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12SCI_H */
