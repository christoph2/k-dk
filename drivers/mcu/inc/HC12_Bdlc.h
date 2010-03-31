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
#include "Utl.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


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


typedef struct tagHC12Bdlc_ConfigType {
    uint16 BaseAddr;

    uint8 Bcr1;
    uint8 Bcr2;
    uint8 Bard;
    uint8 DlcScr;
    uint8 PortDlc;
    uint8 DdrDlc;
} HC12Bdlc_ConfigType;


/*
** Function-Like Macros.
*/
#define HC12Bdlc_IgnoreMessage()    (HC12BDLC_REG8(BCR1)|=IMSG)


/*
**  Functions.
*/
void HC12Bdlc_Init(void);
boolean HC12Bdlc_Busy(void);
boolean HC12Bdlc_Rxd(void);
uint8 HC12Bdlc_Transmit(uint8 const * buf,uint8 len);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_BDLC_H */
