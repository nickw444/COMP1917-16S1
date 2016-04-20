//By:          Nick Whyte
//Course:      COMP1917
//Date:        18 April
//Tutorial:    Wednesday Flute 3pm-6pm.
//Tutor:       Jackie
//Description: This function will reverse a string
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *reverse (char *message);


int main(int argc, char const *argv[])
{
	char * string = "Hello Theree";
	char * newString = reverse(string);
	printf("%s\n", newString);

	int i = 0;
	while(newString[i] != 0) {
		printf("%c\n", newString[i]);
		i++;
	}
	printf("%d\n", newString[i]);
		
	free(newString);

	return EXIT_SUCCESS;
}

char *reverse (char *message) {
	int memorySize = strlen(message) * sizeof(char);
	char *newString = malloc(memorySize);

	int messageLength = strlen(message);
	int counter = messageLength - 1;
	int index = 0;
	while(counter >= 0) {
		newString[index] = message[counter];
		index ++;
		counter --;
	}
	newString[index] = 0;
	return newString;
}