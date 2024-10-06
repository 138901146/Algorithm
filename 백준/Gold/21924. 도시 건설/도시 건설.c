#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a, b, c;
}
edge;

int *parent=NULL;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->c<((edge *)y)->c?1:-1;
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
	int N, M, connected=1;
	long long cost=0, total=0;
	edge *road=NULL;

	scanf("%d%d", &N, &M);
	road=(edge *)malloc(M*sizeof(edge));
	parent=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;++n)
		parent[n]=n;

	for(int m=0;m<M;++m)
		scanf("%d%d%d", &road[m].a, &road[m].b, &road[m].c);
	qsort((void *)road,(size_t)M,sizeof(edge),compare);

	while(M--)
	{
		int node1=find_parent(road[M].a), node2=find_parent(road[M].b);

		if(node1!=node2)
		{
			union_parent(node1,node2);
			cost+=road[M].c;
			++connected;
		}

		total+=road[M].c;
	}

	printf("%lld", connected==N?total-cost:-1);
	free(road);
	free(parent);
	return 0;
}