#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_STUDENT_NAME 20

typedef struct _student
{
	// char name[MAX_STUDENT_NAME];
	char * name;
	int age;
	char * studentId;
} student;



int main(int argc, char const *argv[])
{
	student myStudent;
	myStudent.age = 21;
	char * inputName = "Nick";
	myStudent.name = malloc(sizeof(char) * strlen(inputName));
	
	strcpy(myStudent.name, inputName);
	
	myStudent.name[0] = 'K';

	printf("We have a student with the name pointer: %s \n", myStudent.name);
	// printf("Name is: %s \n", myStudent.stored_name);
	// printf("And Age:: %d \n", myStudent.age);
}


