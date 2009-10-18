/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
#if !defined(__HC12_BCIO_H)
#define	__HC12_BCIO_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/

#define PORTA       ((uint8)0x00)

#define PORTB       ((uint8)0x01)

#define DDRA        ((uint8)0x02)

#define DDRB        ((uint8)0x03)

/*
**  0x04-0x07 Reserved.
*/

#define PORTE       ((uint8)0x08)

#define DDRE        ((uint8)0x09)

#define PEAR        ((uint8)0x0A)
    /* PEAR-Bits.   */
    #define NDBE    ((uint8)0x80)
    #define CGMTE   ((uint8)0x40)
    #define PIPOE   ((uint8)0x20)
    #define NECLK   ((uint8)0x10)
    #define LSTRE   ((uint8)0x08)
    #define RDWE    ((uint8)0x04)
    #define CALE    ((uint8)0x02)
    #define DBENE   ((uint8)0x01)

#define MODE        ((uint8)0x0B)
    /* MODE-Bits.   */
    #define SMODN   ((uint8)0x80)
    #define MODB    ((uint8)0x40)
    #define MODA    ((uint8)0x20)
    #define ESTR    ((uint8)0x10)
    #define IVIS    ((uint8)0x08)
    #define EBSWAI  ((uint8)0x04)
    #define EMK     ((uint8)0x02)
    #define EME     ((uint8)0x01)

#define PUCR        ((uint8)0x0C)
    /* PUCR-Bits.   */
    #define PUPK    ((uint8)0x80)
    #define PUPJ 
  ((uint8)0x40)
    #define PUPH    ((uint8)0x20)
    #define PUPE    ((uint8)0x10)
    #define PUPB    ((uint8)0x02)
    #define PUPA    ((uint8)0x01)

#define RDRIV       ((uint8)0x0D)
    /* RDRIV-Bits.  */
    #define RDPK    ((uint8)0x80)
    #define RDPJ    ((uint8)0x40)
    #define RDPH    ((uint8)0x20)
    #define RDPE    ((uint8)0x10)
    #define RDPB    ((uint8)0x02)
    #define RDPA    ((uint8)0x01)

/*
**  0x0E,0x0F Reserved.
*/


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __HC12_BCIO_H */
