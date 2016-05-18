#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value; // Store our value.
    node * next; // Store a link to the next node
} _node;

typedef struct list {
    node * head;
} _list;


void printNodes(node * n);
void printNodes2(node * head);