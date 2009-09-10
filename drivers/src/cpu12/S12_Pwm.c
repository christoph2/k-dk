/*! \file pwm.c
 *      \brief GERÄTETREIBER: Pulsbreiten-Modulator und Sound-Erzeugung.
 *
 *      t.b.d
 */

/*
;
;                       PWM-Modul für MCS12 (25MHz).
;

;
;                       'Beep': Genauigkeit über fünf Oktaven (1:64).
;
;
;                       'p_set_pl' und 'p_out' sind von der Port-Adresse identisch!

;
;                       'setmode': Push-Pull od. Open-Drain.
;

;                       T(µs)                    Prescaler               Value (PCKA,PCKB)
;                       0,40                     1                                               0
;                       0,80                     2                                               1
;                       1,60                     4                                               2
;                       3,20                     8                                               3
;                       6,40                     16                                              4
;                       12,80                    32                                              5
;                       25,60                    64                                              6
;                       51,20                    128                                     7

; 'Value' entspricht den 'Timebase'-Konstanten!!!


;       todo: center-aligned operation.

MHZ=25  ; Bustakt in MHz.
BUSCLOCK=MHZ*1000*1000

_pwm_tab:
        .word   p_init,p_set_tb,p_set_pm,p_set_pl,p_out,p_beep
*/

#include "S12_Pwm.h"
#include "exception.h"

/*
** AN2612                       - PWM GENERATION USING HCS12 TIMER CHANNELS
**      S12PWM8B8CV1    - HCS12 8-BIT, 8-CHANNEL PULSE WIDTH MODULATOR (PWM) BLOCK GUI
**
*/

/*
** Oktave von A (220Hz) bis GIS1 (415,4Hz) auf der Zeitbasis 2 (800ns).
*/
static const uint16 __tone_tab[12]=
{
        /* 56818,53625,50628,47783,45922,42560,40167,37913,35796,33784,31888,30091 */
    0xDDF2,0xD179,0xC5C4,0xBAA7,0xB362,0xA640,0x9CE7,0x9419,0x8BD4,0x83F8,0x7C90,0x758B 
};

/*
**  Module-Function-Prototypes.
*/
void p_init(void),p_set_tb(void),p_set_pm(void),p_set_pl(void),p_out(void),p_beep(void);

/*
**  Sprungtabelle.
*/
static const PVOID_FUNC FuncTab[PLM_CODE_MAX+1]=
{
    p_init,p_set_tb,p_set_pm,p_set_pl,p_out,p_beep
};

static void ToneOut(uint16 tone);

void Plm(void)
{
    CC_ASSERT(VM_OperandB<SIZEOF_ARRAY(FuncTab),ERROR_ILLOPA);
    FuncTab[VM_OperandB]();
}

/*! \fn void p_init(void)
 *      PWM-Subsystem-Initialisieren.
 */
void  p_init(void)
{
    PWME=((uint8)0x00);     /* PWM-Subsystem vorsichtshalber deaktivieren. */

    PERP=((uint8)0xAA);     /* Pullups für unbenutzte Ports. */
    DDRP=((uint8)0xAA);     /* unbenutzte Ports als Eingänge. */
    RDRP=((uint8)~(0xAA));  /* Ports 1,3,5,7 full drive. */
    PWMPOL=((uint8)0xff);   /* alle Kanäle hi-aktiv. */

    PWMSCLA=((uint8)0x05);
    PWMSCLB=((uint8)0x05);  /* ein Skalierungs-Faktor von 10 (PWMSCLA*2) entspricht */
                            /* bei 25Mhz einem Basis-Zyklus von 400ns. */
    PWMCLK=((uint8)0xAA);   /* Scaled Clock-A bzw. -B verwenden. */
    PWMPRCLK=((uint8)0x00); /* kein Prescaler; dieser mit mit 'setTimeBase' eingestellt. */
    PWMCAE=((uint8)0x00);   /* alle Channels left-aligned. */

    PWMPER01=PWMPER23=PWMPER45=PWMPER67=((uint16)0xFFFF);
    PWMDTY01=PWMDTY23=PWMDTY45=PWMDTY67=((uint16)0x0000);       
        
    PWMCTL=((uint8)0xF0);   /* vier 16Bit-Kanäle (P7,P5,P3,P1) */
    PWME=((uint8)0xAA);     /* alle PWM Channels aktivieren. */
}

/*! \fn void p_set_tb(void)
 *      Zeitbasis (Prescaler einstellen).
 */
void p_set_tb(void)
{
    uint8 chn,timeb;
        
    timeb=LOBYTE(VM_PopW());
    chn=LOBYTE(VM_PopW());
        
    switch (chn) {              /* todo: !!! TESTEN !!! */
        case 0: case 1:
            PWMPRCLK&=((uint8)0xF0);
            PWMPRCLK|=timeb;
            break;
        case 2: case 3:
            PWMPRCLK&=((uint8)0x0F);
            PWMPRCLK|=timeb<<4;
            break;                      
    }
}

/*! \fn void p_set_pm(void)
 *      Portmodus (push-pull od. open-drain).
 */
void p_set_pm(void)
{
    uint8 chn,mode;
        
    mode=LOBYTE(VM_PopW());
    chn=LOBYTE(VM_PopW());
/* Hinweis: Dummy, wird vom HCS12 nicht unterstützt. */
}

/*! \fn void p_set_pl(void)
 *      Periodenlänge einstellen.
 */
void p_set_pl(void)
{
    uint8 chn;
    uint16 length;
        
    length=VM_PopW();
    chn=LOBYTE(VM_PopW());

    if (chn<=3) {
        switch (chn) {
            case 0:
                PWMPER01=length;
                break;
            case 1:
                PWMPER23=length;
                break;
            case 2:
                PWMPER45=length;
                break;
            case 3:
                PWMPER67=length;
                break;
        }
    }
}

/*! \fn void p_out(void)
 *      PWM-Ausgabe starten (duty-count setzen) / stoppen.
 */

/*
; check: Verhalten der 'boundary-cases' mit der CC2 vergleichen!!!
;                        CC2: duty==0 ==> Lowpegel; duty>=period ==> Highpegel.
;                                (Scheint auf den ersten Blick zu stimmen).
*/
void p_out(void)
{
    uint8 chn;
    uint16 value;
        
    value=VM_PopW();
    chn=LOBYTE(VM_PopW());

    if (chn<=3) {
        switch (chn) {
            case 0:
                PWMDTY01=value;
                break;
            case 1:
                PWMDTY23=value;
                break;
            case 2:             
                PWMDTY45=value;
                break;
            case 3:
                PWMDTY67=value;
                break;  
        }
    }
}

static void ToneOut(uint16 tone)        /* todo: Makro (wirklich???) */
{
    PWMPER45=tone;              /* 3.ter PWM-Kanal. */
    PWMDTY45=tone>>1;   /* symmetrisches Rechteck. */
}

/*! \fn void p_beep(void)
 *      Piepen.
 */

/*
 todo: Skalierung in Abhängigkeit der Zeitbasis (>=800ns).
*/
void p_beep(void)
{
    uint16 tone,oct;
        
    tone=VM_PopW();
        
    if ((sint16)tone<0) {       /* negative Werte schalten die Ton-Ausgabe ab. */
        ToneOut(0x0000);
    } else {
        oct=tone/12;
        tone%=12;
        tone=__tone_tab[tone];  /* check: evtl. -1??? */
        
        if (oct==0) {

        } else {
                
        }
    }

        /*
p_beep:
        jsr             VM_PopW ; tone.
        cpd             #$ffff
        bne             beep_cont
;
;                       $ff==-1 schaltetet die Tongenerierung ab;
;                                                       ansonsten Oktavskalierung.
        ldd             #0
        bra             tone_out

beep_cont:
        clra
        pshx
        ldx             #12
        idiv
;
;                       AccD: Ton-# ==> Tabellenoffset/2.
;                       AccX: Oktave (shift-right amount) des Tons.
;               
        ldy             #_tone_tab
        ldaa    #2
        mul
        ldd             d,y     ; Absolutwert des Tones.

        cpx             #0
        bne             chk_div ; unterste Oktave?
        tst             PWMPRCLK
        bne             chk_div ; kleinste Zeitbasis?
        lsld
        bra             tone_out

chk_div:
;
; Ton in Abhängigkeit der Zeitbasis skalieren.
;
        pshd    
        ldab    PWMPRCLK
        subb    #1              ; relativ zur TB 800ns.

        clra
        exg             x,d
        pshx
        addb    1,sp
        tfr             d,x
        leas    2,sp
        puld

        cpx             #0
        beq             no_div
;
; Oktavieren.
;       
div_loop:
        lsrd
        dbne    x,div_loop

no_div:
tone_out:

;
;       PWM-Ausgabe.
;
        std             PWMPER45         ; 3.ter PWM-Kanal.
        lsrd
        std             PWMDTY45         ;  symmetrisches Rechteck.
        pulx

        rts
        */
}

