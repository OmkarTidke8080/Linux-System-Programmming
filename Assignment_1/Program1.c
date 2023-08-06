// Write a program which accept a file name from user and open that file

#include<stdio.h>
#include<fcntl.h>

int main( int argc, char *argv[])
{
   int fd = 0;

   if(argc != 2)
   {
     printf("Invalid naumber of arguments \n");
     return -1;
   }

   fd = open(argv[1],O_RDONLY);
   if(fd == -1)
   {
    printf("unable to open file \n");
   }
   else
   {
    printf("File is successfully opened with fd : %d\n",fd);
   }

    return 0;
}