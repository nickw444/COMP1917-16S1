#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList myList = newLinkedList();
    // addNode(myList, 33);
    // printf("%d\n", getNumNodes(myList));
    // addNode(myList, 42);
    // printf("%d\n", getNumNodes(myList));
    // addNode(myList, 55);
    // printf("%d\n", getNumNodes(myList));
    // addNode(myList, 22);
    // printf("%d\n", getNumNodes(myList));
    // addNode(myList, 77);
    // printf("%d\n", getNumNodes(myList));
    // addNode(myList, 12);
    printf("List has %d nodes\n", getNumNodes(myList));

    printf("%d\n", getSmallest(myList));
}