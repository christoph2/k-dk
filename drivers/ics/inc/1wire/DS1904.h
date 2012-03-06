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
#if !defined(__DS1904_H)
#define __DS1904_H

#include "OW_Api.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Global Types.
*/
typedef struct tagDS1904_ClockType {
    uint8   UserFlags;  /* Four non-volatile general-purpose user-flags. */
    boolean OscEnable;
    uint32  RefPoint;
} DS1904_ClockType;

/*
**  Global Functions.
*/
void    DS1904_ClockRead(OW_ConfigType const * const ConfigPtr, DS1904_ClockType * Clock);
void    DS1904_ClockWrite(OW_ConfigType const * const ConfigPtr, DS1904_ClockType const * Clock);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __DS1904_H */

