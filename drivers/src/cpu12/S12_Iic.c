/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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
**  todo: Interrupt-driven Sequencer!
**          S12Iic_Opcode {START,RESTART,WRITE,READ,STOP};
**          IIC_SequenceState{IIC_SEQ_NOT_RUNNING,IIC_SEQ_RUNNING,IIC_SEQ_COMPLETED};
**          Errorcode: IIC_E_STATE
**
*/

#define IIC_RW_BIT          ((uint8)0x01)

#define S12_IIC_ENABLED()   ((S12_REG8(Cfg,IBCR) & IBEN)==IBEN)
#define S12_IIC_MASTER()    ((S12_REG8(Cfg,IBCR) & MS_SL)==MS_SL)


typedef enum tagIic_OpcodeType {
    START,RESTART,WRITE,READ,STOP
} Iic_OpcodeType;


typedef struct tagIic_PrimitiveType {
    Iic_OpcodeType Opcode;
    uint8 Len;
    uint8 *data;
} Iic_PrimitiveType;


void S12Iic_Init(S12Iic_ConfigType const * const Cfg)
{
    S12_REG8(Cfg,IBCR)=(uint8)0x00;

    S12_REG8(Cfg,IBFD)=Cfg->Prescaler;
    S12_REG8(Cfg,IBSR)=IBIF|IBAL;
    S12_REG8(Cfg,IBCR)=IBEN;
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

    S12_REG8(Cfg,IBCR)=(IBEN|TX_RX);    /* S12_REG8(Cfg,IBCR)=IBEN; */

    return S12IIC_OK;
}


S12Iic_StatusType S12Iic_Write(S12Iic_ConfigType const * const Cfg,uint8 b,boolean *ack)
{
    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    S12_REG8(Cfg,IBCR)|=TX_RX;
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

    if (ack) {
        S12_REG8(Cfg,IBCR)&=~TXAK;
    } else {
        S12_REG8(Cfg,IBCR)|=TXAK;
    }

    S12_REG8(Cfg,IBCR)&=~TX_RX;

    *b=S12_REG8(Cfg,IBDR);  /* Dummy Read.  */
    WAIT_FOR((S12_REG8(Cfg,IBSR) & TCF)==TCF);  /*    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBIF)==IBIF);  */
    S12_REG8(Cfg,IBSR)=IBIF;
    *b=S12_REG8(Cfg,IBDR);

    return S12IIC_OK;
}


boolean S12Iic_PresenceCheck(S12Iic_ConfigType const * const Cfg,uint8 slave_base_addr,uint8 nbits,IIC_PresenceCallback callback)
{
    uint8 found=(uint8)0;
    uint8 idx;
    boolean ack;

    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    if (slave_base_addr==IIC_ADDR_ANY && nbits==(uint8)0x00) {
        (void)S12Iic_Start(Cfg);
        (void)S12Iic_Write(Cfg,IIC_ADDR_ANY,&ack);
        (void)S12Iic_Stop(Cfg);
        if (ack==TRUE) {
            found=(uint8)1;
        }
    } else {
        ASSERT(nbits<(uint8)0x08);

        for (idx=slave_base_addr;idx<(slave_base_addr | (((uint8)2<<nbits)-(uint8)1));idx+=(uint8)0x02) {
            (void)S12Iic_Start(Cfg);
            (void)S12Iic_Write(Cfg,idx,&ack);
            if (ack==TRUE) {
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


boolean S12Iic_ModeReq(S12Iic_ConfigType const * const Cfg,uint8 slave_addr,boolean write)
{
    boolean ack;

    if (S12_IIC_MASTER()) {
        (void)S12Iic_Restart(Cfg);
    } else {
        (void)S12Iic_Start(Cfg);
    }

    if (write) {
        slave_addr&=~IIC_RW_BIT;
    } else {
        slave_addr|=IIC_RW_BIT;
    }

    (void)S12Iic_Write(Cfg,slave_addr,&ack);

#if 0
    if (ack==TRUE) {

    } else {

    }
#endif

    return ack;
}


/*
ISR(iic_handler)
{
    S12_REG8(Cfg,IBSR)|=IBIF;
}
*/
