#ifndef __VECTORS_COMP_H
#define __VECTORS_COMP_H

void __near _Startup(void);

#define II_ENTRY_POINT	_Startup

#if defined(__STDC__)
#define II_INTERUPT	__interrupt
#else
#define II_INTERUPT	interrupt
#endif

#endif /* __VECTORS_COMP_H */

