/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2025 by Christoph Schueler <github.com/Christoph2,
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
 *  s. FLOSS-EXCEPTION.txt
 */
#if !defined(__CPU_PRIMITIVES_H)
#define __CPU_PRIMITIVES_H

/*
**  Compiler and Platform Detection for CPU Primitives
*/

#if defined(__CSMC__)               /* Cosmic Compiler */
    #define CP_TARGET       "kdk/compiler/cpu12/cosmic/CPU_Primitives.h"

#elif defined(__GNUC__)             /* GNU GCC Compiler */

    /*
    **  Windows with MinGW/MSYS2
    */
    #if defined(__MINGW32__) || defined(__MINGW64__) || (defined(_WIN32) && defined(__GNUC__))
        #if defined(_WIN64) || defined(__MINGW64__)
            #define CP_TARGET   "kdk/compiler/win32/gcc/CPU_Primitives_Win64.h"
        #else
            #define CP_TARGET   "kdk/compiler/win32/gcc/CPU_Primitives_Win32.h"
        #endif

    /*
    **  Unix/Linux Platforms
    */
    #elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__)
        #if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__)
            #define CP_TARGET   "kdk/compiler/unix/gcc/CPU_Primitives_Unix_x64.h"
        #elif defined(__i386__) || defined(__i386) || defined(i386)
            #define CP_TARGET   "kdk/compiler/unix/gcc/CPU_Primitives_Unix_x86.h"
        #elif defined(__aarch64__)
            #define CP_TARGET   "kdk/compiler/unix/gcc/CPU_Primitives_Unix_ARM64.h"
        #elif defined(__arm__)
            #define CP_TARGET   "kdk/compiler/unix/gcc/CPU_Primitives_Unix_ARM.h"
        #else
            #define CP_TARGET   "kdk/compiler/unix/gcc/CPU_Primitives_Unix_generic.h"
        #endif

    /*
    **  ARM Embedded Platforms
    */
    #elif defined(__arm__)
        /* STM32 Family */
        #if defined(STM32F1xx) || defined(STM32F4xx) || defined(STM32F7xx) || \
            defined(STM32H7xx) || defined(STM32L4xx) || defined(STM32G4xx) || \
            defined(STM32F0xx) || defined(STM32F3xx) || defined(STM32L0xx) || \
            defined(STM32L1xx) || defined(STM32WBxx) || defined(STM32MPxx)

            #if defined(STM32F0xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32F0.h"
            #elif defined(STM32F1xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32F1.h"
            #elif defined(STM32F3xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32F3.h"
            #elif defined(STM32F4xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32F4.h"
            #elif defined(STM32F7xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32F7.h"
            #elif defined(STM32H7xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32H7.h"
            #elif defined(STM32L0xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32L0.h"
            #elif defined(STM32L1xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32L1.h"
            #elif defined(STM32L4xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32L4.h"
            #elif defined(STM32G4xx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32G4.h"
            #elif defined(STM32WBxx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32WB.h"
            #elif defined(STM32MPxx)
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32MP.h"
            #else
                #define CP_TARGET   "kdk/compiler/stm32/gcc/CPU_Primitives_STM32_generic.h"
            #endif

        /* Generic ARM */
        #else
            #define CP_TARGET   "kdk/compiler/arm/gcc/CPU_Primitives_ARM_Generic.h"
        #endif

    /*
    **  AVR Microcontrollers
    */
    #elif defined(__AVR__)
        #if defined(__AVR_ATmega644__) || defined(__AVR_ATmega644P__)
            #define CP_TARGET   "kdk/compiler/ATMEGA644/gcc/CPU_Primitives.h"
        #elif defined(__AVR_ATmega328P__) || defined(__AVR_ATmega328__)
            #define CP_TARGET   "kdk/compiler/atmega328/gcc/CPU_Primitives.h"
        #elif defined(__AVR_ATmega2560__)
            #define CP_TARGET   "kdk/compiler/atmega2560/gcc/CPU_Primitives.h"
        #else
            #define CP_TARGET   "kdk/compiler/avr/gcc/CPU_Primitives_generic.h"
        #endif

    /*
    **  HC12/S12 Microcontrollers
    */
    #elif defined(MC6812) || defined(__HC12__)
        #define CP_TARGET   "kdk/compiler/cpu12/gcc/CPU_Primitives.h"

    /*
    **  MSP430 Microcontrollers
    */
    #elif defined(__MSP430__)
        #define CP_TARGET   "kdk/compiler/msp430/gcc/CPU_Primitives.h"

    /*
    **  Coldfire Microcontrollers
    */
    #elif defined(__m68k__) && defined(__mcf5200__)
        #define CP_TARGET   "kdk/compiler/coldfire/gcc/CPU_Primitives.h"

    /*
    **  Cygwin Environment
    */
    #elif defined(__CYGWIN32__) || defined(__CYGWIN__)
        #define CP_TARGET   "kdk/compiler/i386/gcc/CPU_Primitives.h"

    /*
    **  RISC-V Architecture
    */
    #elif defined(__riscv) || defined(__riscv__)
        #define CP_TARGET   "kdk/compiler/riscv/gcc/CPU_Primitives.h"

    #else
        #error Unsupported Target for GCC Compiler.
    #endif

/*
**  LLVM Clang Compiler
*/
#elif defined(__clang__)

    /*
    **  Windows with Clang
    */
    #if defined(_WIN32) || defined(_WIN64)
        #if defined(_WIN64)
            #define CP_TARGET   "kdk/compiler/win32/clang/CPU_Primitives_Win64.h"
        #else
            #define CP_TARGET   "kdk/compiler/win32/clang/CPU_Primitives_Win32.h"
        #endif

    /*
    **  Unix/Linux with Clang
    */
    #elif defined(__unix__) || defined(__linux__)
        #if defined(__x86_64__)
            #define CP_TARGET   "kdk/compiler/unix/clang/CPU_Primitives_Unix_x64.h"
        #elif defined(__i386__)
            #define CP_TARGET   "kdk/compiler/unix/clang/CPU_Primitives_Unix_x86.h"
        #elif defined(__aarch64__)
            #define CP_TARGET   "kdk/compiler/unix/clang/CPU_Primitives_Unix_ARM64.h"
        #elif defined(__arm__)
            #define CP_TARGET   "kdk/compiler/unix/clang/CPU_Primitives_Unix_ARM.h"
        #endif

    /*
    **  ARM Embedded with Clang
    */
    #elif defined(__arm__)
        #define CP_TARGET   "kdk/compiler/arm/clang/CPU_Primitives.h"

    #else
        #error Unsupported Target for Clang Compiler.
    #endif

/*
**  Microsoft Visual C++
*/
#elif defined(_MSC_VER)

    #if defined(_WIN64)
        #if defined(_M_X64) || defined(_M_AMD64)
            #define CP_TARGET   "kdk/compiler/win32/msvc/CPU_Primitives_Win64_x64.h"
        #elif defined(_M_ARM64)
            #define CP_TARGET   "kdk/compiler/win32/msvc/CPU_Primitives_Win64_ARM64.h"
        #endif
    #else
        #if defined(_M_IX86)
            #define CP_TARGET   "kdk/compiler/win32/msvc/CPU_Primitives_Win32_x86.h"
        #elif defined(_M_ARM)
            #define CP_TARGET   "kdk/compiler/win32/msvc/CPU_Primitives_Win32_ARM.h"
        #else
            #define CP_TARGET   "kdk/compiler/i386/msvc/CPU_Primitives.h"  /* Fallback */
        #endif
    #endif

/*
**  Intel C++ Compiler
*/
#elif defined(__INTEL_COMPILER) || defined(__ICC)

    #if defined(_WIN32) || defined(_WIN64)
        #define CP_TARGET   "kdk/compiler/win32/icc/CPU_Primitives.h"
    #elif defined(__linux__)
        #define CP_TARGET   "kdk/compiler/unix/icc/CPU_Primitives.h"
    #else
        #error Unsupported Platform for Intel C++ Compiler.
    #endif

/*
**  Metrowerks/Freescale CodeWarrior
*/
#elif defined(__HIWARE__)

    #if defined(__HC12__)
        #define CP_TARGET   "kdk/compiler/cpu12/codewarrior/CPU_Primitives.h"
    #else
        #error Unsupported Target for Metrowerks Compiler.
    #endif

/*
**  IAR Systems Compiler
*/
#elif defined(__IAR_SYSTEMS_ICC__)

    #if defined(__ICCARM__)
        #define CP_TARGET   "kdk/compiler/arm/iar/CPU_Primitives.h"
    #elif defined(__ICCHCS12__)
        #define CP_TARGET   "kdk/compiler/cpu12/iar/CPU_Primitives.h"
    #elif defined(__ICC430__)
        #define CP_TARGET   "kdk/compiler/msp430/iar/CPU_Primitives.h"
    #elif defined(__ICCAVR__)
        #define CP_TARGET   "kdk/compiler/avr/iar/CPU_Primitives.h"
    #elif defined(__ICCRISCV__)
        #define CP_TARGET   "kdk/compiler/riscv/iar/CPU_Primitives.h"
    #else
        #error Unsupported Target for IAR Compiler.
    #endif

/*
**  Imagecraft Compiler
*/
#elif defined(__IMAGECRAFT__)

    #if defined(_AVR)
        #define CP_TARGET   "kdk/compiler/avr/imagecraft/CPU_Primitives.h"
    #elif defined(_HC12)
        #define CP_TARGET   "kdk/compiler/cpu12/imagecraft/CPU_Primitives.h"
    #elif defined(_MSP430)
        #define CP_TARGET   "kdk/compiler/msp430/imagecraft/CPU_Primitives.h"
    #else
        #error Unsupported Target for Imagecraft Compiler.
    #endif

/*
**  MPLAB C18 Compiler (PIC18 Family)
*/
#elif defined(__18CXX)
    #define CP_TARGET   "kdk/compiler/pic/mpl_c18/CPU_Primitives.h"

/*
**  CCS C Compiler (PIC Family)
*/
#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)
    #define CP_TARGET   "kdk/compiler/pic/ccsc/CPU_Primitives.h"

/*
**  Keil C Compiler (ARM/8051)
*/
#elif defined(__CC_ARM) || defined(__ARMCC_VERSION)

    #if defined(__CC_ARM)
        #define CP_TARGET   "kdk/compiler/arm/keil/CPU_Primitives.h"
    #else
        #error Unsupported Target for Keil Compiler.
    #endif

/*
**  Texas Instruments Compiler
*/
#elif defined(__TI_COMPILER_VERSION__)

    #if defined(__MSP430__)
        #define CP_TARGET   "kdk/compiler/msp430/ti/CPU_Primitives.h"
    #elif defined(__TMS320C28XX__)
        #define CP_TARGET   "kdk/compiler/c28x/ti/CPU_Primitives.h"
    #elif defined(__C6X__)
        #define CP_TARGET   "kdk/compiler/c6x/ti/CPU_Primitives.h"
    #elif defined(__ARM_ARCH)
        #define CP_TARGET   "kdk/compiler/arm/ti/CPU_Primitives.h"
    #else
        #error Unsupported Target for TI Compiler.
    #endif

/*
**  Green Hills Compiler
*/
#elif defined(__ghs__)
    #define CP_TARGET   "kdk/compiler/ghs/CPU_Primitives.h"

/*
**  Renesas Compiler
*/
#elif defined(__RX__) || defined(__SH__) || defined(__H8__)

    #if defined(__RX__)
        #define CP_TARGET   "kdk/compiler/rx/renesas/CPU_Primitives.h"
    #elif defined(__SH__)
        #define CP_TARGET   "kdk/compiler/sh/renesas/CPU_Primitives.h"
    #elif defined(__H8__)
        #define CP_TARGET   "kdk/compiler/h8/renesas/CPU_Primitives.h"
    #endif

/*
**  Unknown Compiler
*/
#else
    #error Unsupported Compiler. Please add support for your compiler in CPU_Primitives.h.
#endif

/*
**  Default InterruptStateType - Platform Specific
*/
#if defined(_WIN32) || defined(_WIN64)
    /* Windows platforms */
    #if defined(_WIN64)
        //typedef uint64 InterruptStateType;
    #else
        typedef uint32 InterruptStateType;
    #endif

#elif defined(__unix__) || defined(__linux__)
    /* Unix/Linux platforms */
    typedef uint8 InterruptStateType;

#elif defined(STM32F1xx) || defined(STM32F4xx) || defined(STM32F7xx) || \
      defined(STM32H7xx) || defined(STM32L4xx) || defined(STM32G4xx) || \
      defined(STM32F0xx) || defined(STM32F3xx) || defined(STM32L0xx) || \
      defined(STM32L1xx) || defined(STM32WBxx) || defined(STM32MPxx) || defined(STM32L4R5xx)
    /* STM32 platforms */
    typedef uint32 InterruptStateType;

#elif defined(__AVR__)
    /* AVR platforms */
    typedef uint8 InterruptStateType;

#elif defined(__MSP430__)
    /* MSP430 platforms */
    typedef uint16 InterruptStateType;

#elif defined(MC6812) || defined(__HC12__)
    /* HC12/S12 platforms */
    typedef uint8 InterruptStateType;

#else
    /* Generic fallback */
    typedef uint8 InterruptStateType;
#endif

/*
**  Include the target-specific CPU primitives
*/
#include CP_TARGET
#undef CP_TARGET

/*
**  Common CPU Primitive Validation and Fallbacks
*/
#ifndef CPU_ENTER_POWERDOWN_MODE
    #define CPU_ENTER_POWERDOWN_MODE()          /* Platform doesn't support powerdown */
#endif

#ifndef CPU_LEAVE_POWERDOWN_MODE
    #define CPU_LEAVE_POWERDOWN_MODE()          /* Platform doesn't support powerdown */
#endif

#ifndef CPU_DISABLE_WATCHDOG_TIMER
    #define CPU_DISABLE_WATCHDOG_TIMER()        /* Platform doesn't have watchdog */
#endif

#ifndef CPU_SOFTWARE_INTERRUPT
    #define CPU_SOFTWARE_INTERRUPT()            /* Platform doesn't support SW interrupt */
#endif

#ifndef CPU_RETURN_FROM_INTERRUPT
    #define CPU_RETURN_FROM_INTERRUPT()         /* Platform-specific implementation required */
#endif

#ifndef CPU_BREAKPOINT
    #if defined(_DEBUG) || defined(DEBUG)
        #if defined(_MSC_VER)
            #define CPU_BREAKPOINT()            __debugbreak()
        #elif defined(__GNUC__) || defined(__clang__)
            #define CPU_BREAKPOINT()            __builtin_trap()
        #else
            #define CPU_BREAKPOINT()            /* No breakpoint support */
        #endif
    #else
        #define CPU_BREAKPOINT()                /* No breakpoint in release */
    #endif
#endif

#ifndef CPU_NO_OPERATION
    #if defined(_MSC_VER)
        #define CPU_NO_OPERATION()              __nop()
    #elif defined(__GNUC__) || defined(__clang__)
        #define CPU_NO_OPERATION()              __asm__ __volatile__("nop")
    #else
        #define CPU_NO_OPERATION()              /* No NOP instruction */
    #endif
#endif

/*
**  Validation of mandatory interrupt macros
*/
#ifndef CPU_DISABLE_ALL_INTERRUPTS
    #error CPU_DISABLE_ALL_INTERRUPTS not defined for this platform
#endif

#ifndef CPU_ENABLE_ALL_INTERRUPTS
    #error CPU_ENABLE_ALL_INTERRUPTS not defined for this platform
#endif

#ifndef CPU_INTERRUPTS_DISABLED
    #error CPU_INTERRUPTS_DISABLED not defined for this platform
#endif

#ifndef CPU_SAVE_AND_DISABLE_INTERRUPTS
    #error CPU_SAVE_AND_DISABLE_INTERRUPTS not defined for this platform
#endif

#ifndef CPU_RESTORE_INTERRUPTS
    #error CPU_RESTORE_INTERRUPTS not defined for this platform
#endif

/*
**  Performance and debugging macros (optional)
*/
#ifndef CPU_MEMORY_BARRIER
    #if defined(_MSC_VER)
        #define CPU_MEMORY_BARRIER()            MemoryBarrier()
    #elif defined(__GNUC__) || defined(__clang__)
        #define CPU_MEMORY_BARRIER()            __sync_synchronize()
    #else
        #define CPU_MEMORY_BARRIER()            /* No memory barrier */
    #endif
#endif

#ifndef CPU_COMPILER_BARRIER
    #if defined(_MSC_VER)
        #define CPU_COMPILER_BARRIER()          _ReadWriteBarrier()
    #elif defined(__GNUC__) || defined(__clang__)
        #define CPU_COMPILER_BARRIER()          __asm__ __volatile__("" : : : "memory")
    #else
        #define CPU_COMPILER_BARRIER()          /* No compiler barrier */
    #endif
#endif

#endif /* __CPU_PRIMITIVES_H */