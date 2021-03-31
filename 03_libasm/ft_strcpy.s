section .text
	global _ft_strcpy

_copy_helper:
	mov cl, [rsi]
	mov [rdi], cl
	inc rdx
	inc rdi
	inc rsi
	cmp cl, 0
	jne _copy_helper
	ret

_ft_strcpy
	mov rdx, 0
	call _copy_helper
	sub rdi, rdx
	mov rax, rdi
	ret