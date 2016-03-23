// Ainsley Sydun
// Date: 10 MAR 16
// Expansion of the Leap Year Checking Tool

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define GREG_CAL_START_YEAR 1582
#define TRUE 1
#define FALSE 0

//void testFunction();
int isLeapYear(int year);

int main(int argc, char * argv[]) {   
    //testFunction();
    
    int yearInput;
    //printf("Please enter the year you wish to test: ");
    scanf("%d %d %d", &yearInput, &yearInput2, &yearInput3);
    
    int functReturn = isLeapYear(yearInput);
    
    if (functReturn == 0) {
        printf("%d is not a leap year!\n", yearInput);
    } else if (functReturn == 1) {
        printf("%d is a leap year!\n", yearInput);
    }
    
    return EXIT_SUCCESS;
}

int isLeapYear(int year) {  
    int leapYearResult;
    
    assert(year >= GREG_CAL_START_YEAR);
    if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) {
        leapYearResult = TRUE;
    } else {
        leapYearResult = FALSE;
    }   
    
    return leapYearResult;
}
/*
void testFunction() {
    printf("Beginning test.\n");
    assert(isLeapYear(4000) == 1);
    assert(isLeapYear(4004) == 1);
    assert(isLeapYear(1999) == 0);
    assert(isLeapYear(1900) == 0);
    assert(isLeapYear(2000) == 1);
    assert(isLeapYear(1904) == 1);
    assert(isLeapYear(2100) == 0);
    printf("Tests complete.\n");
}
*/