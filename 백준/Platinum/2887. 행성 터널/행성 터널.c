#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int index, value;
}
node;

typedef struct
{
	int A, B, distance;
}
edge;

int node_compare(const void *x,const void *y)
{
	return ((node *)x)->value>((node *)y)->value?1:-1;
}

int edge_compare(const void *x,const void *y)
{
	return ((edge *)x)->distance>((edge *)y)->distance?1:-1;
}

int *parent=NULL;

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
}

int union_set(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x==parent_y)
		return 0;

	parent[parent_y]=parent_x;
	return 1;
}

int main(void)
{
	int N, count=0;
	long long cost=0;
	node *x=NULL, *y=NULL, *z=NULL;
	edge *tunnel=NULL;

	scanf("%d", &N);
	x=(node *)malloc(N*sizeof(node));
	y=(node *)malloc(N*sizeof(node));
	z=(node *)malloc(N*sizeof(node));
	tunnel=(edge *)malloc((N-1)*3*sizeof(edge));
	parent=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
	{
		scanf("%d%d%d", &x[n].value, &y[n].value, &z[n].value);
		parent[n]=x[n].index=y[n].index=z[n].index=n;
	}

	qsort((void *)x,(size_t)N,sizeof(node),node_compare);
	qsort((void *)y,(size_t)N,sizeof(node),node_compare);
	qsort((void *)z,(size_t)N,sizeof(node),node_compare);

	for(int n=1;n<N;++n,++count)
	{
		tunnel[count].A=x[n-1].index;
		tunnel[count].B=x[n].index;
		tunnel[count].distance=x[n].value-x[n-1].value;
	}
	for(int n=1;n<N;++n,++count)
	{
		tunnel[count].A=y[n-1].index;
		tunnel[count].B=y[n].index;
		tunnel[count].distance=y[n].value-y[n-1].value;
	}
	for(int n=1;n<N;++n,++count)
	{
		tunnel[count].A=z[n-1].index;
		tunnel[count].B=z[n].index;
		tunnel[count].distance=z[n].value-z[n-1].value;
	}

	qsort((void *)tunnel,(size_t)count,sizeof(edge),edge_compare);
	count=N-1;

	for(int i=0;i<(N-1)*3 && count;++i)
		if(union_set(tunnel[i].A,tunnel[i].B))
			cost+=tunnel[i].distance;

	printf("%lld", cost);
	free(x);
	free(y);
	free(z);
	free(tunnel);
	free(parent);
	return 0;
}