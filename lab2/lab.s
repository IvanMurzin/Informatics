bits	64
;	Sorting rows of matrix by min elements
section	.data
n:
	dd	4
m:
	dd	5
matrix:
	dd	7, 8, 9, 4, 6	
	dd	16, 15, 14, 13, 1
	dd	9, 10, 13, 12, 11
	dd	1, 3, 2, 9, 5
min:
	dd	0, 0, 0, 0
section	.text
global	_start
_start:
	mov r8d, [n]	; r8d = n       ; number of rows
	mov r9d, [m]	; r9d = m       ; number of columns
	cmp r8d, 1	; check if n == 1
	jle exit	; if rows <= 1 exit

	mov ecx, r8d	; ecx = n       ; number of rows
	mov ebx, matrix	; ebx = matrix
	mov r10, min	; r10 = min
	xor r11, r11	; r11 - index of current row

find_min:
	xor edi, edi	; edi - local index in row
	mov eax, [rbx]	; eax - first element in the row
	push rcx	; save number of rows
	mov ecx, r9d	; ecx = m       ; number of columns
	dec ecx		; make ecx zero-based
	jecxz store_min	; if ecx == 0 write result in min array

next_element:
	inc edi		        ; move to the next row element
	cmp eax, [rbx+rdi*4]    ; compare min with current
	cmovg eax, [rbx+rdi*4]  ; if min greater than current - replace 
	loop next_element       ; check all elements in row

store_min:
	mov [r10+r11*4], eax    ; store min element in min array
	inc r11d		; increment current row index
	lea rbx, [rbx + r9*4]   ; move rbx to the next row in matrix 
	pop rcx		        ; restore the number of rows
	loop find_min	        ; check all columns

	xor ebx, ebx	; ebx = 0
	mov ecx, r8d 	; ecx = n       ; number of rows
	dec ecx		; make ecx zero-based

	
main_sort_loop:
	mov r12d, 1	; set flag sorted = true
	mov r13d, 1	; set flag isOddLoop = true
	xor edi, edi	; edi - index in inner loop

odd_loop:
	mov eax, [r10+rdi*4]	; eax = min[rdi]
	mov edx, [r10+rdi*4+4]	; edx = min[rdi+1]
	cmp eax, edx		; if min[rdi]>min[rdi+1]
	%ifidni SORT_ORDER, ASC
	jg swap                 ; swap rdi and rdi+1 matrix rows
	%else
	js swap			; swap rdi and rdi+1 matrix rows
	%endif

next_iter_odd_loop:	
	add edi, 2              ; edi += 2
	cmp ecx, edi		; if n-1 > index
	jg odd_loop		; continue

	mov edi, 1		; index in inner loop starts with 1
	xor r13d, r13d		; set flag isOddLoop = false

even_loop:
	mov eax, [r10+rdi*4]	; eax = min[rdi]
	mov edx, [r10+rdi*4+4]	; edx = min[rdi+1]
	cmp eax, edx		; if min[rdi] > min[rdi+1]
	%ifidni SORT_ORDER, ASC
	jg swap                 ; swap rdi and rdi+1 matrix rows
	%else
	jl swap			; swap rdi and rdi+1 matrix rows
	%endif

next_iter_even_loop:
	add edi, 2              ; edi += 2
	cmp ecx, edi		; if n-1 > index
        jg even_loop            ; continue

	or r12d, r12d		; check sorted flag
	jz main_sort_loop	; if sorted = false continue sorting

	jmp exit		; skip swapping not in a loop

swap:
        mov [r10+rdi*4], edx	; min[rdi] = min[rdi+1]
	mov [r10+rdi*4+4], eax	; min[rdi+1] = min[rdi]
	xor r12d, r12d		; set flag sorted = false
	push rcx		; save ecx
	mov ecx, r9d		; ecx = m       ; number of rows
	mov r14d, r9d		; r14 = m       ; offset
	imul r14d, edi		; r14 = m * index of swapping row
	shl r14d, 2		; r14 *= 4 because of ints

swap_rows_loop:
	mov eax, [matrix+r14] 	        ; eax = matrix[rdi][rcx]
	mov edx, [matrix+r14+r9*4]      ; edx = matrix[rdi+1][rcx]
	mov [matrix+r14], edx           ; matrix[rdi][rcx] = matrix[rdi+1][rcx]
	mov [matrix+r14+r9*4], eax      ; matrix[rdi+1][rcx] = matrix[rdi][rcx]
	; shift offset to the next item
        add r14d, 4		        ; equals to '+rcx*4' in previous lines
	loop swap_rows_loop	        ; check all rows
	pop rcx			        ; restore rcx
	or r13d, r13d		        ; check isOddLoop flag
	jz next_iter_even_loop	        ; if isOddLoop = false go to the even loop
	jmp next_iter_odd_loop          ; else to the odd loop

exit:	
	mov	eax, 60
	mov 	edi, 0
	syscall

