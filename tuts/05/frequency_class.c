#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, const char* argv []) {
    // char input;

    int upper, vowels, total_chars, spaces, newlines;
    upper = vowels = total_chars = spaces = newlines = 0;
    // 65-90 is upper
    // 97-122 is lower

    int lettercount[26];
    int i = 0;
    while(i < 26) {
    	lettercount[i] = 0 ;
    	i ++;
    }
    printf("%d\n", i);
    printf("%d\n", lettercount[i + 200]);


    // input = getchar();
    // while (input != EOF) {
    //     // printf("%c\n", input);

    //     if (input <= 'Z' && input >= 'A') {
    //     	upper ++;
    //     } else if (input == '\n') {

    //     }

    //     input = getchar();
    // }

    // printf("Uppercase letters %d\n", upper);

    return EXIT_SUCCESS;
}