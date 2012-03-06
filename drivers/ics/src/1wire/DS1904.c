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

#include "DS1904.h"

#define DS1904_OSC_ENABLE   ((uint8)0x0c)
#define DS1904_CLOCK_READ   ((uint8)0x66)
#define DS1904_CLOCK_WRITE  ((uint8)0x99)

/*
**
**  Device Driver for the Dallas DS1904/DS2415 (Family-Code: 0x24).
**
**  - Real-Time Clock in binary format.
**  - Resolution: 1 Second.
**
*/

void DS1904_ClockRead(OW_ConfigType const * const ConfigPtr, DS1904_ClockType * Clock)
{
    uint8 buf[5];

    OW_WriteByte(ConfigPtr, DS1904_CLOCK_READ);

    OW_ReadBlock(ConfigPtr, buf, 5);
    Clock->OscEnable   = (buf[0] & DS1904_OSC_ENABLE) == DS1904_OSC_ENABLE;
    Clock->UserFlags   = (buf[0] & (uint8)0xf0) >> 4;
    Clock->RefPoint    = MAKEDWORD(MAKEWORD(buf[4], buf[3]), MAKEWORD(buf[2], buf[1]));
}


void DS1904_ClockWrite(OW_ConfigType const * const ConfigPtr, DS1904_ClockType const * Clock)
{
    OW_WriteByte(ConfigPtr, DS1904_CLOCK_WRITE);

    OW_WriteByte(ConfigPtr, (((Clock->UserFlags & (uint8)0x0f) << 4) | (Clock->OscEnable ? DS1904_OSC_ENABLE : (uint8)0x00)));
    OW_WriteByte(ConfigPtr, LOBYTE(LOWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr, HIBYTE(LOWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr, LOBYTE(HIWORD(Clock->RefPoint)));
    OW_WriteByte(ConfigPtr, HIBYTE(HIWORD(Clock->RefPoint)));
}

