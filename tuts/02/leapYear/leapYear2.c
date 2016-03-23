int main (int argc, char * argv[]) {
    int THEYEAR;
    printf ("Please enter the year you are interested in \n");
    scanf ("%d", &THEYEAR);
    assert (THEYEAR > YEAR_MIN); 
    if (THEYEAR % 400 == 0) {
         printf ("%d is a leap year! \n", THEYEAR);
    } else if (THEYEAR %100 == 0) {
         printf ("%d is not a leap year! \n", THEYEAR);
    } else if (THEYEAR %4 == 0) {
       printf ("%d is a leap year! \n", THEYEAR);
    } else {
        printf ("%d is not a leap year! \n", THEYEAR); 
    }
return EXIT_SUCCESS;
} 
