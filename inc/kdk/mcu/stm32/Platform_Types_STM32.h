/*
 * k_dk - Unix/Linux Platform Types for GCC Compiler
 */
#if !defined(__PLATFORM_TYPES_STM32_GCC_H)
#define __PLATFORM_TYPES_STM32_GCC_H

#include <stdint.h>
#include <stddef.h>

/* Symbols */
#if defined(__x86_64__) || defined(__x86_64) || defined(__amd64__) || defined(__amd64)
    #define CPU_TYPE        CPU_TYPE_64
#else
    #define CPU_TYPE        CPU_TYPE_32
#endif

#define CPU_BIT_ORDER   LSB_FIRST
#define CPU_BYTE_ORDER  LOW_BYTE_FIRST

/* Boolean type */
typedef unsigned char boolean;

/* Standard integer types */
typedef int8_t                  sint8;
typedef uint8_t                 uint8;
typedef int16_t                 sint16;
typedef uint16_t                uint16;
typedef int32_t                 sint32;
typedef uint32_t                uint32;
typedef int64_t                 sint64;
typedef uint64_t                uint64;

/* Least-width integer types */
typedef int_least8_t            sint8_least;
typedef uint_least8_t           uint8_least;
typedef int_least16_t           sint16_least;
typedef uint_least16_t          uint16_least;
typedef int_least32_t           sint32_least;
typedef uint_least32_t          uint32_least;
typedef int_least64_t           sint64_least;
typedef uint_least64_t          uint64_least;

/* Fast-width integer types */
typedef int_fast8_t             sint8_fast;
typedef uint_fast8_t            uint8_fast;
typedef int_fast16_t            sint16_fast;
typedef uint_fast16_t           uint16_fast;
typedef int_fast32_t            sint32_fast;
typedef uint_fast32_t           uint32_fast;
typedef int_fast64_t            sint64_fast;
typedef uint_fast64_t           uint64_fast;

/* Maximum-width integer types */
typedef intmax_t                sintmax;
typedef uintmax_t               uintmax;

/* Pointer-width integer types */
typedef intptr_t                sintptr;
typedef uintptr_t               uintptr;

/* Floating-point types */
typedef float                   float32;
typedef double                  float64;
typedef long double             float128;

/* Other common types */
typedef void *                  pvoid;
typedef size_t                  SizeType;
typedef ptrdiff_t               PtrDiffType;
typedef uint8                   StackType;

/* Unix-specific interrupt state type for pthread simulation */
typedef uint32_t                InterruptStateType;

/* Boolean constants */
#if !defined(TRUE)
    #define TRUE    ((boolean)1)
#endif

#if !defined(FALSE)
    #define FALSE   ((boolean)0)
#endif

/* GCC-specific attributes */
#define PACKED_STRUCT           __attribute__((packed))
#define ALIGNED_STRUCT(x)       __attribute__((aligned(x)))

#endif /* __PLATFORM_TYPES_STM32_GCC_H */