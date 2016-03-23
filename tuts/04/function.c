#include <stdio.h>
#include <stdlib.h>

void greetings(int number);

int main(int argc, char const *argv[]){
    int n = 0;

    while (n <= 10) {
        greetings(n);
        n++;
    }
    return EXIT_SUCCESS;
}

void greetings(int number){
    printf("Hello %d!\n", number);
}

