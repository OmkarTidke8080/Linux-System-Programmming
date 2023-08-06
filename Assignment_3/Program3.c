// Write a program which accept two directory names from user and move all files  from source directory to destination directory


#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/dir.h>
#include<string.h>


int main(int argc , char *argv[])
{
   DIR *dp = NULL;

   struct dirent *entry = NULL; 

   char oldname[25];
   char newname[25];
   int iCnt = 1;

   dp = opendir(argv[1]);
   if(dp ==NULL)
   {
    printf("Unable to open directory \n");
    return -1;
   }
   
   while(entry = readdir(dp) != NULL)
   {
    sprintf(oldname,"%s/%s",argv[1],entry->d_name);
    sprintf(newname,"%s/%d.txt",argv[1],entry->d_name);

    rename(oldname,newname);
    iCnt++;

   }

  closedir(dp);
  
    return 0;
}