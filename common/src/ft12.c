/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
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
#include "kdk/common/Ft12.h"
#include <stdio.h>
#include <assert.h>

/*
**
**  FT1.2 protocol (IEC 870-5-1, 870-5-2 (DIN 19244)).
**
*/

void Ft12_Init(Ft12_BufferType * buf)
{
    uint8 idx;

    buf->fcb = 0x00;
    buf->len = 0x00;

    for (idx = 0x00; idx < FT12_BUFFER_SIZE; ++idx) {
        buf->data[idx] = 0x00;
    }
}

/*
fixed (short) Frame:
============
Start 10 h
Control field
Address field
Checksum
End 16 
*/
void Ft12_MakeFixedLenFrame(uint8 address, uint8 control, Ft12_BufferType * buf)
{
    control = (control | buf->fcb);
    buf->data[0] = FT12_FT_FIXED;
    buf->data[1] = control;
    buf->data[2] = address;  
    buf->data[3] = (control + address) % 256;  /* Checksum. */
    buf->data[4] = FT12_FT_STOP;
    buf->fcb = buf->fcb ^ FT12_CF_FCB;
    buf->len = 5;
}

/*
variable (long) Frame:
===============
Start 68 h
length L
length L
Start 68 h
Control field
Address field
Control-Information-Field
link user data
Checksum
End 16 
*/
void Ft12_MakeVarLenFrame(uint8 address, uint8 control, uint8 controlInformation, uint8 len, uint8 * linkuserdata, Ft12_BufferType * buf)
{
    uint8 idx;
    int checksum;
 
    control = (control | buf->fcb);
    checksum = control + address + controlInformation;
    buf->data[0] = FT12_FT_VAR;
    buf->data[1] = len + 3; // Control-Field + Address + Control-Information + User-Data.
    buf->data[2] = len + 3;
    buf->data[3] = FT12_FT_VAR;
    buf->data[4] = control;
    buf->data[5] = address;
    buf->data[6] = controlInformation;
 
    // Check: len max. 252
    for (idx=0; idx < len; ++idx) {
        //  checksum=checksum+linkuserdata[idx];
        buf->data[7 + idx] = linkuserdata[idx];
        checksum = checksum + (buf->data[7 + idx]);
    }
    checksum=checksum % 256;
    buf->data[7 + len] = checksum;
 
    buf->data[8 + len] = FT12_FT_STOP;
    buf->len = len + 9;
    buf->fcb = buf->fcb ^ FT12_CF_FCB;
}

/*
Control-Frame:
===============
Start 68 h
length L=3
length L=3
Start 68 h
Control field
Address field
Control-Information-Field
Checksum
End 16 h
*/
void Ft12_MakeControlFrame(uint8 address, uint8 control, uint8 controlInformation, Ft12_BufferType * buf)
{
    Ft12_MakeVarLenFrame(address, control, controlInformation, 0, (uint8 * )NULL, buf);
}


/*
    ACK Frame:
    ==========
    E5h
*/
void Ft12_MakeAckFrame(Ft12_BufferType * buf)
{
    buf->len = 0x01;
    buf->data[0x00] = FT12_FT_ACK;
}

void Ft12_SendNke(uint8 address, Ft12_BufferType * buf)
{
    Ft12_MakeFixedLenFrame(address, FT12_SND_NKE, buf);
}

void Ft12_ConfirmAck(uint8 address, Ft12_BufferType * buf)
{
    Ft12_MakeFixedLenFrame(address, FT12_FC_CONFIRM_ACK, buf);
}

void Ft12_ConfirmNack(uint8 address, Ft12_BufferType * buf)
{
    Ft12_MakeFixedLenFrame(address, FT12_FC_CONFIRM_NACK, buf);
}

void Ft12_StatusResp(uint8 address, Ft12_BufferType * buf)
{
    Ft12_MakeFixedLenFrame(address, FT12_FC_RESPOND_STATUS, buf);
}

void Ft12_ResetReq(uint8 address, Ft12_BufferType * buf)
{
    Ft12_MakeFixedLenFrame(address, FT12_CF_PRM | FT12_FC_SEND_RESET | buf->fcb, buf);
}

void Ft12_StatusReq(uint8 address, Ft12_BufferType * buf, uint8 sndFCB)
{
    Ft12_MakeFixedLenFrame(address, FT12_CF_PRM | FT12_FC_REQ_STATUS | buf->fcb, buf);
}

Ft12_FrameIndType Ft12_FrameInd(Ft12_BufferType const * buf, Ft12_Frame * frame)
{
    Ft12_FrameIndType result = FT_ERR_OK;

    assert(buf->len > 0);
    // TODO: Check framing and checksum!
    switch (buf->data[0]) {
        case FT12_FT_ACK:
            frame->frameType = FT_ACK_FRAME;
            printf("FT12-ACK.\n");
            break;
        case FT12_FT_FIXED:
            if (buf->data[3] != ((buf->data[2] + buf->data[1]) % 256)) {
                result = FT_ERR_CHECKSUM;
            } else {
                frame->frameType = FT_FIXED_FRAME;
                frame->frame.fixed.address = buf->data[2];
                frame->frame.fixed.control = buf->data[1];
                printf("FT12-FIXED.\n");
            }
            break;
        case FT12_FT_VAR:
            frame->frameType = FT_VAR_FRAME;
            printf("FT12-VAR.\n");
            break;
        default:
            result = FT_ERR_INVALID;  /* Ignore garbage. */
    }
    return result;
}

