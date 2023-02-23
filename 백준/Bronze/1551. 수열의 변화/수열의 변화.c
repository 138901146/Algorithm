#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, K, *A=NULL;

	scanf("%d %d", &N, &K);
	A=(int *)malloc(N*sizeof(int));
	scanf("%d", &A[0]);
	for(int n=1;n<N;n++)
		scanf(",%d", &A[n]);

	for(int k=1;k<=K;k++)
	{
		int *B=malloc((N-k)*sizeof(int));

		for(int n=1;n<=N-k;n++)
			B[n-1]=A[n]-A[n-1];

		A=(int *)realloc(A,(N-k)*sizeof(int));
		for(int n=0;n<N-k;n++)
			A[n]=B[n];

		free(B);
	}

	printf("%d", A[0]);
	for(int n=1;n<N-K;n++)
		printf(",%d", A[n]);
	printf("\n");
	free(A);
	return 0;
}