#if !defined(__S12_MEBI_H)
#define __S12_MEBI_H

#include "Std_Types.h"
#include "CPU_Primitives.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

/*
**  Register-Offsets.
*/
#define	PORTA       ((uint8)0x00)
#define	PORTB       ((uint8)0x01)
#define	DDRA        ((uint8)0x02)
#define	DDRB        ((uint8)0x03)
/*
0x04-0x07 Reserved
*/
#define	PORTE       ((uint8)0x08)
#define	DDRE        ((uint8)0x09)
#define	PEAR        ((uint8)0x0A)
    /*  PEAR-Bits.  */
    #define NOACCE  ((uint8)0x80)
    #define PIPOE   ((uint8)0x20)
    #define NECLK   ((uint8)0x10)
    #define LSTRE   ((uint8)0x08)
    #define RDWE    ((uint8)0x04)

#define	MODE        ((uint8)0x0B)
    /*  MODE-Bits.  */
    #define MODC    ((uint8)0x80)
    #define MODB    ((uint8)0x40)
    #define MODA    ((uint8)0x20)
    #define IVIS    ((uint8)0x08)
    #define EMK     ((uint8)0x02)
    #define EME     ((uint8)0x01)

#define	PUCR        ((uint8)0x0C)
    /*  PUCR-Bits.  */
    #define PUPKE   ((uint8)0x80)
    #define PUPEE   ((uint8)0x10)
    #define PUPBE   ((uint8)0x02)
    #define PUPAE   ((uint8)0x01)

#define	RDRIV       ((uint8)0x0D)
    /*  RDRIV-Bits. */
    #define RDPK    ((uint8)0x80)
    #define RDPE    ((uint8)0x10)
    #define RDPB    ((uint8)0x02)
    #define RDPA    ((uint8)0x01)

#define	EBICTL      ((uint8)0x0E)
    /*  EBICTL-Bits.  */
    #define ESTR    ((uint8)0x01)

typedef enum tagS12Mebi_StatusType {
    S12MEBI_OK
} S12Mebi_StatusType;


typedef enum tagS12Mebi_ModeType {
    S12MODE_SPECIAL_SINGLE_CHIP,
    S12MODE_EMULATION_NARROW,
    S12MODE_SPECIAL_TEST,
    S12MODE_EMULATION_WIDE,
    S12MODE_NORMAL_SINGLE_CHIP,
    S12MODE_NORMAL_EXPANDED_NARROW,
    S12MODE_SPECIAL_PERIPHAL,
    S12MODE_NORMAL_EXPANDED_WIDE
} S12Mebi_ModeType;

typedef struct tagS12Mebi_ConfigType {
    uint16 BaseAddr;
} S12Mebi_ConfigType;


S12Mebi_StatusType S12Mebi_GetMode(S12Mebi_ModeType *mode);
S12Mebi_StatusType S12Mebi_NormalMode(boolean *flag);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_MEBI_H */
