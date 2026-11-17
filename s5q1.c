
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir(".");

    if(dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("Files in Current Directory:\n");

    while((entry = readdir(dir)) != NULL)
    {
        if(entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
            count++;
        }
    }

    printf("\nTotal Number of Files: %d\n", count);

    closedir(dir);

    return 0;
}

