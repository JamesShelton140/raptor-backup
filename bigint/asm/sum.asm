SECTION .TEXT
        GLOBAL add128

add128:
        add rdi, rsi    ; add x.low and y.low, save in rdi
        adc rdx, rcx    ; add x.high and y.high with carry, save in rdx
        mov rsi, 0      ; set rsi = 0
        adc rsi, 0      ; add the carry bit to rsi
        ret             ; return with rdi = x+y.low, rdx = x+y.high, and rsi = carry