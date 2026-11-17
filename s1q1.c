#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        fprintf(stderr, "Usage: %s <file1> <file2>......<fileN>\n", argv[0]);
        return 0;
    }

    for(int i=1 ; i < argc ; i++)
    {
        const char *filename = argv[i];
        struct stat file_info;

        if(stat(filename , &file_info)==-1)
        {
            perror("stat");
            continue;
        }

        printf("File: %s\n",filename);
        printf("Inode Number : %ld\n",(long)file_info.st_ino);

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

        printf("\n");
    }

    return 0;
}

