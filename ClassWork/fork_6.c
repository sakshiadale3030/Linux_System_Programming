#include<unistd.h>
#include<stdio.h>

int main()
{
    if(fork() == 0)
    {
        printf("Child process scheduled\n");
    }
    else
    {
        printf("Parent process scheduled\n");
    }

    return 0;
}   