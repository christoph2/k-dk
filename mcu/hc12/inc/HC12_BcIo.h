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
/* #if 0 */
#define PUPJ ((uint8)0x40)
/* #endif */
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


#define HC12BCIO_CHANNEL_A_0             ((Kdk_ChannelType)0x00)
#define HC12BCIO_CHANNEL_A_1             ((Kdk_ChannelType)0x01)
#define HC12BCIO_CHANNEL_A_2             ((Kdk_ChannelType)0x02)
#define HC12BCIO_CHANNEL_A_3             ((Kdk_ChannelType)0x03)
#define HC12BCIO_CHANNEL_A_4             ((Kdk_ChannelType)0x04)
#define HC12BCIO_CHANNEL_A_5             ((Kdk_ChannelType)0x05)
#define HC12BCIO_CHANNEL_A_6             ((Kdk_ChannelType)0x06)
#define HC12BCIO_CHANNEL_A_7             ((Kdk_ChannelType)0x07)

#define HC12BCIO_CHANNEL_B_0             ((Kdk_ChannelType)0x08)
#define HC12BCIO_CHANNEL_B_1             ((Kdk_ChannelType)0x09)
#define HC12BCIO_CHANNEL_B_2             ((Kdk_ChannelType)0x0a)
#define HC12BCIO_CHANNEL_B_3             ((Kdk_ChannelType)0x0b)
#define HC12BCIO_CHANNEL_B_4             ((Kdk_ChannelType)0x0c)
#define HC12BCIO_CHANNEL_B_5             ((Kdk_ChannelType)0x0d)
#define HC12BCIO_CHANNEL_B_6             ((Kdk_ChannelType)0x0e)
#define HC12BCIO_CHANNEL_B_7             ((Kdk_ChannelType)0x0f)

#define HC12BCIO_CHANNEL_E_0             ((Kdk_ChannelType)0x10)
#define HC12BCIO_CHANNEL_E_1             ((Kdk_ChannelType)0x11)
#define HC12BCIO_CHANNEL_E_2             ((Kdk_ChannelType)0x12)
#define HC12BCIO_CHANNEL_E_3             ((Kdk_ChannelType)0x13)
#define HC12BCIO_CHANNEL_E_4             ((Kdk_ChannelType)0x14)
#define HC12BCIO_CHANNEL_E_5             ((Kdk_ChannelType)0x15)
#define HC12BCIO_CHANNEL_E_6             ((Kdk_ChannelType)0x16)
#define HC12BCIO_CHANNEL_E_7             ((Kdk_ChannelType)0x17)
#define HC12BCIO_CHANNEL_MAX             HC12BCIO_CHANNEL_E_7

#define HC12BCIO_PORT_A                  ((Kdk_PortType)0x00)
#define HC12BCIO_PORT_B                  ((Kdk_PortType)0x01)
#define HC12BCIO_PORT_E                  ((Kdk_PortType)0x02)
#define HC12BCIO_PORT_MAX                HC12BCIO_PORT_E
/*
**  0x0E,0x0F Reserved.
*/


typedef struct tagHC12BcIo_ConfigType {
    uint16 BaseAddr;

    uint8 DdrA;
    uint8 DdrB;
    uint8 DdrE;
    uint8 PortA;
    uint8 PortB;
    uint8 PortE;
    uint8 Pucr;
    uint8 Rdriv;
} HC12BcIo_ConfigType;


typedef enum tagHC12BcIo_ModeType {
    HC12MODE_SPECIAL_SINGLE_CHIP,
    HC12MODE_EMULATION_NARROW,
    HC12MODE_SPECIAL_TEST,
    HC12MODE_EMULATION_WIDE,
    HC12MODE_NORMAL_SINGLE_CHIP,
    HC12MODE_NORMAL_EXPANDED_NARROW,
    HC12MODE_SPECIAL_PERIPHAL,
    HC12MODE_NORMAL_EXPANDED_WIDE
} HC12BcIo_ModeType;

void HC12BcIo_Init(void);

HC12BcIo_ModeType HC12BcIo_GetMode(void);
boolean HC12BcIo_SpecialMode(void);

void HC12BcIo_WritePort(Kdk_PortType port,Kdk_PortLevelType value);
Kdk_PortLevelType HC12BcIo_ReadPort(Kdk_PortType port);

#if defined(__K_AUTOSAR)
void HC12BcIo_WriteChannel(Kdk_PortType port,Kdk_ChannelType bit,Kdk_LevelType level);
Kdk_LevelType HC12BcIo_ReadChannel(Kdk_PortType port,Kdk_ChannelType bit);
#else
void S12Mebi_WriteChannel(Kdk_ChannelType channel,Kdk_LevelType level);
Kdk_LevelType S12Mebi_ReadChannel(Kdk_ChannelType channel);
#endif /* __K_AUTOSAR */

void HC12BcIo_WriteChannelGroup(Kdk_ChannelGroupType const * group,Kdk_PortLevelType level);
Kdk_PortLevelType HC12BcIo_ReadChannelGroup(Kdk_ChannelGroupType const * group);

#if defined(__K_AUTOSAR)
void HC12BcIo_SetPinDirection(Kdk_PortType port,Kdk_ChannelType bit,Kdk_PinDirectionType Direction);
#else
void HC12BcIo_SetPinDirection(Kdk_PinType Pin,Kdk_PinDirectionType Direction);
#endif /* __K_AUTOSAR */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __HC12_BCIO_H */
