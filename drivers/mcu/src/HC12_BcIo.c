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

#include "HC12_BcIo.h"
#include "Hw_Cfg.h"

/*
**  todo: PORT-/DDRS, WOMS, etc...
*/
void HC12BcIo_Init(void)
{
    HC12BCIO_REG8(PORTA)=BCIO.PortA;
    HC12BCIO_REG8(DDRA)=BCIO.DdrA;

    HC12BCIO_REG8(PORTB)=BCIO.PortB;
    HC12BCIO_REG8(DDRB)=BCIO.DdrB;

    HC12BCIO_REG8(PORTE)=BCIO.PortE;
    HC12BCIO_REG8(DDRE)=BCIO.DdrE;

    HC12BCIO_REG8(PUCR)=BCIO.Pucr;
    HC12BCIO_REG8(RDRIV)=BCIO.Rdriv;
}
