; syntax of MOV instruction is 
; MOV destination, source

; MOV register, register
; MOV register, immediate
; MOV memory, immediate
; MOV register, memory
; MOV memory, register

;Both values in MOV operation should be of same size

; MOV EBX, [MY_TABLE] ; moves the address of my table to ebx
; MOV [EBX], 110 ; MY_TABLE[0] = 110

; It is not clear whether you want to move a byte equivalent or word equivalent of the number 110 IN such cases it is wise to use a tyoe specifier

;   BYTE - 1
;   WORD - 2
;   DWORD- 4
;   QWORD- 8
;   TBYTE- 10

; Example it stores the name 'ZARA ALI and changes its values to another name 'Nuha ALi 


section .text  
    global _start

_start:
    ;print the name
    mov edx, 9 ; length of message
    mov ecx, name ; messsage to be displayed
    mov ebx, 1 ; file descriptor stdout
    mov eax, 4 ; system call number sys_write
    int 0x80 ; call kernel

    mov [name], dword 'Nuha'
    ;change the name
    ;print the new name
    mov edx, 8 ; length of string
    mov ecx, name 
    mov ebx, 1
    mov eax,4
    int 0x80

    mov eax,1  ;sys_exit
    int 0x80

section .data
name db 'Zuha ali '
