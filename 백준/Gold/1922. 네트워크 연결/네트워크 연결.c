#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int a, b, c;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->c<((edge *)y)->c?-1:1;
}

int *root=NULL;

int find_root(int current)
{
	if(root[current]==current)
		return current;

	return root[current]=find_root(root[current]);
}

void union_root(int x,int y)
{
	int root_x=find_root(x), root_y=find_root(y);

	if(root_x!=root_y)
		root[root_y]=root_x;
}

int main(void)
{
	int N, M, left, cost=0;
	edge *line=NULL;

	scanf("%d", &N);
	scanf("%d", &M);
	line=(edge *)malloc(M*sizeof(edge));
	root=(int *)malloc((N+1)*sizeof(int));
	left=N-1;

	for(int m=0;m<M;++m)
		scanf("%d%d%d", &line[m].a, &line[m].b, &line[m].c);
	qsort((void *)line,(size_t)M,sizeof(edge),compare);

	for(int n=1;n<=N;++n)
		root[n]=n;

	for(int m=0;m<M&&left;++m)
	{
		if(find_root(line[m].a) == find_root(line[m].b))
			continue;

		union_root(line[m].a,line[m].b);
		--left;
		cost+=line[m].c;
	}

	printf("%d", cost);
	free(line);
	free(root);
	return 0;
}