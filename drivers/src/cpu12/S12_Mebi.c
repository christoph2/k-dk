
#include "S12_Mebi.h"
#include "Hw_Cfg.h"

S12Mebi_StatusType S12Mebi_GetMode(S12Mebi_ModeType *mode)
{
    *mode=(S12Mebi_ModeType)((BYTE_REG(MEBI.BaseAddr,MODE) & (uint8)0xe0) >> 5);

    return S12MEBI_OK;
}


S12Mebi_StatusType S12Mebi_NormalMode(boolean *flag)
{
    uint8 mode=(BYTE_REG(MEBI.BaseAddr,MODE) & (uint8)0xe0) >> 5;
    
    *flag=((mode & ((uint8)0x04))==((uint8)0x04)) && !((mode & ((uint8)0x06))==((uint8)0x06));

    return S12MEBI_OK;
}
