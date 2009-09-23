#if !defined( __PLATFORM_TYPES_H)
#define __PLATFORM_TYPES_H

/* Definitionen f. alle Platformen ==> andere Datei!!!  */
#define CPU_TYPE_8      8
#define CPU_TYPE_16     16
#define CPU_TYPE_32     32

#define MSB_FIRST       0
#define LSB_FIRST       1

#define HIGH_BYTE_FIRST 0
#define	LOW_BYTE_FIRST  1

#if !defined(NULL)
    #define NULL        0
#endif

/* Definitions for CPU12. */

/* Symbols  */
#define	CPU_TYPE        CPU_TYPE_16
#define	CPU_BIT_ORDER   LSB_FIST
#define	CPU_BYTE_ORDER  HIGH_BYTE_FIRST


/* Das gehöhrt eigentlich nach 'Std_Types.h' !!! */
#if (defined(__IAR_SYSTEMS_ICC__) && defined(_DLIB_ADD_C99_SYMBOLS)) || (defined(_C99_COMPILER)) || (defined(_CPP_COMPILER))
#include <stdint.h>
#include <stdbool.h>


/* typedef bool boolean; */
typedef unsigned char boolean;

typedef /*@signed-integral-type@*/      int8_t          sint8;
typedef /*@unsigned-integral-type@*/    int8_t          uint8;
typedef /*@signed-integral-type@*/      int16_t         sint16;
typedef /*@unsigned-integral-type@*/    uint16_t        uint16;
typedef /*@signed-integral-type@*/      int32_t         sint32;
typedef /*@unsigned-integral-type@*/    uint32_t        uint32;

typedef /*@signed-integral-type@*/      int_least8_t    sint8_least;
typedef /*@unsigned-integral-type@*/    uint_least8_t   uint8_least;
typedef /*@signed-integral-type@*/      int_least16_t   sint16_least;
typedef /*@unsigned-integral-type@*/    uint_least16_t  uint16_least;
typedef /*@signed-integral-type@*/      int_least32_t   sint32_least;
typedef /*@unsigned-integral-type@*/    uint_least32_t  uint32_least;

#if !defined(TRUE)
    #define TRUE        ((boolean)true)
#endif

#if !defined(FALSE)
    #define FALSE       ((boolean)false)
#endif


#else
/* Types  */
typedef unsigned char   boolean;
typedef signed char     sint8;
typedef unsigned char   uint8;
typedef signed short    sint16;
typedef unsigned short  uint16;
typedef signed long     sint32;
typedef unsigned long   uint32;

typedef signed char     sint8_least;
typedef unsigned char   uint8_least;
typedef signed short    sint16_least;
typedef unsigned short  uint16_least;
typedef signed long     sint32_least;
typedef unsigned long   uint32_least;

#if !defined(TRUE)
    #define TRUE        ((boolean)1)
#endif

#if !defined(FALSE)
    #define FALSE       ((boolean)0)
#endif

#endif

typedef float           float32;
typedef double          float64;
typedef void *          pvoid;
typedef unsigned int    SizeType;
typedef int             PtrDiffType;

#endif /* __PLATFORM_TYPES_H  */
