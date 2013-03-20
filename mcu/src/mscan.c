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
 */

#include "mcu/inc/mscan.h"

void MSCan_Set11BitIdentifier(MSCan_IdentifierOverlayType * Identifier, MSCan_IdType ID)
{
    Identifier->b[0]   = (uint8)(ID & (MSCan_IdType)0x000007f8ul) >> 3;
    Identifier->b[1]   = (uint8)(ID & (MSCan_IdType)0x00000007ul) << 5;
}


void MSCan_Get11BitIdentifier(MSCan_IdentifierOverlayType const * Identifier, MSCan_IdType * ID)
{
    *ID = (MSCan_IdType)((uint16)Identifier->b[0] << 3) | ((uint16)Identifier->b[1] >> 5);
}


void MSCan_Set29BitIdentifier(MSCan_IdentifierOverlayType * Identifier, MSCan_IdType ID)
{
    uint8 hh, hl, lh, ll;

    hh = HIBYTE(HIWORD(ID));
    hl = LOBYTE(HIWORD(ID));
    lh = HIBYTE(LOWORD(ID));
    ll = LOBYTE(LOWORD(ID));

    Identifier->b[0]   = (hh << 3) | (hl >> 5);
    Identifier->b[1]   = ((hl << 3) & (uint8)0xe0) | ((uint8)0x18) | ((hl << 1) & (uint8)0x06) |
                         ((lh & (uint8)0x80) == 0x80 ? (uint8)0x01 : (uint8)0x00);
    Identifier->b[2]   = (lh << 1) | ((ll & (uint8)0x80) == 0x80 ? (uint8)0x01 : (uint8)0x00);
    Identifier->b[3]   = ll << 1;
}


void MSCan_Get29BitIdentifier(MSCan_IdentifierOverlayType const * Identifier, MSCan_IdType * ID)
{
    *ID = MAKEDWORD(
        MAKEWORD(
            (Identifier->b[0] >> 3),
            ((Identifier->b[0] & (uint8)0x07) << 5) | ( (Identifier->b[1] & (uint8)0xe0) >> 3 ) |
            ((Identifier->b[1] & (uint8)0x06) >> 1)
            ),
        MAKEWORD(
            (Identifier->b[2] >> 1) | ((Identifier->b[1] & (uint8)0x01) == (uint8)0x01 ? (uint8)0x80 : (uint8)0x00),
            (Identifier->b[3] >> 1) | ((Identifier->b[2] & (uint8)0x01) == (uint8)0x01 ? (uint8)0x80 : (uint8)0x00)
            )
        );
}


