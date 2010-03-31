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
#include "HC12_Spi.h"
#include "Hw_Cfg.h"

/*
**  todo: HC12-SPI u. SCI zu SI (Serial Interface) bzw. MSI (Multiple Serial Interface) zusammenfassen.
*/


static void HC12Spi_Handler(HC12Spi_ConfigType const * const Cfg);
static boolean HC12Spi_TxReady(HC12Spi_ConfigType const * const Cfg);


void HC12Spi_Init(HC12Spi_ConfigType const * const Cfg)
{
    uint8 ch;

    HC12_REG8(Cfg,PORTS)=(uint8)0x00;
    HC12_REG8(Cfg,DDRS)=(uint8)0xe0;

    HC12_REG8(Cfg,SPICR1)=MSTR|SWOM|SSOE;
    HC12_REG8(Cfg,SPICR2)=(uint8)0x00;

    HC12_REG8(Cfg,SPIBR)=(uint8)0x06;

    ch=HC12_REG8(Cfg,SPISR);
    ch=HC12_REG8(Cfg,SPIDR);
    HC12_REG8(Cfg,SPICR1)|=SPE;
}


void HC12Spi_SetSpeed(HC12Spi_ConfigType const * const Cfg,uint8 prescaler)
{
    HC12_REG8(Cfg,SPIBR)=(prescaler & (uint8)0x07);
}


/*
    CPOL — SPI Clock Polarity Bit   (Active low/high clock).
    CPHA — SPI Clock Phase Bit      (ClockInPhase).
    LSBFE — SPI LSB-First Enable    (LSB-First).
*/
void HC12Spi_SetFormat(HC12Spi_ConfigType const * const Cfg,boolean cpol,boolean cpha,boolean lsbfe)
{
    uint8 mask;
    /* todo: Fehlercode, falls SPI 'BUSY' !!! */

    mask=HC12_REG8(Cfg,SPICR1) & (uint8)0xf2;

    if (cpol==TRUE) {
        mask|=CPOL;
    }

    if (cpha==TRUE) {
        mask|=CPHA;
    }

    if (lsbfe==TRUE) {
        mask|=LSBF;
    }

    HC12_REG8(Cfg,SPICR1)=mask;
}


boolean HC12Spi_Ready(HC12Spi_ConfigType const * const Cfg)
{
    return (HC12_REG8(Cfg,SPISR) & SPIF)!=(uint8)0;
}


boolean HC12Spi_TxReady(HC12Spi_ConfigType const * const Cfg)    /* TransmitterEmpty */
{
#if 0
    if ((HC12_REG8(Cfg,SPISR) & SPTEF) || (HC12_REG8(Cfg,SPICR1) & SPTIE)) {
        return FALSE;
    } else {
        return TRUE;
    }
#endif
    return TRUE;
}


uint8 HC12Spi_IOByte(HC12Spi_ConfigType const * const Cfg,uint8 data)
{
    HC12_REG8(Cfg,SPIDR)=data;
    WAIT_FOR(HC12Spi_Ready(Cfg));
/*    WAIT_FOR(HC12Spi_TxReady(Cfg)); */

    return HC12_REG8(Cfg,SPIDR);
}


void HC12Spi_IOBuffer(HC12Spi_ConfigType const * const Cfg,uint8 *data,uint8 len,boolean use_interrupt)
{
    uint8 idx;

    if (len) {
        if (len==(uint8)1) {
            data[0]=HC12Spi_IOByte(Cfg,data[0]);
        } else {
            if (use_interrupt==FALSE) {
                for (idx=(uint8)0;idx<len;++idx) {
                    data[idx]=HC12Spi_IOByte(Cfg,data[idx]);
                }
            } else {

            }
        }
    } else {
        /* todo: return ERROR_CODE!!! */
    }
}


void HC12Spi_Handler(HC12Spi_ConfigType const * const Cfg)
{
    uint8 ch;
#if 0
    if ((HC12_REG8(Cfg,SPISR) & SPTEF)==SPTEF) {
        if (Cfg->Vars->IOBufPtr<Cfg->Vars->IOBufLength) {
            HC12_REG8(Cfg,SPIDR)=Cfg->Vars->IOBufAddr[Cfg->Vars->IOBufPtr++];
        } else {
            HC12_REG8(Cfg,SPICR1)&=~SPTIE;
        }
    }
#endif
    if ((HC12_REG8(Cfg,SPISR) & SPIF)==SPIF) {
        ch=HC12_REG8(Cfg,SPIDR);
    }
}

#if 0
ISR1(SPI0_Vector)
{
    HC12Spi_Handler(SPI0);
}
#endif