#include "stdlib.h"
#include "stdio.h"

typedef struct _color {
    char red;
    char green;
    char blue;
} color;


int main(int argc, char const *argv[])
{
    color my_struct1 = {'a','b','c'};
    
    printf("%c\n", my_struct1.red);
    printf("%c\n", my_struct1.green);
    printf("%c\n", my_struct1.blue);

    color * my_struct_pointer = &my_struct1;
    color my_struct_dereference = *my_struct_pointer;

    printf("%c\n", my_struct_dereference.red);
    printf("%c\n", my_struct_pointer->red);

    return 0;
}