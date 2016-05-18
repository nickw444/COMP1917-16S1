#include "LinkedList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node * next;
} node;

typedef struct _linkedList {
    node * head;
    int num_nodes;
} linkedList;


LinkedList newLinkedList(void) {
    LinkedList list = (LinkedList)malloc(sizeof(linkedList));
    list->head = NULL;
    list->num_nodes = 0;
    return list;
}
void addNode(LinkedList l, int newValue) {
    l->num_nodes += 1;
    node * n = malloc(sizeof(node));
    n->value = newValue;
    n->next = l->head;
    l->head = n;
}
int getNumNodes(LinkedList l) {
    return l->num_nodes;
}
int getSmallest(LinkedList l) {
    node * curr = l->head;
    int min = -1;
    if (curr != NULL) {
        min = curr->value;
        while (curr != NULL) {
            if (curr->value < min) {
                min = curr->value;
            }
            curr = curr->next;
        }
    }

    return min;
}

