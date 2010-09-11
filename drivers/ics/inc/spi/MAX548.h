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
#if !defined(__MAX548_H)
#define __MAX548_H

#include "S12_Spi.h"    /* todo: make HW-Independent.   */

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Global Defines.
*/
/*
**
**  Control-Byte
**  ============
**
**  Bit | Name | Meaning / Operation
**  ----------------------------------------------------------------------------------
**  7   | UB1  | Unassigned Bit #1.
**  6   | UB2  | Unassigned Bit #2.
**  5   | UB3  | Unassigned Bit #3.
**  4   | C2   | 0 ==> Power Up, 1 ==> Power Down.
**  3   | C1   | DAC Register Load (0 ==> Disabled, 1 ==> Enabled).
**  2   | C0   | DAC Register Updated on (0 ==> /CS Rising, 1 ==> /LDAC Falling) Edge.
**  1   | A1   | 1 ==> Address DAC-B (MAX550A == don't care).
**  0   | A0   | 1 ==> Address DAC-A.
**
**
*/

#define MAX548_POWER_DOWN   ((uint8)0x10)
#define MAX548_UPDATE_DAC   ((uint8)0x08)
#define MAX548_ASYNCH_LOAD  ((uint8)0x04)
#define MAX548_DACB         ((uint8)0x02)
#define MAX548_DACA         ((uint8)0x01)


/*
**  Global Functions.
*/
void MAX548_Init(void);
void MAX548_Write(uint8 control,uint8 data);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __MAX548_H */
