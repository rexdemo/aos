
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat file_info[argc];
    int i, j;
    char *temp;
    struct stat temp_info;

    if (argc < 2)
    {
        printf("Please enter file names\n");
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &file_info[i]) != 0)
        {
            printf("Unable to get file information: %s\n", argv[i]);
            return 1;
        }
    }

    for (i = 1; i < argc - 1; i++)
    {
        for (j = i + 1; j < argc; j++)
        {
            if (file_info[i].st_size > file_info[j].st_size)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;

                temp_info = file_info[i];
                file_info[i] = file_info[j];
                file_info[j] = temp_info;
            }
        }
    }

    printf("\nFiles in ascending order of size:\n");

    for (i = 1; i < argc; i++)
    {
        printf("%s - %ld bytes\n",
               argv[i], (long)file_info[i].st_size);
    }

    return 0;
}

