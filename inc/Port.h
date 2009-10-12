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
#if !defined(__PORT_H)
#define __PORT_H

#include "EcuM.h"
#include "Std_Types.h"
#include "Port_Cfg.h"

#if defined(xxx_VERSION_INFO_API)
xxx_GetVersionInfo(...)
#endif /* xxx_VERSION_INFO_API */

#define PORT_E_PARAM_PIN		((uint8)0x0a)
#define PORT_E_DIRECTION_UNCHANGEBLE	((uint8)0x0b)
#define PORT_E_PARAM_CONFIG		((uint8)0x0c)
#define PORT_E_PARAM_INVALID_MODE	((uint8)0x0d)
#define PORT_E_MODE_UNCHANGEABLE	((uint8)0x0e)
#define PORT_E_UNINIT			((uint8)0x0f)

typedef struct tagPort_ConfigType {

} Port_ConfigType;

typedef uint8 Port_PinType;

typedef enum tagPort_PinDirectionType {
    PORT_PIN_IN,
    PORT_PIN_OUT
} Port_PinDirectionType; 

#define PORT_PIN_LEVEL_LOW  ((uint8)0x00)
#define PORT_PIN_LEVEL_HIGH ((uint8)0x01)

#define PORT_PIN_MODE_ADC	((uint8)0x00)
#define PORT_PIN_MODE_CAN	((uint8)0x01)
#define PORT_PIN_MODE_DIO	((uint8)0x02)
#define PORT_PIN_MODE_DIO_GPT	((uint8)0x03)
#define PORT_PIN_MODE_DIO_WDG	((uint8)0x04)
#define PORT_PIN_MODE_FLEXRAY	((uint8)0x05)
#define PORT_PIN_MODE_ICU	((uint8)0x06)
#define PORT_PIN_MODE_LIN	((uint8)0x07)
#define PORT_PIN_MODE_MEM	((uint8)0x08)
#define PORT_PIN_MODE_MEM	((uint8)0x09)
#define PORT_PIN_MODE_PWM	((uint8)0x0a)
#define PORT_PIN_MODE_SPI	((uint8)0x0b)

#define PORT_PIN_MODE_IIC	((uint8)0x0c)
#define PORT_PIN_MODE_OCU	((uint8)0x0d)
#define PORT_PIN_MODE_SCI	((uint8)0x0e)


typedef uint8 Port_PinModeType;


void Port_Init(const Port_ConfigType *ConfigPtr);
void Port_SetPinDirection(Port_PinType Pin,Port_PinDirectionType Direction);
void Port_RefreshPortDirection(void);
void Port_GetVersionInfo(Std_VersionInfoType *VersionInfo);
void Port_SetPinMode(Port_PinType Pin,Port_PinModeType Mode);

#endif /* __PORT_H */

