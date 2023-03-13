#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, K, *queue=malloc(100002*sizeof(int)), count=0, front=0, rear=0;
	bool *visited=(bool *)calloc(100002,sizeof(bool));

	scanf("%d%d", &N, &K);

	queue[rear++]=N;
	visited[N]=true;

	while(front<rear && !visited[K])
	{
		int previous_rear=rear;
		while(front<previous_rear)
		{
			if(queue[front]>0 && !visited[queue[front]-1])
			{
				queue[rear++]=queue[front]-1;
				visited[queue[front]-1]=true;
			}
			if(queue[front]<100001 && !visited[queue[front]+1])
			{
				queue[rear++]=queue[front]+1;
				visited[queue[front]+1]=true;
			}
			if(queue[front]*2<100002 && !visited[queue[front]*2])
			{
				queue[rear++]=queue[front]*2;
				visited[queue[front]*2]=true;
			}
			front++;
		}
		count++;
	}

	printf("%d\n", count);
	free(queue);
	free(visited);
	return 0;
}