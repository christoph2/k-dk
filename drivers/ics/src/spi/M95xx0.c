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
#include "M95xx0.h"
#include "Hw_Cfg.h"


/*
**
**  Hardware-Dependent and blocking Routines for now.
**
*/

/*
**  todo: Das gesamte Slave-Select-Handling gehört in das SPI-Modul!!!
*/

/*
**  Local Defines.
*/

/*  M95xx0-Instruction-Codes.   */
#define M95XX0_INS_WREN     ((uint8)0x06)   /* Write Enable.                    */
#define M95XX0_INS_RDSR     ((uint8)0x05)   /* Read Status Register.            */
#define M95XX0_INS_WRDI     ((uint8)0x04)   /* Write Disable.                   */
#define M95XX0_INS_READ     ((uint8)0x03)   /* Read from Memory Array.          */
#define M95XX0_INS_WRITE    ((uint8)0x02)   /* Write to Memory Array.           */
#define M95XX0_INS_WRSR     ((uint8)0x01)   /* Write Status Register.           */


void M95xx0_Init(void)
{
    S12PIM_REG8(PTS)|=PTS7;
    S12PIM_REG8(DDRS)|=DDRS7;
    /* todo: Set SPI-Format. */
}


/*
**  Write-Enable (WREN) must be excuted prior to each WRITE- or WRSR-Instruction.
*/
void M95xx0_WriteEnable(void)
{
    S12PIM_REG8(PTS)&=~PTS7;
    (void)S12Spi_IOByte(SPI0,M95XX0_INS_WREN);
    S12PIM_REG8(PTS)|=PTS7;
}


void M95xx0_WriteDisable(void)
{
    S12PIM_REG8(PTS)&=~PTS7;
    (void)S12Spi_IOByte(SPI0,M95XX0_INS_WRDI);
    S12PIM_REG8(PTS)|=PTS7;
}


uint8 M95xx0_ReadStatusRegister(void)
{
    uint8 result;

    S12PIM_REG8(PTS)&=~PTS7;
    (void)S12Spi_IOByte(SPI0,M95XX0_INS_RDSR);
    result=S12Spi_IOByte(SPI0,(uint8)0xff);
    S12PIM_REG8(PTS)|=PTS7;

    return result;
}


boolean M95xx0_Probe(void)
{
    uint8 sr;

    sr=M95xx0_ReadStatusRegister();

    /* Bits 4-6 are reserved and always read zero. */
    if ((sr & (uint8)0x70)!=(uint8)0x00) {
        return FALSE;
    }

    M95xx0_WriteEnable();
    sr=M95xx0_ReadStatusRegister();
    /* 'WEL'-Bit must be set now. */

    M95xx0_WriteDisable();
    sr=M95xx0_ReadStatusRegister();
    /* 'WEL'-Bit must be cleared now. */

    return TRUE;
}


void M95xx0_WriteStatusRegister(uint8 sr)
{
    S12PIM_REG8(PTS)&=~PTS7;
    (void)S12Spi_IOByte(SPI0,M95XX0_INS_WRSR);
    (void)S12Spi_IOByte(SPI0,sr);
    S12PIM_REG8(PTS)|=PTS7;
}


boolean M95xx0_ReadBytes(uint8 *data,uint16 len)
{

}


boolean M95xx0_WriteBytes(uint8 const *data,uint16 len)
{

}


boolean M95xx0_WriteInProgress(void)
{
    return (M95xx0_ReadStatusRegister() & M95XX0_SR_WIP)==M95XX0_SR_WIP;
}


M95XX0_ProtectionType M95xx0_GetProtection(void)
{
    return (M95XX0_ProtectionType)((M95xx0_ReadStatusRegister() & (M95XX0_SR_BP1|M95XX0_SR_BP0))>>2);
}


/*
** One can control the Hardware Write Protection using the /W-Pin
** (Either High or Low, not floating).
** (i.e. freeze the size of the area of memory that is protected against Write
** Instructions (as specified by the values in the BP0 and BP1 Bits of the Status Register))
** /W protects the block protection bits.
*/
void M95xx0_SetProtection(M95XX0_ProtectionType Protection)
{
#if 0
    ((((uint8)Protection)<<2) & 0xc0)
#endif
}
