#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	stack myStack = newStack();
	stack myNewStack;
	// Remember this is passed by copy, not reference
	myNewStack = push(myStack, 1);
	printf("myNewStack Size is: %d\n", getSize(myNewStack));
	printf("myStack Size is: %d\n", getSize(myStack)); // Why?
	
	
	// Access some internals:
	printf("Stack Size is: %d\n", myStack.size);
	printf("Stack Size is: %d\n", getSize(myStack));
	
	return 0;
}