
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;

    if (argc < 2)
    {
        printf("Please enter file names as command line arguments\n");
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        if (access(argv[i], F_OK) == 0)
        {
            printf("%s is present in current directory\n", argv[i]);
        }
        else
        {
            printf("%s is not present in current directory\n", argv[i]);
        }
    }

    return 0;
}

