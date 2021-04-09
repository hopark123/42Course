section .text
	global _ft_strcpy
	extern _ft_strlen

_ft_strcpy:
	push rcx
	xor rcx, rcx

loop:
	mov al, BYTE[rsi + rcx]
	mov BYTE[rdi + rcx], al
	inc rcx
	cmp al, 0
	je end
	jmp loop

end :
	pop rcx
	mov rax, rdi
	ret







