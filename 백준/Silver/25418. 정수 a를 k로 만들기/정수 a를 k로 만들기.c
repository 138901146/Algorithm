#include<stdio.h>

int min[1000001]={0}, queue[900000];

int main(void)
{
	int A, K, front=0, rear=1;

	scanf("%d%d", &A, &K);

	min[A]=1;
	queue[0]=A;

	while(!min[K])
	{
		if(queue[front]+1<=K&&!min[queue[front]+1])
		{
			min[queue[front]+1]=min[queue[front]]+1;
			queue[rear++]=queue[front]+1;
		}

		if((queue[front]<<1)<=K&&!min[queue[front]<<1])
		{
			min[queue[front]<<1]=min[queue[front]]+1;
			queue[rear++]=queue[front]<<1;
		}

		++front;
	}

	printf("%d", min[K]-1);
	return 0;
}