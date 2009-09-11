
#include "S12_Mmc.h"
#include "Hw_Cfg.h"

S12Mmc_StatusType S12Mmc_Init(void)
{
    BYTE_REG(0x00,INITRG)=MMC.InitRG; /* must use default address of 'INITRG' !!! */
    
    BYTE_REG(MMC.BaseAddr,INITRM)=MMC.InitRM;
    BYTE_REG(MMC.BaseAddr,INITEE)=MMC.InitEE;
    BYTE_REG(MMC.BaseAddr,MISC)=MMC.Misc;
    
    return S12MMC_OK;
}

S12Mmc_StatusType S12Mmc_SetPPage(uint8 ppage)
{
    BYTE_REG(MMC.BaseAddr,PPAGE)=ppage;

    return S12MMC_OK;    
}


S12Mmc_StatusType S12Mmc_GetPPage(uint8 *ppage)
{
    *ppage=BYTE_REG(MMC.BaseAddr,PPAGE);

    return S12MMC_OK;    
}
