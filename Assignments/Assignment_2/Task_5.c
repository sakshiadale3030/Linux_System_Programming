// Find Largest File in Directory
// • Accept directory name.
// • Find and print:
// ◦ largest file name
// ◦ its size in bytes
// • Consider only regular files (ignore directories).

////////////////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<unistd.h>

////////////////////////////////////////////////////////////////////////////
//
// Function name : LargestFile
// Description   : Read the Whole File
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////

void LargestFile(char *DirName)
{
    DIR *dp;
    struct dirent *dir;
    struct stat sobj;
    int iRet = 0;
    off_t max = 0;

    char path[512] = {'\0'};
    char *str = NULL;

    // opendir() is used to open directory file.
    dp = opendir(DirName);

    if(dp == NULL)
    {
        printf("%s\n",strerror(errno));
        return;
    }

    // readdir() is read data drom directory , return pointer pointing to dirent struct.
    while((dir = readdir(dp)) != NULL)
    {
        if(strcmp(dir->d_name,".") == 0 || strcmp(dir->d_name,"..") == 0)
        {
            continue;
        }

        snprintf(path,512,"%s/%s",DirName,dir->d_name);

        // stat() is used retrive metadata about file from inode
        iRet = stat(path,&sobj);
        if(iRet == -1)
        {
            perror("Error in stat ");
            return;
        }
        
        if(sobj.st_size > max)
        {
            str = dir->d_name;
            max = sobj.st_size;
        }

        printf("\nLargest file name : %s and its size is %ld bytes\n",str,max);

    }

    // closedir() is function closes the directory stream associated  with dirp.
    closedir(dp);
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
        printf("Usage: %s <directory_name>\n", argv[0]);
        return -1;
    }
    
    LargestFile(argv[1]);

    return 0;
}
