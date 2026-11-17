
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd;

    fd = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd < 0)
    {
        printf("File opening failed\n");
        return 1;
    }

    close(1);

    dup(fd);

    close(fd);

    printf("Hello World\n");
    printf("Linux is Funny\n");
    printf("Output redirected to file successfully.\n");

    return 0;
}

