/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 */
#include "Bitbus.h"

BBHANDLE Bitbus_OpenMaster(const char * AppName, const char * BitbusDevice, const BitbusOpenData * pData)
{
    return (BBHANDLE)0;
}


BBHANDLE Bitbus_OpenSlave(const char * AppName, const char * BitbusDevice, uint8 TaskId, uint8 FunctionId, BitbusOpenData * pData)
{
    return (BBHANDLE)0;
}


sint32 Bitbus_Close(BBHANDLE hdl)
{
    return (sint32)0;
}


sint32 Bitbus_SendMsg(BBHANDLE hdl, pBitbusMsg pMsg)
{
    return (sint32)0;
}


sint32 Bitbus_WaitMsg(BBHANDLE hdl, pBitbusMsg pMsg, sint32 tout)
{
    return (sint32)0;
}


sint32 Bitbus_Reset(BBHANDLE hdl, uint8 node)
{
    return (sint32)0;
}


sint32 Bitbus_GetMsgLength(BBHANDLE hdl, uint8 node)
{
    return (sint32)0;
}


sint32 Bitbus_GetMsgCnt(BBHANDLE hdl, uint16 scope)
{
    return (sint32)0;
}


sint32 Bitbus_GetAppNames(BBHANDLE hdl, char * buffer, uint16 length)
{
    return (sint32)0;
}


void Bitbus_RxHandler(void)
{

}


