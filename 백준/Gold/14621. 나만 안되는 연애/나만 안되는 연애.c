#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int u, v, d;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->d<((edge *)y)->d?-1:1;
}

int *parent=NULL;

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
}

void union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x!=parent_y)
		parent[parent_y]=parent_x;
}

int main(void)
{
	int N, M, left, sum=0, *type=NULL;
	edge *road=NULL;

	scanf("%d%d", &N, &M);
	road=(edge *)malloc(M*sizeof(edge));
	type=(int *)malloc((N+1)*sizeof(int));
	left=N-1;

	for(int n=1;n<=N;++n)
	{
		getchar();
		type[n]=getchar()=='M';
	}

	for(int m=0;m<M;++m)
	{
		scanf("%d%d%d", &road[m].u, &road[m].v, &road[m].d);
		if(type[road[m].u]==type[road[m].v])
		{
			--m;
			--M;
		}
	}
	free(type);
	qsort((void *)road,(size_t)M,sizeof(edge),compare);

	parent=(int *)malloc((N+1)*sizeof(int));
	for(int n=1;n<=N;++n)
		parent[n]=n;

	for(int m=0;m<M&&left;++m)
	{
		if(find_parent(road[m].u) == find_parent(road[m].v))
			continue;

		union_parent(road[m].u,road[m].v);
		--left;
		sum+=road[m].d;
	}

	printf("%d", left?-1:sum);
	free(road);
	free(parent);
	return 0;
}