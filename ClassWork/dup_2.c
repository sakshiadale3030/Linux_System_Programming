#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd1 = 0, fd2 = 0;

    fd1 = open("./LSP.txt",O_RDWR);
    printf("Fd1 : %d\n",fd1);        //3

    fd2 = dup2(fd1,11);
    printf("Fd2 : %d\n",fd2);        //11
    
    return 0;
} 