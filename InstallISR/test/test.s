	.file	"test.c"
	.arch msp430x110

	.text
	.p2align 1,0
.global	main
	.type	main,@function
/***********************
 * Function `main' 
 ***********************/
main:
	/* prologue: frame size = 4 */
.L__FrameSize_main=0x4
.L__FrameOffset_main=0x8
	mov	#(__stack-4), r1
	mov	r1,r4
	/* prologue end (size=3) */

	mov	r15, @r4 
	mov	r14, 2(r4) 
	mov	#llo(0), r15 

	/* epilogue: frame size=4 */
	add	#4, r1
	br	#__stop_progExec__
	/* epilogue end (size=3) */
	/* function main size 11 (5) */
.Lfe1:
	.size	main,.Lfe1-main
/********* End of function ******/

	.p2align 1,0
.global	SCI0Handler
	.type	SCI0Handler,@function
/***********************
 * Interrupt Sub-Routine `SCI0Handler' at 0x00ff
 ***********************/
SCI0Handler:
	/* prologue: frame size = 2 */
.L__FrameSize_SCI0Handler=0x2
.L__FrameOffset_SCI0Handler=0x6
	push	r5
	push	r4
	mov	r1, r5
	add	#6, r5
	sub	#2, r1	;	2, fpn 1
	mov	r1,r4
	/* prologue end (size=7) */

	add	#llo(1), @r4

	/* epilogue: frame size=2 */
	add	#2, r1
	pop	r4
	pop	r5
	reti
	/* epilogue end (size=4) */
	/* function SCI0Handler size 13 (2) */
.Lfe2:
	.size	SCI0Handler,.Lfe2-SCI0Handler
/********* End of function ******/


/*********************************************************************
 * File test.c: code size: 24 words (0x18)
 * incl. words in prologues: 10, epilogues: 7
 *********************************************************************/
