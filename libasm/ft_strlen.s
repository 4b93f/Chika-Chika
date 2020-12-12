section .text
	global _ft_strlen

_ft_strlen:
		mov rax, 0
		jmp _loop

_loop:
			inc rax
			inc rdi
			mov cl, [rdi]
			cmp cl, 0
			jne _loop
			ret 