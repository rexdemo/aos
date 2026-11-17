
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat file;
    struct tm *t;
    int month, count = 0;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if (month < 1 || month > 12)
    {
        printf("Invalid month\n");
        return 1;
    }

    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory\n");
        return 1;
    }

    printf("\nFiles modified in month %d:\n", month);

    while ((entry = readdir(dir)) != NULL)
    {
        if (stat(entry->d_name, &file) == 0)
        {
            if (S_ISREG(file.st_mode))
            {
                t = localtime(&file.st_mtime);

                if (t->tm_mon + 1 == month)
                {
                    printf("%s\n", entry->d_name);
                    count++;
                }
            }
        }
    }

    printf("\nTotal files: %d\n", count);

    closedir(dir);

    return 0;
}

