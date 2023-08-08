// Write a program which accept directory name and file name from user and create file in that directory

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    char DirName[20] ;
    char FileName[20];
    int fd = 0;

    printf("ENter Directory Name : ");
    scanf("%s",&DirName);

    printf("Enter File Name to be created : ");
    scanf("%s",&FileName);

    dp = opendir(DirName);

   fd = creat(FileName,O_RDONLY);


   closedir(dp);
    





    return 0;
}