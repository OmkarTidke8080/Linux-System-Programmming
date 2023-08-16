// Write a program which creates child process and parent process will communicate with child process by sending signals

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

static int received = 0;

void readmsg(int sig)
{
    if(sig == SIGUSR1)
    {
        received = 1;
    }
}

int main()
{
    signal(SIGUSR1,readmsg);

    pid_t pid2 = fork();

    if(pid2 < 0)
    {
        printf("Unable to create child process...\n");
    }
    else if(pid2 == 0)
    {
        printf("Process1, pid=%d\n",getpid());
        while(!received);
        
            printf("SIGUSR Received\n");
        
    }
    else
    {
        kill(pid2,SIGUSR1);
        printf("%s\n","Process1 end");
        while(1);
    }


    return 0;
}