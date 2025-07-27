#include<stdio.h>
#include<malloc.h>

typedef struct
{
	int id, distance;
}
node;

typedef struct
{
	int u, v, distance;
}
edge;

int *adjacent_list_count=NULL, *depth=NULL;
node **adjacent_list=NULL, *parent=NULL;
edge *edge_list=NULL;

void make_tree(int vertex)
{
	for(int i=0;i<adjacent_list_count[vertex];++i)
		if(adjacent_list[vertex][i].id!=parent[vertex].id)
		{
			parent[adjacent_list[vertex][i].id].id=vertex;
			parent[adjacent_list[vertex][i].id].distance=adjacent_list[vertex][i].distance;
			depth[adjacent_list[vertex][i].id]=depth[vertex]+1;
			make_tree(adjacent_list[vertex][i].id);
		}
}

int main(void)
{
	int N, M, u, v, distance;

	scanf("%d%d", &N, &M);
	adjacent_list_count=(int *)calloc(N+1,sizeof(int));
	adjacent_list=(node **)malloc((N+1)*sizeof(node *));
	edge_list=(edge *)malloc((N-1)*sizeof(edge));

	for(int i=0;i<N-1;++i)
	{
		scanf("%d%d%d", &edge_list[i].u, &edge_list[i].v, &edge_list[i].distance);
		++adjacent_list_count[edge_list[i].u];
		++adjacent_list_count[edge_list[i].v];
	}

	for(int n=1;n<=N;++n)
	{
		adjacent_list[n]=(node *)malloc(adjacent_list_count[n]*sizeof(node));
		adjacent_list_count[n]=0;
	}

	for(int i=0;i<N-1;++i)
	{
		adjacent_list[edge_list[i].u][adjacent_list_count[edge_list[i].u]].id=edge_list[i].v;
		adjacent_list[edge_list[i].u][adjacent_list_count[edge_list[i].u]++].distance=edge_list[i].distance;
		adjacent_list[edge_list[i].v][adjacent_list_count[edge_list[i].v]].id=edge_list[i].u;
		adjacent_list[edge_list[i].v][adjacent_list_count[edge_list[i].v]++].distance=edge_list[i].distance;
	}
	free(edge_list);

	parent=(node *)calloc(N+1,sizeof(node));
	depth=(int *)calloc(N+1,sizeof(int));
	depth[1]=1;
	make_tree(1);

	while(M--)
	{
		distance=0;

		scanf("%d%d", &u, &v);

		while(depth[u]<depth[v])
		{
			distance+=parent[v].distance;
			v=parent[v].id;
		}

		while(depth[v]<depth[u])
		{
			distance+=parent[u].distance;
			u=parent[u].id;
		}

		while(u!=v)
		{
			distance+=parent[u].distance+parent[v].distance;
			u=parent[u].id;
			v=parent[v].id;
		}

		printf("%d\n", distance);
	}

	while(N)
		free(adjacent_list[N--]);
	free(adjacent_list);
	free(adjacent_list_count);
	free(depth);
	free(parent);
	return 0;
}