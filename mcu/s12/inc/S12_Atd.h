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
#if !defined(__S12_ATD_H)
#define __S12_ATD_H

#include "S12_Crg.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**      Register-Offsets..
*/
#define ATDCTL0         ((uint8)0x00)
#define ATDCTL1         ((uint8)0x01)
#define ATDCTL2         ((uint8)0x02)
    /*  ATDCTL2-Bits.  */
    #define ADPU        ((uint8)0x80)
    #define AFFC        ((uint8)0x40)
    #define AWAI        ((uint8)0x20)
    #define ETRIGLE     ((uint8)0x10)
    #define ETRIGP      ((uint8)0x08)
    #define ETRIGE      ((uint8)0x04)
    #define ASCIE       ((uint8)0x02)
    #define ASCIF       ((uint8)0x01)

#define ATDCTL3         ((uint8)0x03)
    /*  ATDCTL3-Bits.  */
    #define S8C         ((uint8)0x40)
    #define S4C         ((uint8)0x20)
    #define S2C         ((uint8)0x10)
    #define S1C         ((uint8)0x08)
    #define FIFO        ((uint8)0x04)
    #define FRZ1        ((uint8)0x02)
    #define FRZ0        ((uint8)0x01)

#define ATDCTL4         ((uint8)0x04)
    /*  ATDCTL4-Bits.  */
    #define SRES8       ((uint8)0x80)
    #define SMP1        ((uint8)0x40)
    #define SMP0        ((uint8)0x20)
    #define PRS4        ((uint8)0x10)
    #define PRS3        ((uint8)0x08)
    #define PRS2        ((uint8)0x04)
    #define PRS1        ((uint8)0x02)
    #define PRS0        ((uint8)0x01)

#define ATDCTL5         ((uint8)0x05)
    /*  ATDCTL5-Bits.  */
    #define DJM         ((uint8)0x80)
    #define DSGN        ((uint8)0x40)
    #define SCAN        ((uint8)0x20)
    #define MULT        ((uint8)0x10)
    #define CC          ((uint8)0x04)
    #define CB          ((uint8)0x02)
    #define CA          ((uint8)0x01)

#define ATDSTAT0        ((uint8)0x06)
    /*  ATDSTAT0-Bits. */
    #define SCF         ((uint8)0x80)
    #define ETORF       ((uint8)0x20)
    #define FIFOR       ((uint8)0x10)
    #define CC2         ((uint8)0x04)
    #define CC1         ((uint8)0x02)
    #define CC0         ((uint8)0x01)

/*
**  0x07 Unimplemented.
*/

#define ATDTEST0        ((uint8)0x08)

#define ATDTEST1        ((uint8)0x09)
    /* ATDTEST1-Bits. */
    #define SC          ((uint8)0x01)

/*
**  0x0A Unimplemented.
*/

#define ATDSTAT1        ((uint8)0x0B)
    /*  ATDSTAT1-Bits. */
    #define CCF7        ((uint8)0x80)
    #define CCF6        ((uint8)0x40)
    #define CCF5        ((uint8)0x20)
    #define CCF4        ((uint8)0x10)
    #define CCF3        ((uint8)0x08)
    #define CCF2        ((uint8)0x04)
    #define CCF1        ((uint8)0x02)
    #define CCF0        ((uint8)0x01)

/*
**  0x0C Unimplemented.
*/

#define ATDDIEN         ((uint8)0x0D)
    /*  ATDDIEN-Bits. */
    #define IEN7        ((uint8)0x80)
    #define IEN6        ((uint8)0x40)
    #define IEN5        ((uint8)0x20)
    #define IEN4        ((uint8)0x10)
    #define IEN3        ((uint8)0x08)
    #define IEN2        ((uint8)0x04)
    #define IEN1        ((uint8)0x02)
    #define IEN0        ((uint8)0x01)

/*
**  0x0E Unimplemented.
*/

#define PORTAD0         ((uint8)0x0F)
    /* PORTAD0-Bits. */
    #define PTAD7       ((uint8)0x80)
    #define PTAD6       ((uint8)0x40)
    #define PTAD5       ((uint8)0x20)
    #define PTAD4       ((uint8)0x10)
    #define PTAD3       ((uint8)0x08)
    #define PTAD2       ((uint8)0x04)
    #define PTAD1       ((uint8)0x02)
    #define PTAD0       ((uint8)0x01)

#define ATDDR0          ((uint8)0x10)
#define ATDDR0H         ((uint8)0x10)
#define ATDDR0L         ((uint8)0x11)

#define ATDDR1          ((uint8)0x12)
#define ATDDR1H         ((uint8)0x12)
#define ATDDR1L         ((uint8)0x13)

#define ATDDR2          ((uint8)0x14)
#define ATDDR2H         ((uint8)0x14)
#define ATDDR2L         ((uint8)0x15)

#define ATDDR3          ((uint8)0x16)
#define ATDDR3H         ((uint8)0x16)
#define ATDDR3L         ((uint8)0x17)

#define ATDDR4          ((uint8)0x18)
#define ATDDR4H         ((uint8)0x18)
#define ATDDR4L         ((uint8)0x19)

#define ATDDR5          ((uint8)0x1A)
#define ATDDR5H         ((uint8)0x1A)
#define ATDDR5L         ((uint8)0x1B)

#define ATD0DR6         ((uint8)0x1C)
#define ATD0DR6H        ((uint8)0x1C)
#define ATD0DR6L        ((uint8)0x1D)

#define ATDDR7          ((uint8)0x1E)
#define ATDDR7H         ((uint8)0x1E)
#define ATDDR7L         ((uint8)0x1F)


typedef enum tagS12Atd_StatusType {
    S12ATD_OK,
    S12ATD_UNINIT,
    S12ATD_ID
} S12Atd_StatusType;


typedef enum tagS12Atd_SampleChannelType {
    S12ATD_SMP_CHN_AD0,
    S12ATD_SMP_CHN_AD1,
    S12ATD_SMP_CHN_AD2,
    S12ATD_SMP_CHN_AD3,
    S12ATD_SMP_CHN_AD4,
    S12ATD_SMP_CHN_AD5,
    S12ATD_SMP_CHN_AD6,
    S12ATD_SMP_CHN_AD7,
    S12ATD_SMP_CHN_AD8,
    S12ATD_SMP_CHN_AD9,
    S12ATD_SMP_CHN_AD10,
    S12ATD_SMP_CHN_AD11,
    S12ATD_SMP_CHN_AD12,
    S12ATD_SMP_CHN_AD13,
    S12ATD_SMP_CHN_AD14,
    S12ATD_SMP_CHN_AD15,
    S12ATD_SMP_CHN_ANY=0xff
} S12Atd_SampleChannelType;


typedef enum tagS12Atd_ExternalTriggerType {
    S12ATD_EXT_TRIG_FALLING_EDGE,
    S12ATD_EXT_TRIG_RISING_EDGE,
    S12ATD_EXT_TRIG_LOW_LEVEL,
    S12ATD_EXT_TRIG_HIGH_LEVEL,
    S12ATD_EXT_TRIG_DISABLED
} S12Atd_ExternalTriggerType;


typedef enum tagS12Atd_ConversionTimeType{
    S12ATD_CONV_TIME_FAST,
    S12ATD_CONV_TIME_MEDIUM_FAST,
    S12ATD_CONV_TIME_MEDIUM_SLOW,
    S12ATD_CONV_TIME_SLOW
} S12Atd_ConversionTimeType;


typedef struct tagS12Atd_ConfigType {
    uint16 BaseAddr;
    uint8 Prescaler;
    S12Atd_ExternalTriggerType ExternalTrigger;
    S12Atd_ConversionTimeType ConversionTime;
    boolean TenBit; // todo: Flags!!!
    boolean EnableCompletionInterrupt;
    boolean ContinuousConversion;
    /* todo: Callout!? */
} S12Atd_ConfigType;


/* DECLARE_ISR1_VECTOR(ATD0_Vector); */


#define S12ATD_GET_CONFIGURATION() HW_GET_CONFIGURATION(S12Atd_Configuration,Cfg,id,S12ATD_ID)

void S12Atd_Init(S12Atd_ConfigType const * const Cfg);
uint16 S12Atd_GetChannel(S12Atd_ConfigType const * const Cfg,uint8 chn);

Kdk_PortLevelType S12Atd_ReadPort(S12Atd_ConfigType const * Cfg,Kdk_PortType port);

Kdk_LevelType S12Atd_ReadChannel(S12Atd_ConfigType const * Cfg,Kdk_ChannelType channel);

Kdk_PortLevelType S12Atd_ReadChannelGroup(S12Atd_ConfigType const * Cfg,Kdk_ChannelGroupType const * group);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_ATD_H */
