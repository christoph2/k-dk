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
#if !defined(__HC12_PWM_H)
#define __HC12_PWM_H

#include "HC12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define PWCLK       ((uint8)0x00)
/*  PWCLK-Bits.  */
    #define CON23   ((uint8)0x80)
    #define CON01   ((uint8)0x40)
    #define PCKA2   ((uint8)0x20)
    #define PCKA1   ((uint8)0x10)
    #define PCKA0   ((uint8)0x08)
    #define PCKB2   ((uint8)0x04)
    #define PCKB1   ((uint8)0x02)
    #define PCKB0   ((uint8)0x01)

#define PWPOL       ((uint8)0x01)
/* PWPOL-Bits. */
    #define PCLK3   ((uint8)0x80)
    #define PCLK2   ((uint8)0x40)
    #define PCLK1   ((uint8)0x20)
    #define PCLK0   ((uint8)0x10)
    #define PPOL3   ((uint8)0x08)
    #define PPOL2   ((uint8)0x04)
    #define PPOL1   ((uint8)0x02)
    #define PPOL0   ((uint8)0x01)

#define PWEN        ((uint8)0x02)
/* PWEN-Bits. */
    #define PWEN3   ((uint8)0x08)
    #define PWEN2   ((uint8)0x04)
    #define PWEN1   ((uint8)0x02)
    #define PWEN0   ((uint8)0x01)

#define PWPRES      ((uint8)0x03)

#define PWSCAL0     ((uint8)0x04)

#define PWSCNT0     ((uint8)0x05)

#define PWSCAL1     ((uint8)0x06)

#define PWSCNT1     ((uint8)0x07)

#define PWCNT0      ((uint8)0x08)

#define PWCNT1      ((uint8)0x09)

#define PWCNT2      ((uint8)0x0a)

#define PWCNT3      ((uint8)0x0b)

#define PWPER0      ((uint8)0x0c)

#define PWPER1      ((uint8)0x0d)

#define PWPER2      ((uint8)0x0e)

#define PWPER3      ((uint8)0x0f)

#define PWDTY0      ((uint8)0x10)

#define PWDTY1      ((uint8)0x11)

#define PWDTY2      ((uint8)0x12)

#define PWDTY3      ((uint8)0x13)

#define PWCTL       ((uint8)0x14)
/* PWCTL-Bits. */
    #define PSWAI   ((uint8)0x10)
    #define CENTR   ((uint8)0x08)
    #define RDPP    ((uint8)0x04)
    #define PUPP    ((uint8)0x02)
    #define PSBCK   ((uint8)0x01)

#define PWTST       ((uint8)0x15)
/* PWTST-Bits. */
    #define DISCR   ((uint8)0x80)
    #define DISCP   ((uint8)0x40)
    #define DISCAL  ((uint8)0x20)

#define PORTP       ((uint8)0x16)

#define DDRP        ((uint8)0x17)

/*
**		Global Types.
*/
typedef uint8 HC12Pwm_ChannelType;

typedef uint16 HC12Pwm_PeriodType;

typedef enum tagHC12Pwm_ChannelClassType {
    HC12_PWM_VARIABLE_PERIOD,
    HC12_PWM_FIXED_PERIOD,
    HC12_PWM_FIXED_PERIOD_SHIFTED
} HC12Pwm_ChannelClassType;

typedef enum tagHC12Pwm_StatusType {
    HC12PWM_OK,
    HC12PWM_UNINIT,
    HC12PWM_ID
} HC12Pwm_StatusType;

typedef enum tagHC12Pwm_OutputStateType {
    HC12_PWM_LOW,
    HC12_PWM_HIGH
} HC12Pwm_OutputStateType;

typedef struct tagHC12Pwm_ConfigType {
    uint16 BaseAddr;

    uint8   DdrP;
    uint8   PortP;
    uint8   PwEn;
    uint8   PwCtl;
    uint8   PwClk;
    uint8   PwPol;
    uint8   PwScal0;
    uint8   PwScal1;

    uint8   PwPer0;
    uint8   PwPer1;
    uint8   PwPer2;
    uint8   PwPer3;

    uint8   PwDty0;
    uint8   PwDty1;
    uint8   PwDty2;
    uint8   PwDty3;

    uint8 IdleState;
} HC12Pwm_ConfigType;

/*
**		Global Functions.
*/
void    HC12Pwm_Init(HC12Pwm_ConfigType const * const ConfigPtr);
void    HC12Pwm_DeInit(void);
void    HC12Pwm_SetTimebase(void);
void    HC12Pwm_SetDutyCycle(uint8 ChannelNumber, uint16 DutyCycle);
void    HC12Pwm_SetPeriodAndDuty(uint8 ChannelNumber, uint16 Period, uint16 DutyCycle);
void    HC12Pwm_SetOutputToIdle(uint8 ChannelNumber);
void    HC12Pwm_SetOutputToActive(uint8 ChannelNumber);
uint8   HC12Pwm_GetOutputState(uint8 ChannelNumber);

uint8   HC12Pwm_GetCounter8(uint8 ChannelNumber);
uint16  HC12Pwm_GetCounter16(uint8 ChannelNumber);
void    HC12Pwm_ResetCounter(uint8 ChannelNumber);

extern HC12Pwm_ConfigType const * PWM;

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_PWM_H */
