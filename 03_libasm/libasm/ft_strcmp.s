section .text
	global _ft_strcmp

_ft_strcmp:
	push rcx
	xor rcx, rcx
	jmp loop

loop_inc:
	inc rcx

loop:
	cmp BYTE[rdi+rcx], 0
	je end
	cmp BYTE[rsi+rcx], 0
	je end
	mov al, BYTE[rdi+rcx]
	mov bl, BYTE[rsi+rcx]
	cmp al, bl
	je loop_inc

end:
	mov al, BYTE[rdi+rcx]
	sub al, BYTE[rsi+rcx]
	pop rcx
	ret