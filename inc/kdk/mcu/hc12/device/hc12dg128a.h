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
 * s. FLOSS-EXCEPTION.txt
 */
#if !defined(__HC12DG128A_H)
#define __HC12DG128A_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


/*
**
**  Module base addresses.
**
*/
#define BASE_ADDR_BCIO      KDK_MAKE_BASE_ADDR(0x0000) /* PA, PB, PE */
#define BASE_ADDR_INIT      KDK_MAKE_BASE_ADDR(0x0010)                  /* 0x10 - INIT */
#define BASE_ADDR_CLK       KDK_MAKE_BASE_ADDR(0x0014)
#define BASE_ADDR_INT       KDK_MAKE_BASE_ADDR(0x001e)
#define BASE_ADDR_BRK       KDK_MAKE_BASE_ADDR(0x0020)                  /* 0x20 - BRK */
#define BASE_ADDR_KWIO      KDK_MAKE_BASE_ADDR(0x0028) /* PJ, PH */
#define BASE_ADDR_PLL       KDK_MAKE_BASE_ADDR(0x0038)
#define BASE_ADDR_PWM       KDK_MAKE_BASE_ADDR(0x0040)
#define BASE_ADDR_ATD0      KDK_MAKE_BASE_ADDR(0x0060)
#define BASE_ADDR_ECT       KDK_MAKE_BASE_ADDR(0x0080)
#define BASE_ADDR_SCI0      KDK_MAKE_BASE_ADDR(0x00c0)
#define BASE_ADDR_SCI1      KDK_MAKE_BASE_ADDR(0x00c8)
#define BASE_ADDR_SPI0      KDK_MAKE_BASE_ADDR(0x00d0)
#define BASE_ADDR_SI        KDK_MAKE_BASE_ADDR(0x00d6)
#define BASE_ADDR_IIC0      KDK_MAKE_BASE_ADDR(0x00e0)
#define BASE_ADDR_EEP       KDK_MAKE_BASE_ADDR(0x00f0)
#define BASE_ADDR_FLS       KDK_MAKE_BASE_ADDR(0x00f4)
#define BASE_ADDR_CAN0      KDK_MAKE_BASE_ADDR(0x0100)
#define BASE_ADDR_ATD1      KDK_MAKE_BASE_ADDR(0x01e0)
#define BASE_ADDR_CAN1      KDK_MAKE_BASE_ADDR(0x0300)


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
#define HC12_FEATURE_ATD    STD_ON      /* Analog/digital converter.    */
#define HC12_FEATURE_PWM    STD_ON      /* Pulse-with-modulator.        */
#define HC12_FEATURE_BDLC   STD_ON      /* Byte datalink controller.    */
#define HC12_FEATURE_SCI    STD_ON      /* Serial comm. interface.      */
#define HC12_FEATURE_SPI    STD_ON      /* Serial periphal interface.   */
#define HC12_FEATURE_BRK    STD_ON      /* Breakpoint module.           */


#define KDK_FEATURE_EEP_HAS_COMPLETION_INT	STD_OFF
#define KDK_FEATURE_EEP_FLS_COMPLETION_INT	STD_OFF	

/*
** 
**  FLS-/EEP-GRAN(ULARITIES)
**  - READ
**  - WRITE
**  - ERASE
**
*/

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

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__HC12DG128A_H */

