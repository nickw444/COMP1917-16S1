
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main (int argc, const char* argv []) {
	// char * my_string = "Hello\0 World";
 	char my_string[4];
 	my_string[0] = 'H';
 	my_string[1] = 'E';
 	my_string[2] = 'L';
 	my_string[3] = 'O';

	// printf("%d\n", my_string[11]);
	printf("%s\n", my_string);
}