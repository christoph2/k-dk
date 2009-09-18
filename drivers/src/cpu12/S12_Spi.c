
#include "S12_Spi.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES
**  ==========
**  S12SPIV3 - HCS12 SERIAL PERIPHERAL INTERFACE (SPI) BLOCK GUIDE
**
*/

/*
**
** todo: todo evtl. doch 'error()' wg. 'MODF'-Handling???
**
**  Return-Codes!!!
**
*/


static void S12Spi_Handler(S12Spi_ConfigType const * const Cfg);
static boolean S12Spi_TxReady(S12Spi_ConfigType const * const Cfg);


/* todo: BufferPointer als statische Variable!!! */

void S12Spi_Init(S12Spi_ConfigType const * const Cfg)
{
    uint8 ch;
    
    S12_REG8(Cfg,SPICR1)=SPE|MSTR|SSOE;
    S12_REG8(Cfg,SPICR2)=MODFEN|BIDIROE|SPISWAI;

    ch=S12_REG8(Cfg,SPIDR);
    S12_REG8(Cfg,SPIBR)=(uint8)0x00;  /* todo: Prescaler setzen!!! */
    S12_REG8(Cfg,SPICR1)|=SPIE;
}


void S12Spi_SetSpeed(S12Spi_ConfigType const * const Cfg,uint8 prescaler)
{
    S12_REG8(Cfg,SPIBR)=(uint8)0x70 | (prescaler & (uint8)0x07);
}


/*
    CPOL — SPI Clock Polarity Bit   (Active low/high clock).
    CPHA — SPI Clock Phase Bit      (ClockInPhase).
    LSBFE — SPI LSB-First Enable    (LSB-First).
*/
void S12Spi_SetFormat(S12Spi_ConfigType const * const Cfg,boolean cpol,boolean cpha,boolean lsbfe)
{
    uint8 mask;
    /* todo: Fehlercode, falls SPI 'BUSY' !!! */
    
    mask=S12_REG8(Cfg,SPICR1) & (uint8)0xf2;
    
    if (cpol==TRUE) {
        mask|=CPOL;
    }
    
    if (cpha==TRUE) {
        mask|=CPHA;
    }
    
    if (lsbfe==TRUE) {
        mask|=LSBFE;
    }    

    S12_REG8(Cfg,SPICR1)=mask;
}


boolean S12Spi_Ready(S12Spi_ConfigType const * const Cfg)  /* todo: besserer Name!!! */    /* TransferComplete */
{
    return (S12_REG8(Cfg,SPISR) & SPIF)!=(uint8)0;
}


boolean S12Spi_TxReady(S12Spi_ConfigType const * const Cfg)    /* TransmitterEmpty */
{
    if ((S12_REG8(Cfg,SPISR) & SPTEF) || (S12_REG8(Cfg,SPICR1) & SPTIE)) {
        return FALSE;
    } else {
        return TRUE;
    }
}


uint8 S12Spi_IOByte(S12Spi_ConfigType const * const Cfg,uint8 data)
{
    WAIT_FOR(S12Spi_TxReady(Cfg));    
    S12_REG8(Cfg,SPIDR)=data;    
    WAIT_FOR(S12Spi_Ready(Cfg));
 
    return S12_REG8(Cfg,SPIDR);
}


void S12Spi_IOBuffer(S12Spi_ConfigType const * const Cfg,uint8 *data,uint8 len,boolean use_interrupt)
{
    uint8 idx;
    
    if (len) {
        if (len==(uint8)1) {
            data[0]=S12Spi_IOByte(Cfg,data[0]);
        } else {
            if (use_interrupt==FALSE) {
                for (idx=0;idx<len;++idx) {
                    data[idx]=S12Spi_IOByte(Cfg,data[idx]);
                }
            } else {
        
            }
        }
    } else {
        /* todo: return ERROR_CODE!!! */   
    }
}


void S12Spi_Handler(S12Spi_ConfigType const * const Cfg)
{
    uint8 ch;
    
    if ((S12_REG8(Cfg,SPISR) & SPTEF)==SPTEF) {
        if (Cfg->Vars->IOBufPtr<Cfg->Vars->IOBufLength) {
            S12_REG8(Cfg,SPIDR)=Cfg->Vars->IOBufAddr[Cfg->Vars->IOBufPtr++];
        } else {
            S12_REG8(Cfg,SPICR1)&=~SPTIE;
        }    
    }
    
    if ((S12_REG8(Cfg,SPISR) & SPIF)==SPIF) {
        ch=S12_REG8(Cfg,SPIDR);
    }
}


ISR1(SPI0_Vector)
{
    S12Spi_Handler(SPI0);
}
