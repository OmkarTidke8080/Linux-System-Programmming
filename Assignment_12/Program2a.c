// Write a program which creates two processes and that two processes can communicate with each other by using shared memeusing shared  memory

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<pthread.h>
#include<fcntl.h>
#include<sys/shm.h>

int main()
{
    int shmid = 0;    // shared memory id
    int shmsize = 100; // shared memory size
    int key = 1234;

    char *ptr = NULL;

    printf("Server application running...\n");

    shmid = shmget(key,shmsize,IPC_CREAT | 0666);

    printf("shared memory allocated successfully...");

    ptr = shmat(shmid,NULL,0);

    if(ptr != NULL)
    {
        printf("Shared memory attached successfully...\n");
    }


    return 0;
}