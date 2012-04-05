/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__HC12_KWIO_H)
#define __HC12_KWIO_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define PORTJ                   ((uint8)0x00)

#define PORTH                   ((uint8)0x01)

#define DDRJ                    ((uint8)0x02)

#define DDRH                    ((uint8)0x03)

#define KWIEJ                   ((uint8)0x04)

#define KWIEH                   ((uint8)0x05)

#define KWIFJ                   ((uint8)0x06)

#define KWIFH                   ((uint8)0x07)

#define KWPJ                    ((uint8)0x08)

#define KWPH                    ((uint8)0x09)

/*
** Symbolic Names for Port-Pins.
*/
#define HC12KWIO_CHANNEL_J_0    ((Kdk_ChannelType)0x00)
#define HC12KWIO_CHANNEL_J_1    ((Kdk_ChannelType)0x01)
#define HC12KWIO_CHANNEL_J_2    ((Kdk_ChannelType)0x02)
#define HC12KWIO_CHANNEL_J_3    ((Kdk_ChannelType)0x03)
#define HC12KWIO_CHANNEL_J_4    ((Kdk_ChannelType)0x04)
#define HC12KWIO_CHANNEL_J_5    ((Kdk_ChannelType)0x05)
#define HC12KWIO_CHANNEL_J_6    ((Kdk_ChannelType)0x06)
#define HC12KWIO_CHANNEL_J_7    ((Kdk_ChannelType)0x07)

#define HC12KWIO_CHANNEL_H_0    ((Kdk_ChannelType)0x08)
#define HC12KWIO_CHANNEL_H_1    ((Kdk_ChannelType)0x09)
#define HC12KWIO_CHANNEL_H_2    ((Kdk_ChannelType)0x0A)
#define HC12KWIO_CHANNEL_H_3    ((Kdk_ChannelType)0x0B)
#define HC12KWIO_CHANNEL_H_4    ((Kdk_ChannelType)0x0C)
#define HC12KWIO_CHANNEL_H_5    ((Kdk_ChannelType)0x0D)
#define HC12KWIO_CHANNEL_H_6    ((Kdk_ChannelType)0x0E)
#define HC12KWIO_CHANNEL_H_7    ((Kdk_ChannelType)0x0F)

/*
**	Global Types.
*/
typedef struct tagHC12KwIo_ConfigType {
    uint8   DdrJ;
    uint8   PortJ;
    uint8   KwieJ;
    uint8   KwpJ;

    uint8   DdrH;
    uint8   PortH;
    uint8   KwieH;
    uint8   KwpH;
} HC12KwIo_ConfigType;

/*
** Global Variables.
*/
extern HC12KwIo_ConfigType const * KWIO;

/*
** Global Functions.
*/
void HC12KwIo_Init(HC12KwIo_ConfigType const * const ConfigPtr);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_KWIO_H */

