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
#if !defined(__S12_EEP_H)
#define __S12_EEP_H


/*
**  Global Defines.
*/

/*  Error-Codes.    */
#define S12EE_ERR_OK           ((uint8)0)
#define S12EE_ERR_INIT         ((uint8)1)
#define S12EE_ERR_PVIOL        ((uint8)2)
#define S12EE_ERR_ACC          ((uint8)3)
#define S12EE_ERR_ADDR         ((uint8)4)

/*  Command-Codes.  */
#define S12EE_ERASE_VERIFY     ((uint8)0x05)
#define S12EE_WORD_PROGRAM     ((uint8)0x20)
#define S12EE_SECTOR_ERASE     ((uint8)0x40)
#define S12EE_MASS_ERASE       ((uint8)0x41)
#define S12EE_SECTOR_MODIFY    ((uint8)0x60)


void S12Eep_Init(void);
void S12Eep_Protect(boolean ena);
uint8 S12Eep_DoCmd(uint8 cmd,uint16 addr,uint16 data);
boolean S12Eep_VerifyErase(void);
uint8 S12Eep_SectorErase(uint16 addr);
uint8 S12Eep_SectorModify(uint16 addr,uint32 data);
uint8 S12Eep_MassErase(void);
uint8 S12Eep_ProgramWord(uint16 addr,uint16 data);

#endif /* __S12_EEP_H */
