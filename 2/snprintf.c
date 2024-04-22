#include <stdio.h>

int main()
{
    char buffer[100];
    int n;
    n = snprintf(buffer, 100, "This is a string.");
    printf("Return value: %d\n", n);
    if (n >= 0 && n < 100) // check returned value
    {
        n = snprintf(buffer, 100, " This is another string.");
        printf("Second time return value: %d\n", n);
    }
    puts(buffer);
    return 0;
}