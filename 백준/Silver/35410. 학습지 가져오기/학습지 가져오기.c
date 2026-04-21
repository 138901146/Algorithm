#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, *t=NULL, current=0;

	scanf("%d", &N);

	t=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &t[i]);

	qsort((void *)t,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		current=current+1<t[i]?t[i]:current+1;

	printf("%d", current+1);

	free(t);
	return 0;
}