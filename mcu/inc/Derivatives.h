/*
 * k_dk - Driver Kit for k_os (Konnex Operating-System based on the
 * OSEK/VDX-Standard).
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
 * s. FLOSS-EXCEPTION.txt
 *
 */
#if !defined(__S12_DERIVATIVES_H)
#define __S12_DERIVATIVES_H

#if defined(__cplusplus)
extern "C"
{
#endif  /* __cplusplus */


#define __MC68HC812A4__       (1u)
#define __MC68HC912B32__      (2u)
#define __MC68HC912BC32__     (3u)
#define __MC68HC912D60__      (4u)
#define __MC68HC912DG128__    (5u)
#define __MC68HC912DG128A__   (6u)
#define __MC9S12A128__        (7u)
#define __MC9S12A256__        (8u)
#define __MC9S12A32__         (9u)
#define __MC9S12A512__        (10u)
#define __MC9S12A64__         (11u)
#define __MC9S12B128__        (12u)
#define __MC9S12B64__         (13u)
#define __MC9S12C128__        (14u)
#define __MC9S12C32__         (15u)
#define __MC9S12C64__         (16u)
#define __MC9S12C96__         (17u)
#define __MC9S12D32__         (18u)
#define __MC9S12D64__         (19u)
#define __MC9S12DB128__       (20u)
#define __MC9S12DG128__       (21u)
#define __MC9S12DG256__       (22u)
#define __MC9S12DJ128__       (23u)
#define __MC9S12DJ256__       (24u)
#define __MC9S12DJ64__        (25u)
#define __MC9S12DP256__       (26u)
#define __MC9S12DP512__       (27u)
#define __MC9S12DT128__       (28u)
#define __MC9S12DT256__       (29u)
#define __MC9S12DT256B__      (30u)
#define __MC9S12E128__        (31u)
#define __MC9S12E256__        (32u)
#define __MC9S12E32__         (33u)
#define __MC9S12E64__         (34u)
#define __MC9S12G128__        (35u)
#define __MC9S12G96__         (36u)
#define __MC9S12GC128__       (37u)
#define __MC9S12GC16__        (38u)
#define __MC9S12GC32__        (39u)
#define __MC9S12GC64__        (40u)
#define __MC9S12GN16__        (41u)
#define __MC9S12GN32__        (42u)
#define __MC9S12H128__        (43u)
#define __MC9S12H256__        (44u)
#define __MC9S12HA32__        (45u)
#define __MC9S12HA48__        (46u)
#define __MC9S12HA64__        (47u)
#define __MC9S12HN64__        (48u)
#define __MC9S12HY32__        (49u)
#define __MC9S12HY48__        (50u)
#define __MC9S12HY64__        (51u)
#define __MC9S12HZ128__       (52u)
#define __MC9S12HZ256__       (53u)
#define __MC9S12HZ64__        (54u)
#define __MC9S12I128__        (55u)
#define __MC9S12I32__         (56u)
#define __MC9S12KC128__       (57u)
#define __MC9S12KC64__        (58u)
#define __MC9S12KG128__       (59u)
#define __MC9S12KG256__       (60u)
#define __MC9S12KG64__        (61u)
#define __MC9S12KL128__       (62u)
#define __MC9S12KL64__        (63u)
#define __MC9S12KT128__       (64u)
#define __MC9S12KT256__       (65u)
#define __MC9S12NE64__        (66u)
#define __MC9S12P128__        (67u)
#define __MC9S12P32__         (68u)
#define __MC9S12P64__         (69u)
#define __MC9S12P96__         (70u)
#define __MC9S12Q128__        (71u)
#define __MC9S12Q32__         (72u)
#define __MC9S12Q64__         (73u)
#define __MC9S12Q96__         (74u)
#define __MC9S12UF32__        (75u)
#define __MC9S12XA128__       (76u)
#define __MC9S12XA256__       (77u)
#define __MC9S12XA512__       (78u)
#define __MC9S12XB128__       (79u)
#define __MC9S12XB256__       (80u)
#define __MC9S12XD128__       (81u)
#define __MC9S12XD256__       (82u)
#define __MC9S12XD64__        (83u)
#define __MC9S12XDG128__      (84u)
#define __MC9S12XDP512__      (85u)
#define __MC9S12XDQ256__      (86u)
#define __MC9S12XDT256__      (87u)
#define __MC9S12XDT384__      (88u)
#define __MC9S12XDT512__      (89u)
#define __MC9S12XEA128__      (90u)
#define __MC9S12XEA256__      (91u)
#define __MC9S12XEG128__      (92u)
#define __MC9S12XEG384__      (93u)
#define __MC9S12XEP100__      (94u)
#define __MC9S12XEP768__      (95u)
#define __MC9S12XEQ384__      (96u)
#define __MC9S12XEQ512__      (97u)
#define __MC9S12XES384__      (98u)
#define __MC9S12XET256__      (99u)
#define __MC9S12XF128__       (100u)
#define __MC9S12XF256__       (101u)
#define __MC9S12XF384__       (102u)
#define __MC9S12XF512__       (103u)
#define __MC9S12XFR128__      (104u)
#define __MC9S12XFR64__       (105u)
#define __MC9S12XHY128__      (106u)
#define __MC9S12XHY256__      (107u)
#define __MC9S12XHZ256__      (108u)
#define __MC9S12XHZ384__      (109u)
#define __MC9S12XHZ512__      (110u)
#define __MC9S12XS128__       (111u)
#define __MC9S12XS256__       (112u)
#define __MC9S12XS64__        (113u)

#if defined(__cplusplus)
}
#endif  /* __cplusplus */

#endif  /*__S12_DERIVATIVES_H */

