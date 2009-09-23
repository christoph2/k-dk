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
#include "S12_Mebi.h"
#include "Hw_Cfg.h"

/*
**  • Port A, B, E, and K related to the core logic and multiplexed bus interface
*/

S12Mebi_StatusType S12Mebi_GetMode(S12Mebi_ModeType *mode)
{
    *mode=(S12Mebi_ModeType)((S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5);

    return S12MEBI_OK;
}


S12Mebi_StatusType S12Mebi_SpecialMode(boolean *flag)
{
    uint8 mode=(S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5;
    
    *flag=!(((mode & ((uint8)0x04))==((uint8)0x04)) && !((mode & ((uint8)0x06))==((uint8)0x06)));

    return S12MEBI_OK;
}
