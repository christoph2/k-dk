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
#include "mcu/s12/inc/S12_Mebi.h"
#include "Hw_Cfg.h"

#include "Kdk_Error.h"

#if S12MEBI_DEV_ERROR_DETECT == STD_ON
#define S12MEBI_ASSERT_VALID_PORT(port) \
    _BEGIN_BLOCK                        \
    if (port > S12MEBI_PORT_MAX) {      \
/*            ErrorHandler(...); */     \
        return;                         \
    }                                   \
    _END_BLOCK
#else
#define S12MEBI_ASSERT_VALID_PORT(port)
#endif /* S12MEBI_DEV_ERROR_DETECT */

#if S12MEBI_DEV_ERROR_DETECT == STD_ON
#define S12MEBI_ASSERT_VALID_CHANNEL(channel) \
    _BEGIN_BLOCK                              \
    if (channel > S12MEBI_CHANNEL_MAX) {      \
/*            ErrorHandler(...); */           \
        return;                               \
    }                                         \
    _END_BLOCK
#else
#define S12MEBI_ASSERT_VALID_CHANNEL(channel)
#endif /* S12MEBI_DEV_ERROR_DETECT */

/*
**  • Port A, B, E, and K related to the core logic and multiplexed bus interface
*/
static const uint8 S12Mebi_Ports[] = {
    PORTA,
    PORTB,
    PORTE,
    PORTK
};

static const uint8 S12Mebi_PortDDRs[] = {
    DDRA,
    DDRB,
    DDRE,
    DDRK
};

void S12Mebi_Init(S12Mebi_ConfigType const * ConfigPtr)
{
    S12MEBI_REG8(PUCR)     = ConfigPtr->Pucr;
    S12MEBI_REG8(RDRIV)    = ConfigPtr->Rdriv;
    S12MEBI_REG8(IRQCR)    = ConfigPtr->IrqCr;
    S12MEBI_REG8(PORTA)    = ConfigPtr->PortA;
    S12MEBI_REG8(DDRA)     = ConfigPtr->DdrA;
    S12MEBI_REG8(PORTB)    = ConfigPtr->PortB;
    S12MEBI_REG8(DDRB)     = ConfigPtr->DdrB;
    S12MEBI_REG8(PORTE)    = ConfigPtr->PortE;
    S12MEBI_REG8(DDRE)     = ConfigPtr->DdrE;
    S12MEBI_REG8(PORTK)    = ConfigPtr->PortK;
    S12MEBI_REG8(DDRK)     = ConfigPtr->DdrK;
}


S12Mebi_ModeType S12Mebi_GetMode(void)
{
    return (S12Mebi_ModeType)((S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5);
}


boolean S12Mebi_SpecialMode(void)
{
    uint8 mode=(S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5;

    return !(((mode & ((uint8)0x04))==((uint8)0x04)) && !((mode & ((uint8)0x06))==((uint8)0x06)));
}


/*
**  Implementation of common functions.
*/
IMPLEMENT_IO_WRITE_PORT(S12MEBI,S12Mebi)
IMPLEMENT_IO_READ_PORT(S12MEBI,S12Mebi)

IMPLEMENT_IO_WRITE_CHANNEL(S12MEBI,S12Mebi)
IMPLEMENT_IO_READ_CHANNEL(S12MEBI,S12Mebi)

IMPLEMENT_IO_WRITE_CHANNEL_GROUP(S12MEBI,S12Mebi)
IMPLEMENT_IO_READ_CHANNEL_GROUP(S12MEBI,S12Mebi)

IMPLEMENT_IO_SET_PIN_DIRECTION(S12MEBI,S12Mebi)

#if defined(__K_AUTOSAR)
void S12Mebi_RefreshPortDirection(S12Mebi_ConfigType const * ConfigPtr)
{
    // todo: Interrupts sperren!!!
    S12MEBI_REG8(DDRA)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[0],ConfigPtr->DdrA,S12MEBI_REG8(DDRA));
    S12MEBI_REG8(DDRB)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[1],ConfigPtr->DdrB,S12MEBI_REG8(DDRB));
    S12MEBI_REG8(DDRE)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[2],ConfigPtr->DdrE,S12MEBI_REG8(DDRE));
    S12MEBI_REG8(DDRK)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[3],ConfigPtr->DdrK,S12MEBI_REG8(DDRK));
}
#endif /* __K_AUTOSAR */
