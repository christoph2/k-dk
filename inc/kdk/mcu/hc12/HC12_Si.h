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
#if !defined(__HC12_SI_H)
#define __HC12_SI_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/

#define PORTS       ((uint8)0x00)

#define DDRS        ((uint8)0x01)

#if (CPU_DERIVATE == CPU12_HC12B32) || (CPU_DERIVATE == CPU12_HC12BC32) || (CPU_DERIVATE == CPU12_HC12BD32)
#define PURDS       ((uint8)0x05)
/* PURDS-Bits.  */
    #define RDPS2   ((uint8)0x40)
    #define RDPS1   ((uint8)0x20)
    #define RDPS0   ((uint8)0x10)
    #define PUPS2   ((uint8)0x04)
    #define PUPS1   ((uint8)0x02)
    #define PUPS0   ((uint8)0x01)
#endif /* CPU12_HC12B32 || CPU12_HC12BC32 || CPU12_HC12BD32 */

#if (CPU_DERIVATE == CPU12_HC12D60) || (CPU_DERIVATE == CPU12_HC12D60A) || \
    (CPU_DERIVATE == CPU12_HC12DG128A)  /* CHECK!!! */
#define PURDS       ((uint8)0x03)
/* PURDS-Bits.  */
    #define RDPS2   ((uint8)0x40)
    #define RDPS1   ((uint8)0x20)
    #define RDPS0   ((uint8)0x10)
    #define PUPS2   ((uint8)0x04)
    #define PUPS1   ((uint8)0x02)
    #define PUPS0   ((uint8)0x01)
#endif /* CPU12_HC12D60 || CPU12_HC12D60A */

typedef struct tagHC12Si_ConfigType {
    uint8   PortS;
    uint8   DdrS;

#if (CPU_DERIVATE != CPU12_HC12A4)
    uint8 PurdS;
#endif
} HC12Si_ConfigType;

void HC12Si_Init(HC12Si_ConfigType const * const ConfigPtr);

void                HC12Si_WritePort(Kdk_PortType port, Kdk_PortLevelType value);
Kdk_PortLevelType   HC12Si_ReadPort(Kdk_PortType port);


#if defined(__K_AUTOSAR)
void            HC12Si_WriteChannel(Kdk_PortType port, Kdk_ChannelType bit, Kdk_LevelType level);
Kdk_LevelType   HC12Si_ReadChannel(Kdk_PortType port, Kdk_ChannelType bit);


#else
void            HC12Si_WriteChannel(Kdk_ChannelType channel, Kdk_LevelType level);
Kdk_LevelType   HC12Si_ReadChannel(Kdk_ChannelType channel);


#endif /* __K_AUTOSAR */

void                HC12Si_WriteChannelGroup(Kdk_ChannelGroupType const * group, Kdk_PortLevelType level);
Kdk_PortLevelType   HC12Si_ReadChannelGroup(Kdk_ChannelGroupType const * group);


#if defined(__K_AUTOSAR)
void HC12Si_SetPinDirection(Kdk_PortType port, Kdk_ChannelType bit, Kdk_PinDirectionType Direction);


#else
void HC12Si_SetPinDirection(Kdk_PinType Pin, Kdk_PinDirectionType Direction);


#endif /* __K_AUTOSAR */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_SI_H */
