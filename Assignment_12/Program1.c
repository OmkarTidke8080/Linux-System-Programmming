// Write a program whcih is used to create a unnamed pipe. parent process creaes new child process both the processes will communicate with each other

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/resource.h>
#include<string.h>
#include<pthread.h>

int main()
{
    int fd[2];
    int iRet = 0;
    char Arr[] = "Hello World";
    char Buffer[512];

    pipe(fd);

    iRet = fork();

    if(iRet == 0)
    {
       printf("Child process communictes with parent..\n");
       close(fd[0]);
       write(fd[1], Arr, strlen(Arr));
       exit(0);
    }
    else
    {
        printf("Parent process communicate swith child..\n");
        close(fd[1]);
        read(fd[0],Buffer, sizeof(Buffer));
        printf("Data from pipe is : %s]\n",Buffer);

    }

    return 0;
}