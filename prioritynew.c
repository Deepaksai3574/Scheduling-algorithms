#include<stdio.h>

int main()
{
    int n,bt[30],tat[30],p[30];
    int wt[30];
    int prt[30];
    printf("No of Process:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        p[i]=i+1;
    }

    printf("Burst Time: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    printf(" priority: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&prt[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(prt[j+1]>prt[j])
                {
                    int priority=bt[j+1];
                    prt[j+1]=prt[j];
                    prt[j]=priority;

                    int b=bt[j+1];
                    bt[j+1]=bt[j];
                    bt[j]=b;

                    int c=p[j+1];
                    p[j+1]=p[j];
                    p[j]=c;

                }
        }
    }
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }
    
    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }

    printf("process--Burst--Wait--TAT--priority \n");
    for(int i=0;i<n;i++)
    {
        printf("P%d      %d      %d     %d      %d\n",p[i],bt[i],wt[i],tat[i],prt[i]);
    }

return 0;
}
