#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, K, A, B, *X=NULL;

	scanf("%d%d", &N, &K);
	X=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%d%d", &A, &B);
		X[i]=B-A;
	}

	qsort((void *)X,(size_t)N,sizeof(int),compare);

	printf("%d", X[K-1]<0?0:X[K-1]);
	free(X);
	return 0;
}