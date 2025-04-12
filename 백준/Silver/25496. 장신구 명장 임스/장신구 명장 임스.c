#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
	return *(int *)x<*(int *)y?-1:1;
}

int main(void)
{
	int N, P, *A=NULL, count=0, total=0;

	scanf("%d%d", &P, &N);

	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;++i)
	{
		scanf("%d", &A[i]);
		total+=A[i];
	}

	P=200-P;

	if(total<=P)
	{
		printf("%d", N);
		free(A);
		return 0;
	}

	qsort((void *)A,(size_t)N,sizeof(int),compare);

	while(count<N&&0<P)
		P-=A[count++];

	printf("%d", count);
	free(A);
	return 0;
}