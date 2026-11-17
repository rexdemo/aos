
#include <stdio.h>
#include <dirent.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    int count = 0;

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("Files in current directory:\n");

    while ((entry = readdir(dir)) != NULL)
    {
        if (entry->d_name[0] != '.')
        {
            printf("%s\n", entry->d_name);
            count++;
        }
    }

    printf("\nTotal number of files: %d\n", count);

    closedir(dir);

    return 0;
}

