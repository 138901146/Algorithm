#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>

int main(void)
{
	int n, *A=NULL, *queue=NULL, front=0, rear=1;
	bool *visited=NULL;

	scanf("%d", &n);
	A=(int *)calloc(n+1,sizeof(int));
	visited=(bool *)calloc(n+1,sizeof(bool));
	queue=(int *)malloc(n*sizeof(int));

	for(int i=1;i<=n;++i)
		scanf("%d", &A[i]);
	scanf("%d", &queue[0]);
	visited[queue[0]]=true;

	while(front<rear)
	{
		int current=queue[front++];

		if(0<current-A[current]&&!visited[current-A[current]])
		{
			visited[current-A[current]]=true;
			queue[rear++]=current-A[current];
		}

		if(current+A[current]<=n&&!visited[current+A[current]])
		{
			visited[current+A[current]]=true;
			queue[rear++]=current+A[current];
		}
	}

	printf("%d", rear);
	free(visited);
	free(queue);
	free(A);
	return 0;
}