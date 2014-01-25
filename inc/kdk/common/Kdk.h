/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
 *                                     cpu12.gems@googlemail.com>
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
 *  s. FLOSS-EXCEPTION.txt
 */

#if !defined(__K_DK_H)
#define __K_DK_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

#include "kdk/common/Std_Types.h"
#include "Sys_Cfg.h"

/*
**  Function-like Macros.
*/
#define KDK_MAKE_BASE_ADDR(addr)    (BASE_ADDR_REGISTERS + (uint16)(addr))
#define IMPL_PORT_MAP(nameLower)    GLUE2( nameLower , _Ports[port])
#define IMPL_REGISTER(nameUpper)    GLUE2( nameUpper , _REG8)

#if !defined(KDK_TOS)
#define KDK_TOS(mem, size) ((uint8 *)(mem) + ((size) - (uint8)1))
#endif /* KDK_TOS */

	
/*
**  Templates.
*/
#define IMPLEMENT_IO_READ_PORT(nameUpper, nameLower)                  \
    Kdk_PortLevelType GLUE2(nameLower, _ReadPort(Kdk_PortType port))  \
    {                                                                 \
        GLUE2(nameUpper, _ASSERT_VALID_PORT(port); )                  \
                                                                      \
        return IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ); \
    }

#define IMPLEMENT_IO_WRITE_PORT(nameUpper, nameLower)                             \
    void GLUE2(nameLower, _WritePort(Kdk_PortType port, Kdk_PortLevelType value)) \
    {                                                                             \
        GLUE2(nameUpper, _ASSERT_VALID_PORT(port); )                              \
                                                                                  \
        IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ) = value;            \
    }

#if defined(__K_AUTOSAR)
#define IMPLEMENT_IO_WRITE_CHANNEL(nameUpper, nameLower)                                              \
    void GLUE2(nameLower, _WriteChannel(Kdk_PortType port, Kdk_ChannelType bit, Kdk_LevelType level)) \
    {                                                                                                 \
        InterruptStateType state;                                                                     \
                                                                                                      \
        GLUE2(nameUpper, _ASSERT_VALID_CHANNEL(channel); )                                            \
                                                                                                      \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                                       \
        if (level == KDK_HIGH) {                                                                      \
            UTL_BIT_SET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);                \
        } else {                                                                                      \
            UTL_BIT_RESET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);              \
        }                                                                                             \
        CPU_RESTORE_INTERRUPTS(state);                                                                \
    }
#else
#define IMPLEMENT_IO_WRITE_CHANNEL(nameUpper, nameLower)                                 \
    void GLUE2(nameLower, _WriteChannel(Kdk_ChannelType channel, Kdk_LevelType level))   \
    {                                                                                    \
        uint8               port;                                                        \
        uint8               bit;                                                         \
        InterruptStateType  state;                                                       \
                                                                                         \
        GLUE2(nameUpper, _ASSERT_VALID_CHANNEL(channel); )                               \
                                                                                         \
        port   = channel / (uint8)8;                                                     \
        bit    = channel % (uint8)8;                                                     \
                                                                                         \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                          \
        if (level == KDK_HIGH) {                                                         \
            UTL_BIT_SET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);   \
        } else {                                                                         \
            UTL_BIT_RESET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit); \
        }                                                                                \
        CPU_RESTORE_INTERRUPTS(state);                                                   \
    }
#endif /* __K_AUTOSAR */

#if defined(__K_AUTOSAR)
#define IMPLEMENT_IO_READ_CHANNEL(nameUpper, nameLower)                                                          \
    Kdk_LevelType GLUE2(nameLower, _ReadChannel(Kdk_PortType port, Kdk_ChannelType bit))                         \
    {                                                                                                            \
        GLUE2(nameUpper, _ASSERT_VALID_CHANNEL(channel); )                                                       \
                                                                                                                 \
        return (UTL_BIT_GET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit)) ? KDK_HIGH : KDK_LOW; \
    }
#else
#define IMPLEMENT_IO_READ_CHANNEL(nameUpper, nameLower)                                                           \
    Kdk_LevelType GLUE2(nameLower, _ReadChannel(Kdk_ChannelType channel))                                         \
    {                                                                                                             \
        uint8   port;                                                                                             \
        uint8   bit;                                                                                              \
                                                                                                                  \
        GLUE2(nameUpper, _ASSERT_VALID_CHANNEL(channel); )                                                        \
                                                                                                                  \
        port   = channel / (uint8)8;                                                                              \
        bit    = channel % (uint8)8;                                                                              \
                                                                                                                  \
        return (UTL_BIT_GET8(  IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit)) ? KDK_HIGH : KDK_LOW; \
    }
#endif

#define IMPLEMENT_IO_WRITE_CHANNEL_GROUP(nameUpper, nameLower)                                             \
    void GLUE2(nameLower, _WriteChannelGroup(Kdk_ChannelGroupType const * group, Kdk_PortLevelType level)) \
    {                                                                                                      \
        InterruptStateType state;                                                                          \
                                                                                                           \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                                            \
        nameUpper ## _REG8( ## nameLower ## _Ports[group->port]) =                                         \
            ( ## nameUpper ## _REG8( ## nameLower ## _Ports[group->port]) & ~group->mask) |                \
            (group->mask & (level << group->offset) /* TODO: Table!!! */                                   \
            );                                                                                             \
        CPU_RESTORE_INTERRUPTS(state);                                                                     \
    }

#define IMPLEMENT_IO_READ_CHANNEL_GROUP(nameUpper, nameLower)                                                   \
    Kdk_PortLevelType GLUE2(nameLower, _ReadChannelGroup(Kdk_ChannelGroupType const * group))                   \
    {                                                                                                           \
        InterruptStateType  state;                                                                              \
        uint8               level;                                                                              \
                                                                                                                \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                                                 \
        level = ( ## nameUpper ## _REG8( ## nameLower ## _Ports[group->port]) & group->mask ) >> group->offset; \
        CPU_RESTORE_INTERRUPTS(state);                                                                          \
                                                                                                                \
        return level;                                                                                           \
    }

/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */
#if defined(__K_AUTOSAR)
#define IMPLEMENT_IO_SET_PIN_DIRECTION(nameUpper, nameLower)                                                        \
    void GLUE2(nameLower, _SetPinDirection(Kdk_PortType port, Kdk_ChannelType bit, Kdk_PinDirectionType Direction)) \
    {                                                                                                               \
        InterruptStateType state;                                                                                   \
                                                                                                                    \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                                                     \
        if (Direction == PORT_PIN_OUT) {                                                                            \
            UTL_BIT_SET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);                              \
        } else {                                                                                                    \
            UTL_BIT_RESET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);                            \
        }                                                                                                           \
        CPU_RESTORE_INTERRUPTS(state);                                                                              \
    }
#else

#define IMPLEMENT_IO_SET_PIN_DIRECTION(nameUpper, nameLower)                                 \
    void GLUE2(nameLower, _SetPinDirection(Kdk_PinType Pin, Kdk_PinDirectionType Direction)) \
    {                                                                                        \
        uint8               port;                                                            \
        uint8               bit;                                                             \
        InterruptStateType  state;                                                           \
                                                                                             \
        port   = Pin / (uint8)8;                                                             \
        bit    = Pin % (uint8)8;                                                             \
                                                                                             \
        CPU_SAVE_AND_DISABLE_INTERRUPTS(state);                                              \
        if (Direction == PORT_PIN_OUT) {                                                     \
            UTL_BIT_SET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);       \
        } else {                                                                             \
            UTL_BIT_RESET8( IMPL_REGISTER(nameUpper) ( IMPL_PORT_MAP(nameLower) ), bit);     \
        }                                                                                    \
        CPU_RESTORE_INTERRUPTS(state);                                                       \
    }
#endif /* __K_AUTOSAR */
/* /////////////////////////////////////////////////////////////////////////////////////////////////////// */

#define KDK_BASE_ADDRESS(mod)           GLUE2(BASE_ADDR_ , mod)
#define KDK_BASE_ADDRESS_MULT(mod, num) GLUE3(BASE_ADDR_ , mod, num)

/*
**  Global Types.
*/
typedef uint8   Kdk_ChannelType;
typedef uint8   Kdk_PinType;
typedef uint8   Kdk_PortType;

typedef struct tagKdk_ChannelGroupType {
    uint8           offset;
    Kdk_PortType    port;
    uint8           mask;
} Kdk_ChannelGroupType;

typedef enum tagKdk_LevelType {
    KDK_LOW,
    KDK_HIGH
} Kdk_LevelType;

typedef enum tagKdk_PinDirectionType {
    PORT_PIN_IN,
    PORT_PIN_OUT
} Kdk_PinDirectionType;

typedef uint8 Kdk_PortLevelType;

typedef void (*Kdk_WritePort_Func)(Kdk_PortType port, Kdk_PortLevelType value);
typedef Kdk_PortLevelType (*Kdk_ReadPort_Func)(Kdk_PortType port);

typedef void (*Kdk_WriteChannel_Func)(Kdk_PortType port, Kdk_ChannelType bit, Kdk_LevelType level);
typedef Kdk_LevelType (*Kdk_ReadChannel_Func)(Kdk_PortType port, Kdk_ChannelType bit);

typedef void (*Kdk_WriteChannelGroup_Func)(Kdk_ChannelGroupType const * group, Kdk_PortLevelType level);
typedef Kdk_PortLevelType (*Kdk_ReadChannelGroup_Func)(Kdk_ChannelGroupType const * group);

typedef void (*Kdk_SetPinDirection_Func)(Kdk_PortType port, Kdk_ChannelType bit, Kdk_PinDirectionType Direction);

/*
**  Global Functions.
*/
#if defined(__K_AUTOSAR)
/* Helper Function for 'Port_RefreshPortDirection'. */
uint8 Kdk_CalculatePinDirection(uint8 changeable, uint8 initialValue, uint8 ActualValue);


#endif /* __K_AUTOSAR */

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __K_DK_H */
