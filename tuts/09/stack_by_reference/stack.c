#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Stack.h"


typedef struct _stack {
  int contents[MAX_STACK];
  int maxSize;
  int size;
} stack;

int top (Stack s){
    assert (s!= NULL && getSize(s) > 0);
    return s->contents[s->size-1];
}

void pop (Stack s) {
    assert (s!= NULL && getSize(s) > 0);
    s->size--;
}

void push (Stack s, int value) {
    assert (s!= NULL && getSize(s) < getMaxSize(s));
    s->contents[s->size] = value;
    s->size++;
}

Stack newStack (void) {
    //allocate memory on heap to store the stack
    Stack s = malloc(sizeof(stack));
    assert(s != NULL);
    s->size = 0;
    s->maxSize = MAX_STACK;
    return s;
}

//free the memory allocated on heap for the stack
void freeStack (Stack s){
     assert(s != NULL);
     free(s);
}

int getSize (Stack s) {
    assert(s != NULL);
    return s->size;
}

int getMaxSize (Stack s){
    assert(s != NULL);
    return s->maxSize;
}




