/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__S12CRG_H)
#define __S12CRG_H

#include "kdk/mcu/s12/S12_Mebi.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define SYNR        ((uint8)0x00)
/*  SYNR-Bits.  */
    #define SYN5    ((uint8)0x20)
    #define SYN4    ((uint8)0x10)
    #define SYN3    ((uint8)0x08)
    #define SYN2    ((uint8)0x04)
    #define SYN1    ((uint8)0x02)
    #define SYN0    ((uint8)0x01)

#define REFDV       ((uint8)0x01)
/*  REFDV-Bits. */
    #define REFDV3  ((uint8)0x08)
    #define REFDV2  ((uint8)0x04)
    #define REFDV1  ((uint8)0x02)
    #define REFDV0  ((uint8)0x01)

#define CTFLG       ((uint8)0x02)
/*  CTFLG-Bits. */
    #define TOUT7   ((uint8)0x80)
    #define TOUT6   ((uint8)0x40)
    #define TOUT5   ((uint8)0x20)
    #define TOUT4   ((uint8)0x10)
    #define TOUT3   ((uint8)0x08)
    #define TOUT2   ((uint8)0x04)
    #define TOUT1   ((uint8)0x02)
    #define TOUT0   ((uint8)0x01)

#define CRGFLG      ((uint8)0x03)
/*  CRGFLG-Bits.  */
    #define RTIF    ((uint8)0x80)
    #define PORF    ((uint8)0x40)
    #define LOCKIF  ((uint8)0x10)
    #define LOCK    ((uint8)0x08)
    #define TRACK   ((uint8)0x04)
    #define SCMIF   ((uint8)0x02)
    #define SCM     ((uint8)0x01)

#define CRGINT      ((uint8)0x04)
/*  CRGINT-Bits.  */
    #define RTIE    ((uint8)0x80)
    #define LOCKIE  ((uint8)0x10)
    #define SCMIE   ((uint8)0x02)

#define CLKSEL      ((uint8)0x05)
/*  CLKSEL-Bits.  */
    #define PLLSEL  ((uint8)0x80)
    #define PSTP    ((uint8)0x40)
    #define SYSWAI  ((uint8)0x20)
    #define ROAWAI  ((uint8)0x10)
    #define PLLWAI  ((uint8)0x08)
    #define CWAI    ((uint8)0x04)
    #define RTIWAI  ((uint8)0x02)
    #define COPWAI  ((uint8)0x01)

#define PLLCTL      ((uint8)0x06)
/* PLLCTL-Bits. */
    #define CME     ((uint8)0x80)
    #define PLLON   ((uint8)0x40)
    #define AUTO    ((uint8)0x20)
    #define ACQ     ((uint8)0x10)
    #define PRE     ((uint8)0x04)
    #define PCE     ((uint8)0x02)
    #define SCME    ((uint8)0x01)

#define RTICTL      ((uint8)0x07)
/*  RTICTL-Bits.  */
    #define RTR6    ((uint8)0x40)
    #define RTR5    ((uint8)0x20)
    #define RTR4    ((uint8)0x10)
    #define RTR3    ((uint8)0x08)
    #define RTR2    ((uint8)0x04)
    #define RTR1    ((uint8)0x02)
    #define RTR0    ((uint8)0x01)

#define COPCTL      ((uint8)0x08)
/*  COPCTL-Bits.  */
    #define WCOP    ((uint8)0x80)
    #define RSBCK   ((uint8)0x40)
    #define CR2     ((uint8)0x04)
    #define CR1     ((uint8)0x02)
    #define CR0     ((uint8)0x01)

#define FORBYP      ((uint8)0x09)
/*  FORBYP-Bits.  */
    #define RTIBYP  ((uint8)0x80)
    #define COPBYP  ((uint8)0x40)
    #define PLLBYP  ((uint8)0x10)
    #define FCM     ((uint8)0x02)

#define CTCTL       ((uint8)0x0a)

#define ARMCOP      ((uint8)0x00b)

/*
** Global Types.
*/
typedef enum tagS12Crg_StatusType {
    S12CRG_OK,
    S12CRG_STATE,
    S12CRG_VALUE

} S12Crg_StatusType;

typedef enum tagS12Crg_PllLockType {
    S12CRG_PLL_LOCKED,
    S12CRG_PLL_UNLOCKED
} S12Crg_PllLockType;

typedef struct tagS12Crg_ConfigType {
    boolean EnablePll;
    uint8   Frequency;
    boolean EnableWatchdog;
    uint8   WatchdogPrescaler;
    boolean EnableRTI;
    uint8   RTIPrescaler;
    uint8   RTIModulo;
} S12Crg_ConfigType;

typedef void (*S12Crg_CB_PllLockChanged)(S12Crg_PllLockType Lock);

/*
**  Function-like Macros.
*/
#define S12CRG_ACKNOWLEDGE_RTI_INTR()   (S12CRG_REG8(CRGFLG) = RTIF)
#define S12CRG_ACKNOWLEDGE_SCM_INTR()   (S12CRG_REG8(CRGFLG) = SCMIF)
#define S12CRG_ACKNOWLEDGE_LOCK_INTR()  (S12CRG_REG8(CRGFLG) = LOCKIF)

/*
**  Function-Prototypes.
*/
S12Crg_StatusType   S12Crg_Init(void);
void                S12Crg_Uninit(void);

S12Crg_StatusType   S12Crg_EnablePll(void);
S12Crg_StatusType   S12Crg_DisablePll(void);
boolean             S12Crg_PllEnabled(void);

S12Crg_StatusType   S12Crg_SetPllFreq(uint8 freq);
S12Crg_StatusType   S12Crg_SetPllParams(uint8 refdv, uint8 synr);
boolean             S12Crg_PllLocked(void);

void    S12Crg_SelectPll(void);
void    S12Crg_UnselectPll(void);
boolean S12Crg_PllSelected(void);

S12Crg_StatusType   S12Crg_EnableRTI(void);
S12Crg_StatusType   S12Crg_DisableRTI(void);
boolean             S12Crg_RTIEnabled(void);
S12Crg_StatusType   S12Crg_SetRTIRate(uint8 rate);

uint8   S12Crg_GetBusFreq(void);
uint8   S12Crg_GetOscFreq(void);

void    S12Crg_EnableWatchdog(void);
void    S12Crg_TriggerWatchdog(void);
void    S12Crg_ResetMCU(void);


/*
**  Configuration Parameter.
*/
#if 0
S12CRG_RTI_API
S12CRG_LOCK_API
    S12CRG_SCM_API
#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__S12CRG_H */
