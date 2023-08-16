// cleint program

#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>

#define FIFO_FILE "Myfifo"

int main()
{
    int fd;
    int end_process;
    int stringlen;
    char readbuf[80];
    char end_str[5];
    printf("FIFO_CLIENT : Send messages ");
    fd = open(FIFO_FILE,O_CREAT | O_WRONLY);
    strcpy(end_str,"end");

    while(1)
    {
        printf("Enter string..");
        fgets(readbuf, sizeof(readbuf),stdin);
        stringlen = strlen(readbuf);
        readbuf[stringlen - 1] = '\0';
        end_process = strcmp(readbuf, end_str);

        if(end_process != 0)
        {
            write(fd, readbuf,strlen(readbuf));
            printf("Sent string %s  and string length %d",readbuf, (int)strlen(readbuf));

        }
        else
        {
            write(fd,readbuf,strlen(readbuf));
            printf("sent string %s and string lengh is %d",readbuf, (int)strlen(readbuf));
            close(fd);
            break;
        }
    }



    return 0;
}