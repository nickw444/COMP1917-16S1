#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char * y = "Hello!";

    printf("%s\n", y);


    /* bonus:
    Can i do the following two lines?
    Is this valid?
    If not, what error will I get, and when?
    
    y[0] = 'b';
    printf("%s\n", y);

    */

    return EXIT_SUCCESS;
}


/*
This compiles to this using `otool -tvV a.out`:


(__TEXT,__text) section
_main:
0000000100000f20    pushq   %rbp
0000000100000f21    movq    %rsp, %rbp
0000000100000f24    subq    $0x20, %rsp
0000000100000f28    leaq    0x5e(%rip), %rax        ## literal pool for: "%s\n"
0000000100000f2f    leaq    0x50(%rip), %rcx        ## literal pool for: "Hello!"
0000000100000f36    movl    $0x0, -0x4(%rbp)
0000000100000f3d    movl    %edi, -0x8(%rbp)
0000000100000f40    movq    %rsi, -0x10(%rbp)
0000000100000f44    movq    %rcx, -0x18(%rbp)
0000000100000f48    movq    -0x18(%rbp), %rsi
0000000100000f4c    movq    %rax, %rdi
0000000100000f4f    movb    $0x0, %al
0000000100000f51    callq   0x100000f64             ## symbol stub for: _printf
0000000100000f56    xorl    %edx, %edx
0000000100000f58    movl    %eax, -0x1c(%rbp)
0000000100000f5b    movl    %edx, %eax
0000000100000f5d    addq    $0x20, %rsp
0000000100000f61    popq    %rbp
0000000100000f62    retq

Pay attention to these two lines:
0000000100000f28    leaq    0x5e(%rip), %rax        ## literal pool for: "%s\n"

0000000100000f2f    leaq    0x50(%rip), %rcx        ## literal pool for: "Hello!"

See how those are the two strings we defined in our code -> they are stored in a special place.

*/