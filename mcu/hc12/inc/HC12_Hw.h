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
#if !defined(__HC12_HW_H)
#define __HC12_HW_H

#include "kdk.h"
#include "CPU_Primitives.h"
#include "Sys_Cfg.h"
#include "InstallISR/ISR.h"


#if CPU_FAMILY == CPU12_HC12

    #if CPU_DERIVATE == CPU12_HC12B32
        #include "device/hc12b32.h"
    #elif  CPU_DERIVATE == CPU12_HC12BC32
        #include "device/hc12bc32.h"
    #elif  CPU_DERIVATE == CPU12_HC12BD32
        #include "device/hc12bd32.h"
    #elif  CPU_DERIVATE == CPU12_HC12A4
        #include "device/hc12a4.h"
    #elif  CPU_DERIVATE == CPU12_HC12D60
        #include "device/hc12d60.h"
    #elif  CPU_DERIVATE == CPU12_HC12D60A
        #include "device/hc12d60a.h"
    #elif  CPU_DERIVATE == CPU12_HC12DG128
        #include "device/hc12dg128.h"
    #elif  CPU_DERIVATE == CPU12_HC12DG128A || CPU_DERIVATE == CPU12_HC12DG128C || CPU_DERIVATE == CPU12_HC12DG128P
        #include "device/hc12dg128a.h"
    #elif  CPU_DERIVATE == CPU12_HC12DT128A || CPU_DERIVATE == CPU12_HC12DT128C || CPU_DERIVATE == CPU12_HC12DT128P
        #include "device/hc12dt128a.h"
    #endif

#else
    #error  CPU family must be HC12.
#endif

#define HC12_REG8(mod, reg)     (BYTE_REG(KDK_BASE_ADDRESS(mod), (reg)))
#define HC12_REG16(mod, reg)    (WORD_REG(KDK_BASE_ADDRESS(mod), (reg)))

#define HC12BCIO_REG8(reg)      (HC12_REG8(BCIO, (reg)))
#define HC12BDLC_REG8(reg)      (HC12_REG8(BDLC, (reg)))

#define HC12CAN_REG8(base, reg) (BYTE_REG(base, (reg)))

#define HC12CLK_REG8(reg)       (HC12_REG8(CLK, (reg)))
#define HC12ECT_REG8(reg)       (HC12_REG8(ECT, (reg)))
#define HC12ECT_REG16(reg)      (HC12_REG16(ECT, (reg)))
#define HC12EEP_REG8(reg)       (HC12_REG8(EEP, (reg)))
#define HC12INT_REG8(reg)       (HC12_REG8(INT, (reg)))
#define HC12KWIO_REG8(reg)      (HC12_REG8(KWIO, (reg)))
#define HC12PLL_REG8(reg)       (HC12_REG8(PLL, (reg)))
#define HC12PWM_REG8(reg)       (HC12_REG8(PWM, (reg)))
#define HC12PWM_REG16(reg)      (HC12_REG16(PWM, (reg)))
#define HC12SI_REG8(reg)        (HC12_REG8(SI, (reg)))
#define HC12SPI_REG8(base, reg) (BYTE_REG(base, (reg)))

#endif /* __HC12_HW_H */
