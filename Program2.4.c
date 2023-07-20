// Write a program which accept directory from user and print all the file names and it types from that directory

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<dirent.h>

int main(int argc, char *argv)
{
  char DirName[20];
  DIR *dp = NULL;
  struct dirent *entry = NULL;
  char name[30];
  struct  stat sobj;

  printf("Enter Name of direcrtory : \n");
  scanf("%s",DirName);

  dp = opendir(DirName);

  if(dp == NULL)
  {
    printf("Unable to open directory \n");
    return -1;
  }

  while( (entry = readdir(dp)) != NULL)
  {
    printf("%s",entry->d_name);

    stat(entry->d_name,&sobj);

    if( S_ISREG(sobj.st_mode))
    {
        printf("%s \n is Regular file \n",entry->d_name );
    }
    else if(S_ISDIR(sobj.st_mode))
    {
        printf(" %s \n is Direcory file \n",entry->d_name);
    }

  }
 


  close(dp);



    return 0; 
}