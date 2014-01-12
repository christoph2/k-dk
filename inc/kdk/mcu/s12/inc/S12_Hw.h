/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__S12_HW_H)
#define __S12_HW_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "Kdk.h"
#include "CPU_Primitives.h"
#include "InstallISR/ISR.h"
#include "Sys_Cfg.h"

#if CPU_FAMILY == CPU12_S12
    #include "mcu/inc/Derivatives.h"
    #include "mcu/s12/inc/device/Devices.h"
#endif /* CPU_FAMILY */

#define S12_REG8(mod, reg)          (BYTE_REG(KDK_BASE_ADDRESS(mod), (reg)))
#define S12_REG16(mod, reg)         (WORD_REG(KDK_BASE_ADDRESS(mod), (reg)))

#define S12_REG8_MULT(mod, reg)     (BYTE_REG(_BASE_ADDRESS_MULT(mod, num), (reg)))
#define S12_REG16_MULT(mod, reg)    (WORD_REG(_BASE_ADDRESS_MULT(mod, num), (reg)))

#define S12ATD_REG8(base, reg)      (BYTE_REG(base, (reg)))
#define S12ATD_REG16(base, reg)     (WORD_REG(base, (reg)))
#define S12CAN_REG8(base, reg)      (BYTE_REG(base, (reg)))
#define S12CRG_REG8(reg)            (S12_REG8(CRG, (reg)))
#define S12BKP_REG8(reg)            (S12_REG8(BKP, (reg)))
#define S12BKP_REG16(reg)           (S12_REG16(BKP, (reg)))
#define S12ECT_REG8(reg)            (S12_REG8(ECT, (reg)))
#define S12ECT_REG16(reg)           (S12_REG16(ECT, (reg)))
#define S12FLS_REG8(reg)            (S12_REG8(FLS, (reg)))
#define S12INT_REG8(reg)            (S12_REG8(INT, (reg)))
#define S12MEBI_REG8(reg)           (S12_REG8(MEBI, (reg)))
#define S12MMC_REG8(reg)            (S12_REG8(MMC, (reg)))
#define S12PIM_REG8(reg)            (S12_REG8(PIM, (reg)))
#define S12PWM_REG8(reg)            (S12_REG8(PWM, (reg)))
#define S12PWM_REG16(reg)           (S12_REG16(PWM, (reg)))
#define S12SCI_REG8(base, reg)      (BYTE_REG(base, (reg)))
#define S12SCI_REG16(base, reg)     (WORD_REG(base, (reg)))
#define S12SPI_REG8(base, reg)      (BYTE_REG(base, (reg)))

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12_HW_H */
