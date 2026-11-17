
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<time.h>

int main()
{
    DIR *dir;
    struct dirent *entry;
    struct stat file_info;
    struct tm *time_info;
    int month, count = 0;

    printf("Enter month (1-12): ");
    scanf("%d", &month);

    if(month < 1 || month > 12)
    {
        printf("Invalid month\n");
        return 1;
    }

    dir = opendir(".");

    if(dir == NULL)
    {
        perror("opendir");
        return 1;
    }

    printf("\nFiles modified in month %d:\n", month);

    while((entry = readdir(dir)) != NULL)
    {
        if(stat(entry->d_name, &file_info) == 0)
        {
            if(S_ISREG(file_info.st_mode))
            {
                time_info = localtime(&file_info.st_mtime);

                if(time_info->tm_mon + 1 == month)
                {
                    printf("%s\n", entry->d_name);
                    count++;
                }
            }
        }
    }

    printf("\nTotal Files: %d\n", count);

    closedir(dir);

    return 0;
}

