/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__HC12IIC_H)
#define __HC12IIC_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "S12_Iic.h"

#define HC12Iic_ConfigType      S12Iic_ConfigType

#define HC12Iic_Init            S12Iic_Init
#define HC12Iic_Start           S12Iic_Start
#define HC12Iic_Restart         S12Iic_Restart
#define HC12Iic_Stop            S12Iic_Stop
#define HC12Iic_Write           S12Iic_Write
#define HC12Iic_Read            S12Iic_Read

#define HC12Iic_ReadMode        S12Iic_ReadMode
#define HC12Iic_WriteMode       S12Iic_WriteMode
#define HC12Iic_PresenceCheck   S12Iic_PresenceCheck

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12IIC_H */

