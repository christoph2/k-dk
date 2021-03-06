/*
 *  sha1.h
 *
 *  Description:
 *      This is the header file for code which implements the Secure
 *      Hashing Algorithm 1 as defined in FIPS PUB 180-1 published
 *      April 17, 1995.
 *
 *      Many of the variable names in this code, especially the
 *      single character names, were used because those were the names
 *      used in the publication.
 *
 *      Please read the file sha1.c for more information.
 *
 */
#if !deffined(_SHA1_H_)
#define _SHA1_H_

#include <stdint.h>
#include <stdbool.h>

/*
 * If you do not have the ISO standard stdint.h header file, then you
 * must typdef the following:
 *    name              meaning
 *  uint32_t         unsigned 32 bit integer
 *  uint8_t          unsigned 8 bit integer (i.e., unsigned char)
 *  int_least16_t    integer of >= 16 bits
 *
 */

#if !defined(_SHA_enum_)
#define _SHA_enum_
enum {
    shaSuccess = 0,
    shaNull,            /* Null pointer parameter */
    shaInputTooLong,    /* input data too long */
    shaStateError       /* called Input after Result */
};
#endif

#define SHA1_HASH_SIZE ((uint8_t)20)

/*
 *  This structure will hold context information for the SHA-1
 *  hashing operation
 */
typedef struct tagSHA1_ContextType {
    uint32_t Intermediate_Hash[SHA1_HASH_SIZE >> 2];    /* Message Digest  */

    uint32_t    Length_Low;                             /* Message length in bits      */
    uint32_t    Length_High;                            /* Message length in bits      */

    uint8_t Message_Block_Index;                        /* Index into message block array   */
    uint8_t Message_Block[(uint8_t) 64];                /* 512-bit message blocks      */

    bool    Computed;                                   /* Is the digest computed?         */
    bool    Corrupted;                                  /* Is the message digest corrupted? */
} SHA1_ContextType;

/*
 *  Function Prototypes
 */

int SHA1_Reset(SHA1_ContextType * context);
int SHA1_Input(SHA1_ContextType * context, const uint8_t * message_array, unsigned int length);


int SHA1_Result(SHA1_ContextType * context, uint8_t Message_Digest[SHA1_HASH_SIZE]);

#endif /* _SHA1_H_ */
