// • Accept file name and number of bytes N.
// • Read exactly N bytes using read() and print on console.
// • If file contains less than N, print only available bytes

////////////////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>
#include <sys/stat.h>
#include<stdlib.h>

////////////////////////////////////////////////////////////////////////////
//
// Function name : ReadFile
// Description   : Display file metadata using stat()
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
//////////////////////////////////////////////////////////////////////////

#define SIZE_BUFFER 256

void ReadFile(char *FileName, char * No)
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    int iRet = 0;

    memset(Buffer,'\0',SIZE_BUFFER);

    // open() -> to open regular file.
    fd = open(FileName,O_RDONLY);

    if(fd < 0)
    {
        printf("Unable to open the file\n");
        printf("Reason : %s\n",strerror(errno));
        return;
    }
    else
    {
        printf("File successfully opened with fd : %d\n",fd);
    }

    // read() -> read content from file into program buffer
    iRet = read(fd,Buffer,atoi(No));

    printf("%d bytes gets successfully read\n",iRet);

    printf("Data from file : %s\n",Buffer);

    close(fd);
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Sakshi Ashok Adale.
//  Date          : 24/12/2025
//
/////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    ReadFile(argv[1],argv[2]);

    return 0;
}
