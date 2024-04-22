#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    int rtn;

    fp = fopen("2.txt", "w+");
    rtn = fprintf(fp, "%d %s", 1, "string");

    printf("Return value: %d\n", rtn);
    fclose(fp);

    return (0);
}