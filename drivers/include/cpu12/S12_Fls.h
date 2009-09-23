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
#if !defined(__S12_FLS_H)
#define __S12_FLS_H

#include "S12_Mmc.h"

/*
**  Global Defines.
*/

/*  Command-Codes. */
#define S12FLS_ERASE_VERIFY     ((uint8)0x05)
#define S12FLS_WORD_PROGRAM     ((uint8)0x20)
#define S12FLS_SECTOR_ERASE     ((uint8)0x40)
#define S12FLS_MASS_ERASE       ((uint8)0x41)

/*  Module-Error-Codes. */
#define S12FLS_ERR_OK           ((uint8)0)
#define S12FLS_ERR_INIT         ((uint8)1)
#define S12FLS_ERR_PVIOL        ((uint8)2)
#define S12FLS_ERR_ACC          ((uint8)3)
#define S12FLS_ERR_ADDR         ((uint8)4)


/*
**  Global Types.
*/
typedef struct tagS12Fls_Geometry {
	uint8 num_blocks;
    uint8 pages_per_block;
    uint8 sectors_per_page;
    uint16 bytes_per_sector;
} S12Fls_Geometry;

/*
**
**  todo: S12Fls_GetGeometry();
**
*/

void S12Fls_Init(void);
void S12Fls_PageSelect(uint8 page);
uint8 S12Fls_DoCmd(uint8 cmd,uint8 page,uint16 addr,uint16 data);
boolean S12Fls_VerifyErase(uint8 block_num);

uint8 S12Fls_SectorErase(uint8 page,uint16 addr);
uint8 S12Fls_MassErase(uint8 block_num);
uint8 S12Fls_PageErase(uint8 page);

uint8 S12Fls_ProgramWord(uint8 page,uint16 addr,uint16 data);
uint8 S12Fls_BurstProgram(uint8 page,uint16 start_addr,const uint16 *data,uint16 len);

#endif /* __S12_FLS_H */
