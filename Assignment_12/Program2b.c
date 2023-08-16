#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<pthread.h>

int main()
{
   int shmid  = 0;
   int shmsize = 100;
   int key = 1234;

   char *ptr = NULL;

   printf("Client application running...\n");

   shmid = shmget(key,shmsize,0666);

   ptr = shmat(shmid,NULL,0);

   if(ptr != NULL)
   {
       printf("Shared memory allocaed successfully...");
   }

    return 0;
}