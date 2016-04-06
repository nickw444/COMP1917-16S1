#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, const char* argv []) {
    char input;
    input = getchar();
    while (input != EOF) {
        printf("%c\n", input);
        input = getchar();
    }

}