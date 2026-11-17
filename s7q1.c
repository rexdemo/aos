
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    int fd;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if(fd < 0)
    {
        perror("File open failed");
        return 1;
    }

    dup2(fd, STDOUT_FILENO);

    close(fd);

    printf("Hello World\n");
    printf("Standard output redirected to file.\n");
    printf("Linux is Funny\n");

    return 0;
}

