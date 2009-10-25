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
#if !defined(__HC12_BDLC_H)
#define	__HC12_BDLC_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#define HC12_BDLC_BASE  ((uint16)0x00f8U)

/*
**  Register-Offsets.
*/
#define BCR1        ((uint8)0x00)
    /* BCR1-Bits.   */
    #define IMSG    ((uint8)0x80)
    #define CLKS    ((uint8)0x40)
    #define R1      ((uint8)0x20)
    #define R0      ((uint8)0x10)
    #define IE      ((uint8)0x02)
    #define WCM     ((uint8)0x01)

#define BSVR        ((uint8)0x01)

#define BCR2        ((uint8)0x02)
    /* BCR2-Bits.   */
    #define ALOOP   ((uint8)0x80)
    #define DLOOP   ((uint8)0x40)
    #define RX4XE   ((uint8)0x20)
    #define NBFS    ((uint8)0x10)
    #define TEOD    ((uint8)0x08)
    #define TSIFR   ((uint8)0x04)
    #define TMIFR1  ((uint8)0x02)
    #define TMIFR0  ((uint8)0x01)

#define BDR         ((uint8)0x03)

#define BARD        ((uint8)0x04)
    /* BARD-Bits.   */
    #define ATE     ((uint8)0x80)
    #define RXPOL   ((uint8)0x40)
    #define BO3     ((uint8)0x08)
    #define BO2     ((uint8)0x04)
    #define BO1     ((uint8)0x02)
    #define BO0     ((uint8)0x01)

#define DLCSCR      ((uint8)0x05)
    /* DLCSCR-Bits. */
    #define BDLCEN  ((uint8)0x04)
    #define PUPDLC  ((uint8)0x02)
    #define RDPDLC  ((uint8)0x01)

#define PORTDLC     ((uint8)0x06)

#define DDRDLC      ((uint8)0x07)
    /* DDRDLC-Bits. */
    #define DDDLC6  ((uint8)0x40)
    #define DDDLC5  ((uint8)0x20)
    #define DDDLC4  ((uint8)0x10)
    #define DDDLC3  ((uint8)0x08)
    #define DDDLC2  ((uint8)0x04)
    #define DDDLC1  ((uint8)0x02)
    #define DDDLC0  ((uint8)0x01)



void HC12Bdlc_Init(void);

#if 0
typedef struct tagHC12BDLC_ConfigType {
    uint16 BaseAddr;
} HC12BDLC_ConfigType;


#define HC12BDLC_TimerCount()    HC12BDLC_REG16(TCNT)
#define HC12BDLC_CapcomReg(no)   HC12BDLC_REG16(TC0+((no)<<1))
uint16 HC12BDLC_GetOverflowCount(void);
uint32 HC12BDLC_GetTickCount(void);
#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_BDLC_H */
