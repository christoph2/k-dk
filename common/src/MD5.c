/* MD5C.C - RSA Data Security, Inc., MD5 message-digest algorithm
 */

/*
 *
 * Copyright (C) 2009 Christoph Schueler (chris@konnex-tools.de)
 *
 *
 */

/* Copyright (C) 1991-2, RSA Data Security, Inc. Created 1991. All
   rights reserved.

   License to copy and use this software is granted provided that it
   is identified as the "RSA Data Security, Inc. MD5 Message-Digest
   Algorithm" in all material mentioning or referencing this software
   or this function.

   License is also granted to make and use derivative works provided
   that such works are identified as "derived from the RSA Data
   Security, Inc. MD5 Message-Digest Algorithm" in all material
   mentioning or referencing the derived work.

   RSA Data Security, Inc. makes no representations concerning either
   the merchantability of this software or the suitability of this
   software for any particular purpose. It is provided "as is"
   without express or implied warranty of any kind.

   These notices must be retained in any copies of any part of this
   documentation and/or software.
 */

#include "MD5.h"

/*
 * Constants for MD5Transform routine.
 *
 */
#define S11 (7UL)
#define S12 (12UL)
#define S13 (17UL)
#define S14 (22UL)
#define S21 (5UL)
#define S22 (9UL)
#define S23 (14UL)
#define S24 (20UL)
#define S31 (4UL)
#define S32 (11UL)
#define S33 (16UL)
#define S34 (23UL)
#define S41 (6UL)
#define S42 (10UL)
#define S43 (15UL)
#define S44 (21UL)

static void MD5_Transform(uint32 [4], unsigned char [64]);
static void MD5_Encode(unsigned char *, uint32 *, unsigned int);
static void MD5_Decode(uint32 *, unsigned char *, unsigned int);


static unsigned char PADDING[64] = {
    0x80,                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0,                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,0,
    0,                   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
};

/* F, G, H and I are basic MD5 functions. */
#define F(x, y, z)                  (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z)                  (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z)                  ((x) ^ (y) ^ (z))
#define I(x, y, z)                  ((y) ^ ((x) | (~z)))

/* ROTATE_LEFT rotates x left n bits. */
#define ROTATE_LEFT(x, n)           (((x) << (n)) | ((x) >> (32 - (n))))

/*
 *
 * FF, GG, HH, and II transformations for rounds 1, 2, 3, and 4.
 * Rotation is separate from addition to prevent recomputation.
 *
 */
#define FF(a, b, c, d, x, s, ac)    {                   \
        (a)   += F((b), (c), (d)) + (x) + (uint32)(ac); \
        (a)    = ROTATE_LEFT((a), (s));                 \
        (a)   += (b);                                   \
}
#define GG(a, b, c, d, x, s, ac)    {                   \
        (a)   += G((b), (c), (d)) + (x) + (uint32)(ac); \
        (a)    = ROTATE_LEFT((a), (s));                 \
        (a)   += (b);                                   \
}
#define HH(a, b, c, d, x, s, ac)    {                   \
        (a)   += H((b), (c), (d)) + (x) + (uint32)(ac); \
        (a)    = ROTATE_LEFT((a), (s));                 \
        (a)   += (b);                                   \
}
#define II(a, b, c, d, x, s, ac)    {                   \
        (a)   += I((b), (c), (d)) + (x) + (uint32)(ac); \
        (a)    = ROTATE_LEFT((a), (s));                 \
        (a)   += (b);                                   \
}

/*
 *
 * MD5 initialization. Begins an MD5 operation, writing a new context.
 *
 */
void MD5_Init(MD5_CTX * context)
{
    context->count[0] = context->count[1] = 0;

    /* Load magic initialization constants. */
    context->state[0]  = 0x67452301UL;
    context->state[1]  = 0xefcdab89UL;
    context->state[2]  = 0x98badcfeUL;
    context->state[3]  = 0x10325476UL;
}


/*
 *
 * MD5 block update operation. Continues an MD5 message-digest
 * operation, processing another message block, and updating the
 *  context.
 *
 */
void MD5_Update(MD5_CTX * context, unsigned char * input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    /* Compute number of bytes mod 64 */
    index = (unsigned int)((context->count[0] >> 3) & 0x3F);

    /* Update number of bits */
    if ((context->count[0] += ((uint32)inputLen << 3)) < ((uint32)inputLen << 3)) {
        context->count[1]++;
    }

    context->count[1] += ((uint32)inputLen >> 29);

    partLen = 64 - index;

    /* Transform as many times as possible. */
    if (inputLen >= partLen) {
        Utl_MemCopy(&context->buffer[index], input, partLen);
        MD5_Transform(context->state, context->buffer);

        for (i = partLen; i + 63 < inputLen; i += 64) {
            MD5_Transform(context->state, &input[i]);
        }

        index = 0;
    } else {
        i = 0;
    }

    /* Buffer remaining input */
    Utl_MemCopy(&context->buffer[index], &input[i], inputLen - i);
}


/*
 * MD5 finalization. Ends an MD5 message-digest operation, writing the
 * the message digest and zeroizing the context.
 *
 */
void MD5_Final(unsigned char digest[16], MD5_CTX * context)
{
    unsigned char   bits[8];
    unsigned int    index, padLen;

    /* Save number of bits */
    MD5_Encode(bits, context->count, 8);

    /* Pad out to 56 mod 64. */
    index  = (unsigned int)((context->count[0] >> 3) & 0x3f);
    padLen = (index < 56) ? (56 - index) : (120 - index);
    MD5_Update(context, PADDING, padLen);

    /* Append length (before padding) */
    MD5_Update(context, bits, 8);
    /* Store state in digest */
    MD5_Encode(digest, context->state, 16);

    /* Zeroize sensitive information. */
    Utl_MemSet(context, 0, sizeof(*context));
}


/*
 * MD5 basic transformation. Transforms state based on block.
 */
static void MD5_Transform(uint32 state[4], unsigned char block[64])
{
    uint32 a = state[0], b = state[1], c = state[2], d = state[3], x[16];

    MD5_Decode(x, block, 64);

    /* Round 1 */
    FF(a, b, c, d, x[ 0], S11, 0xd76aa478UL);   /* 1 */
    FF(d, a, b, c, x[ 1], S12, 0xe8c7b756UL);   /* 2 */
    FF(c, d, a, b, x[ 2], S13, 0x242070dbUL);   /* 3 */
    FF(b, c, d, a, x[ 3], S14, 0xc1bdceeeUL);   /* 4 */
    FF(a, b, c, d, x[ 4], S11, 0xf57c0fafUL);   /* 5 */
    FF(d, a, b, c, x[ 5], S12, 0x4787c62aUL);   /* 6 */
    FF(c, d, a, b, x[ 6], S13, 0xa8304613UL);   /* 7 */
    FF(b, c, d, a, x[ 7], S14, 0xfd469501UL);   /* 8 */
    FF(a, b, c, d, x[ 8], S11, 0x698098d8UL);   /* 9 */
    FF(d, a, b, c, x[ 9], S12, 0x8b44f7afUL);   /* 10 */
    FF(c, d, a, b, x[10], S13, 0xffff5bb1UL);   /* 11 */
    FF(b, c, d, a, x[11], S14, 0x895cd7beUL);   /* 12 */
    FF(a, b, c, d, x[12], S11, 0x6b901122UL);   /* 13 */
    FF(d, a, b, c, x[13], S12, 0xfd987193UL);   /* 14 */
    FF(c, d, a, b, x[14], S13, 0xa679438eUL);   /* 15 */
    FF(b, c, d, a, x[15], S14, 0x49b40821UL);   /* 16 */

    /* Round 2 */
    GG(a, b, c, d, x[ 1], S21, 0xf61e2562UL);   /* 17 */
    GG(d, a, b, c, x[ 6], S22, 0xc040b340UL);   /* 18 */
    GG(c, d, a, b, x[11], S23, 0x265e5a51UL);   /* 19 */
    GG(b, c, d, a, x[ 0], S24, 0xe9b6c7aaUL);   /* 20 */
    GG(a, b, c, d, x[ 5], S21, 0xd62f105dUL);   /* 21 */
    GG(d, a, b, c, x[10], S22,  0x2441453UL);   /* 22 */
    GG(c, d, a, b, x[15], S23, 0xd8a1e681UL);   /* 23 */
    GG(b, c, d, a, x[ 4], S24, 0xe7d3fbc8UL);   /* 24 */
    GG(a, b, c, d, x[ 9], S21, 0x21e1cde6UL);   /* 25 */
    GG(d, a, b, c, x[14], S22, 0xc33707d6UL);   /* 26 */
    GG(c, d, a, b, x[ 3], S23, 0xf4d50d87UL);   /* 27 */
    GG(b, c, d, a, x[ 8], S24, 0x455a14edUL);   /* 28 */
    GG(a, b, c, d, x[13], S21, 0xa9e3e905UL);   /* 29 */
    GG(d, a, b, c, x[ 2], S22, 0xfcefa3f8UL);   /* 30 */
    GG(c, d, a, b, x[ 7], S23, 0x676f02d9UL);   /* 31 */
    GG(b, c, d, a, x[12], S24, 0x8d2a4c8aUL);   /* 32 */

    /* Round 3 */
    HH(a, b, c, d, x[ 5], S31, 0xfffa3942UL);   /* 33 */
    HH(d, a, b, c, x[ 8], S32, 0x8771f681UL);   /* 34 */
    HH(c, d, a, b, x[11], S33, 0x6d9d6122UL);   /* 35 */
    HH(b, c, d, a, x[14], S34, 0xfde5380cUL);   /* 36 */
    HH(a, b, c, d, x[ 1], S31, 0xa4beea44UL);   /* 37 */
    HH(d, a, b, c, x[ 4], S32, 0x4bdecfa9UL);   /* 38 */
    HH(c, d, a, b, x[ 7], S33, 0xf6bb4b60UL);   /* 39 */
    HH(b, c, d, a, x[10], S34, 0xbebfbc70UL);   /* 40 */
    HH(a, b, c, d, x[13], S31, 0x289b7ec6UL);   /* 41 */
    HH(d, a, b, c, x[ 0], S32, 0xeaa127faUL);   /* 42 */
    HH(c, d, a, b, x[ 3], S33, 0xd4ef3085UL);   /* 43 */
    HH(b, c, d, a, x[ 6], S34,  0x4881d05UL);   /* 44 */
    HH(a, b, c, d, x[ 9], S31, 0xd9d4d039UL);   /* 45 */
    HH(d, a, b, c, x[12], S32, 0xe6db99e5UL);   /* 46 */
    HH(c, d, a, b, x[15], S33, 0x1fa27cf8UL);   /* 47 */
    HH(b, c, d, a, x[ 2], S34, 0xc4ac5665UL);   /* 48 */

    /* Round 4 */
    II(a, b, c, d, x[ 0], S41, 0xf4292244UL);   /* 49 */
    II(d, a, b, c, x[ 7], S42, 0x432aff97UL);   /* 50 */
    II(c, d, a, b, x[14], S43, 0xab9423a7UL);   /* 51 */
    II(b, c, d, a, x[ 5], S44, 0xfc93a039UL);   /* 52 */
    II(a, b, c, d, x[12], S41, 0x655b59c3UL);   /* 53 */
    II(d, a, b, c, x[ 3], S42, 0x8f0ccc92UL);   /* 54 */
    II(c, d, a, b, x[10], S43, 0xffeff47dUL);   /* 55 */
    II(b, c, d, a, x[ 1], S44, 0x85845dd1UL);   /* 56 */
    II(a, b, c, d, x[ 8], S41, 0x6fa87e4fUL);   /* 57 */
    II(d, a, b, c, x[15], S42, 0xfe2ce6e0UL);   /* 58 */
    II(c, d, a, b, x[ 6], S43, 0xa3014314UL);   /* 59 */
    II(b, c, d, a, x[13], S44, 0x4e0811a1UL);   /* 60 */
    II(a, b, c, d, x[ 4], S41, 0xf7537e82UL);   /* 61 */
    II(d, a, b, c, x[11], S42, 0xbd3af235UL);   /* 62 */
    II(c, d, a, b, x[ 2], S43, 0x2ad7d2bbUL);   /* 63 */
    II(b, c, d, a, x[ 9], S44, 0xeb86d391UL);   /* 64 */

    state[0]  += a;
    state[1]  += b;
    state[2]  += c;
    state[3]  += d;

    /* Zeroize sensitive information. */
    Utl_MemSet(x, 0, sizeof(x));
}


/*
 * Encodes input (uint32) into output
 * (unsigned char). Assumes len is a
 * multiple of 4.
 */
static void MD5_Encode(unsigned char * output, uint32 * input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[j]      = (unsigned char)(input[i] & 0xff);
        output[j + 1]  = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2]  = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3]  = (unsigned char)((input[i] >> 24) & 0xff);
    }
}


/*
 * Decodes input (unsigned char) into
 * output (uint32). Assumes len is a
 * multiple of 4.
 */
static void MD5_Decode(uint32 * output, unsigned char * input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4) {
        output[i] = ((uint32)input[j]) | (((uint32)input[j + 1]) << 8) |
                    (((uint32)input[j + 2]) << 16) | (((uint32)input[j + 3]) << 24);
    }
}


