#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>

int main()
{
    int fd = 0;
    char Buffer[] = "indiaismycountry";
    int iRet = 0;

    fd = open("Demo.txt", O_CREAT | O_WRONLY | O_APPEND,0777);
    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return -1;
    }

    printf("File successfully opened with fd : %d\n",fd);

    iRet = write(fd,Buffer,16);

    printf("%d bytes gets successfully written\n",iRet);

    fsync(fd); 

    //Process is in waiting state

    close(fd);

    sync();

    return 0;
}