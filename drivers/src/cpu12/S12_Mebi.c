
#include "S12_Mebi.h"
#include "Hw_Cfg.h"

/*
**  • Port A, B, E, and K related to the core logic and multiplexed bus interface
*/

S12Mebi_StatusType S12Mebi_GetMode(S12Mebi_ModeType *mode)
{
    *mode=(S12Mebi_ModeType)((S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5);

    return S12MEBI_OK;
}


S12Mebi_StatusType S12Mebi_SpecialMode(boolean *flag)
{
    uint8 mode=(S12MEBI_REG8(MODE) & (uint8)0xe0) >> 5;
    
    *flag=!(((mode & ((uint8)0x04))==((uint8)0x04)) && !((mode & ((uint8)0x06))==((uint8)0x06)));

    return S12MEBI_OK;
}
