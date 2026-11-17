
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

    if(stat(argv[1], &file_info) == -1)
    {
        perror("stat");
        return 1;
    }

    printf("File Name : %s\n", argv[1]);

    printf("Inode Number : %ld\n", (long)file_info.st_ino);

    if(S_ISREG(file_info.st_mode))
    {
        printf("File Type : Regular File\n");
    }
    else if(S_ISDIR(file_info.st_mode))
    {
        printf("File Type : Directory\n");
    }
    else if(S_ISLNK(file_info.st_mode))
    {
        printf("File Type : Symbolic Link\n");
    }
    else
    {
        printf("File Type : Other\n");
    }

    return 0;
}

