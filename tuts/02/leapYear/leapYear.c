//Nick Whyte
//10 March 2014
//This program is designed to determine if a year is a leap year based on the rules learnt in lecture 6

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#define START_OF_GREG_CALENDAR 1582

int main (int argc, char * argv[]){
    int year;
    printf ("please enter the year you are interested in\n");
    scanf ("%d", &year);
    assert (year >= START_OF_GREG_CALENDAR);
    if (year % 4 == 0){
        if (year % 100 == 0 ){
            if (year % 400 ==0) { 
                printf("is a leap year!\n");
            } else {
                printf ("is not a leap year!\n");
            } 
        } else {
            printf("is a leap year!\n");
        } 
    } else {
        printf("is not a leap year!\n");
    }
    return EXIT_SUCCESS;
}