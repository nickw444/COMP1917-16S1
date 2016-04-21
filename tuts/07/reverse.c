#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char *reverse (char *message);

int main(int argc, char const *argv[])
{
    char * string = "Hello There";
    char * newString = reverse(string);
    printf("String is: %s\n", newString);

    free(newString);

    return EXIT_SUCCESS;
}

char *reverse (char *message) {
    int i = 0;
    int bufLength = strlen(message) + 1;
    char * newString = malloc(sizeof(char) * (bufLength));

    newString[bufLength - 1] = 0;
    int j = bufLength - 2;

    while (i < (bufLength -1)) {
        newString[j] = message[i];
        i ++;
        j --;
    }
    return newString;
}