#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int N, M, **A=NULL, **B=NULL;

	scanf("%d %d", &N, &M);
	A=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		A[n]=(int *)malloc(M*sizeof(int));
	B=(int **)malloc(N*sizeof(int *));
	for(int n=0;n<N;n++)
		B[n]=(int *)malloc(M*sizeof(int));

	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%d", &A[n][m]);
	for(int n=0;n<N;n++)
		for(int m=0;m<M;m++)
			scanf("%d", &B[n][m]);

	for(int n=0;n<N;n++)
	{
		for(int m=0;m<M;m++)
			printf("%d ", A[n][m]+B[n][m]);
		printf("\n");
	}
	for(int n=0;n<N;n++)
		free(B[n]);
	free(B);
	for(int n=0;n<N;n++)
		free(A[n]);
	free(A);
	return 0;
}