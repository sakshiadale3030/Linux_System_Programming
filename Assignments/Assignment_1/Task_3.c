// • Accept file name and mode (read/write/execute).
// • Use access() to check permission for current process.
// • Print “Accessible / Not accessible” with reason.

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Required Header files
//  
////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<string.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function name : CheckPermission
// Description   : open file with given mode and Use access() to check permission for current process.
// Input         : char*
// output        : void
// Author        : Sakshi Ashok Adale.
// Date          : 24/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////

void CheckPermission(char *FileName, char * mode)
{
    int permission = 0;
    int iPer = 0;
    
    if(iPer = (strcmp(mode,"Read")) == 0)
    {
        permission = R_OK;
    }
    else if(iPer = (strcmp(mode,"Write")) == 0)
    {
        permission = W_OK;
    }
    else if(iPer = (strcmp(mode,"Execute")) == 0)
    {
        permission = X_OK;
    }
    else
    {
        perror("Invalid mode ");
        return;
    }

    // access() -> used to access filename and permission
    iPer = access(FileName , permission | F_OK);

    if(iPer == 0)
    {
        printf("File has permission of %s\n",mode);
    }
    else
    {
        printf("File has no permission");
    }

    close(iPer);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : main()   (entry point function)
//  Author        : Sakshi Ashok Adale.
//  Date          : 24/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
    CheckPermission(argv[1],argv[2]);

    return 0;
}
