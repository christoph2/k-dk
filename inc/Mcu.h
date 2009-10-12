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

#if !defined(__MCU_H)
#define __MCU_H

#include "Std_Types.h"
#include "EcuM.h"
#include "Mcu_Cfg.h"

#if defined(xxx_VERSION_INFO_API)
xxx_GetVersionInfo(...)
#endif /* xxx_VERSION_INFO_API */

#define MCU_E_PARAM_CONFIG	((uint8)0x0a)
#define MCU_E_PARAM_CLOCK	((uint8)0x0b)
#define MCU_E_PARAM_MODE	((uint8)0x0c)
#define MCU_E_PARAM_RAMSECTION	((uint8)0x0d)
#define MCU_E_PLL_NOT_LOCKED	((uint8)0x0e)
#define MCU_E_UNINIT		((uint8)0x0f)
#define MCU_E_CLOCK_FAILURE	((uint8)0x10)	/* Assigned by DEM */

typedef struct tagMcu_ConfigType {

} Mcu_ConfigType;

typedef enum tagMcu_PllStatusType {
    MCU_PLL_LOCKED,
    MCU_PLL_UNLOCKED,
    MCU_PLL_STATUS_UNDEFINED
} Mcu_PllStatusType;

typedef uint8 Mcu_ClockType;

typedef enum tagMcu_ResetType {
    MCU_POWER_ON_RESET,
    MCU_WATCHDOG_RESET,
    MCU_SW_RESET,
    MCU_RESET_UNDIFINED
} Mcu_ResetType;

typedef uint8 Mcu_RawResetType;
typedef uint8 Mcu_ModeType;
typedef uint8 Mcu_RamSectionType;


void Mcu_Init(const Mcu_ConfigType *ConfigPtr);
Std_ReturnType Mcu_InitRamSection(Mcu_RamSectionType RamSection);
Std_ReturnType Mcu_InitClock(Mcu_ClockType ClockSetting);
void Mcu_DistributePllClock(void);
Mcu_PllStatusType Mcu_GetPllStatus(void);
Mcu_ResetType Mcu_GetResetReason(void);
Mcu_RawResetType Mcu_GetResetRawValue(void);
void Mcu_PerformReset(void);
void Mcu_SetMode(Mcu_ModeType McuMode);
void Mcu_GetVersionInfo(Std_VersionInfoType *versioninfo);

#endif /* __MCU_H */

