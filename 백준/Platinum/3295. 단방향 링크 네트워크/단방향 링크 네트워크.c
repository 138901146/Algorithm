#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

typedef struct
{
	int u, v;
}
edge;

bool *visited=NULL;
int n, **adjacent_list=NULL, *adjacent_list_size=NULL, *occupied=NULL;

bool dfs(int current)
{
	for(int i=0;i<adjacent_list_size[current];++i)
	{
		int next=adjacent_list[current][i];

		if(!visited[next])
		{
			visited[next]=true;

			if(occupied[next]==-1 || dfs(occupied[next]))
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
	int T;

	scanf("%d", &T);

	while(T--)
	{
		int m, count=0;
		edge *link=NULL;

		scanf("%d%d", &n, &m);
		adjacent_list=(int **)malloc(n*sizeof(int *));
		adjacent_list_size=(int *)calloc(n,sizeof(int));
		link=(edge *)malloc(m*sizeof(edge));
		occupied=(int *)malloc(n*sizeof(int));

		for(int i=0;i<m;++i)
		{
			scanf("%d%d", &link[i].u, &link[i].v);
			++adjacent_list_size[link[i].u];
		}

		for(int i=0;i<n;++i)
		{
			adjacent_list[i]=(int *)malloc(adjacent_list_size[i]*sizeof(int));
			adjacent_list_size[i]=0;
			occupied[i]=-1;
		}

		for(int i=0;i<m;++i)
			adjacent_list[link[i].u][adjacent_list_size[link[i].u]++]=link[i].v;

		free(link);

		visited=(bool *)malloc(n*sizeof(bool));

		for(int i=0;i<n;++i)
		{
			for(int j=0;j<n;++j)
				visited[j]=false;

			count+=dfs(i);
		}

		printf("%d\n", count);
		for(int i=0;i<n;++i)
			free(adjacent_list[i]);
		free(adjacent_list);
		free(adjacent_list_size);
		free(occupied);
		free(visited);
	}

	return 0;
}