

#include "Bitbus.h"

BBHANDLE Bitbus_OpenMaster(const char *AppName,const char *BitbusDevice,const BitbusOpenData *pData)
{
    return (BBHANDLE)0;
}

BBHANDLE Bitbus_OpenSlave (const char *AppName,const char *BitbusDevice,uint8 TaskId,uint8 FunctionId,BitbusOpenData *pData)
{
    return (BBHANDLE)0;    
}


sint32 Bitbus_Close(BBHANDLE hdl)
{
    return (sint32)0;
}


sint32 Bitbus_SendMsg(BBHANDLE hdl,pBitbusMsg pMsg)
{
    return (sint32)0;
}

sint32 Bitbus_WaitMsg(BBHANDLE hdl,pBitbusMsg pMsg,sint32 tout)
{
    return (sint32)0;
}


sint32 Bitbus_Reset(BBHANDLE hdl,uint8 node)
{
    return (sint32)0;
}

sint32 Bitbus_GetMsgLength(BBHANDLE hdl,uint8 node)
{
    return (sint32)0;
}

sint32 Bitbus_GetMsgCnt(BBHANDLE hdl,uint16 scope)
{
    return (sint32)0;
}

sint32 Bitbus_GetAppNames(BBHANDLE hdl,char *buffer,uint16 length)
{
    return (sint32)0;
}






void Bitbus_RxHandler(void)
{
    
}
