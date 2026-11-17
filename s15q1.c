
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat file;
    long n;
    int count = 0;

    printf("Enter size in bytes: ");
    scanf("%ld", &n);

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("\nFiles greater than %ld bytes:\n", n);

    while ((entry = readdir(dir)) != NULL)
    {
        if (stat(entry->d_name, &file) == 0)
        {
            if (S_ISREG(file.st_mode) && file.st_size > n)
            {
                printf("%s - %ld bytes\n",
                       entry->d_name, (long)file.st_size);
                count++;
            }
        }
    }

    printf("\nTotal files: %d\n", count);

    closedir(dir);

    return 0;
}

