#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int A, B, C;
}
edge;

int *parent=NULL;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->C<((edge *)y)->C?1:-1;
}

int find_parent(int node)
{
	if(parent[node]==node)
		return node;
	return parent[node]=find_parent(parent[node]);
}

int union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x==parent_y)
		return 0;

	parent[parent_y]=parent_x;

	return 1;
}

int main(void)
{
	int N, M, cost=0, connected=0;
	edge *route=NULL;

	scanf("%d%d", &N, &M);
	route=(edge *)malloc(M*sizeof(edge));
	parent=(int *)calloc(N+1,sizeof(int));

	for(int i=0;i<M;++i)
		scanf("%d%d%d", &route[i].A, &route[i].B, &route[i].C);
	qsort((void *)route,(size_t)M,sizeof(edge),compare);

	for(int i=1;i<=N;++i)
		parent[i]=i;

	for(int i=0;i<M&&connected<N-1;++i)
		if(union_parent(route[i].A,route[i].B))
		{
			cost+=route[i].C;
			++connected;
		}

	printf("%d", connected==N-1?cost:-1);
	free(route);
	free(parent);
	return 0;
}