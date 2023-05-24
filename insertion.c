#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
int temp,key,n,i,j,a[10];
int pid;
printf("How many elements\n");
scanf("%d",&n);
printf("\nEnter the elements");
{
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
pid=fork();
if(pid==0)
{
printf("we have entered insertion sort");
for(i=0;i<=n-1;i++){
for(j=i+1;j<=n-1;j++){
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nthe sorted elements by insertion sort are:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
printf("\n");
}
else
{
wait(NULL);
printf("\nwe have entered bubble sort ::\n");
for(i=0;i<=n-1;i++){
for(j=i+1;j<=n-1;j++){
if(a[i]>a[j])
{
temp=a[i];
a[i]=a[j];
a[j]=temp;
}
}
}
printf("\nthe sorted elements by bubble sort are::\t");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}
}
}
}
