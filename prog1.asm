section .data
text db "Hello World",10
section .text
global_start
_start:
mov rax,1
mov rdi,1
mov rsi,text
mov rdx,16
syscall
mov rax,60
mov rdi,05
syscall
