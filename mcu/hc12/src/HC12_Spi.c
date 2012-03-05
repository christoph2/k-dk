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
#include "HC12_Spi.h"
#include "Hw_Cfg.h"

/*
**  todo: HC12-SPI u. SCI zu SI (Serial Interface) bzw. MSI (Multiple Serial Interface) zusammenfassen.
*/

static uint16 HC12SPI_ControllerMapping[] = {   /* depends on derivate!!! */
    BASE_ADDR_SPI0,
};

static void HC12Spi_Handler(uint8 Controller);


void HC12Spi_InitController(uint8 Controller)
{
    uint16                              Base       = HC12SPI_ControllerMapping[Controller];
    HC12Spi_ConfigType const * const    ConfigPtr  = &HC12Spi_Configuration[Controller];
    volatile uint8                      dummy;

    HC12SPI_REG8(Base, PORTS)  = (uint8)0x00;
    HC12SPI_REG8(Base, DDRS)   = (uint8)0xe0;

    HC12SPI_REG8(Base, SPICR1) = MSTR | SWOM | SSOE;
    HC12SPI_REG8(Base, SPICR2) = (uint8)0x00;

    HC12SPI_REG8(Base, SPIBR) = ConfigPtr->BaudRateDivisor;

    dummy                          = HC12SPI_REG8(Base, SPISR);
    dummy                          = HC12SPI_REG8(Base, SPIDR);
    HC12SPI_REG8(Base, SPICR1)    |= SPE;
}


void HC12Spi_SetPrescaler(uint8 Controller, uint8 prescaler)
{
    uint16 Base = HC12SPI_ControllerMapping[Controller];

    HC12SPI_REG8(Base, SPIBR) = (prescaler & (uint8)0x07);
}


/*
    CPOL — SPI Clock Polarity Bit   (Active low/high clock).
    CPHA — SPI Clock Phase Bit      (ClockInPhase).
    LSBFE — SPI LSB-First Enable    (LSB-First).
 */
void HC12Spi_SetFormat(uint8 Controller, boolean cpol, boolean cpha, boolean lsbfe)
{
    uint8   mask;
    uint16  Base = HC12SPI_ControllerMapping[Controller];

    /* todo: Fehlercode, falls SPI 'BUSY' !!! */

    mask = HC12SPI_REG8(Base, SPICR1) & (uint8)0xf2;

    if (cpol == TRUE) {
        mask |= CPOL;
    }

    if (cpha == TRUE) {
        mask |= CPHA;
    }

    if (lsbfe == TRUE) {
        mask |= LSBF;
    }

    HC12SPI_REG8(Base, SPICR1) = mask;
}


boolean HC12Spi_Ready(uint8 Controller)
{
    uint16 Base = HC12SPI_ControllerMapping[Controller];

    return (HC12SPI_REG8(Base, SPISR) & SPIF) != (uint8)0;
}


uint8 HC12Spi_IOByte(uint8 Controller, uint8 data)
{
    uint16 Base = HC12SPI_ControllerMapping[Controller];

    HC12SPI_REG8(Base, SPIDR) = data;
    WAIT_FOR(HC12Spi_Ready(Controller));
/*    WAIT_FOR(HC12Spi_TxReady(Cfg)); */

    return HC12SPI_REG8(Base, SPIDR);
}


void HC12Spi_IOBuffer(uint8 Controller, uint8 * data, uint8 len, boolean use_interrupt)
{
    uint8 idx;

    if (len) {
        if (len == (uint8)1) {
            data[0] = HC12Spi_IOByte(Controller, data[0]);
        } else {
            if (use_interrupt == FALSE) {
                for (idx = (uint8)0; idx < len; ++idx) {
                    data[idx] = HC12Spi_IOByte(Controller, data[idx]);
                }
            } else {

            }
        }
    } else {
        /* todo: return ERROR_CODE!!! */
    }
}


static void HC12Spi_Handler(uint8 Controller)
{
    volatile uint8                      dummy;
    uint16                              Base       = HC12SPI_ControllerMapping[Controller];
    HC12Spi_ConfigType const * const    ConfigPtr  = &HC12Spi_Configuration[Controller];

    if (ConfigPtr->Vars->IOBufPtr < ConfigPtr->Vars->IOBufLength) {
        HC12SPI_REG8(Base, SPIDR) = ConfigPtr->Vars->IOBufAddr[ConfigPtr->Vars->IOBufPtr++];
    } else {
        HC12SPI_REG8(Base, SPICR1) &= ~SPIE;
    }

    if ((HC12SPI_REG8(Base, SPISR) & SPIF) == SPIF) {
        dummy = HC12SPI_REG8(Base, SPIDR);
    }
}


#if 0
ISR1(SPI0_Vector)
{
    HC12Spi_Handler(0);
}
#endif
