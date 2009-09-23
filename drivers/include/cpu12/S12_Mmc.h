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
#if !defined(__S12_MMC_H)
#define __S12_MMC_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define INITRM      ((uint8)0x10)
    /*  INITRM-Bits.  */
    #define RAM15   ((uint8)0x80)
    #define RAM14   ((uint8)0x40)
    #define RAM13   ((uint8)0x20)
    #define RAM12   ((uint8)0x10)
    #define RAM11   ((uint8)0x08)
    #define RAMHAL  ((uint8)0x01)

#define INITRG      ((uint8)0x11)
    /*  INITRG-Bits.  */
    #define REG14   ((uint8)0x40)
    #define REG13   ((uint8)0x20)
    #define REG12   ((uint8)0x10)
    #define REG11   ((uint8)0x08)
    
#define INITEE      ((uint8)0x12)
    /*  INITEE-Bits.  */
    #define EE15    ((uint8)0x80)
    #define EE14    ((uint8)0x40)
    #define EE13    ((uint8)0x20)
    #define EE12    ((uint8)0x10)
    #define EEON    ((uint8)0x01)

#define MISC        ((uint8)0x13)
    /*  MISC-Bits.  */
    #define EXSTR1  ((uint8)0x08)
    #define EXSTR0  ((uint8)0x04)
    #define ROMHM   ((uint8)0x02)
    #define ROMON   ((uint8)0x01)
    
#define MTSTO       ((uint8)0x14)

#define MTST1       ((uint8)0x17)

#define MEMSIZ0     ((uint8)0x1C)
    /*  MEMSIZ0-Bits. */
    #define REG_SW0 ((uint8)0x80)
    #define EEP_SW1 ((uint8)0x20)
    #define EEP_SW0 ((uint8)0x10)
    #define RAM_SW2 ((uint8)0x04)
    #define RAM_SW1 ((uint8)0x02)
    #define RAM_SW0 ((uint8)0x01)
    
#define MEMSIZ1     ((uint8)0x1D)
    /*  MEMSIZ1-Bits. */
    #define ROM_SW1 ((uint8)0x80)
    #define ROM_SW0 ((uint8)0x40)
    #define PAG_SW1 ((uint8)0x02)
    #define PAG_SW0 ((uint8)0x01)
    
#define PPAGE       ((uint8)0x30)
    /*  PPAGE-Bits. */
    #define PIX5    ((uint8)0x20)
    #define PIX4    ((uint8)0x10)
    #define PIX3    ((uint8)0x08)
    #define PIX2    ((uint8)0x04)
    #define PIX1    ((uint8)0x02)
    #define PIX0    ((uint8)0x01)
    
/*
**  0x31 - Reserved    
*/


typedef enum tagS12Mmc_StatusType {
    S12MMC_OK
} S12Mmc_StatusType;    

typedef struct tagS12Mmc_ConfigType {
    uint16 BaseAddr;
    uint8 InitRM;
    uint8 InitRG;
    uint8 InitEE;    
    uint8 Misc;    
} S12Mmc_ConfigType;

S12Mmc_StatusType S12Mmc_Init(void);
S12Mmc_StatusType S12Mmc_SetPPage(uint8 ppage);
S12Mmc_StatusType S12Mmc_GetPPage(uint8 *ppage);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_MMC_H*/
