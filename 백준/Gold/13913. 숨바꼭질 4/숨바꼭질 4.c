#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, *queue=malloc(100002*sizeof(int)), *last=malloc(100002*sizeof(int)), count=0, front=0, rear=0;

	scanf("%d%d", &N, &K);
	int temp=N;
	N=K;
	K=temp;

	for(int i=0;i<100002;i++)
		last[i]=-1;

	queue[rear++]=N;
	last[N]=N;

	while(front<rear && last[K]==-1)
	{
		int previous_rear=rear;
		while(front<previous_rear)
		{
			if(queue[front]>0 && last[queue[front]-1]==-1)
			{
				queue[rear++]=queue[front]-1;
				last[queue[front]-1]=queue[front];
			}
			if(queue[front]<100000 && last[queue[front]+1]==-1)
			{
				queue[rear++]=queue[front]+1;
				last[queue[front]+1]=queue[front];
			}
			if(queue[front]%2==0 && queue[front]>0 && last[queue[front]/2]==-1)
			{
				queue[rear++]=queue[front]/2;
				last[queue[front]/2]=queue[front];
			}
			front++;
		}
		count++;
	}

	printf("%d\n", count);
	while(last[K]!=K)
	{
		printf("%d ", K);
		K=last[K];
	}
	printf("%d\n", N);
	free(last);
	free(queue);
	return 0;
}