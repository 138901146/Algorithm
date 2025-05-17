#include<stdio.h>
#include<malloc.h>
#include<memory.h>

int min[100001], queue[100001];

int main(void)
{
	int A, B, N, M, front=0, rear=1;

	scanf("%d%d%d%d", &A, &B, &N, &M);

	memset(min,-1,100001*sizeof(int));

	min[N]=0;
	queue[0]=N;

	while(front<rear && min[M]==-1)
	{
		if(0<queue[front] && min[queue[front]-1]==-1)
		{
			min[queue[front]-1]=min[queue[front]]+1;
			queue[rear++]=queue[front]-1;
		}

		if(queue[front]<100000 && min[queue[front]+1]==-1)
		{
			min[queue[front]+1]=min[queue[front]]+1;
			queue[rear++]=queue[front]+1;
		}

		if(A<=queue[front] && min[queue[front]-A]==-1)
		{
			min[queue[front]-A]=min[queue[front]]+1;
			queue[rear++]=queue[front]-A;
		}

		if(queue[front]+A<=100000 && min[queue[front]+A]==-1)
		{
			min[queue[front]+A]=min[queue[front]]+1;
			queue[rear++]=queue[front]+A;
		}

		if(B<=queue[front] && min[queue[front]-B]==-1)
		{
			min[queue[front]-B]=min[queue[front]]+1;
			queue[rear++]=queue[front]-B;
		}

		if(queue[front]+B<=100000 && min[queue[front]+B]==-1)
		{
			min[queue[front]+B]=min[queue[front]]+1;
			queue[rear++]=queue[front]+B;
		}

		if((long long)queue[front]*A<=100000 && min[queue[front]*A]==-1)
		{
			min[queue[front]*A]=min[queue[front]]+1;
			queue[rear++]=queue[front]*A;
		}

		if((long long)queue[front]*B<=100000 && min[queue[front]*B]==-1)
		{
			min[queue[front]*B]=min[queue[front]]+1;
			queue[rear++]=queue[front]*B;
		}

		++front;
	}

	printf("%d", min[M]);
	return 0;
}