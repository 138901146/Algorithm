#include<stdio.h>
#include<stdbool.h>

void DFS(bool **graph,bool *visited,int source,int N)
{
	visited[source]=true;
	for(int i=0;i<N;i++)
		if(!visited[i] && graph[source][i])
		{
			printf(" %d", i+1);
			DFS(graph,visited,i,N);
		}
}

void BFS(bool **graph,bool *visited,int source,int N)
{
	int *queue=(int *)malloc(N*sizeof(int)), front=0, rear=0;
	visited[source]=true;
	queue[rear++]=source;
	while(front<rear)
	{
		for(int i=0;i<N;i++)
			if(!visited[i] && graph[queue[front]][i])
			{
				queue[rear++]=i;
				visited[i]=true;
			}
		front++;
	}
	for(int i=0;i<rear;i++)
		printf("%d ", queue[i]+1);
	printf("\n");
	free(queue);
}

int main(void)
{
	int N, M, V, x, y;
	bool **graph=NULL, *visited=NULL;

	scanf("%d%d%d", &N, &M, &V);
	graph=(bool **)malloc(N*sizeof(bool *));
	for(int n=0;n<N;n++)
		graph[n]=(bool *)calloc(N,sizeof(bool));
	visited=(bool *)calloc(N,sizeof(bool));

	for(int m=0;m<M;m++)
	{
		scanf("%d%d", &x, &y);
		x--;
		y--;

		graph[x][y]=graph[y][x]=true;
	}

	V--;
	printf("%d", V+1);
	DFS(graph,visited,V,N);
	printf("\n");
	free(visited);
	visited=(bool *)calloc(N,sizeof(bool));

	BFS(graph,visited,V,N);

	free(visited);
	for(int n=0;n<N;n++)
		free(graph[n]);
	free(graph);
	return 0;
}