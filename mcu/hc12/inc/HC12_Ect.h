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
 */
#if !defined(__HC12_ECT_H)
#define	__HC12_ECT_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**  Register-Offsets.
*/
#define TIOS        ((uint8)0x00)
    /* TIOS-Bits.   */
    #define IOS7    ((uint8)0x80)
    #define IOS6    ((uint8)0x40)
    #define IOS5    ((uint8)0x20)
    #define IOS4    ((uint8)0x10)
    #define IOS3    ((uint8)0x08)
    #define IOS2    ((uint8)0x04)
    #define IOS1    ((uint8)0x02)
    #define IOS0    ((uint8)0x01)

#define CFORC       ((uint8)0x01)
    /* CFORC-Bits. */
    #define FOC7    ((uint8)0x80)
    #define FOC6    ((uint8)0x40)
    #define FOC5    ((uint8)0x20)
    #define FOC4    ((uint8)0x10)
    #define FOC3    ((uint8)0x08)
    #define FOC2    ((uint8)0x04)
    #define FOC1    ((uint8)0x02)
    #define FOC0    ((uint8)0x01)

#define OC7M        ((uint8)0x02)
    /* OC7M-Bits.   */
    #define OC7M7   ((uint8)0x80)
    #define OC7M6   ((uint8)0x40)
    #define OC7M5   ((uint8)0x20)
    #define OC7M4   ((uint8)0x10)
    #define OC7M3   ((uint8)0x08)
    #define OC7M2   ((uint8)0x04)
    #define OC7M1   ((uint8)0x02)
    #define OC7M0   ((uint8)0x01)

#define OC7D        ((uint8)0x03)
    /* OC7D-Bits.   */
    #define OC7D7   ((uint8)0x80)
    #define OC7D6   ((uint8)0x40)
    #define OC7D5   ((uint8)0x20)
    #define OC7D4   ((uint8)0x10)
    #define OC7D3   ((uint8)0x08)
    #define OC7D2   ((uint8)0x04)
    #define OC7D1   ((uint8)0x02)
    #define OC7D0   ((uint8)0x01)

#define TCNT        ((uint8)0x04)

#define TSCR        ((uint8)0x06)
    /* TSCR-Bits.   */
    #define TEN     ((uint8)0x80)
    #define TSWAI   ((uint8)0x40)
    #define TSBCK   ((uint8)0x20)
    #define TFFCA   ((uint8)0x10)


#define TQCR        ((uint8)0x07)

#define TCTL1       ((uint8)0x08)
    /* TCTL1-Bits.  */
    #define OM7     ((uint8)0x80)
    #define OL7     ((uint8)0x40)
    #define OM6     ((uint8)0x20)
    #define OL6     ((uint8)0x10)
    #define OM5     ((uint8)0x08)
    #define OL5     ((uint8)0x04)
    #define OM4     ((uint8)0x02)
    #define OL4     ((uint8)0x01)

#define TCTL2       ((uint8)0x09)
    /* TCTL2-Bits.  */
    #define OM3     ((uint8)0x80)
    #define OL3     ((uint8)0x40)
    #define OM2     ((uint8)0x20)
    #define OL2     ((uint8)0x10)
    #define OM1     ((uint8)0x08)
    #define OL1     ((uint8)0x04)
    #define OM0     ((uint8)0x02)
    #define OL0     ((uint8)0x01)

#define TCTL3       ((uint8)0x0A)
    /* TCTL3-Bits.  */
    #define EDG7B   ((uint8)0x80)
    #define EDG7A   ((uint8)0x40)
    #define EDG6B   ((uint8)0x20)
    #define EDG6A   ((uint8)0x10)
    #define EDG5B   ((uint8)0x08)
    #define EDG5A   ((uint8)0x04)
    #define EDG4B   ((uint8)0x02)
    #define EDG4A   ((uint8)0x01)

#define TCTL4       ((uint8)0x0B)
    /* TCTL4-Bits.  */
    #define EDG3B   ((uint8)0x80)
    #define EDG3A   ((uint8)0x40)
    #define EDG2B   ((uint8)0x20)
    #define EDG2A   ((uint8)0x10)
    #define EDG1B   ((uint8)0x08)
    #define EDG1A   ((uint8)0x04)
    #define EDG0B   ((uint8)0x02)
    #define EDG0A   ((uint8)0x01)

#define TMSK1       ((uint8)0x0C)
    /* TMSK1-Bits.  */
    #define C7I     ((uint8)0x80)
    #define C6I     ((uint8)0x40)
    #define C5I     ((uint8)0x20)
    #define C4I     ((uint8)0x10)
    #define C3I     ((uint8)0x08)
    #define C2I     ((uint8)0x04)
    #define C1I     ((uint8)0x02)
    #define C0I     ((uint8)0x01)

#define TMSK2       ((uint8)0x0D)
    /* TMSK2-Bits.  */
    #define TOI     ((uint8)0x80)
    #define PUPT    ((uint8)0x20)
    #define RDPT    ((uint8)0x10)
    #define TCRE    ((uint8)0x08)
    #define PR2     ((uint8)0x04)
    #define PR1     ((uint8)0x02)
    #define PR0     ((uint8)0x01)

#define TFLG1       ((uint8)0x0E)
    /* TFLG1-Bits.  */
    #define C7F     ((uint8)0x80)
    #define C6F     ((uint8)0x40)
    #define C5F     ((uint8)0x20)
    #define C4F     ((uint8)0x10)
    #define C3F     ((uint8)0x08)
    #define C2F     ((uint8)0x04)
    #define C1F     ((uint8)0x02)
    #define C0F     ((uint8)0x01)

#define TFLG2       ((uint8)0x0F)
    /* TFLG2-Bits.  */
    #define TOF     ((uint8)0x80)

#define TC0         ((uint8)0x10)

#define TC1         ((uint8)0x12)

#define TC2         ((uint8)0x14)

#define TC3         ((uint8)0x16)

#define TC4         ((uint8)0x18)

#define TC5         ((uint8)0x1A)

#define TC6         ((uint8)0x1C)

#define TC7         ((uint8)0x1E)

#define PACTL       ((uint8)0x20)
    /* PACTL-Bits.  */
    #define PAEN    ((uint8)0x40)
    #define PAMOD   ((uint8)0x20)
    #define PEDGE   ((uint8)0x10)
    #define CLK1    ((uint8)0x08)
    #define CLK0    ((uint8)0x04)
    #define PAOVI   ((uint8)0x02)
    #define PAI     ((uint8)0x01)

#define PAFLG       ((uint8)0x21)
    /* PAFLG-Bits.  */
    #define PAOVF   ((uint8)0x02)
    #define PAIF    ((uint8)0x01)

#define PACN3       ((uint8)0x22)

#define PACN2       ((uint8)0x23)

#define PACN1       ((uint8)0x24)

#define PACN0       ((uint8)0x25)

#define MCCTL       ((uint8)0x26)
    /* MCCTL-Bits.  */
    #define MCZI    ((uint8)0x80)
    #define MODMC   ((uint8)0x40)
    #define RDMCL   ((uint8)0x20)
    #define ICLAT   ((uint8)0x10)
    #define FLMC    ((uint8)0x08)
    #define MCEN    ((uint8)0x04)
    #define MCPR1   ((uint8)0x02)
    #define MCPR0   ((uint8)0x01)

#define MCFLG       ((uint8)0x27)
    /* MCFLG-Bits.  */
    #define MCZF    ((uint8)0x80)
    #define POLF3   ((uint8)0x08)
    #define POLF2   ((uint8)0x04)
    #define POLF1   ((uint8)0x02)
    #define POLF0   ((uint8)0x01)

#define ICPAR       ((uint8)0x28)
    /* ICPAR-Bits.  */
    #define PA3EN   ((uint8)0x08)
    #define PA2EN   ((uint8)0x04)
    #define PA1EN   ((uint8)0x02)
    #define PA0EN   ((uint8)0x01)

#define DLYCT       ((uint8)0x29)
    /* DLYCT-Bits.  */
    #define DLY1    ((uint8)0x02)
    #define DLY0    ((uint8)0x01)

#define ICOVW       ((uint8)0x2A)
    /* ICOVW-Bits.  */
    #define NOVW7   ((uint8)0x80)
    #define NOVW6   ((uint8)0x40)
    #define NOVW5   ((uint8)0x20)
    #define NOVW4   ((uint8)0x10)
    #define NOVW3   ((uint8)0x08)
    #define NOVW2   ((uint8)0x04)
    #define NOVW1   ((uint8)0x02)
    #define NOVW0   ((uint8)0x01)

#define ICSYS       ((uint8)0x2B)
    /* ICSYS-Bits.  */
    #define SH37    ((uint8)0x80)
    #define SH26    ((uint8)0x40)
    #define SH15    ((uint8)0x20)
    #define SH04    ((uint8)0x10)
    #define TFMOD   ((uint8)0x08)
    #define PACMX   ((uint8)0x04)
    #define BUFEN   ((uint8)0x02)
    #define LATQ    ((uint8)0x01)

/*
**  0x2C - Reserved.
*/

#define TIMTST      ((uint8)0x2D)
    /* TIMTST-Bits. */
    #define TCBYP   ((uint8)0x02)

#define PORTT       ((uint8)0x2E)
    /* PORTT-Bits.  */
    #define PT7     ((uint8)0x80)
    #define PT6     ((uint8)0x40)
    #define PT5     ((uint8)0x20)
    #define PT4     ((uint8)0x10)
    #define PT3     ((uint8)0x08)
    #define PT2     ((uint8)0x04)
    #define PT1     ((uint8)0x02)
    #define PT0     ((uint8)0x01)

#define DDRT        ((uint8)0x2F)
    /* DDRT-Bits.   */
    #define DDT7    ((uint8)0x80)
    #define DDT6    ((uint8)0x40)
    #define DDT5    ((uint8)0x20)
    #define DDT4    ((uint8)0x10)
    #define DDT3    ((uint8)0x08)
    #define DDT2    ((uint8)0x04)
    #define DDT1    ((uint8)0x02)
    #define DDT0    ((uint8)0x01)

#define PBCTL       ((uint8)0x30)
    /* PBCTL-Bits.  */
    #define PBEN    ((uint8)0x40)
    #define PBOVI   ((uint8)0x02)

#define PBFLG       ((uint8)0x31)
    /* PBFLG-Bits.  */
    #define PBOVF   ((uint8)0x02)


#define PA3H        ((uint8)0x32)

#define PA2H        ((uint8)0x33)

#define PA1H        ((uint8)0x34)

#define PA0H        ((uint8)0x35)

#define MCCNT       ((uint8)0x36)

#define MCCNTH      ((uint8)0x36)

#define MCCNTL      ((uint8)0x37)

#define TC0H        ((uint8)0x38)

#define TC1H        ((uint8)0x3A)

#define TC2H        ((uint8)0x3C)

#define TC3H        ((uint8)0x3E)


/*
**  Global Types.
*/
typedef struct tagHC12Ect_ConfigType {
    uint16 BaseAddr;
} HC12Ect_ConfigType;


/*
**  Function-Like-Macros.
*/
#define HC12ECT_ACKNOWLEDGE_TOF_INTR()  HC12ECT_REG8(TFLG2)=TOF

#define HC12ECT_ACKNOWLEDGE_TC0_INTR()  HC12ECT_REG8(TFLG1)=C0F
#define HC12ECT_ACKNOWLEDGE_TC1_INTR()  HC12ECT_REG8(TFLG1)=C1F
#define HC12ECT_ACKNOWLEDGE_TC2_INTR()  HC12ECT_REG8(TFLG1)=C2F
#define HC12ECT_ACKNOWLEDGE_TC3_INTR()  HC12ECT_REG8(TFLG1)=C3F
#define HC12ECT_ACKNOWLEDGE_TC4_INTR()  HC12ECT_REG8(TFLG1)=C4F
#define HC12ECT_ACKNOWLEDGE_TC5_INTR()  HC12ECT_REG8(TFLG1)=C5F
#define HC12ECT_ACKNOWLEDGE_TC6_INTR()  HC12ECT_REG8(TFLG1)=C6F
#define HC12ECT_ACKNOWLEDGE_TC7_INTR()  HC12ECT_REG8(TFLG1)=C7F

#define HC12ECT_ACKNOWLEDGE_MDCU_INTR()	HC12ECT_REG8(MCFLG)=MCZF

#define HC12ECT_ACKNOWLEDGE_PAOV_INTR() HC12ECT_REG8(PAFLG)=PAOVF
#define HC12ECT_ACKNOWLEDGE_PA_INTR()   HC12ECT_REG8(PAFLG)=PAIF

#define HC12ECT_ACKNOWLEDGE_PBOV_INTR() HC12ECT_REG8(PBFLG)=PBOVF


/*
** Global Functions.
*/
void HC12Ect_Init(void);

#define HC12Ect_TimerCount()    HC12ECT_REG16(TCNT)
#define HC12Ect_CapcomReg(no)   HC12ECT_REG16(TC0+((no)<<1))
uint16 HC12Ect_GetOverflowCount(void);
uint32 HC12Ect_GetTickCount(void);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_ECT_H */
