#if !defined(__SPI_H)
#define __SPI_H

#include "Std_Types.h"
#include "CPU_Primitives.h"
#include "ISR.h"


/*
** Register-Offsets.
*/
#define SPICR1      ((uint8)0x00)
        /*  SPICR1-Bits.  */
    #define SPIE    ((uint8)0x80)
    #define SPE     ((uint8)0x40)
    #define SPTIE   ((uint8)0x20)
    #define MSTR    ((uint8)0x10)
    #define CPOL    ((uint8)0x08)
    #define CPHA    ((uint8)0x04)
    #define SSOE    ((uint8)0x02)
    #define LSBFE   ((uint8)0x01)

#define SPICR2      ((uint8)0x01)
        /*  SPICR2-Bits.  */
    #define MODFEN  ((uint8)0x10)
    #define BIDIROE ((uint8)0x08)
    #define SPISWAI ((uint8)0x02)
    #define SPC0    ((uint8)0x01)

#define SPIBR       ((uint8)0x02)
        /*  SPIBR-Bits. */
    #define SPPR2   ((uint8)0x40)
    #define SPPR1   ((uint8)0x20)
    #define SPPR0   ((uint8)0x10)
    #define SPR2    ((uint8)0x04)
    #define SPR1    ((uint8)0x02)
    #define SPR0    ((uint8)0x01)

#define SPISR       ((uint8)0x03)
        /*  SPISR-Bits. */
    #define SPIF    ((uint8)0x80)
    #define SPTEF   ((uint8)0x20)
    #define MODF    ((uint8)0x10)

/*
**  0x04 Reserved.
*/

#define SPIDR       ((uint8)0x05)
/*
**  0x06-0x07 Reserved.
*/

/*
** global Types.
*/

typedef struct tagSPI_VariablesType {
    uint8 *IOBufAddr;
    uint8 IOBufLength;
    uint8 IOBufPtr;
} SPI_VariablesType;


typedef struct tagSPI_ConfigType {
    uint16 BaseAddr;
    uint32 BaudRate;    /* todo: Prescaler!!! */
    SPI_VariablesType * const Vars;
} SPI_ConfigType;

/* todo: CFG-Datei!!! */
#define BASE_ADDR_SPI0  ((uint16)0x00d8)
#define BASE_ADDR_SPI1  ((uint16)0x00f0)
#define BASE_ADDR_SPI2  ((uint16)0x00f8)



void SPI_Init(const SPI_ConfigType *Cfg);
void SPI_SetSpeed(const SPI_ConfigType *Cfg,uint8 prescaler);
void SPI_SetFormat(const SPI_ConfigType *Cfg,boolean cpol,boolean cpha,boolean lsbfe);

boolean SPI_Ready(const SPI_ConfigType *Cfg);
uint8 SPI_IOByte(const SPI_ConfigType *Cfg,uint8 data);

void SPI_IOBuffer(const SPI_ConfigType *Cfg,uint8 *data,uint8 len,boolean use_interrupt);

#endif  /* __SPI_H */
