// write a program which accept filename from user and print all information about that file

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>


int main(int argc, char *argv[])
{

 int fd = 0;
 struct stat sobj;

 if(argc != 2)
 {
    printf("Invalid number of arguments \n");
    return -1;
 }

 stat(argv[1],&sobj);

 printf("File Name : %s\n",argv[1]);
 printf("File Size : %ld\n",sobj.st_size);
 printf("Number of links : %ld\n",sobj.st_nlink);
 printf("Inode number : %ld\n",sobj.st_ino);

    return 0;
}