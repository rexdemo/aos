
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

int count = 0;

void handler(int sig)
{
    count++;

    if(count == 1)
    {
        printf("\nCtrl+C pressed for first time. Press Ctrl+C again to exit.\n");
    }
    else
    {
        printf("\nCtrl+C pressed again. Exiting program.\n");
        exit(0);
    }
}

int main()
{
    signal(SIGINT, handler);

    while(1)
    {
        printf("Program is running...\n");
        sleep(1);
    }

    return 0;
}

