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

/*
** Register-Offsets.
*/
#define FCLKDIV         ((uint8)0x00)
    /*  FCLKDIV-Bits. */
    #define FDIVLD      ((uint8)0x80)
    #define PRDIV8      ((uint8)0x40)
    #define FDIV5       ((uint8)0x20)
    #define FDIV4       ((uint8)0x10)
    #define FDIV3       ((uint8)0x08)
    #define FDIV2       ((uint8)0x04)
    #define FDIV1       ((uint8)0x02)
    #define FDIV0       ((uint8)0x01)
#define FSEC            ((uint8)0x01)
    /*  FSEC-Bits.  */
    #define KEYEN1      ((uint8)0x80)
    #define KEYEN0      ((uint8)0x40)
    #define NV5         ((uint8)0x20)
    #define NV4         ((uint8)0x10)
    #define NV3         ((uint8)0x08)
    #define NV2         ((uint8)0x04)
    #define SEC1        ((uint8)0x02)
    #define SEC0        ((uint8)0x01)

#define FTSTMOD         ((uint8)0x02)
    /*  FTSTMOD-Bits. */
    #define WRALL       ((uint8)0x10)

#define FCNFG           ((uint8)0x03)
    /*  FCNFG-Bits. */
    #define CBEIE       ((uint8)0x80)
    #define CCIE        ((uint8)0x40)
    #define KEYACC      ((uint8)0x20)
    #define BKSEL1      ((uint8)0x02)
    #define BKSEL0      ((uint8)0x01)

#define FPROT           ((uint8)0x04)
    /*  FPROT-Bits. */
    #define FPOPEN      ((uint8)0x80)
    #define NV6         ((uint8)0x40)
    #define FPHDIS      ((uint8)0x20)
    #define FPHS1       ((uint8)0x10)
    #define FPHS0       ((uint8)0x08)
    #define FPLDIS      ((uint8)0x04)
    #define FPLS1       ((uint8)0x02)
    #define FPLS0       ((uint8)0x01)

#define FSTAT           ((uint8)0x05)
    /*  FSTAT-Bits. */
    #define CBEIF       ((uint8)0x80)
    #define CCIF        ((uint8)0x40)
    #define PVIOL       ((uint8)0x20)
    #define ACCERR      ((uint8)0x10)
    #define BLANK       ((uint8)0x04)

#define FCMD            ((uint8)0x06)
    /*  FCMD-Bits.  */
    #define CMDB6       ((uint8)0x40)
    #define CMDB5       ((uint8)0x20)
    #define CMDB2       ((uint8)0x04)
    #define CMDB0       ((uint8)0x01)

/*
**  0x07 - Reserved.
*/

#define FADDRHI         ((uint8)0x08)

#define FADDRLO         ((uint8)0x09)

#define FDATAHI         ((uint8)0x0A)

#define FDATALO         ((uint8)0x0B)

/*
**  0x08-0x0F Reserved for Factory Test
*/


/*
**  Global Types.
*/

/*  Module-Error-Codes. */
typedef enum tagS12Fls_StatusType {
    S12FLS_OK,
    S12FLS_UNINIT,
    S12FLS_ERR_PVIOL,
    S12FLS_ERR_ACC,
    S12FLS_ERR_ADDR
} Fls_StatusType;


typedef struct tagS12Fls_ConfigType {
    uint16 BaseAddr;
} S12Fls_ConfigType;


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
Fls_StatusType S12Fls_DoCmd(uint8 cmd,uint8 page,uint16 addr,uint16 data);
boolean S12Fls_VerifyErase(uint8 block_num);

Fls_StatusType S12Fls_SectorErase(uint8 page,uint16 addr);
Fls_StatusType S12Fls_MassErase(uint8 block_num);
Fls_StatusType S12Fls_PageErase(uint8 page);

Fls_StatusType S12Fls_ProgramWord(uint8 page,uint16 addr,uint16 data);
Fls_StatusType S12Fls_BurstProgram(uint8 page,uint16 start_addr,uint16 const * data,uint16 len);

#endif /* __S12_FLS_H */
