int main(int argc, char const *argv[])
{
    printBetterFoo();
    return 0;
}


void printFoo(int n) {
    if (n == 1) {
        printf("foo\n");
    } else if (n == 2) {
        printf("foo foo\n");
    }
    // ...

}