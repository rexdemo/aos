
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

void handler(int sig)
{
    if (sig == SIGHUP)
    {
        printf("Child received SIGHUP signal.\n");
    }
    else if (sig == SIGINT)
    {
        printf("Child received SIGINT signal.\n");
    }
    else if (sig == SIGQUIT)
    {
        printf("My DADDY has Killed me!!!\n");
        exit(0);
    }
}

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }

    if (pid == 0)
    {
        signal(SIGHUP, handler);
        signal(SIGINT, handler);
        signal(SIGQUIT, handler);

        while (1)
        {
            pause();
        }
    }
    else
    {
        int i;

        for (i = 3; i < 30; i += 3)
        {
            sleep(3);

            if ((i / 3) % 2 == 1)
                kill(pid, SIGHUP);
            else
                kill(pid, SIGINT);
        }

        sleep(3);

        kill(pid, SIGQUIT);

        wait(NULL);
    }

    return 0;
}

