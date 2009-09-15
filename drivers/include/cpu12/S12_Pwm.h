#if !defined(__PWM_H)
#define	__PWM_H

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

typedef enum tagS12Pwm_StatusType {
    S12PWM_OK,
    S12PWM_UNINIT,
    S12PWM_ID
} S12Pwm_StatusType;
    
typedef struct tagS12Pwm_ConfigType {
    uint16 BaseAddr;
    
    uint8 Pwme; /* 0xaa */
} S12Pwm_ConfigType;


S12Pwm_StatusType S12Pwm_Init(void);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */


#endif  /* __PWM_H */
