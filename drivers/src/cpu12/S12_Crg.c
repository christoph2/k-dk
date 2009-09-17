
#include "S12_Crg.h"
#include "Hw_Cfg.h"

S12Crg_StatusType S12Crg_Init(uint8 freq)
{
    S12Crg_StatusType status;
    boolean special_mode;
    

/*    S12CRG_REG8(CLKSEL)&=~PLLSEL; */
    S12CRG_REG8(CLKSEL)=/*PSTP|ROAWAI*/COPWAI;
    S12CRG_REG8(PLLCTL)=CME|PLLON|AUTO|ACQ|SCME;  /* Hinweis: 'ACQ' hat keine Bedeutung, wenn 'AUTO' !!!*/

    (void)S12Mebi_SpecialMode(&special_mode);

    if (special_mode==FALSE) {
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
/*    S12CRG_REG8(CLKSEL)|=PLLSEL;   */
    
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

    S12CRG_REG8(CLKSEL)|=PLLSEL;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisablePLL(void)
{
    boolean flag;

    (void)S12Crg_PLLEnabled(&flag);

    if (flag==FALSE) {
        return S12CRG_STATE;
    }    

    S12CRG_REG8(CLKSEL)&=~PLLSEL;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_PLLEnabled(boolean *flag)
{
    *flag=((S12CRG_REG8(CLKSEL) & PLLSEL)==PLLSEL);

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

    S12CRG_REG8(REFDV)=CRG.OscFreq-((uint8)1);  /* divide, to get 1MHz. */
    S12CRG_REG8(SYNR)=freq-((uint8)1);
    
    WAIT_FOR((S12CRG_REG8(CRGFLG) & LOCK)==LOCK);
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_GetBusFreq(uint8 *freq)
{
    uint8 bus_freq;
    boolean flag;

    (void)S12Crg_PLLEnabled(&flag);    

    if (flag==TRUE) {
        bus_freq=CRG.OscFreq / (S12CRG_REG8(REFDV) + 1);
        bus_freq*=(S12CRG_REG8(SYNR)+1);
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

    S12CRG_REG8(CRGFLG)=RTIF;    
    S12CRG_REG8(CRGINT)|=RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_DisableRTI(void)
{
    boolean flag;

    (void)S12Crg_RTIEnabled(&flag);
    
    if (flag==FALSE) {
        return S12CRG_STATE;    
    }

    S12CRG_REG8(RTICTL)=((uint8)0x00);
    S12CRG_REG8(CRGINT)&=~RTIE;
    S12CRG_REG8(CRGFLG)=RTIF;
    
    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_SetRTIRate(uint8 rate)
{
    boolean flag;

    (void)S12Crg_RTIEnabled(&flag);
    
    if (flag==TRUE) {
        return S12CRG_STATE;    
    }
    
    S12CRG_REG8(RTICTL)=rate;

    return S12CRG_OK;        
}


S12Crg_StatusType S12Crg_RTIEnabled(boolean *flag)
{
    *flag=(S12CRG_REG8(CRGINT) & RTIE)==RTIE;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_TriggerWDG(void)
{
    S12CRG_REG8(ARMCOP)=(uint8)0x55;
    S12CRG_REG8(ARMCOP)=(uint8)0xaa;;

    return S12CRG_OK;
}


S12Crg_StatusType S12Crg_ResetMCU(void)
{

    if (!(S12CRG_REG8(COPCTL) & (CR2|CR1|CR0))) {
        S12CRG_REG8(COPCTL)=(RSBCK|CR0);    /* Enable COP if disabled.                      */
    }    
    S12CRG_REG8(ARMCOP)=(uint8)0xcc;        /* Write garbage to 'ARMCOP' ==> instant RESET. */
    
    return S12CRG_OK;                       /* never reached...                             */
}


/*
**
**  todo:   den Vektoren mit 'S12CRG_USE_RTI_VECTOR' aktivieren !!!
**          das ganze Allgemein verwenden: !!!S12mod_USE_xxx_VECTOR' !!!
**
*/

ISR1(RTI_Vector)
{
    static uint32 cnt;
    
    S12CRG_REG8(CRGFLG)=RTIF;
    
    cnt++;
}

