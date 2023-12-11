section .data   
    userMsg db 'Please enter a number: '
    lenUserMsg equ $ - userMsg
    dispMsg db 'You have netered: '
    lenDispMsg equ $ - dispMsg

section .bss
    num resb 5

section .text   
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, userMsg
    mov edx, lenUserMsg
    int 80h
     
    ;read and store user msg
    mov eax, 3
    mov ebx, 2
    mov ecx, num  ; 5 bytes 4 numeric 1 for sign
    mov edx, 5
    int 80h

    ;Output the numebr entered
    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx, 5
    int 80h 

    ;exit code
    mov eax, 1
    mov ebx, 0
    int 80h
