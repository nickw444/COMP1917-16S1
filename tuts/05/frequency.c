#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


int main (int argc, const char* argv []) {
    char input;
    input = getchar();
    int counter;
    // Initialise all the counters.
    int lettercounter, upperCounter, lowerCounter, lfCounter, spaceCounter, vowelCounter;
    lettercounter = upperCounter = lowerCounter = lfCounter = spaceCounter = vowelCounter = 0;
    counter = 1;

    int analysis [26];

    int i = 0;
    while (i < 26) {
        // Initialise an array where we can store the frequency of
        // each letter occuring
        analysis[i] = 0;
        i++;
    }

    // Loop through each charachter we get from the input
    while (input != EOF) {

        // Do stuff for letters before a and z.
        if (input >= 'a' && input <= 'z') {
            // Convert the letter to an uppercase letter
            input = input - 32;
            // Count this lowercase letter
            lowerCounter++;
        } else if(input == '\n') {
            // Count a new line
            lfCounter++;
        } else if (input == ' ') {
            // Count a space
            spaceCounter++;
        }
        // Count this as being a vowel.
        // Also counts lowercase before we converted lowercase 
        // letters to uppercase.
        if (input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U') {
            vowelCounter++;
        }

        // Subtract 65, such that the letter A (65) goes to 0 (so that we can
        // count it in our letter frequency array)
        input = input - 65;
        // Protect against a buffer overflow (it was a letter out of the alphabet A-Z range)
        if(input >= 0 && input <= 25) {
            // Cast to use the input as an array index
            int inputIndex = (int) input;
            // Increase the counter for total amount of letters
            lettercounter ++;
            // Increment this position in the array
            analysis[inputIndex]++;
        }
        // Calculate the amount of upper case letters
        upperCounter = lettercounter - lowerCounter;
        // Get the next character. 
        input = getchar();
        counter++;

    }

    // Print the results
    printf("########################################\n");
    printf ("%d Characters were inputted\n", counter);
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
            printf ("%c: %f | %d occurrences\n",i+65,analysis[i]/(float)lettercounter * 100, analysis[i]);
            i++;

        }
    }

    return EXIT_SUCCESS;
}

