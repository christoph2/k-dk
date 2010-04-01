/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2009 by Christoph Schueler <chris@konnex-tools.de,
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

/*
**
**  CAN Calibration Protocol.
**
*/

/*
**  Command Codes.
*/
/*  Command                     Code                TimeOut     Remark              */
/*                                                  to ACK [ms]                     */
#define CCP_CONNECT             ((uint8)0x01)   /*  25                              */
#define CCP_GET_CCP_VERSION     ((uint8)0x1B)   /*  25                              */
#define CCP_EXCHANGE_ID         ((uint8)0x17)   /*  25                              */
#define CCP_GET_SEED            ((uint8)0x12)   /*  25          optional command    */
#define CCP_UNLOCK              ((uint8)0x13)   /*  25          optional command    */
#define CCP_SET_MTA             ((uint8)0x02)   /*  25                              */
#define CCP_DNLOAD              ((uint8)0x03)   /*  25                              */
#define CCP_DNLOAD_6            ((uint8)0x23)   /*  25          optional command    */
#define CCP_UPLOAD              ((uint8)0x04)   /*  25                              */
#define CCP_SHORT_UP            ((uint8)0x0F)   /*  25          optional command    */
#define CCP_SELECT_CAL_PAGE     ((uint8)0x11)   /*  25          optional command    */
#define CCP_GET_DAQ_SIZE        ((uint8)0x14)   /*  25                              */
#define CCP_SET_DAQ_PTR         ((uint8)0x15)   /*  25                              */
#define CCP_WRITE_DAQ           ((uint8)0x16)   /*  25                              */
#define CCP_START_STOP          ((uint8)0x06)   /*  25                              */
#define CCP_DISCONNECT          ((uint8)0x07)   /*  25                              */
#define CCP_SET_S_STATUS        ((uint8)0x0C)   /*  25          optional command    */
#define CCP_GET_S_STATUS        ((uint8)0x0D)   /*  25          optional command    */
#define CCP_BUILD_CHKSUM        ((uint8)0x0E)   /*  30000       optional command    */
#define CCP_CLEAR_MEMORY        ((uint8)0x10)   /*  30000       optional command    */
#define CCP_PROGRAM             ((uint8)0x18)   /*  100         optional command    */
#define CCP_PROGRAM_6           ((uint8)0x22)   /*  100         optional command    */
#define CCP_MOVE                ((uint8)0x19)   /*  30000       optional command    */
#define CCP_TEST                ((uint8)0x05)   /*  25          optional command    */
#define CCP_GET_ACTIVE_CAL_PAGE ((uint8)0x09)   /*  25          optional command    */
#define CCP_START_STOP_ALL      ((uint8)0x08)   /*  25          optional command    */
#define CCP_DIAG_SERVICE        ((uint8)0x20)   /*  500         optional command    */
#define CCP_ACTION_SERVICE      ((uint8)0x21)   /*  5000        optional command    */
/*
**    The following comands are optional, if the ECU does not support DAQ:
**    GET_DAQ_SIZE,
**    SET_DAQ_PTR,
**    WRITE_DAQ,
**    START_STOP.
**    If SELECT_CAL_PAGE is implemented, GET_ACTIVE_CAL_PAGE is required.
*/

/*
**  Command Return Codes.
*/
#if
/*  Code    Description                         Error       State transition to */
/*                                              category                        */
0x00        acknowledge / no error              -
0x01        DAQ processor overload              C0
0x10        command processor busy              C1          NONE (wait until ACK or timeout)
0x11        DAQ processor busy                  C1          NONE (wait until ACK or timeout)
0x12        internal timeout                    C1          NONE (wait until ACK or timeout)
0x18        key request                         C1          NONE (embedded seed&key)
0x19        session status request              C1          NONE (embedded SET_S_STATUS)
0x20        cold start request                  C2          COLD START
0x21        cal. data init. request             C2          cal. data initialization
0x22        DAQ list init. request              C2          DAQ list initialization
0x23        code update request                 C2          (COLD START)
0x30        unknown command                     C3          (FAULT)
0x31        command syntax                      C3          FAULT
0x32        parameter(s) out of range           C3          FAULT
0x33        access denied                       C3          FAULT
0x34        overload                            C3          FAULT
0x35        access locked                       C3          FAULT
0x36        resource/function not available     C3          FAULT
#endif

/*
**    If errors occur asynchroneously to protocol commands, the CCP slave device may also
**    directly invoke appropriate error handling by sending error codes as Event Messages
**    (Packet ID 0xFE).
*/
#if 0
Category    Description                         Action          Retries
=========================================================================
timeout     no handshake message                retry                   2
C0          warning                             -                       -
C1          spurious (comm error, busy, ...)    wait (ACK or timeout)   2
C2          resolvable (temp. power loss, ...)  reinitialize            1
C3          unresolvable (setup, overload, ...) terminate               -
#endif
