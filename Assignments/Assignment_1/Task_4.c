// • Accept file name and display file metadata using stat():
// • Size, inode, permissions, hard links, owner uid/gid, 
//   file type, last access/modify time.

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
#include<time.h>

////////////////////////////////////////////////////////////////////////////
//
// Function name : DisplayMetadata
// Description   : Display file metadata using stat()
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
////////////////////////////////////////////////////////////////////////////

void DisplayMetadata(char *FileName)
{
    int iRet = 0;
    struct stat StatBuffer;
    
    // stat() -> display file metadata
    iRet = stat(FileName, &StatBuffer);

    if(iRet == 0)
    {
        printf("INODE Number : %lu\n",StatBuffer.st_ino);

        printf("Total size : %lu\n",StatBuffer.st_size);
        
        printf("Block size : %lu\n",StatBuffer.st_blksize);

        printf("HardLink count : %lu\n",StatBuffer.st_nlink);

        printf("Owner uid : %d\n",StatBuffer.st_uid);

        printf("Owner gid : %d\n",StatBuffer.st_gid);

        printf("Permissions: %o\n",StatBuffer.st_mode & 0777);

        printf("Last access time (Atime): %s", ctime(&StatBuffer.st_atime));

        printf("Last modification time (Mtime): %s", ctime(&StatBuffer.st_mtime)); 
    }
    else
    {
        perror("Error ");
    }
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
    DisplayMetadata(argv[1]);

    return 0;
}
