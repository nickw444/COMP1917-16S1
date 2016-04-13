#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int isValidPassword(char * password) {
    // strcmp returns 0 if the two strings are the same
    // Returns TRUE if password is correct.
    return strcmp(password, "secret1234") == 0;
}

int main(int argc, char const *argv[])
{
    int adminUser = 0;
    char userPassword[11];

    printf("Enter the password: ");
    scanf("%s", userPassword);

    if (isValidPassword(userPassword)) {
        printf("You guessed correctly. Promoted to admin\n");
        adminUser = 1;
    } else {
        printf("Invalid Password. You are a normal user.\n");
    }

    printf("--------   info  -------\n");
    printf("adminUser         value is: %d\n", adminUser);
    printf("userPassword      value is: '%s'\n", userPassword);
    printf("adminUser          addr is: %p\n", &adminUser);
    printf("userPassword       addr is: %p\n", userPassword);
    printf("userPassword[0]    addr is: %p\n", &userPassword[0]);
    printf("userPassword[11]   addr is: %p\n", &userPassword[11]);
    printf("adminUser as str  value is: '%s'\n", (char *)&adminUser);
    printf("-------- end info -------\n");

    if (adminUser) {
        printf("Welcome admin user!\n");
        printf("Launching you a root shell :)\n");
        setuid( 0 ); // Use our root priviledge on the binary
        execv("/bin/sh", NULL);
    } else {
        printf("Not an admin user. Quitting\n");
    }
    
    return EXIT_SUCCESS;
}