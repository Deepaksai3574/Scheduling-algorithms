#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],i,j,p[20],pos,temp,total =0;
    float avwt = 0,avtat = 0;
    printf("Enter total number of process: ");
    scanf("%d",&n);
    
    printf("Enter process burst time:\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;         
    }
    wt[0] = 0;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
  
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
  
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
  
        total+=wt[i];
    }
    avwt=(float)total/n;      
    total=0;
    printf("Process ID\t\tSJF arrangement\t\tWaiting time\t\tTurn around time");
    for(i=0;i<n;i++)
    {
       tat[i]=bt[i]+wt[i];   
        total+=tat[i];
        printf("\np%d\t\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    avtat=(float)total/n;
    printf("\n\nAverage waiting time: %f",avwt);
    printf("\nAverage Turn around time: %f",avtat);
    return 0;
}
