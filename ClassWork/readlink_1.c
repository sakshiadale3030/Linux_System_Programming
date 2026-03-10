#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<errno.h>

int main()
{
    int fd = 0;

    fd = open("./Test/LSPl.txt",O_RDONLY);      //issue

    if(fd == -1)
    {
        printf("Unable to pen the file %s\n",strerror(errno));
        return -1;
    }

    printf("File is open %d\n",fd);

    close(fd);

    return 0;
}