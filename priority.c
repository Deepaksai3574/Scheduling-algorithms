#include <stdio.h>
void swap(int *a,int *b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n,i,tat[20];
    float avwt = 0,avtat = 0;
    printf("Enter Number of Processes: ");
    scanf("%d",&n);
    int b[n],p[n],index[n];
    printf("Enter Burst Times of the process \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
        index[i]=i+1;
    }
    printf("Enter Priorities of the process \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
        index[i]=i+1;
    }
    for(int i=0;i<n;i++)
    {
        int a=p[i],m=i;
        for(int j=i;j<n;j++)
        {
            if(p[j] > a)
            {
                a=p[j];
                m=j;
            }
        }
        swap(&p[i], &p[m]);
        swap(&b[i], &b[m]);
        swap(&index[i],&index[m]);
    }
    int t=0;
    printf("\n\n");
    printf("Order of process Execution is\n");
    for(int i=0;i<n;i++)
    {
        printf("P%d is executed from %d to %d\n",index[i],t,t+b[i]);
        t+=b[i];
    }
    
    printf("\n");
    printf("Process Id     Burst Time   Wait Time    TurnAround Time\n");
    int wait_time=0;
    for(int i=0;i<n;i++)
    {
        printf("P%d\t\t\t\t%d\t\t\t\t%d\t\t\t\t%d\n",index[i],b[i],wait_time,wait_time + b[i]);
        wait_time += b[i];
    }
    for(i =0;i<n;i++)
    {
     tat[i] = wait_time+b[i];
        avwt +=wait_time;
        avtat +=tat[i];
    }    
    avwt/=i;
    avtat/=i;
    printf("%f\n",avwt);
    printf("%f\n",avtat);
    
    return 0;
}
