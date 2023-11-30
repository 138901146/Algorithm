#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

int *vertex_count=NULL, **vertex=NULL, *parent=NULL;

bool match_parent(int current)
{
	bool flag=true;

	for(int i=0;flag&&i<vertex_count[current];++i)
		if(parent[vertex[current][i]]==-1)
		{
			parent[vertex[current][i]]=parent[current]^1;
			flag&=match_parent(vertex[current][i]);
		}
		else if(parent[vertex[current][i]]==parent[current])
			return false;

	return flag;
}

int main(void)
{
	int K;

	scanf("%d", &K);

	while(K--)
	{
		int V, E, **edge=NULL;
		bool flag=true;

		scanf("%d%d", &V, &E);
		vertex=(int **)malloc((V+1)*sizeof(int *));
		vertex_count=(int *)calloc(V+1,sizeof(int));
		edge=(int **)malloc(E*sizeof(int *));

		for(int e=0;e<E;++e)
		{
			edge[e]=(int *)malloc(2*sizeof(int));

			for(int i=0;i<2;++i)
			{
				scanf("%d", &edge[e][i]);
				++vertex_count[edge[e][i]];
			}
		}

		for(int v=1;v<=V;++v)
		{
			vertex[v]=(int *)malloc(vertex_count[v]*sizeof(int));
			vertex_count[v]=0;
		}

		for(int e=0;e<E;++e)
		{
			for(int i=0;i<2;++i)
				vertex[edge[e][i]][vertex_count[edge[e][i]]++]=edge[e][i^1];
			free(edge[e]);
		}
		free(edge);

		parent=(int *)malloc((V+1)*sizeof(int));
		for(int v=1;v<=V;++v)
			parent[v]=-1;

		for(int v=1;flag&&v<=V;++v)
			if(parent[v]==-1)
			{
				parent[v]=0;
				flag&=match_parent(v);
			}

		printf("%s\n", flag?"YES":"NO");
		for(int v=1;v<=V;++v)
			free(vertex[v]);
		free(vertex);
		free(vertex_count);
		free(parent);
	}

	return 0;
}