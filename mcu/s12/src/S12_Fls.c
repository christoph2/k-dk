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
#include "mcu/s12/inc/S12_Fls.h"
#include "Hw_Cfg.h"

#define FE_CLK_DIV          (((16 * 1000) / 200 / 8) - 1) /* todo: Cfg. !!! */

/*  Command-Codes. */
#define S12FLS_ERASE_VERIFY ((uint8)0x05)
#define S12FLS_WORD_PROGRAM ((uint8)0x20)
#define S12FLS_SECTOR_ERASE ((uint8)0x40)
#define S12FLS_MASS_ERASE   ((uint8)0x41)

static void     S12Fls_PageSelect(uint8 page);
static void     S12Fls_ClearPendingErrors(void);
static uint8    S12Fls_CalculateFirstPageInBlock(uint8 block_num);


void S12Fls_Init(void)
{
    S12FLS_REG8(FCNFG)     = (uint8)0x00;
    S12FLS_REG8(FCLKDIV)   = (PRDIV8 | FE_CLK_DIV);
}


Fls_StatusType S12Fls_DoCmd(uint8 cmd, uint8 page, uint16 addr, uint16 data)
{
    if (!((S12FLS_REG8(FCLKDIV) & FDIVLD) == FDIVLD)) {
        return S12FLS_UNINIT;
    }

    S12Fls_ClearPendingErrors();

    S12Fls_PageSelect(page);

    WAIT_FOR((S12FLS_REG8(FSTAT) &  CBEIF) == CBEIF); /* Wait for Command-Buffers ready. */

    *(uint16 *)addr    = data;
    S12FLS_REG8(FCMD)  = cmd;                       /* Write Command. */

    if ((S12FLS_REG8(FSTAT) & PVIOL) == PVIOL) {
        return S12FLS_ERR_PVIOL;
    }

    if ((S12FLS_REG8(FSTAT) & ACCERR) == ACCERR) {
        return S12FLS_ERR_ACC;
    }

    S12FLS_REG8(FSTAT) = CBEIF;                         /* Start Command. */

    WAIT_FOR((S12FLS_REG8(FSTAT) & CCIF) == CCIF);      /* Wait for Command completion. */

    return S12FLS_OK;
}


boolean S12Fls_VerifyErase(uint8 block_num)
{
    Fls_StatusType res;

    res = S12Fls_DoCmd(S12FLS_ERASE_VERIFY, S12Fls_CalculateFirstPageInBlock(block_num), 0xaffeU, 0xdeadU);

    if (res != S12FLS_OK) {
        return FALSE;
    }

    return (S12FLS_REG8(FSTAT) & BLANK) == BLANK;
}


Fls_StatusType S12Fls_SectorErase(uint8 page, uint16 addr)
{
    return S12Fls_DoCmd(S12FLS_SECTOR_ERASE, page, addr, 0xdeadU);
}


Fls_StatusType S12Fls_MassErase(uint8 block_num)
{
    return S12Fls_DoCmd(S12FLS_MASS_ERASE, S12Fls_CalculateFirstPageInBlock(block_num), 0xaffeU, 0xdeadU);
}


Fls_StatusType S12Fls_PageErase(uint8 page)
{
    Fls_StatusType  res;
    uint16          addr = FLS_PAGE_ADDR;

    while (addr < (FLS_PAGE_ADDR + FLS_PAGE_SIZE)) {
        res = S12Fls_SectorErase(page, addr);

        if (res != S12FLS_OK) {
            return res;
        }

        addr += FLS_SECTOR_SIZE;
    }

    return S12FLS_OK;
}


Fls_StatusType S12Fls_ProgramWord(uint8 page, uint16 addr, uint16 data)
{
    return S12Fls_DoCmd(S12FLS_WORD_PROGRAM, page, addr, data);
}


Fls_StatusType S12Fls_BurstProgram(uint8 page, uint16 start_addr, uint16 const * data, uint16 len)
{
    if (!((S12FLS_REG8(FCLKDIV) & FDIVLD) == FDIVLD)) {
        return S12FLS_UNINIT;
    }

    S12Fls_ClearPendingErrors();

    S12Fls_PageSelect(page);

    while (len--) {
        WAIT_FOR((S12FLS_REG8(FSTAT) &  CBEIF) == CBEIF); /* Wait for Command-Buffers ready. */

        *((uint16 *)start_addr++)  = *(data++);
        S12FLS_REG8(FCMD)          = S12FLS_WORD_PROGRAM; /* Write Command. */

        if ((S12FLS_REG8(FSTAT) & PVIOL) == PVIOL) {
            return S12FLS_ERR_PVIOL;
        }

        if ((S12FLS_REG8(FSTAT) & ACCERR) == ACCERR) {
            return S12FLS_ERR_ACC;
        }

        S12FLS_REG8(FSTAT) = CBEIF;                       /* Start Command. */
    }

    WAIT_FOR((S12FLS_REG8(FSTAT) & CCIF) == CCIF);        /* Wait for Command completion. */

    return S12FLS_OK;
}


/*
** Local Functions.
*/
static void S12Fls_PageSelect(uint8 page)
{
    S12FLS_REG8(FCNFG)    &= ~(FLS_NUM_BANKS - 1);
    S12FLS_REG8(FCNFG)    |= ((page - FLS_PPAGE_OFFSET) >> 2) ^ (FLS_NUM_BANKS - 1);
    S12MMC_REG8(PPAGE)     = page;
}


static uint8 S12Fls_CalculateFirstPageInBlock(uint8 block_num)
{
    return (((block_num & (FLS_NUM_BANKS - 1)) ^ (FLS_NUM_BANKS - 1)) * FLS_NUM_BANKS) + FLS_PPAGE_OFFSET;
}


static void S12Fls_ClearPendingErrors(void)
{
    uint8 idx;

    for (idx = (uint8)0x00; idx < FLS_NUM_BANKS; ++idx) {
        S12FLS_REG8(FCNFG)    &= ~(FLS_NUM_BANKS - 1);
        S12FLS_REG8(FCNFG)    |= idx;
        S12FLS_REG8(FSTAT)     = (PVIOL | ACCERR);
    }
}


