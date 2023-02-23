#include<stdio.h>
#include<stdlib.h>

int stemp[100000], etemp[100000];

void merge(int *start,int *end,int left,int right,int mid)
{
	int i=left, j=mid+1;

	for(int k=left;k<=right;k++)
		if(j>right)
		{
			stemp[k]=start[i];
			etemp[k]=end[i];
			i++;
		}
		else if(i>mid)
		{
			stemp[k]=start[j];
			etemp[k]=end[j];
			j++;
		}
		else if(end[i]<end[j] || end[i]==end[j] && start[i]<start[j])
		{
			stemp[k]=start[i];
			etemp[k]=end[i];
			i++;
		}
		else
		{
			stemp[k]=start[j];
			etemp[k]=end[j];
			j++;
		}

	for(int k=left;k<=right;k++)
	{
		start[k]=stemp[k];
		end[k]=etemp[k];
	}
}

void mergesort(int *start,int *end,int left,int right)
{
	if(left<right)
	{
		int mid=(left+right)/2;
		mergesort(start,end,left,mid);
		mergesort(start,end,mid+1,right);
		merge(start,end,left,right,mid);
	}
}

int main(void)
{
	int N, *start=NULL, *end=NULL, count=0, last=-1;

	scanf("%d", &N);
	start=(int *)malloc(N*sizeof(int));
	end=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d%d", &start[n], &end[n]);

	mergesort(start,end,0,N-1);

	for(int n=0;n<N;n++)
		if(start[n]>=last)
		{
			count++;
			last=end[n];
		}

	printf("%d\n", count);
	free(start);
	free(end);
	return 0;
}