section .text
	global _ft_strcmp

_cmp_exit:
	sub rax, rbx
	ret

_ft_strcmp:
	mov rax, 0
	mov al, [rdi]
	mov bl, [rsi]
	cmp al, 0
	je _cmp_exit
	cmp bl, 0
	je _cmp_exit
	inc rdi
	inc rsi
	cmp al, bl
	jne _cmp_exit
	je _ft_strcmp