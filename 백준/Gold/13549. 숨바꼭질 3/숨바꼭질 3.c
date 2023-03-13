#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, K, *queue=malloc(100002*sizeof(int)), front=0, rear=0, count=0;
	bool *visited=calloc(100002,sizeof(bool));

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
				visited[queue[front]-1]=true;
				queue[rear++]=queue[front]-1;
			}
			if(queue[front]<100001 && !visited[queue[front]+1])
			{
				visited[queue[front]+1]=true;
				queue[rear++]=queue[front]+1;
			}
			if(queue[front]*2<100002 && queue[front]>0)
			{
				visited[queue[front]*2]=true;
				queue[front]=queue[front]*2;
				if(queue[front]==K)
				{
					count--;
					break;
				}
				continue;
			}
			front++;
		}
		count++;
	}

	printf("%d\n", count);
	free(visited);
	free(queue);
	return 0;
}