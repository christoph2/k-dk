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
#if !defined(__HC12_ATD_H)
#define __HC12_ATD_H

#include "S12_Crg.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

    /* Check: HC12 Hardware-Trigger !!! */

/*
**      Register-Offsets..
*/
#define ATDCTL0     ((uint8)0x00)
#define ATDCTL1     ((uint8)0x01)
#define ATDCTL2     ((uint8)0x02)
/*  ATDCTL2-Bits.  */
    #define ADPU    ((uint8)0x80)
    #define AFFC    ((uint8)0x40)
    #define ASWAI   ((uint8)0x20)
    #define DJM     ((uint8)0x10)   /* ETRIGLE */
                                    /* ETRIGP */
                                    /* ETRIGE */
    #define ASCIE   ((uint8)0x02)
    #define ASCIF   ((uint8)0x01)

#define ATDCTL3     ((uint8)0x03)
/*  ATDCTL3-Bits.  */
                                    /* S8C */
                                    /* S4C */
                                    /* S2C */
    #define S1C     ((uint8)0x08)
    #define FIFO    ((uint8)0x04)
    #define FRZ1    ((uint8)0x02)
    #define FRZ0    ((uint8)0x01)

#define ATDCTL4     ((uint8)0x04)
/*  ATDCTL4-Bits.  */
    #define RES10   ((uint8)0x80)   /* SRES8 */
    #define SMP1    ((uint8)0x40)
    #define SMP0    ((uint8)0x20)
    #define PRS4    ((uint8)0x10)
    #define PRS3    ((uint8)0x08)
    #define PRS2    ((uint8)0x04)
    #define PRS1    ((uint8)0x02)
    #define PRS0    ((uint8)0x01)

#define ATDCTL5     ((uint8)0x05)
/*  ATDCTL5-Bits.  */
                                    /* DJM */
    #define S8C     ((uint8)0x40)   /* DSGN */
    #define SCAN    ((uint8)0x20)
    #define MULT    ((uint8)0x10)
    #define CC      ((uint8)0x04)
    #define CB      ((uint8)0x02)
    #define CA      ((uint8)0x01)

#define ATDSTAT0    ((uint8)0x06)
/*  ATDSTAT0-Bits. */
    #define SCF     ((uint8)0x80)
                                    /* ETORF   */
                                    /* FIFOR   */
    #define CC2     ((uint8)0x04)
    #define CC1     ((uint8)0x02)
    #define CC0     ((uint8)0x01)

#define ATDSTAT1    ((uint8)0x07)   /* S12 - 0x07 Unimplemented. */
/* ATDSTAT1-Bits. */
    #define CCF7    ((uint8)0x80)
    #define CCF6    ((uint8)0x40)
    #define CCF5    ((uint8)0x20)
    #define CCF4    ((uint8)0x10)
    #define CCF3    ((uint8)0x08)
    #define CCF2    ((uint8)0x04)
    #define CCF1    ((uint8)0x02)
    #define CCF0    ((uint8)0x01)


#define ATDTEST0    ((uint8)0x08)

#define ATDTEST1    ((uint8)0x09)
/* ATDTEST1-Bits. */
    #define SAR1    ((uint8)0x80)
    #define SAR0    ((uint8)0x40)
    #define RST     ((uint8)0x20)

/*
**  0x0A -0x0E Unimplemented.
*/

#define PORTAD0     ((uint8)0x0F)
/* PORTAD0-Bits. */
    #define PTAD7   ((uint8)0x80)
    #define PTAD6   ((uint8)0x40)
    #define PTAD5   ((uint8)0x20)
    #define PTAD4   ((uint8)0x10)
    #define PTAD3   ((uint8)0x08)
    #define PTAD2   ((uint8)0x04)
    #define PTAD1   ((uint8)0x02)
    #define PTAD0   ((uint8)0x01)

#define ATDDR0      ((uint8)0x10)
#define ATDDR0H     ((uint8)0x10)
#define ATDDR0L     ((uint8)0x11)

#define ATDDR1      ((uint8)0x12)
#define ATDDR1H     ((uint8)0x12)
#define ATDDR1L     ((uint8)0x13)

#define ATDDR2      ((uint8)0x14)
#define ATDDR2H     ((uint8)0x14)
#define ATDDR2L     ((uint8)0x15)

#define ATDDR3      ((uint8)0x16)
#define ATDDR3H     ((uint8)0x16)
#define ATDDR3L     ((uint8)0x17)

#define ATDDR4      ((uint8)0x18)
#define ATDDR4H     ((uint8)0x18)
#define ATDDR4L     ((uint8)0x19)

#define ATDDR5      ((uint8)0x1A)
#define ATDDR5H     ((uint8)0x1A)
#define ATDDR5L     ((uint8)0x1B)

#define ATD0DR6     ((uint8)0x1C)
#define ATD0DR6H    ((uint8)0x1C)
#define ATD0DR6L    ((uint8)0x1D)

#define ATDDR7      ((uint8)0x1E)
#define ATDDR7H     ((uint8)0x1E)
#define ATDDR7L     ((uint8)0x1F)


/*
**  Features
*/
#define KDK_ATD_FEATURE_HW_TRIGGER  STD_OFF
#define KDK_ATD_PERIODIC_SAMPLING   STD_OFF


/*
**  Global Types.
*/
typedef enum tagHC12Atd_StatusType {
    HC12ATD_OK,
    HC12ATD_UNINIT,
    HC12ATD_ID
} HC12Atd_StatusType;

typedef enum tagHC12Atd_SampleChannelType {
    HC12ATD_SMP_CHN_AD0,
    HC12ATD_SMP_CHN_AD1,
    HC12ATD_SMP_CHN_AD2,
    HC12ATD_SMP_CHN_AD3,
    HC12ATD_SMP_CHN_AD4,
    HC12ATD_SMP_CHN_AD5,
    HC12ATD_SMP_CHN_AD6,
    HC12ATD_SMP_CHN_AD7,
    HC12ATD_SMP_CHN_AD8,
    HC12ATD_SMP_CHN_AD9,
    HC12ATD_SMP_CHN_AD10,
    HC12ATD_SMP_CHN_AD11,
    HC12ATD_SMP_CHN_AD12,
    HC12ATD_SMP_CHN_AD13,
    HC12ATD_SMP_CHN_AD14,
    HC12ATD_SMP_CHN_AD15,
    HC12ATD_SMP_CHN_ANY = 0xff
} HC12Atd_SampleChannelType;

typedef enum tagHC12Atd_ExternalTriggerType {
    HC12ATD_EXT_TRIG_FALLING_EDGE,
    HC12ATD_EXT_TRIG_RISING_EDGE,
    HC12ATD_EXT_TRIG_LOW_LEVEL,
    HC12ATD_EXT_TRIG_HIGH_LEVEL,
    HC12ATD_EXT_TRIG_DISABLED
} HC12Atd_ExternalTriggerType;

typedef enum tagHC12Atd_ConversionTimeType {
    HC12ATD_CONV_TIME_FAST,
    HC12ATD_CONV_TIME_MEDIUM_FAST,
    HC12ATD_CONV_TIME_MEDIUM_SLOW,
    HC12ATD_CONV_TIME_SLOW
} HC12Atd_ConversionTimeType;

typedef struct tagHC12Atd_ConfigType {
    uint8                       Prescaler;
    HC12Atd_ExternalTriggerType  ExternalTrigger;
    HC12Atd_ConversionTimeType   ConversionTime;
    boolean                     TenBit; /* todo: Flags!!! */
    boolean                     EnableCompletionInterrupt;
    boolean                     ContinuousConversion;
    /* todo: Callout!? */
} HC12Atd_ConfigType;

/* DECLARE_ISR1_VECTOR(ATD0_Vector); */

#define HC12ATD_GET_CONFIGURATION() HW_GET_CONFIGURATION(HC12Atd_Configuration, Cfg, id, HC12ATD_ID)


/*
**  Global Functions.
*/
void    HC12Atd_Init(uint8 Controller);
uint16  HC12Atd_GetChannel(uint8 Controller, uint8 chn);

Kdk_PortLevelType HC12Atd_ReadPort(uint8 Controller, Kdk_PortType port);

Kdk_LevelType HC12Atd_ReadChannel(uint8 Controller, Kdk_ChannelType channel);

Kdk_PortLevelType HC12Atd_ReadChannelGroup(uint8 Controller, Kdk_ChannelGroupType const * group);


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __HC12_ATD_H */
