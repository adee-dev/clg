section .data
    ncnt db 0
    pcnt db 0
    array: dw  80H, 4CH, 3FH
    len equ 3
    msg1: db 'positive  numbers are:' , 0xa
    len1: equ $-msg1
    msg2: db 'negative numbers are:' , 0xa
    len2: equ $-msg2
    
    
section .bss
    buff resb 02
    
section .text
    global _start
    _start:
        Mov rsi, array
        mov rcx ,03
        
        A1:
        bt word[rsi],15
        jnc A
        inc byte[ncnt]
        jmp skip
        
        A:
        inc byte[pcnt]
        
        skip:
            inc rsi
            inc rsi 
            loop A1
            
        mov rax, 1
        mov rdi , 1
        mov rsi, msg1
        mov rdx, len1
        syscall
        
        mov bl,[pcnt]
        mov rdi, buff
        mov rcx, 02
        
        call display
        
        mov rax, 1
        mov rdi, 1
        mov rsi, msg2
        mov rdx,len2
        
        syscall
        
        mov bl, [ncnt]
        mov rdi,buff
        mov rcx, 02
        
        call display
        
        mov rax, 60
        mov rdi, 0
        syscall
        
        display
            rol bl, 4
            mov al, bl
            and al, 0FH
            cmp al, 09
            jbe B
            
       add al, 07h
       
       B:
       add al, 30H
       mov[rdi], al
       inc rdi
       loop display
       
       mov rax, 1
       mov rdi,1
       mov rsi, buff
       mov rdx, 02
       syscall
       
       ret
       
