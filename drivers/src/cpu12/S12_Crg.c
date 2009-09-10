
#include "S12_Crg.h"
#include "Hw_Cfg.h"

S12Crg_StatusType S12Crg_Init(uint8 freq)
{
    S12Crg_StatusType status;
    boolean normal_mode;
    

/*    BYTE_REG(CRG.BaseAddr,CLKSEL)&=~PLLSEL; */
    BYTE_REG(CRG.BaseAddr,CLKSEL)=/*PSTP|ROAWAI*/COPWAI;
    BYTE_REG(CRG.BaseAddr,PLLCTL)=CME|PLLON|AUTO|ACQ|SCME;  /* Hinweis: 'ACQ' hat keine Bedeutung, wenn 'AUTO' !!!*/

    (void)S12Mebi_NormalMode(&normal_mode);

    if (normal_mode==TRUE) {
        status=S12Crg_SetPLLFreq(freq);
        if (status!=S12CRG_OK) {
            return status;   
        }        
        status=S12Crg_EnablePLL();
        if (status!=S12CRG_OK) {
            return status;   
        }            
    } else {
        /* we don't use PLL-Clock in Specialmodes (==> BDM). */
        (void)S12Crg_DisablePLL();
        
    }
    
    if (CRG.EnableRTI==TRUE) {
        status=S12Crg_SetRTIRate(((CRG.RTIPrescaler & (uint8)0x07)<<4) | (CRG.RTIModulo & ((uint8)0x0f)));
        if (status!=S12CRG_OK) {
            return status;
        }
        status=S12Crg_EnableRTI();
    } else {
        status=S12Crg_DisableRTI();
    }   
    if (status!=S12CRG_OK) {
        return status;   
    }
       
    /* todo:  'EnablePLL()' !!! */
/*    BYTE_REG(CRG.BaseAddr,CLKSEL)|=PLLSEL;   */
    
    return S12CRG_OK;
}

/* todo: die Funktionen Enable-/Disable-PLL implementieren ('PLLCTL') !!! */
S12Crg_StatusType S12Crg_EnablePLL(void)
{
    boolean flag;

    (void)S12Crg_PLLEnabled(&flag);

    if (flag==TRUE) {
        return S12CRG_STATE;
    }

    BYTE_REG(CRG.BaseAddr,CLKSEL)|=PLLSEL;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisablePLL(void)
{
    boolean flag;

    (void)S12Crg_PLLEnabled(&flag);

    if (flag==FALSE) {
        return S12CRG_STATE;
    }    

    BYTE_REG(CRG.BaseAddr,CLKSEL)&=~PLLSEL;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_PLLEnabled(boolean *flag)
{
    *flag=((BYTE_REG(CRG.BaseAddr,CLKSEL) & PLLSEL)==PLLSEL);

    return S12CRG_OK;    
}


S12Crg_StatusType S12Crg_SetPLLFreq(uint8 freq)
{
    boolean flag;
    
    if ((freq==((uint8)0)) || freq > CRG.MaxBusFreq) {
        return S12CRG_VALUE;
    }

    (void)S12Crg_PLLEnabled(&flag);

    if (flag==TRUE) {
        return S12CRG_STATE;
    }

    BYTE_REG(CRG.BaseAddr,REFDV)=CRG.OscFreq-((uint8)1);  /* divide to get 1MHz. */
    BYTE_REG(CRG.BaseAddr,SYNR)=freq-((uint8)1);
    
    WAIT_FOR((BYTE_REG(CRG.BaseAddr,CRGFLG) & LOCK)!=((uint8)0x00));
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_GetBusFreq(uint8 *freq)
{
    uint8 bus_freq;
    boolean flag;

    (void)S12Crg_PLLEnabled(&flag);    

    if (flag==TRUE) {
        bus_freq=CRG.OscFreq / (BYTE_REG(CRG.BaseAddr,REFDV) + 1);
        bus_freq*=(BYTE_REG(CRG.BaseAddr,SYNR)+1);
    } else {
        bus_freq=CRG.OscFreq/2;
    }

    *freq=bus_freq;

    return S12CRG_OK;    
}


S12Crg_StatusType S12Crg_GetOscFreq(uint8 *freq)
{
    *freq=CRG.OscFreq;

    return S12CRG_OK;    
}


S12Crg_StatusType S12Crg_EnableRTI(void)
{  
    boolean flag;

    (void)S12Crg_RTIEnabled(&flag);
    
    if (flag==TRUE) {
        return S12CRG_STATE;    
    }

    BYTE_REG(CRG.BaseAddr,CRGFLG)=RTIF;    
    BYTE_REG(CRG.BaseAddr,CRGINT)|=RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisableRTI(void)
{
    boolean flag;

    (void)S12Crg_RTIEnabled(&flag);
    
    if (flag==FALSE) {
        return S12CRG_STATE;    
    }

    BYTE_REG(CRG.BaseAddr,RTICTL)=((uint8)0x00);
    BYTE_REG(CRG.BaseAddr,CRGINT)&=~RTIE;
    BYTE_REG(CRG.BaseAddr,CRGFLG)=RTIF;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetRTIRate(uint8 rate)
{
    boolean flag;

    (void)S12Crg_RTIEnabled(&flag);
    
    if (flag==TRUE) {
        return S12CRG_STATE;    
    }
    
    BYTE_REG(CRG.BaseAddr,RTICTL)=rate;

    return S12CRG_OK;        
}


S12Crg_StatusType S12Crg_RTIEnabled(boolean *flag)
{
    *flag=(BYTE_REG(CRG.BaseAddr,CRGINT) & RTIE)==RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_ResetMCU(void)
{

    if (!(BYTE_REG(CRG.BaseAddr,COPCTL) & (CR2|CR1|CR0))) {
                                        /* Enable COP if disabled. */
        BYTE_REG(CRG.BaseAddr,COPCTL)=(RSBCK|CR0);
    }
    
    BYTE_REG(CRG.BaseAddr,ARMCOP)=0xcc; /* Write garbage to 'ARMCOP' ==> instant RESET. */
    
    return S12CRG_OK;                   /* never reached... */    
}


ISR1(RTI_Vector)
{
    static uint32 cnt;
    
    BYTE_REG(CRG.BaseAddr,CRGFLG)=RTIF;
    
    cnt++;
}
