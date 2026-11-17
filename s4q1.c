
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    for(int i = 1; i < argc; i++)
    {
        if(access(argv[i], F_OK) == 0)
        {
            printf("%s : File is present\n", argv[i]);
        }
        else
        {
            printf("%s : File is not present\n", argv[i]);
        }
    }

    return 0;
}

