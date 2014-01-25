/*
 *
 * (C) 2007-2014 by Christoph Schueler <github.com/Christoph2,
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
 * s. FLOSS-EXCEPTION.txt
 *
 */
#if !defined(__S12_DEVICES_H)
#define __S12_DEVICES_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#if !defined(KDK_DERIVATIVE)
  #error Parameter KDK_DERIVATIVE not set!
#endif

#if KDK_DERIVATIVE == __MC68HC812A4__    
   #include "kdk/mcu/s12/inc/device/kdk/mcu/s12/inc/device/MC68HC812A4_Cfg.h"
#elif KDK_DERIVATIVE == __MC68HC912B32__   
   #include "kdk/mcu/s12/inc/device/MC68HC912B32_Cfg.h"
#elif KDK_DERIVATIVE == __MC68HC912BC32__  
   #include "kdk/mcu/s12/inc/device/MC68HC912BC32_Cfg.h"
#elif KDK_DERIVATIVE == __MC68HC912D60__   
   #include "kdk/mcu/s12/inc/device/MC68HC912D60_Cfg.h"
#elif KDK_DERIVATIVE == __MC68HC912DG128__ 
   #include "kdk/mcu/s12/inc/device/MC68HC912DG128_Cfg.h"
#elif KDK_DERIVATIVE == __MC68HC912DG128A__
   #include "kdk/mcu/s12/inc/device/MC68HC912DG128A_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12A128__     
   #include "kdk/mcu/s12/inc/device/MC9S12A128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12A256__     
   #include "kdk/mcu/s12/inc/device/MC9S12A256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12A32__      
   #include "kdk/mcu/s12/inc/device/MC9S12A32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12A512__     
   #include "kdk/mcu/s12/inc/device/MC9S12A512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12A64__      
   #include "kdk/mcu/s12/inc/device/MC9S12A64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12B128__     
   #include "kdk/mcu/s12/inc/device/MC9S12B128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12B64__      
   #include "kdk/mcu/s12/inc/device/MC9S12B64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12C128__     
   #include "kdk/mcu/s12/inc/device/MC9S12C128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12C32__      
   #include "kdk/mcu/s12/inc/device/MC9S12C32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12C64__      
   #include "kdk/mcu/s12/inc/device/MC9S12C64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12C96__      
   #include "kdk/mcu/s12/inc/device/MC9S12C96_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12D32__      
   #include "kdk/mcu/s12/inc/device/MC9S12D32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12D64__      
   #include "kdk/mcu/s12/inc/device/MC9S12D64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DB128__    
   #include "kdk/mcu/s12/inc/device/MC9S12DB128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DG128__    
   #include "kdk/mcu/s12/inc/device/MC9S12DG128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DG256__    
   #include "kdk/mcu/s12/inc/device/MC9S12DG256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DJ128__    
   #include "kdk/mcu/s12/inc/device/MC9S12DJ128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DJ256__    
   #include "kdk/mcu/s12/inc/device/MC9S12DJ256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DJ64__     
   #include "kdk/mcu/s12/inc/device/MC9S12DJ64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DP256__    
   #include "kdk/mcu/s12/inc/device/MC9S12DP256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DP512__    
   #include "kdk/mcu/s12/inc/device/MC9S12DP512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DT128__    
   #include "kdk/mcu/s12/inc/device/MC9S12DT128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DT256__    
   #include "kdk/mcu/s12/inc/device/MC9S12DT256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12DT256B__   
   #include "kdk/mcu/s12/inc/device/MC9S12DT256B_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12E128__     
   #include "kdk/mcu/s12/inc/device/MC9S12E128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12E256__     
   #include "kdk/mcu/s12/inc/device/MC9S12E256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12E32__      
   #include "kdk/mcu/s12/inc/device/MC9S12E32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12E64__      
   #include "kdk/mcu/s12/inc/device/MC9S12E64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12G128__     
   #include "kdk/mcu/s12/inc/device/MC9S12G128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12G96__      
   #include "kdk/mcu/s12/inc/device/MC9S12G96_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GC128__    
   #include "kdk/mcu/s12/inc/device/MC9S12GC128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GC16__     
   #include "kdk/mcu/s12/inc/device/MC9S12GC16_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GC32__     
   #include "kdk/mcu/s12/inc/device/MC9S12GC32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GC64__     
   #include "kdk/mcu/s12/inc/device/MC9S12GC64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GN16__     
   #include "kdk/mcu/s12/inc/device/MC9S12GN16_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12GN32__     
   #include "kdk/mcu/s12/inc/device/MC9S12GN32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12H128__     
   #include "kdk/mcu/s12/inc/device/MC9S12H128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12H256__     
   #include "kdk/mcu/s12/inc/device/MC9S12H256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HA32__     
   #include "kdk/mcu/s12/inc/device/MC9S12HA32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HA48__     
   #include "kdk/mcu/s12/inc/device/MC9S12HA48_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HA64__     
   #include "kdk/mcu/s12/inc/device/MC9S12HA64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HN64__     
   #include "kdk/mcu/s12/inc/device/MC9S12HN64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HY32__     
   #include "kdk/mcu/s12/inc/device/MC9S12HY32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HY48__     
   #include "kdk/mcu/s12/inc/device/MC9S12HY48_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HY64__     
   #include "kdk/mcu/s12/inc/device/MC9S12HY64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HZ128__    
   #include "kdk/mcu/s12/inc/device/MC9S12HZ128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HZ256__    
   #include "kdk/mcu/s12/inc/device/MC9S12HZ256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12HZ64__     
   #include "kdk/mcu/s12/inc/device/MC9S12HZ64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12I128__     
   #include "kdk/mcu/s12/inc/device/MC9S12I128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12I32__      
   #include "kdk/mcu/s12/inc/device/MC9S12I32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KC128__    
   #include "kdk/mcu/s12/inc/device/MC9S12KC128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KC64__     
   #include "kdk/mcu/s12/inc/device/MC9S12KC64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KG128__    
   #include "kdk/mcu/s12/inc/device/MC9S12KG128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KG256__    
   #include "kdk/mcu/s12/inc/device/MC9S12KG256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KG64__     
   #include "kdk/mcu/s12/inc/device/MC9S12KG64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KL128__    
   #include "kdk/mcu/s12/inc/device/MC9S12KL128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KL64__     
   #include "kdk/mcu/s12/inc/device/MC9S12KL64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KT128__    
   #include "kdk/mcu/s12/inc/device/MC9S12KT128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12KT256__    
   #include "kdk/mcu/s12/inc/device/MC9S12KT256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12NE64__     
   #include "kdk/mcu/s12/inc/device/MC9S12NE64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12P128__     
   #include "kdk/mcu/s12/inc/device/MC9S12P128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12P32__      
   #include "kdk/mcu/s12/inc/device/MC9S12P32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12P64__      
   #include "kdk/mcu/s12/inc/device/MC9S12P64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12P96__      
   #include "kdk/mcu/s12/inc/device/MC9S12P96_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12Q128__     
   #include "kdk/mcu/s12/inc/device/MC9S12Q128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12Q32__      
   #include "kdk/mcu/s12/inc/device/MC9S12Q32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12Q64__      
   #include "kdk/mcu/s12/inc/device/MC9S12Q64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12Q96__      
   #include "kdk/mcu/s12/inc/device/MC9S12Q96_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12UF32__     
   #include "kdk/mcu/s12/inc/device/MC9S12UF32_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XA128__    
   #include "kdk/mcu/s12/inc/device/MC9S12XA128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XA256__    
   #include "kdk/mcu/s12/inc/device/MC9S12XA256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XA512__    
   #include "kdk/mcu/s12/inc/device/MC9S12XA512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XB128__    
   #include "kdk/mcu/s12/inc/device/MC9S12XB128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XB256__    
   #include "kdk/mcu/s12/inc/device/MC9S12XB256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XD128__    
   #include "kdk/mcu/s12/inc/device/MC9S12XD128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XD256__    
   #include "kdk/mcu/s12/inc/device/MC9S12XD256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XD64__     
   #include "kdk/mcu/s12/inc/device/MC9S12XD64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDG128__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDG128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDP512__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDP512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDQ256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDQ256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDT256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDT256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDT384__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDT384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XDT512__   
   #include "kdk/mcu/s12/inc/device/MC9S12XDT512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEA128__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEA128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEA256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEA256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEG128__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEG128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEG384__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEG384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEP100__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEP100_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEP768__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEP768_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEQ384__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEQ384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XEQ512__   
   #include "kdk/mcu/s12/inc/device/MC9S12XEQ512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XES384__   
   #include "kdk/mcu/s12/inc/device/MC9S12XES384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XET256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XET256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XF128__    
   #include "kdk/mcu/s12/inc/device/MC9S12XF128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XF256__    
   #include "kdk/mcu/s12/inc/device/MC9S12XF256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XF384__    
   #include "kdk/mcu/s12/inc/device/MC9S12XF384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XF512__    
   #include "kdk/mcu/s12/inc/device/MC9S12XF512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XFR128__   
   #include "kdk/mcu/s12/inc/device/MC9S12XFR128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XFR64__    
   #include "kdk/mcu/s12/inc/device/MC9S12XFR64_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XHY128__   
   #include "kdk/mcu/s12/inc/device/MC9S12XHY128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XHY256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XHY256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XHZ256__   
   #include "kdk/mcu/s12/inc/device/MC9S12XHZ256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XHZ384__   
   #include "kdk/mcu/s12/inc/device/MC9S12XHZ384_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XHZ512__   
   #include "kdk/mcu/s12/inc/device/MC9S12XHZ512_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XS128__    
   #include "kdk/mcu/s12/inc/device/MC9S12XS128_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XS256__    
   #include "kdk/mcu/s12/inc/device/MC9S12XS256_Cfg.h"
#elif KDK_DERIVATIVE == __MC9S12XS64__     
   #include "kdk/mcu/s12/inc/device/MC9S12XS64_Cfg.h"
#else
    #error Unknown derivative!
#endif

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__S12_DEVICES_H */

