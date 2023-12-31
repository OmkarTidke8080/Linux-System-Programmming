// Write a program which performs interprocess communication using concept of message queus

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX 10

struct mesg_BUFFER
{
    long mesg_type;
    char mesg_text[100];
}message;

int main()
{
    key_t key;
    int msgid;

    key = ftok("progfile",65);

    msgid = (msgget(key, 0666 | IPC_CREAT));
    message.mesg_type = 1;

    printf("Write data : ");
    fgets(message.mesg_text,MAX,stdin);

    msgsnd(msgid, &message, sizeof(message),0);

    printf("Data sedn is : %s\n",message.mesg_text);




    return 0;
}