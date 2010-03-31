/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
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
#include "S12_Atd.h"
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

static uint8 S12Atd_CalculatePrescaler(void);

static void S12Atd_Handler(const S12Atd_ConfigType *Cfg);

void S12Atd_Init(S12Atd_ConfigType const * const Cfg)
{
    uint8 ctl;

    S12_REG8(Cfg,ATDCTL3)=((uint8)S8C|FRZ1);
    S12_REG8(Cfg,ATDCTL4)=(((uint8)Cfg->ConversionTime)<<5)|S12Atd_CalculatePrescaler();
    if (Cfg->TenBit==FALSE) {
        S12_REG8(Cfg,ATDCTL4)|=SRES8;
    }

    S12_REG8(Cfg,ATDCTL5)=((uint8)DJM|MULT);
    if (Cfg->ContinuousConversion==TRUE) {
        S12_REG8(Cfg,ATDCTL5)|=SCAN;
    }

    S12_REG8(Cfg,ATDDIEN)=((uint8)0x00);

    ctl=((uint8)ADPU|AFFC|AWAI);

    if (Cfg->ExternalTrigger!=S12ATD_EXT_TRIG_DISABLED) {
        ctl|=((uint8)Cfg->ExternalTrigger << 3) | ETRIGE;
    }

    if (Cfg->EnableCompletionInterrupt==TRUE) {
        ctl|=ASCIE;
    }
    S12_REG8(Cfg,ATDCTL2)=ctl;

}


uint16 S12Atd_GetChannel(S12Atd_ConfigType const * const Cfg,uint8 chn)
{
    chn&=((uint8)0x07);	
    WAIT_FOR((S12_REG8(Cfg,ATDSTAT0) & SCF) == SCF);
    return *(uint16*)(S12_REG16(Cfg,ATDDR0+(chn<<1)));	/* Right justified data (else divide by 0x40). */
}


uint8 S12Atd_CalculatePrescaler(void)
{
    uint8 bus_freq,res;

    bus_freq=S12Crg_GetBusFreq();
    res=bus_freq>>2;

    if (!(bus_freq & (uint8)0x03)) {
        res--;
    }

    return res;
}

static uint32 conversion_counter=0UL;

static uint16 result[8];

void S12Atd_Handler(const S12Atd_ConfigType *Cfg)
{
    uint8 idx;
    uint8 cc;
    uint8 ccf;

    S12_REG8(Cfg,ATDSTAT0)=SCF;
    cc=S12_REG8(Cfg,ATDSTAT0) & (uint8)0x07;
    ccf=S12_REG8(Cfg,ATDSTAT1);

    for (idx=0;idx<8;++idx) {
        result[idx]=S12_REG8(Cfg,ATDDR0+(idx<<1));
    }

    conversion_counter++;
}


ISR1(ATD0_Vector)
{
    S12Atd_Handler(ATD0);

}
