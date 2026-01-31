#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int H, W;
}
size;

int compare(const void *x,const void *y)
{
	return ((size *)x)->H<((size *)y)->H?1:-1;
}

int main(void)
{
	int N;
	long long total=0, max=0;
	size *chocolate=NULL;

	scanf("%d", &N);

	chocolate=(size *)malloc(N*sizeof(size));

	for(int i=0;i<N;++i)
		scanf("%d", &chocolate[i].H);
	for(int i=0;i<N;++i)
		scanf("%d", &chocolate[i].W);

	qsort((void *)chocolate,(size_t)N,sizeof(size),compare);

	for(int i=0;i<N;++i)
	{
		total+=chocolate[i].W;
		max=(long long)total*chocolate[i].H<max?max:(long long)total*chocolate[i].H;
	}

	printf("%lld", max);
	free(chocolate);
	return 0;
}