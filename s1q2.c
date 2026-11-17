#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/types.h>

void handler(int sig)
{
    printf("Alarm is fired\n");
}

int main()
{
    pid_t pid;

    signal(SIGALRM, handler);

    pid = fork();

    if(pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    else if(pid == 0)
    {
        printf("Child Process\n");
        sleep(2);

        kill(getppid(), SIGALRM);

        printf("Signal sent by child process\n");
    }

    else
    {
        printf("Parent Process Waiting...\n");
        pause();
    }

    return 0;
}

