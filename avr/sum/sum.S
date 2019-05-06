; set up global data area =============================================
	.data

	; set up "data" array
data:
	.word	5
	.word	3
	.word	7
	.word	10
	.word	42
	.word	6
	.word	22
	.word	15
	.word	32

	; set up uninitialized "cnt" and "sum" variables
	.comm	cnt,2,1
	.comm	sum,2,1

	; set up initialized variable "odd"
	
	.section .bss
odd:
	.zero	2	; initialize 16-bits with zero


	; program code starts here ====================================
	.text
main:
	rjmp .L2
.L5:
	lds r24,odd		; load "odd" into r24,r25
	lds r25,odd+1
	or r24,r25		; OR the two bytes (why?)
	breq .L3		; branch if equal to zero

	lds r24,cnt		; load "cnt" into r24,r25
	lds r25,cnt+1

	lsl r24			; left shift, high bit into carry flag
	rol r25			; rotate left, carry enters low bit (16-bit *2)

	subi r24,lo8(-(data))	; 16-bit subtract r24,r25 from (-data[i]) HUH?
	sbci r25,hi8(-(data))

	movw r30,r24		; save result in "z" (r30,r21)
	ld r24,Z		; 16-bit move (data[Z] -> r24,r25)
	ldd r25,Z+1

	lds r18,sum		; get current sum into r18,r19
	lds r19,sum+1

	add r24,r18		;add lo(sum) + lo(data[i])
	adc r25,r19		; add with carry (hi(sum) + hi(data[i])

	sts sum+1,r25		; put result back in r24,r24
	sts sum,r24
.L3:
	lds r24,odd		; load 16_bit odd into r24,r24
	lds r25,odd+1

	ldi r18,lo8(1)		; set up 16_bit "1"
	or r24,r25		; see if this is zero
	breq .L4		; if so, branch

	ldi r18,0		; set r18 to zero
.L4:
	mov r24,r18		; save r18 inro r24
	ldi r25,0		; set r25 to zero

	sts odd+1,r25		; save result in "odd"
	sts odd,r24

	lds r24,cnt		; load "cnt" into r24,r25
	lds r25,cnt+1		
	adiw r24,1		; add 1 to 16-bit value in r24,e25
	sts cnt+1,r25		; save result back in "cnt"
	sts cnt,r24
.L2:
	lds r24,cnt		; load 16-bit z'cntz' into r24, r25
	lds r25,cnt+1
	sbiw r24,9		; 16-bit subtract "9" from r24,r26
	brlt .L5		; branch if less
; end of program, but where do we go? =================================
	ret

