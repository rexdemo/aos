
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    struct stat file_info;

    if(argc != 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    if(lstat(argv[1], &file_info) == -1)
    {
        perror("lstat");
        return 1;
    }

    if(S_ISDIR(file_info.st_mode))
    {
        printf("File Type: Directory\n");
    }
    else if(S_ISCHR(file_info.st_mode))
    {
        printf("File Type: Character Device\n");
    }
    else if(S_ISBLK(file_info.st_mode))
    {
        printf("File Type: Block Device\n");
    }
    else if(S_ISREG(file_info.st_mode))
    {
        printf("File Type: Regular File\n");
    }
    else if(S_ISFIFO(file_info.st_mode))
    {
        printf("File Type: FIFO or Pipe\n");
    }
    else if(S_ISLNK(file_info.st_mode))
    {
        printf("File Type: Symbolic Link\n");
    }
    else if(S_ISSOCK(file_info.st_mode))
    {
        printf("File Type: Socket\n");
    }
    else
    {
        printf("File Type: Unknown\n");
    }

    return 0;
}

