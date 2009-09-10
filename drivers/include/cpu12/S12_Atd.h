#if !defined(__S12_ATD_H)
#define __S12_ATD_H

#include "autosar/Std_Types.h"
#include "autosar/CPU_Primitives.h"

#include "ISR.h"

#include "S12_Crg.h"

#ifdef __cplusplus
extern "C"
{
#endif  /* __cplusplus */

/*
**	Offsets der ATD-Register.
*/

#define ATDCTL0             ((uint8)0x00)
#define ATDCTL1             (uint8)0x01)
#define ATDCTL2             ((uint8)0x02)
    /*  ATD0CTL2-Bits.  */
    #define ADPU        ((uint8)0x80)
    #define AFFC        ((uint8)0x40)
    #define AWAI        ((uint8)0x20)
    #define ETRIGLE     ((uint8)0x10)
    #define ETRIGP      ((uint8)0x08)
    #define ETRIGE      ((uint8)0x04)
    #define ASCIE       ((uint8)0x02)
    #define ASCIF       ((uint8)0x01)

#define ATDCTL3             ((uint8)0x03)
    /*  ATD0CTL3-Bits.  */
    #define S8C         ((uint8)0x40)
    #define S4C         ((uint8)0x20)
    #define S2C         ((uint8)0x10)
    #define S1C         ((uint8)0x08)
    #define FIFO        ((uint8)0x04)
    #define FRZ1        ((uint8)0x02)
    #define FRZ0        ((uint8)0x01)

#define ATDCTL4             ((uint8)0x04)
    /*  ATD0CTL4-Bits.  */
    #define SRES8       ((uint8)0x80)
    #define SMP1        ((uint8)0x40)
    #define SMP0        ((uint8)0x20)
    #define PRS4        ((uint8)0x10)
    #define PRS3        ((uint8)0x08)
    #define PRS2        ((uint8)0x04)
    #define PRS1        ((uint8)0x02)
    #define PRS0        ((uint8)0x01)

#define ATDCTL5             ((uint8)0x05)
    /*  ATD0CTL5-Bits.  */
    #define DJM         ((uint8)0x80)
    #define DSGN        ((uint8)0x40)
    #define SCAN        ((uint8)0x20)
    #define MULT        ((uint8)0x10)
    #define CC          ((uint8)0x04)
    #define CB          ((uint8)0x02)
    #define CA          ((uint8)0x01)

#define ATDSTAT0            ((uint8)0x06)
    /*  ATD0STAT0-Bits. */
    #define SCF         ((uint8)0x80)
    #define ETORF       ((uint8)0x20)
    #define FIFOR       ((uint8)0x10)
    #define CC2         ((uint8)0x04)
    #define CC1         ((uint8)0x02)
    #define CC0         ((uint8)0x01)

#define ATDSTAT1            ((uint8)0x07)
    /*  ATD0STAT1-Bits. */
    #define CCF7        ((uint8)0x80)
    #define CCF6        ((uint8)0x40)
    #define CCF5        ((uint8)0x20)
    #define CCF4        ((uint8)0x10)
    #define CCF3        ((uint8)0x08)
    #define CCF2        ((uint8)0x04)
    #define CCF1        ((uint8)0x02)
    #define CCF0        ((uint8)0x01)

#define ATDTEST0            ((uint8)0x08)
    /*  ATD0TEST0-Bits. */
    #define SAR9        ((uint8)0x80)
    #define SAR8        ((uint8)0x40)
    #define SAR7        ((uint8)0x20)
    #define SAR6        ((uint8)0x10)
    #define SAR5        ((uint8)0x08)
    #define SAR4        ((uint8)0x04)
    #define SAR3        ((uint8)0x02)
    #define SAR2        ((uint8)0x01)

#define ATDTEST1            ((uint8)0x09)
    #define SAR1        ((uint8)0x80)
    #define SAR0        ((uint8)0x40)
    #define RST         ((uint8)0x04)
    #define SC          ((uint8)0x01)
/*
0x0A-0x0C Reserved
*/

#define ATDDIEN             ((uint8)0x0D)

/*
0x0E Reserved
*/

#define PORTAD0             ((uint8)0x0F)   /* NAME ??? */

#define ATDDR0              ((uint8)0x10)
#define ATDDR0H             ((uint8)0x10)
#define ATDDR0L             ((uint8)0x11)

#define ATDDR1              ((uint8)0x12)
#define ATDDR1H             ((uint8)0x12)
#define ATDDR1L             ((uint8)0x13)

#define ATDDR2              ((uint8)0x14)
#define ATDDR2H             ((uint8)0x14)
#define ATDDR2L             ((uint8)0x15)

#define ATDDR3              ((uint8)0x16)
#define ATDDR3H             ((uint8)0x16)
#define ATDDR3L             ((uint8)0x17)

#define ATDDR4              ((uint8)0x18)
#define ATDDR4H             ((uint8)0x18)
#define ATDDR4L             ((uint8)0x19)

#define ATDDR5              ((uint8)0x1A)
#define ATDDR5H             ((uint8)0x1A)
#define ATDDR5L             ((uint8)0x1B)

#define ATD0DR6             ((uint8)0x1C)
#define ATD0DR6H            ((uint8)0x1C)
#define ATD0DR6L            ((uint8)0x1D)

#define ATDDR7              ((uint8)0x1E)
#define ATDDR7H             ((uint8)0x1E)
#define ATDDR7L             ((uint8)0x1F)

#define ATDDR8              ((uint8)0x20)
#define ATDDR8H             ((uint8)0x20)
#define ATDDR8L             ((uint8)0x21)

#define ATDDR9              ((uint8)0x22)
#define ATDDR9H             ((uint8)0x22)
#define ATDDR9L             ((uint8)0x23)

#define ATDDR10             ((uint8)0x24)
#define ATDDR10H            ((uint8)0x24)
#define ATDDR10L            ((uint8)0x25)

#define ATDDR11             ((uint8)0x26)
#define ATDDR11H            ((uint8)0x26)
#define ATDDR11L            ((uint8)0x27)

#define ATDDR12             ((uint8)0x28)
#define ATDDR12H            ((uint8)0x28)
#define ATDDR12L            ((uint8)0x29)

#define ATDDR13             ((uint8)0x2A)
#define ATDDR13H            ((uint8)0x2A)
#define ATDDR13L            ((uint8)0x2B)

#define ATD0DR14            ((uint8)0x2C)
#define ATD0DR14H           ((uint8)0x2C)
#define ATD0DR14L           ((uint8)0x2D)

#define ATDDR15             ((uint8)0x2E)
#define ATDDR15H            ((uint8)0x2E)
#define ATDDR15L            ((uint8)0x2F)


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
    boolean TenBit;
    S12Atd_ExternalTriggerType ExternalTrigger;
    boolean EnableCompletionInterrupt;
    boolean ContinuousConversion;
    S12Atd_ConversionTimeType ConversionTime;
    /* todo: boolean EnableInterrupts*/    
    /* todo: Callout!? */
} S12Atd_ConfigType;

#define S12ATD_GET_CONFIGURATION() HW_GET_CONFIGURATION(S12Atd_Configuration,Cfg,id,S12ATD_ID)

S12Atd_StatusType S12Atd_Init(S12Atd_ConfigType const * const Cfg);
S12Atd_StatusType S12Atd_GetChannel(S12Atd_ConfigType const * const Cfg,uint8 chn,uint16 *result);

#ifdef __cplusplus
}
#endif  /* __cplusplus */

#endif /* __S12_ATD_H */
