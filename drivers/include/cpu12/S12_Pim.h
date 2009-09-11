#if !defined(__S12_PIM_H)
#define __S12_PIM_H

#include "Std_Types.h"

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */
   
/*
**  Register-Offsets.
*/

/*  PortT */
#define PTT             ((uint8)0x00)
    /*  PTT-Bits. */
    #define PTT7        ((uint8)0x80)
    #define PTT6        ((uint8)0x40)
    #define PTT5        ((uint8)0x20)
    #define PTT4        ((uint8)0x10)
    #define PTT3        ((uint8)0x08)
    #define PTT2        ((uint8)0x04)
    #define PTT1        ((uint8)0x02)
    #define PTT0        ((uint8)0x01)

#define PTIT            ((uint8)0x01)
    /*  PTIT-Bits.  */
    #define PTIT7       ((uint8)0x80)
    #define PTIT6       ((uint8)0x40)
    #define PTIT5       ((uint8)0x20)
    #define PTIT4       ((uint8)0x10)
    #define PTIT3       ((uint8)0x08)
    #define PTIT2       ((uint8)0x04)
    #define PTIT1       ((uint8)0x02)
    #define PTIT0       ((uint8)0x01)

#define DDRT            ((uint8)0x02)
    /*  DDRT-Bits.  */
    #define DDRT7       ((uint8)0x80)
    #define DDRT6       ((uint8)0x40)
    #define DDRT5       ((uint8)0x20)
    #define DDRT4       ((uint8)0x10)
    #define DDRT3       ((uint8)0x08)
    #define DDRT2       ((uint8)0x04)
    #define DDRT1       ((uint8)0x02)
    #define DDRT0       ((uint8)0x01)

#define RDRT            ((uint8)0x03)
    /*  RDRT-Bits.  */
    #define RDRT7       ((uint8)0x80)
    #define RDRT6       ((uint8)0x40)
    #define RDRT5       ((uint8)0x20)
    #define RDRT4       ((uint8)0x10)
    #define RDRT3       ((uint8)0x08)
    #define RDRT2       ((uint8)0x04)
    #define RDRT1       ((uint8)0x02)
    #define RDRT0       ((uint8)0x01)

#define PERT            ((uint8)0x04)
    /*  PERT-Bits.  */
    #define PERT7       ((uint8)0x80)
    #define PERT6       ((uint8)0x40)
    #define PERT5       ((uint8)0x20)
    #define PERT4       ((uint8)0x10)
    #define PERT3       ((uint8)0x08)
    #define PERT2       ((uint8)0x04)
    #define PERT1       ((uint8)0x02)
    #define PERT0       ((uint8)0x01)

#define PPST            ((uint8)0x05)
    /*  PPST-Bits.  */
    #define PPST7       ((uint8)0x80)
    #define PPST6       ((uint8)0x40)
    #define PPST5       ((uint8)0x20)
    #define PPST4       ((uint8)0x10)
    #define PPST3       ((uint8)0x08)
    #define PPST2       ((uint8)0x04)
    #define PPST1       ((uint8)0x02)
    #define PPST0       ((uint8)0x01)
/*
**  0x06-0x07 Reserved.
*/

/*  PortS */
#define PTS             ((uint8)0x08)
    /*  PTS-Bits. */
    #define PTS7        ((uint8)0x80)
    #define PTS6        ((uint8)0x40)
    #define PTS5        ((uint8)0x20)
    #define PTS4        ((uint8)0x10)
    #define PTS3        ((uint8)0x08)
    #define PTS2        ((uint8)0x04)
    #define PTS1        ((uint8)0x02)
    #define PTS0        ((uint8)0x01)

#define PTIS            ((uint8)0x09)
    /*  PTIS-Bits.  */
    #define PTIS7       ((uint8)0x80)
    #define PTIS6       ((uint8)0x40)
    #define PTIS5       ((uint8)0x20)
    #define PTIS4       ((uint8)0x10)
    #define PTIS3       ((uint8)0x08)
    #define PTIS2       ((uint8)0x04)
    #define PTIS1       ((uint8)0x02)
    #define PTIS0       ((uint8)0x01)

#define DDRS            ((uint8)0x0A)
    /*  DDRS-Bits.  */
    #define DDRS7       ((uint8)0x80)
    #define DDRS6       ((uint8)0x40)
    #define DDRS5       ((uint8)0x20)
    #define DDRS4       ((uint8)0x10)
    #define DDRS3       ((uint8)0x08)
    #define DDRS2       ((uint8)0x04)
    #define DDRS1       ((uint8)0x02)
    #define DDRS0       ((uint8)0x01)

#define RDRS            ((uint8)0x0B)
    /*  RDRS-Bits.  */
    #define RDRS7       ((uint8)0x80)
    #define RDRS6       ((uint8)0x40)
    #define RDRS5       ((uint8)0x20)
    #define RDRS4       ((uint8)0x10)
    #define RDRS3       ((uint8)0x08)
    #define RDRS2       ((uint8)0x04)
    #define RDRS1       ((uint8)0x02)
    #define RDRS0       ((uint8)0x01)

#define PERS            ((uint8)0x0C)
    /*   PERS-Bits. */
    #define PERS7       ((uint8)0x80)
    #define PERS6       ((uint8)0x40)
    #define PERS5       ((uint8)0x20)
    #define PERS4       ((uint8)0x10)
    #define PERS3       ((uint8)0x08)
    #define PERS2       ((uint8)0x04)
    #define PERS1       ((uint8)0x02)
    #define PERS0       ((uint8)0x01)

#define PPSS            ((uint8)0x0D)
    /*  PPSS-Bits.  */
    #define PPSS7       ((uint8)0x80)
    #define PPSS6       ((uint8)0x40)
    #define PPSS5       ((uint8)0x20)
    #define PPSS4       ((uint8)0x10)
    #define PPSS3       ((uint8)0x08)
    #define PPSS2       ((uint8)0x04)
    #define PPSS1       ((uint8)0x02)
    #define PPSS0       ((uint8)0x01)

#define WOMS            ((uint8)0x0E)
    /*  WOMS-Bits. */
    #define WOMS7       ((uint8)0x80)
    #define WOMS6       ((uint8)0x40)
    #define WOMS5       ((uint8)0x20)
    #define WOMS4       ((uint8)0x10)
    #define WOMS3       ((uint8)0x08)
    #define WOMS2       ((uint8)0x04)
    #define WOMS1       ((uint8)0x02)
    #define WOMS0       ((uint8)0x01)
/*
**  0x0F Reserved.
*/

typedef enum tagS12Pim_StatusType {
    S12PIM_OK
} S12Pim_StatusType;

typedef struct tagS12Pim_ConfigType {
    uint16 BaseAddr;
} S12Pim_ConfigType;

    
#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif /* __S12_MMC_H*/
