
    NAME S12Eep
    
    PUBLIC  S12Eep_Init
    PUBLIC  S12Eep_Protect
    PUBLIC  S12Eep_DoCmd
    PUBLIC  S12Eep_VerifyErase
    PUBLIC  S12Eep_SectorErase
    PUBLIC  S12Eep_MassErase
    PUBLIC  S12Eep_ProgramWord
    PUBLIC  S12Eep_SectorModify
    PUBLIC  S12Eep_Relocate
    
    

;
;   Module-Error-Codes.
;
EE_ERR_OK           EQU     0
EE_ERR_INIT         EQU     1
EE_ERR_PVIOL        EQU     2
EE_ERR_ACC          EQU     3
EE_ERR_ADDR         EQU     4

EE_CLK_DIV          EQU     (((16*1000)/200 /8)-1)	; Prescaler / 16-Mhz-Oszillator.

EE_SECTOR_SIZE      EQU     4

;   Command-Codes.
EE_ERASE_VERIFY     EQU     0x05
EE_WORD_PROGRAM     EQU     0x20
EE_SECTOR_ERASE     EQU     0x40
EE_MASS_ERASE       EQU     0x41
EE_SECTOR_MODIFY    EQU     0x60    

;
;   todo: Include-File!!!
;
ECLKDIV     EQU     0x0110
; ECLKDIV-Bits.
EDIVLD      EQU 0x80
PRDIV8      EQU 0x40
EDIV5       EQU 0x20
EDIV4       EQU 0x10
EDIV3       EQU 0x08
EDIV2       EQU 0x04
EDIV1       EQU 0x02
EDIV0       EQU 0x01


ECNFG       EQU     0x0113
; ECNFG-Bits.
CBEIE       EQU 0x80
CCIE        EQU 0x40


EPROT       EQU     0x0114
; EPROT-Bits.
EPOPEN      EQU 0x80
NV6         EQU 0x40
NV5         EQU 0x20
NV4         EQU 0x10
EPDIS       EQU 0x08
EP2         EQU 0x04
EP1         EQU 0x02
EPO         EQU 0x01


ESTAT       EQU     0x0115
; ESTAT-Bits.
CBEIF       EQU 0x80
CCIF        EQU 0x40
PVIOL       EQU 0x20
ACCERR      EQU 0x10
BLANK       EQU 0x04


ECMD        EQU         0x0116
; ECMD-Bits.
CMDB6       EQU 0x40
CMDB5       EQU 0x20
CMDB2       EQU 0x04
CMDB0       EQU 0x01

EADDR       EQU         0x118
EDATA       EQU         0x11a

;
; ***************************
;

CODE_LEN  EQU       CODE_END-CODE_START
    
    RSEG DATA16_C:CONST:REORDER:NOROOT(0)   ; Constant-Segment.

    RSEG CODE:CODE:REORDER:NOROOT(0)        ; Code-Segment.

CODE_START:

;
;   void S12Eep_Init(void);
;
S12Eep_Init:
    movb    #0x00,ECNFG    ; no Interrupts.
    movb    #(PRDIV8 | EE_CLK_DIV),ECLKDIV
    rts

;
; void S12Eep_Protect(boolean ena);
;
;   User has to disable Interrupts!!!
;
;   Hinweis: ganz so einfach ist das nicht...
;
S12Eep_Protect: 
    tstb
    bne     pr_off
pr_on:
    bclr    EPROT,#EPOPEN
    bra     pr_exit
pr_off:
    bset    EPROT,#EPOPEN
pr_exit:
    rts


;
; uint8 S12Eep_DoCmd(uint8 cmd,uint16 addr,uint16 data);
;

S12Eep_DoCmd:
;   cmd     ==> 2,sp
;   addr    ==> D
;   data    ==> Y
;
    brset   ECLKDIV,#EDIVLD,dc_cont1
    ldab    #EE_ERR_INIT            ; EEP not initialized.
    bra     dc_exit
dc_cont1:
    movb    #(PVIOL|ACCERR),ESTAT   ; Clear pending errors.
    brclr   ESTAT,#CBEIF,*          ; Wait for Command-Buffers ready.
;; IAR
    andb    #0xfe                   ; even alignment.
    exg     y,d                     ; switch addr+data (IAR).
    std     0,y
;;
    movb    2,sp,ECMD               ; Write Command.

    movb    #CBEIF,ESTAT            ; Start Command.

    brclr   ESTAT,#(PVIOL|ACCERR),dc_cont2  ; any errors occurred?

    brclr   ESTAT,#PVIOL,dc_cont2   ; Protection violation?
    movb    #PVIOL,ESTAT
    ldab    #EE_ERR_PVIOL
    bra     dc_exit

    brclr   ESTAT,#ACCERR,dc_cont2  ; Access error?
    movb    #ACCERR,ESTAT
    ldab    #EE_ERR_ACC
    bra     dc_exit

dc_cont2:
    brclr   ESTAT,#CCIF,*           ; Wait for Command completion.
    ldab    #EE_ERR_OK
dc_exit:
    clra
    rts


;
;   boolean S12Eep_VerifyErase(void);
;
S12Eep_VerifyErase:
    movb    #EE_ERASE_VERIFY,1,-sp
    ldd     #0x0800 ; arbitrary address+data.
    ldy     #0xdead
    jsr     S12Eep_DoCmd,pcr
    leas    1,sp
    tstb
    bne     ve_cont1
    brclr   ESTAT,#BLANK,ve_cont1
    ldab    #0x01
    bra     ve_exit
ve_cont1:
    clrb
ve_exit:
    clra
    rts


;
;   uint8 S12Eep_SectorErase(uint16 addr);
;
S12Eep_SectorErase:
;
;   addr ==> D
;
    tfr     d,y
    ldd     0,y
    cpd     #0xffff
    bne     es_cont
    ldd     2,y
    cpd     #0xffff
    bne     es_cont
    ldab    #EE_ERR_OK
    bra     es_exit     ; OK, Sector is erased.
es_cont:
    tfr     y,d
    ldy     #0xdead     ; arbitrary data.
    movb    #EE_SECTOR_ERASE,1,-sp    
    jsr     S12Eep_DoCmd,pcr
    leas    1,sp
es_exit:
    clra
    rts


;
;   uint8 S12Eep_ProgramWord(uint16 addr,uint16 data);
;
S12Eep_ProgramWord:
;
;   addr ==> D
;   data ==> Y
;
    movb    #EE_WORD_PROGRAM,1,-sp
    jsr     S12Eep_DoCmd,pcr
    leas    1,sp
    rts


;
;   uint8 S12Eep_MassErase(void);
;
S12Eep_MassErase:
    movb    #EE_MASS_ERASE,1,-sp
    jsr     S12Eep_DoCmd,pcr
    leas    1,sp
    rts


;
;   uint8 S12Eep_SectorModify(uint16 addr,uint32 data);
;
;   todo: uint32-Parameter 'data', außerdem optimierte Implementation!!!
;
;
S12Eep_SectorModify:
;
;   addr    ==> D
;   data    ==> SP+2(HI):SP+4(LO)
;

    brset   ECLKDIV,#EDIVLD,sm_cont1
    ldab    #EE_ERR_INIT            ; EEP not initialized.
    bra     sm_exit
sm_cont1:
    movb    #(PVIOL|ACCERR),ESTAT   ; Clear pending errors.
    brclr   ESTAT,#CBEIF,*          ; Wait for Command-Buffers ready.
    
    tfr     d,y
    movw    2,sp,0,y

    movb    #EE_SECTOR_MODIFY,ECMD  ; Write Command.
    movb    #CBEIF,ESTAT            ; Start Command.

    brclr   ESTAT,#(PVIOL|ACCERR),sm_cont2  ; any errors occurred?
    brclr   ESTAT,#PVIOL,sm_cont2   ; Protection violation?
    movb    #PVIOL,ESTAT
    ldab    #EE_ERR_PVIOL
    bra     sm_exit
    brclr   ESTAT,#ACCERR,sm_cont2  ; Access error?
    movb    #ACCERR,ESTAT
    ldab    #EE_ERR_ACC
    bra     sm_exit

sm_cont2:

    brclr   ESTAT,#CBEIF,*          ; Wait for Command-Buffers ready.
    
    movw    4,sp,2,y
    movb    #EE_WORD_PROGRAM,ECMD   ; Write Command.
    movb    #CBEIF,ESTAT            ; Start Command.    

    brclr   ESTAT,#(PVIOL|ACCERR),sm_cont3  ; any errors occurred?
    brclr   ESTAT,#PVIOL,sm_cont3   ; Protection violation?
    movb    #PVIOL,ESTAT
    ldab    #EE_ERR_PVIOL
    bra     sm_exit
    brclr   ESTAT,#ACCERR,sm_cont3  ; Access error?
    movb    #ACCERR,ESTAT
    ldab    #EE_ERR_ACC
    bra     sm_exit

sm_cont3:

    brclr   ESTAT,#CCIF,*           ; Wait for Command completion.
    ldab    #EE_ERR_OK

sm_exit:
    clra

    rts

;
;   void S12Eep_Relocate(uint16 *dest_addr);
;
S12Eep_Relocate:
    rts

CODE_END:
    END
