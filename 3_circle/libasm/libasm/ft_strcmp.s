section .text
	global  _ft_strcmp

_ft_strcmp:
	push  rbp
	mov rbp, rsp
	xor		rax, rax
	xor		rcx, rcx
	xor		rdx, rdx

cmp:
	mov		dl, BYTE[rsi+rcx]
	cmp		dl, BYTE[rdi+rcx]
	jne		end
	cmp		BYTE[rdi+rcx], 0
	je		end
	inc		rcx
	jmp		cmp

end:
	mov		al, BYTE[rdi+rcx]
	sub		rax, rdx
	leave
	ret