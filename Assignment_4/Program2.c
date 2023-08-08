// Write a program which accept a directory from user and create a new directory ogf that name

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc , char *argv[])
{
   DIR *dp = NULL;
   struct dirent *entry = NULL;
   char oldname[30];
   char newname[30];
   int iCnt = 1; 

   dp = opendir(argv[1]);

   if(dp == NULL)
   {
      printf("Unable to open director \n");
      return -1;
   }

   while(entry = readdir(dp) != NULL)
   {
      printf(oldname,"%s/%s",argv[1],entry->d_name);
      printf(newname,"%s/%s",argv[1],entry->d_name);

      rename(oldname,newname);
      iCnt++;
   }
}