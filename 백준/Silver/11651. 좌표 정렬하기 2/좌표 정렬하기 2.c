#include<stdio.h>
#include<stdlib.h>

int xtemp[100000], ytemp[100000];
void merge(int *x,int *y,int start,int end,int mid,int N)
{
	int i=start, j=mid+1;

	for(int k=	start;k<=end;k++)
		if(j>end)
		{
			xtemp[k]=x[i];
			ytemp[k]=y[i];
			i++;
		}
		else if(i>mid)
		{
			xtemp[k]=x[j];
			ytemp[k]=y[j];
			j++;
		}
		else if(y[i]<y[j] || y[i]==y[j]&&x[i]<x[j])
		{
			xtemp[k]=x[i];
			ytemp[k]=y[i];
			i++;
		}
		else
		{
			xtemp[k]=x[j];
			ytemp[k]=y[j];
			j++;
		}

	for(int k=start;k<=end;k++)
	{
		x[k]=xtemp[k];
		y[k]=ytemp[k];
	}
}

void mergesort(int *x,int *y,int start,int end,int N)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		mergesort(x,y,start,mid,N);
		mergesort(x,y,mid+1,end,N);
		merge(x,y,start,end,mid,N);
	}
}

int main(void)
{
	int N, *x=NULL, *y=NULL;

	scanf("%d", &N);
	x=(int *)malloc(N*sizeof(int));
	y=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;n++)
		scanf("%d %d", &x[n], &y[n]);

	mergesort(x,y,0,N-1,N);

	for(int n=0;n<N;n++)
		printf("%d %d\n", x[n], y[n]);
	free(x);
	free(y);
	return 0;
}