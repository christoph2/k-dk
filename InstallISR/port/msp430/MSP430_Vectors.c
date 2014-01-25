/*
 * k_os (Konnex Operating-System based on the OSEK/VDX-Standard).
 *
 * (C) 2007-2013 by Christoph Schueler <github.com/Christoph2,
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

#if !defined(__MSP430_VECTORS_H)
#define __MSP430_VECTORS_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#include "mcu/inc/Derivatives.h"
#include "Sys_Cfg.h"

#if !defined(KDK_DERIVATIVE)
  #error Parameter KDK_DERIVATIVE not set!
#endif


#if (KDK_DERIVATIVE ==  __msp430afe221__) || (KDK_DERIVATIVE == __msp430afe222__) || (KDK_DERIVATIVE == __msp430afe223__) || (KDK_DERIVATIVE == __msp430afe231__) || (KDK_DERIVATIVE == __msp430afe232__) || (KDK_DERIVATIVE == __msp430afe233__) || (KDK_DERIVATIVE == __msp430afe251__) || (KDK_DERIVATIVE == __msp430afe252__) || (KDK_DERIVATIVE == __msp430afe253__)

    #include "port/msp430/MSP430_B3C11ED0AB698DE697DA65E69B122D35.c"

#elif (KDK_DERIVATIVE ==  __msp430bt5190__) || (KDK_DERIVATIVE == __msp430f5419__) || (KDK_DERIVATIVE == __msp430f5419a__) || (KDK_DERIVATIVE == __msp430f5436__) || (KDK_DERIVATIVE == __msp430f5436a__) || (KDK_DERIVATIVE == __msp430f5438__) || (KDK_DERIVATIVE == __msp430f5438a__) || (KDK_DERIVATIVE == __msp430sl5438a__) || (KDK_DERIVATIVE == __msp430x54x__) || (KDK_DERIVATIVE == __msp430x54xa__)

    #include "port/msp430/MSP430_713C92212AF9867D9E969E05D5D85915.c"

#elif (KDK_DERIVATIVE ==  __msp430c091__) || (KDK_DERIVATIVE == __msp430c092__) || (KDK_DERIVATIVE == __msp430l092__)

    #include "port/msp430/MSP430_4B52984CF00B571E4848CF4C868E12C6.c"

#elif (KDK_DERIVATIVE ==  __msp430c111__) || (KDK_DERIVATIVE == __msp430c112__) || (KDK_DERIVATIVE == __msp430e112__) || (KDK_DERIVATIVE == __msp430f110__) || (KDK_DERIVATIVE == __msp430f112__) || (KDK_DERIVATIVE == __msp430g2001__) || (KDK_DERIVATIVE == __msp430g2101__) || (KDK_DERIVATIVE == __msp430g2201__) || (KDK_DERIVATIVE == __msp430p112__) || (KDK_DERIVATIVE == __msp430x11x__)

    #include "port/msp430/MSP430_AB278A7EF847B7136A407E54BCE3C6E2.c"

#elif (KDK_DERIVATIVE ==  __msp430c1111__) || (KDK_DERIVATIVE == __msp430c1121__) || (KDK_DERIVATIVE == __msp430f1101__) || (KDK_DERIVATIVE == __msp430f1101a__) || (KDK_DERIVATIVE == __msp430f1111__) || (KDK_DERIVATIVE == __msp430f1111a__) || (KDK_DERIVATIVE == __msp430f1121__) || (KDK_DERIVATIVE == __msp430f1121a__) || (KDK_DERIVATIVE == __msp430f2001__) || (KDK_DERIVATIVE == __msp430f2011__) || (KDK_DERIVATIVE == __msp430f2101__) || (KDK_DERIVATIVE == __msp430f2111__) || (KDK_DERIVATIVE == __msp430f2121__) || (KDK_DERIVATIVE == __msp430f2131__) || (KDK_DERIVATIVE == __msp430g2111__) || (KDK_DERIVATIVE == __msp430g2210__) || (KDK_DERIVATIVE == __msp430g2211__) || (KDK_DERIVATIVE == __msp430x11x1__) || (KDK_DERIVATIVE == __msp430x20x1__) || (KDK_DERIVATIVE == __msp430x21x1__)

    #include "port/msp430/MSP430_375FB88A9E4A8BEFE5835E3C8FDDE6D8.c"

#elif (KDK_DERIVATIVE ==  __msp430c1331__) || (KDK_DERIVATIVE == __msp430c1351__) || (KDK_DERIVATIVE == __msp430x13x1__)

    #include "port/msp430/MSP430_1D59F54AEBDAF592148957FA32C283FA.c"

#elif (KDK_DERIVATIVE ==  __msp430c311s__) || (KDK_DERIVATIVE == __msp430c312__) || (KDK_DERIVATIVE == __msp430c313__) || (KDK_DERIVATIVE == __msp430c314__) || (KDK_DERIVATIVE == __msp430c315__) || (KDK_DERIVATIVE == __msp430e313__) || (KDK_DERIVATIVE == __msp430e315__) || (KDK_DERIVATIVE == __msp430p313__) || (KDK_DERIVATIVE == __msp430p315__) || (KDK_DERIVATIVE == __msp430p315s__) || (KDK_DERIVATIVE == __msp430x31x__)

    #include "port/msp430/MSP430_825D538A8CD92229D7450BBF5CCC05B3.c"

#elif (KDK_DERIVATIVE ==  __msp430c323__) || (KDK_DERIVATIVE == __msp430c325__) || (KDK_DERIVATIVE == __msp430e325__) || (KDK_DERIVATIVE == __msp430p325__) || (KDK_DERIVATIVE == __msp430x32x__)

    #include "port/msp430/MSP430_157184C02D0F6805BEB78DD62CF9B483.c"

#elif (KDK_DERIVATIVE ==  __msp430c336__) || (KDK_DERIVATIVE == __msp430c337__) || (KDK_DERIVATIVE == __msp430e337__) || (KDK_DERIVATIVE == __msp430p337__) || (KDK_DERIVATIVE == __msp430x33x__)

    #include "port/msp430/MSP430_1D97FC279FAE09F014C814F4E269C7D0.c"

#elif (KDK_DERIVATIVE ==  __msp430c412__) || (KDK_DERIVATIVE == __msp430c413__) || (KDK_DERIVATIVE == __msp430f412__) || (KDK_DERIVATIVE == __msp430f413__) || (KDK_DERIVATIVE == __msp430x41x__)

    #include "port/msp430/MSP430_42E7A5ED14BC6D0E60DD013DE5E4413A.c"

#elif (KDK_DERIVATIVE ==  __msp430cg4616__) || (KDK_DERIVATIVE == __msp430cg4617__) || (KDK_DERIVATIVE == __msp430cg4618__) || (KDK_DERIVATIVE == __msp430cg4619__) || (KDK_DERIVATIVE == __msp430fg4616__) || (KDK_DERIVATIVE == __msp430fg4617__) || (KDK_DERIVATIVE == __msp430fg4618__) || (KDK_DERIVATIVE == __msp430fg4619__) || (KDK_DERIVATIVE == __msp430xg46x__)

    #include "port/msp430/MSP430_14FA6052821B6071FB9649A63205A9AF.c"

#elif (KDK_DERIVATIVE ==  __msp430f1122__) || (KDK_DERIVATIVE == __msp430f1132__) || (KDK_DERIVATIVE == __msp430x11x2__)

    #include "port/msp430/MSP430_4A97D6C3BD0D34E141313A6CA1D1D1D2.c"

#elif (KDK_DERIVATIVE ==  __msp430f122__) || (KDK_DERIVATIVE == __msp430f123__) || (KDK_DERIVATIVE == __msp430x12x__)

    #include "port/msp430/MSP430_0E5C1DC59238640315F4D071B04848EE.c"

#elif (KDK_DERIVATIVE ==  __msp430f1222__) || (KDK_DERIVATIVE == __msp430f1232__) || (KDK_DERIVATIVE == __msp430x12x2__)

    #include "port/msp430/MSP430_9D48E8F09E6B3B660CF42D27F56AD87A.c"

#elif (KDK_DERIVATIVE ==  __msp430f133__) || (KDK_DERIVATIVE == __msp430f135__) || (KDK_DERIVATIVE == __msp430x13x__)

    #include "port/msp430/MSP430_C560A03B37966E323D93ACF41B5F9290.c"

#elif (KDK_DERIVATIVE ==  __msp430f147__) || (KDK_DERIVATIVE == __msp430f148__) || (KDK_DERIVATIVE == __msp430f149__) || (KDK_DERIVATIVE == __msp430x14x__)

    #include "port/msp430/MSP430_9FEF3C718A3AA2AE833CEB13282AB0EB.c"

#elif (KDK_DERIVATIVE ==  __msp430f1471__) || (KDK_DERIVATIVE == __msp430f1481__) || (KDK_DERIVATIVE == __msp430f1491__) || (KDK_DERIVATIVE == __msp430x14x1__)

    #include "port/msp430/MSP430_B682506C38E29B761596A798650C2848.c"

#elif (KDK_DERIVATIVE ==  __msp430f155__) || (KDK_DERIVATIVE == __msp430f156__) || (KDK_DERIVATIVE == __msp430f157__) || (KDK_DERIVATIVE == __msp430x15x__)

    #include "port/msp430/MSP430_A9711242B94110B359FF74DAF6AC19B4.c"

#elif (KDK_DERIVATIVE ==  __msp430f1610__) || (KDK_DERIVATIVE == __msp430f1611__) || (KDK_DERIVATIVE == __msp430f1612__) || (KDK_DERIVATIVE == __msp430f167__) || (KDK_DERIVATIVE == __msp430f168__) || (KDK_DERIVATIVE == __msp430f169__) || (KDK_DERIVATIVE == __msp430x16x__)

    #include "port/msp430/MSP430_6C02EE59D453FBA0C53EF366F1653A38.c"

#elif (KDK_DERIVATIVE ==  __msp430f2002__) || (KDK_DERIVATIVE == __msp430f2012__) || (KDK_DERIVATIVE == __msp430g2131__) || (KDK_DERIVATIVE == __msp430g2230__) || (KDK_DERIVATIVE == __msp430g2231__) || (KDK_DERIVATIVE == __msp430x20x2__)

    #include "port/msp430/MSP430_BA7C7659A94363CEF3D144CAF2281EFA.c"

#elif (KDK_DERIVATIVE ==  __msp430f2003__) || (KDK_DERIVATIVE == __msp430f2013__) || (KDK_DERIVATIVE == __msp430x20x3__)

    #include "port/msp430/MSP430_AC1ADBA191C4F37D6D89E70DA5E31E77.c"

#elif (KDK_DERIVATIVE ==  __msp430f2112__) || (KDK_DERIVATIVE == __msp430f2122__) || (KDK_DERIVATIVE == __msp430f2132__) || (KDK_DERIVATIVE == __msp430x21x2__)

    #include "port/msp430/MSP430_9D96426406E1A2D7401ACB822BFCBC8D.c"

#elif (KDK_DERIVATIVE ==  __msp430f2232__) || (KDK_DERIVATIVE == __msp430f2234__) || (KDK_DERIVATIVE == __msp430f2252__) || (KDK_DERIVATIVE == __msp430f2254__) || (KDK_DERIVATIVE == __msp430f2272__) || (KDK_DERIVATIVE == __msp430f2274__) || (KDK_DERIVATIVE == __msp430g2444__) || (KDK_DERIVATIVE == __msp430g2544__) || (KDK_DERIVATIVE == __msp430g2744__) || (KDK_DERIVATIVE == __msp430x22x2__) || (KDK_DERIVATIVE == __msp430x22x4__)

    #include "port/msp430/MSP430_19757934FF7552CD7F34B9EAB5EC32D2.c"

#elif (KDK_DERIVATIVE ==  __msp430f233__) || (KDK_DERIVATIVE == __msp430f235__) || (KDK_DERIVATIVE == __msp430x23x__)

    #include "port/msp430/MSP430_04E47678E7DE132BACC54E0EE389816A.c"

#elif (KDK_DERIVATIVE ==  __msp430f2330__) || (KDK_DERIVATIVE == __msp430f2350__) || (KDK_DERIVATIVE == __msp430f2370__) || (KDK_DERIVATIVE == __msp430x23x0__)

    #include "port/msp430/MSP430_1DF2C017D93AECFDF22CF835176BDC9E.c"

#elif (KDK_DERIVATIVE ==  __msp430f2410__) || (KDK_DERIVATIVE == __msp430f2416__) || (KDK_DERIVATIVE == __msp430f2417__) || (KDK_DERIVATIVE == __msp430f2418__) || (KDK_DERIVATIVE == __msp430f2419__) || (KDK_DERIVATIVE == __msp430f247__) || (KDK_DERIVATIVE == __msp430f248__) || (KDK_DERIVATIVE == __msp430f249__) || (KDK_DERIVATIVE == __msp430x241x__) || (KDK_DERIVATIVE == __msp430x24x__)

    #include "port/msp430/MSP430_B3C836E272654F19EF9A39A421FB2EC1.c"

#elif (KDK_DERIVATIVE ==  __msp430f2471__) || (KDK_DERIVATIVE == __msp430f2481__) || (KDK_DERIVATIVE == __msp430f2491__) || (KDK_DERIVATIVE == __msp430x24x1__)

    #include "port/msp430/MSP430_5AFF86237423D264E572AAE0FA8EF6F2.c"

#elif (KDK_DERIVATIVE ==  __msp430f2616__) || (KDK_DERIVATIVE == __msp430f2617__) || (KDK_DERIVATIVE == __msp430f2618__) || (KDK_DERIVATIVE == __msp430f2619__) || (KDK_DERIVATIVE == __msp430x26x__)

    #include "port/msp430/MSP430_A158FFB563A6950A74B035392A0AF577.c"

#elif (KDK_DERIVATIVE ==  __msp430f4132__) || (KDK_DERIVATIVE == __msp430f4152__) || (KDK_DERIVATIVE == __msp430x41x2__)

    #include "port/msp430/MSP430_053BA78740A7124F6CC580633B3906A8.c"

#elif (KDK_DERIVATIVE ==  __msp430f415__) || (KDK_DERIVATIVE == __msp430f417__) || (KDK_DERIVATIVE == __msp430x415__) || (KDK_DERIVATIVE == __msp430x417__)

    #include "port/msp430/MSP430_FB26E15FCD4FECCC4672EC035B5D8736.c"

#elif (KDK_DERIVATIVE ==  __msp430f423__) || (KDK_DERIVATIVE == __msp430f423a__) || (KDK_DERIVATIVE == __msp430f425__) || (KDK_DERIVATIVE == __msp430f425a__) || (KDK_DERIVATIVE == __msp430f427__) || (KDK_DERIVATIVE == __msp430f427a__) || (KDK_DERIVATIVE == __msp430x42x__)

    #include "port/msp430/MSP430_E4D74D4E552CCA842A4DA70F96C1B4F2.c"

#elif (KDK_DERIVATIVE ==  __msp430f4250__) || (KDK_DERIVATIVE == __msp430f4260__) || (KDK_DERIVATIVE == __msp430f4270__) || (KDK_DERIVATIVE == __msp430fg4250__) || (KDK_DERIVATIVE == __msp430fg4260__) || (KDK_DERIVATIVE == __msp430fg4270__) || (KDK_DERIVATIVE == __msp430x42x0__) || (KDK_DERIVATIVE == __msp430xg42x0__)

    #include "port/msp430/MSP430_81FAF297BC9A2E02FF743007ED887756.c"

#elif (KDK_DERIVATIVE ==  __msp430f435__) || (KDK_DERIVATIVE == __msp430f436__) || (KDK_DERIVATIVE == __msp430f437__) || (KDK_DERIVATIVE == __msp430x43x__)

    #include "port/msp430/MSP430_894EF3B163B12C94608A5F56C9A3BE2D.c"

#elif (KDK_DERIVATIVE ==  __msp430f4351__) || (KDK_DERIVATIVE == __msp430f4361__) || (KDK_DERIVATIVE == __msp430f4371__) || (KDK_DERIVATIVE == __msp430x43x1__)

    #include "port/msp430/MSP430_6D9B174C36D2108BF66EBB9B8FB1D16C.c"

#elif (KDK_DERIVATIVE ==  __msp430f438__) || (KDK_DERIVATIVE == __msp430f439__) || (KDK_DERIVATIVE == __msp430fg437__) || (KDK_DERIVATIVE == __msp430fg438__) || (KDK_DERIVATIVE == __msp430fg439__) || (KDK_DERIVATIVE == __msp430xg43x__)

    #include "port/msp430/MSP430_98646763A3EAEDD9441604EB4C382F86.c"

#elif (KDK_DERIVATIVE ==  __msp430f447__) || (KDK_DERIVATIVE == __msp430f448__) || (KDK_DERIVATIVE == __msp430f449__) || (KDK_DERIVATIVE == __msp430x44x__)

    #include "port/msp430/MSP430_E93850E64D7ACC91E52B457BC76EAB03.c"

#elif (KDK_DERIVATIVE ==  __msp430f4481__) || (KDK_DERIVATIVE == __msp430f4491__)

    #include "port/msp430/MSP430_49514A11BB37CBE2224AB8FF5F55D255.c"

#elif (KDK_DERIVATIVE ==  __msp430f4616__) || (KDK_DERIVATIVE == __msp430f4617__) || (KDK_DERIVATIVE == __msp430f4618__) || (KDK_DERIVATIVE == __msp430f4619__)

    #include "port/msp430/MSP430_2D5CB55453F50E738F4364E6D78F1047.c"

#elif (KDK_DERIVATIVE ==  __msp430f46161__) || (KDK_DERIVATIVE == __msp430f46171__) || (KDK_DERIVATIVE == __msp430f46181__) || (KDK_DERIVATIVE == __msp430f46191__)

    #include "port/msp430/MSP430_98C9002263DCCD31B2F2A16D275C8062.c"

#elif (KDK_DERIVATIVE ==  __msp430f47126__) || (KDK_DERIVATIVE == __msp430f47127__) || (KDK_DERIVATIVE == __msp430f47163__) || (KDK_DERIVATIVE == __msp430f47166__) || (KDK_DERIVATIVE == __msp430f47167__) || (KDK_DERIVATIVE == __msp430f47173__) || (KDK_DERIVATIVE == __msp430f47176__) || (KDK_DERIVATIVE == __msp430f47177__) || (KDK_DERIVATIVE == __msp430f47183__) || (KDK_DERIVATIVE == __msp430f47186__) || (KDK_DERIVATIVE == __msp430f47187__) || (KDK_DERIVATIVE == __msp430f47193__) || (KDK_DERIVATIVE == __msp430f47196__) || (KDK_DERIVATIVE == __msp430f47197__) || (KDK_DERIVATIVE == __msp430x471x6__) || (KDK_DERIVATIVE == __msp430x471x7__)

    #include "port/msp430/MSP430_E0F29FB9E0F41E933DC7A6994FF786B0.c"

#elif (KDK_DERIVATIVE ==  __msp430f477__) || (KDK_DERIVATIVE == __msp430f478__) || (KDK_DERIVATIVE == __msp430f479__) || (KDK_DERIVATIVE == __msp430fg477__) || (KDK_DERIVATIVE == __msp430fg478__) || (KDK_DERIVATIVE == __msp430fg479__) || (KDK_DERIVATIVE == __msp430x47x__) || (KDK_DERIVATIVE == __msp430xg47x__)

    #include "port/msp430/MSP430_BB9171153CAFD99D78F7EF9E0E9A26AB.c"

#elif (KDK_DERIVATIVE ==  __msp430f4783__) || (KDK_DERIVATIVE == __msp430f4784__) || (KDK_DERIVATIVE == __msp430f4793__) || (KDK_DERIVATIVE == __msp430f4794__) || (KDK_DERIVATIVE == __msp430x47x3__) || (KDK_DERIVATIVE == __msp430x47x4__)

    #include "port/msp430/MSP430_01A8C6E483C445D3EBF5894318F1C6D1.c"

#elif (KDK_DERIVATIVE ==  __msp430f5131__) || (KDK_DERIVATIVE == __msp430f5151__) || (KDK_DERIVATIVE == __msp430f5171__)

    #include "port/msp430/MSP430_EC8101207B8B63852E9BC995A8995783.c"

#elif (KDK_DERIVATIVE ==  __msp430f5132__) || (KDK_DERIVATIVE == __msp430f5152__) || (KDK_DERIVATIVE == __msp430f5172__)

    #include "port/msp430/MSP430_A48FAF2E10F972A2A9DF667AE891818D.c"

#elif (KDK_DERIVATIVE ==  __msp430f5212__) || (KDK_DERIVATIVE == __msp430f5213__) || (KDK_DERIVATIVE == __msp430f5214__) || (KDK_DERIVATIVE == __msp430f5217__) || (KDK_DERIVATIVE == __msp430f5218__) || (KDK_DERIVATIVE == __msp430f5219__)

    #include "port/msp430/MSP430_E5D7295003C0054E4FF6532E93031776.c"

#elif (KDK_DERIVATIVE ==  __msp430f5222__) || (KDK_DERIVATIVE == __msp430f5223__) || (KDK_DERIVATIVE == __msp430f5224__) || (KDK_DERIVATIVE == __msp430f5227__) || (KDK_DERIVATIVE == __msp430f5228__) || (KDK_DERIVATIVE == __msp430f5229__)

    #include "port/msp430/MSP430_D183C5BB14E8B82F5B5C1575F447CDBF.c"

#elif (KDK_DERIVATIVE ==  __msp430f5304__)

    #include "port/msp430/MSP430_0FB3F3E9B57672F0FDA02F0B89A87127.c"

#elif (KDK_DERIVATIVE ==  __msp430f5308__) || (KDK_DERIVATIVE == __msp430f5309__) || (KDK_DERIVATIVE == __msp430f5310__)

    #include "port/msp430/MSP430_AB5809433D17495674DF00752BF60F9F.c"

#elif (KDK_DERIVATIVE ==  __msp430f5324__) || (KDK_DERIVATIVE == __msp430f5325__) || (KDK_DERIVATIVE == __msp430f5326__) || (KDK_DERIVATIVE == __msp430f5327__) || (KDK_DERIVATIVE == __msp430f5328__) || (KDK_DERIVATIVE == __msp430f5329__)

    #include "port/msp430/MSP430_58CEE3ACFB6B0C520C90277D0AE05839.c"

#elif (KDK_DERIVATIVE ==  __msp430f5333__) || (KDK_DERIVATIVE == __msp430f5335__)

    #include "port/msp430/MSP430_096774E340759F5B574AA58913699EDA.c"

#elif (KDK_DERIVATIVE ==  __msp430f5336__) || (KDK_DERIVATIVE == __msp430f5338__)

    #include "port/msp430/MSP430_432125AB8D00FC804908C6ECDCFDD89A.c"

#elif (KDK_DERIVATIVE ==  __msp430f5340__) || (KDK_DERIVATIVE == __msp430f5341__) || (KDK_DERIVATIVE == __msp430f5342__)

    #include "port/msp430/MSP430_AF2D1BE15C7EA140BC5A50D73E56A748.c"

#elif (KDK_DERIVATIVE ==  __msp430f5358__) || (KDK_DERIVATIVE == __msp430f5359__)

    #include "port/msp430/MSP430_D72D622F22ED12E3C4DE1739BE28359E.c"

#elif (KDK_DERIVATIVE ==  __msp430f5418__) || (KDK_DERIVATIVE == __msp430f5418a__) || (KDK_DERIVATIVE == __msp430f5435__) || (KDK_DERIVATIVE == __msp430f5435a__) || (KDK_DERIVATIVE == __msp430f5437__) || (KDK_DERIVATIVE == __msp430f5437a__)

    #include "port/msp430/MSP430_E9BDE12599A4A9FFA13162B60241181E.c"

#elif (KDK_DERIVATIVE ==  __msp430f5500__) || (KDK_DERIVATIVE == __msp430f5501__) || (KDK_DERIVATIVE == __msp430f5502__) || (KDK_DERIVATIVE == __msp430f5503__) || (KDK_DERIVATIVE == __msp430f5513__) || (KDK_DERIVATIVE == __msp430f5514__) || (KDK_DERIVATIVE == __msp430f5515__) || (KDK_DERIVATIVE == __msp430f5517__) || (KDK_DERIVATIVE == __msp430f5519__) || (KDK_DERIVATIVE == __msp430x551x__)

    #include "port/msp430/MSP430_D7448E7D46711786A0A80A462C885FA9.c"

#elif (KDK_DERIVATIVE ==  __msp430f5504__) || (KDK_DERIVATIVE == __msp430f5505__) || (KDK_DERIVATIVE == __msp430f5506__) || (KDK_DERIVATIVE == __msp430f5507__)

    #include "port/msp430/MSP430_C61F7176D604865CEA96D69A071E9EE3.c"

#elif (KDK_DERIVATIVE ==  __msp430f5508__) || (KDK_DERIVATIVE == __msp430f5509__) || (KDK_DERIVATIVE == __msp430f5510__)

    #include "port/msp430/MSP430_4AF260A87F6C8555B5D48F79436B7082.c"

#elif (KDK_DERIVATIVE ==  __msp430f5521__) || (KDK_DERIVATIVE == __msp430f5522__) || (KDK_DERIVATIVE == __msp430f5524__) || (KDK_DERIVATIVE == __msp430f5525__) || (KDK_DERIVATIVE == __msp430f5526__) || (KDK_DERIVATIVE == __msp430f5527__) || (KDK_DERIVATIVE == __msp430f5528__) || (KDK_DERIVATIVE == __msp430f5529__) || (KDK_DERIVATIVE == __msp430x552x__)

    #include "port/msp430/MSP430_F305462AFC4AD7F27D464CE5F478DD75.c"

#elif (KDK_DERIVATIVE ==  __msp430f5630__) || (KDK_DERIVATIVE == __msp430f5631__) || (KDK_DERIVATIVE == __msp430f5632__)

    #include "port/msp430/MSP430_A357E573A28943F829E17F8FB21956E1.c"

#elif (KDK_DERIVATIVE ==  __msp430f5633__) || (KDK_DERIVATIVE == __msp430f5634__) || (KDK_DERIVATIVE == __msp430f5635__)

    #include "port/msp430/MSP430_BCC89699260BE8F108BBC89FE940EB29.c"

#elif (KDK_DERIVATIVE ==  __msp430f5636__) || (KDK_DERIVATIVE == __msp430f5637__) || (KDK_DERIVATIVE == __msp430f5638__)

    #include "port/msp430/MSP430_91EAA04B0112CB41055286F0C4D765FF.c"

#elif (KDK_DERIVATIVE ==  __msp430f5658__) || (KDK_DERIVATIVE == __msp430f5659__)

    #include "port/msp430/MSP430_ADF8F674198D1658DFCF9677573E9FD2.c"

#elif (KDK_DERIVATIVE ==  __msp430f6433__) || (KDK_DERIVATIVE == __msp430f6435__)

    #include "port/msp430/MSP430_07088A6A9DD925811F69198EB7079E79.c"

#elif (KDK_DERIVATIVE ==  __msp430f6436__) || (KDK_DERIVATIVE == __msp430f6438__)

    #include "port/msp430/MSP430_302C4E97C6D828965D0BF03CBF16CE4A.c"

#elif (KDK_DERIVATIVE ==  __msp430f6458__) || (KDK_DERIVATIVE == __msp430f6459__)

    #include "port/msp430/MSP430_C300324881DE531791E38BC4B102BE16.c"

#elif (KDK_DERIVATIVE ==  __msp430f6630__) || (KDK_DERIVATIVE == __msp430f6631__) || (KDK_DERIVATIVE == __msp430f6632__)

    #include "port/msp430/MSP430_5E95F53010768AABE77FDBC8F13A12EB.c"

#elif (KDK_DERIVATIVE ==  __msp430f6633__) || (KDK_DERIVATIVE == __msp430f6634__) || (KDK_DERIVATIVE == __msp430f6635__)

    #include "port/msp430/MSP430_285A7FB42E74187BD802A1F926C6B7C6.c"

#elif (KDK_DERIVATIVE ==  __msp430f6636__) || (KDK_DERIVATIVE == __msp430f6637__) || (KDK_DERIVATIVE == __msp430f6638__)

    #include "port/msp430/MSP430_A09276474E4FA1DB79347CAA46C0BF26.c"

#elif (KDK_DERIVATIVE ==  __msp430f6658__) || (KDK_DERIVATIVE == __msp430f6659__)

    #include "port/msp430/MSP430_3ADE2D2A3A6625596C7E4CF45DF4196B.c"

#elif (KDK_DERIVATIVE ==  __msp430f6720__) || (KDK_DERIVATIVE == __msp430f6721__) || (KDK_DERIVATIVE == __msp430f6723__) || (KDK_DERIVATIVE == __msp430f6724__) || (KDK_DERIVATIVE == __msp430f6725__) || (KDK_DERIVATIVE == __msp430f6726__) || (KDK_DERIVATIVE == __msp430f6730__) || (KDK_DERIVATIVE == __msp430f6731__) || (KDK_DERIVATIVE == __msp430f6733__) || (KDK_DERIVATIVE == __msp430f6734__) || (KDK_DERIVATIVE == __msp430f6735__) || (KDK_DERIVATIVE == __msp430f6736__)

    #include "port/msp430/MSP430_81B9696C0158E96E6C5560963AFF2816.c"

#elif (KDK_DERIVATIVE ==  __msp430f6745__) || (KDK_DERIVATIVE == __msp430f6746__) || (KDK_DERIVATIVE == __msp430f6747__) || (KDK_DERIVATIVE == __msp430f6748__) || (KDK_DERIVATIVE == __msp430f6749__) || (KDK_DERIVATIVE == __msp430f6765__) || (KDK_DERIVATIVE == __msp430f6766__) || (KDK_DERIVATIVE == __msp430f6767__) || (KDK_DERIVATIVE == __msp430f6768__) || (KDK_DERIVATIVE == __msp430f6769__) || (KDK_DERIVATIVE == __msp430f6775__) || (KDK_DERIVATIVE == __msp430f6776__) || (KDK_DERIVATIVE == __msp430f6777__) || (KDK_DERIVATIVE == __msp430f6778__) || (KDK_DERIVATIVE == __msp430f6779__)

    #include "port/msp430/MSP430_CD2C3B43C02AFE171165AFD967B33DB3.c"

#elif (KDK_DERIVATIVE ==  __msp430f67451__) || (KDK_DERIVATIVE == __msp430f67461__) || (KDK_DERIVATIVE == __msp430f67471__) || (KDK_DERIVATIVE == __msp430f67481__) || (KDK_DERIVATIVE == __msp430f67491__) || (KDK_DERIVATIVE == __msp430f67651__) || (KDK_DERIVATIVE == __msp430f67661__) || (KDK_DERIVATIVE == __msp430f67671__) || (KDK_DERIVATIVE == __msp430f67681__) || (KDK_DERIVATIVE == __msp430f67691__) || (KDK_DERIVATIVE == __msp430f67751__) || (KDK_DERIVATIVE == __msp430f67761__) || (KDK_DERIVATIVE == __msp430f67771__) || (KDK_DERIVATIVE == __msp430f67781__) || (KDK_DERIVATIVE == __msp430f67791__)

    #include "port/msp430/MSP430_699153F4A69002FC1BFDEBDDC8AB13D1.c"

#elif (KDK_DERIVATIVE ==  __msp430fe423__) || (KDK_DERIVATIVE == __msp430fe4232__) || (KDK_DERIVATIVE == __msp430fe423a__) || (KDK_DERIVATIVE == __msp430fe4242__) || (KDK_DERIVATIVE == __msp430fe425__) || (KDK_DERIVATIVE == __msp430fe4252__) || (KDK_DERIVATIVE == __msp430fe425a__) || (KDK_DERIVATIVE == __msp430fe427__) || (KDK_DERIVATIVE == __msp430fe4272__) || (KDK_DERIVATIVE == __msp430fe427a__) || (KDK_DERIVATIVE == __msp430xe42x__) || (KDK_DERIVATIVE == __msp430xe42x2__) || (KDK_DERIVATIVE == __msp430xe42xa__)

    #include "port/msp430/MSP430_CA458B492F6F582E8AD291BD53109D25.c"

#elif (KDK_DERIVATIVE ==  __msp430fr5720__) || (KDK_DERIVATIVE == __msp430fr5724__) || (KDK_DERIVATIVE == __msp430fr5728__) || (KDK_DERIVATIVE == __msp430fr5730__) || (KDK_DERIVATIVE == __msp430fr5734__) || (KDK_DERIVATIVE == __msp430fr5738__)

    #include "port/msp430/MSP430_301A18A39AD30A90996B213302361EC6.c"

#elif (KDK_DERIVATIVE ==  __msp430fr5721__) || (KDK_DERIVATIVE == __msp430fr5725__) || (KDK_DERIVATIVE == __msp430fr5729__) || (KDK_DERIVATIVE == __msp430fr5731__) || (KDK_DERIVATIVE == __msp430fr5735__) || (KDK_DERIVATIVE == __msp430fr5739__)

    #include "port/msp430/MSP430_9C45E596E465B4BB23CD98AAC64B818B.c"

#elif (KDK_DERIVATIVE ==  __msp430fr5722__) || (KDK_DERIVATIVE == __msp430fr5726__) || (KDK_DERIVATIVE == __msp430fr5732__) || (KDK_DERIVATIVE == __msp430fr5736__)

    #include "port/msp430/MSP430_C68A7852EAF9612FC97262139AD1B126.c"

#elif (KDK_DERIVATIVE ==  __msp430fr5723__) || (KDK_DERIVATIVE == __msp430fr5727__) || (KDK_DERIVATIVE == __msp430fr5733__) || (KDK_DERIVATIVE == __msp430fr5737__)

    #include "port/msp430/MSP430_79F21C8D42ABC92F83222888760E86B4.c"

#elif (KDK_DERIVATIVE ==  __msp430fr5949__) || (KDK_DERIVATIVE == __msp430fr5969__)

    #include "port/msp430/MSP430_6ED214483D88379A48E0E07A2EB807A4.c"

#elif (KDK_DERIVATIVE ==  __msp430fw423__) || (KDK_DERIVATIVE == __msp430fw425__) || (KDK_DERIVATIVE == __msp430fw427__) || (KDK_DERIVATIVE == __msp430fw428__) || (KDK_DERIVATIVE == __msp430fw429__) || (KDK_DERIVATIVE == __msp430xw42x__)

    #include "port/msp430/MSP430_A7E445462288FA4F9CCEBC9989A4D7F1.c"

#elif (KDK_DERIVATIVE ==  __msp430g2102__) || (KDK_DERIVATIVE == __msp430g2202__) || (KDK_DERIVATIVE == __msp430g2302__) || (KDK_DERIVATIVE == __msp430g2402__)

    #include "port/msp430/MSP430_3C2002B86CB5C2DD7AFE3E235985808E.c"

#elif (KDK_DERIVATIVE ==  __msp430g2112__) || (KDK_DERIVATIVE == __msp430g2212__) || (KDK_DERIVATIVE == __msp430g2312__) || (KDK_DERIVATIVE == __msp430g2412__)

    #include "port/msp430/MSP430_DE2F62DB05647FEBC574EC451FAFA8EF.c"

#elif (KDK_DERIVATIVE ==  __msp430g2113__) || (KDK_DERIVATIVE == __msp430g2213__) || (KDK_DERIVATIVE == __msp430g2313__) || (KDK_DERIVATIVE == __msp430g2413__) || (KDK_DERIVATIVE == __msp430g2513__)

    #include "port/msp430/MSP430_15AB77E4CA1AC0A71CD46EF2AFD3422F.c"

#elif (KDK_DERIVATIVE ==  __msp430g2121__) || (KDK_DERIVATIVE == __msp430g2221__)

    #include "port/msp430/MSP430_8FE0283583B2B18BEEBD6F63FC9CF871.c"

#elif (KDK_DERIVATIVE ==  __msp430g2132__) || (KDK_DERIVATIVE == __msp430g2232__) || (KDK_DERIVATIVE == __msp430g2332__) || (KDK_DERIVATIVE == __msp430g2432__)

    #include "port/msp430/MSP430_A9C59AC9148338AC264EDE088BDA730A.c"

#elif (KDK_DERIVATIVE ==  __msp430g2152__) || (KDK_DERIVATIVE == __msp430g2252__) || (KDK_DERIVATIVE == __msp430g2352__) || (KDK_DERIVATIVE == __msp430g2452__)

    #include "port/msp430/MSP430_873EF319D19508BA4B00C284F3A45621.c"

#elif (KDK_DERIVATIVE ==  __msp430g2153__) || (KDK_DERIVATIVE == __msp430g2253__) || (KDK_DERIVATIVE == __msp430g2353__) || (KDK_DERIVATIVE == __msp430g2453__) || (KDK_DERIVATIVE == __msp430g2553__) || (KDK_DERIVATIVE == __msp430tch5e__)

    #include "port/msp430/MSP430_953EC4E5A1BD04BAF6AD56A52E34AFD5.c"

#elif (KDK_DERIVATIVE ==  __msp430g2203__) || (KDK_DERIVATIVE == __msp430g2303__) || (KDK_DERIVATIVE == __msp430g2403__)

    #include "port/msp430/MSP430_957793C807D85D3B0769895A2D079313.c"

#elif (KDK_DERIVATIVE ==  __msp430g2233__) || (KDK_DERIVATIVE == __msp430g2333__) || (KDK_DERIVATIVE == __msp430g2433__) || (KDK_DERIVATIVE == __msp430g2533__)

    #include "port/msp430/MSP430_B7DD2D462A38093C64BC8400C39EB246.c"

#elif (KDK_DERIVATIVE ==  __msp430g2755__) || (KDK_DERIVATIVE == __msp430g2855__) || (KDK_DERIVATIVE == __msp430g2955__)

    #include "port/msp430/MSP430_6050DED7F64B13380EBFC4669A4577E5.c"

#elif (KDK_DERIVATIVE ==  __msp430x47126__) || (KDK_DERIVATIVE == __msp430x47127__)

    #include "port/msp430/MSP430_CE5ED5AF6A1DF3BAE4F70BC1C83CDBC8.c"

#endif


#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__MSP430_VECTORS_H */

