#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value; // Store our value.
    node * next; // Store a link to the next node
} _node;

void printNodes(node * n);
void printNodes2(node * head);

int main(int argc, char const *argv[])
{

    node * head = (node *)malloc(sizeof(node));
    // Point next to null since it is the only node.
    head->next = NULL;

    // Set the value of the first node.
    head->value = 33;
    // Same as:
    (*head).value = 33;

    // [ 33 ] -> NULL


    // Add a new node.
    node * newNode = (node *)malloc(sizeof(node));
    // Set its value:

    newNode->next = NULL;
    newNode->value = 42;
    // [ 42 ] -> NULL;

    // head->next = newNode

    // Add it to the linked list.
    head->next = newNode;
    newNode->next = head;
    // [33] -> [42] -> X

    // Print from the start. [33] -> [42] -> X
    printNodes2(head);
    // Print from new Node: [42] -> X
    // printNodes2(newNode);

    free(head);


    free(newNode);

    return 0;


}

// [33] -> 
void printNodes2(node * head) {
    node * curr = head;
    while (curr != NULL) {
        free(curr);
        
        curr = curr->next;
    }
    printf("X\n");

    // printf("%d\n", head->value);
    // printf("%d\n", head->next->value);
    // printf("%d\n", node2->value);
}










void printNodes(node * n) {
    node * curr = n;
    while (curr != NULL) {
        // While the current node is not pointing at null.
        printf("[%d] -> ", curr->value);
        curr = curr->next;
    }

    printf("X\n");
}