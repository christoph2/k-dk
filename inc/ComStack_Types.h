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
#if !defined(__COMSTACK_TYPES_H)
#define __COMSTACK_TYPES_H

#include "Std_Types.h"

typedef uint8 PduIdType;
    #define PduIdmax        ((PduIdType)-1)

typedef uint8 PduLengthType;
    #define PduLengthmax    ((PduLengthType)-1)

typedef struct tagPduInfoType {
    uint8 *SduDataPtr;
    PduLengthType SduLength;
} PduInfoType;

typedef enum tagBufReq_ReturnType {
    BUFREQ_OK,BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef uint8 NotifResultType;
	#define NTFRSLT_OK              0x00
	#define NTFRSLT_E_NOT_OK        0x01
	#define NTFRSLT_E_TIMEOUT_A     0x02
	#define NTFRSLT_E_TIMEOUT_Bs    0x03
	#define NTFRSLT_E_TIMEOUT_Cr    0x04
	#define NTFRSLT_E_WRONG_SN      0x05
	#define NTFRSLT_E_INVALID_FS    0x06
	#define NTFRSLT_E_UNEXP_PDU     0x07
	#define NTFRSLT_E_WFT_OVRN      0x08
	#define NTFRSLT_E_NO_BUFFER     0x09
	
typedef uint8 BusTrcvErrorType;
	#define BUSTRCV_NO_ERROR        0x00
	#define BUSTRCV_E_ERROR         0x01

#endif	/* __COMSTACK_TYPES_H */
