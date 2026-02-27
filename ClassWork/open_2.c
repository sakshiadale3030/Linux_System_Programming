#include<fcntl.h>
#include<stdio.h>

int main()
{
    int fd = 0;

    fd = open("Second.c",O_RDWR);

    if(fd == -1)
    {
        printf("Enable to open the file\n");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
    }

    return 0;
}