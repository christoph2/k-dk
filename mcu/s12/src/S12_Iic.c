/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2011 by Christoph Schueler <github.com/Christoph2,
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
 * s. FLOSS-EXCEPTION.txt
 */

#include "mcu/s12/inc/S12_Iic.h"

/*
**  "non-autosar-but-autosar-lookalike-iic-module."
*/

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

#define IIC_RW_BIT ((uint8)0x01)

#define S12_IIC_ENABLED()   ((S12_REG8(Cfg, IBCR) & IBEN) == IBEN)
#define S12_IIC_MASTER()    ((S12_REG8(Cfg, IBCR) & MS_SL) == MS_SL)

typedef enum tagIic_OpcodeType {
    IIC_START,
    IIC_RESTART,
    IIC_WRITE,
    IIC_READ,
    IIC_STOP
} Iic_OpcodeType;

typedef struct tagIic_PrimitiveType {
    Iic_OpcodeType  Opcode;
    uint8           Len;
    uint8 *         data;
} Iic_PrimitiveType;

void S12Iic_Init(S12Iic_ConfigType const * const Cfg)
{
    S12_REG8(Cfg, IBCR) = (uint8)0x00;

    S12_REG8(Cfg, IBFD)    = Cfg->Prescaler;
    S12_REG8(Cfg, IBSR)    = IBIF | IBAL;
    S12_REG8(Cfg, IBCR)    = IBEN;
}


void S12Iic_Start(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return;
    }

    WAIT_FOR((S12_REG8(Cfg, IBSR) & IBB) != IBB);
    S12_REG8(Cfg, IBCR) |= (IBEN | MS_SL | TX_RX);
    WAIT_FOR((S12_REG8(Cfg, IBSR) & IBB) == IBB);
}


void S12Iic_Restart(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return;
    }

    S12_REG8(Cfg, IBCR) |= RSTA;
}


void S12Iic_Stop(S12Iic_ConfigType const * const Cfg)
{
    if (!S12_IIC_ENABLED()) {
        return;
    }

    S12_REG8(Cfg, IBCR) = (IBEN | TX_RX);
}


boolean S12Iic_Write(S12Iic_ConfigType const * const Cfg, uint8 b)
{
    boolean ack;

    if (!S12_IIC_ENABLED()) {
        return FALSE;
    }

    S12_REG8(Cfg, IBCR)   |= TX_RX;
    S12_REG8(Cfg, IBDR)    = b;
    WAIT_FOR((S12_REG8(Cfg, IBSR) & IBIF) == IBIF);
    ack                    = ((S12_REG8(Cfg, IBSR) & RXAK) != RXAK);
    S12_REG8(Cfg, IBSR)    = IBIF;

    return ack;
}


void S12Iic_Read(S12Iic_ConfigType const * const Cfg, uint8 * b, boolean ack)
{
    if (!S12_IIC_ENABLED()) {
        return;
    }

    if (ack) {
        S12_REG8(Cfg, IBCR) &= ~TXAK;
    } else {
        S12_REG8(Cfg, IBCR) |= TXAK;
    }

    S12_REG8(Cfg, IBCR) &= ~TX_RX;

    *b = S12_REG8(Cfg, IBDR);                       /* Dummy Read.  */
    WAIT_FOR((S12_REG8(Cfg, IBSR) & TCF) == TCF);   /*    WAIT_FOR((S12_REG8(Cfg,IBSR) & IBIF)==IBIF);  */
    S12_REG8(Cfg, IBSR)    = IBIF;
    *b                     = S12_REG8(Cfg, IBDR);
}


boolean S12Iic_PresenceCheck(S12Iic_ConfigType const * const Cfg, uint8 slave_base_addr, uint8 nbits, IIC_PresenceCallback callback)
{
    uint8   found = (uint8)0;
    uint8   idx;
    boolean ack;

    if (!S12_IIC_ENABLED()) {
        return S12IIC_UNINIT;
    }

    if (slave_base_addr == IIC_ADDR_ANY && nbits == (uint8)0x00) {
        S12Iic_Start(Cfg);
        ack = S12Iic_Write(Cfg, IIC_ADDR_ANY);
        S12Iic_Stop(Cfg);

        if (ack == TRUE) {
            found = (uint8)1;
        }
    } else {
        ASSERT(nbits < (uint8)0x08);

        for (idx = slave_base_addr; idx < (slave_base_addr | (((uint8)2 << nbits) - (uint8)1)); idx += (uint8)0x02) {
            S12Iic_Start(Cfg);
            ack = S12Iic_Write(Cfg, idx);

            if (ack == TRUE) {
                found++;

                if (callback != (IIC_PresenceCallback)NULL) {
                    callback(idx);
                }
            }

            S12Iic_Stop(Cfg);
        }
    }

    return found != (uint8)0;
}


boolean S12Iic_ModeReq(S12Iic_ConfigType const * const Cfg, uint8 slave_addr, boolean write)
{
    if (!S12_IIC_ENABLED()) {
        return FALSE;
    }

    if (S12_IIC_MASTER()) {
        S12Iic_Restart(Cfg);
    } else {
        S12Iic_Start(Cfg);
    }

    if (write) {
        slave_addr &= ~IIC_RW_BIT;
    } else {
        slave_addr |= IIC_RW_BIT;
    }

    return S12Iic_Write(Cfg, slave_addr);
}


/*
   ISR(iic_handler)
   {
    S12_REG8(Cfg,IBSR)|=IBIF;
   }
 */
#if 0
#pragma TRAP_PROC
void _I2CISR( void )
{
    volatile tU08 dummyibdrRead;                                        /* variable to allow dummy reads of IBDR */

    Iic.ibsr.bit.ibif = 1;                                              /* reset the interrupt */

    if(Iic.ibcr.bit.mssl == SET) {                                      /* if module is in master mode */
        if(Iic.ibcr.bit.txrx == SET) {                                  /* if module is to transmit */
            if(TxCompleteflag == SET) {                                 /* if the last byte has been transmitted */
                TxCompleteflag     = CLEAR;                             /* clear the ISR transmit complete flag */
                Iic.ibcr.byte      = (IBEN | TXRX);                     /* send stop signal (clear MSSL) */
                TxBufferemptyflag  = SET;                               /* set the non-ISR transmit buffer empty flag */
            } else {                                                    /* last byte has not been transmitted */
                if(Iic.ibsr.bit.rxak == CLEAR) {                        /* if the slave acknowledged last transfer */
                    if(MasterRxFlag == SET) {                           /* if the last transfer was an address and master is now to Rx */
                        Iic.ibcr.bit.txrx  = CLEAR;                     /* switch to Rx mode */
                        dummyibdrRead      = Iic.ibdr.byte;             /* dummy read of IBDR register */
                    } else {                                            /* last transfer was to instruct other slave to receive */
                        Iic.ibdr.byte = *TxPacketpositionptr;           /* write next byte to IBDR */

                        if (TxPacketpositionptr == TxPacketendptr) {    /* if the last data has been Tx'd */
                            TxCompleteflag = SET;                       /* set the ISR transmit complete flag */
                        } else {                                        /* there is still data to be transmitted */
                            TxPacketpositionptr++;                      /* move to next byte to Tx */
                        }
                    }
                } else {                            /* slave did not acknowledge last transfer */
                    Iic.ibcr.byte = (IBEN | TXRX);  /* send stop signal (clear MSSL) */
                }
            }
        } else {                                                    /* module is to receive data */
            if(RxPacketpositionptr == RxPacketendptr) {             /* if the last byte has been received */
                Iic.ibcr.byte  = (IBEN);                            /* send stop signal (clear MSSL) */
                RxCompleteflag = SET;                               /* set the ISR receive complete flag */
            } else {                                                /* last byte has not been received yet */
                if(RxPacketpositionptr == (RxPacketendptr - 1)) {   /* if the second last byte has been received */
                    Iic.ibcr.bit.txak = SET;                        /* disable active low acknowledge bit (signal to slave to stop Tx) */
                } else {                                            /* second last byte is still to be received */
                                                                    /* do nothing here */
                }
            }

            *RxPacketpositionptr = Iic.ibdr.byte;   /* read the data from the slave */

            if (RxCompleteflag == SET) {            /* if the last byte of data has been received */
                RxCompleteflag     = CLEAR;         /* clear the ISR receive complete flag */
                RxBufferfullflag   = SET;           /* set the receive buffer full flag */
            } else {                                /* there is still data to receive */
                RxPacketpositionptr++;              /* increment the Rx packet position pointer */
            }
        }
    } else {                                                        /* module is in slave mode */
        if(Iic.ibsr.bit.ibal == SET) {                              /* if module is now in slave mode because arbitration has been lost */
            Iic.ibsr.bit.ibal = 1;                                  /* reset the abritration flag */

            if(Iic.ibsr.bit.iaas == SET) {                          /* if this module has been addressed as slave */
                if(Iic.ibsr.bit.srw == SET) {                       /* if module is to transmit */
                    Iic.ibcr.bit.txrx  = SET;                       /* switch to Tx mode */
                    Iic.ibdr.byte      = *TxPacketpositionptr;      /* write next byte to IBDR */

                    if(TxPacketpositionptr == TxPacketendptr) {     /* if the last byte has been transmitted */
                        TxBufferemptyflag = SET;                    /* raise transmit complete flag */
                    } else {                                        /* last byte has not been transmitted */
                        TxPacketpositionptr++;                      /* move to next byte to Tx */
                    }
                } else {                                            /* module is to receive */
                    Iic.ibcr.bit.txrx  = CLEAR;                     /* switch to Rx mode */
                    dummyibdrRead      = Iic.ibdr.byte;             /* dummy read of IBDR register */
                }
            } else {                                                /* module has not been addressed as a slave */
                                                                    /* do nothing here */
            }
        } else {                                                    /* arbitration was not lost */
            if(Iic.ibsr.bit.iaas == SET) {                          /* if this module has been addressed as slave */
                if(Iic.ibsr.bit.srw == SET) {                       /* if module is to transmit */
                    Iic.ibcr.bit.txrx  = SET;                       /* switch to Tx mode */
                    Iic.ibdr.byte      = *TxPacketpositionptr;      /* write next byte to IBDR */

                    if(TxPacketpositionptr == TxPacketendptr) {     /* if the last byte has been transmitted */
                        TxBufferemptyflag = SET;                    /* raise transmit complete flag */
                    } else {                                        /* last byte has not been transmitted */
                        TxPacketpositionptr++;                      /* move to next byte to Tx */
                    }
                } else {                                            /* module is to receive */
                    Iic.ibcr.bit.txrx  = CLEAR;                     /* switch to Rx mode */
                    dummyibdrRead      = Iic.ibdr.byte;             /* dummy read of IBDR register */
                }
            } else {                                                /* module has not been addressed as slave */
                if(Iic.ibcr.bit.txrx == SET) {                      /* if module is to transmit */
                    if(Iic.ibsr.bit.rxak == CLEAR) {                /* if the slave acknowledged last transfer */
                        Iic.ibdr.byte = *TxPacketpositionptr;       /* write next byte to IBDR */

                        if(TxPacketpositionptr == TxPacketendptr) { /* if the last byte has been transmitted */
                            TxBufferemptyflag = SET;                /* raise transmit complete flag */
                        } else {                                    /* last byte has not been transmitted */
                            TxPacketpositionptr++;                  /* move to next byte to Tx */
                        }
                    } else {                                        /* module is not to transmit */
                        Iic.ibcr.bit.txrx  = CLEAR;                 /* switch to Rx mode */
                        dummyibdrRead      = Iic.ibdr.byte;         /* dummy read of IBDR register */
                    }
                } else {                                            /* module is to receive data */
                    *RxPacketpositionptr = Iic.ibdr.byte;           /* read IBDR register and store in current buffer location */

                    if(RxPacketpositionptr == RxPacketendptr) {     /* if the last packet has been received */
                        RxBufferfullflag = SET;                     /* set flag */
                    } else {                                        /* last packet has yet to be received */
                        RxPacketpositionptr++;                      /* move to next byte to transmit */
                    }
                }
            }
        }
    }
}


#endif
