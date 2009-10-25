/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
#if !defined(__HC12_HW_H)
#define __HC12_HW_H

#include "Std_Types.h"
#include "CPU_Primitives.h"
#include "ISR.h"

#define HC12_REG8(mod,reg)      (BYTE_REG((mod)->BaseAddr,(reg)))
#define HC12_REG16(mod,reg)     (WORD_REG((mod)->BaseAddr,(reg)))


#if 0
#define HC12CRG_REG8(reg)        (HC12_REG8(&CRG,(reg)))
#define HC12BKP_REG8(reg)        (HC12_REG8(&BKP,(reg)))
#define HC12BKP_REG16(reg)       (HC12_REG16(&BKP,(reg)))
#define HC12FLS_REG8(reg)        (HC12_REG8(&FLS,(reg)))
#define HC12INT_REG8(reg)        (HC12_REG8(&INT,(reg)))
#define HC12MEBI_REG8(reg)       (HC12_REG8(&MEBI,(reg)))
#define HC12MMC_REG8(reg)        (HC12_REG8(&MMC,(reg)))
#define HC12PIM_REG8(reg)        (HC12_REG8(&PIM,(reg)))
#endif

#define HC12BCIO_REG8(reg)      (HC12_REG8(&BCIO,(reg)))
#define HC12ECT_REG8(reg)       (HC12_REG8(&ECT,(reg)))
#define HC12ECT_REG16(reg)      (HC12_REG16(&ECT,(reg)))
#define HC12EEP_REG8(reg)       (HC12_REG8(&EEP,(reg)))
#define HC12PWM_REG8(reg)       (HC12_REG8(&PWM,(reg)))
#define HC12PWM_REG16(reg)      (HC12_REG16(&PWM,(reg)))


#endif /* __HC12_HW_H */
