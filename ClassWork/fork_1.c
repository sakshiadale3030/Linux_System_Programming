#include<unistd.h>
#include<stdio.h>

int main()
{
    pid_t pid = 0;

    pid = fork();

    printf("%d\n",pid);

    return 0;
}