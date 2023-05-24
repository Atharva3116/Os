#include<stdio.h>
#include<sys/types.h>
void childprocess();
void parentprocess();
int main()
{
pid_t pid;
pid=fork();
if(pid==0)
{
printf("child pid=%d",pid);
childprocess();
}
else{
printf("parent pid=%d",pid);
parentprocess();
return 0;
}
void childprocess(){
printf("i am child process");
}
void parentprocess(){
printf("i am parent process");
}