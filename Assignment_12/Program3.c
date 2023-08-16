// Write a program which creates one child process. child process write somethingin unnamed pipe and parent process read data from that pipe

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

    if(iRet == 0)  // child 
    {
       printf("Child process communictes with parent..\n");
       close(fd[0]);
       write(fd[1], Arr, strlen(Arr));
       exit(0);
    } 
    else  // parent
    {
        printf("Parent process communicate swith child..\n");
        close(fd[1]);
        read(fd[0],Buffer, sizeof(Buffer));
        printf("Data from pipe is : %s]\n",Buffer);

    }

    return 0;
}