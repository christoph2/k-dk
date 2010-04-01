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

#if !defined(__ISO_TP_H)
#define __ISO_TP_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "Utl.h"

/*
**  Global Macros.
*/

#define ISOTP_MAX_PDU_LEN   ((uint16)0x0fffU)

/* NCPI-Types.  */
#define ISOTP_NPCI_TYPE_SF  ((uint8)0x00)   /* Single Frame.        */
#define ISOTP_NPCI_TYPE_FF  ((uint8)0x10)   /* First Frame.         */
#define ISOTP_NPCI_TYPE_CF  ((uint8)0x20)   /* Consecutive Frame.   */
#define ISOTP_NPCI_TYPE_FC  ((uint8)0x30)   /* Flow Control.        */

/* Flow-Control-Types.  */
#define ISOTP_FC_NPDU_CTS   ((uint8)0x00)
#define ISOTP_FC_NPDU_WAIT  ((uint8)0x01)
#define ISOTP_FC_NPDU_OVFLW ((uint8)0x02)

/*
**  Global Function-like Macros.
*/

/* Macros for Protocol-Control-Information.    */
    /* todo: Address-Extension berücksichtigen!!!   */
#define ISOTP_SET_SF_PCI(frame,len)                                                         \
    _BEGIN_BLOCK                                                                            \
        (frame)->SDU[0]=(ISOTP_NPCI_TYPE_SF & (uint8)0xf0) | (LOBYTE((len)) & (uint8)0x0f); \
    _END_BLOCK

#define ISOTP_SET_FF_PCI(frame,len)                                                         \
    _BEGIN_BLOCK                                                                            \
        (frame)->SDU[0]=(ISOTP_NPCI_TYPE_FF & (uint8)0xf0) | (HIBYTE((len)) & (uint8)0x0f); \
        (frame)->SDU[1]=LOBYTE((len));                                                      \
    _END_BLOCK

#define ISOTP_SET_CF_PCI(frame,sn)                                                          \
    _BEGIN_BLOCK                                                                            \
        (frame)->SDU[0]=(ISOTP_NPCI_TYPE_CF & (uint8)0xf0) | (LOBYTE((sn)) & (uint8)0x0f);  \
    _END_BLOCK

#define ISOTP_SET_FC_PCI(frame,fs,block_size,st_min)                                        \
    _BEGIN_BLOCK                                                                            \
        (frame)->SDU[0]=(ISOTP_NPCI_TYPE_FC & (uint8)0xf0) | (LOBYTE((fs)) & (uint8)0x0f);  \
        (frame)->SDU[1]=(uint8)((block_size) & (uint8)0xff);                                \
        (frame)->SDU[2]=(uint8)((st_min) & (uint8)0xff);                                    \
    _END_BLOCK


/*
**  Global Types.
*/

/* Maps to the AUTOSAR-Parameter 'CAN-TP-CONNECTION-CHANNEL:AR:MULTICAST-ADDRESSING'. */
typedef enum tagIsoTp_TA_TypeType {
    N_TA_TYPE_PHYSICAL,     /* 1:1 comm., for all types of NL-Messages. */
                            /* Point to point communication, e.g.       */
                            /* 'ReadDataByteByIdentifier',              */
                            /* 'InputOutputControlByIdentifier'.        */

    N_TA_TYPE_FUNCTIONAL    /* 1:N comm., only for SFs.                 */
                            /* Broadcast communication, phys. addr. of  */
                            /* ECU not known, e.g. 'ECU_RESET',         */
                            /* 'COMMUNICATION_CONTROL'.                 */
                            /* OBD communication will always be         */
                            /* performed as part of functional          */
                            /* addressing.                              */
} IsoTp_TA_TypeType;


typedef struct tagIsoTp_N_AI {      /* Network Address Information.     */
    uint8 N_SA;                     /* Network Source Address.          */
    uint8 N_TA;                     /* Network Target Address.          */
    IsoTp_TA_TypeType N_TA_Type;    /* Network Target Address Type.     */
} IsoTp_N_AI;


typedef enum tagIsoTp_Result_USDT {
    ISOTP_N_OK,
    ISOTP_N_TIMEOUT_A,      /* ISOTP_N_TIMEOUT_Ar, ISOTP_N_TIMEOUT_As. */
    ISOTP_N_TIMEOUT_Bs,
    ISOTP_N_TIMEOUT_Cr,
    ISOTP_N_WRONG_SN ,
    ISOTP_N_UNEXP_NPDU,
    ISOTP_N_WFT_OVRN
} IsoTp__Result_USDT;

void IsoTp_Init(void);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __ISO_TP_H */
