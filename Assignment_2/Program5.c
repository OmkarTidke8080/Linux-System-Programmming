// Write a program which accept directory name from use and print the name of such file which have largst size

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char DirName[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int size = 0;
    int iMax = 0;
    struct stat sobj;
    char namecopy[30] = {'\0'};
    char name[30];

    printf("Enter Name of dirctory \n");
    scanf("%s",&DirName);

    dp = opendir(DirName);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    while( ( entry = readdir(dp)) != NULL)
    {
        printf( " %s / %s ",DirName,entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
           if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(namecopy,name);
            } 

        }
    }
    printf("Name ff largest file is %s\n whithe  %d\n bytes \n",namecopy,iMax);


  closedir(dp);



    return 0;
}