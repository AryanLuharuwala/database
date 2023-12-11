NASM provides various define directives for reserving storage space for variables. the define assembler directive is used for allocating of storage space. It can be used to reserve as well as initialize one or more bytes.

Allocating Storage Space for Initialized Data

[vaiable-name] define-directive initial-value [,initial-value]...

Where, variable-name is the identifier for each storage space. The assembler associates an offset value for each variable name defined in the data segment.

DB define Byte allocates 1 Byte
DW Define Word allocates 2 bytes
DD Define Doubleword  allocates  4 bytes
DQ Define Quadword allocates 8 bytes
DT Define Ten Bytes allocates 10 bytes


choice DB 'y'
number DW 12345
neg_number DW -12345
big_number DQ 123456789
real_number DD 1.234
real_number2 DQ 123.456

Each byte of character is stored as its ASCII value in hexadecimal
Each decimal value is autmatically converted to its 16 bit binary equivalent and stored as a hexadecimal number
Processor uses the little-endian byte ordering
Negative numbers are converted to its 2's complement representation
Short and long floating-point numbers are represented using 32 and 64 bits respectively

section .text
    global _start

_start:
    mov edx,1
    mov ecx, choice
    mov ebx, 1
    mov eax, 4
    int 0x80

    mov eax, 1
    int 0x80

section .data
choice DB 'y'