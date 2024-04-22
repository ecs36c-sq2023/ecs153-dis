#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char str[80];
    int rtn;

    rtn = sprintf(str, "Value of Pi = %f", M_PI);
    puts(str);
    printf("Return value: %d\n", rtn);
    return (0);
}