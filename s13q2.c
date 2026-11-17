
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *entry;
    int len, count = 0;

    if(argc != 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    len = strlen(argv[1]);

    dir = opendir(".");

    if(dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("Files starting with %s:\n", argv[1]);

    while((entry = readdir(dir)) != NULL)
    {
        if(strncmp(entry->d_name, argv[1], len) == 0)
        {
            printf("%s\n", entry->d_name);
            count++;
        }
    }

    printf("\nTotal matching files: %d\n", count);

    closedir(dir);

    return 0;
}

