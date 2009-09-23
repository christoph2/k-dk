#ifndef __VECTORS_COMP_H
#define __VECTORS_COMP_H

@interrupt void _stext(void);

#define II_ENTRY_POINT	_stext
#define II_INTERUPT	@interrupt

#endif /* __VECTORS_COMP_H */

