/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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
 *
 */
#if !defined(__S12DP256B_H)
#define __S12DP256B_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/* TODO: echte Addressen!!! */
/* TODO: Basis-Adresse´n mit 'KDK_' prefixen!!! */
/* TODO: BARREL_SHIFTER - Feature !!! */	
#define BASE_ADDR_INT           KDK_MAKE_BASE_ADDR(0x0000)
#define BASE_ADDR_MEBI          KDK_MAKE_BASE_ADDR(0x0000)
#define BASE_ADDR_MMC           KDK_MAKE_BASE_ADDR(0x0000)

#define BASE_ADDR_BKP           KDK_MAKE_BASE_ADDR(0x0028)

#define BASE_ADDR_CRG           KDK_MAKE_BASE_ADDR(0x0034)
#define BASE_ADDR_ECT           KDK_MAKE_BASE_ADDR(0x0040)

#define BASE_ADDR_ATD0          KDK_MAKE_BASE_ADDR(0x0080)
#define BASE_ADDR_PWM           KDK_MAKE_BASE_ADDR(0x00A0)
#define BASE_ADDR_SCI0          KDK_MAKE_BASE_ADDR(0x00c8)
#define BASE_ADDR_SCI1          KDK_MAKE_BASE_ADDR(0x00d0)
#define BASE_ADDR_SPI0          KDK_MAKE_BASE_ADDR(0x00d8)
#define BASE_ADDR_IIC0          KDK_MAKE_BASE_ADDR(0x00e0)
#define BASE_ADDR_SPI1          KDK_MAKE_BASE_ADDR(0x00f0)
#define BASE_ADDR_SPI2          KDK_MAKE_BASE_ADDR(0x00f8)
#define BASE_ADDR_FLS           KDK_MAKE_BASE_ADDR(0x0100)

#define BASE_ADDR_ATD1          KDK_MAKE_BASE_ADDR(0x0120)

#define BASE_ADDR_CAN0          KDK_MAKE_BASE_ADDR(0x0140)
#define BASE_ADDR_CAN1          KDK_MAKE_BASE_ADDR(0x0180)
#define BASE_ADDR_CAN2          KDK_MAKE_BASE_ADDR(0x01C0)
#define BASE_ADDR_CAN3          KDK_MAKE_BASE_ADDR(0x0200)

#define BASE_ADDR_PIM           KDK_MAKE_BASE_ADDR(0x0240)

#define BASE_ADDR_CAN4          KDK_MAKE_BASE_ADDR(0x0280)


/*
**  Features
*/
#define S12ATD_VARIANT_10B8	    STD_OFF
#define S12ATD_VARIANT_10B16	    STD_ON
#define S12ATD_MODULE		    S12ATD_VARIANT_10B8

#define S12_FEATURE_CAN		    STD_ON      /* CAN-Bus.                     */

#define KDK_ATD_FEATURE_HW_TRIGGER  STD_ON
#define KDK_ATD_PERIODIC_SAMPLING   STD_OFF


/*
**  TODO: Makros für multiple Basis-Addressen, z.B.:

static uint16 S12Can_ControllerMapping[SC12_CAN_NUM_CONTROLLERS] = {
// MACRO_START	    -- S12_CAN_BASE_ADRESSES
    BASE_ADDR_CAN0,
    BASE_ADDR_CAN1,
    BASE_ADDR_CAN2,
    BASE_ADDR_CAN3,
    BASE_ADDR_CAN4,
// MACRO_END
};

**
*/

/*
**
**  Feature multiplicities.
**
*/	
#define SC12_CAN_NUM_CONTROLLERS    5
#define SC12_SCI_NUM_CONTROLLERS    2
#define SC12_SPI_NUM_CONTROLLERS    3	/* ??? */

#if 0
//
//  COPIED FROM HC12.
//

/*
**
**  Features
**
*/
#define HC12_FEATURE_STM    STD_OFF     /* Standard timer module.       */
#define HC12_FEATURE_ECT    STD_ON      /* Enhanced capture timer.      */
#define HC12_FEATURE_PLL    STD_ON      /* Phase locked loop.           */
#define HC12_FEATURE_EEPA   STD_ON      /* 2nd generation EEPROM.       */
#define HC12_FEATURE_FLSA   STD_ON      /* 2nd generation Flash.        */
#define HC12_FEATURE_CAN    STD_ON      /* CAN-Bus.                     */
#define HC12
_FEATURE_ATD    STD_ON      /* Analog/digital converter.    */
#define HC12_FEATURE_PWM    STD_ON      /* Pulse-with-modulator.        */
#define HC12_FEATURE_BDLC   STD_ON      /* Byte datalink controller.    */
#define HC12_FEATURE_SCI    STD_ON      /* Serial comm. interface.      */
#define HC12_FEATURE_SPI    STD_ON      /* Serial periphal interface.   */
#define HC12_FEATURE_BRK    STD_ON      /* Breakpoint module.           */


/*
**
**  Feature multiplicities.
**
*/
#define HC12_EEP_SIZE               ((uint16)0x0800u)

#define HC12_FLASH_NUM_BLOCKS       ((uint8)0x04)
#define HC12_FLASH_BLOCK_SIZE       ((uint16)0x8000u)

#define HC12_RAM_SIZE               ((uint16)0x2000u)

#define HC12_ATD_NUM_CONVERTERS     2
#define HC12_BDLC_NUM_CONTROLLERS   1
#define HC12_CAN_NUM_CONTROLLERS    2
#define HC12_SCI_NUM_CONTROLLERS    2
#define HC12_SPI_NUM_CONTROLLERS    1

#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__S12DP256B_H */

