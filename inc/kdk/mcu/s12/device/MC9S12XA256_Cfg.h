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
#if !defined(__MC9S12XA256_CONFIG_H)
#define __MC9S12XA256_CONFIG_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#define S12_FEATURE_A           STD_ON
#define S12_FEATURE_ACMP        STD_OFF
#define S12_FEATURE_AD          STD_OFF
#define S12_FEATURE_AD0         STD_ON
#define S12_FEATURE_AD1         STD_ON
#define S12_FEATURE_ADC0        STD_ON
#define S12_FEATURE_ADC1        STD_ON
#define S12_FEATURE_API         STD_ON
#define S12_FEATURE_ATA5HC      STD_OFF
#define S12_FEATURE_ATD         STD_OFF
#define S12_FEATURE_ATD0        STD_OFF
#define S12_FEATURE_ATD1        STD_OFF
#define S12_FEATURE_B           STD_ON
#define S12_FEATURE_BDLC        STD_OFF
#define S12_FEATURE_BF          STD_OFF
#define S12_FEATURE_C           STD_ON
#define S12_FEATURE_CFHC        STD_OFF
#define S12_FEATURE_CGMIPLL     STD_OFF
#define S12_FEATURE_COP         STD_ON
#define S12_FEATURE_COP_CPMU    STD_OFF
#define S12_FEATURE_CORE        STD_OFF
#define S12_FEATURE_CPMU        STD_OFF
#define S12_FEATURE_CRG         STD_ON
#define S12_FEATURE_D           STD_ON
#define S12_FEATURE_D2D         STD_OFF
#define S12_FEATURE_D2DI        STD_OFF
#define S12_FEATURE_DAC0        STD_OFF
#define S12_FEATURE_DAC1        STD_OFF
#define S12_FEATURE_DBG         STD_ON
#define S12_FEATURE_E           STD_ON
#define S12_FEATURE_EBI         STD_ON
#define S12_FEATURE_ECRG        STD_OFF
#define S12_FEATURE_ECT         STD_ON
#define S12_FEATURE_EEP         STD_ON
#define S12_FEATURE_EEPROM      STD_OFF
#define S12_FEATURE_EMAC        STD_OFF
#define S12_FEATURE_EPHY        STD_OFF
#define S12_FEATURE_EPIT        STD_OFF
#define S12_FEATURE_F           STD_OFF
#define S12_FEATURE_FLASH       STD_OFF
#define S12_FEATURE_FLEXRAY     STD_OFF
#define S12_FEATURE_FLS         STD_ON
#define S12_FEATURE_G           STD_OFF
#define S12_FEATURE_H           STD_ON
#define S12_FEATURE_ID          STD_OFF
#define S12_FEATURE_IIC0        STD_ON
#define S12_FEATURE_IIC1        STD_OFF
#define S12_FEATURE_INT         STD_ON
#define S12_FEATURE_IQUE        STD_OFF
#define S12_FEATURE_IRQ         STD_ON
#define S12_FEATURE_J           STD_ON
#define S12_FEATURE_K           STD_ON
#define S12_FEATURE_L           STD_OFF
#define S12_FEATURE_LCD         STD_OFF
#define S12_FEATURE_M           STD_ON
#define S12_FEATURE_MC          STD_OFF
#define S12_FEATURE_MMC         STD_ON
#define S12_FEATURE_MPU         STD_OFF
#define S12_FEATURE_MSCAN0      STD_OFF
#define S12_FEATURE_MSCAN1      STD_OFF
#define S12_FEATURE_MSCAN2      STD_OFF
#define S12_FEATURE_MSCAN3      STD_OFF
#define S12_FEATURE_MSCAN4      STD_OFF
#define S12_FEATURE_MSHC        STD_OFF
#define S12_FEATURE_P           STD_ON
#define S12_FEATURE_PARTID      STD_ON
#define S12_FEATURE_PIM         STD_OFF
#define S12_FEATURE_PIT         STD_ON
#define S12_FEATURE_PMF         STD_OFF
#define S12_FEATURE_PMMC        STD_OFF
#define S12_FEATURE_PWM         STD_OFF
#define S12_FEATURE_PWM16       STD_ON
#define S12_FEATURE_PWM8        STD_ON
#define S12_FEATURE_Q           STD_OFF
#define S12_FEATURE_R           STD_OFF
#define S12_FEATURE_RTI         STD_ON
#define S12_FEATURE_S           STD_ON
#define S12_FEATURE_S12GPIM     STD_OFF
#define S12_FEATURE_SCI0        STD_ON
#define S12_FEATURE_SCI1        STD_ON
#define S12_FEATURE_SCI2        STD_ON
#define S12_FEATURE_SCI3        STD_OFF
#define S12_FEATURE_SCI4        STD_ON
#define S12_FEATURE_SCI5        STD_OFF
#define S12_FEATURE_SCI6        STD_OFF
#define S12_FEATURE_SCI7        STD_OFF
#define S12_FEATURE_SDHC        STD_OFF
#define S12_FEATURE_SINT        STD_OFF
#define S12_FEATURE_SMHC        STD_OFF
#define S12_FEATURE_SMRAM       STD_OFF
#define S12_FEATURE_SPI0        STD_ON
#define S12_FEATURE_SPI1        STD_ON
#define S12_FEATURE_SPI2        STD_ON
#define S12_FEATURE_SSD0        STD_OFF
#define S12_FEATURE_SSD1        STD_OFF
#define S12_FEATURE_SSD2        STD_OFF
#define S12_FEATURE_SSD3        STD_OFF
#define S12_FEATURE_SSD4        STD_OFF
#define S12_FEATURE_SSD5        STD_OFF
#define S12_FEATURE_T           STD_ON
#define S12_FEATURE_TIM         STD_OFF
#define S12_FEATURE_TIM0        STD_OFF
#define S12_FEATURE_TIM1        STD_OFF
#define S12_FEATURE_TIM2        STD_OFF
#define S12_FEATURE_U           STD_OFF
#define S12_FEATURE_USB20       STD_OFF
#define S12_FEATURE_V           STD_OFF
#define S12_FEATURE_VREG        STD_ON
#define S12_FEATURE_W           STD_OFF
#define S12_FEATURE_XGATE       STD_ON

#define BASE_ADDR_A             KDK_MAKE_BASE_ADDR(0x0000)
#define BASE_ADDR_B             KDK_MAKE_BASE_ADDR(0x0001)
#define BASE_ADDR_C             KDK_MAKE_BASE_ADDR(0x0004)
#define BASE_ADDR_D             KDK_MAKE_BASE_ADDR(0x0005)
#define BASE_ADDR_E             KDK_MAKE_BASE_ADDR(0x0008)
#define BASE_ADDR_MMC           KDK_MAKE_BASE_ADDR(0x000A)
#define BASE_ADDR_K             KDK_MAKE_BASE_ADDR(0x000C)
#define BASE_ADDR_EBI           KDK_MAKE_BASE_ADDR(0x000E)
#define BASE_ADDR_PARTID        KDK_MAKE_BASE_ADDR(0x001A)
#define BASE_ADDR_IRQ           KDK_MAKE_BASE_ADDR(0x001E)
#define BASE_ADDR_DBG           KDK_MAKE_BASE_ADDR(0x0020)
#define BASE_ADDR_CRG           KDK_MAKE_BASE_ADDR(0x0034)
#define BASE_ADDR_RTI           KDK_MAKE_BASE_ADDR(0x003B)
#define BASE_ADDR_COP           KDK_MAKE_BASE_ADDR(0x003C)
#define BASE_ADDR_ECT           KDK_MAKE_BASE_ADDR(0x0040)
#define BASE_ADDR_ADC1          KDK_MAKE_BASE_ADDR(0x0080)
#define BASE_ADDR_SCI2          KDK_MAKE_BASE_ADDR(0x00B8)
#define BASE_ADDR_SCI0          KDK_MAKE_BASE_ADDR(0x00C8)
#define BASE_ADDR_SCI1          KDK_MAKE_BASE_ADDR(0x00D0)
#define BASE_ADDR_SPI0          KDK_MAKE_BASE_ADDR(0x00D8)
#define BASE_ADDR_IIC0          KDK_MAKE_BASE_ADDR(0x00E0)
#define BASE_ADDR_SPI1          KDK_MAKE_BASE_ADDR(0x00F0)
#define BASE_ADDR_SPI2          KDK_MAKE_BASE_ADDR(0x00F8)
#define BASE_ADDR_FLS           KDK_MAKE_BASE_ADDR(0x0100)
#define BASE_ADDR_EEP           KDK_MAKE_BASE_ADDR(0x0110)
#define BASE_ADDR_INT           KDK_MAKE_BASE_ADDR(0x0121)
#define BASE_ADDR_SCI4          KDK_MAKE_BASE_ADDR(0x0130)
#define BASE_ADDR_T             KDK_MAKE_BASE_ADDR(0x0240)
#define BASE_ADDR_S             KDK_MAKE_BASE_ADDR(0x0248)
#define BASE_ADDR_M             KDK_MAKE_BASE_ADDR(0x0250)
#define BASE_ADDR_P             KDK_MAKE_BASE_ADDR(0x0258)
#define BASE_ADDR_H             KDK_MAKE_BASE_ADDR(0x0260)
#define BASE_ADDR_J             KDK_MAKE_BASE_ADDR(0x0268)
#define BASE_ADDR_AD0           KDK_MAKE_BASE_ADDR(0x0271)
#define BASE_ADDR_AD1           KDK_MAKE_BASE_ADDR(0x0278)
#define BASE_ADDR_ADC0          KDK_MAKE_BASE_ADDR(0x02C0)
#define BASE_ADDR_VREG          KDK_MAKE_BASE_ADDR(0x02F1)
#define BASE_ADDR_API           KDK_MAKE_BASE_ADDR(0x02F2)
#define BASE_ADDR_PWM8          KDK_MAKE_BASE_ADDR(0x0300)
#define BASE_ADDR_PWM16         KDK_MAKE_BASE_ADDR(0x030C)
#define BASE_ADDR_PIT           KDK_MAKE_BASE_ADDR(0x0340)
#define BASE_ADDR_XGATE         KDK_MAKE_BASE_ADDR(0x0380)


#define S12_CAN_NUM_CONTROLLERS                 ((uint8)0)


#define S12_SCI_NUM_INTERFACES                  ((uint8)4)

#define S12_IMPLEMENT_SCI_CONTROLLER_MAPPING    \
    BASE_ADDR_SCI0,                             \
    BASE_ADDR_SCI1,                             \
    BASE_ADDR_SCI2,                             \
    BASE_ADDR_SCI4,                             \

#define S12_SPI_NUM_INTERFACES                  ((uint8)3)

#define S12_IMPLEMENT_SPI_CONTROLLER_MAPPING    \
    BASE_ADDR_SPI0,                             \
    BASE_ADDR_SPI1,                             \
    BASE_ADDR_SPI2,                             \

/*
** Ports.
*/
#define S12MEBI_PORT_A                           ((Kdk_PortType)0x0)  /* 0x0 */
#define S12MEBI_PORT_B                           ((Kdk_PortType)0x1)  /* 0x1 */
#define S12MEBI_PORT_C                           ((Kdk_PortType)0x2)  /* 0x4 */
#define S12MEBI_PORT_D                           ((Kdk_PortType)0x3)  /* 0x5 */
#define S12MEBI_PORT_E                           ((Kdk_PortType)0x4)  /* 0x8 */
#define S12MEBI_PORT_K                           ((Kdk_PortType)0x5)  /* 0xc */
#define S12PIM_PORT_T                           ((Kdk_PortType)0x6)  /* 0x240 */
#define S12PIM_PORT_S                           ((Kdk_PortType)0x7)  /* 0x248 */
#define S12PIM_PORT_M                           ((Kdk_PortType)0x8)  /* 0x250 */
#define S12PIM_PORT_P                           ((Kdk_PortType)0x9)  /* 0x258 */
#define S12PIM_PORT_H                           ((Kdk_PortType)0xa)  /* 0x260 */
#define S12PIM_PORT_J                           ((Kdk_PortType)0xb)  /* 0x268 */


/*
** Symbolic Names for Port-Pins.
*/
#define S12MEBI_CHANNEL_A_0                      ((Kdk_ChannelType)((0 * 8) + 0))
#define S12MEBI_CHANNEL_A_1                      ((Kdk_ChannelType)((0 * 8) + 1))
#define S12MEBI_CHANNEL_A_2                      ((Kdk_ChannelType)((0 * 8) + 2))
#define S12MEBI_CHANNEL_A_3                      ((Kdk_ChannelType)((0 * 8) + 3))
#define S12MEBI_CHANNEL_A_4                      ((Kdk_ChannelType)((0 * 8) + 4))
#define S12MEBI_CHANNEL_A_5                      ((Kdk_ChannelType)((0 * 8) + 5))
#define S12MEBI_CHANNEL_A_6                      ((Kdk_ChannelType)((0 * 8) + 6))
#define S12MEBI_CHANNEL_A_7                      ((Kdk_ChannelType)((0 * 8) + 7))

#define S12MEBI_CHANNEL_B_0                      ((Kdk_ChannelType)((1 * 8) + 0))
#define S12MEBI_CHANNEL_B_1                      ((Kdk_ChannelType)((1 * 8) + 1))
#define S12MEBI_CHANNEL_B_2                      ((Kdk_ChannelType)((1 * 8) + 2))
#define S12MEBI_CHANNEL_B_3                      ((Kdk_ChannelType)((1 * 8) + 3))
#define S12MEBI_CHANNEL_B_4                      ((Kdk_ChannelType)((1 * 8) + 4))
#define S12MEBI_CHANNEL_B_5                      ((Kdk_ChannelType)((1 * 8) + 5))
#define S12MEBI_CHANNEL_B_6                      ((Kdk_ChannelType)((1 * 8) + 6))
#define S12MEBI_CHANNEL_B_7                      ((Kdk_ChannelType)((1 * 8) + 7))

#define S12MEBI_CHANNEL_C_0                      ((Kdk_ChannelType)((2 * 8) + 0))
#define S12MEBI_CHANNEL_C_1                      ((Kdk_ChannelType)((2 * 8) + 1))
#define S12MEBI_CHANNEL_C_2                      ((Kdk_ChannelType)((2 * 8) + 2))
#define S12MEBI_CHANNEL_C_3                      ((Kdk_ChannelType)((2 * 8) + 3))
#define S12MEBI_CHANNEL_C_4                      ((Kdk_ChannelType)((2 * 8) + 4))
#define S12MEBI_CHANNEL_C_5                      ((Kdk_ChannelType)((2 * 8) + 5))
#define S12MEBI_CHANNEL_C_6                      ((Kdk_ChannelType)((2 * 8) + 6))
#define S12MEBI_CHANNEL_C_7                      ((Kdk_ChannelType)((2 * 8) + 7))

#define S12MEBI_CHANNEL_D_0                      ((Kdk_ChannelType)((3 * 8) + 0))
#define S12MEBI_CHANNEL_D_1                      ((Kdk_ChannelType)((3 * 8) + 1))
#define S12MEBI_CHANNEL_D_2                      ((Kdk_ChannelType)((3 * 8) + 2))
#define S12MEBI_CHANNEL_D_3                      ((Kdk_ChannelType)((3 * 8) + 3))
#define S12MEBI_CHANNEL_D_4                      ((Kdk_ChannelType)((3 * 8) + 4))
#define S12MEBI_CHANNEL_D_5                      ((Kdk_ChannelType)((3 * 8) + 5))
#define S12MEBI_CHANNEL_D_6                      ((Kdk_ChannelType)((3 * 8) + 6))
#define S12MEBI_CHANNEL_D_7                      ((Kdk_ChannelType)((3 * 8) + 7))

#define S12MEBI_CHANNEL_E_0                      ((Kdk_ChannelType)((4 * 8) + 0))
#define S12MEBI_CHANNEL_E_1                      ((Kdk_ChannelType)((4 * 8) + 1))
#define S12MEBI_CHANNEL_E_2                      ((Kdk_ChannelType)((4 * 8) + 2))
#define S12MEBI_CHANNEL_E_3                      ((Kdk_ChannelType)((4 * 8) + 3))
#define S12MEBI_CHANNEL_E_4                      ((Kdk_ChannelType)((4 * 8) + 4))
#define S12MEBI_CHANNEL_E_5                      ((Kdk_ChannelType)((4 * 8) + 5))
#define S12MEBI_CHANNEL_E_6                      ((Kdk_ChannelType)((4 * 8) + 6))
#define S12MEBI_CHANNEL_E_7                      ((Kdk_ChannelType)((4 * 8) + 7))

#define S12MEBI_CHANNEL_K_0                      ((Kdk_ChannelType)((5 * 8) + 0))
#define S12MEBI_CHANNEL_K_1                      ((Kdk_ChannelType)((5 * 8) + 1))
#define S12MEBI_CHANNEL_K_2                      ((Kdk_ChannelType)((5 * 8) + 2))
#define S12MEBI_CHANNEL_K_3                      ((Kdk_ChannelType)((5 * 8) + 3))
#define S12MEBI_CHANNEL_K_4                      ((Kdk_ChannelType)((5 * 8) + 4))
#define S12MEBI_CHANNEL_K_5                      ((Kdk_ChannelType)((5 * 8) + 5))
#define S12MEBI_CHANNEL_K_6                      ((Kdk_ChannelType)((5 * 8) + 6))
#define S12MEBI_CHANNEL_K_7                      ((Kdk_ChannelType)((5 * 8) + 7))

#define S12PIM_CHANNEL_T_0                      ((Kdk_ChannelType)((6 * 8) + 0))
#define S12PIM_CHANNEL_T_1                      ((Kdk_ChannelType)((6 * 8) + 1))
#define S12PIM_CHANNEL_T_2                      ((Kdk_ChannelType)((6 * 8) + 2))
#define S12PIM_CHANNEL_T_3                      ((Kdk_ChannelType)((6 * 8) + 3))
#define S12PIM_CHANNEL_T_4                      ((Kdk_ChannelType)((6 * 8) + 4))
#define S12PIM_CHANNEL_T_5                      ((Kdk_ChannelType)((6 * 8) + 5))
#define S12PIM_CHANNEL_T_6                      ((Kdk_ChannelType)((6 * 8) + 6))
#define S12PIM_CHANNEL_T_7                      ((Kdk_ChannelType)((6 * 8) + 7))

#define S12PIM_CHANNEL_S_0                      ((Kdk_ChannelType)((7 * 8) + 0))
#define S12PIM_CHANNEL_S_1                      ((Kdk_ChannelType)((7 * 8) + 1))
#define S12PIM_CHANNEL_S_2                      ((Kdk_ChannelType)((7 * 8) + 2))
#define S12PIM_CHANNEL_S_3                      ((Kdk_ChannelType)((7 * 8) + 3))
#define S12PIM_CHANNEL_S_4                      ((Kdk_ChannelType)((7 * 8) + 4))
#define S12PIM_CHANNEL_S_5                      ((Kdk_ChannelType)((7 * 8) + 5))
#define S12PIM_CHANNEL_S_6                      ((Kdk_ChannelType)((7 * 8) + 6))
#define S12PIM_CHANNEL_S_7                      ((Kdk_ChannelType)((7 * 8) + 7))

#define S12PIM_CHANNEL_M_0                      ((Kdk_ChannelType)((8 * 8) + 0))
#define S12PIM_CHANNEL_M_1                      ((Kdk_ChannelType)((8 * 8) + 1))
#define S12PIM_CHANNEL_M_2                      ((Kdk_ChannelType)((8 * 8) + 2))
#define S12PIM_CHANNEL_M_3                      ((Kdk_ChannelType)((8 * 8) + 3))
#define S12PIM_CHANNEL_M_4                      ((Kdk_ChannelType)((8 * 8) + 4))
#define S12PIM_CHANNEL_M_5                      ((Kdk_ChannelType)((8 * 8) + 5))
#define S12PIM_CHANNEL_M_6                      ((Kdk_ChannelType)((8 * 8) + 6))
#define S12PIM_CHANNEL_M_7                      ((Kdk_ChannelType)((8 * 8) + 7))

#define S12PIM_CHANNEL_P_0                      ((Kdk_ChannelType)((9 * 8) + 0))
#define S12PIM_CHANNEL_P_1                      ((Kdk_ChannelType)((9 * 8) + 1))
#define S12PIM_CHANNEL_P_2                      ((Kdk_ChannelType)((9 * 8) + 2))
#define S12PIM_CHANNEL_P_3                      ((Kdk_ChannelType)((9 * 8) + 3))
#define S12PIM_CHANNEL_P_4                      ((Kdk_ChannelType)((9 * 8) + 4))
#define S12PIM_CHANNEL_P_5                      ((Kdk_ChannelType)((9 * 8) + 5))
#define S12PIM_CHANNEL_P_6                      ((Kdk_ChannelType)((9 * 8) + 6))
#define S12PIM_CHANNEL_P_7                      ((Kdk_ChannelType)((9 * 8) + 7))

#define S12PIM_CHANNEL_H_0                      ((Kdk_ChannelType)((10 * 8) + 0))
#define S12PIM_CHANNEL_H_1                      ((Kdk_ChannelType)((10 * 8) + 1))
#define S12PIM_CHANNEL_H_2                      ((Kdk_ChannelType)((10 * 8) + 2))
#define S12PIM_CHANNEL_H_3                      ((Kdk_ChannelType)((10 * 8) + 3))
#define S12PIM_CHANNEL_H_4                      ((Kdk_ChannelType)((10 * 8) + 4))
#define S12PIM_CHANNEL_H_5                      ((Kdk_ChannelType)((10 * 8) + 5))
#define S12PIM_CHANNEL_H_6                      ((Kdk_ChannelType)((10 * 8) + 6))
#define S12PIM_CHANNEL_H_7                      ((Kdk_ChannelType)((10 * 8) + 7))

#define S12PIM_CHANNEL_J_0                      ((Kdk_ChannelType)((11 * 8) + 0))
#define S12PIM_CHANNEL_J_1                      ((Kdk_ChannelType)((11 * 8) + 1))
#define S12PIM_CHANNEL_J_2                      ((Kdk_ChannelType)((11 * 8) + 2))
#define S12PIM_CHANNEL_J_3                      ((Kdk_ChannelType)((11 * 8) + 3))
#define S12PIM_CHANNEL_J_4                      ((Kdk_ChannelType)((11 * 8) + 4))
#define S12PIM_CHANNEL_J_5                      ((Kdk_ChannelType)((11 * 8) + 5))
#define S12PIM_CHANNEL_J_6                      ((Kdk_ChannelType)((11 * 8) + 6))
#define S12PIM_CHANNEL_J_7                      ((Kdk_ChannelType)((11 * 8) + 7))



/*
**  ADC
*/
#define KAR_IMPLEMENT_ADC_INIT(ConfigPtr) \
    _BEGIN_BLOCK                          \
    _END_BLOCK


#define KAR_IMPLEMENT_ADC_DEINIT()        \
    _BEGIN_BLOCK                          \
    _END_BLOCK


/*
**  Features
*/
#define S12ATD_VARIANT_10B8         STD_OFF
#define S12ATD_VARIANT_10B16        STD_ON
#define KDK_ATD_FEATURE_HW_TRIGGER  STD_ON
#define S12ATD_MODULE               S12ATD_VARIANT_10B8    // S12ATD_VARIANT_10B16

#define S12_FLS_HAS_ECC_FLASH       STD_OFF

#define KAR_IMPLEMENT_ADC_START_GROUP_CONVERSION(Group)
#define KAR_IMPLEMENT_ADC_STOP_GROUP_CONVERSION(Group)
#define KAR_IMPLEMENT_ADC_READ_GROUP(Group, DataBufferPtr)                  (E_OK)
#define KAR_IMPLEMENT_ADC_ENABLE_HARDWARE_TRIGGER(Group)
#define KAR_IMPLEMENT_ADC_DISABLE_HARDWARE_TRIGGER(Group)
#define KAR_IMPLEMENT_ADC_ENABLE_GROUP_NOTIFICATION(Group)
#define KAR_IMPLEMENT_ADC_DISABLE_GROUP_NOTIFICATION(Group)
#define KAR_IMPLEMENT_ADC_GET_GROUP_STATUS(Group)                           (ADC_COMPLETED)
#define KAR_IMPLEMENT_ADC_GET_STREAM_LAST_POINTER(Group, PtrToSamplePtr)    ((Adc_StreamNumSampleType)1)
#define KAR_IMPLEMENT_ADC_SETUP_RESULT_BUFFER(Group, DataBufferPtr)         (E_OK)



#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__MC9S12XA256_CONFIG_H */

