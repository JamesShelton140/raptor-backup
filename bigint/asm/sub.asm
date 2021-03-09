SECTION .TEXT
        GLOBAL sub128

sub128:
        sub rdi, rsi    ; subtract y.low and x.low, save in rdi
        sbb rdx, rcx    ; subtract y.high from x.high with borrow, save in rdx
        mov rsi, 0      ; set rsi = 0
        sbb rsi, 0      ; add the carry bit to rsi
        ret             ; return with rdi = x+y.low, rdx = x+y.high, and rsi = carry