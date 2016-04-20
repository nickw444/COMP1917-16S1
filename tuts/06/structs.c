#include "stdlib.h"
#include "stdio.h"

typedef struct _color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} color;


int main(int argc, char const *argv[])
{
    color my_struct1 = {255,20,30};
    
    printf("%u\n", my_struct1.red);
    printf("%u\n", my_struct1.green);
    printf("%u\n", my_struct1.blue);

    color * my_struct_pointer = &my_struct1;
    // color my_struct_dereference = *my_struct_pointer;

    printf("%d\n", (*my_struct_pointer).red);
    printf("%d\n", my_struct_pointer->red);
    // printf("%d\n", my_struct_dereference.red);
    

    return 0;
}