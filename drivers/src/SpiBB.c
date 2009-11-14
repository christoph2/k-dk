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
#include "SpiBB.h"

/*
**  todo: MSB (needs left-adjust) /LSB-First!
*/

#if 0
Setup:
  MSBFirst,
  ClkPol    CLK_ACTIVE_HIGH|CLK_ACTIVE_LOW
#endif

/*
**    STD_HIGH
**    STD_LOW
**
**    STD_ACTIVE
**    STD_IDLE
**
**    STD_ON
**    STD_OFF
*/

/*
**
** todo: Struktur mit Fkt.Pointern verwenden!!!
**
*/


void SpiBB_SetFormat(uint8 polarity,uint8 phase);


void SpiBB_Init(SpiBB_HWConfigType * const Hw)
{
    *Hw->Port&=~(Hw->ClkMsk|Hw->MosiMsk);  /* todo: je nach Polarität! */

    *Hw->Ddr&=~(Hw->MisoMsk);
    *Hw->Ddr|=(Hw->ClkMsk|Hw->MosiMsk);
}

uint8 SpiBB_ExgBit(SpiBB_HWConfigType * const Hw,uint8 bit)
{
    if (bit==STD_ON) {
        *Hw->Port|=Hw->MosiMsk;
    } else if (bit==STD_OFF) {
        *Hw->Port&=~Hw->MosiMsk;
    } else {
        return (uint8)STD_ON;
    }
#if 0
    /* todo: Polarity!  */
    if (bit==STD_OFF) {
        *Hw->Port&=~Hw->MosiMsk;
    } else if (bit==STD_ON) {
        *Hw->Port|=Hw->MosiMsk;
    }
#endif
    Hw->DelayFct(5);
    *Hw->Port|=Hw->ClkMsk;

    Hw->DelayFct(5);
    *Hw->Port&=~Hw->ClkMsk;

    return (*Hw->Port & Hw->MisoMsk)==Hw->MisoMsk;
}

uint8 SpiBB_ExgBits8(SpiBB_HWConfigType * const Hw,uint8 data,uint8 nbits)
{
    uint8 idx;

    uint8 BitsRx=(uint8)0x00;

    for (idx=nbits;idx>(uint8)0x00;--idx) { /* MSB first. */
        BitsRx|=SpiBB_ExgBit(Hw,Utl_BitGet((uint16)data,idx-1));
        if (idx>1) {
            BitsRx<<=1;
        }
    }

    return BitsRx;
}

uint16 SpiBB_ExgBits16(SpiBB_HWConfigType * const Hw,uint16 data,uint8 nbits)
{
    uint8 idx;
    uint16 BitsRx=(uint16)0x0000U;
    /* ASSERT(nbits<=(uint8)16); */

    for (idx=nbits;idx>(uint8)0x00;--idx) { /* MSB first. */
        BitsRx|=SpiBB_ExgBit(Hw,Utl_BitGet((uint16)data,idx-1));
        if (idx>1) {
            BitsRx<<=1;
        }
    }

    return BitsRx;
}

void SpiBB_SetFormat(uint8 polarity,uint8 phase)
{

}
