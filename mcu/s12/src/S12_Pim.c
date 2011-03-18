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
#include "mcu/s12/inc/S12_Pim.h"
#include "Hw_Cfg.h"
#include "Utl.h"


#if 0
static const uint8 S12PIM_PORT_BASES[]={
    (uint8)0x00,(uint8)0x08,(uint8)0x10,(uint8)0x18,(uint8)0x20,(uint8)0x28
};
#endif

/*
**
**  REFERENCES:
**  ===========
**  MC9S12DP256 Port Intergration Module (PIM) Block User Guide V02.07.
**
*/

/*
    • Port A, B, E, and K related to the core logic and multiplexed bus interface
    • Port T connected to the timer module
    • The serial port S associated with 2 SCI and 1 SPI modules
    • Port M associated with 4 CAN and 1 BDLC module
    • Port P connected to the PWM and 2 SPI modules, which also can be used as an external interrupt source
    • The standard I/O ports H and J associated with the fifth CAN module and the IIC interface. These ports
      can also be used as external interrupt sources.
*/

/*
**
**  USE-CASES for 'S12PIM_OUTPUT_CHECKED' and 'S12PIM_READ_OUTPUT_LATCH':
**  =====================================================================
**
**  - 'S12PIM_OUTPUT_CHECKED':      read back the value written from input-register,
**                                  return 'FALSE' if not equal.
**  - 'S12PIM_READ_OUTPUT_LATCH':   read port output-latch instead of input-register.
**
**
**  a) Short-/Open-Circuit detection:
**  ---------------------------------
**  Obviously, the written should equal to the value read back.
**  'S12Pim_WritePort' returns FALSE, if this is not the case.
**  (requires 'S12PIM_OUTPUT_CHECKED'-Option).
**
**  b) Bit-banged implementation of a Bus-Protocol in a wired-AND, open-drain fashion:
**  ----------------------------------------------------------------------------------
**
**  w  | rb | description
**  ---------------------
**  0  | 0  | OK
**  1  | 1  | OK
**  0  | 1  | short circuit to VCC
**  1  | 0  | collision - passive H-level overridden by an active L-level
**
**  (requires 'S12PIM_OUTPUT_CHECKED'- and 'S12PIM_READ_OUTPUT_LATCH'-Options,
**   furthermore either 'real' (appropriate bit in Wired-Or mode register set)
**   or 'pseudo' (diode-circuit) opendrain outputs).
**
*/


// AR_MODULE_ID_S12_PIM

#if S12PIM_DEV_ERROR_DETECT==STD_ON
#define S12PIM_ASSERT_VALID_PORT(port)  \
    _BEGIN_BLOCK                        \
        if (port>S12PIM_PORT_MAX) {     \
/*            ErrorHandler(...); */     \
            return;                     \
        }                               \
    _END_BLOCK
#else
#define S12PIM_ASSERT_VALID_PORT(port)
#endif /* S12PIM_DEV_ERROR_DETECT */


#if S12PIM_DEV_ERROR_DETECT==STD_ON
#define S12PIM_ASSERT_VALID_CHANNEL(channel)    \
    _BEGIN_BLOCK                                \
        if (channel>S12PIM_CHANNEL_MAX) {       \
/*            ErrorHandler(...); */             \
            return;                             \
        }                                       \
    _END_BLOCK
#else
#define S12PIM_ASSERT_VALID_CHANNEL(channel)
#endif /* S12PIM_DEV_ERROR_DETECT */


void S12Pim_Init(S12Pim_ConfigType const * ConfigPtr)
{
    S12PIM_REG8(MODRR)=ConfigPtr->Modrr;

    /* PortT */
    S12PIM_REG8(RDRT)=ConfigPtr->RdrT;
    S12PIM_REG8(PERT)=ConfigPtr->PerT;
    S12PIM_REG8(PPST)=ConfigPtr->PpsT;
    S12PIM_REG8(PTT)=ConfigPtr->PtT;
    S12PIM_REG8(DDRT)=ConfigPtr->DdrT;

    /* PortS */
    S12PIM_REG8(RDRS)=ConfigPtr->RdrS;
    S12PIM_REG8(PERS)=ConfigPtr->PerS;
    S12PIM_REG8(PPSS)=ConfigPtr->PpsS;
    S12PIM_REG8(WOMS)=ConfigPtr->WomsS;
    S12PIM_REG8(PTS)=ConfigPtr->PtS;
    S12PIM_REG8(DDRS)=ConfigPtr->DdrS;

    /* PortM */
    S12PIM_REG8(RDRM)=ConfigPtr->RdrM;
    S12PIM_REG8(PERM)=ConfigPtr->PerM;
    S12PIM_REG8(PPSM)=ConfigPtr->PpsM;
    S12PIM_REG8(WOMM)=ConfigPtr->WomM;
    S12PIM_REG8(PTM)=ConfigPtr->PtM;
    S12PIM_REG8(DDRM)=ConfigPtr->DdrM;

    /* PortP */
    S12PIM_REG8(RDRP)=ConfigPtr->RdrP;
    S12PIM_REG8(PERP)=ConfigPtr->PerP;
    S12PIM_REG8(PPSP)=ConfigPtr->PpsP;
    S12PIM_REG8(PIEP)=ConfigPtr->PieP;
    S12PIM_REG8(PTP)=ConfigPtr->PtP;
    S12PIM_REG8(DDRP)=ConfigPtr->DdrP;

    /* PortH */
    S12PIM_REG8(RDRH)=ConfigPtr->RdrH;
    S12PIM_REG8(PERH)=ConfigPtr->PerH;
    S12PIM_REG8(PPSH)=ConfigPtr->PpsH;
    S12PIM_REG8(PIEH)=ConfigPtr->PieH;
    S12PIM_REG8(PTH)=ConfigPtr->PtH;
    S12PIM_REG8(DDRH)=ConfigPtr->DdrH;

    /* PortJ */
    S12PIM_REG8(RDRJ)=ConfigPtr->RdrJ;
    S12PIM_REG8(PERJ)=ConfigPtr->PerJ;
    S12PIM_REG8(PPSJ)=ConfigPtr->PpsJ;
    S12PIM_REG8(PIEJ)=ConfigPtr->PieJ;
    S12PIM_REG8(PTJ)=ConfigPtr->PtJ;
    S12PIM_REG8(DDRJ)=ConfigPtr->DdrJ;
}

#if defined(__K_AUTOSAR)
void S12Pim_SetPinDirection(Kdk_PortType port,Kdk_ChannelType bit,Kdk_PinDirectionType Direction)
{
    InterruptStateType state;

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    if (Direction==PORT_PIN_OUT) {
	UTL_BIT_SET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_DDR),bit);
    } else {
	UTL_BIT_RESET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_DDR),bit);
    }
    CPU_RESTORE_INTERRUPTS(state);
}
#else
void S12Pim_SetPinDirection(Kdk_PinType Pin,Kdk_PinDirectionType Direction)
{
    uint8 port;
    uint8 bit;
    InterruptStateType state;

    port=Pin / (uint8)8;
    bit=Pin % (uint8)8;

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    if (Direction==PORT_PIN_OUT) {
	UTL_BIT_SET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_DDR),bit);
    } else {
	UTL_BIT_RESET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_DDR),bit);
    }
    CPU_RESTORE_INTERRUPTS(state);
}
#endif /* __K_AUTOSAR */


void S12Pim_WritePort(Kdk_PortType port,Kdk_PortLevelType value)
{
    S12PIM_ASSERT_VALID_PORT(port);

#if defined(S12PIM_PORT_WRITE_CHECKED)
#if !defined(S12PIM_PORT_WRITE_FAILED_CALLOUT)
#error 'S12PIM_PORT_WRITE_FAILED_CALLOUT' not defined.
#else
    Kdk_PortLevelType actualValue;
    InterruptStateType state;

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT)=value;
    actualValue=S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI);
    CPU_RESTORE_INTERRUPTS(state);

    if (value!=actualValue) {
        S12PIM_PORT_WRITE_FAILED_CALLOUT(port,value,actualValue);
    }
#endif /* S12PIM_PORT_WRITE_FAILED_CALLOUT */
#else
    S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT)=value;
#endif /* S12PIM_PORT_WRITE_CHECKED */
}


Kdk_PortLevelType S12Pim_ReadPort(Kdk_PortType port)
{
    S12PIM_ASSERT_VALID_PORT(port);

#if defined(S12PIM_READ_OUTPUT_LATCH)
    return S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT);   /* output latch   */
#else
    return S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI);   /* input register */
#endif /* S12PIM_READ_OUTPUT_LATCH */
}


#if defined(__K_AUTOSAR)
void S12Pim_WriteChannel(Kdk_PortType port,Kdk_ChannelType bit,Kdk_LevelType level)
{
    InterruptStateType state;
#if defined(S12PIM_CHANNEL_WRITE_CHECKED)
    Kdk_LevelType actualLevel;
#endif /* S12PIM_CHANNEL_WRITE_CHECKED */

    S12PIM_ASSERT_VALID_CHANNEL(channel);

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    if (level==KDK_HIGH) {
	UTL_BIT_SET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit);
    } else {
	UTL_BIT_RESET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit);
    }
#if !defined(S12PIM_CHANNEL_WRITE_FAILED_CALLOUT)
#error 'S12PIM_CHANNEL_WRITE_FAILED_CALLOUT' not defined.
#else
#if defined(S12PIM_CHANNEL_WRITE_CHECKED)
    actualLevel=(Kdk_LevelType)UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI),bit);
    if (level!=actualLevel) {
        S12PIM_CHANNEL_WRITE_FAILED_CALLOUT(port,bit,level,actualLevel);
    }
#endif /* S12PIM_CHANNEL_WRITE_CHECKED */
#endif /* S12PIM_CHANNEL_WRITE_FAILED_CALLOUT */
    CPU_RESTORE_INTERRUPTS(state);
}


Kdk_LevelType S12Pim_ReadChannel(Kdk_PortType port,Kdk_ChannelType bit)
{
    S12PIM_ASSERT_VALID_CHANNEL(channel);

#if defined(S12PIM_READ_OUTPUT_LATCH)
    /* output latch   */
    return (UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit)) ? KDK_HIGH : KDK_LOW;
#else
    /* input register */
    return (UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI),bit)) ? KDK_HIGH : KDK_LOW;
#endif /* S12PIM_READ_OUTPUT_LATCH */
}

#else
void S12Pim_WriteChannel(Kdk_ChannelType channel,Kdk_LevelType level)
{
    uint8 port;
    uint8 bit;
    InterruptStateType state;
#if defined(S12PIM_CHANNEL_WRITE_CHECKED)
    Kdk_LevelType actualLevel;
#endif /* S12PIM_CHANNEL_WRITE_CHECKED */

    S12PIM_ASSERT_VALID_CHANNEL(channel);

    port=channel / (uint8)8;
    bit=channel % (uint8)8;

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    if (level==KDK_HIGH) {
	UTL_BIT_SET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit);
    } else {
	UTL_BIT_RESET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit);
    }
#if defined(S12PIM_CHANNEL_WRITE_CHECKED)
    #if !defined(S12PIM_CHANNEL_WRITE_FAILED_CALLOUT)
        #error 'S12PIM_CHANNEL_WRITE_FAILED_CALLOUT' not defined.
    #endif /* S12PIM_CHANNEL_WRITE_FAILED_CALLOUT */
    actualLevel=(Kdk_LevelType)UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI),bit);
    if (level!=actualLevel) {
        S12PIM_CHANNEL_WRITE_FAILED_CALLOUT(channel,level,actualLevel);
    }
#endif /* S12PIM_CHANNEL_WRITE_CHECKED */
    CPU_RESTORE_INTERRUPTS(state);
}


Kdk_LevelType S12Pim_ReadChannel(Kdk_ChannelType channel)
{
    uint8 port;
    uint8 bit;

    S12PIM_ASSERT_VALID_CHANNEL(channel);

    port=channel / (uint8)8;
    bit=channel % (uint8)8;

#if defined(S12PIM_READ_OUTPUT_LATCH)
    /* output latch   */
    return (UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PT),bit)) ? KDK_HIGH : KDK_LOW;
#else
    /* input register */
    return (UTL_BIT_GET8(S12PIM_REG8(S12PIM_PORT_BASE(port)+S12PIM_PTI),bit)) ? KDK_HIGH : KDK_LOW;
#endif /* S12PIM_READ_OUTPUT_LATCH */
}

#endif /* __K_AUTOSAR */


void S12Pim_WriteChannelGroup(Kdk_ChannelGroupType const * group,Kdk_PortLevelType level)
{
    InterruptStateType state;
#if defined(S12PIM_CHANNEL_GROUP_WRITE_CHECKED)
    Kdk_PortLevelType actualLevel;
#endif /* S12PIM_CHANNEL_GROUP_WRITE_CHECKED */

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
    S12PIM_REG8(S12PIM_PORT_BASE(group->port)+S12PIM_PT)=
        (S12PIM_REG8(S12PIM_PORT_BASE(group->port)+S12PIM_PT) & ~group->mask) |
        (group->mask & (level << group->offset)   /* todo: Table!!! */
    );
#if defined(S12PIM_CHANNEL_GROUP_WRITE_CHECKED)
    actualLevel=(S12PIM_REG8(S12PIM_PORT_BASE(group->port)+S12PIM_PTI) & group->mask ) >> group->offset;
#endif /* S12PIM_CHANNEL_GROUP_WRITE_CHECKED */
    CPU_RESTORE_INTERRUPTS(state);
#if defined(S12PIM_CHANNEL_GROUP_WRITE_CHECKED)
    if (level!=actualLevel) {
        S12PIM_CHANNEL_GROUP_WRITE_FAILED_CALLOUT(group,level,actualLevel);
    }
#endif /* S12PIM_CHANNEL_GROUP_WRITE_CHECKED */
}


Kdk_PortLevelType S12Pim_ReadChannelGroup(Kdk_ChannelGroupType const * group)
{
    InterruptStateType state;
    uint8 level;

    CPU_SAVE_AND_DISABLE_INTERRUPTS(state);
#if defined(S12PIM_READ_OUTPUT_LATCH)
    level=(S12PIM_REG8(S12PIM_PORT_BASE(group->port)+S12PIM_PT) & group->mask ) >> group->offset;
#else
    level=(S12PIM_REG8(S12PIM_PORT_BASE(group->port)+S12PIM_PTI) & group->mask ) >> group->offset;
#endif /* S12PIM_READ_OUTPUT_LATCH */
    CPU_RESTORE_INTERRUPTS(state);

    return level;
}

#if defined(__K_AUTOSAR)
void S12Pim_RefreshPortDirection(S12Pim_ConfigType const * ConfigPtr)
{
    S12PIM_REG8(DDRT)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[0],ConfigPtr->DdrT,S12PIM_REG8(DDRT));
    S12PIM_REG8(DDRS)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[1],ConfigPtr->DdrS,S12PIM_REG8(DDRS));
    S12PIM_REG8(DDRM)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[2],ConfigPtr->DdrM,S12PIM_REG8(DDRM));
    S12PIM_REG8(DDRP)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[3],ConfigPtr->DdrP,S12PIM_REG8(DDRP));
    S12PIM_REG8(DDRH)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[4],ConfigPtr->DdrH,S12PIM_REG8(DDRH));
    S12PIM_REG8(DDRJ)=Kdk_CalculatePinDirection(ConfigPtr->DirectionChangeable[5],ConfigPtr->DdrJ,S12PIM_REG8(DDRJ));
}
#endif /* __K_AUTOSAR */

#if 0
void S12Pim_EnableInterrupt(void)
{

}

void S12Pim_DisableInterrupt(void)
{

}
#endif
