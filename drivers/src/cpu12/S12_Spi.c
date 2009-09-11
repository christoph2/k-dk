
#include "S12_Spi.h"

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
    100000,
    &SPI0Vars
};

static boolean SPI_TxReady(const SPI_ConfigType *Cfg);


/* todo: BufferPointer als statische Variable!!! */

void SPI_Init(const SPI_ConfigType *Cfg)
{
    uint8 ch;

    BYTE_REG(Cfg->BaseAddr,SPICR1)=SPE|MSTR|SSOE;
    BYTE_REG(Cfg->BaseAddr,SPICR2)=MODFEN|BIDIROE|SPISWAI;

    ch=BYTE_REG(Cfg->BaseAddr,SPIDR);
    
    BYTE_REG(Cfg->BaseAddr,SPIBR)=(uint8)0x00;  /* todo: Prescaler setzen!!! */
    
    BYTE_REG(Cfg->BaseAddr,SPICR1)|=SPIE;

    /* todo: OpenDrain!!! */
}

void SPI_SetSpeed(const SPI_ConfigType *Cfg,uint8 prescaler)
{
    BYTE_REG(Cfg->BaseAddr,SPIBR)=0x70 | (prescaler & 0x07);
}

void SPI_SetFormat(const SPI_ConfigType *Cfg,boolean cpol,boolean cpha,boolean lsbfe)
{
    uint8 mask;
    /* todo: Fehlercode, falls SPI 'BUSY' !!! */
    
    mask=BYTE_REG(Cfg->BaseAddr,SPICR1) & (uint8)0xf2;
    
    if (cpol==TRUE) {
        mask|=CPOL;
    }
    
    if (cpha==TRUE) {
        mask|=CPHA;
    }
    
    if (lsbfe==TRUE) {
        mask|=LSBFE;
    }    

    BYTE_REG(Cfg->BaseAddr,SPICR1)=mask;
}


/*
    CPOL — SPI Clock Polarity Bit   (Active low/high clock).
    CPHA — SPI Clock Phase Bit      (ClockInPhase).
    LSBFE — SPI LSB-First Enable    (LSB-First).
*/

boolean SPI_Ready(const SPI_ConfigType *Cfg)  /* todo: besserer Name!!! */    /* TransferComplete */
{
    return (BYTE_REG(Cfg->BaseAddr,SPISR) & SPIF)!=(uint8)0;
}

boolean SPI_TxReady(const SPI_ConfigType *Cfg)    /* TransmitterEmpty */
{
    if ((BYTE_REG(Cfg->BaseAddr,SPISR) & SPTEF) || (BYTE_REG(Cfg->BaseAddr,SPICR1) & SPTIE)) {
        return FALSE;
    } else {
        return TRUE;
    }
}

uint8 SPI_IOByte(const SPI_ConfigType *Cfg,uint8 data)
{
    WAIT_FOR(SPI_TxReady(Cfg));
    
    BYTE_REG(Cfg->BaseAddr,SPIDR)=data;
    
    WAIT_FOR(SPI_Ready(Cfg));
 
    return BYTE_REG(Cfg->BaseAddr,SPIDR);
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
    
    if ((BYTE_REG(Cfg->BaseAddr,SPISR) & SPTEF)==SPTEF) {
        if (Cfg->Vars->IOBufPtr<Cfg->Vars->IOBufLength) {
            BYTE_REG(Cfg->BaseAddr,SPIDR)=Cfg->Vars->IOBufAddr[Cfg->Vars->IOBufPtr++];
        } else {
            BYTE_REG(Cfg->BaseAddr,SPICR1)&=~SPTIE;
        }    
    }
    
    if ((BYTE_REG(Cfg->BaseAddr,SPISR) & SPIF)==SPIF) {
        ch=BYTE_REG(Cfg->BaseAddr,SPIDR);
    }
}

#if 0
ISR(SPI0_Handler)
{
    SPI_Handler(&SPI0);
}
#endif
