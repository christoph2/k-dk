
#include "S12_Pwm.h"
#include "Hw_Cfg.h"

/*
**
**  REFERENCES:
**  ===========
**  AN2612          - PWM GENERATION USING HCS12 TIMER CHANNELS
**  S12PWM8B8CV1    - HCS12 8-BIT, 8-CHANNEL PULSE WIDTH MODULATOR (PWM) BLOCK GUI
**
*/

static void S12Pwm_ResetCounter(uint8 ChannelNumber);

S12Pwm_StatusType S12Pwm_Init(void)
{    
    S12PWM_REG16(PWMPER01)=PWM.PwmPer01;
    S12PWM_REG16(PWMPER23)=PWM.PwmPer23;
    S12PWM_REG16(PWMPER45)=PWM.PwmPer45;
    S12PWM_REG16(PWMPER67)=PWM.PwmPer67;

    S12PWM_REG16(PWMDTY01)=PWM.PwmDty01;
    S12PWM_REG16(PWMDTY23)=PWM.PwmDty23;
    S12PWM_REG16(PWMDTY45)=PWM.PwmDty45;
    S12PWM_REG16(PWMDTY67)=PWM.PwmDty67;
    
    S12PWM_REG16(PWMCNT0)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT2)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT4)=(uint16)0x0000U;
    S12PWM_REG16(PWMCNT6)=(uint16)0x0000U;

    S12PWM_REG8(PWMPOL)=PWM.PwmPol;
    S12PWM_REG8(PWMCLK)=PWM.PwmClk;
    S12PWM_REG8(PWMPRCLK)=PWM.PwmPrClk;
    S12PWM_REG8(PWMCAE)=PWM.PwmCae;
    S12PWM_REG8(PWMSCLA)=PWM.PwmSclA;
    S12PWM_REG8(PWMSCLB)=PWM.PwmSclB;

    S12PWM_REG8(PWMSDN)=PWM.PwmSdn;    
    S12PWM_REG8(PWMCTL)=PWM.PwmCtl;
    S12PWM_REG8(PWME)=PWM.PwmE;         /* OK, start PWM.   */
/* prescaler = (E-Clock * 4)/10 */
    return S12PWM_OK;
}


void S12Pwm_SetTimebase(void)
{
}


void S12Pwm_SetDutyCycle(uint8 ChannelNumber,uint16 DutyCycle)
{
}


void S12Pwm_SetPeriodAndDuty(uint8 ChannelNumber,uint16 Period,uint16 DutyCycle)
{
    
}


void S12Pwm_SetOutputToIdle(uint8 ChannelNumber)
{
    /* einfach PWME löschen... */
}
                             
uint8 S12Pwm_GetOutputState(uint8 ChannelNumber)
{
    /* todo: read 'PTIP' */
}


void S12Pwm_ResetCounter(uint8 ChannelNumber)
{
    S12PWM_REG8(PWMCNT0+ChannelNumber)=(uint8)0x00;
}


#if 0
/*! \fn void p_set_tb(void)
 *      Zeitbasis (Prescaler einstellen).
 */
void p_set_tb(void)
{
    uint8 chn,timeb;
#if 0
    timeb=LOBYTE(VM_PopW());
    chn=LOBYTE(VM_PopW());
#endif
        
    switch (chn) {              /* todo: !!! TESTEN !!! */
        case 0: case 1:
            PWMPRCLK&=((uint8)0xF0);
            PWMPRCLK|=timeb;
            break;
        case 2: case 3:
            PWMPRCLK&=((uint8)0x0F);
            PWMPRCLK|=timeb<<4;
            break;
#if 0
        default:
            CC_ASSERT(FALSE,ERROR_ILLOPA);
#endif            
    }
}

/*! \fn void p_set_pm(void)
 *      Portmodus (push-pull od. open-drain).
 */
void p_set_pm(void)
{
    uint8 chn,mode;
#if 0  
    mode=LOBYTE(VM_PopW());
    chn=LOBYTE(VM_PopW());
#endif
/* Hinweis: Dummy, wird vom HCS12 nicht unterstützt. */
}

/*! \fn void p_set_pl(void)
 *      Periodenlänge einstellen.
 */
void p_set_pl(void)
{
#if 0
    uint8 chn;
    uint16 length;
        
    length=VM_PopW();
    chn=LOBYTE(VM_PopW());
#endif

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
#if 0
            default:
                CC_ASSERT(FALSE,ERROR_ILLOPA);
#endif
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
#if 0
    uint8 chn;
    uint16 value;
        
    value=VM_PopW();
    chn=LOBYTE(VM_PopW());
#endif

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
#if 0                
            default:
                CC_ASSERT(FALSE,ERROR_ILLOPA);
#endif
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
#if 0        
    tone=VM_PopW();
#endif
        
    if ((sint16)tone<0) {       /* negative Werte schalten die Ton-Ausgabe ab. */
        ToneOut(0x0000U);
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
#endif
