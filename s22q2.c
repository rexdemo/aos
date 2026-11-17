
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid1, pid2;

    sigset_t set, oldset;

    // Block Ctrl+C and Ctrl+\
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);

    sigprocmask(SIG_BLOCK, &set, &oldset);

    // Create pipe
    if (pipe(fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    // First child process
    pid1 = fork();

    if (pid1 == 0)
    {
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execlp("ls", "ls", "-l", NULL);

        perror("exec ls failed");
        exit(1);
    }

    // Second child process
    pid2 = fork();

    if (pid2 == 0)
    {
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        execlp("wc", "wc", "-l", NULL);

        perror("exec wc failed");
        exit(1);
    }

    // Parent process
    close(fd[0]);
    close(fd[1]);

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    // Restore original signal mask
    sigprocmask(SIG_SETMASK, &oldset, NULL);

    return 0;
}

