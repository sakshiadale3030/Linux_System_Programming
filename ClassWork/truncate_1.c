#include<stdio.h>
#include<unistd.h>

int main()
{
    int iRet = 0;
    truncate("Demo.txt",10);

    if(iRet == 0)
    {
        printf("Truncate is succesful\n");
    }
    else
    {
        printf("Truncate is not successful\n");
    }
    return 0;
}