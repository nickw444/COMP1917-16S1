/*
    This program is meant to find the largest number in a linked list

    You cannot use any other libraries.
    Compile using: gcc -Wall -Werror -O -o q1 q1.c
    Mark using: ./mark q1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100

typedef struct _node *link;
typedef struct _node {
    int value;
    link next;
} node;


typedef struct _list {
    link head;
} *list;

int largestNode(list l) {
    // Fix this function!
    // You can assume you will always be given at least 1 node.
    // This is very similar to the last prac we did.
    // Notable the only thing that changed is the list struct representation
    // It is the same representation you were given during the practise prac.
    int max = 0;
    node * curr = l->head;
    while (curr != NULL) {
        if (curr->value > max) {
            max = curr->value;
        }
        curr = curr->next;
    }      
    return max;
}

int main(int argc, char *argv[]) {
    // Main function is fine.
    // Don't change this.

    char buffer[100];
    int i = 0;
    char in = getchar();

    list l = malloc(sizeof(list));
    l->head = NULL;

    while (in != EOF) {
        if (in == '\n') {
            buffer[i] = 0;
            i = 0;

            int val = atoi(buffer);
            // Insert into the front of the linked list
            node * oldHead = l->head;
            l->head = malloc(sizeof(node));
            assert(l->head != NULL);
            l->head->value = val;
            l->head->next = oldHead;
        }
        else {
            buffer[i] = in;
            i++;
        }
        in = getchar();
    }

    int largest = largestNode(l);
    printf("Largest: %d\n", largest);

    return EXIT_SUCCESS;
}


