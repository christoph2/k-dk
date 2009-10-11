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
#include "S12_Mmc.h"
#include "Hw_Cfg.h"

S12Mmc_StatusType S12Mmc_Init(void)
{
    BYTE_REG(0x00,INITRG)=MMC.InitRG; /* must use default address of 'INITRG' !!! */

    S12MMC_REG8(INITRM)=MMC.InitRM;
    S12MMC_REG8(INITEE)=MMC.InitEE;
    S12MMC_REG8(MISC)=MMC.Misc;

    return S12MMC_OK;
}

S12Mmc_StatusType S12Mmc_SetPPage(uint8 ppage)
{
    S12MMC_REG8(PPAGE)=ppage;

    return S12MMC_OK;
}


S12Mmc_StatusType S12Mmc_GetPPage(uint8 *ppage)
{
    *ppage=S12MMC_REG8(PPAGE);

    return S12MMC_OK;
}
