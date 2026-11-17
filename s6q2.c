
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/resource.h>

int main()
{
    int n, i;
    pid_t pid;
    struct rusage usage;

    printf("Enter number of child processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        pid = fork();

        if(pid < 0)
        {
            perror("Fork failed");
            exit(1);
        }

        else if(pid == 0)
        {
            printf("Child process %d created. PID = %d\n",
                   i + 1, getpid());

            for(int j = 0; j < 10000000; j++)
            {
                // CPU work
            }

            exit(0);
        }
    }

    for(i = 0; i < n; i++)
    {
        wait(NULL);
    }

    getrusage(RUSAGE_CHILDREN, &usage);

    printf("\nAll child processes terminated.\n");

    printf("Total User Mode Time: %ld seconds %ld microseconds\n",
           usage.ru_utime.tv_sec,
           usage.ru_utime.tv_usec);

    printf("Total Kernel Mode Time: %ld seconds %ld microseconds\n",
           usage.ru_stime.tv_sec,
           usage.ru_stime.tv_usec);

    return 0;
}

