/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the 
 * OSEK/VDX-Standard).
 *
 * (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
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
**  AUTOSAR-CAN-Driver for the HCS12-Family.
**  ========================================
**
**  References: [1] - S12MSCANV2/D (MSCAN Block Guide V02.15)
**              [2] - ISO 11898-1:2003
**              [3] - SAE J1939-21
**              [4] - AUTOSAR Can Driver Specification v3.?.?
**
*/

/*
**  todo: GML (Garantied Message Latency) rechachieren!!!
*/

#include "Can.h"
#if AR_VERSION_CHECK_INTERNAL_FAILS(CAN,3,1,0,1,0)
    #error Wrong Version-Information of Include-File 'Can.h' !
#endif

#include "Det.h"
#if AR_VERSION_CHECK_FAILS(DET,3,1)
    #error Wrong Version-Information of Include-File 'Det.h' !
#endif

#include "S12_Can.h"
#include "Hw_Cfg.h"


/*
**  Local Functions.
*/

static void Can_Init_Impl(const Can_ConfigType *Config);
static void Can_GetVersionInfo_Impl(Std_VersionInfoType *versioninfo);
static void Can_InitController_Impl(uint8 Controller,const Can_ControllerConfigType *Config);
static Can_ReturnType Can_SetControllerMode_Impl(uint8 Controller,Can_StateTransitionType Transition);
static void Can_DisableControllerInterrupts_Impl(uint8 Controller);
static void Can_EnableControllerInterrupts_Impl(uint8 Controller);
static Std_ReturnType Can_Cbk_CheckWakeup_Impl(uint8 Controller);
static Can_ReturnType Can_Write_Impl(uint8 Hth,const Can_PduType *PduInfo);
static void Can_MainFunction_Write_Impl(void);
static void Can_MainFunction_Read_Impl(void);
static void Can_MainFunction_BusOff_Impl(void);
static void Can_MainFunction_Wakeup_Impl(void);

/*
**
**  "Because of the addressing scheme, there is no use-case for
**  remote-data-requests in <???> - [2] 6.7: "...The data frame
**  and the corresponding remote frame shall be named by the
**  same identifier".
**
*/

/*
**
**  [2] 7.4 - LLC-Interface.
**
**  Messages betweeen LLC-User and LLC-Sublayer.
**  ============================================
**  a) User ==> Sublayer
**      Reset_Request   - Request to set the Node into an intial state.
**
**  b) Sublayer ==> User
**      Reset_Response  - Response to the Reset_Request.
**      Node_Status     - Indicates the current status of the node, i.e.
**                        it signals whether or not the node is in the
**                        bus-off state.
**
**  For LLC-Interface-Service-Data s. 8.2.2.
**  For LLC-Interface-Messages s. 13.1.3.
**
*/

/*
**
**  LLC-Service-Primitives ([2] 8.2.2.1 - Table 2)
**  ==============================================
**  L_Data.Request      - Request for Data-Transfer.
**  L_Data.Indication   - Indication of Data-Transfer.
**  L_Data.Confirm      - Confirm Data-Transfer.
**
**  L_Remote.Request    - Request for Remote-Data-Request.
**  L_Remote.Indication - Indication of Remote-Data-Request.
**  L_Remote.Confirm    - Confirmation Remote-Data-Request.
**
*/

/*
**
**  LLC-Service-Primitive Parameters  ([2] 8.2.2.1 - Table 3)
**  =========================================================
**  Identifier          - Identifies the Data and its Priority.
**  DLC                 - Data-Length-Code.
**  Data                - Data the user want to transmit
**  Transfer_Status     - Confirmation Parameter.
**
*/

/* Parameter according to CiA-DS-102: */
/*
    Speed       NBT     NTQs    L/TQ    Samp.-Pt.   TSEG1   TSEG2   BPR         BTR0    BTR1
    ========================================================================================
    1MBit/s     1µS     8       125ns   6tq         5       2       1           0x01    0x14
    800KBit/s   1,25µS  10      125ns   8tq         7       2       1           0x01    0x16
    500KBit/s   2µS     16      125ns   14tq        13      2       1           0x01    0x1C
    250KBit/s   4µS     16      250ns   14tq        13      2       3           0x03    0x1C
    125KBit/s   8µS     16      500ns   14tq        13      2       7           0x07    0x1C
    50KBit/s    20µS    16      1,25µS  14tq        13      2       19          0x13    0x1C
    20KBit/s    50µS    16      3,125µS 14tq        13      2       49          0x31    0x1C
    10KBit/s    100µS   16      6,25µS  14tq        13      2       99          (n/a)
*/

/* Parameter according to ISO 15765-3: */   /* !!! TODO !!! */
/*
    Speed       NBT     NTQs    L/TQ    Samp.-Pt.   TSEG1   TSEG2   BPR         BTR0    BTR1
    ========================================================================================
    500KBit/s   2µS     16      125ns   14tq        13      2       1           0x01    0x1C
    250KBit/s   4µS     16      250ns   14tq        13      2       3           0x03    0x1C
*/


/* other, common Parameters  */
/*  Speed   NBT         NTQs    L/TQ    Samp.-Pt.   TSEG1   TSEG2   BPR         BTR0    BTR1
    ========================================================================================
    62,5    16µS.       16      1µS     14          13      2       15          0x0F    0x1C
    83,3    12µS.       16      750ns   14          13      2       11          0x0B    0x1C
*/


/*
    ==  EQ
    !=  NE
    <   LT
    <=  LE
    >   GT
    >=  GE
*/


/*
**  Local Defines.
*/
#define CAN_EXTENDED_IDENTIFIER_FLAG    BIT3

#define ID_EXTENDED ((uint8)0x08)
#define ID_MASK_11  ((uint32)0x000007FF)
#define ID_MASK_29  ((uint32)0x1FFFFFFF)


#define CAN_IS_SLEEP_REQ(Cfg)   ((S12_REG8((Cfg),CANCTL0) & SLPRQ)==SLPRQ)
#define CAN_IS_SLEEP_ACK(Cfg)   ((S12_REG8((Cfg),CANCTL1) & SLPAK)==SLPAK)

#define CAN_IS_INIT_REQ(Cfg)    ((S12_REG8((Cfg),CANCTL0) & INITRQ)==INITRQ)
#define CAN_IS_INIT_ACK(Cfg)    ((S12_REG8((Cfg),CANCTL1) & INITAK)==INITAK)

/*
**  Local Function-Like Macros.
*/
#define CAN_REQUEST_TRANSMIT_CANCELATION(cfg,buf)   S12_REG8((cfg),CANTARQ)=(buf)
/*
**  You should use the Macros [ABTRQ0..ABTRQ2] als second Parameter.
*/


#if 0
    maybe you implement it in such a way:

    Can.h:
    ======
#define CAN_VENDOR_ID 1
#define CAN_MODULE_ID 80
#define CAN_AR_MAJOR_VERSION 3
#define CAN_AR_MINOR_VERSION 0
#define CAN_AR_PATCH_VERSION 0
#define CAN_SW_MAJOR_VERSION 1
#define CAN_SW_MINOR_VERSION 0
#define CAN_SW_PATCH_VERSION 0

    Can.c
    =====
    #if !CAN_AR_VERSION_CHECK(3, 0, 0)
        #error AUTOSAR specification version number mismatch
    #endif

    #if !CAN_SW_VERSION_CHECK(1U, 0U, 0U)
        #error AUTOSAR software version number mismatch
    #endif

    The checks should ensure that, the c files fit to the h- files.
    Maybe its a good way to define somerwhere external.

    The AR number means the Autosar Version. The SW number ist your software version
    (e.g. 0.1.0 for development, 1.0.0 for a release, 1.1.0 for a patch version)
#endif

#if 0
    you're right, let's just give a small example:
    - in CanIf_Cfg.h, you will find the definition of PRE_COMPILE configuration parameter like:

#define CANIF_STANDARD_CAN 0x0
#define CANIF_EXTENDED_CAN 0x1

    or function definition like:
        - in CanIf_Lcfg.h and CanIf_Lcfg.c, you will find the definition of LINK_TIME configuration parameters like:

        extern CONST(CanIf_PublicConfigType, CANIF_CONST) CanIf_PublicConfiguration;
        ...
        CONST(CanIf_PublicConfigType, CANIF_CONST) CanIf_PublicConfiguration =  {
            2,      /* NumberOfHth */
            1,      /* NumberOfNetwork */
            1,      /* NumberOfController */
            1,      /* NumberOfCanTransceiver */
            1,      /* NumberOfCanDriver */
            FALSE,  /* PollingBusOff */
            FALSE,  /* PollingReceive */
            FALSE,  /* PollingTransmit */
            FALSE   /* PollingWakeup */
        };

        - with POST_BUILD, you follow the same process than on LINK_TIME, but data are downloaded later on.
#endif
/*
**  Local Functions.
*/

#if 0
typedef enum tagS12Can_SpeedType {
  CAN_SPEED_1000,
  CAN_SPEED_800,
  CAN_SPEED_500,
  CAN_SPEED_250,
  CAN_SPEED_125,
  CAN_SPEED_83,
  CAN_SPEED_62,
  CAN_SPEED_50,
  CAN_SPEED_20
} S12Can_SpeedType;

/* Bustiming / 16MHz Osc. */
static const S12Can_BusTimingType Can_SpeedTable[]={
    {(uint8)0x01,(uint8)0x14},    /* 1MBit/s      */
    {(uint8)0x01,(uint8)0x16},    /* 800KBit/s    */
    {(uint8)0x01,(uint8)0x1C},    /* 500KBit/s    */
    {(uint8)0x03,(uint8)0x1C},    /* 250KBit/s    */
    {(uint8)0x07,(uint8)0x1C},    /* 125KBit/s    */
    {(uint8)0x0B,(uint8)0x1C},    /* 83,3KBit/s   */
    {(uint8)0x0F,(uint8)0x1C},    /* 62,5KBit/s   */
    {(uint8)0x13,(uint8)0x1C},    /* 50KBit/s     */
    {(uint8)0x31,(uint8)0x1C},    /* 20KBit/s     */
};
#endif


/*
**  Initialization-State can be determined be HW, we don't need a static var.
*/
AR_IMPLEMENT_MODULE_STATE_VAR(CAN);

/*
**  This is only needed if the CAN-Driver is not used in AUTOSAR-Context,
**  where CanIf-Callbacks are fixed.
*/

/* Hinweis: die 'typedefs' sind total überflüssig... */
typedef void (*Can_TxConfirmationNotificationType)(PduIdType CanTxPduId);
typedef void (*Can_RxIndicationNotificationType)(uint8 Hrh,Can_IdType CanId,uint8 CanDlc,const uint8 * CanSduPtr);
typedef void (*Can_CancelTxConfirmationNotificationType)(const Can_PduType *PduInfoPtr);
typedef void (*Can_ControllerBusoffNotificationType)(uint8 Controller);

typedef struct tagCan_DriverNotificationsType {
    Can_TxConfirmationNotificationType TxNotification;
    Can_RxIndicationNotificationType RxNotification;
    Can_CancelTxConfirmationNotificationType CancelTxNotification;
    Can_ControllerBusoffNotificationType ControllerBusoffNotification;
} Can_DriverNotificationsType;

#if 0
    Notifications/Callbacks.
    ========================

    void xxx_TxConfirmation(PduIdType CanTxPduId);
    void xxx_RxIndication(uint8 Hrh,Can_IdType CanId,uint8 CanDlc,const uint8 * CanSduPtr);
/*      void xxx_RxIndication(PduIdType Can_RxPduId,const uint8 * CanSduPtr);    */
/*      void xxx_RxIndication(PduIdType Can_RxPduId,const PduInfoType * PduInfoPtr);    */
    void xxx_CancelTxConfirmation(const Can_PduType *PduInfoPtr);
    void xxx_ControllerBusoff(uint8 Controller);
#endif

/*
**  Local Types.
*/
typedef enum tagCan_HwStateType {
    CAN_HW_STATE_UNINIT,
    CAN_HW_STATE_STOPPED,
    CAN_HW_STATE_STARTED,   /* Varianten: SYNCHED | NOT_SYNCHED (STOPPED ?!)*/
    CAN_HW_STATE_SLEEPING,
    CAN_HW_STATE_POWER_DOWN
#if 0
        bzw. lt. Module-Doc.:
        =====================
    STARTUP,
    WAIT_FOR_IDLE,
    IDLE,
    RXTX_MESSAGE_ACTIVE,
    SLEEP
#endif
} Can_HwStateType;


static Can_HwStateType Can_GetHwState(S12Can_ConfigType const * const Cfg,boolean *TransitState);
static boolean Can_HwInterruptsEnabled(void);

const Can_PublicIfType Can_PublicIf={
    Can_Init_Impl,
    Can_GetVersionInfo_Impl,
    Can_InitController_Impl,
    Can_SetControllerMode_Impl,
    Can_DisableControllerInterrupts_Impl,
    Can_EnableControllerInterrupts_Impl,
    Can_Cbk_CheckWakeup_Impl,
    Can_Write_Impl,
    Can_MainFunction_Write_Impl,
    Can_MainFunction_Read_Impl,
    Can_MainFunction_BusOff_Impl,
    Can_MainFunction_Wakeup_Impl
};

#if 0

    .
    .
    .
    Can_Can_PublicIf.Can_Init(Config);
    .
    .
    .
#endif

/************************************************************************************************************************
**
**                                          AUTOSAR
**
************************************************************************************************************************/


#define GLUE_NAME(mod)  GLUE2(mod,_DET_ERROR_DETECT)

#if GLUE_NAME(CAN) == STD_ON
#define CAN_DET_ASSERT(cond,ApiId,ErrorId)                                      \
    _BEGIN_BLOCK                                                                \
        if (!(cond)) {                                                          \
            Det_ReportError(CAN_MODULE_ID,CAN_INSTANCE_ID,(ApiId),(ErrorId));   \
        }                                                                       \
    _END_BLOCK
#else
#define CAN_DET_ASSERT(cond,ApiId,ErrorId)
#endif



void Can_Init_Impl(const Can_ConfigType *Config)
{
#if CAN_DEV_ERROR_DETECT==STD_ON
    if (CAN_State!=BSW_UNINIT) {
        /*!REQ!AR!CAN174!*/
        Det_ReportError(CAN_MODULE_ID,CAN_INSTANCE_ID,AR_SERVICE_CAN_INIT,CAN_E_TRANSITION);
    } else {
         CAN_State=BSW_READY;
    }
#endif  /* CAN_DEV_ERROR_DETECT */

    /*!REQ!AR!CAN175!*/
    CAN_DET_ASSERT(Config!=(const Can_ConfigType *)NULL,AR_SERVICE_CAN_INIT,CAN_E_PARAM_POINTER);
}


void Can_GetVersionInfo_Impl(Std_VersionInfoType *versioninfo)
{
#if CAN_VERSION_INFO_API==STD_ON
    versioninfo->vendorID=(uint16)CAN_VENDOR_ID;
    versioninfo->moduleID=(uint16)CAN_MODULE_ID;
    versioninfo->instanceID=(uint8)CAN_INSTANCE_ID;
    versioninfo->sw_major_version=(uint8)CAN_SW_MAJOR_VERSION;
    versioninfo->sw_minor_version=(uint8)CAN_SW_MINOR_VERSION;
    versioninfo->sw_patch_version=(uint8)CAN_SW_PATCH_VERSION;
#else
    UNREFERENCED_PARAMETER(versioninfo);
#endif
}


void Can_InitController_Impl(uint8 Controller,const Can_ControllerConfigType *Config)
{

}

/*
                        |
    ----------------------------------------------------------------------------------------
                        |   CAN_T_START     CAN_T_STOP      CAN_T_SLEEP     CAN_T_WAKEUP
    ----------------------------------------------------------------------------------------
    CANIF_CS_UNINIT     |   ---             ---             ---             ---
    CANIF_CS_STOPPED    |                                   CANIF_CS_SLEEP  ---
    CANIF_CS_STARTED    |                                   ---             ---
    CANIF_CS_SLEEP      |                                                   CANIF_CS_STOPPED

*/

Can_ReturnType Can_SetControllerMode_Impl(uint8 Controller,Can_StateTransitionType Transition)
{
    /*
    **  Only allow valid Transitions from [4] 7.3.2 "State Transitions".
    **  This can help to uncover errors in 'CanIf'.
    */
#if 0
    CAN_T_START
    CAN_T_STOP
    CAN_T_SLEEP
    CAN_T_WAKEUP
#endif

}


void Can_DisableControllerInterrupts_Impl(uint8 Controller)
{

}


void Can_EnableControllerInterrupts_Impl(uint8 Controller)
{

}

#if 0
void Can_ControllerInterrupts(uint8 Controller,boolean enable)
{
    static uint8 InterruptsDisableCounter;  /*todo: array[NUM_CONTROLLERS] !!! */
    static uint8 SavedInterruptsMask;
    boolean gie;    /*+ Global Interrupts Enable Flag.  */

    /* todo: ASSERT InterruptsDisableCounter < (uint8)0xfe  */

#if 0
    SavedInterruptsMask|=S12_REG8(Cfg,CANRIER) & (WUPIE|CSCIE|OVRIE|RXFIE);
    SavedInterruptsMask|=(S12_REG8(Cfg,CANTIER) & (TXEIE0|TXEIE1|TXEIE2)) << 2;
#endif

    CPU_SAVE_AND_DISABLE_INTERRUPTS(gie);   /* ENTER_CRITICAL_SECTION */
                                            /* todo: den Mechanismus genauer untersuchen!!! */
    if (enable) {

    } else {

    }
    CPU_RESTORE_INTERRUPTS(gie);            /* LEAVE_CRITICAL_SECTION */
}
#endif

Std_ReturnType Can_Cbk_CheckWakeup_Impl(uint8 Controller) /* Std_ReturnType Can_Cbk_CheckWakeup(uint8 Controller); */
{

}

/*
**  Struktur f. Controller-Variablen.
*/

typedef struct tagCan_ControllerStateType {
    PduIdType PduHandleTransmittedOnHTH[3]; /* todo: Parameter 'CAN_NUM_HTHS' oder so!!! */

#if 0
    uint8 InterruptsDisableCounter; /* lokale, statische Variablen gehen auch (?), da nur */
    uint8 SavedInterruptsMask;      /* innerhalb einer Critical Section darauf zugegriffen wird!!! */
#endif
} Can_ControllerStateType;



PduIdType PduHandleTransmittedOnHth[3];     /* HC12-/S12(X)-Controller are always equipped /w three Tx-Buffers. */
                                        /* Besser: zwei-Dimensionales Array!!!          */


Can_ReturnType Can_Write_Impl(uint8 Hth,const Can_PduType *PduInfo)
{
    /*
    **
    ** Maps to [2] 8.2.2.2 - L_Data.Request(Identifier,DLC,Data).
    **
    */

    /*
    **
    **  !REQ!AR!CAN276:"The function Can_Write shall store the swPduHandle that is given inside the
    **  parameter  PduInfo until the Can module calls the CanIf_TXConfirmation for this request
    **  where the swPduHandle is given as parameter."
    **
    */
    /* check: wieso nicht den Identifier??? */

    /*
    **  Select Transmit-Buffer... Entscheidend ist der zweite Punkt,
    **  In this sense it is not a Software-Emulation; !REQ!AR!CAN076:
    **  "The Can Module shall NOT support software emulation for multiplexed transmission"
    */
    /* OK, ist erfüllt wenn auch die Tx-Priorität zum Tragen kommt...   */

    /*
    **
    **  Hinweis: Um zu einer genauen 'TxPrio'-Einstellung zu kommen, ist die Differenz
    **  zwischen der größten und der kleinsten ID entscheidend!!!
    **
    **  todo:   Das/Die Makro(s) (11/29/Mixed) erstellt der Code-Generator für
    **          jeden Controller!!!
    **
    **  CAN_GET_PRIO_FROM_ID()
    **      Der kleinste Identifier resultiert in 0x00, der größte in 0xff.
    **
    **
    */
}


void Can_MainFunction_Write_Impl(void)
{


}


void Can_MainFunction_Read_Impl(void)
{

}


void Can_MainFunction_BusOff_Impl(void)
{

}


void Can_MainFunction_Wakeup_Impl(void)
{


}

/************************************************************************************************************************
**
**                                          CHRIS
**
************************************************************************************************************************/

#if 0
    todo: Makros/Paramter für: 'FILTER_OUT_REMOTE_FRAMES','FILTER_OUT_STANDARD_IDENTIFIERS','FILTER_OUT_EXTENDED_IDENTIFIERS'
                                        'PASS_THROUG_IDENTIFIERS'
#endif

/*
** Filter-Masken sind als Sub-Container Controllern zugeordnet (0..*)
*/
typedef struct tagCan_FilterMaskType {
    Can_IdType CanFilterMaskValue;
/*
    Describes a mask for hardware-based filtering of CAN identifiers

                                It shall be distinguished between
                                  - Standard identifier mask
                                  - Extended identifier mask.
*/
} Can_FilterMaskType;


typedef struct tagCan_HardwareObjectConfigType {
    /* HandleType not needed for CPU12!!! */
#if 0
    uint8 CanHandleType;    /* enum: [BASIC|FULL] - Specifies the type (Full-CAN or Basic-CAN) of a hardware object. */
#endif

    uint8 CanIdType;        /* enum: [EXTENDED|MIXED|STANDARD] - Specifies whether the IdValue is of type
                                - standard identifier
                                - extended identifier
                                - mixed mode
                             ImplementationType: Can_IdType
                            */
    Can_IdType CanIdValue;  /* Specifies (together with the filter mask) the identifiers range that passes the hardware filter. */

    uint8 CanObjectType;    /* enum: [RECEIVE|TRANSMIT] - Specifies if the HardwareObject is used as Transmit */
                            /* or as Receive object */

    uint8 CanObjectId;      /*
                            CAN_OBJECT_HANDLE_ID
                            SYMBOLIC-NAME-VALUE=true

                            Holds the handle ID of HRH or HTH. The value of this parameter is unique
                            in a given CAN Driver, and it should start with 0 and continue without any gaps.
                            The HRH and HTH Ids are defined under two different name-spaces.

                                Example: HRH0-0, HRH1-1, HTH0-2, HTH1-3
                            */

    /* todo: Für die folgenden beiden Referenz-Parameter optimale Datenstrukturen finden!!! */
    Can_ControllerConfigType const * const CanControllerRef;    /* Reference to CAN Controller to which the HOH */
                                                                /* is associated to. */
    /* einem Identifier ist genau eine Filter-Maske zugeordnet. */
#if 0
    Can_FilterMaskConfigtype const * const CanFilterMaskRef;    /* Reference to the filter mask that is used for */
                                                                /* hardware filtering togerther with the CAN_ID_VALUE */
#endif
} Can_HardwareObjectConfigType;


#if 0
    Config: LOOPB   - Loopback Enabled.
            LISTEN  - Listen Only; Busmonitor, no Ack generation.
#endif

S12Can_StatusType S12Can_Init(S12Can_ConfigType const * const Cfg,uint8 btr0,uint8 btr1)
{
    S12Can_StatusType ret;

    ret=S12Can_InitializationMode(Cfg,TRUE);
    if (ret!=S12CAN_OK) {
        return ret;
    }

    S12_REG8(Cfg,CANCTL1)=CANE|TIME|/*LOPB|*/WUPM;

    (void)S12Can_SetBusTiming(Cfg,btr0,btr1);
    (void)S12Can_SetFilter(Cfg,&Cfg->Filter);

    ret=S12Can_InitializationMode(Cfg,FALSE);
    if (ret!=S12CAN_OK) {
        return ret;
    }

    S12_REG8(Cfg,CANCTL0)=(CSWAI|TIME|WUPE);    /* Hinweis: Vorsicht mit 'CSWAI' !!! */

    (void)S12Can_EnableInterrupts(Cfg,TRUE);

    return S12CAN_OK;
}


S12Can_StatusType S12Can_EnableInterrupts(S12Can_ConfigType const * const Cfg,boolean enable)
{
    if (S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    if (enable) {
        S12_REG8(Cfg,CANRIER)=WUPIE|CSCIE|RSTATE0|RSTATE1|TSTATE0|TSTATE1|OVRIE|RXFIE;
    } else {
        S12_REG8(Cfg,CANRIER)=(uint8)0x00;
        S12_REG8(Cfg,CANTIER)=(uint8)0x00;
    }

    return S12CAN_OK;
}


boolean S12Can_Sleeping(S12Can_ConfigType const * const Cfg)
{
    return ((S12_REG8(Cfg,CANCTL0) & SLPRQ)==SLPRQ) && ((S12_REG8(Cfg,CANCTL1) & SLPAK)==SLPAK);
}


boolean S12Can_Initializing(S12Can_ConfigType const * const Cfg)
{
    return ((S12_REG8(Cfg,CANCTL0) & INITRQ)==INITRQ) && ((S12_REG8(Cfg,CANCTL1) & INITAK)==INITAK);
}


boolean S12Can_Synchronized(S12Can_ConfigType const * const Cfg)
{
    return ((S12_REG8(Cfg,CANCTL0) & SYNCH)==SYNCH);
}


boolean S12Can_Enabled(S12Can_ConfigType const * const Cfg)
{
    return ((S12_REG8(Cfg,CANCTL1) & CANE)==CANE);
}


S12Can_StatusType S12Can_SetBusTiming(S12Can_ConfigType const * const Cfg,uint8 btr0,uint8 btr1)
{
    if (!S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    S12_REG8(Cfg,CANBTR0)=btr0;
    S12_REG8(Cfg,CANBTR1)=btr1;

    return S12CAN_OK;
}


S12Can_StatusType S12Can_SetFilter(S12Can_ConfigType const * const Cfg,const S12Can_FilterType *Filter)
{
    if (!S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    S12_REG8(Cfg,CANIDAC)=Filter->FilterMode;

    S12_REG8(Cfg,CANIDAR0)=Filter->IdentifierAcceptance[0];
    S12_REG8(Cfg,CANIDAR1)=Filter->IdentifierAcceptance[1];
    S12_REG8(Cfg,CANIDAR2)=Filter->IdentifierAcceptance[2];
    S12_REG8(Cfg,CANIDAR3)=Filter->IdentifierAcceptance[3];
    S12_REG8(Cfg,CANIDAR4)=Filter->IdentifierAcceptance[4];
    S12_REG8(Cfg,CANIDAR5)=Filter->IdentifierAcceptance[5];
    S12_REG8(Cfg,CANIDAR6)=Filter->IdentifierAcceptance[6];
    S12_REG8(Cfg,CANIDAR7)=Filter->IdentifierAcceptance[7];

    S12_REG8(Cfg,CANIDMR0)=Filter->IdentifierMask[0];
    S12_REG8(Cfg,CANIDMR1)=Filter->IdentifierMask[1];
    S12_REG8(Cfg,CANIDMR2)=Filter->IdentifierMask[2];
    S12_REG8(Cfg,CANIDMR3)=Filter->IdentifierMask[3];
    S12_REG8(Cfg,CANIDMR4)=Filter->IdentifierMask[4];
    S12_REG8(Cfg,CANIDMR5)=Filter->IdentifierMask[5];
    S12_REG8(Cfg,CANIDMR6)=Filter->IdentifierMask[6];
    S12_REG8(Cfg,CANIDMR7)=Filter->IdentifierMask[7];

    return S12CAN_OK;
}


S12Can_StatusType S12Can_Stop(S12Can_ConfigType const * const Cfg)
{
    (void)S12Can_InitializationMode(Cfg,TRUE);
    S12_REG8(Cfg,CANCTL1)&=~CANE; /* only in special system operation modes. */
    S12_REG8(Cfg,CANRIER)=(uint8)0x00;
    S12_REG8(Cfg,CANTIER)=(uint8)0x00;

    return S12CAN_OK;
}


S12Can_StatusType S12Can_InitializationMode(S12Can_ConfigType const * const Cfg,boolean enable)
{
    /*
        The following registers enter their hard reset state and restore their default values:
        CANCTL0, CANRFLG, CANRIER, CANTFLG, CANTIER, CANTARQ,
        CANTAAK, CANTBSEL.
    */
    if (enable) {
        S12_REG8(Cfg,CANCTL0)|=INITRQ;
        WAIT_FOR((S12_REG8(Cfg,CANCTL1) & INITAK)==INITAK);
    } else {
        if (!((S12_REG8(Cfg,CANCTL0) & INITRQ) && (S12_REG8(Cfg,CANCTL1) & INITAK))) {
            return S12CAN_STATE; /* must be in Initialization Mode. */
        }
        S12_REG8(Cfg,CANCTL0)&=~INITRQ;
        WAIT_FOR((S12_REG8(Cfg,CANCTL1) & INITAK)!=INITAK);
        (void)S12Can_WaitSynch(Cfg);
    }
    return S12CAN_OK;
}


S12Can_StatusType S12Can_SleepMode(S12Can_ConfigType const * const Cfg,boolean enable)
{
    if (enable) {
        S12_REG8(Cfg,CANCTL0)|=SLPRQ;
        WAIT_FOR((S12_REG8(Cfg,CANCTL1) & SLPAK)==SLPAK);

    } else {
        if (!((S12_REG8(Cfg,CANCTL0) & SLPRQ) && (S12_REG8(Cfg,CANCTL1) & SLPAK))) {
            return S12CAN_STATE; /* must be in Sleep Mode. */
        }
        S12_REG8(Cfg,CANCTL0)&=~SLPRQ;
        WAIT_FOR((S12_REG8(Cfg,CANCTL1) & SLPAK)!=SLPAK);
        (void)S12Can_WaitSynch(Cfg);
    }
    return S12CAN_OK;
}


S12Can_StatusType S12Can_CancelMessage(S12Can_ConfigType const * const Cfg,uint8 Number)
{
    uint8 Mask;

    if (S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    if (Number>(uint8)2) {
        return S12CAN_VALUE;
    }

    Mask=(uint8)1<<Number;  /* todo: BIT(n) !?  */

    if ((S12_REG8(Cfg,CANTARQ) & Mask)==Mask) {
        return S12CAN_STATE; /* request already pending. */
    }
    S12_REG8(Cfg,CANTARQ)|=Mask;

    WAIT_FOR((S12_REG8(Cfg,CANTAAK) & Mask)==Mask);


    return S12CAN_OK;
}


S12Can_StatusType S12Can_Ready(S12Can_ConfigType const * const Cfg,boolean *ready)
{
    *ready=((S12_REG8(Cfg,CANTFLG) & (TXE0|TXE1|TXE2))!=(uint8)0x00);

    return S12CAN_OK;
}


S12Can_StatusType S12Can_RxD(S12Can_ConfigType const * const Cfg,boolean *rxd)
{
    *rxd=((S12_REG8(Cfg,CANRFLG) & RXF)==RXF);

    return S12CAN_OK;
}


S12Can_StatusType S12Can_Transmit(S12Can_ConfigType const * const Cfg,S12Can_MessageType const * Msg,uint8 priority,uint8 *SentOnBuffer)
{
    S12Can_BufferType *TxFG;
    uint8 number_of_buffer;
    boolean ready;

    if (S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    if (Msg->DLR>CAN_MAX_LSDU_LEN) {
        return S12CAN_VALUE;
    }

    /* wait for at least one free buffer */
    ready=FALSE;
    while (!ready) {
        (void)S12Can_Ready(Cfg,&ready);
    }

    TxFG=(S12Can_BufferType*)&S12_REG16(Cfg,CANTXFG);

    S12_REG8(Cfg,CANTBSEL)=S12_REG8(Cfg,CANTFLG);    /* Select Buffer. */
    number_of_buffer=S12_REG8(Cfg,CANTBSEL);

    TxFG->DLR=Msg->DLR;
    TxFG->TBPR=priority;

    /* todo: Funktion (ist übersichtlicher) !!! */
    if (CAN_IS_EXTENDED_ID(Msg->ID)) {
        /* todo: Implementieren !!! */
        if (CAN_IS_RTR(Msg->ID)) {
            TxFG->IDR1|=BIT4;
        }
        TxFG->IDR1|=CAN_EXTENDED_IDENTIFIER_FLAG;
    } else {
        TxFG->IDR0=(uint8)((Msg->ID & (uint32)0x07FF)>>3);
        TxFG->IDR1=(uint8)((Msg->ID & (uint32)0x0007)<<5);
        TxFG->IDR1&=~CAN_EXTENDED_IDENTIFIER_FLAG;
        if (CAN_IS_RTR(Msg->ID)) {
            TxFG->IDR3|=BIT1;
        }
    }

    if ((Msg->DLR!=(uint8)0x00) && (!CAN_IS_RTR(Msg->ID))) {
        Utl_MemCopy((void*)&TxFG->DSR0,(void*)Msg->SDU,(uint16)Msg->DLR);
    }

    if (SentOnBuffer!=(uint8*)NULL) {
        *SentOnBuffer=number_of_buffer;
    }

    S12_REG8(Cfg,CANTFLG)=number_of_buffer;   /* Send Buffer. */

    return S12CAN_OK;
}


S12Can_StatusType S12Can_CopyRxBuffer(S12Can_ConfigType const * const Cfg,S12Can_MessageType *Msg)
{
    S12Can_BufferType *RxFG;
    uint32 ID;
    boolean ExtendedID;
    boolean RTR;

    if (S12Can_Initializing(Cfg)) {
        return S12CAN_STATE;
    }

    if ((S12_REG8(Cfg,CANRFLG) & RXF)==(uint8)0) {
        return S12CAN_STATE;   /* Foreground receive buffer is empty. */
    }

    RxFG=(S12Can_BufferType*)&S12_REG16(Cfg,CANRXFG);

    Msg->DLR=CAN_NORMALIZE_DLC(RxFG->DLR);
                        /* todo: Auf alle Fälle Sättigen!!! */
                        /* DevError/Assertion auslösen.     */
                        /* Strategien: [SATURATE|REJECT]    */
                        /* if DLC>7 DLC=8                   */
                        /* [2] 8.4.3 Table 4 - Coding of the numbers of data bytes by the DLC   */
                        /* Accorrding to [2] 8.4.3 Table 4, if DLC-Bit#3 is set, Bits#2-#0 are  */
                        /* don't care and 'Number of data bytes' is saturated @ 8.              */
                        /* FS-Docu is not clear about this.                                     */
                        /* Im Gegensatz zur ISO-Doku...                                         */
                        /* [1] 3.3.2.3 Data Length Register; Table 3-10 Data length codes       */
                        /* "the data byte count ranges from 0 to 8 for a data frame."           */
                        /* MSCAN Transmits and receives byte counts > 8 !!!                     */

/*
**  ISO-15765-4 Defect-report senden!!!
*/

    ExtendedID=((RxFG->IDR1 & CAN_EXTENDED_IDENTIFIER_FLAG)==CAN_EXTENDED_IDENTIFIER_FLAG);

    if (ExtendedID) {
        RTR=((RxFG->IDR3 & (uint8)0x01)==(uint8)0x01);
        ID=(((uint32)RxFG->IDR0) << 21) | (((uint32)(RxFG->IDR1 & (uint8)0xe0)) << 18) |
           (((uint32)(RxFG->IDR1 & 0x07)) << 15) | (((uint32)RxFG->IDR2) << 7) |
           (((uint32)(RxFG->IDR3 & 0xfe)) >> 1);
        CAN_SET_EXTENDED_ID(ID);

    } else {
        RTR=((RxFG->IDR1 & (uint8)0x10)==(uint8)0x10);
        ID=(uint32)(((uint32)RxFG->IDR0 << 3) | ((uint32)RxFG->IDR1 >> 5));
    }

    if (RTR) {
        CAN_SET_RTR(ID);
    }

    Msg->ID=ID;

    if (!RTR && (Msg->DLR!=(uint8)0x00)) {
        Utl_MemCopy((void*)Msg->SDU,(void*)&RxFG->DSR0,(uint16)Msg->DLR);
    }

    S12_REG8(Cfg,CANRFLG)=RXF;  /* clear receive buffer full flag. */

    return S12CAN_OK;
}


S12Can_StatusType S12Can_GetErrorCounters(S12Can_ConfigType const * const Cfg,uint8 *RxErrors,uint8 *TxErrors)
{
    *RxErrors=S12_REG8(Cfg,CANRXERR);
    *TxErrors=S12_REG8(Cfg,CANTXERR);

    return S12CAN_OK;
}


S12Can_StatusType S12Can_WaitSynch(S12Can_ConfigType const * const Cfg)
{
    WAIT_FOR((S12_REG8(Cfg,CANCTL0) & SYNCH)==SYNCH);

    S12_REG8(Cfg,CANRFLG)=WUPIF|CSCIF|OVRIF|RXF;

    return S12CAN_OK;
}


/*
**  Local, Hardware-Dependent Support Functions.
*/

/* REACHED | TRANSITING */
Can_HwStateType Can_GetHwState(S12Can_ConfigType const * const Cfg,boolean *TransitState)
{
    Can_HwStateType state=CAN_HW_STATE_UNINIT;

#if 0
    CAN_HW_STATE_UNINIT,
    CAN_HW_STATE_STOPPED,
    CAN_HW_STATE_STARTED,
    CAN_HW_STATE_SLEEPING,

#endif
    *TransitState=FALSE;    /* check: Ist 'Transiting' besser ??? */

#if 0
    if (ACK || REQ ) {
        if (!(ACK && REQ)) {
            State=TRANSITING;
        } else {
            State=REACHED;
        }
    }
#endif

#if 0

CAN_IS_SLEEP_REQ
CAN_IS_SLEEP_ACK

CAN_IS_INIT_REQ
CAN_IS_INIT_ACK
#endif

    if (S12Can_Enabled(Cfg)) {
        if ((S12_REG8(Cfg,CANCTL0) & SLPRQ)==SLPRQ) {
            if ((S12_REG8(Cfg,CANCTL1) & SLPAK)==SLPAK) {   /* todo: Wenn nicht 'ACK', dann Transit !!! */
                return CAN_HW_STATE_SLEEPING;
            } else {
                /* Trans-State. */  /* Sleep-Request. */
            }
        }


        /*
        ** Hinweis: Inititialisierung muss zuerst geprüft werden, weil Sleep-Mode danach keine
        **          Rolle mehr spielt; es kann kein Wakup ausgelöst werden, in jedem Fall ==> Stopped.
        */
        if ((S12_REG8(Cfg,CANCTL0) & INITRQ)==INITRQ) {
            if ((S12_REG8(Cfg,CANCTL1) & INITAK)==INITAK) {

            } else {
                /* Trans-State. */  /* Init-Request. */
            }
        } else {
            if (S12Can_Synchronized(Cfg)) {
                return CAN_HW_STATE_STARTED;
            }
        }


    } else {
        state=CAN_HW_STATE_UNINIT;
    }

    return state;
}


boolean Can_HwInterruptsEnabled(void)
{
    boolean res=FALSE;
#if 0
CANRIER
CANTIER
#endif
    return res;
}

/*
**  Interrupt-Handler.
*/
S12Can_MessageType Msg;

void Can_HandleIrqTx(S12Can_ConfigType const * const Cfg)
{
    BYTE_REG(Cfg->BaseAddr,CANTAAK);

    BYTE_REG(Cfg->BaseAddr,CANTFLG)=(uint8)TXE2|TXE1|TXE0;
#if 0
TXE2 - TXE0 —Transmitter Buffer Empty
    This flag indicates that the associated transmit message buffer is empty, and thus not scheduled for
    transmission. The CPU must clear the flag after a message is set up in the transmit buffer and is due
    for transmission. The MSCAN sets the flag after the message is sent successfully. The flag is also set
    by the MSCAN when the transmission request is successfully aborted due to a pending abort request
    (see 3.3.1.9 MSCAN Transmitter Message Abort Control (CANTARQ)). If not masked, a
    Transmit interrupt is pending while this flag is set.
    Clearing a TXEx flag also clears the corresponding ABTAKx (see 3.3.1.10 MSCAN Transmitter
    Message Abort Control (CANTAAK)). When a TXEx flag is set, the corresponding ABTRQx bit is
    cleared (see 3.3.1.9 MSCAN Transmitter Message Abort Control (CANTARQ)).
    When Listen-Mode is active (see 3.3.1.2 MSCAN Control 1 Register (CANCTL1)) the TXEx flags
    cannot be cleared and no transmission is started.
    Read and write accesses to the transmit buffer will be blocked, if the corresponding TXEx bit is cleared
    (TXEx=’0’) and the buffer is scheduled for transmission.
        1 = The associated message buffer is empty (not scheduled).
        0 = The associated message buffer is full (loaded with a message due for transmission).
#endif
}

void Can_HandleIrqRx(S12Can_ConfigType const * const Cfg)
{
/*** TEST ***/
    S12Can_StatusType ret;
    ret=S12Can_CopyRxBuffer(Cfg,&Msg);
/*** TEST ***/

    /* If Vector: call, else clear flag (???). */
    BYTE_REG(Cfg->BaseAddr,CANRFLG)=RXF;
}

void Can_HandleIrqErr(S12Can_ConfigType const * const Cfg)
{
    uint8 rflags;
    uint8 state;

    rflags=BYTE_REG(Cfg->BaseAddr,CANRFLG);

    if ((rflags & CSCIF)==CSCIF) {
        state=rflags & (RSTAT1|RSTAT0|TSTAT1|TSTAT0);

        if (((state & S12CAN_RSTAT_BUSOFF)==S12CAN_RSTAT_BUSOFF) || ((state & S12CAN_TSTAT_BUSOFF)==S12CAN_TSTAT_BUSOFF)) {

        }
        BYTE_REG(Cfg->BaseAddr,CANRFLG)=CSCIF;
    } else if ((rflags & OVRIF)==OVRIF) {

        BYTE_REG(Cfg->BaseAddr,CANRFLG)=OVRIF;
    }
}

void Can_HandleIrqWup(S12Can_ConfigType const * const Cfg)
{
    BYTE_REG(Cfg->BaseAddr,CANRFLG)=WUPIF;
}
