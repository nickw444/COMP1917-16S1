#include <stdlib.h>
#include <stdio.h>

char * makeStringLocal();
char * makeStringInHeap();

int main(int argc, char const *argv[])
{
    // char * myString = makeStringLocal();   
    char * myString = makeStringInHeap();   
    printf("%p\n", myString); //print the address of myString.
    return EXIT_SUCCESS;
}

char * makeStringInHeap() {
    char * myString = malloc(20); // String with 20 chars
    myString[0] = 'a'; // Pretend there was some dynamic
    myString[1] = 'b'; // thing generating these
    myString[2] = 'c';
    myString[3] = 'd';
    myString[4] = 'e';
    myString[5] = 0; // don't forget to null terminate.
    printf("%p\n", myString);
    printf("%s\n", myString);
    return myString;

    // Using malloc means we can return a pointer to the 
    // string we created, since it was made in Heap space
    // and not in the local scope/frame.
}
/*
char * makeStringLocal() {
    // Lets not use malloc and see what happens...

    char myString[20]; // String with 20 chars.
    myString[0] = 'a'; // Pretend there was some dynamic
    myString[1] = 'b'; // thing generating these
    myString[2] = 'c';
    myString[3] = 'd';
    myString[4] = 'e';
    myString[5] = 0; // don't forget to null terminate.

    printf("%p\n", myString);
    printf("%s\n", myString);
    return myString;

    // We will get an error for this if we compile this:
    // address of stack memory associated with local variable 'myString' returned

    // This is because myString is declared in the stack.
    // Remember this function's frame in the stack isn't going to 
    // be around after we return, which is why we need to use malloc.

    // Keep in mind, if you only ever needed to use myString in the local
    // frame/scope (makeStringLocal), it is completely acceptable to use 
    // the above code. 

}
*/