/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
 *                                      cpu12.gems@googlemail.com>
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
 * s. FLOSS-EXCEPTION.txt
 *
 */

/*
**
**  Wrapper for WinSock2 communication.
**
*/

#define _WIN32_WINNT 0x0601
#include <malloc.h>
#include <stdio.h>
#include <process.h>
#include <WinSock2.h>

#include "kdk/win/Com_WinSock.h"
#include "kdk/win/Win_Error.h"

#define WS_VERSION_REQUESTED    MAKEWORD(2, 2)
#define COMM_BUFFER_SIZE    (512)

typedef void (__cdecl * Win_ThreadFunc) (void *);

static void __cdecl ComWinsock_ClientThread(ComWinSock_Type * com);


boolean ComWinsock_InitWinsock(void)
{
    int result;
    WSADATA winsockData;

    result = WSAStartup(MAKEWORD(2, 2), &winsockData);
    if (result != 0) {
      printf("WSAStartup failed with error %d\n", result);
      return FALSE;
    }

    if (winsockData.wHighVersion > WS_VERSION_REQUESTED) {
        printf("NOTE: A higher Winsock version (%u) then the requested one (%u) is available.\n", winsockData.wHighVersion, WS_VERSION_REQUESTED);
    }
    return TRUE;
}

boolean ComWinsock_DeinitWinsock(void)
{
    int result;

    result = WSACleanup();
    if (result == SOCKET_ERROR) {
        Win_Error("ComWinsock_DeinitWinsock");
        return FALSE;
    }
    
    return TRUE;
}

boolean ComWinsock_CloseSocket(ComWinsock_SocketType so)
{
    int result;

    result = closesocket(so);
    if (result == SOCKET_ERROR) {
        Win_Error("ComWinsock_CloseSocket");
        return FALSE;
    }
    
    return TRUE;
}

boolean ComWinsock_ReuseSocket(ComWinsock_SocketType so)
{
    int i = 1;
    int result;

    result = setsockopt(so, SOL_SOCKET, SO_REUSEADDR, (const char *)&i, sizeof(i));
    if  (result == SOCKET_ERROR) {
        Win_Error("SOCKET_ERROR");
        return FALSE;
    }
    return TRUE;
}

#define BUF_SIZE    128


boolean ComWinsock_SetBlocking(ComWinsock_SocketType so, boolean on)
{
    int result;
    unsigned long argp = on ? 0 : 1;

    result = ioctlsocket(so, FIONBIO, (unsigned long *) &argp);
    if (result == SOCKET_ERROR) {
        Win_Error("ComWinsock_SetBlocking");
        return FALSE;
    }

    return TRUE;
}


boolean ComWinsock_Receive(ComWinsock_SocketType so, char * buffer)    /* TODO: Return nbytes !? */
{
    int result;
    boolean ret = TRUE;
    int nbytes;

    ComWinsock_SetBlocking(so, FALSE);
    nbytes = recv(so, (char*)&buffer, BUF_SIZE, 0);
    if (nbytes == SOCKET_ERROR) {
        result = WSAGetLastError();
        if (result != WSAEWOULDBLOCK) {
            Win_Error("ComWinsock_Receive");   /* TODO: Call error hook. */
        }
        ret = FALSE;
    } else {
        buffer[nbytes] = '\0';
        printf("Received: %s\n", buffer);
    }
    ComWinsock_SetBlocking(so, TRUE);
    return ret;
}

ComWinsock_SocketType ComWinsock_CreateTCPSocket(void)
{
    ComWinsock_SocketType socket;
    socket = WSASocket(AF_INET, SOCK_STREAM, IPPROTO_TCP, NULL, 0,0);
    if (socket == SOCKET_ERROR) {
        Win_Error("ComWinsock_CreateTCPSocket");
        return (ComWinsock_SocketType)NULL;
    }
    return socket;
}

boolean ComWinsock_ConnectSocket(ComWinsock_SocketType so, char const * serverAddress, unsigned short serverPort)
{
    SOCKADDR_IN addr;
    int result;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(serverPort);
    addr.sin_addr.s_addr = inet_addr(serverAddress);

    result = connect(so, (const struct sockaddr *)&addr, sizeof(SOCKADDR_IN));
    if (result == SOCKET_ERROR) {
        Win_Error("ComWinsock_ConnectSocket");    // Typical Errors: WSAECONNREFUSED (i.e. no server listening) and WSAETIMEDOUT.
        return FALSE;
    }
    return TRUE;
}

boolean ComWinsock_BindSocket(ComWinsock_SocketType so, unsigned short port)
{
    SOCKADDR_IN addr;
    int res;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);    
    addr.sin_addr.s_addr = htonl(INADDR_ANY);   /* TODO: Parameter! */

    res = bind(so, (SOCKADDR *)&addr, sizeof(addr));
    if (res == SOCKET_ERROR) {
        Win_Error("ComWinsock_BindSocket");
        return FALSE;
    }
    return TRUE;
}

boolean ComWinsock_ListenSocket(ComWinsock_SocketType so, unsigned short queueLength)
{
    int res;

    res = listen(so, queueLength);

    if (res == SOCKET_ERROR) {
        Win_Error("ComWinsock_ListenSocket");
        return FALSE;
    }

    return TRUE;
}

ComWinsock_SocketType ComWinsock_AcceptSocket(ComWinsock_SocketType so)   /* TODO: returns bool!!! */
{
    int res;
    ComWinsock_SocketType peerSocket;
    SOCKADDR_IN clientAddr;
    int addrLen;

    addrLen = sizeof(SOCKADDR_IN);
    peerSocket = accept(so, (SOCKADDR *)&clientAddr, &addrLen);

    if (peerSocket == INVALID_SOCKET) {
        Win_Error("ComWinsock_AcceptSocket");
        return (ComWinsock_SocketType)NULL;
    }

    return peerSocket;
}

boolean ComWinsock_EventSelect(ComWinsock_SocketType so, ComWinsock_HandleType eventObject, unsigned long eventMask)
{
/*
    Events: FD_READ, FD_WRITE , FD_OOB, FD_ACCEPT, FD_CONNECT, FD_CLOSE, FD_QOS, FD_GROUP_QOS,FD_ROUTING_INTERFACE_CHANGE, FD_ADDRESS_LIST_CHANGE
*/
    int result;

    result = WSAEventSelect(so, eventObject, eventMask);
    if (result == SOCKET_ERROR) {
        Win_Error("WSAEventSelect");
        return FALSE;
    }
    return TRUE;
}

boolean ComWinsock_StartClient(ComWinSock_Type * com)
{
    int idx;

    for (idx = 0; idx < CWS_NUM_CLIENT_EVENTS; ++idx) {
        com->waitEvents[idx] = WSACreateEvent();
    }

    com->socket = ComWinsock_CreateTCPSocket();
    if (!com->socket) {
        return FALSE;
    }

    if (!ComWinsock_ReuseSocket(com->socket)) {
        ComWinsock_CloseSocket(com->socket);
        return FALSE;
    }

    if (!ComWinsock_ConnectSocket(com->socket, com->serverAddress, com->serverPort)) {
        ComWinsock_CloseSocket(com->socket);
        return FALSE;
    }

    if (!ComWinsock_EventSelect(com->socket, com->waitEvents[CWS_EVT_RECEIVED], FD_READ | FD_CLOSE)) {
        ComWinsock_CloseSocket(com->socket);
        return FALSE;
    }

    com->hReceiverThread = (HANDLE)_beginthread((Win_ThreadFunc)&ComWinsock_ClientThread, 0, (void*)com);

    return TRUE;
}

void ComWinsock_StopClient(ComWinSock_Type * com)
{
    int result;
    int idx;

    WSASetEvent(com->waitEvents[CWS_EVT_QUIT]);
    WaitForSingleObject(com->hReceiverThread, 5000);

    for (idx = 0; idx < CWS_NUM_CLIENT_EVENTS; ++idx) {
        WSACloseEvent(com->waitEvents[idx]);
    }
    //result = shutdown(vbus->socket, SD_BOTH);
    ComWinsock_CloseSocket(com->socket);
}

boolean ComWinsock_StartServer(void)
{
    ComWinsock_SocketType so;

    so = ComWinsock_CreateTCPSocket();
    if (!so) {
        return FALSE;
    }

    if (!ComWinsock_ReuseSocket(so)) {
        ComWinsock_CloseSocket(so);
        return FALSE;
    }

    if (!ComWinsock_BindSocket(so, 42244)) {
        return FALSE;
    }

    if (!ComWinsock_ListenSocket(so, 1)) {
        return FALSE;
    }

    if (!ComWinsock_AcceptSocket(so)) {
        return FALSE;
    }

    return TRUE;
}

//////////////////////////
//////////////////////////
//////////////////////////

static void __cdecl ComWinsock_ClientThread(ComWinSock_Type * com)
{
    DWORD index;
    DWORD result;
    char buffer[COMM_BUFFER_SIZE];
    WSANETWORKEVENTS networkEvents;
    WSAEVENT eventObject;

    while (1) {
        result = WSAWaitForMultipleEvents(CWS_NUM_CLIENT_EVENTS, com->waitEvents, FALSE, WSA_INFINITE, FALSE/*TRUE*/);
        if ((result != WSA_WAIT_FAILED) && (result != WSA_WAIT_TIMEOUT)) {
            index = result - WSA_WAIT_EVENT_0;
            printf("WaitEvent [%u]\n", index);
            eventObject = com->waitEvents[index];

            if (index == CWS_EVT_QUIT) {
                printf("Finishing thread.\n");
                _endthread();
                break;
            }

            result = WSAEnumNetworkEvents(com->socket, eventObject, &networkEvents);
            printf("Network-Event: [%u]\n", networkEvents.lNetworkEvents);
            if (result == SOCKET_ERROR) {
                Win_Error("ComWinsock_ClientThread/WSAEnumNetworkEvents");
            }
            if ((networkEvents.lNetworkEvents & FD_CLOSE) == FD_CLOSE) {
                if (networkEvents.iErrorCode[FD_CLOSE_BIT] != 0) {
                    printf("FD_CLOSE failed with error %d\n", networkEvents.iErrorCode[FD_CLOSE_BIT]);
                } else {
                    printf("FD_CLOSE\n");
                }
                _endthread();
                break;
            }
            if ((networkEvents.lNetworkEvents & FD_READ) == FD_READ) {
                if (networkEvents.iErrorCode[FD_READ_BIT] != 0) {
                    printf("FD_READ failed with error %d\n", networkEvents.iErrorCode[FD_READ_BIT]);
                } else {
                    printf("FD_READ\n");
                    result = recv(com->socket, buffer, COMM_BUFFER_SIZE, 0);
                    if (result == SOCKET_ERROR) { 
                        Win_Error("recv");
                    } else {
                        buffer[result] = '\0';
                        printf("Received: %s\n", buffer);
                        com->callback((char*)&buffer, result);
                    }

                }
            }
            if (!WSAResetEvent(eventObject)) {
                Win_Error("ComWinsock_ClientThread/WSAResetEvent");
            }

     } else {
            Win_Error("ComWinsock_ClientThread/WSAWaitForMultipleEvents");
        }
    }
}
