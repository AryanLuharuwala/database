Assembly addressing modes

most assembbly manguage instructuon require operands to be processed, an operand address provides the location, where the data to be processed is stored.

Some instruction do not require an operand whereas some other instruction may require one two or three operands
first operand is generally the destination which contains data in a register or memory location and the second operand is the source, source contains either the data to be deloverred(immediate addressing) or the address (inregister or memory of data) generally the source data remains unaltered

Three basic modes of addressing

-Register addressing
-Immediate addressing
-memory addressing

Register addressing a register contains the operand, Depending opon the instruction the register may be the first operand, the second or third

MOV DX, TAX_RATE; Register in the first operand
MOV COUNT,CX; register in the second operand
MOV EAX, EBX; register for both operands


Immediate addressing
an immediate operand has a constant value or an expression, When an instruction with two operands uses immediate addressing, the first operand may be a register or memory location, the second operand may be an immediate constant, the first operand defines the length of data

BYTE_VALUE DB 150 ; a byte value is defined
WORD_VALUE DB 300 ; a word value is defined
ADD BYTE_VALUE, 65 ; an imediate operand 65 is added
MOV AX, 45H ; Immediate constant 45H is transferred to AX



Direct memory addressing

When operand are specified in memory addressing mode, direct access to main memory, usually to the data segment is required, This way of addressing results ijn slower processing of data, to locate the exact location of data in memory we need the segment start address which is typically found in the DS register and an offset value. This offset value is also called the effective address.

In direct addressing mode, the offset value is specified directly as part of the instruction, usually indicated by the variable name, the assembler calculates the offset value and maintains a symbol table which stores the offset value of all the variables used in the program.
in direct addressing one of the operands refers toa  memory location and the other operand refers a register.

ADD BYTE_VALUE, DL ;Adds the reigster in the memory location
MOV BX, WORD_VALUE ;Operand from the memory is added to register


Direct offset addressing

Tjis addressing ,ode uses the arithmetic operators to modify an address 

BYTE_TABLE DB 14,15,22,45  ; Tbales of bytes
WORD_TABLE DB 134,345,567,123 ; Tables of words

the following accesses data from the tables in memory into registers

MOV CL, BYTE_TABLE[2] ; gets the 3rd element of BYTE_TABLE
MOV CL, BYTE_TABLE+2 ; Gtes the 3rd element of BYTE_TABLE
MOV CX, WORD_TABLE[3] ; Gets the 4th element of WORD_TABLE
MOV CX, WORD_TABLE +3; Gets the 4th element of WORD_TABLE


Indirect Moemory addressing
This addressing mode utilizes the computers abiltiy of segment: offset addressing. Gneerally the base registers EBX, EBP (or BX,BP) and the index registers (DI, SI) coded within square brackets for memory references are used for this purposes


Indirect addressing is generally used for variables containing several elements liek arrays, starting addresses are stored in say EBX register

MY_TABLE TIMES 10 DW 0 ; allocates 10 words (2 bytes) each initialized to 0
MOV EBX, [MY_TABLE]  ; effective address of my table in EBX
MOV [EBX], 110 MY_TABLE[0]=110
ADD EBX, 2 ; EBX =EBX+2   ; each adderess holds 2 bytes, adding 2 moves pointer to next word, MY_TABLE[1]
MOV [EBX], 123  ; MY_TABLE[1] =123

