// Write a program which accept file name from user which contains information of employee, we have to read all the contents of that file

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct Employee
{
  char Emp_Name[20];
  int Emp_id ;
  float Emp_Sal;
};


int main(int argc, char *argv[])
{
    int fd = 0;
    struct Employee eobj;
    char FName[20];

    printf("Enter File Name : ");
    scanf("%s",&FName);

    fd = open(FName,O_RDONLY);

    read(fd,&eobj,sizeof(eobj));

    printf("Emp_Name : %s \n",eobj.Emp_Name);
    printf("Emp_Id : %d \n",eobj.Emp_id);
    printf("Employee Salary : \n",eobj.Emp_Sal);


    close(fd);

 
}