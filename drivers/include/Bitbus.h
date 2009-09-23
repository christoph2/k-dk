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
#if !defined(__BITSBUS_H)
#define __BITSBUS_H

#include "Std_Types.h"
#include "CPU_Primitives.h"

/*
**
**    - RAC is »remote access command« and the old style INTEL definition of the base
**    command set every BITBUS controller supports by TASK 0.
**
**    - GBS is »generic bus services« and the newer IEEE1118 definition of RAC. There are
**    more GBS than RAC commands, RAC is a subset of GBS. RAC definitions are provided
**    for compatibility only and should not be used in newer designs
**
*/

/*
**  global Types.
*/
typedef sint32 BBHANDLE; /* returned by BitbusOpen calls. */

typedef struct tagBitbusMsg {
    uint8 _res1;        /* PRIVATE VALUE */
    uint8 _res2;        /* PRIVATE VALUE */
    uint8 len;          /* 7 + LENGTH OF DATA FIELD */
    uint8 flags;        /* ROUTING BITS */
    uint8 node;         /* MASTER: SLAVE ADDRESS. */
                        /* SLAVE : NEVER TOUCH! */
    uint8 src_dest;     /* OWN/TARGET TASK NUMBER (0-15/0-15) */
    uint8 com_res;      /* REQUEST: GBS-/USER-COMMAND */
    uint8 data[248];    /* DATA FIELD */
    uint8 _res3;        /* PRIVATE VALUE */
} BitbusMsg;

typedef BitbusMsg *pBitbusMsg;

typedef struct tagGbsTime {
    uint8 zone;         /* TIME ZONE : 0 = GMT, 8 = PST */
    uint8 offset;       /* TIME OFFSET : 0..59 MINUTES */
    uint8 day_of_week;  /* 1..7, MONDAY = 1. */
    uint8 year;         /* 1980 = 0, 2235 = 255. */
    uint8 month;        /* 1..12, JANUARY = 1. */
    uint8 day;          /* 1..31. */
    uint8 hour;         /* 0..23. */
    uint8 min;          /* 0..59. */
    uint8 sec;          /* 0..59. */
} GbsTime;

typedef GbsTime *pGbsTime;

/* Implementation dependent types. */
/* These types maybe be defined and supplied by the BAPI implementor. */
typedef struct tagBitbusOpenData { /* Implementation-dependent; e.g. COM-Port. */
    sint32 dummy;
} BitbusOpenData;

typedef BitbusOpenData *pBitbusOpenData;

#if 0


/*
**  Special parameters and constants
*/
0x000 GBS_UNPROTECTED (RAC_UNPROTECTED)/*  Enable GBS/RAC access */
0x001 GBS_RW_PROTECTED (RAC_RW_PROTECTED) /* Disable GBS/RAC access */
0x002 GBS_WRITE_PROTECTED (RAC_WRITE_PROTECTED)/* Set GBS/RAC access to read-only. */

0x080 MT_FLAG   flags   
/*Message type. If set, the message is a response (a message
from slave to master). This field should be handled by BAPI
to prevent errors.
*/
0x040 SE_FLAG   flags 
/*
Source extension or 5th bit of source task number. Source
extension is used to route a BITBUS command message to a
host connected to a BITBUS master node (e.g. PC plug-in
board). This field should be handled by BAPI to prevent
errors.
*/
0x020 DE_FLAG   flags 
/*
Destination extension or 5th bit of destination task number.
Destination extension is used to route a BITBUS response
message to a host connected to a BITBUS slave node
*/
0x010 TR_FLAG   flags 
/*
Direction bit for host interface transfers.
*/
0x0F0 SRC_TSK   src_dest 
/*
Mask the source task number from the src_dest field. The
result must be shifted 4 times right to get a valid task
number. This field should be handled by BAPI to prevent
errors.
*/
0x00F DST_TSK   src_dest 
/*
Mask the destination task number from the src_dest field.
*/

/*
**  Error-Codes.
*/
0x000           GBS_OK, GBS_ERR_OK      All except GBS_CREATE 
/*
All works fine!
*/
0x01..0x1f      Task number, response   GBS_CREATE 
/*
The GBS_CREATE returns the task
number of the new created task in
com_res.
*/
0x20..0x7f      User defined errors 
/*
Reserved for user defined commands
*/
0x080           GBS_ERR_NO_DEST_TASK    ALL incl. non-GBS tasks 
/*
This error can have two sources:
If a message is send to a task that does
not exist, the link layer will answer the
message signalling this error.
If a GBS/RAC command uses an task
number as an parameter (e.g.
GBS_DELETE), this error is returned if the
requested task does not exist.
*/
0x081           GBS_ERR_TASK_OVFL       GBS_CREATE 
/*
If no more tasks can be created by the
OS, this error is replied.
*/

0x082           GBS_ERR_REGISTER_OVFL   GBS_CREATE 
/*
If no more tasks can be created because
of a lack of register sets.
*/
0x083           GBS_ERR_DUPLICATE_FID   GBS_CREATE 
/*
If there is already another task running
with the same FID in use, this error is
returned - no task is created.
*/
0x084           GBS_ERR_NO_BUFFERS      GBS_CREATE 
/*
If there is not enough memory to create
a stack for the new task, this error is
returned - no task is created.
*/
0x085           GBS_ERR_BAD_TASK_PRTY   GBS_SUSPEND,GBS_RESUME,GBS_CREATE
/*
The current priority or the priority found
in the ITD is invalid.
*/
0x086           GBS_ERR_BAD_TASK_DESC   GBS_CREATE 
/*
If the ITD descriptor found is not valid -
no task is created.
*/
0x087           GBS_ERR_NO_MEMORY       All GBS/RAC 
/* An internal operation fails because of lack of memory. */
0x088           GBS_ERR_BAD_PROC_ADDR   GBS_DEFINE_SERVICE 
/* The address parameter of the command is not valid. */
0x090           GBS_ERR_TIME_OUT        ALL incl. non-GBS tasks 
/*
A node can not be reached or a
communication link breaks caused by
successive timeouts. Note that not all
breaks in communication can be
signalled and therefor a layer7 timeout
has to be maintained by the application.
*/
0x091           GBS_ERR_PROTOCOL        ALL incl. non-GBS tasks 
/* General protocol error (sequencing error,..) */
0x093           GBS_ERR_NO_DEST_DEVICE  ALL incl. non-GBS tasks 
/* Bad destination address (0 or 255) */
0x095           GBS_ERR_PROTECTED       ALL incl. non-GBS tasks 
/* 
The access to this command is protected
by a previous GBS_PROTECT command.
*/
0x096           GBS_ERR_UNKNOWN_CMD     ALL incl. non-GBS tasks 
/* The command is not known or not supported. */
0x097           GBS_ERR_BAD_CMD_LEN     ALL incl. non-GBS tasks 
/*
This error can be used to signal an
application that the node expected a
longer message.
*/
0x98..0xfd 
/*
Reserved by BEUG for future use
*/
0x0FE           GBS_ERR_BAD_SERVICE 
/*
The command is not supported. This
error is an IEEE1118 add-on. It can
extends the
GBS_ERR_UNKNOWN_CMD error code.
*/
0x0ff           GBS_ERR_GENERAL         ALL Unspecified error. 
/*
Should not be used if there is a chance to avoid it!
*/


#endif

/*
**
**  BAPI constant values.
**
*/

/*
** The commands
*/

enum BAPI_CMD {
    GBS_RESET,              /* (RAC_RESET) */
    /* Resets a node. Special care has to be taken because not every
       implementation will perform a hardware reset!
    */

    GBS_CREATE,             /* (RAC_CREATE) */
    /* Create a task. The message carries the tasks ITD (initial task descriptor)
       address (2 byte, msb first). The address can be extendet using the
       GBS_EXTEND_ADDR command.
    */

    GBS_DELETE,             /* (RAC_DELETE) */
    /* Deletes a running task. The only parameter is the task number
       returned by GBS_CREATE (or retrieved by GBS_GET_FID)
    */

    GBS_GETFID,             /* (RAC_GETFID) */
    /* Retrieves a list of running tasks from a BITBUS node. The message is
       expected to be an array with the task numbers as an index. The array
       is filled by the node with the tasks function id codes (FID, a byte).
       Valid FID codes are:
       0 = NOFID 1 = GBSTASK 0x80..0xfe user FID's and 0xff = NOFID
    */

    GBS_PROTECT,            /* (RAC_PROTECT) */
    /* This command allows to lock some commands temporarily. The
       locking code is a single byte: 0 = UNLOCK, 1 = LOCK, 2 = RDONLY
    */

    GBS_READ_IO,            /* (RAC_READ_IO) */
    /* Read specified IO ports. The addresses and the data are expected to
       be bytes.
       The GBS_EXTEND_ADDR command can be used to enlarge the
       addressing range to 24 bits (0..0xffffff). However, all byte addresses
       within a message are extended with the same base address so that all
       ports accessed by a single message must be within the same 256-byte
       page.
    */

    GBS_WRITE_IO,           /* (RAC_WRITE_IO) */
    /* Write a value to the specified IO ports. The addresses and the data
       are expected to be bytes. The address range can be extended, see
       GBS_READ_IO for details.
    */

    GBS_UPDATE_IO,          /* (RAC_UPDATE_IO) */
    /* Write a value to the specified IO ports and read them back
       immediately. The addresses and the data are expected to be bytes.
       The address range can be extended, see GBS_READ_IO for details.
    */

    GBS_UPLOAD_DATA,        /* (RAC_UPLOAD_DATA) */
    /* Read a chunk of memory from a given 16-bit address. The address
       can be extended to 32-bit using the GBS_EXTEND_ADDR command.
    */

    GBS_DOWNLOAD_DATA,      /* (RAC_DOWNLOAD_DATA) */
    /* Write a chunk of memory to a given 16-bit address. The address can
       be extended to 32-bit using the GBS_EXTEND_ADDR command.
    */

    GBS_OR_IO,              /* (RAC_OR_IO) */
    /* The data in the message is bitwise ored with the current port value
       and write the result back to the port immediately. The addresses and
       the data are expected to be bytes. The address range can be
       extended, see GBS_READ_IO for details.
    */

    GBS_AND_IO,             /* (RAC_AND_IO) */
    /* The data in the message is bitwise anded with the current port value
       and write the result back to the port immediately. The addresses and
       the data are expected to be bytes. The address range can be
       extended, see GBS_READ_IO for details.
    */

    GBS_XOR_IO,             /* (RAC_XOR_IO) */
    /* The data in the message is bitwise xored with the current port value
       and write the result back to the port immediately. The addresses and
       the data are expected to be bytes. The address range can be
       extended, see GBS_READ_IO for details.
    */

    GBS_WRITE_SCRATCHPAD,   /* (RAC_WRITE_SCRATCHPAD) */
    /* Write values to the specified address in scratch pad ram. The
       addresses and the data are expected to be bytes. This command
       was/is used to access i8044/i80152 internal RAM for an example. The
       use is implementation depending.
       The address range can be extended, see GBS_READ_IO for details.
    */

    GBS_READ_SCRATCHPAD,    /* (RAC_READ_SCRATCHPAD) */
    /* Read values from the specified address in scratch pad ram. The
       addresses and the data are expected to be bytes. This command
       was/is used to access i8044/i80152 internal RAM for an example. The
       use is implementation depending.
       The address range can be extended, see GBS_READ_IO for details.
    */

    GBS_GET_NODE_INFO,      /* (RAC_GET_NODE_INFO) */
    /* This commands replies some node information:
       6 byte of node id (“i8044“), all ASCII.
       2 bytes version of node firmware (“21“), all ASCII
       1 byte (byte #9) supported message length
       Additional vendor and/or implementation depending information can
       be added behind byte #9.
    */

    GBS_OFFLINE,            /* (RAC_OFFLINE) */
    /* Reset the communication between a master and a specific node.
       Used to fix a bug within older i8044 processors ...
    */

    GBS_UPLOAD_CODE,        /* (RAC_UPLOAD_CODE) */
    /* Read a chunk of memory from a given 16-bit address. If the
       processor supports different address spaces for code and data
       memory, the commands GBS_UPLOAD_DATA (0x00´8) and
       GBS_UPLOAD_CODE can be used to access both spaces at will.
       The address can be extended to 32-bit using the
       GBS_EXTEND_ADDR command.
    */

    GBS_DOWNLOAD_CODE,      /* (RAC_DOWNLOAD_CODE) */
    /* Write a chunk of memory to a given 16-bit address. If the processor
       supports different address spaces for code and data memory, the
       command GBS_DOWNLAOD_DATA (0x00´9) and
       GBS_DOWNLOAD_CODE can be used to access both spaces at will.
       If the code memory is an EEPROM or FLASH memory, a suitable
       programming algorithm is used.
       The address can be extended to 32-bit using the
       GBS_EXTEND_ADDR command.
    */

    GBS_READ_REGISTER,
    /* This command is new with IEEE1118. Allows to read a processors
       special function registers (SFR). This command is implementation
       depended. Use is not recommended, because a wrong programming
       of an SFR may have dramatic drawbacks.
    */

    GBS_WRITE_REGISTER,
    /* This command is new with IEEE1118. Allows to read a processors
       special function registers (SFR). This command is implementation
       depended. Use is not recommended, because a wrong programming
       of an SFR may have dramatic drawbacks.
    */

    GBS_GET_TIME,
    /* Read the nodes clock information. */

    GBS_SET_TIME,
    /* Sets the nodes clock information to a given value. */

    GBS_SUSPEND_TASK,
    /* Stop execution of an task. The task number must be provided. */

    GBS_RESUME_TASK, 
    /* Restarts a previously suspended task. The task number must be
       provided.
    */

    GBS_DEFINE_SERVICE,
    /* Install a user supplied command (0xc0..0xff). */

    GBS_GET_TASK_ID,
    /* Get a tasks id (task number). The function ID is given as a parameter. */

    GBS_EXTEND_ADDR,
    /*
       This command can be used to extend the addressing range of an
       command. Memory up- and downloads can be boosted up to 32-bit
       and IO commands up to 24-bit. The GBS_EXTEND_ADDR modifies a
       given command - so two commands (GBS_EXTEND_ADDR + the
       original command) are included within a single message. There is no
       loss in performance using this command!
       The extended address can be a page address on 80x51 systems
       supporting paging, a 16-Bit segment address on a 80x86 system or a
       linear address (68000, 386, 80251, ...)
    */

    GBS_USER_SERVICE_START=0xc0,
    /* Defines the first user defined command */

    GBS_USER_SERVICE_END=0xff
    /* Defines the last user defined command */
};

/*
**  BAPI error codes and miscellaneous constants
**  Error codes are related to functions returning BBHANDLE or INT32.
*/

#define BAPI_OK, BAPI_ERR_OK BAPI   0L
/* function call success code */

#define BAPI_ERR_TIMEOUT            -1L 
/*
If „BitbusWaitMsg“ run into a timeout condition, this code is
returned.
*/

#define BAPI_ERR_NO_BOARD           -2L  
/*
If an open (master or slave) fails because there is no board
installed, this is the error returned.
*/

#define BAPI_ERR_NO_CONNECTION      -3L  
/*
This error is returned by the BAPI function „BitbusGetMsgLength“
if the slave „node“ can not be reached.
*/

#define BAPI_ERR_RESET_FAIL         -4L  
/*
„BitbusReset“ fails caused by unspecified reasons.
*/

#define BAPI_ERR_INVALID_TID        -5L  
/*
The task id in the „src_dest“ field of the BITBUS header is not
valid. See „3.1. BAPI in a multi-tasking environment“ for more
information.
*/

#define BAPI_ERR_INVALID_FID        -6L 
/*
The FID is not valid
*/

#define BAPI_ERR_INVALID_HANDLE     -7L  
/*
The bitbus handle returned by an open (master or slave) call is
not or no longer valid.
*/

#define BAPI_ERR_BUFF_TOO_SHORT     -8L  
/*
You try to send a message that will not fit into the given buffer. It
is a good practice to retrieve the usable message length by calling
„BitbusGetMsgLength“ to prevent this error.
*/

#define BAPI_ERR_INVALID_FLAGS      -9L  
/*
The flags setting in the „flags“ field of the BITBUS header is illegal.
See „3.1. BAPI in a multi-tasking environment“ for more
information.
*/

/*
-100L and lower BAPI_ERR_USER 
Reserved for implementation specific errors. An implementor
should avoid to use user errors
*/


/*
**  Misc. Constants.
*/
#define BAPI_MAX_MSG_LEN    ((uint8)255)    /* Maximum message length specified by IEEE1118 */
#define BAPI_WAIT_FOREVER   -1L             /* Eternal wait condition (BitbusWaitMsg) */
#define BAPI_LOCAL_SCOPE    ((uint8)0       /* Parameter for BitbusGetMsgCount */
#define BAPI_GLOBAL_SCOPE   ((uint8)1)      /* Parameter for BitbusGetMsgCount */


/*
**  Function-Prototypes.
*/

BBHANDLE Bitbus_OpenMaster(const char *AppName,const char *BitbusDevice,const BitbusOpenData *pData);
BBHANDLE Bitbus_OpenSlave(const char *AppName,const char *BitbusDevice,uint8 TaskId,uint8 FunctionId,BitbusOpenData *pData);
sint32 Bitbus_Close(BBHANDLE hdl);
sint32 Bitbus_SendMsg(BBHANDLE hdl,pBitbusMsg pMsg);
sint32 Bitbus_WaitMsg(BBHANDLE hdl,pBitbusMsg pMsg,sint32 tout);
sint32 Bitbus_Reset(BBHANDLE hdl,uint8 node);
sint32 Bitbus_GetMsgLength(BBHANDLE hdl,uint8 node);
sint32 Bitbus_GetMsgCnt(BBHANDLE hdl,uint16 scope);
sint32 Bitbus_GetAppNames(BBHANDLE hdl,char *buffer,uint16 length);


void Bitbus_RxHandler(void);

#endif /* __BITSBUS_H */
