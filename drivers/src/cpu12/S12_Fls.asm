
/*
**  Hinweis: 'lbsr' ist eine Alternative zu 'jsr,pcr' !!!
*/

#if 0
MC9S12DP256B, Mask 2K79X
========================
========
CCIF command complete flag may be erroneously set.	MUCts00973
------------------------------------------------------------------

Description
-----------
When pipeline programming the flash NVM array, the CCIF (command
complete flag) may be momentarily set between pipelined commands. This
is due to a bug with the physical flash block interface which restarts
the next command as a new sequence when transitioning from one physical
flash row to the next, rather than recognising the next command as part
of an ongoing command sequence. Since the location of physical flash row
boundaries differs between devices, it is difficult to specify whether
CCIF flag set instances are erroneous or not. The workaround should be
closely followed to avoid this issue. 

Workaround
----------
The code which is checking for the end of command operations should
check for both CBEIF (Command Buffer Empty Interrupt Flag) and CCIF
(Command Complete Interrupt Flag) to be set, as an indication of the end
of operations, rather than just the CCIF Flag. 

#endif


#if 0
**
**  DP256-Flash-Geometry
**  =========================
**  num_blocks          (4)
**  pages_per_block     (4)
**  sectors_per_page    (32)
**  bytes_per_sector    (512)
**
#endif

;
;   Sector-Start-Addresses
;   ======================
;   512 byte sectors start at addresses $x000, $x200, $x400,$x600, $x800, $xA00, $xC00 and $xE00. 
;   1024 bytes sectors start at addresses $x000, $x400, $x800 and $xC00.
;
;   An erase sector is 4 bytes for EEPROM, 1024 bytes for a 128k byte Flash block and 512
;   bytes for all other Flash blocks.
;
;   Flash (but not EEPROM) also has a mode called Burst programming. Burst
;   programming is invoked by pipelining program commands for words on the
;   same Flash row. A row is 64 bytes on 32k and 64k byte Flash blocks and 128
;   bytes on the 128k Flash block. Burst programming reduces the programming
;   time by keeping the high voltage generation switched on between program
;   commands on the same row. Burst programming is approximately twice as fast
;   as single word programming.
;

#if 0
/*
**	Flash Block #0 enthält Bootloader und Interrupt-Vektoren.
**		außerdem vom Bank #0 ausgewählt sein, wenn in die
**		Bereiche 0x4000-0x7fff und 0xc000-0xffff geschrieben
**		werden soll!!!
*/

/*
** NON-BANKED-REGISTERS
** --------------------
** FCLKDIV
** FSEC
** (FACTORY-TEST)
** FCNFG
**
*/

#endif

    NAME    S12Fls

    PUBLIC  S12Fls_Init
    PUBLIC  S12Fls_PageSelect
    PUBLIC  S12Fls_DoCmd
    PUBLIC  S12Fls_VerifyErase
    PUBLIC  S12Fls_SectorErase
    
    PUBLIC  S12Fls_ProgramWord
    PUBLIC  S12Fls_BurstProgram

FLS_PPAGE_OFFSET    EQU     0x30    ; todo: Cfg-Parameters!!!
FE_CLK_DIV          EQU     ((16*1000)/200/8)-1
FLS_NUM_BANKS	    EQU     4
FLS_SECTOR_SIZE     EQU     512

;
;   Command-Codes.
;
FE_ERASE_VERIFY     EQU     0x05
FE_WORD_PROGRAM     EQU     0x20
FE_SECTOR_ERASE     EQU     0x40
FE_MASS_ERASE       EQU     0x41    
 
 
;
;   Module-Error-Codes.
;
FE_ERR_OK           EQU     0
FE_ERR_INIT         EQU     1
FE_ERR_PVIOL        EQU     2
FE_ERR_ACC          EQU     3
FE_ERR_ADDR         EQU     4

;
;   todo: Include-File!!!
;
PPAGE               EQU     0x0030

FCLKDIV             EQU     0x0100
; FCLKDIV-Bits.
FDIVLD      EQU     0x80
PRDIV8 	    EQU     0x40
FDIV5 	    EQU     0x20
FDIV4 	    EQU     0x10
FDIV3 	    EQU     0x08
FDIV2 	    EQU     0x04
FDIV1 	    EQU     0x02
FDIV0	    EQU     0x01


FSEC                EQU     0x0101
; FSEC-Bits.
KEYEN1      EQU     0x80
KEYEN0      EQU     0x40
NV5         EQU     0x20
NV4         EQU     0x10
NV3         EQU     0x08
NV2         EQU     0x04
SEC1        EQU     0x02
SEC0        EQU     0x01


FTSTMOD             EQU     0x0102
; FTSTMOD-Bits.
WRALL       EQU     0x10


FCNFG               EQU     0x0103
; FCNFG-Bits.
CBEIE       EQU     0x80
CCIE        EQU     0x40
KEYACC      EQU     0x20
BKSEL1      EQU     0x02
BKSEL0      EQU     0x01


FPROT               EQU     0x0104
; FPROT-Bits.
FPOPEN      EQU     0x80
NV6         EQU     0x40
FPHDIS      EQU     0x20
FPHS1       EQU     0x10
FPHS0       EQU     0x08
FPLDIS      EQU     0x04
FPLS1       EQU     0x02
FPLS0       EQU     0x01


FSTAT               EQU     0x0105
; FSTAT-Bits.
CBEIF       EQU     0x80
CCIF        EQU     0x40
PVIOL       EQU     0x20
ACCERR      EQU     0x10
BLANK       EQU     0x04


FCMD                EQU     0x0106
; FCMD-Bits.
CMDB6       EQU     0x40
CMDB5       EQU     0x20
CMDB2       EQU     0x04
CMDB0       EQU     0x01


FADDR               EQU     0x0108
FDATA               EQU     0x11a
;
; ***************************
;

FLS_BC_KEYS         EQU     0xFF00  ; eight Bytes, Backdoor Comparison Keys.

CODE_LEN  EQU       CODE_END-CODE_START    
    
    RSEG DATA16_C:CONST:REORDER:NOROOT(0)   ; Constant-Segment.
    

    RSEG CODE:CODE:REORDER:NOROOT(0)        ; Code-Segment.
CODE_START:
;
;   void S12Fls_Init(void);
;
S12Fls_Init:
    movb    #0x00,FCNFG
    movb    #(PRDIV8 | FE_CLK_DIV),FCLKDIV
    rts


;
;   void S12Fls_PageSelect(uint8 page);
;
S12Fls_PageSelect:
;
;   page ==> B
;
    pshb
    subb    #FLS_PPAGE_OFFSET
    lsrb
    lsrb    ; Divide by four.
    eorb    #(FLS_NUM_BANKS-1)
    bclr    FCNFG,#(FLS_NUM_BANKS-1)
    orab    FCNFG
    stab    FCNFG           ; Select Bank.
    movb    1,sp+,PPAGE     ; Select PPAGE.
    rts


S12Fls_ClearPendingErrors:
    pshd
    ldaa    #FLS_NUM_BANKS
cpe_loop:
    bclr    FCNFG,#(FLS_NUM_BANKS-1)
    tfr     a,b
    decb
    orab    FCNFG
    stab    FCNFG
    movb    #(PVIOL | ACCERR),FSTAT
    dbne    a,cpe_loop
    puld
    rts

;
;   uint8 S12Fls_DoCmd(uint8 cmd,uint8 page,uint16 addr,uint16 data);
;

S12Fls_DoCmd:
;
;   cmd     ==> B
;   page    ==> A
;   addr    ==> Y
;   data    ==> 2,sp
;

    brset   FCLKDIV,#FDIVLD,dc_cont1
    ldab    #FE_ERR_INIT    ; FLS not initialized.
    bra     dc_exit   
dc_cont1:
    jsr     S12Fls_ClearPendingErrors,pcr

    pshd
    tfr     a,b
    jsr     S12Fls_PageSelect,pcr
    puld

    brclr   FSTAT,#CBEIF,*  ; Wait for Command-Buffers ready.
;;  IAR
    movw    2,sp,0,y
;;
    stab    FCMD            ; Write Command.
    movb    #CBEIF,FSTAT    ; Start Command.

    brclr   FSTAT,#(PVIOL|ACCERR),dc_cont2  ; any errors occurred?
    
    brclr   FSTAT,#PVIOL,dc_cont2   ; Protection violation?
    movb    #PVIOL,FSTAT
    ldab    #FE_ERR_PVIOL
    bra     dc_exit

    brclr   FSTAT,#ACCERR,dc_cont2  ; Access error?
    movb    #ACCERR,FSTAT
    ldab    #FE_ERR_ACC
    bra     dc_exit
dc_cont2:
    brclr   FSTAT,#CCIF,*           ; Wait for Command completion.
    ldab    #FE_ERR_OK
dc_exit:
    clra
    rts

;
;   boolean S12Fls_VerifyErase(uint8 block_num);
;
S12Fls_VerifyErase:
;
;   block_num   ==> B
;

    andb    #(FLS_NUM_BANKS-1)
    eorb    #(FLS_NUM_BANKS-1)      ; Calculate first page of Block.
    ldaa    #FLS_NUM_BANKS
    mul
    addb    #FLS_PPAGE_OFFSET
    tfr     b,a    
    ldab    #FE_ERASE_VERIFY
    ldy     #0xaffe                 ; arbitrary address+data.
    movw    #0xdead,2,-sp    
    jsr     S12Fls_DoCmd,pcr
    leas    2,sp
    tstb
    bne     ve_cont1
    brclr   FSTAT,#BLANK,ve_cont1
    ldab    #0x01
    bra     ve_exit
ve_cont1:
ve_exit:
    clra
    rts


;
;   uint8 S12Fls_ProgramWord(uint8 page,uint16 addr,uint16 data);
;
S12Fls_ProgramWord:
;
;   page    ==> 2,sp
;   addr    ==> D
;   data    ==> Y
;
    exg     d,y
    pshd
    ldab    #FE_WORD_PROGRAM
    ldaa    4,sp
    jsr     S12Fls_DoCmd,pcr
    leas    2,sp

    rts


;
;   uint8 S12Fls_BurstProgram(uint8 page,uint16 start_addr,const uin8 *data,uint16 len);
;
S12Fls_BurstProgram:
;
;   page        ==> 2,sp
;   start_addr  ==> D
;   data        ==> Y
;   len         ==> 3,sp
;
    pshx

    brset   FCLKDIV,#FDIVLD,bp_cont1
    ldab    #FE_ERR_INIT    ; FLS not initialized.
    bra     bp_exit

bp_cont1:
    jsr     S12Fls_ClearPendingErrors,pcr
    
    tfr     d,x
    ldd     3+2,sp
    beq     bp_finish       ; check for len!=0.
    
    ldab    2+2,sp          
    jsr     S12Fls_PageSelect,pcr  ; Select PPAGE and BLOCK.
    
bp_loop:
    brclr   FSTAT,#CBEIF,*          ; Wait for Command-Buffers ready.
    movw    2,y+,2,x+               ; Write data to dst. address.
    movb    #FE_WORD_PROGRAM,FCMD   ; Write Command.
    movb    #CBEIF,FSTAT            ; Start Command.
    
    brclr   FSTAT,#(PVIOL|ACCERR),bp_cont2  ; any errors occurred?
    brclr   FSTAT,#PVIOL,bp_cont2   ; Protection violation?
    movb    #PVIOL,FSTAT
    ldab    #FE_ERR_PVIOL
    bra     bp_exit
    brclr   FSTAT,#ACCERR,bp_cont2  ; Access error?
    movb    #ACCERR,FSTAT
    ldab    #FE_ERR_ACC
    bra     bp_exit

bp_cont2:
    ldd     3+2,sp
    subd    #1
    std     3+2,sp
    bne     bp_loop
    
bp_finish:
    brclr   FSTAT,#CCIF,*           ; Wait for Command completion.
    ldab    #FE_ERR_OK
bp_exit:
    pulx
    rts


;
;   uint8 S12Fls_SectorErase(uint8 page,uint16 addr);
;
S12Fls_SectorErase:
;
;   page    ==> B
;   addr    ==> Y
;
    tfr     b,a
    ldab    #FE_SECTOR_ERASE
    movw    #0xdead,2,-sp   ; arbitrary data.
    jsr     S12Fls_DoCmd,pcr
    leas    2,sp
    tstb
    bne     se_cont
    brclr   FSTAT,#BLANK,se_cont
    ldab    #0x01
    bra     se_exit
se_cont:

se_exit:
    clra
    rts

;
;   uint8 S12Fls_MassErase(uint8 block_num);
;
;   Note:   A mass erase of the entire block is only possible when the FPLDIS,
;           FPHDIS and FOPEN bits are set, see section Parallel Flash Block
;           Programming.
;
S12Fls_MassErase:
;
;   block_num   ==> B
;
    andb    #(FLS_NUM_BANKS-1)
    eorb    #(FLS_NUM_BANKS-1)      ; Calculate first page of Block.
    ldaa    #FLS_NUM_BANKS
    mul
    addb    #FLS_PPAGE_OFFSET
    tfr     b,a    
    ldab    #FE_MASS_ERASE
    ldy     #0xaffe                 ; arbitrary address+data.
    movw    #0xdead,2,-sp    
    jsr     S12Fls_DoCmd,pcr
    leas    2,sp
    clra
    rts


CODE_END:
    END
        
