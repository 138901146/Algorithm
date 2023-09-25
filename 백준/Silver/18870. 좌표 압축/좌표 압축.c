#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int order, index;
}
location;

int compare(const void *x,const void *y)
{
	return ((location *)x)->order>((location *)y)->order?1:-1;
}

int main(void)
{
	int N, count=0, *compressed=NULL;
	location *X=NULL;

	scanf("%d", &N);
	X=(location *)malloc(N*sizeof(location));
	compressed=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%d", &X[i].order);
		X[i].index=i;
	}

	qsort((void *)X,(size_t)N,sizeof(location),compare);

	compressed[X[0].index]=0;
	for(int i=1;i<N;++i)
	{
		count+=X[i].order==X[i-1].order;
		compressed[X[i].index]=i-count;
	}

	for(int i=0;i<N;++i)
		printf("%d ", compressed[i]);
	free(X);
	free(compressed);
	return 0;
}