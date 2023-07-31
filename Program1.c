// write a program which creates static library which contains file name from user and which displays th information of file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include "sharedfile.h"

void DisplayFileInfo(char file[50])
{
    struct stat sobj;
    stat(file,&sobj);

    printf("File Size is : %d\n",sobj.st_size);
    printf("Number of links : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("Number of block : %d\n",sobj.st_blocks);
    printf("Mode of file : %s\n",sobj.st_mode);

}