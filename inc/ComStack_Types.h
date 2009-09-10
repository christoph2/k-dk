#if !defined(__COMSTACK_TYPES_H)
#define __COMSTACK_TYPES_H

#include "Std_Types.h"

typedef uint8 PduIdType;
    #define	PduIdmax	((PduIdType)-1)

typedef uint8 PduLengthType;
    #define	PduLengthmax	((PduLengthType)-1)

typedef struct tagPduInfoType
    uint8 *SduDataPtr,
    PduLengthType SduLength
} PduInfoType;

typedef enum tagBufReq_ReturnType {
    BUFREQ_OK,BUFREQ_E_NOT_OK,
    BUFREQ_E_BUSY,BUFREQ_E_OVFL
} BufReq_ReturnType;

typedef uint8 NotifResultType;
	#define NTFRSLT_OK              0x00
	#define NTFRSLT_E_NOT_OK        0x01
	#define NTFRSLT_E_TIMEOUT_A     0x02
	#define NTFRSLT_E_TIMEOUT_Bs    0x03
	#define NTFRSLT_E_TIMEOUT_Cr    0x04
	#define NTFRSLT_E_WRONG_SN      0x05
	#define NTFRSLT_E_INVALID_FS    0x06
	#define NTFRSLT_E_UNEXP_PDU     0x07
	#define NTFRSLT_E_WFT_OVRN      0x08
	#define NTFRSLT_E_NO_BUFFER     0x09
	
typedef uint8 BusTrcvErrorType;
	#define BUSTRCV_NO_ERROR        0x00
	#define BUSTRCV_E_ERROR         0x01

#endif	/* __COMSTACK_TYPES_H */

