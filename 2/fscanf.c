#include <stdio.h>

int main()
{
    char str[80];
    float f;
    FILE *pFile;

    pFile = fopen("2.txt", "r");
    if (fscanf(pFile, "%f %s", &f, str))
    {
        printf("%f %s \n", f, str);
    }
    else
    {
        printf("fscanf failed\n");
    }
    fclose(pFile);

    return 0;
}