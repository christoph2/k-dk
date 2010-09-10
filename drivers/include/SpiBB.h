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

#if !defined(__SPI_BB_H)
#define __SPI_BB_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "Utl.h"

typedef void (*DelayFunctionType)(uint16 uS);

typedef struct tagSpiBB_HWConfigType {
    uint8 volatile * const Port;
    uint8 volatile * const Ddr; /* todo: not needed!?*/

    DelayFunctionType DelayFct;

    uint8 ClkMsk;
    uint8 MosiMsk;
    uint8 MisoMsk;
} SpiBB_HWConfigType ;

void SpiBB_Init(SpiBB_HWConfigType * const Hw);
uint8 SpiBB_ExgBit(SpiBB_HWConfigType * const Hw,uint8 bit);
uint8 SpiBB_ExgBits8(SpiBB_HWConfigType * const Hw,uint8 data,uint8 nbits);
uint16 SpiBB_ExgBits16(SpiBB_HWConfigType * const Hw,uint16 data,uint8 nbits);
uint8 SpiBB_GetQ(SpiBB_HWConfigType * const Hw);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __SPI_BB_H */

