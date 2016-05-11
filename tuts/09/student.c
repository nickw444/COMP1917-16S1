#include <stdlib.h>
#include <stdio.h>


typedef struct _student
{
	char * name;
	// Or we could store their name in the struct
	// char stored_name[20];
	int age;
} student;

int main(int argc, char const *argv[])
{
	student myStudent;
	myStudent.name = malloc(20*sizeof(char));
	myStudent.name[0] = 'N';
	myStudent.name[1] = 'i';
	myStudent.name[2] = 'c';
	myStudent.name[3] = 'k';
	myStudent.name[4] = 0;

	myStudent.age = 21;
	printf("We have a student with the name pointer: %s \n", myStudent.name);
	// printf("Name is: %s \n", myStudent.stored_name);
	printf("And Age:: %d \n", myStudent.age);
}


