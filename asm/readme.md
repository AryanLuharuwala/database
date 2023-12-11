To speed up a processors operations the processor includes some internal memory storage locations called registers
the registers store data elements for processing without having to access the memory, a limited number of registers are built into the processor chip

Processor Registers
There are ten 32 bit and six 16 bit processor registers in IA32 architecture, the registers are grouped into-
General registers
Control registers
Segment registers

The general registersa re further divided into 
Data registers
Pointer registers
Index registers


Datqa registers 
Four 32 bit data registers are used for arithmetic logical and other operations, these 32 bit registers can be used in three ways

As completer 32 bit data registers EAX<EBX<ECX<EDX

Lower Halves of the 32 bit registers can be used as four 16 bit data registers, AX<BX<CX<DX
Lower and higher halves of the above mentioned 16 bit data registers cna be used as 8 8bit data registers AH,AL,BH,BL,CH,CL,DH,DL

Some of the data registers have specific uses in arithmetic operations

AX is the primary accumulator; it is used in input/output and most arithmetic instructions, FOr example in multiplication operation, one operand is stored in EAX or AX or AL register according to the size of the operand.

BX is known as the base register as it could be used in indexed addressing

CX is known as count register as the ECX, CX, registers store the loop count in iterative operations

DX is known as the data register, It is also used in inout.output operations, it is also used with AX register along with DX for mulitply and divide operations involving large values

Pointer registers
pointer registers are  32 bit EIP, ESP, EbP registers and corresponding 16 bit right portions IP, SP, BP there are three categories

Instruction Pointer(IP) the 16 bit IP register stores the offset address of the next instruction to be executed IP in association with the CS register as CS:IP gives the complete address of the current instruction in the code segment
Stack Pointer(SP) the 16 bit SP register provides the offset value within the program stack, SP in association with the SS register SS:SP refers to be current position of data or address within the program stack

Base Pointer BP the 16 bit BP register mainly helps in referencing the parameter variables passed to a subroutine, the address in SS register is combined with the offset in BP to get the location of the parameter. BP can also be combined with DI and Si as base register for special addressing

Index Registers
the 32 bit registers ESI EDI and their 16 bit rightmost portions SI and DI are used for indexed addressing and sometimes used in addition and subtraction the two sets of index pointers

Source Index SI it is used as source index for string operations
Destination Idnex DI it is used as destination index for string operations


COntrol Registers
The 32 bit instruction pointer register and the 32 bit flags register combined are considered as the control register

Many instructions involve comparisons and mathematical calculations and change the status of flags and other conditions instruction testa and the vlaue of these status flags to take the control flow to other location

Overflow flag 11 OF it indicates the overflow of a high-order bit (leftmost bit) of data after a signed arithmetic operation

Direction Flag 10 DF it determines left or right direction for moving or comparing stringdata. When the DF value is 0, the string operation takes left-to right direction and when the value is set to 2 the string operation takes right-to-left direction

Interrupt Flag 9 IF it determines whther the external interrupts like keyboard entry are to be ignored or processed, it disables the external interrupt when the value is set to 0 and enables interrupt when set to 1

Trap Flag 8 TF it alloes setting the operation of the processor in single-step mode. The DEBUG program we used sets the trap flag, so we could step throught the execution one instruction at a time

Sign Flag 7 SF it shows the sign of the result of an arithmetic operation. This flag is set according to the sign of a data item following the arithmetic operation. The sign is indicated by the high-order of leftmost bit. A positive result clears the value of SF to 0 and negative results set it to 1

Zero Flag 6 ZF it indicates the result of an arithmetic or comparison operation, a non zero result clears the zero flag to 0 and a zero result sets it to 1

Auxiliary Carry FLag 4 AF it contains the carry from bit 3 to bit 4 following an arithmetic operation used for specialized arithmetic the AF is set when a 1byte arithmetic operation causes a carry from bit 3 to bit 4

Parity flag 2 PF it indicates the total number of 1 bit in the result obtained form an arithmetic operation. An even number of 1 bits clears the parity flag to 0 and an odd number of 1 bits ssets the parity flag to 1

Carry Flag 0 CF it contains the carry of 0 or 1 from a high-order bit leftmost after an arithmetic operation. It stores the contents of last bit of a shift or rotate operation

Code Segment it contains all the instruction to be executed. A 16 bit code segment or CS register stores the starting address of the code segment

Data segment it contains data, constants and work areas a 16 bit data segment register or DS register stores the starting address of the data segment

Stack Segment it contains data and return addresses of procedures or subroutines. It is implemented as a stack data structuure. The stack segment register or SS register stores the starting address of the stack.

