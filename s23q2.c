
#include <stdio.h>
#include <sys/stat.h>

int main()
{
    char filename[100];
    struct stat file;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (lstat(filename, &file) == 0)
    {
        if (S_ISDIR(file.st_mode))
            printf("File Type: Directory\n");

        else if (S_ISCHR(file.st_mode))
            printf("File Type: Character Device\n");

        else if (S_ISBLK(file.st_mode))
            printf("File Type: Block Device\n");

        else if (S_ISREG(file.st_mode))
            printf("File Type: Regular File\n");

        else if (S_ISFIFO(file.st_mode))
            printf("File Type: FIFO or Pipe\n");

        else if (S_ISLNK(file.st_mode))
            printf("File Type: Symbolic Link\n");

        else if (S_ISSOCK(file.st_mode))
            printf("File Type: Socket\n");

        else
            printf("Unknown File Type\n");
    }
    else
    {
        printf("File not found\n");
    }

    return 0;
}

