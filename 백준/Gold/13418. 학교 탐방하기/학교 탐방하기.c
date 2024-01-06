#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int A, B, C;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->C>((edge *)y)->C?-1:1;
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
	int N, M, count, primary=0, secondary=0;
	edge *road=NULL;

	scanf("%d%d", &N, &M);
	parent=(int *)malloc((N+1)*sizeof(int));
	road=(edge *)malloc((M+1)*sizeof(edge));

	for(int i=0;i<=M;++i)
	{
		scanf("%d%d%d", &road[i].A, &road[i].B, &road[i].C);
		road[i].C^=1;
	}

	qsort((void *)road,(size_t)M+1,sizeof(edge),compare);

	for(int i=0;i<=N;++i)
		parent[i]=i;

	count=N;
	for(int i=0;i<=M && count;++i)
		if(find_parent(road[i].A)!=find_parent(road[i].B))
		{
			primary+=road[i].C;
			union_parent(road[i].A,road[i].B);
			--count;
		}

	for(int i=0;i<=N;++i)
		parent[i]=i;

	count=N;
	for(int i=M;i>=0 && count;--i)
		if(find_parent(road[i].A)!=find_parent(road[i].B))
		{
			secondary+=road[i].C;
			union_parent(road[i].A,road[i].B);
			--count;
		}

	printf("%d", primary*primary-secondary*secondary);
	free(road);
	free(parent);
	return 0;
}