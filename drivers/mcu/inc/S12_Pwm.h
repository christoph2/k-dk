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
#if !defined(__S12_PWM_H)
#define	__S12_PWM_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define PWME            ((uint8)0x00)
    /*  PWME-Bits.  */
    #define PWME7       ((uint8)0x80)
    #define PWME6       ((uint8)0x40)
    #define PWME5       ((uint8)0x20)
    #define PWME4       ((uint8)0x10)
    #define PWME3       ((uint8)0x08)
    #define PWME2       ((uint8)0x04)
    #define PWME1       ((uint8)0x02)
    #define PWME0       ((uint8)0x01)

#define PWMPOL          ((uint8)0x01)
    /*  PWMPOL-Bits.  */
    #define PPOL7       ((uint8)0x80)
    #define PPOL6       ((uint8)0x40)
    #define PPOL5       ((uint8)0x20)
    #define PPOL4       ((uint8)0x10)
    #define PPOL3       ((uint8)0x08)
    #define PPOL2       ((uint8)0x04)
    #define PPOL1       ((uint8)0x02)
    #define PPOL0       ((uint8)0x01)

#define PWMCLK          ((uint8)0x02)
    /*  PWMCLK-Bits.  */
    #define PCLK7       ((uint8)0x80)
    #define PCLK6       ((uint8)0x40)
    #define PCLK5       ((uint8)0x20)
    #define PCLK4       ((uint8)0x10)
    #define PCLK3       ((uint8)0x08)
    #define PCLK2       ((uint8)0x04)
    #define PCLK1       ((uint8)0x02)
    #define PCLK0       ((uint8)0x01)

#define PWMPRCLK        ((uint8)0x03)
    /*  PWMPRCLK-Bits.  */
    #define PCKB2       ((uint8)0x40)
    #define PCKB1       ((uint8)0x20)
    #define PCKB0       ((uint8)0x10)
    #define PCKA2       ((uint8)0x04)
    #define PCKA1       ((uint8)0x02)
    #define PCKA0       ((uint8)0x01)

#define PWMCAE          ((uint8)0x04)
    /*  PWMCAE-Bits.  */
    #define CAE7        ((uint8)0x80)
    #define CAE6        ((uint8)0x40)
    #define CAE5        ((uint8)0x20)
    #define CAE4        ((uint8)0x10)
    #define CAE3        ((uint8)0x08)
    #define CAE2        ((uint8)0x04)
    #define CAE1        ((uint8)0x02)
    #define CAE0        ((uint8)0x01)

#define PWMCTL          ((uint8)0x05)
    /*  PWMCTL-Bits.  */
    #define CON67       ((uint8)0x80)
    #define CON45       ((uint8)0x40)
    #define CON23       ((uint8)0x20)
    #define CON01       ((uint8)0x10)
    #define PSWAI       ((uint8)0x08)
    #define PFRZ        ((uint8)0x04)

#define PWMTST          ((uint8)0x06)

#define PWMPRSC         ((uint8)0x07)

#define PWMSCLA         ((uint8)0x08)
    /* 0 ==> Presc. = 512; 1 ==> Presc. = 2 */
#define PWMSCLB         ((uint8)0x09)

#define PWMSCNTA        ((uint8)0x0A)

#define PWMSCNTB        ((uint8)0x0B)

#define PWMCNT0         ((uint8)0x0C)

#define PWMCNT1         ((uint8)0x0D)

#define PWMCNT2         ((uint8)0x0E)

#define PWMCNT3         ((uint8)0x0F)

#define PWMCNT4         ((uint8)0x10)

#define PWMCNT5         ((uint8)0x11)

#define PWMCNT6         ((uint8)0x12)

#define PWMCNT7         ((uint8)0x13)

#define PWMPER0         ((uint8)0x14)
#define PWMPER1		((uint8)0x15)
#define PWMPER01        ((uint8)0x14)

#define PWMPER2         ((uint8)0x16)
#define PWMPER3         ((uint8)0x17)
#define PWMPER23        ((uint8)0x16)

#define PWMPER4         ((uint8)0x18)
#define PWMPER5         ((uint8)0x19)
#define PWMPER45        ((uint8)0x18)

#define PWMPER6         ((uint8)0x1A)
#define PWMPER7         ((uint8)0x1B)
#define PWMPER67        ((uint8)0x1A)

#define PWMDTY0         ((uint8)0x1C)
#define PWMDTY1         ((uint8)0x1D)
#define PWMDTY01        ((uint8)0x1C)

#define PWMDTY2         ((uint8)0x1E)
#define PWMDTY3         ((uint8)0x1F)
#define PWMDTY23        ((uint8)0x1E)

#define PWMDTY4         ((uint8)0x20)
#define PWMDTY5         ((uint8)0x21)
#define PWMDTY45        ((uint8)0x20)

#define PWMDTY6         ((uint8)0x22)
#define PWMDTY7         ((uint8)0x23)
#define PWMDTY67        ((uint8)0x22)

#define PWMSDN          ((uint8)0x24)
    /*  PWMSDN-Bits.  */
    #define PWMIF       ((uint8)0x80)
    #define PWMIE       ((uint8)0x40)
    #define PWMRSTRT    ((uint8)0x20)
    #define PWMLVL      ((uint8)0x10)
    #define PWM7IN      ((uint8)0x04)
    #define PWM7INL     ((uint8)0x02)
    #define PWM7ENA     ((uint8)0x01)
/*
**  0x25-0x27 Reserved.
*/


#define S12PWM8B8C_NUM_CHANNELS ((uint8)8)


typedef enum tagS12Pwm_StatusType {
    S12PWM_OK,
    S12PWM_UNINIT,
    S12PWM_ID
} S12Pwm_StatusType;


typedef struct tagS12Pwm_ConfigType {
    uint16 BaseAddr;

    uint8 PwmE;
    uint8 PwmCtl;
    uint8 PwmPol;
    uint8 PwmClk;
    uint8 PwmPrClk;
    uint8 PwmCae;
    uint8 PwmSclA;
    uint8 PwmSclB;

    uint8 PwmSdn;

    uint16 PwmPer01;
    uint16 PwmPer23;
    uint16 PwmPer45;
    uint16 PwmPer67;

    uint16 PwmDty01;
    uint16 PwmDty23;
    uint16 PwmDty45;
    uint16 PwmDty67;
} S12Pwm_ConfigType;


void S12Pwm_Init(void);

void S12Pwm_SetTimebase(void);
void S12Pwm_SetDutyCycle(uint8 ChannelNumber,uint16 DutyCycle);
void S12Pwm_SetPeriodAndDuty(uint8 ChannelNumber,uint16 Period,uint16 DutyCycle);
void S12Pwm_SetOutputToIdle(uint8 ChannelNumber);
uint8 S12Pwm_GetOutputState(uint8 ChannelNumber);
uint8 S12Pwm_GetCounter8(uint8 ChannelNumber);
uint16 S12Pwm_GetCounter16(uint8 ChannelNumber);
void S12Pwm_ResetCounter(uint8 ChannelNumber);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12_PWM_H */
