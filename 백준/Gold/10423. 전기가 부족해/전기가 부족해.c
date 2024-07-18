#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int u, v, w;
}
edge;

bool *YNY=NULL;
int *parent=NULL;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->w<((edge *)y)->w?1:-1;
}

int find_parent(int node)
{
	if(parent[node]==node)
		return node;
	return parent[node]=find_parent(parent[node]);
}

void union_parent(int p,int c)
{
	parent[c]=find_parent(p);
}

int main(void)
{
	int N, M, K, power_plant, cost=0;
	edge *cable=NULL;

	scanf("%d%d%d", &N, &M, &K);
	YNY=(bool *)calloc(N+1,sizeof(bool));
	cable=(edge *)malloc(M*sizeof(edge));
	parent=(int *)malloc((N+1)*sizeof(int));

	for(int n=1;n<=N;++n)
		parent[n]=n;

	while(K--)
	{
		scanf("%d", &power_plant);
		YNY[power_plant]=true;
	}

	for(int m=0;m<M;++m)
		scanf("%d%d%d", &cable[m].u, &cable[m].v, &cable[m].w);
	qsort((void *)cable,(size_t)M,sizeof(edge),compare);

	while(M--)
	{
		int node1=find_parent(cable[M].u), node2=find_parent(cable[M].v);

		if(node1==node2 || YNY[node1]&&YNY[node2])
			continue;
		else if(YNY[node1])
			union_parent(node1,node2);
		else
			union_parent(node2,node1);

		cost+=cable[M].w;
	}

	printf("%d", cost);
	free(cable);
	free(YNY);
	return 0;
}