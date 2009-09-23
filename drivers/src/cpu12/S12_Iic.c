#include "S12_Iic.h"

/*
**  REFERENCES
**  ==========
**
**  S12IICV2    - HCS12 INTER-INTEGRATED CIRCUIT (IIC) BLOCK GUIDE
**  AN2318      - USING I2C BUS WITH HCS12 MICROCONTROLLERS APPLICATION NOTE
**
*/


/*
**
**  todo: Über einen Interrupt-gesteuerten Sequencer nachdenken!!!
**          S12Iic_Opcode {START,RESTART,WRITE,READ,STOP};
**
*/


#define S12_IIC_ENABLED()   ((S12_REG8(Cfg,IBCR) & IBEN)==IBEN)

typedef enum tagIic_OpcodeType {
    START,RESTART,WRITE,READ,STOP
} Iic_OpcodeType;

typedef struct tagIic_PrimitiveType {
    Iic_OpcodeType Opcode;
    uint8 Len;
    uint8 *data;        
} Iic_PrimitiveType;


S12Iic_StatusType S12Iic_Init(S12Iic_ConfigType const * const Cfg)
{
    S12_REG8(Cfg,IBCR)=(uint8)0x00;

    /* todo: PIM-Modul!!! */
#if 0
    DDRJ|=(uint8)0xc0;
    PTJ|=(uint8)0xc0;
    DDRJ&=(uint8)~0xC0;
#endif

    S12_REG8(Cfg,IBFD)=Cfg->Prescaler;
    S12_REG8(Cfg,IBSR)=IBIF|IBAL;
    S12_REG8(Cfg,IBCR)=IBEN;
    
    return S12IIC_OK;
}

S12Iic_StatusType S12Iic_Start(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBB)!=IBB);
    S12_REG8(Cfg,IBCR)|=(IBEN|MS_SL|TX_RX);                    
    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBB)==IBB);
    
    return S12IIC_OK;
}

S12Iic_StatusType S12Iic_Restart(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }    

    S12_REG8(Cfg,IBCR)|=RSTA;
    
    return S12IIC_OK;    
}

S12Iic_StatusType S12Iic_Stop(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    S12_REG8(Cfg,IBCR)=IBEN;
    /*  IBCR&=~MS_SL; */

    return S12IIC_OK;
}

/* todo: R/W-Bit setzen!!! */
/*
    The R/W bit tells the slave the desired direction of data transfer.
        1 = Read transfer, the slave transmits data to the master.
        0 = Write transfer, the master transmits data to the slave.
*/

S12Iic_StatusType S12Iic_Write(S12Iic_ConfigType const * const Cfg,uint8 b,boolean *ack)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }
    
    S12_REG8(Cfg,IBDR)=b;
    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBIF)==IBIF);
    *ack=((S12_REG8(Cfg,IBSR) & RXAK)!=RXAK);    
    S12_REG8(Cfg,IBSR)=IBIF;
        
    return S12IIC_OK;
}

S12Iic_StatusType S12Iic_Read(S12Iic_ConfigType const * const Cfg,uint8 *b,boolean ack)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }
    
    S12_REG8(Cfg,IBCR)=IBEN|MS_SL;

    if (ack==FALSE) {
        S12_REG8(Cfg,IBCR)|=TXAK;
    }

    *b=S12_REG8(Cfg,IBDR);
    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBIF)==IBIF);
    S12_REG8(Cfg,IBSR)=IBIF;
    S12_REG8(Cfg,IBCR)=IBEN|MS_SL|TX_RX;
    *b=S12_REG8(Cfg,IBDR);
        
    return S12IIC_OK;
}

/*
**
**  todo: statt 'boolean' 'IIC_StatusType' verwenden: [IIC_OK|IIC_NOT_PRESENT].
**
*/

boolean S12Iic_PresenceCheck(S12Iic_ConfigType const * const Cfg,uint8 slave_base_addr,uint8 addr_mask,IIC_PresenceCallback callback)
{
    uint8 found=(uint8)0;
    uint8 idx;
    boolean ack;
    
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    if (slave_base_addr==IIC_ADDR_ANY) {
        (void)S12Iic_Write(Cfg,IIC_ADDR_ANY,&ack);
        if (ack==TRUE) {
            found=(uint8)1;
        }
    } else {
        addr_mask&=(uint8)0x7f;
        for (idx=0;idx<addr_mask;idx+=2) {  /* haut so nicht hin!!! */
            (void)S12Iic_Start(Cfg);
            (void)S12Iic_Write(Cfg,slave_base_addr+idx,&ack);
            if (ack==TRUE) { /* todo: korrekte Addresierung!!! */
                found++;
                if (callback!=(IIC_PresenceCallback)NULL) {
                    callback(idx);
                }
            }
            (void)S12Iic_Stop(Cfg);
        }
    }
    
    return (found!=(uint8)0);
}

#if 0
IIC_StatusType S12Iic_SendAddress(S12Iic_ConfigType const * const Cfg,uint8 slave_addr)
{
    IIC_StatusType res;

    if (!S12_IIC_ENABLED(Cfg)) {
        return S12IIC_UNINIT;
    }    
    
    S12Iic_Start(Cfg);
    res=S12Iic_Write(Cfg,slave_addr & (uint8)0xfe);
    if (res==IIC_NAK) {
        S12Iic_Stop(Cfg);
    }
    
    return res;
}
#endif


/*
ISR(iic_handler)
{
    S12_REG8(Cfg,IBSR)|=IBIF;
}       
*/
