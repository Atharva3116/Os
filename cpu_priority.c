#include<stdio.h>
#include<unistd.h>
void main()
{
int pid,retnice;
printf("\npress DEL to stop process\n");
pid=fork();
for(;;)
{
if(pid==0)
{
retnice=nice(-5);
printf("child gets higher cpu priority of %d\n",retnice);
sleep(10);
}
else
{
retnice=nice(4);
printf("parent gets lower cpu priorityof %d\n",retnice);
sleep(10);
}
}
}