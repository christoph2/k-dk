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

#include "HC12_Eep.h"
#include "Hw_Cfg.h"


void HC12Ect_DelayUS(uint16 uS);

void HC12Eep_Init(void)
{
    HC12EEP_REG8(EEMCR)|=EESWAI;
    HC12EEP_REG8(EEPROG)|=(BULKP);  /* if Busclock < fPROG, EERC is needed... */
    HC12EEP_REG8(EEPROG)&=~EEPGM;
}


void HC12Eep_Protect(boolean on)
{
    if (on) {
        HC12EEP_REG8(EEPROT)|=(uint8)0x1f;
        HC12EEP_REG8(EEPROG)|=BULKP;

    } else {
        HC12EEP_REG8(EEPROT)&=~((uint8)0x1f);
        HC12EEP_REG8(EEPROG)&=~BULKP;
    }
}


void HC12Eep_LockProtectionState(void)
{
    HC12EEP_REG8(EEMCR)|=PROTLCK;   /* Block-protection bits are now locked. */
}


HC12Eep_StatusType HC12Eep_DoCmd(uint8 cmd,boolean b8,uint16 addr,uint16 data)
{
    /*
    **
    **  tPROG:  min: 10.0 ms, max: 10.5 ms.
    **  tERASE: min: 10.0 ms.
    **
    */
    if ((addr<HC12EEP_START) || (addr>=(HC12EEP_START+HC12EEP_LEN))) {
        return HC12EEP_ADDR;
    }

    if (!((cmd & ERASE)==ERASE)) {
        if (!b8) {
            if ((addr & (uint16)0x0001U)==(uint16)0x0001U) {
                return HC12EEP_ALIGN;
            }
#if 0
            if (*(uint16*)addr!=(uint16)0xffffU) {
                return HC12EEP_NOT_ERASED;
            }
#endif
        } else {
#if 0
            if (*(uint8*)addr!=(uint8)0xff) {
                return HC12EEP_NOT_ERASED;
            }
#endif
        }
    } else {
        if ( ((cmd & (BYTE|ROW))==(uint8)0x00) && ((HC12EEP_REG8(EEPROG) & BULKP)==BULKP)) {
            return HC12EEP_PVIOL;
        }
    }

    if ((HC12EEP_REG8(EEPROT) & ((uint8)0x3f))!=(uint8)0x00) {
        return HC12EEP_PVIOL;
    }

    HC12EEP_REG8(EEPROG)&=~EEPGM;

    /* 1. Write BYTE|ROW|ERASE to desired value, write EELAT=1. */
    /* todo: Delay!!! */
    HC12EEP_REG8(EEPROG)=(cmd & (uint8)0x1c) | EELAT;

    /* 2. *Write a byte or aligned word to an EEPROM-Address. */
    if (b8) {
        *(uint8*)addr=LOBYTE(data);
    } else {
        *(uint16*)addr=data;
    }

    /* 3. Write EEPGM=1 */
    HC12EEP_REG8(EEPROG)|=EEPGM;

    WAIT_FOR(!((HC12EEP_REG8(EEPROG) & EEPGM)==EEPGM));

/* 6. Write EELAT=0 */
    HC12EEP_REG8(EEPROG)&=~EELAT;

    return HC12EEP_OK;
}


/*
**
**  'WriteByte()'/'WriteWord()' are erasing only if necessary,
**  selective write more zeros is also supported.
**
*/
HC12Eep_StatusType HC12Eep_WriteByte(uint16 addr,uint8 data)
{
    HC12Eep_StatusType status;

    if ((data | (*(uint8*)addr))!=(uint8)0xff) {
        status=HC12Eep_EraseByte(addr);

        if (status!=HC12EEP_OK) {
            return status;
        }
    }

    return HC12Eep_ProgramByte(addr,data);
}


HC12Eep_StatusType HC12Eep_WriteWord(uint16 addr,uint16 data)
{
    HC12Eep_StatusType status;

    if ((data | (*(uint16*)addr))!=(uint16)0xffffU) {
        status=HC12Eep_EraseWord(addr);

        if (status!=HC12EEP_OK) {
            return status;
        }
    }

    return HC12Eep_ProgramWord(addr,data);
}


void HC12Ect_DelayUS(uint16 uS)
{
    uint16 then=HC12Ect_TimerCount()+uS;

    WAIT_FOR(HC12Ect_TimerCount()>=then);
}
