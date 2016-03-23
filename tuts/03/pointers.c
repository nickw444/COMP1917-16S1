#include <stdlib.h>
#include <stdio.h>
void myWriteToVar(int *varToWrite);

int main(int argc, char const *argv[])
{
    int myVar = 9000;

    printf("MyVar is at %p\n", &myVar);
    printf("MyVar is equal to %d\n", myVar);

    myWriteToVar("lelelelele");

    return 0;
}

void myWriteToVar(int *varToWrite) {
    printf("++ varToWrite is %d\n", *varToWrite);
    printf("++ varToWrite is at %p\n", varToWrite);
    int ** junk = &varToWrite;
    printf("++ varToWrite container address is at %p\n", *junk);

}