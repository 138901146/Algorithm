#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
#include<memory.h>

typedef struct
{
	int u, v;
}
edge;

int **adjacent_list=NULL, *adjacent_list_count=NULL, *occupied=NULL;
bool *visited=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_count[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(!occupied[next] || dfs(occupied[next]))
			{
				occupied[next]=current;
				return true;
			}
		}
	}

	return false;
}

int main(void)
{
	int N, M, count=0;
	edge *chain=NULL;

	scanf("%d%d", &N, &M);
	adjacent_list=(int **)malloc((N+1)*sizeof(int *));
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	chain=(edge *)malloc(M*sizeof(edge));

	for(int m=0;m<M;++m)
	{
		scanf("%d%d", &chain[m].u, &chain[m].v);
		++adjacent_list_count[chain[m].u];
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(int *)malloc(adjacent_list_count[n]*sizeof(int));
		adjacent_list_count[n]=0;
	}

	while(M--)
		adjacent_list[chain[M].u][adjacent_list_count[chain[M].u]++]=chain[M].v;
	free(chain);

	visited=(bool *)malloc((N+1)*sizeof(bool));
	occupied=(int *)calloc(N+1,sizeof(int));

	for(int n=1;n<=N;++n)
	{
		memset(visited,0,N+1);
		count+=dfs(n);
	}

	printf("%d", N-count);
	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(visited);
	free(occupied);
	return 0;
}