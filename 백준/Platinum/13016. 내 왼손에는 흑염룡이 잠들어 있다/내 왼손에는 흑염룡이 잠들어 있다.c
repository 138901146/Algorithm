#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int to, length;
}
edge;

int origin, target=0, *edge_count=NULL;
edge **from=NULL;

void DFS(int current,int *distance)
{
	target=distance[current]>distance[target]?current:target;

	for(int i=0;i<edge_count[current];i++)
		if(from[current][i].to!=origin && !distance[from[current][i].to])
		{
			distance[from[current][i].to]=distance[current]+from[current][i].length;
			DFS(from[current][i].to,distance);
		}
}

int main(void)
{
	int N, **road=NULL, *primary=NULL, *secondary=NULL;

	scanf("%d", &N);
	from=(edge **)malloc((N+1)*sizeof(edge *));
	edge_count=(int *)calloc(N+1,sizeof(int));
	road=(int **)malloc((N-1)*sizeof(int *));

	for(int n=0;n<N-1;n++)
	{
		road[n]=(int *)malloc(3*sizeof(int));
		for(int i=0;i<2;i++)
		{
			scanf("%d", &road[n][i]);
			edge_count[road[n][i]]++;
		}
		scanf("%d", &road[n][2]);
	}

	for(int n=1;n<=N;n++)
	{
		from[n]=(edge *)malloc(edge_count[n]*sizeof(edge));
		edge_count[n]=0;
	}

	for(int n=0;n<N-1;n++)
	{
		from[road[n][0]][edge_count[road[n][0]]].to=road[n][1];
		from[road[n][0]][edge_count[road[n][0]]++].length=road[n][2];
		from[road[n][1]][edge_count[road[n][1]]].to=road[n][0];
		from[road[n][1]][edge_count[road[n][1]]++].length=road[n][2];
		free(road[n]);
	}
	free(road);

	primary=(int *)calloc(N+1,sizeof(int));
	secondary=(int *)calloc(N+1,sizeof(int));
	origin=1;
	DFS(1,primary);
	origin=target;
	free(primary);
	primary=(int *)calloc(N+1,sizeof(int));
	DFS(target,primary);
	origin=target;
	DFS(target,secondary);

	for(int n=1;n<=N;n++)
	{
		printf("%d\n", primary[n]>secondary[n]?primary[n]:secondary[n]);
		free(from[n]);
	}
	free(from);
	free(primary);
	free(secondary);
	free(edge_count);
	return 0;
}