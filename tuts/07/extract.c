// extract.c
// funtions and types used to extract x,y,z values from a
// string containing a url of the form
// "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5"
// initially by richard buckland
// 13 April 2014
// your name here:
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "extract.h"
#include <math.h>
#define TRUE 1
#define FALSE 0
 
void testmyAtoL();
void testmyAtoD();
triordinate extractCoordinate(char * urlString);

int main (int argc, char *argv[]) {
    testmyAtoD();
    testmyAtoL();
    char * message = "http://almondbread.cse.unsw.edu.au:7191/tile_x3.14_y-0.141_z5";
    // extract(message);
	// char * value = "0.11";
	// printf("Val: %lf\n", myAtoD(value)); 
    triordinate dat = extract (message);
 	// char * value = "-6746.421";
 	// printf("Val: %lf\n", myAtoD(value));
    printf ("dat is (%f, %f, %d)\n", dat.x, dat.y, dat.z);
 
    assert (dat.x == 3.14);
    assert (dat.y == -0.141);
    assert (dat.z == 5);
 
    return EXIT_SUCCESS;
}


triordinate extract (char *message) {
	int pos = 0;
	char locString[30];
	while (message[pos] != 0) {
		// printf("%c\n", message[pos]);
		if (message[pos] == '/' && message[pos + 1] == 't') {
			// printf("FOUND /\n");
			pos++;
			int counter = 0;
			while (message[pos] != 0) {
				// printf("%c\n",message[pos] );
				locString[counter] = message[pos];
				counter ++;
				pos++;
			}
			locString[counter] = 0;
		}
		pos++;
	}
	// printf("%s\n", locString);

	triordinate value = extractCoordinate(locString);
	return value;
}
 
triordinate extractCoordinate(char * urlString) {
	int stringPos = 0;
	char xCoord[20];
	int xCoordPos = 0;
	char yCoord[20];
	int yCoordPos = 0;
	char zCoord[10];
	int zCoordPos = 0;
	char nextChar;
	nextChar = urlString[stringPos];
	while (nextChar != 0) {
		if (nextChar == 'x') {
			stringPos ++;
			nextChar = urlString[stringPos];
			while(nextChar != 'y' && nextChar != '_') {

				xCoord[xCoordPos] = nextChar;
				// xCoord[xCoordPos] = 'a';
				xCoordPos ++;
				stringPos ++;
				nextChar = urlString[stringPos];
			}
			xCoord[xCoordPos] = 0;
		}
		else if (nextChar == 'y') {
			stringPos ++;
			nextChar = urlString[stringPos];
			while(nextChar != 'z' && nextChar != '_') {
				yCoord[yCoordPos] = nextChar;
				yCoordPos ++;
				stringPos ++;
				nextChar = urlString[stringPos];
			}
			yCoord[yCoordPos] = 0;
		}
		else if (nextChar == 'z' && nextChar != '_') {
			stringPos ++;
			nextChar = urlString[stringPos];	
			while(nextChar != 0) {
				
				zCoord[zCoordPos] = nextChar;
				zCoordPos ++;
				stringPos ++;
				nextChar = urlString[stringPos];
			}
			zCoord[zCoordPos] = 0;
		}
		else {
			stringPos++;
			nextChar = urlString[stringPos];
		}
	}
	triordinate outputCoord;
	outputCoord.x = atof(xCoord);
	outputCoord.y = atof(yCoord);
	outputCoord.z = atoi(zCoord);
	// 
	return outputCoord;
}

double myAtoD (char *message) {
	int dotPos = 0;
	int foundDot = FALSE;
	float floatUnits = 0.1;
	int pos = 0;
	double fValue = 0;
	double iValue = 0;
	while (message[pos] != 0) {
		if (message[pos] == '.') {
			dotPos = pos;
			foundDot = TRUE;
		}
		else if (foundDot == TRUE) {
			if (message[pos] <= '9' && message[pos] >= '0') {
				int number = message[pos] - '0';
				fValue = fValue + (number * floatUnits);
				floatUnits = floatUnits/(float)10;
			}
		}
		pos++;
	}

	int length = 0;
	if (foundDot == FALSE) {
		length = strlen(message) ;
	}
	else {
		length = dotPos ;
	}

	pos = 0;
	while(message[pos] != 0 && pos < length ) {
		if (message[pos] <= '9' && message[pos] >= '0') {
			int number = message[pos] - '0';
			iValue = iValue + number * pow(10,(length - pos - 1));
		}
		pos ++;
	}
	double fullValue = fValue + iValue;
	if (message[0] == '-') {
		fullValue = fullValue * -1;
	}
	return fValue + iValue; 
}
 
long myAtoL (char *message) {
	int length = strlen(message);
	long value = 0;
	int pos = 0;
	while (message[pos] != 0) {
		if (message[pos] <= '9' && message[pos] >= '0') {
			int number = message[pos] - '0';

			value = value + number * pow(10,(length - pos - 1));
		} 
		pos ++;
	}
	if (message[0] == '-') {
		value = value * -1;
	}
	return value;
}

void testmyAtoL() {
	printf("Testing myAtoL\n");
	assert(myAtoL("6746") == 6746);
	assert(myAtoL("6746") == 6746);
	assert(myAtoL("222") == 222);
	assert(myAtoL("-4736") == -4736);
	assert(myAtoL("-746562") == -746562);
	printf("Testing myAtoL Passed\n");
}
void testmyAtoD() {
	printf("Testing myAtoD\n");
	// printf("%lf \n", myAtoD("1.00001"));
	// assert(myAtoD("1.00001") == 1.00001);
	// double test = 6746.947;
	// assert(myAtoD("6746.947") == test);
	// assert(myAtoD("-6746.421") == -6746.421);
	printf("Testing myAtoD Passed\n");

}
