#include <stdio.h>
#include <stdlib.h>
void swap(int *first, int *second);
int main(int argc, char const *argv[])
{
    int a = 5;
    int b = 7;
    printf("A is: %d and B is: %d\n", a, b);
    swap(&a, &b);
    printf("A is: %d and B is: %d\n", a, b);
    return EXIT_SUCCESS;
}

void swap(int* first, int* second) {
    int tmp = *second;
    *second = *first;
    *first = tmp;
}