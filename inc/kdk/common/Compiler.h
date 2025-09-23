/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
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
#if !defined(__COMPILER_H)
#define __COMPILER_H

/*
**  Compiler and Platform Detection with Support for New Targets
*/

/*
**  Microsoft Visual C++ (MSVC) - Windows Platforms
*/
#if defined(_MSC_VER)
    #define _MICROSOFT_C_
    #define COMPILER_MSVC           1
    #define COMPILER_VERSION        _MSC_VER

    #if defined(_WIN64) || defined(_M_X64) || defined(_M_AMD64)
        #define _MSVC_WIN64_X64_
        #define TARGET_ARCH_X64     1
    #elif defined(_WIN32) || defined(_M_IX86)
        #define _MSVC_WIN32_X86_
        #define TARGET_ARCH_X86     1
    #elif defined(_M_ARM64)
        #define _MSVC_WIN_ARM64_
        #define TARGET_ARCH_ARM64   1
    #elif defined(_M_ARM)
        #define _MSVC_WIN_ARM_
        #define TARGET_ARCH_ARM     1
    #endif

    /* MSVC Version Detection */
    #if _MSC_VER >= 1930      /* Visual Studio 2022 */
        #define MSVC_2022       1
    #elif _MSC_VER >= 1920    /* Visual Studio 2019 */
        #define MSVC_2019       1
    #elif _MSC_VER >= 1910    /* Visual Studio 2017 */
        #define MSVC_2017       1
    #elif _MSC_VER >= 1900    /* Visual Studio 2015 */
        #define MSVC_2015       1
    #endif

/*
**  GNU GCC Compiler - Multiple Platforms
*/
#elif defined(__GNUC__)
    #define _GNU_C_
    #define COMPILER_GCC            1
    #define COMPILER_VERSION        (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

    /*
    **  Windows with MinGW/MSYS2
    */
    #if defined(__MINGW32__) || defined(__MINGW64__) || defined(_WIN32) || defined(_WIN64)
        #define _GNU_C_MINGW_

        #if defined(__MINGW64__) || defined(_WIN64)
            #define _GNU_C_MINGW64_
            #define TARGET_ARCH_X64     1
        #else
            #define _GNU_C_MINGW32_
            #define TARGET_ARCH_X86     1
        #endif

    /*
    **  Unix/Linux Platforms
    */
    #elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__) || defined(linux)
        #define _GNU_C_UNIX_

        #if defined(__linux__) || defined(linux)
            #define _GNU_C_LINUX_
        #endif

        #if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64)
            #define _GNU_C_UNIX_X64_
            #define TARGET_ARCH_X64     1
        #elif defined(__i386__) || defined(__i386) || defined(i386)
            #define _GNU_C_UNIX_X86_
            #define TARGET_ARCH_X86     1
        #elif defined(__aarch64__)
            #define _GNU_C_UNIX_ARM64_
            #define TARGET_ARCH_ARM64   1
        #elif defined(__arm__)
            #define _GNU_C_UNIX_ARM_
            #define TARGET_ARCH_ARM     1
        #endif

    /*
    **  ARM Embedded Platforms
    */
    #elif defined(__arm__) || defined(__ARM_ARCH)
        #define _GNU_C_ARM_
        #define TARGET_ARCH_ARM         1

        /* STM32 Family Detection */
        #if defined(STM32F1xx) || defined(STM32F4xx) || defined(STM32F7xx) || \
            defined(STM32H7xx) || defined(STM32L4xx) || defined(STM32G4xx) || \
            defined(STM32F0xx) || defined(STM32F3xx) || defined(STM32L0xx) || \
            defined(STM32L1xx) || defined(STM32WBxx) || defined(STM32MPxx)
            #define _GNU_C_ARM_STM32_
            #define TARGET_STM32        1

            #if defined(STM32F1xx)
                #define TARGET_STM32F1  1
            #elif defined(STM32F4xx)
                #define TARGET_STM32F4  1
            #elif defined(STM32F7xx)
                #define TARGET_STM32F7  1
            #elif defined(STM32H7xx)
                #define TARGET_STM32H7  1
            #elif defined(STM32L4xx)
                #define TARGET_STM32L4  1
            #elif defined(STM32G4xx)
                #define TARGET_STM32G4  1
            #endif
        #endif

    /*
    **  AVR Microcontrollers
    */
    #elif defined(__AVR__)
        #define _GNU_C_AVR_
        #define TARGET_AVR              1

    /*
    **  HC12/S12 Microcontrollers
    */
    #elif defined(MC6812) || defined(__HC12__)
        #define _GNU_C_CPU12_
        #define TARGET_CPU12            1

    /*
    **  MSP430 Microcontrollers
    */
    #elif defined(__MSP430__)
        #define _GNU_C_MSP430_
        #define TARGET_MSP430           1

    /*
    **  Coldfire Microcontrollers
    */
    #elif defined(__m68k__) && defined(__mcf5200__)
        #define _GNU_C_COLDFIRE_
        #define TARGET_COLDFIRE         1

    /*
    **  Cygwin Environment
    */
    #elif defined(__CYGWIN32__) || defined(__CYGWIN__)
        #define _GNU_C_CYGWIN_
        #define KAR_DUMMY_TARGET        1

    #else
        #error Unsupported Target for GCC-Compiler.
    #endif

/*
**  LLVM Clang Compiler
*/
#elif defined(__clang__)
    #define _CLANG_C_
    #define COMPILER_CLANG          1
    #define COMPILER_VERSION        (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

    #if defined(_WIN32) || defined(_WIN64)
        #define _CLANG_C_WINDOWS_

        #if defined(_WIN64)
            #define _CLANG_C_WIN64_
            #define TARGET_ARCH_X64     1
        #else
            #define _CLANG_C_WIN32_
            #define TARGET_ARCH_X86     1
        #endif

    #elif defined(__unix__) || defined(__linux__)
        #define _CLANG_C_UNIX_

        #if defined(__x86_64__)
            #define _CLANG_C_UNIX_X64_
            #define TARGET_ARCH_X64     1
        #elif defined(__i386__)
            #define _CLANG_C_UNIX_X86_
            #define TARGET_ARCH_X86     1
        #elif defined(__arm__)
            #define _CLANG_C_UNIX_ARM_
            #define TARGET_ARCH_ARM     1
        #endif

    #elif defined(__arm__)
        #define _CLANG_C_ARM_
        #define TARGET_ARCH_ARM         1

    #else
        #error Unsupported Target for Clang-Compiler.
    #endif

/*
**  Cosmic C Compiler (Embedded)
*/
#elif defined(__CSMC__)
    #define _COSMIC_C_

    #if (CPU_FAMILY == CPU12_S12) || (CPU_FAMILY == CPU12_HC12)
        #define _COSMIC_C_CPU12_
        #define TARGET_CPU12            1
    #else
        #error Unsupported Target for Cosmic Compiler.
    #endif

/*
**  Metrowerks/Freescale CodeWarrior
*/
#elif defined(__HIWARE__)
    #define _METROWERKS_C_

    #if defined(__HC12__)
        #define _METROWERKS_C_CPU12_
        #define TARGET_CPU12            1
    #else
        #error Unsupported Target for Metrowerks-Compiler.
    #endif

/*
**  IAR Systems Compiler
*/
#elif defined(__IAR_SYSTEMS_ICC__)
    #define _IAR_C_

    #if defined(__ICCARM__)
        #define _IAR_C_ARM_
        #define TARGET_ARCH_ARM         1
    #elif defined(__ICCHCS12__)
        #define _IAR_C_CPU12_
        #define TARGET_CPU12            1
    #elif defined(__ICC430__)
        #define _IAR_C_MSP430_
        #define TARGET_MSP430           1
    #else
        #error Unsupported Target for IAR Compiler.
    #endif

/*
**  Imagecraft Compiler
*/
#elif defined(__IMAGECRAFT__)
    #define _IMAGECRAFT_C_

    #if defined(_AVR)
        #define _IMAGECRAFT_C_AVR_
        #define TARGET_AVR              1
    #elif defined(_HC12)
        #define _IMAGECRAFT_C_CPU12_
        #define TARGET_CPU12            1
    #elif defined(_MSP430)
        #define _IMAGECRAFT_C_MSP430_
        #define TARGET_MSP430           1
    #else
        #error Unsupported Target for Imagecraft-Compiler.
    #endif

/*
**  MPLAB C18 Compiler (PIC18 Family)
*/
#elif defined(__18CXX)
    #define _MPLAB_C18_
    #define TARGET_PIC18            1

    #if defined(__SMALL__)
        #define _MPLAB_C18_SMALL_
    #elif defined(__LARGE__)
        #define _MPLAB_C18_LARGE_
    #elif defined(__TRADITIONAL18__)
        #define _MPLAB_C18_TRADITIONAL18_
    #elif defined(__EXTENDED18__)
        #define _MPLAB_C18_EXTENDED18_
    #endif

/*
**  CCS C Compiler (PIC Family)
*/
#elif defined(__PCH__) || defined(__PCB__) || defined(__PCM__)
    #define _CCSC_C_PIC_
    #define TARGET_PIC              1

/*
**  Intel C++ Compiler
*/
#elif defined(__INTEL_COMPILER) || defined(__ICC)
    #define _INTEL_C_
    #define COMPILER_ICC            1
    #define COMPILER_VERSION        __INTEL_COMPILER

    #if defined(_WIN32) || defined(_WIN64)
        #define _INTEL_C_WINDOWS_
    #elif defined(__linux__)
        #define _INTEL_C_LINUX_
    #endif

/*
**  Unknown Compiler
*/
#else
    #error Unsupported Compiler. Please add support for your compiler.
#endif

/*
**  Common Compiler Abstraction Macros
*/
#define AUTOMATIC
#define TYPEDEF
#define STATIC          static
#define NULL_PTR        ((void *)0)

/*
**  Function Macros
*/
#define FUNC(rettype, memclass)                 memclass rettype

/*
**  Pointer Macros
*/
#define P2VAR(ptrtype, memclass, ptrclass)          memclass ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass)        memclass ptrtype const *
#define CONSTP2VAR(ptrtype, memclass, ptrclass)     memclass ptrtype * const
#define CONSTP2CONST(ptrtype, memclass, ptrclass)   memclass ptrtype const * const
#define P2FUNC(rettype, ptrclass, fctname)          rettype(*fctname)

/*
**  Constant Macros
*/
#define CONST(type, memclass)                   memclass const type

/*
**  Variable Macros
*/
#define VAR(type, memclass)                     memclass type

/*
**  Compiler-Specific Attributes and Optimizations
*/
#if defined(COMPILER_MSVC)
    /* Microsoft Visual C++ */
    #define INLINE              __forceinline
    #define NO_INLINE           __declspec(noinline)
    #define ALIGNED(x)          __declspec(align(x))
    #define PACKED_BEGIN        __pragma(pack(push, 1))
    #define PACKED_END          __pragma(pack(pop))
    #define PACKED_STRUCT       /* Use PACKED_BEGIN/END */
    #define RESTRICT            __restrict
    #define LIKELY(x)           (x)
    #define UNLIKELY(x)         (x)

    #if defined(_WIN64)
        #define CALLING_CONV    __fastcall
    #else
        #define CALLING_CONV    __stdcall
    #endif

#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    /* GCC or Clang */
    #define INLINE              __attribute__((always_inline)) inline
    #define NO_INLINE           __attribute__((noinline))
    #define ALIGNED(x)          __attribute__((aligned(x)))
    #define PACKED_BEGIN        /* Not used with GCC */
    #define PACKED_END          /* Not used with GCC */
    #define PACKED_STRUCT       __attribute__((packed))
    #define RESTRICT            __restrict__
    #define LIKELY(x)           __builtin_expect(!!(x), 1)
    #define UNLIKELY(x)         __builtin_expect(!!(x), 0)
    #define CALLING_CONV        /* Default calling convention */

#else
    /* Default fallbacks */
    #define INLINE              inline
    #define NO_INLINE
    #define ALIGNED(x)
    #define PACKED_BEGIN
    #define PACKED_END
    #define PACKED_STRUCT
    #define RESTRICT
    #define LIKELY(x)           (x)
    #define UNLIKELY(x)         (x)
    #define CALLING_CONV
#endif

/*
**  Memory Management and Barriers
*/
#if defined(COMPILER_MSVC)
    #include <intrin.h>
    #define MEMORY_BARRIER()        MemoryBarrier()
    #define COMPILER_BARRIER()      _ReadWriteBarrier()
    #define PREFETCH_READ(addr)     _mm_prefetch((const char*)(addr), _MM_HINT_T0)
    #define PREFETCH_WRITE(addr)    _mm_prefetch((const char*)(addr), _MM_HINT_T0)

#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    #define MEMORY_BARRIER()        __sync_synchronize()
    #define COMPILER_BARRIER()      __asm__ __volatile__("" : : : "memory")
    #define PREFETCH_READ(addr)     __builtin_prefetch((addr), 0, 3)
    #define PREFETCH_WRITE(addr)    __builtin_prefetch((addr), 1, 3)

#else
    #define MEMORY_BARRIER()
    #define COMPILER_BARRIER()
    #define PREFETCH_READ(addr)
    #define PREFETCH_WRITE(addr)
#endif

/*
**  Branch Prediction and Loop Optimizations
*/
#if defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    #define HOT_FUNCTION        __attribute__((hot))
    #define COLD_FUNCTION       __attribute__((cold))
    #define PURE_FUNCTION       __attribute__((pure))
    #define CONST_FUNCTION      __attribute__((const))
#else
    #define HOT_FUNCTION
    #define COLD_FUNCTION
    #define PURE_FUNCTION
    #define CONST_FUNCTION
#endif

/*
**  Section Placement (for embedded targets)
*/
#if defined(TARGET_STM32) || defined(TARGET_CPU12) || defined(TARGET_MSP430) || defined(TARGET_AVR)
    #if defined(COMPILER_GCC)
        #define SECTION(name)       __attribute__((section(name)))
        #define RAM_SECTION         __attribute__((section(".data")))
        #define ROM_SECTION         __attribute__((section(".rodata")))
        #define ISR_SECTION         __attribute__((section(".text.isr")))
    #else
        #define SECTION(name)
        #define RAM_SECTION
        #define ROM_SECTION
        #define ISR_SECTION
    #endif
#else
    #define SECTION(name)
    #define RAM_SECTION
    #define ROM_SECTION
    #define ISR_SECTION
#endif

/*
**  Platform-Specific Interrupt Handling
*/
#if defined(TARGET_STM32)
    #define ISR(name)           void name(void)
    #define INTERRUPT           __attribute__((interrupt))
#elif defined(TARGET_AVR)
    #include <avr/interrupt.h>
    /* ISR macro already defined by AVR headers */
#elif defined(TARGET_MSP430)
    #include <msp430.h>
    #define ISR(name)           __attribute__((interrupt)) void name(void)
#elif defined(_GNU_C_CPU12_) || defined(_COSMIC_C_CPU12_) || defined(_METROWERKS_C_CPU12_)
    #define ISR(name)           interrupt void name(void)
#else
    #define ISR(name)           void name(void)
    #define INTERRUPT
#endif

/*
**  Include platform-specific headers
*/
#include "kdk/common/Std_Macros.h"
#include "kdk/common/Compiler_Cfg.h"

#endif /* __COMPILER_H */