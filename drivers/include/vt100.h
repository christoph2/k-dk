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
#if !defined(__VT100_H)
#define __VT100_H

#include "Std_Types.h"
#include "ascii.h"
#include "S12_Sci.h"

#define VT100_CSI   "\x1b["   /* Control Sequence Introducer */


#define VT100_BUFFER_LEN    ((uint8)24)     /* Adjust for your needs! */

/*
**  Attributes (Select Graphics Redition
*/
#define VT_100_ATTRS_OFF    ((uint8)0)
#define VT_100_BOLD         ((uint8)1)
#define VT_100_UNDERSCORE   ((uint8)4)
#define VT_100_BLINK        ((uint8)5)
#define VT_100_REVERSE      ((uint8)7)

/*
**
**  Lolevel-Functions.
**
*/

/*
** Cursor-Functions.
*/

void VT100_CUU(uint8 distance,char *buf);           /* Cursor Up */
void VT100_CUD(uint8 distance,char *buf);           /* Cursor Down */
void VT100_CUF(uint8 distance,char *buf);           /* Cursor Foreward */
void VT100_CUB(uint8 distance,char *buf);           /* Cursor Backward */
void VT100_CUP(uint8 line,uint8 column,char *buf);  /* Cursor Position */
void VT100_CHOME(char *buf);                        /* Cursor Home */
void VT100_HVP(uint8 line,uint8 column,char *buf);  /* Cursor Position */


void VT100_SGR(const uint8 *attrs,uint8 len,char *buf);               /* Select Graphic Rendition */

void VT100_Send(const SCI_ConfigType *Cfg,const char *buf);

/*
**
**  Highlevel-Functions.
**
*/

void VT100_CursorUp(const SCI_ConfigType *Cfg,uint8 distance);
void VT100_CursorDown(const SCI_ConfigType *Cfg,uint8 distance);
void VT100_CursorRight(const SCI_ConfigType *Cfg,uint8 distance);
void VT100_CursorLeft(const SCI_ConfigType *Cfg,uint8 distance);
void VT100_CursorPosition(const SCI_ConfigType *Cfg,uint8 line,uint8 column);
void VT100_CursorHome(const SCI_ConfigType *Cfg);
void VT100_CharAttributes(const SCI_ConfigType *Cfg,const uint8 *attrs,uint8 len);

void VT100_RxHandler(char ch);

#endif /* __VT100_H */
