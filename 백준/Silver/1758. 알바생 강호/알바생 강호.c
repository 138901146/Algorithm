#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, *tip=NULL;
	long long total=0;

	scanf("%d", &N);
	tip=(int *)malloc(N*sizeof(int));

	for(int n=0;n<N;++n)
		scanf("%d", &tip[n]);

	qsort((void *)tip,(size_t)N,sizeof(int),compare);

	for(int n=0;n<N;++n)
		total+=tip[n]<n?0:tip[n]-n;

	printf("%lld", total);
	free(tip);
	return 0;
}