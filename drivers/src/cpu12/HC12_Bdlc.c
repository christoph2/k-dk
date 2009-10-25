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
#include "Hw_Cfg.h"
#include "HC12_Bdlc.h"

static void HC12Bdlc_NOIP(void);
static void HC12Bdlc_RXEOF(void);
static void HC12Bdlc_RXIFR(void);
static void HC12Bdlc_RDRF(void);
static void HC12Bdlc_TDRE(void);
static void HC12Bdlc_LOARB(void);
static void HC12Bdlc_CRCERR(void);
static void HC12Bdlc_SYMINV(void);
static void HC12Bdlc_WUP(void);

static const VoidFunctionType HC12Bdlc_Intr[]={
    HC12Bdlc_NOIP,HC12Bdlc_RXEOF,HC12Bdlc_RXIFR,
    HC12Bdlc_RDRF,HC12Bdlc_TDRE,HC12Bdlc_LOARB,
    HC12Bdlc_CRCERR,HC12Bdlc_SYMINV,HC12Bdlc_WUP,
};

#if 0
$00 0000    No interrupts pending                   (NOIP)
$04 0001    Received EOF                            (RXEOF)
$08 0010    Received IFR byte                       (RXIFR)
$0C 0011    BDLC Rx data register full              (RDRF)
$10 0100    BDLC Tx data register empty             (TDRE)
$14 0101    Loss of arbitration                     (LOARB)
$18 0110    Cyclical redundancy check (CRC) error   (CRCERR)
$1C 0111    Symbol invalid or out of range          (SYMINV)
$20 1000    Wakeup                                  (WUP)
#endif

void HC12Bdlc_Init(void)
{

}


static void BDLC_Handler(void);

/* ISR1(BDLC_Handler) */

void BDLC_Handler(void)
{
/*    BSVR>>2 */
}

static void HC12Bdlc_NOIP(void)
{

}


static void HC12Bdlc_RXEOF(void)
{

}


static void HC12Bdlc_RXIFR(void)
{

}


static void HC12Bdlc_RDRF(void)
{

}


static void HC12Bdlc_TDRE(void)
{

}


static void HC12Bdlc_LOARB(void)
{

}


static void HC12Bdlc_CRCERR(void)
{

}

static void HC12Bdlc_SYMINV(void)
{

}

static void HC12Bdlc_WUP(void)
{

}

#if 0
***************************************************************************
***************************************************************************
*                                                                         *
*         General BDLC Driver Routines for J1850 Communication            *
*                                                                         *
***************************************************************************
*                                                                         *
* File Name: gen_bdlc.asm                    Copyright (c) Motorola 1997  *
*                                                                         *
* Current Revision: 1.0                                                   *
* Current Release Level: RP                                               *
* Current Revision Release Date: 2/18/98                                   *
*                                                                         *
* Current Release Written By: Kim Sparks                                  *
*                             Motorola Systems Engineering - Austin, TX   *
*                                                                         *
* Assembled Under: CASM08 (P&E Micro Inc.)     Ver.: 3.06 SLD             *
*                                                                         *
* Project Folder Name: GEN_BDLC                                           *
*                                                                         *
*                                                                         *
* Part Family Software Routine Works With: HC08                           *
* Part Module(s) Software Routine Works With: bdlc_d20                    *
*                                             bdc_a20                     *
*                                                                         *
* Routine Size (Bytes):      312                                          *
* RAM Used (Bytes):           30                                          *
*                                                                         *
* Full Functional Description Of Routine Design:                          *
*                                                                         *
* This program demonstrates the main functionality of the BDLC module,    *
* including transmitting a message, receiving messages, filtering         *
* incoming messages, dealing with loss of arbitration and various errors. *
* It points out the correct procedures for programming the module and     *
* any idiosyncrasies with the BDLC module.                                *
*                                                                         *
* Immediately following a reset the message $55 $55 $55 $55 is loaded     *
* into a ram buffer and transmitted on the J1850 bus. The format of the   *
* message being transmitted consists of a three byte consolidated header  *
* followed by one data byte. In real-life user applications, the messages *
* used for J1850 communication will contain more data bytes and possibly  *
* a different header format. The one transmission following a reset is    *
* the only transmission that the program performs. This can be easily     *
* modified by loading the RAM buffer with another message and initiating  *
* a transmission.                                                         *
*                                                                         *
* As far as receiving messages, the program is designed to receive only   *
* messages that contain a $55 in the second byte.  The program will       *
* filter out messages that don't meet this criteria. If the message       *
* $6c $55 $01 $04 is received, then the module will switch into 4x        *
* receive mode and start receiving messages at 41.6 Kbps.                 *
*                                                                         *
* This program was developed for the 68HC908AS20 and 68HC908AT60, but it  *
* will work with any HC08 that has the BDLC ver. bdlc_d20 or greater.     *
* The other hardware used in the application was a 4.0 MHz canned         *
* oscillator to clock the AS20 and a HIP7020 transceiver to waveshape the *
* the J1850 messages.                                                     *
*                                                                         *
***************************************************************************
*                                                                         *
* Motorola reserves the right to make changes without further notice to   *
* any product herein to improve reliability, function, or design. Motorola*
* does not assume any liability arising out of the application or use of  *
* any product, circuit, or software described herein; neither does it     *
* convey any license under its patent rights nor the rights of others.    *
* Motorola products are not designed, intended, or authorized for use as  *
* components in systems intended for surgical implant into the body, or   *
* other applications intended to support life, or for any other           *
* application in which the failure of the Motorola product could create a *
* situation where personal injury or death may occur. Should Buyer        *
* purchase or use Motorola products for any such intended or unauthorized *
* application, Buyer shall indemnify and hold Motorola and its officers,  *
* employees, subsidiaries, affiliates, and distributors harmless against  *
* all claims, costs, damages, and expenses, and reasonable attorney fees  *
* arising out of, directly or indirectly, any claim of personal injury or *
* death associated with such unintended or unauthorized use, even if such *
* manufacture of the part. Motorola claim alleges that Motorola was       *
* negligent regarding the design or and the Motorola Logo are registered  *
* trademarks of Motorola Inc.                                             *
*                                                                         *
***************************************************************************
*****                            Equates                              *****
***************************************************************************

***  BDLC Register Equates  ***

bard            equ     $3b     ;BDLC analog and roundtrip delay
bcr1            equ     $3c     ;BDLC control register 1
bcr2            equ     $3d     ;BDLC control register 2
bsvr            equ     $3e     ;BDLC state vector register
bdr             equ     $3f     ;BDLC data register

*** BARD Bit Assignments ***

ate             equ     7       ;Analog transceiver enable bit
rxpol           equ     6       ;Receive pin polarity bit
bo3             equ     3       ;Bard offset bit 3
bo2             equ     2       ;Bard offset bit 2
bo1             equ     1       ;Bard offset bit 1
bo0             equ     0       ;Bard offset bit 0

*** BCR1 Bit Assignments ***

imsg            equ     7       ;Ignore message bit
clks            equ     6       ;Clock bit
r1              equ     5       ;Rate select bit 1
r0              equ     4       ;Rate select bit 0
test1           equ     3       ;Mode pins when using an MMDS
test0           equ     2       ; dev. sys with EM board
ie              equ     1       ;Interrupt enable bit
wcm             equ     0       ;Wait clock mode bit

*** BCR2 Bit Assignments ***

aloop           equ     7       ;Analog loopback mode bit
dloop           equ     6       ;Digital loopback mode bit
rx4xe           equ     5       ;Receive 4x enable bit
nbfs            equ     4       ;Normalization bit format select bit
teod            equ     3       ;Transmit end of data bit
tsifr           equ     2       ;Transmit single byte IFR with no CRC bit
tmifr1          equ     1       ;Transmit multiple byte IFR with CRC bit
tmifr0          equ     0       ;Transmit multiple byte IFR without CRC bit

*** BDLC Interrupt Sources ***

eof             equ     $04     ;Received an end of frame
rxifr           equ     $08     ;Received IFR byte
rdrf            equ     $0c     ;BDLC Rx data register full
tdre            equ     $10     ;BDLC Tx data register empty
loa             equ     $14     ;Loss of arbitration
crc_err         equ     $18     ;Cyclical redundancy check error
invalid         equ     $1c     ;Symbol invalid or out of range
wake_up         equ     $20     ;Wakeup

*** General Equates for the MC68HC08AS20  ***

ram             equ     $50     ;User RAM
rom             equ     $ae00   ;User ROM
config          equ     $1f     ;Configuration register

bdlc_vec        equ     $ffdc   ;BDLC interrupt vector (high)
reset           equ     $fffe   ;Reset vector (high)


***************************************************************************
*****                   HC08 RAM Storage Assignments                  *****
***************************************************************************

                org     ram

*** BDLC Flags ***

retx_flag       rmb     $1      ;Retransmit flag
rc4x_flag       rmb     $1      ;4x mode flag
loa_flag        rmb     $1      ;Loss of arbitration flag

*** Transmit Message Count and Buffer ***

tdre_cnt        rmb     $1      ;Total number of bytes that have been
                                ; transmitted
tx_message      rmb     $d      ;Transmit buffer, first byte is the # of
                                ; bytes in the message to transmit & the
                                ; remaining bytes make up the message

*** Receive Message Count and Buffer ***

rc_message      rmb     $d      ;Receive buffer, first byte is the # of
                                ; bytes received & remaining bytes are
                                ; the message


***************************************************************************
*****                        Main Program                             *****
***************************************************************************

***************************************************************************
* Following a reset the BDLC and MCU are initialized, and the transmit
* routine is called.  Once the first byte of the message is loaded into the
* the BDR the program stays in a loop that checks to see if the message
* needs to be retransmitted.
***************************************************************************

        org     rom
start:  mov     #$03,config     ;Enable the stop instruction & disable
                                ; the COP
        jsr     bdlc_init       ;Initialize the BDLC module
        jsr     mcu_init        ;Initialize the MCU

retran: jsr     transmit        ;Transmit a message

        clra                    ;Check for loss of arbitration or CRC
here:   cbeq    retx_flag,here  ; error, retransmit the message if set
        clr     retx_flag       ;Reset the error flag
        bra     retran          ;Branch back to the where the transmit
                                ; routine is called


***************************************************************************
*****                BDLC Initialization Subroutine                   *****
***************************************************************************

***************************************************************************
* To initialize the BDLC there are three main steps. First initialize the
* BARD, BCR2 & BCR1. Leave the BDLC in digital and analog loopback modes
* such that loopback tests can be performed. Exit from loopback mode and
* clear any pending interrupts. Finally enable the BDLC interrupts.
***************************************************************************

bdlc_init:
        mov     #$07,bard       ;Select off-chip analog Xcver with
                                ; inverted polarity, 16 us delay
        mov     #$c0,bcr2       ;Remain in loopback modes, set NBFS if using
                                ; IFS, leave last 4 bits 0's to prevent
                                ; undesirable BDLC operation
        mov     #$ac,bcr1       ;Ignore messages until a valid SOF, Set up
                                ; the clocks, set bits 2 & 3 for emulation

                                ;User should perform loopback tests if
                                ; desired

        mov     #$00,bcr2       ;Exit out of A & D loopback modes

int_chk:
        ldx     bsvr            ;Read BDLC status register
        cbeqx   #$00,en_int     ;Check if a status flag has been set
        jmp     bdlc_int        ;Service set flags
        bra     int_chk         ;Branch to check status register

en_int: mov     #$ae,bcr1       ;Enable BDLC interrupts
        rts

***************************************************************************
*****                MCU Initialization Subroutine                    *****
***************************************************************************

***************************************************************************
* This subroutine clears the appropriate RAM variables used by the program,
* and delays for one EOF time period (~280 us). This delay allows the
* BDLC to monitor the bus and enable the receiver circuitry internally
* after it sees the bus idle for an EOF time period.  Since the IMSG bit is
* left set until the first SOF is received, there will not be an EOF
* interrupt.  When the first SOF is received the IMSG bit is automatically
* cleared by the hardware.
*
* The final step of the microcontroller's initialization is to clear its
* interrupt mask bit.
***************************************************************************

mcu_init:
        clr     tdre_cnt        ;Clear all flags, counters and the first
        clr     retx_flag       ; byte of the transmit and receive buffers
        clr     loa_flag
        clr     rc4x_flag
        clr     rc_message
        clr     tx_message
        jsr     eof_delay       ;Delay for one EOF time period

        cli                     ;Clear interrupt mask bit for MCU

        rts                     ;Return from subroutine

***************************************************************************
*****                 BDLC Transmit Subroutine                        *****
***************************************************************************

***************************************************************************
* This subroutine moves the message $04 $55 $55 $55 $55 into the
* tx_message RAM buffer.  The first byte represents how many data bytes
* are in the message.  The following four bytes are the actual data bytes
* that will be transmitted on the bus.  After the RAM buffer is loaded the
* first data byte of the message is loaded into the BDR, which initiates
* the transmission.  The tdre_cnt counter is incremented to keep track of
* how many bytes have been transmitted.
***************************************************************************

transmit:
        mov     #$04,tx_message ;Load the number of bytes to transmit
                                ; to the transmit buffer
        mov     #$55,tx_message+1;Load first byte of the message to the
                                 ; transmit buffer
        mov     #$55,tx_message+2;Load second byte of the message to the
                                ; transmit buffer
        mov     #$55,tx_message+3;Load third byte of the message to the
                                ; transmit buffer
        mov     #$55,tx_message+4;Load fourth byte of the message to the
                                ; transmit buffer

        lda     tx_message+1    ;Transmit the first byte of the
        sta     bdr             ; message
        inc     tdre_cnt        ;Increment the transmit byte counter
        rts

***************************************************************************
*****                     EOF Delay Subroutine                        *****
***************************************************************************

***************************************************************************
* This subroutine delays for approximately one EOF time period (280 us).
***************************************************************************

eof_delay:                      ;Delay for approx. 280 us or 1 EOF period
        lda     #$5b            ;2 cycles => 2 us
inner:  dbnza   inner           ;3 cycles => 3 us x 91 = 273 us
        rts                     ;4 cycles => 4 us
                                ;Total = 2 + 273 + 4 = 279 us

***************************************************************************
*****                  BDLC Interrupt Service Routine                 *****
***************************************************************************

***************************************************************************
* The key to servicing the interrupts generated by the BDLC is to use a
* jump table.  The value in the BSVR is used to index to the correct
* location in the jump table.  When the BSVR is accessed by the user's
* software, the bit value read reflects only the highest priority
* interrupt. Once that interrupt is cleared, any pending interrupts are set.
*
* The following is a summary of the actions taken by the each interrupt
* service routine:
* $00 - No Interrupts Pending.  This interrupt service routine should
*       never happen.
* $04 - EOF Interrupt. First, the routine checks to see if loss of arbi--
*       tration occurred. If so, then the message that needs to be retrans-
*       mitted has already been loaded by the program and the transmit
*       RAM variables should not be cleared, only the receiver variables.
*       Next, the routine checks to see if the EOF was a result of transmit-
*       ting a message or receiving one.  If it was result of transmitting,
*       then the transmitter & receiver RAM variables are cleared. If the
*       EOF was a result of receiving a message, then the received message
*       is analyzed to see if the BDLC should switch into 4x receive mode or
*       not. If so, then it is switched and the receiver RAM variables are
*       cleared. If not, then just the receiver RAM variables are cleared.
* $08 - RXIFR Interrupt. IFR is not used in this program, so this interrupt
*       should not happen.
* $0C - RDRF Interrupt. This interrupt occurs when a data byte is received.
*       Two things are checked as the bytes are received. First does the
*       second byte = $55 if not then ignore the rest of the message.
*       Second, does the first 4 bytes of the message = $6c $55 $01 $04?
*       If so, then switch into 4x receive mode.
* $10 - TDRE Interrupt. This routine continues to transmit the message
*       that has been stored in the tx_message buffer.  If the last byte
*       has been sent, then an EOD is transmitted.
* $14 - LOA Interrupt. In this routine, the loss of arbitration and
*       retransmit RAM variables are set, and the transmit counter is
*       cleared. That way the message to be transmitted will be loaded
*       and transmitted again.
* $18 - CRC Error flag. If the CRC error occurred during a transmission
*       then the retransmit RAM variable is set. Also the transmit and
*       receiver RAM variables are cleared.  If the CRC error occurred
*       while receiving a message, then only the receiver RAM variables
*       are cleared.
* $1C - Symbol Invalid Interrupt. Same sequence is used as for a CRC error,
*       except that an EOF delay (~280 us) is added before the software
*       returns from the interrupt service routine. The delay is added
*       because after an invalid symbol interrupt the BDLC module needs to
*       see the bus idle for an EOF time period.  This ensures that there
*       isn't still a fault on the bus.  An EOF interrupt will be generated
*       once the EOF time period has expired.
* $20 - Wakeup flag. Low power modes are not being used in this program,
*       so this interrupt should never occur.
***************************************************************************

bdlc_int:
        pshh                    ;Push H onto the stack
        clrh                    ;Clear H. This will ensure that the indexed
                                ; addressing will jump to the correct BDLC
                                ; routine
        ldx     bsvr            ;Read the bsvr value
        jmp     jmptab,x

jmptab: jmp     serve0          ;Jump to no interrupt service
        nop
        jmp     serve1          ;Jump to EOF interrupt service
        nop
        jmp     serve2          ;Jump to RxIFR interrupt service
        nop
        jmp     serve3          ;Jump to RDRF interrupt service
        nop
        jmp     serve4          ;Jump to TDRE interrupt service
        nop
        jmp     serve5          ;Jump to LOA interrupt service
        nop
        jmp     serve6          ;Jump to CRC error interrupt service
        nop
        jmp     serve7          ;Jump to symbol invalid interrupt service
        nop
        jmp     serve8          ;Jump to wake up interrupt service


****************************** No Interrupt *******************************

serve0: pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return


***************************** EOF Interrupt *******************************

serve1: lda     #$01            ;Check to see if a LOA occurred
        cbeq    loa_flag,clear_loa
                                ;If so, then skip clearing the transmit
                                ; flags because the BDR is loaded with
                                ; the message to retransmit

        clra                    ;Check to see if the EOF occurred because of
        cbeq    tdre_cnt,check_4x ;a transmission or just reception of a message

        clr     tdre_cnt        ;If EOF occurred because a message was trans-
        clr     tx_message      ; mitted then clear transmission flags
        jmp     no_rc4x         ;Skip to where the receiver RAM variables
                                ; are cleared

clear_loa:
        clr     loa_flag        ;Clear the LOA flag and continue with
                                ; clearing the proper receiver flags

check_4x:
        lda     rc4x_flag       ;Check to see if the message just received
        cmp     mode_4x         ; signaled for the node to switch into 4x
        bne     no_rc4x         ; receive mode

        mov     #$20,bcr2       ;Enable 4x mode

no_rc4x:
        clr     rc4x_flag       ;Do not switch in 4x mode
        clr     rc_message      ;Clear the receive byte count
        pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


**************************** RxIFR Interrupt ******************************

serve2: pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Not using IFR, return


**************************** RDRF Interrupt *******************************

serve3: lda     bdr             ;Store the receive byte of BDLC data to
                                ; acc. and clear the RDRF flag

        ldx     rc_message      ;Load the count byte into the index reg.
        sta     rc_message+1,X  ;Store received byte to receive RAM buffer
        inc     rc_message      ;Increment to next RAM location
        ldx     rc_message      ;Load the index reg. with the byte # received
        cbeqx   #$01,byte_1
        cbeqx   #$02,byte_2
        cbeqx   #$03,byte_3
        cbeqx   #$04,byte_4
        jmp     return

byte_1:
        cmp     byte1           ;Compare the 1st byte received with the
                                ; 1st byte in the message look up table
        bne     return          ;If the bytes are not equal then return
        inc     rc4x_flag       ;Increment the 4x mode flag
        jmp     return


byte_2:
        cmp     byte2           ;Compare the 2nd byte received with the
                                ; 2nd byte in the message look up table
        beq     keep_mes        ;If the bytes equal keep the message

        bset    imsg,bcr1       ;If not, ignore the message
        clr     rc_message      ;Clear the number of bytes received
        clr     rc4x_flag       ;Clear the 4x mode flag
        jmp     return
keep_mes:
        inc     rc4x_flag       ;Increment the 4x mode flag
        jmp     return


byte_3:
        cmp     byte3           ;Compare the 3rd byte received with the
                                ; 3rd byte in the message look up table
        bne     return          ;If they don't match, then continue
        inc     rc4x_flag       ;If they match, then increment the 4x
                                ; mode flag
        jmp     return


byte_4:
        cmp     byte4           ;Compare the 4th byte received with the
                                ; 4th byte in the message look up table
        bne     return          ;If they don't match, then continue
        inc     rc4x_flag       ;If they match, then increment the 4x
                                ; mode flag
return:
        pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti


**************************** TDRE Interrupt *******************************

serve4: lda     tx_message      ;Load the acc with the number of bytes
                                ; that have been transmitted
        cbeq    tdre_cnt,txdone ;Compare it with the number of total
                                ; bytes in the message to transmit,
                                ; branch if equal
        inc     tdre_cnt        ;Increment transmit byte counter
        ldx     tdre_cnt        ;Load the number of the byte to transmit
                                ; in the index reg.
        lda     tx_message,X    ;Load the byte to transmit in acc
        sta     bdr             ;Transmit byte
        bra     ret4            ;Jump to return
txdone: bset    teod,bcr2       ;Transmit an EOD on the bus
ret4:   pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


***************************** LOA Interrupt *******************************

serve5: inc     loa_flag        ;Increment the loa flag
        inc     retx_flag       ;Increment retransmit flag because a LOA
                                ; occurred during arbitration
        clr     tdre_cnt        ;Clear transmit byte counter
        pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


************************** CRC Error Interrupt ****************************

serve6: clra                    ;Check if the CRC error occurred during
        cbeq    tdre_cnt,rec6   ; message reception from another node.
                                ; If so, jump to rec6

        clr     tdre_cnt        ;Clear the transmit byte count
        inc     retx_flag       ;If not, then retransmit the message

rec6:                           ;CRC error occurred while receiving a
                                ; message from another node
        clr     rc4x_flag       ;Clear the 4x mode flag
        clr     rc_message      ;Clear the receive byte count
                                ;*User may want to add s/w here*
        pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


************************* Symbol Invalid Interrupt ************************

serve7: clra                    ;Check if the Sym Inv error occurred during
        cbeq    tdre_cnt,rec7   ; message reception from another node.
                                ; If so jump to rec7

        clr     tdre_cnt        ;Clear the transmit byte count
        inc     retx_flag       ;If not, then retransmit the message

rec7:                           ;Inv Sym occurred while receiving a
                                ; message from another node
        clr     rc4x_flag       ;Clear the 4x mode flag
        clr     rc_message      ;Clear the receive byte count
                                ;*User may want to add s/w here*
        jsr     eof_delay       ;Delay for the eof to be generated
        pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


**************************** Wake Up Interrupt ****************************

serve8: pulh                    ;Pull the H to return to previous operating
                                ; conditions
        rti                     ;Return from the interrupt


***************************************************************************
*****                     Message Look Up Table                       *****
***************************************************************************

***************************************************************************
* These are the bytes that have to be received in order to switch the part
* into 4x receive mode.
***************************************************************************

mode_4x         fcb     $04
byte1           fcb     $6c
byte2           fcb     $55
byte3           fcb     $01
byte4           fcb     $04


***************************************************************************
*****                  MC68HC08AS20 Reset Vectors                     *****
***************************************************************************

        org     bdlc_vec        ;BDLC interrupt vector
        fdb     bdlc_int

        org     reset           ;Reset interrupt vector
        fdb     start

#endif
