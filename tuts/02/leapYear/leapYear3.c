#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define YEAR_MIN 1582

int isLeapYear( int year );

int main( int argc, char *argv[] ) {
    int year;
    printf("please enter the year (after 1582)?\n");
    scanf("%d", &year);
    printf("%d ", year);
    if( isLeapYear(year) ) {
        printf("is a leap year!\n");
    } else {
        printf("is not a leap year!\n");
    }
return EXIT_SUCCESS;
}

int isLeapYear( int year ) {
assert( year >= YEAR_MIN );
return ( year%4 == 0 && !( year%100 == 0) ) || ( year%400 == 0 );
}