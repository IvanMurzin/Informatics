bits	64
;	res=( (a+b)^2-(c-d)^2 )/( a+e^3-c )
section .data
res: 
	dq	0
a:
	dw	0;65535
b:	
	dd	4294967295
c:
	dd	4294967295
d:	
	dw	65535
e:
	dw	65535
section .text
global	_start
_start:
	;	init variables
	movzx	eax, word[a] 	; eax=a
	movzx 	r8, word[a]	; r8=a
	mov	ebx, dword[b] 	; ebx=b
	mov	ecx, dword[c] 	; ecx=c
	movzx	edi, word[d] 	; edi=d
	movzx	esi, word[e]	; esi=e

	;	numerator
	add	eax, ebx	; rax=a+b	; 2^16+2^32<=2^33
	jc	_error		; if overflow return with an error
	mul	rax		; rax=(a+b)^2	; 2^32*2^32=2^64
	push	rcx		; save rcx
	sbb	rcx, rdi	; rcx=c-d	; sbb because of unsigned variables
	jc	_error		; if negative return with an error
	push    rax		; save rax for mul rcx
	mov 	rax, rcx	; 
	mul	rax		; rcx=(c-d)^2	; 2^32*2^32=2^64
	mov 	rcx, rax
	pop	rax
	sbb	rax, rcx	; rax=(a+b)^2-(c-d)^2
	jc	_error		; if negative return with an error
	pop 	rcx		; rcx=c
	push 	rax		; save numerator

	; 	denominator
	mov	rax, rsi	; rax=e	
	mul 	rsi		; rax=e^2
	mul     rsi 		; rax=e^3 	; 2^16*2^16*2^16=2^48
	add	rax, r8		; rax=a+e^3
	sbb	rax, rcx	; rax=a+e^3-c
	jc	_error		; if negative return with an error
	je      _error		; if denominator==0 exit with an error
	
	; 	result
	mov 	rsi, rax	; rsi=a+e^3-c
	pop	rax		; rax=(a+b)^2-(c-d)^2
	div	rsi		; rax=((a+b)^2-(c-d)^2)/(a+e^3-c)
	mov	[res], rax 	; res=((a+b)^2-(c-d)^2)/(a+e^3-c)	


	mov 	eax, 60
	mov 	edi, 0
	syscall

_error:
	;	exit program with an error
    	mov     eax, 60     
    	mov     edi, 1 
	syscall

