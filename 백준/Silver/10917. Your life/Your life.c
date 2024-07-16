#include<stdio.h>
#include<stdlib.h>

#define INF 999999

typedef struct
{
	int x, y;
}
edge;

int compare(const void *x,const void *y)
{
	return ((edge *)x)->x<((edge *)y)->x?-1:((edge *)x)->x>((edge *)y)->x?1:((edge *)x)->y<((edge *)y)->y?-1:1;
}

int main(void)
{
	int N, M, *min=NULL;
	edge *change=NULL;

	scanf("%d%d", &N, &M);
	min=(int *)malloc((N+1)*sizeof(int));
	change=(edge *)malloc(M*sizeof(edge));

	for(int n=2;n<=N;++n)
		min[n]=INF;
	min[1]=0;

	for(int m=0;m<M;++m)
		scanf("%d%d", &change[m].x, &change[m].y);
	qsort((void *)change,(size_t)M,sizeof(edge),compare);

	for(int m=0;m<M;++m)
		if(min[change[m].x]+1<min[change[m].y])
			min[change[m].y]=min[change[m].x]+1;

	printf("%d", min[N]==INF?-1:min[N]);
	free(change);
	free(min);
	return 0;
}