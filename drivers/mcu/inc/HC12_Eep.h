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
#if !defined(__HC12_EEP_H)
#define __HC12_EEP_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**  Register-Offsets.
*/

#define EEMCR       ((uint8)0x00)
    /* EEMCR-Bits.  */
    #define EESWAI  ((uint8)0x04)
    #define PROTLCK ((uint8)0x02)
    #define EERC    ((uint8)0x01)

#define EEPROT      ((uint8)0x01)
    /* EEPROT-Bits. */
    #define BPROT4  ((uint8)0x10)
    #define BPROT3  ((uint8)0x08)
    #define BPROT2  ((uint8)0x04)
    #define BPROT1  ((uint8)0x02)
    #define BPROT0  ((uint8)0x01)

#define EETST       ((uint8)0x02)
    /* EETST-Bits.  */
    #define EEODD   ((uint8)0x80)
    #define EEVEN   ((uint8)0x40)
    #define MARG    ((uint8)0x20)
    #define EECPD   ((uint8)0x10)
    #define EECPRD  ((uint8)0x08)
    #define EECPM   ((uint8)0x02)


#define EEPROG      ((uint8)0x03)
    /* EEPROG-Bits  */
    #define BULKP   ((uint8)0x80)
    #define BYTE    ((uint8)0x10)
    #define ROW     ((uint8)0x08)
    #define ERASE   ((uint8)0x04)
    #define EELAT   ((uint8)0x02)
    #define EEPGM   ((uint8)0x01)


/*
**  Global Defines.
*/

/*  Command-Codes.  */
#define HC12EE_PROG_BYTE    ((uint8)0x00)
#define HC12EE_PROG_WORD    ((uint8)0x00)
#define HC12EE_ERASE_BYTE   (ERASE|BYTE)
#define HC12EE_ERASE_WORD   (ERASE|BYTE)
#define HC12EE_ERASE_ROW    (ERASE|ROW)
#define HC12EE_ERASE_BULK   (ERASE)


typedef enum tagHC12Eep_StatusType {
    HC12EEP_OK,
    HC12EEP_UNINIT,
    HC12EEP_ADDR,
    HC12EEP_PVIOL,
    HC12EEP_ALIGN,
    HC12EEP_NOT_ERASED
} HC12Eep_StatusType;

typedef struct tagHC12Eep_ConfigType {
    uint16 BaseAddr;
} HC12Eep_ConfigType;

/*
**  Basic EEP-Functions.
*/
void HC12Eep_Init(void);
void HC12Eep_Protect(boolean on);
void HC12Eep_LockProtectionState(void);
HC12Eep_StatusType HC12Eep_DoCmd(uint8 cmd,boolean b8,uint16 addr,uint16 data);

#define HC12Eep_ProgramWord(addr,data)     HC12Eep_DoCmd(HC12EE_PROG_WORD,FALSE,(addr),(data))
#define HC12Eep_ProgramByte(addr,data)     HC12Eep_DoCmd(HC12EE_PROG_BYTE,TRUE,(addr),(data))

#define HC12Eep_EraseByte(addr)            HC12Eep_DoCmd(HC12EE_ERASE_BYTE,TRUE,(addr),(uint16)0x0000U)
#define HC12Eep_EraseWord(addr)            HC12Eep_DoCmd(HC12EE_ERASE_WORD,FALSE,(addr),(uint16)0x0000U)
#define HC12Eep_EraseRow(addr)             HC12Eep_DoCmd(HC12EE_ERASE_ROW,TRUE,(addr),(uint16)0x0000U)
#define HC12Eep_EraseBulk()                HC12Eep_DoCmd(HC12EE_ERASE_BULK,TRUE,HC12EEP_START,(uint16)0x0000U)


/*
** 'High-Level' EEP-Functions.
*/
HC12Eep_StatusType HC12Eep_WriteByte(uint16 addr,uint8 data);
HC12Eep_StatusType HC12Eep_WriteWord(uint16 addr,uint16 data);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __HC12_EEP_H */
