#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

int main(int argc, char const *argv[])
{
    LinkedList myList = newLinkedList();
    addNode(myList, 33);
    printf("%d\n", getNumNodes(myList));
    addNode(myList, 42);
    printf("%d\n", getNumNodes(myList));
}