/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__STD_TYPES_H)
#define	__STD_TYPES_H

#include "Std_Macros.h"
#include "Platform_Types.h"
#include "Compiler.h"
#include "Os_Types.h"

#define E_NOT_OK    ((uint8)0x01)

#define STD_HIGH    ((uint8)0x01)
#define STD_LOW     ((uint8)0x00)

#define STD_ACTIVE  ((uint8)0x01)
#define STD_IDLE    ((uint8)0x00)

#define STD_ON      0x01
#define STD_OFF     0x00

typedef uint8 Std_ReturnType;

/*
typedef enum tagStd_ReturnType {
    E_OK,
    E_NOT_OK
} Std_ReturnType;
*/

typedef struct tagStd_VersionInfoType {
    uint16 vendorID;
    uint16 moduleID;
    uint8 instanceID;
    uint8 sw_major_version;
    uint8 sw_minor_version;
    uint8 sw_patch_version;
} Std_VersionInfoType;


typedef enum tagStd_LevelType {
    Std_Low=STD_LOW,
    Std_High=STD_HIGH
} Std_LevelType;

#endif	/* __STD_TYPES_H  */

