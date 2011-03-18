;
;  k_dk - Driver Kit for k_os (Konnex Operating-System based on the 
;  OSEK/VDX-Standard).
; 
;  (C) 2007-2010 by Christoph Schueler <github.com/Christoph2,
;                                       cpu12.gems@googlemail.com>
;
;  All Rights Reserved
;
;  This program is free software; you can redistribute it and/or modify
;  it under the terms of the GNU General Public License as published by
;  the Free Software Foundation; either version 2 of the License, or
;  (at your option) any later version.
;
;  This program is distributed in the hope that it will be useful,
;  but WITHOUT ANY WARRANTY; without even the implied warranty of
;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
;  GNU General Public License for more details.
;
;  You should have received a copy of the GNU General Public License along
;  with this program; if not, write to the Free Software Foundation, Inc.,
;  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
;

/*
**
**  DP256-Flash-Geometry
**  =========================
**  num_blocks          (4)
**  pages_per_block     (4)
**  sectors_per_page    (32)
**  bytes_per_sector    (512)
**
**  DP512-Flash-Geometry
**  =========================
**  num_blocks          (4)
**  pages_per_block     (8)
**  sectors_per_page    (16)
**  bytes_per_sector    (1024)
**
*/


    NAME    S12Fls

    PUBLIC  S12Fls_Init
    PUBLIC  S12Fls_DoCmd
    PUBLIC  S12Fls_VerifyErase

    PUBLIC  S12Fls_SectorErase
    PUBLIC  S12Fls_PageErase
    PUBLIC  S12Fls_MassErase

    PUBLIC  S12Fls_ProgramWord
    PUBLIC  S12Fls_BurstProgram

FLS_PAGE_ADDR       EQU     0x8000
FLS_PAGE_SIZE       EQU     0x4000

FLS_PPAGE_OFFSET    EQU     0x30

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
FDATA               EQU     0x011a
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

;
;   Hinweis: Fehler treten bereits nach 'Command'-Write auf!!!
;
    brclr   FSTAT,#(PVIOL|ACCERR),dc_cont2  ; any errors occurred?

    brclr   FSTAT,#PVIOL,dc_cont2   ; Protection violation?
    movb    #PVIOL,FSTAT
    ldab    #FE_ERR_PVIOL
    bra     dc_exit
; Die fehler-Prüfung ist nicht korrekt!!!
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
    brclr   FSTAT,#BLANK,se_cont    /* ???? */
    ldab    #0x01
    bra     se_exit
se_cont:

se_exit:
    clra
    rts

;
;   uint8 S12Fls_PageErase(uint8 page);
;
S12Fls_PageErase:
    pshb
    ldy     #FLS_PAGE_ADDR
pe_loop:
    ldab    0,SP
    jsr     S12Fls_SectorErase,pcr
    leay    FLS_SECTOR_SIZE,y

    cpy     #(FLS_PAGE_ADDR+FLS_PAGE_SIZE)
    bcs     pe_loop

pe_exit:
    leas    1,sp
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

