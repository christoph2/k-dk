#if !defined(__S12IIC_H)
#define __S12IIC_H

#include "S12_Hw.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/* 
** Register-Offsets 
*/
#define IBAD            ((uint8)0x00)
        /*  IBAD-Bits.  */
/*
        #define ADR7    0x80
        #define ADR6    0x40
        #define ADR5    0x20
        #define ADR4    0x10
        #define ADR3    0x08
        #define ADR2    0x04
        #define ADR1    0x02 
*/

#define IBFD            ((uint8)0x01)
        /*  IBFD-Bits.  */
        #define IBC7    ((uint8)0x80)
        #define IBC6    ((uint8)0x40)
        #define IBC5    ((uint8)0x20)
        #define IBC4    ((uint8)0x10)
        #define IBC3    ((uint8)0x08)
        #define IBC2    ((uint8)0x04)
        #define IBC1    ((uint8)0x02)
        #define IBC0    ((uint8)0x01)

#define IBCR            ((uint8)0x02)
        /*  IBCR-Bits.  */
        #define IBEN    ((uint8)0x80)
        #define IBIE    ((uint8)0x40)
        #define MS_SL   ((uint8)0x20)
        #define TX_RX   ((uint8)0x10)
        #define TXAK    ((uint8)0x08)
        #define RSTA    ((uint8)0x04)
        #define IBSWAI  ((uint8)0x01)

#define IBSR            ((uint8)0x03)
        /*  IBSR-Bits.  */
        #define TCF     ((uint8)0x80)
        #define IAAS    ((uint8)0x40)
        #define IBB     ((uint8)0x20)
        #define IBAL    ((uint8)0x10)
        #define SRW     ((uint8)0x04)
        #define IBIF    ((uint8)0x02)
        #define RXAK    ((uint8)0x01)

#define IBDR            ((uint8)0x04)

/*
**  Defines.
*/

#define IIC_ADDR_ANY    ((uint8)0)

/*
**  global Types.
*/
typedef struct tagS12Iic_ConfigType {
    uint16 BaseAddr;
    uint8 Prescaler;
    /* todo: boolean EnableInterrupts*/    
    /* todo: Callouts (mit der Option, den Puffer zu kopieren!?) */    
} S12Iic_ConfigType;

typedef enum taS12Iic_StatusType {
    S12IIC_OK,
    S12IIC_UNINIT,    
    S12IIC_ID,
    S12IIC_STATE,
    S12IIC_VALUE    
} S12Iic_StatusType;

typedef void (*IIC_PresenceCallback)(uint8 addr);


/* DECLARE_ISR(iic_handler);   */
/*
**  Function-Prototypes.
*/
S12Iic_StatusType S12Iic_Init(S12Iic_ConfigType const * const Cfg);
S12Iic_StatusType S12Iic_Start(S12Iic_ConfigType const * const Cfg);
S12Iic_StatusType S12Iic_Restart(S12Iic_ConfigType const * const Cfg);
S12Iic_StatusType S12Iic_Stop(S12Iic_ConfigType const * const Cfg);
S12Iic_StatusType S12Iic_Write(S12Iic_ConfigType const * const Cfg,uint8 b,/*@out@*/boolean *ack);
S12Iic_StatusType S12Iic_Read(S12Iic_ConfigType const * const Cfg,/*@out@*/uint8 *b,boolean ack);

boolean S12Iic_PresenceCheck(S12Iic_ConfigType const * const Cfg,uint8 slave_base_addr,uint8 addr_mask,IIC_PresenceCallback callback);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12IIC_H */
