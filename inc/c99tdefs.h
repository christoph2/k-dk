#if !defined(__C99TDEFS_H)
#define __C99TDEFS_H

#include <stdint.h>
#include <stdbool.h>    /* Nur C99 ??? */

/* Types  */
typedef bool            boolean;
typedef int8_t          sint8;
typedef uint8_t         uint8;
typedef int16_t         sint16;
typedef uint16_t        uint16;
typedef int32_t         sint32;
typedef uint32_t        uint32;

typedef int_least8_t    sint8_least;
typedef uint_least8_t   uint8_least;
typedef int_least16_t   sint16_least;
typedef uint_least8_t   uint16_least;
typedef int_least32_t   sint32_least;
typedef uint_least32_t  uint32_least;

/*
typedef float           float32;
typedef double          float64;
*/
#endif /* __C99TDEFS_H */
