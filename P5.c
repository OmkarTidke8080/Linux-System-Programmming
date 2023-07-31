#include<stdio.h>
#include "sharedfile.h"

int main()
{
    char file[30];
    printf("Enter the file name\n");
    scanf("%s",file);
    DisplayFileInfo(file);
    
    return 0;
}