
#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    struct stat file;
    int i;

    if (argc < 2)
    {
        printf("Please provide file names\n");
        return 1;
    }

    for (i = 1; i < argc; i++)
    {
        if (stat(argv[i], &file) == 0)
        {
            printf("\nFile Name: %s\n", argv[i]);
            printf("Inode Number: %ld\n", (long)file.st_ino);

            if (S_ISREG(file.st_mode))
                printf("File Type: Regular File\n");

            else if (S_ISDIR(file.st_mode))
                printf("File Type: Directory\n");

            else if (S_ISLNK(file.st_mode))
                printf("File Type: Symbolic Link\n");

            else
                printf("File Type: Other File Type\n");
        }
        else
        {
            printf("%s not found\n", argv[i]);
        }
    }

    return 0;
}

