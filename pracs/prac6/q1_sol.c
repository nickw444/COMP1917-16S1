/*
    This program is meant to find the largest number in a linked list

    You cannot use any other libraries.
    Compile using: gcc -Wall -Werror -O -o q1 q1.c
    Mark using: ./q1
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100


typedef struct _node {
    int value;
    struct _node * next;
} node;

typedef struct _linkedList {
    node * head;
} linkedList;


int largestNode(linkedList * list) {
    // Fix this function!
    // You can assume you will always be given at least 1 node.
     // -1
   int max = 0;
   node * curr = list->head;
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

    node * head = NULL;

    while (in != EOF) {
        if (in == '\n') {
            buffer[i] = 0;
            i = 0;

            int val = atoi(buffer);
            // Insert into the front of the linked list
            node * oldHead = head;
            head = malloc(sizeof(node));
            assert(head != NULL);
            head->value = val;
            head->next = oldHead;
        }
        else {
            buffer[i] = in;
            i++;
        }
        in = getchar();
    }
    linkedList * list = malloc(sizeof(linkedList));
    assert(list != NULL);

    list->head = head;

    int largest = largestNode(list);
    printf("Largest: %d\n", largest);

    return EXIT_SUCCESS;
}
