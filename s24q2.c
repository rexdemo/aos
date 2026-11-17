
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t pid;

void alarm_handler(int sig)
{
    printf("\nTime limit exceeded! Killing child process.\n");
    kill(pid, SIGKILL);
}

void child_handler(int sig)
{
    printf("\nChild process terminated.\n");
}

int main()
{
    signal(SIGALRM, alarm_handler);
    signal(SIGCHLD, child_handler);

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }

    if (pid == 0)
    {
        printf("Child process started.\n");

        execlp("sleep", "sleep", "10", NULL);

        printf("Command execution failed.\n");
        exit(1);
    }
    else
    {
        printf("Parent process started.\n");

        alarm(5);

        wait(NULL);

        alarm(0);

        printf("Parent process completed.\n");
    }

    return 0;
}

