
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    else if(pid == 0)
    {
        while(1)
        {
            printf("Child process is running...\n");
            sleep(1);
        }
    }

    else
    {
        sleep(3);

        printf("\nParent: Suspending child process.\n");
        kill(pid, SIGSTOP);

        sleep(3);

        printf("\nParent: Resuming child process.\n");
        kill(pid, SIGCONT);

        sleep(3);

        printf("\nParent: Terminating child process.\n");
        kill(pid, SIGTERM);

        wait(NULL);
    }

    return 0;
}

