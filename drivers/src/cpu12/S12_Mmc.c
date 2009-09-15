
#include "S12_Mmc.h"
#include "Hw_Cfg.h"

S12Mmc_StatusType S12Mmc_Init(void)
{
    BYTE_REG(0x00,INITRG)=MMC.InitRG; /* must use default address of 'INITRG' !!! */
    
    S12MMC_REG8(INITRM)=MMC.InitRM;
    S12MMC_REG8(INITEE)=MMC.InitEE;
    S12MMC_REG8(MISC)=MMC.Misc;
    
    return S12MMC_OK;
}

S12Mmc_StatusType S12Mmc_SetPPage(uint8 ppage)
{
    S12MMC_REG8(PPAGE)=ppage;

    return S12MMC_OK;    
}


S12Mmc_StatusType S12Mmc_GetPPage(uint8 *ppage)
{
    *ppage=S12MMC_REG8(PPAGE);

    return S12MMC_OK;    
}
