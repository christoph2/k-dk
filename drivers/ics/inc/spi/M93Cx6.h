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

#if !defined(__M93CX6_H)
#define __M93CX6_H

#include "HC12_Spi.h" /* todo: make independent of SPI-Impl. */
#include "Hw_Cfg.h"

boolean M93Cx6_Erase(uint16 addr);
boolean M93Cx6_EraseAll(void);
boolean M93Cx6_EraseWriteEnable(void);
boolean M93Cx6_EraseWriteDisable(void);
uint16  M93Cx6_Read(uint16 addr);
boolean M93Cx6_Write(uint16 addr, uint16 data);
boolean M93Cx6_WriteAll(uint16 data);   /* Fill - for convenience.  */

#endif /* __M93CX6_H */

