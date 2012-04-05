/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
#if !defined(__HC12CLK_H)
#define __HC12CLK_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#define HC12_DG128_CLK_BASE ((uint16)0x0014)

#define RTICTL              ((uint8)0x00)
/* RTICTL-Bits. */
    #define RTIE            ((uint8)0x80)
    #define RSWAI           ((uint8)0x40)
    #define RSBCK           ((uint8)0x20)
    #define RTBYP           ((uint8)0x08)
    #define RTR2            ((uint8)0x04)
    #define RTR1            ((uint8)0x02)
    #define RTR0            ((uint8)0x01)

#define RTIFLG              ((uint8)0x01)
/*  RTIFLG-Flags. */
    #define RTIF            ((uint8)0x80)

#define COPCTL              ((uint8)0x02)
/*  COPCTL-Flags. */
    #define CME             ((uint8)0x80)
    #define FCME            ((uint8)0x40)
    #define FCMCOP          ((uint8)0x20)
    #define WCOP            ((uint8)0x10)
    #define DISR            ((uint8)0x08)
    #define CR2             ((uint8)0x04)
    #define CR1             ((uint8)0x02)
    #define CR0             ((uint8)0x01)

#define COPRST              ((uint8)0x03)

/*
** Global Types.
*/
typedef enum tagHC12Clk_StatusType {
    HC12CLK_OK,
    HC12CLK_STATE,
    HC12CLK_VALUE
} HC12Clk_StatusType;

typedef struct tagHC12Clk_ConfigType {
    boolean EnableWatchdog;
    uint8   WatchdogPrescaler;
    boolean EnableRTI;
    uint8   RTIPrescaler;
    uint8   RTIModulo;
} HC12Clk_ConfigType;

typedef enum tagHC12Clk_PllLockType {
    HC12CLK_PLL_LOCKED,
    HC12CLK_PLL_UNLOCKED
} HC12Clk_PllLockType;

/*
**  Function-like Macros.
*/
#define HC12CLK_ACKNOWLEDGE_RTI_INTR() (HC12CLK_REG8(RTIFLG) = RTIF)

/*
**  Function-Prototypes.
*/
void                HC12Clk_Init(void);
HC12Clk_StatusType  HC12Clk_EnableRTI(void);
HC12Clk_StatusType  HC12Clk_DisableRTI(void);
boolean             HC12Clk_RTIEnabled(void);
HC12Clk_StatusType  HC12Clk_SetRTIRate(uint8 rate);

void    HC12Clk_EnableWatchdog(void);
void    HC12Clk_TriggerWatchdog(void);
void    HC12Clk_ResetMCU(void);


typedef void (*HC12Clk_CB_PllLockChanged)(HC12Clk_PllLockType Lock);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__HC12CLK_H */
