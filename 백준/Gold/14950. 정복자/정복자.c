#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int A, B, C;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->C<((edge *)y)->C?-1:1;
}

int *parent=NULL;

int _find(int x)
{
	if(parent[x]==x)
		return x;

	return parent[x]=_find(parent[x]);
}

int _union(int x,int y)
{
	int parent_x=_find(x), parent_y=_find(y);

	if(parent_x==parent_y)
		return 0;

	parent[parent_y]=parent_x;

	return 1;
}

int main(void)
{
	int N, M, t, count=0;
	long long total=0;
	edge *road=NULL;

	scanf("%d%d%d", &N, &M, &t);
	road=(edge *)malloc(M*sizeof(edge));
	for(int i=0;i<M;++i)
		scanf("%d%d%d", &road[i].A, &road[i].B, &road[i].C);
	qsort((void *)road,(size_t)M,sizeof(edge),compare);

	parent=(int *)calloc(N+1,sizeof(int));
	for(int i=1;i<=N;++i)
		parent[i]=i;

	for(int i=0;i<M&&count<N-1;++i)
		if(_union(road[i].A,road[i].B))
			total+=(long long)count++*t+road[i].C;

	printf("%lld", total);
	free(road);
	free(parent);
	return 0;
}