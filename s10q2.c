
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
    int fd[2];
    pid_t pid;
    char write_msg[] = "Hello Child Process";
    char read_msg[100];

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
        close(fd[1]);

        read(fd[0], read_msg, sizeof(read_msg));

        printf("Child received message: %s\n", read_msg);

        close(fd[0]);
    }

    else
    {
        close(fd[0]);

        printf("Parent is writing message to pipe.\n");

        write(fd[1], write_msg, strlen(write_msg) + 1);

        close(fd[1]);

        wait(NULL);
    }

    return 0;
}

