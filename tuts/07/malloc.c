#include <stdlib.h>
#include <stdio.h>

char * makeMyString(void);

int main(int argc, char const *argv[])
{
	char * myString = makeMyString();
	printf("%s\n", myString);
	free(myString);
	return 0;
}

char * makeMyString(void) {
	char * str = malloc(sizeof(char) * 10);
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	str[3] = 'd';
	str[4] = 'e';
	str[5] = 'f';
	str[6] = 0;

	return str;
}