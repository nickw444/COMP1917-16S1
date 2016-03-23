//Nick Whyte
//10 March 2016
//Our program tells us if it is a leap year or not

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define START_OF_GREG_CALENDAR 1582
#define TRUE 1
#define FALSE 0
int isLeapYear(int year);
void runLeapYearTests();

int main(int argc, char * argv[]) {
   runLeapYearTests();

   int year;
   printf("Please enter the year you are interested in:\n");
   scanf("%d", &year);

   assert (year >= START_OF_GREG_CALENDAR);

   int result = isLeapYear(year);
   if (result == TRUE) {
      printf("Yes, it is a leap year\n");
   } else {
      printf("No, it is not a leap year\n");
   }

   return EXIT_SUCCESS;
}

int isLeapYear(int year) {
   int leapYear;
   if (year % 400 == 0) {
      leapYear = TRUE;
   } else {
      if (year % 4 == 0) {
         if (year % 100 == 0) {
            leapYear = FALSE;
         } else {
            leapYear = TRUE;
         }
      } else {
         leapYear = FALSE;
      }
   }
   return leapYear;
}

void runLeapYearTests() {
   printf("Running tests!\n");
   assert(isLeapYear(2016) == TRUE);
   assert(isLeapYear(2015) == FALSE);
   assert(isLeapYear(2000) == TRUE);
   assert(isLeapYear(1999) == FALSE);
   assert(isLeapYear(1996) == TRUE);
   printf("All Tests Passed. You are awesome!\n");
}
