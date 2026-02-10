#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int i, j, length;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->length<((edge *)y)->length?-1:1;
}

int *parent=NULL;

int find_parent(int current)
{
	if(parent[current]==current)
		return current;

	return parent[current]=find_parent(parent[current]);
}

int union_parent(int x,int y)
{
	int parent_x=find_parent(x), parent_y=find_parent(y);

	if(parent_x==parent_y)		return 0;


	parent[parent_y]=parent_x;

	return 1;
}

int main(void)
{
	int P, R;

	scanf("%d", &P);

	while(P)
	{
		int total=0, done=0;
		edge *data=NULL;

		scanf("%d", &R);

		data=(edge *)malloc(R*sizeof(edge));
		parent=(int *)malloc((P+1)*sizeof(int));

		for(int i=0;i<R;++i)
			scanf("%d%d%d", &data[i].i, &data[i].j, &data[i].length);

		for(int i=0;i<=P;++i)
			parent[i]=i;

		qsort((void *)data,(size_t)R,sizeof(edge),compare);

		for(int i=0;i<R&&done<P-1;++i)
			if(union_parent(data[i].i,data[i].j))
			{
				++done;
				total+=data[i].length;
			}

		free(parent);
		free(data);
		printf("%d\n", total);
		scanf("%d", &P);
	}

	return 0;
}