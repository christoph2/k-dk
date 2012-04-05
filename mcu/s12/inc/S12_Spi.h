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
#if !defined(__S12_SPI_H)
#define __S12_SPI_H

#include "S12_Hw.h"

/*
** Register-Offsets.
*/
#define SPICR1      ((uint8)0x00)
/*  SPICR1-Bits.  */
    #define SPIE    ((uint8)0x80)
    #define SPE     ((uint8)0x40)
    #define SPTIE   ((uint8)0x20)
    #define MSTR    ((uint8)0x10)
    #define CPOL    ((uint8)0x08)
    #define CPHA    ((uint8)0x04)
    #define SSOE    ((uint8)0x02)
    #define LSBFE   ((uint8)0x01)

#define SPICR2      ((uint8)0x01)
/*  SPICR2-Bits.  */
    #define MODFEN  ((uint8)0x10)
    #define BIDIROE ((uint8)0x08)
    #define SPISWAI ((uint8)0x02)
    #define SPC0    ((uint8)0x01)

#define SPIBR       ((uint8)0x02)
/*  SPIBR-Bits. */
    #define SPPR2   ((uint8)0x40)
    #define SPPR1   ((uint8)0x20)
    #define SPPR0   ((uint8)0x10)
    #define SPR2    ((uint8)0x04)
    #define SPR1    ((uint8)0x02)
    #define SPR0    ((uint8)0x01)

#define SPISR       ((uint8)0x03)
/*  SPISR-Bits. */
    #define SPIF    ((uint8)0x80)
    #define SPTEF   ((uint8)0x20)
    #define MODF    ((uint8)0x10)

/*
**  0x04 Reserved.
*/

#define SPIDR       ((uint8)0x05)

/*
**  0x06-0x07 Reserved.
*/

/*
** global Types.
*/

typedef struct tagS12Spi_VariablesType {
    uint8 * IOBufAddr;
    uint8   IOBufLength;
    uint8   IOBufPtr;
} S12Spi_VariablesType;

typedef struct tagS12Spi_ConfigType {
    uint8                           num;
    uint8                           BaudRateDivisor;
    S12Spi_VariablesType * const    Vars;
} S12Spi_ConfigType;

void    S12Spi_InitController(uint8 Controller);
void    S12Spi_SetPrescaler(uint8 Controller, uint8 prescaler);
void    S12Spi_SetFormat(uint8 Controller, boolean cpol, boolean cpha, boolean lsbfe);

boolean S12Spi_TxReady(uint8 Controller);

uint8   S12Spi_IOByte(uint8 Controller, uint8 data);
void    S12Spi_IOBuffer(uint8 Controller, uint8 * data, uint8 len, boolean use_interrupt);


#endif  /* __S12_SPI_H */
