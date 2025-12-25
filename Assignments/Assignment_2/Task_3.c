// List All Files From Directory
// • Accept directory name.
// • Use opendir() / readdir() to print only names (skip . and ..)

////////////////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<dirent.h>
#include<errno.h>
#include<string.h>

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
        if(strcmp(dir->d_name,".") != 0 && strcmp(dir->d_name,"..") != 0)
        {
            printf("File name : %s\n",dir->d_name);
        }
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

    ListAllFile(argv[1]);

    return 0;
}
