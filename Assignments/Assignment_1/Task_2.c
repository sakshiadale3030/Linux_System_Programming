// • Accept file name and mode (R, W, RW, A) from user.
// • Convert mode to flags (O_RDONLY, O_WRONLY, O_RDWR, O_APPEND | O_CREAT).
// • Open file accordingly and display fd.

/////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
//////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

///////////////////////////////////////////////////////////////////////////////
//
// Function name : OpenFile
// Description   : open file with given mode.
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
/////////////////////////////////////////////////////////////////

void OpenFile(char *FileName, char * mode)
{
    int fd = 0;
    int iFlag = 0;
    
    if((strcmp(mode,"R")) == 0)
    {
        iFlag = O_RDONLY | O_CREAT;
    }
    else if((strcmp(mode,"W")) == 0)
    {
        iFlag = O_WRONLY | O_CREAT;
    }
    else if((strcmp(mode,"RW")) == 0)
    {
        iFlag = O_RDWR | O_CREAT;
    }
    else if((strcmp(mode,"A")) == 0)
    {
        iFlag = O_APPEND | O_CREAT;
    }
    else
    {
        perror("Invalid mode ");
    }

    // open() -> to open regular file.
    fd = open(FileName , iFlag , 0777);

    if(fd == -1)
    {
        perror("Unable to open file ");
    }
    else
    {
        printf("File gets successfully opened with fd : %d\n",fd);
    }

    close(fd);
}
/////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Sakshi Ashok Adale.
//  Date          : 24/12/2025
//
//////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    OpenFile(argv[1],argv[2]);

    return 0;
}
