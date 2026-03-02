#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int c1, c2, distance;
}
communicate;

typedef struct
{
	int x, y;
}
location;

int compare(const void *x,const void *y)
{
	return ((communicate *)x)->distance<((communicate *)y)->distance?-1:1;
}

int *parent=NULL;

int find_parent(int x)
{
	if(x==parent[x])
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
	int N, count=0, matched=0;
	location *cow=NULL;
	communicate *band=NULL;

	scanf("%d", &N);

	if(N==1)
	{
		printf("0");
		return 0;
	}

	cow=(location *)malloc(N*sizeof(location));

	for(int i=0;i<N;++i)
		scanf("%d%d", &cow[i].x, &cow[i].y);

	band=(communicate *)malloc((N*(N-1)>>1)*sizeof(communicate));

	for(int i=0;i<N;++i)
		for(int j=i+1;j<N;++j)
		{
			band[count].c1=i;
			band[count].c2=j;
			band[count++].distance=(cow[i].x-cow[j].x)*(cow[i].x-cow[j].x)+(cow[i].y-cow[j].y)*(cow[i].y-cow[j].y);
		}

	qsort((void *)band,(size_t)count,sizeof(communicate),compare);

	free(cow);
	parent=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		parent[i]=i;

	for(count=0;matched<N-1;++count)
		matched+=union_parent(band[count].c1,band[count].c2);

	printf("%d", band[count-1].distance);
	free(band);
	free(parent);
	return 0;
}