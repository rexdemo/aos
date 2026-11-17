
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1)
    {
        perror("pipe");
        return 1;
    }

    pid = fork();

    if(pid < 0)
    {
        perror("fork");
        return 1;
    }

    else if(pid == 0)
    {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);

        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);

        perror("execlp");
        exit(1);
    }

    else
    {
        wait(NULL);

        pid = fork();

        if(pid == 0)
        {
            close(fd[1]);

            dup2(fd[0], STDIN_FILENO);

            close(fd[0]);

            execlp("wc", "wc", "-l", NULL);

            perror("execlp");
            exit(1);
        }

        else
        {
            close(fd[0]);
            close(fd[1]);

            wait(NULL);
        }
    }

    return 0;
}

