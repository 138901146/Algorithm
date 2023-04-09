#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main(void)
{
	int N, X, *queue=NULL, count=-1, front=0, rear=0, *previous=NULL, *route=NULL;
	bool *visited=NULL;

	scanf("%d", &N);
	if(N==1)
	{
		printf("0\n1\n");
		return 0;
	}
	previous=(int *)malloc((N+1)*sizeof(int));
	visited=(bool *)calloc(N+1,sizeof(bool));
	queue=(int *)malloc(N*sizeof(int));

	queue[rear++]=N;

	while(front<rear)
	{
		if(queue[front]==1)
			break;
		if(queue[front]%3==0 && !visited[queue[front]/3])
		{
			visited[queue[front]/3]=true;
			previous[queue[front]/3]=queue[front];
			queue[rear++]=queue[front]/3;
		}
		if(queue[front]%2==0 && !visited[queue[front]/2])
		{
			visited[queue[front]/2]=true;
			previous[queue[front]/2]=queue[front];
			queue[rear++]=queue[front]/2;
		}
		if(queue[front]>1 && !visited[queue[front]-1])
		{
			visited[queue[front]-1]=true;
			previous[queue[front]-1]=queue[front];
			queue[rear++]=queue[front]-1;
		}
		front++;
	}

	count=0;
	X=1;
	route=(int *)malloc(rear*sizeof(int));
	while(X!=N)
	{
		route[count++]=X;
		X=previous[X];
	}
	printf("%d\n%d", count, N);
	for(int i=count-1;i>=0;i--)
		printf(" %d", route[i]);
	printf("\n");
	free(route);
	free(visited);
	free(queue);
	free(previous);
	return 0;
}