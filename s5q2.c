
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char buffer[100];

    if(pipe(fd) == -1)
    {
        perror("Pipe failed");
        return 1;
    }

    pid = fork();

    if(pid < 0)
    {
        perror("Fork failed");
        return 1;
    }

    else if(pid == 0)
    {
        close(fd[0]);

        write(fd[1], "Hello World\n", 12);
        write(fd[1], "Hello SPPU\n", 11);
        write(fd[1], "Linux is Funny\n", 15);

        close(fd[1]);
        exit(0);
    }

    else
    {
        close(fd[1]);

        printf("Messages received from child process:\n");

        while(read(fd[0], buffer, sizeof(buffer) - 1) > 0)
        {
            printf("%s", buffer);
        }

        close(fd[0]);
    }

    return 0;
}

