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

#include "IsoTp.h"

#define CAN_VENDOR_ID 1
#define CAN_MODULE_ID 80
#define CAN_AR_MAJOR_VERSION 1
#define CAN_AR_MINOR_VERSION 0
#define CAN_AR_PATCH_VERSION 0
#define CAN_SW_MAJOR_VERSION 1
#define CAN_SW_MINOR_VERSION 0
#define CAN_SW_PATCH_VERSION 0


#define ISOTP_TA_TYPE_PHYSICAL      ((uint8)0xda)    /* 218d */
#define ISOTP_TA_TYPE_FUNCTIONAL    ((uint8)0xdb)    /* 219d */

#if 0

CAN 29Bit-Identifier
====================

Normal fixed format:
--------------------

                2                   1                   0
8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
 PR  |   |  PDU-FORMAT   |     N_TA      |     N_SA      |
         |  <--  N_AI (Network Address Information) -->  |
#endif

/*
**  'N_AI' + 'N_PCI' constitutes the N_SDU (???)
*/


/*
**  todo: add support for OSEK-Events!!!
*/

/*
**  MType (Message-Type): 'diagnostics', 'remote diagnostics'.
*/

/*
**  Hinweis: der CAN-Buffer-Type gilt generell (s. AR-CAN-Driver) !!!
*/
#define CAN_MAX_LSDU_LEN    ((uint8)0x08)

typedef uint8 Can_SDUType[CAN_MAX_LSDU_LEN];

typedef struct tagCan_MessageType { /* besser: L-PDU!?  */
    uint32 ID;
    boolean ExtendedID;
    boolean RTR;    /* not used be AR-CAN-Driver.   */
    uint8 DLR;
    Can_SDUType LSDU;
} Can_MessageType;
/*
***************************************************
*/

#if 0
TA_Type ==> die drei MSBs der CAN-ID... ist die Priorität!!!
#endif

#if 0
    10.3.2 Network layer service parameter

    10.3.2.1 General
        This subclause specifies the network layer service parameters used for diagnostic communication.

    10.3.2.2 Message type (MTYPE)
        The parameter MTYPE identifies the message data content and address format. For the diagnostic
        communication between road vehicles and their towed vehicles the MTYPE parameter shall be coded by
        means of diagnostic communication channels (see 10.2.6).

        MTYPE = <Remote Diagnostics>

    10.3.2.3 Network layer address information (N_AI)


    10.3.2.3.1 General
        The network layer address information N_AI shall be a data record which consists of the following parameters.

        N_AI: Record = {
            <N_TAtype>;
            <N_TA>;
            <N_SA>;
            <N_AE>
        }

    10.3.2.3.2 Network layer target address type (N_TAtype)
        This parameter contains the message priority, the message data content, the target address type and the
        address type of the network layer address extension AN_AE in the case that it represents a target address
        extension.

        N_TAtype: Record = {
            <Priority>;
            <ReservedBit>;
            <DataPage>;
            <PDUFormat>
        }

    10.3.2.3.2.1 Priority (PRIO)
        The priority shall be used to optimize the message latency time.

        PRIO: 3 Bit = 7

    10.3.2.3.2.2 Reserved bit (RES)
        This bit is reserved for future expansion.

        RES: 1 Bit = 0

    10.3.2.3.2.3 Data page (DP)
        The data page (DP) identifies together with the PDUFormat parameter the message data content.

        DP: 1 Bit = 0

    10.3.2.3.2.4 PDU format (PF)
        The PDU format (PF) parameter determines together with the data page information (DP) the PDU format, the
        message data content, the target address type and the address type of the address extension in the case that
        N_AE represents a target address extension.

        PF: 8 Bit = { 206(10) | 205(10) }
        206(10) = PDU1 (PS=DA); Diagnostic Message; Mixed addressing; Physical target addresses.
        205(10) = PDU1 (PS=DA); Diagnostic Message; Mixed addressing; Functional target addresses.

    10.3.2.3.3 Network layer target address (N_TA)
        The network layer target address N_TA represents the target address of the message receiver. The
        parameter shall correspond to the destination address DA of the ISO 11992 identifier definition.

        N_TA: 8 Bit = {
            <Towed vehicle target address>|
            <Towing vehicle client target address>|
            <Towing vehicle server target address>
        }

    10.3.2.3.4 Network layer source address (N_SA)
        The network layer source address N_SA represents the source address of the message sender. This
        parameter shall correspond to the source address SA of the ISO 11992 identifier definition.

        N_SA: 8 Bit = {
            <Towed vehicle source address>|
            <Towing vehicle client source address>|
            <Towing vehicle server source address>
        }

    10.3.2.3.5 Network layer address extension (N_AE)
        The network layer address extension N_AE represents a client or server local address on the towed vehicle
        local network.
        Whether N_AE represents a target or source address is specified by means of diagnostic communication
        channels (see 10.2.6).

        N_AE: 8 Bit = { <TargetAddressExtension> | <SourceAddressExtension> }

    10.3.2.4 Message data (A_DATA)
        The MessageData represents the data record which shall be transmitted.

        MessageData: Record = {<A_DATA>}

    10.3.2.5 Message length (Length)
        The parameter Length identifies the number of message data bytes. The maximum length allowed is 255(10)
        bytes.

        Length = { <N>; 0 <= N <= 255(10)}

        NOTE The USDT protocol allows a maximum of 4095(10) MessageData bytes. For the diagnostic communication
        between towing and towed vehicles, the length is limited to 255(10) bytes.


    10.3.2.6 Network layer service request result (N_Result)
        N_Result is an internal network layer parameter which identifies the result of a service request or indication.

        N_Result = {
            N_OK                |
            N_TIMEOUT_A         |
            N_TIMEOUT_Bs        |
            N_TIMEOUT_Cr        |
            N_WRONG_SN          |
            N_INVALID_FS        |
            N_UNEXP_PDU         |
            N_WFT_OVRN          |
            N_BUFFER_OVFLW      |
            N_UNEXPECTED_DLC    |
            N_ERROR
        }

    where

    N_OK:               The service execution has completed successfully.
    N_TIMEOUT_A:        Timer N_Ar/N_As has passed its timeout value N_Asmax/N_Armax.
    N_TIMEOUT_Bs:       Timer N_Bs has passed its timeout value N_Bsmax.
    N_TIMEOUT_Cr:       The timer N_Cr has passed its timeout value N_Crmax.
    N_WRONG_SN:         Reception of an unexpected sequence number (PCI.SN) value.
    N_INVALID_FS:       Invalid or unknown FlowStatus value has been received in a flow control (FC N_PDU).
    N_UNEXP_PDU:        Reception of an unexpected protocol data unit.
    N_WFT_OVRN:         Reception of a flow control WAIT frame that exceeds the maximum counter N_WFTmax.
    N_BUFFER_OVFLW:     Reception of a flow control (FC) N_PDU with FlowStatus = OVFLW.
    N_UNEXPECTED_DLC:   N_PDU has been received with fewer CAN data bytes than expected.
    N_ERROR:            General error. An error has been detected by the network layer entity and no other
                        parameter value can be used to better describe the error.

    10.3.3 Network layer service data units (N_SDU)

    10.3.3.1 General
        The network layer service data units (N_SDU) have the following general format:

        <Service name>.<Service primitive> = {
            <MTYPE>
            <N_AI>
            <Service primitive parameter>
        }

    10.3.3.2 N_USData.Request service primitive
        The service primitive requests transmission of <MessageData> with <Length> bytes from the sender to the
        receiver peer entity identified by <N_AI>.

        N_USData.Request = {
            <MTYPE>;
            <N_AI>;
            <MessageData> ;
            <Length>;
        }

    10.3.3.3 N_USData.Confirmation service primitive
        The service primitive confirms the completion of a N_USData service request identified by <N_AI> parameter.
        The parameter <N_Result> provides the status of the service request.

        N_USData.Confirmation = {
            <MTYPE>;
            <N_AI>;
            <N_Result>;
        }

    10.3.3.4 N_USData_FF.Indication service primitive
        The service primitive indicates the reception of a first frame (FF) of a segmented message with <Length>
        bytes from a peer entity identified by <N_AI> to the adjacent upper layer.

        N_USData.Indication = {
            <MTYPE> ;
            <N_AI>;
            <Length>;
        }

    10.3.3.5 N_USData.Indication service primitive
        The service primitive indicates <N_Result> events and delivers <MessageData> with <Length> bytes received
        from a peer entity identified by <N_AI> to the adjacent upper layer.

        N_USData.Indication = {
            <MTYPE> ;
            <N_AI>;
            <MessageData>;
            <Length>;
            <N_Result>
        }


    10.4 Network layer protocol

    10.4.1 General
        The network layer protocol describes the communication between peer network layer entities on a data link
        between a towed and a towing vehicle.

    10.4.2 Network layer protocol parameter

    10.4.2.1 Network layer protocol address information (N_AI)
        The network layer protocol address information N_AI shall correspond to the respective network layer address
        information.

    10.4.2.2 Network layer protocol control information (N_PCI)

    10.4.2.2.1 General
        The network layer protocol control information N_PCI shall be used in the network layer PDU. It encodes the
        network layer PDU type and network layer protocol control information.

        N_PCI = {
            <SingleFrame PCI>|
            <FirstFrame PCI>|
            <ConsecutiveFrame PCI>|
            <FlowControl PCI>
        }

        The encoding of the network layer protocol information N_PCI shall be as shown in Table 31.
        Table 31 — Encoding of network layer protocol control information

        Protocol control information (N_PCI) N_PCI
        Byte #1
        PCI name Mnemonic 7 6 5 4 3 2 1 0
        Byte #2 Byte #3
        SingleFrame PCI SF_PCI 0 0 0 0 SF.DL – –
        FF.DL –
        FirstFrame PCI FF_PCI 0 0 0 1
        high nibble low byte –
        ConsecutiveFrame PCI CF_PCI 0 0 1 0 SN – –
        FlowControl PCI FC_PCI 0 0 1 1 FS BS STmin
        ReservedByDocument RBD 40(16) to FF(16) reserved reserved

    10.4.2.2.2 SingleFrame.DataLength (SF.DL)
        The parameter SingleFrame.DataLength (SF.DL) determines the number of valid message data bytes of a
        single frame message.

        SF.DL: 4 bit = { 1 u <N> u 6(10) }

        NOTE The network layer protocol using the mixed address format allows a maximum of six (6) MessageData bytes in
        a single frame message.

    10.4.2.2.3 FirstFrame.DataLength (FF.DL)
        The parameter FirstFrame.DataLength (FF.DL) determines the number of message data bytes of a
        segmented multi frame message.

        FF.DL: 8 bit = { 7(10) u <N> u 255(10})

        NOTE The USDT protocol allows a maximum of 4095(10) MessageData bytes. For the diagnostic communication
        between towing and towed vehicles the length is limited to 255(10) bytes.

    10.4.2.2.4 SequenceNumber (SN)
        The parameter SequenceNumber (SN) shall be used to check the sequence of consecutive frames in a
        segmented transmission. The SequenceNumber shall be set to one for the first consecutive frame of a
        segmented transmission and shall be incremented by one for each following consecutive frame. After the
        SequenceNumber reaches the value of fifteen, it shall be set to zero for the next consecutive frame.

        SN: 4 bit = 0 ... 15(10)

    10.4.2.2.5 BlockSize (BS)
        The parameter BlockSize (BS) shall be used by the receiving network layer peer entity in the flow control
        frame to request the transmission of a maximum number of consecutive frames by the sending network layer
        peer entity without an intermediate flow control frame.

        BS: 8 bit = 1(10) ... 15(10)

        The value BS = 0, i.e. no intermediate flow control frames, shall not be used.

    10.4.2.2.6 SeparationTime (STmin)
        The parameter SeparationTime (STmin) shall be used by the receiving network layer peer entity in the flow
        control frame to request a minimum time gap between the transmission of consecutive frames from the
        sending network layer peer entity.

        STmin: 8 bit = 10(10) ms to 127(10) ms

    10.4.2.2.7 FlowStatus (FS)
        The FlowStatus (FS) shall be used by the receiving network layer peer entity in the FlowControl frame to
        indicate to the sender whether it is ready to receive <BS> consecutive frames sent with <ST> separation time.

        FS: 4 bit = {
            <ContinueToSend>|
            <Wait>|
            <Overflow>
        }

        ContinueToSend = CTS = 0000(2)
        Wait = WT = 0001(2)
        Overflow = OVFLW = 0010(2)

        BS and STmin transmitted with the first flow control frame shall be valid during the transmission of the whole
        message.


    10.4.2.2.8 Network layer protocol data (N_DATA)
        The network layer parameter N_DATA contains the segments of the message data record.

        N_DATA = { < record of <N> MessageData bytes >; 1 u N u 6(10) }

        NOTE For diagnostic communication between towing and towed vehicles this data record corresponds to the
        segmented application layer parameter ServiceIdentifier and ServiceParameter (A_DATA).

    10.4.2.3 Maximum number of FC.Wait frame transmissions (N_WFTmax)
        The local entity parameter maximum number of FC.Wait frame transmissions N_WFTmax defines the allowed
        maximum number of consecutive FlowControl frames with FlowStatus set to Wait.

        N_WFTmax = 10(10)

    10.4.3 Network layer protocol data units (N_PDU)

    10.4.3.1 General
        Four different network layer protocol data units (N_PDU) are specified which correspond to the
        MixedAddressFormat:

        N_PDU = {
            <SingleFrame>       |
            <FirstFrame>        |
            <ConsecutiveFrame>  |
            <FlowControl>
        }

    10.4.3.2 SingleFrame N_PDU
        Unsegmented single frame message with up to six message data bytes.

        SingleFrame = {
            <N_AI>;
            <SingleFrame PCI>;
        <N_DATA>
    }

    10.4.3.3 FirstFrame N_PDU
        First frame of a segmented message transmission with a message length from 710 up to 25510 message data
        bytes.

        FirstFrame = {
            <N_AI>;
            <FirstFrame PCI>;
            <N_DATA>
        }

    10.4.3.4 ConsecutiveFrame N_PDU
        Consecutive frame of a segmented transmission.

        ConsecutiveFrame = {
            <N_AI>;
            <ConsecutiveFrame PCI>;
            <N_DATA>
        }

    10.4.3.5 FlowControl N_PDU
        Flow control frames are sent by the message receiver to control the transmission of consecutive frames sent
        by the message transmitter.

        FlowControlFrame = {
            <N_AI>;
        <FlowControlFrame PCI>
    }
#endif

#if 0
=====================================================================================================
Table 32 — Network layer timing values
=====================================================================================================
Name    Description
=====================================================================================================
N_As    Transmission delay time of a N_PDU frame on the sender side                     min. 0
                                                                                        max. 100 ms
N_Ar    Transmission delay time of a N_PDU frame on the receiver side                   min. 0
                                                                                        max. 100 ms
N_Bs    Time between transmission of a FirstFrame or ConsecutiveFrame and reception of  min. 0
        a FlowControlFrame or time between two consecutive FlowControlFrames.           max. 150 ms
N_Br    Time between reception of a FirstFrame or ConsecutiveFrame and transmission     min. 0
        request of a FlowControlFrame.                                                  max. 35 ms(a)
N_Cs    Time between reception of a FlowControlFrame or transmission of a               min. 0
        ConsecutiveFrame and transmission request of next ConsecutiveFrame              max. 35 ms(b)
N_Cr    Time between transmission of a FlowControlFrame or reception of a               min. 0
        ConsecutiveFrame and reception of a ConsecutiveFrame                            max. 150 ms
=====================================================================================================
    (a) Sender internal performance requirement (N_Brmax + N_Armax) < (0.9 × N_Bsmax)
    (b) Receiver internal performance requirement (N_Csmax + N_Asmax) < (0.9 × N_Crmax)
=====================================================================================================

=====================================================================================================
Table 33 — Network layer time outs
=====================================================================================================
Name    Time out    Description
=====================================================================================================
NSTO1   N_As max    N_PDU transmission failed on sender side
NRTO1   N_Ar max    N_PDU transmission failed on receiver side
NSTO2   N_Bs max    FlowControlFrame not received on sender side
NRTO2   N_Cr max    ConsecutiveFrame not received on receiver side
=====================================================================================================
#endif

typedef enum tagState {
    IDLE,
    FIRST,
    CONS,
    FLOW_CONTROL
} State;

struct Connection {
    State state;
};

void IsoTp_DecodeFrame(Can_MessageType *Frame);


typedef enum tagIsoTp_FlowStatusType {
    FC_CTS,     /* FLOW_STATE CLEAR_TO_SEND -- FS_CTS */
    FC_WAIT,    /* WAIT     -- FS_WAIT  */
    FC_OVFLW    /* OVERFLOW -- FS_OVFLW */
#if 0
    /* Flexray  */
    FS_CNLDO,   /* Data Outdated - Abbruch wegen veralteter Daten.      */
    FS_CNLNB,   /* No Buffer - Abbruch, da kein Empfangspuffer frei.    */
    FS_CNLOR    /* Other Reason - Abbruch aus anderem Grund.            */
#endif
} IsoTp_FlowStatusType;

typedef struct tagIsoTp_FlowControlFrame {
    IsoTp_FlowStatusType status;
    uint8 block_size;
    uint8 st_min;
} IsoTp_FlowControlFrame;

typedef enum tagIsoTp_NCPI_Type {
    N_SINGLE_FRAME,
    N_FIRST_FRAME,
    N_CONSECUTIVE_FRAME,
    N_FLOW_CONTROL
} IsoTp_NCPI_Type;

typedef struct tagIsoTp_NPCI {
    IsoTp_NCPI_Type Type;

    union {
        uint8 data_length;          /* Single- and First-Frame. */
        uint8 sequence_number;      /* Consecutive Frame.       */
        IsoTp_FlowControlFrame fc;  /* Flow Control.            */
    };
} IsoTp_NPCI;


#if 0
/* Protocol Control Information:    */
FlowStatus:             enum    = {ContinueToSend,Wait}
SingleFrameDataLength:  4Bit    = 0..7
FirstFrameDataLength:   12Bit   = 8..4095 (0xfff)
SequenceNumber:         4Bit    = 0..15
BlockSize:              1Byte   = 0..255
SeperationTime:         1Byte   = 0..255
MaxFCWaitFrames:        1Byte   = 0..255
NCPI_Type:              s.o.
#endif

#if 0
/* Address Information:             */
NetworkSourceAddress:       1Byte   = 0..255
NetworkTargetAddress:       1Byte   = 0..255
NetworkTargetAddressType:   enum    = {physical,functional}
#endif


/* STmin-Calculation:   */
/************************************/
/* 0x00 - 0x7F : 0 - 127 ms         */
/* 0x80 - 0xF0 : reserved           */
/* 0xF1 - 0xF9 : 100 us - 900 us (in Hunderter Schritten)   */
/* 0xFA - 0xFF : reserved           */
/************************************/
#if 0
    i = frame.data[ext+2];
    printf("STmin: 0x%02X = ", i);

    if (i < 0x80)
        printf("%d ms", i);
    else if (i > 0xF0 && i < 0xFA)
        printf("%d us", (i & 0x0F) * 100);
    else
        printf("reserved");
#endif


#if 0
/*
**  =====================
**  ISO 15765-2 Parameter
**  =====================
*/
/*  Par.    Class   Description                                                                 Default Type    */
- Ar        Timing  Time for transmission of the CAN frame (any N_PDU) on the receiver side     1000000 ISO_15765_2.DOP_IDENTICAL_UNUM32_0__20000000
- As        Timing  Time for transmission of the CAN frame (any N_PDU) on the sender side       1000000 ISO_15765_2.DOP_IDENTICAL_UNUM32_0__20000000
- BlockSize Com     This sets the block size the interface should report to the vehicle for
                    receiving segmented transfers in a Transmit Flow Control Message.           0       ISO_15765_2.DOP_IDENTICAL_UNUM32_0_0xFF
- BlockSizeOverride
            Timing  This sets the block size the interface should use to send segmented
                    messages to the vehicle. The flow control value reported by the vehicle
                    should be ignored                                                           65535   ISO_15765_2.DOP_BlockSizeOverride
- Br
- Bs
#endif

void IsoTp_Init(void)
{

}

/* todo: Parameter 'TRUST_FILTERS' um den Dekodieraufwand bei den Identifiern zu reduzieren. */

/* 'put remaining bytes in first frame to have equal sized consecutive frames.' */

/* todo: L-SDU zum dekodieren verwenden, da sowohl 11- als auch 29-Bit Identifier verwendet werden!!! */

void IsoTp_DecodeFrame(Can_MessageType *Frame)
{
    uint8 sf_data_length;
    uint8 ff_data_length;
    uint8 sn;
    uint8 flow_status;
    uint8 block_size;
    uint8 st_min;

    switch (Frame->LSDU[0] & ((uint8)0xf0)) {
        case ISOTP_NPCI_TYPE_SF:  /* Single Frame.        */
            sf_data_length=Frame->LSDU[0] & ((uint8)0x0f);
            break;
        case ISOTP_NPCI_TYPE_FF:  /* First Frame.         */
            ff_data_length=((Frame->LSDU[0] & ((uint8)0x0f))<<8) | Frame->LSDU[1];
            break;
        case ISOTP_NPCI_TYPE_CF:  /* Consecutive Frame.   */
            sn=Frame->LSDU[0] & ((uint8)0x0f);
            break;
        case ISOTP_NPCI_TYPE_FC:  /* Flow Control.        */
            flow_status=Frame->LSDU[0] & ((uint8)0x0f);
            block_size=Frame->LSDU[1];
            st_min=Frame->LSDU[2];
            break;
        default:
            break;
    }
}

#if 0
N_USData.request
N_USDATA_FF.indication
N_USData.indication
N_USData.confirm    /* Request completed. */
=======================
N_ChangeParameter.request
N_ChangeParameter.confirm
#endif
