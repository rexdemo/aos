
#include<stdio.h>
#include<stdlib.h>
#include<sys/resource.h>

int main()
{
    struct rlimit limit;

    // Get file size limit
    if(getrlimit(RLIMIT_FSIZE, &limit) == -1)
    {
        perror("getrlimit");
        return 1;
    }

    printf("File Size Limit:\n");
    printf("Soft Limit: %ld\n", (long)limit.rlim_cur);
    printf("Hard Limit: %ld\n", (long)limit.rlim_max);

    // Set file size limit
    limit.rlim_cur = 1024 * 1024;

    if(setrlimit(RLIMIT_FSIZE, &limit) == -1)
    {
        perror("setrlimit");
        return 1;
    }

    printf("\nFile size limit set to 1 MB.\n");

    // Get memory limit
    if(getrlimit(RLIMIT_AS, &limit) == -1)
    {
        perror("getrlimit");
        return 1;
    }

    printf("\nMemory Limit:\n");
    printf("Soft Limit: %ld\n", (long)limit.rlim_cur);
    printf("Hard Limit: %ld\n", (long)limit.rlim_max);

    return 0;
}

