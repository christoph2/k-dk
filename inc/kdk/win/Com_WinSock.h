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
 */
#if !defined(__COM_WINSOCK_H)
#define __COM_WINSOCK_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */

typedef unsigned short ComWinsock_SocketType;
typedef void * ComWinsock_HandleType;

#define CWS_EVT_RECEIVED        (0)
#define CWS_EVT_QUIT            (1)
#define CWS_EVT_CLIENT          (2)

#define CWS_NUM_CLIENT_EVENTS   (2)
#define CWS_NUM_SERVER_EVENTS   (3)

typedef boolean ( * ComWinsock_CallbackType)(char * buffer, ULONG len);

typedef struct tagComWinSock_ClientType {
    char serverAddress[128];
    USHORT serverPort;
    SOCKET socket;
    WSAEVENT waitEvents[CWS_NUM_CLIENT_EVENTS];
    HANDLE hReceiverThread;
    ComWinsock_CallbackType callback;
} ComWinSock_ClientType;

typedef struct tagComWinSock_ServerType {
    //char serverAddress[128];
    USHORT serverPort;
    SOCKET listenSocket;
    SOCKET clientSocket;
    WSAEVENT waitEvents[CWS_NUM_SERVER_EVENTS];
    HANDLE hReceiverThread;
    ComWinsock_CallbackType callback;
} ComWinSock_ServerType;

boolean ComWinsock_InitWinsock(void);
boolean ComWinsock_DeinitWinsock(void);
boolean ComWinsock_StartClient(ComWinSock_ClientType * com);
void ComWinsock_StopClient(ComWinSock_ClientType * com);

boolean ComWinsock_StartServer(ComWinSock_ServerType * com);
void ComWinsock_StopServer(ComWinSock_ServerType * com);

boolean ComWinsock_CloseSocket(ComWinsock_SocketType so);
ComWinsock_SocketType ComWinsock_CreateTCPSocket(void);
boolean ComWinsock_ReuseSocket(ComWinsock_SocketType so);
boolean ComWinsock_SetBlocking(ComWinsock_SocketType so, boolean on);
boolean ComWinsock_EventSelect(ComWinsock_SocketType so, ComWinsock_HandleType eventObject, unsigned long eventMask);
boolean ComWinsock_ConnectSocket(ComWinsock_SocketType so, char const * serverAddress, unsigned short serverPort);
boolean ComWinsock_BindSocket(ComWinsock_SocketType so, unsigned short port);
boolean ComWinsock_ListenSocket(ComWinsock_SocketType so, unsigned short queueLength);
ComWinsock_SocketType ComWinsock_AcceptSocket(ComWinsock_SocketType so);

boolean ComWinsock_Receive(ComWinsock_SocketType so, char * buffer);

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /* __COM_WINSOCK_H */
