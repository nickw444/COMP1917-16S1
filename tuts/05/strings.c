
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, const char* argv []) {
	// char * my_string = "Hello\0 World";
    // char * my_string = "Hello World!";
    // char * my_other_string = "Hello World!";
    char my_string[2];
    my_string[0] = 'H';
    my_string[1] = 0;

    char my_other_string[2];
    my_other_string[0] = 'O';
    my_other_string[1] = 0;


    printf("s1 %s %p\n", my_string, my_string);
    printf("s2 %s %p\n", my_other_string, my_other_string);

    int i = 0;
    int isEqual = 1;
    while(i < 2) {
        if (my_string[i] != my_other_string[i]) {
            isEqual = 0;
        }
        i ++;
    }

    printf("The strings are Equal: %d\n", isEqual);


    // if (my_string == my_other_string) {
    //     printf("Strings are equal, yay \n");
    // }
}