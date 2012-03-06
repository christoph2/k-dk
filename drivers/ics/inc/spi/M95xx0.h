/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__M95XX0_H)
#define __M95XX0_H

#include "S12_Spi.h"    /* todo: make HW-Independent.   */

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Global Defines.
*/

/* M95xx0 Status Register Bits  */
#define M95XX0_SR_SRWD  ((uint8)0x80)       /* Status Register Write Protect.   */
#define M95XX0_SR_BP1   ((uint8)0x08)       /* Block-Protect Bit #1.            */
#define M95XX0_SR_BP0   ((uint8)0x04)       /* Block-Protect Bit #0.            */
/*
**
**  Meaning of Blockprotection Bits:
**  ================================
**
**  BP1 BP0  | Protected Block | M95640        | M95320        | M95256
**  -------------------------------------------------------------------------
**    0   0  | None            | None          | None          | None
**    0   1  | Upper Quarter   | 1800h - 1FFFh | 0C00h - 0FFFh | 6000h-7FFFh
**    1   0  | Upper Half      | 1000h - 1FFFh | 0800h - 0FFFh | 4000h-7FFFh
**    1   1  | Whole Memory    | 0000h - 1FFFh | 0000h - 0FFFh | 0000h-7FFFh
**
*/
#define M95XX0_SR_WEL   ((uint8)0x02)       /* Write-Enable Latch Bit.          */
#define M95XX0_SR_WIP   ((uint8)0x01)       /* Write In Progress Bit.           */

/*
**  Global Types.
*/
typedef enum tagM95XX0_ProtectionType {
    M95XX0_PROTECT_NONE,
    M95XX0_PROTECT_UPPER_QUARTER,
    M95XX0_PROTECT_UPPER_HALF,
    M95XX0_PROTECT_WHOLE_MEMORY,
} M95XX0_ProtectionType;

/*
**  Global Functions.
*/
void M95xx0_Init(void);

void    M95xx0_WriteEnable(void);
void    M95xx0_WriteDisable(void);
uint8   M95xx0_ReadStatusRegister(void);
void    M95xx0_WriteStatusRegister(uint8 sr);
boolean M95xx0_ReadBytes(uint8 * data, uint16 len);
boolean M95xx0_WriteBytes(uint8 const * data, uint16 len);

boolean M95xx0_WriteInProgress(void);

boolean M95xx0_Probe(void);

M95XX0_ProtectionType   M95xx0_GetProtection(void);
void                    M95xx0_SetProtection(M95XX0_ProtectionType Protection);


#define M95xx0_IsBusy() ((M95xx0_ReadStatusRegister() & M95XX0_SR_WIP) == M95XX0_SR_WIP)

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __M95XX0_H */

