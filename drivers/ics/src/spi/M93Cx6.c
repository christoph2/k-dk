/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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

/*
**
**          VARIANTS
**          ========
**
**          Number of Address-Bits:
**          -----------------------
**                | x8-ORG  x16-ORG
**          ------|----------------
**          06/46 | 7       6
**          56/66 | 9       8
**          76/86 | 11      10
**          -----------------------
**          The smaller parts are ignoring bits according to their memsize.
**          Unused fill bits (EWEN,EWDS,ERAL,WRAL) = Adressbits minus two.
**
*/

/*
**
**  CAT93C46/56/57/66/86 are:        1K/2K/2K/4K/16K-bit.
**
**
*/

/*
**  todo: BUSY-Handling, switch to BitBang for ERASE/WRITE.
*/

#include "M93Cx6.h"

#define M93Cx6_X16
#define M93Cx6_X8

#define M93Cx6_16K
#define M93Cx6_8K
#define M93Cx6_4K
#define M93Cx6_2K
#define M93Cx6_1K
#define M93Cx6_256

/*
**  Local Defines.
*/
#define M93Cx6_OP_ERASE BIN8(111)

#define M93Cx6_OP_ERAL  BIN8(10010)
#define M93Cx6_OP_EWDS  BIN8(10000)
#define M93Cx6_OP_EWEN  BIN8(10011)

#define M93Cx6_OP_READ  BIN8(110)
#define M93Cx6_OP_WRITE BIN8(101)

#define M93Cx6_OP_WRAL  BIN8(10001)

/*
**  Local Functions.
*/
static void M93Cx6_WriteAddr(uint8 opcode, uint16 addr);
static void M93Cx6_WriteOpcodeOnly(uint8 opcode);


/*
**  Global Functions.
*/
boolean M93Cx6_Erase(uint16 addr)
{

}


boolean M93Cx6_EraseAll(void)
{
    M93Cx6_WriteOpcodeOnly(M93Cx6_OP_ERAL);
}


boolean M93Cx6_EraseWriteEnable(void)
{
    M93Cx6_WriteOpcodeOnly(M93Cx6_OP_EWEN);
}


boolean M93Cx6_EraseWriteDisable(void)
{
    M93Cx6_WriteOpcodeOnly(M93Cx6_OP_EWDS);
}


uint16 M93Cx6_Read(uint16 addr)
{
    M93Cx6_WriteAddr(M93Cx6_OP_READ, addr);
}


boolean M93Cx6_Write(uint16 addr, uint16 data)
{
    uint8 foo;

    M93Cx6_WriteAddr(M93Cx6_OP_WRITE, addr);
    foo    = HC12Spi_IOByte(&SPI0, HIBYTE(data));
    foo    = HC12Spi_IOByte(&SPI0, LOBYTE(data));
}


boolean M93Cx6_WriteAll(uint16 data)
{
    M93Cx6_WriteOpcodeOnly(M93Cx6_OP_WRAL);
}


/*
**  Local Functions.
*/
void M93Cx6_WriteAddr(uint8 opcode, uint16 addr)
{
    uint8 data;

    data = HC12Spi_IOByte(&SPI0, opcode << 5);

    data = HC12Spi_IOByte(&SPI0, addr);
}


void M93Cx6_WriteOpcodeOnly(uint8 opcode)
{
    uint8 data;

    data   = HC12Spi_IOByte(&SPI0, opcode << 3);
    data   = HC12Spi_IOByte(&SPI0, 0x00);
}


