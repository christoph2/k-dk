/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the 
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__HC12_EEPA_H)
#define __HC12_EEPA_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**  Register-Offsets.
*/
#define EEDIVH      ((uint8)0x02)

#define EEDIVL      ((uint8)0x03)

#define EEMCR       ((uint8)0x04)
    /* EEMCR-Bits.  */
    #define NOBDML  ((uint8)0x80)
    #define NOSHW   ((uint8)0x40)
    #define EESWAI  ((uint8)0x04)
    #define PROTLCK ((uint8)0x02)
    #define DMY     ((uint8)0x01)

#define EEPROT      ((uint8)0x05)
    /* EEPROT-Bits. */
    #define SHPROT  ((uint8)0x80)
    #define BPROT5  ((uint8)0x20)
    #define BPROT4  ((uint8)0x10)
    #define BPROT3  ((uint8)0x08)
    #define BPROT2  ((uint8)0x04)
    #define BPROT1  ((uint8)0x02)
    #define BPROT0  ((uint8)0x01)

#define EETST       ((uint8)0x06)
    /* EETST-Bits.  */
    #define EREVTN  ((uint8)0x40)
    #define ETMSD   ((uint8)0x04)
    #define ETMR    ((uint8)0x02)
    #define ETMSE   ((uint8)0x01)

#define EEPROG      ((uint8)0x07)
    /* EEPROG-Bits  */
    #define BULKP   ((uint8)0x80)
    #define AUTO    ((uint8)0x20)
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


typedef enum tagHC12EepA_StatusType {
    HC12EEP_OK,
    HC12EEP_UNINIT,
    HC12EEP_ADDR,
    HC12EEP_PVIOL,
    HC12EEP_ALIGN,
    HC12EEP_NOT_ERASED
} HC12EepA_StatusType;

typedef struct tagHC12EepA_ConfigType {
    uint16 BaseAddr;

    uint16 EeDiv;
} HC12EepA_ConfigType;

/*
**  Basic EEP-Functions.
*/
void HC12EepA_Init(void);
void HC12EepA_Protect(boolean on);
void HC12EepA_LockProtectionState(void);
HC12EepA_StatusType HC12EepA_DoCmd(uint8 cmd,boolean b8,uint16 addr,uint16 data);

#define HC12EepA_ProgramWord(addr,data)     HC12EepA_DoCmd(HC12EE_PROG_WORD,FALSE,(addr),(data))
#define HC12EepA_ProgramByte(addr,data)     HC12EepA_DoCmd(HC12EE_PROG_BYTE,TRUE,(addr),(data))

#define HC12EepA_EraseByte(addr)            HC12EepA_DoCmd(HC12EE_ERASE_BYTE,TRUE,(addr),(uint16)0x0000U)
#define HC12EepA_EraseWord(addr)            HC12EepA_DoCmd(HC12EE_ERASE_WORD,FALSE,(addr),(uint16)0x0000U)
#define HC12EepA_EraseRow(addr)             HC12EepA_DoCmd(HC12EE_ERASE_ROW,TRUE,(addr),(uint16)0x0000U)
#define HC12EepA_EraseBulk()                HC12EepA_DoCmd(HC12EE_ERASE_BULK,TRUE,HC12EEP_START,(uint16)0x0000U)


/*
** 'High-Level' EEP-Functions.
*/
HC12EepA_StatusType HC12EepA_WriteByte(uint16 addr,uint8 data);
HC12EepA_StatusType HC12EepA_WriteWord(uint16 addr,uint16 data);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __HC12_EEPA_H */
