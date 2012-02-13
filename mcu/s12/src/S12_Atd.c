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
 * s. FLOSS-EXCEPTION.txt
 */
#include "mcu/s12/inc/S12_Atd.h"
#include "Hw_Cfg.h"

/*
**
**  ATD_10B8C-Module-Driver.
**
**
*/

/*
**
**  REFERENCES
**  ==========
**  ATD_10B8C Block User Guide V02.12.
**
*/

/*
static const uint8 S12Atd_Ports[] = {
    PORTAD0,
    PORTAD1
};
*/

/*
** Local Constants.
*/
static uint16 S12Atd_ControllerMapping[] = {   /* depends on derivate!!! */
    BASE_ADDR_ATD0,
    BASE_ADDR_ATD1,
};


static uint8 S12Atd_CalculatePrescaler(void);

static void S12Atd_Handler(uint8 Controller);


void S12Atd_Init(uint8 Controller)
{
    uint16                          Base       = S12Atd_ControllerMapping[Controller];
    S12Atd_ConfigType const * const ConfigPtr  = &S12Atd_Configuration[Controller];

    uint8 ctl;

    S12ATD_REG8(Base, ATDCTL3) = ((uint8)S8C | FRZ1);
    S12ATD_REG8(Base, ATDCTL4) = (((uint8)ConfigPtr->ConversionTime) << 5) | S12Atd_CalculatePrescaler();

    if (ConfigPtr->TenBit == FALSE) {
        S12ATD_REG8(Base, ATDCTL4) |= SRES8;
    }

    S12ATD_REG8(Base, ATDCTL5) = ((uint8)DJM | MULT);

    if (ConfigPtr->ContinuousConversion == TRUE) {
        S12ATD_REG8(Base, ATDCTL5) |= SCAN;
    }

    S12ATD_REG8(Base, ATDDIEN) = ((uint8)0x00);

    ctl = ((uint8)ADPU | AFFC | AWAI);

    if (ConfigPtr->ExternalTrigger != S12ATD_EXT_TRIG_DISABLED) {
        ctl |= ((uint8)ConfigPtr->ExternalTrigger << 3) | ETRIGE;
    }

    if (ConfigPtr->EnableCompletionInterrupt == TRUE) {
        ctl |= ASCIE;
    }

    S12ATD_REG8(Base, ATDCTL2) = ctl;

}


uint16 S12Atd_GetChannel(uint8 Controller, uint8 chn)
{
    uint16                          Base       = S12Atd_ControllerMapping[Controller];

    chn &= ((uint8)0x07);
    WAIT_FOR((S12ATD_REG8(Base, ATDSTAT0) & SCF) == SCF);
    return *(uint16 *)(S12ATD_REG16(Base, ATDDR0 + (chn << 1)));  /* Right justified data (else divide by 0x40). */
}


uint8 S12Atd_CalculatePrescaler(void)
{
    uint8 bus_freq, res;

    bus_freq   = S12Crg_GetBusFreq();
    res        = bus_freq >> 2;

    if (!(bus_freq & (uint8)0x03)) {
        res--;
    }

    return res;
}


static uint32 conversion_counter = 0UL;

static uint16 result[8];

void S12Atd_Handler(uint8 Controller)
{
    uint8   idx;
    uint8   cc;
    uint8   ccf;
    uint16                          Base       = S12Atd_ControllerMapping[Controller];

    S12ATD_REG8(Base, ATDSTAT0)    = SCF;
    cc                         = S12ATD_REG8(Base, ATDSTAT0) & (uint8)0x07;
    ccf                        = S12ATD_REG8(Base, ATDSTAT1);

    for (idx = 0; idx < 8; ++idx) {
        result[idx] = S12ATD_REG8(Base, ATDDR0 + (idx << 1));
    }

    conversion_counter++;
}


/*
**  Implementation of common functions.
*/
#if 0
IMPLEMENT_IO_READ_PORT(S12ATD, S12Atd)

IMPLEMENT_IO_READ_CHANNEL(S12ATD, S12Atd)

IMPLEMENT_IO_READ_CHANNEL_GROUP(S12ATD, S12Atd)
#endif

#if 0
ISR1(ATD0_Vector)
{
    S12Atd_Handler(0);

}
#endif
