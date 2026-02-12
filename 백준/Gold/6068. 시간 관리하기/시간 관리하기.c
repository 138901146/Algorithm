#include<stdio.h>
#include<stdlib.h>

typedef struct
{
	int T, S;
}
due;

int compare(const void *x,const void *y)
{
	return ((due *)x)->S-((due *)y)->T<((due *)y)->S-((due *)y)->T?1:-1;
}

int main(void)
{
	int N, end=1234567;
	due *work=NULL;

	scanf("%d", &N);

	work=(due *)malloc(N*sizeof(due));

	for(int i=0;i<N;++i)
		scanf("%d%d", &work[i].T, &work[i].S);

	qsort((void *)work,(size_t)N,sizeof(due),compare);

	for(int i=0;i<N;++i)
		end=(work[i].S<end?work[i].S:end)-work[i].T;

	printf("%d", end<0?-1:end);
	free(work);
	return 0;
}