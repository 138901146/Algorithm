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

void union_parent(int node1,int node2)
{
	parent[node1]=find_parent(node2);
}

int main(void)
{
	int V, E, cost=0;
	edge *list=NULL;

	scanf("%d%d", &V, &E);
	list=(edge *)malloc(E*sizeof(edge));
	parent=(int *)malloc((V+1)*sizeof(int));

	for(int v=1;v<=V;++v)
		parent[v]=v;

	for(int e=0;e<E;++e)
		scanf("%d%d%d", &list[e].A, &list[e].B, &list[e].C);
	qsort((void *)list,(size_t)E,sizeof(edge),compare);

	while(E--)
	{
		int node1=find_parent(list[E].A), node2=find_parent(list[E].B);

		if(node1!=node2)
		{
			union_parent(node1,node2);
			cost+=list[E].C;
		}
	}

	printf("%d", cost);
	free(list);
	return 0;
}