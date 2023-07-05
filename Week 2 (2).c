#include<stdio.h>

int at[10],t,pt[10],tat[10],wt[10],n,time=0,i,ready[10],pry[10],op=0, maxpr,x,p[10];
float atat=0,awt=0;

void main()
{
    printf("Enter number of processes \n");
    scanf("%d",&n);

    printf("Enter araival times: \n");
    for(i=0;i<n;i++)
    scanf("%d",&at[i]);

    printf("Enter process times: \n");
    for(i=0;i<n;i++)
    scanf("%d",&pt[i]);

    printf("Enter priority: \n");
    for(i=0;i<n;i++)
    scanf("%d",&pry[i]);

    for(i=0;i<n;i++)
    ready[i]=0;

    for(i=0;i<n;i++)
    p[i]=pt[i];

    for(i=0;i<n;i++)
    time+=pt[i];
    t=n;
    while(t--)
    {
        for(i=0;i<n;i++)
        if(op>=at[i])
        ready[i]=1;

        for(i=0;i<n;i++)
        if(pt[i]==0)
        pry[i]=0;
        maxpr=pry[0];
        for(i=0;i<n;i++)
        if(ready[i]==1)
        if(pry[i]>maxpr)
        maxpr=pry[i];

        for(i=0;i<n;i++)
        if(maxpr==pry[i])
        x=i;

        //printing chart
        printf("%d p%d ",op,(x+1));


        op=op+pt[x];
        tat[x]=op;
        ready[x]=0;
        pry[x]=0;
    }
    printf("%d",op);
    for(i=0;i<n;i++)
    {
        tat[i]=tat[i]-at[i];
    }

    for(i=0;i<n;i++)
    {
        atat+=tat[i];
        wt[i]=tat[i]-pt[i];
    }
    for(i=0;i<n;i++)
    awt+=wt[i];

    awt=awt/n;
    atat=atat/n;

    printf("\n");
    for(i=0;i<n;i++)
    printf("P%d  %d  %d \n",(i+1),tat[i],wt[i]);
    printf("ATAT=%f  \nAWT=%f ",atat,awt);
}
