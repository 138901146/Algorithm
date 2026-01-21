#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int N, K, *queue=NULL, front=0, rear=1;
	bool *visited=NULL;

	scanf("%d%d", &N, &K);

	visited=(bool *)calloc(N+2,sizeof(bool));
	queue=(int *)calloc(N+2,sizeof(int));

	while(front<rear&&K--&&!visited[N])
	{
		int previous_rear=rear;

		while(front<previous_rear)
		{
			if(queue[front]+1<=N&&!visited[queue[front]+1])
			{
				visited[queue[front]+1]=true;
				queue[rear++]=queue[front]+1;
			}
			if(queue[front]+(queue[front]>>1)<=N&&!visited[queue[front]+(queue[front]>>1)])
			{
				visited[queue[front]+(queue[front]>>1)]=true;
				queue[rear++]=queue[front]+(queue[front]>>1);
			}

			if(visited[N])
			{
				printf("minigimbob");
				free(queue);
				free(visited);
				return 0;
			}
			++front;
		}
	}

	printf("water");
	free(queue);
	free(visited);
	return 0;
}