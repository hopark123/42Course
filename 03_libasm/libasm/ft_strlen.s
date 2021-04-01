section .text
	global _ft_strlen

_ft_strlen:
	xor rax, rax

loop:
	cmp [rdi], rax
	je  return
	inc rax
	inc rdi
	jmp loop

return:
	ret