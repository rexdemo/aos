
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;
    int status;

    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    else if(pid == 0)
    {
        printf("Child process is running.\n");
        exit(5);
    }

    else
    {
        wait(&status);

        if(WIFEXITED(status))
        {
            printf("Child process terminated normally.\n");
            printf("Exit Status: %d\n", WEXITSTATUS(status));
        }
        else
        {
            printf("Child process terminated abnormally.\n");
        }
    }

    return 0;
}

