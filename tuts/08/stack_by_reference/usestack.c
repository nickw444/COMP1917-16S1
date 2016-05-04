#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Stack myStack = newStack();
	// Remember this is passed by copy, not reference
	push(myStack, 1);
	printf("myStack Size is: %d\n", getSize(myStack));
	
	
	// Access some internals:
	// printf("Stack Size is: %d\n", myStack->size);
	printf("Stack Size is: %d\n", getSize(myStack));
	
	return 0;
}