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
#if !defined(__HC12PLL_H)
#define __HC12PLL_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#define HC12_DG128_PLL_BASE        ((uint8)0x38)

/*
**  Register-Offsets.
*/
#define SYNR            ((uint8)0x00)
    /*  SYNR-Bits. */
    #define SYN5        ((uint8)0x20)
    #define SYN4        ((uint8)0x10)
    #define SYN3        ((uint8)0x08)
    #define SYN2        ((uint8)0x04)
    #define SYN1        ((uint8)0x02)
    #define SYN0        ((uint8)0x01)

#define REFDV           ((uint8)0x01)
    /*  REFDV-Bits. */
    #define REFDV2      ((uint8)0x04)
    #define REFDV1      ((uint8)0x02)
    #define REFDV0      ((uint8)0x01)

#define CGTFLG          ((uint8)0x02)
    /*  CGTFLG-Bits. */
    #define TSTOUT7     ((uint8)0x80)
    #define TSTOUT6     ((uint8)0x40)
    #define TSTOUT5     ((uint8)0x20)
    #define TSTOUT4     ((uint8)0x10)
    #define TSTOUT3     ((uint8)0x08)
    #define TSTOUT2     ((uint8)0x04)
    #define TSTOUT1     ((uint8)0x02)
    #define TSTOUT0     ((uint8)0x01)

#define PLLFLG          ((uint8)0x03)
    /*  PLLFLG-Bits. */
    #define LOCKIF      ((uint8)0x80)
    #define LOCK        ((uint8)0x40)
    #define LHIF        ((uint8)0x02)
    #define LHOME       ((uint8)0x01)

#define PLLCR           ((uint8)0x04)
    /*  PLLCR-Bits. */
    #define LOCKIE      ((uint8)0x80)
    #define PLLON       ((uint8)0x40)
    #define AUTO        ((uint8)0x20)
    #define ACQ         ((uint8)0x10)
    #define PSTP        ((uint8)0x04)
    #define LHIE        ((uint8)0x02)
    #define NOLHM       ((uint8)0x01)

#define CLKSEL          ((uint8)0x05)
    /*  CLKSEL-Bits. */
    #define BCSP        ((uint8)0x40)
    #define BCSS        ((uint8)0x20)
    #define MCS         ((uint8)0x04)

#define SLOW            ((uint8)0x06)
    /*  SLOW-Bits. */
    #define SLDV5       ((uint8)0x20)
    #define SLDV4       ((uint8)0x10)
    #define SLDV3       ((uint8)0x08)
    #define SLDV2       ((uint8)0x04)
    #define SLDV1       ((uint8)0x02)
    #define SLDV0       ((uint8)0x01)

/*
** Global Types.
*/
typedef enum tagHC12Pll_StatusType {
    HC12PLL_OK,
    HC12PLL_STATE,
    HC12PLL_VALUE
} HC12Pll_StatusType;


typedef enum tagHC12Pll_PllLockType {
    HC12PLL_PLL_LOCKED,
    HC12PLL_PLL_UNLOCKED
} HC12Pll_PllLockType;


typedef enum tagHC12Pll_LimpHomeStatupType {
    HC12PLL_LH_LIMP_HOME,
    HC12PLL_LH_NORMAL_OPERATION
} HC12Pll_LimpHomeStatupType;


typedef struct tagHC12Pll_ConfigType {
    uint16 BaseAddr;
    boolean EnablePll;
    uint8 Frequency;
    uint8 SlowModeDivider;
} HC12Pll_ConfigType;


/*
**  Function-like Macros.
*/
#define HC12PLL_ACKNOWLEDGE_LOCK_INTR() (HC12PLL_REG8(PLLFLG)=LOCKIF)
#define HC12PLL_ACKNOWLEDGE_LH_INTR()   (HC12PLL_REG8(PLLFLG)=LHIF)

/*
**  Function-Prototypes.
*/
HC12Pll_StatusType HC12Pll_Init(void);
void HC12Pll_Uninit(void);

HC12Pll_StatusType HC12Pll_EnablePll(void);
HC12Pll_StatusType HC12Pll_DisablePll(void);
boolean HC12Pll_PllEnabled(void);

void HC12Pll_SelectPll(void);
void HC12Pll_UnselectPll(void);
boolean HC12Pll_PllSelected(void);

HC12Pll_StatusType HC12Pll_SetPllFreq(uint8 freq);
HC12Pll_StatusType HC12Pll_SetPllParams(uint8 refdv,uint8 synr);
HC12Pll_StatusType HC12Pll_PllLocked(void);

uint8 HC12Pll_GetBusFreq(void);
uint8 HC12Pll_GetOscFreq(void);

/*
**  Configuration Parameter.
*/
#if 0
#define S12CRG_SYNCH_PLL 0

S12CRG_RTI_API
S12CRG_LOCK_API
S12CRG_SCM_API
#endif


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__HC12PLL_H */
