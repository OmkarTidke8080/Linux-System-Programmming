// Write a program whcih accept directory name from user and write athe information of all regular files in and the read the contents from that file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>


int main(int argc, char *argv[])
{
    
  DIR *dp = NULL;
  struct dirent * entry = NULL;
  struct stat sobj;
  char name[30];
   char DirName[20];

  printf("Enter name of dirsctory : ");
  scanf("%s",&DirName);

  dp = open(DirName,O_RDONLY);

  while( (entry = readdir(dp)) != NULL)
  {
    sprintf("%s/%s",DirName,entry->d_name);

     stat(name,&sobj);

     if(S_ISREG(sobj.st_mode))
     {
        printf("File Name is : %s",entry->d_name);
        printf("File Size is : %d \n",sobj.st_size);
        printf("Number of links : %d\n",sobj.st_nlink);
        printf("Inode Number : %d\n",sobj.st_ino);
     }
  }


    return 0;
}