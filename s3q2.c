#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>

pid_t pid;
volatile sig_atomic_t timeout = 0;

void sigchld_handler(int sig)
{
    printf("\nChild process has completed.\n");
}

void alarm_handler(int sig)
{
    timeout = 1;
    kill(pid, SIGKILL);
}

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <command>\n", argv[0]);
        return 1;
    }

    signal(SIGCHLD, sigchld_handler);
    signal(SIGALRM, alarm_handler);

    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    else if(pid == 0)
    {
        printf("Child process started.\n");

        execvp(argv[1], &argv[1]);

        perror("execvp");
        exit(1);
    }

    else
    {
        printf("Parent process started.\n");

        alarm(5);

        int status;
        while(waitpid(pid, &status, 0) == -1)
        {
            if(errno != EINTR)
            {
                perror("waitpid");
                return 1;
            }
        }

        alarm(0);

        if(timeout)
        {
            printf("Child process killed after 5 seconds.\n");
        }
        else
        {
            printf("Child process completed within 5 seconds.\n");
        }
    }

    return 0;
}

