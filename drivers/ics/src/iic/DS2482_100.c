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
#include "DS2482_100.h"

/*
**  todo: Make independent of IIC-Implementation.
*/

/*
**  Local Defines.
*/

/* Configuration Register Bits. */
#define CONF_1WS_BAR                ((uint8)0x80)
#define CONF_SPU_BAR                ((uint8)0x40)
#define CONF_PPM_BAR                ((uint8)0x20)
#define CONF_APU_BAR                ((uint8)0x10)
#define CONF_1WS                    ((uint8)0x08)
#define CONF_SPU                    ((uint8)0x04)
#define CONF_PPM                    ((uint8)0x02)
#define CONF_APU                    ((uint8)0x01)

/* Status Register Bits. */
#define STATUS_DIR                  ((uint8)0x80)
#define STATUS_TSB                  ((uint8)0x40)
#define STATUS_SBR                  ((uint8)0x20)
#define STATUS_RST                  ((uint8)0x10)
#define STATUS_LL                   ((uint8)0x08)
#define STATUS_SD                   ((uint8)0x04)
#define STATUS_PPD                  ((uint8)0x02)
#define STATUS_1WB                  ((uint8)0x01)

/*  Pointer Codes (Register Selection). */
#define REG_STATUS                  ((uint8)0xf0)
#define REG_READ_DATA               ((uint8)0xe1)
#define REG_CONF                    ((uint8)0xc3)

/* Feature Setting */
#define ACTIVE_PULLUP_ON            CONF_APU
#define ACTIVE_PULLUP_OFF           CONF_APU_BAR

#define PRESENCE_PULSE_MASKING_ON   CONF_PPM
#define PRESENCE_PULSE_MASKING_OFF  CONF_PPM_BAR

#define STRONG_PULLUP_ON            CONF_SPU
#define STRONG_PULLUP_OFF           CONF_SPU_BAR

#define OVERDRIVE_SPEED_ON          CONF_1WS
#define OVERDRIVE_SPEED_OFF         CONF_1WS_BAR

/* Command-Codes. */
#define CMD_DEVICE_RESET            ((uint8)0xf0)
#define CMD_SET_READ_POINTER        ((uint8)0xe1)
#define CMD_WRITE_CONFIGURATION     ((uint8)0xd2)
#define CMD_1WIRE_RESET             ((uint8)0xb4)
#define CMD_1WIRE_SINGLE_BIT        ((uint8)0x87)
#define CMD_1WIRE_WRITE_BYTE        ((uint8)0xa5)
#define CMD_1WIRE_READ_BYTE         ((uint8)0x96)
#define CMD_1WIRE_TRIPLET           ((uint8)0x78)

#define CMD_DRST                    ((uint8)0xf0)   /* Device Reset         */
#define CMD_SRP                     ((uint8)0xe1)   /* Set Read Pointer     */
#define CMD_WCFG                    ((uint8)0xd2)   /* Write Configuration  */
#define CMD_1WRS                    ((uint8)0xb4)   /* 1-Wire Reset         */
#define CMD_1WSB                    ((uint8)0x87)   /* 1-Wire Single Bit    */
#define CMD_1WWB                    ((uint8)0xa5)   /* 1-Wire Write Byte    */
#define CMD_1WRB                    ((uint8)0x96)   /* 1-Wire Read Byte     */
#define CMD_1WT                     ((uint8)0x78)   /* 1-Wire Triplet       */

/* besser: IIC_CHECK_SUCCESS */
#define IIC_CHECK_SUCCESS(cond)  \
    do {                         \
        if (!(cond)) {           \
            HC12Iic_Stop(&IIC0); \
            return FALSE;        \
        }                        \
    } while (0)

boolean DS2482_100_DeviceReset(uint8 addr)
{
    boolean ack;
    uint8   data;

    ack = HC12Iic_WriteMode(&IIC0, addr);
    IIC_CHECK_SUCCESS(ack);

    HC12Iic_Write(&IIC0, CMD_DEVICE_RESET, &ack);
    IIC_CHECK_SUCCESS(ack);

    ack = HC12Iic_ReadMode(&IIC0, addr);
    IIC_CHECK_SUCCESS(ack);

    HC12Iic_Read(&IIC0, &data, FALSE);

    HC12Iic_Stop(&IIC0);

    return (data & (STATUS_RST | STATUS_SD)) == STATUS_RST;
}


boolean DS2482_100_BusReset(uint8 addr)
{
    boolean ack;
    uint8   data;

    ack = HC12Iic_WriteMode(&IIC0, addr);
    IIC_CHECK_SUCCESS(ack);

    HC12Iic_Write(&IIC0, CMD_1WIRE_RESET, &ack);
    IIC_CHECK_SUCCESS(ack);

    HC12Iic_Stop(&IIC0);

    return TRUE;
}


void DS2482_100_Init(void)
{

}


