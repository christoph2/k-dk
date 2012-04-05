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
#if !defined(__ASCII_H)
#define __ASCII_H

#define ASCII_NUL   ((uint8)0x00)
#define ASCII_SOH   ((uint8)0x01)
#define ASCII_STX   ((uint8)0x02)
#define ASCII_ETX   ((uint8)0x03)
#define ASCII_EQT   ((uint8)0x04)
#define ASCII_ENQ   ((uint8)0x05)
#define ASCII_ACK   ((uint8)0x06)
#define ASCII_BEL   ((uint8)0x07)
#define ASCII_BS    ((uint8)0x08)
#define ASCII_HT    ((uint8)0x09)
#define ASCII_LF    ((uint8)0x0a)
#define ASCII_VT    ((uint8)0x0b)
#define ASCII_FF    ((uint8)0x0c)
#define ASCII_CR    ((uint8)0x0d)
#define ASCII_SO    ((uint8)0x0e)
#define ASCII_SI    ((uint8)0x0f)
#define ASCII_DLE   ((uint8)0x10)
#define ASCII_DC1   ((uint8)0x11)
#define ASCII_DC2   ((uint8)0x12)
#define ASCII_DC3   ((uint8)0x13)
#define ASCII_DC4   ((uint8)0x14)
#define ASCII_NAK   ((uint8)0x15)
#define ASCII_SYN   ((uint8)0x16)
#define ASCII_ETB   ((uint8)0x17)
#define ASCII_CAN   ((uint8)0x18)
#define ASCII_EM    ((uint8)0x19)
#define ASCII_SUB   ((uint8)0x1a)
#define ASCII_ESC   ((uint8)0x1b)
#define ASCII_FS    ((uint8)0x1c)
#define ASCII_GS    ((uint8)0x1d)
#define ASCII_RS    ((uint8)0x1e)
#define ASCII_US    ((uint8)0x1f)
#define ASCII_SPACE ((uint8)0x20)
#define ASCII_DEL   ((uint8)0x7f)

#endif /* __ASCII_H */
