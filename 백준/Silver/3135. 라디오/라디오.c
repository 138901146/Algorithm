#include<stdio.h>

#define INF 9999

int main(void)
{
	int A, B, N, min[1000], queue[1000], front=0, rear=1, freq;

	for(int i=0;i<1000;++i)
		min[i]=INF;

	scanf("%d%d", &A, &B);
	scanf("%d", &N);

	min[A]=0;
	queue[0]=A;

	while(N--)
	{
		scanf("%d", &freq);

		if(freq==A)
			continue;
		min[freq]=1;
		queue[rear++]=freq;
	}

	while(min[B]==INF)
	{
		if(0<queue[front]&&min[queue[front]]+1<min[queue[front]-1])
		{
			min[queue[front]-1]=min[queue[front]]+1;
			queue[rear++]=queue[front]-1;
		}
		if(queue[front]<999&&min[queue[front]]+1<min[queue[front]+1])
		{
			min[queue[front]+1]=min[queue[front]]+1;
			queue[rear++]=queue[front]+1;
		}
		++front;
	}

	printf("%d", min[B]);
	return 0;
}