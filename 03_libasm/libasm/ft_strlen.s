section .text
	global _ft_strlen

_ft_strlen:
	push rcx
	xor rcx, rcx

loop:
	cmp BYTE[rdi + rcx], 0
	je  end
	inc rcx
	jmp loop

end :
	pop rcx
	ret
	