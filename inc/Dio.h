/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
#if !defined(__DIO_H)
#define __DIO_H

#if defined(DioVersionInfoApi)
Dio_GetVersionInfo(...)
#endif /* DioVersionInfoApi */

#include "Std_Types.h"
#include "Dio_Cfg.h"

#define DIO_E_PARAM_INVALID_CHANNEL_ID	((uint8)10)
#define DIO_E_PARAM_INVALID_PORT_ID	((uint8)20)
#define DIO_E_PARAM_INVALID_GROUP_ID	((uint8)31)

typedef uint8 Dio_ChannelType;
typedef uint8 Dio_PortType;

typedef struct tagDio_ChannelGroupType {
    uint8 offset;
    Dio_PortType port;
    uint8 mask;
} Dio_ChannelGroupType;

typedef enum tagDio_LevelType {
#if 0
    STD_LOW,
    STD_HIGH
#endif
    DIO_LOW,
    DIO_HIGH
} Dio_LevelType;

typedef uint8 Dio_PortLevelType;

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
void Dio_WriteChannel(Dio_ChannelType ChannelId,Dio_LevelType Level);
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
void Dio_WritePort(Dio_PortType PortId,Dio_PortLevelType Level);
Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr);
void Dio_WriteChannelGroup(const Dio_ChannelGroupType *ChannelGroupIdPtr,Dio_PortLevelType Level);
void Dio_GetVersionInfo(Std_VersionInfoType *VersionInfo);


#endif /* __DIO_H */

