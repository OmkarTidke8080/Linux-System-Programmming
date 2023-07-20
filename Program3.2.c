// Write a program which accept directory name from user and check whether that file is present in that directory or not

#include<stdio.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;

   if(argc != 2)
   {
    printf("Insufficient arguments \n");
    return -1;
   }

   dp = opendir(argv[1]);

   if(dp == NULL)
   {
    printf("Directory does not exist \n");
    return -1;
   }

   else
   {
    printf("Directory exist\n");
   }

   closedir(dp);








    return 0;
}