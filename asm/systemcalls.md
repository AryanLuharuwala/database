System alls are API for the interface btween the user space and the kernel space. We have already used the system calls. sys_write and sys_exit, for writing into the screen and exiting from the program respectively

Put the system call number in the EAX register
Store the arguments to the system call in the registers EBX< ECX

call the relevant interrupt 80h
the result is usually returnedd in the EAX register

There are six registers that store the arguments of the system call used, they are EBX, ECX< EDX, ESI, EDi, EBP. these registers take the consecutive arguments starting with the EBX register. IF there are more than six arguments then the memory location of the first argument is stored in the EBX register



the following code shows the use of system call sys_write

mov edx, 4    ;message length
mov ecx, msg  ;message to write
mov ebx, 1    ; file descriptor stdout
mov eax, 4    ; system call number sys_write
int 0x80      ; call kernel



sys_exit - eax -1  ebx -int
sys_fork - eax -2  ebx -struct pt_regs
sys_read - eax -3  ebx -unsigned int - ecx - char* - edx - size_t
sys_write - eax - 4  ebx -unsigned int - ecx - const char* - edx - size_t
sys_open - eax - 5 - ebx - const char* - ecx - int - edx - int
sys_close - eax - 6 - ebx - unsigned int