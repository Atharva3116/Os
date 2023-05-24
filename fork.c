#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
int pid;
pid=fork();

if(pid<0)
{
fprintf(stderr,"\nfork failed\n");
return 1;
}

else if(pid==0)
{
printf("\nchild process is running\n");
printf("\n child process id=%d",getpid());
printf("\n parent process id=%d",getppid());
sleep(10);
printf("\nchild process id=%d",getpid());
printf("\nparent process id=%d",getppid());
printf("\nchild process is completed\n");
}
else
{
printf("\nparent process id=%d\n",getpid());
}

return 0;
}