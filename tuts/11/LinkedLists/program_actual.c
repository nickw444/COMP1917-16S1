#include <stdlib.h>
#include <stdio.h>

typedef struct _node {
    int value; // Store our value.
    struct _node * next; // Store a link to the next node
} node;

typedef struct _list  {
    struct _node * head;
} list;

void printList(list * l);
void deleteNode(list * l, int value);
void freeList(list * l);
int minInList(list * l);

int main(int argc, char const *argv[])
{
    int numbers[9] = {10, 5, 3,5,4,5,6,7,8};
    node * prev = NULL;
    int i = 0;
    while (i < 9) {
        node * curr = (node *)malloc(sizeof(node));
        curr->next = prev;
        curr->value = numbers[i];
        i ++;
        prev = curr;
    }

    list * myList = (list *)malloc(sizeof(list));
    myList->head = prev;

    // CLASS CODE BELOW
    printList(myList);
    deleteNode(myList, 4747);
    printList(myList);

    printf("Min is: %d\n", minInList(myList));

    // freeList(myList);

    // list * myEmptyList = (list *)malloc(sizeof(list));
    // myEmptyList->head = NULL;
    // // printf("Head Node points to %p\n", myEmptyList);
    // printList(myEmptyList);
    // freeList(myEmptyList);
    // deleteNode(myEmptyList, 10);



    return 0;
}


void printList(list * l) {
    node * curr = l->head;
    while (curr != NULL) {
        printf("[%d] -> ", curr->value);
        curr = curr->next;
    }
    printf("X\n");
}
void deleteNode(list * l, int value) {
    node * curr = l->head;
    node * prev = NULL;

    while (curr != NULL && curr->value != value) {
        prev = curr;
        curr = curr->next;
    }
    if (curr != NULL) {
        if (prev == NULL) {
            l->head = curr->next;
        } else {
            prev->next = curr->next;
        }
        free(curr);
    }
}
void freeList(list * l) {
    node * curr = l->head;
    while (curr != NULL) {
        node * next = curr->next;
        printf("Freeing %d\n", curr->value);
        free(curr);
        curr = next;
    }
    free(l);
}
void appendList(list * l, int value);
void pushList(list * l, int value);


int minInList(list * l) {
    node * curr = l->head;
    int min = curr->value;

    while (curr != NULL) {
        if (curr -> value < min) {
            min = curr->value;
        } 
        curr = curr->next;
    }
    return min;
}


