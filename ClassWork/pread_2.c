#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>

int main()
{
    int fd = 0;
    off_t offset = 0;
    char Buffer[100];
    int iRet = 0;

    fd = open("./LSP.txt",O_RDONLY);

    offset = lseek(fd,10,SEEK_SET);

    printf("Current offset is : %ld\n",offset);     //0

    iRet = read(fd,Buffer,5);

    //printf("Data from file is : %5s\n",Buffer);  // 5 width specifier
    printf("\n");
    write(1,Buffer,iRet);
    printf("\n");

    offset = lseek(fd,0,SEEK_CUR);

    printf("Current offset is : %ld\n",offset);     //10
    return 0;
} 