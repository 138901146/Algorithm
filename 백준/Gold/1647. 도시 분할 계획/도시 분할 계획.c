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
	int N, M, left, sum=0;
	edge *road=NULL;

	scanf("%d%d", &N, &M);
	road=(edge *)malloc(M*sizeof(edge));
	parent=(int *)malloc((N+1)*sizeof(int));
	left=N-2;

	for(int m=0;m<M;++m)
		scanf("%d%d%d", &road[m].A, &road[m].B, &road[m].C);
	qsort((void *)road,(size_t)M,sizeof(edge),compare);

	for(int n=1;n<=N;++n)
		parent[n]=n;

	for(int m=0;m<M&&left;++m)
	{
		if(find_parent(road[m].A) == find_parent(road[m].B))
			continue;

		union_parent(road[m].A,road[m].B);
		--left;
		sum+=road[m].C;
	}

	printf("%d", sum);
	free(road);
	free(parent);
	return 0;
}