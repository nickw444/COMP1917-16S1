#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Stack.h"


typedef struct _stack {
    // Implement Me
} stack;

int top (Stack s){
    // Implement Me
}

void pop (Stack s) {
    // Implement Me
}

void push (Stack s, int value) {
    // Implement Me
}

Stack newStack (void) {
    //allocate memory on heap to store the stack
}

Stack newStackBroken1 (void) {
    stack s;
    return &s;
}

Stack newStackBroken2 (void) {
    Stack s = malloc(sizeof(Stack))
    return s;
}

//free the memory allocated on heap for the stack
void freeStack (Stack s){
    // Implement Me
}

int getSize (Stack s) {
    // Implement Me
}

int getMaxSize (Stack s){
    // Implement Me
}




