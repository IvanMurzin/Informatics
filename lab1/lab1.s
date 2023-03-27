bits	64
;	res=( (a+b)^2-(c-d)^2 )/( a+e^3-c )
;	res=( (a+b-c+d)*(a+b+c-d) )/( a+e^3-c )
section .data
res: 
	dq	0
a:
	dw	16
b:	
	dd	4
c:
	dd	4
d:	
	dw	14
e:
	dw	2
section .text
global	_start
_start:
	;	init variables
	movzx	eax, word[a] 	; eax=a
	mov	ebx, dword[b] 	; ebx=b
	mov	ecx, dword[c] 	; ecx=c
	movzx	edi, word[d] 	; edi=d
	movzx	esi, word[e]	; esi=e

	;	numerator
	push	rax		; save rax
	push 	rax		; save rax
	add	rax, rbx	; rax=a+b
	sbb 	rax, rcx	; rax=a+b-c	sbb because of unsigned variables
	jc	_error		; if negative return with an error
	add	rax, rdi	; rax=a+b-c+d
	mov 	rbp, rax	; rbp=a+b-c+d
	pop	rax		; rax=a
	add	rax, rbx	; rax=a+b
	add	rax, rcx	; rax=a+b+c
	sbb	rax, rdi	; rax=a+b+c-d	sbb because of unsigned variables
	jc	_error		; if negative return with an error
	imul	rbp		; rax=(a+b-c+d)*(a+b+c-d) or rdx-hier bits, rax-lower bits
	pop	r8		; r8=a
	push 	rdx		; save rdx-hier bits
	push	rax		; save rax-lower bits

	; 	denominator
	mov	rax, rsi	; rax=e	
	imul 	rax, rsi	; rax=e^2
	imul	rax, rsi 	; rax=e^3
	add	rax, r8		; rax=a+e^3
	sbb	rax, rcx	; rax=a+e^3-c
	jc	_error		; if negative return with an error
	je      _error		; if denominator==0 exit with an error
	
	; 	result
	mov 	rsi, rax	; rsi=a+e^3-c
	mov	rdi, rdx	; rdx=hier bits of rax
	pop     rax		; rax=lower bits
	pop	rdx		; rdx=hier bits

	idiv	rsi		; rax=((a+b-c+d)*(a+b+c-d))/(a+e^3-c)
	mov	[res], rax 	; res=((a+b-c+d)*(a+b+c-d))/(a+e^3-c)	


	mov 	eax, 60
	mov 	edi, 0
	syscall

_error:
	;	exit program with an error
    	mov     eax, 60     
    	mov     edi, 1 
	syscall

