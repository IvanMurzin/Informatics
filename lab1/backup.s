bits	64
;	res=( (a+b)^2-(c-d)^2 )/( a+e^3-c )
section .data
res: 
	dq	0
a:
	dw	16
b:	
	dd	4
c:
	dd	14
d:	
	dw	4
e:
	dw	2
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
	add	rax, rbx	; rax=a+b	; 2^16+2^32<=2^33
	jc	_error		; if overflow return with an error
	imul	rax		; rax=(a+b)^2	; 2^32*2^32=2^64
	push	rcx		; save rcx
	sbb	rcx, rdi	; rcx=c-d	; sbb because of unsigned variables
	jc	_error		; if negative return with an error
	imul	rcx, rcx	; rcx=(c-d)^2	; 2^32*2^32=2^64
	sbb	rax, rcx	; rax=(a+b)^2-(c-d)^2
	jc	_error		; if negative return with an error
	pop 	rcx		; rcx=c
	push 	rax		; save numerator

	; 	denominator
	mov	rax, rsi	; rax=e	
	imul 	rsi		; rax=e^2
	imul    rsi 		; rax=e^3 	; 2^16*2^16*2^16=2^48
	add	rax, r8		; rax=a+e^3
	sbb	rax, rcx	; rax=a+e^3-c
	jc	_error		; if negative return with an error
	je      _error		; if denominator==0 exit with an error
	
	; 	result
	mov 	rsi, rax	; rsi=a+e^3-c
	pop	rax		; rax=(a+b)^2-(c-d)^2
	idiv	rsi		; rax=((a+b)^2-(c-d)^2)/(a+e^3-c)
	mov	[res], rax 	; res=((a+b)^2-(c-d)^2)/(a+e^3-c)	


	mov 	eax, 60
	mov 	edi, 0
	syscall

_error:
	;	exit program with an error
    	mov     eax, 60     
    	mov     edi, 1 
	syscall

