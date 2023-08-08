// Write a program which writes structure in file. structure should contain information of student

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)

struct Student
{
    int Rollno;
    char SName[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char FName[20];
    int fd = 0;


    printf("Enter the File name : \n");
    scanf("%s",FName);

    fd = open(FName,O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Roll Number : %d \n",sobj.Rollno);
    printf("Name : %s\n",sobj.SName);
    printf("Marks : %d\n",sobj.Marks);
    printf("Age : %d\n",sobj.Age);
 
    close(fd);

 return 0;


}