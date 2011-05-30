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

#include "HC12_KwIo.h"


/*
** Global Variables.
*/
HC12KwIo_ConfigType const * KWIO;


/*
** Local Constants.
*/
static const uint8 HC12KwIo_Ports[] = {
    PORTJ,
    PORTH,
};

static const uint8 HC12KwIo_PortDDRs[] = {
    DDRJ,
    DDRH,
};


/*
**	Global Functions.
*/
void HC12KwIo_Init(HC12KwIo_ConfigType const * const ConfigPtr)
{
 	 KWIO=ConfigPtr;
	 
	 /* Setup Ports. */
	 HC12KWIO_REG8(PORTJ) = ConfigPtr->PortJ;
	 HC12KWIO_REG8(DDRJ) = ConfigPtr->DdrJ;	 
	 HC12KWIO_REG8(KWPJ) = ConfigPtr->KwpJ;
	 HC12KWIO_REG8(PORTH) = ConfigPtr->PortH;	 
	 HC12KWIO_REG8(DDRH) = ConfigPtr->DdrH;
	 HC12KWIO_REG8(KWPH) = ConfigPtr->KwpH;
	 
	 /* Clear Pending Interrupts. */
	 HC12KWIO_REG8(KWIFJ) = (uint8)0xff;
	 HC12KWIO_REG8(KWIFH) = (uint8)0xff;	 
	 
	 /* Enable Interrupts. */
	 HC12KWIO_REG8(KWIEJ) = ConfigPtr->KwieJ;	 
	 HC12KWIO_REG8(KWIEH) = ConfigPtr->KwieH;		  	 
}

//HC12KWIO_FEATURE_KW_INTR
// HC12KWIO_KW_CALLBACK

#if defined(HC12KWIO_FEATURE_KW_INTR)
ISR1(HC12KwIo_KwuHandler)
{
#if !defined(HC12KWIO_KW_CALLBACK)
#error Symbol HC12KWIO_KW_CALLBACK must be defined.
#else
    HC12KWIO_KW_CALLBACK();
//    HC12KWIO_ACKNOWLEDGE_KW_INTR();
#endif  /* HC12KWIO_KW_CALLBACK */
}
#endif  /* HC12KWIO_FEATURE_KW_INTR */

