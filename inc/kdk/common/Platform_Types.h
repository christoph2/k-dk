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
#if !defined(__PLATFORM_TYPES_H)
#define __PLATFORM_TYPES_H

/*
**  CPU Type Definitions
*/
#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32
#define CPU_TYPE_64     64

/*
**  Byte Order Definitions
*/
#define MSB_FIRST       0
#define LSB_FIRST       1

#define HIGH_BYTE_FIRST 0
#define LOW_BYTE_FIRST  1

/*
**  Compiler and Platform Detection
*/

/* Windows Platform Detection */
#if defined(_WIN32) || defined(_WIN64) || defined(__WIN32__) || defined(__WINDOWS__)
    #define PLATFORM_WINDOWS    1

    #if defined(_WIN64) || defined(__WIN64__)
        #define PLATFORM_WINDOWS_64     1
        #define PLATFORM_ARCH_BITS      64
    #else
        #define PLATFORM_WINDOWS_32     1
        #define PLATFORM_ARCH_BITS      32
    #endif

    /* Windows Compiler Detection */
    #if defined(_MSC_VER)
        #define COMPILER_MSVC       1
        #define COMPILER_VERSION    _MSC_VER

        #if _MSC_VER >= 1930      /* Visual Studio 2022 */
            #define COMPILER_MSVC_2022  1
        #elif _MSC_VER >= 1920    /* Visual Studio 2019 */
            #define COMPILER_MSVC_2019  1
        #elif _MSC_VER >= 1910    /* Visual Studio 2017 */
            #define COMPILER_MSVC_2017  1
        #elif _MSC_VER >= 1900    /* Visual Studio 2015 */
            #define COMPILER_MSVC_2015  1
        #endif

    #elif defined(__GNUC__) && (defined(__MINGW32__) || defined(__MINGW64__))
        #define COMPILER_MINGW      1
        #define COMPILER_GCC        1
        #define COMPILER_VERSION    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

        #if defined(__MINGW64__)
            #define COMPILER_MINGW64    1
        #else
            #define COMPILER_MINGW32    1
        #endif

    #elif defined(__clang__)
        #define COMPILER_CLANG      1
        #define COMPILER_VERSION    (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
    #endif

/* Unix/Linux Platform Detection */
#elif defined(__unix__) || defined(__unix) || defined(unix) || defined(__linux__) || defined(linux)
    #define PLATFORM_UNIX       1

    #if defined(__linux__) || defined(linux)
        #define PLATFORM_LINUX  1
    #endif

    #if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64)
        #define PLATFORM_ARCH_BITS      64
        #define PLATFORM_UNIX_64        1
    #else
        #define PLATFORM_ARCH_BITS      32
        #define PLATFORM_UNIX_32        1
    #endif

    #if defined(__GNUC__)
        #define COMPILER_GCC        1
        #define COMPILER_VERSION    (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)
    #elif defined(__clang__)
        #define COMPILER_CLANG      1
        #define COMPILER_VERSION    (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)
    #endif

/* Embedded Platform Detection */
#else
    #define PLATFORM_EMBEDDED   1

    /* ARM Architecture */
    #if defined(__arm__) || defined(__ARM_ARCH)
        #define PLATFORM_ARM        1

        #if defined(STM32F1xx) || defined(STM32F4xx) || defined(STM32F7xx) || \
            defined(STM32H7xx) || defined(STM32L4xx) || defined(STM32G4xx) || defined(STM32L4R5xx)
            #define PLATFORM_STM32      1
        #endif
    #endif
#endif

/*
**  Platform-specific Type Includes
*/
#if defined(PLATFORM_WINDOWS) && defined(COMPILER_MSVC)
    /* Windows with MSVC */
    #include "kdk/mcu/win32/Platform_Types_Win32_MSVC.h"

#elif defined(PLATFORM_WINDOWS) && defined(COMPILER_MINGW)
    /* Windows with MinGW */
    #include "kdk/mcu/win32/Platform_Types_Win32_GCC.h"

#elif defined(PLATFORM_UNIX) && defined(COMPILER_GCC)
    /* Unix/Linux with GCC */
    #include "kdk/mcu/unix/Platform_Types_Unix_GCC.h"

#elif defined(PLATFORM_STM32)
    /* STM32 platforms */
    #include "kdk/mcu/stm32/Platform_Types_STM32.h"

#elif defined(COMPILER_MSVC)
    /* Fallback for any MSVC platform */
    #include "kdk/mcu/i386/Platform_Types_i386.h"

#else
    /* Original embedded platform selection */

    #if CPU_FAMILY == CPU12_HC12
        #include "kdk/mcu/hc12/Platform_Types_HC12.h"

    #elif CPU_FAMILY == CPU12_S12
        #include "kdk/mcu/s12/Platform_Types_S12.h"

    #elif CPU_FAMILY == PIC_F18
        #include "kdk/mcu/pic/Platform_Types_PIC.h"

    #elif CPU_FAMILY == __430X_CORE__
        #include "kdk/mcu/msp430/Platform_Types_MSP430.h"

    #elif CPU_FAMILY == COLDFIRE
        #include "kdk/mcu/mcf5225/Platform_Types_mcf5225.h"

    #else
        #error Unknown CPU family. Please define appropriate CPU_FAMILY or platform macros.
    #endif

#endif

/*
**  Common Definitions (available on all platforms)
*/
#if !defined(NULL)
    #define NULL    ((void *) 0)
#endif

#if !defined(TRUE)
    #define TRUE    (1u)
#endif

#if !defined(FALSE)
    #define FALSE   (0u)
#endif

/*
**  Platform-specific optimizations and features
*/
#if defined(COMPILER_MSVC)
    /* MSVC specific optimizations */
    #define FORCE_INLINE    __forceinline
    #define NO_INLINE       __declspec(noinline)
    #define ALIGNED(x)      __declspec(align(x))
    #define PACKED          /* Use #pragma pack for MSVC */

    #if defined(PLATFORM_WINDOWS_64)
        #define CALLING_CONV    __fastcall
    #else
        #define CALLING_CONV    __stdcall
    #endif

#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    /* GCC/Clang specific optimizations */
    #define FORCE_INLINE    __attribute__((always_inline)) inline
    #define NO_INLINE       __attribute__((noinline))
    #define ALIGNED(x)      __attribute__((aligned(x)))
    #define PACKED          __attribute__((packed))
    #define CALLING_CONV    /* Default calling convention */

#else
    /* Fallback for other compilers */
    #define FORCE_INLINE    inline
    #define NO_INLINE
    #define ALIGNED(x)
    #define PACKED
    #define CALLING_CONV
#endif

/*
**  Memory barriers and synchronization
*/
#if defined(COMPILER_MSVC)
    #define MEMORY_BARRIER()    MemoryBarrier()
    #define COMPILER_BARRIER()  _ReadWriteBarrier()
#elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    #define MEMORY_BARRIER()    __sync_synchronize()
    #define COMPILER_BARRIER()  __asm__ __volatile__("" : : : "memory")
#else
    #define MEMORY_BARRIER()
    #define COMPILER_BARRIER()
#endif

/*
**  Branch prediction hints (for performance optimization)
*/
#if defined(COMPILER_GCC) || defined(COMPILER_CLANG)
    #define LIKELY(x)       __builtin_expect(!!(x), 1)
    #define UNLIKELY(x)     __builtin_expect(!!(x), 0)
#else
    #define LIKELY(x)       (x)
    #define UNLIKELY(x)     (x)
#endif

/*
**  Debug assertions and error handling
*/
#ifdef _DEBUG
    #if defined(COMPILER_MSVC)
        #define DEBUG_BREAK()   __debugbreak()
    #elif defined(COMPILER_GCC) || defined(COMPILER_CLANG)
        #if defined(PLATFORM_UNIX)
            #include <signal.h>
            #define DEBUG_BREAK()   raise(SIGTRAP)
        #else
            #define DEBUG_BREAK()   __builtin_trap()
        #endif
    #else
        #define DEBUG_BREAK()
    #endif
#else
    #define DEBUG_BREAK()
#endif

/*
**  Static analysis hints
*/
#if !defined(STATIC_ASSERT)
#if defined(COMPILER_MSVC) && (_MSC_VER >= 1700) /* VS2012+ */
    #define STATIC_ASSERT(cond, msg)    static_assert(cond, msg)
#elif defined(COMPILER_GCC) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 6))
    #define STATIC_ASSERT(cond, msg)    _Static_assert(cond, msg)
#else
    #define STATIC_ASSERT(cond, msg)    typedef char static_assertion_##__LINE__[(cond) ? 1 : -1]
#endif
#endif /* STATIC_ASSERT */

/*
**  Platform capability detection
*/
#if defined(PLATFORM_ARCH_BITS)
    #if PLATFORM_ARCH_BITS == 64
        #define PLATFORM_64BIT      1
        #define PLATFORM_POINTER_SIZE   8
    #else
        #define PLATFORM_32BIT      1
        #define PLATFORM_POINTER_SIZE   4
    #endif
#endif

#endif /* __PLATFORM_TYPES_H  */