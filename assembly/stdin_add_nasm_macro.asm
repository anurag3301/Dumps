STDIN equ 0
STDOUT equ 1
STDERR equ 2

SYS_READ equ 0
SYS_WRITE equ 1
SYS_EXIT equ 60

ASCCI_OFFSET equ 48


%macro exit 0
    mov rax, SYS_EXIT
    mov rdi, 0
    syscall
%endmacro

%macro printDigit 1
    mov rax, %1
    call _printRAXDigit
%endmacro

%macro print 1
    mov rax, %1
    call _print
%endmacro

section .data
    digit db 0,10
    inputa db "Enter first single digit number: ",0
    inputb db "Enter second single digit number: ",0
    output db "Sum of the two numbers is: ",0

section .bss
    num resb 2
    temp resb 1

section .text
    global _start

_start:
    print inputa
    call _getDigit
    mov [temp], rax

    print inputb
    call _getDigit
    add rax, [temp]
    mov [temp], rax
    print output
    printDigit [temp]

    exit


_getDigit:
    mov rax, SYS_READ
    mov rdi, STDIN
    mov rsi, num
    mov rdx, 2
    syscall
    mov rax, [num]
    sub rax, ASCCI_OFFSET
    ret
    

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

