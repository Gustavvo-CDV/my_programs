#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int  i, numberArray[10];

    FILE *open_file;

    if(argc !=2 || strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s file_destination file origin\n", argv[0]);
        return 1;

    }

    open_file = fopen(argv[1], "r");
    if (open_file == NULL)
    {
        printf("%s doesn't exist.", argv[1]);
        exit(1);
    }

    for (i = 0; i < 10; i++)
    {
        fscanf(open_file, "%d", &numberArray[i]);
    }

    int counter = 1;

    for (i = 0; i < 10; i++)
    {
        printf("%i. %i * 3= %d\n", counter,numberArray[i], numberArray[i] * 3);
        counter ++;
    }

    fclose(open_file);
    exit(0);
    }