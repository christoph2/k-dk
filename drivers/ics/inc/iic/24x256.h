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
#if !defined(__24X256_H)
#define __24X256_H

#include "S12_Iic.h"    /* todo: make HW-Independent.   */

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Global Functions.
*/

void M24x256_Init(void);

boolean M24x256_WriteByte(uint8 slave_addr,uint16 mem_addr,uint8 data);

boolean M24x256_Busy(uint8 slave_addr);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __24X256_H */
