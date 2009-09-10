;;;-----------------------------------------
;;; Start MC68HCS12 gcc assembly output
;;; gcc compiler 3.3.6-m68hc1x-20060122
;;; Command:	\cygwin\usr\\lib\gcc-lib\m6811-elf\3.3.6-m68hc1x-20060122\cc1.exe -quiet -I ../ -I . -iprefix C:\cygwin\usr\m6811-elf\bin\../lib/gcc-lib/m6811-elf\3.3.6-m68hc1x-20060122\ -D__GNUC__=3 -D__GNUC_MINOR__=3 -D__GNUC_PATCHLEVEL__=6 -Dmc68hc1x -D__mc68hc1x__ -D__mc68hc1x -D__INT__=32 -Dmc6812 -DMC6812 -Dmc68hcs12 ../ISR.c -quiet -dumpbase ISR.c -m68hcs12 -auxbase ISR -O3 -fomit-frame-pointer -o ISR.s
;;; Compiled:	Thu Mar 26 13:17:35 2009
;;; (META)compiled by GNU C version 3.3.2.
;;;-----------------------------------------
	.file	"ISR.c"
	.mode mlong
	; extern	SCI0Handler
	; extern	_start
	.globl	interrupt_vectors
	.section	.vectors,"a",@progbits
	.type	interrupt_vectors, @object
	.size	interrupt_vectors, 128
interrupt_vectors:
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	SCI0Handler
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	DUMMY_VECTOR
	.word	_start
	.word	_start
	.word	_start
	.sect	.text
	.globl	ISR_Init
	.type	ISR_Init,@function
ISR_Init:
	rts
	.size	ISR_Init, .-ISR_Init
	.type	DUMMY_VECTOR,@function
DUMMY_VECTOR:
	rts
	.size	DUMMY_VECTOR, .-DUMMY_VECTOR
	.ident	"GCC: (GNU) 3.3.6-m68hc1x-20060122"
