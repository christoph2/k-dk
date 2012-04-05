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
 * s. FLOSS-EXCEPTION.txt
 */
#include "mcu/s12/inc/S12_Atd.h"
#include "Hw_Cfg.h"

/*
**
**  ATD 10B8C-/10B16C Module-Driver.
**
**
*/

/*
**
**  REFERENCES
**  ==========
**  ATD10B8C  Block User Guide V02.12.
**  ATD10B16C Block User Guide V03.00.
**
*/
/* HINWEIS: DIE VERFÜGBARKEIT DES 'ETRIG' EINGANG hängt vom derivat ab!!! */
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

static void S12Atd_Handler(uint8 Controller);


void S12Atd_Init(uint8 Controller)
{
    VAR(uint16, AUTOMATIC)          Base = S12Atd_ControllerMapping[Controller];
    S12Adc_ConfigType const * const ConfigPtr = &S12Atd_Configuration[Controller];
    uint8                           ctl;

    if ((ConfigPtr->Flags & S12_ATD_ENABLE_CONTROLLER) == S12_ATD_ENABLE_CONTROLLER) {

        S12ATD_REG8(Base, ATDCTL3) = ((uint8)S8C | FRZ1);
        S12ATD_REG8(Base, ATDCTL4) = (((uint8)ConfigPtr->ConversionTime) << 5) | ConfigPtr->Prescaler;

        if ((ConfigPtr->Flags & S12_ATD_EIGHT_BIT) == S12_ATD_EIGHT_BIT) {
            S12ATD_REG8(Base, ATDCTL4) |= SRES8;
        }

#if S12ATD_MODULE == S12ATD_VARIANT_10B16
        S12ATD_REG8(Base, ATDCTL0) = ConfigPtr->MultChannelWrapAround;
#endif  /* S12ATD_MODULE */

#if S12_ATD_RESULT_ALIGNMENT == S12ATD_RESULT_ALIGN_RIGHT
        S12ATD_REG8(Base, ATDCTL5) = DJM;
#else
        S12ATD_REG8(Base, ATDCTL5) = ((uint8)0x00;
#endif

        if ((ConfigPtr->Flags & S12_ATD_CONTINIOUS_CONVERSION) == S12_ATD_CONTINIOUS_CONVERSION) {
            S12ATD_REG8(Base, ATDCTL5) |= SCAN;
        }

#if S12ATD_MODULE == S12ATD_VARIANT_10B16
        S12ATD_REG8(Base, ATDDIEN0) = ((uint8)0x00);
        S12ATD_REG8(Base, ATDDIEN1) = ((uint8)0x00);
#else
        S12ATD_REG8(Base, ATDDIEN) = ((uint8)0x00);
#endif  /* S12ATD_MODULE */

        ctl = ((uint8)ADPU | AFFC);

        if ((ConfigPtr->Flags & S12_ATD_POWERDOWN) == S12_ATD_POWERDOWN) {
            ctl |= AWAI;
        }

        if (ConfigPtr->ExternalTrigger != S12ATD_EXT_TRIG_DISABLED) {
            ctl |= (uint8)ConfigPtr->ExternalTrigger;
#if S12ATD_MODULE == S12ATD_VARIANT_10B16
            S12ATD_REG8(Base, ATDCTL1) = ConfigPtr->TriggerSource;
#endif      /* S12ATD_MODULE */
        }

        S12ATD_REG8(Base, ATDSTAT0)    = SCF;
        S12ATD_REG8(Base, ATDCTL2)     = ctl;
    } else {
        S12ATD_REG8(Base, ATDCTL2) = (uint8)0x00;
    }
}


void S12Atd_DeInit(uint8 Controller)
{
    VAR(uint16, AUTOMATIC) Base = S12Atd_ControllerMapping[Controller];

#if S12ATD_MODULE == S12ATD_VARIANT_10B16
    S12ATD_REG8(Base, ATDCTL0) = (uint8)0x0f;
    S12ATD_REG8(Base, ATDCTL1) = (uint8)0x0f;
#endif /* S12ATD_MODULE */
    S12ATD_REG8(Base, ATDCTL2) = (uint8)0x00;
    S12ATD_REG8(Base, ATDCTL3) = S4C;
    S12ATD_REG8(Base, ATDCTL4) = PRS2 | PRS1;
    S12ATD_REG8(Base, ATDCTL5) = (uint8)0x00;
}


uint16 S12Atd_GetChannel(uint8 Controller, uint8 chn)
{
    VAR(uint16, AUTOMATIC) Base = S12Atd_ControllerMapping[Controller];

    chn &= ((uint8)0x07);
    WAIT_FOR((S12ATD_REG8(Base, ATDSTAT0) & SCF) == SCF);
    return *(uint16 *)(S12ATD_REG16(Base, ATDDR0 + (chn << 1)));  /* Right justified data (else divide by 0x40). */
}


void S12Atd_EnableHardwareTrigger(uint8 Controller)
{
    VAR(uint16, AUTOMATIC) Base = S12Atd_ControllerMapping[Controller];

    S12ATD_REG8(Base, ATDCTL2) |= ETRIGE;
}


void S12Atd_DisableHardwareTrigger(uint8 Controller)
{
    VAR(uint16, AUTOMATIC) Base = S12Atd_ControllerMapping[Controller];

    S12ATD_REG8(Base, ATDCTL2) &= ~ETRIGE;
}


#if 0
static uint32 conversion_counter = 0UL;

static uint16 result[8];

void S12Atd_Handler(uint8 Controller)
{
    uint8   idx;
    uint8   cc;
    uint8   ccf;

    VAR(uint16, AUTOMATIC)  Base = S12Atd_ControllerMapping[Controller];

    S12ATD_REG8(Base, ATDSTAT0)    = SCF;
    cc                             = S12ATD_REG8(Base, ATDSTAT0) & (uint8)0x07;
    ccf                            = S12ATD_REG8(Base, ATDSTAT1);

    for (idx = 0; idx < 8; ++idx) {
        result[idx] = S12ATD_REG8(Base, ATDDR0 + (idx << 1));
    }

    conversion_counter++;
}


#endif

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
