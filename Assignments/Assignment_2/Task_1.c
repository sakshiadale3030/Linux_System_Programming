// • Accept file name and print full content on console.
// • Use a buffer loop (read() until 0).
// • Show total bytes read.

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
#include<sys/stat.h>
#include<stdlib.h>

///////////////////////////////////////////////////////////////////////////
//
//  User Defined Macros
//
////////////////////////////////////////////////////////////////////////////

#define SIZE_BUFFER 1024

////////////////////////////////////////////////////////////////////////////
//
// Function name : ReadWholeFile
// Description   : Read the Whole File
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
//////////////////////////////////////////////////////////////////////////

void ReadWholeFile(char *FileName)
{
    int fd = 0;
    char Buffer[SIZE_BUFFER];
    int iRet = 0;

    // memset is used to flush and clear
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
    iRet = read(fd,Buffer,SIZE_BUFFER);

    while(iRet > 0)
    {
        printf("%d bytes gets successfully read\n",iRet);
        printf("Data from file : %s\n",Buffer);

        // memset is used to flush and clear
        memset(Buffer,'\0',SIZE_BUFFER);        
        iRet = read(fd,Buffer,SIZE_BUFFER);
    }

    if(iRet == 0)
    {
        printf("We read the whole data successfully.\n");
    }
    else
    {
        perror("Failed to Read ");
        return;
    }

    close(fd);
}
/////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Sakshi Ashok Adale.
//  Date          : 25/12/2025
//
/////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: %s <FileName>\n", argv[0]);
        return -1;
    }

    ReadWholeFile(argv[1]);

    return 0;
}
