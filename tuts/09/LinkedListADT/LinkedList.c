#include "LinkedList.h"
#include <stdlib.h>

typedef struct node {
    int value;
    struct node * next;
} node;

typedef struct _linkedList {
    node * head;
    // int num_nodes;
} linkedList;


LinkedList newLinkedList(void) {
    LinkedList list = (LinkedList)malloc(sizeof(linkedList));
    list->head = NULL;
    return list;
}
void addNode(LinkedList l, int newValue) {
    node * n = malloc(sizeof(node));
    n->next = l->head;
    l->head = n;
}
int getNumNodes(LinkedList l) {
    node * curr = l->head;
    int count = 0;
    while (curr != NULL) {
        count ++;
        curr = curr->next;
    }
    return count;
}

