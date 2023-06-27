STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

ASCCI_OFFSET equ 48

section .data
    digit db 0,10
    inputa db "Enter first single digit number: ",0
    inputb db "Enter second single digit number: ",0
    output db "Sum of the two numbers is: ",0

section .bss
    num resb 2
    temp resb 1
    digitSpace resb 100
    digitSpacePos resb 8

section .text
    global _start

_start:
    mov rax, inputb
    call _print
    call _getDigit
    mov [temp], rax

    mov rax, inputb
    call _print
    call _getDigit
    add rax, [temp]
    mov [temp], rax
    mov rax, output
    call _print
    mov rax, [temp]
    call _printRAXDigit

    mov rax, SYS_EXIT
    mov rdi, 0
    syscall


_getDigit:
    mov rax, SYS_READ
    mov rdi, STDIN
    mov rsi, num
    mov rdx, 2
    syscall
    mov rax, [num]
    sub rax, ASCCI_OFFSET
    ret

_printRAX:
    mov rcx, digitSpace
    mov rbx, 10
    mov [rcx], rbx
    inc rcx
    mov [digitSpacePos], rcx

_printRAXLoop:
    mov rdx, 0
    mov rbx, 10
    div rbx
    push rax
    add rdx, 48

    
    

_printRAXDigit:
    add rax, ASCCI_OFFSET 
    mov [digit], al
    mov rax, SYS_WRITE
    mov rdi, STDOUT
    mov rsi, digit
    mov rdx, 2
    syscall
    ret

_print:
    push rax
    mov rbx, 0

_printLoop:
    inc rax
    inc rbx
    mov cl, [rax]
    cmp cl, 0
    jne _printLoop

    mov rax, SYS_WRITE
    mov rdi, STDOUT
    pop rsi
    mov rdx, rbx
    syscall

    ret

