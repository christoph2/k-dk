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
#include "MAX548.h"
#include "Hw_Cfg.h"

/*
**
**  Device Driver for the Maxim Single-(MAX550A)-/Dual(MAX548A/MAX549A) 8-Bit DACs.
**
**      - Clock-Freq. up to 10MHz.
**      - The DAC-Outputs are directly connected to a R-2R-Ladder, i.e. unbuffered.
**        Apply only high resistive loads > 1M. Connecting a 200..1000pF Capacitor
**        suppresses spikes/crosstalk from the digital part.
**
*/

/*
**  TESTED: YES (28.11.2009).
*/

void MAX548_Init(void)
{
    S12PIM_REG8(PTH)  |= PTH1;
    S12PIM_REG8(DDRH) |= DDRH1;
    /* todo: Set SPI-Format. */
}


/*
**
**  Common Command Codes:
**  =====================
**
**  Value   Constants                       Meaning/Operation
**  -----------------------------------------------------------------
**  0x01    MAX548_DACA                     Load input register A(1)
**  0x02    MAX548_DACB                     Load input register B(1)
**  0x03    MAX548_DACA|MAX548_DACB         Load input registers A+B(1)
**  0x08    MAX548_UPDATE_DAC               Update both DACs from Input registers. Input
**                                          registers unchanged, i.e. Data-Byte ignored.
**  0x09    MAX548_UPDATE_DAC|MAX548_DACA
**  0x0a    MAX548_UPDATE_DAC|MAX548_DACB
**  0x0b    MAX548_UPDATE_DAC|MAX548_DACA|
            MAX548_DACB
**  -----------------------------------------------------------------
**  (1) - DAC Output unchanged.
**  (?) - Makes sense when the /LDAC-Pins of multiple ICs are
**        tied together (==> synchronous DAC outputs).
*/
void MAX548_Write(uint8 control, uint8 data)
{
    S12PIM_REG8(PTH) &= ~PTH1;    /* Chip Select. */
    (void)S12Spi_IOByte(SPI0, control);
    (void)S12Spi_IOByte(SPI0, data);
    S12PIM_REG8(PTH) |= PTH1;     /* Instruction executed on rising edge. */
}


