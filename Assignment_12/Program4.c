// Write a program which maps any file in memory and read data from that mapped file

#include<stdio.h>
#include<fcntl.h>
#include<sys/mman.h>
#include<unistd.h>



int main(void)
{
    int fd = open("/temp/test_map",O_CREAT | O_RDWR, S_IRWXU);

    char * mapped_region = mmap(NULL, sysconf(_SC_PAGE_SIZE),PROT_WRITE,MAP_SHARED, fd,0);

    printf("%c\n",mapped_region[0]);
       printf("%c\n",mapped_region[1]);
          printf("%c\n",mapped_region[2]);
             printf("%c\n",mapped_region[3]);
                printf("%c\n",mapped_region[4]);
                   printf("%c\n",mapped_region[5]);


   





   
}