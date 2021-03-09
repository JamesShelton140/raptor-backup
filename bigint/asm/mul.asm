SECTION .TEXT
        GLOBAL mul128
; rdx-rdi * rcx-rsi
mul128:
        mov rax, rdi
        mov rbx, rdx 
        mul rsi
        mov r8, rax
        mov r9, rdx

        mov rax, rbx
        mul rcx
        mov r10, rax
        mov r11, rdx

        mov rax, rcx
        mul rdi
        add r9, rax
        adc r10, rdx
        adc r11, 0
        
        mov rax, rsi
        mul rbx
        add r9, rax
        adc r10, rdx
        adc r11, 0
        
        ret