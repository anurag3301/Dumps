; Buffer to store string version of RAX with two byte
; First byte 0 which will be updated by the ascii value
; of the number and second byte 10 which is new line
section .data
    digit db 0,10           

section .text
    global _start

_start:
    push 4
    push 8
    push 3

    ; Pop from stack and store the number in rax
    ; Print the number in the  rax register
    pop rax
    call _printRAXDigit
    pop rax
    call _printRAXDigit
    pop rax
    call _printRAXDigit


_printRAXDigit:
    add rax, 48         ; add 48 to the number in rax which will get the ascii code
    mov [digit], al     ; update the first value of the digit buffer with the number ascii
    mov rax, 1          ; Initialise the sys_write
    mov rdi, 1          ; file discripter to be STDOUT
    mov rsi, digit      ; store the address of digit in rsi to be printed
    mov rdx, 2          ; print two bytes, number + \n
    syscall
    ret
