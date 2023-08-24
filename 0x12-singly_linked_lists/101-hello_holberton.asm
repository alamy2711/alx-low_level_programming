section .text
	greeting: db "Hello, Holberton", 10, 0
	extern printf
	global main

main:
	; Start
	push rbp
	mov rdi, greeting
	call printf

	; Exit
	pop rbp
	mov rax, 0
	ret