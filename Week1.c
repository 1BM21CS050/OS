#include <stdio.h>

int at[10], pt[10], ia, ip, n;
int tat[10], wt[10], it, iw, pos, j, i;
float atat = 0, awt = 0;
void fcfs()
{

      wt[0] = wtavg = 0;
      tat[0] = tatavg = bt[0];
      for(i=1;i<n;i++)
      {
       wt[i] = wt[i-1] +bt[i-1];
       tat[i] = tat[i-1] +bt[i];
       wtavg = wtavg + wt[i];
       tatavg = tatavg + tat[i];
      }
}
void srtf()
{
    int rt[10], endTime, i, smallest;
    int remain = 0, time, sum_wait = 0, sum_turnaround = 0;
    printf("Enter no of Processes : ");
    scanf("%d", &n);
    printf("Enter arrival times\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &at[i]);
    }
    printf("Enter Process times \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pt[i]);
        rt[i] = pt[i];
    }
    rt[9] = 9999;
    for (time = 0; remain != n; time++)
    {
        smallest = 9;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && rt[i] < rt[smallest] && rt[i] > 0)
            {
                smallest = i;
            }
        }
        rt[smallest]--;
        if (rt[smallest] == 0)
        {
            remain++;
            endTime = time + 1;
            printf("\nP%d  %d  %d", smallest + 1, endTime - at[smallest], endTime - pt[smallest] - at[smallest]);
            sum_wait += endTime - pt[smallest] - at[smallest];
            sum_turnaround += endTime - at[smallest];
        }
    }
    printf("\n\nAverage waiting time = %f\n", sum_wait * 1.0 / n);
    printf("Average Turnaround time = %f", sum_turnaround * 1.0 / n);
}

void sjf()
{
    int completed = 0;
    int currentTime = 0;
    int complete[n], ct[n];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival times:\n");
    for (int ia = 0; ia < n; ia++)
        scanf("%d", &at[ia]);

    printf("Enter process times:\n");
    for (int ip = 0; ip < n; ip++)
        scanf("%d", &pt[ip]);

    for (int i = 0; i < n; i++)
    {
        complete[i] = 0;
        ct[i] = 0;
    }

    while (completed != n)
    {
        int shortest = -1;
        int min_bt = 9999;

        for (int i = 0; i < n; i++)
        {
            if (at[i] <= currentTime && complete[i] == 0)
            {
                if (pt[i] < min_bt)
                {
                    min_bt = pt[i];
                    shortest = i;
                }
                if (pt[i] == min_bt)
                {
                    if (at[i] < at[shortest])
                    {
                        shortest = i;
                    }
                }
            }
        }

        if (shortest == -1)
        {
            currentTime++;
        }
        else
        {
            ct[shortest] = currentTime + pt[shortest];
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - pt[shortest];
            complete[shortest] = 1;
            completed++;
            currentTime = ct[shortest];
        }
    }

    for (int i = 0; i < n; i++)
    {
        atat += tat[i];
        awt += wt[i];
    }

    atat = atat / n;
    awt = awt / n;

    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\n", i, tat[i], wt[i]);
    }

    printf("\nAverage TAT = %f\nAverage WT = %f\n", atat, awt);
}

void main()
{
    int op = 1, x;
    printf("1.FCFS \n2.SJF \n3.SRTF\n");
    scanf("%d", &x);
    switch (x)
    {
    case 1:
        fcfs();
        break;
    case 2:
        sjf();
        break;

    case 3:
        srtf();
        break;

    default:
        printf("Invalid option \n");
    }
}
