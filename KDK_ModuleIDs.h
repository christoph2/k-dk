/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2012 by Christoph Schueler <github.com/Christoph2,
 *                                     cpu12.gems@googlemail.com>
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__KDK_MODULE_IDS_H)
#define __KDK_MODULE_IDS_H

#include "Sys_Cfg.h"

#if !defined(CPU_FAMILY)
#error 'CPU_FAMILY' not defined.
#else
#if CPU_FAMILY == CPU12_HC12
#define AR_MODULE_ID_HC12_BCIO  0x10
#define AR_MODULE_ID_HC12_BDLC  0x20
#define AR_MODULE_ID_HC12_CLK   0x30
#define AR_MODULE_ID_HC12_ECT   0x40
#define AR_MODULE_ID_HC12_EEP   0x50
#define AR_MODULE_ID_HC12_EEPA  0x60
#define AR_MODULE_ID_HC12_IIC   0x70
#define AR_MODULE_ID_HC12_PLL   0x80
#define AR_MODULE_ID_HC12_PWM   0x90
#define AR_MODULE_ID_HC12_SI    0xa0
#define AR_MODULE_ID_HC12_SPI   0xb0
#elif CPU_FAMILY == CPU12_S12
#define AR_MODULE_ID_S12_ATD    0x10
#define AR_MODULE_ID_S12_BKP    0x20
#define AR_MODULE_ID_S12_CAN    0x30
#define AR_MODULE_ID_S12_CRG    0x40
#define AR_MODULE_ID_S12_ECT    0x50
#define AR_MODULE_ID_S12_EEP    0x60
#define AR_MODULE_ID_S12_FLS    0x70
#define AR_MODULE_ID_S12_IIC    0x80
#define AR_MODULE_ID_S12_INT    0x90
#define AR_MODULE_ID_S12_MEBI   0xa0
#define AR_MODULE_ID_S12_MMC    0xb0
#define AR_MODULE_ID_S12_PIM    0xc0
#define AR_MODULE_ID_S12_PWM    0xd0
#define AR_MODULE_ID_S12_SCI    0xe0
#define AR_MODULE_ID_S12_SPI    0xf0
#else
#error Unsupported CPU-Family.
#endif  /* CPU_FAMILY */
#endif  /* !defined(CPU_FAMILY) */

#endif  /* __KDK_MODULE_IDS_H */
