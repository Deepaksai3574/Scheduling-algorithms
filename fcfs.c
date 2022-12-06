#include <stdio.h>
#include <string.h>

int main()
{
    int pid[30],at[30],bt[30],tat[30],wt[30],n,twt=0,ttat=0;
    float awt=0,atat=0;
    printf("Enter number of process: \n");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        pid[i] = i+1;
    }
    printf("Enter the arrival times: \n");
    for(int i = 0;i<n;i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter the Burst times: \n");
    for(int i =0;i<n;i++)
    {
        scanf("%d", &bt[i]);
    }
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++)
        {
            if(at[j+1]<at[j])
            {
                int temp = at[j+1];
                at[j+1] = at[j];
                at[j] = temp;
                
                int b = bt[j+1];
                bt[j+1] = bt[j];
                bt[j] = b;
                
                int c = pid[j+1];
                pid[j+1]=pid[j];
                pid[j] = c;
            }
        }
    }
    wt[0] = 0;
    for(int i =1;i<n;i++)
    {
        wt[i] = bt[i-1]+wt[i-1]+at[i-1]-at[i];
    }
    for(int i =0;i<n;i++)
    {
        tat[i] = wt[i]+bt[i];
    }
printf("\nProcess ID\t\tArrival time\t\tBurst time\t\tTurn Around time\t\tWaiting time \n");
for(int i =0;i<n;i++)
{
    twt = twt + wt[i];
    ttat = ttat + tat[i];
printf("P%d\t\t\t\t%d\t\t\t\t\t\t%d\t\t\t\t\t%d\t\t\t\t\t%d\n",pid[i],at[i],bt[i],tat[i],wt[i]);
}
float s = (float)twt/(float)n;
float t = (float)ttat/(float)n;

printf("Average waiting time = %f",s);
printf("/n");
printf("Average Turn Around time = %f",t);
return 0;
    
    
}
