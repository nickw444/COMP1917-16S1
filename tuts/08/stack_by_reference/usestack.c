#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
	Stack myStack = newStack();
	printf("Stack is at %p\n", myStack);
	push(myStack, 1);
	
	printf("myStack Size is: %d\n", getSize(myStack));
	
	printf("Stack is at %p\n", myStack);
	// Access some internals:
	// printf("Stack Size is: %d\n", myStack->size);
	printf("Stack Size is: %d\n", getSize(myStack));

	// printf("Size is %d", myStack->size);
	
	return 0;
}