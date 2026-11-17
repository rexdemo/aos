
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buffer[100];

    pipe(fd);

    pid = fork();

    if (pid == 0)
    {
        close(fd[0]);

        write(fd[1], "Hello World\n", 12);
        write(fd[1], "Hello SPPU\n", 11);
        write(fd[1], "Linux is Funny\n", 15);

        close(fd[1]);
    }
    else
    {
        close(fd[1]);

        read(fd[0], buffer, sizeof(buffer));
        printf("%s", buffer);

        close(fd[0]);

        wait(NULL);
    }

    return 0;
}

