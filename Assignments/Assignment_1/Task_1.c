// • Accept file name from user and open it using open().
// • Print: success message + returned file descriptor.
// • Handle errors using perror().

/////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
//////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>

/////////////////////////////////////////////////////////////////
//
// Function name : OpenFile
// Description   : open file with given name of file.
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
/////////////////////////////////////////////////////////////////

void OpenFile(char *FileName)
{
    int fd = 0;

    // open() -> to open regular file.
    fd = open(FileName , O_RDWR);

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
    if (argc != 2)
    {
        printf("Usage: %s <FileName>\n", argv[0]);
        return -1;
    }
    
    OpenFile(argv[1]);

    return 0;
}

