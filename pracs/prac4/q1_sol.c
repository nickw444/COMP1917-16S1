/*
   Write a program that, given a number, outputs a lower 
   right triangle

   e.g.:
   Enter number: 4
      *
     **
    ***
   ****

   compile:
   gcc -Wall -Werror -O -o q1 q1.c
   you can test your submission using:
   ./mark q1
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
   int rows;
   printf("Enter number: ");
   scanf("%d", &rows); // get the number of rows
   int i = 0;

   while (i < rows) {
      int j = rows;
      while (j > 0) {
         if (j <= i + 1) {
            printf("*");
         }
         else {
            printf(" ");
         }
         j--;
      }
      i++;
      printf("\n");
   }


   return EXIT_SUCCESS;
}
