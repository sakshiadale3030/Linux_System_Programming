// List Files with Type
// • Accept directory name.
// • Print each entry with its type: Regular / Directory / Link / FIFO / Socket / Char / Block
// • Use lstat() for accurate type.

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
// Function name : ListAllFile
// Description   : Read the Whole File
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 25/12/2025
//
//////////////////////////////////////////////////////////////////////////

void ListAllFile(char *DirName)
{
    DIR *dp;
    struct dirent *dir;
    struct stat sobj;
    int iRet = 0;

    char path[1024] = {'\0'};

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
        printf("File name : %s\n",dir->d_name);

        snprintf(path,1024,"%s/%s",DirName,dir->d_name);

        iRet = lstat(path,&sobj);

        if(iRet == -1)
        {
            printf("Unable to get stat %s\n",strerror(errno));
            return;
        }

        switch(sobj.st_mode & S_IFMT) 
        {
            case S_IFBLK:  
                printf("block device\n");            
                break;

            case S_IFCHR:  
                printf("character device\n");      
                break;

            case S_IFDIR:  
                printf("directory\n");              
                break;
            case S_IFIFO:  
                printf("FIFO/pipe\n");               
                break;

            case S_IFLNK:  
                printf("symlink\n");                 
                break;

            case S_IFREG:  
                printf("regular file\n");            
                break;

            case S_IFSOCK: 
                printf("socket\n");                  
                break;

            default:       
                printf("unknown?\n");                
                break;
        }
    }
    
    // closedir() is function closes the directory stream associated  with dirp.
    closedir(dp);
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
    if(argc != 2)
    {
        printf("Usage: %s <directory_name>\n", argv[0]);
        return -1;
    }
    
    ListAllFile(argv[1]);

    return 0;
}
