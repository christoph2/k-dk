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
 */
#if !defined(__FT12_H)
#define __FT12_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "Std_Types.h"
#include "Ft12_Cfg.h"

    
/*
**
**  FT1.2 protocol (IEC 870-5-1, 870-5-2 (DIN 19244)).
**
*/

#define FT12_FT_FIXED            ((uint8)0x10)
#define FT12_FT_VAR              ((uint8)0x68)
#define FT12_FT_STOP             ((uint8)0x16)
#define FT12_FT_ACK              ((uint8)0xe5)

#define FT12_SND_NKE             ((uint8)0x40)
#define FT12_SND_UD              ((uint8)0x43)
#define FT12_REQ_UD1             ((uint8)0x4A)
#define FT12_REQ_UD2             ((uint8)0x4B)
#define FT12_RSP_UD              ((uint8)0x08)

#define FT12_CF_DIR              ((uint8)0x80)
#define FT12_CF_PRM              ((uint8)0x40)
#define FT12_CF_FCB              ((uint8)0x20)
#define FT12_CF_ACD              ((uint8)0x20)
#define FT12_CF_RES              ((uint8)0x20)
#define FT12_CF_FCV              ((uint8)0x10)
#define FT12_CF_DFC              ((uint8)0x10)

#define FT12_ADDR_NC             ((uint8)0x00)
#define FT12_ADDR_NETWORK        ((uint8)0xfd)
#define FT12_ADDR_BROADCAST_ALL  ((uint8)0xfe)
#define FT12_ADDR_BROADCAST_NONE ((uint8)0x0f)

// Function-Codes.
#define FT12_FC_SEND_RESET       ((uint8)0x00)
#define FT12_FC_SEND_UDAT        ((uint8)0x03)
#define FT12_FC_REQ_STATUS       ((uint8)0x09)
#define FT12_FC_CONFIRM_ACK      ((uint8)0x00)
#define FT12_FC_CONFIRM_NACK     ((uint8)0x01)
#define FT12_FC_RESPOND_STATUS   ((uint8)0x0b)

typedef enum tagFt12_FrameType {
    FT_ACK_FRAME,
    FT_FIXED_FRAME,
    FT_VAR_FRAME
} Ft12_FrameType;

typedef enum tagFt12_FrameIndType {
    FT_ERR_OK,
    FT_ERR_INVALID,
    FT_ERR_CHECKSUM,
    FT_ERR_FRAMING
} Ft12_FrameIndType;

typedef struct tagFt12_FixedFrame {
    uint8 address;
    uint8 control;
} Ft12_FixedFrame;

typedef struct tagFt12_VarFrame {
    uint8 address;
    uint8 control;
    uint8 controlInformation;
    uint8 len;
    uint8 linkuserdata[FT12_BUFFER_SIZE];
} Ft12_VarFrame;

typedef struct tagFt12_Frame {
    Ft12_FrameType frameType;

    union {
        Ft12_FixedFrame fixed;
        Ft12_VarFrame var;
    } frame;
} Ft12_Frame;

typedef struct tagFt12_BufferType {
     uint8 len;
     uint8 fcb;
     uint8 data[FT12_BUFFER_SIZE];
} Ft12_BufferType;

#define FT12_SET_FCB(buffer)    ((buffer)->fcb = (uint8)0x01)
#define FT12_RESET_FCB(buffer)  ((buffer)->fcb = (uint8)0x00)
#define FT12_GET_FCB(buffer)    ((buffer)->fcb & 0x01)

#define FT12_PDU_LEN(buffer)    ((buffer)->len - 0x01)
#define FT12_PDU_PTR(buffer)    ((uint8*)((buffer) ->data + 0x05 ))

void Ft12_Init(Ft12_BufferType * buf);
void Ft12_MakeFixedLenFrame(uint8 address, uint8 control, Ft12_BufferType * buf);
void Ft12_MakeVarLenFrame(uint8 address, uint8 control, uint8 controlInformation, uint8 len, uint8 * linkuserdata, Ft12_BufferType * buf);
void Ft12_MakeControlFrame(uint8 address, uint8 control, uint8 controlInformation, Ft12_BufferType * buf);
void Ft12_MakeAckFrame(Ft12_BufferType * buf);

void Ft12_SendNke(uint8 address, Ft12_BufferType * buf);
void Ft12_ConfirmAck(uint8 address, Ft12_BufferType * buf);
void Ft12_ConfirmNack(uint8 address, Ft12_BufferType * buf);
void Ft12_StatusResp(uint8 address, Ft12_BufferType * buf);
void Ft12_ResetReq(uint8 address, Ft12_BufferType * buf);
void Ft12_StatusReq(uint8 address, Ft12_BufferType * buf);

Ft12_FrameIndType Ft12_FrameInd(Ft12_BufferType const * buf, Ft12_Frame * frame);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __FT12_H */

