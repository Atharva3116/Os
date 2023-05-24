#include<stdio.h>
#include<stdlib.h>
struct process
{
int first_bt,next_bt,at,ft,tat,wt,temp_bt,Priority;
}P[100];
struct schedule
{
int pid,endtime;

}sch[100];
int sch_cnt;
int ct;
int np;
int i;
void accept()
{
printf("enter the no of process:");
scanf("%d",&np);
for(i=0;i<np;i++)
{
printf("enter the arrival time:");
scanf("%d",&P[i].at);
printf("enter fisrt BT");
scanf("%d",&P[i].first_bt);
printf("enter prioritty");
scanf("%d",&P[i].Priority);
P[i].next_bt=rand()%10+1;
P[i].temp_bt=P[i].first_bt;
}
}
int getProcessByPriority()
{
int min_p=-1;
int min_at=32768;
for(i=0;i<np;i++)
{
if(P[i].at<=ct && P[i].temp_bt>0 && P[i].temp_bt<min_at)
{
min_p=i;
min_at=P[i].Priority;
}
}
return min_p;
}
void showGanttchart()
{
for(i=0;i<sch_cnt*5;i++)
printf("-");
printf("\n|");
for(i=0;i<sch_cnt;i++)
printf("P%d |",sch[i].pid);
printf("\n");
for(i=0;i<sch_cnt*5;i++)
printf("-");
printf("n0");
for(i=0;i<=sch_cnt;i++)
printf("%5d",sch[i].endtime);
}
void main()
{
accept();
while(1)
{
int x=getProcessByPriority();
if(x==-1)
break;
sch[sch_cnt].pid=x;
ct+=P[x].temp_bt;
P[x].temp_bt=0;
sch[sch_cnt].endtime=ct;
sch_cnt++;
}
for(i=0;i<np;i++)
{
P[i].temp_bt=P[i].next_bt;
}
while(1)
{
int x= getProcessByPriority();
if(x==-1)
break;
sch[sch_cnt].pid=x;
ct+=P[x].temp_bt;
P[x].temp_bt=0;
P[x].ft=ct;
sch[sch_cnt].endtime=ct;
sch_cnt++;
P[x].tat=P[x].ft-P[x].at;
P[x].wt=P[x].tat-P[x].first_bt-P[x].next_bt-2;
}
void showPT()
{
float avgtat=0, avgwt=0;
printf("\n");
printf("\nPID\tFBT\tNBT\tTAT\tPrio\tFT\tTAT\tWT\n");
for(i=0;i<np;i++)
{
printf("\nP%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n",i,P[i].first_bt,P[i].next_bt,P[i].at,P[i].Priority,P[i].ft,P[i].tat,P[i].wt);
avgtat+=P[i].tat;
avgwt+=P[i].wt;
}
avgtat=avgtat/np;
avgwt=avgwt/np;
printf("avg tat=%f\n",avgtat);
printf("avg wt =%f\n",avgwt);
}
showPT();
showGanttchart();
}