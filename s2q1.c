#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

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

    printf("Inode Number : %ld\n",
           (long)file_info.st_ino);

    printf("Number of Hard Links : %ld\n",
           (long)file_info.st_nlink);

    printf("File Size : %ld bytes\n",
           (long)file_info.st_size);

    printf("File Permissions : %o\n",
           file_info.st_mode & 0777);

    printf("Number of Blocks : %ld\n",
           (long)file_info.st_blocks);

    printf("Last Access Time : %s",
           ctime(&file_info.st_atime));

    printf("Last Modification Time : %s",
           ctime(&file_info.st_mtime));

    printf("Last Status Change Time : %s",
           ctime(&file_info.st_ctime));

    return 0;
}

