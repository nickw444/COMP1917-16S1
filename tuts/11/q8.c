#include <stdlib.h>
#include <stdio.h>

char aFunction(char x[2]) {

    printf("%p\n", x); // Notice how the location in memory is the same 
                       // as where it was declared.
    printf("%s\n", x); // Notice how the entire string is printed
    return x[3]; // notice how i can access the 3rd element. 
}

int main(int argc, char const *argv[])
{
    char myArr[5];
    myArr[0] = 'a';
    myArr[1] = 'b';
    myArr[2] = 'c';
    myArr[3] = 'd';
    myArr[4] = 0;

    printf("%p\n", myArr); // Address in memory (where it is declared)

    char res = aFunction(myArr);

    printf("%c\n", res);
}
