#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x>*(int *)y?1:-1;
}

int main(void)
{
	int N, K, *A=NULL;

	scanf("%d%d", &N, &K);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
		scanf("%d", &A[i]);
	qsort((void *)A,(size_t)N,sizeof(int),compare);

	printf("%d", A[K-1]);
	free(A);
	return 0;
}