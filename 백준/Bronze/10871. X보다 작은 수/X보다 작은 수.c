#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, *A=NULL, X;

	scanf("%d %d", &N, &X);
	A=(int *)malloc(N*sizeof(int));

	for(int i=0;i<N;i++)
	{
		scanf("%d", &A[i]);
		if(A[i]<X)
			printf("%d ", A[i]);
	}
	printf("\n");

	free(A);
	return 0;
}