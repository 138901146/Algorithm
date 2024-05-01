#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, L, *h=NULL;

	scanf("%d%d", &N, &L);
	h=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &h[i]);
	qsort((void *)h,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N && h[i]<=L;++i,++L);

	printf("%d", L);
	free(h);
	return 0;
}