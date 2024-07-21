#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?1:-1;
}

int main(void)
{
	int N, *t=NULL, max=0;

	scanf("%d", &N);
	t=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &t[i]);
	qsort((void *)t,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		max=max<i+1+t[i]?i+1+t[i]:max;

	printf("%d", max+1);
	free(t);
	return 0;
}