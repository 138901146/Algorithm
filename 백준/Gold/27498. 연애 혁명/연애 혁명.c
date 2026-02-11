#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a, b, c;
}
love;

int *parent=NULL;

int compare(const void *x,const void *y)
{
	return ((love *)x)->c<((love *)y)->c?1:-1;
}

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
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
	int N, M, d, count=0, total=0;
	love *relation=NULL;

	scanf("%d%d", &N, &M);

	relation=(love *)malloc(M*sizeof(love));
	parent=(int *)malloc((N+1)*sizeof(int));

	for(int i=0;i<=N;++i)
		parent[i]=i;

	for(int i=0;i<M;++i)
	{
		scanf("%d%d%d%d", &relation[i].a, &relation[i].b, &relation[i].c, &d);

		if(d)
		{
			++count;
			union_parent(relation[i].a,relation[i].b);
			--i;
			--M;
		}
		else
			total+=relation[i].c;
	}

	qsort((void *)relation,(size_t)M,sizeof(love),compare);

	for(int i=0;i<M&&count<N-1;++i)
		if(union_parent(relation[i].a,relation[i].b))
		{
			++count;
			total-=relation[i].c;
		}

	printf("%d", total);
	free(relation);
	free(parent);
	return 0;
}