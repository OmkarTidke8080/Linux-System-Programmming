// Write a program which accept directory name from user and printf all the file names from that directory

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>
#include<unistd.h>


int main(int argc , char * argv[])
{
  char DirName[20];
  DIR *dp = NULL;
  char name[30];
  struct dirent *entry = NULL;

  printf("Enter name of directory \n");
  scanf("%s",DirName);

  dp = opendir(DirName);
  if(dp == NULL)
  {
    printf("Unable to open directory\n");
    return -1;
  }

  while((entry = readdir(dp)) != NULL)
  {
    printf("%s\n",entry->d_name);
  }

  close(dp);






    return 0;
}