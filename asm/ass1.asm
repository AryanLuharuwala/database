segment .text   
    global _start

_start:
    mov edx, len
    mov ecx, msg
    mov ebx, 1  ;file descriptor(stdout)
    mov eax, 4  ; system call number
    int 0x80    ; call kernel

    mov eax, 1
    int 0x80 

segment .data
msg db 'Hello WOrld!',0xa
len equ $ - msg