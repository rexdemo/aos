
#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    char filename[100];
    struct stat file;

    printf("Enter file name: ");
    scanf("%s", filename);

    if (stat(filename, &file) == 0)
    {
        printf("\nFile Properties\n");

        printf("Inode Number: %ld\n", (long)file.st_ino);
        printf("Number of Hard Links: %ld\n", (long)file.st_nlink);
        printf("File Size: %ld bytes\n", (long)file.st_size);
        printf("File Permissions: %o\n", file.st_mode & 0777);
        printf("Number of Blocks: %ld\n", (long)file.st_blocks);

        printf("Last Access Time: %s", ctime(&file.st_atime));
        printf("Last Modification Time: %s", ctime(&file.st_mtime));
        printf("Last Status Change Time: %s", ctime(&file.st_ctime));
    }
    else
    {
        printf("File not found\n");
    }

    return 0;
}

