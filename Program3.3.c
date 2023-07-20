// Write a program which accept two directory names from user and move all files  from source directory to destination directory


#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    char *dpSource = NULL;
    char *dpDest = NULL;
    int fdSource = 0;
    int fdDest = 0;
    unsigned char Buffer[4096];
    int Ret = 0;
    int copy = 0;
  
    struct dirent *entry = NULL;

    if(argc != 3)
    {
        printf("Insufficient arguments \n");
        return -1;
    }

    dpSource = argv[1];
    dpDest = argv[2];


    fdSource = open(dpSource, O_RDONLY);
    fdDest = open(dpDest,O_CREAT | O_WRONLY);

   while(1)
   {
     Ret = read(fdSource,Buffer,4096);
     if(Ret == -1)
     {
        printf("Error reading files\n");
        return -1;
     }
          copy = Ret;

        if(copy == 0)
        {
          break;
        }

       Ret = write(fdDest,Buffer,copy);
       if(Ret == -1)
       {
        printf("Error writing into file \n");
        return -1;
       }
   }

    close(fdSource);
    close(fdDest);

return 0;
}



