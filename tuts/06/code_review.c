#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


int main (int argc, const char* argv []) {
    char input;
    input = getchar();
    int counter = 1; 
    int lettercounter = 0;
    int upperCounter  = 0;
    int lowerCounter = 0;
    int lfCounter = 0;
    int spaceCounter = 0;
    int vowelCounter = 0;


    int analysis [26];

    int i = 0;
    while (i < 26) {
        analysis[i] = 0;
        i++;
    }

    while (input != EOF) {
        // printf ("%c \n", input);
        if (input >= 'a' && input <= 'z') {
            input = input - 32;
            lowerCounter++;
        }
        if(input == '\n') {
            lfCounter++;
        }
        if (input == ' ') {
            spaceCounter++;
        }
        if (input == 'A' || input == 'E' || input == 'I' || 
            input == 'O' || input == 'U') {
            vowelCounter++;
        }
        input = input - 'A';
        if(input >= 0 && input <= 25) {
            int inputIndex = (int)input;
            lettercounter ++;
            analysis[inputIndex]++;
        }
        upperCounter = lettercounter - lowerCounter;
        input = getchar();
        counter++;

    }

    printf("########################################\n");
    printf("%d Characters were inputted\n", counter);
    printf("%d Letters were inputted\n", lettercounter);
    printf("%d Were lowercase & %d were uppercase\n", lowerCounter, upperCounter);
    printf("%d Linefeeds were inputted\n", lfCounter);
    printf("%d Spaces were inputted\n", spaceCounter);
    printf("%d Vowels were inputted\n", vowelCounter);
    printf("%f Vowels were inputted\n", vowelCounter/(float)lettercounter);
    printf("########################################\n");
    
    i = 0;
    if (lettercounter > 0) {
        while (i < 26) {
            float percentage = analysis[i]/(float)lettercounter * 100;
            printf ("%c: %f | %d occurrences\n",i+65, percentage, analysis[i]);
            i++;

        }
    }

    return EXIT_SUCCESS;
}

