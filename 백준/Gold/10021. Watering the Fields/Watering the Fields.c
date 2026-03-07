#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int i, j;
	long long cost;
}
node;

int compare(const void *x,const void *y)
{
	return ((node *)x)->cost<((node *)y)->cost?-1:1;
}

int *parent=NULL;

int find_parent(int x)
{
	if(parent[x]==x)
		return x;

	return parent[x]=find_parent(parent[x]);
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
	int N, C, *x=NULL, *y=NULL, edge_count=0, matched=0;
	long long total=0;
	node *edge=NULL;

	scanf("%d%d", &N, &C);

	x=(int *)malloc(N*sizeof(int));
	y=(int *)malloc(N*sizeof(int));
	edge=(node *)malloc(N*(N-1)*sizeof(node)>>1);

	for(int i=0;i<N;++i)
		scanf("%d%d", &x[i], &y[i]);

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
		{
			long long distance=(long long)(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);

			if(C<=distance)
			{
				edge[edge_count].i=i;
				edge[edge_count].j=j;
				edge[edge_count++].cost=distance;
			}
		}

	qsort((void *)edge,(size_t)edge_count,sizeof(node),compare);

	free(x);
	free(y);
	parent=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		parent[i]=i;

	for(int i=0;i<edge_count&&matched<N-1;++i)
		if(union_parent(edge[i].i,edge[i].j))
		{
			++matched;
			total+=edge[i].cost;
		}

	printf("%lld", matched==N-1?total:-1);
	free(parent);
	free(edge);
	return 0;
}