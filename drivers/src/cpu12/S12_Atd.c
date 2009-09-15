/*
Here's a filter technique we have used on many projects.
AVERAGE = [ ( 7 * OLD ) + ( 1 * NEW ) ] / 8
In other words, an average is calculated over 8 values. Each time you get a
new ADC reading, you multiply OLD (the old average) by 7, then add NEW (the
new ADC sample), and divide that sum by 8. Intermediate results are
typically calculated to 16-bit precision, even though the resolution of the
ADC samples is typically 8 or 10 bits.

We use adds and shifts, no multiplies or divides. In other words, shift OLD
over three times (x 8), subtract OLD (the old value), add in NEW, then shift
the result right three times. This runs very fast.
We call this a "7/8" filter. It's a medium-speed filter (depending of course
on how often you sample the ADC and execute this routine).
For a faster filter we use a 3/4 filter, or for slower response we use a
15/16 filter, or 31/32, etc. The denominator is always a power of 2, and the
weighting of the old average is [2^N - 1]. By using binary denominators, the
shift/subtract/add/shift technique helps optimize the speed of the filter.
These are simple but effective IIR filters.
Another idea that might be useful. If this is a line-powered system, you can
easily get 50/60/100/120 Hz power supply noise that can cause a fraction of
a bit of dither, no matter how good the PCB layout is. It's not easy to
reduce the AC noise floor below about 20 millivolts. Try setting the ADC
sample rate to a multiple of the line frequency--such as 600 or 1200 samples
per second, which handles both 50 and 60 Hz (and their rectified offshoots
of 100 Hz and 120 Hz). That way you will always be sampling at just about
the same phase of the line voltage, effectively notching out that
interference source. Synchronous sampling can replace a lot of brute force
filtering, and the only cost is setting the sample rate properly.
Hope this is helpful.
*/

/* AVG=((OLD<<3)-OLD+NEW)>>3 */

#include "S12_Atd.h"
#include "Hw_Cfg.h"

/*
**
**  ATD_10B8C-Module-Driver.
**
**
*/

/*
**
**  REFERENCES
**  ==========
**  ATD_10B8C Block User Guide V02.12.
**
*/

static uint8 S12Atd_CalculatePrescaler(void);

static void S12Atd_Handler(const S12Atd_ConfigType *Cfg);

S12Atd_StatusType S12Atd_Init(S12Atd_ConfigType const * const Cfg)
{
    uint8 ctl;

    S12_REG8(Cfg,ATDCTL3)=((uint8)S8C|FRZ1);          /* todo: Sequence-Length!!! */
    S12_REG8(Cfg,ATDCTL4)=(((uint8)Cfg->ConversionTime)<<5)|S12Atd_CalculatePrescaler();
    if (Cfg->TenBit==FALSE) {
        S12_REG8(Cfg,ATDCTL4)|=SRES8;
    }
        
    S12_REG8(Cfg,ATDCTL5)=((uint8)DJM|MULT);
    if (Cfg->ContinuousConversion==TRUE) {
        S12_REG8(Cfg,ATDCTL5)|=SCAN;
    }
    
    S12_REG8(Cfg,ATDDIEN)=((uint8)0x00);    

    ctl=((uint8)ADPU|AFFC|AWAI);

    if (Cfg->ExternalTrigger!=S12ATD_EXT_TRIG_DISABLED) {
        ctl|=((uint8)Cfg->ExternalTrigger << 3) | ETRIGE;
    }
    
    if (Cfg->EnableCompletionInterrupt==TRUE) {
        ctl|=ASCIE;
    }
    S12_REG8(Cfg,ATDCTL2)=ctl;
    
    return S12ATD_OK;
}

S12Atd_StatusType S12Atd_GetChannel(S12Atd_ConfigType const * const Cfg,uint8 chn,uint16 *result)
{    
    chn&=((uint8)0x07);	
    WAIT_FOR((S12_REG8(Cfg,ATDSTAT0) & SCF) == SCF);   /* check!!! */
    *result=*(uint16*)(S12_REG16(Cfg,ATDDR0+(chn<<1)));	/* Right justified data (else divide by 0x40). */
    
    return S12ATD_OK;
}


uint8 S12Atd_CalculatePrescaler(void)
{
    uint8 bus_freq,res;

    (void)S12Crg_GetBusFreq(&bus_freq);
    res=bus_freq>>2;

    if (!(bus_freq & (uint8)0x03)) {
        res--;
    }
    
    return res;
}

static uint32 conversion_counter=0UL;

static uint16 result[8];

void S12Atd_Handler(const S12Atd_ConfigType *Cfg)
{
    uint8 idx;
    uint8 cc;
    uint8 ccf;
    
    S12_REG8(Cfg,ATDSTAT0)=SCF;
    cc=S12_REG8(Cfg,ATDSTAT0) & (uint8)0x07;
    ccf=S12_REG8(Cfg,ATDSTAT1);

    for (idx=0;idx<8;++idx) {
        result[idx]=S12_REG8(Cfg,ATDDR0+(idx<<1));
    }
    
    conversion_counter++;    
}


ISR1(ATD0_Vector)
{
    S12Atd_Handler(ATD0);
        
}
