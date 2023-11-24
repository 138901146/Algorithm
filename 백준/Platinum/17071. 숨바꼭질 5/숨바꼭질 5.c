#include<stdio.h>

int queue[1000002], visited[2][500001];

int main(void)
{
	int N, K, time=0, front=0, rear=1, min=100000000;

	scanf("%d%d", &N, &K);

	for(int i=0;i<500001;++i)
		visited[0][i]=visited[1][i]=100000000;

	queue[0]=N;
	visited[0][N]=0;
	while(front<rear)
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			if(queue[front]>0 && visited[time&1^1][queue[front]-1]>time+1)
			{
				visited[time&1^1][queue[front]-1]=time+1;
				queue[rear++]=queue[front]-1;
			}

			if(queue[front]<500000 && visited[time&1^1][queue[front]+1]>time+1)
			{
				visited[time&1^1][queue[front]+1]=time+1;
				queue[rear++]=queue[front]+1;
			}

			if(queue[front]<=250000 && visited[time&1^1][queue[front]<<1]>time+1)
			{
				visited[time&1^1][queue[front]<<1]=time+1;
				queue[rear++]=queue[front]<<1;
			}

			++front;
		}

		++time;
	}

	time=0;
	while(K<=500000)
	{
		if(visited[time&1][K]<=time && time<min)
			min=time;

		K+=++time;
	}

	printf("%d", min==100000000?-1:min);
	return 0;
}