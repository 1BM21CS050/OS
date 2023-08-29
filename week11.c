#include<stdio.h>
#include<stdlib.h>
int disks;
void quicksort(int number[25], int first, int last)
{
    int i, j, pivot, temp;
    if (first < last)
    {
    	pivot = first;
    	i = first;
    	j = last;
    	while (i < j)
    	{
        	while (number[i] <= number[pivot] && i < last)
            	i++;
        	while (number[j] > number[pivot])
            	j--;
        	if (i < j)
        	{
            	temp = number[i];
            	number[i] = number[j];
            	number[j] = temp;
        	}
    	}
    	temp = number[pivot];
    	number[pivot] = number[j];
    	number[j] = temp;
    	quicksort(number, first, j - 1);
    	quicksort(number, j + 1, last);
    }
}
void fcfs(int arr[],int src, int n)
{
    int sseq[20],i;
    sseq[0]=abs(arr[0]-src);
    for(i=1;i<n;i++)
    sseq[i]=abs(arr[i]-arr[i-1]);
    int sum=0;
    for(i=0;i<n;i++)
    sum+=sseq[i];
    printf("\nFCFS \nTotal seek sequenece: %d \nSeek Sequence: \n",sum);
    for(i=0;i<n;i++)
    printf("%d ",sseq[i]);
    printf("\n");
}
void cscan(int arr[], int src, int n)
{
    int i,sum=0,j,sseq[20];
    quicksort(arr, 0, n-1);
    int index;
    for (index = 0; index < n; index++) {
    	if (arr[index] == src) {
        	break;
    	}
    }
    i=index+1;
    j=0;
    while(i<=n)
    {
    	sseq[j]=abs(arr[i]-arr[i-1]);
    	i++;
    	j++;
    }
    sseq[j++]=abs(disks-arr[i-1]);
    i=0;
    sseq[j++]=abs(disks);
    while(i<index)
    {
    	sseq[j++]=abs(arr[i]-arr[i-1]);
    	i++;
    }
    for(i=0;i<(n+2);i++)
    sum+=sseq[i];
    printf("\nC-SCAN \nTotal seek sequenece: %d \nSeek Sequence: \n",sum);
    for(i=0;i<n+2;i++)
    printf("%d ",sseq[i]);
    printf("\n");
}
void scan(int arr[], int src, int n)
{
    int i,sum=0,j,sseq[20];
    quicksort(arr, 0, n-1);
    int index;
    for (index = 0; index < n; index++) {
    	if (arr[index] == src) {
        	break;
    	}
    }
    i=index-1;
    j=0;
    while(i>=0)
    {
    	sseq[j]=abs(arr[i]-arr[i+1]);
    	i--;
    	j++;
    }
    i=index+1;
    sseq[j++]=abs(arr[i++]-arr[0]);
    while(i<=n)
    {
    	sseq[j++]=abs(arr[i]-arr[i-1]);
    	i++;
    }
    for(i=0;i<n;i++)
    sum+=sseq[i];
    printf("\nSCAN \nTotal seek sequenece: %d \nSeek Sequence: \n",sum);
    for(i=0;i<n;i++)
    printf("%d ",sseq[i]);
    printf("\n");
}
void main()
{
    int source, arr[20],i,n,copy[20];
    printf("Enter numebr of disks: ");
    scanf("%d",&n);
    printf("\nEnter %d values: ",n);
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    printf("\nEnter source position: ");
    scanf("%d",&source);
    printf("\nEnter number disks: ");
    scanf("%d",&disks);
    for(i=0;i<n;i++)
    copy[i]=arr[i];
    arr[n]=source;
    copy[n]=arr[n];
    fcfs(copy , source , n);
    scan(copy , source , n);
    cscan(arr , source , n);
}

