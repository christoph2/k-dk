/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
 * s. FLOSS-EXCEPTION.txt
 */
#include "mcu/s12/inc/S12_Spi.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES
**  ==========
**  S12SPIV3 - HCS12 SERIAL PERIPHERAL INTERFACE (SPI) BLOCK GUIDE
**
*/

/*
** Local Constants.
*/
static uint16 S12SPI_ControllerMapping[] = {   /* depends on derivate!!! */
    BASE_ADDR_SPI0,
    BASE_ADDR_SPI1,
    BASE_ADDR_SPI2
};

static void     S12Spi_Handler(uint8 Controller);
static boolean  S12Spi_TxReady(uint8 Controller);


void S12Spi_InitController(uint8 Controller)
{
    uint8 ch;

    uint16                          Base       = S12SPI_ControllerMapping[Controller];
    S12Spi_ConfigType const * const ConfigPtr  = &S12Spi_Configuration[Controller];

    S12SPI_REG8(Base, SPICR1)  = SPE | MSTR /*|SSOE*/;
    S12SPI_REG8(Base, SPICR2)  = /*MODFEN|BIDIROE|*/ SPISWAI;

    ch                     = S12SPI_REG8(ConfigPtr, SPIDR);
    S12SPI_REG8(Base, SPIBR)   = ConfigPtr->BaudRateDivisor;
/*    S12_REG8(Cfg,SPICR1)|=SPIE; */
}


void S12Spi_SetSpeed(uint8 Controller, uint8 prescaler)
{
    uint16                          Base       = S12SPI_ControllerMapping[Controller];

    S12SPI_REG8(Base, SPIBR) = (uint8)0x70 | (prescaler & (uint8)0x07);
}


/*
    CPOL — SPI Clock Polarity Bit   (Active low/high clock).
    CPHA — SPI Clock Phase Bit      (ClockInPhase).
    LSBFE — SPI LSB-First Enable    (LSB-First).
 */
void S12Spi_SetFormat(uint8 Controller, boolean cpol, boolean cpha, boolean lsbfe)
{
    uint8 mask;
    uint16                          Base       = S12SPI_ControllerMapping[Controller];

    /* todo: Fehlercode, falls SPI 'BUSY' !!! */

    mask = S12SPI_REG8(Base, SPICR1) & (uint8)0xf2;

    if (cpol == TRUE) {
        mask |= CPOL;
    }

    if (cpha == TRUE) {
        mask |= CPHA;
    }

    if (lsbfe == TRUE) {
        mask |= LSBFE;
    }

    S12SPI_REG8(Base, SPICR1) = mask;
}


boolean S12Spi_TxReady(uint8 Controller)    /* TransmitterEmpty */
{
    uint16                          Base       = S12SPI_ControllerMapping[Controller];

    if ((S12SPI_REG8(Base, SPISR) & SPTEF) == SPTEF /*|| (S12_REG8(Cfg,SPICR1) & SPTIE)*/) {
        return TRUE;
    } else {
        return FALSE;
    }
}


/*
**  todo: Convinience-Makros: 'ReadByte','WriteByte'!!!
*/
uint8 S12Spi_IOByte(uint8 Controller, uint8 data)
{
    uint16                          Base       = S12SPI_ControllerMapping[Controller];

    WAIT_FOR(S12SPISpi_TxReady(Controller));
    S12SPI_REG8(Base, SPIDR) = data;

    while ((S12SPI_REG8(Base, SPISR) & SPIF) == (uint8)0x00) {
    }

    return S12SPI_REG8(Base, SPIDR);
}


void S12Spi_IOBuffer(uint8 Controller, uint8 * data, uint8 len, boolean use_interrupt)
{
    uint8 idx;

    if (len) {
        if (len == (uint8)1) {
            data[0] = S12Spi_IOByte(Controller, data[0]);
        } else {
            if (use_interrupt == FALSE) {
                for (idx = (uint8)0; idx < len; ++idx) {
                    data[idx] = S12Spi_IOByte(Controller, data[idx]);
                }
            } else {

            }
        }
    } else {
        /* todo: return ERROR_CODE!!! */
    }
}


void S12Spi_Handler(S12Spi_ConfigType const * const Cfg)
{
    uint8 ch;

    if ((S12_REG8(Cfg,SPISR) & SPTEF)==SPTEF) {
        if (Cfg->Vars->IOBufPtr<Cfg->Vars->IOBufLength) {
            S12_REG8(Cfg,SPIDR)=Cfg->Vars->IOBufAddr[Cfg->Vars->IOBufPtr++];
        } else {
            S12_REG8(Cfg,SPICR1)&=~SPTIE;
        }
    }

    if ((S12_REG8(Cfg,SPISR) & SPIF)==SPIF) {
        ch=S12_REG8(Cfg,SPIDR);
    }
}


ISR1(SPI0_Vector)
{
    S12Spi_Handler(SPI0);
}
