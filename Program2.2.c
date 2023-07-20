// Write a progrma which accpet file name from user and write a string in that file

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main( int argc, char *argv[])
{
  int fd = 0;
  char Buffer[BLOCKSIZE];
  int size = 0;
  int Ret = 0;


  if(argc != 2)
  {
     printf("Insufficient arguments \n");
     return -1;
  }


  fd = open(argv[1],O_RDONLY);
  if(fd == -1)
  {
    printf("Unable to open file\n");
    return -1;
  }

  while(( Ret = read(fd,Buffer,sizeof(Buffer))) != 0)
  {
    write(1,Buffer,Ret);
  }

  close(fd);

    return 0;
}