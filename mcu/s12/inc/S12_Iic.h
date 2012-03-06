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
#if !defined(__S12IIC_H)
#define __S12IIC_H

#if CPU_FAMILY == CPU12_S12
    #include "S12_Hw.h"
#elif CPU_FAMILY == CPU12_HC12
    #include "HC12_Hw.h"
/*    #define S12_REG8    HC12_REG8 */
#else
    #error Wrong CPU Family.
#endif

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
** Register-Offsets
*/
#define IBAD            ((uint8)0x00)
/*  IBAD-Bits.  */

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
    uint8   Prescaler;
} S12Iic_ConfigType;

typedef enum taS12Iic_StatusType {
    S12IIC_OK,
    S12IIC_UNINIT,
    S12IIC_ID,
    S12IIC_STATE,
    S12IIC_VALUE
} S12Iic_StatusType;

typedef void (*IIC_PresenceCallback)(uint8 addr);

/*
**  Function-Prototypes.
*/

/* Basic-Functions.     */
void    S12Iic_Init(S12Iic_ConfigType const * const Cfg);
void    S12Iic_Start(S12Iic_ConfigType const * const Cfg);
void    S12Iic_Restart(S12Iic_ConfigType const * const Cfg);
void    S12Iic_Stop(S12Iic_ConfigType const * const Cfg);
boolean S12Iic_Write(S12Iic_ConfigType const * const Cfg, uint8 b);
void    S12Iic_Read(S12Iic_ConfigType const * const Cfg, /*@out@*/ uint8 * b, boolean ack);


/* Highlevel-Functions. */
boolean S12Iic_PresenceCheck(S12Iic_ConfigType const * const Cfg, uint8 slave_base_addr, uint8 nbits, IIC_PresenceCallback callback);

boolean S12Iic_ModeReq(S12Iic_ConfigType const * const Cfg, uint8 slave_addr, boolean write);


#define S12Iic_ReadMode(cfg, addr)  S12Iic_ModeReq((cfg), (addr), FALSE)
#define S12Iic_WriteMode(cfg, addr) S12Iic_ModeReq((cfg), (addr), TRUE)

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __S12IIC_H */
