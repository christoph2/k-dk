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
 */
#include "S12_Mebi.h"
#include "Hw_Cfg.h"

/*
**  • Port A, B, E, and K related to the core logic and multiplexed bus interface
*/


void S12Mebi_Init(S12Mebi_ConfigType const * ConfigPtr)
{
    S12MEBI_REG8(PUCR)=ConfigPtr->Pucr;
    S12MEBI_REG8(RDRIV)=ConfigPtr->Rdriv;
    S12MEBI_REG8(IRQCR)=ConfigPtr->IrqCr;
    S12MEBI_REG8(PORTA)=ConfigPtr->PortA;
    S12MEBI_REG8(DDRA)=ConfigPtr->DdrA;
    S12MEBI_REG8(PORTB)=ConfigPtr->PortB;
    S12MEBI_REG8(DDRB)=ConfigPtr->DdrB;
    S12MEBI_REG8(PORTE)=ConfigPtr->PortE;
    S12MEBI_REG8(DDRE)=ConfigPtr->DdrE;
    S12MEBI_REG8(PORTK)=ConfigPtr->PortK;
    S12MEBI_REG8(DDRK)=ConfigPtr->DdrK;
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
