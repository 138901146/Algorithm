#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:*(int *)x==*(int *)y?0:-1;
}

int main(void)
{
	int N, *a=NULL;

	scanf("%d", &N);
	a=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &a[i]);

	qsort((void *)a,(size_t)N,sizeof(int),compare);

	for(int i=0;i<N;++i)
		printf("%d ", a[i]);

	free(a);
	return 0;
}