// Write String to File
// • Accept file name and a string from user.
// • Write string using write() (append mode by default).
// • Print number of bytes written.

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
// Function name : WriteToFile
// Description   : Read the Whole File
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////

void WriteToFile(char *FileName, char *str)
{
    int fd = 0;
    int iRet = 0;

    // open() -> to open regular file.
    fd = open(FileName,O_WRONLY | O_APPEND);

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

    // write() -> write content to file 
    iRet = write(fd,str,strlen(str));

    if(iRet == -1)
    {
        perror("Unable to write ");
    }
    else
    {
        printf("%d bytes gets successfully writen\n",iRet);
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
    char buffer[SIZE_BUFFER] = {0};

    for(int i = 2; i < argc; i++)
    {
        strcat(buffer, argv[i]);
        if(i < argc - 1)
            strcat(buffer, " ");
    }

    WriteToFile(argv[1], buffer);

    return 0;
}
