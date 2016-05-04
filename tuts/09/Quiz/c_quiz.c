#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{

    // int myVariable = 33;
    // int * myVariablePointer = &myVariable;    
    // // doSomething(&myVariablePointer);


    // printf("%p\n", *&myVariablePointer); // Line 1
    // printf("%p\n", myVariablePointer);   // Line 2 


    // printf("%d\n", (int)myVariablePointer);
    // printf("%d\n", *myVariablePointer);


    // printf("%d\n", *myVariablePointer);
    // printf("%d\n", *myVariablePointer);

    char * string1 = "CSESoc Is the Best";
    char * string2[] = {
        "CSE is sorta okay too",
        "CSE is sorta okay too 2",
        "CSE is sorta okay too 3",
    };

    printf("%s\n", string1);
    int i = 0;
    while ( i < 3) {
        printf("%s\n", string2[i]);
        i++;
    }

    return EXIT_SUCCESS;
}