#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct
{
	int x, y, z;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->z>((edge *)y)->z?1:-1;
}

int *parent=NULL;

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
}

bool union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x==parent_y)
		return false;

	parent[parent_y]=parent_x;
	return true;
}

int main(void)
{
	int m, n;

	scanf("%d%d", &m, &n);

	while(m&&n)
	{
		int count, sum=0;
		edge *road=malloc(n*sizeof(edge));

		parent=(int *)malloc(m*sizeof(int));

		for(int i=0;i<n;++i)
		{
			scanf("%d%d%d", &road[i].x, &road[i].y, &road[i].z);
			sum+=road[i].z;
		}

		qsort((void *)road,(size_t)n,sizeof(edge),compare);

		for(int i=0;i<m;++i)
			parent[i]=i;

		count=m-1;
		for(int i=0;i<n && count;++i)
			if(union_parent(road[i].x,road[i].y))
			{
				sum-=road[i].z;
				--count;
			}

		printf("%d\n", sum);
		free(road);
		free(parent);

		scanf("%d%d", &m, &n);
	}

	return 0;
}