
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

static void SPI_Handler(const SPI_ConfigType *Cfg);

static SPI_VariablesType SPI0Vars;

static const SPI_ConfigType SPI0={
    BASE_ADDR_SPI0,
    (uint32)100000,
    &SPI0Vars
};

static boolean SPI_TxReady(const SPI_ConfigType *Cfg);


/* todo: BufferPointer als statische Variable!!! */

void SPI_Init(const SPI_ConfigType *Cfg)
{
    uint8 ch;
    
    S12_REG8(Cfg,SPICR1)=SPE|MSTR|SSOE;
    S12_REG8(Cfg,SPICR2)=MODFEN|BIDIROE|SPISWAI;

    ch=S12_REG8(Cfg,SPIDR);
    S12_REG8(Cfg,SPIBR)=(uint8)0x00;  /* todo: Prescaler setzen!!! */
    S12_REG8(Cfg,SPICR1)|=SPIE;
}

void SPI_SetSpeed(const SPI_ConfigType *Cfg,uint8 prescaler)
{
    S12_REG8(Cfg,SPIBR)=0x70 | (prescaler & 0x07);
}

void SPI_SetFormat(const SPI_ConfigType *Cfg,boolean cpol,boolean cpha,boolean lsbfe)
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


/*
    CPOL � SPI Clock Polarity Bit   (Active low/high clock).
    CPHA � SPI Clock Phase Bit      (ClockInPhase).
    LSBFE � SPI LSB-First Enable    (LSB-First).
*/

boolean SPI_Ready(const SPI_ConfigType *Cfg)  /* todo: besserer Name!!! */    /* TransferComplete */
{
    return (S12_REG8(Cfg,SPISR) & SPIF)!=(uint8)0;
}

boolean SPI_TxReady(const SPI_ConfigType *Cfg)    /* TransmitterEmpty */
{
    if ((S12_REG8(Cfg,SPISR) & SPTEF) || (S12_REG8(Cfg,SPICR1) & SPTIE)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

uint8 SPI_IOByte(const SPI_ConfigType *Cfg,uint8 data)
{
    WAIT_FOR(SPI_TxReady(Cfg));    
    S12_REG8(Cfg,SPIDR)=data;    
    WAIT_FOR(SPI_Ready(Cfg));
 
    return S12_REG8(Cfg,SPIDR);
}


void SPI_IOBuffer(const SPI_ConfigType *Cfg,uint8 *data,uint8 len,boolean use_interrupt)
{
    uint8 idx;
    
    if (len) {
        if (len==(uint8)1) {
            data[0]=SPI_IOByte(Cfg,data[0]);
        } else {
            if (use_interrupt==FALSE) {
                for (idx=0;idx<len;++idx) {
                    data[idx]=SPI_IOByte(Cfg,data[idx]);
                }
            } else {
        
            }
        }
    } else {
        /* todo: return ERROR_CODE!!! */   
    }
}

void SPI_Handler(const SPI_ConfigType *Cfg)
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

#if 0
ISR(SPI0_Handler)
{
    SPI_Handler(&SPI0);
}
#endif
