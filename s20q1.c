
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

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
        while (1)
        {
            printf("Child process is running...\n");
            sleep(1);
        }
    }
    else
    {
        sleep(3);

        printf("\nSuspending child process...\n");
        kill(pid, SIGSTOP);

        sleep(3);

        printf("\nResuming child process...\n");
        kill(pid, SIGCONT);

        sleep(3);

        printf("\nTerminating child process...\n");
        kill(pid, SIGTERM);

        wait(NULL);

        printf("Child process terminated.\n");
    }

    return 0;
}

