#include<stdio.h>
int main()
{
    int n,bt[20],wt[20],tat[20],i,j;
    float avwt = 0,avtat = 0;
    printf("Enter total number of process: ");
    scanf("%d",&n);
    
    printf("Enter process burst time");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
    wt[0] = 0;
    for(i=1;i<n;i++)
    {
        wt[i] = 0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
    }
    printf("Process ID\t\tWaiting time\t\tTurn around time");
    for(i=0;i<n;i++)
    {
        tat[i] = bt[i]+wt[i];
        avwt+=wt[i];
        avtat += tat[i];
        printf("\np[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage waiting time: %f",avwt);
    printf("\nAverage TYurn around time: %f",avtat);
    return 0;
}
